// ======================================================================
// \title  HealthMonitorComponentImpl.cpp
// \author aleha
// \brief  cpp file for HealthMonitor component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/HealthMonitor/HealthMonitorComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  HealthMonitorComponentImpl ::
#if FW_OBJECT_NAMES == 1
    HealthMonitorComponentImpl(
        const char *const compName
    ) :
      HealthMonitorComponentBase(compName)
#else
    HealthMonitorComponentImpl(void)
#endif
  {
    this->lastTemp = 0;
    this->tlmWrite_HEALTH_MONITOR_LAST_TEMP(this->lastTemp);
    this->critWarn = false;
    this->fatalWarn = false;
  }

  void HealthMonitorComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    HealthMonitorComponentBase::init(queueDepth, instance);
  }

  HealthMonitorComponentImpl ::
    ~HealthMonitorComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void HealthMonitorComponentImpl ::
    tempIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 request
    )
  {
    this->lastTemp = request;
    this->tlmWrite_HEALTH_MONITOR_LAST_TEMP(this->lastTemp);
    int phase = this->currPhase;

    if(this->critWarn == false) {
      if(this->lastTemp < this->tempThresholds[phase][0]) {
        this->log_WARNING_HI_HEALTH_MONITOR_TEMP_CRITICAL_LO(this->lastTemp);
        this->critWarn = true;
      }
      if(this->lastTemp > this->tempThresholds[phase][1]) {
        this->log_WARNING_HI_HEALTH_MONITOR_TEMP_CRITICAL_HI(this->lastTemp);
        this->critWarn = true;
      }
    } else {
      if(this->lastTemp >= this->tempThresholds[phase][0] && this->lastTemp <= this->tempThresholds[phase][1]) {
        this->critWarn = false;
      }
    }

    if(this->fatalWarn == false) {
      if(this->lastTemp < this->tempThresholds[9][0]) {
        this->log_WARNING_HI_HEALTH_MONITOR_TEMP_FATAL_LO(this->lastTemp);
        this->fatalWarn = true;
        this->healthAlertOut_out(0, 1, 300);
      }
      if(this->lastTemp > this->tempThresholds[9][1]) {
        this->log_WARNING_HI_HEALTH_MONITOR_TEMP_FATAL_HI(this->lastTemp);
        this->fatalWarn = true;
        this->healthAlertOut_out(0, 1, 300);
      } else {
        if(this->lastTemp >= this->tempThresholds[9][0] && this->lastTemp <= this->tempThresholds[9][1]) {
          this->fatalWarn = false;
      }
    }
    }
  }

  void HealthMonitorComponentImpl ::
    phaseIn_handler(
        const NATIVE_INT_TYPE portNum,
        U32 nextPhase
    )
  {
    this->currPhase = nextPhase;
    this->tlmWrite_HEALTH_MONITOR_CURR_PHASE(this->currPhase);
  }

  void HealthMonitorComponentImpl ::
    threshIn_handler(
        const NATIVE_INT_TYPE portNum,
        U32 phase,
        F32 minTemp,
        F32 maxTemp
    )
  {
    int phaseInt = phase;
    this->tempThresholds[phaseInt][0] = minTemp;
    this->tempThresholds[phaseInt][1] = maxTemp;
    this->log_ACTIVITY_HI_HEALTH_MONITOR_THRESHOLD_CHANGED(phase, minTemp, maxTemp);
  }

  void HealthMonitorComponentImpl ::
    SchedIn_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    this->healthTempReqOut_out(0, 1);
  }

} // end namespace Ref

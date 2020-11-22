// ======================================================================
// \title  HealthMonitorComponentImpl.cpp
// \author Leah
// \brief  cpp file for HealthMonitor component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// Reference: https://github.com/Aleha-C/fprime/tree/AEGIS_Assignment
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
      this->warning = false;
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
    schedIn_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    // TODO
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void HealthMonitorComponentImpl ::
    HM_UPDATE_TEMP_THRESHOLD_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        U32 phase,
        F32 minTemp,
        F32 maxTemp
    )
  {
      int i = phase;
      this->minThresholds[i] = minTemp;
      this->maxThresholds[i] = maxTemp;
      this->log_ACTIVITY_HI_HM_TEMP_THRESHOLD_UPDATED(phase, minTemp, maxTemp);
      this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void HealthMonitorComponentImpl ::
    parameterUpdated(
      FwPrmIdType id /*!< The parameter ID*/
  ) {
      this->log_ACTIVITY_LO_HM_PARAMATER_UPDATED(id);
      Fw::ParamValid valid;
      U32 phase = 0;
      F32 temperature = 50.0;
      F32 minTemp = 50.0;
      F32 maxTemp = 100.0;
    
      switch(id) {
          case PARAMID_PHASE: {
              phase = this->paramGet_phase(valid);
              this->tlmWrite_HM_PARAMETER_PHASE(phase);
              break;
          }
          case PARAMID_TEMPERATURE: {
              temperature = this->paramGet_temperature(valid);
              this->tlmWrite_HM_PARAMETER_TEMP(temperature);
              break;
          }
          case PARAMID_MINTEMP: {
              minTemp = this->paramGet_minTemp(valid);
              this->tlmWrite_HM_PARAMETER_MIN_TEMP(minTemp);
              this->minThresholds[phase] = minTemp;
              break;
          }
          case PARAMID_MAXTEMP: {
              maxTemp = this->paramGet_maxTemp(valid);
              this->tlmWrite_HM_PARAMETER_MAX_TEMP(maxTemp);
              this->maxThresholds[phase] = maxTemp;
              break;
          }
      }
      
      if (this->warning == false) {
          if (temperature < this->minThresholds[phase]) {
              this->warning = true;
              this->log_WARNING_LO_HM_TEMP_LO(temperature);
          }
          if (temperature > this->maxThresholds[phase]) {
              this->warning = true;
              this->log_WARNING_HI_HM_TEMP_HI(temperature);
          }
      }
      else {
          if (temperature >= this->minThresholds[phase] && temperature <= this->maxThresholds[phase]) {
              this->warning = false;
          }
      }
  }

} // end namespace Ref

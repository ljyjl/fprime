// ======================================================================
// \title  HealthMonitorComponentImpl.cpp
// \author ljyjl
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
    // TODO
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref

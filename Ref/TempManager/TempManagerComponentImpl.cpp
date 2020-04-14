// ======================================================================
// \title  TempManagerComponentImpl.cpp
// \author aleha
// \brief  cpp file for TempManager component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/TempManager/TempManagerComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  TempManagerComponentImpl ::
#if FW_OBJECT_NAMES == 1
    TempManagerComponentImpl(
        const char *const compName
    ) :
      TempManagerComponentBase(compName)
#else
    TempManagerComponentImpl(void)
#endif
  {
    this->lastTemp = 50;
    this->autoCheckEnabled = true;
    this->tlmWrite_TEMP_MANAGER_LAST_TEMP(50);
  }

  void TempManagerComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    TempManagerComponentBase::init(queueDepth, instance);
  }

  TempManagerComponentImpl ::
    ~TempManagerComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void TempManagerComponentImpl ::
    tempIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 temperature
    )
  {
    this->lastTemp = temperature;
    this->tlmWrite_TEMP_MANAGER_LAST_TEMP(temperature);
  }

  void TempManagerComponentImpl ::
    healthTempReqIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 request
    )
  {
    this->tempOut_out(0, this->lastTemp);
  }

  void TempManagerComponentImpl ::
    SchedIn_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    if(this->autoCheckEnabled == true) {
      this->managerReqOut_out(0, 1);
    }
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void TempManagerComponentImpl ::
    TEMP_MANAGER_ENABLE_AUTO_CHECK_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    this->autoCheckEnabled = true;
    this->log_ACTIVITY_LO_TEMP_MANAGER_AUTOCHECK_ENABLED(1);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void TempManagerComponentImpl ::
    TEMP_MANAGER_DISABLE_AUTO_CHECK_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq
    )
  {
    this->autoCheckEnabled = false;
    this->log_ACTIVITY_LO_TEMP_MANAGER_AUTOCHECK_DISABLED(0);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref

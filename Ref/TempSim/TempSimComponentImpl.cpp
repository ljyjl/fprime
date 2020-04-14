// ======================================================================
// \title  TempSimComponentImpl.cpp
// \author aleha
// \brief  cpp file for TempSim component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/TempSim/TempSimComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  TempSimComponentImpl ::
#if FW_OBJECT_NAMES == 1
    TempSimComponentImpl(
        const char *const compName
    ) :
      TempSimComponentBase(compName)
#else
    TempSimComponentImpl(void)
#endif
  {

  }

  void TempSimComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    TempSimComponentBase::init(queueDepth, instance);
  }

  TempSimComponentImpl ::
    ~TempSimComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void TempSimComponentImpl ::
    driverReqIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 request
    )
  {
    this->tempOut_out(0, this->currTemp);
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void TempSimComponentImpl ::
    TEMPSIM_SET_TEMP_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 temperature
    )
  {
    this->currTemp = temperature;
    this->tlmWrite_TEMPSIM_CURR_TEMP(this->currTemp);
    this->log_ACTIVITY_HI_TEMPSIM_TEMP_CHANGED(temperature);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref

// ======================================================================
// \title  TempDriverComponentImpl.cpp
// \author aleha
// \brief  cpp file for TempDriver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/TempDriver/TempDriverComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  TempDriverComponentImpl ::
#if FW_OBJECT_NAMES == 1
    TempDriverComponentImpl(
        const char *const compName
    ) :
      TempDriverComponentBase(compName)
#else
    TempDriverComponentImpl(void)
#endif
  {
    this->lastTemp = 0;
    this->tlmWrite_DRIVER_LAST_TEMP(0);
  }

  void TempDriverComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    TempDriverComponentBase::init(queueDepth, instance);
  }

  TempDriverComponentImpl ::
    ~TempDriverComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void TempDriverComponentImpl ::
    tempIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 temperature
    )
  {
    this->lastTemp = temperature;
    this->tlmWrite_DRIVER_LAST_TEMP(temperature);
    this->tempOut_out(0, this->lastTemp);
  }

  void TempDriverComponentImpl ::
    managerReqIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 request
    )
  {
    this->driverReqOut_out(0, 1);
  }

} // end namespace Ref

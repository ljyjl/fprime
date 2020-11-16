// ======================================================================
// \title  ThermometerComponentImpl.cpp
// \author Leah
// \brief  cpp file for Thermometer component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// Reference: https://github.com/Aleha-C/fprime/tree/AEGIS_Assignment
// ======================================================================


#include <Ref/Thermometer/ThermometerComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ThermometerComponentImpl ::
#if FW_OBJECT_NAMES == 1
    ThermometerComponentImpl(
        const char *const compName
    ) :
      ThermometerComponentBase(compName)
#else
    ThermometerComponentImpl(void)
#endif
  {

  }

  void ThermometerComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    ThermometerComponentBase::init(queueDepth, instance);
  }

  ThermometerComponentImpl ::
    ~ThermometerComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void ThermometerComponentImpl ::
    temperatureReqIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 requestTempteratue
    )
  {
      this->temperatureOut_out(0, this->currentTemp);
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void ThermometerComponentImpl ::
    THERMO_SET_TEMP_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        F32 temperature
    )
  {
    this->currentTemp = temperature;
    this->tlmWrite_THERMO_TEMP(this->currentTemp);
    this->log_ACTIVITY_HI_TERMO_TEMP_UPDATED(temperature);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref

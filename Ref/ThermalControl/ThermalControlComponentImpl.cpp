// ======================================================================
// \title  ThermalControlComponentImpl.cpp
// \author Leah
// \brief  cpp file for ThermalControl component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// Reference: https://github.com/Aleha-C/fprime/tree/AEGIS_Assignment
// ======================================================================


#include <Ref/ThermalControl/ThermalControlComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ThermalControlComponentImpl ::
#if FW_OBJECT_NAMES == 1
    ThermalControlComponentImpl(
        const char *const compName
    ) :
      ThermalControlComponentBase(compName)
#else
    ThermalControlComponentImpl(void)
#endif
  {

  }

  void ThermalControlComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    ThermalControlComponentBase::init(queueDepth, instance);
  }

  ThermalControlComponentImpl ::
    ~ThermalControlComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void ThermalControlComponentImpl ::
    schedIn_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    // TODO
  }

  void ThermalControlComponentImpl ::
    temperatureIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 temperature
    )
  {
      this->recvTemp = temperature;
      //this->tlmWrite_THERMAL_TEMP(temperature);
      this->log_ACTIVITY_HI_TC_TEMP_RECV(temperature);
  }

  void ThermalControlComponentImpl ::
    parameterUpdated(
        FwPrmIdType id /*!< The parameter ID*/
    ) {
    this->log_ACTIVITY_LO_TC_PARAMATER_UPDATED(id);
    Fw::ParamValid valid;
    switch(id) {
        case PARAMID_PHASE: {
            U32 phase = this->paramGet_phase(valid);
            this->tlmWrite_TC_PARAMETER_PHASE(phase);
            break;
        }
        case PARAMID_TEMPERATURE: {
            F32 temperature = this->paramGet_temperature(valid);
            this->tlmWrite_TC_PARAMETER_TEMP(temperature);
            break;
        }
        case PARAMID_MINTEMP: {
            F32 minTemp = this->paramGet_minTemp(valid);
            this->tlmWrite_TC_PARAMETER_MIN_TEMP(minTemp);
            break;
        }
        case PARAMID_MAXTEMP: {
            F32 maxTemp = this->paramGet_maxTemp(valid);
            this->tlmWrite_TC_PARAMETER_MAX_TEMP(maxTemp);
            break;
        }
    }
}


} // end namespace Ref

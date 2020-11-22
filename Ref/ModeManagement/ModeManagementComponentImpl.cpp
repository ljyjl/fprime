// ======================================================================
// \title  ModeManagementComponentImpl.cpp
// \author Leah
// \brief  cpp file for ModeManagement component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/ModeManagement/ModeManagementComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ModeManagementComponentImpl ::
#if FW_OBJECT_NAMES == 1
    ModeManagementComponentImpl(
        const char *const compName
    ) :
      ModeManagementComponentBase(compName)
#else
    ModeManagementComponentImpl(void)
#endif
  {
      this->warning = false;
  }

  void ModeManagementComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    ModeManagementComponentBase::init(queueDepth, instance);
  }

  ModeManagementComponentImpl ::
    ~ModeManagementComponentImpl(void)
  {
      
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void ModeManagementComponentImpl ::
    MM_UPDATE_PHASE_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        U32 phase
    )
  {
      this->currentPhase = phase;
      this->tlmWrite_MM_PHASE(this->currentPhase);
      this->log_ACTIVITY_HI_MM_PHASE_UPDATED(phase);
      this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void ModeManagementComponentImpl ::
    parameterUpdated(
      FwPrmIdType id /*!< The parameter ID*/
  ) {
      this->log_ACTIVITY_LO_MM_PARAMATER_UPDATED(id);
      Fw::ParamValid valid;
      U32 phase = 0;
      F32 temperature = 50.0;
      F32 minTemp = 50.0;
      F32 maxTemp = 100.0;
    
      switch(id) {
          case PARAMID_PHASE: {
              phase = this->paramGet_phase(valid);
              this->tlmWrite_MM_PARAMETER_PHASE(phase);
              break;
          }
          case PARAMID_TEMPERATURE: {
              temperature = this->paramGet_temperature(valid);
              this->tlmWrite_MM_PARAMETER_TEMP(temperature);
              break;
          }
          case PARAMID_MINTEMP: {
              minTemp = this->paramGet_minTemp(valid);
              this->tlmWrite_MM_PARAMETER_MIN_TEMP(minTemp);
              this->minThresholds[phase] = minTemp;
              break;
          }
          case PARAMID_MAXTEMP: {
              maxTemp = this->paramGet_maxTemp(valid);
              this->tlmWrite_MM_PARAMETER_MAX_TEMP(maxTemp);
              this->maxThresholds[phase] = maxTemp;
              break;
          }
      }
      
      if (this->warning == false) {
          if (temperature < this->minThresholds[phase]) {
              this->warning = true;
              this->log_WARNING_HI_MM_SAFETY_MODE_ENTERED(8);
          }
          if (temperature > this->maxThresholds[phase]) {
              this->warning = true;
              this->log_WARNING_HI_MM_SAFETY_MODE_ENTERED(8);
          }
      }
      else {
          if (temperature >= this->minThresholds[phase] && temperature <= this->maxThresholds[phase]) {
              this->warning = false;
          }
      }
  }


} // end namespace Ref

// ======================================================================
// \title  ControllerComponentImpl.cpp
// \author aleha
// \brief  cpp file for Controller component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/Controller/ControllerComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ControllerComponentImpl ::
#if FW_OBJECT_NAMES == 1
    ControllerComponentImpl(
        const char *const compName
    ) :
      ControllerComponentBase(compName)
#else
    ControllerComponentImpl(void)
#endif
  {
    this->currPhase = 0;
    this->tlmWrite_CONTROLLER_CURRENT_PHASE(0);
  }

  void ControllerComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    ControllerComponentBase::init(queueDepth, instance);
  }

  ControllerComponentImpl ::
    ~ControllerComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void ControllerComponentImpl ::
    healthAlertIn_handler(
        const NATIVE_INT_TYPE portNum,
        U32 enterSafeMode,
        U32 sourceComponent
    )
  {
    this->log_WARNING_HI_CONTROLLER_HEALTH_ALERT_RECEIVED(sourceComponent);
    if(enterSafeMode == 1) {
      this->currPhase = 8;
      F32 componentNum1 = 100;
      F32 state = 0;
      this->opOut_out(0, 0, 2, componentNum1, state, 0);
      this->log_WARNING_HI_CONTROLLER_NON_ESSENTIAL_COMPONENTS_DISABLED(1);
      this->log_WARNING_HI_CONTROLLER_SAFETY_MODE(0);
      F32 componentNum2 = sourceComponent;
      // Send health component (#200) updated operations phase
      this->opOut_out(0, 0, 0, componentNum2, this->currPhase, 0);
      this->tlmWrite_CONTROLLER_CURRENT_PHASE(this->currPhase);
      this->log_ACTIVITY_HI_CONTROLLER_PHASE_CHANGED(this->currPhase);
    }
  }

  // ----------------------------------------------------------------------
  // Command handler implementations
  // ----------------------------------------------------------------------

  void ControllerComponentImpl ::
    CONTROLLER_CHANGE_PHASE_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        U32 phase
    )
  {
    if((this->currPhase == 0 || this->currPhase == 1 || this->currPhase == 2 || this->currPhase == 8) and 
        (phase != 0 || phase != 1 || phase != 2 || phase != 8)) {
      F32 componentNum1 = 100;
      F32 state = 1;
      // Enable science component (#100)
      this->opOut_out(0, 0, 2, componentNum1, state, 0);
    }
    this->currPhase = phase;
    if(this->currPhase == 0 || this->currPhase == 1 || this->currPhase == 2 || this->currPhase == 8) {
      F32 componentNum2 = 100;
      F32 state = 0;
      // Disable science component (#100)
      this->opOut_out(0, 0, 2, componentNum2, state, 0);
      this->log_WARNING_HI_CONTROLLER_NON_ESSENTIAL_COMPONENTS_DISABLED(1);
      if(this->currPhase == 8) {
        this->log_WARNING_HI_CONTROLLER_SAFETY_MODE(0);
      }
    }
    F32 componentNum3 = 200;
    // Send health component (#200) updated operations phase
    this->opOut_out(0, 0, 0, componentNum3, phase, 0);
    this->tlmWrite_CONTROLLER_CURRENT_PHASE(phase);
    this->log_ACTIVITY_HI_CONTROLLER_PHASE_CHANGED(phase);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

  void ControllerComponentImpl ::
    CONTROLLER_CHANGE_TEMP_THRESHOLD_cmdHandler(
        const FwOpcodeType opCode,
        const U32 cmdSeq,
        U32 phase,
        F32 minTemp,
        F32 maxTemp
    )
  {
    this->opOut_out(0, 0, 1, phase, minTemp, maxTemp);
    this->log_ACTIVITY_HI_CONTROLLER_TEMP_THRESHOLD_CHANGED(phase, minTemp, maxTemp);
    this->cmdResponse_out(opCode,cmdSeq,Fw::COMMAND_OK);
  }

} // end namespace Ref

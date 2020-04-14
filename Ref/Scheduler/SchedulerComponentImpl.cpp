// ======================================================================
// \title  SchedulerComponentImpl.cpp
// \author aleha
// \brief  cpp file for Scheduler component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/Scheduler/SchedulerComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  SchedulerComponentImpl ::
#if FW_OBJECT_NAMES == 1
    SchedulerComponentImpl(
        const char *const compName
    ) :
      SchedulerComponentBase(compName)
#else
    SchedulerComponentImpl(void)
#endif
  {

  }

  void SchedulerComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    SchedulerComponentBase::init(queueDepth, instance);
  }

  SchedulerComponentImpl ::
    ~SchedulerComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void SchedulerComponentImpl ::
    opIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 time,
        F32 op,
        F32 val1,
        F32 val2,
        F32 val3
    )
  {
    if(op == 0) {
      this->log_ACTIVITY_HI_SCHEDULER_UPDATE_COMPONENT_PHASE(val1, val2);
      this->phaseOut_out(0, val2);
    }
    else if (op == 1) {
      this->log_ACTIVITY_HI_SCHEDULER_UPDATE_TEMP_THRESHOLD(val1, val2, val3);
      this->threshOut_out(0, val1, val2, val3);
    }
    else if (op == 2) {
      this->log_ACTIVITY_HI_SCHEDULER_UPDATE_COMPONENT_STATE(val1, val2);
      this->activeStatusOut_out(0, val2);
    }
  }

} // end namespace Ref

// ======================================================================
// \title  SchedulerComponentImpl.hpp
// \author aleha
// \brief  hpp file for Scheduler component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef Scheduler_HPP
#define Scheduler_HPP

#include "Ref/Scheduler/SchedulerComponentAc.hpp"

namespace Ref {

  class SchedulerComponentImpl :
    public SchedulerComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object Scheduler
      //!
      SchedulerComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object Scheduler
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object Scheduler
      //!
      ~SchedulerComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for opIn
      //!
      void opIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 time, 
          F32 op, 
          F32 val1, 
          F32 val2, 
          F32 val3 
      );


    };

} // end namespace Ref

#endif

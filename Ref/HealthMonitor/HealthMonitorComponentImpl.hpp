// ======================================================================
// \title  HealthMonitorComponentImpl.hpp
// \author ljyjl
// \brief  hpp file for HealthMonitor component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef HealthMonitor_HPP
#define HealthMonitor_HPP

#include "Ref/HealthMonitor/HealthMonitorComponentAc.hpp"

namespace Ref {

  class HealthMonitorComponentImpl :
    public HealthMonitorComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object HealthMonitor
      //!
      HealthMonitorComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object HealthMonitor
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object HealthMonitor
      //!
      ~HealthMonitorComponentImpl(void);

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for schedIn
      //!
      void schedIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for HM_UPDATE_TEMP_THRESHOLD command handler
      //! 
      void HM_UPDATE_TEMP_THRESHOLD_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          U32 phase, 
          F32 minTemp, 
          F32 maxTemp 
      );


    };

} // end namespace Ref

#endif

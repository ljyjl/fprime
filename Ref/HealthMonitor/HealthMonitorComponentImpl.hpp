// ======================================================================
// \title  HealthMonitorComponentImpl.hpp
// \author Leah
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
    
      private:
        bool warning;
        F32 minThresholds[10] = {50, 45, 55, 20, 15, 25, 10, 15, 0, 0};
        F32 maxThresholds[10] = {100, 105, 95, 200, 205, 195, 300, 295, 100, 1000};

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
      
      
  PRIVATE:

    // ----------------------------------------------------------------------
    // Parameter update implementations
    // ----------------------------------------------------------------------

    void parameterUpdated(
        FwPrmIdType id /*!< The parameter ID*/
    );

  };

} // end namespace Ref

#endif

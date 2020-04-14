// ======================================================================
// \title  HealthMonitorComponentImpl.hpp
// \author aleha
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
        bool critWarn;
        bool fatalWarn;
        F32 lastTemp;
        F32 currPhase;
        // {Deployment, Warmup, Burn, 
        //  Charge, Comms, Science
        //  Pre-Disposal, Disposal, SafeMode, GlobalFatal}
        F32 tempThresholds[10][2] = {{50, 100}, {45, 105}, {55, 95}, 
                                    {20, 200}, {15, 205}, {25, 195}, 
                                    {10, 300}, {15, 295}, {0,100}, {0, 1000}};

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for tempIn
      //!
      void tempIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 request 
      );

      //! Handler implementation for phaseIn
      //!
      void phaseIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 nextPhase 
      );

      //! Handler implementation for threshIn
      //!
      void threshIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          U32 phase, 
          F32 minTemp, 
          F32 maxTemp 
      );

      //! Handler implementation for SchedIn
      //!
      void SchedIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );


    };

} // end namespace Ref

#endif

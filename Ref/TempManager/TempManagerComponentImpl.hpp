// ======================================================================
// \title  TempManagerComponentImpl.hpp
// \author aleha
// \brief  hpp file for TempManager component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef TempManager_HPP
#define TempManager_HPP

#include "Ref/TempManager/TempManagerComponentAc.hpp"

namespace Ref {

  class TempManagerComponentImpl :
    public TempManagerComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object TempManager
      //!
      TempManagerComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object TempManager
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object TempManager
      //!
      ~TempManagerComponentImpl(void);

      private:
        F32 lastTemp;
        bool autoCheckEnabled;

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for tempIn
      //!
      void tempIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 temperature 
      );

      //! Handler implementation for healthTempReqIn
      //!
      void healthTempReqIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 request 
      );

      //! Handler implementation for SchedIn
      //!
      void SchedIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          NATIVE_UINT_TYPE context /*!< The call order*/
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for TEMP_MANAGER_ENABLE_AUTO_CHECK command handler
      //! 
      void TEMP_MANAGER_ENABLE_AUTO_CHECK_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );

      //! Implementation for TEMP_MANAGER_DISABLE_AUTO_CHECK command handler
      //! 
      void TEMP_MANAGER_DISABLE_AUTO_CHECK_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq /*!< The command sequence number*/
      );


    };

} // end namespace Ref

#endif

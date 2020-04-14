// ======================================================================
// \title  TempSimComponentImpl.hpp
// \author aleha
// \brief  hpp file for TempSim component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef TempSim_HPP
#define TempSim_HPP

#include "Ref/TempSim/TempSimComponentAc.hpp"

namespace Ref {

  class TempSimComponentImpl :
    public TempSimComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object TempSim
      //!
      TempSimComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object TempSim
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object TempSim
      //!
      ~TempSimComponentImpl(void);

      private:
        F32 currTemp = 50;

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for driverReqIn
      //!
      void driverReqIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 request 
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for TEMPSIM_SET_TEMP command handler
      //! 
      void TEMPSIM_SET_TEMP_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          F32 temperature 
      );


    };

} // end namespace Ref

#endif

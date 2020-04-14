// ======================================================================
// \title  TempDriverComponentImpl.hpp
// \author aleha
// \brief  hpp file for TempDriver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef TempDriver_HPP
#define TempDriver_HPP

#include "Ref/TempDriver/TempDriverComponentAc.hpp"

namespace Ref {

  class TempDriverComponentImpl :
    public TempDriverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object TempDriver
      //!
      TempDriverComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object TempDriver
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object TempDriver
      //!
      ~TempDriverComponentImpl(void);

      private:
        F32 lastTemp;

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

      //! Handler implementation for managerReqIn
      //!
      void managerReqIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 request 
      );


    };

} // end namespace Ref

#endif

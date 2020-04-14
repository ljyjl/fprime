// ======================================================================
// \title  ScienceDriverComponentImpl.hpp
// \author aleha
// \brief  hpp file for ScienceDriver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef ScienceDriver_HPP
#define ScienceDriver_HPP

#include "Ref/ScienceDriver/ScienceDriverComponentAc.hpp"

namespace Ref {

  class ScienceDriverComponentImpl :
    public ScienceDriverComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object ScienceDriver
      //!
      ScienceDriverComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object ScienceDriver
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object ScienceDriver
      //!
      ~ScienceDriverComponentImpl(void);

      private:
        F32 retrievedData;

    PRIVATE:

      // ----------------------------------------------------------------------
      // Handler implementations for user-defined typed input ports
      // ----------------------------------------------------------------------

      //! Handler implementation for scienceIn
      //!
      void scienceIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 science 
      );

      //! Handler implementation for scienceManagerReqIn
      //!
      void scienceManagerReqIn_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 request 
      );


    };

} // end namespace Ref

#endif

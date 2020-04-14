// ======================================================================
// \title  ScienceManagerComponentImpl.hpp
// \author aleha
// \brief  hpp file for ScienceManager component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef ScienceManager_HPP
#define ScienceManager_HPP

#include "Ref/ScienceManager/ScienceManagerComponentAc.hpp"

namespace Ref {

  class ScienceManagerComponentImpl :
    public ScienceManagerComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object ScienceManager
      //!
      ScienceManagerComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object ScienceManager
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object ScienceManager
      //!
      ~ScienceManagerComponentImpl(void);

      private:
        F32 retrievedData;
        bool isEnabled = true;

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

      //! Handler implementation for activeStatus
      //!
      void activeStatus_handler(
          const NATIVE_INT_TYPE portNum, /*!< The port number*/
          F32 status 
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

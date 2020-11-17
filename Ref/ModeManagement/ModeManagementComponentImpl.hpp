// ======================================================================
// \title  ModeManagementComponentImpl.hpp
// \author Leah
// \brief  hpp file for ModeManagement component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================

#ifndef ModeManagement_HPP
#define ModeManagement_HPP

#include "Ref/ModeManagement/ModeManagementComponentAc.hpp"

namespace Ref {

  class ModeManagementComponentImpl :
    public ModeManagementComponentBase
  {

    public:

      // ----------------------------------------------------------------------
      // Construction, initialization, and destruction
      // ----------------------------------------------------------------------

      //! Construct object ModeManagement
      //!
      ModeManagementComponentImpl(
#if FW_OBJECT_NAMES == 1
          const char *const compName /*!< The component name*/
#else
          void
#endif
      );

      //! Initialize object ModeManagement
      //!
      void init(
          const NATIVE_INT_TYPE queueDepth, /*!< The queue depth*/
          const NATIVE_INT_TYPE instance = 0 /*!< The instance number*/
      );

      //! Destroy object ModeManagement
      //!
      ~ModeManagementComponentImpl(void);
      
    private:
         U32 currentPhase;


    PRIVATE:

      // ----------------------------------------------------------------------
      // Command handler implementations
      // ----------------------------------------------------------------------

      //! Implementation for MM_UPDATE_PHASE command handler
      //! 
      void MM_UPDATE_PHASE_cmdHandler(
          const FwOpcodeType opCode, /*!< The opcode*/
          const U32 cmdSeq, /*!< The command sequence number*/
          U32 phase 
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

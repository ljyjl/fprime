// ======================================================================
// \title  ScienceManagerComponentImpl.cpp
// \author aleha
// \brief  cpp file for ScienceManager component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/ScienceManager/ScienceManagerComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ScienceManagerComponentImpl ::
#if FW_OBJECT_NAMES == 1
    ScienceManagerComponentImpl(
        const char *const compName
    ) :
      ScienceManagerComponentBase(compName)
#else
    ScienceManagerComponentImpl(void)
#endif
  {
    this->retrievedData = 0;
    this->tlmWrite_SCIENCE_MANAGER_DATA(this->retrievedData);
    this->isEnabled = false;
    this->tlmWrite_SCIENCE_MANAGER_IS_ENABLED(1);
  }

  void ScienceManagerComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    ScienceManagerComponentBase::init(queueDepth, instance);
  }

  ScienceManagerComponentImpl ::
    ~ScienceManagerComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void ScienceManagerComponentImpl ::
    scienceIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 science
    )
  {
    this->retrievedData = science;
    this->tlmWrite_SCIENCE_MANAGER_DATA(this->retrievedData);
  }

  void ScienceManagerComponentImpl ::
    activeStatus_handler(
        const NATIVE_INT_TYPE portNum,
        F32 status
    )
  {
    if(status == 1) {
      this->isEnabled = true;
    } 
    else {
      this->isEnabled = false;
    }
    this->tlmWrite_SCIENCE_MANAGER_IS_ENABLED(status);
  }

  void ScienceManagerComponentImpl ::
    SchedIn_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    if(this->isEnabled == true) {
      this->scienceManagerReqOut_out(0, 1);
    }
  }

} // end namespace Ref

// ======================================================================
// \title  ScienceDriverComponentImpl.cpp
// \author aleha
// \brief  cpp file for ScienceDriver component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/ScienceDriver/ScienceDriverComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ScienceDriverComponentImpl ::
#if FW_OBJECT_NAMES == 1
    ScienceDriverComponentImpl(
        const char *const compName
    ) :
      ScienceDriverComponentBase(compName)
#else
    ScienceDriverComponentImpl(void)
#endif
  {
    this->retrievedData = 0;
    this->tlmWrite_SCIENCE_DRIVER_DATA(this->retrievedData);
  }

  void ScienceDriverComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    ScienceDriverComponentBase::init(queueDepth, instance);
  }

  ScienceDriverComponentImpl ::
    ~ScienceDriverComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void ScienceDriverComponentImpl ::
    scienceIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 science
    )
  {
    this->retrievedData = science;
    this->tlmWrite_SCIENCE_DRIVER_DATA(this->retrievedData);
    this->scienceOut_out(0, this->retrievedData);
  }

  void ScienceDriverComponentImpl ::
    scienceManagerReqIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 request
    )
  {
    this->scienceDriverReqOut_out(0, 1);
  }

} // end namespace Ref

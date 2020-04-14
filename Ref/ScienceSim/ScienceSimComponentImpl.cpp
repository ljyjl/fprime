// ======================================================================
// \title  ScienceSimComponentImpl.cpp
// \author aleha
// \brief  cpp file for ScienceSim component implementation class
//
// \copyright
// Copyright 2009-2015, by the California Institute of Technology.
// ALL RIGHTS RESERVED.  United States Government Sponsorship
// acknowledged.
//
// ======================================================================


#include <Ref/ScienceSim/ScienceSimComponentImpl.hpp>
#include "Fw/Types/BasicTypes.hpp"
#include <stdlib.h>

namespace Ref {

  // ----------------------------------------------------------------------
  // Construction, initialization, and destruction
  // ----------------------------------------------------------------------

  ScienceSimComponentImpl ::
#if FW_OBJECT_NAMES == 1
    ScienceSimComponentImpl(
        const char *const compName
    ) :
      ScienceSimComponentBase(compName)
#else
    ScienceSimComponentImpl(void)
#endif
  {
    this->previous_data = 0;
    this->tlmWrite_SCIENCE_SIM_DATA(this->previous_data);
  }

  void ScienceSimComponentImpl ::
    init(
        const NATIVE_INT_TYPE queueDepth,
        const NATIVE_INT_TYPE instance
    )
  {
    ScienceSimComponentBase::init(queueDepth, instance);
  }

  ScienceSimComponentImpl ::
    ~ScienceSimComponentImpl(void)
  {

  }

  // ----------------------------------------------------------------------
  // Handler implementations for user-defined typed input ports
  // ----------------------------------------------------------------------

  void ScienceSimComponentImpl ::
    scienceDriverReqIn_handler(
        const NATIVE_INT_TYPE portNum,
        F32 request
    )
  {
    this->scienceOut_out(0, this->previous_data);
  }

  void ScienceSimComponentImpl ::
    SchedIn_handler(
        const NATIVE_INT_TYPE portNum,
        NATIVE_UINT_TYPE context
    )
  {
    this->previous_data = (rand() % 100) + 1;
    this->tlmWrite_SCIENCE_SIM_DATA(this->previous_data);
  }

} // end namespace Ref

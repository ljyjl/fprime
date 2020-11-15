####
# 'Ref' Deployment:
#
# This sets up the build for the 'Ref' Application, including the custom reference
# components. In addition, it imports FPrime.cmake, which includes the core F Prime
# components.
#
# This file has several sections.
#
# 1. Header Section: define basic properties of the build
# 2. F prime core: includes all F prime core components, and build-system properties
# 3. Local subdirectories: contains all deployment specific directory additions
####

##
# Section 1: Basic Project Setup
#
# This contains the basic project information. Specifically, a cmake version and
# project definition.
##
project(Ref C CXX)
cmake_minimum_required(VERSION 3.5)
set(FPRIME_FRAMEWORK_PATH "${CMAKE_CURRENT_LIST_DIR}/.." CACHE PATH "Location of F prime framework" FORCE)
set(FPRIME_PROJECT_ROOT "${CMAKE_CURRENT_LIST_DIR}/.." CACHE PATH "Root path of F prime project" FORCE)

##
# Section 2: F prime Core
#
# This includes all of the F prime core components, and imports the make-system. F prime core
# components will be placed in the F-Prime binary subdirectory to keep them from
# colliding with deployment specific items.
##
include("${CMAKE_CURRENT_LIST_DIR}/../cmake/FPrime.cmake")
# NOTE: register custom targets between these two lines
include("${CMAKE_CURRENT_LIST_DIR}/../cmake/FPrime-Code.cmake")
# Note: when building a deployment outside of the F prime core directories, then the
# build root must be re-mapped for use with the standard build system components.
#
# In this way, the module names can be predicted as an offset from the (new) build
# root, without breaking the standard locations of F prime.
#
# Uncomment the following lines, and set them to the BUILD_ROOT of your deployment,
# which is typically one directory up from the CMakeLists.txt in the deployment dir.
#set(FPRIME_CURRENT_BUILD_ROOT "${CMAKE_CURRENT_LIST_DIR}/..")
#message(STATUS "F prime BUILD_ROOT currently set to: ${FPRIME_CURRENT_BUILD_ROOT}")

##
# Section 3: Components and Topology
#
# This section includes deployment specific directories. This allows use of non-
# core components in the topology, which is also added here.
##
# Add component subdirectories
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/PingReceiver/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/RecvBuffApp/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/SendBuffApp/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/SignalGen/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/TemperaturePorts/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/TempSim/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/TempDriver/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/TempManager/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/SchedulerPorts/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/HealthMonitorPorts/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/HealthMonitor/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/SciencePorts/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/GeneralPorts/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/ScienceSim/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/ScienceDriver/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/ScienceManager/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/ControllerPorts/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Controller/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Scheduler/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/SubPorts/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Thermometer/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/ThermalControl/")

# Add Topology subdirectory
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Top/")

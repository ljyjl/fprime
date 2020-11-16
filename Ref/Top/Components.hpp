#ifndef __LITS_COMPONENTS_HEADER__
#define __LITS_COMPONENTS_HEADER__
#include <Svc/ActiveRateGroup/ActiveRateGroupImpl.hpp>
#include <Svc/RateGroupDriver/RateGroupDriverImpl.hpp>

#include <Svc/CmdDispatcher/CommandDispatcherImpl.hpp>
#include <Svc/CmdSequencer/CmdSequencerImpl.hpp>
#include <Svc/PassiveConsoleTextLogger/ConsoleTextLoggerImpl.hpp>
#include <Svc/ActiveLogger/ActiveLoggerImpl.hpp>
#include <Svc/LinuxTime/LinuxTimeImpl.hpp>
#include <Svc/TlmChan/TlmChanImpl.hpp>
#include <Svc/PrmDb/PrmDbImpl.hpp>
#include <Fw/Obj/SimpleObjRegistry.hpp>
#include <Svc/FileUplink/FileUplink.hpp>
#include <Svc/FileDownlink/FileDownlink.hpp>
#include <Svc/BufferManager/BufferManager.hpp>
#include <Svc/Health/HealthComponentImpl.hpp>

#include <Ref/RecvBuffApp/RecvBuffComponentImpl.hpp>
#include <Ref/SendBuffApp/SendBuffComponentImpl.hpp>
#include <Ref/PingReceiver/PingReceiverComponentImpl.hpp>
#include <Ref/SignalGen/SignalGen.hpp>
#include <Svc/AssertFatalAdapter/AssertFatalAdapterComponentImpl.hpp>
#include <Svc/FatalHandler/FatalHandlerComponentImpl.hpp>
#include <Drv/BlockDriver/BlockDriverImpl.hpp>
#include <Drv/SocketIpDriver/SocketIpDriverComponentImpl.hpp>
#include <Svc/GroundInterface/GroundInterface.hpp>

//#include <Ref/TempSim/TempSimComponentImpl.hpp>
//#include <Ref/TempDriver/TempDriverComponentImpl.hpp>
//#include <Ref/TempManager/TempManagerComponentImpl.hpp>
//#include <Ref/HealthMonitor/HealthMonitorComponentImpl.hpp>
//#include <Ref/ScienceSim/ScienceSimComponentImpl.hpp>
//#include <Ref/ScienceDriver/ScienceDriverComponentImpl.hpp>
//#include <Ref/ScienceManager/ScienceManagerComponentImpl.hpp>
//#include <Ref/Controller/ControllerComponentImpl.hpp>
//#include <Ref/Scheduler/SchedulerComponentImpl.hpp>
#include <Ref/Thermometer/ThermometerComponentImpl.hpp>
#include <Ref/ThermalControl/ThermalControlComponentImpl.hpp>

void constructRefArchitecture(void);
bool constructApp(bool dump, U32 port_number, char* hostname);
void exitTasks(void);


extern Svc::RateGroupDriverImpl rateGroupDriverComp;
extern Svc::ActiveRateGroupImpl rateGroup1Comp, rateGroup2Comp, rateGroup3Comp;
extern Svc::CmdSequencerComponentImpl cmdSeq;
extern Svc::GroundInterfaceComponentImpl groundIf;
extern Svc::ConsoleTextLoggerImpl textLogger;
extern Svc::ActiveLoggerImpl eventLogger;
extern Svc::LinuxTimeImpl linuxTime;
extern Svc::TlmChanImpl chanTlm;
extern Svc::CommandDispatcherImpl cmdDisp;
extern Svc::PrmDbImpl prmDb;
extern Svc::FileUplink fileUplink;
extern Svc::FileDownlink fileDownlink;
extern Svc::BufferManager fileDownlinkBufferManager;
extern Svc::BufferManager fileUplinkBufferManager;
extern Svc::AssertFatalAdapterComponentImpl fatalAdapter;
extern Svc::FatalHandlerComponentImpl fatalHandler;
extern Svc::HealthImpl health;

extern Drv::BlockDriverImpl blockDrv;

extern Ref::RecvBuffImpl recvBuffComp;
extern Ref::SendBuffImpl sendBuffComp;
extern Ref::SignalGen SG1 , SG2, SG3, SG4, SG5;
extern Ref::PingReceiverComponentImpl pingRcvr;
extern Drv::SocketIpDriverComponentImpl socketIpDriver;

//extern Ref::TempSimComponentImpl tempSim;
//extern Ref::TempDriverComponentImpl tempDriver;
//extern Ref::TempManagerComponentImpl tempManager;
//extern Ref::HealthMonitorComponentImpl healthMonitor;
//extern Ref::ScienceSimComponentImpl scienceSim;
//extern Ref::ScienceDriverComponentImpl scienceDriver;
//extern Ref::ScienceManagerComponentImpl scienceManager;
//extern Ref::ControllerComponentImpl controller;
//extern Ref::SchedulerComponentImpl scheduler;
extern Ref::ThermometerComponentImpl thermometer;
extern Ref::ThermalControlComponentImpl thermalControl;

#endif

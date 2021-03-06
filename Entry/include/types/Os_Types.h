/**
 * WhatsApp - the open source AUTOSAR platform https://github.com/parai
 *
 * Copyright (C) 2014  WhatsApp <parai@foxmail.com>
 *
 * This source code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published by the
 * Free Software Foundation; See <http://www.gnu.org/licenses/old-licenses/gpl-2.0.txt>.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * for more details.
 * Version: AUTOSAR 4.2.0
 * Generated by arxml.py
 */
#ifndef OS_TYPES_H
#define OS_TYPES_H

/* ============================ [ INCLUDES  ] ====================================================== */
#include "Std_Types.h"
#include "Gpt.h"
#include "EcuC.h"
#ifdef __cplusplus
namespace autosar {
extern "C" {
#endif
/* ============================ [ MACROS    ] ====================================================== */
/* ============================ [ TYPES     ] ====================================================== */
/* This container defines which type of notification is used when the alarm expires. */
typedef struct Os_AlarmActionType_tag
{
    int TODO; // TODO
} Os_AlarmActionType ;

/* This specifies the type of autostart for the alarm.. */
typedef enum
{
	OS_ALARMAUTOSTARTTYPE_ABSOLUTE,
	OS_ALARMAUTOSTARTTYPE_RELATIVE
} Os_AlarmAutostartTypeType ;

/* If present this container defines if an alarm is started automatically at system start-up depending
 *  on the application mode.
 */
typedef struct Os_AlarmAutostartType_tag
{
/* The relative or absolute tick value when the alarm expires for the first time. Note that for
 *  an alarm which is RELATIVE the value must be at bigger than 0.
 */
	uint64 OsAlarmAlarmTime ;
	Os_AlarmAutostartTypeType OsAlarmAutostartType ;
/* Cycle time of a cyclic alarm in ticks. If the value is 0 than the alarm is not cyclic. */
	uint64 OsAlarmCycleTime ;
/* Reference to the application modes for which the AUTOSTART shall be performed */
/* /AUTOSAR/EcucDefs/Os/OsAppMode */
    struct Os_AppModeType_tag* OsAlarmAppModeRef ;
} Os_AlarmAutostartType ;

/* Container to structure the OS-Application-specific hooks */
typedef struct Os_ApplicationHooksType_tag
{
/* true: Hook is called
                                                false: Hook is not called */
/* Select the OS-Application error hook. */
	boolean OsAppErrorHook ;
/* true: Hook is called
                                                false: Hook is not called */
/* Select the OS-Application specific shutdown hook for the OS-Application. */
	boolean OsAppShutdownHook ;
/* true: Hook is called
                                                false: Hook is not called */
/* Select the OS-Application specific startup hook for the OS-Application. */
	boolean OsAppStartupHook ;
} Os_ApplicationHooksType ;

/* Trusted function (as part of a trusted OS-Application) available to other OS-Applications. This
 *  also supersedes the OSEK OIL attribute TRUSTED in APPLICATION because the optionality of this
 *  parameter is describing that already.
 */
/* TODO: */
typedef void (*Os_TrustedFunctionNameType)(void);

/* Container to structure the configration parameters of trusted functions */
typedef struct Os_ApplicationTrustedFunctionType_tag
{
	Os_TrustedFunctionNameType OsTrustedFunctionName ;
} Os_ApplicationTrustedFunctionType ;

/* This Container contains the information who will drive the counter. */
typedef struct Os_DriverType_tag
{
/* Reference to the GPT channel. */
/* /AUTOSAR/EcucDefs/Gpt/GptChannelConfigSet/GptChannelConfiguration */
	Gpt_ChannelConfigurationType* OsGptChannelRef ;
} Os_DriverType ;

/* Allows the user to define constants which can be e.g. used to compare time values with timer
 *  tick values.
 */
typedef struct Os_TimeConstantType_tag
{
/* This parameter contains the value of the constant in seconds. */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 OsTimeValue ;
} Os_TimeConstantType ;

/* This parameter contains the natural type or unit of the counter. */
typedef enum
{
	OS_COUNTERTYPE_HARDWARE,
	OS_COUNTERTYPE_SOFTWARE
} Os_CounterTypeType ;

/* Data properties of the data to be transferred on the IOC communication channel. */
typedef struct Os_IocDataPropertiesType_tag
{
/* This parameter is used to define in which order the data is send, e.g. whether IocSendGroup(A,B)
 *  or IocSendGroup(B,A) shall be used.
 */
	uint8 OsIocDataPropertyIndex ;
/* Initial Value for the data to be transferred on the IOC communication channel. */
	char* OsIocInitValue ;
/* This is the type of the data to be transferred on the IOC communication channel. This attribute
 *  is necessary to generate the parameter type of the Ioc functions. Additionally this information
 *  should be used to compute the data size for necessary data copy operations within the Ioc module.
 */
/* If more than one attribute is defined, the IOC generator should generate an IocXxxGroup function
 *  (Xxx= CHOICE [Send, Receive, Write, Read]).
 * 
 *                                                         N:1 communication (Multiplicity of OsIocSenderProperties
 *  > 1) is only allowed for multiplicity of OsIocDataRef = 1
 */
	/*TODO:IMPLEMENTATION-DATA-TYPE*/void* OsIocDataTypeRef ;
} Os_IocDataPropertiesType ;

/* This parameter is used to select whether this communication is implemented as a macro or as
 *  a function.
 */
typedef enum
{
	OS_IOCFUNCTIONIMPLEMENTATIONKIND_DO_NOT_CARE,
	OS_IOCFUNCTIONIMPLEMENTATIONKIND_FUNCTION,
	OS_IOCFUNCTIONIMPLEMENTATIONKIND_MACRO
} Os_IocFunctionImplementationKindType ;

/* This attribute defines the name of a callback function that the IOC shall call on the receiving
 *  core for each data reception.
 */
/* TODO: */
typedef void (*Os_IocReceiverPullCBType)(void);

/* Representation of receiver properties for one communication. For each OsIocCommunication (1:1
 *  or N:1) one receiver has to be defined. This container should be instanciated within an OsIocCommunication.
 */
typedef struct Os_IocReceiverPropertiesType_tag
{
	Os_IocFunctionImplementationKindType OsIocFunctionImplementationKind ;
/* In case of non existence of this attribute no ReceiverPullCB notification shall be applied by
 *  the IOC. The name of the function shall begin with the name of the receiving module, followed
 *  with a callback name and followed by the IocId.
 * 
 *                                                         Example: void RTE_ReceiverPullCB_RTE25
 *  (void).
 * 
 *                                                         If this attribute does not exist, it
 *  means that no ReceiverPullCB shall be called (No notification from IOC is required). If this
 *  attribute exists the IOC shall call the callback function on the receiving core.
 */
	Os_IocReceiverPullCBType OsIocReceiverPullCB ;
/* This attribute is a reference to the receiving OsApplication instance defined in the configuration
 *  file of the OS.
 */
/* This information allows for the generator to get additional information necessary for the code
 *  generation like:
 *                                                         * The protection properties of the communicating
 *  OsApplications to find out which protections have to be crossed
 *                                                         * The core identifiers to find out if
 *  an intra or an inter core communication has to be realized
 *                                                         * Interrupt details in case of cross
 *  core notification to realize over IRQs
 */
/* /AUTOSAR/EcucDefs/Os/OsApplication */
    struct Os_ApplicationType_tag* OsIocReceivingOsApplicationRef ;
} Os_IocReceiverPropertiesType ;

/* Representation of sender properties for one communication. For each OsIocCommunication one (1:1)
 *  or many senders (N:1) have to be defined. Multiplicity > 1 (N:1 communication) is only allowed
 *  for Multiplicity of OsIocDataTypeRef = 1.
 */
typedef struct Os_IocSenderPropertiesType_tag
{
	Os_IocFunctionImplementationKindType OsIocFunctionImplementationKind ;
/* This parameter does not exist in 1:1 communication. */
/* Representation of a sender in a N:1 communication to distinguish between senders. */
	uint8 OsIocSenderId ;
/* This attribute is a reference to the sending OS-Application instance defined in the configuration
 *  file of the OS.
 */
/* This information shall allows the generator to get additional information necessary for the
 *  code generation like:
 *                                                         * The protection properties of the communicating
 *  OS-Applications to find out which protection boundaries have to be crossed.
 *                                                         * The core identifiers to find out if
 *  an intra or an inter core communication has to be realized
 *                                                         * Interrupt details in case of cross
 *  core notification to realize over IRQs
 */
/* /AUTOSAR/EcucDefs/Os/OsApplication */
    struct Os_ApplicationType_tag* OsIocSendingOsApplicationRef ;
} Os_IocSenderPropertiesType ;

/* Representation of a 1:1 or N:1 communication between software parts located in different OS-Applications
 *  that are bound to the same or to different cores.
 */
typedef struct Os_IocCommunicationType_tag
{
	Os_IocDataPropertiesType* OsIocDataProperties ;
	Os_IocReceiverPropertiesType* OsIocReceiverProperties ;
/* This container should be instanciated within an OsIocCommunication. */
	Os_IocSenderPropertiesType* OsIocSenderProperties ;
/* This configuration information shall allow the optimization of the needed memory for communications
 *  requiring buffers within the RTE and within the IOC.
 */
/* This attribute defines the size of the IOC internal queue to be allocated for a queued communication.
 */
	uint32 OsIocBufferLength ;
} Os_IocCommunicationType ;

/* This container contains a list of times the interrupt uses resources. */
typedef struct Os_IsrResourceLockType_tag
{
/* This parameter contains the maximum time the interrupt is allowed to hold the given resource
 *  (in seconds).
 */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 OsIsrResourceLockBudget ;
/* Reference to the resource the locking time is depending on */
/* /AUTOSAR/EcucDefs/Os/OsResource */
    struct Os_ResourceType_tag* OsIsrResourceLockResourceRef ;
} Os_IsrResourceLockType ;

/* This container contains all parameters which are related to timing protection */
typedef struct Os_IsrTimingProtectionType_tag
{
	Os_IsrResourceLockType* OsIsrResourceLock ;
/* This parameter contains the maximum time for which the ISR is allowed to lock all interrupts
 *  (via SuspendAllInterrupts() or DisableAllInterrupts()) (in seconds).
 */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 OsIsrAllInterruptLockBudget ;
/* The parameter contains the maximum allowed execution time of the interrupt (in seconds). */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 OsIsrExecutionBudget ;
/* This parameter contains the maximum time for which the ISR is allowed to lock all Category 2
 *  interrupts (via SuspendOSInterrupts()) (in seconds).
 */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 OsIsrOsInterruptLockBudget ;
/* This parameter contains the minimum inter-arrival time between successive interrupts (in seconds). */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 OsIsrTimeFrame ;
} Os_IsrTimingProtectionType ;

/* This attribute specifies the category of this ISR. */
typedef enum
{
	OS_ISRCATEGORY_CATEGORY_1,
	OS_ISRCATEGORY_CATEGORY_2
} Os_IsrCategoryType ;

/* Container to structure all hooks belonging to the OS */
typedef struct Os_HooksType_tag
{
/* true: Hook is called
                                                false: Hook is not called */
/* Error hook as defined by OSEK */
	boolean OsErrorHook ;
/* true: Hook is called
                                                false: Hook is not called */
/* Post-task hook as defined by OSEK */
	boolean OsPostTaskHook ;
/* true: Hook is called
                                                false: Hook is not called */
/* Pre-task hook as defined by OSEK */
	boolean OsPreTaskHook ;
/* true: Protection hook is called on protection error
 *                                                 false: Protection hook is not called
 */
/* Switch to enable/disable the call to the (user supplied) protection hook. */
	boolean OsProtectionHook ;
/* true: Hook is called
                                                false: Hook is not called */
/* Shutdown hook as defined by OSEK */
	boolean OsShutdownHook ;
/* true: Hook is called
                                                false: Hook is not called */
/* Startup hook as defined by OSEK */
	boolean OsStartupHook ;
} Os_HooksType ;

/* A scalability class for each System Object "OS" has to be selected. In order to customize the
 *  operating system to the needs of the user and to take full advantage of the processor features
 *  the operating system can be scaled according to the scalability classes.
 */
typedef enum
{
	OS_SCALABILITYCLASS_SC1,
	OS_SCALABILITYCLASS_SC2,
	OS_SCALABILITYCLASS_SC3,
	OS_SCALABILITYCLASS_SC4
} Os_ScalabilityClassType ;

/* The Status attribute specifies whether a system with standard or extended status has to be used.
 *  Automatic assigment is not supported for this attribute.
 */
typedef enum
{
	OS_STATUS_EXTENDED,
	OS_STATUS_STANDARD
} Os_StatusType ;

/* This specifies the type of the resource. */
typedef enum
{
	OS_RESOURCEPROPERTY_INTERNAL,
	OS_RESOURCEPROPERTY_LINKED,
	OS_RESOURCEPROPERTY_STANDARD
} Os_ResourcePropertyType ;

/* This specifies the type of the autostart for the schedule table. */
typedef enum
{
	OS_SCHEDULETABLEAUTOSTARTTYPE_ABSOLUTE,
	OS_SCHEDULETABLEAUTOSTARTTYPE_RELATIVE,
	OS_SCHEDULETABLEAUTOSTARTTYPE_SYNCHRON
} Os_ScheduleTableAutostartTypeType ;

/* This container specifies if and how the schedule table is started on startup of the Operating
 *  System. The options to start a schedule table correspond to the API calls to start schedule
 *  tables during runtime.
 */
typedef struct Os_ScheduleTableAutostartType_tag
{
	Os_ScheduleTableAutostartTypeType OsScheduleTableAutostartType ;
/* Relative offset in ticks when the schedule table starts. Only used if the OsScheduleTableAutostartType
 *  is RELATIVE.
 */
/* Absolute autostart tick value when the schedule table starts. Only used if the OsScheduleTableAutostartType
 *  is ABSOLUTE.
 */
	uint64 OsScheduleTableStartValue ;
/* Reference in which application modes the schedule table should be started during startup */
/* /AUTOSAR/EcucDefs/Os/OsAppMode */
    struct Os_AppModeType_tag* OsScheduleTableAppModeRef ;
} Os_ScheduleTableAutostartType ;

/* Event that is triggered by that schedule table. */
typedef struct Os_ScheduleTableEventSettingType_tag
{
/* Reference to event that will be set by action */
/* /AUTOSAR/EcucDefs/Os/OsEvent */
    struct Os_EventType_tag* OsScheduleTableSetEventRef ;
/* /AUTOSAR/EcucDefs/Os/OsTask */
    struct Os_TaskType_tag* OsScheduleTableSetEventTaskRef ;
} Os_ScheduleTableEventSettingType ;

/* Task that is triggered by that schedule table. */
typedef struct Os_ScheduleTableTaskActivationType_tag
{
/* Reference to task that will be activated by action */
/* /AUTOSAR/EcucDefs/Os/OsTask */
    struct Os_TaskType_tag* OsScheduleTableActivateTaskRef ;
} Os_ScheduleTableTaskActivationType ;

/* Adjustable expiry point */
typedef struct Os_ScheduleTblAdjustableExpPointType_tag
{
/* The maximum positive adjustment that can be made to the expiry point offset (in ticks). */
	uint64 OsScheduleTableMaxLengthen ;
/* The maximum negative adjustment that can be made to the expiry point offset (in ticks). */
	uint64 OsScheduleTableMaxShorten ;
} Os_ScheduleTblAdjustableExpPointType ;

/* The point on a Schedule Table at which the OS activates tasks and/or sets events */
typedef struct Os_ScheduleTableExpiryPointType_tag
{
	Os_ScheduleTableEventSettingType* OsScheduleTableEventSetting ;
	Os_ScheduleTableTaskActivationType* OsScheduleTableTaskActivation ;
	Os_ScheduleTblAdjustableExpPointType* OsScheduleTblAdjustableExpPoint ;
/* The offset from zero (in ticks) at which the expiry point is to be processed. */
	uint64 OsScheduleTblExpPointOffset ;
} Os_ScheduleTableExpiryPointType ;

/* AUTOSAR OS provides support for synchronisation in two ways: explicit and implicit. */
typedef enum
{
	OS_SCHEDULETBLSYNCSTRATEGY_EXPLICIT,
	OS_SCHEDULETBLSYNCSTRATEGY_IMPLICIT,
	OS_SCHEDULETBLSYNCSTRATEGY_NONE
} Os_ScheduleTblSyncStrategyType ;

/* This container specifies the synchronization parameters of the schedule table. */
typedef struct Os_ScheduleTableSyncType_tag
{
/* This configuration is only valid if the explicit synchronisation is used. */
	uint64 OsScheduleTblExplicitPrecision ;
	Os_ScheduleTblSyncStrategyType OsScheduleTblSyncStrategy ;
} Os_ScheduleTableSyncType ;

/* This container determines whether the task is activated during the system start-up procedure
 *  or not for some specific application modes.
 */
typedef struct Os_TaskAutostartType_tag
{
/* Reference to application modes in which that task is activated on startup of the OS */
/* /AUTOSAR/EcucDefs/Os/OsAppMode */
    struct Os_AppModeType_tag* OsTaskAppModeRef ;
} Os_TaskAutostartType ;

/* This container contains the worst case time between getting and releasing a given resource (in
 *  seconds).
 */
typedef struct Os_TaskResourceLockType_tag
{
/* This parameter contains the maximum time the task is allowed to lock the resource (in seconds) */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 OsTaskResourceLockBudget ;
/* Reference to the resource used by the task */
/* /AUTOSAR/EcucDefs/Os/OsResource */
    struct Os_ResourceType_tag* OsTaskResourceLockResourceRef ;
} Os_TaskResourceLockType ;

/* This container contains all parameters regarding timing protection of the task. */
typedef struct Os_TaskTimingProtectionType_tag
{
	Os_TaskResourceLockType* OsTaskResourceLock ;
/* This parameter contains the maximum time for which the task is allowed to lock all interrupts
 *  (via SuspendAllInterrupts() or DisableAllInterrupts()) (in seconds).
 */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 OsTaskAllInterruptLockBudget ;
/* This parameter contains the maximum allowed execution time of the task (in seconds). */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 OsTaskExecutionBudget ;
/* This parameter contains the maximum time for which the task is allowed to lock all Category
 *  2 interrupts (via SuspendOSInterrupts()) (in seconds).
 */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 OsTaskOsInterruptLockBudget ;
/* The minimum inter-arrival time between activations and/or releases of a task (in seconds). */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 OsTaskTimeFrame ;
} Os_TaskTimingProtectionType ;

/* The OsTaskSchedule attribute defines the preemptability of the task. */
typedef enum
{
	OS_TASKSCHEDULE_FULL,
	OS_TASKSCHEDULE_NON
} Os_TaskScheduleType ;

/* An OsAlarm may be used to asynchronously inform or activate a specific task. It is possible
 *  to start alarms automatically at system start-up depending on the application mode.
 */
typedef struct Os_AlarmType_tag
{
	Os_AlarmActionType* OsAlarmAction ;
	Os_AlarmAutostartType* OsAlarmAutostart ;
/* Reference to applications which have an access to this object. */
/* /AUTOSAR/EcucDefs/Os/OsApplication */
    struct Os_ApplicationType_tag* OsAlarmAccessingApplication ;
/* Reference to the assigned counter for that alarm */
/* /AUTOSAR/EcucDefs/Os/OsCounter */
    struct Os_CounterType_tag* OsAlarmCounterRef ;
} Os_AlarmType ;

/* OsAppMode is the object used to define OSEK OS properties for an OSEK OS application mode. */
typedef struct Os_AppModeType_tag
{
    AppModeType AppMode;
} Os_AppModeType ;

/* An AUTOSAR OS must be capable of supporting a collection of OS objects (tasks, interrupts, alarms,
 *  hooks etc.) that form a cohesive functional unit. This collection of objects is termed an OS-Application.
 */
typedef struct Os_ApplicationType_tag
{
	Os_ApplicationHooksType* OsApplicationHooks ;
	Os_ApplicationTrustedFunctionType* OsApplicationTrustedFunction ;
/* ID of the core onto which the OsApplication is bound. */
	uint16 OsApplicationCoreAssignment ;
/* true: OS-Application is trusted
 *                                         false: OS-Application is not trusted (default)
 */
/* Parameter to specify if an OS-Application is trusted or not. */
	boolean OsTrusted ;
/* Specifies the OsAlarms that belong to the OsApplication. */
/* /AUTOSAR/EcucDefs/Os/OsAlarm */
	Os_AlarmType* OsAppAlarmRef ;
/* References the OsCounters that belong to the OsApplication. */
/* /AUTOSAR/EcucDefs/Os/OsCounter */
    struct Os_CounterType_tag* OsAppCounterRef ;
/* Denotes which "EcucPartition" is implemented by this "OSApplication". */
/* /AUTOSAR/EcucDefs/EcuC/EcucPartitionCollection/EcucPartition */
	EcuC_PartitionType* OsAppEcucPartitionRef ;
/* references which OsIsrs belong to the OsApplication */
/* /AUTOSAR/EcucDefs/Os/OsIsr */
    struct Os_IsrType_tag* OsAppIsrRef ;
/* References the OsScheduleTables that belong to the OsApplication. */
/* /AUTOSAR/EcucDefs/Os/OsScheduleTable */
    struct Os_ScheduleTableType_tag* OsAppScheduleTableRef ;
/* references which OsTasks belong to the OsApplication */
/* /AUTOSAR/EcucDefs/Os/OsTask */
    struct Os_TaskType_tag* OsAppTaskRef ;
/* Optionally one task of an OS-Application may be defined as Restart Task. */
/* Multiplicity = 1: Restart Task is activated by the Operating System if the protection hook requests
 *  it.
 * 
 *                                         Multiplicity = 0: No task is automatically started after
 *  a protection error happened.
 */
/* /AUTOSAR/EcucDefs/Os/OsTask */
    struct Os_TaskType_tag* OsRestartTask ;
} Os_ApplicationType ;

/* Configuration information for the counters that belong to the OsApplication. */
typedef struct Os_CounterType_tag
{
/* This configuration is only valid if the counter has OsCounterType set to HARDWARE.
 * 
 *                                         If the container does not exist (multiplicity=0) the
 *  timer is managed by the OS internally (OSINTERNAL).
 * 
 *                                         If the container exists the OS can use the GPT interface
 *  to manage the timer. The user have to supply the GPT channel.
 * 
 *                                         If the counter is driven by some other (external to
 *  the OS) source (like a TPU for example) this must be described as a vendor specific extension.
 */
	Os_DriverType* OsDriver ;
/* A time value will be converted to a timer tick value during generation and can later on accessed
 *  via the OsConstName. The conversation is done by rounding time values to the nearest fitting
 *  tick value.
 */
	Os_TimeConstantType* OsTimeConstant ;
/* Maximum possible allowed value of the system counter in ticks. */
	uint64 OsCounterMaxAllowedValue ;
/* The MINCYCLE attribute specifies the minimum allowed number of counter ticks for a cyclic alarm
 *  linked to the counter.
 */
	uint64 OsCounterMinCycle ;
/* The TICKSPERBASE attribute specifies the number of ticks required to reach a counterspecific
 *  unit. The interpretation is implementation-specific.
 */
	uint32 OsCounterTicksPerBase ;
	Os_CounterTypeType OsCounterType ;
/* Time of one counter tick in seconds. */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 OsSecondsPerTick ;
/* Reference to applications which have an access to this object. */
/* /AUTOSAR/EcucDefs/Os/OsApplication */
	Os_ApplicationType* OsCounterAccessingApplication ;
} Os_CounterType ;

/* Representation of OS events in the configuration context. Adopted from the OSEK OIL specification. */
typedef struct Os_EventType_tag
{
/* If event mask would be set to AUTO in OIL, this parameter should be omitted here. */
	uint64 OsEventMask ;
} Os_EventType ;

/* Configuration of the IOC (Inter OS Application Communicator). */
typedef struct Os_IocType_tag
{
/* The name shall begin with the name of the sending software service and be followed by a unique
 *  identifier delivered by the sending software service. In the case of RTE as user attention
 *  shall be paid on the fact that uniqueness for identifier names has to be reached over ports,
 *  data elements, object instances and maybe additional identification properties (E.g. Case 1:N
 *  mapping to 1:1).
 * 
 *                                         Example:
 *                                         - <NameSpace>_UniqueID
 */
	Os_IocCommunicationType* OsIocCommunication ;
} Os_IocType ;

/* The OsIsr container represents an OSEK interrupt service routine. */
typedef struct Os_IsrType_tag
{
/* If the container exists, the timing protection is used for this interrupt. If the container
 *  does not exist, the interrupt is not supervised regarding timing violations.
 */
	Os_IsrTimingProtectionType* OsIsrTimingProtection ;
	Os_IsrCategoryType OsIsrCategory ;
/* This reference defines the resources accessed by this ISR. */
/* /AUTOSAR/EcucDefs/Os/OsResource */
    struct Os_ResourceType_tag * OsIsrResourceRef ;
} Os_IsrType ;

/* OS is the object used to define OSEK OS properties for an OSEK application. */
typedef struct Os_OSType_tag
{
	Os_HooksType* OsHooks ;
/* The OS uses the value internally. It depends on the ECU HW. */
/* Maximum number of cores that are controlled by the OS. */
	uint16 OsNumberOfCores ;
/* If the scalability class is omitted this translates to the OIL AUTO mechanism. */
	Os_ScalabilityClassType OsScalabilityClass ;
/* true: Stacks are monitored
                                        false: Stacks are not monitored */
/* Select stack monitoring of Tasks/Category 2 ISRs */
	boolean OsStackMonitoring ;
	Os_StatusType OsStatus ;
/* As defined by OSEK */
	boolean OsUseGetServiceId ;
/* As defined by OSEK */
	boolean OsUseParameterAccess ;
/* The OsUseResScheduler attribute defines whether the resource RES_SCHEDULER is used within the
 *  application.
 */
	boolean OsUseResScheduler ;
} Os_OSType ;

/* An OsResource object is used to co-ordinate the concurrent access by tasks and ISRs to a shared
 *  resource, e.g. the scheduler, any program sequence, memory or any hardware area.
 */
typedef struct Os_ResourceType_tag
{
	Os_ResourcePropertyType OsResourceProperty ;
/* Reference to applications which have an access to this object. */
/* /AUTOSAR/EcucDefs/Os/OsApplication */
	Os_ApplicationType* OsResourceAccessingApplication ;
/* The link to the resource. Must be valid if OsResourceProperty is LINKED. If OsResourceProperty
 *  is not LINKED the value is ignored.
 */
/* /AUTOSAR/EcucDefs/Os/OsResource */
    struct Os_ResourceType_tag* OsResourceLinkedResourceRef ;
} Os_ResourceType ;

/* An OsScheduleTable addresses the synchronization issue by providing an encapsulation of a statically
 *  defined set of alarms that cannot be modified at runtime.
 */
typedef struct Os_ScheduleTableType_tag
{
	Os_ScheduleTableAutostartType* OsScheduleTableAutostart ;
	Os_ScheduleTableExpiryPointType* OsScheduleTableExpiryPoint ;
	Os_ScheduleTableSyncType* OsScheduleTableSync ;
/* This parameter defines the modulus of the schedule table (in ticks). */
	uint64 OsScheduleTableDuration ;
/* false: the schedule table processing stops when the final expiry point is processed. */
/* true: first expiry point on the schedule table shall be processed at final expiry point delay
 *  ticks after the final expiry point is processed.
 */
	boolean OsScheduleTableRepeating ;
/* Reference to applications which have an access to this object. */
/* /AUTOSAR/EcucDefs/Os/OsApplication */
	Os_ApplicationType* OsSchTblAccessingApplication ;
/* This parameter contains a reference to the counter which drives the schedule table. */
/* /AUTOSAR/EcucDefs/Os/OsCounter */
	Os_CounterType* OsScheduleTableCounterRef ;
} Os_ScheduleTableType ;

/* An OsSpinlock object is used to co-ordinate concurrent access by TASKs/ISR2s on different cores
 *  to a shared resource.
 */
typedef struct Os_SpinlockType_tag
{
/* Reference to OsApplications that have an access to this object. */
/* /AUTOSAR/EcucDefs/Os/OsApplication */
	Os_ApplicationType* OsSpinlockAccessingApplication ;
/* Reference to OsApplications that have an access to this object. */
/* To check whether a spinlock can be occupied (in a nested way) without any danger of deadlock,
 *  a linked list of spinlocks can be defined. A spinlock can only be occupied in the order of
 *  the linked list. It is allowed to skip a spinlock.
 * 
 *                                         If no linked list is specified, spinlocks cannot be
 *  nested.
 */
/* /AUTOSAR/EcucDefs/Os/OsSpinlock */
    struct Os_SpinlockType_tag* OsSpinlockSuccessor ;
} Os_SpinlockType ;

/* This container represents an OSEK task. */
typedef struct Os_TaskType_tag
{
/* If the task shall be activated during the system start-up, this container is present and holds
 *  the references to the application modes in which the task is auto-started.
 */
	Os_TaskAutostartType* OsTaskAutostart ;
	Os_TaskTimingProtectionType* OsTaskTimingProtection ;
/* This attribute defines the maximum number of queued activation requests for the task. A value
 *  equal to "1" means that at any time only a single activation is permitted for this task. Note
 *  that the value must be a natural number starting at 1.
 */
	uint32 OsTaskActivation ;
/* OSEK OS defines the lowest priority as zero (0); larger values correspond to higher priorities. */
/* The priority of a task is defined by the value of this attribute. This value has to be understood
 *  as a relative value, i.e. the values show only the relative ordering of the tasks.
 */
	uint32 OsTaskPriority ;
/* If this attribute is set to NON, no internal resources may be assigned to this task. */
	Os_TaskScheduleType OsTaskSchedule ;
/* Reference to applications which have an access to this object. */
/* /AUTOSAR/EcucDefs/Os/OsApplication */
	Os_ApplicationType* OsTaskAccessingApplication ;
/* This reference defines the list of events the extended task may react on. */
/* /AUTOSAR/EcucDefs/Os/OsEvent */
	Os_EventType* OsTaskEventRef ;
/* This reference defines a list of resources accessed by this task. */
/* /AUTOSAR/EcucDefs/Os/OsResource */
	Os_ResourceType* OsTaskResourceRef ;
} Os_TaskType ;

/* ============================ [ DATAS     ] ====================================================== */
/* ============================ [ DECLARES  ] ====================================================== */
/* ============================ [ LOCALS    ] ====================================================== */
/* ============================ [ FUNCTIONS ] ====================================================== */
#ifdef __cplusplus
}}  /* name space */
#endif
#endif /* OS_TYPES_H */


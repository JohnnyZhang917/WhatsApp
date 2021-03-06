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
#ifndef WDGIF_TYPES_H
#define WDGIF_TYPES_H

/* ============================ [ INCLUDES  ] ====================================================== */
#include "Std_Types.h"
#ifdef __cplusplus
namespace autosar {
extern "C" {
#endif
/* ============================ [ MACROS    ] ====================================================== */
/* ============================ [ TYPES     ] ====================================================== */
/* It contains the information for the selection of a particular Watchdog device in case multiple
 *  Watchdog drivers are connected.
 */
typedef struct WdgIf_DeviceType_tag
{
/* Represents the watchdog interface ID so that it can be referenced by the watchdog manager. */
	uint8 WdgIfDeviceIndex ;
/* Reference to the watchdog drivers that are controlled by the watchdog interface. */
/* /AUTOSAR/EcucDefs/Wdg/WdgGeneral */
	Wdg_GeneralType* WdgIfDriverRef ;
} WdgIf_DeviceType ;

/* This container collects all generic watchdog interface parameters. */
typedef struct WdgIf_GeneralType_tag
{
/* true: Development error detection enabled
 *                                         false: Development error detection disabled
 */
/* Pre-processor switch for enabling the development error detection and reporting. */
	boolean WdgIfDevErrorDetect ;
/* true: Version information service enabled
 *                                         false: Version information service disabled
 */
/* Pre-processor switch to enable / disable the service returning the version information. */
	boolean WdgIfVersionInfoApi ;
} WdgIf_GeneralType ;

/* ============================ [ DATAS     ] ====================================================== */
/* ============================ [ DECLARES  ] ====================================================== */
/* ============================ [ LOCALS    ] ====================================================== */
/* ============================ [ FUNCTIONS ] ====================================================== */
#ifdef __cplusplus
}}  /* name space */
#endif
#endif /* WDGIF_TYPES_H */


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
#ifndef DET_TYPES_H
#define DET_TYPES_H

/* ============================ [ INCLUDES  ] ====================================================== */
#include "Std_Types.h"
#ifdef __cplusplus
namespace autosar {
extern "C" {
#endif
/* ============================ [ MACROS    ] ====================================================== */
/* ============================ [ TYPES     ] ====================================================== */
/* Optional list of functions to be called by the Development Error Tracer in context of each call
 *  of Det_ReportError.
 */
/* TODO: 
 * typedef void (*Det_ErrorHookType)(void);
 */

/* Generic configuration parameters of the Det module. */
typedef struct Det_GeneralType_tag
{
/* Only if the parameter is present and set to true, the Det requires the Dlt interface and forwards
 *  it's call to the function Dlt_DetForwardErrorTrace. In this case the optional interface to
 *  Dlt_Det is required.
 */
	boolean DetForwardToDlt ;
/* true: Version info API enabled.
 *                                         false: Version info API disabled.
 */
/* Pre-processor switch to enable / disable the API to read out the modules version information. */
	boolean DetVersionInfoApi ;
} Det_GeneralType ;

/* Configuration of the notification functions. */
typedef struct Det_NotificationType_tag
{
/* The type of these functions shall be identical the type of Det_ReportError itself: Std_ReturnType
 *  (*f)(uint16, uint8, uint8, uint8).
 */
	Det_ErrorHookType DetErrorHook ;
} Det_NotificationType ;

/* ============================ [ DATAS     ] ====================================================== */
/* ============================ [ DECLARES  ] ====================================================== */
/* ============================ [ LOCALS    ] ====================================================== */
/* ============================ [ FUNCTIONS ] ====================================================== */
#ifdef __cplusplus
}}  /* name space */
#endif
#endif /* DET_TYPES_H */


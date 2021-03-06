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
#ifndef LINTP_TYPES_H
#define LINTP_TYPES_H

/* ============================ [ INCLUDES  ] ====================================================== */
#include "Std_Types.h"
#ifdef __cplusplus
namespace autosar {
extern "C" {
#endif
/* ============================ [ MACROS    ] ====================================================== */
/* ============================ [ TYPES     ] ====================================================== */
/* This container contains the channel specific configuration parameter of LinTp. */
typedef struct LinTp_ChannelConfigType_tag
{
/* false: Do drop TP Frames of Not requested LIN-Slaves
 *                                                 true: Drop not TP Frames of Not requested LIN-Slaves
 */
/* Configures if TP Frames of not requested LIN-Slaves are dropped or not. */
	boolean LinTpDropNotRequestedNad ;
/* false: BswM is not called
                                                true: BswM is called */
/* Enables or disables the call of BswM_LinTp_RequestMode() to diagnostic request/response schedule. */
	boolean LinTpScheduleChangeDiag ;
} LinTp_ChannelConfigType ;

/* For each received N-SDU on any channel the node is connected to. */
typedef struct LinTp_RxNSduType_tag
{
/* Range of minimum length is 1 to 4095.
 * 
 *                                                 Note that this is not relevant for Tx. The reason
 *  for this is to have identical structures for Tx and Rx.
 */
/* Data Length Code of this RxNsdu. In case of variable length message, this value indicates the
 *  minimum data length.
 */
	uint16 LinTpDl ;
/* Value in seconds of the N_Cr timeout. N_Cr is the time until reception of the next Consecutive
 *  Frame N_PDU.
 */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 LinTpNcr ;
/* The identifier of the Transport Protocol message. This ID will be the one that is communicated
 *  with upper layers.
 */
	uint16 LinTpRxNSduId ;
/* A N-SDU transported on LIN is identified using the NAD for the specific slave. */
	uint8 LinTpRxNSduNad ;
/* Reference to the global PDU */
/* /AUTOSAR/EcucDefs/EcuC/EcucPduCollection/Pdu */
	EcuC_PduType* LinTpRxNSduPduRef ;
/* Index of the channel this N-SDU belongs to. */
/* /AUTOSAR/EcucDefs/LinIf/LinIfGlobalConfig/LinIfChannel */
	LinIf_ChannelType* LinTpRxNSduChannelRef ;
} LinTp_RxNSduType ;

/* For each transmitted N-SDU on any channel the node is connected to. */
typedef struct LinTp_TxNSduType_tag
{
/* Value in second of the N_As timeout. N_As is the time for transmission of a LIN frame (any N_PDU)
 *  on the part of the sender.
 */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 LinTpNas ;
/* Value in seconds of the performance requirement of N_Cs. N_Cs is the time which elapses between
 *  the transmit request of a CF N-PDU until the transmit request of the next CF N-PDU.
 */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 LinTpNcs ;
/* The identifier of the Transport Protocol message. This ID will be the one that is communicated
 *  with upper layers.
 */
	uint16 LinTpTxNSduId ;
/* A N-SDU transported on LIN is identified using the NAD for the specific slave. */
	uint8 LinTpTxNSduNad ;
/* Reference to the global PDU */
/* /AUTOSAR/EcucDefs/EcuC/EcucPduCollection/Pdu */
	EcuC_PduType* LinTpTxNSduPduRef ;
/* Index of the channel this N-SDU belongs to. */
/* /AUTOSAR/EcucDefs/LinIf/LinIfGlobalConfig/LinIfChannel */
	LinIf_ChannelType* LinTpTxNSduChannelRef ;
} LinTp_TxNSduType ;

/* Container that holds all LIN transport protocol general parameters. */
typedef struct LinTp_GeneralType_tag
{
/* Switches the LinTp_GetVersionInfo function ON or OFF. */
	boolean LinTpVersionInfoApi ;
} LinTp_GeneralType ;

/* This container contains the global configuration parameter of the LinTp. */
typedef struct LinTp_GlobalConfigType_tag
{
	LinTp_ChannelConfigType* LinTpChannelConfig ;
	LinTp_RxNSduType* LinTpRxNSdu ;
	LinTp_TxNSduType* LinTpTxNSdu ;
/* Configures the maximum number of allowed response pending frames. */
	uint16 LinTpMaxNumberOfRespPendingFrames ;
/* Number of transport protocol messages that can be received for all channels this node is connected
 *  to.
 */
	uint16 LinTpNumberOfRxNSdu ;
/* Number of transport protocol messages that can be transmitted for all channels this node is
 *  connected to.
 */
	uint16 LinTpNumberOfTxNSdu ;
/* P2 Timeout when a response pending frame is expected in seconds. */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 LinTpP2Max ;
/* Definition of the P2 timeout observation parameter in seconds. */
/* in fact, it should be type <float> according to arxml, but only supported in tool side*/
	uint64 LinTpP2Timing ;
} LinTp_GlobalConfigType ;

/* ============================ [ DATAS     ] ====================================================== */
/* ============================ [ DECLARES  ] ====================================================== */
/* ============================ [ LOCALS    ] ====================================================== */
/* ============================ [ FUNCTIONS ] ====================================================== */
#ifdef __cplusplus
}}  /* name space */
#endif
#endif /* LINTP_TYPES_H */


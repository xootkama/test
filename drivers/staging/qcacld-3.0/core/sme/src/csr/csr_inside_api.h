/*
<<<<<<< HEAD
 * Copyright (c) 2011-2019 The Linux Foundation. All rights reserved.
=======
 * Copyright (c) 2011-2020 The Linux Foundation. All rights reserved.
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *
 * Permission to use, copy, modify, and/or distribute this software for
 * any purpose with or without fee is hereby granted, provided that the
 * above copyright notice and this permission notice appear in all
 * copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL
 * WARRANTIES WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE
 * AUTHOR BE LIABLE FOR ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL
 * DAMAGES OR ANY DAMAGES WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR
 * PROFITS, WHETHER IN AN ACTION OF CONTRACT, NEGLIGENCE OR OTHER
 * TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION WITH THE USE OR
 * PERFORMANCE OF THIS SOFTWARE.
 */

/*
 * DOC: csr_inside_api.h
 *
 * Define interface only used by CSR.
 */
#ifndef CSR_INSIDE_API_H__
#define CSR_INSIDE_API_H__

#include "csr_support.h"
#include "sme_inside.h"
#include "cds_reg_service.h"
<<<<<<< HEAD

#define CSR_PASSIVE_MAX_CHANNEL_TIME   110
#define CSR_PASSIVE_MIN_CHANNEL_TIME   60

#define CSR_ACTIVE_MAX_CHANNEL_TIME    40
#define CSR_ACTIVE_MIN_CHANNEL_TIME    20

#ifdef WLAN_AP_STA_CONCURRENCY
#define CSR_PASSIVE_MAX_CHANNEL_TIME_CONC   110
#define CSR_PASSIVE_MIN_CHANNEL_TIME_CONC   60

#define CSR_ACTIVE_MAX_CHANNEL_TIME_CONC    27
#define CSR_ACTIVE_MIN_CHANNEL_TIME_CONC    20

#define CSR_REST_TIME_CONC                  100
#define CSR_MIN_REST_TIME_CONC              50
#define CSR_IDLE_TIME_CONC                  25

#endif

#define CSR_MAX_NUM_SUPPORTED_CHANNELS 55

#define CSR_MAX_2_4_GHZ_SUPPORTED_CHANNELS 14

#define CSR_MAX_BSS_SUPPORT            512

/* This number minus 1 means the number of times a channel is scanned before
 * a BSS is remvoed from
 */
/* cache scan result */
#define CSR_AGING_COUNT     3
/* 5 seconds */
#define CSR_SCAN_GET_RESULT_INTERVAL    (5 * QDF_MC_TIMER_TO_SEC_UNIT)
/* 60 seconds */
#define CSR_MIC_ERROR_TIMEOUT  (60 * QDF_MC_TIMER_TO_SEC_UNIT)
/* 60 seconds */
#define CSR_TKIP_COUNTER_MEASURE_TIMEOUT  (60 * QDF_MC_TIMER_TO_SEC_UNIT)

/* the following defines are NOT used by palTimer */
#define CSR_JOIN_FAILURE_TIMEOUT_DEFAULT (3000)
#define CSR_JOIN_FAILURE_TIMEOUT_MIN   (1000)   /* minimal value */
/* These are going against the signed RSSI (int8_t) so it is between -+127 */
#define CSR_BEST_RSSI_VALUE         (-30)       /* RSSI >= this is in CAT4 */
#define CSR_DEFAULT_RSSI_DB_GAP     30  /* every 30 dbm for one category */
#define CSR_BSS_CAP_VALUE_NONE  0       /* not much value */
#define CSR_BSS_CAP_VALUE_HT    1
#define CSR_BSS_CAP_VALUE_VHT    2
#define CSR_BSS_CAP_VALUE_WMM   1
#define CSR_BSS_CAP_VALUE_UAPSD 1
#define CSR_BSS_CAP_VALUE_5GHZ  2

#define CSR_ROAMING_DFS_CHANNEL_DISABLED           (0)
#define CSR_ROAMING_DFS_CHANNEL_ENABLED_NORMAL     (1)
#define CSR_ROAMING_DFS_CHANNEL_ENABLED_ACTIVE     (2)

#define CSR_ACTIVE_SCAN_LIST_CMD_TIMEOUT (1000*30)

=======
#include "wlan_objmgr_vdev_obj.h"

/* This number minus 1 means the number of times a channel is scanned before
 * a BSS is removed from cache scan result
 */
#define CSR_AGING_COUNT     3

/* These are going against the signed RSSI (int8_t) so it is between -+127 */
#define CSR_BEST_RSSI_VALUE         (-30)       /* RSSI >= this is in CAT4 */
#define CSR_DEFAULT_RSSI_DB_GAP     30  /* every 30 dbm for one category */

#ifdef QCA_WIFI_3_0_EMU
#define CSR_ACTIVE_SCAN_LIST_CMD_TIMEOUT (1000*30*20)
#else
#define CSR_ACTIVE_SCAN_LIST_CMD_TIMEOUT (1000*30)
#endif
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/* ***************************************************************************
 * The MAX BSSID Count should be lower than the command timeout value.
 * As in some case auth timeout can take upto 5 sec (in case of SAE auth) try
 * (command timeout/5000 - 1) candidates.
 * ***************************************************************************/
#define CSR_MAX_BSSID_COUNT     (SME_ACTIVE_LIST_CMD_TIMEOUT_VALUE/5000) - 1
#define CSR_CUSTOM_CONC_GO_BI    100
extern uint8_t csr_wpa_oui[][CSR_WPA_OUI_SIZE];
<<<<<<< HEAD
bool csr_is_supported_channel(tpAniSirGlobal pMac, uint8_t channelId);

#define RSSI_THRESHOLD_5GHZ -70
#define BEST_CANDIDATE_RSSI_WEIGHT 50
#define MIN_RSSI (-100)
#define MAX_RSSI 0
#define ROAM_MAX_CHANNEL_WEIGHT 100
#define MAX_CHANNEL_UTILIZATION 100
#define NSS_1X1_WEIGHTAGE 3
#define MAX_ESTIMATED_AIR_TIME_FRACTION 255
#define MAX_AP_LOAD 255

#define LOW_CHANNEL_CONGESTION_WEIGHT 500
#define MODERATE_CHANNEL_CONGESTION_WEIGHT 370
#define CONSIDERABLE_CHANNEL_CONGESTION_WEIGHT 250
#define HIGH_CHANNEL_CONGESTION_WEIGHT 120

#define LOW_CHANNEL_CONGESTION 0
#define MODERATE_CHANNEL_CONGESTION 25
#define CONSIDERABLE_CHANNEL_CONGESTION 50
#define HIGH_CHANNEL_CONGESTION 75
#define EXTREME_CHANNEL_CONGESTION 100

#define EXCELLENT_RSSI -55
#define BAD_RSSI  -80
#define EXCELLENT_RSSI_WEIGHT 100
#define RSSI_BUCKET 5
#define RSSI_WEIGHT_BUCKET 250

#define BEST_CANDIDATE_80MHZ 100
#define BEST_CANDIDATE_40MHZ 70
#define BEST_CANDIDATE_20MHZ 30
#define BEST_CANDIDATE_MAX_BSS_SCORE 10000

#define WLAN_20MHZ_BW_INDEX                  0
#define WLAN_SCORE_40MHZ_BW_INDEX            1
#define WLAN_SCORE_80MHZ_BW_INDEX            2
#define WLAN_SCORE_160MHZ_BW_INDEX           3
#define WLAN_SCORE_MAX_BW_INDEX              4

#define WLAN_NSS_1x1_INDEX                   0
#define WLAN_NSS_2x2_INDEX                   1
#define WLAN_NSS_3x3_INDEX                   2
#define WLAN_NSS_4x4_INDEX                   3
#define WLAN_MAX_NSS_INDEX                   4

#define WLAN_BAND_2G_INDEX                   0
#define WLAN_BAND_5G_INDEX                   1
/* 2 and 3 are reserved */
#define WLAN_MAX_BAND_INDEX                  4

#define WLAN_SCORE_INDEX_0                   0
#define WLAN_SCORE_INDEX_3                   3
#define WLAN_SCORE_INDEX_7                   7
#define WLAN_SCORE_OFFSET_INDEX_7_4          4
#define WLAN_SCORE_INDEX_11                  11
#define WLAN_SCORE_OFFSET_INDEX_11_8         8
#define WLAN_SCORE_MAX_INDEX                 15
#define WLAN_SCORE_OFFSET_INDEX_15_12        12

#define MAX_OCE_WAN_DL_CAP 16

enum csr_scancomplete_nextcommand {
	eCsrNextScanNothing,
	eCsrNextLostLinkScan1Success,
	eCsrNextLostLinkScan1Failed,
	eCsrNextLostLinkScan2Success,
	eCsrNextLostLinkScan2Failed,
	eCsrNextLostLinkScan3Success,
	eCsrNexteScanForSsidSuccess,
	eCsrNextLostLinkScan3Failed,
	eCsrNext11dScan1Failure,
	eCsrNext11dScan1Success,
	eCsrNext11dScan2Failure,
	eCsrNext11dScan2Success,
	eCsrNext11dScanComplete,
	eCsrNexteScanForSsidFailure,
	eCsrNextCheckAllowConc,

=======
bool csr_is_supported_channel(struct mac_context *mac, uint32_t chan_freq);

enum csr_scancomplete_nextcommand {
	eCsrNextScanNothing,
	eCsrNexteScanForSsidSuccess,
	eCsrNexteScanForSsidFailure,
	eCsrNextCheckAllowConc,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
};

enum csr_roamcomplete_result {
	eCsrJoinSuccess,
	eCsrJoinFailure,
	eCsrReassocSuccess,
	eCsrReassocFailure,
	eCsrNothingToJoin,
	eCsrStartBssSuccess,
	eCsrStartBssFailure,
	eCsrSilentlyStopRoaming,
	eCsrSilentlyStopRoamingSaveState,
	eCsrJoinFailureDueToConcurrency,
	eCsrStopBssSuccess,
	eCsrStopBssFailure,
};

<<<<<<< HEAD
struct tag_scanreq_param {
	uint8_t bReturnAfter1stMatch;
	uint8_t fUniqueResult;
	uint8_t freshScan;
	uint8_t hiddenSsid;
	uint8_t reserved;
};

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
struct tag_csrscan_result {
	tListElem Link;
	/* This BSS is removed when it reaches 0 or less */
	int32_t AgingCount;
	/* The bigger the number, the better the BSS.
	 * This value override capValue
	 */
	uint32_t preferValue;
	/* The biggger the better. This value is in use only if we have
	 * equal preferValue
	 */
	uint32_t capValue;
<<<<<<< HEAD
=======
	/* This member must be the last in the structure because the end of
	 * struct bss_description (inside) is an
	 * array with nonknown size at this time
	 */
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	/* Preferred Encryption type that matched with profile. */
	eCsrEncryptionType ucEncryptionType;
	eCsrEncryptionType mcEncryptionType;
	/* Preferred auth type that matched with the profile. */
<<<<<<< HEAD
	eCsrAuthType authType;
	int  bss_score;
=======
	enum csr_akm_type authType;
	int  bss_score;
	uint8_t retry_count;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	tCsrScanResultInfo Result;
	/*
	 * WARNING - Do not add any element here
	 * This member Result must be the last in the structure because the end
<<<<<<< HEAD
	 * of tSirBssDescription (inside) is an array with nonknown size at
=======
	 * of struct bss_description (inside) is an array with nonknown size at
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	 * this time.
	 */
};

struct scan_result_list {
	tDblLinkList List;
	tListElem *pCurEntry;
};

<<<<<<< HEAD
/**
 * csr_scan_for_ssid_context() - Callback context for SSID scan
 *
 * @mac_ctx: mac context
 * @session_id: scan session id
 * @roam_id: roam Id
 */
struct csr_scan_for_ssid_context {
	tpAniSirGlobal mac_ctx;
	uint32_t session_id;
	uint32_t roam_id;
};

#define CSR_IS_ROAM_REASON(pCmd, reason) \
					((reason) == (pCmd)->roamCmd.roamReason)
#define CSR_IS_BETTER_PREFER_VALUE(v1, v2)   ((v1) > (v2))
#define CSR_IS_EQUAL_PREFER_VALUE(v1, v2)   ((v1) == (v2))
#define CSR_IS_BETTER_CAP_VALUE(v1, v2)     ((v1) > (v2))
#define CSR_IS_EQUAL_CAP_VALUE(v1, v2)  ((v1) == (v2))
#define CSR_IS_BETTER_RSSI(v1, v2)   ((v1) > (v2))
#define CSR_IS_ENC_TYPE_STATIC(encType) \
		((eCSR_ENCRYPT_TYPE_NONE == (encType)) || \
		(eCSR_ENCRYPT_TYPE_WEP40_STATICKEY == (encType)) || \
		(eCSR_ENCRYPT_TYPE_WEP104_STATICKEY == (encType)))

#define CSR_IS_WAIT_FOR_KEY(pMac, sessionId) \
		 (CSR_IS_ROAM_JOINED(pMac, sessionId) && \
		  CSR_IS_ROAM_SUBSTATE_WAITFORKEY(pMac, sessionId))
=======
#define CSR_IS_ENC_TYPE_STATIC(encType) ((eCSR_ENCRYPT_TYPE_NONE == (encType)) \
			|| (eCSR_ENCRYPT_TYPE_WEP40_STATICKEY == (encType)) || \
			(eCSR_ENCRYPT_TYPE_WEP104_STATICKEY == (encType)))

#define CSR_IS_AUTH_TYPE_FILS(auth_type) \
		((eCSR_AUTH_TYPE_FILS_SHA256 == auth_type) || \
		(eCSR_AUTH_TYPE_FILS_SHA384 == auth_type) || \
		(eCSR_AUTH_TYPE_FT_FILS_SHA256 == auth_type) || \
		(eCSR_AUTH_TYPE_FT_FILS_SHA384 == auth_type))
#define CSR_IS_WAIT_FOR_KEY(mac, sessionId) \
		 (CSR_IS_ROAM_JOINED(mac, sessionId) && \
		  CSR_IS_ROAM_SUBSTATE_WAITFORKEY(mac, sessionId))
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/* WIFI has a test case for not using HT rates with TKIP as encryption */
/* We may need to add WEP but for now, TKIP only. */

#define CSR_IS_11n_ALLOWED(encType) ((eCSR_ENCRYPT_TYPE_TKIP != (encType)) && \
			(eCSR_ENCRYPT_TYPE_WEP40_STATICKEY != (encType)) && \
			(eCSR_ENCRYPT_TYPE_WEP104_STATICKEY != (encType)) && \
				     (eCSR_ENCRYPT_TYPE_WEP40 != (encType)) && \
				       (eCSR_ENCRYPT_TYPE_WEP104 != (encType)))

#define CSR_IS_DISCONNECT_COMMAND(pCommand) ((eSmeCommandRoam == \
		(pCommand)->command) && \
		((eCsrForcedDisassoc == (pCommand)->u.roamCmd.roamReason) || \
<<<<<<< HEAD
		(eCsrForcedIbssLeave == (pCommand)->u.roamCmd.roamReason) ||\
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		(eCsrForcedDeauth == (pCommand)->u.roamCmd.roamReason) || \
					(eCsrSmeIssuedDisassocForHandoff == \
					(pCommand)->u.roamCmd.roamReason) || \
					(eCsrForcedDisassocMICFailure == \
					(pCommand)->u.roamCmd.roamReason)))

<<<<<<< HEAD
eCsrRoamState csr_roam_state_change(tpAniSirGlobal pMac,
				    eCsrRoamState NewRoamState,
					uint8_t sessionId);
QDF_STATUS csr_scanning_state_msg_processor(tpAniSirGlobal pMac, void *pMsgBuf);
void csr_roaming_state_msg_processor(tpAniSirGlobal pMac, void *pMsgBuf);
void csr_roam_joined_state_msg_processor(tpAniSirGlobal pMac, void *pMsgBuf);
bool csr_scan_complete(tpAniSirGlobal pMac, tSirSmeScanRsp *pScanRsp);
void csr_release_command_roam(tpAniSirGlobal pMac, tSmeCmd *pCommand);
void csr_release_command_scan(tpAniSirGlobal pMac, tSmeCmd *pCommand);
void csr_release_command_wm_status_change(tpAniSirGlobal pMac,
					tSmeCmd *pCommand);
extern void csr_release_roc_req_cmd(tpAniSirGlobal mac_ctx);

bool csr_is_duplicate_bss_description(tpAniSirGlobal pMac,
				      tSirBssDescription *pSirBssDesc1,
				      tSirBssDescription *pSirBssDesc2);
QDF_STATUS csr_roam_save_connected_bss_desc(tpAniSirGlobal pMac,
						uint32_t sessionId,
					    tSirBssDescription *pBssDesc);
bool csr_is_network_type_equal(tSirBssDescription *pSirBssDesc1,
			       tSirBssDescription *pSirBssDesc2);
QDF_STATUS csr_scan_sme_scan_response(tpAniSirGlobal pMac, void *pMsgBuf);
/*
 * Prepare a filter base on a profile for parsing the scan results.
 * Upon successful return, caller MUST call csr_free_scan_filter on
 * pScanFilter when it is done with the filter.
 */
QDF_STATUS csr_roam_prepare_filter_from_profile(tpAniSirGlobal pMac,
						tCsrRoamProfile *pProfile,
						tCsrScanResultFilter
						*pScanFilter);
QDF_STATUS csr_roam_copy_profile(tpAniSirGlobal pMac,
				 tCsrRoamProfile *pDstProfile,
				 tCsrRoamProfile *pSrcProfile);
QDF_STATUS csr_roam_start(tpAniSirGlobal pMac);
void csr_roam_stop(tpAniSirGlobal pMac, uint32_t sessionId);
void csr_roam_startMICFailureTimer(tpAniSirGlobal pMac);
void csr_roam_stopMICFailureTimer(tpAniSirGlobal pMac);
void csr_roam_startTKIPCounterMeasureTimer(tpAniSirGlobal pMac);
void csr_roam_stopTKIPCounterMeasureTimer(tpAniSirGlobal pMac);

QDF_STATUS csr_scan_open(tpAniSirGlobal pMac);
QDF_STATUS csr_scan_close(tpAniSirGlobal pMac);
QDF_STATUS csr_scan_request_lost_link1(tpAniSirGlobal pMac, uint32_t sessionId);
QDF_STATUS csr_scan_request_lost_link2(tpAniSirGlobal pMac, uint32_t sessionId);
QDF_STATUS csr_scan_request_lost_link3(tpAniSirGlobal pMac, uint32_t sessionId);
QDF_STATUS csr_scan_handle_failed_lostlink1(tpAniSirGlobal pMac,
					    uint32_t sessionId);
QDF_STATUS csr_scan_handle_failed_lostlink2(tpAniSirGlobal pMac,
					    uint32_t sessionId);
QDF_STATUS csr_scan_handle_failed_lostlink3(tpAniSirGlobal pMac,
					    uint32_t sessionId);
bool csr_scan_append_bss_description(tpAniSirGlobal pMac,
				     tSirBssDescription *pSirBssDescription,
				     tDot11fBeaconIEs *pIes,
				     uint8_t sessionId);
void csr_scan_call_callback(tpAniSirGlobal pMac, tSmeCmd *pCommand,
			    eCsrScanStatus scanStatus);
QDF_STATUS csr_scan_copy_request(tpAniSirGlobal pMac, tCsrScanRequest *pDstReq,
				 tCsrScanRequest *pSrcReq);
QDF_STATUS csr_scan_free_request(tpAniSirGlobal pMac, tCsrScanRequest *pReq);
QDF_STATUS csr_scan_copy_result_list(tpAniSirGlobal pMac, tScanResultHandle hIn,
				     tScanResultHandle *phResult);
QDF_STATUS csr_scan_for_ssid(tpAniSirGlobal pMac, uint32_t sessionId,
			     tCsrRoamProfile *pProfile, uint32_t roamId,
			     bool notify);
/* To remove fresh scan commands from the pending queue */
bool csr_scan_remove_fresh_scan_command(tpAniSirGlobal pMac, uint8_t sessionId);
QDF_STATUS csr_scan_abort_mac_scan(tpAniSirGlobal pMac, uint8_t sessionId,
				   uint32_t scan_id, eCsrAbortReason reason);
QDF_STATUS csr_scan_abort_all_scans(tpAniSirGlobal mac_ctx,
				   eCsrAbortReason reason);
/**
 * csr_remove_cmd_from_pending_list() - Remove command from
 * pending list
 * @pMac: Pointer to Global MAC structure
 * @sessionId: session id
 * @scan_id: scan id
 * @pList: pointer to pending command list
 * @commandType: sme command type
 *
 * Remove command from pending list by matching either
 * scan id or session id.
 *
 * Return: QDF_STATUS_SUCCESS for success, QDF_STATUS_E_FAILURE
 * for failure
 */
QDF_STATUS csr_remove_cmd_from_pending_list(tpAniSirGlobal pMac,
						      uint8_t sessionId,
						      uint32_t scan_id,
						      tDblLinkList *pList,
						   eSmeCommandType commandType);
QDF_STATUS csr_scan_abort_mac_scan_not_for_connect(tpAniSirGlobal pMac,
						   uint8_t sessionId);
QDF_STATUS csr_scan_abort_scan_for_ssid(tpAniSirGlobal pMac,
					uint32_t sessionId);
void csr_remove_scan_for_ssid_from_pending_list(tpAniSirGlobal pMac,
						tDblLinkList *pList,
						uint32_t sessionId);

QDF_STATUS csr_abort_scan_from_active_list(tpAniSirGlobal pMac,
		tDblLinkList *pList, uint32_t sessionId, uint32_t scan_id,
		eSmeCommandType scan_cmd_type, eCsrAbortReason abort_reason);

/* To age out scan results base. tSmeGetScanChnRsp is a pointer returned by
 * LIM that has the information regarding scanned channels. The logic is that
 * whenever CSR add a BSS to scan result, it set the age count to a value.
 * This function deduct the age count if channelId matches the BSS' channelId
 * The BSS is remove if the count reaches 0.
 */
QDF_STATUS csr_scan_age_results(tpAniSirGlobal pMac,
				tSmeGetScanChnRsp *pScanChnInfo);

/* If fForce is true we will save the new String that is learn't. */
/* Typically it will be true in case of Join or user initiated ioctl */
bool csr_learn_11dcountry_information(tpAniSirGlobal pMac,
				   tSirBssDescription *pSirBssDesc,
				   tDot11fBeaconIEs *pIes, bool fForce);
void csr_apply_country_information(tpAniSirGlobal pMac);
void csr_set_cfg_scan_control_list(tpAniSirGlobal pMac, uint8_t *countryCode,
				   tCsrChannel *pChannelList);
void csr_reinit_scan_cmd(tpAniSirGlobal pMac, tSmeCmd *pCommand);
void csr_free_scan_result_entry(tpAniSirGlobal pMac, struct tag_csrscan_result
				*pResult);

QDF_STATUS csr_roam_call_callback(tpAniSirGlobal pMac, uint32_t sessionId,
				  tCsrRoamInfo *pRoamInfo, uint32_t roamId,
				  eRoamCmdStatus u1, eCsrRoamResult u2);
QDF_STATUS csr_roam_issue_connect(tpAniSirGlobal pMac, uint32_t sessionId,
				  tCsrRoamProfile *pProfile,
				  tScanResultHandle hBSSList,
				  eCsrRoamReason reason, uint32_t roamId,
				  bool fImediate, bool fClearScan);
QDF_STATUS csr_roam_issue_reassoc(tpAniSirGlobal pMac, uint32_t sessionId,
				  tCsrRoamProfile *pProfile,
				 tCsrRoamModifyProfileFields *pModProfileFields,
				  eCsrRoamReason reason, uint32_t roamId,
				  bool fImediate);
void csr_roam_complete(tpAniSirGlobal pMac, enum csr_roamcomplete_result Result,
		       void *Context);
QDF_STATUS csr_roam_issue_set_context_req(tpAniSirGlobal pMac,
					uint32_t sessionId,
					  eCsrEncryptionType EncryptType,
					  tSirBssDescription *pBssDescription,
					  tSirMacAddr *bssId, bool addKey,
					  bool fUnicast,
					  tAniKeyDirection aniKeyDirection,
					  uint8_t keyId, uint16_t keyLength,
					  uint8_t *pKey, uint8_t paeRole);
QDF_STATUS csr_roam_process_disassoc_deauth(tpAniSirGlobal pMac,
						tSmeCmd *pCommand,
					    bool fDisassoc, bool fMICFailure);
QDF_STATUS csr_roam_save_connected_infomation(tpAniSirGlobal pMac,
					      uint32_t sessionId,
					      tCsrRoamProfile *pProfile,
					      tSirBssDescription *pSirBssDesc,
					      tDot11fBeaconIEs *pIes);
void csr_roam_check_for_link_status_change(tpAniSirGlobal pMac,
					tSirSmeRsp *pSirMsg);
void csr_roam_stats_rsp_processor(tpAniSirGlobal pMac, tSirSmeRsp *pSirMsg);
QDF_STATUS csr_roam_issue_start_bss(tpAniSirGlobal pMac, uint32_t sessionId,
				    tCsrRoamStartBssParams *pParam,
				    tCsrRoamProfile *pProfile,
				    tSirBssDescription *pBssDesc,
					uint32_t roamId);
QDF_STATUS csr_roam_issue_stop_bss(tpAniSirGlobal pMac, uint32_t sessionId,
				   eCsrRoamSubState NewSubstate);
bool csr_is_same_profile(tpAniSirGlobal pMac, tCsrRoamConnectedProfile
			*pProfile1,
			 tCsrRoamProfile *pProfile2);
bool csr_is_roam_command_waiting(tpAniSirGlobal pMac);
bool csr_is_roam_command_waiting_for_session(tpAniSirGlobal pMac,
					uint32_t sessionId);
bool csr_is_scan_for_roam_command_active(tpAniSirGlobal pMac);
eRoamCmdStatus csr_get_roam_complete_status(tpAniSirGlobal pMac,
					    uint32_t sessionId);
/* pBand can be NULL if caller doesn't need to get it */
QDF_STATUS csr_roam_issue_disassociate_cmd(tpAniSirGlobal pMac,
					uint32_t sessionId,
					   eCsrRoamDisconnectReason reason);
QDF_STATUS csr_roam_disconnect_internal(tpAniSirGlobal pMac, uint32_t sessionId,
					eCsrRoamDisconnectReason reason);
/* pCommand may be NULL */
void csr_roam_remove_duplicate_command(tpAniSirGlobal pMac, uint32_t sessionId,
				       tSmeCmd *pCommand,
				       eCsrRoamReason eRoamReason);

QDF_STATUS csr_send_join_req_msg(tpAniSirGlobal pMac, uint32_t sessionId,
				 tSirBssDescription *pBssDescription,
				 tCsrRoamProfile *pProfile,
				 tDot11fBeaconIEs *pIes, uint16_t messageType);
QDF_STATUS csr_send_mb_disassoc_req_msg(tpAniSirGlobal pMac, uint32_t sessionId,
					tSirMacAddr bssId, uint16_t reasonCode);
QDF_STATUS csr_send_mb_deauth_req_msg(tpAniSirGlobal pMac, uint32_t sessionId,
				      tSirMacAddr bssId, uint16_t reasonCode);
QDF_STATUS csr_send_mb_disassoc_cnf_msg(tpAniSirGlobal pMac,
					tpSirSmeDisassocInd pDisassocInd);
QDF_STATUS csr_send_mb_deauth_cnf_msg(tpAniSirGlobal pMac,
				      tpSirSmeDeauthInd pDeauthInd);
QDF_STATUS csr_send_assoc_cnf_msg(tpAniSirGlobal pMac, tpSirSmeAssocInd
				pAssocInd,
				  QDF_STATUS status);
QDF_STATUS csr_send_assoc_ind_to_upper_layer_cnf_msg(tpAniSirGlobal pMac,
						     tpSirSmeAssocInd pAssocInd,
						     QDF_STATUS Halstatus,
						     uint8_t sessionId);
QDF_STATUS csr_send_mb_start_bss_req_msg(tpAniSirGlobal pMac,
					uint32_t sessionId,
					 eCsrRoamBssType bssType,
					 tCsrRoamStartBssParams *pParam,
					 tSirBssDescription *pBssDesc);
QDF_STATUS csr_send_mb_stop_bss_req_msg(tpAniSirGlobal pMac,
=======
enum csr_roam_state csr_roam_state_change(struct mac_context *mac,
					  enum csr_roam_state NewRoamState,
					  uint8_t sessionId);
void csr_roaming_state_msg_processor(struct mac_context *mac, void *msg_buf);
void csr_roam_joined_state_msg_processor(struct mac_context *mac,
					 void *msg_buf);
void csr_scan_callback(struct wlan_objmgr_vdev *vdev,
				struct scan_event *event, void *arg);
void csr_release_command_roam(struct mac_context *mac, tSmeCmd *pCommand);
void csr_release_command_wm_status_change(struct mac_context *mac,
					  tSmeCmd *pCommand);

QDF_STATUS csr_roam_save_connected_bss_desc(struct mac_context *mac,
					    uint32_t sessionId,
					    struct bss_description *bss_desc);

QDF_STATUS csr_roam_copy_profile(struct mac_context *mac,
				 struct csr_roam_profile *pDstProfile,
				 struct csr_roam_profile *pSrcProfile);
QDF_STATUS csr_roam_start(struct mac_context *mac);
void csr_roam_stop(struct mac_context *mac, uint32_t sessionId);

QDF_STATUS csr_scan_open(struct mac_context *mac);
QDF_STATUS csr_scan_close(struct mac_context *mac);

bool
csr_scan_append_bss_description(struct mac_context *mac,
				struct bss_description *pSirBssDescription);

QDF_STATUS csr_scan_for_ssid(struct mac_context *mac, uint32_t sessionId,
			     struct csr_roam_profile *pProfile, uint32_t roamId,
			     bool notify);
/**
 * csr_scan_abort_mac_scan() - Generic API to abort scan request
 * @mac: pointer to pmac
 * @vdev_id: pdev id
 * @scan_id: scan id
 *
 * Generic API to abort scans
 *
 * Return: 0 for success, non zero for failure
 */
QDF_STATUS csr_scan_abort_mac_scan(struct mac_context *mac, uint32_t vdev_id,
				   uint32_t scan_id);

/* If fForce is true we will save the new String that is learn't. */
/* Typically it will be true in case of Join or user initiated ioctl */
bool csr_learn_11dcountry_information(struct mac_context *mac,
				   struct bss_description *pSirBssDesc,
				   tDot11fBeaconIEs *pIes, bool fForce);
void csr_apply_country_information(struct mac_context *mac);
void csr_free_scan_result_entry(struct mac_context *mac, struct tag_csrscan_result
				*pResult);

QDF_STATUS csr_roam_call_callback(struct mac_context *mac, uint32_t sessionId,
				  struct csr_roam_info *roam_info,
				  uint32_t roamId,
				  eRoamCmdStatus u1, eCsrRoamResult u2);
QDF_STATUS csr_roam_issue_connect(struct mac_context *mac, uint32_t sessionId,
				  struct csr_roam_profile *pProfile,
				  tScanResultHandle hBSSList,
				  enum csr_roam_reason reason, uint32_t roamId,
				  bool fImediate, bool fClearScan);
QDF_STATUS csr_roam_issue_reassoc(struct mac_context *mac, uint32_t sessionId,
				  struct csr_roam_profile *pProfile,
				 tCsrRoamModifyProfileFields *pModProfileFields,
				  enum csr_roam_reason reason, uint32_t roamId,
				  bool fImediate);
void csr_roam_complete(struct mac_context *mac, enum csr_roamcomplete_result Result,
		       void *Context, uint8_t session_id);

/**
 * csr_issue_set_context_req_helper  - Function to fill unicast/broadcast keys
 * request to set the keys to fw
 * @mac:         Poiner to mac context
 * @profile:     Pointer to connected profile
 * @vdev_id:     vdev id
 * @bssid:       Connected BSSID
 * @addkey:      Is add key request to crypto
 * @unicast:     Unicast(1) or broadcast key(0)
 * @key_direction: Key used in TX or RX or both Tx and RX path
 * @key_id:       Key index
 * @key_length:   Key length
 * @key:          Pointer to the key
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
csr_issue_set_context_req_helper(struct mac_context *mac,
				 struct csr_roam_profile *profile,
				 uint32_t session_id,
				 tSirMacAddr *bssid, bool addkey,
				 bool unicast, tAniKeyDirection key_direction,
				 uint8_t key_id, uint16_t key_length,
				 uint8_t *key);

QDF_STATUS csr_roam_process_disassoc_deauth(struct mac_context *mac,
						tSmeCmd *pCommand,
					    bool fDisassoc, bool fMICFailure);

QDF_STATUS
csr_roam_save_connected_information(struct mac_context *mac,
				    uint32_t sessionId,
				    struct csr_roam_profile *pProfile,
				    struct bss_description *pSirBssDesc,
				    tDot11fBeaconIEs *pIes);

void csr_roam_check_for_link_status_change(struct mac_context *mac,
					tSirSmeRsp *pSirMsg);

QDF_STATUS csr_roam_issue_start_bss(struct mac_context *mac, uint32_t sessionId,
				    struct csr_roamstart_bssparams *pParam,
				    struct csr_roam_profile *pProfile,
				    struct bss_description *bss_desc,
					uint32_t roamId);
QDF_STATUS csr_roam_issue_stop_bss(struct mac_context *mac, uint32_t sessionId,
				   enum csr_roam_substate NewSubstate);
bool csr_is_same_profile(struct mac_context *mac, tCsrRoamConnectedProfile
			*pProfile1, struct csr_roam_profile *pProfile2);
bool csr_is_roam_command_waiting_for_session(struct mac_context *mac,
					uint32_t sessionId);
eRoamCmdStatus csr_get_roam_complete_status(struct mac_context *mac,
					    uint32_t sessionId);
/* pBand can be NULL if caller doesn't need to get it */
QDF_STATUS csr_roam_issue_disassociate_cmd(struct mac_context *mac,
					   uint32_t sessionId,
					   eCsrRoamDisconnectReason reason,
					   tSirMacReasonCodes mac_reason);
QDF_STATUS csr_roam_disconnect_internal(struct mac_context *mac, uint32_t sessionId,
					eCsrRoamDisconnectReason reason,
					tSirMacReasonCodes mac_reason);
/* pCommand may be NULL */
void csr_roam_remove_duplicate_command(struct mac_context *mac, uint32_t sessionId,
				       tSmeCmd *pCommand,
				       enum csr_roam_reason eRoamReason);

QDF_STATUS csr_send_join_req_msg(struct mac_context *mac, uint32_t sessionId,
				 struct bss_description *pBssDescription,
				 struct csr_roam_profile *pProfile,
				 tDot11fBeaconIEs *pIes, uint16_t messageType);
QDF_STATUS csr_send_mb_disassoc_req_msg(struct mac_context *mac, uint32_t sessionId,
					tSirMacAddr bssId, uint16_t reasonCode);
QDF_STATUS csr_send_mb_deauth_req_msg(struct mac_context *mac, uint32_t sessionId,
				      tSirMacAddr bssId, uint16_t reasonCode);
QDF_STATUS csr_send_mb_disassoc_cnf_msg(struct mac_context *mac,
					struct disassoc_ind *pDisassocInd);
QDF_STATUS csr_send_mb_deauth_cnf_msg(struct mac_context *mac,
				      struct deauth_ind *pDeauthInd);
QDF_STATUS csr_send_assoc_cnf_msg(struct mac_context *mac,
				  struct assoc_ind *pAssocInd,
				  QDF_STATUS status,
				  enum mac_status_code mac_status_code);
QDF_STATUS csr_send_mb_start_bss_req_msg(struct mac_context *mac,
					 uint32_t sessionId,
					 eCsrRoamBssType bssType,
					 struct csr_roamstart_bssparams *pParam,
					 struct bss_description *bss_desc);
QDF_STATUS csr_send_mb_stop_bss_req_msg(struct mac_context *mac,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
					uint32_t sessionId);

/* Caller should put the BSS' ssid to fiedl bssSsid when
 * comparing SSID for a BSS.
 */
<<<<<<< HEAD
bool csr_is_ssid_match(tpAniSirGlobal pMac, uint8_t *ssid1, uint8_t ssid1Len,
		       uint8_t *bssSsid, uint8_t bssSsidLen,
			bool fSsidRequired);
bool csr_is_phy_mode_match(tpAniSirGlobal pMac, uint32_t phyMode,
			   tSirBssDescription *pSirBssDesc,
			   tCsrRoamProfile *pProfile,
			   eCsrCfgDot11Mode *pReturnCfgDot11Mode,
			   tDot11fBeaconIEs *pIes);
bool csr_roam_is_channel_valid(tpAniSirGlobal pMac, uint8_t channel);

/* pNumChan is a caller allocated space with the sizeof pChannels */
QDF_STATUS csr_get_cfg_valid_channels(tpAniSirGlobal pMac, uint8_t *pChannels,
				      uint32_t *pNumChan);
void csr_roam_ccm_cfg_set_callback(tpAniSirGlobal pMac, int32_t result);

int8_t csr_get_cfg_max_tx_power(tpAniSirGlobal pMac, uint8_t channel);

/* To free the last roaming profile */
void csr_free_roam_profile(tpAniSirGlobal pMac, uint32_t sessionId);
void csr_free_connect_bss_desc(tpAniSirGlobal pMac, uint32_t sessionId);
QDF_STATUS csr_move_bss_to_head_from_bssid(tpAniSirGlobal pMac,
					   struct qdf_mac_addr *bssid,
					   tScanResultHandle hScanResult);
bool csr_check_ps_ready(void *pv);
bool csr_check_ps_offload_ready(void *pv, uint32_t sessionId);

/* to free memory allocated inside the profile structure */
void csr_release_profile(tpAniSirGlobal pMac, tCsrRoamProfile *pProfile);
/* To free memory allocated inside scanFilter */
void csr_free_scan_filter(tpAniSirGlobal pMac, tCsrScanResultFilter
			*pScanFilter);
eCsrCfgDot11Mode csr_get_cfg_dot11_mode_from_csr_phy_mode(tCsrRoamProfile
							*pProfile,
							  eCsrPhyMode phyMode,
							  bool fProprietary);
uint32_t csr_translate_to_wni_cfg_dot11_mode(tpAniSirGlobal pMac,
					     eCsrCfgDot11Mode csrDot11Mode);
void csr_save_channel_power_for_band(tpAniSirGlobal pMac, bool fPopulate5GBand);
void csr_apply_channel_power_info_to_fw(tpAniSirGlobal pMac,
					tCsrChannel *pChannelList,
					uint8_t *countryCode);
void csr_apply_power2_current(tpAniSirGlobal pMac);
void csr_assign_rssi_for_category(tpAniSirGlobal pMac, int8_t bestApRssi,
				  uint8_t catOffset);
QDF_STATUS csr_roam_remove_connected_bss_from_scan_cache(tpAniSirGlobal pMac,
						tCsrRoamConnectedProfile *
							 pConnProfile);
QDF_STATUS csr_roam_start_roaming(tpAniSirGlobal pMac, uint32_t sessionId,
				  eCsrRoamingReason roamingReason);
/* return a bool to indicate whether roaming completed or continue. */
bool csr_roam_complete_roaming(tpAniSirGlobal pMac, uint32_t sessionId,
			       bool fForce, eCsrRoamResult roamResult);
void csr_roam_completion(tpAniSirGlobal pMac, uint32_t sessionId,
			 tCsrRoamInfo *pRoamInfo, tSmeCmd *pCommand,
			 eCsrRoamResult roamResult, bool fSuccess);
void csr_roam_cancel_roaming(tpAniSirGlobal pMac, uint32_t sessionId);
void csr_apply_channel_power_info_wrapper(tpAniSirGlobal pMac);
void csr_reset_pmkid_candidate_list(tpAniSirGlobal pMac, uint32_t sessionId);
#ifdef FEATURE_WLAN_WAPI
void csr_reset_bkid_candidate_list(tpAniSirGlobal pMac, uint32_t sessionId);
#endif /* FEATURE_WLAN_WAPI */
QDF_STATUS csr_save_to_channel_power2_g_5_g(tpAniSirGlobal pMac,
					uint32_t tableSize, tSirMacChanInfo
					*channelTable);

/* To check whether a country code matches the one in the IE Only check the
 * first two characters, ignoring in/outdoor pCountry -- caller allocated
 * buffer contain the country code that is checking against the one in pIes.
 * It can be NULL. caller must provide pIes, it cannot be NULL. This function
 * always return true if 11d support is not turned on. pIes cannot be NULL
 */
bool csr_match_country_code(tpAniSirGlobal pMac, uint8_t *pCountry,
			    tDot11fBeaconIEs *pIes);
QDF_STATUS csr_roam_set_key(tpAniSirGlobal pMac, uint32_t sessionId,
			    tCsrRoamSetKey *pSetKey, uint32_t roamId);
QDF_STATUS csr_roam_open_session(tpAniSirGlobal pMac,
				 csr_roam_completeCallback callback,
				void *pContext,
				 uint8_t *pSelfMacAddr, uint8_t *pbSessionId,
				 uint32_t type, uint32_t subType);

/**
 * csr_purge_sme_cmd_list() - perge all sme cmds.
 * @mac_ctx: mac context
 * @sessionid: session id of the session
 * @flush_all_sme_cmd: If all sme cmds needed to be flushed
 *
 * Return: void
 */
void csr_purge_sme_cmd_list(tpAniSirGlobal mac_ctx, uint8_t sessionid,
				bool flush_all_cmd);

/**
 * csr_roam_close_session: API to close csr session
 * @pMac: mac context
 * @sessionId: session id
 * @fSync: whether cleanupneeds to handle synchronously
 * @flush_all_sme_cmds: whether all commands needs to be flushed
 * @callback: pointer to callback API
 * @pContext: callback context
 *
 * Return: None
 */
QDF_STATUS csr_roam_close_session(tpAniSirGlobal pMac, uint32_t sessionId,
				  bool fSync, bool flush_all_sme_cmds,
				  csr_roamSessionCloseCallback callback,
				  void *pContext);
void csr_cleanup_session(tpAniSirGlobal pMac, uint32_t sessionId);
QDF_STATUS csr_roam_get_session_id_from_bssid(tpAniSirGlobal pMac,
						struct qdf_mac_addr *bssid,
					      uint32_t *pSessionId);
eCsrCfgDot11Mode csr_find_best_phy_mode(tpAniSirGlobal pMac, uint32_t phyMode);

/*
 * csr_scan_enable() -
 * Enable the scanning feature of CSR. It must be called before any scan
 * request can be performed.
 *
 * tHalHandle - HAL context handle
 * Return QDF_STATUS
 */
QDF_STATUS csr_scan_enable(tpAniSirGlobal pMac);

/*
 * csr_scan_disable() -
 * Disableing the scanning feature of CSR. After this function return success,
 * no scan is performed until a successful to csr_scan_enable
 *
 * tHalHandle - HAL context handle
 * Return QDF_STATUS
 */
QDF_STATUS csr_scan_disable(tpAniSirGlobal pMac);
/*
 * csr_scan_request() -
 * Request a 11d or full scan.
 *
 * callback - a callback function that scan calls upon finish, will not be
 * called if csr_scan_request returns error
 * pContext - a pointer passed in for the callback
 * Return QDF_STATUS
 */
QDF_STATUS csr_scan_request(tpAniSirGlobal pMac, uint16_t sessionId,
			tCsrScanRequest *scan_req,
			csr_scan_completeCallback callback, void *pContext);

/*
 * csrScanAbort() -
 * If a scan request is abort, the scan complete callback will be called
 * first before csrScanAbort returns.
 *
 * pScanRequestID - The request ID returned from csr_scan_request
 * Return QDF_STATUS
 */
QDF_STATUS csrScanAbort(tpAniSirGlobal pMac, uint32_t scanRequestID);

/*
 * csr_scan_get_result() -
 * Return scan results.
 *
 * pFilter - If pFilter is NULL, all cached results are returned
 * phResult - an object for the result.
 * Return QDF_STATUS
 */
QDF_STATUS csr_scan_get_result(tpAniSirGlobal pMac, tCsrScanResultFilter
				*pFilter, tScanResultHandle *phResult);

/**
 * csr_scan_get_result_for_bssid - gets the scan result from scan cache for the
 *	bssid specified
 * @mac_ctx: mac context
 * @bssid: bssid to get the scan result for
 *
 * Return: tCsrScanResultInfo * or NULL if no result
 */
tCsrScanResultInfo *csr_scan_get_result_for_bssid(tpAniSirGlobal mac_ctx,
						  struct qdf_mac_addr *bssid);

/*
 * csr_scan_flush_result() -
 * Clear scan results.
 *
 * pMac - pMac global pointer
 * sessionId - Session Identifier
 * Return QDF_STATUS
 */
QDF_STATUS csr_scan_flush_result(tpAniSirGlobal pMac);
/*
 * csr_scan_filter_results() -
 *  Filter scan results based on valid channel list.
 *
 * pMac - Pointer to Global MAC structure
 * Return QDF_STATUS
 */
QDF_STATUS csr_scan_filter_results(tpAniSirGlobal pMac);

void csr_save_scan_results(tpAniSirGlobal pMac, uint8_t reason,
				  uint8_t sessionId);

QDF_STATUS csr_scan_flush_selective_result(tpAniSirGlobal pMac, bool flushP2P);
=======
bool csr_is_ssid_match(struct mac_context *mac, uint8_t *ssid1, uint8_t ssid1Len,
		       uint8_t *bssSsid, uint8_t bssSsidLen,
			bool fSsidRequired);
bool csr_is_phy_mode_match(struct mac_context *mac, uint32_t phyMode,
			   struct bss_description *pSirBssDesc,
			   struct csr_roam_profile *pProfile,
			   enum csr_cfgdot11mode *pReturnCfgDot11Mode,
			   tDot11fBeaconIEs *pIes);

/**
 * csr_roam_is_channel_valid() - validate channel frequency
 * @mac: mac context
 * @chan_freq: channel frequency
 *
 * This function validates channel frequency present in valid channel
 * list or not.
 *
 * Return: true or false
 */
bool csr_roam_is_channel_valid(struct mac_context *mac, uint32_t chan_freq);

/**
 * csr_get_cfg_valid_channels() - Get valid channel frequency list
 * @mac: mac context
 * @ch_freq_list: valid channel frequencies
 * @num_ch_freq: valid channel nummber
 *
 * This function returns the valid channel frequencies.
 *
 * Return: QDF_STATUS_SUCCESS for success.
 */
QDF_STATUS csr_get_cfg_valid_channels(struct mac_context *mac,
				      uint32_t *ch_freq_list,
				      uint32_t *num_ch_freq);

int8_t csr_get_cfg_max_tx_power(struct mac_context *mac, uint32_t ch_freq);

/* To free the last roaming profile */
void csr_free_roam_profile(struct mac_context *mac, uint32_t sessionId);
void csr_free_connect_bss_desc(struct mac_context *mac, uint32_t sessionId);

/* to free memory allocated inside the profile structure */
void csr_release_profile(struct mac_context *mac,
			 struct csr_roam_profile *pProfile);

enum csr_cfgdot11mode
csr_get_cfg_dot11_mode_from_csr_phy_mode(struct csr_roam_profile *pProfile,
					 eCsrPhyMode phyMode,
					 bool fProprietary);

uint32_t csr_translate_to_wni_cfg_dot11_mode(struct mac_context *mac,
				    enum csr_cfgdot11mode csrDot11Mode);
void csr_save_channel_power_for_band(struct mac_context *mac, bool fPopulate5GBand);
void csr_apply_channel_power_info_to_fw(struct mac_context *mac,
					struct csr_channel *pChannelList,
					uint8_t *countryCode);
void csr_apply_power2_current(struct mac_context *mac);
void csr_assign_rssi_for_category(struct mac_context *mac, int8_t bestApRssi,
				  uint8_t catOffset);

/* return a bool to indicate whether roaming completed or continue. */
bool csr_roam_complete_roaming(struct mac_context *mac, uint32_t sessionId,
			       bool fForce, eCsrRoamResult roamResult);
void csr_roam_completion(struct mac_context *mac, uint32_t sessionId,
			 struct csr_roam_info *roam_info, tSmeCmd *pCommand,
			 eCsrRoamResult roamResult, bool fSuccess);
void csr_roam_cancel_roaming(struct mac_context *mac, uint32_t sessionId);
void csr_apply_channel_power_info_wrapper(struct mac_context *mac);
void csr_reset_pmkid_candidate_list(struct mac_context *mac, uint32_t sessionId);
QDF_STATUS csr_save_to_channel_power2_g_5_g(struct mac_context *mac,
					uint32_t tableSize, tSirMacChanInfo
					*channelTable);

/*
 * csr_roam_vdev_delete() - CSR api to delete vdev
 * @mac_ctx: pointer to mac context
 * @vdev_id: vdev id to be deleted.
 * @cleanup: clean up vdev session on true
 *
 * Return QDF_STATUS
 */
QDF_STATUS csr_roam_vdev_delete(struct mac_context *mac_ctx,
				uint8_t vdev_id, bool cleanup);

/*
 * csr_cleanup_vdev_session() - CSR api to cleanup vdev
 * @mac_ctx: pointer to mac context
 * @vdev_id: vdev id to be deleted.
 *
 * This API is used to clean up vdev information gathered during
 * vdev was enabled.
 *
 * Return QDF_STATUS
 */
void csr_cleanup_vdev_session(struct mac_context *mac, uint8_t vdev_id);

QDF_STATUS csr_roam_get_session_id_from_bssid(struct mac_context *mac,
						struct qdf_mac_addr *bssid,
					      uint32_t *pSessionId);
enum csr_cfgdot11mode csr_find_best_phy_mode(struct mac_context *mac,
							uint32_t phyMode);

/*
 * csr_copy_ssids_from_roam_params() - copy SSID from roam_params to scan filter
 * @roam_params: roam params
 * @filter: scan filter
 *
 * Return void
 */
void csr_copy_ssids_from_roam_params(struct roam_ext_params *roam_params,
				     struct scan_filter *filter);

/*
 * csr_update_connect_n_roam_cmn_filter() - update common scan filter
 * @mac_ctx: pointer to mac context
 * @filter: scan filter
 * @opmode: opmode
 *
 * Return void
 */
void csr_update_connect_n_roam_cmn_filter(struct mac_context *mac_ctx,
					  struct scan_filter *filter,
					  enum QDF_OPMODE opmode);

/*
 * csr_covert_enc_type_new() - convert csr enc type to wlan enc type
 * @enc: csr enc type
 *
 * Return enum wlan_enc_type
 */
enum wlan_enc_type csr_covert_enc_type_new(eCsrEncryptionType enc);

/*
 * csr_covert_auth_type_new() - convert csr auth type to wlan auth type
 * @auth: csr auth type
 *
 * Return enum wlan_auth_type
 */
enum wlan_auth_type csr_covert_auth_type_new(enum csr_akm_type auth);

/**
 * csr_roam_get_scan_filter_from_profile() - prepare scan filter from
 * given roam profile
 * @mac: Pointer to Global MAC structure
 * @profile: roam profile
 * @filter: Populated scan filter based on the connected profile
 * @is_roam: if filter is for roam
 *
 * This function creates a scan filter based on the roam profile. Based on this
 * filter, scan results are obtained.
 *
 * Return: QDF_STATUS_SUCCESS on success, QDF_STATUS_E_FAILURE otherwise
 */
QDF_STATUS
csr_roam_get_scan_filter_from_profile(struct mac_context *mac_ctx,
				      struct csr_roam_profile *profile,
				      struct scan_filter *filter,
				      bool is_roam);

/**
 * csr_neighbor_roam_get_scan_filter_from_profile() - prepare scan filter from
 * connected profile
 * @mac: Pointer to Global MAC structure
 * @filter: Populated scan filter based on the connected profile
 * @vdev_id: Session ID
 *
 * This function creates a scan filter based on the currently
 * connected profile. Based on this filter, scan results are obtained
 *
 * Return: QDF_STATUS_SUCCESS on success, QDF_STATUS_E_FAILURE otherwise
 */
QDF_STATUS
csr_neighbor_roam_get_scan_filter_from_profile(struct mac_context *mac,
					       struct scan_filter *filter,
					       uint8_t vdev_id);
/*
 * csr_scan_get_result() - Return scan results based on filter
 * @mac: Pointer to Global MAC structure
 * @filter: If pFilter is NULL, all cached results are returned
 * @phResult: an object for the result.
 *
 * Return QDF_STATUS
 */
QDF_STATUS csr_scan_get_result(struct mac_context *mac,
			       struct scan_filter *filter,
			       tScanResultHandle *phResult);

/**
 * csr_scan_get_result_for_bssid - gets the scan result from scan cache for the
 *      bssid specified
 * @mac_ctx: mac context
 * @bssid: bssid to get the scan result for
 * @res: pointer to tCsrScanResultInfo
 *
 * Return: QDF_STATUS
 */
QDF_STATUS csr_scan_get_result_for_bssid(struct mac_context *mac_ctx,
					 struct qdf_mac_addr *bssid,
					 tCsrScanResultInfo *res);

/*
 * csr_scan_filter_results() -
 *  Filter scan results based on valid channel list.
 *
 * mac - Pointer to Global MAC structure
 * Return QDF_STATUS
 */
QDF_STATUS csr_scan_filter_results(struct mac_context *mac);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/*
 * csr_scan_result_get_first
 * Returns the first element of scan result.
 *
 * hScanResult - returned from csr_scan_get_result
 * tCsrScanResultInfo * - NULL if no result
 */
<<<<<<< HEAD
tCsrScanResultInfo *csr_scan_result_get_first(tpAniSirGlobal pMac,
=======
tCsrScanResultInfo *csr_scan_result_get_first(struct mac_context *mac,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
					      tScanResultHandle hScanResult);
/*
 * csr_scan_result_get_next
 * Returns the next element of scan result. It can be called without calling
 * csr_scan_result_get_first first
 *
 * hScanResult - returned from csr_scan_get_result
 * Return Null if no result or reach the end
 */
<<<<<<< HEAD
tCsrScanResultInfo *csr_scan_result_get_next(tpAniSirGlobal pMac,
=======
tCsrScanResultInfo *csr_scan_result_get_next(struct mac_context *mac,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
					     tScanResultHandle hScanResult);

/*
 * csr_get_country_code() -
 * This function is to get the country code current being used
 * pBuf - Caller allocated buffer with at least 3 bytes, upon success return,
 * this has the country code
 * pbLen - Caller allocated, as input, it indicates the length of pBuf. Upon
 * success return, this contains the length of the data in pBuf
 * Return QDF_STATUS
 */
<<<<<<< HEAD
QDF_STATUS csr_get_country_code(tpAniSirGlobal pMac, uint8_t *pBuf,
				uint8_t *pbLen);

/*
 * csr_set_country_code() -
 * This function is to set the country code so channel/power setting matches
 * the countrycode and the domain it belongs to.
 *
 * pCountry - Caller allocated buffer with at least 3 bytes specifying the
 * country code
 * Return QDF_STATUS
 */
QDF_STATUS csr_set_country_code(tpAniSirGlobal pMac, uint8_t *pCountry);

/*
=======
QDF_STATUS csr_get_country_code(struct mac_context *mac, uint8_t *pBuf,
				uint8_t *pbLen);

/*
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * csr_get_regulatory_domain_for_country() -
 * This function is to get the regulatory domain for a country.
 * This function must be called after CFG is downloaded and all the band/mode
 * setting already passed into CSR.
 *
 * pCountry - Caller allocated buffer with at least 3 bytes specifying the
 * country code
 * pDomainId - Caller allocated buffer to get the return domain ID upon
 * success return. Can be NULL.
 * source - the source of country information.
 * Return QDF_STATUS
 */
<<<<<<< HEAD
QDF_STATUS csr_get_regulatory_domain_for_country(tpAniSirGlobal pMac,
=======
QDF_STATUS csr_get_regulatory_domain_for_country(struct mac_context *mac,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
						 uint8_t *pCountry,
						 v_REGDOMAIN_t *pDomainId,
						 enum country_src source);

/* some support functions */
<<<<<<< HEAD
bool csr_is11d_supported(tpAniSirGlobal pMac);
bool csr_is11h_supported(tpAniSirGlobal pMac);
bool csr_is11e_supported(tpAniSirGlobal pMac);
bool csr_is_wmm_supported(tpAniSirGlobal pMac);
bool csr_is_mcc_supported(tpAniSirGlobal pMac);

/* Return SUCCESS is the command is queued, failed */
QDF_STATUS csr_queue_sme_command(tpAniSirGlobal pMac, tSmeCmd *pCommand,
				 bool fHighPriority);
tSmeCmd *csr_get_command_buffer(tpAniSirGlobal pMac);
void csr_release_command(tpAniSirGlobal pMac, tSmeCmd *pCommand);
void csr_scan_flush_bss_entry(tpAniSirGlobal pMac,
			      tpSmeCsaOffloadInd pCsaOffloadInd);
QDF_STATUS csr_get_active_scan_entry(tpAniSirGlobal mac, uint32_t scan_id,
	tListElem **entry);

#ifdef FEATURE_WLAN_WAPI
bool csr_is_profile_wapi(tCsrRoamProfile *pProfile);
#endif /* FEATURE_WLAN_WAPI */

void csr_get_vdev_type_nss(tpAniSirGlobal mac_ctx,
		enum tQDF_ADAPTER_MODE dev_mode,
		uint8_t *nss_2g, uint8_t *nss_5g);
=======
bool csr_is11h_supported(struct mac_context *mac);
bool csr_is11e_supported(struct mac_context *mac);
bool csr_is_wmm_supported(struct mac_context *mac);

/* Return SUCCESS is the command is queued, failed */
QDF_STATUS csr_queue_sme_command(struct mac_context *mac, tSmeCmd *pCommand,
				 bool fHighPriority);
tSmeCmd *csr_get_command_buffer(struct mac_context *mac);
void csr_release_command(struct mac_context *mac, tSmeCmd *pCommand);
void csr_release_command_buffer(struct mac_context *mac, tSmeCmd *pCommand);

#ifdef FEATURE_WLAN_WAPI
bool csr_is_profile_wapi(struct csr_roam_profile *pProfile);
#endif /* FEATURE_WLAN_WAPI */

/**
 * csr_get_vdev_type_nss() - gets the nss value based on vdev type
 * @dev_mode: current device operating mode.
 * @nss2g: Pointer to the 2G Nss parameter.
 * @nss5g: Pointer to the 5G Nss parameter.
 *
 * Fills the 2G and 5G Nss values based on device mode.
 *
 * Return: None
 */
void csr_get_vdev_type_nss(enum QDF_OPMODE dev_mode, uint8_t *nss_2g,
			   uint8_t *nss_5g);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

#ifdef FEATURE_WLAN_DIAG_SUPPORT_CSR

/* Security */
#define WLAN_SECURITY_EVENT_REMOVE_KEY_REQ  5
#define WLAN_SECURITY_EVENT_REMOVE_KEY_RSP  6
#define WLAN_SECURITY_EVENT_PMKID_CANDIDATE_FOUND  7
#define WLAN_SECURITY_EVENT_PMKID_UPDATE    8
#define WLAN_SECURITY_EVENT_MIC_ERROR       9
#define WLAN_SECURITY_EVENT_SET_UNICAST_REQ  10
#define WLAN_SECURITY_EVENT_SET_UNICAST_RSP  11
#define WLAN_SECURITY_EVENT_SET_BCAST_REQ    12
#define WLAN_SECURITY_EVENT_SET_BCAST_RSP    13

<<<<<<< HEAD

#define AUTH_OPEN       0
#define AUTH_SHARED     1
#define AUTH_WPA_EAP    2
#define AUTH_WPA_PSK    3
#define AUTH_WPA2_EAP   4
#define AUTH_WPA2_PSK   5
#ifdef FEATURE_WLAN_WAPI
#define AUTH_WAPI_CERT  6
#define AUTH_WAPI_PSK   7
#endif /* FEATURE_WLAN_WAPI */

#define ENC_MODE_OPEN   0
#define ENC_MODE_WEP40  1
#define ENC_MODE_WEP104 2
#define ENC_MODE_TKIP   3
#define ENC_MODE_AES    4
#define ENC_MODE_AES_GCMP    5
#define ENC_MODE_AES_GCMP_256    6
#ifdef FEATURE_WLAN_WAPI
#define ENC_MODE_SMS4   5       /* WAPI */
#endif /* FEATURE_WLAN_WAPI */

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#define NO_MATCH    0
#define MATCH       1

#define WLAN_SECURITY_STATUS_SUCCESS        0
#define WLAN_SECURITY_STATUS_FAILURE        1

/* Scan */
#define WLAN_SCAN_EVENT_ACTIVE_SCAN_REQ     1
#define WLAN_SCAN_EVENT_ACTIVE_SCAN_RSP     2
#define WLAN_SCAN_EVENT_PASSIVE_SCAN_REQ    3
#define WLAN_SCAN_EVENT_PASSIVE_SCAN_RSP    4
#define WLAN_SCAN_EVENT_HO_SCAN_REQ         5
#define WLAN_SCAN_EVENT_HO_SCAN_RSP         6

#define WLAN_SCAN_STATUS_SUCCESS        0
#define WLAN_SCAN_STATUS_FAILURE        1
#define WLAN_SCAN_STATUS_ABORT          2

/* Ibss */
#define WLAN_IBSS_EVENT_START_IBSS_REQ      0
#define WLAN_IBSS_EVENT_START_IBSS_RSP      1
#define WLAN_IBSS_EVENT_JOIN_IBSS_REQ       2
#define WLAN_IBSS_EVENT_JOIN_IBSS_RSP       3
#define WLAN_IBSS_EVENT_COALESCING          4
#define WLAN_IBSS_EVENT_PEER_JOIN           5
#define WLAN_IBSS_EVENT_PEER_LEAVE          6
#define WLAN_IBSS_EVENT_STOP_REQ            7
#define WLAN_IBSS_EVENT_STOP_RSP            8

#define AUTO_PICK       0
#define SPECIFIED       1

#define WLAN_IBSS_STATUS_SUCCESS        0
#define WLAN_IBSS_STATUS_FAILURE        1

/* 11d */
#define WLAN_80211D_EVENT_COUNTRY_SET   0
#define WLAN_80211D_EVENT_RESET         1

#define WLAN_80211D_DISABLED         0
#define WLAN_80211D_SUPPORT_MULTI_DOMAIN     1
#define WLAN_80211D_NOT_SUPPORT_MULTI_DOMAIN     2

<<<<<<< HEAD
int diag_auth_type_from_csr_type(eCsrAuthType authType);
int diag_enc_type_from_csr_type(eCsrEncryptionType encType);
=======
/**
 * diag_auth_type_from_csr_type() - to convert CSR auth type to DIAG auth type
 * @authtype: CSR auth type
 *
 * DIAG tool understands its own ENUMs, so this API can be used to convert
 * CSR defined auth type ENUMs to DIAG defined auth type ENUMs
 *
 *
 * Return: DIAG auth type
 */
enum mgmt_auth_type diag_auth_type_from_csr_type(enum csr_akm_type authtype);
/**
 * diag_enc_type_from_csr_type() - to convert CSR encr type to DIAG encr type
 * @enctype: CSR encryption type
 *
 * DIAG tool understands its own ENUMs, so this API can be used to convert
 * CSR defined encr type ENUMs to DIAG defined encr type ENUMs
 *
 * Return: DIAG encryption type
 */
enum mgmt_encrypt_type diag_enc_type_from_csr_type(eCsrEncryptionType enctype);
/**
 * diag_dot11_mode_from_csr_type() - to convert CSR .11 mode to DIAG .11 mode
 * @dot11mode: CSR 80211 mode
 *
 * DIAG tool understands its own ENUMs, so this API can be used to convert
 * CSR defined 80211 mode ENUMs to DIAG defined 80211 mode ENUMs
 *
 * Return: DIAG 80211mode
 */
enum mgmt_dot11_mode
diag_dot11_mode_from_csr_type(enum csr_cfgdot11mode dot11mode);
/**
 * diag_ch_width_from_csr_type() - to convert CSR ch width to DIAG ch width
 * @ch_width: CSR channel width
 *
 * DIAG tool understands its own ENUMs, so this API can be used to convert
 * CSR defined ch width ENUMs to DIAG defined ch width ENUMs
 *
 * Return: DIAG channel width
 */
enum mgmt_ch_width diag_ch_width_from_csr_type(enum phy_ch_width ch_width);
/**
 * diag_persona_from_csr_type() - to convert QDF persona to DIAG persona
 * @persona: QDF persona
 *
 * DIAG tool understands its own ENUMs, so this API can be used to convert
 * QDF defined persona type ENUMs to DIAG defined persona type ENUMs
 *
 * Return: DIAG persona
 */
enum mgmt_bss_type diag_persona_from_csr_type(enum QDF_OPMODE persona);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#endif /* #ifdef FEATURE_WLAN_DIAG_SUPPORT_CSR */
/*
 * csr_scan_result_purge() -
 * Remove all items(tCsrScanResult) in the list and free memory for each item
 * hScanResult - returned from csr_scan_get_result. hScanResult is considered
 * gone by calling this function and even before this function reutrns.
 * Return QDF_STATUS
 */
<<<<<<< HEAD
QDF_STATUS csr_scan_result_purge(tpAniSirGlobal pMac,
=======
QDF_STATUS csr_scan_result_purge(struct mac_context *mac,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				 tScanResultHandle hScanResult);

/* /////////////////////////////////////////Common Scan ends */

/*
 * csr_roam_connect() -
 * To inititiate an association
 * pProfile - can be NULL to join to any open ones
 * pRoamId - to get back the request ID
 * Return QDF_STATUS
 */
<<<<<<< HEAD
QDF_STATUS csr_roam_connect(tpAniSirGlobal pMac, uint32_t sessionId,
			    tCsrRoamProfile *pProfile,
=======
QDF_STATUS csr_roam_connect(struct mac_context *mac, uint32_t sessionId,
			    struct csr_roam_profile *pProfile,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			    uint32_t *pRoamId);

/*
 * csr_roam_reassoc() -
 * To inititiate a re-association
 * pProfile - can be NULL to join the currently connected AP. In that
 * case modProfileFields should carry the modified field(s) which could trigger
 * reassoc
 * modProfileFields - fields which are part of tCsrRoamConnectedProfile
 * that might need modification dynamically once STA is up & running and this
 * could trigger a reassoc
 * pRoamId - to get back the request ID
 * Return QDF_STATUS
 */
<<<<<<< HEAD
QDF_STATUS csr_roam_reassoc(tpAniSirGlobal pMac, uint32_t sessionId,
			    tCsrRoamProfile *pProfile,
			    tCsrRoamModifyProfileFields modProfileFields,
			    uint32_t *pRoamId);

/*
 * csr_roam_reconnect() -
 * To disconnect and reconnect with the same profile
 *
 * Return QDF_STATUS. It returns fail if currently not connected
 */
QDF_STATUS csr_roam_reconnect(tpAniSirGlobal pMac, uint32_t sessionId);

/*
 * csr_roam_set_pmkid_cache() -
 * return the PMKID candidate list
 *
 * pPMKIDCache - caller allocated buffer point to an array of tPmkidCacheInfo
 * numItems - a variable that has the number of tPmkidCacheInfo allocated
 * when retruning, this is either the number needed or number of items put
 * into pPMKIDCache
 * Return QDF_STATUS - when fail, it usually means the buffer allocated is not
 * big enough and pNumItems has the number of tPmkidCacheInfo.
 * \Note: pNumItems is a number of tPmkidCacheInfo, not
 * sizeof(tPmkidCacheInfo) * something
 */
QDF_STATUS csr_roam_set_pmkid_cache(tpAniSirGlobal pMac, uint32_t sessionId,
				    tPmkidCacheInfo *pPMKIDCache,
				   uint32_t numItems, bool update_entire_cache);

=======
QDF_STATUS csr_roam_reassoc(struct mac_context *mac, uint32_t sessionId,
			    struct csr_roam_profile *pProfile,
			    tCsrRoamModifyProfileFields modProfileFields,
			    uint32_t *pRoamId);

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#ifdef WLAN_FEATURE_ROAM_OFFLOAD
/*
 * csr_get_pmk_info(): store PMK in pmk_cache
 * @mac_ctx: pointer to global structure for MAC
 * @session_id: Sme session id
 * @pmk_cache: pointer to a structure of Pmk
 *
 * This API gets the PMK from the session and
 * stores it in the pmk_cache
 *
 * Return: none
 */
<<<<<<< HEAD
void csr_get_pmk_info(tpAniSirGlobal mac_ctx, uint8_t session_id,
		      tPmkidCacheInfo *pmk_cache);

/*
 * csr_roam_set_psk_pmk() -
 * store PSK/PMK
 * pMac  - pointer to global structure for MAC
 * sessionId - Sme session id
 * pPSK_PMK - pointer to an array of Psk/Pmk
 * Return QDF_STATUS - usually it succeed unless sessionId is not found
 * Note:
 */
QDF_STATUS csr_roam_set_psk_pmk(tpAniSirGlobal pMac, uint32_t sessionId,
				uint8_t *pPSK_PMK, size_t pmk_len);

QDF_STATUS csr_roam_set_key_mgmt_offload(tpAniSirGlobal mac_ctx,
=======
void csr_get_pmk_info(struct mac_context *mac_ctx, uint8_t session_id,
		      tPmkidCacheInfo *pmk_cache);

/*
 * csr_roam_set_psk_pmk() - store PSK/PMK in CSR session
 *
 * @mac  - pointer to global structure for MAC
 * @sessionId - Sme session id
 * @psk_pmk - pointer to an array of PSK/PMK
 * @update_to_fw - Send RSO update config command to firmware to update
 * PMK
 *
 * Return QDF_STATUS - usually it succeed unless sessionId is not found
 */
QDF_STATUS csr_roam_set_psk_pmk(struct mac_context *mac, uint32_t sessionId,
				uint8_t *psk_pmk, size_t pmk_len,
				bool update_to_fw);

QDF_STATUS csr_roam_set_key_mgmt_offload(struct mac_context *mac_ctx,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
					 uint32_t session_id,
					 bool roam_key_mgmt_offload_enabled,
					 struct pmkid_mode_bits *pmkid_modes);
#endif
/*
 * csr_roam_get_wpa_rsn_req_ie() -
 * Return the WPA or RSN IE CSR passes to PE to JOIN request or START_BSS
 * request
 * pLen - caller allocated memory that has the length of pBuf as input.
 * Upon returned, *pLen has the needed or IE length in pBuf.
 * pBuf - Caller allocated memory that contain the IE field, if any, upon return
 * Return QDF_STATUS - when fail, it usually means the buffer allocated is not
 * big enough
 */
<<<<<<< HEAD
QDF_STATUS csr_roam_get_wpa_rsn_req_ie(tpAniSirGlobal pMac, uint32_t sessionId,
=======
QDF_STATUS csr_roam_get_wpa_rsn_req_ie(struct mac_context *mac, uint32_t sessionId,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				       uint32_t *pLen, uint8_t *pBuf);

/*
 * csr_roam_get_wpa_rsn_rsp_ie() -
 * Return the WPA or RSN IE from the beacon or probe rsp if connected
 *
 * pLen - caller allocated memory that has the length of pBuf as input.
 * Upon returned, *pLen has the needed or IE length in pBuf.
 * pBuf - Caller allocated memory that contain the IE field, if any, upon return
 * Return QDF_STATUS - when fail, it usually means the buffer allocated is not
 * big enough
 */
<<<<<<< HEAD
QDF_STATUS csr_roam_get_wpa_rsn_rsp_ie(tpAniSirGlobal pMac, uint32_t sessionId,
				       uint32_t *pLen, uint8_t *pBuf);

/*
 * csr_roam_get_num_pmkid_cache() -
 * Return number of PMKID cache entries
 *
 * Return uint32_t - the number of PMKID cache entries
 */
uint32_t csr_roam_get_num_pmkid_cache(tpAniSirGlobal pMac, uint32_t sessionId);

/*
 * csr_roam_get_pmkid_cache() -
 * Return PMKID cache from CSR
 *
 * pNum - caller allocated memory that has the space of the number of pBuf
 * tPmkidCacheInfo as input. Upon returned, *pNum has the needed or actually
 * number in tPmkidCacheInfo.
 * pPmkidCache - Caller allocated memory that contains PMKID cache, if any,
 * upon return
 * Return QDF_STATUS - when fail, it usually means the buffer allocated is
 * not big enough
 */
QDF_STATUS csr_roam_get_pmkid_cache(tpAniSirGlobal pMac, uint32_t sessionId,
				  uint32_t *pNum, tPmkidCacheInfo *pPmkidCache);

=======
QDF_STATUS csr_roam_get_wpa_rsn_rsp_ie(struct mac_context *mac, uint32_t sessionId,
				       uint32_t *pLen, uint8_t *pBuf);

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/**
 * csr_roam_get_connect_profile() - To return the current connect profile,
 * caller must call csr_roam_free_connect_profile after it is done and before
 * reuse for another csr_roam_get_connect_profile call.
 *
<<<<<<< HEAD
 * @pMac:          pointer to global adapter context
=======
 * @mac:          pointer to global adapter context
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @sessionId:     session ID
 * @pProfile:      pointer to a caller allocated structure
 *                 tCsrRoamConnectedProfile
 *
 * Return: QDF_STATUS. Failure if not connected, success otherwise
 */
<<<<<<< HEAD
QDF_STATUS csr_roam_get_connect_profile(tpAniSirGlobal pMac, uint32_t sessionId,
					tCsrRoamConnectedProfile *pProfile);

/*
 * csr_roam_get_connect_state()
 *  To return the current connect state of Roaming
 *
 * Return QDF_STATUS
 */
QDF_STATUS csr_roam_get_connect_state(tpAniSirGlobal pMac, uint32_t sessionId,
				      eCsrConnectState *pState);

=======
QDF_STATUS csr_roam_get_connect_profile(struct mac_context *mac, uint32_t sessionId,
					tCsrRoamConnectedProfile *pProfile);

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
void csr_roam_free_connect_profile(tCsrRoamConnectedProfile *profile);

/*
 * csr_apply_channel_and_power_list() -
<<<<<<< HEAD
 *  HDD calls this function to set the WNI_CFG_VALID_CHANNEL_LIST base on the
=======
 *  HDD calls this function to set the CFG_VALID_CHANNEL_LIST base on the
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * band/mode settings. This function must be called after CFG is downloaded
 * and all the band/mode setting already passed into CSR.

 * Return QDF_STATUS
 */
<<<<<<< HEAD
QDF_STATUS csr_apply_channel_and_power_list(tpAniSirGlobal pMac);

/*
 * csr_roam_connect_to_last_profile() -
 * To disconnect and reconnect with the same profile
 *
 * Return QDF_STATUS. It returns fail if currently connected
 */
QDF_STATUS csr_roam_connect_to_last_profile(tpAniSirGlobal pMac,
					uint32_t sessionId);

/*
 * csr_roam_disconnect() -
 *  To disconnect from a network
 *
 * Reason -- To indicate the reason for disconnecting. Currently, only
 * eCSR_DISCONNECT_REASON_MIC_ERROR is meanful.
 * Return QDF_STATUS
 */
QDF_STATUS csr_roam_disconnect(tpAniSirGlobal pMac, uint32_t sessionId,
			       eCsrRoamDisconnectReason reason);

/*
 * csr_scan_get_pmkid_candidate_list() -
 *  Return the PMKID candidate list
 *
 * pPmkidList - caller allocated buffer point to an array of tPmkidCandidateInfo
 * pNumItems - pointer to a variable that has the number of tPmkidCandidateInfo
 * allocated when retruning, this is either the number needed or number of
 * itemsput into pPmkidList
 * Return QDF_STATUS - when fail, it usually means the buffer allocated is not
 * big enough and pNumItems has the number of tPmkidCandidateInfo.
 * Note: pNumItems is a number of tPmkidCandidateInfo, not
 * sizeof(tPmkidCandidateInfo) * something
 */
QDF_STATUS csr_scan_get_pmkid_candidate_list(tpAniSirGlobal pMac,
						uint32_t sessionId,
					     tPmkidCandidateInfo *pPmkidList,
					     uint32_t *pNumItems);
=======
QDF_STATUS csr_apply_channel_and_power_list(struct mac_context *mac);

/*
 * csr_roam_disconnect() - To disconnect from a network
 * @mac: pointer to mac context
 * @session_id: Session ID
 * @reason: CSR disconnect reason code as per @enum eCsrRoamDisconnectReason
 * @mac_reason: Mac Disconnect reason code as per @enum eSirMacReasonCodes
 *
 * Return QDF_STATUS
 */
QDF_STATUS csr_roam_disconnect(struct mac_context *mac, uint32_t session_id,
			       eCsrRoamDisconnectReason reason,
			       tSirMacReasonCodes mac_reason);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/* This function is used to stop a BSS. It is similar of csr_roamIssueDisconnect
 * but this function doesn't have any logic other than blindly trying to stop
 * BSS
 */
<<<<<<< HEAD
QDF_STATUS csr_roam_issue_stop_bss_cmd(tpAniSirGlobal pMac, uint32_t sessionId,
				       bool fHighPriority);

void csr_call_roaming_completion_callback(tpAniSirGlobal pMac,
					  tCsrRoamSession *pSession,
					  tCsrRoamInfo *pRoamInfo,
					uint32_t roamId,
					  eCsrRoamResult roamResult);
/**
 * csr_roam_issue_disassociate_sta_cmd() - disassociate a associated station
 * @pMac:          Pointer to global structure for MAC
=======
QDF_STATUS csr_roam_issue_stop_bss_cmd(struct mac_context *mac, uint32_t sessionId,
				       bool fHighPriority);

void csr_call_roaming_completion_callback(struct mac_context *mac,
					  struct csr_roam_session *pSession,
					  struct csr_roam_info *roam_info,
					  uint32_t roamId,
					  eCsrRoamResult roamResult);
/**
 * csr_roam_issue_disassociate_sta_cmd() - disassociate a associated station
 * @mac:          Pointer to global structure for MAC
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @sessionId:     Session Id for Soft AP
 * @p_del_sta_params: Pointer to parameters of the station to disassoc
 *
 * CSR function that HDD calls to issue a deauthenticate station command
 *
 * Return: QDF_STATUS_SUCCESS on success or another QDF_STATUS_* on error
 */
<<<<<<< HEAD
QDF_STATUS csr_roam_issue_disassociate_sta_cmd(tpAniSirGlobal pMac,
					       uint32_t sessionId,
					       struct tagCsrDelStaParams
					       *p_del_sta_params);
/**
 * csr_roam_issue_deauth_sta_cmd() - issue deauthenticate station command
 * @pMac:          Pointer to global structure for MAC
=======
QDF_STATUS csr_roam_issue_disassociate_sta_cmd(struct mac_context *mac,
					       uint32_t sessionId,
					       struct csr_del_sta_params
					       *p_del_sta_params);
/**
 * csr_roam_issue_deauth_sta_cmd() - issue deauthenticate station command
 * @mac:          Pointer to global structure for MAC
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @sessionId:     Session Id for Soft AP
 * @pDelStaParams: Pointer to parameters of the station to deauthenticate
 *
 * CSR function that HDD calls to issue a deauthenticate station command
 *
 * Return: QDF_STATUS_SUCCESS on success or another QDF_STATUS_** on error
 */
<<<<<<< HEAD
QDF_STATUS csr_roam_issue_deauth_sta_cmd(tpAniSirGlobal pMac,
		uint32_t sessionId,
		struct tagCsrDelStaParams *pDelStaParams);

/*
 * csr_roam_issue_tkip_counter_measures() -
 * csr function that HDD calls to start and stop tkip countermeasures
 *
 * sessionId - session Id for Soft AP
 * bEnable   - Flag to start/stop countermeasures
 * Return QDF_STATUS
 */
QDF_STATUS csr_roam_issue_tkip_counter_measures(tpAniSirGlobal pMac,
					uint32_t sessionId, bool bEnable);

/*
 * csr_roam_get_associated_stas
 *  csr function that HDD calls to get list of associated stations based on
 * module ID
 * sessionId - session Id for Soft AP
 * modId - module ID - PE/HAL/TL
 * pUsrContext - Opaque HDD context
 * pfnSapEventCallback - Sap event callback in HDD
 * pAssocStasBuf - Caller allocated memory to be filled with associatd
 * stations info
 * Return QDF_STATUS
 */
QDF_STATUS csr_roam_get_associated_stas(tpAniSirGlobal pMac, uint32_t sessionId,
					QDF_MODULE_ID modId, void *pUsrContext,
					void *pfnSapEventCallback,
					uint8_t *pAssocStasBuf);

QDF_STATUS csr_send_mb_get_associated_stas_req_msg(tpAniSirGlobal pMac,
						   uint32_t sessionId,
						   QDF_MODULE_ID modId,
						   struct qdf_mac_addr bssId,
						   void *pUsrContext,
						   void *pfnSapEventCallback,
						   uint8_t *pAssocStasBuf);

/*
 * csr_roam_get_wps_session_overlap() -
 * csr function that HDD calls to get WPS PBC session overlap information
 *
 * sessionId - session Id for Soft AP
 * pUsrContext - Opaque HDD context
 * pfnSapEventCallback - Sap event callback in HDD
 * pRemoveMac - pointer to MAC address of session to be removed
 * Return QDF_STATUS
 */
QDF_STATUS csr_roam_get_wps_session_overlap(tpAniSirGlobal pMac,
					uint32_t sessionId,
					    void *pUsrContext,
					    void *pfnSapEventCallback,
					    struct qdf_mac_addr pRemoveMac);

QDF_STATUS csr_send_mb_get_wpspbc_sessions(tpAniSirGlobal pMac,
					   uint32_t sessionId,
					   struct qdf_mac_addr bssId,
					   void *pUsrContext,
					   void *pfnSapEventCallback,
					   struct qdf_mac_addr pRemoveMac);
=======
QDF_STATUS csr_roam_issue_deauth_sta_cmd(struct mac_context *mac,
		uint32_t sessionId,
		struct csr_del_sta_params *pDelStaParams);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/*
 * csr_send_chng_mcc_beacon_interval() -
 *   csr function that HDD calls to send Update beacon interval
 *
 * sessionId - session Id for Soft AP
 * Return QDF_STATUS
 */
QDF_STATUS
<<<<<<< HEAD
csr_send_chng_mcc_beacon_interval(tpAniSirGlobal pMac, uint32_t sessionId);

#ifdef WLAN_FEATURE_HOST_ROAM
void csr_roam_ft_pre_auth_rsp_processor(tHalHandle hHal,
		tpSirFTPreAuthRsp pFTPreAuthRsp);
void csr_release_command_preauth(tpAniSirGlobal mac_ctx, tSmeCmd *command);
#else
static inline void csr_roam_ft_pre_auth_rsp_processor(tHalHandle hHal,
		tpSirFTPreAuthRsp pFTPreAuthRsp)
{}
static inline void csr_release_command_preauth(tpAniSirGlobal mac_ctx,
		tSmeCmd *command)
=======
csr_send_chng_mcc_beacon_interval(struct mac_context *mac, uint32_t sessionId);

/**
 * csr_roam_ft_pre_auth_rsp_processor() - Handle the preauth response
 * @mac_ctx: Global MAC context
 * @preauth_rsp: Received preauthentication response
 *
 * Return: None
 */
#ifdef WLAN_FEATURE_HOST_ROAM
void csr_roam_ft_pre_auth_rsp_processor(struct mac_context *mac_ctx,
					tpSirFTPreAuthRsp pFTPreAuthRsp);
#else
static inline
void csr_roam_ft_pre_auth_rsp_processor(struct mac_context *mac_ctx,
					tpSirFTPreAuthRsp pFTPreAuthRsp)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{}
#endif

#if defined(FEATURE_WLAN_ESE)
void update_cckmtsf(uint32_t *timeStamp0, uint32_t *timeStamp1,
		    uint64_t *incr);
#endif

<<<<<<< HEAD
QDF_STATUS csr_roam_enqueue_preauth(tpAniSirGlobal pMac, uint32_t sessionId,
				    tpSirBssDescription pBssDescription,
				    eCsrRoamReason reason, bool fImmediate);
QDF_STATUS csr_dequeue_roam_command(tpAniSirGlobal pMac, eCsrRoamReason reason);
void csr_init_occupied_channels_list(tpAniSirGlobal pMac, uint8_t sessionId);
bool csr_neighbor_roam_is_new_connected_profile(tpAniSirGlobal pMac,
						uint8_t sessionId);
bool csr_neighbor_roam_connected_profile_match(tpAniSirGlobal pMac,
					       uint8_t sessionId,
					       struct tag_csrscan_result
						*pResult,
					       tDot11fBeaconIEs *pIes);

QDF_STATUS csr_scan_create_entry_in_scan_cache(tpAniSirGlobal pMac,
						uint32_t sessionId,
						struct qdf_mac_addr bssid,
						uint8_t channel);

QDF_STATUS csr_update_channel_list(tpAniSirGlobal pMac);
QDF_STATUS csr_roam_del_pmkid_from_cache(tpAniSirGlobal pMac,
=======
QDF_STATUS csr_roam_enqueue_preauth(struct mac_context *mac, uint32_t sessionId,
				    struct bss_description *pBssDescription,
				    enum csr_roam_reason reason,
				    bool fImmediate);
QDF_STATUS csr_dequeue_roam_command(struct mac_context *mac,
				enum csr_roam_reason reason,
				uint8_t session_id);
void csr_init_occupied_channels_list(struct mac_context *mac, uint8_t sessionId);

QDF_STATUS csr_scan_create_entry_in_scan_cache(struct mac_context *mac,
						uint32_t sessionId,
						struct qdf_mac_addr bssid,
						uint32_t ch_freq);

QDF_STATUS csr_update_channel_list(struct mac_context *mac);
QDF_STATUS csr_roam_del_pmkid_from_cache(struct mac_context *mac,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
					 uint32_t sessionId,
					 tPmkidCacheInfo *pmksa,
					 bool flush_cache);

<<<<<<< HEAD
bool csr_elected_country_info(tpAniSirGlobal pMac);
void csr_add_vote_for_country_info(tpAniSirGlobal pMac, uint8_t *pCountryCode);
void csr_clear_votes_for_country_info(tpAniSirGlobal pMac);

QDF_STATUS csr_send_ext_change_channel(tpAniSirGlobal mac_ctx,
				uint32_t channel, uint8_t session_id);

#ifdef QCA_HT_2040_COEX
QDF_STATUS csr_set_ht2040_mode(tpAniSirGlobal pMac, uint32_t sessionId,
			       ePhyChanBondState cbMode, bool obssEnabled);
#endif
QDF_STATUS csr_scan_handle_search_for_ssid(tpAniSirGlobal mac,
		tSmeCmd *command);
QDF_STATUS csr_scan_handle_search_for_ssid_failure(tpAniSirGlobal mac,
		tSmeCmd *command);

tpSirBssDescription csr_get_fst_bssdescr_ptr(tScanResultHandle result_handle);

tSirBssDescription*
csr_get_bssdescr_from_scan_handle(tScanResultHandle result_handle,
				  tSirBssDescription *bss_descr);
void csr_release_scan_command(tpAniSirGlobal pMac, tSmeCmd *pCommand,
			      eCsrScanStatus scanStatus);
bool is_disconnect_pending(tpAniSirGlobal mac_ctx,
				   uint8_t sessionid);
void csr_scan_active_list_timeout_handle(void *userData);
QDF_STATUS csr_prepare_disconnect_command(tpAniSirGlobal mac,
			uint32_t session_id, tSmeCmd **sme_cmd);
QDF_STATUS csr_roam_prepare_bss_config_from_profile(tpAniSirGlobal mac_ctx,
		tCsrRoamProfile *profile, tBssConfigParam *bss_cfg,
		tSirBssDescription *bss_desc);
void csr_roam_prepare_bss_params(tpAniSirGlobal mac_ctx, uint32_t session_id,
		tCsrRoamProfile *profile, tSirBssDescription *bss_desc,
		tBssConfigParam *bss_cfg, tDot11fBeaconIEs *ies);

void csr_remove_bssid_from_scan_list(tpAniSirGlobal mac_ctx,
	tSirMacAddr bssid);

QDF_STATUS csr_roam_set_bss_config_cfg(tpAniSirGlobal mac_ctx,
		uint32_t session_id,
		tCsrRoamProfile *profile, tSirBssDescription *bss_desc,
		tBssConfigParam *bss_cfg, tDot11fBeaconIEs *ies,
		bool reset_country);
void csr_prune_channel_list_for_mode(tpAniSirGlobal pMac,
				     tCsrChannel *pChannelList);
=======
#if defined(WLAN_SAE_SINGLE_PMK) && defined(WLAN_FEATURE_ROAM_OFFLOAD)
/**
 * csr_clear_sae_single_pmk - API to clear single_pmk_info cache
 * @psoc: psoc common object
 * @vdev_id: session id
 * @pmksa: pmk info
 *
 * Return : None
 */
void csr_clear_sae_single_pmk(struct wlan_objmgr_psoc *psoc,
			      uint8_t vdev_id, tPmkidCacheInfo *pmksa);

void csr_store_sae_single_pmk_to_global_cache(struct mac_context *mac,
					      struct csr_roam_session *session,
					      uint8_t vdev_id);
#else
static inline void
csr_clear_sae_single_pmk(struct wlan_objmgr_psoc *psoc, uint8_t vdev_id,
			 tPmkidCacheInfo *pmksa)
{
}

static inline
void csr_store_sae_single_pmk_to_global_cache(struct mac_context *mac,
					      struct csr_roam_session *session,
					      uint8_t vdev_id)
{}
#endif

QDF_STATUS csr_send_ext_change_channel(struct mac_context *mac_ctx,
				uint32_t channel, uint8_t session_id);

/**
 * csr_csa_start() - request CSA IE transmission from PE
 * @mac_ctx: handle returned by mac_open
 * @session_id: SAP session id
 *
 * Return: QDF_STATUS
 */
QDF_STATUS csr_csa_restart(struct mac_context *mac_ctx, uint8_t session_id);

/**
 * csr_sta_continue_csa() - Continue for CSA for STA after HW mode change
 * @mac_ctx: handle returned by mac_open
 * @vdev_id: STA VDEV ID
 *
 * Return: QDF_STATUS
 */
QDF_STATUS csr_sta_continue_csa(struct mac_context *mac_ctx,
				uint8_t vdev_id);

#ifdef QCA_HT_2040_COEX
QDF_STATUS csr_set_ht2040_mode(struct mac_context *mac, uint32_t sessionId,
			       ePhyChanBondState cbMode, bool obssEnabled);
#endif
QDF_STATUS csr_scan_handle_search_for_ssid(struct mac_context *mac_ctx,
					   uint32_t session_id);
QDF_STATUS csr_scan_handle_search_for_ssid_failure(struct mac_context *mac,
		uint32_t session_id);
void csr_saved_scan_cmd_free_fields(struct mac_context *mac_ctx,
				    struct csr_roam_session *session);
struct bss_description*
csr_get_fst_bssdescr_ptr(tScanResultHandle result_handle);

struct bss_description*
csr_get_bssdescr_from_scan_handle(tScanResultHandle result_handle,
				  struct bss_description *bss_descr);

bool is_disconnect_pending(struct mac_context *mac_ctx,
				   uint8_t sessionid);

QDF_STATUS
csr_roam_prepare_bss_config_from_profile(struct mac_context *mac_ctx,
					 struct csr_roam_profile *profile,
					 struct bss_config_param *bss_cfg,
					 struct bss_description *bss_desc);

void
csr_roam_prepare_bss_params(struct mac_context *mac_ctx, uint32_t session_id,
			    struct csr_roam_profile *profile,
			    struct bss_description *bss_desc,
			    struct bss_config_param *bss_cfg,
			    tDot11fBeaconIEs *ies);

/**
 * csr_remove_bssid_from_scan_list() - remove the bssid from
 * scan list
 * @mac_tx: mac context.
 * @bssid: bssid to be removed
 *
 * This function remove the given bssid from scan list.
 *
 * Return: void.
 */
void csr_remove_bssid_from_scan_list(struct mac_context *mac_ctx,
				     tSirMacAddr bssid);

QDF_STATUS
csr_roam_set_bss_config_cfg(struct mac_context *mac_ctx, uint32_t session_id,
			    struct csr_roam_profile *profile,
			    struct bss_description *bss_desc,
			    struct bss_config_param *bss_cfg,
			    tDot11fBeaconIEs *ies, bool reset_country);

void csr_prune_channel_list_for_mode(struct mac_context *mac,
				     struct csr_channel *pChannelList);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

#ifdef WLAN_FEATURE_11W
bool csr_is_mfpc_capable(struct sDot11fIERSN *rsn);
#else
static inline bool csr_is_mfpc_capable(struct sDot11fIERSN *rsn)
{
	return false;
}
#endif

/**
<<<<<<< HEAD
=======
 * csr_get_rf_band()
 *
 * @channel: channel number
 *
 * This function is used to translate channel number to band
 *
 * Return: BAND_2G -  if 2.4GHZ channel
 *         BAND_5G -  if 5GHZ channel
 */
enum band_info csr_get_rf_band(uint8_t channel);

/**
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * csr_lookup_pmkid_using_bssid() - lookup pmkid using bssid
 * @mac: pointer to mac
 * @session: sme session pointer
 * @pmk_cache: pointer to pmk cache
<<<<<<< HEAD
 * @index: index value needs to be seached
 *
 * Return: true if pmkid is found else false
 */
bool csr_lookup_pmkid_using_bssid(tpAniSirGlobal mac,
					tCsrRoamSession *session,
					tPmkidCacheInfo *pmk_cache,
					uint32_t *index);

=======
 *
 * Return: true if pmkid is found else false
 */
bool csr_lookup_pmkid_using_bssid(struct mac_context *mac,
					struct csr_roam_session *session,
					tPmkidCacheInfo *pmk_cache);

/**
 * csr_lookup_fils_pmkid  - Lookup FILS PMKID using ssid and cache id
 * @mac:       Pointer to mac context
 * @vdev_id:   vdev id
 * @cache_id:  FILS cache id
 * @ssid:      SSID pointer
 * @ssid_len:  SSID length
 * @bssid:     Pointer to the BSSID to lookup
 *
 * Return: True if lookup is successful
 */
bool csr_lookup_fils_pmkid(struct mac_context *mac, uint8_t vdev_id,
			   uint8_t *cache_id, uint8_t *ssid,
			   uint8_t ssid_len, struct qdf_mac_addr *bssid);
/**
 * csr_is_pmkid_found_for_peer() - check if pmkid sent by peer is present
				   in PMK cache. Used in SAP mode.
 * @mac: pointer to mac
 * @session: sme session pointer
 * @peer_mac_addr: mac address of the connecting peer
 * @pmkid: pointer to pmkid(s) send by peer
 * @pmkid_count: number of pmkids sent by peer
 *
 * Return: true if pmkid is found else false
 */
bool csr_is_pmkid_found_for_peer(struct mac_context *mac,
				 struct csr_roam_session *session,
				 tSirMacAddr peer_mac_addr,
				 uint8_t *pmkid, uint16_t pmkid_count);
#ifdef WLAN_FEATURE_11AX
void csr_update_session_he_cap(struct mac_context *mac_ctx,
			struct csr_roam_session *session);
void csr_init_session_twt_cap(struct csr_roam_session *session,
			      uint32_t type_of_persona);
#else
static inline void csr_update_session_he_cap(struct mac_context *mac_ctx,
			struct csr_roam_session *session)
{
}

static inline void csr_init_session_twt_cap(struct csr_roam_session *session,
					    uint32_t type_of_persona)
{
}
#endif
/**
 * csr_get_channel_for_hw_mode_change() - This function to find
 *                                       out if HW mode change
 *                                       is needed for any of
 *                                       the candidate AP which
 *                                       STA could join
 * @mac_ctx: mac context
 * @result_handle: an object for the result.
 * @session_id: STA session ID
 *
 * This function is written to find out for any bss from scan
 * handle a HW mode change to DBS will be needed or not.
 *
 * Return: AP channel freq for which DBS HW mode will be needed. 0
 * means no HW mode change is needed.
 */
uint32_t
csr_get_channel_for_hw_mode_change(struct mac_context *mac_ctx,
				   tScanResultHandle result_handle,
				   uint32_t session_id);

/**
 * csr_scan_get_channel_for_hw_mode_change() - This function to find
 *                                       out if HW mode change
 *                                       is needed for any of
 *                                       the candidate AP which
 *                                       STA could join
 * @mac_ctx: mac context
 * @session_id: STA session ID
 * @profile: profile
 *
 * This function is written to find out for any bss from scan
 * handle a HW mode change to DBS will be needed or not.
 * If there is no candidate AP which requires DBS, this function will return
 * the first Candidate AP's chan.
 *
 * Return: AP channel freq for which HW mode change will be needed. 0
 * means no candidate AP to connect.
 */
uint32_t
csr_scan_get_channel_for_hw_mode_change(
	struct mac_context *mac_ctx, uint32_t session_id,
	struct csr_roam_profile *profile);
/**
 * csr_setup_vdev_session() - API to setup vdev mac session
 * @vdev_mlme: vdev mlme private object
 *
 * This API setsup the vdev session for the mac layer
 *
 * Returns: QDF_STATUS
 */
QDF_STATUS csr_setup_vdev_session(struct vdev_mlme_obj *vdev_mlme);


#ifdef FEATURE_WLAN_DIAG_SUPPORT_CSR
/**
 * csr_get_sta_cxn_info() - This function populates all the connection
 *			    information which is formed by DUT-STA to AP
 * @mac_ctx: pointer to mac context
 * @session: pointer to sta session
 * @conn_profile: pointer to connected DUTSTA-REFAP profile
 * @buf: pointer to char buffer to write all the connection information.
 * @buf_size: maximum size of the provided buffer
 *
 * Returns: None (information gets populated in buffer)
 */
void csr_get_sta_cxn_info(struct mac_context *mac_ctx,
			  struct csr_roam_session *session,
			  struct tagCsrRoamConnectedProfile *conn_profile,
			  char *buf, uint32_t buf_sz);
#endif
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#endif /* CSR_INSIDE_API_H__ */

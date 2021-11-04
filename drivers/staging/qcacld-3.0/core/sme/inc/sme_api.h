/*
<<<<<<< HEAD
 * Copyright (c) 2012-2019 The Linux Foundation. All rights reserved.
=======
 * Copyright (c) 2012-2020 The Linux Foundation. All rights reserved.
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

#if !defined(__SME_API_H)
#define __SME_API_H

/**
 * file  smeApi.h
 *
 * brief prototype for SME APIs
 */

/*--------------------------------------------------------------------------
  Include Files
  ------------------------------------------------------------------------*/
#include "csr_api.h"
<<<<<<< HEAD
#include "cds_mq.h"
#include "qdf_lock.h"
#include "qdf_types.h"
#include "sir_api.h"
#include "cds_reg_service.h"
#include "p2p_api.h"
#include "cds_regdomain.h"
#include "sme_internal.h"
#include "wma_tgt_cfg.h"
#include "wma_sar_public_structs.h"

#include "sme_rrm_internal.h"
#include "sir_types.h"
=======
#include "qdf_lock.h"
#include "qdf_types.h"
#include "sir_api.h"
#include "cds_regdomain.h"
#include "sme_internal.h"
#include "wma_tgt_cfg.h"
#include "wma_fips_public_structs.h"
#include "wma_sar_public_structs.h"
#include "wlan_mlme_public_struct.h"
#include "sme_rrm_internal.h"
#include "sir_types.h"
#include "scheduler_api.h"
#include "wlan_serialization_legacy_api.h"
#include <qca_vendor.h>
#include "wmi_unified.h"
#include "wmi_unified_param.h"

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/*--------------------------------------------------------------------------
  Preprocessor definitions and constants
  ------------------------------------------------------------------------*/

<<<<<<< HEAD
#define SME_SUMMARY_STATS         (1 << eCsrSummaryStats)
#define SME_GLOBAL_CLASSA_STATS   (1 << eCsrGlobalClassAStats)
#define SME_GLOBAL_CLASSD_STATS   (1 << eCsrGlobalClassDStats)
#define SME_PER_CHAIN_RSSI_STATS  (1 << csr_per_chain_rssi_stats)

#define sme_log_rate_limited(rate, level, args...) \
		QDF_TRACE_RATE_LIMITED(rate, QDF_MODULE_ID_SME, level, ## args)
#define sme_log_rate_limited_fl(rate, level, format, args...) \
			sme_log_rate_limited(rate, level, FL(format), ## args)
#define sme_alert_rate_limited(rate, format, args...) \
			sme_log_rate_limited_fl(rate, QDF_TRACE_LEVEL_FATAL,\
				format, ## args)
#define sme_err_rate_limited(rate, format, args...) \
			sme_log_rate_limited_fl(rate, QDF_TRACE_LEVEL_ERROR,\
				format, ## args)
#define sme_warn_rate_limited(rate, format, args...) \
			sme_log_rate_limited_fl(rate, QDF_TRACE_LEVEL_WARN,\
				format, ## args)
#define sme_info_rate_limited(rate, format, args...) \
			sme_log_rate_limited_fl(rate, QDF_TRACE_LEVEL_INFO,\
				format, ## args)
#define sme_debug_rate_limited(rate, format, args...) \
			sme_log_rate_limited_fl(rate, QDF_TRACE_LEVEL_DEBUG,\
				format, ## args)

#define sme_log(level, args...) QDF_TRACE(QDF_MODULE_ID_SME, level, ## args)
#define sme_logfl(level, format, args...) sme_log(level, FL(format), ## args)

#define sme_alert(format, args...) \
		sme_logfl(QDF_TRACE_LEVEL_FATAL, format, ## args)
#define sme_err(format, args...) \
		sme_logfl(QDF_TRACE_LEVEL_ERROR, format, ## args)
#define sme_warn(format, args...) \
		sme_logfl(QDF_TRACE_LEVEL_WARN, format, ## args)
#define sme_info(format, args...) \
		sme_logfl(QDF_TRACE_LEVEL_INFO, format, ## args)
#define sme_debug(format, args...) \
		sme_logfl(QDF_TRACE_LEVEL_DEBUG, format, ## args)

#define SME_ENTER() sme_logfl(QDF_TRACE_LEVEL_DEBUG, "enter")
#define SME_EXIT() sme_logfl(QDF_TRACE_LEVEL_DEBUG, "exit")

/* DBS Scan policy selection ext flags */
#define SME_SCAN_FLAG_EXT_DBS_SCAN_POLICY_MASK  0x00000003
#define SME_SCAN_FLAG_EXT_DBS_SCAN_POLICY_BIT   0
#define SME_SCAN_DBS_POLICY_DEFAULT             0x0
#define SME_SCAN_DBS_POLICY_FORCE_NONDBS        0x1
#define SME_SCAN_DBS_POLICY_IGNORE_DUTY         0x2
#define SME_SCAN_DBS_POLICY_MAX                 0x3
#define SME_SCAN_REJECT_RATE_LIMIT              5
=======
#define sme_alert(params...) QDF_TRACE_FATAL(QDF_MODULE_ID_SME, params)
#define sme_err(params...) QDF_TRACE_ERROR(QDF_MODULE_ID_SME, params)
#define sme_warn(params...) QDF_TRACE_WARN(QDF_MODULE_ID_SME, params)
#define sme_info(params...) QDF_TRACE_INFO(QDF_MODULE_ID_SME, params)
#define sme_debug(params...) QDF_TRACE_DEBUG(QDF_MODULE_ID_SME, params)

#define sme_nofl_alert(params...) \
	QDF_TRACE_FATAL_NO_FL(QDF_MODULE_ID_SME, params)
#define sme_nofl_err(params...) \
	QDF_TRACE_ERROR_NO_FL(QDF_MODULE_ID_SME, params)
#define sme_nofl_warn(params...) \
	QDF_TRACE_WARN_NO_FL(QDF_MODULE_ID_SME, params)
#define sme_nofl_info(params...) \
	QDF_TRACE_INFO_NO_FL(QDF_MODULE_ID_SME, params)
#define sme_nofl_debug(params...) \
	QDF_TRACE_DEBUG_NO_FL(QDF_MODULE_ID_SME, params)

#define sme_alert_rl(params...) QDF_TRACE_FATAL_RL(QDF_MODULE_ID_SME, params)
#define sme_err_rl(params...) QDF_TRACE_ERROR_RL(QDF_MODULE_ID_SME, params)
#define sme_warn_rl(params...) QDF_TRACE_WARN_RL(QDF_MODULE_ID_SME, params)
#define sme_info_rl(params...) QDF_TRACE_INFO_RL(QDF_MODULE_ID_SME, params)
#define sme_debug_rl(params...) QDF_TRACE_DEBUG_RL(QDF_MODULE_ID_SME, params)

#define SME_ENTER() QDF_TRACE_ENTER(QDF_MODULE_ID_SME, "enter")
#define SME_EXIT() QDF_TRACE_EXIT(QDF_MODULE_ID_SME, "exit")
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

#define SME_SESSION_ID_ANY        50
#define SME_SESSION_ID_BROADCAST  0xFF

#define SME_INVALID_COUNTRY_CODE "XX"
#define INVALID_ROAM_ID 0

#define SME_SET_CHANNEL_REG_POWER(reg_info_1, val) do {	\
	reg_info_1 &= 0xff00ffff;	      \
	reg_info_1 |= ((val & 0xff) << 16);   \
} while (0)

#define SME_SET_CHANNEL_MAX_TX_POWER(reg_info_2, val) do { \
	reg_info_2 &= 0xffff00ff;	      \
	reg_info_2 |= ((val & 0xff) << 8);   \
} while (0)

#define SME_CONFIG_TO_ROAM_CONFIG 1
#define ROAM_CONFIG_TO_SME_CONFIG 2

#define NUM_OF_BANDS 2

<<<<<<< HEAD
#define SME_ACTIVE_LIST_CMD_TIMEOUT_VALUE (30*1000)
#define SME_CMD_TIMEOUT_VALUE (SME_ACTIVE_LIST_CMD_TIMEOUT_VALUE + 1000)
/*--------------------------------------------------------------------------
  Type declarations
  ------------------------------------------------------------------------*/
typedef void (*hdd_ftm_msg_processor)(void *);
typedef struct _smeConfigParams {
	tCsrConfigParam csrConfig;
	struct rrm_config_param rrmConfig;
	bool snr_monitor_enabled;
	bool enable_action_oui;
} tSmeConfigParams, *tpSmeConfigParams;

#ifdef FEATURE_WLAN_TDLS
#define SME_TDLS_MAX_SUPP_CHANNELS       128
#define SME_TDLS_MAX_SUPP_OPER_CLASSES   32

typedef struct _smeTdlsPeerCapParams {
	uint8_t isPeerResponder;
	uint8_t peerUapsdQueue;
	uint8_t peerMaxSp;
	uint8_t peerBuffStaSupport;
	uint8_t peerOffChanSupport;
	uint8_t peerCurrOperClass;
	uint8_t selfCurrOperClass;
	uint8_t peerChanLen;
	uint8_t peerChan[SME_TDLS_MAX_SUPP_CHANNELS];
	uint8_t peerOperClassLen;
	uint8_t peerOperClass[SME_TDLS_MAX_SUPP_OPER_CLASSES];
	uint8_t prefOffChanNum;
	uint8_t prefOffChanBandwidth;
	uint8_t opClassForPrefOffChan;
} tSmeTdlsPeerCapParams;

/**
 * eSmeTdlsPeerState - tdls peer state
 * @eSME_TDLS_PEER_STATE_PEERING: tdls connection in progress
 * @eSME_TDLS_PEER_STATE_CONNECTED: tdls peer is connected
 * @eSME_TDLS_PEER_STATE_TEARDOWN: tdls peer is tear down
 * @eSME_TDLS_PEER_ADD_MAC_ADDR: add peer mac into connection table
 * @eSME_TDLS_PEER_REMOVE_MAC_ADDR: remove peer mac from connection table
 */
typedef enum {
	eSME_TDLS_PEER_STATE_PEERING,
	eSME_TDLS_PEER_STATE_CONNECTED,
	eSME_TDLS_PEER_STATE_TEARDOWN,
	eSME_TDLS_PEER_ADD_MAC_ADDR,
	eSME_TDLS_PEER_REMOVE_MAC_ADDR,
} eSmeTdlsPeerState;

typedef struct _smeTdlsPeerStateParams {
	uint32_t vdevId;
	tSirMacAddr peerMacAddr;
	uint32_t peerState;
	tSmeTdlsPeerCapParams peerCap;
} tSmeTdlsPeerStateParams;

#define ENABLE_CHANSWITCH  1
#define DISABLE_CHANSWITCH 2
=======
#define SUPPORTED_CRYPTO_CAPS 0x3FFFF

#define SME_ACTIVE_LIST_CMD_TIMEOUT_VALUE (30*1000)
#define SME_CMD_TIMEOUT_VALUE (SME_ACTIVE_LIST_CMD_TIMEOUT_VALUE + 1000)

/* Disconnect timeout = vdev stop + bss peer delete + 1 sec */
#define SME_CMD_VDEV_DISCONNECT_TIMEOUT (STOP_RESPONSE_TIMER + \
					 SIR_DELETE_STA_TIMEOUT + 1000)
#define SME_DISCONNECT_TIMEOUT (SME_CMD_VDEV_DISCONNECT_TIMEOUT + 1000)

/* AP start timeout = vdev start + 2 sec */
#define SME_CMD_VDEV_START_BSS_TIMEOUT (START_RESPONSE_TIMER + 2000)
#define SME_CMD_START_BSS_TIMEOUT (SME_CMD_VDEV_START_BSS_TIMEOUT + 1000)

/* AP stop timeout = vdev stop + self peer delete + 1 sec */
#define SME_CMD_STOP_BSS_CMD_TIMEOUT (STOP_RESPONSE_TIMER + \
				      SIR_DELETE_STA_TIMEOUT + 1000)
#define SME_CMD_STOP_BSS_TIMEOUT (SME_CMD_STOP_BSS_CMD_TIMEOUT + 1000)

/* Peer disconenct timeout = peer delete + 1 sec */
#define SME_CMD_PEER_DISCONNECT_TIMEOUT (SIR_DELETE_STA_TIMEOUT + 1000)
#define SME_PEER_DISCONNECT_TIMEOUT (SME_CMD_PEER_DISCONNECT_TIMEOUT + 1000)

#define SME_CMD_GET_DISCONNECT_STATS_TIMEOUT 200

/* Roam cmds timeout = vdev start + peer assoc + 1 sec */
#define SME_CMD_ROAM_CMD_TIMEOUT (START_RESPONSE_TIMER + \
				  SIR_PEER_ASSOC_TIMEOUT + 1000)
#define SME_CMD_ADD_DEL_TS_TIMEOUT (4 * 1000)

/*
 * POLICY_MGR_SER_CMD_TIMEOUT should be same as SME_CMD_POLICY_MGR_CMD_TIMEOUT
 * if SME_CMD_POLICY_MGR_CMD_TIMEOUT is changed change
 * POLICY_MGR_SER_CMD_TIMEOUT as well.
 */
#define SME_CMD_POLICY_MGR_CMD_TIMEOUT (SIR_VDEV_PLCY_MGR_TIMEOUT + 1000)
#define SME_POLICY_MGR_CMD_TIMEOUT (SME_CMD_POLICY_MGR_CMD_TIMEOUT + 1000)

#define SME_VDEV_DELETE_CMD_TIMEOUT (DELETE_RESPONSE_TIMER + 2000)
#define SME_CMD_VDEV_CREATE_DELETE_TIMEOUT QDF_MAX(13000, \
						SME_VDEV_DELETE_CMD_TIMEOUT + 1)

/*--------------------------------------------------------------------------
  Type declarations
  ------------------------------------------------------------------------*/
struct sme_config_params {
	struct csr_config_params csr_config;
};

#ifdef FEATURE_WLAN_TDLS
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#define BW_20_OFFSET_BIT   0
#define BW_40_OFFSET_BIT   1
#define BW_80_OFFSET_BIT   2
#define BW_160_OFFSET_BIT  3
<<<<<<< HEAD
typedef struct sme_tdls_chan_switch_params_struct {
	uint32_t vdev_id;
	tSirMacAddr peer_mac_addr;
	uint16_t tdls_off_ch_bw_offset;/* Target Off Channel Bandwidth offset */
	uint8_t tdls_off_channel;      /* Target Off Channel */
	uint8_t tdls_off_ch_mode;      /* TDLS Off Channel Mode */
	uint8_t is_responder;          /* is peer responder or initiator */
	uint8_t opclass;           /* tdls operating class */
} sme_tdls_chan_switch_params;
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#endif /* FEATURE_WLAN_TDLS */

/* Thermal Mitigation*/
typedef struct {
	uint16_t smeMinTempThreshold;
	uint16_t smeMaxTempThreshold;
} tSmeThermalLevelInfo;

<<<<<<< HEAD
#define SME_MAX_THERMAL_LEVELS (4)
#define SME_MAX_THROTTLE_LEVELS (4)

typedef struct {
	/* Array of thermal levels */
	tSmeThermalLevelInfo smeThermalLevels[SME_MAX_THERMAL_LEVELS];
	uint8_t smeThermalMgmtEnabled;
	uint32_t smeThrottlePeriod;
	uint8_t sme_throttle_duty_cycle_tbl[SME_MAX_THROTTLE_LEVELS];
} tSmeThermalParams;

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
typedef enum {
	SME_AC_BK = 0,
	SME_AC_BE = 1,
	SME_AC_VI = 2,
	SME_AC_VO = 3
} sme_ac_enum_type;

<<<<<<< HEAD
/*---------------------------------------------------------------------------
  Enumeration of the various TSPEC directions

  From 802.11e/WMM specifications
  ---------------------------------------------------------------------------*/

typedef enum {
=======
/*
 * Enumeration of the various TSPEC directions
 * From 802.11e/WMM specifications
 */
enum sme_qos_wmm_dir_type {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	SME_QOS_WMM_TS_DIR_UPLINK = 0,
	SME_QOS_WMM_TS_DIR_DOWNLINK = 1,
	SME_QOS_WMM_TS_DIR_RESV = 2,    /* Reserved */
	SME_QOS_WMM_TS_DIR_BOTH = 3,
<<<<<<< HEAD
} sme_qos_wmm_dir_type;
=======
};
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * struct sme_oem_capability - OEM capability to be exchanged between host
 *                             and userspace
 * @ftm_rr: FTM range report capability bit
 * @lci_capability: LCI capability bit
 * @reserved1: reserved
 * @reserved2: reserved
 */
struct sme_oem_capability {
	uint32_t ftm_rr:1;
	uint32_t lci_capability:1;
	uint32_t reserved1:30;
	uint32_t reserved2;
};

/**
<<<<<<< HEAD
 * enum sme_scan_flags -  scan request control flags
 *
 * @SME_SCAN_FLAG_LOW_SPAN: Span corresponds to the total time
 *      taken to accomplish the scan. Thus, this flag intends the driver to
 *      perform the scan request with lesser span/duration. It is specific to
 *      the driver implementations on how this is accomplished. Scan accuracy
 *      may get impacted with this flag. This flag cannot be used with
 * @SME_SCAN_FLAG_LOW_POWER: This flag intends the scan attempts
 *      to consume optimal possible power. Drivers can resort to their
 *      specific means to optimize the power. Scan accuracy may get impacted
 *      with this flag.
 * @SME_SCAN_FLAG_HIGH_ACCURACY: Accuracy here intends to the
 *      extent of scan results obtained. Thus HIGH_ACCURACY scan flag aims to
 *      get maximum possible scan results. This flag hints the driver to use
 *      the best possible scan configuration to improve the accuracy in
 *      scanning.Latency and power use may get impacted with this flag.
 */
enum sme_scan_flags {
	SME_SCAN_FLAG_LOW_SPAN = 1<<0,
	SME_SCAN_FLAG_LOW_POWER = 1<<1,
	SME_SCAN_FLAG_HIGH_ACCURACY = 1<<2,
};
/**
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * struct sme_5g_pref_params : 5G preference params to be read from ini
 * @rssi_boost_threshold_5g: RSSI threshold above which 5 GHz is favored
 * @rssi_boost_factor_5g: Factor by which 5GHz RSSI is boosted
 * @max_rssi_boost_5g: Maximum boost that can be applied to 5GHz RSSI
 * @rssi_penalize_threshold_5g: RSSI threshold below which 5G is not favored
 * @rssi_penalize_factor_5g: Factor by which 5GHz RSSI is penalized
 * @max_rssi_penalize_5g: Maximum penalty that can be applied to 5G RSSI
 */
struct sme_5g_band_pref_params {
	int8_t      rssi_boost_threshold_5g;
	uint8_t     rssi_boost_factor_5g;
	uint8_t     max_rssi_boost_5g;
	int8_t      rssi_penalize_threshold_5g;
	uint8_t     rssi_penalize_factor_5g;
	uint8_t     max_rssi_penalize_5g;
};

<<<<<<< HEAD
/*-------------------------------------------------------------------------
  Function declarations and documenation
  ------------------------------------------------------------------------*/
QDF_STATUS sme_open(tHalHandle hHal);
QDF_STATUS sme_init_chan_list(tHalHandle hal, uint8_t *alpha2,
		enum country_src cc_src);
QDF_STATUS sme_close(tHalHandle hHal);
QDF_STATUS sme_start(tHalHandle hHal);
QDF_STATUS sme_stop(tHalHandle hHal, tHalStopType stopType);
QDF_STATUS sme_open_session(tHalHandle hHal, csr_roam_completeCallback callback,
		void *pContext, uint8_t *pSelfMacAddr,
		uint8_t *pbSessionId, uint32_t type,
		uint32_t subType);
void sme_set_curr_device_mode(tHalHandle hHal,
		enum tQDF_ADAPTER_MODE currDeviceMode);
/**
 * sme_close_session: Close session for scan/roam operation.
 * @hHal: The handle returned by mac_open.
 * @sessionId: A previous opened session's ID.
 * @flush_all_sme_cmds: whether all sme commands needs to be flushed
 * @callback: pointer to callback API
 * @pContext: context needs to be passed to callback
 *
 * @Return: QDF_STATUS
 */
QDF_STATUS sme_close_session(tHalHandle hHal, uint8_t sessionId,
		bool flush_all_sme_cmds,
		csr_roamSessionCloseCallback callback,
		void *pContext);
/**
 * sme_print_commands(): Print active, pending sme and scan commands
 * @hal_handle: The handle returned by mac_open
 *
 * Return: None
 */
void sme_print_commands(tHalHandle hal_handle);
QDF_STATUS sme_update_roam_params(tHalHandle hHal, uint8_t session_id,
		struct roam_ext_params *roam_params_src, int update_param);
#ifdef FEATURE_WLAN_SCAN_PNO
void sme_update_roam_pno_channel_prediction_config(
		tHalHandle hal, tCsrConfigParam *csr_config,
		uint8_t copy_from_to);
#else
static inline void sme_update_roam_pno_channel_prediction_config(
		tHalHandle hal, tCsrConfigParam *csr_config,
		uint8_t copy_from_to)
{}
#endif
QDF_STATUS sme_update_config(tHalHandle hHal,
		tpSmeConfigParams pSmeConfigParams);

/**
 * sme_destroy_config() - destroy the config params allocated dynamically
 * @hal: handle returned by mac_open
 *
 * This function is used to de-allocate the memory for config params
 * which are allocated using sme_update_config() function
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_destroy_config(tHalHandle hal);

QDF_STATUS sme_set11dinfo(tHalHandle hHal, tpSmeConfigParams pSmeConfigParams);
QDF_STATUS sme_get_soft_ap_domain(tHalHandle hHal,
		v_REGDOMAIN_t *domainIdSoftAp);
QDF_STATUS sme_set_reg_info(tHalHandle hHal, uint8_t *apCntryCode);
QDF_STATUS sme_hdd_ready_ind(tHalHandle hHal);
QDF_STATUS sme_process_msg(tHalHandle hHal, cds_msg_t *pMsg);
void sme_free_msg(tHalHandle hHal, cds_msg_t *pMsg);
QDF_STATUS sme_scan_request(tHalHandle hHal, uint8_t sessionId,
		tCsrScanRequest *, csr_scan_completeCallback callback,
		void *pContext);
QDF_STATUS sme_scan_get_result(tHalHandle hHal, uint8_t sessionId,
		tCsrScanResultFilter *pFilter,
		tScanResultHandle *phResult);
QDF_STATUS sme_get_ap_channel_from_scan_cache(tHalHandle hHal,
		tCsrRoamProfile *profile,
		tScanResultHandle *scan_cache,
		uint8_t *ap_chnl_id);
bool sme_store_joinreq_param(tHalHandle hal_handle,
		tCsrRoamProfile *profile,
		tScanResultHandle scan_cache,
		uint32_t *roam_id,
		uint32_t session_id);
bool sme_clear_joinreq_param(tHalHandle hal_handle,
		uint32_t session_id);
QDF_STATUS sme_issue_stored_joinreq(tHalHandle hal_handle,
		uint32_t *roam_id,
		uint32_t session_id);
QDF_STATUS sme_scan_flush_result(tHalHandle hHal);
QDF_STATUS sme_filter_scan_results(tHalHandle hHal, uint8_t sessionId);
QDF_STATUS sme_scan_flush_p2p_result(tHalHandle hHal, uint8_t sessionId);
tCsrScanResultInfo *sme_scan_result_get_first(tHalHandle,
		tScanResultHandle hScanResult);
tCsrScanResultInfo *sme_scan_result_get_next(tHalHandle,
		tScanResultHandle hScanResult);
QDF_STATUS sme_scan_result_purge(tHalHandle hHal,
		tScanResultHandle hScanResult);
QDF_STATUS sme_scan_get_pmkid_candidate_list(tHalHandle hHal, uint8_t sessionId,
		tPmkidCandidateInfo *pPmkidList,
		uint32_t *pNumItems);
QDF_STATUS sme_roam_connect(tHalHandle hHal, uint8_t sessionId,
		tCsrRoamProfile *pProfile, uint32_t *pRoamId);
QDF_STATUS sme_roam_reassoc(tHalHandle hHal, uint8_t sessionId,
		tCsrRoamProfile *pProfile,
		tCsrRoamModifyProfileFields modProfileFields,
		uint32_t *pRoamId, bool fForce);
QDF_STATUS sme_roam_connect_to_last_profile(tHalHandle hHal, uint8_t sessionId);
QDF_STATUS sme_roam_disconnect(tHalHandle hHal, uint8_t sessionId,
		eCsrRoamDisconnectReason reason);
void sme_dhcp_done_ind(tHalHandle hal, uint8_t session_id);
QDF_STATUS sme_roam_stop_bss(tHalHandle hHal, uint8_t sessionId);
QDF_STATUS sme_roam_get_associated_stas(tHalHandle hHal, uint8_t sessionId,
		QDF_MODULE_ID modId, void *pUsrContext,
		void *pfnSapEventCallback,
		uint8_t *pAssocStasBuf);
QDF_STATUS sme_roam_disconnect_sta(tHalHandle hHal, uint8_t sessionId,
		struct tagCsrDelStaParams *p_del_sta_params);
QDF_STATUS sme_roam_deauth_sta(tHalHandle hHal, uint8_t sessionId,
		struct tagCsrDelStaParams *pDelStaParams);
QDF_STATUS sme_roam_tkip_counter_measures(tHalHandle hHal, uint8_t sessionId,
		bool bEnable);
QDF_STATUS sme_roam_get_wps_session_overlap(tHalHandle hHal, uint8_t sessionId,
		void *pUsrContext,
		void *pfnSapEventCallback,
		struct qdf_mac_addr pRemoveMac);
QDF_STATUS sme_roam_get_connect_state(tHalHandle hHal, uint8_t sessionId,
		eCsrConnectState *pState);
QDF_STATUS sme_roam_get_connect_profile(tHalHandle hHal, uint8_t sessionId,
		tCsrRoamConnectedProfile *pProfile);
void sme_roam_free_connect_profile(tCsrRoamConnectedProfile *profile);
QDF_STATUS sme_roam_set_pmkid_cache(tHalHandle hHal, uint8_t sessionId,
		tPmkidCacheInfo *pPMKIDCache,
		uint32_t numItems,
		bool update_entire_cache);

#ifdef WLAN_FEATURE_ROAM_OFFLOAD
/**
 * sme_get_pmk_info(): A wrapper function to request CSR to save PMK
 * @hal: Global structure
=======
/**
 * struct sme_session_params: Session creation params passed by HDD layer
 * @vdev: pointer to vdev object
 */
struct sme_session_params {
	struct wlan_objmgr_vdev *vdev;
};

#define MAX_CANDIDATE_INFO 10

/**
 * struct bss_candidate_info - Candidate bss information
 *
 * @bssid : BSSID of candidate bss
 * @status : status code for candidate bss
 */
struct bss_candidate_info {
	struct qdf_mac_addr bssid;
	uint32_t status;
};

/*
 * MBO transition reason codes
 */
enum {
	MBO_TRANSITION_REASON_UNSPECIFIED,
	MBO_TRANSITION_REASON_EXCESSIVE_FRAME_LOSS_RATE,
	MBO_TRANSITION_REASON_EXCESSIVE_DELAY_FOR_CURRENT_TRAFFIC,
	MBO_TRANSITION_REASON_INSUFFICIENT_BANDWIDTH_FOR_CURRENT_TRAFFIC,
	MBO_TRANSITION_REASON_LOAD_BALANCING,
	MBO_TRANSITION_REASON_LOW_RSSI,
	MBO_TRANSITION_REASON_RECEIVED_EXCESSIVE_RETRANSMISSIONS,
	MBO_TRANSITION_REASON_HIGH_INTERFERENCE,
	MBO_TRANSITION_REASON_GRAY_ZONE,
	MBO_TRANSITION_REASON_TRANSITIONING_TO_PREMIUM_AP,
};

/*-------------------------------------------------------------------------
  Function declarations and documenation
  ------------------------------------------------------------------------*/
QDF_STATUS sme_open(mac_handle_t mac_handle);
QDF_STATUS sme_init_chan_list(mac_handle_t mac_handle, uint8_t *alpha2,
		enum country_src cc_src);
QDF_STATUS sme_close(mac_handle_t mac_handle);
QDF_STATUS sme_start(mac_handle_t mac_handle);

/**
 * sme_stop() - Stop all SME modules and put them at idle state
 * @mac_handle: Opaque handle to the MAC context
 *
 * The function stops each module in SME. Upon return, all modules are
 * at idle state ready to start.
 *
 * This is a synchronous call
 *
 * Return: QDF_STATUS_SUCCESS if SME is stopped.  Other status means
 *         SME failed to stop one or more modules but caller should
 *         still consider SME is stopped.
 */
QDF_STATUS sme_stop(mac_handle_t mac_handle);

/**
 * sme_populate_nss_chain_params() - fill vdev nss chain params from ini
 * @mac_handle: The handle returned by mac_open.
 * @vdev_ini_cfg: pointer to the structure to be filled
 * @device_mode: device mode (eg STA, SAP etc.)
 * @rf_chains_supported: number of chains supported by fw(updated during
 *                       service ready event)
 *
 * This API will fill the nss chain params for the particular vdev from ini
 * configuration for the respective vdev.
 *
 * Return: none
 */
void sme_populate_nss_chain_params(mac_handle_t mac_handle,
			     struct wlan_mlme_nss_chains *vdev_ini_cfg,
			     enum QDF_OPMODE device_mode,
			     uint8_t rf_chains_supported);

/**
 * sme_store_nss_chains_cfg_in_vdev() - fill vdev nss chain params from ini
 * @vdev: Pointer to vdev obj
 * @vdev_ini_cfg: pointer to the structure the values are to be filled from
 *
 * This API will copy the nss chain params for the particular vdev from ini
 * configuration to the respective vdev's dynamic, and ini config.
 *
 * Return: none
 */
void
sme_store_nss_chains_cfg_in_vdev(struct wlan_objmgr_vdev *vdev,
				 struct wlan_mlme_nss_chains *vdev_ini_cfg);

/**
 * sme_modify_nss_chains_tgt_cfg() - Change the nss in ini for
 * particular opmode, and band, according to the chain config supported by FW.
 * @mac_handle: The handle returned by mac_open.
 * @vdev_op_mode: vdev operation mode.
 * @band:- band for which user wants to change nss.
 *
 * This API will change the nss in ini (for eg. rx_nss_2g) in the mlme cfg i.e
 * the global config structure kept in mac context, according to the max
 * supported chains per band which is got as part of ext service ready event.
 *
 * Return: none
 */
void
sme_modify_nss_chains_tgt_cfg(mac_handle_t mac_handle,
			      enum QDF_OPMODE vdev_op_mode,
			      enum nss_chains_band_info band);

/**
 * sme_update_nss_in_mlme_cfg() - Change the nss in ini(rx_nss_(band)) for
 * particular opmode, and band.
 * @mac_handle: The handle returned by mac_open.
 * @rx_nss: new value of rx nss that user wants to change.
 * @tx_nss: new value of tx nss that user wants to change.
 * @vdev_op_mode: vdev operation mode.
 * @band:- band for which user wants to change nss.
 *
 * This API will change the nss in ini (for eg. rx_nss_2g) in the mlme cfg i.e
 * the global config structure kept in mac context.
 *
 * Return: none
 */
void
sme_update_nss_in_mlme_cfg(mac_handle_t mac_handle,
			   uint8_t rx_nss, uint8_t tx_nss,
			   enum QDF_OPMODE vdev_op_mode,
			   enum nss_chains_band_info band);

/**
 * sme_nss_chains_update() - validate and send the user params to fw
 * @mac_handle: The handle returned by mac_open.
 * @user_cfg: pointer to the structure to be validated and sent to fw
 * @vdev_id: vdev id
 *
 *
 * This API will validate the config, and if found correct will update the
 * config in dynamic config, and send to the fw.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
sme_nss_chains_update(mac_handle_t mac_handle,
		      struct wlan_mlme_nss_chains *user_cfg,
		      uint8_t vdev_id);

/**
 * sme_vdev_create() - Create vdev for given persona
 * @mac_handle: The handle returned by mac_open
 * @vdev_params: params required for vdev creation
 *
 * This API will create the object manager vdev and in the same
 * context vdev mlme object manager notification is invoked, which
 * will send the vdev create to the firmware.
 *
 * If the vdev creation is successful the following object is referenced
 * by below modules:
 * 1) WLAN_OBJMGR_ID
 * 2) WLAN_LEGACY_SME_ID
 * 3) WLAN_LEGACY_WMA_ID
 *
 * Return: Newly created Vdev object or NULL incase in any error
 */
struct wlan_objmgr_vdev *sme_vdev_create(mac_handle_t mac_handle,
				  struct wlan_vdev_create_params *vdev_params);


/**
 * sme_vdev_delete() - Delete vdev for given id
 * @mac_handle: The handle returned by mac_open.
 * @vdev: VDEV Object
 *
 * This is a synchronous API. This API needs to be called to delete vdev
 * in SME module before terminating the session completely.
 *
 * The following modules releases their reference to the vdev object:
 * 1) WLAN_LEGACY_WMA_ID
 * 2) WLAN_LEGACY_SME_ID
 *
 * Return: QDF_STATUS_SUCCESS - vdev is deleted.
 *         QDF_STATUS_E_INVAL when failed to delete vdev.
 */
QDF_STATUS sme_vdev_delete(mac_handle_t mac_handle,
			   struct wlan_objmgr_vdev *vdev);

/**
 * sme_cleanup_session() -  clean up sme session info for vdev
 * @mac_handle: mac handle
 * @vdev_id: vdev id
 *
 * Return: none
 */
void sme_cleanup_session(mac_handle_t mac_handle, uint8_t vdev_id);

/**
 * sme_set_curr_device_mode() - Sets the current operating device mode.
 * @mac_handle: The handle returned by mac_open.
 * @curr_device_mode: Current operating device mode.
 */
void sme_set_curr_device_mode(mac_handle_t mac_handle,
			      enum QDF_OPMODE curr_device_mode);

/**
 * sme_update_nud_config() - update nud config
 * @mac_handle: The handle returned by mac_open.
 * @nud_fail_behavior: Vlaue of nud fail behaviour
 */
void sme_update_nud_config(mac_handle_t mac_handle, uint8_t nud_fail_behavior);

QDF_STATUS sme_update_roam_params(mac_handle_t mac_handle,
				  uint8_t session_id,
				  struct roam_ext_params *roam_params_src,
				  int update_param);
QDF_STATUS sme_update_config(mac_handle_t mac_handle,
			     struct sme_config_params *pSmeConfigParams);

QDF_STATUS sme_set11dinfo(mac_handle_t mac_handle,
			  struct sme_config_params *pSmeConfigParams);
QDF_STATUS sme_hdd_ready_ind(mac_handle_t mac_handle);

#ifdef WLAN_BCN_RECV_FEATURE
/*
 * sme_register_bcn_report_pe_cb() - Register SME callback
 * @mac_handle: The handle returned by mac_open.
 * @cb: cb of type beacon_report_cb
 *
 * This function Register SME callback in order to send
 * beacon report to upper layer
 *
 * Return QDF_STATUS_SUCCESS -
 */
QDF_STATUS
sme_register_bcn_report_pe_cb(mac_handle_t mac_handle, beacon_report_cb cb);
#else
static inline QDF_STATUS
sme_register_bcn_report_pe_cb(mac_handle_t mac_handle, beacon_report_cb cb)
{
	return QDF_STATUS_SUCCESS;
}
#endif

/**
 * sme_ser_cmd_callback() - callback from serialization module
 * @cmd: serialization command
 * @reason: reason why serialization module has given this callback
 *
 * Serialization module will give callback to SME for why it triggered
 * the callback
 *
 * Return: QDF_STATUS_SUCCESS
 */
QDF_STATUS sme_ser_cmd_callback(struct wlan_serialization_command *cmd,
				enum wlan_serialization_cb_reason reason);

/**
 * sme_purge_pdev_all_ser_cmd_list() - purge all scan and non-scan
 * active and pending cmds for pdev
 * @mac_handle: pointer to global MAC context
 *
 * Return : none
 */
void sme_purge_pdev_all_ser_cmd_list(mac_handle_t mac_handle);

/*
 * sme_process_msg() - The main message processor for SME.
 * @mac: The global mac context
 * @msg: The message to be processed.
 *
 * This function is called by a message dispatcher when to process a message
 * targeted for SME.
 * This is a synchronous call
 *
 * Return: QDF_STATUS_SUCCESS - SME successfully processed the message.
 * Other status means SME failed to process the message to HAL.
 */
QDF_STATUS sme_process_msg(struct mac_context *mac, struct scheduler_msg *pMsg);

QDF_STATUS sme_mc_process_handler(struct scheduler_msg *msg);
/*
 * sme_scan_get_result() - Return scan results based on filter
 * @mac: Pointer to Global MAC structure
 * @vdev_id: vdev_id
 * @filter: If pFilter is NULL, all cached results are returned
 * @phResult: an object for the result.
 *
 * Return QDF_STATUS
 */
QDF_STATUS sme_scan_get_result(mac_handle_t mac_handle, uint8_t vdev_id,
			       struct scan_filter *filter,
			       tScanResultHandle *phResult);
QDF_STATUS sme_get_ap_channel_from_scan_cache(
		struct csr_roam_profile *profile,
		tScanResultHandle *scan_cache,
		uint32_t *ap_ch_freq);
/**
 * sme_get_ap_channel_from_scan() - a wrapper function to get
 *				  AP's channel id from
 *				  CSR by filtering the
 *				  result which matches
 *				  our roam profile.
 * @profile: SAP profile
 * @ap_ch_freq: pointer to channel id of SAP. Fill the value after finding the
 *              best ap from scan cache.
 *
 * This function is written to get AP's channel id from CSR by filtering
 * the result which matches our roam profile. This is a synchronous call.
 *
 * Return: QDF_STATUS.
 */
QDF_STATUS sme_get_ap_channel_from_scan(void *profile,
					tScanResultHandle *scan_cache,
					uint32_t *ap_ch_freq);

tCsrScanResultInfo *sme_scan_result_get_first(mac_handle_t,
		tScanResultHandle hScanResult);
tCsrScanResultInfo *sme_scan_result_get_next(mac_handle_t,
		tScanResultHandle hScanResult);
QDF_STATUS sme_scan_result_purge(tScanResultHandle hScanResult);
QDF_STATUS sme_roam_connect(mac_handle_t mac_handle, uint8_t sessionId,
		struct csr_roam_profile *pProfile, uint32_t *pRoamId);
QDF_STATUS sme_roam_reassoc(mac_handle_t mac_handle, uint8_t sessionId,
		struct csr_roam_profile *pProfile,
		tCsrRoamModifyProfileFields modProfileFields,
		uint32_t *pRoamId, bool fForce);

/**
 * sme_roam_disconnect() - API to request CSR to disconnect
 * @mac_handle: Opaque handle to the global MAC context
 * @session: SME session identifier
 * @reason: Reason to disconnect
 * @mac_reason: Reason to disconnect as per enum eSirMacReasonCodes
 *
 * Return: QDF Status success or failure
 */
QDF_STATUS sme_roam_disconnect(mac_handle_t mac_handle, uint8_t session,
			       eCsrRoamDisconnectReason reason,
			       tSirMacReasonCodes mac_reason);

void sme_dhcp_done_ind(mac_handle_t mac_handle, uint8_t session_id);
QDF_STATUS sme_roam_stop_bss(mac_handle_t mac_handle, uint8_t sessionId);
QDF_STATUS sme_roam_disconnect_sta(mac_handle_t mac_handle, uint8_t sessionId,
		struct csr_del_sta_params *p_del_sta_params);
QDF_STATUS sme_roam_deauth_sta(mac_handle_t mac_handle, uint8_t sessionId,
		struct csr_del_sta_params *pDelStaParams);
QDF_STATUS sme_roam_get_connect_profile(mac_handle_t mac_handle,
					uint8_t sessionId,
					tCsrRoamConnectedProfile *pProfile);
void sme_roam_free_connect_profile(tCsrRoamConnectedProfile *profile);

#ifdef WLAN_FEATURE_ROAM_OFFLOAD
/**
 * sme_set_roam_scan_ch_event_cb() - Register roam scan ch callback
 * @mac_handle: Opaque handle to the MAC context
 * @cb: callback to be registered
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
sme_set_roam_scan_ch_event_cb(mac_handle_t mac_handle,
			      sme_get_raom_scan_ch_callback cb);

/**
 * sme_get_roam_scan_ch() -API to get roam scan channels
 * @mac_handle: Pointer to mac handle
 * @sta_id: vdev id
 * @pcontext: pointer to the context
 *
 * Extract number of frequencies and frequency list from chan_info and print
 * to the logs.
 *
 * Return: None
 */
QDF_STATUS
sme_get_roam_scan_ch(mac_handle_t mac_handle,
		     uint8_t vdev_id, void *pcontext);

/**
 * sme_get_pmk_info(): A wrapper function to request CSR to save PMK
 * @mac_handle: Global structure
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @session_id: SME session_id
 * @pmk_cache: pointer to a structure of pmk
 *
 * Return: none
 */
<<<<<<< HEAD
void sme_get_pmk_info(tHalHandle hal, uint8_t session_id,
		      tPmkidCacheInfo *pmk_cache);

QDF_STATUS sme_roam_set_psk_pmk(tHalHandle hHal, uint8_t sessionId,
		uint8_t *pPSK_PMK, size_t pmk_len);
#endif
QDF_STATUS sme_roam_get_security_req_ie(tHalHandle hHal, uint8_t sessionId,
		uint32_t *pLen, uint8_t *pBuf,
		eCsrSecurityType secType);
QDF_STATUS sme_roam_get_security_rsp_ie(tHalHandle hHal, uint8_t sessionId,
		uint32_t *pLen, uint8_t *pBuf,
		eCsrSecurityType secType);
uint32_t sme_roam_get_num_pmkid_cache(tHalHandle hHal, uint8_t sessionId);
QDF_STATUS sme_roam_get_pmkid_cache(tHalHandle hHal, uint8_t sessionId,
		uint32_t *pNum,
		tPmkidCacheInfo *pPmkidCache);
QDF_STATUS sme_get_config_param(tHalHandle hHal, tSmeConfigParams *pParam);
QDF_STATUS sme_get_statistics(tHalHandle hHal,
		eCsrStatsRequesterType requesterId,
		uint32_t statsMask, tCsrStatsCallback callback,
		uint32_t periodicity, bool cache, uint8_t staId,
		void *pContext, uint8_t sessionId);
QDF_STATUS sme_get_rssi(tHalHandle hHal,
		tCsrRssiCallback callback,
		uint8_t staId, struct qdf_mac_addr bssId, int8_t lastRSSI,
		void *pContext, void *p_cds_context);
QDF_STATUS sme_get_snr(tHalHandle hHal,
		tCsrSnrCallback callback,
		uint8_t staId, struct qdf_mac_addr bssId, void *pContext);
#ifdef FEATURE_WLAN_ESE
QDF_STATUS sme_get_tsm_stats(tHalHandle hHal,
		tCsrTsmStatsCallback callback,
		uint8_t staId, struct qdf_mac_addr bssId,
		void *pContext, void *p_cds_context, uint8_t tid);
QDF_STATUS sme_set_cckm_ie(tHalHandle hHal,
		uint8_t sessionId,
		uint8_t *pCckmIe, uint8_t cckmIeLen);
QDF_STATUS sme_set_ese_beacon_request(tHalHandle hHal, const uint8_t sessionId,
		const tCsrEseBeaconReq *pEseBcnReq);
QDF_STATUS sme_set_plm_request(tHalHandle hHal, tpSirPlmReq pPlm);
#endif /*FEATURE_WLAN_ESE */
QDF_STATUS sme_cfg_set_int(tHalHandle hal, uint16_t cfg_id, uint32_t value);
QDF_STATUS sme_cfg_set_str(tHalHandle hal, uint16_t cfg_id, uint8_t *str,
		uint32_t length);
QDF_STATUS sme_cfg_get_int(tHalHandle hal, uint16_t cfg_id,
		uint32_t *cfg_value);
QDF_STATUS sme_cfg_get_str(tHalHandle hal, uint16_t cfg_id, uint8_t *str,
		uint32_t *length);
QDF_STATUS sme_get_modify_profile_fields(tHalHandle hHal, uint8_t sessionId,
					 tCsrRoamModifyProfileFields *
					 pModifyProfileFields);

extern QDF_STATUS sme_set_host_power_save(tHalHandle hHal, bool psMode);

void sme_set_dhcp_till_power_active_flag(tHalHandle hHal, uint8_t flag);
extern QDF_STATUS sme_register11d_scan_done_callback(tHalHandle hHal,
		csr_scan_completeCallback);
void sme_deregister11d_scan_done_callback(tHalHandle hHal);

#ifdef FEATURE_OEM_DATA_SUPPORT
extern QDF_STATUS sme_register_oem_data_rsp_callback(tHalHandle h_hal,
		sme_send_oem_data_rsp_msg callback);
void sme_deregister_oem_data_rsp_callback(tHalHandle h_hal);

#else
static inline QDF_STATUS sme_register_oem_data_rsp_callback(tHalHandle h_hal,
		sme_send_oem_data_rsp_msg callback)
{
	return QDF_STATUS_SUCCESS;
}
static inline void sme_deregister_oem_data_rsp_callback(tHalHandle h_hal)
=======
void sme_get_pmk_info(mac_handle_t mac_handle, uint8_t session_id,
		      tPmkidCacheInfo *pmk_cache);

QDF_STATUS sme_roam_set_psk_pmk(mac_handle_t mac_handle, uint8_t sessionId,
				uint8_t *psk_pmk, size_t pmk_len,
				bool update_to_fw);
#else
static inline
void sme_get_pmk_info(mac_handle_t mac_handle, uint8_t session_id,
		      tPmkidCacheInfo *pmk_cache)
{}

static inline QDF_STATUS
sme_get_roam_scan_ch(mac_handle_t mac_handle,
		     uint8_t vdev_id, void *pcontext)
{
	return QDF_STATUS_E_FAILURE;
}

static inline QDF_STATUS
sme_set_roam_scan_ch_event_cb(mac_handle_t mac_handle,
			      void *cb)
{
	return QDF_STATUS_E_FAILURE;
}

static inline
QDF_STATUS sme_roam_set_psk_pmk(mac_handle_t mac_handle, uint8_t sessionId,
				uint8_t *psk_pmk, size_t pmk_len,
				bool update_to_fw)
{
	return QDF_STATUS_SUCCESS;
}
#endif

/**
 * sme_roam_get_wpa_rsn_req_ie() - Retrieve WPA/RSN Request IE
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: ID of the specific session
 * @len: Caller allocated memory that has the length of @buf as input.
 *	Upon returned, @len has the length of the IE store in @buf
 * @buf: Caller allocated memory that contain the IE field, if any,
 *	upon return
 *
 * A wrapper function to request CSR to return the WPA or RSN IE CSR
 * passes to PE to JOIN request or START_BSS request
 * This is a synchronous call.
 *
 * Return: QDF_STATUS - when fail, it usually means the buffer allocated is not
 *			 big enough
 */
QDF_STATUS sme_roam_get_wpa_rsn_req_ie(mac_handle_t mac_handle,
				       uint8_t session_id,
				       uint32_t *len, uint8_t *buf);

/**
 * sme_roam_get_wpa_rsn_rsp_ie() - Retrieve WPA/RSN Response IE
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: ID of the specific session
 * @len: Caller allocated memory that has the length of @buf as input.
 *	Upon returned, @len has the length of the IE store in @buf
 * @buf: Caller allocated memory that contain the IE field, if any,
 *	upon return
 *
 * A wrapper function to request CSR to return the WPA or RSN IE CSR
 * passes to PE to JOIN request or START_BSS request
 * This is a synchronous call.
 *
 * Return: QDF_STATUS - when fail, it usually means the buffer allocated is not
 *			 big enough
 */
QDF_STATUS sme_roam_get_wpa_rsn_rsp_ie(mac_handle_t mac_handle,
				       uint8_t session_id,
				       uint32_t *len, uint8_t *buf);

QDF_STATUS sme_get_config_param(mac_handle_t mac_handle,
				struct sme_config_params *pParam);
QDF_STATUS sme_get_snr(mac_handle_t mac_handle,
		       tCsrSnrCallback callback,
		       struct qdf_mac_addr bssId, void *pContext);
#ifdef FEATURE_WLAN_ESE
QDF_STATUS sme_get_tsm_stats(mac_handle_t mac_handle,
		tCsrTsmStatsCallback callback,
		struct qdf_mac_addr bssId,
		void *pContext, uint8_t tid);
QDF_STATUS sme_set_cckm_ie(mac_handle_t mac_handle,
		uint8_t sessionId,
		uint8_t *pCckmIe, uint8_t cckmIeLen);
QDF_STATUS sme_set_ese_beacon_request(mac_handle_t mac_handle,
				      const uint8_t sessionId,
				      const tCsrEseBeaconReq *in_req);

/**
 * sme_set_plm_request() - set plm request
 * @mac_handle: Opaque handle to the global MAC context
 * @req: Pointer to input plm request
 *
 * Return: QDF_STATUS enumeration
 */
QDF_STATUS sme_set_plm_request(mac_handle_t mac_handle,
			       struct plm_req_params *req);
#endif /*FEATURE_WLAN_ESE */

QDF_STATUS sme_get_modify_profile_fields(mac_handle_t mac_handle,
					 uint8_t sessionId,
					 tCsrRoamModifyProfileFields *
					 pModifyProfileFields);

#ifdef FEATURE_OEM_DATA_SUPPORT
QDF_STATUS sme_register_oem_data_rsp_callback(mac_handle_t mac_handle,
		sme_send_oem_data_rsp_msg callback);
void sme_deregister_oem_data_rsp_callback(mac_handle_t mac_handle);

#else
static inline
QDF_STATUS sme_register_oem_data_rsp_callback(mac_handle_t mac_handle,
					      void *callback)
{
	return QDF_STATUS_SUCCESS;
}

static inline
void sme_deregister_oem_data_rsp_callback(mac_handle_t mac_handle)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
}

#endif

<<<<<<< HEAD
extern QDF_STATUS sme_wow_add_pattern(tHalHandle hHal,
		struct wow_add_pattern *pattern, uint8_t sessionId);
extern QDF_STATUS sme_wow_delete_pattern(tHalHandle hHal,
		struct wow_delete_pattern *pattern, uint8_t sessionId);

void sme_register_ftm_msg_processor(tHalHandle hal,
				    hdd_ftm_msg_processor callback);

extern QDF_STATUS sme_enter_wowl(tHalHandle hHal,
			 void (*enter_wowl_callback_routine)(void
						  *callbackContext,
						  QDF_STATUS  status),
			 void *enter_wowl_callback_context,
#ifdef WLAN_WAKEUP_EVENTS
			 void (*wake_reason_ind_cb)(void *callbackContext,
						 tpSirWakeReasonInd
						 wake_reason_ind),
			 void *wake_reason_ind_cb_ctx,
#endif /* WLAN_WAKEUP_EVENTS */
			 tpSirSmeWowlEnterParams wowl_enter_params,
			 uint8_t sessionId);

extern QDF_STATUS sme_exit_wowl(tHalHandle hHal,
		tpSirSmeWowlExitParams wowl_exit_params);
QDF_STATUS sme_roam_set_key(tHalHandle, uint8_t sessionId,
		tCsrRoamSetKey *pSetKey, uint32_t *pRoamId);
QDF_STATUS sme_get_country_code(tHalHandle hHal, uint8_t *pBuf, uint8_t *pbLen);


void sme_apply_channel_power_info_to_fw(tHalHandle hHal);

/* some support functions */
bool sme_is11d_supported(tHalHandle hHal);
bool sme_is11h_supported(tHalHandle hHal);
bool sme_is_wmm_supported(tHalHandle hHal);

typedef void (*tSmeChangeCountryCallback)(void *pContext);
QDF_STATUS sme_change_country_code(tHalHandle hHal,
		tSmeChangeCountryCallback callback,
		uint8_t *pCountry,
		void *pContext,
		void *p_cds_context,
		bool countryFromUserSpace,
		bool sendRegHint);
QDF_STATUS sme_generic_change_country_code(tHalHandle hHal,
					   uint8_t *pCountry);

QDF_STATUS sme_update_channel_list(tpAniSirGlobal mac_ctx);

QDF_STATUS sme_tx_fail_monitor_start_stop_ind(tHalHandle hHal,
		uint8_t tx_fail_count,
		void *txFailIndCallback);
QDF_STATUS sme_dhcp_start_ind(tHalHandle hHal,
		uint8_t device_mode,
		uint8_t *macAddr, uint8_t sessionId);
QDF_STATUS sme_dhcp_stop_ind(tHalHandle hHal,
		uint8_t device_mode,
		uint8_t *macAddr, uint8_t sessionId);
void sme_set_cfg_privacy(tHalHandle hHal, tCsrRoamProfile *pProfile,
		bool fPrivacy);
void sme_get_recovery_stats(tHalHandle hHal);
QDF_STATUS sme_neighbor_report_request(tHalHandle hHal, uint8_t sessionId,
		tpRrmNeighborReq pRrmNeighborReq,
		tpRrmNeighborRspCallbackInfo callbackInfo);
QDF_STATUS sme_get_wcnss_wlan_compiled_version(tHalHandle hHal,
		tSirVersionType * pVersion);
QDF_STATUS sme_get_wcnss_wlan_reported_version(tHalHandle hHal,
		tSirVersionType *pVersion);
QDF_STATUS sme_get_wcnss_software_version(tHalHandle hHal,
		uint8_t *pVersion, uint32_t versionBufferSize);
QDF_STATUS sme_get_wcnss_hardware_version(tHalHandle hHal,
		uint8_t *pVersion, uint32_t versionBufferSize);
#ifdef FEATURE_WLAN_WAPI
QDF_STATUS sme_scan_get_bkid_candidate_list(tHalHandle hHal, uint32_t sessionId,
		tBkidCandidateInfo * pBkidList,
		uint32_t *pNumItems);
#endif /* FEATURE_WLAN_WAPI */
#ifdef FEATURE_OEM_DATA_SUPPORT
QDF_STATUS sme_oem_data_req(tHalHandle hHal, struct oem_data_req *);
QDF_STATUS sme_oem_update_capability(tHalHandle hHal,
				     struct sme_oem_capability *cap);
QDF_STATUS sme_oem_get_capability(tHalHandle hHal,
				  struct sme_oem_capability *cap);
#endif /*FEATURE_OEM_DATA_SUPPORT */
QDF_STATUS sme_roam_update_apwpsie(tHalHandle, uint8_t sessionId,
		tSirAPWPSIEs * pAPWPSIES);
QDF_STATUS sme_roam_update_apwparsni_es(tHalHandle hHal, uint8_t sessionId,
		tSirRSNie *pAPSirRSNie);
QDF_STATUS sme_change_mcc_beacon_interval(tHalHandle hHal, uint8_t sessionId);
QDF_STATUS sme_set_host_offload(tHalHandle hHal, uint8_t sessionId,
		tpSirHostOffloadReq pRequest);

/**
 * sme_conf_hw_filter_mode() - configure the given mode for the given session
 * @hal: internal hal handle
 * @session_id: the Id of the session to configure the hw filter for
 * @mode_bitmap: the hw filter mode to configure
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_conf_hw_filter_mode(tHalHandle hal, uint8_t session_id,
				   uint8_t mode_bitmap, bool filter_enable);

QDF_STATUS sme_set_keep_alive(tHalHandle hHal, uint8_t sessionId,
		tpSirKeepAliveReq pRequest);
QDF_STATUS sme_get_operation_channel(tHalHandle hHal, uint32_t *pChannel,
		uint8_t sessionId);
QDF_STATUS sme_register_mgmt_frame(tHalHandle hHal, uint8_t sessionId,
		uint16_t frameType, uint8_t *matchData,
		uint16_t matchLen);
QDF_STATUS sme_deregister_mgmt_frame(tHalHandle hHal, uint8_t sessionId,
		uint16_t frameType, uint8_t *matchData,
		uint16_t matchLen);
QDF_STATUS sme_ConfigureAppsCpuWakeupState(tHalHandle hHal, bool isAppsAwake);
QDF_STATUS sme_configure_suspend_ind(tHalHandle hHal,
		uint32_t conn_state_mask,
		csr_readyToSuspendCallback,
		void *callbackContext);
QDF_STATUS sme_configure_resume_req(tHalHandle hHal,
		tpSirWlanResumeParam wlanResumeParam);
#ifdef WLAN_FEATURE_EXTWOW_SUPPORT
QDF_STATUS sme_configure_ext_wow(tHalHandle hHal,
		tpSirExtWoWParams wlanExtParams,
		csr_readyToSuspendCallback callback,
		void *callbackContext);
QDF_STATUS sme_configure_app_type1_params(tHalHandle hHal,
		tpSirAppType1Params wlanAppType1Params);
QDF_STATUS sme_configure_app_type2_params(tHalHandle hHal,
		tpSirAppType2Params wlanAppType2Params);
#endif
int8_t sme_get_infra_session_id(tHalHandle hHal);
uint8_t sme_get_infra_operation_channel(tHalHandle hHal, uint8_t sessionId);
uint8_t sme_get_concurrent_operation_channel(tHalHandle hHal);
/**
 * sme_get_beaconing_concurrent_operation_channel() - To get concurrent
 * operating channel of beaconing interface
=======
QDF_STATUS sme_get_country_code(mac_handle_t mac_handle, uint8_t *pBuf,
				uint8_t *pbLen);

QDF_STATUS sme_generic_change_country_code(mac_handle_t mac_handle,
					   uint8_t *pCountry);


/**
 * sme_update_channel_list() - Update configured channel list to fwr
 * This is a synchronous API.
 * @mac_handle: Opaque handle to the global MAC context.
 *
 * Return: QDF_STATUS  SUCCESS.
 * FAILURE or RESOURCES  The API finished and failed.
 */
QDF_STATUS sme_update_channel_list(mac_handle_t mac_handle);

QDF_STATUS sme_tx_fail_monitor_start_stop_ind(mac_handle_t mac_handle,
		uint8_t tx_fail_count,
		void *txFailIndCallback);
QDF_STATUS sme_dhcp_start_ind(mac_handle_t mac_handle,
		uint8_t device_mode,
		uint8_t *macAddr, uint8_t sessionId);
QDF_STATUS sme_dhcp_stop_ind(mac_handle_t mac_handle,
		uint8_t device_mode,
		uint8_t *macAddr, uint8_t sessionId);
QDF_STATUS sme_neighbor_report_request(mac_handle_t mac_handle,
		 uint8_t sessionId,
		tpRrmNeighborReq pRrmNeighborReq,
		tpRrmNeighborRspCallbackInfo callbackInfo);

#ifdef FEATURE_OEM_DATA
/**
 * sme_oem_data_cmd() - the wrapper to send oem data cmd to wma
 * @mac_handle: Opaque handle to the global MAC context.
 * @@oem_data_event_handler_cb: callback to be registered
 * @oem_data: the pointer of oem data
 * @vdev id: vdev id to fetch adapter
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_oem_data_cmd(mac_handle_t mac_handle,
			    void (*oem_data_event_handler_cb)
			    (const struct oem_data *oem_event_data,
			     uint8_t vdev_id),
			     struct oem_data *oem_data,
			     uint8_t vdev_id);
#endif

#ifdef FEATURE_OEM_DATA_SUPPORT
/**
 * sme_oem_req_cmd() - send oem request cmd to WMA
 * @mac_handle: Opaque handle to the global MAC context
 * @oem_req: OEM data request
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_oem_req_cmd(mac_handle_t mac_handle,
			   struct oem_data_req *oem_req);
QDF_STATUS sme_oem_update_capability(mac_handle_t mac_handle,
				     struct sme_oem_capability *cap);
QDF_STATUS sme_oem_get_capability(mac_handle_t mac_handle,
				  struct sme_oem_capability *cap);
#endif /*FEATURE_OEM_DATA_SUPPORT */
QDF_STATUS sme_change_mcc_beacon_interval(uint8_t sessionId);
QDF_STATUS sme_set_host_offload(mac_handle_t mac_handle, uint8_t sessionId,
		struct sir_host_offload_req *pRequest);
QDF_STATUS sme_set_keep_alive(mac_handle_t mac_handle, uint8_t sessionId,
		struct keep_alive_req *pRequest);
QDF_STATUS sme_get_operation_channel(mac_handle_t mac_handle,
				     uint32_t *chan_freq,
				     uint8_t sessionId);
QDF_STATUS sme_register_mgmt_frame(mac_handle_t mac_handle, uint8_t sessionId,
		uint16_t frameType, uint8_t *matchData,
		uint16_t matchLen);
QDF_STATUS sme_deregister_mgmt_frame(mac_handle_t mac_handle,
				     uint8_t sessionId,
				     uint16_t frameType, uint8_t *matchData,
				     uint16_t matchLen);
#ifdef WLAN_FEATURE_EXTWOW_SUPPORT
QDF_STATUS sme_configure_ext_wow(mac_handle_t mac_handle,
		tpSirExtWoWParams wlanExtParams,
		csr_readyToSuspendCallback callback,
		void *callbackContext);
QDF_STATUS sme_configure_app_type1_params(mac_handle_t mac_handle,
		tpSirAppType1Params wlanAppType1Params);
QDF_STATUS sme_configure_app_type2_params(mac_handle_t mac_handle,
		tpSirAppType2Params wlanAppType2Params);
#endif
/**
 * sme_get_beaconing_concurrent_operation_channel() - To get concurrent
 * operating channel frequency of beaconing interface
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @mac_handle: Pointer to mac context
 * @vdev_id_to_skip: channel of which vdev id to skip
 *
 * This routine will return operating channel of active AP/GO channel
 * and will skip the channel of vdev_id_to_skip.
 * If other no reqested mode is active it will return 0
 *
<<<<<<< HEAD
 * Return: uint8_t
 */
uint8_t sme_get_beaconing_concurrent_operation_channel(tHalHandle hal,
						       uint8_t vdev_id_to_skip);
#ifdef FEATURE_WLAN_MCC_TO_SCC_SWITCH
uint16_t sme_check_concurrent_channel_overlap(tHalHandle hHal, uint16_t sap_ch,
		eCsrPhyMode sapPhyMode,
		uint8_t cc_switch_mode);
#endif
/**
 * sme_abort_mac_scan() - API to cancel MAC scan
 * @hHal: The handle returned by mac_open
 * @sessionId: sessionId on which we need to abort scan
 * @scan_id: scan id on which we need to abort scan
 * @reason: Reason to abort the scan
 *
 * This function aborts MAC scan.
 *
 * Return: QDF_STATUS_E_FAILURE for failure, QDF_STATUS_SUCCESS for
 * success
 */
QDF_STATUS sme_abort_mac_scan(tHalHandle hHal, uint8_t sessionId,
		uint32_t scan_id, eCsrAbortReason reason);
QDF_STATUS sme_get_cfg_valid_channels(tHalHandle hHal, uint8_t *aValidChannels,
		uint32_t *len);
#ifdef FEATURE_WLAN_SCAN_PNO
QDF_STATUS sme_set_preferred_network_list(tHalHandle hHal,
		tpSirPNOScanReq pRequest,
		uint8_t sessionId,
		preferred_network_found_ind_cb
		callbackRoutine, void *callbackContext);

QDF_STATUS sme_preferred_network_found_ind(tHalHandle hHal, void *pMsg);
#endif /* FEATURE_WLAN_SCAN_PNO */
#ifdef WLAN_FEATURE_PACKET_FILTERING
QDF_STATUS sme_8023_multicast_list(tHalHandle hHal, uint8_t sessionId,
		tpSirRcvFltMcAddrList pMulticastAddrs);
QDF_STATUS sme_receive_filter_set_filter(tHalHandle hHal,
		tpSirRcvPktFilterCfgType pRcvPktFilterCfg,
		uint8_t sessionId);
QDF_STATUS sme_receive_filter_clear_filter(tHalHandle hHal,
		tpSirRcvFltPktClearParam pRcvFltPktClearParam,
		uint8_t sessionId);
#endif /* WLAN_FEATURE_PACKET_FILTERING */
bool sme_is_channel_valid(tHalHandle hHal, uint8_t channel);
QDF_STATUS sme_set_freq_band(tHalHandle hHal, uint8_t sessionId,
		tSirRFBand eBand);
QDF_STATUS sme_get_freq_band(tHalHandle hHal, tSirRFBand *pBand);
#ifdef WLAN_FEATURE_GTK_OFFLOAD
QDF_STATUS sme_set_gtk_offload(tHalHandle hal_ctx,
		tpSirGtkOffloadParams request,
		uint8_t session_id);
QDF_STATUS sme_get_gtk_offload(tHalHandle hal_ctx,
		gtk_offload_get_info_callback callback_routine,
		void *callback_context, uint8_t session_id);
#endif /* WLAN_FEATURE_GTK_OFFLOAD */
uint16_t sme_chn_to_freq(uint8_t chanNum);
bool sme_is_channel_valid(tHalHandle hHal, uint8_t channel);
QDF_STATUS sme_set_max_tx_power(tHalHandle hHal, struct qdf_mac_addr pBssid,
		struct qdf_mac_addr pSelfMacAddress, int8_t dB);
QDF_STATUS sme_set_max_tx_power_per_band(tSirRFBand band, int8_t db);
QDF_STATUS sme_set_tx_power(tHalHandle hHal, uint8_t sessionId,
		struct qdf_mac_addr bssid,
		enum tQDF_ADAPTER_MODE dev_mode, int power);
QDF_STATUS sme_set_custom_mac_addr(tSirMacAddr customMacAddr);
QDF_STATUS sme_hide_ssid(tHalHandle hHal, uint8_t sessionId,
		uint8_t ssidHidden);
QDF_STATUS sme_set_tm_level(tHalHandle hHal, uint16_t newTMLevel,
		uint16_t tmMode);
void sme_feature_caps_exchange(tHalHandle hHal);
void sme_disable_feature_capablity(uint8_t feature_index);
void sme_reset_power_values_for5_g(tHalHandle hHal);
QDF_STATUS sme_update_roam_prefer5_g_hz(tHalHandle hHal, bool nRoamPrefer5GHz);
QDF_STATUS sme_set_roam_intra_band(tHalHandle hHal, const bool nRoamIntraBand);
QDF_STATUS sme_update_roam_scan_n_probes(tHalHandle hHal, uint8_t sessionId,
		const uint8_t nProbes);
QDF_STATUS sme_update_roam_scan_home_away_time(tHalHandle hHal,
		uint8_t sessionId,
		const uint16_t nRoamScanHomeAwayTime,
		const bool bSendOffloadCmd);

bool sme_get_roam_intra_band(tHalHandle hHal);
uint8_t sme_get_roam_scan_n_probes(tHalHandle hHal);
uint16_t sme_get_roam_scan_home_away_time(tHalHandle hHal);
QDF_STATUS sme_update_roam_rssi_diff(tHalHandle hHal, uint8_t sessionId,
		uint8_t RoamRssiDiff);
QDF_STATUS sme_update_fast_transition_enabled(tHalHandle hHal,
		bool isFastTransitionEnabled);
QDF_STATUS sme_update_wes_mode(tHalHandle hHal, bool isWESModeEnabled,
		uint8_t sessionId);
QDF_STATUS sme_set_roam_scan_control(tHalHandle hHal, uint8_t sessionId,
		bool roamScanControl);

QDF_STATUS sme_update_is_fast_roam_ini_feature_enabled(tHalHandle hHal,
		uint8_t sessionId,
		const bool
		isFastRoamIniFeatureEnabled);

QDF_STATUS sme_config_fast_roaming(tHalHandle hal, uint8_t session_id,
		const bool is_fast_roam_enabled);

QDF_STATUS sme_update_is_mawc_ini_feature_enabled(tHalHandle hHal,
		const bool MAWCEnabled);
QDF_STATUS sme_stop_roaming(tHalHandle hHal, uint8_t sessionId, uint8_t reason);

/**
 * sme_indicate_disconnect_inprogress() - Indicate to csr that disconnect is in
 * progress
 * @hal: The handle returned by mac_open
 * @session_id: sessionId on which disconenct has started
 *
 * Return: void
 */
void sme_indicate_disconnect_inprogress(tHalHandle hal, uint8_t session_id);
QDF_STATUS sme_start_roaming(tHalHandle hHal, uint8_t sessionId,
		uint8_t reason);
QDF_STATUS sme_update_enable_fast_roam_in_concurrency(tHalHandle hHal,
		bool bFastRoamInConIniFeatureEnabled);
#ifdef FEATURE_WLAN_ESE
QDF_STATUS sme_update_is_ese_feature_enabled(tHalHandle hHal, uint8_t sessionId,
		const bool isEseIniFeatureEnabled);
#endif /* FEATURE_WLAN_ESE */
QDF_STATUS sme_update_config_fw_rssi_monitoring(tHalHandle hHal,
		bool fEnableFwRssiMonitoring);
QDF_STATUS sme_set_roam_rescan_rssi_diff(tHalHandle hHal,
		uint8_t sessionId,
		const uint8_t nRoamRescanRssiDiff);
uint8_t sme_get_roam_rescan_rssi_diff(tHalHandle hHal);

QDF_STATUS sme_set_roam_opportunistic_scan_threshold_diff(tHalHandle hHal,
		uint8_t sessionId,
		const uint8_t nOpportunisticThresholdDiff);
uint8_t sme_get_roam_opportunistic_scan_threshold_diff(tHalHandle hHal);
QDF_STATUS sme_set_neighbor_lookup_rssi_threshold(tHalHandle hHal,
		uint8_t sessionId, uint8_t neighborLookupRssiThreshold);
QDF_STATUS sme_set_delay_before_vdev_stop(tHalHandle hHal,
		uint8_t sessionId, uint8_t delay_before_vdev_stop);
uint8_t sme_get_neighbor_lookup_rssi_threshold(tHalHandle hHal);
QDF_STATUS sme_set_neighbor_scan_refresh_period(tHalHandle hHal,
		uint8_t sessionId, uint16_t neighborScanResultsRefreshPeriod);
uint16_t sme_get_neighbor_scan_refresh_period(tHalHandle hHal);
uint16_t sme_get_empty_scan_refresh_period(tHalHandle hHal);
QDF_STATUS sme_update_empty_scan_refresh_period(tHalHandle hHal,
		uint8_t sessionId, uint16_t nEmptyScanRefreshPeriod);
QDF_STATUS sme_set_neighbor_scan_min_chan_time(tHalHandle hHal,
		const uint16_t nNeighborScanMinChanTime,
		uint8_t sessionId);
QDF_STATUS sme_set_neighbor_scan_max_chan_time(tHalHandle hHal,
		uint8_t sessionId, const uint16_t nNeighborScanMaxChanTime);
uint16_t sme_get_neighbor_scan_min_chan_time(tHalHandle hHal,
		uint8_t sessionId);
uint32_t sme_get_neighbor_roam_state(tHalHandle hHal, uint8_t sessionId);
uint32_t sme_get_current_roam_state(tHalHandle hHal, uint8_t sessionId);
uint32_t sme_get_current_roam_sub_state(tHalHandle hHal, uint8_t sessionId);
uint32_t sme_get_lim_sme_state(tHalHandle hHal);
uint32_t sme_get_lim_mlm_state(tHalHandle hHal);
bool sme_is_lim_session_valid(tHalHandle hHal, uint8_t sessionId);
uint32_t sme_get_lim_sme_session_state(tHalHandle hHal, uint8_t sessionId);
uint32_t sme_get_lim_mlm_session_state(tHalHandle hHal, uint8_t sessionId);
uint16_t sme_get_neighbor_scan_max_chan_time(tHalHandle hHal,
		uint8_t sessionId);
QDF_STATUS sme_set_neighbor_scan_period(tHalHandle hHal, uint8_t sessionId,
		const uint16_t nNeighborScanPeriod);
uint16_t sme_get_neighbor_scan_period(tHalHandle hHal, uint8_t sessionId);
QDF_STATUS sme_set_neighbor_scan_min_period(tHalHandle h_hal,
		uint8_t session_id, const uint16_t neighbor_scan_min_period);
QDF_STATUS sme_set_roam_bmiss_first_bcnt(tHalHandle hHal,
		uint8_t sessionId, const uint8_t nRoamBmissFirstBcnt);
uint8_t sme_get_roam_bmiss_first_bcnt(tHalHandle hHal);
QDF_STATUS sme_set_roam_bmiss_final_bcnt(tHalHandle hHal, uint8_t sessionId,
		const uint8_t nRoamBmissFinalBcnt);
uint8_t sme_get_roam_bmiss_final_bcnt(tHalHandle hHal);
QDF_STATUS sme_set_roam_beacon_rssi_weight(tHalHandle hHal, uint8_t sessionId,
		const uint8_t nRoamBeaconRssiWeight);
uint8_t sme_get_roam_beacon_rssi_weight(tHalHandle hHal);
uint8_t sme_get_roam_rssi_diff(tHalHandle hHal);
QDF_STATUS sme_change_roam_scan_channel_list(tHalHandle hHal, uint8_t sessionId,
		uint8_t *pChannelList,
		uint8_t numChannels);
QDF_STATUS sme_set_ese_roam_scan_channel_list(tHalHandle hHal,
		uint8_t sessionId, uint8_t *pChannelList,
		uint8_t numChannels);
QDF_STATUS sme_get_roam_scan_channel_list(tHalHandle hHal,
		uint8_t *pChannelList, uint8_t *pNumChannels,
		uint8_t sessionId);
bool sme_get_is_ese_feature_enabled(tHalHandle hHal);
bool sme_get_wes_mode(tHalHandle hHal);
bool sme_get_roam_scan_control(tHalHandle hHal);
bool sme_get_is_lfr_feature_enabled(tHalHandle hHal);
bool sme_get_is_ft_feature_enabled(tHalHandle hHal);
QDF_STATUS sme_update_roam_scan_offload_enabled(tHalHandle hHal,
		bool nRoamScanOffloadEnabled);
uint8_t sme_is_feature_supported_by_fw(uint8_t featEnumValue);
#ifdef FEATURE_WLAN_TDLS
QDF_STATUS sme_send_tdls_link_establish_params(tHalHandle hHal,
		uint8_t sessionId,
		const tSirMacAddr peerMac,
		tCsrTdlsLinkEstablishParams *
		tdlsLinkEstablishParams);
QDF_STATUS sme_send_tdls_mgmt_frame(tHalHandle hHal, uint8_t sessionId,
		const tSirMacAddr peerMac, uint8_t frame_type,
		uint8_t dialog, uint16_t status,
		uint32_t peerCapability, uint8_t *buf,
		uint8_t len, uint8_t responder, enum sir_wifi_traffic_ac ac);
QDF_STATUS sme_change_tdls_peer_sta(tHalHandle hHal, uint8_t sessionId,
		const tSirMacAddr peerMac,
		tCsrStaParams *pstaParams);
QDF_STATUS sme_add_tdls_peer_sta(tHalHandle hHal, uint8_t sessionId,
		const tSirMacAddr peerMac);
QDF_STATUS sme_delete_tdls_peer_sta(tHalHandle hHal, uint8_t sessionId,
		const tSirMacAddr peerMac);
void sme_set_tdls_power_save_prohibited(tHalHandle hHal, uint32_t sessionId,
		bool val);
QDF_STATUS sme_send_tdls_chan_switch_req(
		tHalHandle hal,
		sme_tdls_chan_switch_params *ch_switch_params);
#endif

/*
 * SME API to enable/disable WLAN driver initiated SSR
 */
void sme_update_enable_ssr(tHalHandle hHal, bool enableSSR);
QDF_STATUS sme_set_phy_mode(tHalHandle hHal, eCsrPhyMode phyMode);
eCsrPhyMode sme_get_phy_mode(tHalHandle hHal);
QDF_STATUS sme_handoff_request(tHalHandle hHal, uint8_t sessionId,
			       tCsrHandoffRequest *pHandoffInfo);
QDF_STATUS sme_is_sta_p2p_client_connected(tHalHandle hHal);
#ifdef FEATURE_WLAN_LPHB
QDF_STATUS sme_lphb_config_req(tHalHandle hHal,
		tSirLPHBReq * lphdReq,
		void (*pCallbackfn)(void *pHddCtx,
			tSirLPHBInd * indParam));
#endif /* FEATURE_WLAN_LPHB */
QDF_STATUS sme_add_periodic_tx_ptrn(tHalHandle hHal, tSirAddPeriodicTxPtrn
		*addPeriodicTxPtrnParams);
QDF_STATUS sme_del_periodic_tx_ptrn(tHalHandle hHal, tSirDelPeriodicTxPtrn
		*delPeriodicTxPtrnParams);
QDF_STATUS sme_send_rate_update_ind(tHalHandle hHal,
		tSirRateUpdateInd *rateUpdateParams);
QDF_STATUS sme_roam_del_pmkid_from_cache(tHalHandle hHal, uint8_t sessionId,
		tPmkidCacheInfo *pmksa, bool flush_cache);
void sme_get_command_q_status(tHalHandle hHal);

QDF_STATUS sme_enable_rmc(tHalHandle hHal, uint32_t sessionId);
QDF_STATUS sme_disable_rmc(tHalHandle hHal, uint32_t sessionId);
QDF_STATUS sme_send_rmc_action_period(tHalHandle hHal, uint32_t sessionId);
QDF_STATUS sme_request_ibss_peer_info(tHalHandle hHal, void *pUserData,
	pIbssPeerInfoCb peerInfoCbk, bool allPeerInfoReqd, uint8_t staIdx);
QDF_STATUS sme_send_cesium_enable_ind(tHalHandle hHal, uint32_t sessionId);

/**
 * sme_set_wlm_latency_level_ind() - Used to set the latency level to fw
 * @hal
=======
 * Return: uint32_t
 */
uint32_t sme_get_beaconing_concurrent_operation_channel(mac_handle_t mac_handle,
						       uint8_t vdev_id_to_skip);
#ifdef FEATURE_WLAN_MCC_TO_SCC_SWITCH
/**
 * sme_check_concurrent_channel_overlap() - Get interfering concurrent channel
 * @mac_handle: SAP context pointer
 * @sap_ch_freq: SAP home channel frequency
 * @sapPhyMode: sap phymode
 * @cc_switch_mode: force scc channel switch mode
 *
 * Determine if a concurrent channel is interfering.
 *
 * Return: Channel freq (Mhz) of the interfering channel, or 0 if none.
 */
uint16_t sme_check_concurrent_channel_overlap(mac_handle_t mac_handle,
					      uint16_t sap_ch_freq,
					      eCsrPhyMode sapPhyMode,
					      uint8_t cc_switch_mode);
#endif

/**
 * sme_get_cfg_valid_channels() - To get valid channel list
 * @valid_ch_freq: pointer to array which save the valid channel list
 * @len: the length of the valid channel list
 *
 * Return: QDF status
 */
QDF_STATUS sme_get_cfg_valid_channels(uint32_t *valid_ch_freq, uint32_t *len);

#ifdef WLAN_FEATURE_PACKET_FILTERING
QDF_STATUS sme_8023_multicast_list(mac_handle_t mac_handle, uint8_t sessionId,
		tpSirRcvFltMcAddrList pMulticastAddrs);
#endif /* WLAN_FEATURE_PACKET_FILTERING */
uint16_t sme_chn_to_freq(uint8_t chanNum);

/*
 * sme_is_channel_valid() - validate a channel against current regdmn
 * To check if the channel is valid for currently established domain
 *   This is a synchronous API.
 *
 * mac_handle - The handle returned by mac_open.
 * chan_freq - channel to verify
 *
 * Return: true/false, true if channel is valid
 */
bool sme_is_channel_valid(mac_handle_t mac_handle, uint32_t chan_freq);

QDF_STATUS sme_set_max_tx_power(mac_handle_t mac_handle,
				struct qdf_mac_addr pBssid,
				struct qdf_mac_addr pSelfMacAddress, int8_t dB);
QDF_STATUS sme_set_max_tx_power_per_band(enum band_info band, int8_t db);
QDF_STATUS sme_set_tx_power(mac_handle_t mac_handle, uint8_t sessionId,
		struct qdf_mac_addr bssid,
		enum QDF_OPMODE dev_mode, int power);
QDF_STATUS sme_set_custom_mac_addr(tSirMacAddr customMacAddr);
QDF_STATUS sme_hide_ssid(mac_handle_t mac_handle, uint8_t sessionId,
		uint8_t ssidHidden);

/**
 * sme_update_roam_scan_n_probes() - Update no.of roam scan probes
 * @mac_handle: The handle returned by mac_open
 * @vdev_id: vdev identifier
 * @probes: number of probe requests to be sent out
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_update_roam_scan_n_probes(mac_handle_t mac_handle,
					 uint8_t vdev_id,
					 const uint8_t probes);

/**
 * sme_update_roam_scan_home_away_time() - Update roam scan Home away time
 * @mac_handle: Opaque handle to the global MAC context
 * @vdev_id: vdev identifier
 * @roam_scan_home_away_time: Scan home away time
 * @send_offload_cmd: If it's true, the command is sent to firmware,
 *		      otherwise the command is not sent to firmware
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
sme_update_roam_scan_home_away_time(mac_handle_t mac_handle, uint8_t vdev_id,
				    const uint16_t roam_scan_home_away_time,
				    const bool send_offload_cmd);

bool sme_get_roam_intra_band(mac_handle_t mac_handle);

/**
 * sme_get_roam_scan_n_probes() - get Roam scan number of probes
 * @mac_handle: The handle returned by mac_open
 * @vdev_id: vdev identifier
 * @roam_scan_n_probes: Buffer to fill the number of probes.
 *			Valid only if the return status is success.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_get_roam_scan_n_probes(mac_handle_t mac_handle, uint8_t vdev_id,
				      uint8_t *roam_scan_n_probes);

/**
 * sme_update_roam_rssi_diff() - Update RoamRssiDiff
 * @mac_handle: Opaque handle to the global MAC context
 * @vdev_id: vdev identifier
 * @roam_rssi_diff: Minimum rssi difference between potential candidate and
 *		    current AP.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_update_roam_rssi_diff(mac_handle_t mac_handle, uint8_t vdev_id,
				     uint8_t roam_rssi_diff);

/**
 * sme_get_roam_scan_home_away_time() - get Roam scan home away time
 * @mac_handle: The handle returned by mac_open
 * @vdev_id: vdev identifier
 * @roam_scan_home_away_time: Buffer to fill the roam scan home away time.
 *			      Valid only if the return status is success.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_get_roam_scan_home_away_time(mac_handle_t mac_handle,
					    uint8_t vdev_id,
					    uint16_t *roam_scan_home_away_time);
QDF_STATUS sme_update_wes_mode(mac_handle_t mac_handle, bool isWESModeEnabled,
		uint8_t sessionId);
QDF_STATUS sme_set_roam_scan_control(mac_handle_t mac_handle, uint8_t sessionId,
		bool roamScanControl);

QDF_STATUS sme_update_is_fast_roam_ini_feature_enabled(mac_handle_t mac_handle,
		uint8_t sessionId,
		const bool
		isFastRoamIniFeatureEnabled);

QDF_STATUS sme_config_fast_roaming(mac_handle_t mac_handle, uint8_t session_id,
				   const bool is_fast_roam_enabled);

QDF_STATUS sme_stop_roaming(mac_handle_t mac_handle, uint8_t sessionId,
			    uint8_t reason, uint32_t requestor);

QDF_STATUS sme_start_roaming(mac_handle_t mac_handle, uint8_t sessionId,
			     uint8_t reason, uint32_t requestor);
#ifdef FEATURE_WLAN_ESE
QDF_STATUS sme_update_is_ese_feature_enabled(mac_handle_t mac_handle,
					     uint8_t sessionId,
					     const bool isEseIniFeatureEnabled);
#endif /* FEATURE_WLAN_ESE */
QDF_STATUS sme_set_roam_rescan_rssi_diff(mac_handle_t mac_handle,
		uint8_t sessionId,
		const uint8_t nRoamRescanRssiDiff);
uint8_t sme_get_roam_rescan_rssi_diff(mac_handle_t mac_handle);

QDF_STATUS sme_set_roam_opportunistic_scan_threshold_diff(
		mac_handle_t mac_handle,
		uint8_t sessionId,
		const uint8_t nOpportunisticThresholdDiff);
uint8_t sme_get_roam_opportunistic_scan_threshold_diff(mac_handle_t mac_handle);

/**
 * sme_set_neighbor_lookup_rssi_threshold() - update neighbor lookup rssi thr
 * @mac_handle: The handle returned by mac_open
 * @vdev_id: vdev identifier
 * @neighbor_lookup_rssi_threshold: Neighbor lookup rssi threshold
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
sme_set_neighbor_lookup_rssi_threshold(mac_handle_t mac_handle,
				       uint8_t vdev_id,
				       uint8_t neighbor_lookup_rssi_threshold);

/**
 * sme_get_neighbor_lookup_rssi_threshold() - get neighbor lookup rssi threshold
 * @mac_handle: The handle returned by mac_open
 * @vdev_id: vdev identifier
 * @lookup_threshold: Buffer to fill the neighbor lookup threshold.
 *		      Valid only if the return status is success.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_get_neighbor_lookup_rssi_threshold(mac_handle_t mac_handle,
						  uint8_t vdev_id,
						  uint8_t *lookup_threshold);
QDF_STATUS sme_set_neighbor_scan_refresh_period(mac_handle_t mac_handle,
		uint8_t sessionId, uint16_t neighborScanResultsRefreshPeriod);
uint16_t sme_get_neighbor_scan_refresh_period(mac_handle_t mac_handle);

/**
 * sme_get_empty_scan_refresh_period_global() - get global scan refresh period
 * @mac_handle: The handle returned by mac_open
 *
 * Return: Empty scan refresh period configured through ini
 */
uint16_t sme_get_empty_scan_refresh_period_global(mac_handle_t mac_handle);

/**
 * sme_get_empty_scan_refresh_period() - get empty scan refresh period
 * @mac_handle: The handle returned by mac_open.
 * @vdev_id: vdev identifier
 * @refresh_threshold: Buffer to fill the empty scan refresh period.
 *		       Valid only if the return status is success.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_get_empty_scan_refresh_period(mac_handle_t mac_handle,
					     uint8_t vdev_id,
					     uint16_t *refresh_threshold);
QDF_STATUS sme_update_empty_scan_refresh_period(mac_handle_t mac_handle,
		uint8_t sessionId, uint16_t empty_scan_refresh_period);
/**
 * sme_update_full_roam_scan_period() - Send full roam scan period to SME
 * @mac_handle: Opaque handle to the MAC context
 * @vdev_id: vdev id
 * @full_roam_scan_period: Idle period in seconds between two successive
 * full channel roam scans
 *
 * Updated full scan period in roam info and a roam_offload_scan request.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_update_full_roam_scan_period(mac_handle_t mac_handle,
					    uint8_t vdev_id,
					    uint32_t full_roam_scan_period);

/**
 * sme_modify_roam_cand_sel_criteria() - Modify candidate selection criteria
 * @mac_handle: Opaque handle to the global MAC context
 * @vdev_id: vdev Identifier
 * @enable_scoring_for_roam: Carries enable/disable indication
 *
 * Enable/disable scoring for roam candidate selection based on the value of
 * enable_scoring_for_roam. Below is the description of enable/disable,
 * Disable-0: Disable scoring for roam candidate selection. Roaming
 *	      shall fallback to legacy selection criteria, only RSSI.
 * Enable-1 : Enable scoring for roam candidate selection.
 *
 * Return: Success or failure
 */
QDF_STATUS
sme_modify_roam_cand_sel_criteria(mac_handle_t mac_handle,
				  uint8_t vdev_id,
				  bool enable_scoring_for_roam);

/**
 * sme_roam_control_restore_default_config - Restore roam config to default
 * @mac_handle: Opaque handle to the global MAC context
 * @vdev_id: vdev Identifier
 *
 * Restore enable_scoring_for_roam, emptyScanRefreshPeriod,
 * full_roam_scan_period to their default values and send RSO command to
 * firmware with the updated values.
 *
 * Return: Success or failure
 */
QDF_STATUS sme_roam_control_restore_default_config(mac_handle_t mac_handle,
						   uint8_t vdev_id);

/**
 * sme_roam_reset_configs() - API to reset roam config
 * @mac_handle: Opaque handle to the global MAC context
 * @vdev_id: vdev Identifier
 *
 * Return: void
 */
void sme_roam_reset_configs(mac_handle_t mac_handle, uint8_t vdev_id);

QDF_STATUS sme_set_neighbor_scan_min_chan_time(mac_handle_t mac_handle,
		const uint16_t nNeighborScanMinChanTime,
		uint8_t sessionId);
QDF_STATUS sme_set_neighbor_scan_max_chan_time(mac_handle_t mac_handle,
				uint8_t sessionId,
				const uint16_t nNeighborScanMaxChanTime);
uint16_t sme_get_neighbor_scan_min_chan_time(mac_handle_t mac_handle,
					     uint8_t sessionId);
uint32_t sme_get_neighbor_roam_state(mac_handle_t mac_handle,
				     uint8_t sessionId);
uint32_t sme_get_current_roam_state(mac_handle_t mac_handle, uint8_t sessionId);
uint32_t sme_get_current_roam_sub_state(mac_handle_t mac_handle,
					uint8_t sessionId);
uint32_t sme_get_lim_sme_state(mac_handle_t mac_handle);
uint32_t sme_get_lim_mlm_state(mac_handle_t mac_handle);
bool sme_is_lim_session_valid(mac_handle_t mac_handle, uint8_t sessionId);
uint32_t sme_get_lim_sme_session_state(mac_handle_t mac_handle,
				       uint8_t sessionId);
uint32_t sme_get_lim_mlm_session_state(mac_handle_t mac_handle,
				       uint8_t sessionId);
uint16_t sme_get_neighbor_scan_max_chan_time(mac_handle_t mac_handle,
					     uint8_t sessionId);
QDF_STATUS sme_set_neighbor_scan_period(mac_handle_t mac_handle,
		uint8_t sessionId,
		const uint16_t nNeighborScanPeriod);
uint16_t sme_get_neighbor_scan_period(mac_handle_t mac_handle,
				      uint8_t sessionId);
QDF_STATUS sme_set_roam_bmiss_first_bcnt(mac_handle_t mac_handle,
		uint8_t sessionId, const uint8_t nRoamBmissFirstBcnt);
QDF_STATUS sme_set_roam_bmiss_final_bcnt(mac_handle_t mac_handle,
					 uint8_t sessionId,
					 const uint8_t nRoamBmissFinalBcnt);
/**
 * sme_get_roam_rssi_diff() - get Roam rssi diff
 * @mac_handle: The handle returned by mac_open
 * @vdev_id: vdev identifier
 * @rssi_diff: Buffer to fill the roam RSSI diff.
 *	       Valid only if the return status is success.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_get_roam_rssi_diff(mac_handle_t mac_handle, uint8_t vdev_id,
				  uint8_t *rssi_diff);
QDF_STATUS sme_change_roam_scan_channel_list(mac_handle_t mac_handle,
					     uint8_t sessionId,
					     uint32_t *channel_freq_list,
					     uint8_t numChannels);

/**
 * sme_update_roam_scan_freq_list() - Update roam scan freq list
 * @mac_handle: Opaque handle to the global MAC context
 * @vdev_id: vdev identifier
 * @freq_list: List of frequencies to be configured
 * @num_channels: Number of frequencies to be configured
 * @freq_list_type: Type of frequency list to be configured to
 *
 * Update the frequencies from freq_list to the corresponding channel list
 * in neighborRoamInfo
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
sme_update_roam_scan_freq_list(mac_handle_t mac_handle, uint8_t vdev_id,
			       uint32_t *freq_list, uint8_t num_chan,
			       uint32_t freq_list_type);
QDF_STATUS sme_set_ese_roam_scan_channel_list(mac_handle_t mac_handle,
					      uint8_t sessionId,
					      uint32_t *chan_freq_list,
					      uint8_t numChannels);
QDF_STATUS sme_get_roam_scan_channel_list(mac_handle_t mac_handle,
					  uint32_t *freq_list,
					  uint8_t *pNumChannels,
					  uint8_t sessionId);

/**
 * sme_dump_freq_list() - Dump the frequencies from given chan info
 * @chan_info: Contains the frequency list and number of frequencies
 *
 * Extract number of frequencies and frequency list from chan_info and print
 * to the logs.
 *
 * Return: None
 */
void sme_dump_freq_list(tCsrChannelInfo *chan_info);
bool sme_get_is_ese_feature_enabled(mac_handle_t mac_handle);
bool sme_get_wes_mode(mac_handle_t mac_handle);
bool sme_get_roam_scan_control(mac_handle_t mac_handle);
bool sme_get_is_lfr_feature_enabled(mac_handle_t mac_handle);
bool sme_get_is_ft_feature_enabled(mac_handle_t mac_handle);
bool sme_is_feature_supported_by_fw(enum cap_bitmap feature);

QDF_STATUS sme_set_phy_mode(mac_handle_t mac_handle, eCsrPhyMode phyMode);
eCsrPhyMode sme_get_phy_mode(mac_handle_t mac_handle);
QDF_STATUS sme_handoff_request(mac_handle_t mac_handle, uint8_t sessionId,
			       tCsrHandoffRequest *pHandoffInfo);

QDF_STATUS sme_add_periodic_tx_ptrn(mac_handle_t mac_handle,
		tSirAddPeriodicTxPtrn *addPeriodicTxPtrnParams);
QDF_STATUS sme_del_periodic_tx_ptrn(mac_handle_t mac_handle,
		tSirDelPeriodicTxPtrn *delPeriodicTxPtrnParams);
QDF_STATUS sme_send_rate_update_ind(mac_handle_t mac_handle,
		tSirRateUpdateInd *rateUpdateParams);
QDF_STATUS sme_roam_del_pmkid_from_cache(mac_handle_t mac_handle,
					 uint8_t vdev_id,
					 struct wlan_crypto_pmksa *pmksa,
					 bool set_pmk);

void sme_get_command_q_status(mac_handle_t mac_handle);

#ifdef FEATURE_WLAN_RMC
QDF_STATUS sme_enable_rmc(mac_handle_t mac_handle, uint32_t sessionId);
QDF_STATUS sme_disable_rmc(mac_handle_t mac_handle, uint32_t sessionId);
QDF_STATUS sme_send_rmc_action_period(mac_handle_t mac_handle,
				      uint32_t sessionId);
#endif

#ifdef QCA_IBSS_SUPPORT
/*
 * sme_request_ibss_peer_info() -  request ibss peer info
 * @mac_handle: Opaque handle to the global MAC context
 * @cb_context: Pointer to user data
 * @peer_info_cb: Peer info callback
 * @allPeerInfoReqd: All peer info required or not
 * @staIdx: sta index
 *
 * Return:  QDF_STATUS
 */
QDF_STATUS sme_request_ibss_peer_info(mac_handle_t mac_handle,
				      void *cb_context,
				      ibss_peer_info_cb peer_info_cb,
				      bool allPeerInfoReqd,
				      uint8_t *mac_addr);
#else
static inline
QDF_STATUS sme_request_ibss_peer_info(mac_handle_t mac_handle,
				      void *cb_context,
				      ibss_peer_info_cb peer_info_cb,
				      bool allPeerInfoReqd,
				      uint8_t *mac_addr)
{
	return QDF_STATUS_SUCCESS;
}
#endif

QDF_STATUS sme_send_cesium_enable_ind(mac_handle_t mac_handle,
				      uint32_t sessionId);

/**
 * sme_set_wlm_latency_level_ind() - Used to set the latency level to fw
 * @mac_handle
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @session_id
 * @latency_level
 *
 * Return QDF_STATUS
 */
<<<<<<< HEAD
QDF_STATUS sme_set_wlm_latency_level(tHalHandle hal,
=======
QDF_STATUS sme_set_wlm_latency_level(mac_handle_t mac_handle,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				     uint16_t session_id,
				     uint16_t latency_level);
/*
 * SME API to enable/disable idle mode powersave
 * This should be called only if powersave offload
 * is enabled
 */
QDF_STATUS sme_set_idle_powersave_config(bool value);
<<<<<<< HEAD
QDF_STATUS sme_notify_modem_power_state(tHalHandle hHal, uint32_t value);

/*SME API to convert convert the ini value to the ENUM used in csr and MAC*/
ePhyChanBondState sme_get_cb_phy_state_from_cb_ini_value(uint32_t cb_ini_value);
int sme_update_ht_config(tHalHandle hHal, uint8_t sessionId, uint16_t htCapab,
		int value);
int16_t sme_get_ht_config(tHalHandle hHal, uint8_t session_id,
		uint16_t ht_capab);
#ifdef QCA_HT_2040_COEX
QDF_STATUS sme_notify_ht2040_mode(tHalHandle hHal, uint16_t staId,
		struct qdf_mac_addr macAddrSTA,
		uint8_t sessionId,
		uint8_t channel_type);
QDF_STATUS sme_set_ht2040_mode(tHalHandle hHal, uint8_t sessionId,
		uint8_t channel_type, bool obssEnabled);
#endif
QDF_STATUS sme_get_reg_info(tHalHandle hHal, uint8_t chanId,
		uint32_t *regInfo1, uint32_t *regInfo2);
#ifdef FEATURE_WLAN_TDLS
QDF_STATUS sme_update_fw_tdls_state(tHalHandle hHal, void *psmeTdlsParams,
		bool useSmeLock);
QDF_STATUS sme_update_tdls_peer_state(tHalHandle hHal,
		tSmeTdlsPeerStateParams *pPeerStateParams);
#endif /* FEATURE_WLAN_TDLS */
#ifdef FEATURE_WLAN_CH_AVOID
QDF_STATUS sme_add_ch_avoid_callback(tHalHandle hHal,
	void (*pCallbackfn)(void *hdd_context, void *indi_param));
QDF_STATUS sme_ch_avoid_update_req(tHalHandle hHal);
#else
static inline
QDF_STATUS sme_add_ch_avoid_callback(tHalHandle hHal,
	void (*pCallbackfn)(void *hdd_context, void *indi_param))
{
	return QDF_STATUS_E_NOSUPPORT;
}

static inline
QDF_STATUS sme_ch_avoid_update_req(tHalHandle hHal)
{
	return QDF_STATUS_E_NOSUPPORT;
}
#endif /* FEATURE_WLAN_CH_AVOID */
#ifdef FEATURE_WLAN_AUTO_SHUTDOWN
QDF_STATUS sme_set_auto_shutdown_cb(tHalHandle hHal, void (*pCallbackfn)(void));
QDF_STATUS sme_set_auto_shutdown_timer(tHalHandle hHal, uint32_t timer_value);
#endif
QDF_STATUS sme_roam_channel_change_req(tHalHandle hHal,
				       struct qdf_mac_addr bssid,
				       struct ch_params_s *ch_params,
				       tCsrRoamProfile *profile);

QDF_STATUS sme_roam_start_beacon_req(tHalHandle hHal,
		struct qdf_mac_addr bssid, uint8_t dfsCacWaitStatus);
QDF_STATUS sme_roam_csa_ie_request(tHalHandle hHal, struct qdf_mac_addr bssid,
				   uint8_t targetChannel, uint8_t csaIeReqd,
				   struct ch_params_s *ch_params);

QDF_STATUS sme_init_thermal_info(tHalHandle hHal,
				 tSmeThermalParams thermalParam);

QDF_STATUS sme_set_thermal_level(tHalHandle hHal, uint8_t level);
QDF_STATUS sme_txpower_limit(tHalHandle hHal, tSirTxPowerLimit *psmetx);
QDF_STATUS sme_get_link_speed(tHalHandle hHal, tSirLinkSpeedInfo *lsReq,
		void *plsContext,
		void (*pCallbackfn)(tSirLinkSpeedInfo *indParam,
		void *pContext));
QDF_STATUS sme_modify_add_ie(tHalHandle hHal,
		tSirModifyIE *pModifyIE, eUpdateIEsType updateType);
QDF_STATUS sme_update_add_ie(tHalHandle hHal,
		tSirUpdateIE *pUpdateIE, eUpdateIEsType updateType);
QDF_STATUS sme_update_connect_debug(tHalHandle hHal, uint32_t set_value);
const char *sme_request_type_to_string(const uint8_t request_type);
const char *sme_scan_type_to_string(const uint8_t scan_type);
const char *sme_bss_type_to_string(const uint8_t bss_type);
QDF_STATUS sme_ap_disable_intra_bss_fwd(tHalHandle hHal, uint8_t sessionId,
		bool disablefwd);
QDF_STATUS sme_get_channel_bonding_mode5_g(tHalHandle hHal, uint32_t *mode);
QDF_STATUS sme_get_channel_bonding_mode24_g(tHalHandle hHal, uint32_t *mode);
#ifdef WLAN_FEATURE_STATS_EXT
=======
QDF_STATUS sme_notify_modem_power_state(mac_handle_t mac_handle,
					uint32_t value);

/*SME API to convert convert the ini value to the ENUM used in csr and MAC*/
ePhyChanBondState sme_get_cb_phy_state_from_cb_ini_value(uint32_t cb_ini_value);
int sme_update_ht_config(mac_handle_t mac_handle, uint8_t sessionId,
			 uint16_t htCapab,
			 int value);
int16_t sme_get_ht_config(mac_handle_t mac_handle, uint8_t session_id,
			  uint16_t ht_capab);
#ifdef QCA_HT_2040_COEX
QDF_STATUS sme_notify_ht2040_mode(mac_handle_t mac_handle,
				  struct qdf_mac_addr macAddrSTA,
				  uint8_t sessionId,
				  uint8_t channel_type);
QDF_STATUS sme_set_ht2040_mode(mac_handle_t mac_handle, uint8_t sessionId,
			       uint8_t channel_type, bool obssEnabled);
#endif

/**
 * sme_get_reg_info() - To get tx power information
 * @mac_handle: Opaque handle to the global MAC context
 * @chan_freq: channel freq
 * @regInfo1: first reg info to fill
 * @regInfo2: second reg info to fill
 *
 * This routine will give you tx power information
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_get_reg_info(mac_handle_t mac_handle, uint32_t chan_freq,
			    uint32_t *regInfo1, uint32_t *regInfo2);

#ifdef FEATURE_WLAN_CH_AVOID
QDF_STATUS sme_ch_avoid_update_req(mac_handle_t mac_handle);
#else
static inline
QDF_STATUS sme_ch_avoid_update_req(mac_handle_t mac_handle)
{
	return QDF_STATUS_SUCCESS;
}
#endif
#ifdef FEATURE_WLAN_AUTO_SHUTDOWN
/**
 * sme_set_auto_shutdown_cb() - Register auto shutdown evt handler
 * @mac_handle: Handle to the global MAC context
 * @callback_fn: callback function to be invoked when an auto shutdown
 *               event is received
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_set_auto_shutdown_cb(mac_handle_t mac_handle,
				    void (*callback_fn)(void));

QDF_STATUS sme_set_auto_shutdown_timer(mac_handle_t mac_handle,
				       uint32_t timer_value);
#endif
QDF_STATUS sme_roam_channel_change_req(mac_handle_t mac_handle,
				       struct qdf_mac_addr bssid,
				       struct ch_params *ch_params,
				       struct csr_roam_profile *profile);

QDF_STATUS sme_roam_start_beacon_req(mac_handle_t mac_handle,
				     struct qdf_mac_addr bssid,
				     uint8_t dfsCacWaitStatus);

/**
 * sme_roam_csa_ie_request() - request CSA IE transmission from PE
 * @mac_handle: handle returned by mac_open
 * @bssid: SAP bssid
 * @target_chan_freq: target channel frequency information
 * @csaIeReqd: CSA IE Request
 * @ch_params: channel information
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_csa_restart(struct mac_context *mac_ctx, uint8_t session_id);

QDF_STATUS sme_roam_csa_ie_request(mac_handle_t mac_handle,
				   struct qdf_mac_addr bssid,
				   uint32_t target_chan_freq, uint8_t csaIeReqd,
				   struct ch_params *ch_params);

/**
 * sme_set_addba_accept() - Allow/Reject the ADDBA req session
 * @mac_handle: handle returned by mac_open
 * @session_id: sme session id
 * @value: Allow/Reject AddBA session
 *
 * Allows/Rejects the ADDBA req session
 *
 * Return: 0 on success else errno
 */
int sme_set_addba_accept(mac_handle_t mac_handle, uint8_t session_id,
			 int value);

QDF_STATUS sme_init_thermal_info(mac_handle_t mac_handle);

QDF_STATUS sme_set_thermal_level(mac_handle_t mac_handle, uint8_t level);
QDF_STATUS sme_txpower_limit(mac_handle_t mac_handle,
			     struct tx_power_limit *psmetx);

/**
 * sme_get_link_speed() - Retrieve current link speed
 * @mac_handle: Global MAC handle
 * @req: Link speed request structure
 * @context: User context to be passed back when invoking @cb
 * @cb: Callback function to be invoked with link speed results
 *
 * Return: QDF_STATUS_SUCCESS if the request was accepted, otherwise
 * an appropriate error status.
 */
QDF_STATUS sme_get_link_speed(mac_handle_t mac_handle,
			      struct link_speed_info *req,
			      void *context,
			      sme_link_speed_cb cb);

QDF_STATUS sme_modify_add_ie(mac_handle_t mac_handle,
		tSirModifyIE *pModifyIE, eUpdateIEsType updateType);
QDF_STATUS sme_update_add_ie(mac_handle_t mac_handle,
		tSirUpdateIE *pUpdateIE, eUpdateIEsType updateType);
QDF_STATUS sme_update_connect_debug(mac_handle_t mac_handle,
				    uint32_t set_value);
const char *sme_bss_type_to_string(const uint8_t bss_type);
QDF_STATUS sme_ap_disable_intra_bss_fwd(mac_handle_t mac_handle,
					uint8_t sessionId,
					bool disablefwd);

/**
 * sme_send_unit_test_cmd() - send unit test command to lower layer
 * @session_id: sme session id to be filled while forming the command
 * @module_id: module id given by user to be filled in the command
 * @arg_count: number of argument count
 * @arg: pointer to argument list
 *
 * This API exposed to HDD layer which takes the argument from user and sends
 * down to lower layer for further processing
 *
 * Return: QDF_STATUS based on overall success
 */
QDF_STATUS sme_send_unit_test_cmd(uint32_t vdev_id, uint32_t module_id,
				  uint32_t arg_count, uint32_t *arg);

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
typedef struct sStatsExtRequestReq {
	uint32_t request_data_len;
	uint8_t *request_data;
} tStatsExtRequestReq, *tpStatsExtRequestReq;
<<<<<<< HEAD
typedef void (*StatsExtCallback)(void *, tStatsExtEvent *);
void sme_stats_ext_register_callback(tHalHandle hHal,
		StatsExtCallback callback);

/**
 * sme_register_stats_ext2_callback() - Register stats ext2 register
 * @hal_handle: hal handle for getting global mac struct
 * @stats_ext2_cb: callback to be registered
=======

#ifdef WLAN_FEATURE_STATS_EXT
/**
 * sme_stats_ext_register_callback() - Register stats ext callback
 * @mac_handle: Opaque handle to the MAC context
 * @callback: Function to be invoked for stats ext events
 *
 * This function is called to register the callback that send vendor
 * event for stats ext
 */
void sme_stats_ext_register_callback(mac_handle_t mac_handle,
				     stats_ext_cb callback);

/**
 * sme_stats_ext_deregister_callback() - Deregister stats ext callback
 * @mac_handle: Opaque handle to the MAC context
 *
 * This function is called to deregister the callback that send vendor
 * event for stats ext
 */
void sme_stats_ext_deregister_callback(mac_handle_t mac_handle);

/**
 * sme_stats_ext2_register_callback() - Register stats ext2 callback
 * @mac_handle: Opaque handle to the MAC context
 * @callback: Function to be invoked for stats ext2 events
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *
 * This function will register a callback for frame aggregation failure
 * indications processing.
 *
 * Return: void
 */
<<<<<<< HEAD
void sme_stats_ext2_register_callback(tHalHandle hal_handle,
		void (*stats_ext2_cb)(void *, struct stats_ext2_event *));
void sme_stats_ext_deregister_callback(tHalHandle hhal);
QDF_STATUS sme_stats_ext_request(uint8_t session_id,
		tpStatsExtRequestReq input);
QDF_STATUS sme_stats_ext_event(tHalHandle hHal, void *pMsg);
#endif
QDF_STATUS sme_update_dfs_scan_mode(tHalHandle hHal,
		uint8_t sessionId,
		uint8_t allowDFSChannelRoam);
uint8_t sme_get_dfs_scan_mode(tHalHandle hHal);

#ifdef FEATURE_WLAN_EXTSCAN
QDF_STATUS sme_get_valid_channels_by_band(tHalHandle hHal, uint8_t wifiBand,
		uint32_t *aValidChannels,
		uint8_t *pNumChannels);
QDF_STATUS sme_ext_scan_get_capabilities(tHalHandle hHal,
		tSirGetExtScanCapabilitiesReqParams *pReq);
QDF_STATUS sme_ext_scan_start(tHalHandle hHal,
		tSirWifiScanCmdReqParams *pStartCmd);
QDF_STATUS sme_ext_scan_stop(tHalHandle hHal,
		tSirExtScanStopReqParams *pStopReq);
QDF_STATUS sme_set_bss_hotlist(tHalHandle hHal,
		tSirExtScanSetBssidHotListReqParams *
		pSetHotListReq);
QDF_STATUS sme_reset_bss_hotlist(tHalHandle hHal,
		tSirExtScanResetBssidHotlistReqParams *
		pResetReq);
QDF_STATUS sme_set_significant_change(tHalHandle hHal,
		tSirExtScanSetSigChangeReqParams *
		pSetSignificantChangeReq);
QDF_STATUS sme_reset_significant_change(tHalHandle hHal,
		tSirExtScanResetSignificantChangeReqParams
		*pResetReq);
QDF_STATUS sme_get_cached_results(tHalHandle hHal,
		tSirExtScanGetCachedResultsReqParams *
		pCachedResultsReq);

QDF_STATUS sme_set_epno_list(tHalHandle hal,
			     struct wifi_epno_params *req_msg);
QDF_STATUS sme_set_passpoint_list(tHalHandle hal,
					struct wifi_passpoint_req *req_msg);
QDF_STATUS sme_reset_passpoint_list(tHalHandle hal,
					struct wifi_passpoint_req *req_msg);

QDF_STATUS sme_ext_scan_register_callback(tHalHandle hHal,
		void (*pExtScanIndCb)(void *, const uint16_t, void *));
#else
static inline QDF_STATUS sme_ext_scan_register_callback(tHalHandle hHal,
		void (*pExtScanIndCb)(void *, const uint16_t, void *))
{
	return QDF_STATUS_SUCCESS;
}
#endif /* FEATURE_WLAN_EXTSCAN */
QDF_STATUS sme_abort_roam_scan(tHalHandle hHal, uint8_t sessionId);
#ifdef WLAN_FEATURE_LINK_LAYER_STATS
QDF_STATUS sme_ll_stats_clear_req(tHalHandle hHal,
		tSirLLStatsClearReq * pclearStatsReq);
QDF_STATUS sme_ll_stats_set_req(tHalHandle hHal,
		tSirLLStatsSetReq *psetStatsReq);
QDF_STATUS sme_ll_stats_get_req(tHalHandle hHal,
				tSirLLStatsGetReq *pgetStatsReq,
				void *context);
QDF_STATUS sme_set_link_layer_stats_ind_cb(tHalHandle hHal,
		void (*callbackRoutine)(void *callbackCtx,
					int indType, void *pRsp,
					void *cookie));
QDF_STATUS sme_set_link_layer_ext_cb(tHalHandle hal,
		     void (*ll_stats_ext_cb)(tHddHandle callback_ctx,
					     tSirLLStatsResults * rsp));
QDF_STATUS sme_reset_link_layer_stats_ind_cb(tHalHandle hhal);
QDF_STATUS sme_ll_stats_set_thresh(tHalHandle hal,
				struct sir_ll_ext_stats_threshold *threshold);
#endif /* WLAN_FEATURE_LINK_LAYER_STATS */

QDF_STATUS sme_set_wisa_params(tHalHandle hal,
				struct sir_wisa_params *wisa_params);
#ifdef WLAN_FEATURE_ROAM_OFFLOAD
QDF_STATUS sme_update_roam_offload_enabled(tHalHandle hHal,
		bool nRoamOffloadEnabled);
QDF_STATUS sme_update_roam_key_mgmt_offload_enabled(tHalHandle hal_ctx,
		uint8_t session_id,
		bool key_mgmt_offload_enabled,
		struct pmkid_mode_bits *pmkid_modes);
#endif
#ifdef WLAN_FEATURE_NAN
QDF_STATUS sme_nan_event(tHalHandle hHal, void *pMsg);
#endif /* WLAN_FEATURE_NAN */
QDF_STATUS sme_get_link_status(tHalHandle hHal,
		tCsrLinkStatusCallback callback,
		void *pContext, uint8_t sessionId);
QDF_STATUS sme_get_temperature(tHalHandle hHal,
		void *tempContext,
		void (*pCallbackfn)(int temperature,
			void *pContext));
QDF_STATUS sme_set_scanning_mac_oui(tHalHandle hHal,
		tSirScanMacOui *pScanMacOui);

#ifdef IPA_OFFLOAD
/* ---------------------------------------------------------------------------
    \fn sme_ipa_offload_enable_disable
    \brief  API to enable/disable IPA offload
    \param  hHal - The handle returned by macOpen.
    \param  sessionId - Session Identifier
    \param  pRequest -  Pointer to the offload request.
    \return QDF_STATUS
  ---------------------------------------------------------------------------*/
QDF_STATUS sme_ipa_offload_enable_disable(tHalHandle hal,
				uint8_t session_id,
				struct sir_ipa_offload_enable_disable *request);
#else
static inline QDF_STATUS sme_ipa_offload_enable_disable(tHalHandle hal,
				uint8_t session_id,
				struct sir_ipa_offload_enable_disable *request)
{
	return QDF_STATUS_SUCCESS;
}
#endif /* IPA_OFFLOAD */

#ifdef DHCP_SERVER_OFFLOAD
QDF_STATUS sme_set_dhcp_srv_offload(tHalHandle hHal,
		tSirDhcpSrvOffloadInfo * pDhcpSrvInfo);
#endif /* DHCP_SERVER_OFFLOAD */
#ifdef WLAN_FEATURE_GPIO_LED_FLASHING
QDF_STATUS sme_set_led_flashing(tHalHandle hHal, uint8_t type,
		uint32_t x0, uint32_t x1);
#endif
QDF_STATUS sme_handle_dfs_chan_scan(tHalHandle hHal, uint8_t dfs_flag);
QDF_STATUS sme_set_mas(uint32_t val);
QDF_STATUS sme_set_miracast(tHalHandle hal, uint8_t filter_type);
QDF_STATUS sme_ext_change_channel(tHalHandle hHal, uint32_t channel,
					  uint8_t session_id);

QDF_STATUS sme_configure_modulated_dtim(tHalHandle hal, uint8_t session_id,
				      uint32_t modulated_dtim);

QDF_STATUS sme_override_listen_interval(tHalHandle h_hal, uint8_t session_id,
		uint32_t override_li);

QDF_STATUS sme_configure_stats_avg_factor(tHalHandle hal, uint8_t session_id,
					  uint16_t stats_avg_factor);

QDF_STATUS sme_configure_guard_time(tHalHandle hal, uint8_t session_id,
				    uint32_t guard_time);

QDF_STATUS sme_wifi_start_logger(tHalHandle hal,
		struct sir_wifi_start_log start_log);

bool sme_neighbor_middle_of_roaming(tHalHandle hHal,
						uint8_t sessionId);

/*
 * sme_is_any_session_in_middle_of_roaming() - check if roaming is in progress
 * @hal: HAL Handle
 *
 * Checks if any SME session is in middle of roaming
 *
 * Return : true if roaming is in progress else false
 */
bool sme_is_any_session_in_middle_of_roaming(tHalHandle hal);

QDF_STATUS sme_enable_uapsd_for_ac(void *cds_ctx, uint8_t sta_id,
				      sme_ac_enum_type ac, uint8_t tid,
				      uint8_t pri, uint32_t srvc_int,
				      uint32_t sus_int,
				      sme_qos_wmm_dir_type dir,
				      uint8_t psb, uint32_t sessionId,
				      uint32_t delay_interval);

QDF_STATUS sme_disable_uapsd_for_ac(void *cds_ctx, uint8_t sta_id,
				       sme_ac_enum_type ac,
				       uint32_t sessionId);

QDF_STATUS sme_set_rssi_monitoring(tHalHandle hal,
					struct rssi_monitor_req *input);
QDF_STATUS sme_set_rssi_threshold_breached_cb(tHalHandle hal,
			void (*cb)(void *, struct rssi_breach_event *));
QDF_STATUS sme_reset_rssi_threshold_breached_cb(tHalHandle hal);

QDF_STATUS sme_register_mgmt_frame_ind_callback(tHalHandle hal,
			sir_mgmt_frame_ind_callback callback);

QDF_STATUS sme_update_nss(tHalHandle h_hal, uint8_t nss);
void sme_update_user_configured_nss(tHalHandle hal, uint8_t nss);

bool sme_is_any_session_in_connected_state(tHalHandle h_hal);

QDF_STATUS sme_pdev_set_pcl(tHalHandle hal,
		struct sir_pcl_list msg);
QDF_STATUS sme_pdev_set_hw_mode(tHalHandle hal,
		struct sir_hw_mode msg);
void sme_register_hw_mode_trans_cb(tHalHandle hal,
		hw_mode_transition_cb callback);
QDF_STATUS sme_nss_update_request(tHalHandle hHal, uint32_t vdev_id,
				uint8_t  new_nss, void *cback,
				uint8_t next_action, void *hdd_context,
				enum sir_conn_update_reason reason);

typedef void (*sme_peer_authorized_fp) (uint32_t vdev_id);
QDF_STATUS sme_set_peer_authorized(uint8_t *peer_addr,
				   sme_peer_authorized_fp auth_fp,
				   uint32_t vdev_id);
QDF_STATUS sme_soc_set_dual_mac_config(tHalHandle hal,
		struct sir_dual_mac_config msg);
QDF_STATUS sme_soc_set_antenna_mode(tHalHandle hal,
		struct sir_antenna_mode_param *msg);

void sme_set_scan_disable(tHalHandle h_hal, int value);
void sme_setdef_dot11mode(tHalHandle hal);

QDF_STATUS sme_handle_set_fcc_channel(tHalHandle hHal,
				      bool fcc_constraint,
				      bool scan_pending);

QDF_STATUS sme_update_roam_scan_hi_rssi_scan_params(tHalHandle hal_handle,
	uint8_t session_id,
	uint32_t notify_id,
	int32_t val);

void wlan_sap_enable_phy_error_logs(tHalHandle hal, bool enable_log);
#ifdef WLAN_FEATURE_DSRC
void sme_set_dot11p_config(tHalHandle hal, bool enable_dot11p);

QDF_STATUS sme_ocb_set_config(tHalHandle hHal, void *context,
			      ocb_callback callback,
			      struct sir_ocb_config *config);

QDF_STATUS sme_ocb_set_utc_time(tHalHandle hHal, struct sir_ocb_utc *utc);

QDF_STATUS sme_ocb_start_timing_advert(tHalHandle hHal,
	struct sir_ocb_timing_advert *timing_advert);

QDF_STATUS sme_ocb_stop_timing_advert(tHalHandle hHal,
	struct sir_ocb_timing_advert *timing_advert);

int sme_ocb_gen_timing_advert_frame(tHalHandle hHal, tSirMacAddr self_addr,
				    uint8_t **buf, uint32_t *timestamp_offset,
				    uint32_t *time_value_offset);

QDF_STATUS sme_ocb_get_tsf_timer(tHalHandle hHal, void *context,
				 ocb_callback callback,
				 struct sir_ocb_get_tsf_timer *request);

QDF_STATUS sme_dcc_get_stats(tHalHandle hHal, void *context,
			     ocb_callback callback,
			     struct sir_dcc_get_stats *request);

QDF_STATUS sme_dcc_clear_stats(tHalHandle hHal, uint32_t vdev_id,
			       uint32_t dcc_stats_bitmap);

QDF_STATUS sme_dcc_update_ndl(tHalHandle hHal, void *context,
			      ocb_callback callback,
			      struct sir_dcc_update_ndl *request);

QDF_STATUS sme_register_for_dcc_stats_event(tHalHandle hHal, void *context,
					    ocb_callback callback);
QDF_STATUS sme_deregister_for_dcc_stats_event(tHalHandle hHal);

#else
static inline void sme_set_dot11p_config(tHalHandle hal, bool enable_dot11p)
{
	return;
}

static inline QDF_STATUS sme_ocb_set_config(tHalHandle hHal, void *context,
		ocb_callback callback,
		struct sir_ocb_config *config)
{
	return QDF_STATUS_SUCCESS;
}

static inline QDF_STATUS sme_ocb_set_utc_time(struct sir_ocb_utc *utc)
{
	return QDF_STATUS_SUCCESS;
}

static inline QDF_STATUS sme_ocb_start_timing_advert(
		struct sir_ocb_timing_advert *timing_advert)
{
	return QDF_STATUS_SUCCESS;
}

static inline QDF_STATUS sme_ocb_stop_timing_advert(struct sir_ocb_timing_advert
		*timing_advert)
{
	return QDF_STATUS_SUCCESS;
}

static inline int sme_ocb_gen_timing_advert_frame(tHalHandle hHal,
		tSirMacAddr self_addr, uint8_t **buf,
		uint32_t *timestamp_offset,
		uint32_t *time_value_offset)
{
	return 0;
}

static inline QDF_STATUS sme_ocb_get_tsf_timer(tHalHandle hHal, void *context,
		ocb_callback callback,
		struct sir_ocb_get_tsf_timer *request)
{
	return QDF_STATUS_SUCCESS;
}

static inline QDF_STATUS sme_dcc_get_stats(tHalHandle hHal, void *context,
		ocb_callback callback,
		struct sir_dcc_get_stats *request)
{
	return QDF_STATUS_SUCCESS;
}

static inline QDF_STATUS sme_dcc_clear_stats(uint32_t vdev_id,
		uint32_t dcc_stats_bitmap)
{
	return QDF_STATUS_SUCCESS;
}

static inline QDF_STATUS sme_dcc_update_ndl(tHalHandle hHal, void *context,
		ocb_callback callback,
		struct sir_dcc_update_ndl *request)
{
	return QDF_STATUS_SUCCESS;
}

static inline QDF_STATUS sme_register_for_dcc_stats_event(tHalHandle hHal,
		void *context, ocb_callback callback)
{
	return QDF_STATUS_SUCCESS;
}
static inline QDF_STATUS sme_deregister_for_dcc_stats_event(tHalHandle hHal)
{
	return QDF_STATUS_SUCCESS;
}
#endif
void sme_add_set_thermal_level_callback(tHalHandle hal,
		sme_set_thermal_level_callback callback);

void sme_update_tgt_services(tHalHandle hal, struct wma_tgt_services *cfg);
bool sme_validate_sap_channel_switch(tHalHandle hal,
		uint16_t sap_ch, eCsrPhyMode sap_phy_mode,
		uint8_t cc_switch_mode, uint8_t session_id);

bool sme_is_session_id_valid(tHalHandle hal, uint32_t session_id);

#ifdef FEATURE_WLAN_TDLS
void sme_get_opclass(tHalHandle hal, uint8_t channel, uint8_t bw_offset,
		uint8_t *opclass);
#else
static inline void
sme_get_opclass(tHalHandle hal, uint8_t channel, uint8_t bw_offset,
=======
void sme_stats_ext2_register_callback(mac_handle_t mac_handle,
				      stats_ext2_cb callback);

QDF_STATUS sme_stats_ext_request(uint8_t session_id,
				 tpStatsExtRequestReq input);
#else
static inline void
sme_stats_ext_register_callback(mac_handle_t mac_handle,
				stats_ext_cb callback)
{
}

static inline void
sme_stats_ext_deregister_callback(mac_handle_t mac_handle)
{
}

static inline void
sme_stats_ext2_register_callback(mac_handle_t mac_handle,
				 stats_ext2_cb callback)
{
}
#endif /* WLAN_FEATURE_STATS_EXT */
QDF_STATUS sme_update_dfs_scan_mode(mac_handle_t mac_handle,
		uint8_t sessionId,
		uint8_t allowDFSChannelRoam);
uint8_t sme_get_dfs_scan_mode(mac_handle_t mac_handle);

/**
 * sme_get_valid_channels_by_band() - to fetch valid channels filtered by band
 * @mac_handle: Opaque handle to the global MAC context
 * @wifi_band: RF band information
 * @valid_chan_list: output array to store channel info
 * @valid_chan_len: output number of channels
 *
 *  SME API to fetch all valid channels filtered by band
 *
 *  Return: QDF_STATUS
 */
QDF_STATUS sme_get_valid_channels_by_band(mac_handle_t mac_handle,
					  uint8_t wifi_band,
					  uint32_t *valid_chan_list,
					  uint8_t *valid_chan_len);

#ifdef FEATURE_WLAN_EXTSCAN
/**
 * sme_ext_scan_get_capabilities() - SME API to fetch extscan capabilities
 * @mac_handle: Opaque handle to the MAC context
 * @params: extscan capabilities request structure
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
sme_ext_scan_get_capabilities(mac_handle_t mac_handle,
			      struct extscan_capabilities_params *params);

/**
 * sme_ext_scan_start() - SME API to issue extscan start
 * @mac_handle: Opaque handle to the MAC context
 * @params: extscan start structure
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
sme_ext_scan_start(mac_handle_t mac_handle,
		   struct wifi_scan_cmd_req_params *params);

/**
 * sme_ext_scan_stop() - SME API to issue extscan stop
 * @mac_handle: Opaque handle to the MAC context
 * @params: extscan stop structure
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_ext_scan_stop(mac_handle_t mac_handle,
			     struct extscan_stop_req_params *params);

/**
 * sme_set_bss_hotlist() - SME API to set BSSID hotlist
 * @mac_handle: Opaque handle to the MAC context
 * @params: extscan set hotlist structure
 *
 * Handles the request to set the BSSID hotlist in firmware.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
sme_set_bss_hotlist(mac_handle_t mac_handle,
		    struct extscan_bssid_hotlist_set_params *params);

/**
 * sme_reset_bss_hotlist() - SME API to reset BSSID hotlist
 * @mac_handle: Opaque handle to the MAC context
 * @params: extscan reset hotlist structure
 *
 * Handles the request to reset the BSSID hotlist in firmware.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
sme_reset_bss_hotlist(mac_handle_t mac_handle,
		      struct extscan_bssid_hotlist_reset_params *params);

/**
 * sme_set_significant_change() - SME API to set significant change
 * @mac_handle: Opaque handle to the MAC context
 * @params: extscan set significant change structure
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
sme_set_significant_change(mac_handle_t mac_handle,
			   struct extscan_set_sig_changereq_params *params);

/**
 * sme_reset_significant_change() -  SME API to reset significant change
 * @mac_handle: Opaque handle to the MAC context
 * @params: extscan reset significant change structure
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
sme_reset_significant_change(mac_handle_t mac_handle,
			     struct extscan_capabilities_reset_params *params);

/**
 * sme_get_cached_results() - SME API to get cached results
 * @mac_handle: Opaque handle to the MAC context
 * @params: extscan get cached results structure
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
sme_get_cached_results(mac_handle_t mac_handle,
		       struct extscan_cached_result_params *params);

/**
 * sme_set_epno_list() - set epno network list
 * @mac_handle: Opaque handle to the MAC context
 * @params: request message
 *
 * This function sends an Enhanced PNO configuration to firmware.
 *
 * Return: QDF_STATUS enumeration
 */
QDF_STATUS sme_set_epno_list(mac_handle_t mac_handle,
			     struct wifi_enhanced_pno_params *params);

/**
 * sme_set_passpoint_list() - set passpoint network list
 * @mac_handle: Opaque handle to the MAC context
 * @params: set passpoint list request parameters
 *
 * This function constructs the cds message and fill in message type,
 * bodyptr with @params and posts it to WDA queue.
 *
 * Return: QDF_STATUS enumeration
 */
QDF_STATUS sme_set_passpoint_list(mac_handle_t mac_handle,
				  struct wifi_passpoint_req_param *params);

/**
 * sme_reset_passpoint_list() - reset passpoint network list
 * @mac_handle: Opaque handle to the MAC context
 * @params: reset passpoint list request parameters
 *
 * Return: QDF_STATUS enumeration
 */
QDF_STATUS sme_reset_passpoint_list(mac_handle_t mac_handle,
				    struct wifi_passpoint_req_param *params);

QDF_STATUS sme_ext_scan_register_callback(mac_handle_t mac_handle,
					  ext_scan_ind_cb ext_scan_ind_cb);
#else
static inline
QDF_STATUS sme_ext_scan_register_callback(mac_handle_t mac_handle,
					  ext_scan_ind_cb ext_scan_ind_cb)
{
	return QDF_STATUS_SUCCESS;
}
#endif /* FEATURE_WLAN_EXTSCAN */
QDF_STATUS sme_abort_roam_scan(mac_handle_t mac_handle, uint8_t sessionId);

/**
 * sme_get_vht_ch_width() - SME API to get the max supported FW chan width
 *
 * Return: Max channel width supported by FW (eg. 20, 40, 80, 160, 80+80)
 */
uint32_t sme_get_vht_ch_width(void);

#ifdef WLAN_FEATURE_LINK_LAYER_STATS
QDF_STATUS sme_ll_stats_clear_req(mac_handle_t mac_handle,
		tSirLLStatsClearReq * pclearStatsReq);
QDF_STATUS sme_ll_stats_set_req(mac_handle_t mac_handle,
		tSirLLStatsSetReq *psetStatsReq);

/**
 * sme_ll_stats_get_req() - SME API to get the Link Layer Statistics
 * @mac_handle: Global MAC handle
 * @get_stats_req: Link Layer get stats request params structure
 * @context: Callback context
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_ll_stats_get_req(mac_handle_t mac_handle,
				tSirLLStatsGetReq *get_stats_req,
				void *context);

/**
 * sme_set_link_layer_stats_ind_cb() -
 * SME API to trigger the stats are available after get request
 * @mac_handle: MAC handle
 * @callback: HDD callback which needs to be invoked after
 *    getting status notification from FW
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_set_link_layer_stats_ind_cb(mac_handle_t mac_handle,
					   link_layer_stats_cb callback);

QDF_STATUS sme_set_link_layer_ext_cb(mac_handle_t mac_handle,
		     void (*ll_stats_ext_cb)(hdd_handle_t callback_ctx,
					     tSirLLStatsResults * rsp));
QDF_STATUS sme_reset_link_layer_stats_ind_cb(mac_handle_t mac_handle);
QDF_STATUS sme_ll_stats_set_thresh(mac_handle_t mac_handle,
				struct sir_ll_ext_stats_threshold *threshold);
#else /* WLAN_FEATURE_LINK_LAYER_STATS */
static inline QDF_STATUS
sme_set_link_layer_ext_cb(mac_handle_t mac_handle, void (*ll_stats_ext_cb)
			  (hdd_handle_t callback_ctx, tSirLLStatsResults
			  *rsp))
{
	return QDF_STATUS_SUCCESS;
}

static inline QDF_STATUS
sme_set_link_layer_stats_ind_cb(mac_handle_t mac_handle,
				link_layer_stats_cb callback)
{
	return QDF_STATUS_SUCCESS;
}

static inline QDF_STATUS
sme_reset_link_layer_stats_ind_cb(mac_handle_t mac_handle)
{
	return QDF_STATUS_SUCCESS;
}
#endif /* WLAN_FEATURE_LINK_LAYER_STATS */

QDF_STATUS sme_set_wisa_params(mac_handle_t mac_handle,
			       struct sir_wisa_params *wisa_params);
#ifdef WLAN_FEATURE_ROAM_OFFLOAD
QDF_STATUS sme_update_roam_key_mgmt_offload_enabled(mac_handle_t mac_handle,
		uint8_t session_id,
		bool key_mgmt_offload_enabled,
		struct pmkid_mode_bits *pmkid_modes);
#endif
QDF_STATUS sme_get_link_status(mac_handle_t mac_handle,
			       csr_link_status_callback callback,
			       void *context, uint8_t session_id);
QDF_STATUS sme_get_temperature(mac_handle_t mac_handle,
		void *tempContext,
		void (*pCallbackfn)(int temperature,
			void *pContext));

/**
 * sme_set_scanning_mac_oui() - SME API to set scanning mac oui
 * @mac_handle: MAC Handle
 * @scan_mac_oui: Scanning Mac Oui
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_set_scanning_mac_oui(mac_handle_t mac_handle,
				    struct scan_mac_oui *scan_mac_oui);

#ifdef DHCP_SERVER_OFFLOAD
/**
 * sme_set_dhcp_srv_offload() - Set DHCP server offload
 * @mac_handle: Handle to the global MAC context
 * @dhcp_srv_info : DHCP server offload info struct
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
sme_set_dhcp_srv_offload(mac_handle_t mac_handle,
			 struct dhcp_offload_info_params *dhcp_srv_info);
#endif /* DHCP_SERVER_OFFLOAD */
#ifdef WLAN_FEATURE_GPIO_LED_FLASHING
QDF_STATUS sme_set_led_flashing(mac_handle_t mac_handle, uint8_t type,
		uint32_t x0, uint32_t x1);
#endif
QDF_STATUS sme_enable_dfs_chan_scan(mac_handle_t mac_handle, uint8_t dfs_flag);
QDF_STATUS sme_set_mas(uint32_t val);
QDF_STATUS sme_set_miracast(mac_handle_t mac_handle, uint8_t filter_type);
QDF_STATUS sme_ext_change_channel(mac_handle_t mac_handle, uint32_t channel,
				  uint8_t session_id);

QDF_STATUS sme_configure_stats_avg_factor(mac_handle_t mac_handle,
					  uint8_t session_id,
					  uint16_t stats_avg_factor);

QDF_STATUS sme_configure_guard_time(mac_handle_t mac_handle, uint8_t session_id,
				    uint32_t guard_time);

QDF_STATUS sme_wifi_start_logger(mac_handle_t mac_handle,
				 struct sir_wifi_start_log start_log);

bool sme_neighbor_middle_of_roaming(mac_handle_t mac_handle,
				    uint8_t sessionId);

/**
 * sme_is_any_session_in_middle_of_roaming() - check if roaming is in progress
 * @mac_handle: MAC Handle
 *
 * Checks if any SME session is in middle of roaming
 *
 * Return: true if roaming is in progress else false
 */
bool sme_is_any_session_in_middle_of_roaming(mac_handle_t mac_handle);

/**
 * sme_send_flush_logs_cmd_to_fw() - Initiate command to FW to flush logs
 *
 * This function will initiate a command to firmware to flush their logs.
 * This should normally be done in response to an anomaly detected by the
 * host.
 *
 * Return: QDF_STATUS_SUCCESS if the command was sent, otherwise an
 *         appropriate QDF_STATUS error
 */
QDF_STATUS sme_send_flush_logs_cmd_to_fw(void);

/**
 * sme_enable_uapsd_for_ac() - enable uapsd for access category request to WMA
 * @ac: access category
 * @tid: tid value
 * @pri: user priority
 * @srvc_int: service interval
 * @sus_int: suspend interval
 * @dir: tspec direction
 * @psb: PSB value
 * @sessionId: session id
 * @delay_interval: delay interval
 *
 * Return: QDF status
 */
QDF_STATUS sme_enable_uapsd_for_ac(sme_ac_enum_type ac, uint8_t tid,
				   uint8_t pri, uint32_t srvc_int,
				   uint32_t sus_int,
				   enum sme_qos_wmm_dir_type dir,
				   uint8_t psb, uint32_t sessionId,
				   uint32_t delay_interval);

/**
 * sme_disable_uapsd_for_ac() - disable uapsd access category request to WMA
 * @ac: access category
 * @sessionId: session id
 *
 * Return: QDF status
 */
QDF_STATUS sme_disable_uapsd_for_ac(sme_ac_enum_type ac, uint32_t sessionId);

#ifdef FEATURE_RSSI_MONITOR
QDF_STATUS sme_set_rssi_monitoring(mac_handle_t mac_handle,
				   struct rssi_monitor_param *input);

/**
 * sme_set_rssi_threshold_breached_cb() - Set RSSI threshold breached callback
 * @mac_handle: global MAC handle
 * @cb: callback function pointer
 *
 * This function registers the RSSI threshold breached callback function.
 *
 * Return: QDF_STATUS enumeration.
 */
QDF_STATUS sme_set_rssi_threshold_breached_cb(mac_handle_t mac_handle,
					      rssi_threshold_breached_cb cb);
#else /* FEATURE_RSSI_MONITOR */
static inline
QDF_STATUS sme_set_rssi_threshold_breached_cb(mac_handle_t mac_handle,
					      rssi_threshold_breached_cb cb)
{
	return QDF_STATUS_SUCCESS;
}
#endif
/**
 * sme_reset_rssi_threshold_breached_cb() - Reset RSSI threshold breached
 *                                          callback
 * @mac_handle: global MAC handle
 *
 * This function de-registers the RSSI threshold breached callback function.
 *
 * Return: QDF_STATUS enumeration.
 */
QDF_STATUS sme_reset_rssi_threshold_breached_cb(mac_handle_t mac_handle);

QDF_STATUS sme_register_mgmt_frame_ind_callback(mac_handle_t mac_handle,
			sir_mgmt_frame_ind_callback callback);

QDF_STATUS sme_update_nss(mac_handle_t mac_handle, uint8_t nss);
void sme_update_user_configured_nss(mac_handle_t mac_handle, uint8_t nss);

bool sme_is_any_session_in_connected_state(mac_handle_t mac_handle);

QDF_STATUS sme_pdev_set_pcl(struct policy_mgr_pcl_list *msg);
QDF_STATUS sme_pdev_set_hw_mode(struct policy_mgr_hw_mode msg);
QDF_STATUS sme_nss_update_request(uint32_t vdev_id,
				  uint8_t  new_nss, uint8_t ch_width,
				  policy_mgr_nss_update_cback cback,
				  uint8_t next_action,
				  struct wlan_objmgr_psoc *psoc,
				  enum policy_mgr_conn_update_reason reason,
				  uint32_t original_vdev_id);

typedef void (*sme_peer_authorized_fp) (uint32_t vdev_id);
QDF_STATUS sme_set_peer_authorized(uint8_t *peer_addr,
				   sme_peer_authorized_fp auth_fp,
				   uint32_t vdev_id);
QDF_STATUS sme_soc_set_dual_mac_config(struct policy_mgr_dual_mac_config msg);
QDF_STATUS sme_soc_set_antenna_mode(mac_handle_t mac_handle,
				    struct sir_antenna_mode_param *msg);

void sme_setdef_dot11mode(mac_handle_t mac_handle);

/**
 * sme_update_tx_bfee_supp() - sets the Tx Bfee support
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: SME session id
 * @cfg_val: Tx Bfee config value
 *
 * Return: 0 on success else err code
 */
int sme_update_tx_bfee_supp(mac_handle_t mac_handle, uint8_t session_id,
			    uint8_t cfg_val);

/**
 * sme_update_tx_bfee_nsts() - sets the Tx Bfee nsts
 * @mac_handle: MAC handle
 * @session_id: SME session id
 * @usr_cfg_val: user config value
 * @nsts_val: Tx Bfee nsts config value
 *
 * Return: 0 on success else err code
 */
int sme_update_tx_bfee_nsts(mac_handle_t mac_handle, uint8_t session_id,
			    uint8_t usr_cfg_val, uint8_t nsts_val);

void wlan_sap_enable_phy_error_logs(mac_handle_t mac_handle,
				    uint32_t enable_log);
#ifdef WLAN_FEATURE_DSRC
int sme_ocb_gen_timing_advert_frame(mac_handle_t mac_handle,
				    tSirMacAddr self_addr,
				    uint8_t **buf, uint32_t *timestamp_offset,
				    uint32_t *time_value_offset);

#else
static inline
int sme_ocb_gen_timing_advert_frame(mac_handle_t mac_handle,
				    tSirMacAddr self_addr, uint8_t **buf,
				    uint32_t *timestamp_offset,
				    uint32_t *time_value_offset)
{
	return 0;
}

#endif

void sme_add_set_thermal_level_callback(mac_handle_t mac_handle,
		sme_set_thermal_level_callback callback);

void sme_update_tgt_services(mac_handle_t mac_handle,
			     struct wma_tgt_services *cfg);

bool sme_validate_sap_channel_switch(mac_handle_t mac_handle,
				     uint32_t sap_ch_freq, eCsrPhyMode sap_phy_mode,
				     uint8_t cc_switch_mode,
				     uint8_t session_id);

bool sme_is_session_id_valid(mac_handle_t mac_handle, uint32_t session_id);

#ifdef FEATURE_WLAN_TDLS
void sme_get_opclass(mac_handle_t mac_handle, uint8_t channel,
		     uint8_t bw_offset, uint8_t *opclass);
#else
static inline void
sme_get_opclass(mac_handle_t mac_handle, uint8_t channel, uint8_t bw_offset,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		uint8_t *opclass)
{
}
#endif

#ifdef FEATURE_LFR_SUBNET_DETECTION
<<<<<<< HEAD
QDF_STATUS sme_gateway_param_update(tHalHandle hHal,
				struct gateway_param_update_req *request);
#endif

#ifdef FEATURE_GREEN_AP
QDF_STATUS sme_send_egap_conf_params(uint32_t enable,
				     uint32_t inactivity_time,
				     uint32_t wait_time,
				     uint32_t flags);
#else
static inline QDF_STATUS sme_send_egap_conf_params(uint32_t enable,
						   uint32_t inactivity_time,
						   uint32_t wait_time,
						   uint32_t flags)
{
	return QDF_STATUS_E_NOSUPPORT;
}
#endif

void sme_update_fine_time_measurement_capab(tHalHandle hal, uint8_t session_id,
								uint32_t val);
QDF_STATUS sme_ht40_stop_obss_scan(tHalHandle hHal, uint32_t vdev_id);
QDF_STATUS sme_set_fw_test(struct set_fwtest_params *fw_test);
QDF_STATUS sme_set_tsfcb(tHalHandle hHal,
	int (*cb_fn)(void *cb_ctx, struct stsf *ptsf), void *cb_ctx);

QDF_STATUS sme_reset_tsfcb(tHalHandle h_hal);

#ifdef WLAN_FEATURE_TSF
QDF_STATUS sme_set_tsf_gpio(tHalHandle h_hal, uint32_t pinvalue);
QDF_STATUS sme_reset_tsf_gpio(tHalHandle h_hal);

#else
static inline QDF_STATUS sme_set_tsf_gpio(tHalHandle h_hal, uint32_t pinvalue)
{
	return QDF_STATUS_E_FAILURE;
}
static inline QDF_STATUS sme_reset_tsf_gpio(tHalHandle h_hal)
{
	return QDF_STATUS_E_FAILURE;
}

#endif

QDF_STATUS sme_update_mimo_power_save(tHalHandle hHal,
				      uint8_t is_ht_smps_enabled,
				      uint8_t ht_smps_mode,
				      bool send_smps_action);

bool sme_is_sta_smps_allowed(tHalHandle hHal, uint8_t session_id);
QDF_STATUS sme_add_beacon_filter(tHalHandle hal,
				uint32_t session_id, uint32_t *ie_map);
QDF_STATUS sme_remove_beacon_filter(tHalHandle hal, uint32_t session_id);

/**
 * sme_apf_offload_register_callback() - Register get apf offload callback
 *
 * @hal - MAC global handle
 * @callback_routine - callback routine from HDD
 *
 * API used by HDD to register its APF get caps callback in SME.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_apf_offload_register_callback(tHalHandle hal,
					void (*papf_get_offload_cb)(void *,
					struct sir_apf_get_offload *));

/**
 * sme_apf_offload_deregister_callback() - De-register get apf offload callback
 *
 * @hal - MAC global handle
 *
 * API used by HDD to de-register its APF get caps callback in SME.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_apf_offload_deregister_callback(tHalHandle hal);

/**
 * sme_get_apf_capabilities() - Get length for APF offload
 * @hal: Global HAL handle
 * @context: Context pointer
 *
 * API to get APF version and max filter size.
 *
 * Return: QDF_STATUS enumeration
 */
QDF_STATUS sme_get_apf_capabilities(tHalHandle hal, void *context);

/**
 * sme_set_apf_instructions() - Set APF apf filter instructions.
 * @hal: HAL handle
=======
QDF_STATUS sme_gateway_param_update(mac_handle_t mac_handle,
				struct gateway_update_req_param *request);
#endif

void sme_update_fine_time_measurement_capab(mac_handle_t mac_handle,
					    uint8_t session_id,
					    uint32_t val);
QDF_STATUS sme_ht40_stop_obss_scan(mac_handle_t mac_handle, uint32_t vdev_id);
QDF_STATUS sme_set_fw_test(struct set_fwtest_params *fw_test);
QDF_STATUS sme_set_tsfcb(mac_handle_t mac_handle,
	int (*cb_fn)(void *cb_ctx, struct stsf *ptsf), void *cb_ctx);

QDF_STATUS sme_reset_tsfcb(mac_handle_t mac_handle);

#if defined(WLAN_FEATURE_TSF) && !defined(WLAN_FEATURE_TSF_PLUS_NOIRQ)
QDF_STATUS sme_set_tsf_gpio(mac_handle_t mac_handle, uint32_t pinvalue);
#endif

QDF_STATUS sme_update_mimo_power_save(mac_handle_t mac_handle,
				      uint8_t is_ht_smps_enabled,
				      uint8_t ht_smps_mode,
				      bool send_smps_action);
#ifdef WLAN_BCN_RECV_FEATURE
/**
 * sme_handle_bcn_recv_start() - Enable fw to start sending
 * beacons of the current connected AP
 * @mac_handle: Opaque handle to the global MAC context
 * @vdev_id: SME session id
 * @nth_value: Beacon report period
 * @do_not_resume: beacon reporting resume after a pause is completed
 *
 * This function remove beacon filter. It allow fw to send
 * all beacons from connected peer to driver.
 *
 * Return: QDF_STATUS enumeration
 */
QDF_STATUS sme_handle_bcn_recv_start(mac_handle_t mac_handle,
				     uint32_t vdev_id,
				     uint32_t nth_value,
				     bool do_not_resume);

/**
 * sme_is_beacon_report_started() - Check bcn recv started
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: SME session id
 *
 * This function is to check beacon report started or not.
 *
 * Return: true on success
 */
bool sme_is_beacon_report_started(mac_handle_t mac_handle,
				  uint32_t session_id);

/**
 * sme_is_beacon_reporting_do_not_resume() - Check auto resume allowed or not
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: SME session id
 *
 * This function is to check auto resume of beacon reporting is allowed or not.
 *
 * Return: true on success
 */
bool sme_is_beacon_reporting_do_not_resume(mac_handle_t mac_handle,
					   uint32_t session_id);

/**
 * stop_beacon_report() - To stop beacon report
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: SME session id
 *
 * Return: None
 */
void sme_stop_beacon_report(mac_handle_t mac_handle,
			    uint32_t session_id);

#else
static inline
bool sme_is_beacon_report_started(mac_handle_t mac_handle,
				  uint32_t session_id)
{
	return true;
}

static inline
bool sme_is_beacon_reporting_do_not_resume(mac_handle_t mac_handle,
					   uint32_t session_id)
{
	return false;
}

static inline
void sme_stop_beacon_report(mac_handle_t mac_handle,
			    uint32_t session_id)
{
}

#endif

QDF_STATUS sme_add_beacon_filter(mac_handle_t mac_handle,
				 uint32_t session_id, uint32_t *ie_map);
QDF_STATUS sme_remove_beacon_filter(mac_handle_t mac_handle,
				    uint32_t session_id);

#ifdef FEATURE_WLAN_APF
/**
 * sme_get_apf_capabilities() - Get APF capabilities
 * @mac_handle: Opaque handle to the global MAC context
 * @callback: Callback function to be called with the result
 * @context: Opaque context to be used by the caller to associate the
 *   request with the response
 *
 * This function constructs the cds message and fill in message type,
 * post the same to WDA.
 *
 * Return: QDF_STATUS enumeration
 */
QDF_STATUS sme_get_apf_capabilities(mac_handle_t mac_handle,
				    apf_get_offload_cb callback,
				    void *context);

/**
 * sme_set_apf_instructions() - Set APF apf filter instructions.
 * @mac_handle: Opaque handle to the global MAC context
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @apf_set_offload: struct to set apf filter instructions.
 *
 * APFv2 (Legacy APF) API to set the APF packet filter.
 *
 * Return: QDF_STATUS enumeration.
 */
<<<<<<< HEAD
QDF_STATUS sme_set_apf_instructions(tHalHandle hal,
				struct sir_apf_set_offload *);

/**
 * sme_set_apf_enable_disable - Send apf enable/disable cmd
 * @hal: global hal handle
=======
QDF_STATUS sme_set_apf_instructions(mac_handle_t mac_handle,
				    struct sir_apf_set_offload
							*apf_set_offload);

/**
 * sme_set_apf_enable_disable - Send apf enable/disable cmd
 * @mac_handle: Opaque handle to the global MAC context
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @vdev_id: vdev id
 * @apf_enable: true: Enable APF Int., false: Disable APF Int.
 *
 * API to either enable or disable the APF interpreter.
 *
 * Return: QDF_STATUS enumeration.
 */
<<<<<<< HEAD
QDF_STATUS sme_set_apf_enable_disable(tHalHandle hal, uint8_t vdev_id,
=======
QDF_STATUS sme_set_apf_enable_disable(mac_handle_t mac_handle, uint8_t vdev_id,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				      bool apf_enable);

/**
 * sme_apf_write_work_memory - Write into the apf work memory
<<<<<<< HEAD
 * @hal: global hal handle
=======
 * @mac_handle: Opaque handle to the global MAC context
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @write_params: APF parameters for the write operation
 *
 * API for writing into the APF work memory.
 *
<<<<<<< HEAD
 * Return: QDF_STATUS enumeration.
 */
QDF_STATUS sme_apf_write_work_memory(tHalHandle hal,
				    struct wmi_apf_write_memory_params
								*write_params);

/**
 * sme_apf_read_work_memory - Read part of apf work memory
 * @hal: global hal handle
 * @read_params: APF parameters for the get operation
 *
 * API for issuing a APF read memory request.
 *
 * Return: QDF_STATUS enumeration.
 */
QDF_STATUS
sme_apf_read_work_memory(tHalHandle hal,
			 struct wmi_apf_read_memory_params *read_params);

/**
 * sme_apf_read_memory_register_callback() - Register apf mem callback
 *
 * @hal - MAC global handle
 * @callback_routine - callback routine from HDD
 *
 * API used by HDD to register its APF read memory callback in SME.
 *
 * Return: QDF_STATUS Enumeration
 */
QDF_STATUS sme_apf_read_memory_register_callback(tHalHandle hal,
			void (*apf_read_mem_cb)(void *context,
			struct wmi_apf_read_memory_resp_event_params *));

/**
 * sme_apf_read_memory_deregister_callback() - De-register apf mem callback
 *
 * @h_hal - MAC global handle
 *
 * API used by HDD to de-register its APF read memory callback in SME.
 *
 * Return: QDF_STATUS Enumeration
 */
QDF_STATUS sme_apf_read_memory_deregister_callback(tHalHandle h_hal);

uint32_t sme_get_wni_dot11_mode(tHalHandle hal);
QDF_STATUS sme_create_mon_session(tHalHandle hal_handle, uint8_t *bssid);
QDF_STATUS sme_set_adaptive_dwelltime_config(tHalHandle hal,
			struct adaptive_dwelltime_params *dwelltime_params);

void sme_set_vdev_ies_per_band(uint8_t vdev_id,
			       uint8_t is_hw_mode_dbs);
bool sme_check_enable_rx_ldpc_sta_ini_item(void);
QDF_STATUS sme_issue_same_ap_reassoc_cmd(uint8_t session_id);
void sme_set_pdev_ht_vht_ies(tHalHandle hHal, bool enable2x2);

void sme_update_vdev_type_nss(tHalHandle hal, uint8_t max_supp_nss,
		uint32_t vdev_type_nss, tSirRFBand band);
void sme_update_hw_dbs_capable(tHalHandle hal, uint8_t hw_dbs_capable);
void sme_register_p2p_lo_event(tHalHandle hHal, void *context,
					p2p_lo_callback callback);

QDF_STATUS sme_remove_bssid_from_scan_list(tHalHandle hal,
	tSirMacAddr bssid);

QDF_STATUS sme_process_mac_pwr_dbg_cmd(tHalHandle hal, uint32_t session_id,
				       struct sir_mac_pwr_dbg_cmd*
				       dbg_args);

void sme_get_vdev_type_nss(tHalHandle hal, enum tQDF_ADAPTER_MODE dev_mode,
		uint8_t *nss_2g, uint8_t *nss_5g);
QDF_STATUS sme_roam_set_default_key_index(tHalHandle hal, uint8_t session_id,
					  uint8_t default_idx);
QDF_STATUS sme_register_p2p_ack_ind_callback(tHalHandle hal,
		sir_p2p_ack_ind_callback callback);
void sme_send_disassoc_req_frame(tHalHandle hal, uint8_t session_id, uint8_t
				*peer_mac, uint16_t reason, uint8_t
				wait_for_ack);
QDF_STATUS sme_update_access_policy_vendor_ie(tHalHandle hal,
					uint8_t session_id, uint8_t *vendor_ie,
					int access_policy);

QDF_STATUS sme_update_sta_roam_policy(tHalHandle hal,
		enum sta_roam_policy_dfs_mode dfs_mode,
		bool skip_unsafe_channels,
		uint8_t session_id, uint8_t sap_operating_band);
QDF_STATUS sme_enable_disable_chanavoidind_event(tHalHandle hal,
					uint8_t set_value);
QDF_STATUS sme_set_default_scan_ie(tHalHandle hal, uint16_t session_id,
				uint8_t *ie_data, uint16_t ie_len);
/**
 * sme_update_session_param() - API to update PE session param
 * @hal: HAL handle for device
 * @session_id: Session ID
 * @param_type: Param type to be updated
 * @param_val: Param value to be update
 *
 * Note: this setting will not persist over reboots.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_update_session_param(tHalHandle hal, uint8_t session_id,
		uint32_t param_type, uint32_t param_val);

/**
 * sme_update_fils_setting() - API to update PE FILS setting
 * @hal: HAL handle for device
 * @session_id: Session ID
 * @param_val: Param value to be update
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_update_fils_setting(tHalHandle hal, uint8_t session_id,
				   uint8_t param_val);
#ifdef WLAN_FEATURE_DISA
/**
 * sme_encrypt_decrypt_msg_register_callback() - Registers
 * encrypt/decrypt message callback
 *
 * @hal - MAC global handle
 * @callback_routine - callback routine from HDD
 * @context - callback context
 *
 * This API is invoked by HDD to register its callback in SME
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_encrypt_decrypt_msg_register_callback(tHalHandle hal,
		void (*encrypt_decrypt_cb)(void *cookie,
					   struct sir_encrypt_decrypt_rsp_params
					   *encrypt_decrypt_rsp_params));

/**
 * sme_encrypt_decrypt_msg_deregister_callback() - Registers
 * encrypt/decrypt message callback
 *
 * @h_hal - MAC global handle
 * @callback_routine - callback routine from HDD
 *
 * This API is invoked by HDD to de-register its callback in SME
 *
 * Return: QDF_STATUS Enumeration
 */
QDF_STATUS sme_encrypt_decrypt_msg_deregister_callback(tHalHandle h_hal);

/**
 * sme_encrypt_decrypt_msg() - handles encrypt/decrypt mesaage
 * @hal: HAL handle
 * @encrypt_decrypt_params: struct to set encryption/decryption params.
 *
 * Return: QDF_STATUS enumeration.
 */
QDF_STATUS sme_encrypt_decrypt_msg(tHalHandle hal,
	struct encrypt_decrypt_req_params *encrypt_decrypt_params,
	void *context);
#endif

/**
 * sme_set_cts2self_for_p2p_go() - sme function to set ini parms to FW.
 * @hal:                    reference to the HAL
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_set_cts2self_for_p2p_go(tHalHandle hal);
void sme_set_prefer_80MHz_over_160MHz(tHalHandle hal,
		bool sta_prefer_80MHz_over_160MHz);
void sme_set_allow_adj_ch_bcn(tHalHandle hal, bool allow_adj_ch_bcn);
QDF_STATUS sme_update_tx_fail_cnt_threshold(tHalHandle hal_handle,
		uint8_t session_id, uint32_t tx_fail_count);
QDF_STATUS sme_update_short_retry_limit_threshold(tHalHandle hal_handle,
		struct sme_short_retry_limit *short_retry_limit_th);
QDF_STATUS sme_update_long_retry_limit_threshold(tHalHandle hal_handle,
		struct sme_long_retry_limit  *long_retry_limit_th);
/**
 * sme_set_etsi_srd_ch_in_master_mode() - master mode UNI-III band ch support
 * @hal: HAL pointer
 * @srd_chan_support: ETSI SRD channel support
 *
 * This function set master ETSI SRD channel support
 *
 * Return: None
 */
void sme_set_etsi_srd_ch_in_master_mode(tHalHandle hal,
					bool etsi_srd_chan_support);

/**
 * sme_roam_is_ese_assoc() - Check if association type is ESE
 * @roam_info: Pointer to roam info
 *
 * Return: true if ESE Association, false otherwise.
 */
#ifdef FEATURE_WLAN_ESE
bool sme_roam_is_ese_assoc(tCsrRoamInfo *roam_info);
#else
static inline bool sme_roam_is_ese_assoc(tCsrRoamInfo *roam_info)
{
	return false;
}
#endif
/**
 * sme_neighbor_roam_is11r_assoc() - Check if association type is 11R
 * @hal_ctx: HAL handle
 * @session_id: session id
 *
 * Return: true if 11r Association, false otherwise.
 */
bool sme_neighbor_roam_is11r_assoc(tHalHandle hal_ctx, uint8_t session_id);
/**
 * sme_update_sta_inactivity_timeout(): Update sta_inactivity_timeout to FW
 * @hal: Handle returned by mac_open
 * @sta_inactivity_timer:  struct for sta inactivity timer
 *
 * If a station does not send anything in sta_inactivity_timeout seconds, an
 * empty data frame is sent to it in order to verify whether it is
 * still in range. If this frame is not ACKed, the station will be
 * disassociated and then deauthenticated.
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure.
*/
QDF_STATUS sme_update_sta_inactivity_timeout(tHalHandle hal_handle,
		struct sme_sta_inactivity_timeout  *sta_inactivity_timer);

/**
 * sme_set_lost_link_info_cb() - plug in callback function for receiving
 * @hal: HAL handle
 * @cb: callback function
 *
 * Return: HAL status
 */
QDF_STATUS sme_set_lost_link_info_cb(tHalHandle hal,
		void (*cb)(void *, struct sir_lost_link_info *));

#ifdef WLAN_POWER_DEBUGFS
QDF_STATUS sme_power_debug_stats_req(tHalHandle hal, void (*callback_fn)
				(struct  power_stats_response *response,
				void *context), void *power_stats_context);
#endif

/**
 * sme_get_sar_power_limits() - get SAR limits
 * @hal: HAL handle
 * @callback: Callback function to invoke with the results
 * @context: Opaque context to pass back to caller in the callback
 *
 * Return: QDF_STATUS_SUCCESS if the request is successfully sent
 * to firmware for processing, otherwise an error status.
 */
QDF_STATUS sme_get_sar_power_limits(tHalHandle hal,
				    wma_sar_cb callback, void *context);

/**
 * sme_set_sar_power_limits() - set sar limits
 * @hal: HAL handle
 * @sar_limit_cmd: struct to send sar limit cmd.
 *
 * Return: QDF_STATUS enumeration.
 */
QDF_STATUS sme_set_sar_power_limits(tHalHandle hal,
				    struct sar_limit_cmd_params *sar_limit_cmd);

/**
 * sme_send_coex_config_cmd() - Send COEX config params
 * @coex_cfg_params: struct to coex config params
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_send_coex_config_cmd(struct coex_config_params *coex_cfg_params);

void sme_set_cc_src(tHalHandle hal_handle, enum country_src);


#ifdef WLAN_FEATURE_WOW_PULSE
QDF_STATUS sme_set_wow_pulse(struct wow_pulse_mode *wow_pulse_set_info);
#endif
/* ARP DEBUG STATS */
QDF_STATUS sme_set_nud_debug_stats(tHalHandle hal,
				   struct set_arp_stats_params
				   *set_stats_param);
QDF_STATUS sme_get_nud_debug_stats(tHalHandle hal,
				   struct get_arp_stats_params
				   *get_stats_param);
QDF_STATUS sme_set_nud_debug_stats_cb(tHalHandle hal,
			void (*cb)(void *, struct rsp_stats *, void *context),
			void *context);


#ifdef WLAN_FEATURE_UDP_RESPONSE_OFFLOAD
QDF_STATUS sme_set_udp_resp_offload(struct udp_resp_offload *pudp_resp_cmd);
#else
static inline QDF_STATUS sme_set_udp_resp_offload(struct udp_resp_offload
							*pudp_resp_cmd)
{
	return QDF_STATUS_E_FAILURE;
}
#endif

/**
 * sme_get_rcpi() - gets the rcpi value for peer mac addr
 * @hal: handle returned by mac_open
 * @rcpi: rcpi request containing peer mac addr, callback and related info
 *
 * This function posts the rcpi measurement request message to wma queue
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_get_rcpi(tHalHandle hal, struct sme_rcpi_req *rcpi);

/**
 * sme_get_rssi_snr_by_bssid() - gets the rssi and snr by bssid from scan cache
 * @hal: handle returned by mac_open
 * @profile: current connected profile
 * @bssid: bssid to look for in scan cache
 * @rssi: rssi value found
 * @snr: snr value found
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_get_rssi_snr_by_bssid(tHalHandle hal, tCsrRoamProfile *profile,
				     const uint8_t *bssid, int8_t *rssi,
				     int8_t *snr);

/**
 * sme_get_beacon_frm() - gets the bss descriptor from scan cache and prepares
 * beacon frame
 * @hal: handle returned by mac_open
 * @profile: current connected profile
 * @bssid: bssid to look for in scan cache
 * @frame_buf: frame buffer to populate
 * @frame_len: length of constructed frame
 * @channel: Pointer to channel info to be filled
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_get_beacon_frm(tHalHandle hal, tCsrRoamProfile *profile,
			    const tSirMacAddr bssid,
			    uint8_t **frame_buf, uint32_t *frame_len,
			    int *channel);

/**
 * sme_rso_cmd_status_cb() - Set RSO cmd status callback
 * @hal: HAL Handle
 * @cb: HDD Callback to rso comman status read
 *
 * This function is used to save HDD RSO Command status callback in MAC
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_rso_cmd_status_cb(tHalHandle hal,
		void (*cb)(void *, struct rso_cmd_status *));

void sme_set_5g_band_pref(tHalHandle hal_handle,
			  struct sme_5g_band_pref_params *pref_params);

/**
 * sme_set_bt_activity_info_cb - set the callback handler for bt events
 * @hal: handle returned by mac_open
 * @cb: callback handler
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_set_bt_activity_info_cb(tHalHandle hal,
				void (*cb)(void *, uint32_t profile_info));

/**
 * sme_congestion_register_callback(): registers congestion callback
 * @hal: handler for HAL
 * @congestion_cb: congestion callback
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_congestion_register_callback(tHalHandle hal,
	void (*congestion_cb)(void *, uint32_t congestion, uint32_t vdev_id));

/**
 * sme_scan_get_result_for_bssid - gets the scan result from scan cache for the
 *	bssid specified
 * @hal: handle returned by mac_open
 * @bssid: bssid to get the scan result for
 *
 * Return: tCsrScanResultInfo * or NULL if no result
 */
tCsrScanResultInfo *sme_scan_get_result_for_bssid(tHalHandle hal_handle,
						  struct qdf_mac_addr *bssid);

QDF_STATUS sme_delete_all_tdls_peers(tHalHandle hal, uint8_t session_id,
		bool disable_tdls_state);

/**
 * sme_set_random_mac() - Set random mac address filter
 * @hal: hal handle for getting global mac struct
 * @callback: callback to be invoked for response from firmware
 * @session_id: interface id
 * @random_mac: random mac address to be set
 * @freq: Channel frequency
 * @context: parameter to callback
 *
 * This function is used to set random mac address filter for action frames
 * which are send with the same address, callback is invoked when corresponding
 * event from firmware has come.
 *
 * Return: eHalStatus enumeration.
 */
QDF_STATUS sme_set_random_mac(tHalHandle hal,
			      action_frame_random_filter_callback callback,
			      uint32_t session_id, uint8_t *random_mac,
			      uint32_t freq, void *context);

/**
 * sme_clear_random_mac() - clear random mac address filter
 * @hal: HAL handle
 * @session_id: interface id
 * @random_mac: random mac address to be cleared
 * @freq: Channel frequency
 *
 * This function is used to clear the randmom mac address filters
 * which are set with sme_set_random_mac
 *
 * Return: QDF_STATUS enumeration.
 */
QDF_STATUS sme_clear_random_mac(tHalHandle hal, uint32_t session_id,
				uint8_t *random_mac, uint32_t freq);

/**
 * sme_set_chip_pwr_save_fail_cb() - set chip power save failure callback
 * @hal: global hal handle
 * @cb: callback function pointer
 *
 * This function stores the chip power save failure callback function.
 *
 * Return: QDF_STATUS enumeration.
 */
QDF_STATUS sme_set_chip_pwr_save_fail_cb(tHalHandle hal, void (*cb)(void *,
				 struct chip_pwr_save_fail_detected_params *));
/**
 * sme_get_chain_rssi - sme api to get chain rssi
 * @phal: global hal handle
 * @input: get chain rssi req params
 *
 * Return: QDF_STATUS enumeration.
 */
QDF_STATUS sme_get_chain_rssi(tHalHandle phal,
	struct get_chain_rssi_req_params *input);

/**
 * sme_chain_rssi_register_callback - chain rssi callback
 * @phal: global hal handle
 * @pchain_rssi_ind_cb: callback function pointer
 * @context: callback context
 *
 * Return: QDF_STATUS enumeration.
 */
QDF_STATUS
sme_chain_rssi_register_callback(tHalHandle phal,
				 void (*pchain_rssi_ind_cb)(void *ctx,
							    void *pmsg,
							    void *context),
				 void *context);

/**
 * sme_chain_rssi_deregister_callback() - De-register chain rssi callback
 * @hal: global hal handle
 *
 * This function De-registers the scandone callback  to SME
 *
 * Return: None
 */
void sme_chain_rssi_deregister_callback(tHalHandle hal);

/**
 * sme_process_msg_callback() - process callback message from LIM
 * @hal: global hal handle
 * @msg: cds message
 *
 * This function process the callback messages from LIM.
 *
 * Return: QDF_STATUS enumeration.
 */
QDF_STATUS sme_process_msg_callback(tHalHandle hal, cds_msg_t *msg);

/**
 * sme_set_dbs_scan_selection_config() - Update DBS scan selection
 * configuration
 * @hal: The handle returned by macOpen
 * @params: wmi_dbs_scan_sel_params config
 *
 * Return: QDF_STATUS if DBS scan selection update
 * configuration success else failure status
 */
QDF_STATUS sme_set_dbs_scan_selection_config(tHalHandle hal,
		struct wmi_dbs_scan_sel_params *params);

/**
 * sme_set_reorder_timeout() - set reorder timeout value
 * including Voice,Video,Besteffort,Background parameters
 * @hal: hal handle for getting global mac struct
 * @reg: struct sir_set_rx_reorder_timeout_val
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure.
 */
QDF_STATUS sme_set_reorder_timeout(tHalHandle hal,
		struct sir_set_rx_reorder_timeout_val *req);

/**
 * sme_set_rx_set_blocksize() - set blocksize value
 * including mac_addr and win_limit parameters
 * @hal: hal handle for getting global mac struct
 * @reg: struct sir_peer_set_rx_blocksize
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure.
 */

QDF_STATUS sme_set_rx_set_blocksize(tHalHandle hal,
		struct sir_peer_set_rx_blocksize *req);
/**
 * sme_ipa_uc_stat_request() - set ipa config parameters
 * @vdev_id: virtual device for the command
 * @param_id: parameter id
 * @param_val: parameter value
 * @req_cat: parameter category
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure
 */
QDF_STATUS sme_ipa_uc_stat_request(tHalHandle hal,
			uint32_t vdev_id, uint32_t param_id,
			uint32_t param_val, uint32_t req_cat);

/**
 * sme_set_smps_cfg() - set SMPS config params
 * @vdev_id: virtual device for the command
 * @param_id: parameter id
 * @param_val: parameter value
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure
 */

QDF_STATUS sme_set_smps_cfg(uint32_t vdev_id, uint32_t param_id,
				uint32_t param_val);

/**
 * sme_get_peer_stats() - sme api to post peer info request
 * @mac: mac handle
 * @req: peer info request struct send to wma
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure
 */
QDF_STATUS sme_get_peer_stats(tpAniSirGlobal mac,
			      struct sir_peer_info_req req);

/**
 * sme_get_peer_info() - sme api to get peer info
 * @hal: hal handle for getting global mac struct
 * @req: peer info request struct send to wma
 * @context: context of callback function
 * @callbackfn: hdd callback function when receive response
 *
 * This function will send WMA_GET_PEER_INFO to WMA
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure
 */
QDF_STATUS sme_get_peer_info(tHalHandle hal,
		struct sir_peer_info_req req,
		void *context,
		void (*callbackfn)(struct sir_peer_info_resp *param,
			void *pcontext));

/**
 * sme_get_peer_info_ext() - sme api to get peer ext info
 * @hal: hal handle for getting global mac struct
 * @req: peer ext info request struct send to wma
 * @context: context of callback function
 * @callbackfn: hdd callback function when receive response
 *
 * This function will send WMA_GET_PEER_INFO_EXT to WMA
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure
 */
QDF_STATUS sme_get_peer_info_ext(tHalHandle hal,
		struct sir_peer_info_ext_req *req,
		void *context,
		void (*callbackfn)(struct sir_peer_info_ext_resp *param,
			void *pcontext));

/**
 * sme_cli_set_command() - SME wrapper API over WMA "set" command
 * processor cmd
 * @vdev_id: virtual device for the command
 * @param_id: parameter id
 * @sval: parameter value
 * @vpdev: parameter category
 *
 * Command handler for set operations
 *
 * Return: 0 on success, errno on failure
 */
int sme_cli_set_command(int vdev_id, int param_id, int sval, int vpdev);

/*
 * sme_set_chan_info_callback() - set scan chan info call back
 * @hal: Handle returned by mac_open
 * @callback: scan chan info call back
 *
 * This function is used to set scan chan info call back.
 *
 * Return: None
 */
void sme_set_chan_info_callback(tHalHandle hal_handle,
			void (*callback)(struct scan_chan_info *chan_info));

/**
 * sme_set_bmiss_bcnt() - set bmiss config parameters
 * @vdev_id: virtual device for the command
 * @first_cnt: bmiss first value
 * @final_cnt: bmiss final value
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure
 */
QDF_STATUS sme_set_bmiss_bcnt(uint32_t vdev_id, uint32_t first_cnt,
		uint32_t final_cnt);

/**
 * sme_set_del_pmkid_cache() - API to update PMKID cache
 * @hal: HAL handle for device
 * @session_id: Session id
 * @pmk_cache_info: Pointer to PMK cache info
 * @is_add: boolean that implies whether to add or delete PMKID entry
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_set_del_pmkid_cache(tHalHandle hal, uint8_t session_id,
				   tPmkidCacheInfo *pmk_cache_info,
				   bool is_add);
/**
 * sme_set_action_oui_ext() - set action oui extensions in pmac
 * @hal: hal global context
 * @wmi_ext: pointer to oui extension to be stored
 * @action_id: action for which @wmi_ext is meant
 *
 * Return: if set is success return QDF_STATUS_SUCCESS
 *         else QDF_STATUS_E_INVAL or QDF_STATUS_E_NOMEM
 */
QDF_STATUS sme_set_action_oui_ext(tHalHandle hal,
				  struct wmi_action_oui_extension *wmi_ext,
				  enum wmi_action_oui_id action_id);
/**
 * sme_send_action_oui() - send action oui extensions to wma
 * @hal: hal global context
 * @action_id: action for which oui extensions need to be send to wma
 *
 * Return: if set is success return QDF_STATUS_SUCCESS
 *         else QDF_STATUS_E_INVAL or QDF_STATUS_E_NOMEM
 */
QDF_STATUS sme_send_action_oui(tHalHandle hal,
			enum wmi_action_oui_id action_id);

/**
 * sme_send_hlp_ie_info() - API to send HLP IE info to fw
 * @hal: HAL handle for device
 * @session_id: Session id
 * @profile: CSR Roam profile
 * @if_addr: IP address
 *
 * This API is used to send HLP IE info along with IP address
 * to fw if LFR3 is enabled.
 *
 * Return: QDF_STATUS
 */
void sme_send_hlp_ie_info(tHalHandle hal, uint8_t session_id,
			  tCsrRoamProfile *profile, uint32_t if_addr);

#if defined(WLAN_FEATURE_FILS_SK)
/**
 * sme_update_fils_config - Update FILS config to CSR roam session
 * @hal: HAL handle for device
 * @session_id: session id
 * @src_profile: Source profile having latest FILS config
 *
 * API to update FILS config to roam csr session and update the same
 * to fw if LFR3 is enabled.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_update_fils_config(tHalHandle hal, uint8_t session_id,
				tCsrRoamProfile *src_profile);

/**
 * sme_free_join_rsp_fils_params - free fils params
 * @roam_info: roam info
 *
 * Return: void
 */
void sme_free_join_rsp_fils_params(tCsrRoamInfo *roam_info);
#else
static inline QDF_STATUS sme_update_fils_config(tHalHandle hal,
				uint8_t session_id,
				tCsrRoamProfile *src_profile)
{
	return QDF_STATUS_SUCCESS;
}
static inline void sme_free_join_rsp_fils_params(tCsrRoamInfo *roam_info)
{}
#endif
/**
 * sme_display_disconnect_stats() - Display per session Disconnect stats
 * @hal: hal global context
 * session_id: SME session id
 *
 * Return: None
 */
void sme_display_disconnect_stats(tHalHandle hal, uint8_t session_id);

/**
 * sme_set_vc_mode_config() - Set voltage corner config to FW.
 * @bitmap:	Bitmap that refers to voltage corner config with
 * different phymode and bw configuration
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_set_vc_mode_config(uint32_t vc_bitmap);

/*
 * sme_send_limit_off_channel_params() - send limit off channel parameters
 * @hal: global hal handle
 * @vdev_id: vdev id
 * @is_tos_active: tos active or inactive
 * @max_off_chan_time: max off channel time
 * @rest_time: rest time
 * @skip_dfs_chan: skip dfs channel
 *
 * This function sends command to WMA for setting limit off channel command
 * parameters.
 *
 * Return: QDF_STATUS enumeration.
 */
QDF_STATUS sme_send_limit_off_channel_params(tHalHandle hal, uint8_t vdev_id,
		bool is_tos_active, uint32_t max_off_chan_time,
		uint32_t rest_time, bool skip_dfs_chan);

/**
 * sme_is_conn_state_connected() -- check if SME connection state is connected
 * @hal: global hal handle
 * @session_id: current Session Id
 *
 * This API checks if the current SME connection state is connected for the
 * given session id.
 *
 * Return: True if connected, false if any other state.
 */
bool sme_is_conn_state_connected(tHalHandle hal, uint8_t session_id);

/**
 * sme_fast_reassoc() - invokes FAST REASSOC command
 * @hal: handle returned by mac_open
 * @profile: current connected profile
 * @bssid: bssid to look for in scan cache
 * @channel: channel on which reassoc should be send
 * @vdev_id: vdev id
 * @connected_bssid: bssid of currently connected profile
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_fast_reassoc(tHalHandle hal, tCsrRoamProfile *profile,
			    const tSirMacAddr bssid, int channel,
			    uint8_t vdev_id, const tSirMacAddr connected_bssid);

/**
 * sme_enable_roaming_on_connected_sta() - Enable roaming on an connected sta
 * @hal: handle returned by mac_open
 *
 * The function check if any connected STA is present on which roaming is not
 * enabled and if present enabled roaming on that STA.
 *
 * Return: none
 */
void sme_enable_roaming_on_connected_sta(tHalHandle hal);

/**
 * sme_unpack_rsn_ie: wrapper to unpack RSN IE and update def RSN params
 * if optional fields are not present.
 * @hal: handle returned by mac_open
 * @buf: rsn ie buffer pointer
 * @buf_len: rsn ie buffer length
 * @rsn_ie: outframe rsn ie structure
 * @append_ie: flag to indicate if the rsn_ie need to be appended from buf
 *
 * Return: parse status
 */
uint32_t sme_unpack_rsn_ie(tHalHandle hal, uint8_t *buf,
			   uint8_t buf_len, tDot11fIERSN *rsn_ie,
			   bool append_ie);

/**
 * sme_is_sta_key_exchange_in_progress() - checks whether the STA/P2P client
 * session has key exchange in progress
 *
 * @hal: global hal handle
 * @session_id: session id
 *
 * Return: true - if key exchange in progress
 *         false - if not in progress
 */
bool sme_is_sta_key_exchange_in_progress(tHalHandle hal, uint8_t session_id);

/**
 * sme_send_mgmt_tx() - Sends mgmt frame from CSR to LIM
 * @hal: The handle returned by mac_open
 * @session_id: session id
 * @buf: pointer to frame
 * @len: frame length
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_send_mgmt_tx(tHalHandle hal, uint8_t session_id,
			   const uint8_t *buf, uint32_t len);

#ifdef WLAN_FEATURE_SAE
/**
 * sme_handle_sae_msg() - Sends SAE message received from supplicant
 * @hal: The handle returned by mac_open
 * @session_id: session id
 * @sae_status: status of SAE authentication
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_handle_sae_msg(tHalHandle hal, uint8_t session_id,
		uint8_t sae_status);
#else
static inline QDF_STATUS sme_handle_sae_msg(tHalHandle hal, uint8_t session_id,
		uint8_t sae_status)
{
	return QDF_STATUS_SUCCESS;
}
#endif

/**
 * sme_get_roam_scan_stats() - Send roam scan stats cmd to wma
 * @hal: handle returned by mac_open
 * @cb: call-back invoked for roam scan stats response
 * @context: context of callback
 * @vdev_id: vdev id
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
sme_get_roam_scan_stats(tHalHandle hal, roam_scan_stats_cb cb, void *context,
			uint32_t vdev_id);

/**
 * sme_get_scan_id() - Sme wrapper to get scan ID
 * @scan_id: output pointer to hold scan_id
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_get_scan_id(uint32_t *scan_id);

/*
 * sme_validate_channel_list() - Validate the given channel list
 * @hal: handle to global hal context
 * @chan_list: Pointer to the channel list
 * @num_channels: number of channels present in the chan_list
 *
 * Validates the given channel list with base channels in mac context
 *
 * Return: True if all channels in the list are valid, false otherwise
 */
bool sme_validate_channel_list(tHalHandle hal,
				      uint8_t *chan_list,
				      uint8_t num_channels);
=======
 * Return: QDF_STATUS enumeration.
 */
QDF_STATUS sme_apf_write_work_memory(mac_handle_t mac_handle,
				    struct wmi_apf_write_memory_params
								*write_params);

/**
 * sme_apf_read_work_memory - Read part of apf work memory
 * @mac_handle: Opaque handle to the global MAC context
 * @read_params: APF parameters for the get operation
 * @callback: callback to handle the the read response
 *
 * API for issuing a APF read memory request.
 *
 * Return: QDF_STATUS enumeration.
 */
QDF_STATUS
sme_apf_read_work_memory(mac_handle_t mac_handle,
			 struct wmi_apf_read_memory_params *read_params,
			 apf_read_mem_cb callback);

#endif /* FEATURE_WLAN_APF */

uint32_t sme_get_wni_dot11_mode(mac_handle_t mac_handle);
QDF_STATUS sme_create_mon_session(mac_handle_t mac_handle, uint8_t *bssid,
				  uint8_t vdev_id);

/**
 * sme_delete_mon_session() - post message to delete PE session for mon_mode
 * operation
 * @mac_handle: Opaque handle to the global MAC context
 * @vdev_id: sme session id
 *
 * Return: QDF_STATUS_SUCCESS on success, non-zero error code on failure.
 */
QDF_STATUS sme_delete_mon_session(mac_handle_t mac_handle, uint8_t vdev_id);

/**
 * sme_set_vdev_ies_per_band() - sends the per band IEs to vdev
 * @mac_handle: Opaque handle to the global MAC context
 * @vdev_id: vdev_id for which IE is targeted
 * @device_mode: vdev mode
 *
 * Return: None
 */
void sme_set_vdev_ies_per_band(mac_handle_t mac_handle, uint8_t vdev_id,
			       enum QDF_OPMODE device_mode);

void sme_set_pdev_ht_vht_ies(mac_handle_t mac_handle, bool enable2x2);

/**
 * sme_update_vdev_type_nss() - sets the nss per vdev type
 * @mac_handle: Opaque handle to the global MAC context
 * @max_supp_nss: max_supported Nss
 * @band: 5G or 2.4G band
 *
 * Sets the per band Nss for each vdev type based on INI and configured
 * chain mask value.
 *
 * Return: None
 */
void sme_update_vdev_type_nss(mac_handle_t mac_handle, uint8_t max_supp_nss,
			      enum nss_chains_band_info band);

#ifdef FEATURE_P2P_LISTEN_OFFLOAD
void sme_register_p2p_lo_event(mac_handle_t mac_handle, void *context,
					p2p_lo_callback callback);
#else
static inline void sme_register_p2p_lo_event(mac_handle_t mac_handle,
					     void *context,
					     p2p_lo_callback callback)
{
}
#endif

QDF_STATUS sme_remove_bssid_from_scan_list(mac_handle_t mac_handle,
	tSirMacAddr bssid);

QDF_STATUS sme_process_mac_pwr_dbg_cmd(mac_handle_t mac_handle,
				       uint32_t session_id,
				       struct sir_mac_pwr_dbg_cmd*
				       dbg_args);

void sme_get_vdev_type_nss(enum QDF_OPMODE dev_mode,
			   uint8_t *nss_2g, uint8_t *nss_5g);
QDF_STATUS sme_roam_set_default_key_index(mac_handle_t mac_handle,
					  uint8_t session_id,
					  uint8_t default_idx);
void sme_send_disassoc_req_frame(mac_handle_t mac_handle,
				 uint8_t session_id, uint8_t *peer_mac,
				 uint16_t reason, uint8_t wait_for_ack);
QDF_STATUS sme_update_access_policy_vendor_ie(mac_handle_t mac_handle,
					      uint8_t session_id,
					      uint8_t *vendor_ie,
					      int access_policy);

/**
 * sme_set_peer_param() - set peer param
 * @vdev_id: vdev ID
 * @peer_addr: peer MAC address
 * @param_id: param ID to be updated
 * @param_Value: paraam value
 *
 * This SME API is used to send the peer param to WMA to be sent to FW.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_set_peer_param(uint8_t *peer_addr, uint32_t param_id,
			      uint32_t param_value, uint32_t vdev_id);

QDF_STATUS sme_update_sta_roam_policy(mac_handle_t mac_handle,
		enum sta_roam_policy_dfs_mode dfs_mode,
		bool skip_unsafe_channels,
		uint8_t session_id, uint8_t sap_operating_band);
QDF_STATUS sme_enable_disable_chanavoidind_event(mac_handle_t mac_handle,
					uint8_t set_value);
QDF_STATUS sme_set_default_scan_ie(mac_handle_t mac_handle, uint16_t session_id,
				uint8_t *ie_data, uint16_t ie_len);
/**
 * sme_update_session_param() - API to update PE session param
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: Session ID
 * @param_type: Param type to be updated
 * @param_val: Param value to be update
 *
 * Note: this setting will not persist over reboots.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_update_session_param(mac_handle_t mac_handle, uint8_t session_id,
		uint32_t param_type, uint32_t param_val);
#ifdef WLAN_FEATURE_FIPS
/**
 * sme_fips_request() - Perform a FIPS certification operation
 * @mac_handle: Opaque handle to the global MAC context
 * @param: The FIPS certification parameters
 * @callback: Callback function to invoke with the results
 * @context: Opaque context to pass back to caller in the callback
 *
 * Return: QDF_STATUS_SUCCESS if the request is successfully sent
 * to firmware for processing, otherwise an error status.
 */
QDF_STATUS sme_fips_request(mac_handle_t mac_handle, struct fips_params *param,
			    wma_fips_cb callback, void *context);
#else
static inline
QDF_STATUS sme_fips_request(mac_handle_t mac_handle, struct fips_params *param,
			    wma_fips_cb callback, void *context)
{
	return QDF_STATUS_E_NOSUPPORT;
}
#endif /* WLAN_FEATURE_FIPS */

/**
 * sme_set_cts2self_for_p2p_go() - sme function to set ini parms to FW.
 * @mac_handle: Opaque handle to the global MAC context
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_set_cts2self_for_p2p_go(mac_handle_t mac_handle);

QDF_STATUS sme_update_tx_fail_cnt_threshold(mac_handle_t mac_handle,
		uint8_t session_id, uint32_t tx_fail_count);

/**
 * sme_roam_is_ese_assoc() - Check if association type is ESE
 * @roam_info: Pointer to roam info
 *
 * Return: true if ESE Association, false otherwise.
 */
#ifdef FEATURE_WLAN_ESE
bool sme_roam_is_ese_assoc(struct csr_roam_info *roam_info);
#else
static inline bool sme_roam_is_ese_assoc(struct csr_roam_info *roam_info)
{
	return false;
}
#endif
/**
 * sme_neighbor_roam_is11r_assoc() - Check if association type is 11R
 * @mac_handle: MAC_HANDLE handle
 * @session_id: session id
 *
 * Return: true if 11r Association, false otherwise.
 */
bool sme_neighbor_roam_is11r_assoc(mac_handle_t mac_handle, uint8_t session_id);

/**
 * sme_update_sta_inactivity_timeout(): Update sta_inactivity_timeout to FW
 * @mac_handle: Handle returned by mac_open
 * @sta_inactivity_timer:  struct for sta inactivity timer
 *
 * If a station does not send anything in sta_inactivity_timeout seconds, an
 * empty data frame is sent to it in order to verify whether it is
 * still in range. If this frame is not ACKed, the station will be
 * disassociated and then deauthenticated.
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure.
*/
QDF_STATUS sme_update_sta_inactivity_timeout(mac_handle_t mac_handle,
		struct sme_sta_inactivity_timeout  *sta_inactivity_timer);

/**
 * sme_set_lost_link_info_cb() - plug in callback function for receiving
 * @mac_handle: Opaque handle to the MAC context
 * @cb: callback function
 *
 * Return: HAL status
 */
QDF_STATUS sme_set_lost_link_info_cb(mac_handle_t mac_handle,
				     lost_link_info_cb cb);

/**
 * sme_update_new_channel_event() - update new channel event for sapFsm
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: session id
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure.
 */
QDF_STATUS sme_update_new_channel_event(mac_handle_t mac_handle,
					uint8_t session_id);
#ifdef WLAN_POWER_DEBUG
QDF_STATUS sme_power_debug_stats_req(
		mac_handle_t mac_handle,
		void (*callback_fn)(struct power_stats_response *response,
				    void *context),
		void *power_stats_context);
#endif

#ifdef WLAN_FEATURE_BEACON_RECEPTION_STATS
/**
 * sme_beacon_debug_stats_req() - SME API to collect beacon debug stats
 * @vdev_id: Vdev id on which stats is being requested
 * @callback_fn: Pointer to the callback function for beacon stats event
 * @beacon_stats_context: Pointer to context
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_beacon_debug_stats_req(
		mac_handle_t mac_handle, uint32_t vdev_id,
		void (*callback_fn)(struct bcn_reception_stats_rsp
				    *response, void *context),
		void *beacon_stats_context);
#endif

/**
 * sme_get_sar_power_limits() - get SAR limits
 * @mac_handle: Opaque handle to the global MAC context
 * @callback: Callback function to invoke with the results
 * @context: Opaque context to pass back to caller in the callback
 *
 * Return: QDF_STATUS_SUCCESS if the request is successfully sent
 * to firmware for processing, otherwise an error status.
 */
QDF_STATUS sme_get_sar_power_limits(mac_handle_t mac_handle,
				    wma_sar_cb callback, void *context);

/**
 * sme_set_sar_power_limits() - set sar limits
 * @mac_handle: Opaque handle to the global MAC context
 * @sar_limit_cmd: struct to send sar limit cmd.
 *
 * Return: QDF_STATUS enumeration.
 */
QDF_STATUS sme_set_sar_power_limits(mac_handle_t mac_handle,
		struct sar_limit_cmd_params *sar_limit_cmd);

/**
 * sme_send_coex_config_cmd() - Send COEX config params
 * @coex_cfg_params: struct to coex config params
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_send_coex_config_cmd(struct coex_config_params *coex_cfg_params);

void sme_set_cc_src(mac_handle_t mac_handle, enum country_src);


#ifdef WLAN_FEATURE_WOW_PULSE
QDF_STATUS sme_set_wow_pulse(struct wow_pulse_mode *wow_pulse_set_info);
#endif

/* ARP DEBUG STATS */
QDF_STATUS sme_set_nud_debug_stats(mac_handle_t mac_handle,
				   struct set_arp_stats_params
				   *set_stats_param);
QDF_STATUS sme_get_nud_debug_stats(mac_handle_t mac_handle,
				   struct get_arp_stats_params
				   *get_stats_param);
QDF_STATUS sme_set_nud_debug_stats_cb(mac_handle_t mac_handle,
			void (*cb)(void *, struct rsp_stats *, void *context),
			void *context);

/**
 * sme_set_del_peers_ind_callback() - Register del peers ind callback
 * @mac_handle - MAC global handle
 * @callback_routine - callback routine from HDD
 *
 * This API is invoked by HDD to register its callback to mac
 *
 * Return: QDF_STATUS
 */
void
sme_set_del_peers_ind_callback(mac_handle_t mac_handle,
			       void (*callback)(struct wlan_objmgr_psoc *psoc,
						uint8_t vdev_id));

/**
 * sme_set_chan_info_callback() - Register chan info callback
 * @mac_handle - MAC global handle
 * @callback_routine - callback routine from HDD
 *
 * This API is invoked by HDD to register its callback to mac
 *
 * Return: QDF_STATUS
 */
void sme_set_chan_info_callback(mac_handle_t mac_handle,
			void (*callback)(struct scan_chan_info *chan_info));

/**
 * sme_get_rssi_snr_by_bssid() - gets the rssi and snr by bssid from scan cache
 * @mac_handle: handle returned by mac_open
 * @profile: current connected profile
 * @bssid: bssid to look for in scan cache
 * @rssi: rssi value found
 * @snr: snr value found
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_get_rssi_snr_by_bssid(mac_handle_t mac_handle,
				     struct csr_roam_profile *profile,
				     const uint8_t *bssid, int8_t *rssi,
				     int8_t *snr);

/**
 * sme_get_beacon_frm() - gets the bss descriptor from scan cache and prepares
 * beacon frame
 * @mac_handle: handle returned by mac_open
 * @profile: current connected profile
 * @bssid: bssid to look for in scan cache
 * @frame_buf: frame buffer to populate
 * @frame_len: length of constructed frame
 * @ch_freq: Pointer to channel freq info to be filled
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_get_beacon_frm(mac_handle_t mac_handle,
			      struct csr_roam_profile *profile,
			      const tSirMacAddr bssid,
			      uint8_t **frame_buf, uint32_t *frame_len,
			      uint32_t *ch_freq);

#ifdef WLAN_FEATURE_ROAM_OFFLOAD
/**
 * sme_fast_reassoc() - invokes FAST REASSOC command
 * @mac_handle: handle returned by mac_open
 * @profile: current connected profile
 * @bssid: bssid to look for in scan cache
 * @ch_freq: channel on which reassoc should be send
 * @vdev_id: vdev id
 * @connected_bssid: bssid of currently connected profile
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_fast_reassoc(mac_handle_t mac_handle,
			    struct csr_roam_profile *profile,
			    const tSirMacAddr bssid, uint32_t ch_freq,
			    uint8_t vdev_id, const tSirMacAddr connected_bssid);

/**
 * sme_roam_invoke_nud_fail() - invokes REASSOC command to best available bssid
 * @mac_handle: handle returned by mac_open
 * @vdev_id: vdev id
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_roam_invoke_nud_fail(mac_handle_t mac_handle, uint8_t vdev_id);

#else
static inline
QDF_STATUS sme_fast_reassoc(mac_handle_t mac_handle,
			    struct csr_roam_profile *profile,
			    const tSirMacAddr bssid, uint32_t ch_freq,
			    uint8_t vdev_id, const tSirMacAddr connected_bssid)
{
	return QDF_STATUS_SUCCESS;
}

static inline
QDF_STATUS sme_roam_invoke_nud_fail(mac_handle_t mac_handle, uint8_t vdev_id)
{
	return QDF_STATUS_SUCCESS;
}

#endif

/**
 * sme_register_tx_queue_cb(): Register tx queue callback
 * @mac_handle: Opaque handle for MAC context
 * @tx_queue_cb: Transmit Queues callback
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_register_tx_queue_cb(mac_handle_t mac_handle,
				    tx_queue_cb tx_queue_cb);

/**
 * sme_deregister_tx_queue_cb() - Deregister the tx queue callback
 * @mac_handle: Opaque handle for MAC context
 *
 * Return: QDF status
 */
QDF_STATUS sme_deregister_tx_queue_cb(mac_handle_t mac_handle);

/**
 * sme_rso_cmd_status_cb() - Set RSO cmd status callback
 * @mac_handle: Opaque handle for the MAC context
 * @cb: HDD Callback to rso command status read
 *
 * This function is used to save HDD RSO Command status callback in MAC
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_rso_cmd_status_cb(mac_handle_t mac_handle,
				 rso_cmd_status_cb cb);

/**
 * sme_register_set_connection_info_cb() - Register connection
 * info callback
 * @mac_handle - MAC global handle
 * @set_connection_info_cb - callback routine from HDD to set
 *                   connection info flag
 * @get_connection_info_cb - callback routine from HDD to get
 *                         connection info
 *
 * This API is invoked by HDD to register its callback to mac
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_register_set_connection_info_cb(mac_handle_t mac_handle,
				bool (*set_connection_info_cb)(bool),
				bool (*get_connection_info_cb)(uint8_t *session_id,
				enum scan_reject_states *reason));

/**
 * sme_set_dbs_scan_selection_config() - Update DBS scan selection
 * configuration
 * @mac_handle: The handle returned by macOpen
 * @params: wmi_dbs_scan_sel_params config
 *
 * Return: QDF_STATUS if DBS scan selection update
 * configuration success else failure status
 */
QDF_STATUS sme_set_dbs_scan_selection_config(mac_handle_t mac_handle,
		struct wmi_dbs_scan_sel_params *params);

/**
 * sme_store_pdev() - store pdev
 * @mac_handle - MAC global handle
 * @pdev - pdev ptr
 *
 * Return: QDF_STATUS
 */
void sme_store_pdev(mac_handle_t mac_handle, struct wlan_objmgr_pdev *pdev);

/**
 * sme_set_reorder_timeout() - set reorder timeout value
 * including Voice,Video,Besteffort,Background parameters
 * @mac_handle: Opaque handle to the global MAC context
 * @reg: struct sir_set_rx_reorder_timeout_val
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure.
 */
QDF_STATUS sme_set_reorder_timeout(mac_handle_t mac_handle,
		struct sir_set_rx_reorder_timeout_val *req);

/**
 * sme_set_rx_set_blocksize() - set blocksize value
 * including mac_addr and win_limit parameters
 * @mac_handle: Opaque handle to the global MAC context
 * @reg: struct sir_peer_set_rx_blocksize
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure.
 */

QDF_STATUS sme_set_rx_set_blocksize(mac_handle_t mac_handle,
				    struct sir_peer_set_rx_blocksize *req);

/**
 * sme_get_rcpi() - gets the rcpi value for peer mac addr
 * @mac_handle: handle returned by mac_open
 * @rcpi: rcpi request containing peer mac addr, callback and related info
 *
 * This function posts the rcpi measurement request message to wma queue
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_get_rcpi(mac_handle_t mac_handle, struct sme_rcpi_req *rcpi);

/**
 * sme_set_chip_pwr_save_fail_cb() - set chip power save failure callback
 * @mac_handle: opaque handle to the MAC context
 * @cb: callback function pointer
 *
 * This function stores the chip power save failure callback function.
 *
 * Return: QDF_STATUS enumeration.
 */

QDF_STATUS sme_set_chip_pwr_save_fail_cb(mac_handle_t mac_handle,
					 pwr_save_fail_cb cb);
/**
 * sme_cli_set_command() - SME wrapper API over WMA "set" command
 * processor cmd
 * @vdev_id: virtual device for the command
 * @param_id: parameter id
 * @sval: parameter value
 * @vpdev: parameter category
 *
 * Command handler for set operations
 *
 * Return: 0 on success, errno on failure
 */
int sme_cli_set_command(int vdev_id, int param_id, int sval, int vpdev);

/**
 * sme_set_bt_activity_info_cb - set the callback handler for bt events
 * @mac_handle: handle returned by mac_open
 * @cb: callback handler
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_set_bt_activity_info_cb(mac_handle_t mac_handle,
				       bt_activity_info_cb cb);

/**
 * sme_set_enable_mem_deep_sleep - set the mem deep sleep config to FW
 * @mac_handle: handle returned by mac_open
 * @vdev_id: vdev id
 *
 * Return: 0 for success else failure code
 */
int sme_set_enable_mem_deep_sleep(mac_handle_t mac_handle, int vdev_id);

/**
 * sme_set_cck_tx_fir_override - set the CCK TX FIR Override to FW
 * @mac_handle: handle returned by mac_open
 * @vdev_id: vdev id
 *
 * Return: 0 for success else failure code
 */
int sme_set_cck_tx_fir_override(mac_handle_t mac_handle, int vdev_id);

/**
 * sme_set_smps_cfg() - set SMPS config params
 * @vdev_id: virtual device for the command
 * @param_id: parameter id
 * @param_val: parameter value
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure
 */

QDF_STATUS sme_set_smps_cfg(uint32_t vdev_id, uint32_t param_id,
				uint32_t param_val);

/**
 * sme_get_peer_info_ext() - sme api to get peer ext info
 * @mac_handle: Opaque handle to the global MAC context
 * @req: peer ext info request struct send to wma
 * @context: context of callback function
 * @callbackfn: hdd callback function when receive response
 *
 * This function will send WMA_GET_PEER_INFO_EXT to WMA
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure
 */
QDF_STATUS sme_get_peer_info_ext(mac_handle_t mac_handle,
		struct sir_peer_info_ext_req *req,
		void *context,
		void (*callbackfn)(struct sir_peer_info_ext_resp *param,
			void *pcontext));

/**
 * sme_get_chain_rssi() - Get chain rssi
 * @mac_handle: Opaque handle to the global MAC context
 * @input: get chain rssi req params
 * @callback: Callback function to be called with the result
 * @context: Opaque context to be used by the caller to associate the
 *   request with the response
 *
 * This function constructs the cds message and fill in message type,
 * post the same to WDA.
 *
 * Return: QDF_STATUS enumeration
 */
QDF_STATUS sme_get_chain_rssi(mac_handle_t mac_handle,
			      struct get_chain_rssi_req_params *input,
			      get_chain_rssi_callback callback,
			      void *context);

/**
 * sme_get_isolation() - sme api to get antenna isolation
 * @mac_handle: hal handle for getting global mac struct
 * @context: context of callback function
 * @callbackfn: hdd callback function when receive response
 *
 * This function will send WMA_GET_ISOLATION to WMA
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure
 */
QDF_STATUS sme_get_isolation(mac_handle_t mac_handle,
			     void *context,
			     sme_get_isolation_cb callbackfn);

#ifdef FEATURE_FW_STATE
/**
 * sme_get_fw_state() - Get fw state
 * @mac_handle: Opaque handle to the global MAC context
 * @callback: Callback function to be called with the result
 * @context: Opaque context to be used by the caller to associate the
 *   request with the response
 *
 * This function constructs the cds message and fill in message type,
 * post the same to WDA.
 *
 * Return: QDF_STATUS enumeration
 */
QDF_STATUS sme_get_fw_state(mac_handle_t mac_handle,
			    fw_state_callback callback,
			    void *context);
#endif /* FEATURE_FW_STATE */

/**
 * sme_get_valid_channels() - sme api to get valid channels for
 * current regulatory domain
 * @ch_freq_list: list of the valid channel frequencies
 * @list_len: length of the channel list
 *
 * This function will get valid channels for current regulatory
 * domain
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure
 */
QDF_STATUS sme_get_valid_channels(uint32_t *ch_freq_list, uint32_t *list_len);

/**
 * sme_get_mac_context() - sme api to get the pmac context
 *
 * This function will return the pmac context
 *
 * Return: pointer to pmac context
 */
struct mac_context *sme_get_mac_context(void);

/**
 * sme_display_disconnect_stats() - Display per session Disconnect stats
 * @mac_handle: Opaque handle to the global MAC context
 * session_id: SME session id
 *
 * Return: None
 */
void sme_display_disconnect_stats(mac_handle_t mac_handle, uint8_t session_id);

/**
 * sme_process_msg_callback() - process callback message from LIM
 * @mac: global mac context
 * @msg: scheduler message
 *
 * This function process the callback messages from LIM.
 *
 * Return: QDF_STATUS enumeration.
 */
QDF_STATUS sme_process_msg_callback(struct mac_context *mac,
				    struct scheduler_msg *msg);

/**
 * sme_set_bmiss_bcnt() - set bmiss config parameters
 * @vdev_id: virtual device for the command
 * @first_cnt: bmiss first value
 * @final_cnt: bmiss final value
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure
 */
QDF_STATUS sme_set_bmiss_bcnt(uint32_t vdev_id, uint32_t first_cnt,
		uint32_t final_cnt);

/**
 * sme_send_limit_off_channel_params() - send limit off channel parameters
 * @mac_handle: Opaque handle to the global MAC context
 * @vdev_id: vdev id
 * @is_tos_active: tos active or inactive
 * @max_off_chan_time: max off channel time
 * @rest_time: rest time
 * @skip_dfs_chan: skip dfs channel
 *
 * This function sends command to WMA for setting limit off channel command
 * parameters.
 *
 * Return: QDF_STATUS enumeration.
 */
QDF_STATUS sme_send_limit_off_channel_params(mac_handle_t mac_handle,
					     uint8_t vdev_id,
					     bool is_tos_active,
					     uint32_t max_off_chan_time,
					     uint32_t rest_time,
					     bool skip_dfs_chan);

#ifdef FEATURE_WLAN_DYNAMIC_CVM
/**
 * sme_set_vc_mode_config() - Set voltage corner config to FW.
 * @bitmap:	Bitmap that refers to voltage corner config with
 * different phymode and bw configuration
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_set_vc_mode_config(uint32_t vc_bitmap);
#endif

/**
 * sme_set_del_pmkid_cache() - API to update PMKID cache
 * @psoc: psoc common object
 * @session_id: Session id
 * @pmk_cache_info: Pointer to PMK cache info
 * @is_add: boolean that implies whether to add or delete PMKID entry
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_set_del_pmkid_cache(struct wlan_objmgr_psoc *psoc,
				   uint8_t session_id,
				   tPmkidCacheInfo *pmk_cache_info,
				   bool is_add);

/**
 * sme_clear_sae_single_pmk_info() - Clear sae_single_pmk onfo
 * @psoc: Psoc object
 * @session_id: session id
 * @pmk_cache_info: pmk cache info
 *
 * This function will clear sae_single_pmk info while processing delete pmk
 * command from userspace.
 *
 * Return: None
 */
void sme_clear_sae_single_pmk_info(struct wlan_objmgr_psoc *psoc,
				   uint8_t session_id,
				   tPmkidCacheInfo *pmk_cache_info);

/**
 * sme_send_hlp_ie_info() - API to send HLP IE info to fw
 * @mac_handle: Opaque handle to the global MAC context
 * @vdev_id: vdev id
 * @profile: CSR Roam profile
 * @if_addr: IP address
 *
 * This API is used to send HLP IE info along with IP address
 * to fw if LFR3 is enabled.
 *
 * Return: None
 */
void sme_send_hlp_ie_info(mac_handle_t mac_handle, uint8_t vdev_id,
			  struct csr_roam_profile *profile, uint32_t if_addr);

/**
 * sme_update_session_assoc_ie() - Updates the assoc IEs to csr_roam_session
 * @mac_handle: Opaque handle to the global MAC context
 * @vdev_id: vdev id
 * @src_profile: Pointer to Roam profile in HDD
 *
 * This API is used to copy the assoc IE sent from user space to
 * csr_roam_session
 *
 * Return: None
 */
void sme_update_session_assoc_ie(mac_handle_t mac_handle,
				 uint8_t vdev_id,
				 struct csr_roam_profile *src_profile);

/**
 * sme_send_rso_connect_params() - Updates the assoc IEs to csr_roam_session
 * @mac_handle: Opaque handle to the global MAC context
 * @vdev_id: vdev id
 * @src_profile: CSR Roam profile
 *
 * When the user space updates the assoc IEs or FILS auth type or FILS ERP info,
 * host driver needs to send these updated parameters to firmware via
 * RSO update command.
 *
 * Return: None
 */
QDF_STATUS sme_send_rso_connect_params(mac_handle_t mac_handle,
				       uint8_t vdev_id,
				       struct csr_roam_profile *src_profile);

#if defined(WLAN_FEATURE_FILS_SK)
/**
 * sme_update_fils_config - Update FILS config to CSR roam session
 * @mac_handle: Opaque handle to the global MAC context
 * @vdev_id: vdev id
 * @src_profile: Source roam profile having latest FILS config
 *
 * API to update FILS config to roam csr session.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_update_fils_config(mac_handle_t mac_handle, uint8_t vdev_id,
				  struct csr_roam_profile *src_profile);

/**
 * sme_free_join_rsp_fils_params - free fils params
 * @roam_info: roam info
 *
 * Return: void
 */
void sme_free_join_rsp_fils_params(struct csr_roam_info *roam_info);
#else
static inline
QDF_STATUS sme_update_fils_config(mac_handle_t mac_handle, uint8_t vdev_id,
				  struct csr_roam_profile *src_profile)
{
	return QDF_STATUS_SUCCESS;
}

static inline
void sme_free_join_rsp_fils_params(struct csr_roam_info *roam_info)
{}

#endif

#ifdef WLAN_FEATURE_11AX_BSS_COLOR
/**
 * sme_set_he_bss_color() - Sets the HE BSS color
 *
 * @mac_handle: The handle returned by mac_open
 * @session_id: session_id of the request
 * @bss_color: HE BSS color value to set
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_set_he_bss_color(mac_handle_t mac_handle, uint8_t session_id,
				uint8_t bss_color);
#else
static inline
QDF_STATUS sme_set_he_bss_color(mac_handle_t mac_handle, uint8_t session_id,
				uint8_t bss_color)
{
	return QDF_STATUS_SUCCESS;
}
#endif

/**
 * sme_is_conn_state_connected() -- check if SME connection state is connected
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: current Session Id
 *
 * This API checks if the current SME connection state is connected for the
 * given session id.
 *
 * Return: True if connected, false if any other state.
 */
bool sme_is_conn_state_connected(mac_handle_t mac_handle, uint8_t session_id);

/**
 * sme_scan_get_result_for_bssid - gets the scan result from scan cache for the
 * bssid specified
 * @mac_handle: handle returned by mac_open
 * @bssid: bssid to get the scan result for
 * @res: pointer to tCsrScanResultInfo allocated from caller
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_scan_get_result_for_bssid(mac_handle_t mac_handle,
					 struct qdf_mac_addr *bssid,
					 tCsrScanResultInfo *res);

/**
 * sme_get_bss_transition_status() - get bss transition status all cadidates
 * @mac_handle: handle returned by mac_open
 * @transition_reason : Transition reason
 * @bssid: bssid to get BSS transition status
 * @info : bss candidate information
 * @n_candidates : number of candidates
 * @is_bt_in_progress: bt activity indicator
 *
 * Return: QDF_STATUS_SUCCESS on success otherwise a QDF_STATUS error
 */
QDF_STATUS sme_get_bss_transition_status(mac_handle_t mac_handle,
					 uint8_t transition_reason,
					 struct qdf_mac_addr *bssid,
					 struct bss_candidate_info *info,
					 uint16_t n_candidates,
					 bool is_bt_in_progress);

/**
 * sme_unpack_rsn_ie: wrapper to unpack RSN IE and update def RSN params
 * if optional fields are not present.
 * @mac_handle: handle returned by mac_open
 * @buf: rsn ie buffer pointer
 * @buf_len: rsn ie buffer length
 * @rsn_ie: outframe rsn ie structure
 * @append_ie: flag to indicate if the rsn_ie need to be appended from buf
 *
 * Return: parse status
 */
uint32_t sme_unpack_rsn_ie(mac_handle_t mac_handle, uint8_t *buf,
			   uint8_t buf_len, tDot11fIERSN *rsn_ie,
			   bool append_ie);

/**
 * sme_add_qcn_ie: Adds QCN IE data to IE buffer
 * @mac_handle: handle returned by mac_open
 * @ie_data: ie buffer pointer
 * @ie_len: ie length pointer
 *
 * Return: none
 */
void sme_add_qcn_ie(mac_handle_t mac_handle, uint8_t *ie_data,
		    uint16_t *ie_len);

/**
 * sme_get_oper_chan_freq - gets the operating channel freq
 * @vdev: vdev handle
 *
 * Return: operating channel frequency
 */
int16_t sme_get_oper_chan_freq(struct wlan_objmgr_vdev *vdev);

/**
 * sme_get_oper_ch_width - gets the operating channel width
 * @vdev: vdev handle
 *
 * Return: operating channel width
 */
enum phy_ch_width sme_get_oper_ch_width(struct wlan_objmgr_vdev *vdev);

/**
 * sme_get_oper_ch_width - gets the secondary channel frequency
 * @vdev: vdev handle
 * @sec20chan_freq: secondary channel frequency
 *
 * Return: secondary channel frequency
 */
int sme_get_sec20chan_freq_mhz(struct wlan_objmgr_vdev *vdev,
						uint16_t *sec20chan_freq);

/**
 * sme_enable_roaming_on_connected_sta() - Enable roaming on an connected sta
 * @mac_handle: handle returned by mac_open
 * @vdev_id: vdev id
 *
 * The function check if any connected STA is present on which roaming is not
 * enabled and if present enabled roaming on that STA.
 *
 * Return: none
 */
void sme_enable_roaming_on_connected_sta(mac_handle_t mac_handle,
					 uint8_t vdev_id);

/**
 * sme_send_mgmt_tx() - Sends mgmt frame from CSR to LIM
 * @mac_handle: The handle returned by mac_open
 * @session_id: session id
 * @buf: pointer to frame
 * @len: frame length
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_send_mgmt_tx(mac_handle_t mac_handle, uint8_t session_id,
			    const uint8_t *buf, uint32_t len);

#ifdef WLAN_FEATURE_SAE
/**
 * sme_handle_sae_msg() - Sends SAE message received from supplicant
 * @mac_handle: The handle returned by mac_open
 * @session_id: session id
 * @sae_status: status of SAE authentication
 * @peer_mac_addr: mac address of the peer to be authenticated
 * @pmkid: PMKID derived at the end of SAE authentication
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_handle_sae_msg(mac_handle_t mac_handle,
			      uint8_t session_id,
			      uint8_t sae_status,
			      struct qdf_mac_addr peer_mac_addr,
			      const uint8_t *pmkid);
#else
static inline
QDF_STATUS sme_handle_sae_msg(mac_handle_t mac_handle,
			      uint8_t session_id,
			      uint8_t sae_status,
			      struct qdf_mac_addr peer_mac_addr,
			      const uint8_t *pmkid)
{
	return QDF_STATUS_SUCCESS;
}
#endif

/**
 * sme_set_ba_buff_size() - sets BA buffer size
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: SME session id
 * @buff_size: BA buffer size
 *
 * Return: 0 on success else err code
 */
int sme_set_ba_buff_size(mac_handle_t mac_handle, uint8_t session_id,
			 uint16_t buff_size);

/**
 * sme_send_addba_req() - send ADDBA request with user config
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: SME session id
 * @tid: tid val for BA session
 * @buff_size: BA buffer size
 *
 * Return: 0 on success else err code
 */
int sme_send_addba_req(mac_handle_t mac_handle, uint8_t session_id, uint8_t tid,
		       uint16_t buff_size);

/**
 * sme_set_no_ack_policy() - Sets no ack policy for AC
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: SME session id
 * @val: no ack policy value
 * @ac: access category
 *
 * Return: 0 on success else err code
 */
int sme_set_no_ack_policy(mac_handle_t mac_handle, uint8_t session_id,
			  uint8_t val, uint8_t ac);

/**
 * sme_set_auto_rate_he_sgi() - Sets SGI for auto rate
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: SME session id
 * @cfg_val: SGI configuration value
 *
 * Return: 0 on success else err code
 */
int sme_set_auto_rate_he_sgi(mac_handle_t mac_handle, uint8_t session_id,
			     uint8_t cfg_val);

/**
 * sme_set_auto_rate_ldpc() - Sets LDPC for auto rate
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: SME session id
 * @ldpc_disable: LDPC configuration value
 *
 * Return: 0 on success else err code
 */
int sme_set_auto_rate_ldpc(mac_handle_t mac_handle, uint8_t session_id,
			   uint8_t ldpc_disable);

/**
 * sme_set_auto_rate_he_ltf() - Sets HE LTF for auto rate
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: SME session id
 * @cfg_val: LTF configuration value
 *
 * Return: 0 on success else err code
 */
int sme_set_auto_rate_he_ltf(mac_handle_t mac_handle, uint8_t session_id,
			     uint8_t cfg_val);

#ifdef WLAN_FEATURE_11AX
/**
 * sme_update_tgt_he_cap() - sets the HE caps to pmac
 * @mac_handle: Pointer to MAC handle
 * @cfg: Pointer to WMA target CFG
 * @he_cap_ini: Pointer to HE CAP configured by INI
 *
 * Return: None
 */
void sme_update_tgt_he_cap(mac_handle_t mac_handle,
			   struct wma_tgt_cfg *cfg,
			   tDot11fIEhe_cap *he_cap_ini);

/**
 * sme_update_he_cap_nss() - sets the nss based on user request
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: SME session id
 * @nss: no.of spatial streams value
 *
 * Return: None
 */
void sme_update_he_cap_nss(mac_handle_t mac_handle, uint8_t session_id,
			   uint8_t nss);

/**
 * sme_update_he_tx_bfee_supp() - sets the HE Tx Bfee support
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: SME session id
 * @cfg_val: Tx Bfee config value
 *
 * Return: 0 on success else err code
 */
int sme_update_he_tx_bfee_supp(mac_handle_t mac_handle, uint8_t session_id,
			       uint8_t cfg_val);

/**
 * sme_update_he_tx_bfee_nsts() - sets the HE Tx Bfee NSTS
 * @mac_handle: MAC handle
 * @session_id: SME session id
 * @cfg_val: Tx Bfee NSTS value
 *
 * Return: 0 on success else err code
 */
int sme_update_he_tx_bfee_nsts(mac_handle_t mac_handle, uint8_t session_id,
			       uint8_t cfg_val);

/**
 * sme_set_he_tx_bf_cbf_rates() - sets the HE Tx Bfee CBF frame rates to FW
 * @session_id: SME session id
 *
 * Return: None
 */
void sme_set_he_tx_bf_cbf_rates(uint8_t session_id);

/**
 * sme_config_su_ppdu_queue() - Configures SU PPDU queue enable/disable in FW
 * @session_id: SME session id
 * @enable: Enable/Disable config
 *
 * Return: None
 */
void sme_config_su_ppdu_queue(uint8_t session_id, bool enable);

/**
 * sme_update_he_mcs() - sets the HE MCS based on user request
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: SME session id
 * @he_mcs: HE MCS value
 *
 * Return: 0 on success else err code
 */
int sme_update_he_mcs(mac_handle_t mac_handle, uint8_t session_id,
		      uint16_t he_mcs);

/**
 * sme_update_he_trigger_frm_mac_pad() - sets the HE MAC padding capability
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: SME session id
 * @cfg_val: HE MAC padding duration value
 *
 * Return: 0 on success else err code
 */
int sme_update_he_trigger_frm_mac_pad(mac_handle_t mac_handle,
				      uint8_t session_id,
				      uint8_t cfg_val);

/**
 * sme_update_he_om_ctrl_supp() - sets the HE OM control capability
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: SME session id
 * @cfg_val: HE OM control config
 *
 * Return: 0 on success else err code
 */
int sme_update_he_om_ctrl_supp(mac_handle_t mac_handle, uint8_t session_id,
			       uint8_t cfg_val);

#define A_CTRL_ID_OMI 0x1
struct omi_ctrl_tx {
	uint32_t omi_in_vht:1;
	uint32_t omi_in_he:1;
	uint32_t a_ctrl_id:4;
	uint32_t rx_nss:3;
	uint32_t ch_bw:2;
	uint32_t ul_mu_dis:1;
	uint32_t tx_nsts:3;
	uint32_t er_su_dis:1;
	uint32_t dl_mu_mimo_resound:1;
	uint32_t ul_mu_data_dis:1;
	uint32_t reserved:14;
};

int sme_send_he_om_ctrl_bw_update(mac_handle_t mac_handle, uint8_t session_id,
				  uint8_t cfg_val);

int sme_send_he_om_ctrl_nss_update(mac_handle_t mac_handle, uint8_t session_id,
				   uint8_t cfg_val);

void sme_reset_he_om_ctrl(mac_handle_t mac_handle);

/**
 * sme_config_action_tx_in_tb_ppdu() - Sends action frame in TB PPDU cfg to FW
 * @mac_handle: Pointer to MAC handle
 * @session_id: SME session id
 * @cfg_val: configuration setting value
 *
 * Return: 0 on success else err code
 */
int sme_config_action_tx_in_tb_ppdu(mac_handle_t mac_handle, uint8_t session_id,
				    uint8_t cfg_val);

/**
 * sme_send_he_om_ctrl_update() - Send HE OM ctrl Tx cmd to FW
 * @mac_handle: Pointer to mac handle
 * @session_id: SME session id
 *
 * Return: 0 on success else err code
 */
int sme_send_he_om_ctrl_update(mac_handle_t mac_handle, uint8_t session_id);

/**
 * sme_set_he_om_ctrl_param() - Update HE OM control params for OMI Tx
 * @mac_handle: Pointer to mac handle
 * @session_id: SME session id
 * @param: HE om control parameter
 * @cfg_val: HE OM control parameter config value
 *
 * Return: 0 on success else err code
 */
int sme_set_he_om_ctrl_param(mac_handle_t mac_handle, uint8_t session_id,
			     enum qca_wlan_vendor_attr_he_omi_tx param,
			     uint8_t cfg_val);

/**
 * sme_set_usr_cfg_mu_edca() - sets the user cfg MU EDCA params flag
 * @mac_handle: Opaque handle to the global MAC context
 * @val: value to be set
 *
 * Return: none
 */
void sme_set_usr_cfg_mu_edca(mac_handle_t mac_handle, bool val);

/**
 * sme_set_he_mu_edca_def_cfg() - sets the default MU EDCA params values
 * @mac_handle: Opaque handle to the global MAC context
 *
 * Return: none
 */
void sme_set_he_mu_edca_def_cfg(mac_handle_t mac_handle);

/**
 * sme_update_he_htc_he_supp() - Update +HTC-HE support in HE capabilities
 * @mac_handle: Pointer to mac handle
 * @session_id: SME session id
 * @cfg_val: config setting
 *
 * Return: 0 on success else err code
 */
int sme_update_he_htc_he_supp(mac_handle_t mac_handle, uint8_t session_id,
			      bool cfg_val);

/**
 * sme_update_mu_edca_params() - updates MU EDCA params values
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: SME session id
 *
 * Return: 0 on success else err code
 */
int sme_update_mu_edca_params(mac_handle_t mac_handle, uint8_t session_id);

/**
 * sme_update_he_tx_stbc_cap() - Sets the HE Tx STBC capability
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: SME session id
 * @value: set value
 *
 * Return: 0 on success else err code
 */
int sme_update_he_tx_stbc_cap(mac_handle_t mac_handle, uint8_t session_id,
			      int value);

/**
 * sme_update_he_rx_stbc_cap() - Sets the HE Rx STBC capability
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: SME session id
 * @value: set value
 *
 * Return: 0 on success else err code
 */
int sme_update_he_rx_stbc_cap(mac_handle_t mac_handle, uint8_t session_id,
			      int value);

/**
 * sme_update_he_frag_supp() - sets the HE fragmentation support
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: SME session id
 * @he_frag: HE fragmention support value
 *
 * Return: 0 on success else err code
 */
int sme_update_he_frag_supp(mac_handle_t mac_handle, uint8_t session_id,
			    uint16_t he_frag);

/**
 * sme_update_he_ldpc_supp() - sets the HE LDPC support
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: SME session id
 * @he_ldpc: HE LDPC support value
 *
 * Return: 0 on success else err code
 */
int sme_update_he_ldpc_supp(mac_handle_t mac_handle, uint8_t session_id,
			    uint16_t he_ldpc);

/**
 * sme_update_he_twt_req_support() - Sets twt request capability
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: SME session id
 * @value: set value
 *
 * Return: 0 on success else err code
 */
int sme_update_he_twt_req_support(mac_handle_t mac_handle, uint8_t session_id,
				  uint8_t cfg_val);
#else
static inline void sme_update_tgt_he_cap(mac_handle_t mac_handle,
					 struct wma_tgt_cfg *cfg,
					 tDot11fIEhe_cap *he_cap_ini)
{}
static inline void sme_update_he_cap_nss(mac_handle_t mac_handle,
					 uint8_t session_id,
					 uint8_t nss)
{}
static inline int sme_update_he_mcs(mac_handle_t mac_handle, uint8_t session_id,
				    uint16_t he_mcs)
{
	return 0;
}

static inline void sme_set_he_mu_edca_def_cfg(mac_handle_t mac_handle)
{
}

static inline int sme_update_mu_edca_params(mac_handle_t mac_handle,
					    uint8_t session_id)
{
	return 0;
}

static inline int sme_update_he_trigger_frm_mac_pad(mac_handle_t mac_handle,
						    uint8_t session_id,
						    uint8_t cfg_val)
{
	return 0;
}

static inline int sme_update_he_om_ctrl_supp(mac_handle_t mac_handle,
					     uint8_t session_id,
					     uint8_t cfg_val)
{
	return 0;
}


static inline int
sme_set_he_om_ctrl_param(mac_handle_t mac_handle, uint8_t session_id,
			 enum qca_wlan_vendor_attr_he_omi_tx param,
			 uint8_t cfg_val)
{
	return 0;
}

static inline void sme_reset_he_om_ctrl(mac_handle_t mac_handle)
{
}

static inline int sme_config_action_tx_in_tb_ppdu(mac_handle_t mac_handle,
						  uint8_t session_id,
						  uint8_t cfg_val)
{
	return 0;
}

static inline int sme_update_he_htc_he_supp(mac_handle_t mac_handle,
					    uint8_t session_id,
					    bool cfg_val)
{
	return 0;
}

static inline int
sme_send_he_om_ctrl_update(mac_handle_t mac_handle, uint8_t session_id)
{
	return 0;
}
static inline void sme_set_usr_cfg_mu_edca(mac_handle_t mac_handle, bool val)
{
}

static inline int sme_update_he_tx_stbc_cap(mac_handle_t mac_handle,
					    uint8_t session_id,
					    int value)
{
	return 0;
}

static inline int sme_update_he_rx_stbc_cap(mac_handle_t mac_handle,
					    uint8_t session_id,
					    int value)
{
	return 0;
}

static inline int sme_update_he_frag_supp(mac_handle_t mac_handle,
					  uint8_t session_id,
					  uint16_t he_frag)
{
	return 0;
}

static inline int sme_update_he_ldpc_supp(mac_handle_t mac_handle,
					  uint8_t session_id,
					  uint16_t he_ldpc)
{
	return 0;
}

static inline int sme_update_he_tx_bfee_supp(mac_handle_t mac_handle,
					     uint8_t session_id,
					     uint8_t cfg_val)
{
	return 0;
}
static inline int sme_update_he_tx_bfee_nsts(mac_handle_t mac_handle,
					     uint8_t session_id,
					     uint8_t cfg_val)
{
	return 0;
}

static inline void sme_set_he_tx_bf_cbf_rates(uint8_t session_id)
{
}

static inline void sme_config_su_ppdu_queue(uint8_t session_id, bool enable)
{
}

static inline int sme_update_he_twt_req_support(mac_handle_t mac_handle,
						uint8_t session_id,
						uint8_t cfg_val)
{
	return 0;
}

#endif

/**
 * sme_update_session_txq_edca_params() - sets the configured
 * internal EDCA params values
 *
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: session id
 * @txq_edca_params: edca parameters
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
sme_update_session_txq_edca_params(mac_handle_t mac_handle, uint8_t session_id,
				   tSirMacEdcaParamRecord *txq_edca_params);

/**
 * sme_is_sta_key_exchange_in_progress() - checks whether the STA/P2P client
 * session has key exchange in progress
 *
 * @mac_handle: Opaque handle to the global MAC context
 * @session_id: session id
 *
 * Return: true - if key exchange in progress
 *         false - if not in progress
 */
bool sme_is_sta_key_exchange_in_progress(mac_handle_t mac_handle,
					 uint8_t session_id);

/*
 * sme_validate_channel_list() - Validate the given channel list
 * @mac_handle: Opaque handle to the global MAC context
 * @chan_freq_list: Pointer to the channel list
 * @num_channels: number of channels present in the chan_list
 *
 * Validates the given channel list with base channels in mac context
 *
 * Return: True if all channels in the list are valid, false otherwise
 */
bool sme_validate_channel_list(mac_handle_t mac_handle,
			       uint32_t *chan_freq_list,
			       uint8_t num_channels);
/**
 * sme_set_amsdu() - set amsdu enable/disable based on user cfg
 * @mac_handle: Opaque handle to the global MAC context
 * @enable: enable or disable
 *
 * Return: None
 */
void sme_set_amsdu(mac_handle_t mac_handle, bool enable);

#ifdef WLAN_FEATURE_11AX
void sme_set_he_testbed_def(mac_handle_t mac_handle, uint8_t vdev_id);
void sme_reset_he_caps(mac_handle_t mac_handle, uint8_t vdev_id);
#else
static inline void sme_set_he_testbed_def(mac_handle_t mac_handle,
					  uint8_t vdev_id)
{
}
static inline void sme_reset_he_caps(mac_handle_t mac_handle, uint8_t vdev_id)
{
}
#endif

/**
 * sme_get_mcs_idx() - gets mcs index
 * @raw_rate: raw rate from fw
 * @rate_flags: rate flags
 * @nss: number of nss
 * @dcm: dcm will be calculated from rate
 * @guard_interval: guard interval info from rate
 * @mcs_rate_flags: mcs rate flag
 *
 * Return: return mcs index
 */
uint8_t sme_get_mcs_idx(uint16_t raw_rate, enum tx_rate_info rate_flags,
			uint8_t *nss, uint8_t *dcm,
			enum txrate_gi *guard_interval,
			enum tx_rate_info *mcs_rate_flags);

#ifdef WLAN_SUPPORT_TWT
/**
 * sme_register_twt_enable_complete_cb() - TWT enable registrar
 * @mac_handle: MAC handle
 * @twt_enable_cb: Function callback to handle enable event
 *
 * Return: QDF Status
 */
QDF_STATUS sme_register_twt_enable_complete_cb(mac_handle_t mac_handle,
					       twt_enable_cb twt_enable_cb);

/**
 * sme_register_twt_disable_complete_cb - TWT disable registrar
 * @mac_handle: MAC handle
 * @twt_disable_cb: Function callback to handle disable event
 *
 * Return: QDF Status
 */
QDF_STATUS sme_register_twt_disable_complete_cb(mac_handle_t mac_handle,
						twt_disable_cb twt_disable_cb);

/**
 * sme_deregister_twt_enable_complete_cb() - TWT enable deregistrar
 * @mac_handle: Opaque handle to the global MAC context
 *
 * Return: QDF Status
 */
QDF_STATUS sme_deregister_twt_enable_complete_cb(mac_handle_t mac_handle);

/**
 * sme_deregister_twt_disable_complete_cb - TWT disable deregistrar
 * @mac_handle: Opaque handle to the global MAC context
 *
 * Return: QDF Status
 */
QDF_STATUS sme_deregister_twt_disable_complete_cb(mac_handle_t mac_handle);

#else
static inline
QDF_STATUS sme_register_twt_enable_complete_cb(mac_handle_t mac_handle,
					       twt_enable_cb twt_enable_cb)
{
	return QDF_STATUS_SUCCESS;
}

static inline
QDF_STATUS sme_register_twt_disable_complete_cb(mac_handle_t mac_handle,
						twt_disable_cb twt_disable_cb)
{
	return QDF_STATUS_SUCCESS;
}

static inline
QDF_STATUS sme_deregister_twt_enable_complete_cb(mac_handle_t mac_handle)
{
	return QDF_STATUS_SUCCESS;
}

static inline
QDF_STATUS sme_deregister_twt_disable_complete_cb(mac_handle_t mac_handle)
{
	return QDF_STATUS_SUCCESS;
}
#endif
/**
 * sme_get_sta_cxn_info() - This function populates all the connection
 *			    information which is formed by DUT-STA to AP
 *			    by calling CSR helper API.
 * @mac_ctx: pointer to mac context
 * @session: pointer to sta session
 * @conn_profile: pointer to connected DUTSTA-REFAP profile
 * @buf: pointer to char buffer to write all the connection information.
 * @buf_size: maximum size of the provided buffer
 *
 * Returns: QDF_STATUS
 */
#ifdef FEATURE_WLAN_DIAG_SUPPORT_CSR
QDF_STATUS sme_get_sta_cxn_info(mac_handle_t mac_handle, uint32_t session_id,
				char *buf, uint32_t buf_sz);
#else
static inline QDF_STATUS
sme_get_sta_cxn_info(mac_handle_t mac_handle, uint32_t session_id,
		     char *buf, uint32_t buf_sz)
{
	qdf_scnprintf(buf, buf_sz,
		      "\nDiag macro disable, ask vendor to enable");
	return QDF_STATUS_SUCCESS;
}
#endif

#if defined(FEATURE_WLAN_ESE) && defined(WLAN_FEATURE_ROAM_OFFLOAD)
/**
 * sme_add_key_btk() - Add BTK key
 * @mac_handle: MAC handle
 * @session_id: SME session identifier
 * @key: key material
 * @key_len: length of the key
 *
 * Return: 0 on success and negative value for failure
 */
int sme_add_key_btk(mac_handle_t mac_handle, uint8_t session_id,
		    const uint8_t *key, const int key_len);

#else
static inline int sme_add_key_btk(mac_handle_t mac_handle, uint8_t session_id,
				  const uint8_t *key, const int key_len)
{
	return 0;
}
#endif

#ifdef FEATURE_WLAN_ESE
/**
 * sme_add_key_krk() - Add KRK key
 * @mac_handle: MAC handle
 * @session_id: SME session identifier
 * @key: key material
 * @key_len: length of the key
 *
 * Return: 0 on success and negative value for failure
 */
int sme_add_key_krk(mac_handle_t mac_handle, uint8_t session_id,
		    const uint8_t *key, const int key_len);

#else

static inline int sme_add_key_krk(mac_handle_t mac_handle, uint8_t session_id,
				  const uint8_t *key, const int key_len)
{
	return 0;
}
#endif

/**
 * sme_get_roam_scan_stats() - Send roam scan stats cmd to wma
 * @mac_handle: handle returned by mac_open
 * @cb: call-back invoked for roam scan stats response
 * @context: context of callback
 * @vdev_id: vdev id
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
sme_get_roam_scan_stats(mac_handle_t mac_handle, roam_scan_stats_cb cb,
			void *context, uint32_t vdev_id);

/**
 * sme_update_score_config() - Update the Scoring Config from MLME
 * @mac_handle: Mac Handle
 * @score_config: Pointer to the scoring config structure to be populated
 *
 * Return: None
 */
void sme_update_score_config(mac_handle_t mac_handle,
			     struct scoring_config *score_config);

/**
 * sme_enable_fw_module_log_level() - enable fw module log level
 * @mac_handle: handle returned by mac_open
 * @vdev_id: vdev id
 *
 * Return: None
 */
void sme_enable_fw_module_log_level(mac_handle_t mac_handle, int vdev_id);

#ifdef WLAN_FEATURE_MOTION_DETECTION
/**
 * sme_motion_det_cfg - motion detection configuration
 * @vdev_id: vdev id
 * @time_t1: Time T1 for motion detection in msecs
 * @time_t2: Time T2 for motion detection in msecs
 * @n1: number of packets for coarse detection
 * @n2: number of packets for fine detection
 * @time_t1_gap: gap between packets in coarse detection in msecs
 * @time_t2_gap: gap between packets in fine detection in msecs
 * @coarse_k: number of times fine motion detection has to be performed for
 *	      coarse detection
 * @fine_k: number of times fine motion detection has to be performed for
 *	    fine detection
 * @coarse_q: number of times motion is expected to be detected for success
 *	      case in coarse detection
 * @fine_q: number of times motion is expected to be detected for success
 *	    case in fine detection
 * @md_coarse_thr_high: higher threshold value (in percent) from host to FW,
 *			which will be used in coarse detection phase of motion
 *			detection. This is the threshold for the correlation of
 *			the old RF local-scattering environment with current RF
 *			local-scattering environment. Value of 100(%) indicates
 *			that neither the transceiver nor any nearby objects
 *			have changed position
 * @md_fine_thr_high: higher threshold value (in percent) from host to FW, which
 *		      will be used in fine detection phase of motion detection.
 *		      This is the threshold for correlation between the old and
 *		      current RF environments, as explained above
 * @md_coarse_thr_low: lower threshold value (in percent) for immediate
 *		       detection of motion in coarse detection phase. This is
 *		       the threshold for correlation between the old and current
 *		       RF environments, as explained above
 * @md_fine_thr_low: lower threshold value (in percent) for immediate detection
 *		     of motion in fine detection phase. This is the threshold
 *		     for correlation between the old and current RF
 *		     environments, as explained above
 * @eSME_TDLS_PEER_REMOVE_MAC_ADDR: remove peer mac from connection table
 */

struct sme_motion_det_cfg {
	uint8_t vdev_id;
	uint32_t time_t1;
	uint32_t time_t2;
	uint32_t n1;
	uint32_t n2;
	uint32_t time_t1_gap;
	uint32_t time_t2_gap;
	uint32_t coarse_K;
	uint32_t fine_K;
	uint32_t coarse_Q;
	uint32_t fine_Q;
	uint8_t md_coarse_thr_high;
	uint8_t md_fine_thr_high;
	uint8_t md_coarse_thr_low;
	uint8_t md_fine_thr_low;
};

/**
 * sme_motion_det_base_line_cfg - motion detection base line configuration
 * @vdev_id : vdev id
 * @bl_time_t: time T for baseline (in ms), every bl_time_t, bl_n pkts are sent
 * @bl_packet_gap: gap between packets for baseline  in msecs
 * bl_n: number of packets to be sent during one baseline
 * bl_num_meas: number of times the baseline measurement to be done
 */
struct sme_motion_det_base_line_cfg {
	uint8_t vdev_id;
	uint32_t bl_time_t;
	uint32_t bl_packet_gap;
	uint32_t bl_n;
	uint32_t bl_num_meas;
};

/**
 * sme_motion_det_en - Start/Stop motion detection
 * @vdev_id: vdev_id
 * @enable: start = 1, stop =0
 */
struct sme_motion_det_en {
	uint8_t vdev_id;
	bool enable;
};

/**
 * sme_motion_det_base_line_en - Start/Stop motion detection base line
 * @vdev_id: vdev_id
 * @enable: start = 1, stop =0
 */
struct sme_motion_det_base_line_en {
	uint8_t vdev_id;
	bool enable;
};

/**
 * sme_motion_det_config - Post motion detection configuration msg to scheduler
 * @mac_handle: mac handle
 * @motion_det_cfg: motion detection configuration
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure
 */
QDF_STATUS sme_motion_det_config(mac_handle_t mac_handle,
				 struct sme_motion_det_cfg *motion_det_cfg);

/**
 * sme_motion_det_enable - Post motion detection start/stop msg to scheduler
 * @mac_handle: mac handle
 * @motion_det_en: motion detection start/stop
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure
 */
QDF_STATUS sme_motion_det_enable(mac_handle_t mac_handle,
				 struct sme_motion_det_en *motion_det_en);

/**
 * sme_motion_det_base_line_config - Post md baselining cfg msg to scheduler
 * @mac_handle: mac handle
 * @motion_det_base_line_cfg: motion detection baselining configuration
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure
 */
QDF_STATUS sme_motion_det_base_line_config(
		mac_handle_t mac_handle,
		struct sme_motion_det_base_line_cfg *motion_det_base_line_cfg);

/**
 * sme_motion_det_base_line_enable - Post md baselining enable msg to scheduler
 * @mac_handle: mac handle
 * @motion_det_base_line_en: motion detection baselining start/stop
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure
 */
QDF_STATUS sme_motion_det_base_line_enable(
		mac_handle_t mac_handle,
		struct sme_motion_det_base_line_en *motion_det_base_line_en);

/**
 * sme_set_md_host_evt_cb - Register/set motion detection callback
 * @mac_handle: mac handle
 * @callback_fn: motion detection callback function pointer
 * @hdd_ctx: hdd context
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure
 */
QDF_STATUS sme_set_md_host_evt_cb
(
	mac_handle_t mac_handle,
	QDF_STATUS (*callback_fn)(void *ctx, struct sir_md_evt *event),
	void *hdd_ctx
);

/**
 * sme_set_md_bl_evt_cb - Register/set motion detection baseline callback
 * @mac_handle: mac handle
 * @callback_fn: callback function pointer
 * @hdd_ctx: hdd context
 *
 * Return: QDF_STATUS_SUCCESS or non-zero on failure
 */
QDF_STATUS sme_set_md_bl_evt_cb
(
	mac_handle_t mac_handle,
	QDF_STATUS (*callback_fn)(void *ctx, struct sir_md_bl_evt *event),
	void *hdd_ctx
);
#endif /* WLAN_FEATURE_MOTION_DETECTION */

#ifdef FW_THERMAL_THROTTLE_SUPPORT
/**
 * sme_set_thermal_throttle_cfg() - SME API to set the thermal throttle
 * configuration parameters
 * @mac_handle: Opaque handle to the global MAC context
 * @enable: Enable Throttle
 * @dc: duty cycle in msecs
 * @dc_off_percent: duty cycle off percentage
 * @prio: Disables the transmit queues in fw that have lower priority
 * than value defined by prio
 * @target_temp: Target temperature
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_set_thermal_throttle_cfg(mac_handle_t mac_handle, bool enable,
					uint32_t dc, uint32_t dc_off_percent,
					uint32_t prio, uint32_t target_temp);

/**
 * sme_set_thermal_mgmt() - SME API to set the thermal management params
 * @mac_handle: Opaque handle to the global MAC context
 * @lower_thresh_deg: Lower threshold value of Temperature
 * @higher_thresh_deg: Higher threshold value of Temperature
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_set_thermal_mgmt(mac_handle_t mac_handle,
				uint16_t lower_thresh_deg,
				uint16_t higher_thresh_deg);
#endif /* FW_THERMAL_THROTTLE_SUPPORT */

/**
 * sme_update_hidden_ssid_status_cb() - cb fun to update hidden ssid stats
 * @mac_handle: mac handler
 * @cb: cb of type hidden_ssid_cb
 */
QDF_STATUS sme_update_hidden_ssid_status_cb(mac_handle_t mac_handle,
					    hidden_ssid_cb cb);

/**
 * sme_update_owe_info() - Update OWE info
 * @mac: mac context
 * @assoc_ind: assoc ind
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_update_owe_info(struct mac_context *mac,
			       struct assoc_ind *assoc_ind);

#ifdef WLAN_MWS_INFO_DEBUGFS
/**
 * sme_get_mws_coex_info() - SME API to get the coex information
 * @mac_handle: mac handler
 * @vdev_id: Vdev_id
 * @cmd_id: enum mws_coex_cmdid which information is needed.
 * @callback_fn: Callback function
 * @context: callback context
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
sme_get_mws_coex_info(mac_handle_t mac_handle, uint32_t vdev_id,
		      uint32_t cmd_id, void (*callback_fn)(void *coex_info_data,
							   void *context,
							   wmi_mws_coex_cmd_id
							   cmd_id),
		      void *context);
#endif /* WLAN_MWS_INFO_DEBUGFS */

#ifdef WLAN_BCN_RECV_FEATURE
/**
 * sme_register_bcn_recv_pause_ind_cb() - Register pause ind cb
 * mac_handle: man handler
 * cb: callback function to HDD
 *
 * This function register HDD callback in order to indicate beacon
 * receive pause indication to userspace.
 *
 * return QDF_STATUS of cb registration
 */
QDF_STATUS sme_register_bcn_recv_pause_ind_cb(mac_handle_t mac_handle,
					      beacon_pause_cb cb);

#else
static inline
QDF_STATUS sme_register_bcn_recv_pause_ind_cb(mac_handle_t mac_handle,
					      beacon_pause_cb cb)
{
	return QDF_STATUS_SUCCESS;
}
#endif

/**
 * sme_set_disconnect_ies() - set disconnect IEs
 * @mac_handle: handle returned by mac_open
 * @vdev_id: vdev id
 * @ie_data: Disconnect IE data
 * @ie_len: Disconnect IE length
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_set_disconnect_ies(mac_handle_t mac_handle, uint8_t vdev_id,
				  uint8_t *ie_data, uint16_t ie_len);

void sme_chan_to_freq_list(
			struct wlan_objmgr_pdev *pdev,
			uint32_t *freq_list,
			const uint8_t *chan_list,
			uint32_t chan_list_len);

/**
 * sme_set_roam_triggers() - Send roam trigger bitmap to WMA
 * @mac_handle: Opaque handle to the MAC context
 * @triggers: Carries pointer of the object containing vdev id and
 *	      roam_trigger_bitmap.
 *
 * Send the roam trigger bitmap received to WMA/WMI. WMI converts
 * the bitmap to firmware compatible bitmap as per reasons
 * defined @WMI_ROAM_TRIGGER_REASON_ID
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_set_roam_triggers(mac_handle_t mac_handle,
				 struct roam_triggers *triggers);

/**
 * sme_set_roam_config_enable() - Cache roam config status in SME
 * @mac_handle: Opaque handle to the MAC context
 * @vdev_id: vdev id
 * @roam_control_enable: Carries a non-zero value if the current set request is
 *			 for enable, otherwise carries a 0.
 *
 * Cache control roam config enable/disable status in SME so that the
 * userspace can query for the status based on a vdev/session at any time.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_set_roam_config_enable(mac_handle_t mac_handle,
				      uint8_t vdev_id,
				      uint8_t roam_control_enable);

/**
 * sme_get_roam_config_status() - Get roam config status from SME
 * @mac_handle: Opaque handle to the MAC context
 * @vdev_id: vdev id
 * @config_status: Pointer of a buffer to fill the status
 *
 * Get the cached control roam config status in SME and copy to status.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_get_roam_config_status(mac_handle_t mac_handle, uint8_t vdev_id,
				      uint8_t *config_status);

/**
 * sme_get_full_roam_scan_period_global() - get global full scan refresh period
 * @mac_handle: The handle returned by mac_open
 *
 * Return: Full roam scan period configured through ini
 */
uint16_t sme_get_full_roam_scan_period_global(mac_handle_t mac_handle);

/**
 * sme_get_full_roam_scan_period() - Get full roam scan period
 * @mac_handle: Opaque handle to the MAC context
 * @vdev_id: vdev id
 * @full_roam_scan_period: Pointer of a buffer to fill the full roam scan period
 *
 * Get the full scan period cached in neighborRoamInfo and fill in the given
 * buffer full_roam_scan_period.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_get_full_roam_scan_period(mac_handle_t mac_handle,
					 uint8_t vdev_id,
					 uint32_t *full_roam_scan_period);

/**
 * sme_check_for_duplicate_session() - check for duplicate session
 * @mac_handle: Opaque handle to the MAC context
 * @peer_addr: Peer device mac address
 *
 * Check for duplicate mac address is available on other vdev.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_check_for_duplicate_session(mac_handle_t mac_handle,
					   uint8_t *peer_addr);
#ifdef FEATURE_ANI_LEVEL_REQUEST
/*
 * sme_get_ani_level() -
 * A wrapper function that client calls to register a callback to get ani level
 *
 * @mac_handle - pointer to mac handle
 * @freqs - frequencies for which ANI level has to be fetched
 * @num_freqs - number of frequencies
 * @callback - SME sends back the ani level using the callback
 * @context - user context to be passed back along with the callback
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_get_ani_level(mac_handle_t mac_handle, uint32_t *freqs,
			     uint8_t num_freqs, void (*callback)(
			     struct wmi_host_ani_level_event *ani, uint8_t num,
			     void *context), void *context);
#endif /* FEATURE_ANI_LEVEL_REQUEST */

/**
 * sme_get_prev_connected_bss_ies() - Get the previous connected AP IEs
 * @mac_handle: The handle returned by mac_open.
 * @vdev_id: vdev id
 * @ies: IEs of the disconnected AP. Currently to carry beacon IEs.
 * @ie_len: Length of the @ies
 *
 * This API extracts the IEs from the previous connected AP info and update
 * them to the ies and ie_len.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_get_prev_connected_bss_ies(mac_handle_t mac_handle,
					  uint8_t vdev_id,
					  uint8_t **ies, uint32_t *ie_len);

#ifdef FEATURE_MONITOR_MODE_SUPPORT
/**
 * sme_set_monitor_mode_cb() - Register monitor mode vdev up operation callback
 * @mac_handle: Opaque handle to the MAC context
 * @monitor_mode_cb: callback to be registered
 *
 * Return: QDF_STATUS
 */
QDF_STATUS sme_set_monitor_mode_cb(mac_handle_t mac_handle,
				   void (*monitor_mode_cb)(uint8_t vdev_id));

/*
 * sme_process_monitor_mode_vdev_up_evt() - Handle vdev up completion
 * @vdev_id: vdev id
 *
 * Return: QDF_STATUS.
 */
QDF_STATUS sme_process_monitor_mode_vdev_up_evt(uint8_t vdev_id);
#else
static inline
QDF_STATUS sme_set_monitor_mode_cb(mac_handle_t mac_handle,
				   void (*monitor_mode_cb)(uint8_t vdev_id))
{
	return QDF_STATUS_SUCCESS;
}

static inline QDF_STATUS
sme_process_monitor_mode_vdev_up_evt(uint8_t vdev_id)
{
	return QDF_STATUS_E_FAILURE;
}
#endif
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

#endif /* #if !defined( __SME_API_H ) */

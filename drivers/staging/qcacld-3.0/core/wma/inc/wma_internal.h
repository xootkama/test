/*
<<<<<<< HEAD
 * Copyright (c) 2013-2019 The Linux Foundation. All rights reserved.
=======
 * Copyright (c) 2013-2020 The Linux Foundation. All rights reserved.
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

#ifndef WMA_INTERNAL_H
#define WMA_INTERNAL_H
<<<<<<< HEAD

=======
#include <cdp_txrx_handle.h>
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#if !defined(REMOVE_PKT_LOG)
#include "pktlog_ac.h"
#endif

/* ################### defines ################### */
/*
 * TODO: Following constant should be shared by firwmare in
 * wmi_unified.h. This will be done once wmi_unified.h is updated.
 */
#define WMI_PEER_STATE_AUTHORIZED 0x2

#define WMA_2_4_GHZ_MAX_FREQ  3000
<<<<<<< HEAD
#define WOW_CSA_EVENT_OFFSET 12

#define WMA_DEFAULT_SCAN_REQUESTER_ID        1
#define WMI_SCAN_FINISH_EVENTS (WMI_SCAN_EVENT_START_FAILED | \
				WMI_SCAN_EVENT_COMPLETED | \
				WMI_SCAN_EVENT_DEQUEUED)
/* default value */
#define DEFAULT_INFRA_STA_KEEP_ALIVE_PERIOD  20
#define DEFAULT_STA_SA_QUERY_MAX_RETRIES_COUNT       (5)
#define DEFAULT_STA_SA_QUERY_RETRY_INTERVAL    (200)

/* pdev vdev and peer stats*/
#define FW_PDEV_STATS_SET 0x1
#define FW_VDEV_STATS_SET 0x2
#define FW_PEER_STATS_SET 0x4
#define FW_RSSI_PER_CHAIN_STATS_SET 0x8
#define FW_STATS_SET 0xf
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/*AR9888/AR6320  noise floor approx value
 * similar to the mentioned the WMA
 */
#define WMA_TGT_NOISE_FLOOR_DBM (-96)
<<<<<<< HEAD
#define WMA_TGT_MAX_SNR         (WMA_TGT_NOISE_FLOOR_DBM * (-1))
=======
#define WMA_INVALID_PER_CHAIN_SNR  (0x80)
#define WMA_INVALID_PER_CHAIN_RSSI (0xFF)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/*
 * Make sure that link monitor and keep alive
 * default values should be in sync with CFG.
 */
#define WMA_LINK_MONITOR_DEFAULT_TIME_SECS 10
#define WMA_KEEP_ALIVE_DEFAULT_TIME_SECS   5

<<<<<<< HEAD
#define AGC_DUMP  1
#define CHAN_DUMP 2
#define WD_DUMP   3
#ifdef CONFIG_ATH_PCIE_ACCESS_DEBUG
#define PCIE_DUMP 4
#endif

/* conformance test limits */
#define FCC       0x10
#define MKK       0x40
#define ETSI      0x30

/* Maximum Buffer length allowed for DFS-2 phyerrors */
#define DFS_MAX_BUF_LENGTH 4096

/*
 * Maximum Buffer length allowed for DFS-3 phyerrors
 * When 160MHz is supported the Max length of phyerrors
 * is larger than the legacy phyerrors.
 */
#define DFS3_MAX_BUF_LENGTH 4436

#define WMI_DEFAULT_NOISE_FLOOR_DBM (-96)

#define WMI_MCC_MIN_CHANNEL_QUOTA             20
#define WMI_MCC_MAX_CHANNEL_QUOTA             80
#define WMI_MCC_MIN_NON_ZERO_CHANNEL_LATENCY  30

/* The maximum number of patterns that can be transmitted by the firmware
 *  and maximum patterns size.
 */
#define WMA_MAXNUM_PERIODIC_TX_PTRNS 6

#define WMI_MAX_HOST_CREDITS 2
#define WMI_WOW_REQUIRED_CREDITS 1

#define WMI_MAX_MHF_ENTRIES 32


#define MAX_HT_MCS_IDX 8
#define MAX_VHT_MCS_IDX 10
#define INVALID_MCS_IDX 255

=======
/* The maximum number of patterns that can be transmitted by the firmware
 *  and maximum patterns size.
 */
#ifndef WMA_MAXNUM_PERIODIC_TX_PTRNS
#define WMA_MAXNUM_PERIODIC_TX_PTRNS 6
#endif

#define WMA_WMM_EXPO_TO_VAL(val)        ((1 << (val)) - 1)

#define MAX_HT_MCS_IDX 8
#define MAX_VHT_MCS_IDX 10
#ifdef WLAN_FEATURE_11AX
#define MAX_HE_MCS_IDX 12
#endif
#define INVALID_MCS_IDX 255

#define IS_MCS_HAS_DCM_RATE(val)  \
		((val) == 0 || (val) == 1 || \
		 (val) == 3 || (val) == 4)

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#define LINK_STATUS_LEGACY      0
#define LINK_STATUS_VHT         0x1
#define LINK_STATUS_MIMO        0x2
#define LINK_SUPPORT_VHT	0x4
#define LINK_SUPPORT_MIMO	0x8

#define LINK_RATE_VHT           0x3

#define MAX_ENTRY_HOLD_REQ_QUEUE 2
#define MAX_ENTRY_VDEV_RESP_QUEUE 10

<<<<<<< HEAD
/* Time(in ms) to detect DOS attack */
#define WMA_MGMT_FRAME_DETECT_DOS_TIMER 1000

#define MAX_NUM_HW_MODE    0xff
#define MAX_NUM_PHY        0xff

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/**
 * struct index_data_rate_type - non vht data rate type
 * @mcs_index: mcs rate index
 * @ht20_rate: HT20 supported rate table
 * @ht40_rate: HT40 supported rate table
 */
struct index_data_rate_type {
	uint8_t  mcs_index;
	uint16_t ht20_rate[2];
	uint16_t ht40_rate[2];
};

/**
 * struct index_vht_data_rate_type - vht data rate type
 * @mcs_index: mcs rate index
 * @ht20_rate: VHT20 supported rate table
 * @ht40_rate: VHT40 supported rate table
 * @ht80_rate: VHT80 supported rate table
<<<<<<< HEAD
=======
 * @ht160_rate: VHT160 supported rate table
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 */
struct index_vht_data_rate_type {
	uint8_t mcs_index;
	uint16_t ht20_rate[2];
	uint16_t ht40_rate[2];
	uint16_t ht80_rate[2];
<<<<<<< HEAD
};

=======
	uint16_t ht160_rate[2];
};

#ifdef WLAN_FEATURE_11AX
#define MAX_HE_DCM_INDEX 2
/**
 * struct index_he_data_rate_type - he data rate type
 * @beacon_rate_index: Beacon rate index
 * @supported_he80_rate: he80 rate
 * @supported_he40_rate: he40 rate
 * @supported_he20_rate: he20 rate
 * @supported_he160_rate: he160 rate
 */
struct index_he_data_rate_type {
	uint8_t beacon_rate_index;
	uint16_t supported_he20_rate[MAX_HE_DCM_INDEX][3];
	uint16_t supported_he40_rate[MAX_HE_DCM_INDEX][3];
	uint16_t supported_he80_rate[MAX_HE_DCM_INDEX][3];
	uint16_t supported_he160_rate[MAX_HE_DCM_INDEX][3];
};
#endif

struct wifi_scan_cmd_req_params;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/*
 * wma_main.c functions declarations
 */

<<<<<<< HEAD
int
wmi_unified_pdev_set_param(wmi_unified_t wmi_handle, WMI_PDEV_PARAM param_id,
			   uint32_t param_value);

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/**
 * wma_send_msg_by_priority() - Send wma message to PE with priority.
 * @wma_handle: wma handle
 * @msg_type: message type
 * @body_ptr: message body ptr
 * @body_val: message body value
 * @is_high_priority: if msg is high priority
 *
 * Return: none
 */
void wma_send_msg_by_priority(tp_wma_handle wma_handle, uint16_t msg_type,
<<<<<<< HEAD
		void *body_ptr, uint32_t body_val, int is_high_priority);
=======
		void *body_ptr, uint32_t body_val, bool is_high_priority);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * wma_send_msg() - Send wma message to PE.
 * @wma_handle: wma handle
 * @msg_type: message type
 * @body_ptr: message body ptr
 * @body_val: message body value
 *
 * Return: none
 */
void wma_send_msg(tp_wma_handle wma_handle, uint16_t msg_type,
			 void *body_ptr, uint32_t body_val);
<<<<<<< HEAD
=======

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/**
 * wma_send_msg_high_priority() - Send wma message to PE with high priority.
 * @wma_handle: wma handle
 * @msg_type: message type
 * @body_ptr: message body ptr
 * @body_val: message body value
 *
 * Return: none
 */
void wma_send_msg_high_priority(tp_wma_handle wma_handle, uint16_t msg_type,
			void *body_ptr, uint32_t body_val);

<<<<<<< HEAD

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
void wma_data_tx_ack_comp_hdlr(void *wma_context,
				      qdf_nbuf_t netbuf, int32_t status);

QDF_STATUS wma_set_ppsconfig(uint8_t vdev_id, uint16_t pps_param,
				    int value);

/*
 * wma_scan_roam.c functions declarations
 */

#ifdef WLAN_FEATURE_ROAM_OFFLOAD
void wma_process_roam_invoke(WMA_HANDLE handle,
				struct wma_roam_invoke_cmd *roaminvoke);

void wma_process_roam_synch_fail(WMA_HANDLE handle,
				 struct roam_offload_synch_fail *synch_fail);

int wma_roam_synch_event_handler(void *handle, uint8_t *event,
					uint32_t len);

#ifdef WLAN_FEATURE_FIPS
/**
 * wma_register_pmkid_req_event_handler() - Register pmkid request event handler
 * @wma_handle: wma_handle
 *
 * This function register pmkid request event handler.
 */
void wma_register_pmkid_req_event_handler(tp_wma_handle wma_handle);

/**
 * wma_roam_pmkid_request_event_handler() - Handles roam pmkid request event
 * @handle: wma_handle
 * @event: pmkid request event data pointer
 * @len: length of the data
 *
 * Handles pmkid request event from firmware which is triggered after roam
 * candidate selection.
 */
int wma_roam_pmkid_request_event_handler(void *handle,
					 uint8_t *event,
					 uint32_t len);
#else
static inline void
wma_register_pmkid_req_event_handler(tp_wma_handle wma_handle)
{
}

static inline int
wma_roam_pmkid_request_event_handler(void *handle,
				     uint8_t *event,
				     uint32_t len)
{
	return 0;
}
#endif /* WLAN_FEATURE_FIPS */

/**
<<<<<<< HEAD
=======
 * wma_roam_auth_offload_event_handler() - Handle LFR-3.0 Roam authentication
 * offload event.
 * @handle: wma_handle
 * @event:  rso auth offload event data pointer
 * @len: length of the data
 *
 * Handles roam authentication offload event from firmware which is triggered
 * after roam candidate selection.
 */
int wma_roam_auth_offload_event_handler(WMA_HANDLE handle, uint8_t *event,
					uint32_t len);

/**
 * wma_roam_stats_event_handler() - Handle the WMI_ROAM_STATS_EVENTID
 * from target
 * @handle: wma_handle
 * @event:  roam debug stats event data pointer
 * @len: length of the data
 *
 * This function handles the roam debug stats from the target and logs it
 * to kmsg. This WMI_ROAM_STATS_EVENTID event is received whenever roam
 * scan trigger happens or when neighbor report is sent by the firmware.
 *
 * Return: Success or Failure status
 */
int wma_roam_stats_event_handler(WMA_HANDLE handle, uint8_t *event,
				 uint32_t len);

/**
 * wma_mlme_roam_synch_event_handler_cb() - roam synch event handler
 * @handle: wma handle
 * @event: event data
 * @len: length of data
 *
 * This function is roam synch event handler. It sends roam
 * indication for upper layer.
 *
 * Return: Success or Failure status
 */
int wma_mlme_roam_synch_event_handler_cb(void *handle, uint8_t *event,
					 uint32_t len);

/**
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * wma_roam_synch_frame_event_handler() - roam synch frame event handler
 * @handle: wma handle
 * @event: event data
 * @len: length of data
 *
 * This function is roam synch frame event handler.
 *
 * Return: Success or Failure status
 */
int wma_roam_synch_frame_event_handler(void *handle, uint8_t *event,
					uint32_t len);
<<<<<<< HEAD
=======
#else
static inline int wma_mlme_roam_synch_event_handler_cb(void *handle,
						       uint8_t *event,
						       uint32_t len)
{
	return 0;
}

static inline int
wma_roam_stats_event_handler(WMA_HANDLE handle, uint8_t *event,
			     uint32_t len)
{
	return 0;
}

static inline int
wma_roam_pmkid_request_event_handler(void *handle,
				     uint8_t *event,
				     uint32_t len)
{
	return 0;
}
#endif

#ifdef WLAN_FEATURE_ROAM_OFFLOAD
/**
 * wma_roam_scan_chan_list_event_handler() - roam scan chan list event handler
 * @handle: wma handle
 * @event: pointer to fw event
 * @len: length of event
 *
 * Return: Success or Failure status
 */
int wma_roam_scan_chan_list_event_handler(WMA_HANDLE handle,
					  uint8_t *event,
					  uint32_t len);
#else
static inline int
wma_roam_scan_chan_list_event_handler(WMA_HANDLE handle, uint8_t *event,
				      uint32_t len)
{
	return 0;
}
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#endif

/**
 * wma_update_per_roam_config() -per roam config parameter updation to FW
 * @handle: wma handle
 * @req_buf: per roam config parameters
 *
 * Return: none
 */
void wma_update_per_roam_config(WMA_HANDLE handle,
				 struct wmi_per_roam_config_req *req_buf);

<<<<<<< HEAD
QDF_STATUS wma_get_buf_start_scan_cmd(tp_wma_handle wma_handle,
				      tSirScanOffloadReq *scan_req,
				      struct scan_start_params *cmd);

QDF_STATUS wma_get_buf_stop_scan_cmd(tp_wma_handle wma_handle,
				     wmi_buf_t *buf,
				     int *buf_len,
				     tAbortScanParams *abort_scan_req);

QDF_STATUS wma_start_scan(tp_wma_handle wma_handle,
			  tSirScanOffloadReq *scan_req, uint16_t msg_type);

QDF_STATUS wma_stop_scan(tp_wma_handle wma_handle,
			 tAbortScanParams *abort_scan_req);

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
QDF_STATUS wma_update_channel_list(WMA_HANDLE handle,
				   tSirUpdateChanList *chan_list);

#ifdef WLAN_FEATURE_ROAM_OFFLOAD
QDF_STATUS wma_roam_scan_fill_self_caps(tp_wma_handle wma_handle,
					roam_offload_param *
					roam_offload_params,
<<<<<<< HEAD
					tSirRoamOffloadScanReq *roam_req);
=======
					struct roam_offload_scan_req *roam_req);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#endif

QDF_STATUS wma_roam_scan_offload_mode(tp_wma_handle wma_handle,
				      wmi_start_scan_cmd_fixed_param *
				      scan_cmd_fp,
<<<<<<< HEAD
				      tSirRoamOffloadScanReq *roam_req,
				      uint32_t mode, uint32_t vdev_id);

QDF_STATUS wma_roam_scan_mawc_params(tp_wma_handle wma_handle,
		tSirRoamOffloadScanReq *roam_req);

QDF_STATUS wma_roam_scan_offload_rssi_thresh(tp_wma_handle wma_handle,
					     tSirRoamOffloadScanReq *roam_req);

QDF_STATUS wma_roam_scan_offload_scan_period(tp_wma_handle wma_handle,
					     uint32_t scan_period,
					     uint32_t scan_age,
					     uint32_t vdev_id);
=======
				      struct roam_offload_scan_req *roam_req,
				      uint32_t mode, uint32_t vdev_id);

/**
 * wma_roam_scan_mawc_params() - send roam scan mode request to fw
 * @wma_handle: wma handle
 * @roam_req: roam request param
 *
 * Fill the MAWC roaming parameters and send
 * WMI_ROAM_CONFIGURE_MAWC_CMDID TLV to firmware.
 *
 * Return: QDF status
 */
QDF_STATUS wma_roam_scan_mawc_params(tp_wma_handle wma_handle,
		struct roam_offload_scan_req *roam_req);

/**
 * wma_roam_scan_offload_rssi_threshold() - set scan offload rssi threashold
 * @wma_handle: wma handle
 * @roam_req:   Roaming request buffer
 *
 * Send WMI_ROAM_SCAN_RSSI_THRESHOLD TLV to firmware
 *
 * Return: QDF status
 */
QDF_STATUS
wma_roam_scan_offload_rssi_thresh(tp_wma_handle wma_handle,
				  struct roam_offload_scan_req *roam_req);

QDF_STATUS
wma_roam_scan_offload_scan_period(tp_wma_handle wma_handle,
				  struct roam_offload_scan_req *roam_req);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

QDF_STATUS wma_roam_scan_offload_rssi_change(tp_wma_handle wma_handle,
					     uint32_t vdev_id,
					     int32_t rssi_change_thresh,
					     uint32_t bcn_rssi_weight,
					     uint32_t hirssi_delay_btw_scans);

QDF_STATUS wma_roam_scan_offload_chan_list(tp_wma_handle wma_handle,
					   uint8_t chan_count,
<<<<<<< HEAD
					   uint8_t *chan_list,
					   uint8_t list_type, uint32_t vdev_id);

A_UINT32 e_csr_auth_type_to_rsn_authmode(eCsrAuthType authtype,
=======
					   uint32_t *chan_freq_list,
					   uint8_t list_type, uint32_t vdev_id);

A_UINT32 e_csr_auth_type_to_rsn_authmode(enum csr_akm_type authtype,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
					 eCsrEncryptionType encr);

A_UINT32 e_csr_encryption_type_to_rsn_cipherset(eCsrEncryptionType encr);

void wma_roam_scan_fill_scan_params(tp_wma_handle wma_handle,
<<<<<<< HEAD
				    tpAniSirGlobal pMac,
				    tSirRoamOffloadScanReq *roam_req,
=======
				    struct mac_context *mac,
				    struct roam_offload_scan_req *roam_req,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				    wmi_start_scan_cmd_fixed_param *
				    scan_params);

QDF_STATUS wma_roam_scan_bmiss_cnt(tp_wma_handle wma_handle,
				   A_INT32 first_bcnt,
				   A_UINT32 final_bcnt, uint32_t vdev_id);

QDF_STATUS wma_roam_scan_offload_command(tp_wma_handle wma_handle,
					 uint32_t command, uint32_t vdev_id);

<<<<<<< HEAD
QDF_STATUS wma_roam_preauth_chan_set(tp_wma_handle wma_handle,
				     tpSwitchChannelParams params,
				     uint8_t vdev_id);

QDF_STATUS wma_roam_preauth_chan_cancel(tp_wma_handle wma_handle,
					tpSwitchChannelParams params,
					uint8_t vdev_id);

void wma_roam_preauth_scan_event_handler(tp_wma_handle wma_handle,
						uint8_t vdev_id,
						wmi_scan_event_fixed_param *
						wmi_event);

void wma_set_channel(tp_wma_handle wma, tpSwitchChannelParams params);

#ifdef FEATURE_WLAN_SCAN_PNO
QDF_STATUS wma_pno_start(tp_wma_handle wma, tpSirPNOScanReq pno);

QDF_STATUS wma_pno_stop(tp_wma_handle wma, uint8_t vdev_id);

void wma_config_pno(tp_wma_handle wma, tpSirPNOScanReq pno);
void wma_set_pno_channel_prediction(uint8_t *buf_ptr,
		tpSirPNOScanReq pno);
void wma_scan_cache_updated_ind(tp_wma_handle wma, uint8_t sessionId);
#else
static inline void wma_set_pno_channel_prediction(uint8_t *buf_ptr,
		void *pno)
{
	WMA_LOGD("PNO Channel Prediction feature not supported");
	WMITLV_SET_HDR(buf_ptr, WMITLV_TAG_ARRAY_FIXED_STRUC, 0);
}
#endif

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#ifdef WLAN_FEATURE_ROAM_OFFLOAD
void wma_set_ric_req(tp_wma_handle wma, void *msg, uint8_t is_add_ts);
#endif

#ifdef FEATURE_WLAN_EXTSCAN

int wma_extscan_start_stop_event_handler(void *handle,
					 uint8_t *cmd_param_info,
					 uint32_t len);

int wma_extscan_operations_event_handler(void *handle,
					 uint8_t *cmd_param_info,
					 uint32_t len);

int wma_extscan_table_usage_event_handler(void *handle,
					  uint8_t *cmd_param_info,
					  uint32_t len);

int wma_extscan_capabilities_event_handler(void *handle,
					   uint8_t *cmd_param_info,
					   uint32_t len);

int wma_extscan_hotlist_match_event_handler(void *handle,
					    uint8_t *cmd_param_info,
					    uint32_t len);

int wma_extscan_cached_results_event_handler(void *handle,
					     uint8_t *cmd_param_info,
					     uint32_t len);

int wma_extscan_change_results_event_handler(void *handle,
					     uint8_t *cmd_param_info,
					     uint32_t len);

int wma_passpoint_match_event_handler(void *handle,
				     uint8_t  *cmd_param_info,
				     uint32_t len);

#endif

<<<<<<< HEAD
void wma_register_extscan_event_handler(tp_wma_handle wma_handle);

#ifdef FEATURE_WLAN_EXTSCAN
QDF_STATUS wma_get_buf_extscan_start_cmd(tp_wma_handle wma_handle,
					 tSirWifiScanCmdReqParams *pstart,
					 wmi_buf_t *buf, int *buf_len);

QDF_STATUS wma_start_extscan(tp_wma_handle wma,
			     tSirWifiScanCmdReqParams *pstart);

QDF_STATUS wma_stop_extscan(tp_wma_handle wma,
			    tSirExtScanStopReqParams *pstopcmd);

QDF_STATUS wma_get_buf_extscan_hotlist_cmd(tp_wma_handle wma_handle,
					   tSirExtScanSetBssidHotListReqParams *
					   photlist, int *buf_len);

QDF_STATUS wma_extscan_start_hotlist_monitor(tp_wma_handle wma,
					     tSirExtScanSetBssidHotListReqParams
					     *photlist);

QDF_STATUS wma_extscan_stop_hotlist_monitor(tp_wma_handle wma,
			tSirExtScanResetBssidHotlistReqParams *photlist_reset);

QDF_STATUS wma_get_buf_extscan_change_monitor_cmd(tp_wma_handle wma_handle,
				tSirExtScanSetSigChangeReqParams *psigchange,
				wmi_buf_t *buf, int *buf_len);

QDF_STATUS wma_extscan_start_change_monitor(tp_wma_handle wma,
					    tSirExtScanSetSigChangeReqParams *
					    psigchange);

QDF_STATUS wma_extscan_stop_change_monitor(tp_wma_handle wma,
		   tSirExtScanResetSignificantChangeReqParams *pResetReq);

QDF_STATUS wma_extscan_get_cached_results(tp_wma_handle wma,
					  tSirExtScanGetCachedResultsReqParams *
					  pcached_results);

QDF_STATUS wma_extscan_get_capabilities(tp_wma_handle wma,
					tSirGetExtScanCapabilitiesReqParams *
					pgetcapab);
QDF_STATUS wma_set_epno_network_list(tp_wma_handle wma,
				struct wifi_epno_params *req);

QDF_STATUS wma_set_passpoint_network_list(tp_wma_handle wma,
					struct wifi_passpoint_req *req);

QDF_STATUS wma_reset_passpoint_network_list(tp_wma_handle wma,
					struct wifi_passpoint_req *req);
#endif

QDF_STATUS  wma_ipa_offload_enable_disable(tp_wma_handle wma,
			struct sir_ipa_offload_enable_disable *ipa_offload);

void wma_process_unit_test_cmd(WMA_HANDLE handle,
				      t_wma_unit_test_cmd *wma_utest);

QDF_STATUS wma_scan_probe_setoui(tp_wma_handle wma, tSirScanMacOui *psetoui);

int wma_scan_event_callback(WMA_HANDLE handle, uint8_t *data, uint32_t len);
=======
int wma_handle_btm_blacklist_event(void *handle, uint8_t *cmd_param_info,
				   uint32_t len);

#ifdef FEATURE_WLAN_EXTSCAN
int wma_extscan_wow_event_callback(void *handle, void *event, uint32_t len);

void wma_register_extscan_event_handler(tp_wma_handle wma_handle);

/**
 * wma_start_extscan() - start extscan command to fw.
 * @wma: wma handle
 * @params: extscan command request params
 *
 * This function sends start extscan request to fw.
 *
 * Return: QDF Status.
 */
QDF_STATUS wma_start_extscan(tp_wma_handle wma,
			     struct wifi_scan_cmd_req_params *pstart);

/**
 * wma_stop_extscan() - stop extscan command to fw.
 * @wma: wma handle
 * @params: stop scan command request params
 *
 * This function sends stop extscan request to fw.
 *
 * Return: QDF Status.
 */
QDF_STATUS wma_stop_extscan(tp_wma_handle wma,
			    struct extscan_stop_req_params *params);

/**
 * wma_extscan_start_hotlist_monitor() - start hotlist monitor
 * @wma: wma handle
 * @params: hotlist request params
 *
 * This function configures hotlist monitor in fw.
 *
 * Return: QDF status
 */
QDF_STATUS wma_extscan_start_hotlist_monitor(tp_wma_handle wma,
			struct extscan_bssid_hotlist_set_params *params);

/**
 * wma_extscan_stop_hotlist_monitor() - stop hotlist monitor
 * @wma: wma handle
 * @params: hotlist request params
 *
 * This function configures hotlist monitor to stop in fw.
 *
 * Return: QDF status
 */
QDF_STATUS wma_extscan_stop_hotlist_monitor(tp_wma_handle wma,
			struct extscan_bssid_hotlist_reset_params *params);

/**
 * wma_extscan_start_change_monitor() - send start change monitor cmd
 * @wma: wma handle
 * @params: change monitor request params
 *
 * This function sends start change monitor request to fw.
 *
 * Return: QDF status
 */
QDF_STATUS
wma_extscan_start_change_monitor(tp_wma_handle wma,
			struct extscan_set_sig_changereq_params *params);

/**
 * wma_extscan_stop_change_monitor() - send stop change monitor cmd
 * @wma: wma handle
 * @params: change monitor request params
 *
 * This function sends stop change monitor request to fw.
 *
 * Return: QDF status
 */
QDF_STATUS
wma_extscan_stop_change_monitor(tp_wma_handle wma,
			struct extscan_capabilities_reset_params *params);

/**
 * wma_extscan_get_cached_results() - extscan get cached results
 * @wma: wma handle
 * @params: cached results parameters
 *
 * This function send request to fw to get cached results.
 *
 * Return: QDF status
 */
QDF_STATUS
wma_extscan_get_cached_results(tp_wma_handle wma,
			       struct extscan_cached_result_params *params);

/**
 * wma_extscan_get_capabilities() - extscan get capabilities
 * @wma: wma handle
 * @params: get capabilities params
 *
 * This function sends request to fw to get extscan capabilities.
 *
 * Return: QDF status
 */
QDF_STATUS
wma_extscan_get_capabilities(tp_wma_handle wma,
			     struct extscan_capabilities_params *params);

/**
 * wma_set_epno_network_list() - set epno network list
 * @wma: WMA handle
 * @req: epno config params request structure
 *
 * This function reads the incoming epno config request structure
 * and constructs the WMI message to the firmware.
 *
 * Return: 0 on success, error number otherwise
 */
QDF_STATUS wma_set_epno_network_list(tp_wma_handle wma,
				     struct wifi_enhanced_pno_params *req);

/**
 * wma_set_passpoint_network_list() - set passpoint network list
 * @wma: WMA handle
 * @params: passpoint network request structure
 *
 * This function sends the passpoint configs down to the firmware
 *
 * Return: QDF_STATUS enumeration
 */
QDF_STATUS
wma_set_passpoint_network_list(tp_wma_handle wma,
			       struct wifi_passpoint_req_param *params);

/**
 * wma_reset_passpoint_network_list() - reset passpoint network list
 * @wma: WMA handle
 * @params: passpoint network request structure
 *
 * This function sends down WMI command with network id set to wildcard id.
 * firmware shall clear all the config entries
 *
 * Return: QDF_STATUS enumeration
 */
QDF_STATUS
wma_reset_passpoint_network_list(tp_wma_handle wma,
				 struct wifi_passpoint_req_param *params);
#endif

/**
 * wma_scan_probe_setoui() - set scan probe OUI
 * @wma: wma handle
 * @set_oui: OUI parameters
 *
 * set scan probe OUI parameters in firmware
 *
 * Return: QDF status
 */
QDF_STATUS wma_scan_probe_setoui(tp_wma_handle wma,
				 struct scan_mac_oui *set_oui);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

void wma_roam_better_ap_handler(tp_wma_handle wma, uint32_t vdev_id);

int wma_roam_event_callback(WMA_HANDLE handle, uint8_t *event_buf,
			    uint32_t len);

<<<<<<< HEAD
#ifdef FEATURE_WLAN_SCAN_PNO
int wma_nlo_match_evt_handler(void *handle, uint8_t *event, uint32_t len);

int wma_nlo_scan_cmp_evt_handler(void *handle, uint8_t *event, uint32_t len);
#endif

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#ifdef WLAN_FEATURE_ROAM_OFFLOAD
void wma_process_roam_synch_complete(WMA_HANDLE handle, uint8_t vdev_id);
static inline bool wma_is_roam_synch_in_progress(tp_wma_handle wma,
		uint8_t vdev_id)
{
	return wma->interfaces[vdev_id].roam_synch_in_progress;
}
#else
static inline bool wma_is_roam_synch_in_progress(tp_wma_handle wma,
		uint8_t vdev_id)
{
	return false;
}
<<<<<<< HEAD
static inline uint32_t wma_roam_scan_get_cckm_mode(
		struct sSirRoamOffloadScanReq *roam_req, uint32_t auth_mode)
{
	return WMI_AUTH_CCKM;
}
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#endif

/*
 * wma_dev_if.c functions declarations
 */

<<<<<<< HEAD
void *wma_find_vdev_by_addr(tp_wma_handle wma, uint8_t *addr,
				   uint8_t *vdev_id);

/**
 * wma_find_vdev_by_id() - Returns vdev handle for given vdev id.
 * @wma - wma handle
 * @vdev_id - vdev ID
 *
 * Return: Returns vdev handle if given vdev id is valid.
 *         Otherwise returns NULL.
 */
static inline void *wma_find_vdev_by_id(tp_wma_handle wma, uint8_t vdev_id)
{
	if (vdev_id >= wma->max_bssid)
		return NULL;

	return wma->interfaces[vdev_id].handle;
}

/**
 * wma_get_vdev_count() - Returns number of active vdev.
 * @wma - wma handle
 *
 * Return: Returns valid vdev count.
 */
static inline uint8_t wma_get_vdev_count(tp_wma_handle wma)
{
	uint8_t vdev_count = 0, i;

	for (i = 0; i < wma->max_bssid; i++) {
		if (wma->interfaces[i].handle)
			vdev_count++;
	}
	return vdev_count;
}

bool wma_is_vdev_in_ap_mode(tp_wma_handle wma, uint8_t vdev_id);

#ifdef QCA_IBSS_SUPPORT
bool wma_is_vdev_in_ibss_mode(tp_wma_handle wma, uint8_t vdev_id);
=======
/**
 * wma_find_vdev_id_by_addr() - find vdev_id from mac address
 * @wma: wma handle
 * @addr: mac address
 * @vdev_id: return vdev_id
 *
 * Return: SUCCESS or FAILURE
 */
QDF_STATUS wma_find_vdev_id_by_addr(tp_wma_handle wma, uint8_t *addr,
				    uint8_t *vdev_id);

bool wma_is_vdev_in_ap_mode(tp_wma_handle wma, uint8_t vdev_id);

#ifdef QCA_IBSS_SUPPORT
/**
 * wma_is_vdev_in_ibss_mode() - check that vdev is in ibss mode or not
 * @wma: wma handle
 * @vdev_id: vdev id
 *
 * Helper function to know whether given vdev id
 * is in IBSS mode or not.
 *
 * Return: True/False
 */
bool wma_is_vdev_in_ibss_mode(tp_wma_handle wma, uint8_t vdev_id);

/**
 * wma_adjust_ibss_heart_beat_timer() - set ibss heart beat timer in fw.
 * @wma: wma handle
 * @vdev_id: vdev id
 * @peer_num_delta: peer number delta value
 *
 * Return: none
 */
void wma_adjust_ibss_heart_beat_timer(tp_wma_handle wma,
				      uint8_t vdev_id,
				      int8_t peer_num_delta);

/**
 * wma_set_ibss_pwrsave_params() - set ibss power save parameter to fw
 * @wma: wma handle
 * @vdev_id: vdev id
 *
 * Return: 0 for success or error code.
 */
QDF_STATUS
wma_set_ibss_pwrsave_params(tp_wma_handle wma, uint8_t vdev_id);

/**
 * wma_ibss_peer_info_event_handler() - IBSS peer info event handler
 * @handle: wma handle
 * @data: event data
 * @len: length of data
 *
 * This function handles IBSS peer info event from FW.
 *
 * Return: 0 for success or error code
 */
int wma_ibss_peer_info_event_handler(void *handle, uint8_t *data,
				     uint32_t len);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#else
/**
 * wma_is_vdev_in_ibss_mode(): dummy function
 * @wma: wma handle
 * @vdev_id: vdev id
 *
 * Return false since no vdev can be in ibss mode without ibss support
 */
static inline
bool wma_is_vdev_in_ibss_mode(tp_wma_handle wma, uint8_t vdev_id)
{
	return false;
}
<<<<<<< HEAD
#endif

/**
 * wma_is_vdev_in_beaconning_mode() - check if vdev is in a beaconning mode
 * @wma: wma handle
 * @vdev_id: vdev id
 *
 * Helper function to know whether given vdev id
 * is in a beaconning mode or not.
 *
 * Return: True if vdev needs to beacon.
 */
static inline
bool wma_is_vdev_in_beaconning_mode(tp_wma_handle wma, uint8_t vdev_id)
{
	return wma_is_vdev_in_ap_mode(wma, vdev_id) ||
		wma_is_vdev_in_ibss_mode(wma, vdev_id);
}

/**
 * wma_find_bssid_by_vdev_id() - Get the BSS ID corresponding to the vdev ID
 * @wma - wma handle
 * @vdev_id - vdev ID
 *
 * Return: Returns pointer to bssid on success,
 *         otherwise returns NULL.
 */
static inline uint8_t *wma_find_bssid_by_vdev_id(tp_wma_handle wma,
						 uint8_t vdev_id)
{
	if (vdev_id >= wma->max_bssid)
		return NULL;

	return wma->interfaces[vdev_id].bssid;
}

void *wma_find_vdev_by_bssid(tp_wma_handle wma, uint8_t *bssid,
				    uint8_t *vdev_id);

QDF_STATUS wma_vdev_detach(tp_wma_handle wma_handle,
			struct del_sta_self_params *pdel_sta_self_req_param,
			uint8_t generateRsp);

int wma_vdev_start_resp_handler(void *handle, uint8_t *cmd_param_info,
				       uint32_t len);

QDF_STATUS wma_vdev_set_param(wmi_unified_t wmi_handle, uint32_t if_id,
				uint32_t param_id, uint32_t param_value);

void wma_remove_peer(tp_wma_handle wma, uint8_t *bssid,
			    uint8_t vdev_id, ol_txrx_peer_handle peer,
			    bool roam_synch_in_progress);

QDF_STATUS wma_create_peer(tp_wma_handle wma, ol_txrx_pdev_handle pdev,
			  ol_txrx_vdev_handle vdev,
			  u8 peer_addr[IEEE80211_ADDR_LEN],
			  uint32_t peer_type, uint8_t vdev_id,
			  bool roam_synch_in_progress);

int wma_vdev_stop_resp_handler(void *handle, uint8_t *cmd_param_info,
				      u32 len);

ol_txrx_vdev_handle wma_vdev_attach(tp_wma_handle wma_handle,
				struct add_sta_self_params *self_sta_req,
				uint8_t generateRsp);

QDF_STATUS wma_vdev_start(tp_wma_handle wma, struct wma_vdev_start_req *req,
			  bool isRestart);

void wma_vdev_resp_timer(void *data);

int wma_set_packet_capture_mode(tp_wma_handle wma_handle,
				uint8_t vdev_id,
				uint8_t val);

struct wma_target_req *wma_fill_vdev_req(tp_wma_handle wma,
						uint8_t vdev_id,
						uint32_t msg_type, uint8_t type,
						void *params, uint32_t timeout);
=======

/**
 * wma_adjust_ibss_heart_beat_timer() - set ibss heart beat timer in fw.
 * @wma: wma handle
 * @vdev_id: vdev id
 * @peer_num_delta: peer number delta value
 *
 * This function is dummy
 *
 * Return: none
 */
static inline void
wma_adjust_ibss_heart_beat_timer(tp_wma_handle wma,
				 uint8_t vdev_id,
				 int8_t peer_num_delta)
{
}

/**
 * wma_ibss_peer_info_event_handler() - IBSS peer info event handler
 * @handle: wma handle
 * @data: event data
 * @len: length of data
 *
 * This function is dummy
 *
 * Return: 0 for success or error code
 */
static inline int
wma_ibss_peer_info_event_handler(void *handle, uint8_t *data,
				 uint32_t len)
{
	return 0;
}

/**
 * wma_set_ibss_pwrsave_params() - set ibss power save parameter to fw
 * @wma: wma handle
 * @vdev_id: vdev id
 *
 * This function is dummy
 *
 * Return: 0 for success or error code.
 */
static inline QDF_STATUS
wma_set_ibss_pwrsave_params(tp_wma_handle wma, uint8_t vdev_id)
{
	return QDF_STATUS_SUCCESS;
}
#endif /* QCA_IBSS_SUPPORT */

/**
 * wma_get_vdev_bssid() - Get BSSID from mlme_obj
 * @vdev - pointer to vdev
 *
 * This API is used to get BSSID stored in vdev mlme object.
 *
 * Return: pointer to bssid on success else NULL.
 */
uint8_t *wma_get_vdev_bssid(struct wlan_objmgr_vdev *vdev);

/**
 * wma_find_bssid_by_vdev_id() - Get the BSS ID corresponding to the vdev ID
 * @wma - wma handle
 * @vdev_id - vdev ID
 *
 * Return: Returns pointer to bssid on success,
 *         otherwise returns NULL.
 */
static inline uint8_t *wma_find_bssid_by_vdev_id(tp_wma_handle wma,
						 uint8_t vdev_id)
{
	if (vdev_id >= wma->max_bssid)
		return NULL;

	return wma_get_vdev_bssid(wma->interfaces[vdev_id].vdev);
}

/**
 * wma_find_vdev_id_by_bssid() - Get the corresponding vdev_id from BSSID
 * @wma - wma handle
 * @bssid - bssid address
 * @vdev_id - vdev ID
 *
 * Return: SUCCESS or FAILURE.
 */
QDF_STATUS wma_find_vdev_id_by_bssid(tp_wma_handle wma, uint8_t *bssid,
				     uint8_t *vdev_id);

/**
 * wma_vdev_detach() - send vdev delete command to fw
 * @wma_handle: wma handle
 * @pdel_vdev_req_param: del vdev params
 *
 * Return: QDF status
 */
QDF_STATUS wma_vdev_detach(tp_wma_handle wma_handle,
			struct del_vdev_params *pdel_vdev_req_param);

QDF_STATUS wma_vdev_set_param(wmi_unified_t wmi_handle, uint32_t if_id,
				uint32_t param_id, uint32_t param_value);

QDF_STATUS wma_remove_peer(tp_wma_handle wma, uint8_t *mac_addr,
			   uint8_t vdev_id, bool no_fw_peer_delete);

QDF_STATUS wma_peer_unmap_conf_send(tp_wma_handle wma,
				    struct send_peer_unmap_conf_params *msg);

QDF_STATUS wma_create_peer(tp_wma_handle wma,
			   uint8_t peer_addr[QDF_MAC_ADDR_SIZE],
			   uint32_t peer_type, uint8_t vdev_id,
			   bool roam_synch_in_progress);

/**
 * wma_send_del_bss_response() - send delete bss resp
 * @wma: wma handle
 * @resp: pointer to del bss response
 *
 * Return: none
 */
void wma_send_del_bss_response(tp_wma_handle wma, struct del_bss_resp *resp);

/**
 * __wma_handle_vdev_stop_rsp() - vdev stop response handler
 * @resp_event: pointer to response received
 *
 * Return: QDF_STATUS_SUCCESS for success or QDF_ERROR code
 */
QDF_STATUS
__wma_handle_vdev_stop_rsp(struct vdev_stop_response *resp_event);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

void wma_hold_req_timer(void *data);
struct wma_target_req *wma_fill_hold_req(tp_wma_handle wma,
				    uint8_t vdev_id, uint32_t msg_type,
				    uint8_t type, void *params,
				    uint32_t timeout);

<<<<<<< HEAD
void wma_remove_vdev_req(tp_wma_handle wma, uint8_t vdev_id,
				uint8_t type);

void wma_add_bss(tp_wma_handle wma, tpAddBssParams params);

void wma_add_sta(tp_wma_handle wma, tpAddStaParams add_sta);

void wma_delete_sta(tp_wma_handle wma, tpDeleteStaParams del_sta);

void wma_delete_bss(tp_wma_handle wma, tpDeleteBssParams params);

int32_t wma_find_vdev_by_type(tp_wma_handle wma, int32_t type);

void wma_set_vdev_intrabss_fwd(tp_wma_handle wma_handle,
				      tpDisableIntraBssFwd pdis_intra_fwd);

void wma_delete_bss_ho_fail(tp_wma_handle wma, tpDeleteBssParams params);
=======
/**
 * wma_add_bss() - Add BSS request to fw as per opmode
 * @wma: wma handle
 * @params: add bss params
 *
 * Return: none
 */
void wma_add_bss(tp_wma_handle wma, struct bss_params *params);

/**
 * wma_add_sta() - process add sta request as per opmode
 * @wma: wma handle
 * @add_Sta: add sta params
 *
 * Return: none
 */
void wma_add_sta(tp_wma_handle wma, tpAddStaParams add_sta);

/**
 * wma_delete_sta() - process del sta request as per opmode
 * @wma: wma handle
 * @del_sta: delete sta params
 *
 * Return: none
 */
void wma_delete_sta(tp_wma_handle wma, tpDeleteStaParams del_sta);

/**
 * wma_delete_bss() - process delete bss request from upper layer
 * @wma: wma handle
 * @vdev_id: vdev id
 *
 * Return: none
 */
void wma_delete_bss(tp_wma_handle wma, uint8_t vdev_id);

int32_t wma_find_vdev_by_type(tp_wma_handle wma, int32_t type);

/**
 * wma_set_vdev_intrabss_fwd() - set intra_fwd value to wni_in.
 * @wma_handle: wma handle
 * @pdis_intra_fwd: Pointer to DisableIntraBssFwd struct
 *
 * Return: none
 */
void wma_set_vdev_intrabss_fwd(tp_wma_handle wma_handle,
				      tpDisableIntraBssFwd pdis_intra_fwd);

/**
 * wma_delete_bss_ho_fail() - process delete bss request for handoff failure
 * @wma: wma handle
 * @vdev_id: vdev id
 *
 * Delete BSS in case of ROAM_HO_FAIL processing is handled separately in
 * this routine. It needs to be done without sending any commands to firmware
 * because firmware has already stopped and deleted peer and vdev is down.
 * Relevant logic is aggregated from other routines. It changes the host
 * data structures without sending VDEV_STOP, PEER_FLUSH_TIDS, PEER_DELETE
 * and VDEV_DOWN commands to firmware.
 *
 * Return: none
 */
void wma_delete_bss_ho_fail(tp_wma_handle wma, uint8_t vdev_id);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

uint32_t wma_get_bcn_rate_code(uint16_t rate);

/*
 * wma_mgmt.c functions declarations
 */
<<<<<<< HEAD

int wma_beacon_swba_handler(void *handle, uint8_t *event, uint32_t len);

int wma_peer_sta_kickout_event_handler(void *handle, u8 *event, u32 len);

void wma_extscan_wow_event_callback(void *handle, void *event, uint32_t len);

=======
#ifdef WLAN_WMI_BCN
int wma_beacon_swba_handler(void *handle, uint8_t *event, uint32_t len);
#endif

/**
 * wma_peer_sta_kickout_event_handler() - kickout event handler
 * @handle: wma handle
 * @event: event data
 * @len: data length
 *
 * Kickout event is received from firmware on observing beacon miss
 * It handles kickout event for different modes and indicate to
 * upper layers.
 *
 * Return: 0 for success or error code
 */
int wma_peer_sta_kickout_event_handler(void *handle, uint8_t *event,
				       uint32_t len);

/**
 * wma_unified_bcntx_status_event_handler() - beacon tx status event handler
 * @handle: wma handle
 * @cmd_param_info: event data
 * @len: data length
 *
 * WMI Handler for WMI_OFFLOAD_BCN_TX_STATUS_EVENTID event from firmware.
 * This event is generated by FW when the beacon transmission is offloaded
 * and the host performs beacon template modification using WMI_BCN_TMPL_CMDID
 * The FW generates this event when the first successful beacon transmission
 * after template update
 *
 * Return: 0 for success or error code
 */
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
int wma_unified_bcntx_status_event_handler(void *handle,
					   uint8_t *cmd_param_info,
					   uint32_t len);

void wma_set_sta_sa_query_param(tp_wma_handle wma,
				  uint8_t vdev_id);

void wma_set_sta_keep_alive(tp_wma_handle wma, uint8_t vdev_id,
				   uint32_t method, uint32_t timeperiod,
				   uint8_t *hostv4addr, uint8_t *destv4addr,
				   uint8_t *destmac);

int wma_vdev_install_key_complete_event_handler(void *handle,
						uint8_t *event,
						uint32_t len);

<<<<<<< HEAD
=======
/**
 * wma_objmgr_set_peer_mlme_phymode() - set phymode to peer object
 * @wma:      wma handle
 * @mac_addr: mac addr of peer
 * @phymode:  phymode value to set
 *
 * Return: None
 */
void wma_objmgr_set_peer_mlme_phymode(tp_wma_handle wma, uint8_t *mac_addr,
				      enum wlan_phymode phymode);

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
QDF_STATUS wma_send_peer_assoc(tp_wma_handle wma,
					   tSirNwType nw_type,
					   tpAddStaParams params);

QDF_STATUS wmi_unified_vdev_set_gtx_cfg_send(wmi_unified_t wmi_handle,
				  uint32_t if_id,
				  gtx_config_t *gtx_info);

void wma_update_protection_mode(tp_wma_handle wma, uint8_t vdev_id,
			   uint8_t llbcoexist);

void wma_process_update_beacon_params(tp_wma_handle wma,
				 tUpdateBeaconParams *bcn_params);

<<<<<<< HEAD
void wma_update_cfg_params(tp_wma_handle wma, tSirMsgQ *cfgParam);

void wma_set_bsskey(tp_wma_handle wma_handle, tpSetBssKeyParams key_info);

void wma_adjust_ibss_heart_beat_timer(tp_wma_handle wma,
				      uint8_t vdev_id,
				      int8_t peer_num_delta);

void wma_set_stakey(tp_wma_handle wma_handle, tpSetStaKeyParams key_info);
=======
/**
 * wma_update_rts_params() - update cfg parameters to target
 * @wma: wma handle
 * @value: rts_threshold
 *
 * Return: none
 */
void wma_update_rts_params(tp_wma_handle wma, uint32_t value);

/**
 * wma_update_frag_params() - update cfg parameters to target
 * @wma: wma handle
 * @value: frag_threshold
 *
 * Return: none
 */
void wma_update_frag_params(tp_wma_handle wma, uint32_t value);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

QDF_STATUS wma_process_update_edca_param_req(WMA_HANDLE handle,
						    tEdcaParams *edca_params);

<<<<<<< HEAD
=======
/**
 * wma_tbttoffset_update_event_handler() - tbtt offset update handler
 * @handle: wma handle
 * @event: event buffer
 * @len: data length
 *
 * Return: 0 for success or error code
 */
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
int wma_tbttoffset_update_event_handler(void *handle, uint8_t *event,
					       uint32_t len);

void wma_send_probe_rsp_tmpl(tp_wma_handle wma,
				    tpSendProbeRespParams probe_rsp_info);

<<<<<<< HEAD
void wma_send_beacon(tp_wma_handle wma, tpSendbeaconParams bcn_info);

void wma_set_keepalive_req(tp_wma_handle wma,
				  tSirKeepAliveReq *keepalive);
=======
/**
 * wma_set_ap_vdev_up() - send vdev up req
 * @wma: wma handle
 * @vdev_id: vdev id
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wma_set_ap_vdev_up(tp_wma_handle wma, uint8_t vdev_id);

void wma_send_beacon(tp_wma_handle wma, tpSendbeaconParams bcn_info);

void wma_set_keepalive_req(tp_wma_handle wma,
				  struct keep_alive_req *keepalive);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

void wma_beacon_miss_handler(tp_wma_handle wma, uint32_t vdev_id,
			     int32_t rssi);

void wma_process_update_opmode(tp_wma_handle wma_handle,
				      tUpdateVHTOpMode *update_vht_opmode);

void wma_process_update_rx_nss(tp_wma_handle wma_handle,
				      tUpdateRxNss *update_rx_nss);

void wma_process_update_membership(tp_wma_handle wma_handle,
					  tUpdateMembership *membership);

void wma_process_update_userpos(tp_wma_handle wma_handle,
				       tUpdateUserPos *userpos);

<<<<<<< HEAD
void wma_hidden_ssid_vdev_restart(tp_wma_handle wma_handle,
				  tHalHiddenSsidVdevRestart *pReq);

int
wma_mgmt_offload_data_event_handler(void *handle, uint8_t *data,
				    uint32_t data_len);

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/*
 * wma_power.c functions declarations
 */

<<<<<<< HEAD
void wma_enable_sta_ps_mode(tp_wma_handle wma, tpEnablePsParams ps_req);
=======
/**
 * wma_enable_sta_ps_mode() - enable sta powersave params in fw
 * @ps_req: power save request
 *
 * Return: none
 */
void wma_enable_sta_ps_mode(tpEnablePsParams ps_req);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

QDF_STATUS wma_unified_set_sta_ps_param(wmi_unified_t wmi_handle,
					    uint32_t vdev_id, uint32_t param,
					    uint32_t value);

<<<<<<< HEAD
QDF_STATUS
wma_set_ibss_pwrsave_params(tp_wma_handle wma, uint8_t vdev_id);

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
QDF_STATUS wma_set_ap_peer_uapsd(tp_wma_handle wma, uint32_t vdev_id,
				     uint8_t *peer_addr, uint8_t uapsd_value,
				     uint8_t max_sp);

void wma_update_edca_params_for_ac(tSirMacEdcaParamRecord *edca_param,
<<<<<<< HEAD
					  wmi_wmm_vparams *wmm_param, int ac);
=======
				   struct wmi_host_wme_vparams *wmm_param,
				   int ac, bool mu_edca_param);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

void wma_set_tx_power(WMA_HANDLE handle,
			     tMaxTxPowerParams *tx_pwr_params);

void wma_set_max_tx_power(WMA_HANDLE handle,
				 tMaxTxPowerParams *tx_pwr_params);

<<<<<<< HEAD
void wma_disable_sta_ps_mode(tp_wma_handle wma, tpDisablePsParams ps_req);

=======
void wma_disable_sta_ps_mode(tpDisablePsParams ps_req);

/**
 * wma_send_max_tx_pwrlmt() - send max tx power limit to fw
 * @handle: wma handle
 * @vdev_id: vdev id
 *
 * Return: none
 */
void wma_send_max_tx_pwrlmt(WMA_HANDLE handle, uint8_t vdev_id);

/**
 * wma_enable_uapsd_mode() - enable uapsd mode in fw
 * @wma: wma handle
 * @ps_req: power save request
 *
 * Return: none
 */
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
void wma_enable_uapsd_mode(tp_wma_handle wma, tpEnableUapsdParams ps_req);

void wma_disable_uapsd_mode(tp_wma_handle wma, tpDisableUapsdParams ps_req);

QDF_STATUS wma_get_temperature(tp_wma_handle wma_handle);

int wma_pdev_temperature_evt_handler(void *handle, uint8_t *event,
					    uint32_t len);

QDF_STATUS wma_process_tx_power_limits(WMA_HANDLE handle,
<<<<<<< HEAD
				       tSirTxPowerLimit *ptxlim);
=======
				       struct tx_power_limit *ptxlim);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

void wma_update_noa(struct beacon_info *beacon,
			   struct p2p_sub_element_noa *noa_ie);

void wma_update_probe_resp_noa(tp_wma_handle wma_handle,
				      struct p2p_sub_element_noa *noa_ie);

<<<<<<< HEAD
int wma_p2p_noa_event_handler(void *handle, uint8_t *event,
				     uint32_t len);

void wma_process_set_p2pgo_noa_req(tp_wma_handle wma,
					  tP2pPsParams *ps_params);

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
void wma_process_set_mimops_req(tp_wma_handle wma_handle,
				       tSetMIMOPS *mimops);

QDF_STATUS wma_set_mimops(tp_wma_handle wma, uint8_t vdev_id, int value);

QDF_STATUS wma_notify_modem_power_state(void *wma_ptr,
					tSirModemPowerStateInd *pReq);

QDF_STATUS wma_set_smps_params(tp_wma_handle wma, uint8_t vdev_id,
				      int value);

<<<<<<< HEAD
void wma_set_suspend_dtim(tp_wma_handle wma);

void wma_set_resume_dtim(tp_wma_handle wma);

/*
 * wma_data.c functions declarations
 */


void wma_set_bss_rate_flags(struct wma_txrx_node *iface,
				   tpAddBssParams add_bss);
=======
/*
 * wma_data.c functions declarations
 */
/**
 * wma_set_bss_rate_flags() - set rate flags based on BSS capability
 * @wma: pointer to wma handle
 * @vdev_id: vdev id
 * @add_bss: pointer to bss params
 *
 * Return: none
 */
void wma_set_bss_rate_flags(tp_wma_handle wma, uint8_t vdev_id,
			    struct bss_params *add_bss);

/**
 * wma_get_vht_rate_flags() - Return the VHT rate flags corresponding to the BW
 * @ch_width: BW for which rate flags is required
 *
 * Return: Rate flags corresponding to ch_width
 */
enum tx_rate_info wma_get_vht_rate_flags(enum phy_ch_width ch_width);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

int32_t wmi_unified_send_txbf(tp_wma_handle wma, tpAddStaParams params);

/**
 * wma_check_txrx_chainmask() - check txrx chainmask
 * @num_rf_chains: number of rf chains
 * @cmd_value: command value
 *
 * Return: QDF_STATUS_SUCCESS for success or error code
 */
QDF_STATUS wma_check_txrx_chainmask(int num_rf_chains, int cmd_value);

int wma_peer_state_change_event_handler(void *handle,
					       uint8_t *event_buff,
					       uint32_t len);

QDF_STATUS wma_set_enable_disable_mcc_adaptive_scheduler(uint32_t
						mcc_adaptive_scheduler);

QDF_STATUS wma_set_mcc_channel_time_latency
	(tp_wma_handle wma,
	uint32_t mcc_channel, uint32_t mcc_channel_time_latency);

QDF_STATUS wma_set_mcc_channel_time_quota
	(tp_wma_handle wma,
	uint32_t adapter_1_chan_number,
	uint32_t adapter_1_quota, uint32_t adapter_2_chan_number);

<<<<<<< HEAD
void wma_set_linkstate(tp_wma_handle wma, tpLinkStateParams params);

void wma_unpause_vdev(tp_wma_handle wma);

=======
/**
 * wma_process_rate_update_indate() - rate update indication
 * @wma: wma handle
 * @pRateUpdateParams: Rate update params
 *
 * This function update rate & short GI interval to fw based on params
 * send by SME.
 *
 * Return: QDF status
 */
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
QDF_STATUS wma_process_rate_update_indicate(tp_wma_handle wma,
					    tSirRateUpdateInd *
					    pRateUpdateParams);

QDF_STATUS wma_tx_attach(tp_wma_handle wma_handle);

QDF_STATUS wma_tx_detach(tp_wma_handle wma_handle);

#if defined(QCA_LL_LEGACY_TX_FLOW_CONTROL) || \
	defined(QCA_LL_TX_FLOW_CONTROL_V2) || defined(CONFIG_HL_SUPPORT)

<<<<<<< HEAD
=======
/**
 * wma_mcc_vdev_tx_pause_evt_handler() - pause event handler
 * @handle: wma handle
 * @event: event buffer
 * @len: data length
 *
 * This function handle pause event from fw and pause/unpause
 * vdev.
 *
 * Return: 0 for success or error code.
 */
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
int wma_mcc_vdev_tx_pause_evt_handler(void *handle, uint8_t *event,
					     uint32_t len);
#endif

#if defined(CONFIG_HL_SUPPORT) && defined(QCA_BAD_PEER_TX_FLOW_CL)
QDF_STATUS wma_process_init_bad_peer_tx_ctl_info(tp_wma_handle wma,
					struct t_bad_peer_txtcl_config *config);
#else
static inline QDF_STATUS
wma_process_init_bad_peer_tx_ctl_info(tp_wma_handle wma,
			struct t_bad_peer_txtcl_config *config)
{
	return QDF_STATUS_E_FAILURE;
}
#endif

QDF_STATUS wma_process_init_thermal_info(tp_wma_handle wma,
					 t_thermal_mgmt *pThermalParams);

QDF_STATUS wma_process_set_thermal_level(tp_wma_handle wma,
					 uint8_t thermal_level);

QDF_STATUS wma_set_thermal_mgmt(tp_wma_handle wma_handle,
				       t_thermal_cmd_params thermal_info);

int wma_thermal_mgmt_evt_handler(void *handle, uint8_t *event,
					uint32_t len);

<<<<<<< HEAD
int wma_ibss_peer_info_event_handler(void *handle, uint8_t *data,
					    uint32_t len);

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
int wma_fast_tx_fail_event_handler(void *handle, uint8_t *data,
					  uint32_t len);

/*
 * wma_utils.c functions declarations
 */

#ifdef WLAN_FEATURE_STATS_EXT
<<<<<<< HEAD
=======
/**
 * wma_stats_ext_event_handler() - extended stats event handler
 * @handle:     wma handle
 * @event_buf:  event buffer received from fw
 * @len:        length of data
 *
 * Return: 0 for success or error code
 */
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
int wma_stats_ext_event_handler(void *handle, uint8_t *event_buf,
				       uint32_t len);
#endif

enum eSmpsModeValue host_map_smps_mode(A_UINT32 fw_smps_mode);
int wma_smps_mode_to_force_mode_param(uint8_t smps_mode);

#ifdef WLAN_FEATURE_LINK_LAYER_STATS
void wma_register_ll_stats_event_handler(tp_wma_handle wma_handle);

<<<<<<< HEAD
=======
/**
 * wma_process_ll_stats_clear_req() - clear link layer stats
 * @wma: wma handle
 * @clearReq: ll stats clear request command params
 *
 * Return: QDF_STATUS_SUCCESS for success or error code
 */
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
QDF_STATUS wma_process_ll_stats_clear_req
	(tp_wma_handle wma, const tpSirLLStatsClearReq clearReq);

QDF_STATUS wma_process_ll_stats_set_req
	(tp_wma_handle wma, const tpSirLLStatsSetReq setReq);

<<<<<<< HEAD
=======
/**
 * wma_process_ll_stats_get_req() - link layer stats get request
 * @wma:wma handle
 * @getReq:ll stats get request command params
 *
 * Return: QDF_STATUS_SUCCESS for success or error code
 */
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
QDF_STATUS wma_process_ll_stats_get_req
	(tp_wma_handle wma, const tpSirLLStatsGetReq getReq);

int wma_unified_link_iface_stats_event_handler(void *handle,
					       uint8_t *cmd_param_info,
					       uint32_t len);
void wma_config_stats_ext_threshold(tp_wma_handle wma,
				    struct sir_ll_ext_stats_threshold *thresh);
#endif

void wma_post_link_status(tAniGetLinkStatus *pGetLinkStatus,
			  uint8_t link_status);

<<<<<<< HEAD
int wma_link_status_event_handler(void *handle, uint8_t *cmd_param_info,
				  uint32_t len);
=======
/**
 * wma_link_status_event_handler() - link status event handler
 * @handle: wma handle
 * @cmd_param_info: data from event
 * @len: length
 *
 * Return: 0 for success or error code
 */
int wma_link_status_event_handler(void *handle, uint8_t *cmd_param_info,
				  uint32_t len);

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/**
 * wma_rso_cmd_status_event_handler() - RSO Command status event handler
 * @wmi_event: WMI event
 *
 * This function is used to send RSO command status to upper layer
 *
 * Return: 0 for success
 */
int wma_rso_cmd_status_event_handler(wmi_roam_event_fixed_param *wmi_event);
<<<<<<< HEAD
=======

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
int wma_stats_event_handler(void *handle, uint8_t *cmd_param_info,
			    uint32_t len);

QDF_STATUS wma_send_link_speed(uint32_t link_speed);

int wma_link_speed_event_handler(void *handle, uint8_t *cmd_param_info,
				 uint32_t len);

QDF_STATUS wma_wni_cfg_dnld(tp_wma_handle wma_handle);

int wma_unified_debug_print_event_handler(void *handle, uint8_t *datap,
					  uint32_t len);

<<<<<<< HEAD
bool wma_is_sap_active(tp_wma_handle wma_handle);

bool wma_is_p2p_go_active(tp_wma_handle wma_handle);

bool wma_is_p2p_cli_active(tp_wma_handle wma_handle);

bool wma_is_sta_active(tp_wma_handle wma_handle);

WLAN_PHY_MODE wma_peer_phymode(tSirNwType nw_type, uint8_t sta_type,
			       uint8_t is_ht, uint8_t ch_width,
			       uint8_t is_vht);
=======
/**
 * wma_peer_phymode() - get phymode
 * @nw_type: nw type
 * @sta_type: sta type
 * @is_ht: is ht supported
 * @ch_width: supported channel width
 * @is_vht: is vht supported
 * @is_he: is HE supported
 *
 * Return: host phymode
 */
enum wlan_phymode
wma_peer_phymode(tSirNwType nw_type, uint8_t sta_type,
		 uint8_t is_ht, uint8_t ch_width,
		 uint8_t is_vht, bool is_he);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

int32_t wma_txrx_fw_stats_reset(tp_wma_handle wma_handle,
				uint8_t vdev_id, uint32_t value);

int32_t wma_set_txrx_fw_stats_level(tp_wma_handle wma_handle,
				    uint8_t vdev_id, uint32_t value);

<<<<<<< HEAD
void wma_get_stats_req(WMA_HANDLE handle,
		       tAniGetPEStatsReq *get_stats_param);

#if defined(QCA_WIFI_FTM)
void wma_utf_detach(tp_wma_handle wma_handle);

void wma_utf_attach(tp_wma_handle wma_handle);

QDF_STATUS
wma_process_ftm_command(tp_wma_handle wma_handle,
			struct ar6k_testmode_cmd_data *msg_buffer);
#endif

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/*
 * wma_features.c functions declarations
 */

/**
 * wma_sar_register_event_handlers() - Register SAR event handlers
 * @handle: WMA Handle
 *
 * Function to be called during WMA initialization to register SAR
 * event handlers with WMI
 *
 * Return: QDF_STATUS_SUCCESS if registration is successful, otherwise
 *         an error enumeration
 */
QDF_STATUS wma_sar_register_event_handlers(WMA_HANDLE handle);

void wma_process_link_status_req(tp_wma_handle wma,
				 tAniGetLinkStatus *pGetLinkStatus);

<<<<<<< HEAD
#ifdef FEATURE_WLAN_LPHB
QDF_STATUS wma_process_lphb_conf_req(tp_wma_handle wma_handle,
				     tSirLPHBReq *lphb_conf_req);

#endif

QDF_STATUS wma_process_dhcp_ind(tp_wma_handle wma_handle,
				tAniDHCPInd *ta_dhcp_ind);

QDF_STATUS wma_get_peer_info(WMA_HANDLE handle,
				struct sir_peer_info_req *peer_info_req);

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/**
 * wma_get_peer_info_ext() - get peer info
 * @handle: wma interface
 * @peer_info_req: get peer info request information
 *
 * This function will send WMI_REQUEST_PEER_STATS_INFO_CMDID to FW
 *
 * Return: 0 on success, otherwise error value
 */
QDF_STATUS wma_get_peer_info_ext(WMA_HANDLE handle,
				struct sir_peer_info_ext_req *peer_info_req);

/**
<<<<<<< HEAD
=======
 * wma_get_isolation() - get antenna isolation
 * @handle: wma interface
 *
 * This function will send WMI_COEX_GET_ANTENNA_ISOLATION_CMDID to FW
 *
 * Return: 0 on success, otherwise error value
 */
QDF_STATUS wma_get_isolation(tp_wma_handle wma);

/**
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * wma_peer_info_event_handler() - Handler for WMI_PEER_STATS_INFO_EVENTID
 * @handle: WMA global handle
 * @cmd_param_info: Command event data
 * @len: Length of cmd_param_info
 *
 * This function will handle WMI_PEER_STATS_INFO_EVENTID
 *
 * Return: 0 on success, error code otherwise
 */
int wma_peer_info_event_handler(void *handle, u_int8_t *cmd_param_info,
				   u_int32_t len);

int wma_profile_data_report_event_handler(void *handle, uint8_t *event_buf,
				       uint32_t len);

QDF_STATUS wma_unified_fw_profiling_cmd(wmi_unified_t wmi_handle,
				uint32_t cmd, uint32_t value1, uint32_t value2);

<<<<<<< HEAD
void wma_wow_tx_complete(void *wma);

int wmi_unified_nat_keepalive_enable(tp_wma_handle wma, uint8_t vdev_id);

int wma_unified_csa_offload_enable(tp_wma_handle wma, uint8_t vdev_id);

#ifdef WLAN_FEATURE_NAN
int wma_nan_rsp_event_handler(void *handle, uint8_t *event_buf, uint32_t len);
#endif

=======
int wma_unified_csa_offload_enable(tp_wma_handle wma, uint8_t vdev_id);

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#ifdef FEATURE_WLAN_TDLS
int wma_tdls_event_handler(void *handle, uint8_t *event, uint32_t len);
#endif

int wma_csa_offload_handler(void *handle, uint8_t *event, uint32_t len);

<<<<<<< HEAD
#ifdef WLAN_FEATURE_GTK_OFFLOAD
int wma_gtk_offload_status_event(void *handle, uint8_t *event, uint32_t len);
#endif

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#ifdef FEATURE_OEM_DATA_SUPPORT
int wma_oem_data_response_handler(void *handle, uint8_t *datap,
				  uint32_t len);
#endif

<<<<<<< HEAD
int
wma_unified_dfs_phyerr_filter_offload_enable(tp_wma_handle wma_handle);

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#if !defined(REMOVE_PKT_LOG)
QDF_STATUS wma_pktlog_wmi_send_cmd(WMA_HANDLE handle,
				   struct ath_pktlog_wmi_params *params);
#endif
<<<<<<< HEAD
int wma_d0_wow_disable_ack_event(void *handle, u_int8_t *event,
				u_int32_t len);
int wma_wow_wakeup_host_event(void *handle, uint8_t *event,
				     uint32_t len);
int wma_pdev_resume_event_handler(void *handle, uint8_t *event, uint32_t len);

/**
 * wma_get_wow_bus_suspend() - check is wow bus suspended or not
 * @wma: wma handle
 *
 * Return: true/false
 */
static inline int wma_get_wow_bus_suspend(tp_wma_handle wma)
{

	return qdf_atomic_read(&wma->is_wow_bus_suspended);
}

QDF_STATUS wma_resume_req(tp_wma_handle wma, enum qdf_suspend_type type);

QDF_STATUS wma_wow_add_pattern(tp_wma_handle wma,
			struct wow_add_pattern *ptrn);

QDF_STATUS wma_wow_delete_user_pattern(tp_wma_handle wma,
			struct wow_delete_pattern *pattern);

QDF_STATUS wma_wow_enter(tp_wma_handle wma, tpSirHalWowlEnterParams info);

QDF_STATUS wma_wow_exit(tp_wma_handle wma, tpSirHalWowlExitParams info);

QDF_STATUS wma_suspend_req(tp_wma_handle wma, enum qdf_suspend_type type);
void wma_calculate_and_update_conn_state(tp_wma_handle wma);
void wma_update_conn_state(tp_wma_handle wma, uint32_t conn_mask);
void wma_update_conn_state(tp_wma_handle wma, uint32_t conn_mask);

void wma_del_ts_req(tp_wma_handle wma, tDelTsParams *msg);

void wma_aggr_qos_req(tp_wma_handle wma,
			     tAggrAddTsParams *pAggrQosRspMsg);

void wma_add_ts_req(tp_wma_handle wma, tAddTsParams *msg);

int wma_process_receive_filter_set_filter_req(tp_wma_handle wma_handle,
						     tSirRcvPktFilterCfgType *
						     rcv_filter_param);

int wma_process_receive_filter_clear_filter_req(tp_wma_handle wma_handle,
						       tSirRcvFltPktClearParam *
						       rcv_clear_param);
=======

int wma_wow_wakeup_host_event(void *handle, uint8_t *event,
				     uint32_t len);

int wma_d0_wow_disable_ack_event(void *handle, uint8_t *event, uint32_t len);

int wma_pdev_resume_event_handler(void *handle, uint8_t *event, uint32_t len);

void wma_del_ts_req(tp_wma_handle wma, struct del_ts_params *msg);

/**
 * wma_aggr_qos_req() - send aggr qos request to fw
 * @wma: handle to wma
 * @pAggrQosRspMsg - combined struct for all ADD_TS requests.
 *
 * A function to handle WMA_AGGR_QOS_REQ. This will send out
 * ADD_TS requestes to firmware in loop for all the ACs with
 * active flow.
 *
 * Return: none
 */
void wma_aggr_qos_req(tp_wma_handle wma,
		      struct aggr_add_ts_param *pAggrQosRspMsg);

void wma_add_ts_req(tp_wma_handle wma, struct add_ts_param *msg);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

#ifdef FEATURE_WLAN_ESE
QDF_STATUS wma_process_tsm_stats_req(tp_wma_handle wma_handler,
				     void *pTsmStatsMsg);
<<<<<<< HEAD
QDF_STATUS wma_plm_start(tp_wma_handle wma, const tpSirPlmReq plm);
QDF_STATUS wma_plm_stop(tp_wma_handle wma, const tpSirPlmReq plm);
void wma_config_plm(tp_wma_handle wma, tpSirPlmReq plm);
#endif

QDF_STATUS wma_process_mcbc_set_filter_req(tp_wma_handle wma_handle,
					   struct sSirRcvFltMcAddrList *mcbc_param);
#ifdef WLAN_FEATURE_GTK_OFFLOAD
QDF_STATUS wma_process_gtk_offload_req(tp_wma_handle wma,
					      tpSirGtkOffloadParams params);

QDF_STATUS wma_process_gtk_offload_getinfo_req(tp_wma_handle wma,
					       tpSirGtkOffloadGetInfoRspParams
					       params);
#endif

QDF_STATUS wma_enable_arp_ns_offload(tp_wma_handle wma,
				     tpSirHostOffloadReq pHostOffloadParams,
				     bool bArpOnly);

/**
 * wma_conf_hw_filter_mode() - configure hw filter to the given mode
 * @wma: wma handle
 * @req: hardware filter request parameters
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wma_conf_hw_filter_mode(tp_wma_handle wma,
				   struct wmi_hw_filter_req_params *req);

=======
void wma_config_plm(tp_wma_handle wma, struct plm_req_params *plm);
#endif

QDF_STATUS wma_process_mcbc_set_filter_req(tp_wma_handle wma_handle,
					   tSirRcvFltMcAddrList * mcbc_param);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
QDF_STATUS wma_process_cesium_enable_ind(tp_wma_handle wma);

QDF_STATUS wma_process_get_peer_info_req
	(tp_wma_handle wma, tSirIbssGetPeerInfoReqParams *pReq);

QDF_STATUS wma_process_tx_fail_monitor_ind
	(tp_wma_handle wma, tAniTXFailMonitorInd *pReq);

<<<<<<< HEAD
=======
#ifdef FEATURE_WLAN_RMC
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
QDF_STATUS wma_process_rmc_enable_ind(tp_wma_handle wma);

QDF_STATUS wma_process_rmc_disable_ind(tp_wma_handle wma);

QDF_STATUS wma_process_rmc_action_period_ind(tp_wma_handle wma);
<<<<<<< HEAD

QDF_STATUS wma_process_add_periodic_tx_ptrn_ind(WMA_HANDLE handle,
						tSirAddPeriodicTxPtrn *
						pAddPeriodicTxPtrnParams);
=======
#else
static inline
QDF_STATUS wma_process_rmc_enable_ind(tp_wma_handle wma)
{
	return QDF_STATUS_SUCCESS;
}

static inline
QDF_STATUS wma_process_rmc_disable_ind(tp_wma_handle wma)
{
	return QDF_STATUS_SUCCESS;
}

static inline
QDF_STATUS wma_process_rmc_action_period_ind(tp_wma_handle wma)
{
	return QDF_STATUS_SUCCESS;
}
#endif

QDF_STATUS wma_process_add_periodic_tx_ptrn_ind(WMA_HANDLE handle,
						tSirAddPeriodicTxPtrn *pattern);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

QDF_STATUS wma_process_del_periodic_tx_ptrn_ind(WMA_HANDLE handle,
						tSirDelPeriodicTxPtrn *
						pDelPeriodicTxPtrnParams);

#ifdef WLAN_FEATURE_STATS_EXT
<<<<<<< HEAD
QDF_STATUS wma_stats_ext_req(void *wma_ptr, tpStatsExtRequest preq);
#endif

QDF_STATUS wma_process_ibss_route_table_update_ind(void *wma_handle,
						   struct sAniIbssRouteTable *pData);

=======
/**
 * wma_stats_ext_req() - request ext stats from fw
 * @wma_ptr: wma handle
 * @preq: stats ext params
 *
 * Return: QDF status
 */
QDF_STATUS wma_stats_ext_req(void *wma_ptr, tpStatsExtRequest preq);
#endif

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#ifdef WLAN_FEATURE_EXTWOW_SUPPORT
QDF_STATUS wma_enable_ext_wow(tp_wma_handle wma, tpSirExtWoWParams params);

int wma_set_app_type1_params_in_fw(tp_wma_handle wma,
				   tpSirAppType1Params appType1Params);

QDF_STATUS wma_set_app_type2_params_in_fw(tp_wma_handle wma,
				   tpSirAppType2Params appType2Params);
#endif

#ifdef FEATURE_WLAN_AUTO_SHUTDOWN
int wma_auto_shutdown_event_handler(void *handle, uint8_t *event,
				    uint32_t len);

<<<<<<< HEAD
QDF_STATUS wma_set_auto_shutdown_timer_req(tp_wma_handle wma_handle,
					   tSirAutoShutdownCmdParams *
					   auto_sh_cmd);
=======
/**
 * wma_set_auto_shutdown_timer_req() - sets auto shutdown timer in firmware
 * @wma_handle: wma handle
 * @auto_sh_cmd: auto shutdown timer params
 *
 * Return: QDF status
 */
QDF_STATUS
wma_set_auto_shutdown_timer_req(tp_wma_handle wma_handle,
				struct auto_shutdown_cmd *auto_sh_cmd);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#endif

#ifdef WLAN_FEATURE_TSF
int wma_vdev_tsf_handler(void *handle, uint8_t *data, uint32_t data_len);
QDF_STATUS wma_capture_tsf(tp_wma_handle wma_handle, uint32_t vdev_id);
QDF_STATUS wma_reset_tsf_gpio(tp_wma_handle wma_handle, uint32_t vdev_id);
QDF_STATUS wma_set_tsf_gpio_pin(WMA_HANDLE handle, uint32_t pin);
#else
static inline QDF_STATUS wma_capture_tsf(tp_wma_handle wma_handle,
					uint32_t vdev_id)
{
	return QDF_STATUS_SUCCESS;
}

static inline QDF_STATUS wma_reset_tsf_gpio(tp_wma_handle wma_handle,
					 uint32_t vdev_id)
{
	return QDF_STATUS_SUCCESS;
}

static inline int wma_vdev_tsf_handler(void *handle, uint8_t *data,
					uint32_t data_len)
{
	return 0;
}

static inline QDF_STATUS wma_set_tsf_gpio_pin(WMA_HANDLE handle, uint32_t pin)
{
	return QDF_STATUS_E_INVAL;
}
#endif
QDF_STATUS wma_set_wisa_params(tp_wma_handle wma, struct sir_wisa_params *wisa);

<<<<<<< HEAD
#ifdef WLAN_FEATURE_NAN
QDF_STATUS wma_nan_req(void *wma_ptr, tpNanRequest nan_req);
#endif

#ifdef DHCP_SERVER_OFFLOAD
int wma_process_dhcpserver_offload(tp_wma_handle wma_handle,
				   tSirDhcpSrvOffloadInfo *
				   pDhcpSrvOffloadInfo);
=======
#ifdef DHCP_SERVER_OFFLOAD
/**
 * wma_process_dhcpserver_offload() - enable DHCP server offload
 * @wma_handle: wma handle
 * @params: DHCP server offload information
 *
 * Return: QDF_STATUS_SUCCESS for success or error code
 */
QDF_STATUS
wma_process_dhcpserver_offload(tp_wma_handle wma_handle,
			       struct dhcp_offload_info_params *params);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#endif

#ifdef WLAN_FEATURE_GPIO_LED_FLASHING
QDF_STATUS wma_set_led_flashing(tp_wma_handle wma_handle,
<<<<<<< HEAD
				tSirLedFlashingReq *flashing);
=======
				struct flashing_req_params *flashing);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#endif

/**
 * wma_sar_rsp_evt_handler() -  process sar response event from FW.
<<<<<<< HEAD
 * @scn_handle: scn handle
=======
 * @handle: ol scn handle
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @event: event buffer
 * @len: buffer length
 *
 * Return: 0 for success or error code
 */
<<<<<<< HEAD
int wma_sar_rsp_evt_handler(ol_scn_t scn_handle, uint8_t *event, uint32_t len);

#ifdef FEATURE_WLAN_CH_AVOID
int wma_channel_avoid_evt_handler(void *handle, uint8_t *event,
					 uint32_t len);

=======
int wma_sar_rsp_evt_handler(ol_scn_t handle, uint8_t *event, uint32_t len);

#ifdef FEATURE_WLAN_CH_AVOID
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
QDF_STATUS wma_process_ch_avoid_update_req(tp_wma_handle wma_handle,
					   tSirChAvoidUpdateReq *
					   ch_avoid_update_req);
#endif

<<<<<<< HEAD
QDF_STATUS wma_suspend_target(WMA_HANDLE handle, int disable_target_intr);

#ifdef FEATURE_WLAN_TDLS

QDF_STATUS wma_update_fw_tdls_state(WMA_HANDLE handle, void *pwmaTdlsparams);
int wma_update_tdls_peer_state(WMA_HANDLE handle,
			       tTdlsPeerStateParams *peerStateParams);
/**
 * wma_set_tdls_offchan_mode() - set tdls off channel mode
 * @handle: wma handle
 * @chan_switch_params: Pointer to tdls channel switch parameter structure
 *
 * This function sets tdls off channel mode
 *
 * Return: 0 on success; negative errno otherwise
 */
QDF_STATUS wma_set_tdls_offchan_mode(WMA_HANDLE wma_handle,
			      tdls_chan_switch_params *chan_switch_params);
#endif

struct ieee80211com *wma_dfs_attach(struct ieee80211com *dfs_ic);

void wma_dfs_detach(struct ieee80211com *dfs_ic);

void wma_dfs_configure(struct ieee80211com *ic);

/**
 * wma_dfs_configure_channel() - configure DFS channel
 * @dfs_ic: ieee80211com ptr
 * @band_center_freq1: center frequency 1
 * @band_center_freq2: center frequency 2
 *       (valid only for 11ac vht 80plus80 mode)
 * @req: vdev start request
 *
 * Set the Channel parameters in to DFS module
 * Also,configure the DFS radar filters for
 * matching the DFS phyerrors.
 *
 * Return: None
 */
void wma_dfs_configure_channel(struct ieee80211com *dfs_ic,
				uint32_t band_center_freq1,
				uint32_t band_center_freq2,
				struct wma_vdev_start_req *req);

void wma_set_vdev_mgmt_rate(tp_wma_handle wma, uint8_t vdev_id);
void wma_set_sap_keepalive(tp_wma_handle wma, uint8_t vdev_id);

int wma_rssi_breached_event_handler(void *handle,
				u_int8_t  *cmd_param_info, u_int32_t len);
=======
#ifdef FEATURE_WLAN_TDLS
int wma_update_tdls_peer_state(WMA_HANDLE handle,
			       struct tdls_peer_update_state *peer_state);
#endif

void wma_set_vdev_mgmt_rate(tp_wma_handle wma, uint8_t vdev_id);
void wma_set_sap_keepalive(tp_wma_handle wma, uint8_t vdev_id);

#ifdef FEATURE_RSSI_MONITOR
int wma_rssi_breached_event_handler(void *handle,
				u_int8_t  *cmd_param_info, u_int32_t len);
#else /* FEATURE_RSSI_MONITOR */
static inline
int wma_rssi_breached_event_handler(void *handle,
				u_int8_t  *cmd_param_info, u_int32_t len)
{
	return 0;
}
#endif /* FEATURE_RSSI_MONITOR */

QDF_STATUS wma_process_cfg_action_frm_tb_ppdu(tp_wma_handle wma,
				   struct cfg_action_frm_tb_ppdu *cfg_info);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

QDF_STATUS wma_process_set_ie_info(tp_wma_handle wma,
				   struct vdev_ie_info *ie_info);
int wma_peer_assoc_conf_handler(void *handle, uint8_t *cmd_param_info,
				uint32_t len);
<<<<<<< HEAD
int wma_vdev_delete_handler(void *handle, uint8_t *cmd_param_info,
				uint32_t len);
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

int wma_peer_delete_handler(void *handle, uint8_t *cmd_param_info,
				uint32_t len);
void wma_remove_req(tp_wma_handle wma, uint8_t vdev_id,
			    uint8_t type);
<<<<<<< HEAD
int wma_p2p_lo_event_handler(void *handle, uint8_t *event_buf,
				uint32_t len);
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

QDF_STATUS wma_process_hal_pwr_dbg_cmd(WMA_HANDLE handle,
				       struct sir_mac_pwr_dbg_cmd *
				       sir_pwr_dbg_params);

<<<<<<< HEAD
#ifdef WLAN_FEATURE_DISA
int wma_encrypt_decrypt_msg_handler(void *handle, uint8_t *data,
			uint32_t data_len);
#else
static inline int wma_encrypt_decrypt_msg_handler(void *handle, uint8_t *data,
			uint32_t data_len)
{
	return 0;
}
#endif

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/**
 * wma_lost_link_info_handler() - collect lost link information and inform SME
 * @wma: WMA handle
 * @vdev_id: vdev ID
 * @rssi: rssi at disconnection time
 *
 * Return: none
 */
void wma_lost_link_info_handler(tp_wma_handle wma, uint32_t vdev_id,
				int32_t rssi);
int wma_unified_power_debug_stats_event_handler(void *handle,
			uint8_t *cmd_param_info, uint32_t len);
<<<<<<< HEAD

/**
 * wma_get_rcpi_req() - get rcpi request
 * @handle: wma handle
 * @rcpi_request: rcpi params
 *
 * Return: none
 */
QDF_STATUS wma_get_rcpi_req(WMA_HANDLE handle,
			    struct sme_rcpi_req *rcpi_request);

/**
 * wma_rcpi_event_handler() - rcpi event handler
 * @handle: wma handle
=======
/**
 * wma_unified_beacon_debug_stats_event_handler() - collect beacon debug stats
 * @handle: WMA handle
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @cmd_param_info: data from event
 * @len: length
 *
 * Return: 0 for success or error code
 */
<<<<<<< HEAD
int wma_rcpi_event_handler(void *handle, uint8_t *cmd_param_info,
			   uint32_t len);
=======
int wma_unified_beacon_debug_stats_event_handler(void *handle,
						 uint8_t *cmd_param_info,
						 uint32_t len);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

#ifdef FEATURE_WLAN_DIAG_SUPPORT
/**
 * wma_sta_kickout_event()- send sta kickout event
 * @kickout_reason - reasoncode for kickout
<<<<<<< HEAD
 * @macaddr[IEEE80211_ADDR_LEN]: Peer mac address
=======
 * @macaddr[QDF_MAC_ADDR_SIZE]: Peer mac address
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @vdev_id: Unique id for identifying the VDEV
 *
 * This function sends sta kickout diag event
 *
 * Return: void.
 */
void wma_sta_kickout_event(uint32_t kickout_reason, uint8_t vdev_id,
							uint8_t *macaddr);
#else
static inline void wma_sta_kickout_event(uint32_t kickout_reason,
					uint8_t vdev_id, uint8_t *macaddr)
{

};
#endif /* FEATURE_WLAN_DIAG_SUPPORT */

/**
<<<<<<< HEAD
=======
 * wma_get_rcpi_req() - get rcpi request
 * @handle: wma handle
 * @rcpi_request: rcpi params
 *
 * Return: none
 */
QDF_STATUS wma_get_rcpi_req(WMA_HANDLE handle,
			    struct sme_rcpi_req *rcpi_request);

/**
 * wma_rcpi_event_handler() - rcpi event handler
 * @handle: wma handle
 * @cmd_param_info: data from event
 * @len: length
 *
 * Return: 0 for success or error code
 */
int wma_rcpi_event_handler(void *handle, uint8_t *cmd_param_info,
			   uint32_t len);

/**
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * wma_acquire_wakelock() - acquire the given wakelock
 * @wl: the wakelock to acquire
 * @msec: the wakelock duration in milliseconds
 *
 * This also acquires the wma runtime pm lock.
 *
 * Return: None
 */
void wma_acquire_wakelock(qdf_wake_lock_t *wl, uint32_t msec);

/**
 * wma_release_wakelock() - release the given wakelock
 * @wl: the wakelock to release
 *
 * This also releases the wma runtime pm lock.
 *
 * Return: None
 */
void wma_release_wakelock(qdf_wake_lock_t *wl);

/**
<<<<<<< HEAD
 * wma_send_vdev_start_to_fw() - send the vdev start command to firmware
 * @wma: a reference to the global WMA handle
 * @params: the vdev start params to send to firmware
 *
 * Consumers should call wma_release_wakelock() upon receipt of the vdev start
 * response from firmware to avoid power penalties. Alternatively, calling the
 * matching vdev_up or vdev_down APIs will also release this lock.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS
wma_send_vdev_start_to_fw(t_wma_handle *wma, struct vdev_start_params *params);

/**
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * wma_send_vdev_stop_to_fw() - send the vdev stop command to firmware
 * @wma: a reference to the global WMA handle
 * @vdev_id: the Id of the vdev to stop
 *
 * Consumers should call wma_release_wakelock() upon receipt of the vdev stop
 * response from firmware to avoid power penalties.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wma_send_vdev_stop_to_fw(t_wma_handle *wma, uint8_t vdev_id);

<<<<<<< HEAD
/**
 * wma_send_vdev_up_to_fw() - send the vdev up command to firmware
 * @wma: a reference to the global WMA handle
 * @params: the vdev up params to send to firmware
 * @bssid: the BssId to send to firmware
 *
 * This also releases the vdev start wakelock.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wma_send_vdev_up_to_fw(t_wma_handle *wma,
				  struct vdev_up_params *params,
				  uint8_t bssid[IEEE80211_ADDR_LEN]);
=======
int wma_get_arp_stats_handler(void *handle, uint8_t *data, uint32_t data_len);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * wma_send_vdev_down_to_fw() - send the vdev down command to firmware
 * @wma: a reference to the global WMA handle
 * @vdev_id: the Id of the vdev to down
 *
 * This also releases the vdev start wakelock.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wma_send_vdev_down_to_fw(t_wma_handle *wma, uint8_t vdev_id);

<<<<<<< HEAD
int wma_get_arp_stats_handler(void *handle, uint8_t *data,
			      uint32_t data_len);
=======
/*
 * wma_rx_aggr_failure_event_handler - event handler to handle rx aggr failure
 * @handle: the wma handle
 * @event_buf: buffer with event
 * @len: buffer length
 *
 * This function receives rx aggregation failure event and then pass to upper
 * layer
 *
 * Return: 0 on success
 */
int wma_rx_aggr_failure_event_handler(void *handle, u_int8_t *event_buf,
							u_int32_t len);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * wma_wlan_bt_activity_evt_handler - event handler to handle bt activity
 * @handle: the WMA handle
 * @event: buffer with the event parameters
 * @len: length of the buffer
 *
 * This function receives BT activity event from firmware and passes the event
 * information to upper layers
 *
 * Return: 0 on success
 */
int wma_wlan_bt_activity_evt_handler(void *handle, uint8_t *event,
				     uint32_t len);
<<<<<<< HEAD
=======

/**
 * wma_pdev_div_info_evt_handler - event handler to handle antenna info
 * @handle: the wma handle
 * @event_buf: buffer with event
 * @len: buffer length
 *
 * This function receives antenna info from firmware and passes the event
 * to upper layer
 *
 * Return: 0 on success
 */
int wma_pdev_div_info_evt_handler(void *handle, u_int8_t *event_buf,
	u_int32_t len);

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/**
 * wma_update_beacon_interval() - update beacon interval in fw
 * @wma: wma handle
 * @vdev_id: vdev id
 * @beaconInterval: becon interval
 *
 * Return: none
 */
void
wma_update_beacon_interval(tp_wma_handle wma, uint8_t vdev_id,
				uint16_t beaconInterval);

#define RESET_BEACON_INTERVAL_TIMEOUT 200

struct wma_beacon_interval_reset_req {
	qdf_timer_t event_timeout;
	uint8_t vdev_id;
	uint16_t interval;
};

/**
 * wma_fill_beacon_interval_reset_req() - req to reset beacon interval
 * @wma: wma handle
 * @vdev_id: vdev id
 * @beacon_interval: beacon interval
 * @timeout: timeout val
 *
 * Return: status
 */
int wma_fill_beacon_interval_reset_req(tp_wma_handle wma, uint8_t vdev_id,
				uint16_t beacon_interval, uint32_t timeout);
<<<<<<< HEAD

/**
 * wma_pdev_div_info_evt_handler - event handler to handle antenna info
 * @handle: the wma handle
 * @event_buf: buffer with event
 * @len: buffer length
 *
 * This function receives antenna info from firmware and passes the event
 * to upper layer
 *
 * Return: 0 on success
 */
int wma_pdev_div_info_evt_handler(void *handle, u_int8_t *event_buf,
	u_int32_t len);

/**
 * wma_extract_comb_phyerr_spectral() - extract comb phy error from event
 * @handle: wma handle
 * @param evt_buf: pointer to event buffer
 * @param datalen: data length of event buffer
 * @param buf_offset: Pointer to hold value of current event buffer offset
 * post extraction
 * @param phyerr: Pointer to hold phyerr
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wma_extract_comb_phyerr_spectral(void *handle, void *evt_buf,
		uint16_t datalen, uint16_t *buf_offset,
		wmi_host_phyerr_t *phyerr);

#ifdef FEATURE_SPECTRAL_SCAN
/**
 * wma_extract_single_phyerr_spectral() - extract single phy error from event
 * @handle: wma handle
 * @param evt_buf: pointer to event buffer
 * @param datalen: data length of event buffer
 * @param buf_offset: Pointer to hold value of current event buffer offset
 * post extraction
 * @param phyerr: Pointer to hold phyerr
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wma_extract_single_phyerr_spectral(void *handle,
		void *evt_buf,
		uint16_t datalen, uint16_t *buf_offset,
		wmi_host_phyerr_t *phyerr);
#endif

/*
 * wma_rx_aggr_failure_event_handler - event handler to handle rx aggr failure
 * @handle: the wma handle
 * @event_buf: buffer with event
 * @len: buffer length
 *
 * This function receives rx aggregation failure event and then pass to upper
 * layer
 *
 * Return: 0 on success
 */
int wma_rx_aggr_failure_event_handler(void *handle, u_int8_t *event_buf,
							u_int32_t len);

/*
 * wma_is_vdev_valid - check the vdev status
 * @vdev_id: vdev identifier
 *
 * This function verifies the vdev validity
 *
 * Return: 'true' on valid vdev else 'false'
 */
bool wma_is_vdev_valid(uint32_t vdev_id);
=======
/*
 * wma_is_vdev_valid() - check the vdev status
 * @vdev_id: vdev identifier
 *
 * This function verifies the vdev validity
 *
 * Return: 'true' on valid vdev else 'false'
 */
bool wma_is_vdev_valid(uint32_t vdev_id);

/**
 * wma_vdev_obss_detection_info_handler - event handler to handle obss detection
 * @handle: the wma handle
 * @event: buffer with event
 * @len: buffer length
 *
 * This function receives obss detection info from firmware which is used to
 * decide obss protection.
 *
 * Return: 0 on success
 */
int wma_vdev_obss_detection_info_handler(void *handle, uint8_t *event,
					 uint32_t len);

/**
 * wma_vdev_bss_color_collision_info_handler - event handler to
 *  handle obss color collision detection.
 * @handle: the wma handle
 * @event: buffer with event
 * @len: buffer length
 *
 * This function receives obss color collision detection info from firmware
 * which is used to select new bss color.
 *
 * Return: 0 on success
 */
int wma_vdev_bss_color_collision_info_handler(void *handle,
					      uint8_t *event,
					      uint32_t len);

#ifdef WLAN_SUPPORT_TWT
/**
 * wma_twt_en_complete_event_handler - TWT enable complete event handler
 * @handle: wma handle
 * @event: buffer with event
 * @len: buffer length
 *
 * Return: 0 on success
 */
int wma_twt_en_complete_event_handler(void *handle,
				      uint8_t *event, uint32_t len);

/**
 * wma_twt_disable_comp_event_handler- TWT disable complete event handler
 * @handle: wma handle
 * @event: buffer with event
 * @len: buffer length
 *
 * Return: 0 on success
 */
int wma_twt_disable_comp_event_handler(void *handle, uint8_t *event,
				       uint32_t len);
#else
static inline int wma_twt_en_complete_event_handler(void *handle,
						    uint8_t *event,
						    uint32_t len)
{
	return 0;
}

static inline int wma_twt_disable_comp_event_handler(void *handle,
						     uint8_t *event,
						     uint32_t len)
{
	return 0;
}
#endif
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * wma_get_roam_scan_stats() - Get roam scan stats request
 * @handle: wma handle
 * @req: request details
 *
 * Return: QDF_STATUS
 */
QDF_STATUS wma_get_roam_scan_stats(WMA_HANDLE handle,
				   struct sir_roam_scan_stats *req);

/**
 * wma_roam_scan_stats_event_handler() - roam scan stats event handler
 * @handle: wma handle
 * @event: event data
 * @len: length of data
 *
 * Return: Success or Failure status
 */
int wma_roam_scan_stats_event_handler(void *handle, uint8_t *event,
				      uint32_t len);

<<<<<<< HEAD
=======
/**
 * wma_send_vdev_down() - send del bss req to firmware
 * @wma: wma handle.
 * @req: pointer to del bss response
 *
 * This function sends del bss resp to upper layer
 *
 * Return: none
 */
void wma_send_vdev_down(tp_wma_handle wma, struct del_bss_resp *req);

/**
 * wma_cold_boot_cal_event_handler() - Cold boot cal event handler
 * @wma_ctx: wma handle
 * @event_buff: event data
 * @len: length of data
 *
 * Return: Success or Failure status
 */
int wma_cold_boot_cal_event_handler(void *wma_ctx, uint8_t *event_buff,
				    uint32_t len);

#ifdef FEATURE_OEM_DATA
/**
 * wma_oem_event_handler() - oem data event handler
 * @wma_ctx: wma handle
 * @event_buff: event data
 * @len: length of event buffer
 *
 * Return: Success or Failure status
 */
int wma_oem_event_handler(void *wma_ctx, uint8_t *event_buff, uint32_t len);
#endif

/**
 * wma_set_roam_triggers() - Send roam trigger bitmap to WMI
 * @wma_handle: wma handle
 * @triggers: Carries vdev id and roam trigger bitmap.
 *
 * Return: Success or Failure status
 */
QDF_STATUS wma_set_roam_triggers(tp_wma_handle wma_handle,
				 struct roam_triggers *triggers);

/**
 * wma_get_ani_level_evt_handler - event handler to fetch ani level
 * @handle: the wma handle
 * @event_buf: buffer with event
 * @len: buffer length
 *
 * This function receives ani level from firmware and passes the event
 * to upper layer
 *
 * Return: 0 on success
 */
int wma_get_ani_level_evt_handler(void *handle, uint8_t *event_buf,
				  uint32_t len);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#endif

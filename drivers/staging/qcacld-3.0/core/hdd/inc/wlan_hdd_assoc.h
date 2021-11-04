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

#if !defined(WLAN_HDD_ASSOC_H__)
#define WLAN_HDD_ASSOC_H__

/**
 * DOC: wlan_hdd_assoc.h
 *
 */

/* Include files */
#include <sme_api.h>
#include <wlan_defs.h>
<<<<<<< HEAD
#include "ol_txrx_ctrl_api.h"
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#include "cdp_txrx_peer_ops.h"
#include <net/cfg80211.h>
#include <linux/ieee80211.h>

#define HDD_TIME_STRING_LEN 24

<<<<<<< HEAD
/* Preprocessor Definitions and Constants */
#ifdef FEATURE_WLAN_TDLS
#define HDD_MAX_NUM_TDLS_STA          8
#define HDD_MAX_NUM_TDLS_STA_P_UAPSD_OFFCHAN  1
#define TDLS_STA_INDEX_VALID(staId) \
	(((staId) >= 0) && ((staId) < 0xFF))
#endif
#define TKIP_COUNTER_MEASURE_STARTED 1
#define TKIP_COUNTER_MEASURE_STOPED  0
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/* Timeout (in ms) for Link to Up before Registering Station */
#define ASSOC_LINKUP_TIMEOUT 60

/* Timeout in ms for peer info request commpletion */
#define IBSS_PEER_INFO_REQ_TIMOEUT 1000

#define INVALID_PEER_IDX -1

/**
 * enum eConnectionState - connection state values at HDD
 * @eConnectionState_NotConnected: Not associated in Infra or participating in
 *			in an IBSS / Ad-hoc network
 * @eConnectionState_Connecting: While connection in progress
 * @eConnectionState_Associated: Associated in an Infrastructure network
 * @eConnectionState_IbssDisconnected: Participating in an IBSS network though
 *			disconnected (no partner stations in the IBSS)
 * @eConnectionState_IbssConnected: Participating in an IBSS network with
 *			partner stations also present
 * @eConnectionState_Disconnecting: Disconnecting in an Infrastructure network.
 * @eConnectionState_NdiDisconnected: NDI in disconnected state - no peers
 * @eConnectionState_NdiConnected: NDI in connected state - at least one peer
 */
typedef enum {
	eConnectionState_NotConnected,
	eConnectionState_Connecting,
	eConnectionState_Associated,
	eConnectionState_IbssDisconnected,
	eConnectionState_IbssConnected,
	eConnectionState_Disconnecting,
	eConnectionState_NdiDisconnected,
	eConnectionState_NdiConnected,
} eConnectionState;

/**
 * enum peer_status - Peer status
 * @ePeerConnected: peer connected
 * @ePeerDisconnected: peer disconnected
 */
enum peer_status {
	ePeerConnected = 1,
	ePeerDisconnected
};

/**
 * struct hdd_conn_flag - connection flags
 * @ht_present: ht element present or not
 * @vht_present: vht element present or not
 * @hs20_present: hs20 element present or not
 * @ht_op_present: ht operation present or not
 * @vht_op_present: vht operation present or not
 */
struct hdd_conn_flag {
	uint8_t ht_present:1;
	uint8_t vht_present:1;
	uint8_t hs20_present:1;
	uint8_t ht_op_present:1;
	uint8_t vht_op_present:1;
	uint8_t reserved:3;
};

/*defines for tx_BF_cap_info */
#define TX_BF_CAP_INFO_TX_BF			0x00000001
#define TX_BF_CAP_INFO_RX_STAG_RED_SOUNDING	0x00000002
#define TX_BF_CAP_INFO_TX_STAG_RED_SOUNDING	0x00000004
#define TX_BF_CAP_INFO_RX_ZFL			0x00000008
#define TX_BF_CAP_INFO_TX_ZFL			0x00000010
#define TX_BF_CAP_INFO_IMP_TX_BF		0x00000020
#define TX_BF_CAP_INFO_CALIBRATION		0x000000c0
#define TX_BF_CAP_INFO_CALIBRATION_SHIFT	6
#define TX_BF_CAP_INFO_EXP_CSIT_BF		0x00000100
#define TX_BF_CAP_INFO_EXP_UNCOMP_STEER_MAT	0x00000200
#define TX_BF_CAP_INFO_EXP_BF_CSI_FB		0x00001c00
#define TX_BF_CAP_INFO_EXP_BF_CSI_FB_SHIFT	10
#define TX_BF_CAP_INFO_EXP_UNCMP_STEER_MAT	0x0000e000
#define TX_BF_CAP_INFO_EXP_UNCMP_STEER_MAT_SHIFT 13
#define TX_BF_CAP_INFO_EXP_CMP_STEER_MAT_FB	0x00070000
#define TX_BF_CAP_INFO_EXP_CMP_STEER_MAT_FB_SHIFT 16
#define TX_BF_CAP_INFO_CSI_NUM_BF_ANT		0x00180000
#define TX_BF_CAP_INFO_CSI_NUM_BF_ANT_SHIFT	18
#define TX_BF_CAP_INFO_UNCOMP_STEER_MAT_BF_ANT	0x00600000
#define TX_BF_CAP_INFO_UNCOMP_STEER_MAT_BF_ANT_SHIFT 20
#define TX_BF_CAP_INFO_COMP_STEER_MAT_BF_ANT	0x01800000
#define TX_BF_CAP_INFO_COMP_STEER_MAT_BF_ANT_SHIFT 22
#define TX_BF_CAP_INFO_RSVD			0xfe000000

/* defines for antenna selection info */
#define ANTENNA_SEL_INFO			0x01
#define ANTENNA_SEL_INFO_EXP_CSI_FB_TX		0x02
#define ANTENNA_SEL_INFO_ANT_ID_FB_TX		0x04
#define ANTENNA_SEL_INFO_EXP_CSI_FB		0x08
#define ANTENNA_SEL_INFO_ANT_ID_FB		0x10
#define ANTENNA_SEL_INFO_RX_AS			0x20
#define ANTENNA_SEL_INFO_TX_SOUNDING_PPDU	0x40
#define ANTENNA_SEL_INFO_RSVD			0x80

/**
<<<<<<< HEAD
 * typedef connection_info_t - structure to store connection information
 * @connState: connection state of the NIC
 * @bssId: BSSID
 * @SSID: SSID Info
 * @staId: Station ID
 * @peerMacAddress:Peer Mac Address of the IBSS Stations
 * @authType: Auth Type
 * @ucEncryptionType: Unicast Encryption Type
 * @mcEncryptionType: Multicast Encryption Type
 * @Keys: Keys
 * @operationChannel: Operation Channel
 * @uIsAuthenticated: Remembers authenticated state
 * @dot11Mode: dot11Mode
 * @proxyARPService: proxy arp service
=======
 * struct hdd_connection_info - structure to store connection information
 * @conn_state: connection state of the NIC
 * @bssid: BSSID
 * @SSID: SSID Info
 * @peer_macaddr:Peer Mac Address of the IBSS Stations
 * @auth_type: Auth Type
 * @uc_encrypt_type: Unicast Encryption Type
 * @mc_encrypt_type: Multicast Encryption Type
 * @is_authenticated: Remembers authenticated state
 * @dot11mode: dot11mode
 * @proxy_arp_service: proxy arp service
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @ptk_installed: ptk installed state
 * @gtk_installed: gtk installed state
 * @nss: number of spatial streams negotiated
 * @rate_flags: rate flags for current connection
<<<<<<< HEAD
 * @freq: channel frequency
 * @txrate: txrate structure holds nss & datarate info
=======
 * @chan_freq: channel frequency
 * @txrate: txrate structure holds nss & datarate info
 * @rxrate: rx rate info
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @noise: holds noise information
 * @ht_caps: holds ht capabilities info
 * @vht_caps: holds vht capabilities info
 * @hs20vendor_ie: holds passpoint/hs20 info
 * @conn_flag: flag conn info params is present or not
 * @roam_count: roaming counter
 * @signal: holds rssi info
 * @assoc_status_code: holds assoc fail reason
 * @congestion: holds congestion percentage
 * @last_ssid: holds last ssid
 * @last_auth_type: holds last auth type
 * @auth_time: last authentication established time
 * @connect_time: last association established time
<<<<<<< HEAD
 */
typedef struct connection_info_s {
	eConnectionState connState;
	struct qdf_mac_addr bssId;
	tCsrSSIDInfo SSID;
	uint8_t staId[MAX_PEERS];
	struct qdf_mac_addr peerMacAddress[MAX_PEERS];
	eCsrAuthType authType;
	eCsrEncryptionType ucEncryptionType;
	eCsrEncryptionType mcEncryptionType;
	tCsrKeys Keys;
	uint8_t operationChannel;
	uint8_t uIsAuthenticated;
	uint32_t dot11Mode;
	uint8_t proxyARPService;
=======
 * @ch_width: channel width of operating channel
 * @max_tx_bitrate: Max tx bitrate supported by the AP
 * to which currently sta is connected.
 */
struct hdd_connection_info {
	eConnectionState conn_state;
	struct qdf_mac_addr bssid;
	tCsrSSIDInfo ssid;
	struct qdf_mac_addr peer_macaddr[MAX_PEERS];
	enum csr_akm_type auth_type;
	eCsrEncryptionType uc_encrypt_type;
	eCsrEncryptionType mc_encrypt_type;
	uint8_t is_authenticated;
	uint32_t dot11mode;
	uint8_t proxy_arp_service;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	bool ptk_installed;
	bool gtk_installed;
	uint8_t nss;
	uint32_t rate_flags;
<<<<<<< HEAD
	uint32_t freq;
	struct rate_info txrate;
=======
	uint32_t chan_freq;
	struct rate_info txrate;
	struct rate_info rxrate;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	int8_t noise;
	struct ieee80211_ht_cap ht_caps;
	struct ieee80211_vht_cap vht_caps;
	struct hdd_conn_flag conn_flag;
	tDot11fIEhs20vendor_ie hs20vendor_ie;
	struct ieee80211_ht_operation ht_operation;
	struct ieee80211_vht_operation vht_operation;
<<<<<<< HEAD
	uint32_t roam_count;
	int8_t signal;
	int32_t assoc_status_code;
	uint32_t cca;
	tCsrSSIDInfo last_ssid;
	eCsrAuthType last_auth_type;
	char auth_time[HDD_TIME_STRING_LEN];
	char connect_time[HDD_TIME_STRING_LEN];
	enum phy_ch_width ch_width;
} connection_info_t;

/* Forward declarations */
typedef struct hdd_adapter_s hdd_adapter_t;
typedef struct hdd_context_s hdd_context_t;
typedef struct hdd_station_ctx hdd_station_ctx_t;
typedef struct hdd_ap_ctx_s hdd_ap_ctx_t;
=======
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0)) \
     && defined(WLAN_FEATURE_11AX)
	struct ieee80211_he_operation *he_operation;
	uint32_t he_oper_len;
#endif
	uint32_t roam_count;
	int8_t signal;
	int32_t assoc_status_code;
	tCsrSSIDInfo last_ssid;
	enum csr_akm_type last_auth_type;
	char auth_time[HDD_TIME_STRING_LEN];
	char connect_time[HDD_TIME_STRING_LEN];
	enum phy_ch_width ch_width;
	struct rate_info max_tx_bitrate;
};

/* Forward declarations */
struct hdd_adapter;
struct hdd_station_ctx;
struct hdd_context;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * hdd_is_connecting() - Function to check connection progress
 * @hdd_sta_ctx:    pointer to global HDD Station context
 *
 * Return: true if connecting, false otherwise
 */
<<<<<<< HEAD
bool hdd_is_connecting(hdd_station_ctx_t *hdd_sta_ctx);

/**
 * hdd_is_disconnecting() - Function to check disconnection progress
 * @hdd_sta_ctx:    pointer to global HDD Station context
 *
 * Return: true if disconnecting, false otherwise
 */
bool hdd_is_disconnecting(hdd_station_ctx_t *hdd_sta_ctx);
=======
bool hdd_is_connecting(struct hdd_station_ctx *hdd_sta_ctx);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/*
 * hdd_is_fils_connection: API to determine if connection is FILS
 * @adapter: hdd adapter
 *
 * Return: true if fils connection else false
 */
<<<<<<< HEAD
bool hdd_is_fils_connection(hdd_adapter_t *adapter);


/**
 * hdd_conn_is_connected() - Function to check connection status
 * @pHddStaCtx:    pointer to global HDD Station context
 *
 * Return: false if any errors encountered, true otherwise
 */
bool hdd_conn_is_connected(hdd_station_ctx_t *pHddStaCtx);

/**
 * hdd_conn_get_connected_band() - get current connection radio band
 * @pHddStaCtx:    pointer to global HDD Station context
 *
 * Return: SIR_BAND_2_4_GHZ or SIR_BAND_5_GHZ based on current AP connection
 *      SIR_BAND_ALL if not connected
 */
tSirRFBand hdd_conn_get_connected_band(hdd_station_ctx_t *pHddStaCtx);
=======
bool hdd_is_fils_connection(struct hdd_adapter *adapter);

/**
 * hdd_conn_set_connection_state() - set connection state
 * @adapter: pointer to the adapter
 * @conn_state: connection state
 *
 * This function updates the global HDD station context connection state.
 *
 * Return: none
 */
void hdd_conn_set_connection_state(struct hdd_adapter *adapter,
				   eConnectionState conn_state);

/**
 * hdd_conn_is_connected() - Function to check connection status
 * @sta_ctx:    pointer to global HDD Station context
 *
 * Return: false if any errors encountered, true otherwise
 */
bool hdd_conn_is_connected(struct hdd_station_ctx *sta_ctx);

/**
 * hdd_adapter_is_connected_sta() - check if @adapter is a connected station
 * @adapter: the adapter to check
 *
 * Return: true if @adapter is a connected station
 */
bool hdd_adapter_is_connected_sta(struct hdd_adapter *adapter);

/**
 * hdd_conn_get_connected_band() - get current connection radio band
 * @sta_ctx:    pointer to global HDD Station context
 *
 * Return: BAND_2G or BAND_5G based on current AP connection
 *      BAND_ALL if not connected
 */
enum band_info hdd_conn_get_connected_band(struct hdd_station_ctx *sta_ctx);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * hdd_get_sta_connection_in_progress() - get STA for which connection
 *                                        is in progress
 * @hdd_ctx: hdd context
 *
 * Return: hdd adpater for which connection is in progress
 */
<<<<<<< HEAD
hdd_adapter_t *hdd_get_sta_connection_in_progress(hdd_context_t *hdd_ctx);
=======
struct hdd_adapter *hdd_get_sta_connection_in_progress(
			struct hdd_context *hdd_ctx);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * hdd_abort_ongoing_sta_connection() - Disconnect the sta for which the
 * connection is in progress.
 *
 * @hdd_ctx: hdd context
 *
 * Return: none
 */
<<<<<<< HEAD
void hdd_abort_ongoing_sta_connection(hdd_context_t *hdd_ctx);

/**
 * hdd_sme_roam_callback() - hdd sme roam callback
 * @pContext: pointer to adapter context
 * @pRoamInfo: pointer to roam info
 * @roamId: roam id
 * @roamStatus: roam status
 * @roamResult: roam result
 *
 * Return: QDF_STATUS enumeration
 */
QDF_STATUS hdd_sme_roam_callback(void *pContext, tCsrRoamInfo *pRoamInfo,
				 uint32_t roamId,
				 eRoamCmdStatus roamStatus,
				 eCsrRoamResult roamResult);

/**
 * hdd_set_genie_to_csr() - set genie to csr
 * @pAdapter: pointer to adapter
 * @RSNAuthType: pointer to auth type
 *
 * Return: 0 on success, error number otherwise
 */
int hdd_set_genie_to_csr(hdd_adapter_t *pAdapter, eCsrAuthType *RSNAuthType);

/**
 * hdd_set_csr_auth_type() - set csr auth type
 * @pAdapter: pointer to adapter
 * @RSNAuthType: auth type
 *
 * Return: 0 on success, error number otherwise
 */
int hdd_set_csr_auth_type(hdd_adapter_t *pAdapter, eCsrAuthType RSNAuthType);
=======
void hdd_abort_ongoing_sta_connection(struct hdd_context *hdd_ctx);

/**
 * hdd_sme_roam_callback() - hdd sme roam callback
 * @context: pointer to adapter context
 * @roam_info: pointer to roam info
 * @roam_id: roam id
 * @roam_status: roam status
 * @roam_result: roam result
 *
 * Return: QDF_STATUS enumeration
 */
QDF_STATUS hdd_sme_roam_callback(void *context,
				 struct csr_roam_info *roam_info,
				 uint32_t roam_id,
				 eRoamCmdStatus roam_status,
				 eCsrRoamResult roam_result);

/**
 * hdd_set_genie_to_csr() - set genie to csr
 * @adapter: pointer to adapter
 * @rsn_auth_type: pointer to auth type
 *
 * Return: 0 on success, error number otherwise
 */
int hdd_set_genie_to_csr(struct hdd_adapter *adapter,
			 enum csr_akm_type *rsn_auth_type);

/**
 * hdd_set_csr_auth_type() - set csr auth type
 * @adapter: pointer to adapter
 * @rsn_auth_type: auth type
 *
 * Return: 0 on success, error number otherwise
 */
int hdd_set_csr_auth_type(struct hdd_adapter *adapter,
			  enum csr_akm_type rsn_auth_type);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

#ifdef FEATURE_WLAN_TDLS
/**
 * hdd_roam_register_tdlssta() - register new TDLS station
<<<<<<< HEAD
 * @pAdapter: pointer to adapter
 * @peerMac: pointer to peer MAC address
 * @staId: station identifier
 * @ucastSig: unicast signature
 *
 * Construct the staDesc and register with TL the new STA.
=======
 * @adapter: pointer to adapter
 * @peerMac: pointer to peer MAC address
 * @qos: Quality of service
 *
 * Construct the txrx_desc and register the new STA with the Data Plane.
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * This is called as part of ADD_STA in the TDLS setup.
 *
 * Return: QDF_STATUS enumeration
 */
<<<<<<< HEAD
QDF_STATUS hdd_roam_register_tdlssta(hdd_adapter_t *pAdapter,
				     const uint8_t *peerMac, uint16_t staId,
				     uint8_t ucastSig, uint8_t qos);
#endif

QDF_STATUS hdd_roam_deregister_tdlssta(hdd_adapter_t *pAdapter, uint8_t staId);

/**
 * hdd_perform_roam_set_key_complete() - perform set key complete
 * @pAdapter: pointer to adapter
 *
 * Return: none
 */
void hdd_perform_roam_set_key_complete(hdd_adapter_t *pAdapter);

#ifdef FEATURE_WLAN_ESE
/**
 * hdd_indicate_ese_bcn_report_no_results() - beacon report no scan results
 * @pAdapter: pointer to adapter
=======
QDF_STATUS hdd_roam_register_tdlssta(struct hdd_adapter *adapter,
				     const uint8_t *peerMac, uint8_t qos);
#endif

#ifdef FEATURE_WLAN_ESE
/**
 * hdd_indicate_ese_bcn_report_no_results() - beacon report no scan results
 * @adapter: pointer to adapter
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @measurementToken: measurement token
 * @flag: flag
 * @numBss: number of bss
 *
 * If the measurement is none and no scan results found,
 * indicate the supplicant about measurement done.
 *
 * Return: none
 */
void
<<<<<<< HEAD
hdd_indicate_ese_bcn_report_no_results(const hdd_adapter_t *pAdapter,
=======
hdd_indicate_ese_bcn_report_no_results(const struct hdd_adapter *adapter,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
					    const uint16_t measurementToken,
					    const bool flag,
					    const uint8_t numBss);
#endif /* FEATURE_WLAN_ESE */

<<<<<<< HEAD
QDF_STATUS hdd_change_peer_state(hdd_adapter_t *pAdapter,
				 uint8_t sta_id,
				 enum ol_txrx_peer_state sta_state,
				 bool roam_synch_in_progress);
#ifdef WLAN_FEATURE_ROAM_OFFLOAD
bool hdd_is_roam_sync_in_progress(tCsrRoamInfo *roaminfo);
#else
static inline bool hdd_is_roam_sync_in_progress(tCsrRoamInfo *roaminfo)
=======
/**
 * hdd_change_peer_state() - change peer state
 * @adapter: HDD adapter
 * @peer_mac_addr: Peer MAC address
 * @sta_state: peer state
 * @roam_synch_in_progress: roam synch in progress
 *
 * Return: QDF status
 */
QDF_STATUS hdd_change_peer_state(struct hdd_adapter *adapter,
				 uint8_t *peer_mac_addr,
				 enum ol_txrx_peer_state sta_state,
				 bool roam_synch_in_progress);
#ifdef WLAN_FEATURE_ROAM_OFFLOAD
bool hdd_is_roam_sync_in_progress(struct csr_roam_info *roaminfo);
#else
static inline bool hdd_is_roam_sync_in_progress(struct csr_roam_info *roaminfo)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	return false;
}
#endif

<<<<<<< HEAD
QDF_STATUS hdd_roam_register_sta(struct hdd_adapter_s *adapter,
					struct tagCsrRoamInfo *roam_info,
					uint8_t sta_id,
					struct qdf_mac_addr *peer_mac_addr,
					struct sSirBssDescription *bss_desc);

bool hdd_save_peer(hdd_station_ctx_t *sta_ctx, uint8_t sta_id,
		   struct qdf_mac_addr *peer_mac_addr);
void hdd_delete_peer(hdd_station_ctx_t *sta_ctx, uint8_t sta_id);
int hdd_get_peer_idx(hdd_station_ctx_t *sta_ctx, struct qdf_mac_addr *addr);
QDF_STATUS hdd_roam_deregister_sta(hdd_adapter_t *adapter, uint8_t sta_id);

#ifdef WLAN_FEATURE_ROAM_OFFLOAD
QDF_STATUS hdd_wma_send_fastreassoc_cmd(hdd_adapter_t *adapter,
				  const tSirMacAddr bssid, int channel);
=======
/**
 * hdd_update_dp_vdev_flags() - update datapath vdev flags
 * @cbk_data: callback data
 * @vdev_id: virtual interface id
 * @vdev_param: vdev parameter
 * @is_link_up: link state up or down
 *
 * Return: QDF status
 */
QDF_STATUS hdd_update_dp_vdev_flags(void *cbk_data,
				    uint8_t vdev_id,
				    uint32_t vdev_param,
				    bool is_link_up);

QDF_STATUS hdd_roam_register_sta(struct hdd_adapter *adapter,
				 struct csr_roam_info *roam_info,
				 struct bss_description *bss_desc);

/**
 * hdd_save_peer() - Save peer MAC address in adapter peer table.
 * @sta_ctx: pointer to hdd station context
 * @peer_mac_addr: mac address of new peer
 *
 * This information is passed to iwconfig later. The peer that joined
 * last is passed as information to iwconfig.

 * Return: true if success, false otherwise
 */
bool hdd_save_peer(struct hdd_station_ctx *sta_ctx,
		   struct qdf_mac_addr *peer_mac_addr);

/**
 * hdd_delete_peer() - removes peer from hdd station context peer table
 * @sta_ctx: pointer to hdd station context
 * @peer_mac_addr: mac address of peer to be deleted
 *
 * Return: None
 */
void hdd_delete_peer(struct hdd_station_ctx *sta_ctx,
		     struct qdf_mac_addr *peer_mac_addr);

#ifdef WLAN_FEATURE_ROAM_OFFLOAD
QDF_STATUS
hdd_wma_send_fastreassoc_cmd(struct hdd_adapter *adapter,
			     const tSirMacAddr bssid, uint32_t ch_freq);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/**
 * hdd_save_gtk_params() - Save GTK offload params
 * @adapter: HDD adapter
 * @csr_roam_info: CSR roam info
 * @is_reassoc: boolean to indicate roaming
 *
 * Return: None
 */
<<<<<<< HEAD
void hdd_save_gtk_params(hdd_adapter_t *adapter,
			 tCsrRoamInfo *csr_roam_info, bool is_reassoc);
#else
static inline QDF_STATUS hdd_wma_send_fastreassoc_cmd(hdd_adapter_t *adapter,
		const tSirMacAddr bssid, int channel)
{
	return QDF_STATUS_SUCCESS;
}
static inline void hdd_save_gtk_params(hdd_adapter_t *adapter,
				       tCsrRoamInfo *csr_roam_info,
=======
void hdd_save_gtk_params(struct hdd_adapter *adapter,
			 struct csr_roam_info *csr_roam_info, bool is_reassoc);
#else
static inline QDF_STATUS
hdd_wma_send_fastreassoc_cmd(struct hdd_adapter *adapter,
			     const tSirMacAddr bssid, uint32_t ch_freq)
{
	return QDF_STATUS_SUCCESS;
}
static inline void hdd_save_gtk_params(struct hdd_adapter *adapter,
				       struct csr_roam_info *csr_roam_info,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				       bool is_reassoc)
{
}
#endif

/**
<<<<<<< HEAD
 * hdd_copy_ht_caps()- copy ht caps info from roam info to
 *  hdd station context.
=======
 * hdd_copy_ht_caps()- copy ht caps info from roam ht caps
 * info to source ht_cap info of type ieee80211_ht_cap.
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @hdd_ht_cap: pointer to Source ht_cap info of type ieee80211_ht_cap
 * @roam_ht_cap: pointer to roam ht_caps info
 *
 * Return: None
 */
<<<<<<< HEAD
=======

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
void hdd_copy_ht_caps(struct ieee80211_ht_cap *hdd_ht_cap,
		      tDot11fIEHTCaps *roam_ht_cap);

/**
<<<<<<< HEAD
 * hdd_copy_vht_caps()- copy vht caps info from roam info to
 *  hdd station context.
=======
 * hdd_add_beacon_filter() - add beacon filter
 * @adapter: Pointer to the hdd adapter
 *
 * Return: 0 on success and errno on failure
 */
int hdd_add_beacon_filter(struct hdd_adapter *adapter);

/**
 * hdd_copy_vht_caps()- copy vht caps info from roam vht caps
 * info to source vht_cap info of type ieee80211_vht_cap.
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @hdd_vht_cap: pointer to Source vht_cap info of type ieee80211_vht_cap
 * @roam_vht_cap: pointer to roam vht_caps info
 *
 * Return: None
 */
void hdd_copy_vht_caps(struct ieee80211_vht_cap *hdd_vht_cap,
		       tDot11fIEVHTCaps *roam_vht_cap);

<<<<<<< HEAD
=======
/**
 * hdd_roam_profile_init() - initialize adapter roam profile
 * @adapter: The HDD adapter being initialized
 *
 * This function initializes the roam profile that is embedded within
 * the adapter.
 *
 * Return: void
 */
void hdd_roam_profile_init(struct hdd_adapter *adapter);

/**
 * hdd_any_valid_peer_present() - Check if any valid peer is present
 * @adapter: The HDD adapter
 *
 * Check if there is any peer present with non-zero mac address other than
 * broadcast address.
 *
 * Return: True if there is any valid peer present
 */
bool hdd_any_valid_peer_present(struct hdd_adapter *adapter);

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#endif

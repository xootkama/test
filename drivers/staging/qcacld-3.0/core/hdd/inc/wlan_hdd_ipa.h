/*
<<<<<<< HEAD
 * Copyright (c) 2013-2018 The Linux Foundation. All rights reserved.
=======
 * Copyright (c) 2013-2019 The Linux Foundation. All rights reserved.
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

#ifndef HDD_IPA_H__
#define HDD_IPA_H__

/**
 * DOC: wlan_hdd_ipa.h
 *
 * WLAN IPA interface module headers
 */

<<<<<<< HEAD
/**
 * enum hdd_ipa_wlan_event - HDD IPA events
 * @HDD_IPA_CLIENT_CONNECT: Client Connects
 * @HDD_IPA_CLIENT_DISCONNECT: Client Disconnects
 * @HDD_IPA_AP_CONNECT: SoftAP is started
 * @HDD_IPA_AP_DISCONNECT: SoftAP is stopped
 * @HDD_IPA_STA_CONNECT: STA associates to AP
 * @HDD_IPA_STA_DISCONNECT: STA dissociates from AP
 * @HDD_IPA_CLIENT_CONNECT_EX: Peer associates/re-associates to softap
 * @HDD_IPA_WLAN_EVENT_MAX: Max value for the enum
 */
enum hdd_ipa_wlan_event {
	HDD_IPA_CLIENT_CONNECT,
	HDD_IPA_CLIENT_DISCONNECT,
	HDD_IPA_AP_CONNECT,
	HDD_IPA_AP_DISCONNECT,
	HDD_IPA_STA_CONNECT,
	HDD_IPA_STA_DISCONNECT,
	HDD_IPA_CLIENT_CONNECT_EX,
	HDD_IPA_WLAN_EVENT_MAX
};

#ifdef IPA_OFFLOAD
/* Include files */
#include <wlan_hdd_assoc.h> /* hdd_context_t */

/**
 * enum hdd_ipa_forward_type: Type of forward packet received from IPA
 * @HDD_IPA_FORWARD_PKT_NONE: No forward packet
 * @HDD_IPA_FORWARD_PKT_LOCAL_STACK: Packet forwarded to kernel network stack
 * @HDD_IPA_FORWARD_PKT_DISCARD: Discarded packet before sending to kernel stack
 */
enum hdd_ipa_forward_type {
	HDD_IPA_FORWARD_PKT_NONE = 0,
	HDD_IPA_FORWARD_PKT_LOCAL_STACK = 1,
	HDD_IPA_FORWARD_PKT_DISCARD = 2
};

/**
 * FIXME: Temporary hack - until IPA functionality gets restored
 *
 */
typedef void (*hdd_ipa_nbuf_cb_fn)(qdf_nbuf_t);
void hdd_ipa_nbuf_cb(qdf_nbuf_t skb);  /* Fwd declare */
static inline hdd_ipa_nbuf_cb_fn wlan_hdd_stub_ipa_fn(void)
{
	return hdd_ipa_nbuf_cb;
};

QDF_STATUS hdd_ipa_init(hdd_context_t *hdd_ctx);
void hdd_ipa_flush(hdd_context_t *hdd_ctx);
QDF_STATUS hdd_ipa_cleanup(hdd_context_t *hdd_ctx);
QDF_STATUS hdd_ipa_process_rxt(void *cds_context, qdf_nbuf_t rxBuf,
	uint8_t sta_id);
int hdd_ipa_wlan_evt(hdd_adapter_t *adapter, uint8_t sta_id,
	enum hdd_ipa_wlan_event type, uint8_t *mac_addr);
int hdd_ipa_set_perf_level(hdd_context_t *hdd_ctx, uint64_t tx_packets,
	uint64_t rx_packets);
int hdd_ipa_suspend(hdd_context_t *hdd_ctx);
int hdd_ipa_resume(hdd_context_t *hdd_ctx);
void hdd_ipa_uc_stat_query(hdd_context_t *hdd_ctx, uint32_t *ipa_tx_diff,
	uint32_t *ipa_rx_diff);
void hdd_ipa_uc_rt_debug_host_dump(hdd_context_t *hdd_ctx);
void hdd_ipa_uc_stat_request(hdd_context_t *hdd_ctx, uint8_t reason);
void hdd_ipa_uc_sharing_stats_request(hdd_adapter_t *adapter,
				      uint8_t reset_stats);
void hdd_ipa_uc_set_quota(hdd_adapter_t *adapter, uint8_t set_quota,
			  uint64_t quota_bytes);
bool hdd_ipa_is_enabled(hdd_context_t *pHddCtx);
bool hdd_ipa_uc_is_enabled(hdd_context_t *pHddCtx);
bool hdd_ipa_is_fw_wdi_actived(hdd_context_t *hdd_ctx);

#ifndef QCA_LL_TX_FLOW_CONTROL_V2
int hdd_ipa_send_mcc_scc_msg(hdd_context_t *hdd_ctx, bool mcc_mode);
void hdd_ipa_set_mcc_mode(bool mcc_mode);
#else
static inline int hdd_ipa_send_mcc_scc_msg(hdd_context_t *hdd_ctx,
					   bool mcc_mode)
{
	return 0;
}

static inline void hdd_ipa_set_mcc_mode(bool mcc_mode)
{
}

static inline void hdd_ipa_mcc_work_handler(struct work_struct *work)
{
}
#endif
int hdd_ipa_uc_ssr_reinit(hdd_context_t *hdd_ctx);
int hdd_ipa_uc_ssr_deinit(void);
void hdd_ipa_uc_force_pipe_shutdown(hdd_context_t *hdd_ctx);
struct sk_buff *hdd_ipa_tx_packet_ipa(hdd_context_t *hdd_ctx,
	struct sk_buff *skb, uint8_t session_id);
bool hdd_ipa_is_present(void);
void hdd_ipa_dump_info(hdd_context_t *hdd_ctx);
QDF_STATUS hdd_ipa_uc_ol_init(hdd_context_t *hdd_ctx);
int hdd_ipa_uc_ol_deinit(hdd_context_t *hdd_ctx);

/**
 * hdd_ipa_uc_smmu_map() - Map / Unmap DMA buffer to IPA UC
 * @map: Map / unmap operation
 * @num_buf: Number of buffers in array
 * @buf_arr: Buffer array of DMA mem mapping info
 *
 * This API maps/unmaps WLAN-IPA buffers if SMMU S1 translation
 * is enabled.
 *
 * Return: Status of map operation
 */
int hdd_ipa_uc_smmu_map(bool map, uint32_t num_buf, qdf_mem_info_t *buf_arr);

/**
 * hdd_ipa_uc_stat() - Print IPA uC stats
 * @adapter: network adapter
 *
 * Return: None
 */
void hdd_ipa_uc_stat(hdd_adapter_t *adapter);

/**
 * hdd_ipa_uc_info() - Print IPA uC resource and session information
 * @adapter: network adapter
 *
 * Return: None
 */
void hdd_ipa_uc_info(hdd_context_t *hdd_ctx);

/**
 * hdd_ipa_clean_adapter_iface() - Clean adapter IPA interface
 * @adapter: network adapter
 *
 * Return: None
 */
void hdd_ipa_clean_adapter_iface(hdd_adapter_t *adapter);

/**
 * hdd_ipa_fw_rejuvenate() - send fw rejuvenate message to IPA driver
 * @hdd_ctx: hdd context
 *
 * Return: void
 */
void hdd_ipa_fw_rejuvenate_send_msg(hdd_context_t *hdd_ctx);

/**
 * hdd_ipa_uc_disconnect_ap() - send ap disconnect event
 * @hdd_ctx: pointer to hdd adapter
 *
 * Send disconnect ap event to IPA driver during SSR
 *
 * Return: 0 - Success
 */
int hdd_ipa_uc_disconnect_ap(hdd_adapter_t *adapter);

#else

static inline QDF_STATUS hdd_ipa_init(hdd_context_t *hdd_ctx)
{
	return QDF_STATUS_SUCCESS;
}

static inline void hdd_ipa_flush(hdd_context_t *hdd_ctx)
{
}

static inline QDF_STATUS hdd_ipa_cleanup(hdd_context_t *hdd_ctx)
{
	return QDF_STATUS_SUCCESS;
}

static inline QDF_STATUS hdd_ipa_process_rxt(void *cds_context,
	qdf_nbuf_t rxBuf, uint8_t sta_id)
{
	return QDF_STATUS_SUCCESS;
}

static inline int hdd_ipa_wlan_evt(hdd_adapter_t *adapter, uint8_t sta_id,
	enum hdd_ipa_wlan_event type, uint8_t *mac_addr)
{
	return 0;
}

static inline int hdd_ipa_send_mcc_scc_msg(hdd_context_t *hdd_ctx,
	bool mcc_mode)
{
	return 0;
=======
#include <qdf_nbuf.h>

#ifdef IPA_OFFLOAD

/**
 * hdd_ipa_send_nbuf_to_network() - Send network buffer to kernel
 * @nbuf: network buffer
 * @dev: network adapter
 *
 * Called when a network buffer is received which should not be routed
 * to the IPA module.
 *
 * Return: None
 */
void hdd_ipa_send_nbuf_to_network(qdf_nbuf_t nbuf, qdf_netdev_t dev);

/**
 * hdd_ipa_set_tx_flow_info() - To set TX flow info if IPA is
 * enabled
 *
 * This routine is called to set TX flow info if IPA is enabled
 *
 * Return: None
 */
void hdd_ipa_set_tx_flow_info(void);

/**
 * hdd_ipa_set_mcc_mode() - To set mcc mode if IPA is enabled
 * @mcc_mode: mcc mode
 *
 * This routine is called to set mcc mode if IPA is enabled
 *
 * Return: None
 */
void hdd_ipa_set_mcc_mode(bool mcc_mode);

#else
static inline
void hdd_ipa_send_nbuf_to_network(qdf_nbuf_t skb, qdf_netdev_t dev)
{
}

static inline void hdd_ipa_set_tx_flow_info(void)
{
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

static inline void hdd_ipa_set_mcc_mode(bool mcc_mode)
{
}

<<<<<<< HEAD
static inline void hdd_ipa_mcc_work_handler(struct work_struct *work)
{
}

static inline int hdd_ipa_set_perf_level(hdd_context_t *hdd_ctx,
	uint64_t tx_packets,
	uint64_t rx_packets)
{
	return 0;
}

static inline int hdd_ipa_suspend(hdd_context_t *hdd_ctx)
{
	return 0;
}

static inline int hdd_ipa_resume(hdd_context_t *hdd_ctx)
{
	return 0;
}

static inline void hdd_ipa_uc_stat_query(hdd_context_t *hdd_ctx,
	uint32_t *ipa_tx_diff,
	uint32_t *ipa_rx_diff)
{
	*ipa_tx_diff = 0;
	*ipa_rx_diff = 0;
}

static inline void hdd_ipa_uc_stat_request(hdd_adapter_t *adapter,
	uint8_t reason)
{
}

static inline void hdd_ipa_uc_rt_debug_host_dump(hdd_context_t *hdd_ctx)
{
}

static inline bool hdd_ipa_is_enabled(hdd_context_t *pHddCtx)
{
	return false;
}

static inline bool hdd_ipa_uc_is_enabled(hdd_context_t *pHddCtx)
{
	return false;
}

static inline bool hdd_ipa_is_fw_wdi_actived(hdd_context_t *hdd_ctx)
{
	return false;
}

static inline void hdd_ipa_dump_info(hdd_context_t *hdd_ctx)
{
}

static inline int hdd_ipa_uc_ssr_reinit(hdd_context_t *hdd_ctx)
{
	return false;
}

static inline int hdd_ipa_uc_ssr_deinit(void)
{
	return false;
}
static inline void hdd_ipa_uc_force_pipe_shutdown(hdd_context_t *hdd_ctx)
{
}

/**
 * hdd_ipa_tx_packet_ipa() - send packet to IPA
 * @hdd_ctx:    Global HDD context
 * @skb:        skb sent to IPA
 * @session_id: send packet instance session id
 *
 * Send TX packet which generated by system to IPA.
 * This routine only will be used for function verification
 *
 * Return: NULL packet sent to IPA properly
 *         skb packet not sent to IPA. legacy data path should handle
 */
static inline struct sk_buff *hdd_ipa_tx_packet_ipa(hdd_context_t *hdd_ctx,
	struct sk_buff *skb, uint8_t session_id)
{
	return skb;
}

/**
 * hdd_ipa_is_present() - get IPA hw status
 *
 * ipa_uc_reg_rdyCB is not directly designed to check
 * ipa hw status. This is an undocumented function which
 * has confirmed with IPA team.
 *
 * Return: true - ipa hw present
 *         false - ipa hw not present
 */
static inline bool hdd_ipa_is_present(void)
{
	return false;
}

/**
 * hdd_ipa_uc_ol_init() - Initialize IPA uC offload
 * @hdd_ctx: Global HDD context
 *
 * Return: QDF_STATUS
 */
static inline QDF_STATUS hdd_ipa_uc_ol_init(hdd_context_t *hdd_ctx)
{
	return QDF_STATUS_SUCCESS;
}

/**
 * hdd_ipa_uc_ol_deinit() - Disconnect IPA TX and RX pipes
 * @hdd_ctx: Global HDD context
 *
 * Return: 0 on success, negativer errno on error
 */
static inline int hdd_ipa_uc_ol_deinit(hdd_context_t *hdd_ctx)
{
	return 0;
}

static inline int hdd_ipa_uc_smmu_map(bool map, uint32_t num_buf,
				      qdf_mem_info_t *buf_arr)
{
	return 0;
}

static inline void hdd_ipa_uc_stat(hdd_adapter_t *adapter)
{
}

static inline void hdd_ipa_uc_info(hdd_context_t *hdd_ctx)
{
}

static inline void hdd_ipa_fw_rejuvenate_send_msg(hdd_context_t *hdd_ctx)
{
}

static inline void hdd_ipa_clean_adapter_iface(hdd_adapter_t *adapter)
{
}

static inline int hdd_ipa_uc_disconnect_ap(hdd_adapter_t *adapter)
{
	return 0;
}
#endif /* IPA_OFFLOAD */
#endif /* #ifndef HDD_IPA_H__ */
=======
#endif
#endif /* HDD_IPA_H__ */
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

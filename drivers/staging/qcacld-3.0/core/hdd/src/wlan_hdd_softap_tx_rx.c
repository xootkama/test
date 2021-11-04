/*
<<<<<<< HEAD
 * Copyright (c) 2012-2018 The Linux Foundation. All rights reserved.
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

<<<<<<< HEAD
/* Include files */
#include <linux/semaphore.h>
=======
/* denote that this file does not allow legacy hddLog */
#define HDD_DISALLOW_LEGACY_HDDLOG 1

/* Include files */
#include <linux/semaphore.h>
#include "osif_sync.h"
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#include <wlan_hdd_tx_rx.h>
#include <wlan_hdd_softap_tx_rx.h>
#include <linux/netdevice.h>
#include <linux/skbuff.h>
#include <linux/etherdevice.h>
#include <qdf_types.h>
#include <ani_global.h>
#include <qdf_types.h>
#include <net/ieee80211_radiotap.h>
#include <cds_sched.h>
#include <wlan_hdd_napi.h>
<<<<<<< HEAD
#include <ol_txrx.h>
#include <cdp_txrx_peer_ops.h>
#include <cds_utils.h>
#include <wlan_hdd_regulatory.h>
#include <wlan_hdd_ipa.h>
#include "wma_types.h"
=======
#include <cdp_txrx_cmn.h>
#include <cdp_txrx_peer_ops.h>
#include <cds_utils.h>
#include <cdp_txrx_flow_ctrl_v2.h>
#include <cdp_txrx_misc.h>
#include <wlan_hdd_object_manager.h>
#include "wlan_p2p_ucfg_api.h"
#include <wlan_hdd_regulatory.h>
#include "wlan_ipa_ucfg_api.h"
#include "wlan_policy_mgr_ucfg.h"
#include <wma_types.h>
#include "wlan_hdd_sta_info.h"
#include "ol_defines.h"
#include <wlan_hdd_sar_limits.h>
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/* Preprocessor definitions and constants */
#undef QCA_HDD_SAP_DUMP_SK_BUFF

/* Type declarations */

/* Function definitions and documenation */
#ifdef QCA_HDD_SAP_DUMP_SK_BUFF
/**
 * hdd_softap_dump_sk_buff() - Dump an skb
 * @skb: skb to dump
 *
 * Return: None
 */
static void hdd_softap_dump_sk_buff(struct sk_buff *skb)
{
<<<<<<< HEAD
	QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_INFO,
		  "%s: head = %pK ", __func__, skb->head);
	QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_INFO,
		  "%s: tail = %pK ", __func__, skb->tail);
	QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_INFO,
		  "%s: end = %pK ", __func__, skb->end);
	QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_INFO,
		  "%s: len = %d ", __func__, skb->len);
	QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_INFO,
		  "%s: data_len = %d ", __func__, skb->data_len);
	QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_INFO,
		  "%s: mac_len = %d", __func__, skb->mac_len);

	QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_INFO,
		  "0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x ", skb->data[0],
		  skb->data[1], skb->data[2], skb->data[3], skb->data[4],
		  skb->data[5], skb->data[6], skb->data[7]);
	QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_INFO,
=======
	QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_ERROR,
		  "%s: head = %pK ", __func__, skb->head);
	QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_INFO,
		  "%s: tail = %pK ", __func__, skb->tail);
	QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_ERROR,
		  "%s: end = %pK ", __func__, skb->end);
	QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_ERROR,
		  "%s: len = %d ", __func__, skb->len);
	QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_ERROR,
		  "%s: data_len = %d ", __func__, skb->data_len);
	QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_ERROR,
		  "%s: mac_len = %d", __func__, skb->mac_len);

	QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_ERROR,
		  "0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x ", skb->data[0],
		  skb->data[1], skb->data[2], skb->data[3], skb->data[4],
		  skb->data[5], skb->data[6], skb->data[7]);
	QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_ERROR,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		  "0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x 0x%x", skb->data[8],
		  skb->data[9], skb->data[10], skb->data[11], skb->data[12],
		  skb->data[13], skb->data[14], skb->data[15]);
}
#else
static void hdd_softap_dump_sk_buff(struct sk_buff *skb)
{
}
#endif

#ifdef QCA_LL_LEGACY_TX_FLOW_CONTROL
<<<<<<< HEAD
/**
 * hdd_softap_tx_resume_timer_expired_handler() - TX Q resume timer handler
 * @adapter_context: pointer to vdev adapter
 *
 * TX Q resume timer handler for SAP and P2P GO interface.  If Blocked
 * OS Q is not resumed during timeout period, to prevent permanent
 * stall, resume OS Q forcefully for SAP and P2P GO interface.
 *
 * Return: None
 */
void hdd_softap_tx_resume_timer_expired_handler(void *adapter_context)
{
	hdd_adapter_t *pAdapter = (hdd_adapter_t *) adapter_context;

	if (!pAdapter) {
=======
void hdd_softap_tx_resume_timer_expired_handler(void *adapter_context)
{
	struct hdd_adapter *adapter = (struct hdd_adapter *) adapter_context;

	if (!adapter) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		hdd_err("NULL adapter");
		return;
	}

<<<<<<< HEAD
	hdd_info("Enabling queues");
	wlan_hdd_netif_queue_control(pAdapter, WLAN_WAKE_ALL_NETIF_QUEUE,
				     WLAN_CONTROL_PATH);
}

#if defined(CONFIG_PER_VDEV_TX_DESC_POOL)

/**
 * hdd_softap_tx_resume_false() - Resume OS TX Q false leads to queue disabling
 * @pAdapter: pointer to hdd adapter
=======
	hdd_debug("Enabling queues");
	wlan_hdd_netif_queue_control(adapter, WLAN_WAKE_ALL_NETIF_QUEUE,
				     WLAN_CONTROL_PATH);
}

/**
 * hdd_softap_tx_resume_false() - Resume OS TX Q false leads to queue disabling
 * @adapter: pointer to hdd adapter
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @tx_resume: TX Q resume trigger
 *
 *
 * Return: None
 */
static void
<<<<<<< HEAD
hdd_softap_tx_resume_false(hdd_adapter_t *pAdapter, bool tx_resume)
=======
hdd_softap_tx_resume_false(struct hdd_adapter *adapter, bool tx_resume)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	if (true == tx_resume)
		return;

<<<<<<< HEAD
	hdd_info("Disabling queues");
	wlan_hdd_netif_queue_control(pAdapter, WLAN_STOP_ALL_NETIF_QUEUE,
				     WLAN_DATA_FLOW_CONTROL);

	if (QDF_TIMER_STATE_STOPPED ==
			qdf_mc_timer_get_current_state(&pAdapter->
						       tx_flow_control_timer)) {
		QDF_STATUS status;

		status = qdf_mc_timer_start(&pAdapter->tx_flow_control_timer,
=======
	hdd_debug("Disabling queues");
	wlan_hdd_netif_queue_control(adapter, WLAN_STOP_ALL_NETIF_QUEUE,
				     WLAN_DATA_FLOW_CONTROL);

	if (QDF_TIMER_STATE_STOPPED ==
			qdf_mc_timer_get_current_state(&adapter->
						       tx_flow_control_timer)) {
		QDF_STATUS status;

		status = qdf_mc_timer_start(&adapter->tx_flow_control_timer,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				WLAN_SAP_HDD_TX_FLOW_CONTROL_OS_Q_BLOCK_TIME);

		if (!QDF_IS_STATUS_SUCCESS(status))
			hdd_err("Failed to start tx_flow_control_timer");
		else
<<<<<<< HEAD
			pAdapter->hdd_stats.hddTxRxStats.txflow_timer_cnt++;
	}
}
#else

static inline void
hdd_softap_tx_resume_false(hdd_adapter_t *pAdapter, bool tx_resume)
{
}
#endif

/**
 * hdd_softap_tx_resume_cb() - Resume OS TX Q.
 * @adapter_context: pointer to vdev apdapter
 * @tx_resume: TX Q resume trigger
 *
 * Q was stopped due to WLAN TX path low resource condition
 *
 * Return: None
 */
void hdd_softap_tx_resume_cb(void *adapter_context, bool tx_resume)
{
	hdd_adapter_t *pAdapter = (hdd_adapter_t *) adapter_context;

	if (!pAdapter) {
=======
			adapter->hdd_stats.tx_rx_stats.txflow_timer_cnt++;
	}
}

void hdd_softap_tx_resume_cb(void *adapter_context, bool tx_resume)
{
	struct hdd_adapter *adapter = (struct hdd_adapter *) adapter_context;

	if (!adapter) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		hdd_err("NULL adapter");
		return;
	}

	/* Resume TX  */
	if (true == tx_resume) {
		if (QDF_TIMER_STATE_STOPPED !=
<<<<<<< HEAD
		    qdf_mc_timer_get_current_state(&pAdapter->
						   tx_flow_control_timer)) {
			qdf_mc_timer_stop(&pAdapter->tx_flow_control_timer);
		}

		hdd_info("Enabling queues");
		wlan_hdd_netif_queue_control(pAdapter,
					WLAN_WAKE_ALL_NETIF_QUEUE,
					WLAN_DATA_FLOW_CONTROL);
	}
	hdd_softap_tx_resume_false(pAdapter, tx_resume);
}

static inline struct sk_buff *hdd_skb_orphan(hdd_adapter_t *pAdapter,
		struct sk_buff *skb)
{
	hdd_context_t *hdd_ctx = WLAN_HDD_GET_CTX(pAdapter);
	int need_orphan = 0;

	if (pAdapter->tx_flow_low_watermark > 0) {
=======
		    qdf_mc_timer_get_current_state(&adapter->
						   tx_flow_control_timer)) {
			qdf_mc_timer_stop(&adapter->tx_flow_control_timer);
		}

		hdd_debug("Enabling queues");
		wlan_hdd_netif_queue_control(adapter,
					WLAN_WAKE_ALL_NETIF_QUEUE,
					WLAN_DATA_FLOW_CONTROL);
	}
	hdd_softap_tx_resume_false(adapter, tx_resume);
}

static inline struct sk_buff *hdd_skb_orphan(struct hdd_adapter *adapter,
		struct sk_buff *skb)
{
	struct hdd_context *hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	int need_orphan = 0;

	if (adapter->tx_flow_low_watermark > 0) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#if (LINUX_VERSION_CODE > KERNEL_VERSION(3, 19, 0))
		/*
		 * The TCP TX throttling logic is changed a little after
		 * 3.19-rc1 kernel, the TCP sending limit will be smaller,
		 * which will throttle the TCP packets to the host driver.
		 * The TCP UP LINK throughput will drop heavily. In order to
		 * fix this issue, need to orphan the socket buffer asap, which
		 * will call skb's destructor to notify the TCP stack that the
		 * SKB buffer is unowned. And then the TCP stack will pump more
		 * packets to host driver.
		 *
		 * The TX packets might be dropped for UDP case in the iperf
		 * testing. So need to be protected by follow control.
		 */
		need_orphan = 1;
#else
		if (hdd_ctx->config->tx_orphan_enable)
			need_orphan = 1;
#endif
	} else if (hdd_ctx->config->tx_orphan_enable) {
		if (qdf_nbuf_is_ipv4_tcp_pkt(skb) ||
		    qdf_nbuf_is_ipv6_tcp_pkt(skb))
			need_orphan = 1;
	}

	if (need_orphan) {
		skb_orphan(skb);
<<<<<<< HEAD
		++pAdapter->hdd_stats.hddTxRxStats.txXmitOrphaned;
=======
		++adapter->hdd_stats.tx_rx_stats.tx_orphaned;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	} else
		skb = skb_unshare(skb, GFP_ATOMIC);

	return skb;
}

#else
/**
 * hdd_skb_orphan() - skb_unshare a cloned packed else skb_orphan
<<<<<<< HEAD
 * @pAdapter: pointer to HDD adapter
=======
 * @adapter: pointer to HDD adapter
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @skb: pointer to skb data packet
 *
 * Return: pointer to skb structure
 */
<<<<<<< HEAD
static inline struct sk_buff *hdd_skb_orphan(hdd_adapter_t *pAdapter,
=======
static inline struct sk_buff *hdd_skb_orphan(struct hdd_adapter *adapter,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		struct sk_buff *skb) {

	struct sk_buff *nskb;
#if (LINUX_VERSION_CODE > KERNEL_VERSION(3, 19, 0))
<<<<<<< HEAD
	hdd_context_t *hdd_ctx = pAdapter->pHddCtx;
#endif
	hdd_skb_fill_gso_size(pAdapter->dev, skb);
=======
	struct hdd_context *hdd_ctx = WLAN_HDD_GET_CTX(adapter);
#endif

	hdd_skb_fill_gso_size(adapter->dev, skb);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	nskb = skb_unshare(skb, GFP_ATOMIC);
#if (LINUX_VERSION_CODE > KERNEL_VERSION(3, 19, 0))
	if (unlikely(hdd_ctx->config->tx_orphan_enable) && (nskb == skb)) {
		/*
		 * For UDP packets we want to orphan the packet to allow the app
		 * to send more packets. The flow would ultimately be controlled
		 * by the limited number of tx descriptors for the vdev.
		 */
<<<<<<< HEAD
		++pAdapter->hdd_stats.hddTxRxStats.txXmitOrphaned;
=======
		++adapter->hdd_stats.tx_rx_stats.tx_orphaned;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		skb_orphan(skb);
	}
#endif
	return nskb;
}
#endif /* QCA_LL_LEGACY_TX_FLOW_CONTROL */

<<<<<<< HEAD
=======
#define IEEE8021X_AUTH_TYPE_EAP 0
#define EAP_CODE_OFFSET 18
#define EAP_CODE_FAILURE 4

/* Wait EAP Failure frame timeout in (MS) */
#define EAP_FRM_TIME_OUT 80

/**
 * hdd_softap_inspect_tx_eap_pkt() - Inspect eap pkt tx/tx-completion
 * @adapter: pointer to hdd adapter
 * @skb: sk_buff
 * @tx_comp: tx sending or tx completion
 *
 * Inspect the EAP-Failure pkt tx sending and tx completion.
 *
 * Return: void
 */
static void hdd_softap_inspect_tx_eap_pkt(struct hdd_adapter *adapter,
					  struct sk_buff *skb,
					  bool tx_comp)
{
	struct qdf_mac_addr *mac_addr;
	uint8_t *data;
	uint8_t auth_type, eap_code;
	struct hdd_station_info *sta_info;
	struct hdd_hostapd_state *hapd_state;

	if (qdf_likely(QDF_NBUF_CB_GET_PACKET_TYPE(skb) !=
	    QDF_NBUF_CB_PACKET_TYPE_EAPOL) || skb->len < (EAP_CODE_OFFSET + 1))
		return;

	if (cds_is_driver_recovering() || cds_is_driver_in_bad_state() ||
	    cds_is_load_or_unload_in_progress()) {
		hdd_debug("Recovery/(Un)load in Progress. Ignore!!!");
		return;
	}
	if (adapter->device_mode != QDF_P2P_GO_MODE)
		return;
	hapd_state = WLAN_HDD_GET_HOSTAP_STATE_PTR(adapter);
	if (!hapd_state || hapd_state->bss_state != BSS_START) {
		hdd_debug("Hostapd State is not START");
		return;
	}
	data = skb->data;
	auth_type = *(uint8_t *)(data + EAPOL_PACKET_TYPE_OFFSET);
	if (auth_type != IEEE8021X_AUTH_TYPE_EAP)
		return;
	eap_code = *(uint8_t *)(data + EAP_CODE_OFFSET);
	if (eap_code != EAP_CODE_FAILURE)
		return;
	mac_addr = (struct qdf_mac_addr *)skb->data;
	sta_info = hdd_get_sta_info_by_mac(&adapter->sta_info_list,
					   mac_addr->bytes,
					   STA_INFO_SOFTAP_INSPECT_TX_EAP_PKT);
	if (!sta_info)
		return;
	if (tx_comp) {
		hdd_debug("eap_failure frm tx done "QDF_MAC_ADDR_FMT,
			  QDF_MAC_ADDR_REF(mac_addr->bytes));
		qdf_atomic_clear_bit(PENDING_TYPE_EAP_FAILURE,
				     &sta_info->pending_eap_frm_type);
		qdf_event_set(&hapd_state->qdf_sta_eap_frm_done_event);
	} else {
		hdd_debug("eap_failure frm tx pending "QDF_MAC_ADDR_FMT,
			  QDF_MAC_ADDR_REF(mac_addr->bytes));
		qdf_event_reset(&hapd_state->qdf_sta_eap_frm_done_event);
		qdf_atomic_set_bit(PENDING_TYPE_EAP_FAILURE,
				   &sta_info->pending_eap_frm_type);
		QDF_NBUF_CB_TX_EXTRA_FRAG_FLAGS_NOTIFY_COMP(skb) = 1;
	}
	hdd_put_sta_info_ref(&adapter->sta_info_list, &sta_info, true,
			     STA_INFO_SOFTAP_INSPECT_TX_EAP_PKT);
}

void hdd_softap_check_wait_for_tx_eap_pkt(struct hdd_adapter *adapter,
					  struct qdf_mac_addr *mac_addr)
{
	struct hdd_station_info *sta_info;
	QDF_STATUS qdf_status;
	struct hdd_hostapd_state *hapd_state;

	if (adapter->device_mode != QDF_P2P_GO_MODE)
		return;
	hapd_state = WLAN_HDD_GET_HOSTAP_STATE_PTR(adapter);
	if (!hapd_state || hapd_state->bss_state != BSS_START) {
		hdd_err("Hostapd State is not START");
		return;
	}
	sta_info = hdd_get_sta_info_by_mac(
				&adapter->sta_info_list,
				mac_addr->bytes,
				STA_INFO_SOFTAP_CHECK_WAIT_FOR_TX_EAP_PKT);
	if (!sta_info)
		return;
	if (qdf_atomic_test_bit(PENDING_TYPE_EAP_FAILURE,
				&sta_info->pending_eap_frm_type)) {
		hdd_debug("eap_failure frm pending "QDF_MAC_ADDR_FMT,
			  QDF_MAC_ADDR_REF(mac_addr->bytes));
		qdf_status = qdf_wait_for_event_completion(
				&hapd_state->qdf_sta_eap_frm_done_event,
				EAP_FRM_TIME_OUT);
		if (!QDF_IS_STATUS_SUCCESS(qdf_status))
			hdd_debug("eap_failure tx timeout");
	}
	hdd_put_sta_info_ref(&adapter->sta_info_list, &sta_info, true,
			     STA_INFO_SOFTAP_CHECK_WAIT_FOR_TX_EAP_PKT);
}

#ifdef SAP_DHCP_FW_IND
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/**
 * hdd_post_dhcp_ind() - Send DHCP START/STOP indication to FW
 * @adapter: pointer to hdd adapter
 * @sta_id: peer station ID
 * @type: WMA message type
 *
<<<<<<< HEAD
 * Return: None
 */
QDF_STATUS hdd_post_dhcp_ind(hdd_adapter_t *adapter,
			     uint8_t sta_id, uint16_t type)
{
	QDF_STATUS status = QDF_STATUS_SUCCESS;

	hdd_debug("Post DHCP indication,sta_id=%d,  type=%d", sta_id, type);

	if (!adapter) {
		hdd_err("NULL adapter");
		return QDF_STATUS_E_FAILURE;
	}

	status = wma_send_dhcp_ind(type,
				   adapter->device_mode,
				   adapter->macAddressCurrent.bytes,
				   adapter->aStaInfo[sta_id].macAddrSTA.bytes);
	if (!QDF_IS_STATUS_SUCCESS(status))
		QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_ERROR,
				"%s: Post DHCP Ind MSG fail", __func__);

	return status;
}

void hdd_softap_notify_dhcp_ind(void *context, struct sk_buff *netbuf)
{
	hdd_ap_ctx_t *hdd_ap_ctx;
	struct qdf_mac_addr *dest_mac_addr;
	uint8_t sta_id;

	hdd_adapter_t *adapter = context;

	if (!adapter) {
		hdd_err("NULL adapter");
		return;
	}
=======
 * Return: error number
 */
int hdd_post_dhcp_ind(struct hdd_adapter *adapter, uint8_t *mac_addr,
		      uint16_t type)
{
	tAniDHCPInd pmsg;
	QDF_STATUS status = QDF_STATUS_SUCCESS;

	hdd_debug("Post DHCP indication,sta_mac=" QDF_MAC_ADDR_FMT
		  " ,  type=%d", QDF_MAC_ADDR_REF(mac_addr), type);

	if (!adapter) {
		hdd_err("NULL adapter");
		return -EINVAL;
	}

	pmsg.msgType = type;
	pmsg.msgLen = (uint16_t) sizeof(tAniDHCPInd);
	pmsg.device_mode = adapter->device_mode;
	qdf_mem_copy(pmsg.adapterMacAddr.bytes,
		     adapter->mac_addr.bytes,
		     QDF_MAC_ADDR_SIZE);
	qdf_mem_copy(pmsg.peerMacAddr.bytes,
		     mac_addr,
		     QDF_MAC_ADDR_SIZE);

	status = wma_process_dhcp_ind(cds_get_context(QDF_MODULE_ID_WMA),
				      &pmsg);
	if (!QDF_IS_STATUS_SUCCESS(status)) {
		QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_ERROR,
			  "%s: Post DHCP Ind MSG fail", __func__);
		return -EFAULT;
	}

	return 0;
}

#define DHCP_CLIENT_MAC_ADDR_OFFSET 0x46

/**
 * hdd_softap_notify_dhcp_ind() - Notify SAP for DHCP indication for tx desc
 * @context: pointer to HDD context
 * @netbuf: pointer to OS packet (sk_buff)
 *
 * Return: None
 */
static void hdd_softap_notify_dhcp_ind(void *context, struct sk_buff *netbuf)
{
	struct hdd_ap_ctx *hdd_ap_ctx;
	uint8_t *dest_mac_addr;
	struct hdd_adapter *adapter = context;

	if (hdd_validate_adapter(adapter))
		return;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	hdd_ap_ctx = WLAN_HDD_GET_AP_CTX_PTR(adapter);
	if (!hdd_ap_ctx) {
		hdd_err("HDD sap context is NULL");
		return;
	}

<<<<<<< HEAD
	dest_mac_addr = (struct qdf_mac_addr *)netbuf->data;

	if (QDF_NBUF_CB_GET_IS_BCAST(netbuf) ||
	    QDF_NBUF_CB_GET_IS_MCAST(netbuf)) {
		/* The BC/MC station ID is assigned during BSS
		 * starting phase.  SAP will return the station ID
		 * used for BC/MC traffic.
		 */
		sta_id = hdd_ap_ctx->uBCStaId;
	} else {
		if (QDF_STATUS_SUCCESS !=
		    hdd_softap_get_sta_id(adapter,
					  dest_mac_addr, &sta_id)) {
			QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA,
				  QDF_TRACE_LEVEL_INFO_HIGH,
				  "%s: Failed to find right station", __func__);
			return;
		}
	}
	hdd_post_dhcp_ind(adapter, sta_id, WMA_DHCP_STOP_IND);
}

/**
 * hdd_dhcp_indication() - Send DHCP START/STOP indication to FW
 * @adapter: pointer to hdd adapter
 * @sta_id: peer station ID
 * @skb: pointer to OS packet (sk_buff)
 * @dir: direction
 *
 * Return: true if tx completion to be notified for skb
 */
bool hdd_dhcp_indication(hdd_adapter_t *adapter,
			 uint8_t sta_id,
			 struct sk_buff *skb,
			 enum qdf_proto_dir dir)
{
	enum qdf_proto_subtype subtype = QDF_PROTO_INVALID;
	hdd_station_info_t *hdd_sta_info;
	bool notify_tx_comp = false;

=======
	dest_mac_addr = netbuf->data + DHCP_CLIENT_MAC_ADDR_OFFSET;

	hdd_post_dhcp_ind(adapter, dest_mac_addr, WMA_DHCP_STOP_IND);
}

int hdd_softap_inspect_dhcp_packet(struct hdd_adapter *adapter,
				   struct sk_buff *skb,
				   enum qdf_proto_dir dir)
{
	enum qdf_proto_subtype subtype = QDF_PROTO_INVALID;
	struct hdd_station_info *hdd_sta_info;
	int errno = 0;
	struct qdf_mac_addr *src_mac;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	if (((adapter->device_mode == QDF_SAP_MODE) ||
	     (adapter->device_mode == QDF_P2P_GO_MODE)) &&
	    ((dir == QDF_TX && QDF_NBUF_CB_PACKET_TYPE_DHCP ==
				QDF_NBUF_CB_GET_PACKET_TYPE(skb)) ||
	     (dir == QDF_RX && qdf_nbuf_is_ipv4_dhcp_pkt(skb) == true))) {

<<<<<<< HEAD
		subtype = qdf_nbuf_get_dhcp_subtype(skb);
		hdd_sta_info = &adapter->aStaInfo[sta_id];
=======
		src_mac = (struct qdf_mac_addr *)(skb->data +
						  DHCP_CLIENT_MAC_ADDR_OFFSET);

		subtype = qdf_nbuf_get_dhcp_subtype(skb);
		hdd_sta_info = hdd_get_sta_info_by_mac(
					&adapter->sta_info_list,
					src_mac->bytes,
					STA_INFO_SOFTAP_INSPECT_DHCP_PACKET);
		if (!hdd_sta_info) {
			hdd_debug("Station not found");
			return -EINVAL;
		}
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

		hdd_debug("ENTER: type=%d, phase=%d, nego_status=%d",
			  subtype,
			  hdd_sta_info->dhcp_phase,
			  hdd_sta_info->dhcp_nego_status);

		switch (subtype) {
		case QDF_PROTO_DHCP_DISCOVER:
			if (dir != QDF_RX)
				break;
			if (hdd_sta_info->dhcp_nego_status == DHCP_NEGO_STOP)
<<<<<<< HEAD
				hdd_post_dhcp_ind(adapter, sta_id,
						  WMA_DHCP_START_IND);
=======
				errno =	hdd_post_dhcp_ind(
						adapter,
						hdd_sta_info->sta_mac.bytes,
						WMA_DHCP_START_IND);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			hdd_sta_info->dhcp_phase = DHCP_PHASE_DISCOVER;
			hdd_sta_info->dhcp_nego_status = DHCP_NEGO_IN_PROGRESS;
			break;
		case QDF_PROTO_DHCP_OFFER:
			hdd_sta_info->dhcp_phase = DHCP_PHASE_OFFER;
			break;
		case QDF_PROTO_DHCP_REQUEST:
			if (dir != QDF_RX)
				break;
			if (hdd_sta_info->dhcp_nego_status == DHCP_NEGO_STOP)
<<<<<<< HEAD
				hdd_post_dhcp_ind(adapter, sta_id,
						  WMA_DHCP_START_IND);
=======
				errno = hdd_post_dhcp_ind(
						adapter,
						hdd_sta_info->sta_mac.bytes,
						WMA_DHCP_START_IND);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			hdd_sta_info->dhcp_nego_status = DHCP_NEGO_IN_PROGRESS;
		case QDF_PROTO_DHCP_DECLINE:
			if (dir == QDF_RX)
				hdd_sta_info->dhcp_phase = DHCP_PHASE_REQUEST;
			break;
		case QDF_PROTO_DHCP_ACK:
		case QDF_PROTO_DHCP_NACK:
			hdd_sta_info->dhcp_phase = DHCP_PHASE_ACK;
			if (hdd_sta_info->dhcp_nego_status ==
<<<<<<< HEAD
				DHCP_NEGO_IN_PROGRESS)
				notify_tx_comp = true;
=======
				DHCP_NEGO_IN_PROGRESS) {
				hdd_debug("Setting NOTIFY_COMP Flag");
				QDF_NBUF_CB_TX_EXTRA_FRAG_FLAGS_NOTIFY_COMP(skb)
									= 1;
			}
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			hdd_sta_info->dhcp_nego_status = DHCP_NEGO_STOP;
			break;
		default:
			break;
		}

		hdd_debug("EXIT: phase=%d, nego_status=%d",
			  hdd_sta_info->dhcp_phase,
			  hdd_sta_info->dhcp_nego_status);
<<<<<<< HEAD
	}
	return notify_tx_comp;
}
=======
		hdd_put_sta_info_ref(&adapter->sta_info_list, &hdd_sta_info,
				     true, STA_INFO_SOFTAP_INSPECT_DHCP_PACKET);
	}

	return errno;
}
#else
static void hdd_softap_notify_dhcp_ind(void *context, struct sk_buff *netbuf)
{
}
#endif
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * __hdd_softap_hard_start_xmit() - Transmit a frame
 * @skb: pointer to OS packet (sk_buff)
 * @dev: pointer to network device
 *
 * Function registered with the Linux OS for transmitting
 * packets. This version of the function directly passes
 * the packet to Transport Layer.
 * In case of any packet drop or error, log the error with
 * INFO HIGH/LOW/MEDIUM to avoid excessive logging in kmsg.
 *
<<<<<<< HEAD
 * Return: Always returns NETDEV_TX_OK
 */
static netdev_tx_t __hdd_softap_hard_start_xmit(struct sk_buff *skb,
						struct net_device *dev)
{
	sme_ac_enum_type ac = SME_AC_BE;
	hdd_adapter_t *pAdapter = (hdd_adapter_t *) netdev_priv(dev);
	hdd_ap_ctx_t *pHddApCtx = WLAN_HDD_GET_AP_CTX_PTR(pAdapter);
	struct qdf_mac_addr *pDestMacAddress;
	uint8_t STAId;
	uint32_t num_seg;
	bool notify_tx_comp = false;

	++pAdapter->hdd_stats.hddTxRxStats.txXmitCalled;
	pAdapter->hdd_stats.hddTxRxStats.cont_txtimeout_cnt = 0;
=======
 * Return: None
 */
static void __hdd_softap_hard_start_xmit(struct sk_buff *skb,
					 struct net_device *dev)
{
	sme_ac_enum_type ac = SME_AC_BE;
	struct hdd_adapter *adapter = (struct hdd_adapter *) netdev_priv(dev);
	struct hdd_ap_ctx *ap_ctx = WLAN_HDD_GET_AP_CTX_PTR(adapter);
	struct hdd_context *hdd_ctx = adapter->hdd_ctx;
	struct qdf_mac_addr *dest_mac_addr, *mac_addr;
	static struct qdf_mac_addr bcast_mac_addr = QDF_MAC_ADDR_BCAST_INIT;
	void *soc = cds_get_context(QDF_MODULE_ID_SOC);
	uint32_t num_seg;
	struct hdd_station_info *sta_info = NULL;

	++adapter->hdd_stats.tx_rx_stats.tx_called;
	adapter->hdd_stats.tx_rx_stats.cont_txtimeout_cnt = 0;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	/* Prevent this function from being called during SSR since TL
	 * context may not be reinitialized at this time which may
	 * lead to a crash.
	 */
	if (cds_is_driver_recovering() || cds_is_driver_in_bad_state() ||
	    cds_is_load_or_unload_in_progress()) {
		QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_INFO_HIGH,
			  "%s: Recovery/(Un)load in Progress. Ignore!!!",
			  __func__);
		goto drop_pkt;
	}

<<<<<<< HEAD
=======
	if (hdd_ctx->hdd_wlan_suspended) {
		hdd_err_rl("Device is system suspended, drop pkt");
		goto drop_pkt;
	}

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	/*
	 * If the device is operating on a DFS Channel
	 * then check if SAP is in CAC WAIT state and
	 * drop the packets. In CAC WAIT state device
	 * is expected not to transmit any frames.
	 * SAP starts Tx only after the BSS START is
	 * done.
	 */
<<<<<<< HEAD
	if (pHddApCtx->dfs_cac_block_tx)
		goto drop_pkt;
=======
	if (ap_ctx->dfs_cac_block_tx)
		goto drop_pkt;

	if (ap_ctx->hostapd_state.bss_state != BSS_START) {
		QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_INFO_HIGH,
			  "%s: SAP is not in START state (%d). Ignore!!!",
			  __func__,
			  ap_ctx->hostapd_state.bss_state);
		goto drop_pkt;
	}
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	/*
	 * If a transmit function is not registered, drop packet
	 */
<<<<<<< HEAD
	if (!pAdapter->tx_fn) {
=======
	if (!adapter->tx_fn) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_INFO_HIGH,
			 "%s: TX function not registered by the data path",
			 __func__);
		goto drop_pkt;
	}

	wlan_hdd_classify_pkt(skb);

<<<<<<< HEAD
	pDestMacAddress = (struct qdf_mac_addr *) skb->data;

	if (QDF_NBUF_CB_GET_IS_BCAST(skb) ||
	    QDF_NBUF_CB_GET_IS_MCAST(skb)) {
		/* The BC/MC station ID is assigned during BSS
		 * starting phase.  SAP will return the station ID
		 * used for BC/MC traffic.
		 */
		STAId = pHddApCtx->uBCStaId;
	} else {
		if (QDF_STATUS_SUCCESS !=
			 hdd_softap_get_sta_id(pAdapter,
				 pDestMacAddress, &STAId)) {
=======
	dest_mac_addr = (struct qdf_mac_addr *)skb->data;

	/* In case of mcast, fetch the bcast sta_info. Else use the pkt addr */
	if (QDF_NBUF_CB_GET_IS_MCAST(skb))
		mac_addr = &bcast_mac_addr;
	else
		mac_addr = dest_mac_addr;

	sta_info = hdd_get_sta_info_by_mac(&adapter->sta_info_list,
					   mac_addr->bytes,
					   STA_INFO_SOFTAP_HARD_START_XMIT);

	if (!QDF_NBUF_CB_GET_IS_BCAST(skb) && !QDF_NBUF_CB_GET_IS_MCAST(skb)) {
		if (!sta_info) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA,
				  QDF_TRACE_LEVEL_INFO_HIGH,
				  "%s: Failed to find right station", __func__);
			goto drop_pkt;
		}

<<<<<<< HEAD
		if (STAId >= WLAN_MAX_STA_COUNT) {
			QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA,
				  QDF_TRACE_LEVEL_INFO_HIGH,
				  "%s: Failed to find right station", __func__);
			goto drop_pkt;
		} else if (false == pAdapter->aStaInfo[STAId].isUsed) {
			QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA,
				  QDF_TRACE_LEVEL_INFO_HIGH,
				  "%s: STA %d is unregistered", __func__,
				  STAId);
			goto drop_pkt;
		} else if (true == pAdapter->aStaInfo[STAId].
							isDeauthInProgress) {
			QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA,
				  QDF_TRACE_LEVEL_INFO_HIGH,
				  "%s: STA %d deauth in progress", __func__,
				  STAId);
			goto drop_pkt;
		}

		if ((OL_TXRX_PEER_STATE_CONN !=
		     pAdapter->aStaInfo[STAId].tlSTAState)
		    && (OL_TXRX_PEER_STATE_AUTH !=
			pAdapter->aStaInfo[STAId].tlSTAState)) {
=======
		if (sta_info->is_deauth_in_progress) {
			QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA,
				  QDF_TRACE_LEVEL_INFO_HIGH,
				  "%s: STA " QDF_MAC_ADDR_FMT
				  "deauth in progress", __func__,
				  QDF_MAC_ADDR_REF(sta_info->sta_mac.bytes));
			goto drop_pkt;
		}

		if (sta_info->peer_state != OL_TXRX_PEER_STATE_CONN &&
		    sta_info->peer_state != OL_TXRX_PEER_STATE_AUTH) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA,
				  QDF_TRACE_LEVEL_INFO_HIGH,
				  "%s: Station not connected yet", __func__);
			goto drop_pkt;
<<<<<<< HEAD
		} else if (OL_TXRX_PEER_STATE_CONN ==
			   pAdapter->aStaInfo[STAId].tlSTAState) {
=======
		}

		if (sta_info->peer_state == OL_TXRX_PEER_STATE_CONN) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			if (ntohs(skb->protocol) != HDD_ETHERTYPE_802_1_X) {
				QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA,
					  QDF_TRACE_LEVEL_INFO_HIGH,
					  "%s: NON-EAPOL packet in non-Authenticated state",
					  __func__);
				goto drop_pkt;
			}
		}
	}

<<<<<<< HEAD
	hdd_get_tx_resource(pAdapter, STAId,
			WLAN_SAP_HDD_TX_FLOW_CONTROL_OS_Q_BLOCK_TIME);

	/* Get TL AC corresponding to Qdisc queue index/AC. */
	ac = hdd_qdisc_ac_to_tl_ac[skb->queue_mapping];
	++pAdapter->hdd_stats.hddTxRxStats.txXmitClassifiedAC[ac];
=======
	if (QDF_NBUF_CB_GET_IS_BCAST(skb) || QDF_NBUF_CB_GET_IS_MCAST(skb))
		hdd_get_tx_resource(
				adapter, &adapter->mac_addr,
				WLAN_SAP_HDD_TX_FLOW_CONTROL_OS_Q_BLOCK_TIME);
	else
		hdd_get_tx_resource(
				adapter, dest_mac_addr,
				WLAN_SAP_HDD_TX_FLOW_CONTROL_OS_Q_BLOCK_TIME);

	/* Get TL AC corresponding to Qdisc queue index/AC. */
	ac = hdd_qdisc_ac_to_tl_ac[skb->queue_mapping];
	++adapter->hdd_stats.tx_rx_stats.tx_classified_ac[ac];
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

#if defined(IPA_OFFLOAD)
	if (!qdf_nbuf_ipa_owned_get(skb)) {
#endif

<<<<<<< HEAD
		skb = hdd_skb_orphan(pAdapter, skb);
=======
		skb = hdd_skb_orphan(adapter, skb);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		if (!skb)
			goto drop_pkt_accounting;

#if defined(IPA_OFFLOAD)
	} else {
		/*
		 * Clear the IPA ownership after check it to avoid ipa_free_skb
		 * is called when Tx completed for intra-BSS Tx packets
		 */
		qdf_nbuf_ipa_owned_clear(skb);
	}
#endif

	/*
	 * Add SKB to internal tracking table before further processing
	 * in WLAN driver.
	 */
	qdf_net_buf_debug_acquire_skb(skb, __FILE__, __LINE__);

<<<<<<< HEAD
	pAdapter->stats.tx_bytes += skb->len;
	pAdapter->aStaInfo[STAId].tx_bytes += skb->len;

	if (qdf_nbuf_is_tso(skb)) {
		num_seg = qdf_nbuf_get_tso_num_seg(skb);
		pAdapter->stats.tx_packets += num_seg;
		pAdapter->aStaInfo[STAId].tx_packets += num_seg;
	} else {
		++pAdapter->stats.tx_packets;
		pAdapter->aStaInfo[STAId].tx_packets++;
	}
	pAdapter->aStaInfo[STAId].last_tx_rx_ts = qdf_system_ticks();

	if (STAId != pHddApCtx->uBCStaId)
		notify_tx_comp = hdd_dhcp_indication(pAdapter,
						     STAId, skb, QDF_TX);
=======
	adapter->stats.tx_bytes += skb->len;

	if (sta_info) {
		sta_info->tx_bytes += skb->len;

		if (qdf_nbuf_is_tso(skb)) {
			num_seg = qdf_nbuf_get_tso_num_seg(skb);
			adapter->stats.tx_packets += num_seg;
			sta_info->tx_packets += num_seg;
		} else {
			++adapter->stats.tx_packets;
			sta_info->tx_packets++;
			hdd_ctx->no_tx_offload_pkt_cnt++;
		}
		sta_info->last_tx_rx_ts = qdf_system_ticks();
	}

	QDF_NBUF_CB_TX_EXTRA_FRAG_FLAGS_NOTIFY_COMP(skb) = 0;

	hdd_softap_inspect_dhcp_packet(adapter, skb, QDF_TX);
	hdd_softap_inspect_tx_eap_pkt(adapter, skb, false);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	hdd_event_eapol_log(skb, QDF_TX);
	QDF_NBUF_CB_TX_PACKET_TRACK(skb) = QDF_NBUF_TX_PKT_DATA_TRACK;
	QDF_NBUF_UPDATE_TX_PKT_COUNT(skb, QDF_NBUF_TX_PKT_HDD);
	qdf_dp_trace_set_track(skb, QDF_TX);
	DPTRACE(qdf_dp_trace(skb, QDF_DP_TRACE_HDD_TX_PACKET_PTR_RECORD,
<<<<<<< HEAD
			qdf_nbuf_data_addr(skb), sizeof(qdf_nbuf_data(skb)),
=======
			QDF_TRACE_DEFAULT_PDEV_ID, qdf_nbuf_data_addr(skb),
			sizeof(qdf_nbuf_data(skb)),
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			QDF_TX));

	/* check whether need to linearize skb, like non-linear udp data */
	if (hdd_skb_nontso_linearize(skb) != QDF_STATUS_SUCCESS) {
		QDF_TRACE(QDF_MODULE_ID_HDD_DATA,
			  QDF_TRACE_LEVEL_INFO_HIGH,
			  "%s: skb %pK linearize failed. drop the pkt",
			  __func__, skb);
<<<<<<< HEAD
		++pAdapter->hdd_stats.hddTxRxStats.txXmitDroppedAC[ac];
		goto drop_pkt_and_release_skb;
	}

	if (pAdapter->tx_fn(ol_txrx_get_vdev_by_sta_id(STAId),
		 (qdf_nbuf_t)skb, notify_tx_comp) != NULL) {
		QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_INFO_HIGH,
			  "%s: Failed to send packet to txrx for staid:%d",
			  __func__, STAId);
		++pAdapter->hdd_stats.hddTxRxStats.txXmitDroppedAC[ac];
=======
		++adapter->hdd_stats.tx_rx_stats.tx_dropped_ac[ac];
		goto drop_pkt_and_release_skb;
	}

	if (adapter->tx_fn(soc, adapter->vdev_id, (qdf_nbuf_t)skb)) {
		QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_INFO_HIGH,
			  "%s: Failed to send packet to txrx for sta: "
			  QDF_MAC_ADDR_FMT, __func__,
			  QDF_MAC_ADDR_REF(dest_mac_addr->bytes));
		++adapter->hdd_stats.tx_rx_stats.tx_dropped_ac[ac];
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		goto drop_pkt_and_release_skb;
	}
	netif_trans_update(dev);

<<<<<<< HEAD
	return NETDEV_TX_OK;
=======
	wlan_hdd_sar_unsolicited_timer_start(hdd_ctx);
	hdd_put_sta_info_ref(&adapter->sta_info_list, &sta_info, true,
			     STA_INFO_SOFTAP_HARD_START_XMIT);

	return;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

drop_pkt_and_release_skb:
	qdf_net_buf_debug_release_skb(skb);
drop_pkt:
<<<<<<< HEAD

	qdf_dp_trace_data_pkt(skb, QDF_DP_TRACE_DROP_PACKET_RECORD, 0,
=======
	qdf_dp_trace_data_pkt(skb, QDF_TRACE_DEFAULT_PDEV_ID,
			      QDF_DP_TRACE_DROP_PACKET_RECORD, 0,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			      QDF_TX);
	kfree_skb(skb);

drop_pkt_accounting:
<<<<<<< HEAD
	++pAdapter->stats.tx_dropped;
	++pAdapter->hdd_stats.hddTxRxStats.txXmitDropped;

	return NETDEV_TX_OK;
}

/**
 * hdd_softap_hard_start_xmit() - Wrapper function to protect
 * __hdd_softap_hard_start_xmit from SSR
 * @skb: pointer to OS packet
 * @dev: pointer to net_device structure
 *
 * Function called by OS if any packet needs to transmit.
 *
 * Return: Always returns NETDEV_TX_OK
 */
netdev_tx_t hdd_softap_hard_start_xmit(struct sk_buff *skb,
				       struct net_device *dev)
{
	netdev_tx_t ret;

	cds_ssr_protect(__func__);
	ret = __hdd_softap_hard_start_xmit(skb, dev);
	cds_ssr_unprotect(__func__);

	return ret;
}

/**
 * __hdd_softap_tx_timeout() - TX timeout handler
 * @dev: pointer to network device
 *
 * This function is registered as a netdev ndo_tx_timeout method, and
 * is invoked by the kernel if the driver takes too long to transmit a
 * frame.
 *
 * Return: None
 */
static void __hdd_softap_tx_timeout(struct net_device *dev)
{
	hdd_adapter_t *adapter = WLAN_HDD_GET_PRIV_PTR(dev);
	hdd_context_t *hdd_ctx;
	struct netdev_queue *txq;
	int i;

	DPTRACE(qdf_dp_trace(NULL, QDF_DP_TRACE_HDD_SOFTAP_TX_TIMEOUT,
				NULL, 0, QDF_TX));
=======
	if (sta_info)
		hdd_put_sta_info_ref(&adapter->sta_info_list, &sta_info, true,
				     STA_INFO_SOFTAP_HARD_START_XMIT);
	++adapter->stats.tx_dropped;
	++adapter->hdd_stats.tx_rx_stats.tx_dropped;
}

netdev_tx_t hdd_softap_hard_start_xmit(struct sk_buff *skb,
				       struct net_device *net_dev)
{
	struct osif_vdev_sync *vdev_sync;

	if (osif_vdev_sync_op_start(net_dev, &vdev_sync)) {
		hdd_debug_rl("Operation on net_dev is not permitted");
		kfree_skb(skb);
		return NETDEV_TX_OK;
	}

	__hdd_softap_hard_start_xmit(skb, net_dev);

	osif_vdev_sync_op_stop(vdev_sync);

	return NETDEV_TX_OK;
}

QDF_STATUS hdd_softap_ipa_start_xmit(qdf_nbuf_t nbuf, qdf_netdev_t dev)
{
	if (NETDEV_TX_OK == hdd_softap_hard_start_xmit(
					(struct sk_buff *)nbuf,
					(struct net_device *)dev))
		return QDF_STATUS_SUCCESS;
	else
		return QDF_STATUS_E_FAILURE;
}

static void __hdd_softap_tx_timeout(struct net_device *dev)
{
	struct hdd_adapter *adapter = WLAN_HDD_GET_PRIV_PTR(dev);
	struct hdd_context *hdd_ctx;
	struct netdev_queue *txq;
	void *soc = cds_get_context(QDF_MODULE_ID_SOC);
	int i;

	DPTRACE(qdf_dp_trace(NULL, QDF_DP_TRACE_HDD_SOFTAP_TX_TIMEOUT,
			QDF_TRACE_DEFAULT_PDEV_ID,
			NULL, 0, QDF_TX));
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	/* Getting here implies we disabled the TX queues for too
	 * long. Queues are disabled either because of disassociation
	 * or low resource scenarios. In case of disassociation it is
	 * ok to ignore this. But if associated, we have do possible
	 * recovery here
	 */
	hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	if (cds_is_driver_recovering() || cds_is_driver_in_bad_state()) {
<<<<<<< HEAD
		QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_WARN,
=======
		QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_ERROR,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			 "%s: Recovery in Progress. Ignore!!!", __func__);
		return;
	}

<<<<<<< HEAD
=======
	if (hdd_ctx->hdd_wlan_suspended) {
		hdd_debug("wlan is suspended, ignore timeout");
		return;
	}

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	TX_TIMEOUT_TRACE(dev, QDF_MODULE_ID_HDD_SAP_DATA);

	for (i = 0; i < NUM_TX_QUEUES; i++) {
		txq = netdev_get_tx_queue(dev, i);
		QDF_TRACE(QDF_MODULE_ID_HDD_DATA,
			  QDF_TRACE_LEVEL_DEBUG,
			  "Queue: %d status: %d txq->trans_start: %lu",
			  i, netif_tx_queue_stopped(txq), txq->trans_start);
	}

<<<<<<< HEAD
	wlan_hdd_display_netif_queue_history(hdd_ctx, QDF_STATS_VERB_LVL_HIGH);
	ol_tx_dump_flow_pool_info();
	QDF_TRACE(QDF_MODULE_ID_HDD_DATA, QDF_TRACE_LEVEL_DEBUG,
			"carrier state: %d", netif_carrier_ok(dev));

	++adapter->hdd_stats.hddTxRxStats.tx_timeout_cnt;
	++adapter->hdd_stats.hddTxRxStats.cont_txtimeout_cnt;

	if (adapter->hdd_stats.hddTxRxStats.cont_txtimeout_cnt >
	    HDD_TX_STALL_THRESHOLD) {
		QDF_TRACE(QDF_MODULE_ID_HDD_DATA, QDF_TRACE_LEVEL_ERROR,
			  "Detected data stall due to continuous TX timeouts");
		adapter->hdd_stats.hddTxRxStats.cont_txtimeout_cnt = 0;
		if (hdd_ctx->config->enable_data_stall_det)
			ol_txrx_post_data_stall_event(
					DATA_STALL_LOG_INDICATOR_HOST_DRIVER,
					DATA_STALL_LOG_HOST_SOFTAP_TX_TIMEOUT,
					0xFF, 0xFF,
					DATA_STALL_LOG_RECOVERY_TRIGGER_PDR);
	}
}

/**
 * hdd_softap_tx_timeout() - SSR wrapper for __hdd_softap_tx_timeout
 * @dev: pointer to net_device
 *
 * Return: none
 */
void hdd_softap_tx_timeout(struct net_device *dev)
{
	cds_ssr_protect(__func__);
	__hdd_softap_tx_timeout(dev);
	cds_ssr_unprotect(__func__);
}

/**
 * @hdd_softap_init_tx_rx() - Initialize Tx/RX module
 * @pAdapter: pointer to adapter context
 *
 * Return: QDF_STATUS_E_FAILURE if any errors encountered,
 *	   QDF_STATUS_SUCCESS otherwise
 */
QDF_STATUS hdd_softap_init_tx_rx(hdd_adapter_t *pAdapter)
{
	QDF_STATUS status = QDF_STATUS_SUCCESS;

	uint8_t STAId = 0;

	qdf_mem_zero(&pAdapter->stats, sizeof(struct net_device_stats));

	spin_lock_init(&pAdapter->staInfo_lock);

	for (STAId = 0; STAId < WLAN_MAX_STA_COUNT; STAId++) {
		qdf_mem_zero(&pAdapter->aStaInfo[STAId],
			     sizeof(hdd_station_info_t));
	}

	return status;
}

/**
 * @hdd_softap_deinit_tx_rx() - Deinitialize Tx/RX module
 * @pAdapter: pointer to adapter context
 *
 * Return: QDF_STATUS_E_FAILURE if any errors encountered,
 *	   QDF_STATUS_SUCCESS otherwise
 */
QDF_STATUS hdd_softap_deinit_tx_rx(hdd_adapter_t *pAdapter)
{
	QDF_STATUS status = QDF_STATUS_SUCCESS;

	return status;
}

/**
 * hdd_softap_init_tx_rx_sta() - Initialize tx/rx for a softap station
 * @pAdapter: pointer to adapter context
 * @STAId: Station ID to initialize
 * @pmacAddrSTA: pointer to the MAC address of the station
 *
 * Return: QDF_STATUS_E_FAILURE if any errors encountered,
 *	   QDF_STATUS_SUCCESS otherwise
 */
QDF_STATUS hdd_softap_init_tx_rx_sta(hdd_adapter_t *pAdapter, uint8_t STAId,
				     struct qdf_mac_addr *pmacAddrSTA)
{
	spin_lock_bh(&pAdapter->staInfo_lock);
	if (pAdapter->aStaInfo[STAId].isUsed) {
		spin_unlock_bh(&pAdapter->staInfo_lock);
		hdd_err("Reinit of in use station %d", STAId);
		return QDF_STATUS_E_FAILURE;
	}

	qdf_mem_zero(&pAdapter->aStaInfo[STAId], sizeof(hdd_station_info_t));

	pAdapter->aStaInfo[STAId].isUsed = true;
	pAdapter->aStaInfo[STAId].isDeauthInProgress = false;
	qdf_copy_macaddr(&pAdapter->aStaInfo[STAId].macAddrSTA, pmacAddrSTA);

	spin_unlock_bh(&pAdapter->staInfo_lock);
	return QDF_STATUS_SUCCESS;
}

/**
 * hdd_softap_deinit_tx_rx_sta() - Deinitialize tx/rx for a softap station
 * @pAdapter: pointer to adapter context
 * @STAId: Station ID to deinitialize
 *
 * Return: QDF_STATUS_E_FAILURE if any errors encountered,
 *	   QDF_STATUS_SUCCESS otherwise
 */
QDF_STATUS hdd_softap_deinit_tx_rx_sta(hdd_adapter_t *pAdapter, uint8_t STAId)
{
	QDF_STATUS status = QDF_STATUS_SUCCESS;
	hdd_hostapd_state_t *pHostapdState;

	pHostapdState = WLAN_HDD_GET_HOSTAP_STATE_PTR(pAdapter);

	spin_lock_bh(&pAdapter->staInfo_lock);

	if (false == pAdapter->aStaInfo[STAId].isUsed) {
		spin_unlock_bh(&pAdapter->staInfo_lock);
		hdd_err("Deinit station not inited %d", STAId);
		return QDF_STATUS_E_FAILURE;
	}

	pAdapter->aStaInfo[STAId].isUsed = false;
	pAdapter->aStaInfo[STAId].isDeauthInProgress = false;

	spin_unlock_bh(&pAdapter->staInfo_lock);
	return status;
}
=======
	wlan_hdd_display_adapter_netif_queue_history(adapter);

	cdp_dump_flow_pool_info(cds_get_context(QDF_MODULE_ID_SOC));
	QDF_TRACE(QDF_MODULE_ID_HDD_DATA, QDF_TRACE_LEVEL_DEBUG,
			"carrier state: %d", netif_carrier_ok(dev));

	++adapter->hdd_stats.tx_rx_stats.tx_timeout_cnt;
	++adapter->hdd_stats.tx_rx_stats.cont_txtimeout_cnt;

	if (adapter->hdd_stats.tx_rx_stats.cont_txtimeout_cnt >
	    HDD_TX_STALL_THRESHOLD) {
		QDF_TRACE(QDF_MODULE_ID_HDD_DATA, QDF_TRACE_LEVEL_ERROR,
			  "Detected data stall due to continuous TX timeouts");
		adapter->hdd_stats.tx_rx_stats.cont_txtimeout_cnt = 0;

		if (cdp_cfg_get(soc, cfg_dp_enable_data_stall))
			cdp_post_data_stall_event(soc,
					  DATA_STALL_LOG_INDICATOR_HOST_DRIVER,
					  DATA_STALL_LOG_HOST_SOFTAP_TX_TIMEOUT,
					  OL_TXRX_PDEV_ID, 0xFF,
					  DATA_STALL_LOG_RECOVERY_TRIGGER_PDR);
	}
}

void hdd_softap_tx_timeout(struct net_device *net_dev)
{
	struct osif_vdev_sync *vdev_sync;

	if (osif_vdev_sync_op_start(net_dev, &vdev_sync))
		return;

	__hdd_softap_tx_timeout(net_dev);

	osif_vdev_sync_op_stop(vdev_sync);
}

void hdd_softap_init_tx_rx(struct hdd_adapter *adapter)
{
	qdf_mem_zero(&adapter->stats, sizeof(struct net_device_stats));
}

QDF_STATUS hdd_softap_deinit_tx_rx(struct hdd_adapter *adapter)
{
	QDF_BUG(adapter);
	if (!adapter)
		return QDF_STATUS_E_FAILURE;

	adapter->tx_fn = NULL;

	return QDF_STATUS_SUCCESS;
}

static void
hdd_reset_sta_info_during_reattach(struct hdd_station_info *sta_info)
{
	sta_info->in_use = 0;
	sta_info->sta_id = 0;
	sta_info->sta_type = 0;
	qdf_mem_zero(&sta_info->sta_mac, QDF_MAC_ADDR_SIZE);
	sta_info->peer_state = 0;
	sta_info->is_qos_enabled = 0;
	sta_info->is_deauth_in_progress = 0;
	sta_info->nss = 0;
	sta_info->rate_flags = 0;
	sta_info->ecsa_capable = 0;
	sta_info->max_phy_rate = 0;
	sta_info->tx_packets = 0;
	sta_info->tx_bytes = 0;
	sta_info->rx_packets = 0;
	sta_info->rx_bytes = 0;
	sta_info->last_tx_rx_ts = 0;
	sta_info->assoc_ts = 0;
	sta_info->disassoc_ts = 0;
	sta_info->tx_rate = 0;
	sta_info->rx_rate = 0;
	sta_info->ampdu = 0;
	sta_info->sgi_enable = 0;
	sta_info->tx_stbc = 0;
	sta_info->rx_stbc = 0;
	sta_info->ch_width = 0;
	sta_info->mode = 0;
	sta_info->max_supp_idx = 0;
	sta_info->max_ext_idx = 0;
	sta_info->max_mcs_idx = 0;
	sta_info->rx_mcs_map = 0;
	sta_info->tx_mcs_map = 0;
	sta_info->freq = 0;
	sta_info->dot11_mode = 0;
	sta_info->ht_present = 0;
	sta_info->vht_present = 0;
	qdf_mem_zero(&sta_info->ht_caps, sizeof(sta_info->ht_caps));
	qdf_mem_zero(&sta_info->vht_caps, sizeof(sta_info->vht_caps));
	sta_info->reason_code = 0;
	sta_info->rssi = 0;
	sta_info->dhcp_phase = 0;
	sta_info->dhcp_nego_status = 0;
	sta_info->capability = 0;
	sta_info->support_mode = 0;
	sta_info->rx_retry_cnt = 0;
	sta_info->rx_mc_bc_cnt = 0;

	if (sta_info->assoc_req_ies.len) {
		qdf_mem_free(sta_info->assoc_req_ies.data);
		sta_info->assoc_req_ies.data = NULL;
		sta_info->assoc_req_ies.len = 0;
	}

	sta_info->pending_eap_frm_type = 0;
}

/**
 * hdd_sta_info_re_attach() - Re-Attach the station info structure into the list
 * @sta_info_container: The station info container obj that stores and maintains
 *                      the sta_info obj.
 * @sta_info: The station info structure that is to be attached to the
 *            container object.
 *
 * This function re-attaches the station if it gets re-connect after
 * disconnecting and before its all references are released.
 *
 * Return: QDF STATUS SUCCESS on successful attach, error code otherwise
 */

static QDF_STATUS hdd_sta_info_re_attach(
				struct hdd_sta_info_obj *sta_info_container,
				struct hdd_station_info *sta_info,
				struct qdf_mac_addr *sta_mac)
{
	if (!sta_info_container || !sta_info) {
		hdd_err("Parameter(s) null");
		return QDF_STATUS_E_INVAL;
	}

	qdf_spin_lock_bh(&sta_info_container->sta_obj_lock);

	if (sta_info->is_attached) {
		qdf_spin_unlock_bh(&sta_info_container->sta_obj_lock);
		hdd_err("sta info is alredy attached");
		return QDF_STATUS_SUCCESS;
	}

	hdd_reset_sta_info_during_reattach(sta_info);
	/* Add one extra ref for reattach */
	hdd_take_sta_info_ref(sta_info_container, sta_info, false,
			      STA_INFO_ATTACH_DETACH);
	qdf_mem_copy(&sta_info->sta_mac, sta_mac, sizeof(struct qdf_mac_addr));
	sta_info->is_attached = true;
	qdf_spin_unlock_bh(&sta_info_container->sta_obj_lock);

	return QDF_STATUS_SUCCESS;
}

QDF_STATUS hdd_softap_init_tx_rx_sta(struct hdd_adapter *adapter,
				     struct qdf_mac_addr *sta_mac)
{
	struct hdd_station_info *sta_info;
	QDF_STATUS status;

	sta_info = hdd_get_sta_info_by_mac(&adapter->sta_info_list,
					   sta_mac->bytes,
					   STA_INFO_SOFTAP_INIT_TX_RX_STA);

	if (sta_info) {
		hdd_err("Reinit of in use station " QDF_MAC_ADDR_FMT,
			QDF_MAC_ADDR_REF(sta_mac->bytes));
		status = hdd_sta_info_re_attach(&adapter->sta_info_list,
						sta_info, sta_mac);
		hdd_put_sta_info_ref(&adapter->sta_info_list, &sta_info, true,
				     STA_INFO_SOFTAP_INIT_TX_RX_STA);
		return status;
	}

	sta_info = qdf_mem_malloc(sizeof(struct hdd_station_info));
	if (!sta_info)
		return QDF_STATUS_E_NOMEM;

	sta_info->is_deauth_in_progress = false;
	qdf_mem_copy(&sta_info->sta_mac, sta_mac, sizeof(struct qdf_mac_addr));

	status = hdd_sta_info_attach(&adapter->sta_info_list, sta_info);
	if (QDF_IS_STATUS_ERROR(status)) {
		hdd_err("Failed to attach station: " QDF_MAC_ADDR_FMT,
			QDF_MAC_ADDR_REF(sta_mac->bytes));
		qdf_mem_free(sta_info);
	}

	return status;
}

/**
 * hdd_softap_tsf_timestamp_rx() - time stamp Rx netbuf
 * @context: pointer to HDD context
 * @netbuf: pointer to a Rx netbuf
 *
 * Return: None
 */
#ifdef WLAN_FEATURE_TSF_PLUS
static inline void hdd_softap_tsf_timestamp_rx(struct hdd_context *hdd_ctx,
					       qdf_nbuf_t netbuf)
{
	uint64_t target_time;

	if (!hdd_tsf_is_rx_set(hdd_ctx))
		return;

	target_time = ktime_to_us(netbuf->tstamp);
	hdd_rx_timestamp(netbuf, target_time);
}
#else
static inline void hdd_softap_tsf_timestamp_rx(struct hdd_context *hdd_ctx,
					       qdf_nbuf_t netbuf)
{
}
#endif
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * hdd_softap_notify_tx_compl_cbk() - callback to notify tx completion
 * @skb: pointer to skb data
 * @adapter: pointer to vdev apdapter
 *
 * Return: None
 */
<<<<<<< HEAD
void hdd_softap_notify_tx_compl_cbk(struct sk_buff *skb,
				    void *context)
{
	int errno;
	hdd_adapter_t *adapter = NULL;

	adapter = (hdd_adapter_t *)context;
=======
static void hdd_softap_notify_tx_compl_cbk(struct sk_buff *skb,
					   void *context)
{
	int errno;
	struct hdd_adapter *adapter = context;

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	errno = hdd_validate_adapter(adapter);
	if (errno)
		return;

<<<<<<< HEAD
	if (QDF_NBUF_CB_PACKET_TYPE_DHCP == QDF_NBUF_CB_GET_PACKET_TYPE(skb))
		hdd_softap_notify_dhcp_ind(context, skb);
}

/**
 * hdd_softap_rx_packet_cbk() - Receive packet handler
 * @context: pointer to HDD context
 * @rxBuf: pointer to rx qdf_nbuf
 *
 * Receive callback registered with TL.  TL will call this to notify
 * the HDD when one or more packets were received for a registered
 * STA.
 *
 * Return: QDF_STATUS_E_FAILURE if any errors encountered,
 *	   QDF_STATUS_SUCCESS otherwise
 */
QDF_STATUS hdd_softap_rx_packet_cbk(void *context, qdf_nbuf_t rxBuf)
{
	hdd_adapter_t *pAdapter = NULL;
	int rxstat;
	unsigned int cpu_index;
	struct sk_buff *skb = NULL;
	hdd_context_t *pHddCtx = NULL;
	struct qdf_mac_addr src_mac;
	uint8_t staid = 0;

	/* Sanity check on inputs */
	if (unlikely((NULL == context) || (NULL == rxBuf))) {
=======
	if (QDF_NBUF_CB_PACKET_TYPE_DHCP == QDF_NBUF_CB_GET_PACKET_TYPE(skb)) {
		hdd_debug("sending DHCP indication");
		hdd_softap_notify_dhcp_ind(context, skb);
	} else if (QDF_NBUF_CB_GET_PACKET_TYPE(skb) ==
						QDF_NBUF_CB_PACKET_TYPE_EAPOL) {
		hdd_softap_inspect_tx_eap_pkt(adapter, skb, true);
	}
}

QDF_STATUS hdd_softap_rx_packet_cbk(void *adapter_context, qdf_nbuf_t rx_buf)
{
	struct hdd_adapter *adapter = NULL;
	QDF_STATUS qdf_status;
	unsigned int cpu_index;
	struct sk_buff *skb = NULL;
	struct sk_buff *next = NULL;
	struct hdd_context *hdd_ctx = NULL;
	struct qdf_mac_addr *src_mac;
	struct hdd_station_info *sta_info;

	/* Sanity check on inputs */
	if (unlikely((!adapter_context) || (!rx_buf))) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_ERROR,
			  "%s: Null params being passed", __func__);
		return QDF_STATUS_E_FAILURE;
	}

<<<<<<< HEAD
	pAdapter = (hdd_adapter_t *)context;
	if (unlikely(WLAN_HDD_ADAPTER_MAGIC != pAdapter->magic)) {
		QDF_TRACE(QDF_MODULE_ID_HDD_DATA, QDF_TRACE_LEVEL_ERROR,
			  "Magic cookie(%x) for adapter sanity verification is invalid",
			  pAdapter->magic);
		return QDF_STATUS_E_FAILURE;
	}

	pHddCtx = pAdapter->pHddCtx;
	if (unlikely(NULL == pHddCtx)) {
=======
	adapter = (struct hdd_adapter *)adapter_context;
	if (unlikely(WLAN_HDD_ADAPTER_MAGIC != adapter->magic)) {
		QDF_TRACE(QDF_MODULE_ID_HDD_DATA, QDF_TRACE_LEVEL_ERROR,
			  "Magic cookie(%x) for adapter sanity verification is invalid",
			  adapter->magic);
		return QDF_STATUS_E_FAILURE;
	}

	hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	if (unlikely(!hdd_ctx)) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_ERROR,
			  "%s: HDD context is Null", __func__);
		return QDF_STATUS_E_FAILURE;
	}

	/* walk the chain until all are processed */
<<<<<<< HEAD
	skb = (struct sk_buff *)rxBuf;

	hdd_softap_dump_sk_buff(skb);

	skb->dev = pAdapter->dev;

	if (unlikely(skb->dev == NULL)) {
		QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA, QDF_TRACE_LEVEL_ERROR,
			  "%s: ERROR!!Invalid netdevice", __func__);
		return QDF_STATUS_E_FAILURE;
	}
	cpu_index = wlan_hdd_get_cpu();
	++pAdapter->hdd_stats.hddTxRxStats.rxPackets[cpu_index];
	++pAdapter->stats.rx_packets;
	pAdapter->stats.rx_bytes += skb->len;

	qdf_mem_copy(&src_mac, skb->data + QDF_NBUF_SRC_MAC_OFFSET,
		sizeof(src_mac));
	if (QDF_STATUS_SUCCESS ==
		hdd_softap_get_sta_id(pAdapter, &src_mac, &staid)) {
		if (staid < WLAN_MAX_STA_COUNT) {
			pAdapter->aStaInfo[staid].rx_packets++;
			pAdapter->aStaInfo[staid].rx_bytes += skb->len;
			pAdapter->aStaInfo[staid].last_tx_rx_ts =
				qdf_system_ticks();
		}
	}

	hdd_dhcp_indication(pAdapter, staid, skb, QDF_RX);

	hdd_event_eapol_log(skb, QDF_RX);
	qdf_dp_trace_log_pkt(pAdapter->sessionId, skb, QDF_RX);
	DPTRACE(qdf_dp_trace(skb,
		QDF_DP_TRACE_RX_HDD_PACKET_PTR_RECORD,
		qdf_nbuf_data_addr(skb),
		sizeof(qdf_nbuf_data(skb)), QDF_RX));
	DPTRACE(qdf_dp_trace_data_pkt(skb,
				      QDF_DP_TRACE_RX_PACKET_RECORD,
				      0, QDF_RX));

	skb->protocol = eth_type_trans(skb, skb->dev);

	/* hold configurable wakelock for unicast traffic */
	if (pHddCtx->config->rx_wakelock_timeout &&
	    skb->pkt_type != PACKET_BROADCAST &&
	    skb->pkt_type != PACKET_MULTICAST) {
		cds_host_diag_log_work(&pHddCtx->rx_wake_lock,
				       pHddCtx->config->rx_wakelock_timeout,
				       WIFI_POWER_EVENT_WAKELOCK_HOLD_RX);
		qdf_wake_lock_timeout_acquire(&pHddCtx->rx_wake_lock,
					      pHddCtx->config->
						      rx_wakelock_timeout);
	}

	/* Remove SKB from internal tracking table before submitting
	 * it to stack
	 */
	qdf_net_buf_debug_release_skb(rxBuf);
	if (hdd_napi_enabled(HDD_NAPI_ANY) &&
		!pHddCtx->enableRxThread)
		rxstat = netif_receive_skb(skb);
	else
		rxstat = netif_rx_ni(skb);
	if (NET_RX_SUCCESS == rxstat)
		++pAdapter->hdd_stats.hddTxRxStats.rxDelivered[cpu_index];
	else
		++pAdapter->hdd_stats.hddTxRxStats.rxRefused[cpu_index];
=======
	next = (struct sk_buff *)rx_buf;

	while (next) {
		skb = next;
		next = skb->next;
		skb->next = NULL;

/* Debug code, remove later */
#if defined(QCA_WIFI_QCA6290) || defined(QCA_WIFI_QCA6390) || \
    defined(QCA_WIFI_QCA6490) || defined(QCA_WIFI_QCA6750)
		QDF_TRACE(QDF_MODULE_ID_HDD_DATA, QDF_TRACE_LEVEL_DEBUG,
			 "%s: skb %pK skb->len %d\n", __func__, skb, skb->len);
#endif

		hdd_softap_dump_sk_buff(skb);

		skb->dev = adapter->dev;

		if (unlikely(!skb->dev)) {
			QDF_TRACE(QDF_MODULE_ID_HDD_SAP_DATA,
				  QDF_TRACE_LEVEL_ERROR,
				  "%s: ERROR!!Invalid netdevice", __func__);
			qdf_nbuf_free(skb);
			continue;
		}
		cpu_index = wlan_hdd_get_cpu();
		++adapter->hdd_stats.tx_rx_stats.rx_packets[cpu_index];
		++adapter->stats.rx_packets;
		adapter->stats.rx_bytes += skb->len;

		/* Send DHCP Indication to FW */
		src_mac = (struct qdf_mac_addr *)(skb->data +
						  QDF_NBUF_SRC_MAC_OFFSET);
		sta_info = hdd_get_sta_info_by_mac(
					&adapter->sta_info_list,
					(uint8_t *)src_mac,
					STA_INFO_SOFTAP_RX_PACKET_CBK);

		if (sta_info) {
			sta_info->rx_packets++;
			sta_info->rx_bytes += skb->len;
			sta_info->last_tx_rx_ts = qdf_system_ticks();
			hdd_softap_inspect_dhcp_packet(adapter, skb, QDF_RX);
			hdd_put_sta_info_ref(&adapter->sta_info_list, &sta_info,
					     true,
					     STA_INFO_SOFTAP_RX_PACKET_CBK);
		}

		if (qdf_unlikely(qdf_nbuf_is_ipv4_eapol_pkt(skb) &&
				 qdf_mem_cmp(qdf_nbuf_data(skb) +
					     QDF_NBUF_DEST_MAC_OFFSET,
					     adapter->mac_addr.bytes,
					     QDF_MAC_ADDR_SIZE))) {
			qdf_nbuf_free(skb);
			continue;
		}

		hdd_event_eapol_log(skb, QDF_RX);
		qdf_dp_trace_log_pkt(adapter->vdev_id,
				     skb, QDF_RX, QDF_TRACE_DEFAULT_PDEV_ID);
		DPTRACE(qdf_dp_trace(skb,
			QDF_DP_TRACE_RX_HDD_PACKET_PTR_RECORD,
			QDF_TRACE_DEFAULT_PDEV_ID,
			qdf_nbuf_data_addr(skb),
			sizeof(qdf_nbuf_data(skb)), QDF_RX));
		DPTRACE(qdf_dp_trace_data_pkt(skb, QDF_TRACE_DEFAULT_PDEV_ID,
				QDF_DP_TRACE_RX_PACKET_RECORD, 0, QDF_RX));

		skb->protocol = eth_type_trans(skb, skb->dev);

		/* Remove SKB from internal tracking table before submitting
		 * it to stack
		 */
		qdf_net_buf_debug_release_skb(skb);

		hdd_softap_tsf_timestamp_rx(hdd_ctx, skb);

		qdf_status = hdd_rx_deliver_to_stack(adapter, skb);

		if (QDF_IS_STATUS_SUCCESS(qdf_status))
			++adapter->hdd_stats.tx_rx_stats.rx_delivered[cpu_index];
		else
			++adapter->hdd_stats.tx_rx_stats.rx_refused[cpu_index];
	}
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	return QDF_STATUS_SUCCESS;
}

<<<<<<< HEAD
/**
 * hdd_softap_deregister_sta(hdd_adapter_t *pAdapter, uint8_t staId)
 * @pAdapter: pointer to adapter context
 * @staId: Station ID to deregister
 *
 * Return: QDF_STATUS_SUCCESS on success, QDF_STATUS_E_** on error
 */
QDF_STATUS hdd_softap_deregister_sta(hdd_adapter_t *pAdapter, uint8_t staId)
{
	QDF_STATUS qdf_status = QDF_STATUS_SUCCESS;
	hdd_context_t *pHddCtx;

	if (NULL == pAdapter) {
=======
QDF_STATUS hdd_softap_deregister_sta(struct hdd_adapter *adapter,
				     struct hdd_station_info **sta_info)
{
	struct hdd_context *hdd_ctx;
	struct qdf_mac_addr *mac_addr;
	struct hdd_station_info *sta = *sta_info;

	if (!adapter) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		hdd_err("NULL adapter");
		return QDF_STATUS_E_INVAL;
	}

<<<<<<< HEAD
	if (WLAN_HDD_ADAPTER_MAGIC != pAdapter->magic) {
=======
	if (WLAN_HDD_ADAPTER_MAGIC != adapter->magic) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		hdd_err("Invalid adapter magic");
		return QDF_STATUS_E_INVAL;
	}

<<<<<<< HEAD
	pHddCtx = (hdd_context_t *) (pAdapter->pHddCtx);
	/* Clear station in TL and then update HDD data
	 * structures. This helps to block RX frames from other
	 * station to this station.
	 */
	qdf_status = ol_txrx_clear_peer(staId);
	if (!QDF_IS_STATUS_SUCCESS(qdf_status))
		hdd_err("ol_txrx_clear_peer() failed for staID %d, Status= %d [0x%08X]",
			staId, qdf_status, qdf_status);

	if (pAdapter->aStaInfo[staId].isUsed) {
		if (hdd_ipa_uc_is_enabled(pHddCtx)) {
			if (hdd_ipa_wlan_evt(pAdapter,
					 pAdapter->aStaInfo[staId].ucSTAId,
					 HDD_IPA_CLIENT_DISCONNECT,
					 pAdapter->aStaInfo[staId].macAddrSTA.
					 bytes))
				hdd_err("WLAN_CLIENT_DISCONNECT event failed");
		}
		spin_lock_bh(&pAdapter->staInfo_lock);
		qdf_mem_zero(&pAdapter->aStaInfo[staId],
			     sizeof(hdd_station_info_t));
		spin_unlock_bh(&pAdapter->staInfo_lock);
	}
	pHddCtx->sta_to_adapter[staId] = NULL;

	return qdf_status;
}

/**
 * hdd_softap_register_sta() - Register a SoftAP STA
 * @pAdapter: pointer to adapter context
 * @fAuthRequired: is additional authentication required?
 * @fPrivacyBit: should 802.11 privacy bit be set?
 * @staId: station ID assigned to this station
 * @ucastSig: unicast security signature
 * @bcastSig: broadcast security signature
 * @pPeerMacAddress: station MAC address
 * @fWmmEnabled: is WMM enabled for this STA?
 *
 * Return: QDF_STATUS_SUCCESS on success, QDF_STATUS_E_** on error
 */
QDF_STATUS hdd_softap_register_sta(hdd_adapter_t *pAdapter,
				   bool fAuthRequired,
				   bool fPrivacyBit,
				   uint8_t staId,
				   uint8_t ucastSig,
				   uint8_t bcastSig,
				   struct qdf_mac_addr *pPeerMacAddress,
				   bool fWmmEnabled)
{
	QDF_STATUS qdf_status = QDF_STATUS_E_FAILURE;
	struct ol_txrx_desc_type staDesc = { 0 };
	hdd_context_t *pHddCtx = pAdapter->pHddCtx;
	struct ol_txrx_ops txrx_ops;

	hdd_info("STA:%u, Auth:%u, Priv:%u, WMM:%u",
		 staId, fAuthRequired, fPrivacyBit, fWmmEnabled);

	/*
	 * Clean up old entry if it is not cleaned up properly
	 */
	if (pAdapter->aStaInfo[staId].isUsed) {
		hdd_info("clean up old entry for STA %d", staId);
		hdd_softap_deregister_sta(pAdapter, staId);
	}

	/* Get the Station ID from the one saved during the assocation. */
	staDesc.sta_id = staId;

	/* Save the pAdapter Pointer for this staId */
	pHddCtx->sta_to_adapter[staId] = pAdapter;

	qdf_status =
		hdd_softap_init_tx_rx_sta(pAdapter, staId,
					  pPeerMacAddress);

	staDesc.is_qos_enabled = fWmmEnabled;

	/* Register the vdev transmit and receive functions */
	qdf_mem_zero(&txrx_ops, sizeof(txrx_ops));
	txrx_ops.rx.rx = hdd_softap_rx_packet_cbk;
	txrx_ops.tx.tx_comp = hdd_softap_notify_tx_compl_cbk;
	ol_txrx_vdev_register(
		 ol_txrx_get_vdev_from_vdev_id(pAdapter->sessionId),
		 pAdapter, &txrx_ops);
	pAdapter->tx_fn = txrx_ops.tx.tx;

	qdf_status = ol_txrx_register_peer(&staDesc);
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		hdd_err("ol_txrx_register_peer() failed to register.  Status= %d [0x%08X]",
			qdf_status, qdf_status);
=======
	if (!sta) {
		hdd_err("Invalid station");
		return QDF_STATUS_E_INVAL;
	}

	hdd_ctx = WLAN_HDD_GET_CTX(adapter);

	if (!hdd_ctx) {
		hdd_err("HDD context is null");
		return QDF_STATUS_E_INVAL;
	}

	/*
	 * If the address is a broadcast address then the CDP layers expects
	 * the self mac address of the adapter.
	 */
	if (QDF_IS_ADDR_BROADCAST(sta->sta_mac.bytes))
		mac_addr = &adapter->mac_addr;
	else
		mac_addr = &sta->sta_mac;

	if (ucfg_ipa_is_enabled()) {
		if (ucfg_ipa_wlan_evt(hdd_ctx->pdev, adapter->dev,
				      adapter->device_mode,
				      adapter->vdev_id,
				      WLAN_IPA_CLIENT_DISCONNECT,
				      mac_addr->bytes) != QDF_STATUS_SUCCESS)
			hdd_debug("WLAN_CLIENT_DISCONNECT event failed");
	}
	hdd_sta_info_detach(&adapter->sta_info_list, &sta);

	ucfg_mlme_update_oce_flags(hdd_ctx->pdev);

	return QDF_STATUS_SUCCESS;
}

QDF_STATUS hdd_softap_register_sta(struct hdd_adapter *adapter,
				   bool auth_required,
				   bool privacy_required,
				   struct qdf_mac_addr *sta_mac,
				   bool wmm_enabled)
{
	QDF_STATUS qdf_status = QDF_STATUS_E_FAILURE;
	struct ol_txrx_desc_type txrx_desc = {0};
	struct hdd_context *hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	struct ol_txrx_ops txrx_ops;
	void *soc = cds_get_context(QDF_MODULE_ID_SOC);
	struct hdd_ap_ctx *ap_ctx;
	struct hdd_station_info *sta_info;

	ap_ctx = WLAN_HDD_GET_AP_CTX_PTR(adapter);

	/*
	 * If the address is a broadcast address, then provide the self mac addr
	 * to the data path. Else provide the mac address of the connected peer.
	 */
	if (qdf_is_macaddr_broadcast(sta_mac) && ap_ctx)
		qdf_mem_copy(&txrx_desc.peer_addr, &adapter->mac_addr,
			     QDF_MAC_ADDR_SIZE);
	else
		qdf_mem_copy(&txrx_desc.peer_addr, sta_mac,
			     QDF_MAC_ADDR_SIZE);

	qdf_status = hdd_softap_init_tx_rx_sta(adapter, sta_mac);
	sta_info = hdd_get_sta_info_by_mac(&adapter->sta_info_list,
					   sta_mac->bytes,
					   STA_INFO_SOFTAP_REGISTER_STA);

	if (!sta_info) {
		hdd_debug("STA not found");
		return QDF_STATUS_E_INVAL;
	}

	txrx_desc.is_qos_enabled = wmm_enabled;

	/* Register the vdev transmit and receive functions */
	qdf_mem_zero(&txrx_ops, sizeof(txrx_ops));

	txrx_ops.tx.tx_comp = hdd_softap_notify_tx_compl_cbk;

	if (adapter->hdd_ctx->enable_dp_rx_threads) {
		txrx_ops.rx.rx = hdd_rx_pkt_thread_enqueue_cbk;
		txrx_ops.rx.rx_stack = hdd_softap_rx_packet_cbk;
		txrx_ops.rx.rx_flush = hdd_rx_flush_packet_cbk;
		txrx_ops.rx.rx_gro_flush = hdd_rx_thread_gro_flush_ind_cbk;
	} else {
		txrx_ops.rx.rx = hdd_softap_rx_packet_cbk;
		txrx_ops.rx.rx_stack = NULL;
		txrx_ops.rx.rx_flush = NULL;
	}

	cdp_vdev_register(soc,
			  adapter->vdev_id,
			  (ol_osif_vdev_handle)adapter,
			  &txrx_ops);
	adapter->tx_fn = txrx_ops.tx.tx;

	qdf_status = cdp_peer_register(soc, OL_TXRX_PDEV_ID, &txrx_desc);
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		hdd_debug("cdp_peer_register() failed to register.  Status = %d [0x%08X]",
			  qdf_status, qdf_status);
		hdd_put_sta_info_ref(&adapter->sta_info_list, &sta_info, true,
				     STA_INFO_SOFTAP_REGISTER_STA);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return qdf_status;
	}

	/* if ( WPA ), tell TL to go to 'connected' and after keys come to the
	 * driver then go to 'authenticated'.  For all other authentication
	 * types (those that do not require upper layer authentication) we can
	 * put TL directly into 'authenticated' state
	 */

<<<<<<< HEAD
	pAdapter->aStaInfo[staId].ucSTAId = staId;
	pAdapter->aStaInfo[staId].isQosEnabled = fWmmEnabled;

	if (!fAuthRequired) {
		hdd_info("open/shared auth StaId= %d.  Changing TL state to AUTHENTICATED at Join time",
			 pAdapter->aStaInfo[staId].ucSTAId);
=======
	sta_info->is_qos_enabled = wmm_enabled;

	if (!auth_required) {
		hdd_debug("open/shared auth STA MAC= " QDF_MAC_ADDR_FMT
			  ".  Changing TL state to AUTHENTICATED at Join time",
			 QDF_MAC_ADDR_REF(sta_info->sta_mac.bytes));
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

		/* Connections that do not need Upper layer auth,
		 * transition TL directly to 'Authenticated' state.
		 */
<<<<<<< HEAD
		qdf_status = hdd_change_peer_state(pAdapter, staDesc.sta_id,
						OL_TXRX_PEER_STATE_AUTH, false);

		pAdapter->aStaInfo[staId].tlSTAState = OL_TXRX_PEER_STATE_AUTH;
		pAdapter->sessionCtx.ap.uIsAuthenticated = true;
		if (!qdf_is_macaddr_broadcast(pPeerMacAddress))
			qdf_status = wlan_hdd_send_sta_authorized_event(
							   pAdapter, pHddCtx,
							   pPeerMacAddress);
	} else {

		hdd_info("ULA auth StaId= %d.  Changing TL state to CONNECTED at Join time",
			 pAdapter->aStaInfo[staId].ucSTAId);

		qdf_status = hdd_change_peer_state(pAdapter, staDesc.sta_id,
						OL_TXRX_PEER_STATE_CONN, false);
		pAdapter->aStaInfo[staId].tlSTAState = OL_TXRX_PEER_STATE_CONN;

		pAdapter->sessionCtx.ap.uIsAuthenticated = false;

	}

	/* Enable Tx queue */
	hdd_info("Enabling queues");
	wlan_hdd_netif_queue_control(pAdapter,
				   WLAN_START_ALL_NETIF_QUEUE_N_CARRIER,
				   WLAN_CONTROL_PATH);

=======
		qdf_status = hdd_change_peer_state(adapter,
						   txrx_desc.peer_addr.bytes,
						   OL_TXRX_PEER_STATE_AUTH,
						   false);

		sta_info->peer_state = OL_TXRX_PEER_STATE_AUTH;
		if (!qdf_is_macaddr_broadcast(sta_mac))
			qdf_status = wlan_hdd_send_sta_authorized_event(
							adapter, hdd_ctx,
							sta_mac);
	} else {

		hdd_debug("ULA auth STA MAC = " QDF_MAC_ADDR_FMT
			  ".  Changing TL state to CONNECTED at Join time",
			 QDF_MAC_ADDR_REF(sta_info->sta_mac.bytes));

		qdf_status = hdd_change_peer_state(adapter,
						   txrx_desc.peer_addr.bytes,
						   OL_TXRX_PEER_STATE_CONN,
						   false);

		sta_info->peer_state = OL_TXRX_PEER_STATE_CONN;
	}

	hdd_put_sta_info_ref(&adapter->sta_info_list, &sta_info, true,
			     STA_INFO_SOFTAP_REGISTER_STA);
	hdd_debug("Enabling queues");
	wlan_hdd_netif_queue_control(adapter,
				   WLAN_START_ALL_NETIF_QUEUE_N_CARRIER,
				   WLAN_CONTROL_PATH);
	ucfg_mlme_update_oce_flags(hdd_ctx->pdev);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	return qdf_status;
}

/**
 * hdd_softap_register_bc_sta() - Register the SoftAP broadcast STA
<<<<<<< HEAD
 * @pAdapter: pointer to adapter context
 * @fPrivacyBit: should 802.11 privacy bit be set?
 *
 * Return: QDF_STATUS_SUCCESS on success, QDF_STATUS_E_** on error
 */
QDF_STATUS hdd_softap_register_bc_sta(hdd_adapter_t *pAdapter,
				      bool fPrivacyBit)
{
	QDF_STATUS qdf_status = QDF_STATUS_E_FAILURE;
	hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
	struct qdf_mac_addr broadcastMacAddr =
					QDF_MAC_ADDR_BROADCAST_INITIALIZER;
	hdd_ap_ctx_t *pHddApCtx;

	pHddApCtx = WLAN_HDD_GET_AP_CTX_PTR(pAdapter);

	pHddCtx->sta_to_adapter[WLAN_RX_BCMC_STA_ID] = pAdapter;
	pHddCtx->sta_to_adapter[pHddApCtx->uBCStaId] = pAdapter;
	qdf_status =
		hdd_softap_register_sta(pAdapter, false, fPrivacyBit,
					(WLAN_HDD_GET_AP_CTX_PTR(pAdapter))->
					uBCStaId, 0, 1, &broadcastMacAddr, 0);
=======
 * @adapter: pointer to adapter context
 * @privacy_required: should 802.11 privacy bit be set?
 *
 * Return: QDF_STATUS_SUCCESS on success, QDF_STATUS_E_** on error
 */
QDF_STATUS hdd_softap_register_bc_sta(struct hdd_adapter *adapter,
				      bool privacy_required)
{
	QDF_STATUS qdf_status = QDF_STATUS_E_FAILURE;
	struct qdf_mac_addr broadcast_macaddr = QDF_MAC_ADDR_BCAST_INIT;
	struct hdd_ap_ctx *ap_ctx;
	uint8_t sta_id;
	ap_ctx = WLAN_HDD_GET_AP_CTX_PTR(adapter);
	sta_id = ap_ctx->broadcast_sta_id;

	if (sta_id >= WLAN_MAX_STA_COUNT) {
		hdd_err("Error: Invalid sta_id: %u", sta_id);
		return qdf_status;
	}

	qdf_status = hdd_softap_register_sta(adapter, false,
					     privacy_required,
					     &broadcast_macaddr, 0);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	return qdf_status;
}

<<<<<<< HEAD
/**
 * hdd_softap_deregister_bc_sta() - Deregister the SoftAP broadcast STA
 * @pAdapter: pointer to adapter context
 *
 * Return: QDF_STATUS_SUCCESS on success, QDF_STATUS_E_** on error
 */
QDF_STATUS hdd_softap_deregister_bc_sta(hdd_adapter_t *pAdapter)
{
	return hdd_softap_deregister_sta(pAdapter,
					 (WLAN_HDD_GET_AP_CTX_PTR(pAdapter))->
					 uBCStaId);
}

/**
 * hdd_softap_stop_bss() - Stop the BSS
 * @pAdapter: pointer to adapter context
 *
 * Return: QDF_STATUS_SUCCESS on success, QDF_STATUS_E_** on error
 */
QDF_STATUS hdd_softap_stop_bss(hdd_adapter_t *pAdapter)
{
	QDF_STATUS qdf_status = QDF_STATUS_E_FAILURE;
	uint8_t staId = 0;
	hdd_context_t *pHddCtx;

	pHddCtx = WLAN_HDD_GET_CTX(pAdapter);

	/* bss deregister is not allowed during wlan driver loading or
	 * unloading
	 */
	if (cds_is_load_or_unload_in_progress()) {
		hdd_warn("Loading_unloading in Progress, state: 0x%x. Ignore!!!",
			cds_get_driver_state());
		return QDF_STATUS_E_PERM;
	}

	qdf_status = hdd_softap_deregister_bc_sta(pAdapter);

	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		hdd_err("Failed to deregister BC sta Id %d",
			(WLAN_HDD_GET_AP_CTX_PTR(pAdapter))->uBCStaId);
	}

	for (staId = 0; staId < WLAN_MAX_STA_COUNT; staId++) {
		/* This excludes BC sta as it is already deregistered */
		if (pAdapter->aStaInfo[staId].isUsed) {
			qdf_status = hdd_softap_deregister_sta(pAdapter, staId);
			if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
				hdd_err("Failed to deregister sta Id %d",
					staId);
			}
		}
	}
	if (pAdapter->device_mode == QDF_SAP_MODE &&
	    !pHddCtx->config->disable_channel)
		wlan_hdd_restore_channels(pHddCtx);

	/* Mark the indoor channel (passive) to enable */
	if (pHddCtx->config->disable_indoor_channel &&
			pAdapter->device_mode == QDF_SAP_MODE) {
		hdd_update_indoor_channel(pHddCtx, false);
		sme_update_channel_list(pHddCtx->hHal);
	}

	if (hdd_ipa_is_enabled(pHddCtx)) {
		if (hdd_ipa_wlan_evt(pAdapter,
				WLAN_HDD_GET_AP_CTX_PTR(pAdapter)->uBCStaId,
				HDD_IPA_AP_DISCONNECT,
				pAdapter->dev->dev_addr))
			hdd_err("WLAN_AP_DISCONNECT event failed");
	}

	return qdf_status;
}

/**
 * hdd_softap_change_sta_state() - Change the state of a SoftAP station
 * @pAdapter: pointer to adapter context
 * @pDestMacAddress: MAC address of the station
 * @state: new state of the station
 *
 * Return: QDF_STATUS_SUCCESS on success, QDF_STATUS_E_** on error
 */
QDF_STATUS hdd_softap_change_sta_state(hdd_adapter_t *pAdapter,
				       struct qdf_mac_addr *pDestMacAddress,
				       enum ol_txrx_peer_state state)
{
	uint8_t ucSTAId = WLAN_MAX_STA_COUNT;
	QDF_STATUS qdf_status;

	ENTER_DEV(pAdapter->dev);

	qdf_status = hdd_softap_get_sta_id(pAdapter, pDestMacAddress, &ucSTAId);
	if (QDF_STATUS_SUCCESS != qdf_status) {
		hdd_err("Failed to find right station");
		return qdf_status;
	}

	if (false ==
	    qdf_is_macaddr_equal(&pAdapter->aStaInfo[ucSTAId].macAddrSTA,
				 pDestMacAddress)) {
		hdd_err("Station %u MAC address not matching", ucSTAId);
		return QDF_STATUS_E_FAILURE;
	}

	qdf_status =
		hdd_change_peer_state(pAdapter, ucSTAId, state, false);
	hdd_info("Station %u changed to state %d", ucSTAId, state);

	if (QDF_STATUS_SUCCESS == qdf_status) {
		pAdapter->aStaInfo[ucSTAId].tlSTAState =
			OL_TXRX_PEER_STATE_AUTH;
	}

	EXIT();
	return qdf_status;
}

/*
 * hdd_softap_get_sta_id() - Find station ID from MAC address
 * @pAdapter: pointer to adapter context
 * @pDestMacAddress: MAC address of the destination
 * @staId: Station ID associated with the MAC address
 *
 * Return: QDF_STATUS_SUCCESS if a match was found, in which case
 *	   staId is populated, QDF_STATUS_E_FAILURE if a match is
 *	   not found
 */
QDF_STATUS hdd_softap_get_sta_id(hdd_adapter_t *pAdapter,
				 struct qdf_mac_addr *pMacAddress,
				 uint8_t *staId)
{
	uint8_t i;

	for (i = 0; i < WLAN_MAX_STA_COUNT; i++) {
		if (!qdf_mem_cmp
			(&pAdapter->aStaInfo[i].macAddrSTA, pMacAddress,
			QDF_MAC_ADDR_SIZE) && pAdapter->aStaInfo[i].isUsed) {
			*staId = i;
			return QDF_STATUS_SUCCESS;
		}
	}

	return QDF_STATUS_E_FAILURE;
}
=======
QDF_STATUS hdd_softap_stop_bss(struct hdd_adapter *adapter)
{
	QDF_STATUS status = QDF_STATUS_E_FAILURE;
	uint8_t indoor_chnl_marking = 0;
	struct hdd_context *hdd_ctx;
	struct hdd_ap_ctx *ap_ctx;
	struct hdd_station_info *sta_info, *tmp = NULL;

	hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	ap_ctx = WLAN_HDD_GET_AP_CTX_PTR(adapter);

	status = ucfg_policy_mgr_get_indoor_chnl_marking(hdd_ctx->psoc,
							 &indoor_chnl_marking);
	if (QDF_STATUS_SUCCESS != status)
		hdd_err("can't get indoor channel marking, using default");
	/* This is stop bss callback running in scheduler thread so do not
	 * driver unload in progress check otherwise it can lead to peer
	 * object leak
	 */

	hdd_for_each_sta_ref_safe(adapter->sta_info_list, sta_info, tmp,
				  STA_INFO_SOFTAP_STOP_BSS) {
		status = hdd_softap_deregister_sta(adapter, &sta_info);
		hdd_put_sta_info_ref(&adapter->sta_info_list, &sta_info, true,
				     STA_INFO_SOFTAP_STOP_BSS);
	}

	if (adapter->device_mode == QDF_SAP_MODE &&
	    !hdd_ctx->config->disable_channel)
		wlan_hdd_restore_channels(hdd_ctx);

	/*  Mark the indoor channel (passive) to enable  */
	if (indoor_chnl_marking && adapter->device_mode == QDF_SAP_MODE) {
		hdd_update_indoor_channel(hdd_ctx, false);
		sme_update_channel_list(hdd_ctx->mac_handle);
	}

	if (ucfg_ipa_is_enabled()) {
		if (ucfg_ipa_wlan_evt(hdd_ctx->pdev,
				      adapter->dev,
				      adapter->device_mode,
				      adapter->vdev_id,
				      WLAN_IPA_AP_DISCONNECT,
				      adapter->dev->dev_addr) !=
		    QDF_STATUS_SUCCESS)
			hdd_err("WLAN_AP_DISCONNECT event failed");
	}

	return status;
}

QDF_STATUS hdd_softap_change_sta_state(struct hdd_adapter *adapter,
				       struct qdf_mac_addr *sta_mac,
				       enum ol_txrx_peer_state state)
{
	QDF_STATUS qdf_status;
	struct hdd_station_info *sta_info;
	struct qdf_mac_addr mac_addr;

	hdd_enter_dev(adapter->dev);

	sta_info = hdd_get_sta_info_by_mac(&adapter->sta_info_list,
					   sta_mac->bytes,
					   STA_INFO_SOFTAP_CHANGE_STA_STATE);

	if (!sta_info) {
		hdd_debug("Failed to find right station MAC: " QDF_MAC_ADDR_FMT,
			  QDF_MAC_ADDR_REF(sta_mac->bytes));
		return QDF_STATUS_E_INVAL;
	}

	if (qdf_is_macaddr_broadcast(&sta_info->sta_mac))
		qdf_mem_copy(&mac_addr, &adapter->mac_addr, QDF_MAC_ADDR_SIZE);
	else
		qdf_mem_copy(&mac_addr, sta_mac, QDF_MAC_ADDR_SIZE);

	qdf_status =
		hdd_change_peer_state(adapter, mac_addr.bytes,
				      state, false);
	hdd_debug("Station " QDF_MAC_ADDR_FMT " changed to state %d",
		  QDF_MAC_ADDR_REF(mac_addr.bytes), state);

	if (QDF_STATUS_SUCCESS == qdf_status) {
		sta_info->peer_state = OL_TXRX_PEER_STATE_AUTH;
		p2p_peer_authorized(adapter->vdev, sta_mac->bytes);
	}

	hdd_put_sta_info_ref(&adapter->sta_info_list, &sta_info, true,
			     STA_INFO_SOFTAP_CHANGE_STA_STATE);
	hdd_exit();
	return qdf_status;
}

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

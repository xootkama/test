/*
<<<<<<< HEAD
 * Copyright (c) 2012-2019 The Linux Foundation. All rights reserved.
=======
 * Copyright (c) 2012-2021 The Linux Foundation. All rights reserved.
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

/**
 * DOC: cds_api.c
 *
 * Connectivity driver services APIs
 */

<<<<<<< HEAD
#include <cds_mq.h>
#include "cds_sched.h"
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#include <cds_api.h>
#include "sir_types.h"
#include "sir_api.h"
#include "sir_mac_prot_def.h"
#include "sme_api.h"
#include "mac_init_api.h"
#include "wlan_qct_sys.h"
#include "i_cds_packet.h"
#include "cds_reg_service.h"
#include "wma_types.h"
#include "wlan_hdd_main.h"
<<<<<<< HEAD
#include "wlan_hdd_tsf.h"
#include <linux/vmalloc.h>

#include "pld_common.h"
#include "sap_api.h"
#include "qdf_trace.h"
=======
#include "wlan_hdd_power.h"
#include "wlan_hdd_tsf.h"
#include <linux/vmalloc.h>
#include <scheduler_core.h>

#include "pld_common.h"
#include "sap_api.h"
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#include "bmi.h"
#include "ol_fw.h"
#include "ol_if_athvar.h"
#include "hif.h"
<<<<<<< HEAD
#include "cds_concurrency.h"
#include "cds_utils.h"
#include "wlan_logging_sock_svc.h"
#include "wma.h"
#include "ol_txrx.h"
#include "pktlog_ac.h"
#include "wlan_hdd_ipa.h"
#include "qdf_cpuhp.h"

=======
#include "wlan_policy_mgr_api.h"
#include "cds_utils.h"
#include "wlan_logging_sock_svc.h"
#include "wma.h"
#include "pktlog_ac.h"
#include "wlan_policy_mgr_api.h"

#include <cdp_txrx_cmn_reg.h>
#include <cdp_txrx_cfg.h>
#include <cdp_txrx_misc.h>
#include <ol_defines.h>
#include <dispatcher_init_deinit.h>
#include <cdp_txrx_handle.h>
#include <cdp_txrx_host_stats.h>
#include "target_type.h"
#include "wlan_ocb_ucfg_api.h"
#include "wlan_ipa_ucfg_api.h"
#include "dp_txrx.h"
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#ifdef ENABLE_SMMU_S1_TRANSLATION
#include "pld_common.h"
#include <asm/dma-iommu.h>
#include <linux/iommu.h>
#endif
<<<<<<< HEAD
/* Preprocessor Definitions and Constants */

/* Maximum number of cds message queue get wrapper failures to cause panic */
#define CDS_WRAPPER_MAX_FAIL_COUNT (CDS_CORE_MAX_MESSAGES * 3)

/* Data definitions */
static cds_context_type g_cds_context;
static p_cds_contextType gp_cds_context;
static struct __qdf_device g_qdf_ctx;

/* Debug variable to detect MC thread stuck */
static atomic_t cds_wrapper_empty_count;

static uint8_t cds_multicast_logging;

void cds_sys_probe_thread_cback(void *pUserData);
static void cds_trigger_recovery_work(void *param);

/**
=======

#ifdef QCA_WIFI_QCA8074
#include <target_if_dp.h>
#endif
#include "wlan_mlme_ucfg_api.h"
#include "cfg_ucfg_api.h"
#include "wlan_cp_stats_mc_ucfg_api.h"
#include <qdf_hang_event_notifier.h>
#include <qdf_notifier.h>
#include <qwlan_version.h>
#include <qdf_trace.h>

/* Preprocessor Definitions and Constants */

/* Preprocessor Definitions and Constants */

/* Data definitions */
static struct cds_context g_cds_context;
static struct cds_context *gp_cds_context;
static struct __qdf_device g_qdf_ctx;

static uint8_t cds_multicast_logging;

#define DRIVER_VER_LEN (11)
#define HANG_EVENT_VER_LEN (1)

struct cds_hang_event_fixed_param {
	uint16_t tlv_header;
	uint8_t recovery_reason;
	char driver_version[DRIVER_VER_LEN];
	char hang_event_version[HANG_EVENT_VER_LEN];
} qdf_packed;

#ifdef QCA_WIFI_QCA8074
static inline int
cds_send_delba(struct cdp_ctrl_objmgr_psoc *psoc,
	       uint8_t vdev_id, uint8_t *peer_macaddr,
	       uint8_t tid, uint8_t reason_code)
{
	return wma_dp_send_delba_ind(vdev_id, peer_macaddr, tid, reason_code);
}

static struct ol_if_ops  dp_ol_if_ops = {
	.peer_set_default_routing = target_if_peer_set_default_routing,
	.peer_rx_reorder_queue_setup = target_if_peer_rx_reorder_queue_setup,
	.peer_rx_reorder_queue_remove = target_if_peer_rx_reorder_queue_remove,
	.is_hw_dbs_2x2_capable = policy_mgr_is_dp_hw_dbs_2x2_capable,
	.lro_hash_config = target_if_lro_hash_config,
	.rx_invalid_peer = wma_rx_invalid_peer_ind,
	.is_roam_inprogress = wma_is_roam_in_progress,
	.get_con_mode = cds_get_conparam,
	.send_delba = cds_send_delba,
#ifdef DP_MEM_PRE_ALLOC
	.dp_prealloc_get_context = dp_prealloc_get_context_memory,
	.dp_prealloc_put_context = dp_prealloc_put_context_memory,
	.dp_prealloc_get_consistent = dp_prealloc_get_coherent,
	.dp_prealloc_put_consistent = dp_prealloc_put_coherent,
	.dp_get_multi_pages = dp_prealloc_get_multi_pages,
	.dp_put_multi_pages = dp_prealloc_put_multi_pages,
#endif
	.dp_rx_get_pending = dp_rx_tm_get_pending,
    /* TODO: Add any other control path calls required to OL_IF/WMA layer */
};
#else
static struct ol_if_ops  dp_ol_if_ops;
#endif

static void cds_trigger_recovery_work(void *param);

/**
 * struct cds_recovery_call_info - caller information for cds_trigger_recovery
 * @func: caller's function name
 * @line: caller's line number
 */
struct cds_recovery_call_info {
	const char *func;
	uint32_t line;
} __cds_recovery_caller;

/**
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * cds_recovery_work_init() - Initialize recovery work queue
 *
 * Return: none
 */
static QDF_STATUS cds_recovery_work_init(void)
{
	qdf_create_work(0, &gp_cds_context->cds_recovery_work,
<<<<<<< HEAD
			cds_trigger_recovery_work, NULL);
	gp_cds_context->cds_recovery_wq =
		qdf_create_workqueue("cds_recovery_workqueue");
	if (NULL == gp_cds_context->cds_recovery_wq) {
=======
			cds_trigger_recovery_work, &__cds_recovery_caller);
	gp_cds_context->cds_recovery_wq =
		qdf_create_workqueue("cds_recovery_workqueue");
	if (!gp_cds_context->cds_recovery_wq) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		cds_err("Failed to create cds_recovery_workqueue");
		return QDF_STATUS_E_FAILURE;
	}

	return QDF_STATUS_SUCCESS;
}

/**
 * cds_recovery_work_deinit() - Initialize recovery work queue
 *
 * Return: none
 */
static void cds_recovery_work_deinit(void)
{
	if (gp_cds_context->cds_recovery_wq) {
		qdf_flush_workqueue(0, gp_cds_context->cds_recovery_wq);
		qdf_destroy_workqueue(0, gp_cds_context->cds_recovery_wq);
	}
}

<<<<<<< HEAD
/**
 * cds_init() - Initialize CDS
 *
 * This function allocates the resource required for CDS, but does not
 * initialize all the members. This overall initialization will happen at
 * cds_open().
 *
 * Return: Global context on success and NULL on failure.
 */
v_CONTEXT_t cds_init(void)
{
	QDF_STATUS ret;

	ret = qdf_debugfs_init();
	if (ret != QDF_STATUS_SUCCESS)
		cds_err("Failed to init debugfs");

	qdf_lock_stats_init();
	qdf_mem_init();
	qdf_mc_timer_manager_init();
	qdf_event_list_init();
	qdf_cpuhp_init();

	gp_cds_context = &g_cds_context;

	gp_cds_context->qdf_ctx = &g_qdf_ctx;
	qdf_mem_zero(&g_qdf_ctx, sizeof(g_qdf_ctx));

	qdf_trace_spin_lock_init();

#if defined(TRACE_RECORD)
	qdf_trace_init();
#endif
	qdf_register_debugcb_init();

	cds_ssr_protect_init();

	ret = cds_recovery_work_init();
	if (ret != QDF_STATUS_SUCCESS) {
		cds_err("Failed to init recovery work");
		goto deinit;
	}

	return gp_cds_context;
deinit:
	qdf_mc_timer_manager_exit();
	qdf_mem_exit();
	qdf_lock_stats_deinit();
	qdf_debugfs_exit();
	gp_cds_context->qdf_ctx = NULL;
	gp_cds_context = NULL;
	qdf_mem_zero(&g_cds_context, sizeof(g_cds_context));

	return NULL;
=======
static bool cds_is_drv_connected(void)
{
	int ret;
	qdf_device_t qdf_ctx;

	qdf_ctx = cds_get_context(QDF_MODULE_ID_QDF_DEVICE);
	if (!qdf_ctx) {
		cds_err("cds context is invalid");
		return false;
	}

	ret = pld_is_drv_connected(qdf_ctx->dev);

	return ((ret > 0) ? true : false);
}

static bool cds_is_drv_supported(void)
{
	qdf_device_t qdf_ctx;
	struct pld_platform_cap cap = {0};

	qdf_ctx = cds_get_context(QDF_MODULE_ID_QDF_DEVICE);
	if (!qdf_ctx) {
		cds_err("cds context is invalid");
		return false;
	}

	pld_get_platform_cap(qdf_ctx->dev, &cap);

	return ((cap.cap_flag & PLD_HAS_DRV_SUPPORT) ? true : false);
}

static QDF_STATUS cds_wmi_send_recv_qmi(void *buf, uint32_t len, void * cb_ctx,
					qdf_wmi_recv_qmi_cb wmi_rx_cb)
{
	qdf_device_t qdf_ctx;

	qdf_ctx = cds_get_context(QDF_MODULE_ID_QDF_DEVICE);
	if (!qdf_ctx) {
		cds_err("cds context is invalid");
		return QDF_STATUS_E_INVAL;
	}

	if (pld_qmi_send(qdf_ctx->dev, 0, buf, len, cb_ctx, wmi_rx_cb))
		return QDF_STATUS_E_INVAL;

	return QDF_STATUS_SUCCESS;
}

/**
 * cds_update_recovery_reason() - update the recovery reason code
 * @reason: recovery reason
 *
 * Return: None
 */
static void cds_update_recovery_reason(enum qdf_hang_reason recovery_reason)
{
	if (!gp_cds_context) {
		cds_err("gp_cds_context is null");
		return;
	}

	gp_cds_context->recovery_reason = recovery_reason;
}

QDF_STATUS cds_init(void)
{
	QDF_STATUS status;

	gp_cds_context = &g_cds_context;

	status = cds_recovery_work_init();
	if (QDF_IS_STATUS_ERROR(status)) {
		cds_err("Failed to init recovery work; status:%u", status);
		goto deinit;
	}

	cds_ssr_protect_init();

	gp_cds_context->qdf_ctx = &g_qdf_ctx;

	qdf_register_self_recovery_callback(cds_trigger_recovery_psoc);
	qdf_register_fw_down_callback(cds_is_fw_down);
	qdf_register_is_driver_unloading_callback(cds_is_driver_unloading);
	qdf_register_recovering_state_query_callback(cds_is_driver_recovering);
	qdf_register_drv_connected_callback(cds_is_drv_connected);
	qdf_register_drv_supported_callback(cds_is_drv_supported);
	qdf_register_wmi_send_recv_qmi_callback(cds_wmi_send_recv_qmi);
	qdf_register_recovery_reason_update(cds_update_recovery_reason);
	qdf_register_get_bus_reg_dump(pld_get_bus_reg_dump);

	return QDF_STATUS_SUCCESS;

deinit:
	gp_cds_context = NULL;
	qdf_mem_zero(&g_cds_context, sizeof(g_cds_context));

	return status;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * cds_deinit() - Deinitialize CDS
 *
 * This function frees the CDS resources
 */
void cds_deinit(void)
{
<<<<<<< HEAD
	if (gp_cds_context == NULL)
		return;

	cds_recovery_work_deinit();
	qdf_cpuhp_deinit();
	qdf_mc_timer_manager_exit();
	qdf_mem_exit();
	qdf_lock_stats_deinit();
	qdf_debugfs_exit();
	qdf_event_list_destroy();

	gp_cds_context->qdf_ctx = NULL;
	gp_cds_context = NULL;

	qdf_mem_zero(&g_cds_context, sizeof(g_cds_context));
	return;
=======
	QDF_BUG(gp_cds_context);
	if (!gp_cds_context)
		return;

	qdf_register_get_bus_reg_dump(NULL);
	qdf_register_recovery_reason_update(NULL);
	qdf_register_recovering_state_query_callback(NULL);
	qdf_register_fw_down_callback(NULL);
	qdf_register_is_driver_unloading_callback(NULL);
	qdf_register_self_recovery_callback(NULL);
	qdf_register_wmi_send_recv_qmi_callback(NULL);

	gp_cds_context->qdf_ctx = NULL;
	qdf_mem_zero(&g_qdf_ctx, sizeof(g_qdf_ctx));

	/* currently, no ssr_protect_deinit */

	cds_recovery_work_deinit();

	gp_cds_context = NULL;
	qdf_mem_zero(&g_cds_context, sizeof(g_cds_context));
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

#ifdef FEATURE_WLAN_DIAG_SUPPORT
/**
 * cds_tdls_tx_rx_mgmt_event()- send tdls mgmt rx tx event
 * @event_id: event id
 * @tx_rx: tx or rx
 * @type: type of frame
 * @action_sub_type: action frame type
 * @peer_mac: peer mac
 *
 * This Function sends tdls mgmt rx tx diag event
 *
 * Return: void.
 */
void cds_tdls_tx_rx_mgmt_event(uint8_t event_id, uint8_t tx_rx,
		uint8_t type, uint8_t action_sub_type, uint8_t *peer_mac)
{
	WLAN_HOST_DIAG_EVENT_DEF(tdls_tx_rx_mgmt,
		struct host_event_tdls_tx_rx_mgmt);

	tdls_tx_rx_mgmt.event_id = event_id;
	tdls_tx_rx_mgmt.tx_rx = tx_rx;
	tdls_tx_rx_mgmt.type = type;
	tdls_tx_rx_mgmt.action_sub_type = action_sub_type;
	qdf_mem_copy(tdls_tx_rx_mgmt.peer_mac,
			peer_mac, CDS_MAC_ADDRESS_LEN);
	WLAN_HOST_DIAG_EVENT_REPORT(&tdls_tx_rx_mgmt,
				EVENT_WLAN_TDLS_TX_RX_MGMT);
}
#endif

/**
<<<<<<< HEAD
 * vos_set_ac_specs_params() - set ac_specs params in mac open param
 * @param: Pointer to mac open param
 * @hdd_ctx: Pointer to hdd context
 *
 * Return: none
 */
static void cds_set_ac_specs_params(struct cds_config_info *cds_cfg,
					hdd_context_t *hdd_ctx)
{
	uint8_t num_entries = 0;
	uint8_t tx_sched_wrr_param[TX_SCHED_WRR_PARAMS_NUM];
	uint8_t *tx_sched_wrr_ac;
	int i;

	if (NULL == hdd_ctx)
		return;

	if (NULL == cds_cfg)
		return;

	if (NULL == hdd_ctx->config) {
		/* Do nothing if hdd_ctx is invalid */
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			"%s: Warning: hdd_ctx->cfg_ini is NULL", __func__);
		return;
	}

	for (i = 0; i < OL_TX_NUM_WMM_AC; i++) {
		switch (i) {
		case OL_TX_WMM_AC_BE:
			tx_sched_wrr_ac = hdd_ctx->config->tx_sched_wrr_be;
			break;
		case OL_TX_WMM_AC_BK:
			tx_sched_wrr_ac = hdd_ctx->config->tx_sched_wrr_bk;
			break;
		case OL_TX_WMM_AC_VI:
			tx_sched_wrr_ac = hdd_ctx->config->tx_sched_wrr_vi;
			break;
		case OL_TX_WMM_AC_VO:
			tx_sched_wrr_ac = hdd_ctx->config->tx_sched_wrr_vo;
			break;
		default:
			tx_sched_wrr_ac = NULL;
			break;
		}

		hdd_string_to_u8_array(tx_sched_wrr_ac,
				tx_sched_wrr_param,
				&num_entries,
				sizeof(tx_sched_wrr_param));

		if (num_entries == TX_SCHED_WRR_PARAMS_NUM) {
			cds_cfg->ac_specs[i].wrr_skip_weight =
						tx_sched_wrr_param[0];
			cds_cfg->ac_specs[i].credit_threshold =
						tx_sched_wrr_param[1];
			cds_cfg->ac_specs[i].send_limit =
						tx_sched_wrr_param[2];
			cds_cfg->ac_specs[i].credit_reserve =
						tx_sched_wrr_param[3];
			cds_cfg->ac_specs[i].discard_weight =
						tx_sched_wrr_param[4];
		}

		num_entries = 0;
	}
}

=======
 * cds_cfg_update_ac_specs_params() - update ac_specs params
 * @olcfg: cfg handle
 * @mac_params: mac params
 *
 * Return: none
 */
static void
cds_cfg_update_ac_specs_params(struct txrx_pdev_cfg_param_t *olcfg,
		struct cds_config_info *cds_cfg)
{
	int i;

	if (!olcfg)
		return;

	if (!cds_cfg)
		return;

	for (i = 0; i < QCA_WLAN_AC_ALL; i++) {
		olcfg->ac_specs[i].wrr_skip_weight =
			cds_cfg->ac_specs[i].wrr_skip_weight;
		olcfg->ac_specs[i].credit_threshold =
			cds_cfg->ac_specs[i].credit_threshold;
		olcfg->ac_specs[i].send_limit =
			cds_cfg->ac_specs[i].send_limit;
		olcfg->ac_specs[i].credit_reserve =
			cds_cfg->ac_specs[i].credit_reserve;
		olcfg->ac_specs[i].discard_weight =
			cds_cfg->ac_specs[i].discard_weight;
	}
}

#if defined(QCA_LL_TX_FLOW_CONTROL_V2) || defined(QCA_LL_PDEV_TX_FLOW_CONTROL)
static inline void
cds_cdp_set_flow_control_params(struct wlan_objmgr_psoc *psoc,
				struct txrx_pdev_cfg_param_t *cdp_cfg)
{
	cdp_cfg->tx_flow_stop_queue_th =
		cfg_get(psoc, CFG_DP_TX_FLOW_STOP_QUEUE_TH);
	cdp_cfg->tx_flow_start_queue_offset =
		cfg_get(psoc, CFG_DP_TX_FLOW_START_QUEUE_OFFSET);
}
#else
static inline void
cds_cdp_set_flow_control_params(struct wlan_objmgr_psoc *psoc,
				struct txrx_pdev_cfg_param_t *cdp_cfg)
{}
#endif

#ifdef QCA_SUPPORT_TXRX_DRIVER_TCP_DEL_ACK
static inline void
cds_cdp_update_del_ack_params(struct wlan_objmgr_psoc *psoc,
			      struct txrx_pdev_cfg_param_t *cdp_cfg)
{
	cdp_cfg->del_ack_enable =
		cfg_get(psoc, CFG_DP_DRIVER_TCP_DELACK_ENABLE);
	cdp_cfg->del_ack_pkt_count =
		cfg_get(psoc, CFG_DP_DRIVER_TCP_DELACK_PKT_CNT);
	cdp_cfg->del_ack_timer_value =
		cfg_get(psoc, CFG_DP_DRIVER_TCP_DELACK_TIMER_VALUE);
}
#else
static inline void
cds_cdp_update_del_ack_params(struct wlan_objmgr_psoc *psoc,
			      struct txrx_pdev_cfg_param_t *cdp_cfg)
{}
#endif

#ifdef WLAN_SUPPORT_TXRX_HL_BUNDLE
static inline void
cds_cdp_update_bundle_params(struct wlan_objmgr_psoc *psoc,
			     struct txrx_pdev_cfg_param_t *cdp_cfg)
{
	cdp_cfg->bundle_timer_value =
		cfg_get(psoc, CFG_DP_HL_BUNDLE_TIMER_VALUE);
	cdp_cfg->bundle_size =
		cfg_get(psoc, CFG_DP_HL_BUNDLE_SIZE);
}
#else
static inline void
cds_cdp_update_bundle_params(struct wlan_objmgr_psoc *psoc,
			     struct txrx_pdev_cfg_param_t *cdp_cfg)
{
}
#endif

/**
 * cds_cdp_cfg_attach() - attach data path config module
 * @cds_cfg: generic platform level config instance
 *
 * Return: none
 */
static void cds_cdp_cfg_attach(struct wlan_objmgr_psoc *psoc)
{
	struct txrx_pdev_cfg_param_t cdp_cfg = {0};
	void *soc = cds_get_context(QDF_MODULE_ID_SOC);
	struct hdd_context *hdd_ctx = gp_cds_context->hdd_context;

	cdp_cfg.is_full_reorder_offload =
		cfg_get(psoc, CFG_DP_REORDER_OFFLOAD_SUPPORT);
	cdp_cfg.is_uc_offload_enabled = ucfg_ipa_uc_is_enabled();
	cdp_cfg.uc_tx_buffer_count = cfg_get(psoc, CFG_DP_IPA_UC_TX_BUF_COUNT);
	cdp_cfg.uc_tx_buffer_size =
			cfg_get(psoc, CFG_DP_IPA_UC_TX_BUF_SIZE);
	cdp_cfg.uc_rx_indication_ring_count =
		cfg_get(psoc, CFG_DP_IPA_UC_RX_IND_RING_COUNT);
	cdp_cfg.uc_tx_partition_base =
		cfg_get(psoc, CFG_DP_IPA_UC_TX_PARTITION_BASE);
	cdp_cfg.enable_rxthread = hdd_ctx->enable_rxthread;
	cdp_cfg.ip_tcp_udp_checksum_offload =
		cfg_get(psoc, CFG_DP_TCP_UDP_CKSUM_OFFLOAD);
	cdp_cfg.nan_ip_tcp_udp_checksum_offload =
		cfg_get(psoc, CFG_DP_NAN_TCP_UDP_CKSUM_OFFLOAD);
	cdp_cfg.p2p_ip_tcp_udp_checksum_offload =
		cfg_get(psoc, CFG_DP_P2P_TCP_UDP_CKSUM_OFFLOAD);
	cdp_cfg.legacy_mode_csum_disable =
		cfg_get(psoc, CFG_DP_LEGACY_MODE_CSUM_DISABLE);
	cdp_cfg.ce_classify_enabled =
		cfg_get(psoc, CFG_DP_CE_CLASSIFY_ENABLE);
	cdp_cfg.tso_enable = cfg_get(psoc, CFG_DP_TSO);
	cdp_cfg.lro_enable = cfg_get(psoc, CFG_DP_LRO);
	cdp_cfg.enable_data_stall_detection =
		cfg_get(psoc, CFG_DP_ENABLE_DATA_STALL_DETECTION);
	cdp_cfg.gro_enable = cfg_get(psoc, CFG_DP_GRO);
	cdp_cfg.enable_flow_steering =
		cfg_get(psoc, CFG_DP_FLOW_STEERING_ENABLED);
	cdp_cfg.disable_intra_bss_fwd =
		cfg_get(psoc, CFG_DP_AP_STA_SECURITY_SEPERATION);
	cdp_cfg.pktlog_buffer_size =
		cfg_get(psoc, CFG_DP_PKTLOG_BUFFER_SIZE);

	cds_cdp_update_del_ack_params(psoc, &cdp_cfg);

	cds_cdp_update_bundle_params(psoc, &cdp_cfg);

	gp_cds_context->cfg_ctx = cdp_cfg_attach(soc, gp_cds_context->qdf_ctx,
					(void *)(&cdp_cfg));
	if (!gp_cds_context->cfg_ctx) {
		WMA_LOGD("%s: failed to init cfg handle", __func__);
		return;
	}

	/* Configure Receive flow steering */
	cdp_cfg_set_flow_steering(soc, gp_cds_context->cfg_ctx,
				  cfg_get(psoc, CFG_DP_FLOW_STEERING_ENABLED));

	cds_cdp_set_flow_control_params(psoc, &cdp_cfg);
	cdp_cfg_set_flow_control_parameters(soc, gp_cds_context->cfg_ctx,
					    (void *)&cdp_cfg);

	/* adjust the cfg_ctx default value based on setting */
	cdp_cfg_set_rx_fwd_disabled(soc, gp_cds_context->cfg_ctx,
				    cfg_get(psoc,
					    CFG_DP_AP_STA_SECURITY_SEPERATION));

	/*
	 * adjust the packet log enable default value
	 * based on CFG INI setting
	 */
	cdp_cfg_set_packet_log_enabled(soc, gp_cds_context->cfg_ctx,
		(uint8_t)cds_is_packet_log_enabled());

	/* adjust the ptp rx option default value based on CFG INI setting */
	cdp_cfg_set_ptp_rx_opt_enabled(soc, gp_cds_context->cfg_ctx,
				       (uint8_t)cds_is_ptp_rx_opt_enabled());
}
static QDF_STATUS cds_register_all_modules(void)
{
	QDF_STATUS status;

	scheduler_register_wma_legacy_handler(&wma_mc_process_handler);
	scheduler_register_sys_legacy_handler(&sys_mc_process_handler);

	/* Register message queues in given order such that queue priority is
	 * intact:
	 * 1) QDF_MODULE_ID_SYS: Timer queue(legacy SYS queue)
	 * 2) QDF_MODULE_ID_TARGET_IF: Target interface queue
	 * 3) QDF_MODULE_ID_PE: Legacy PE message queue
	 * 4) QDF_MODULE_ID_SME: Legacy SME message queue
	 * 5) QDF_MODULE_ID_OS_IF: OS IF message queue for new components
	 */
	status = scheduler_register_module(QDF_MODULE_ID_SYS,
					&scheduler_timer_q_mq_handler);
	status = scheduler_register_module(QDF_MODULE_ID_TARGET_IF,
					&scheduler_target_if_mq_handler);
	status = scheduler_register_module(QDF_MODULE_ID_PE,
					&pe_mc_process_handler);
	status = scheduler_register_module(QDF_MODULE_ID_SME,
					&sme_mc_process_handler);
	status = scheduler_register_module(QDF_MODULE_ID_OS_IF,
					&scheduler_os_if_mq_handler);
	status = scheduler_register_module(QDF_MODULE_ID_SCAN,
					&scheduler_scan_mq_handler);
	return status;
}

static QDF_STATUS cds_deregister_all_modules(void)
{
	QDF_STATUS status;

	scheduler_deregister_wma_legacy_handler();
	scheduler_deregister_sys_legacy_handler();
	status = scheduler_deregister_module(QDF_MODULE_ID_SCAN);
	status = scheduler_deregister_module(QDF_MODULE_ID_SYS);
	status = scheduler_deregister_module(QDF_MODULE_ID_TARGET_IF);
	status = scheduler_deregister_module(QDF_MODULE_ID_PE);
	status = scheduler_deregister_module(QDF_MODULE_ID_SME);
	status = scheduler_deregister_module(QDF_MODULE_ID_OS_IF);

	return status;
}

/**
 * cds_set_ac_specs_params() - set ac_specs params in cds_config_info
 * @cds_cfg: Pointer to cds_config_info
 * @hdd_ctx: Pointer to hdd context
 *
 * Return: none
 */
static void
cds_set_ac_specs_params(struct cds_config_info *cds_cfg)
{
	int i;
	struct cds_context *cds_ctx;

	if (!cds_cfg)
		return;

	cds_ctx = cds_get_context(QDF_MODULE_ID_QDF);

	if (!cds_ctx) {
		cds_err("Invalid CDS Context");
		return;
	}

	for (i = 0; i < QCA_WLAN_AC_ALL; i++) {
		cds_cfg->ac_specs[i] = cds_ctx->ac_specs[i];
	}
}

static int cds_hang_event_notifier_call(struct notifier_block *block,
					unsigned long state,
					void *data)
{
	struct qdf_notifer_data *cds_hang_data = data;
	uint32_t total_len;
	struct cds_hang_event_fixed_param *cmd;
	uint8_t *cds_hang_evt_buff;

	if (!cds_hang_data)
		return NOTIFY_STOP_MASK;

	cds_hang_evt_buff = cds_hang_data->hang_data;

	if (!cds_hang_evt_buff)
		return NOTIFY_STOP_MASK;

	total_len = sizeof(*cmd);
	if (cds_hang_data->offset + total_len > QDF_WLAN_HANG_FW_OFFSET)
		return NOTIFY_STOP_MASK;

	cds_hang_evt_buff = cds_hang_data->hang_data + cds_hang_data->offset;
	cmd = (struct cds_hang_event_fixed_param *)cds_hang_evt_buff;
	QDF_HANG_EVT_SET_HDR(&cmd->tlv_header, HANG_EVT_TAG_CDS,
			     QDF_HANG_GET_STRUCT_TLVLEN(*cmd));

	cmd->recovery_reason = gp_cds_context->recovery_reason;

	qdf_mem_copy(&cmd->driver_version, QWLAN_VERSIONSTR,
		     DRIVER_VER_LEN);

	qdf_mem_copy(&cmd->hang_event_version, QDF_HANG_EVENT_VERSION,
		     HANG_EVENT_VER_LEN);

	cds_hang_data->offset += total_len;
	return NOTIFY_OK;
}

static qdf_notif_block cds_hang_event_notifier = {
	.notif_block.notifier_call = cds_hang_event_notifier_call,
};

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/**
 * cds_open() - open the CDS Module
 *
 * cds_open() function opens the CDS Scheduler
 * Upon successful initialization:
 * - All CDS submodules should have been initialized
 *
 * - The CDS scheduler should have opened
 *
 * - All the WLAN SW components should have been opened. This includes
 * SYS, MAC, SME, WMA and TL.
 *
 * Return: QDF status
 */
<<<<<<< HEAD
QDF_STATUS cds_open(void)
{
	QDF_STATUS status;
	int iter = 0;
	tSirRetStatus sirStatus = eSIR_SUCCESS;
=======
QDF_STATUS cds_open(struct wlan_objmgr_psoc *psoc)
{
	QDF_STATUS status;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	struct cds_config_info *cds_cfg;
	qdf_device_t qdf_ctx;
	struct htc_init_info htcInfo;
	struct ol_context *ol_ctx;
	struct hif_opaque_softc *scn;
	void *HTCHandle;
<<<<<<< HEAD
	hdd_context_t *pHddCtx;
	cds_context_type *cds_ctx;

	QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_INFO_HIGH,
		  "%s: Opening CDS", __func__);

	cds_ctx = cds_get_context(QDF_MODULE_ID_QDF);
	if (!cds_ctx) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_FATAL,
			  "%s: Trying to open CDS without a PreOpen", __func__);
		QDF_ASSERT(0);
=======
	struct hdd_context *hdd_ctx;
	struct cds_context *cds_ctx;
	mac_handle_t mac_handle;

	cds_debug("Opening CDS");

	cds_ctx = cds_get_context(QDF_MODULE_ID_QDF);
	if (!cds_ctx) {
		cds_alert("Trying to open CDS without a PreOpen");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return QDF_STATUS_E_FAILURE;
	}

	/* Initialize the timer module */
	qdf_timer_module_init();

	/* Initialize bug reporting structure */
	cds_init_log_completion();

<<<<<<< HEAD
	/* Initialize the probe event */
	status = qdf_event_create(&gp_cds_context->ProbeEvent);
	if (QDF_IS_STATUS_ERROR(status)) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_FATAL,
			  "%s: Unable to init probeEvent", __func__);
		QDF_ASSERT(0);
		return status;
	}

	status = qdf_event_create(&gp_cds_context->wmaCompleteEvent);
	if (QDF_IS_STATUS_ERROR(status)) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_FATAL,
			  "%s: Unable to init wmaCompleteEvent", __func__);
		QDF_ASSERT(0);
		goto err_probe_event;
	}

	/* Initialize the free message queue */
	status = cds_mq_init(&gp_cds_context->freeVosMq);
	if (QDF_IS_STATUS_ERROR(status)) {
		/* Critical Error ...  Cannot proceed further */
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_FATAL,
			  "%s: Failed to initialize CDS free message queue",
			  __func__);
		QDF_ASSERT(0);
		goto err_wma_complete_event;
	}

	for (iter = 0; iter < CDS_CORE_MAX_MESSAGES; iter++) {
		(gp_cds_context->aMsgWrappers[iter]).pVosMsg =
			&(gp_cds_context->aMsgBuffers[iter]);
		INIT_LIST_HEAD(&gp_cds_context->aMsgWrappers[iter].msgNode);
		cds_mq_put(&gp_cds_context->freeVosMq,
			   &(gp_cds_context->aMsgWrappers[iter]));
	}

	pHddCtx = (hdd_context_t *) (gp_cds_context->pHDDContext);
	if (!pHddCtx || !pHddCtx->config) {
		/* Critical Error ...  Cannot proceed further */
		cds_err("Hdd Context is Null");
		QDF_ASSERT(0);

		status = QDF_STATUS_E_FAILURE;
		goto err_msg_queue;
	}

	status = qdf_mutex_create(&cds_ctx->qdf_conc_list_lock);
	if (QDF_IS_STATUS_ERROR(status)) {
		cds_err("Failed to init qdf_conc_list_lock");
		QDF_ASSERT(0);
		goto err_msg_queue;
=======
	status = qdf_event_create(&gp_cds_context->wma_complete_event);
	if (QDF_IS_STATUS_ERROR(status)) {
		cds_alert("Unable to init wma_complete_event");
		return status;
	}

	hdd_ctx = gp_cds_context->hdd_context;
	if (!hdd_ctx || !hdd_ctx->config) {
		cds_err("Hdd Context is Null");

		status = QDF_STATUS_E_FAILURE;
		goto err_wma_complete_event;
	}

	status = dispatcher_enable();
	if (QDF_IS_STATUS_ERROR(status)) {
		cds_err("Failed to enable dispatcher; status:%d", status);
		goto err_wma_complete_event;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	}

	/* Now Open the CDS Scheduler */
	status = cds_sched_open(gp_cds_context,
				&gp_cds_context->qdf_sched,
				sizeof(cds_sched_context));
	if (QDF_IS_STATUS_ERROR(status)) {
<<<<<<< HEAD
		/* Critical Error ...  Cannot proceed further */
		cds_alert("Failed to open CDS Scheduler");
		QDF_ASSERT(0);
		goto err_concurrency_lock;
=======
		cds_alert("Failed to open CDS Scheduler");
		goto err_dispatcher_disable;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	}

	scn = cds_get_context(QDF_MODULE_ID_HIF);
	if (!scn) {
<<<<<<< HEAD
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_FATAL,
			  "%s: scn is null!", __func__);
=======
		cds_alert("scn is null!");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

		status = QDF_STATUS_E_FAILURE;
		goto err_sched_close;
	}

	cds_cfg = cds_get_ini_config();
	if (!cds_cfg) {
		cds_err("Cds config is NULL");
<<<<<<< HEAD
		QDF_ASSERT(0);
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

		status = QDF_STATUS_E_FAILURE;
		goto err_sched_close;
	}

<<<<<<< HEAD
	hdd_enable_fastpath(pHddCtx->config, scn);

	/* Initialize BMI and Download firmware */
	ol_ctx = cds_get_context(QDF_MODULE_ID_BMI);
	/* Initialize BMI and Download firmware */
	status = bmi_download_firmware(ol_ctx);
	if (status != QDF_STATUS_SUCCESS) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_FATAL,
			  "BMI FIALED status:%d", status);
		goto err_bmi_close;
	}

	hdd_wlan_update_target_info(pHddCtx, scn);

	htcInfo.pContext = ol_ctx;
	htcInfo.TargetFailure = ol_target_failure;
	htcInfo.TargetSendSuspendComplete = wma_target_suspend_acknowledge;
	htcInfo.target_initial_wakeup_cb = wma_handle_initial_wake_up;
=======
	hdd_enable_fastpath(hdd_ctx, scn);

	/* Initialize BMI and Download firmware */
	ol_ctx = cds_get_context(QDF_MODULE_ID_BMI);
	status = bmi_download_firmware(ol_ctx);
	if (QDF_IS_STATUS_ERROR(status)) {
		cds_alert("BMI FIALED status:%d", status);
		goto err_bmi_close;
	}

	hdd_wlan_update_target_info(hdd_ctx, scn);

	htcInfo.pContext = ol_ctx;
	htcInfo.TargetFailure = ol_target_failure;
	htcInfo.TargetSendSuspendComplete =
		ucfg_pmo_psoc_target_suspend_acknowledge;
	htcInfo.target_initial_wakeup_cb = ucfg_pmo_psoc_handle_initial_wake_up;
	htcInfo.target_psoc = (void *)psoc;
	htcInfo.cfg_wmi_credit_cnt = hdd_ctx->config->cfg_wmi_credit_cnt;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	qdf_ctx = cds_get_context(QDF_MODULE_ID_QDF_DEVICE);

	/* Create HTC */
	gp_cds_context->htc_ctx =
		htc_create(scn, &htcInfo, qdf_ctx, cds_get_conparam());
	if (!gp_cds_context->htc_ctx) {
<<<<<<< HEAD
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_FATAL,
			  "%s: Failed to Create HTC", __func__);
=======
		cds_alert("Failed to Create HTC");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

		status = QDF_STATUS_E_FAILURE;
		goto err_bmi_close;
	}
<<<<<<< HEAD

	status = bmi_done(ol_ctx);
	if (QDF_IS_STATUS_ERROR(status)) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_FATAL,
			  "%s: Failed to complete BMI phase", __func__);
		goto err_htc_close;
	}

	cds_set_ac_specs_params(cds_cfg, pHddCtx);

	/*Open the WMA module */
	status = wma_open(gp_cds_context,
			  hdd_update_tgt_cfg,
			  hdd_dfs_indicate_radar, cds_cfg);
	if (QDF_IS_STATUS_ERROR(status)) {
		/* Critical Error ...  Cannot proceed further */
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_FATAL,
			  "%s: Failed to open WMA module", __func__);
		QDF_ASSERT(0);
=======
	ucfg_pmo_psoc_update_htc_handle(psoc, (void *)gp_cds_context->htc_ctx);

	status = bmi_done(ol_ctx);
	if (QDF_IS_STATUS_ERROR(status)) {
		cds_alert("Failed to complete BMI phase");
		goto err_htc_close;
	}

	/*Open the WMA module */
	status = wma_open(psoc, hdd_update_tgt_cfg, cds_cfg,
			  hdd_ctx->target_type);
	if (QDF_IS_STATUS_ERROR(status)) {
		cds_alert("Failed to open WMA module");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		goto err_htc_close;
	}

	/* Number of peers limit differs in each chip version. If peer max
	 * limit configured in ini exceeds more than supported, WMA adjusts
	 * and keeps correct limit in cds_cfg.max_station. So, make sure
<<<<<<< HEAD
	 * config entry pHddCtx->config->maxNumberOfPeers has adjusted value
=======
	 * config entry hdd_ctx->config->maxNumberOfPeers has adjusted value
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	 */
	/* In FTM mode cds_cfg->max_stations will be zero. On updating same
	 * into hdd context config entry, leads to pe_open() to fail, if
	 * con_mode change happens from FTM mode to any other mode.
	 */
	if (QDF_DRIVER_TYPE_PRODUCTION == cds_cfg->driver_type)
<<<<<<< HEAD
		pHddCtx->config->maxNumberOfPeers = cds_cfg->max_station;

	HTCHandle = cds_get_context(QDF_MODULE_ID_HTC);
	if (!HTCHandle) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_FATAL,
			  "%s: HTCHandle is null!", __func__);
=======
		ucfg_mlme_set_sap_max_peers(psoc, cds_cfg->max_station);

	HTCHandle = cds_get_context(QDF_MODULE_ID_HTC);
	gp_cds_context->cfg_ctx = NULL;
	if (!HTCHandle) {
		cds_alert("HTCHandle is null!");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

		status = QDF_STATUS_E_FAILURE;
		goto err_wma_close;
	}

	status = htc_wait_target(HTCHandle);
	if (QDF_IS_STATUS_ERROR(status)) {
		cds_alert("Failed to complete BMI phase. status: %d", status);
<<<<<<< HEAD

		if (status != QDF_STATUS_E_NOMEM && !cds_is_fw_down())
			QDF_BUG(0);

		goto err_wma_close;
	}
	bmi_target_ready(scn, gp_cds_context->cfg_ctx);

	/* Now proceed to open the MAC */
	sirStatus =
		mac_open(&(gp_cds_context->pMACContext),
			gp_cds_context->pHDDContext, cds_cfg);

	if (eSIR_SUCCESS != sirStatus) {
		/* Critical Error ...  Cannot proceed further */
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_FATAL,
			  "%s: Failed to open MAC", __func__);
		QDF_ASSERT(0);

		status = QDF_STATUS_E_FAILURE;
		goto err_wma_close;
	}

	/* Now proceed to open the SME */
	status = sme_open(gp_cds_context->pMACContext);
	if (QDF_IS_STATUS_ERROR(status)) {
		/* Critical Error ...  Cannot proceed further */
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_FATAL,
			  "%s: Failed to open SME", __func__);
		QDF_ASSERT(0);
		goto err_mac_close;
	}

	gp_cds_context->pdev_txrx_ctx =
		ol_txrx_pdev_attach(gp_cds_context->cfg_ctx,
				    gp_cds_context->htc_ctx,
				    gp_cds_context->qdf_ctx);
	if (!gp_cds_context->pdev_txrx_ctx) {
		/* Critical Error ...  Cannot proceed further */
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_FATAL,
			  "%s: Failed to open TXRX", __func__);
		QDF_ASSERT(0);

		status = QDF_STATUS_E_FAILURE;
		goto err_sme_close;
	}

	QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_INFO_HIGH,
		  "%s: CDS successfully Opened", __func__);

	return QDF_STATUS_SUCCESS;

err_sme_close:
	sme_close(gp_cds_context->pMACContext);

err_mac_close:
	mac_close(gp_cds_context->pMACContext);

err_wma_close:
	cds_shutdown_notifier_purge();
	wma_close(gp_cds_context);

	wma_wmi_service_close(gp_cds_context);
=======
		QDF_BUG(status == QDF_STATUS_E_NOMEM || cds_is_fw_down());

		goto err_wma_close;
	}

	cds_debug("target_type %d 8074:%d 6290:%d 6390: %d 6490: %d 6750: %d",
		  hdd_ctx->target_type,
		  TARGET_TYPE_QCA8074,
		  TARGET_TYPE_QCA6290,
		  TARGET_TYPE_QCA6390,
		  TARGET_TYPE_QCA6490,
		  TARGET_TYPE_QCA6750);

	if (TARGET_TYPE_QCA6290 == hdd_ctx->target_type ||
	    TARGET_TYPE_QCA6390 == hdd_ctx->target_type ||
	    TARGET_TYPE_QCA6490 == hdd_ctx->target_type ||
	    TARGET_TYPE_QCA6750 == hdd_ctx->target_type)
		gp_cds_context->dp_soc = cdp_soc_attach(LITHIUM_DP,
			gp_cds_context->hif_context, htcInfo.target_psoc,
			gp_cds_context->htc_ctx, gp_cds_context->qdf_ctx,
			&dp_ol_if_ops);
	else
		gp_cds_context->dp_soc = cdp_soc_attach(MOB_DRV_LEGACY_DP,
			gp_cds_context->hif_context, htcInfo.target_psoc,
			gp_cds_context->htc_ctx, gp_cds_context->qdf_ctx,
			&dp_ol_if_ops);

	if (!gp_cds_context->dp_soc) {
		status = QDF_STATUS_E_FAILURE;
		goto err_wma_close;
	}

	wlan_psoc_set_dp_handle(psoc, gp_cds_context->dp_soc);
	ucfg_pmo_psoc_update_dp_handle(psoc, gp_cds_context->dp_soc);
	ucfg_ocb_update_dp_handle(psoc, gp_cds_context->dp_soc);

	cds_set_ac_specs_params(cds_cfg);
	cds_cfg_update_ac_specs_params((struct txrx_pdev_cfg_param_t *)
				       gp_cds_context->cfg_ctx, cds_cfg);
	cds_cdp_cfg_attach(psoc);

	bmi_target_ready(scn, gp_cds_context->cfg_ctx);

	/* Now proceed to open the MAC */
	status = mac_open(psoc, &mac_handle,
			  gp_cds_context->hdd_context, cds_cfg);

	if (QDF_STATUS_SUCCESS != status) {
		cds_alert("Failed to open MAC");
		goto err_soc_detach;
	}
	gp_cds_context->mac_context = mac_handle;

	/* Now proceed to open the SME */
	status = sme_open(mac_handle);
	if (QDF_IS_STATUS_ERROR(status)) {
		cds_alert("Failed to open SME");
		goto err_mac_close;
	}

	cds_register_all_modules();

	status = dispatcher_psoc_open(psoc);
	if (QDF_IS_STATUS_ERROR(status)) {
		cds_alert("Failed to open PSOC Components");
		goto deregister_modules;
	}

	ucfg_mc_cp_stats_register_pmo_handler();
	qdf_hang_event_register_notifier(&cds_hang_event_notifier);

	return QDF_STATUS_SUCCESS;

deregister_modules:
	cds_deregister_all_modules();
	sme_close(mac_handle);

err_mac_close:
	mac_close(mac_handle);
	gp_cds_context->mac_context = NULL;

err_soc_detach:
	cdp_soc_detach(gp_cds_context->dp_soc);
	gp_cds_context->dp_soc = NULL;

	ucfg_ocb_update_dp_handle(psoc, NULL);
	ucfg_pmo_psoc_update_dp_handle(psoc, NULL);
	wlan_psoc_set_dp_handle(psoc, NULL);

err_wma_close:
	cds_shutdown_notifier_purge();
	wma_close();
	wma_wmi_service_close();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

err_htc_close:
	if (gp_cds_context->htc_ctx) {
		htc_destroy(gp_cds_context->htc_ctx);
		gp_cds_context->htc_ctx = NULL;
<<<<<<< HEAD
=======
		ucfg_pmo_psoc_update_htc_handle(psoc, NULL);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	}

err_bmi_close:
	bmi_cleanup(ol_ctx);

err_sched_close:
<<<<<<< HEAD
	if (QDF_IS_STATUS_ERROR(cds_sched_close(gp_cds_context))) {
		cds_err("Failed to close CDS Scheduler");
		QDF_ASSERT(false);
	}

err_concurrency_lock:
	qdf_mutex_destroy(&cds_ctx->qdf_conc_list_lock);

err_msg_queue:
	cds_mq_deinit(&gp_cds_context->freeVosMq);

err_wma_complete_event:
	qdf_event_destroy(&gp_cds_context->wmaCompleteEvent);

err_probe_event:
	qdf_event_destroy(&gp_cds_context->ProbeEvent);
=======
	if (QDF_IS_STATUS_ERROR(cds_sched_close()))
		QDF_DEBUG_PANIC("Failed to close CDS Scheduler");

err_dispatcher_disable:
	if (QDF_IS_STATUS_ERROR(dispatcher_disable()))
		QDF_DEBUG_PANIC("Failed to disable dispatcher");

err_wma_complete_event:
	qdf_event_destroy(&gp_cds_context->wma_complete_event);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	return status;
} /* cds_open() */

<<<<<<< HEAD
static QDF_STATUS cds_pktlog_enable(void *pdev_txrx_ctx, void *scn)
{
	int errno;

	switch (cds_get_conparam()) {
	case QDF_GLOBAL_FTM_MODE:
	case QDF_GLOBAL_EPPING_MODE:
		return QDF_STATUS_SUCCESS;
	default:
		break;
	}

	htt_pkt_log_init(pdev_txrx_ctx, scn);

	errno = pktlog_htc_attach();
	if (errno)
		goto pktlog_deinit;

	return QDF_STATUS_SUCCESS;

pktlog_deinit:
	htt_pktlogmod_exit(pdev_txrx_ctx, scn);

	return QDF_STATUS_E_FAILURE;
}

static void cds_pktlog_disable(void *pdev_txrx_ctx, void *scn)
{
	switch (cds_get_conparam()) {
	case QDF_GLOBAL_FTM_MODE:
	case QDF_GLOBAL_EPPING_MODE:
		return;
	default:
		break;
	}

	htt_pktlogmod_exit(pdev_txrx_ctx, scn);
}

/**
 * cds_pre_enable() - pre enable cds
 * @cds_context: CDS context
 *
 * Return: QDF status
 */
QDF_STATUS cds_pre_enable(v_CONTEXT_t cds_context)
{
	QDF_STATUS qdf_status = QDF_STATUS_SUCCESS;
	p_cds_contextType p_cds_context = (p_cds_contextType) cds_context;
	void *scn;

	QDF_TRACE(QDF_MODULE_ID_SYS, QDF_TRACE_LEVEL_DEBUG, "cds prestart");

	if (gp_cds_context != p_cds_context) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: Context mismatch", __func__);
		QDF_ASSERT(0);
		return QDF_STATUS_E_INVAL;
	}

	if (p_cds_context->pMACContext == NULL) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: MAC NULL context", __func__);
		QDF_ASSERT(0);
		return QDF_STATUS_E_INVAL;
	}

	if (p_cds_context->pWMAContext == NULL) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: WMA NULL context", __func__);
		QDF_ASSERT(0);
		return QDF_STATUS_E_INVAL;
	}

	scn = cds_get_context(QDF_MODULE_ID_HIF);
	if (!scn) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_FATAL,
			  "%s: scn is null!", __func__);
		return QDF_STATUS_E_FAILURE;
	}

	/* call Packetlog connect service */
	qdf_status = cds_pktlog_enable(gp_cds_context->pdev_txrx_ctx, scn);
	if (QDF_IS_STATUS_ERROR(qdf_status))
		return qdf_status;

	/* Reset wma wait event */
	qdf_event_reset(&gp_cds_context->wmaCompleteEvent);

	/*call WMA pre start */
	qdf_status = wma_pre_start(gp_cds_context);
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		QDF_TRACE(QDF_MODULE_ID_SYS, QDF_TRACE_LEVEL_FATAL,
			  "Failed to WMA prestart");
		QDF_ASSERT(0);
		goto pktlog_disable;
	}

	/* Need to update time out of complete */
	qdf_status = qdf_wait_for_event_completion(
					&gp_cds_context->wmaCompleteEvent,
					CDS_WMA_TIMEOUT);
	if (qdf_status != QDF_STATUS_SUCCESS) {
		if (qdf_status == QDF_STATUS_E_TIMEOUT) {
			QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
				  "%s: Timeout occurred before WMA complete",
				  __func__);
		} else {
			QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
				  "%s: wma_pre_start reporting other error",
				  __func__);
		}
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: Test MC thread by posting a probe message to SYS",
			  __func__);
		wlan_sys_probe();

		QDF_ASSERT(0);
		goto pktlog_disable;
	}

	qdf_status = htc_start(gp_cds_context->htc_ctx);
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		QDF_TRACE(QDF_MODULE_ID_SYS, QDF_TRACE_LEVEL_FATAL,
			  "Failed to Start HTC");
		QDF_ASSERT(0);
		goto pktlog_disable;
	}
	qdf_status = wma_wait_for_ready_event(gp_cds_context->pWMAContext);
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_FATAL,
			  "Failed to get ready event from target firmware");

		/*
		 * Panic when the failure is not because the FW is down,
		 * fail gracefully if FW is down allowing re-probing from
		 * from the platform driver
		 */
		if ((!cds_is_fw_down()) && (!cds_is_self_recovery_enabled()))
			QDF_BUG(0);

		wma_wmi_stop();
		htc_stop(gp_cds_context->htc_ctx);
		goto pktlog_disable;
	}

	if (ol_txrx_pdev_post_attach(gp_cds_context->pdev_txrx_ctx)) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_FATAL,
			"Failed to attach pdev");
		wma_wmi_stop();
		htc_stop(gp_cds_context->htc_ctx);
		QDF_ASSERT(0);
		qdf_status = QDF_STATUS_E_FAILURE;
		goto pktlog_disable;
	}

	return QDF_STATUS_SUCCESS;

pktlog_disable:
	cds_pktlog_disable(gp_cds_context->pdev_txrx_ctx, scn);

	return qdf_status;
}

/**
 * cds_enable() - start/enable cds module
 * @cds_context: CDS context
 *
 * Return: QDF status
 */
QDF_STATUS cds_enable(v_CONTEXT_t cds_context)
{
	QDF_STATUS qdf_status;
	tSirRetStatus sirStatus = eSIR_SUCCESS;
	p_cds_contextType p_cds_context = (p_cds_contextType) cds_context;
	tHalMacStartParameters halStartParams;
	int errno;

	/* We support only one instance for now ... */
	if (gp_cds_context != p_cds_context) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: mismatch in context", __func__);
		return QDF_STATUS_E_FAILURE;
	}

	if (!p_cds_context->pWMAContext) {
=======
QDF_STATUS cds_dp_open(struct wlan_objmgr_psoc *psoc)
{
	QDF_STATUS qdf_status;
	struct dp_txrx_config dp_config;

	qdf_status = cdp_pdev_attach(cds_get_context(QDF_MODULE_ID_SOC),
				     gp_cds_context->htc_ctx,
				     gp_cds_context->qdf_ctx, 0);
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		/* Critical Error ...  Cannot proceed further */
		cds_alert("Failed to open TXRX");
		QDF_ASSERT(0);
		goto close;
	}

	if (cdp_txrx_intr_attach(gp_cds_context->dp_soc)
				!= QDF_STATUS_SUCCESS) {
		cds_alert("Failed to attach interrupts");
		goto pdev_detach;
	}

	dp_config.enable_rx_threads =
		(cds_get_conparam() == QDF_GLOBAL_MONITOR_MODE) ?
		false : gp_cds_context->cds_cfg->enable_dp_rx_threads;

	qdf_status = dp_txrx_init(cds_get_context(QDF_MODULE_ID_SOC),
				  OL_TXRX_PDEV_ID,
				  &dp_config);

	if (!QDF_IS_STATUS_SUCCESS(qdf_status))
		goto intr_close;

	ucfg_pmo_psoc_set_txrx_pdev_id(psoc, OL_TXRX_PDEV_ID);
	ucfg_ocb_set_txrx_pdev_id(psoc, OL_TXRX_PDEV_ID);

	cds_debug("CDS successfully Opened");

	return 0;

intr_close:
	cdp_txrx_intr_detach(gp_cds_context->dp_soc);

pdev_detach:
	cdp_pdev_detach(gp_cds_context->dp_soc,
			OL_TXRX_PDEV_ID, false);

close:
	return QDF_STATUS_E_FAILURE;
}

#ifdef HIF_USB
static inline void cds_suspend_target(tp_wma_handle wma_handle)
{
	QDF_STATUS status;
	/* Suspend the target and disable interrupt */
	status = ucfg_pmo_psoc_suspend_target(wma_handle->psoc, 0);
	if (status)
		cds_err("Failed to suspend target, status = %d", status);
}
#else
static inline void cds_suspend_target(tp_wma_handle wma_handle)
{
	QDF_STATUS status;
	/* Suspend the target and disable interrupt */
	status = ucfg_pmo_psoc_suspend_target(wma_handle->psoc, 1);
	if (status)
		cds_err("Failed to suspend target, status = %d", status);
}
#endif /* HIF_USB */

/**
 * cds_pre_enable() - pre enable cds
 *
 * Return: QDF status
 */
QDF_STATUS cds_pre_enable(void)
{
	QDF_STATUS status;
	int errno;
	void *scn;
	void *soc;
	void *hif_ctx;

	cds_enter();

	if (!gp_cds_context) {
		cds_err("cds context is null");
		return QDF_STATUS_E_INVAL;
	}

	if (!gp_cds_context->wma_context) {
		cds_err("wma context is null");
		return QDF_STATUS_E_INVAL;
	}

	scn = cds_get_context(QDF_MODULE_ID_HIF);
	if (!scn) {
		cds_err("hif context is null");
		return QDF_STATUS_E_INVAL;
	}

	soc = cds_get_context(QDF_MODULE_ID_SOC);
	if (!soc) {
		cds_err("soc context is null");
		return QDF_STATUS_E_INVAL;
	}

	/* call Packetlog connect service */
	if (QDF_GLOBAL_FTM_MODE != cds_get_conparam() &&
	    QDF_GLOBAL_EPPING_MODE != cds_get_conparam())
		cdp_pkt_log_con_service(soc, OL_TXRX_PDEV_ID,
					scn);

	/*call WMA pre start */
	status = wma_pre_start();
	if (QDF_IS_STATUS_ERROR(status)) {
		cds_err("Failed to WMA prestart");
		return QDF_STATUS_E_FAILURE;
	}

	status = htc_start(gp_cds_context->htc_ctx);
	if (QDF_IS_STATUS_ERROR(status)) {
		cds_err("Failed to Start HTC");
		goto exit_with_status;
	}

	status = wma_wait_for_ready_event(gp_cds_context->wma_context);
	if (QDF_IS_STATUS_ERROR(status)) {
		cds_err("Failed to wait for ready event; status: %u", status);
		goto stop_wmi;
	}

	errno = cdp_pdev_post_attach(soc, OL_TXRX_PDEV_ID);
	if (errno) {
		cds_err("Failed to attach pdev");
		status = qdf_status_from_os_return(errno);
		goto stop_wmi;
	}

	return QDF_STATUS_SUCCESS;

stop_wmi:
	/* Send pdev suspend to fw otherwise FW is not aware that
	 * host is freeing resources.
	 */
	if (!(cds_is_driver_recovering() || cds_is_driver_in_bad_state()))
		cds_suspend_target(gp_cds_context->wma_context);

	hif_ctx = cds_get_context(QDF_MODULE_ID_HIF);
	if (!hif_ctx)
		cds_err("%s: Failed to get hif_handle!", __func__);

	wma_wmi_stop();

	if (hif_ctx) {
		cds_err("%s: Disable the isr & reset the soc!", __func__);
		hif_disable_isr(hif_ctx);
		hif_reset_soc(hif_ctx);
	}
	htc_stop(gp_cds_context->htc_ctx);

	wma_wmi_work_close();
exit_with_status:
	return status;
}

QDF_STATUS cds_enable(struct wlan_objmgr_psoc *psoc)
{
	QDF_STATUS qdf_status;
	struct mac_start_params mac_params;
	int errno;

	/* We support only one instance for now ... */
	if (!gp_cds_context) {
		cds_err("Invalid CDS context");
		return QDF_STATUS_E_FAILURE;
	}

	if (!gp_cds_context->wma_context) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		cds_err("WMA NULL context");
		return QDF_STATUS_E_FAILURE;
	}

<<<<<<< HEAD
	if (!p_cds_context->pMACContext) {
=======
	if (!gp_cds_context->mac_context) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		cds_err("MAC NULL context");
		return QDF_STATUS_E_FAILURE;
	}

	/* Start the wma */
<<<<<<< HEAD
	qdf_status = wma_start(p_cds_context);
=======
	qdf_status = wma_start();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	if (qdf_status != QDF_STATUS_SUCCESS) {
		cds_err("Failed to start wma; status:%d", qdf_status);
		return QDF_STATUS_E_FAILURE;
	}

	/* Start the MAC */
<<<<<<< HEAD
	qdf_mem_zero(&halStartParams, sizeof(tHalMacStartParameters));

	/* Start the MAC */
	sirStatus = mac_start(p_cds_context->pMACContext, &halStartParams);

	if (eSIR_SUCCESS != sirStatus) {
		cds_err("Failed to start MAC; status:%d", sirStatus);
=======
	qdf_mem_zero(&mac_params, sizeof(mac_params));
	mac_params.driver_type = QDF_DRIVER_TYPE_PRODUCTION;
	qdf_status = mac_start(gp_cds_context->mac_context, &mac_params);

	if (QDF_STATUS_SUCCESS != qdf_status) {
		cds_err("Failed to start MAC; status:%d", qdf_status);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		goto err_wma_stop;
	}

	/* START SME */
<<<<<<< HEAD
	qdf_status = sme_start(p_cds_context->pMACContext);
=======
	qdf_status = sme_start(gp_cds_context->mac_context);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		cds_err("Failed to start SME; status:%d", qdf_status);
		goto err_mac_stop;
	}

<<<<<<< HEAD
	errno = ol_txrx_pdev_attach_target(p_cds_context->pdev_txrx_ctx);
	if (errno) {
		cds_err("Failed to attach pdev target; errno:%d", errno);
		goto err_sme_stop;
	}

	return QDF_STATUS_SUCCESS;

err_sme_stop:
	sme_stop(p_cds_context->pMACContext, HAL_STOP_TYPE_SYS_RESET);

err_mac_stop:
	mac_stop(p_cds_context->pMACContext, HAL_STOP_TYPE_SYS_RESET);

err_wma_stop:
	qdf_event_reset(&(gp_cds_context->wmaCompleteEvent));
	qdf_status = wma_stop(p_cds_context, HAL_STOP_TYPE_RF_KILL);
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: Failed to stop wma", __func__);
		QDF_ASSERT(QDF_IS_STATUS_SUCCESS(qdf_status));
		wma_setneedshutdown(cds_context);
	} else {
		qdf_status =
			qdf_wait_for_event_completion(
					&gp_cds_context->wmaCompleteEvent,
					CDS_WMA_TIMEOUT);
		if (qdf_status != QDF_STATUS_SUCCESS) {
			if (qdf_status == QDF_STATUS_E_TIMEOUT) {
				QDF_TRACE(QDF_MODULE_ID_QDF,
					  QDF_TRACE_LEVEL_FATAL,
					  "%s: Timeout occurred before WMA_stop complete",
					  __func__);
			} else {
				QDF_TRACE(QDF_MODULE_ID_QDF,
					  QDF_TRACE_LEVEL_FATAL,
					  "%s: WMA_stop reporting other error",
					  __func__);
			}
			QDF_ASSERT(0);
			wma_setneedshutdown(cds_context);
=======
	qdf_status = cdp_soc_attach_target(cds_get_context(QDF_MODULE_ID_SOC));
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		cds_err("Failed to attach soc target; status:%d", qdf_status);
		goto err_sme_stop;
	}

	errno = cdp_pdev_attach_target(cds_get_context(QDF_MODULE_ID_SOC),
				       OL_TXRX_PDEV_ID);
	if (errno) {
		cds_err("Failed to attach pdev target; errno:%d", errno);
		goto err_soc_target_detach;
	}

	qdf_status = dispatcher_psoc_enable(psoc);
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		cds_err("dispatcher_psoc_enable failed; status:%d", qdf_status);
		goto err_soc_target_detach;
	}

	/* Trigger psoc enable for CLD components */
	hdd_component_psoc_enable(psoc);

	return QDF_STATUS_SUCCESS;

err_soc_target_detach:
	/* NOOP */

err_sme_stop:
	sme_stop(gp_cds_context->mac_context);

err_mac_stop:
	mac_stop(gp_cds_context->mac_context);

err_wma_stop:
	qdf_event_reset(&gp_cds_context->wma_complete_event);
	qdf_status = wma_stop();
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		cds_err("Failed to stop wma");
		QDF_ASSERT(QDF_IS_STATUS_SUCCESS(qdf_status));
		wma_setneedshutdown();
	} else {
		qdf_status =
			qdf_wait_for_event_completion(
					&gp_cds_context->wma_complete_event,
					CDS_WMA_TIMEOUT);
		if (qdf_status != QDF_STATUS_SUCCESS) {
			if (qdf_status == QDF_STATUS_E_TIMEOUT) {
				cds_alert("Timeout occurred before WMA_stop complete");
			} else {
				cds_alert("WMA_stop reporting other error");
			}
			QDF_ASSERT(0);
			wma_setneedshutdown();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		}
	}

	return QDF_STATUS_E_FAILURE;
} /* cds_enable() */

/**
 * cds_disable() - stop/disable cds module
<<<<<<< HEAD
 * @cds_context: CDS context
 *
 * Return: QDF status
 */
QDF_STATUS cds_disable(v_CONTEXT_t cds_context)
=======
 * @psoc: Psoc pointer
 *
 * Return: QDF status
 */
QDF_STATUS cds_disable(struct wlan_objmgr_psoc *psoc)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	QDF_STATUS qdf_status;
	void *handle;

<<<<<<< HEAD
	if (gp_cds_sched_context)
		cds_sched_flush_mc_mqs(gp_cds_sched_context);

	qdf_status = wma_stop(cds_context, HAL_STOP_TYPE_RF_KILL);
=======
	/* PSOC disable for all new components. It needs to happen before
	 * target is PDEV suspended such that a component can abort all its
	 * ongoing transaction with FW. Always keep it before wma_stop() as
	 * wma_stop() does target PDEV suspend.
	 */

	/* Trigger psoc disable for CLD components */
	if (psoc) {
		hdd_component_psoc_disable(psoc);
		dispatcher_psoc_disable(psoc);
	}

	qdf_status = wma_stop();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		cds_err("Failed to stop wma");
		QDF_ASSERT(QDF_IS_STATUS_SUCCESS(qdf_status));
<<<<<<< HEAD
		wma_setneedshutdown(cds_context);
=======
		wma_setneedshutdown();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	}

	handle = cds_get_context(QDF_MODULE_ID_PE);
	if (!handle) {
		cds_err("Invalid PE context return!");
		return QDF_STATUS_E_INVAL;
	}

<<<<<<< HEAD
	umac_stop(cds_context);
=======
	umac_stop();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	return qdf_status;
}

<<<<<<< HEAD
#ifdef HIF_USB
static inline void cds_suspend_target(tp_wma_handle wma_handle)
{
	QDF_STATUS status;
	/* Suspend the target and disable interrupt */
	status = wma_suspend_target(wma_handle, 0);
	if (status)
		cds_err("Failed to suspend target, status = %d", status);
}
#else
static inline void cds_suspend_target(tp_wma_handle wma_handle)
{
	QDF_STATUS status;
	/* Suspend the target and disable interrupt */
	status = wma_suspend_target(wma_handle, 1);
	if (status)
		cds_err("Failed to suspend target, status = %d", status);
}
#endif /* HIF_USB */

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/**
 * cds_post_disable() - post disable cds module
 *
 * Return: QDF status
 */
QDF_STATUS cds_post_disable(void)
{
	tp_wma_handle wma_handle;
	struct hif_opaque_softc *hif_ctx;
<<<<<<< HEAD
	ol_txrx_pdev_handle txrx_pdev;
=======
	struct scheduler_ctx *sched_ctx;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	QDF_STATUS qdf_status;

	wma_handle = cds_get_context(QDF_MODULE_ID_WMA);
	if (!wma_handle) {
		cds_err("Failed to get wma_handle!");
		return QDF_STATUS_E_INVAL;
	}

	hif_ctx = cds_get_context(QDF_MODULE_ID_HIF);
	if (!hif_ctx) {
		cds_err("Failed to get hif_handle!");
		return QDF_STATUS_E_INVAL;
	}

<<<<<<< HEAD
	txrx_pdev = cds_get_context(QDF_MODULE_ID_TXRX);
	if (!txrx_pdev) {
		cds_err("Failed to get txrx pdev!");
		return QDF_STATUS_E_INVAL;
	}

	/* Clean up all MC thread message queues */
	if (gp_cds_sched_context)
		cds_sched_flush_mc_mqs(gp_cds_sched_context);
=======
	/* flush any unprocessed scheduler messages */
	sched_ctx = scheduler_get_context();
	if (sched_ctx)
		scheduler_queues_flush(sched_ctx);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	/*
	 * With new state machine changes cds_close can be invoked without
	 * cds_disable. So, send the following clean up prerequisites to fw,
	 * So Fw and host are in sync for cleanup indication:
	 * - Send PDEV_SUSPEND indication to firmware
	 * - Disable HIF Interrupts.
	 * - Clean up CE tasklets.
	 */

<<<<<<< HEAD
	cds_info("send deinit sequence to firmware");
=======
	cds_debug("send deinit sequence to firmware");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	if (!(cds_is_driver_recovering() || cds_is_driver_in_bad_state()))
		cds_suspend_target(wma_handle);
	hif_disable_isr(hif_ctx);
	hif_reset_soc(hif_ctx);

	if (gp_cds_context->htc_ctx) {
		wma_wmi_stop();
		htc_stop(gp_cds_context->htc_ctx);
	}

<<<<<<< HEAD
	qdf_status = cds_close_rx_thread(gp_cds_context);
=======
	qdf_status = cds_close_rx_thread();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		cds_err("Failed to close RX thread!");
		return QDF_STATUS_E_INVAL;
	}

<<<<<<< HEAD
	if (cds_get_pktcap_mode_enable()) {
		qdf_status = cds_close_mon_thread(gp_cds_context);
		if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
			cds_err("Failed to close MON thread!");
			return QDF_STATUS_E_INVAL;
		}
	}

	ol_txrx_pdev_pre_detach(txrx_pdev, 1);
=======
	qdf_status = cds_close_mon_thread();
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		cds_err("Failed to close MON thread!");
		return QDF_STATUS_E_INVAL;
	}

	cdp_pdev_pre_detach(cds_get_context(QDF_MODULE_ID_SOC),
			    OL_TXRX_PDEV_ID, 1);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	return QDF_STATUS_SUCCESS;
}

/**
 * cds_close() - close cds module
<<<<<<< HEAD
 * @cds_context: CDS context
=======
 * @psoc: Psoc pointer
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *
 * This API allows user to close modules registered
 * with connectivity device services.
 *
 * Return: QDF status
 */
<<<<<<< HEAD
QDF_STATUS cds_close(v_CONTEXT_t cds_context)
{
	QDF_STATUS qdf_status;

	qdf_status = cds_sched_close(cds_context);
=======
QDF_STATUS cds_close(struct wlan_objmgr_psoc *psoc)
{
	QDF_STATUS qdf_status;

	qdf_hang_event_unregister_notifier(&cds_hang_event_notifier);
	qdf_status = cds_sched_close();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	QDF_ASSERT(QDF_IS_STATUS_SUCCESS(qdf_status));
	if (QDF_IS_STATUS_ERROR(qdf_status))
		cds_err("Failed to close CDS Scheduler");

<<<<<<< HEAD
	qdf_status = wma_wmi_work_close(cds_context);
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
		 "%s: Failed to close wma_wmi_work", __func__);
		QDF_ASSERT(0);
	}

	hdd_lro_destroy();
	hdd_gro_destroy();

	if (gp_cds_context->htc_ctx) {
		htc_destroy(gp_cds_context->htc_ctx);
		gp_cds_context->htc_ctx = NULL;
	}

	ol_txrx_pdev_detach(gp_cds_context->pdev_txrx_ctx);
	cds_free_context(cds_context, QDF_MODULE_ID_TXRX,
			 gp_cds_context->pdev_txrx_ctx);

	qdf_status = sme_close(((p_cds_contextType) cds_context)->pMACContext);
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: Failed to close SME", __func__);
		QDF_ASSERT(QDF_IS_STATUS_SUCCESS(qdf_status));
	}

	qdf_status = mac_close(((p_cds_contextType) cds_context)->pMACContext);
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: Failed to close MAC", __func__);
		QDF_ASSERT(QDF_IS_STATUS_SUCCESS(qdf_status));
	}

	((p_cds_contextType) cds_context)->pMACContext = NULL;

	cds_shutdown_notifier_purge();

	if (true == wma_needshutdown(cds_context)) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
				  "%s: Failed to shutdown wma", __func__);
	} else {
		qdf_status = wma_close(cds_context);
		if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
			QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
				  "%s: Failed to close wma", __func__);
=======
	qdf_status = dispatcher_disable();
	QDF_ASSERT(QDF_IS_STATUS_SUCCESS(qdf_status));
	if (QDF_IS_STATUS_ERROR(qdf_status))
		cds_err("Failed to disable dispatcher; status:%d", qdf_status);

	dispatcher_psoc_close(psoc);

	qdf_flush_work(&gp_cds_context->cds_recovery_work);

	qdf_status = wma_wmi_work_close();
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		cds_err("Failed to close wma_wmi_work");
		QDF_ASSERT(0);
	}

	if (gp_cds_context->htc_ctx) {
		htc_destroy(gp_cds_context->htc_ctx);
		ucfg_pmo_psoc_update_htc_handle(psoc, NULL);
		gp_cds_context->htc_ctx = NULL;
	}

	qdf_status = sme_close(gp_cds_context->mac_context);
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		cds_err("Failed to close SME");
		QDF_ASSERT(QDF_IS_STATUS_SUCCESS(qdf_status));
	}

	qdf_status = mac_close(gp_cds_context->mac_context);
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		cds_err("Failed to close MAC");
		QDF_ASSERT(QDF_IS_STATUS_SUCCESS(qdf_status));
	}

	gp_cds_context->mac_context = NULL;

	cdp_soc_detach(gp_cds_context->dp_soc);
	gp_cds_context->dp_soc = NULL;

	ucfg_pmo_psoc_update_dp_handle(psoc, NULL);
	wlan_psoc_set_dp_handle(psoc, NULL);

	cds_shutdown_notifier_purge();

	if (true == wma_needshutdown()) {
		cds_err("Failed to shutdown wma");
	} else {
		qdf_status = wma_close();
		if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
			cds_err("Failed to close wma");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			QDF_ASSERT(QDF_IS_STATUS_SUCCESS(qdf_status));
		}
	}

<<<<<<< HEAD
	qdf_status = wma_wmi_service_close(cds_context);
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: Failed to close wma_wmi_service", __func__);
		QDF_ASSERT(QDF_IS_STATUS_SUCCESS(qdf_status));
	}

	cds_mq_deinit(&((p_cds_contextType) cds_context)->freeVosMq);

	qdf_status = qdf_event_destroy(&gp_cds_context->wmaCompleteEvent);
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: failed to destroy wmaCompleteEvent", __func__);
		QDF_ASSERT(QDF_IS_STATUS_SUCCESS(qdf_status));
	}

	qdf_status = qdf_event_destroy(&gp_cds_context->ProbeEvent);
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: failed to destroy ProbeEvent", __func__);
		QDF_ASSERT(QDF_IS_STATUS_SUCCESS(qdf_status));
	}

	if (!QDF_IS_STATUS_SUCCESS(qdf_mutex_destroy(
				   &gp_cds_context->qdf_conc_list_lock))) {
		cds_err("Failed to destroy qdf_conc_list_lock");
=======
	qdf_status = wma_wmi_service_close();
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		cds_err("Failed to close wma_wmi_service");
		QDF_ASSERT(QDF_IS_STATUS_SUCCESS(qdf_status));
	}

	qdf_status = qdf_event_destroy(&gp_cds_context->wma_complete_event);
	if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
		cds_err("failed to destroy wma_complete_event");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		QDF_ASSERT(QDF_IS_STATUS_SUCCESS(qdf_status));
	}

	cds_deinit_ini_config();
	qdf_timer_module_deinit();

<<<<<<< HEAD
=======
	cds_deregister_all_modules();

	return QDF_STATUS_SUCCESS;
}

QDF_STATUS cds_dp_close(struct wlan_objmgr_psoc *psoc)
{
	cdp_txrx_intr_detach(gp_cds_context->dp_soc);

	dp_txrx_deinit(cds_get_context(QDF_MODULE_ID_SOC));

	cdp_pdev_detach(cds_get_context(QDF_MODULE_ID_SOC), OL_TXRX_PDEV_ID, 1);

	ucfg_pmo_psoc_set_txrx_pdev_id(psoc, OL_TXRX_INVALID_PDEV_ID);

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	return QDF_STATUS_SUCCESS;
}

/**
 * cds_get_context() - get context data area
 *
<<<<<<< HEAD
 * @moduleId: ID of the module who's context data is being retrived.
=======
 * @module_id: ID of the module who's context data is being retrieved.
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *
 * Each module in the system has a context / data area that is allocated
 * and managed by CDS.  This API allows any user to get a pointer to its
 * allocated context data area from the CDS global context.
 *
 * Return: pointer to the context data area of the module ID
 *	   specified, or NULL if the context data is not allocated for
 *	   the module ID specified
 */
<<<<<<< HEAD
void *cds_get_context(QDF_MODULE_ID moduleId)
{
	void *pModContext = NULL;

	if (gp_cds_context == NULL) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: cds context pointer is null", __func__);
		return NULL;
	}

	switch (moduleId) {
	case QDF_MODULE_ID_HDD:
	{
		pModContext = gp_cds_context->pHDDContext;
=======
void *cds_get_context(QDF_MODULE_ID module_id)
{
	void *context = NULL;

	if (!gp_cds_context) {
		cds_err("cds context pointer is null");
		return NULL;
	}

	switch (module_id) {
	case QDF_MODULE_ID_HDD:
	{
		context = gp_cds_context->hdd_context;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		break;
	}

	case QDF_MODULE_ID_SME:
	case QDF_MODULE_ID_PE:
	{
		/* In all these cases, we just return the MAC Context */
<<<<<<< HEAD
		pModContext = gp_cds_context->pMACContext;
=======
		context = gp_cds_context->mac_context;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		break;
	}

	case QDF_MODULE_ID_WMA:
	{
		/* For wma module */
<<<<<<< HEAD
		pModContext = gp_cds_context->pWMAContext;
=======
		context = gp_cds_context->wma_context;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		break;
	}

	case QDF_MODULE_ID_QDF:
	{
		/* For SYS this is CDS itself */
<<<<<<< HEAD
		pModContext = gp_cds_context;
=======
		context = gp_cds_context;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		break;
	}

	case QDF_MODULE_ID_HIF:
	{
<<<<<<< HEAD
		pModContext = gp_cds_context->pHIFContext;
=======
		context = gp_cds_context->hif_context;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		break;
	}

	case QDF_MODULE_ID_HTC:
	{
<<<<<<< HEAD
		pModContext = gp_cds_context->htc_ctx;
=======
		context = gp_cds_context->htc_ctx;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		break;
	}

	case QDF_MODULE_ID_QDF_DEVICE:
	{
<<<<<<< HEAD
		pModContext = gp_cds_context->qdf_ctx;
=======
		context = gp_cds_context->qdf_ctx;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		break;
	}

	case QDF_MODULE_ID_BMI:
	{
<<<<<<< HEAD
		pModContext = gp_cds_context->g_ol_context;
		break;
	}

	case QDF_MODULE_ID_TXRX:
	{
		pModContext = gp_cds_context->pdev_txrx_ctx;
		break;
	}

	case QDF_MODULE_ID_CFG:
	{
		pModContext = gp_cds_context->cfg_ctx;
=======
		context = gp_cds_context->g_ol_context;
		break;
	}

	case QDF_MODULE_ID_CFG:
	{
		context = gp_cds_context->cfg_ctx;
		break;
	}

	case QDF_MODULE_ID_SOC:
	{
		context = gp_cds_context->dp_soc;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		break;
	}

	default:
	{
<<<<<<< HEAD
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: Module ID %i does not have its context maintained by CDS",
			  __func__, moduleId);
=======
		cds_err("Module ID %i does not have its context maintained by CDS",
			module_id);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		QDF_ASSERT(0);
		return NULL;
	}
	}

<<<<<<< HEAD
	if (pModContext == NULL) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_DEBUG,
			  "%s: Module ID %i context is Null", __func__,
			  moduleId);
	}

	return pModContext;
=======
	if (!context)
		cds_err("Module ID %i context is Null", module_id);

	return context;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
} /* cds_get_context() */

/**
 * cds_get_global_context() - get CDS global Context
 *
 * This API allows any user to get the CDS Global Context pointer from a
 * module context data area.
 *
 * Return: pointer to the CDS global context, NULL if the function is
<<<<<<< HEAD
 *	   unable to retreive the CDS context.
 */
v_CONTEXT_t cds_get_global_context(void)
{
	if (gp_cds_context == NULL) {
=======
 *	   unable to retrieve the CDS context.
 */
void *cds_get_global_context(void)
{
	if (!gp_cds_context) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		/*
		 * To avoid recursive call, this should not change to
		 * QDF_TRACE().
		 */
		pr_err("%s: global cds context is NULL", __func__);
	}

	return gp_cds_context;
} /* cds_get_global_context() */

/**
 * cds_get_driver_state() - Get current driver state
 *
 * This API returns current driver state stored in global context.
 *
 * Return: Driver state enum
 */
enum cds_driver_state cds_get_driver_state(void)
{
<<<<<<< HEAD
	if (gp_cds_context == NULL) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: global cds context is NULL", __func__);
=======
	if (!gp_cds_context) {
		cds_err("global cds context is NULL");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

		return CDS_DRIVER_STATE_UNINITIALIZED;
	}

	return gp_cds_context->driver_state;
}

/**
 * cds_set_driver_state() - Set current driver state
 * @state:	Driver state to be set to.
 *
 * This API sets driver state to state. This API only sets the state and doesn't
 * clear states, please make sure to use cds_clear_driver_state to clear any
 * state if required.
 *
 * Return: None
 */
void cds_set_driver_state(enum cds_driver_state state)
{
<<<<<<< HEAD
	if (gp_cds_context == NULL) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: global cds context is NULL: %x", __func__,
			  state);
=======
	if (!gp_cds_context) {
		cds_err("global cds context is NULL: %x", state);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

		return;
	}

	gp_cds_context->driver_state |= state;
}

/**
 * cds_clear_driver_state() - Clear current driver state
 * @state:	Driver state to be cleared.
 *
 * This API clears driver state. This API only clears the state, please make
 * sure to use cds_set_driver_state to set any new states.
 *
 * Return: None
 */
void cds_clear_driver_state(enum cds_driver_state state)
{
<<<<<<< HEAD
	if (gp_cds_context == NULL) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: global cds context is NULL: %x", __func__,
			  state);
=======
	if (!gp_cds_context) {
		cds_err("global cds context is NULL: %x", state);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

		return;
	}

	gp_cds_context->driver_state &= ~state;
}

<<<<<<< HEAD
enum cds_fw_state cds_get_fw_state(void)
{
	if (gp_cds_context == NULL) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: global cds context is NULL", __func__);

		return CDS_FW_STATE_UNINITIALIZED;
	}

	return gp_cds_context->fw_state;
}

void cds_set_fw_state(enum cds_fw_state state)
{
	if (gp_cds_context == NULL) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: global cds context is NULL: %d", __func__,
			  state);

		return;
	}

	qdf_atomic_set_bit(state, &gp_cds_context->fw_state);
}

void cds_clear_fw_state(enum cds_fw_state state)
{
	if (gp_cds_context == NULL) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: global cds context is NULL: %d", __func__,
			  state);

		return;
	}

	qdf_atomic_clear_bit(state, &gp_cds_context->fw_state);
}

/**
 * cds_alloc_context() - allocate a context within the CDS global Context
 * @p_cds_context: pointer to the global Vos context
 * @moduleId: module ID who's context area is being allocated.
 * @ppModuleContext: pointer to location where the pointer to the
=======
/**
 * cds_alloc_context() - allocate a context within the CDS global Context
 * @module_id: module ID who's context area is being allocated.
 * @module_context: pointer to location where the pointer to the
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *	allocated context is returned. Note this output pointer
 *	is valid only if the API returns QDF_STATUS_SUCCESS
 * @param size: size of the context area to be allocated.
 *
 * This API allows any user to allocate a user context area within the
 * CDS Global Context.
 *
 * Return: QDF status
 */
<<<<<<< HEAD
QDF_STATUS cds_alloc_context(void *p_cds_context, QDF_MODULE_ID moduleID,
			     void **ppModuleContext, uint32_t size)
{
	void **pGpModContext = NULL;

	if (p_cds_context == NULL) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: cds context is null", __func__);
		return QDF_STATUS_E_FAILURE;
	}

	if ((gp_cds_context != p_cds_context) || (ppModuleContext == NULL)) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: context mismatch or null param passed",
			  __func__);
		return QDF_STATUS_E_FAILURE;
	}

	switch (moduleID) {
	case QDF_MODULE_ID_WMA:
	{
		pGpModContext = &(gp_cds_context->pWMAContext);
		break;
	}

	case QDF_MODULE_ID_HIF:
	{
		pGpModContext = &(gp_cds_context->pHIFContext);
		break;
	}

	case QDF_MODULE_ID_BMI:
	{
		pGpModContext = &(gp_cds_context->g_ol_context);
		break;
	}

	case QDF_MODULE_ID_EPPING:
	case QDF_MODULE_ID_SME:
	case QDF_MODULE_ID_PE:
	case QDF_MODULE_ID_HDD:
	case QDF_MODULE_ID_HDD_SOFTAP:
	default:
	{
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: Module ID %i "
			  "does not have its context allocated by CDS",
			  __func__, moduleID);
		QDF_ASSERT(0);
		return QDF_STATUS_E_INVAL;
	}
	}

	if (NULL != *pGpModContext) {
		/* Context has already been allocated!
		 * Prevent double allocation
		 */
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: Module ID %i context has already been allocated",
			  __func__, moduleID);
=======
QDF_STATUS cds_alloc_context(QDF_MODULE_ID module_id,
			     void **module_context, uint32_t size)
{
	void **cds_mod_context = NULL;

	if (!gp_cds_context) {
		cds_err("cds context is null");
		return QDF_STATUS_E_FAILURE;
	}

	if (!module_context) {
		cds_err("null param passed");
		return QDF_STATUS_E_FAILURE;
	}

	switch (module_id) {
	case QDF_MODULE_ID_WMA:
		cds_mod_context = &gp_cds_context->wma_context;
		break;

	case QDF_MODULE_ID_HIF:
		cds_mod_context = &gp_cds_context->hif_context;
		break;

	case QDF_MODULE_ID_BMI:
		cds_mod_context = &gp_cds_context->g_ol_context;
		break;

	default:
		cds_err("Module ID %i does not have its context allocated by CDS",
			module_id);
		QDF_ASSERT(0);
		return QDF_STATUS_E_INVAL;
	}

	if (*cds_mod_context) {
		/* Context has already been allocated!
		 * Prevent double allocation
		 */
		cds_err("Module ID %i context has already been allocated",
			module_id);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return QDF_STATUS_E_EXISTS;
	}

	/* Dynamically allocate the context for module */

<<<<<<< HEAD
	*ppModuleContext = qdf_mem_malloc(size);

	if (*ppModuleContext == NULL) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: Failed to " "allocate Context for module ID %i",
			  __func__, moduleID);
=======
	*module_context = qdf_mem_malloc(size);

	if (!*module_context) {
		cds_err("Failed to allocate Context for module ID %i",
			module_id);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		QDF_ASSERT(0);
		return QDF_STATUS_E_NOMEM;
	}

<<<<<<< HEAD
	*pGpModContext = *ppModuleContext;
=======
	*cds_mod_context = *module_context;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	return QDF_STATUS_SUCCESS;
} /* cds_alloc_context() */

/**
 * cds_set_context() - API to set context in global CDS Context
 * @module_id: Module ID
 * @context: Pointer to the Module Context
 *
 * API to set a MODULE Context in global CDS Context
 *
 * Return: QDF_STATUS
 */
QDF_STATUS cds_set_context(QDF_MODULE_ID module_id, void *context)
{
<<<<<<< HEAD
	p_cds_contextType p_cds_context = cds_get_global_context();

	if (!p_cds_context) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "cds context is Invalid");
=======
	struct cds_context *p_cds_context = cds_get_global_context();

	if (!p_cds_context) {
		cds_err("cds context is Invalid");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return QDF_STATUS_NOT_INITIALIZED;
	}

	switch (module_id) {
<<<<<<< HEAD
	case QDF_MODULE_ID_HIF:
		p_cds_context->pHIFContext = context;
		break;
	case QDF_MODULE_ID_HDD:
		p_cds_context->pHDDContext = context;
		break;
	default:
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: Module ID %i does not have its context managed by CDS",
			  __func__, module_id);
=======
	case QDF_MODULE_ID_HDD:
		p_cds_context->hdd_context = context;
		break;
	case QDF_MODULE_ID_HIF:
		p_cds_context->hif_context = context;
		break;
	default:
		cds_err("Module ID %i does not have its context managed by CDS",
			module_id);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		QDF_ASSERT(0);
		return QDF_STATUS_E_INVAL;
	}

	return QDF_STATUS_SUCCESS;
}

/**
 * cds_free_context() - free an allocated context within the
 *			CDS global Context
<<<<<<< HEAD
 * @p_cds_context: pointer to the global Vos context
 * @moduleId: module ID who's context area is being free
 * @pModuleContext: pointer to module context area to be free'd.
=======
 * @module_id: module ID who's context area is being free
 * @module_context: pointer to module context area to be free'd.
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *
 *  This API allows a user to free the user context area within the
 *  CDS Global Context.
 *
 * Return: QDF status
 */
<<<<<<< HEAD
QDF_STATUS cds_free_context(void *p_cds_context, QDF_MODULE_ID moduleID,
			    void *pModuleContext)
{
	void **pGpModContext = NULL;

	if ((p_cds_context == NULL) || (gp_cds_context != p_cds_context) ||
	    (pModuleContext == NULL)) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: Null params or context mismatch", __func__);
		return QDF_STATUS_E_FAILURE;
	}

	switch (moduleID) {
	case QDF_MODULE_ID_WMA:
	{
		pGpModContext = &(gp_cds_context->pWMAContext);
		break;
	}

	case QDF_MODULE_ID_HIF:
	{
		pGpModContext = &(gp_cds_context->pHIFContext);
		break;
	}

	case QDF_MODULE_ID_TXRX:
	{
		pGpModContext = &(gp_cds_context->pdev_txrx_ctx);
		break;
	}

	case QDF_MODULE_ID_BMI:
	{
		pGpModContext = &(gp_cds_context->g_ol_context);
		break;
	}

	case QDF_MODULE_ID_EPPING:
	case QDF_MODULE_ID_HDD:
	case QDF_MODULE_ID_SME:
	case QDF_MODULE_ID_PE:
	case QDF_MODULE_ID_HDD_SOFTAP:
	default:
	{
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: Module ID %i "
			  "does not have its context allocated by CDS",
			  __func__, moduleID);
		QDF_ASSERT(0);
		return QDF_STATUS_E_INVAL;
	}
	}

	if (NULL == *pGpModContext) {
		/* Context has not been allocated or freed already! */
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: Module ID %i "
			  "context has not been allocated or freed already",
			  __func__, moduleID);
		return QDF_STATUS_E_FAILURE;
	}

	if (*pGpModContext != pModuleContext) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: pGpModContext != pModuleContext", __func__);
		return QDF_STATUS_E_FAILURE;
	}

	if (pModuleContext != NULL)
		qdf_mem_free(pModuleContext);

	*pGpModContext = NULL;
=======
QDF_STATUS cds_free_context(QDF_MODULE_ID module_id, void *module_context)
{
	void **cds_mod_context = NULL;

	if (!gp_cds_context) {
		cds_err("cds context is null");
		return QDF_STATUS_E_FAILURE;
	}

	if (!module_context) {
		cds_err("Null param");
		return QDF_STATUS_E_FAILURE;
	}

	switch (module_id) {
	case QDF_MODULE_ID_WMA:
		cds_mod_context = &gp_cds_context->wma_context;
		break;

	case QDF_MODULE_ID_HIF:
		cds_mod_context = &gp_cds_context->hif_context;
		break;

	case QDF_MODULE_ID_BMI:
		cds_mod_context = &gp_cds_context->g_ol_context;
		break;

	default:
		cds_err("Module ID %i does not have its context allocated by CDS",
			module_id);
		QDF_ASSERT(0);
		return QDF_STATUS_E_INVAL;
	}

	if (!*cds_mod_context) {
		/* Context has not been allocated or freed already! */
		cds_err("Module ID %i context has not been allocated or freed already",
			module_id);
		return QDF_STATUS_E_FAILURE;
	}

	if (*cds_mod_context != module_context) {
		cds_err("cds_mod_context != module_context");
		return QDF_STATUS_E_FAILURE;
	}

	qdf_mem_free(module_context);

	*cds_mod_context = NULL;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	return QDF_STATUS_SUCCESS;
} /* cds_free_context() */

<<<<<<< HEAD
/**
 * cds_mq_post_message_by_priority() - posts message using priority
 * to message queue
 * @msgQueueId: message queue id
 * @pMsg: message to be posted
 * @is_high_priority: wheather message is high priority
 *
 * This function is used to post high priority message to message queue
 *
 * Return: QDF_STATUS_SUCCESS on success
 *         QDF_STATUS_E_FAILURE on failure
 *         QDF_STATUS_E_RESOURCES on resource allocation failure
 */
QDF_STATUS cds_mq_post_message_by_priority(QDF_MODULE_ID msgQueueId,
					   cds_msg_t *pMsg,
					   int is_high_priority)
{
	p_cds_mq_type pTargetMq = NULL;
	p_cds_msg_wrapper pMsgWrapper = NULL;
	uint32_t debug_count = 0;

	if (!pMsg) {
		cds_err("pMsg is null");
		return QDF_STATUS_E_INVAL;
	}

	if (!gp_cds_context) {
		cds_err("gp_cds_context is null");
		return QDF_STATUS_E_INVAL;
	}

	if (!gp_cds_sched_context) {
		cds_err("gp_cds_sched_context is null");
		return QDF_STATUS_E_INVAL;
	}

	if (!gp_cds_sched_context->McThread) {
		cds_err("Cannot post message because MC thread is stopped");
		return QDF_STATUS_E_FAILURE;
	}

	switch (msgQueueId) {
	/* Message Queue ID for messages bound for SME */
	case QDF_MODULE_ID_SME:
	{
		pTargetMq = &(gp_cds_context->qdf_sched.smeMcMq);
		break;
	}

	/* Message Queue ID for messages bound for PE */
	case QDF_MODULE_ID_PE:
	{
		pTargetMq = &(gp_cds_context->qdf_sched.peMcMq);
		break;
	}

	/* Message Queue ID for messages bound for wma */
	case QDF_MODULE_ID_WMA:
	{
		pTargetMq = &(gp_cds_context->qdf_sched.wmaMcMq);
		break;
	}

	/* Message Queue ID for messages bound for the SYS module */
	case QDF_MODULE_ID_SYS:
	{
		pTargetMq = &(gp_cds_context->qdf_sched.sysMcMq);
		break;
	}

	default:
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  ("%s: Trying to queue msg into unknown MC Msg queue ID %d"),
			  __func__, msgQueueId);

		return QDF_STATUS_E_FAILURE;
	}

	QDF_ASSERT(NULL != pTargetMq);
	if (pTargetMq == NULL) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: pTargetMq == NULL", __func__);
		return QDF_STATUS_E_FAILURE;
	}

	/* Try and get a free Msg wrapper */
	pMsgWrapper = cds_mq_get(&gp_cds_context->freeVosMq);

	if (NULL == pMsgWrapper) {
		debug_count = atomic_inc_return(&cds_wrapper_empty_count);
		if (1 == debug_count) {
			QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
				"%s: CDS Core run out of message wrapper %d",
				__func__, debug_count);
			cds_flush_logs(WLAN_LOG_TYPE_FATAL,
				WLAN_LOG_INDICATOR_HOST_ONLY,
				WLAN_LOG_REASON_VOS_MSG_UNDER_RUN,
				true, false);
		}
		if (CDS_WRAPPER_MAX_FAIL_COUNT == debug_count)
			QDF_BUG(0);

		return QDF_STATUS_E_RESOURCES;
	}

	atomic_set(&cds_wrapper_empty_count, 0);

	/* Copy the message now */
	qdf_mem_copy((void *)pMsgWrapper->pVosMsg,
		     (void *)pMsg, sizeof(cds_msg_t));

	if (is_high_priority)
		cds_mq_put_front(pTargetMq, pMsgWrapper);
	else
		cds_mq_put(pTargetMq, pMsgWrapper);

	set_bit(MC_POST_EVENT, &gp_cds_context->qdf_sched.mcEventFlag);
	wake_up_interruptible(&gp_cds_context->qdf_sched.mcWaitQueue);

	return QDF_STATUS_SUCCESS;
} /* cds_mq_post_message() */

/**
 * cds_sys_probe_thread_cback() -  probe mc thread callback
 * @pUserData: pointer to user data
 *
 * Return: none
 */
void cds_sys_probe_thread_cback(void *pUserData)
{
	if (gp_cds_context != pUserData) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: gp_cds_context != pUserData", __func__);
		return;
	}

	if (qdf_event_set(&gp_cds_context->ProbeEvent) != QDF_STATUS_SUCCESS) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: qdf_event_set failed", __func__);
		return;
	}
} /* cds_sys_probe_thread_cback() */

/**
 * cds_wma_complete_cback() - wma complete callback
 * @pUserData: pointer to user data
 *
 * Return: none
 */
void cds_wma_complete_cback(void *pUserData)
{
	if (gp_cds_context != pUserData) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: gp_cds_context != pUserData", __func__);
		return;
	}

	if (qdf_event_set(&gp_cds_context->wmaCompleteEvent) !=
	    QDF_STATUS_SUCCESS) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: qdf_event_set failed", __func__);
		return;
	}
} /* cds_wma_complete_cback() */

/**
 * cds_core_return_msg() - return core message
 * @pVContext: pointer to cds context
 * @pMsgWrapper: pointer to message wrapper
 *
 * Return: none
 */
void cds_core_return_msg(void *pVContext, p_cds_msg_wrapper pMsgWrapper)
{
	p_cds_contextType p_cds_context = (p_cds_contextType) pVContext;

	QDF_ASSERT(gp_cds_context == p_cds_context);

	if (gp_cds_context != p_cds_context) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: gp_cds_context != p_cds_context", __func__);
		return;
	}

	QDF_ASSERT(NULL != pMsgWrapper);

	if (pMsgWrapper == NULL) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: pMsgWrapper == NULL in function", __func__);
		return;
	}

	/*
	** Return the message on the free message queue
	*/
	INIT_LIST_HEAD(&pMsgWrapper->msgNode);
	cds_mq_put(&p_cds_context->freeVosMq, pMsgWrapper);
} /* cds_core_return_msg() */

/**
 * cds_get_vdev_types() - get vdev type
 * @mode: mode
 * @type: type
 * @sub_type: sub_type
 *
 * Return: WMI vdev type
 */
QDF_STATUS cds_get_vdev_types(enum tQDF_ADAPTER_MODE mode, uint32_t *type,
			      uint32_t *sub_type)
{
	QDF_STATUS status = QDF_STATUS_SUCCESS;
	*type = 0;
	*sub_type = 0;

	switch (mode) {
	case QDF_STA_MODE:
		*type = WMI_VDEV_TYPE_STA;
		break;
	case QDF_SAP_MODE:
		*type = WMI_VDEV_TYPE_AP;
		break;
	case QDF_P2P_DEVICE_MODE:
		*type = WMI_VDEV_TYPE_AP;
		*sub_type = WMI_UNIFIED_VDEV_SUBTYPE_P2P_DEVICE;
		break;
	case QDF_P2P_CLIENT_MODE:
		*type = WMI_VDEV_TYPE_STA;
		*sub_type = WMI_UNIFIED_VDEV_SUBTYPE_P2P_CLIENT;
		break;
	case QDF_P2P_GO_MODE:
		*type = WMI_VDEV_TYPE_AP;
		*sub_type = WMI_UNIFIED_VDEV_SUBTYPE_P2P_GO;
		break;
	case QDF_OCB_MODE:
		*type = WMI_VDEV_TYPE_OCB;
		break;
	case QDF_IBSS_MODE:
		*type = WMI_VDEV_TYPE_IBSS;
		break;
	case QDF_MONITOR_MODE:
		*type = WMI_VDEV_TYPE_MONITOR;
		break;
	case QDF_NDI_MODE:
		*type = WMI_VDEV_TYPE_NDI;
		break;
	default:
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "Invalid device mode %d", mode);
		status = QDF_STATUS_E_INVAL;
		break;
	}
	return status;
}
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * cds_flush_work() - flush pending works
 * @work: pointer to work
 *
 * Return: none
 */
void cds_flush_work(void *work)
{
	cancel_work_sync(work);
}

/**
 * cds_flush_delayed_work() - flush delayed works
 * @dwork: pointer to delayed work
 *
 * Return: none
 */
void cds_flush_delayed_work(void *dwork)
{
	cancel_delayed_work_sync(dwork);
}

<<<<<<< HEAD
=======
#ifndef REMOVE_PKT_LOG
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/**
 * cds_is_packet_log_enabled() - check if packet log is enabled
 *
 * Return: true if packet log is enabled else false
 */
bool cds_is_packet_log_enabled(void)
{
<<<<<<< HEAD
	hdd_context_t *pHddCtx;

	pHddCtx = (hdd_context_t *) (gp_cds_context->pHDDContext);
	if ((NULL == pHddCtx) || (NULL == pHddCtx->config)) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_FATAL,
			  "%s: Hdd Context is Null", __func__);
		return false;
	}

	return pHddCtx->config->enablePacketLog;
}

#ifdef QCA_WIFI_3_0_ADRASTEA
/**
 * cds_force_assert_target() - Force target assert via platform
 * driver
 * @qdf_ctx: pointer of qdf context
 *
 * For ADRASTREA chipsets target assert is supported via platform driver,
 * for ROME chipsets control of self-recovery is with the hostdriver.
 *
 * Return: QDF_STATUS_SUCCESS if target assert through firmware is supported
 *         QDF_STATUS_E_INVAL if targer assert through firmware failed
 */
static QDF_STATUS cds_force_assert_target(qdf_device_t qdf_ctx)
{

	cds_set_recovery_in_progress(true);
	/*
	 * If force assert thru platform is available, trigger that interface.
	 * That should generate recovery by going thru the normal FW
	 * assert recovery model.
	 */
	if (!pld_force_assert_target(qdf_ctx->dev)) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_INFO_HIGH,
			  "Force assert triggered");
		return QDF_STATUS_SUCCESS;
	}

	QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
		  "Self Recovery not supported via Platform driver assert");

	cds_set_recovery_in_progress(false);

	if (!cds_is_fw_down())
		QDF_BUG(0);

	return QDF_STATUS_E_INVAL;
}

#else
static QDF_STATUS cds_force_assert_target(qdf_device_t qdf_ctx)
=======
	struct hdd_context *hdd_ctx;

	hdd_ctx = gp_cds_context->hdd_context;
	if ((!hdd_ctx) || (!hdd_ctx->config)) {
		cds_alert("Hdd Context is Null");
		return false;
	}
	return hdd_ctx->config->enable_packet_log;
}
#endif

static int cds_force_assert_target_via_pld(qdf_device_t qdf)
{
	int errno;

	errno = pld_force_assert_target(qdf->dev);
	if (errno == -EOPNOTSUPP)
		cds_info("PLD does not support target force assert");
	else if (errno)
		cds_err("Failed PLD target force assert; errno %d", errno);
	else
		cds_info("Target force assert triggered via PLD");

	return errno;
}

static QDF_STATUS cds_force_assert_target_via_wmi(qdf_device_t qdf)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	QDF_STATUS status;
	t_wma_handle *wma;

	wma = cds_get_context(QDF_MODULE_ID_WMA);
	if (!wma) {
		cds_err("wma is null");
		return QDF_STATUS_E_INVAL;
	}

<<<<<<< HEAD
	/* attempt to send crash inject (assert) to firmware */
	status = wma_crash_inject(wma, RECOVERY_SIM_SELF_RECOVERY, 0);
	if (QDF_IS_STATUS_ERROR(status)) {
		cds_err("Failed target force assert; status:%d", status);
		goto schedule_recovery;
	}

	/* wait for firmware assert to trigger a recovery event */
	status = qdf_wait_for_event_completion(&wma->recovery_event,
				       WMA_CRASH_INJECT_TIMEOUT);
	if (QDF_IS_STATUS_ERROR(status)) {
		cds_err("Failed target force assert wait; status:%d", status);
		goto schedule_recovery;
	}

	return QDF_STATUS_SUCCESS;

schedule_recovery:
	/* if all else fails, try recovery without the firmware assert */
	cds_err("Scheduling recovery work without firmware assert");
	cds_set_recovery_in_progress(true);
	pld_schedule_recovery_work(qdf_ctx->dev);

	return status;
}
#endif

/**
 * cds_trigger_recovery_work() - trigger self recovery work
 *
 * Return: none
 */
static void cds_trigger_recovery_work(void *param)
{
	QDF_STATUS status;
	struct qdf_runtime_lock recovery_lock;
	qdf_device_t qdf_ctx;

	if (cds_is_driver_recovering()) {
		cds_err("Recovery in progress; ignoring recovery trigger");
=======
	status = wma_crash_inject(wma, RECOVERY_SIM_SELF_RECOVERY, 0);
	if (QDF_IS_STATUS_ERROR(status)) {
		cds_err("Failed target force assert; status %d", status);
		return status;
	}

	status = qdf_wait_for_event_completion(&wma->recovery_event,
				       WMA_CRASH_INJECT_TIMEOUT);
	if (QDF_IS_STATUS_ERROR(status)) {
		cds_err("Failed target force assert wait; status %d", status);
		return status;
	}

	return QDF_STATUS_SUCCESS;
}

/**
 * cds_force_assert_target() - Send assert command to firmware
 * @qdf: QDF device instance to assert
 *
 * An out-of-band recovery mechanism will cleanup and restart the entire wlan
 * subsystem in the event of a firmware crash. This API injects a firmware
 * crash to start this process when the wlan driver is known to be in a bad
 * state. If a firmware assert inject fails, the wlan driver will schedule
 * the driver recovery anyway, as a best effort attempt to return to a working
 * state.
 *
 * Return: QDF_STATUS
 */
static QDF_STATUS cds_force_assert_target(qdf_device_t qdf)
{
	int errno;
	QDF_STATUS status;

	/* first, try target assert inject via pld */
	errno = cds_force_assert_target_via_pld(qdf);
	if (!errno)
		return QDF_STATUS_SUCCESS;
	if (errno != -EOPNOTSUPP)
		return QDF_STATUS_E_FAILURE;

	/* pld assert is not supported, try target assert inject via wmi */
	status = cds_force_assert_target_via_wmi(qdf);
	if (QDF_IS_STATUS_SUCCESS(status))
		return QDF_STATUS_SUCCESS;

	/* wmi assert failed, start recovery without the firmware assert */
	cds_err("Scheduling recovery work without firmware assert");
	pld_schedule_recovery_work(qdf->dev, PLD_REASON_DEFAULT);

	return status;
}

/**
 * cds_trigger_recovery_handler() - handle a self recovery request
 * @func: the name of the function that called cds_trigger_recovery
 * @line: the line number of the call site which called cds_trigger_recovery
 *
 * Return: none
 */
static void cds_trigger_recovery_handler(const char *func, const uint32_t line)
{
	QDF_STATUS status;
	qdf_runtime_lock_t rtl;
	qdf_device_t qdf;

	/* NOTE! This code path is delicate! Think very carefully before
	 * modifying the content or order of the following. Please review any
	 * potential changes with someone closely familiar with this feature.
	 */

	if (cds_is_driver_recovering()) {
		cds_info("WLAN recovery already in progress");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return;
	}

	if (cds_is_driver_in_bad_state()) {
<<<<<<< HEAD
		cds_err("Driver is in bad state; ignoring recovery trigger");
=======
		cds_info("WLAN has already failed recovery");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return;
	}

	if (cds_is_fw_down()) {
<<<<<<< HEAD
		cds_err("firmware is down; ignoring recovery trigger");
		return;
	}

	if (!cds_is_self_recovery_enabled()) {
		cds_err("Recovery is not enabled");
		QDF_BUG(0);
		return;
	}

	qdf_ctx = cds_get_context(QDF_MODULE_ID_QDF_DEVICE);
	if (!qdf_ctx) {
		cds_err("qdf_ctx is null");
		return;
	}

	status = qdf_runtime_lock_init(&recovery_lock);
=======
		cds_info("Firmware has already initiated recovery");
		return;
	}

	qdf = cds_get_context(QDF_MODULE_ID_QDF_DEVICE);
	if (!qdf) {
		cds_err("Qdf context is null");
		return;
	}

	/* if *wlan* recovery is disabled, crash here for debugging */
	if (!cds_is_self_recovery_enabled()) {
		QDF_DEBUG_PANIC("WLAN recovery is not enabled (via %s:%d)",
				func, line);
		return;
	}

	/* ignore recovery if we are unloading; it would be a waste anyway */
	if (cds_is_driver_unloading()) {
		cds_info("WLAN is unloading; ignore recovery");
		return;
	}

	status = qdf_runtime_lock_init(&rtl);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	if (QDF_IS_STATUS_ERROR(status)) {
		cds_err("qdf_runtime_lock_init failed, status: %d", status);
		return;
	}

<<<<<<< HEAD
	qdf_runtime_pm_prevent_suspend(&recovery_lock);

	cds_force_assert_target(qdf_ctx);

	qdf_runtime_pm_allow_suspend(&recovery_lock);
	qdf_runtime_lock_deinit(&recovery_lock);
}

/**
 * cds_get_recovery_reason() - get self recovery reason
 * @reason: recovery reason
 *
 * Return: None
 */
void cds_get_recovery_reason(enum cds_hang_reason *reason)
{
	if (!gp_cds_context) {
		cds_err("gp_cds_context is null");
		return;
	}

	*reason = gp_cds_context->recovery_reason;
}

/**
 * cds_reset_recovery_reason() - reset the reason to unspecified
 *
 * Return: None
 */
void cds_reset_recovery_reason(void)
=======
	status = qdf_runtime_pm_prevent_suspend(&rtl);
	if (QDF_IS_STATUS_ERROR(status)) {
		cds_err("Failed to acquire runtime pm lock");
		goto deinit_rtl;
	}

	cds_set_recovery_in_progress(true);
	cds_force_assert_target(qdf);

	status = qdf_runtime_pm_allow_suspend(&rtl);
	if (QDF_IS_STATUS_ERROR(status))
		cds_err("Failed to release runtime pm lock");

deinit_rtl:
	qdf_runtime_lock_deinit(&rtl);
}

static void cds_trigger_recovery_work(void *context)
{
	struct cds_recovery_call_info *call_info = context;

	cds_trigger_recovery_handler(call_info->func, call_info->line);
}

void __cds_trigger_recovery(enum qdf_hang_reason reason, const char *func,
			    const uint32_t line)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	if (!gp_cds_context) {
		cds_err("gp_cds_context is null");
		return;
	}

<<<<<<< HEAD
	gp_cds_context->recovery_reason = CDS_REASON_UNSPECIFIED;
}

/**
 * cds_trigger_recovery() - trigger self recovery
 * @reason: recovery reason
 *
 * Return: none
 */
void cds_trigger_recovery(enum cds_hang_reason reason)
=======
	gp_cds_context->recovery_reason = reason;

	__cds_recovery_caller.func = func;
	__cds_recovery_caller.line = line;
	qdf_queue_work(0, gp_cds_context->cds_recovery_wq,
		       &gp_cds_context->cds_recovery_work);
}

void cds_trigger_recovery_psoc(void *psoc, enum qdf_hang_reason reason,
			       const char *func, const uint32_t line)
{
	__cds_trigger_recovery(reason, func, line);
}


/**
 * cds_get_recovery_reason() - get self recovery reason
 * @reason: recovery reason
 *
 * Return: None
 */
void cds_get_recovery_reason(enum qdf_hang_reason *reason)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	if (!gp_cds_context) {
		cds_err("gp_cds_context is null");
		return;
	}

<<<<<<< HEAD
	gp_cds_context->recovery_reason = reason;

	if (in_atomic()) {
		qdf_queue_work(0, gp_cds_context->cds_recovery_wq,
				&gp_cds_context->cds_recovery_work);
		return;
	}
	cds_trigger_recovery_work(NULL);
}

/**
 * cds_get_monotonic_boottime() - Get kernel boot time.
 *
 * Return: Time in microseconds
 */

uint64_t cds_get_monotonic_boottime(void)
{
	struct timespec ts;

	get_monotonic_boottime(&ts);
	return ((uint64_t) ts.tv_sec * 1000000) + (ts.tv_nsec / 1000);
=======
	*reason = gp_cds_context->recovery_reason;
}

/**
 * cds_reset_recovery_reason() - reset the reason to unspecified
 *
 * Return: None
 */
void cds_reset_recovery_reason(void)
{
	if (!gp_cds_context) {
		cds_err("gp_cds_context is null");
		return;
	}

	gp_cds_context->recovery_reason = QDF_REASON_UNSPECIFIED;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * cds_set_wakelock_logging() - Logging of wakelock enabled/disabled
 * @value: Boolean value
 *
 * This function is used to set the flag which will indicate whether
 * logging of wakelock is enabled or not
 *
 * Return: None
 */
void cds_set_wakelock_logging(bool value)
{
<<<<<<< HEAD
	p_cds_contextType p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
				"cds context is Invald");
=======
	struct cds_context *p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		cds_err("cds context is Invald");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return;
	}
	p_cds_context->is_wakelock_log_enabled = value;
}

/**
 * cds_is_wakelock_enabled() - Check if logging of wakelock is enabled/disabled
 * @value: Boolean value
 *
 * This function is used to check whether logging of wakelock is enabled or not
 *
 * Return: true if logging of wakelock is enabled
 */
bool cds_is_wakelock_enabled(void)
{
<<<<<<< HEAD
	p_cds_contextType p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
				"cds context is Invald");
=======
	struct cds_context *p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		cds_err("cds context is Invald");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return false;
	}
	return p_cds_context->is_wakelock_log_enabled;
}

/**
 * cds_set_ring_log_level() - Sets the log level of a particular ring
 * @ring_id: ring_id
 * @log_levelvalue: Log level specificed
 *
 * This function converts HLOS values to driver log levels and sets the log
 * level of a particular ring accordingly.
 *
 * Return: None
 */
void cds_set_ring_log_level(uint32_t ring_id, uint32_t log_level)
{
<<<<<<< HEAD
	p_cds_contextType p_cds_context;
=======
	struct cds_context *p_cds_context;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	uint32_t log_val;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
<<<<<<< HEAD
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
				"%s: cds context is Invald", __func__);
=======
		cds_err("cds context is Invald");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return;
	}

	switch (log_level) {
	case LOG_LEVEL_NO_COLLECTION:
		log_val = WLAN_LOG_LEVEL_OFF;
		break;
	case LOG_LEVEL_NORMAL_COLLECT:
		log_val = WLAN_LOG_LEVEL_NORMAL;
		break;
	case LOG_LEVEL_ISSUE_REPRO:
		log_val = WLAN_LOG_LEVEL_REPRO;
		break;
	case LOG_LEVEL_ACTIVE:
	default:
		log_val = WLAN_LOG_LEVEL_ACTIVE;
		break;
	}

	if (ring_id == RING_ID_WAKELOCK) {
		p_cds_context->wakelock_log_level = log_val;
		return;
	} else if (ring_id == RING_ID_CONNECTIVITY) {
		p_cds_context->connectivity_log_level = log_val;
		return;
	} else if (ring_id == RING_ID_PER_PACKET_STATS) {
		p_cds_context->packet_stats_log_level = log_val;
		return;
	} else if (ring_id == RING_ID_DRIVER_DEBUG) {
		p_cds_context->driver_debug_log_level = log_val;
		return;
	} else if (ring_id == RING_ID_FIRMWARE_DEBUG) {
		p_cds_context->fw_debug_log_level = log_val;
		return;
	}
}

/**
 * cds_get_ring_log_level() - Get the a ring id's log level
 * @ring_id: Ring id
 *
 * Fetch and return the log level corresponding to a ring id
 *
 * Return: Log level corresponding to the ring ID
 */
enum wifi_driver_log_level cds_get_ring_log_level(uint32_t ring_id)
{
<<<<<<< HEAD
	p_cds_contextType p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
				"%s: cds context is Invald", __func__);
=======
	struct cds_context *p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		cds_err("cds context is Invald");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return WLAN_LOG_LEVEL_OFF;
	}

	if (ring_id == RING_ID_WAKELOCK)
		return p_cds_context->wakelock_log_level;
	else if (ring_id == RING_ID_CONNECTIVITY)
		return p_cds_context->connectivity_log_level;
	else if (ring_id == RING_ID_PER_PACKET_STATS)
		return p_cds_context->packet_stats_log_level;
	else if (ring_id == RING_ID_DRIVER_DEBUG)
		return p_cds_context->driver_debug_log_level;
	else if (ring_id == RING_ID_FIRMWARE_DEBUG)
		return p_cds_context->fw_debug_log_level;

	return WLAN_LOG_LEVEL_OFF;
}

/**
 * cds_set_multicast_logging() - Set mutlicast logging value
 * @value: Value of multicast logging
 *
 * Set the multicast logging value which will indicate
 * whether to multicast host and fw messages even
 * without any registration by userspace entity
 *
 * Return: None
 */
void cds_set_multicast_logging(uint8_t value)
{
	cds_multicast_logging = value;
}

/**
 * cds_is_multicast_logging() - Get multicast logging value
 *
 * Get the multicast logging value which will indicate
 * whether to multicast host and fw messages even
 * without any registration by userspace entity
 *
 * Return: 0 - Multicast logging disabled, 1 - Multicast logging enabled
 */
uint8_t cds_is_multicast_logging(void)
{
	return cds_multicast_logging;
}

<<<<<<< HEAD
static void cds_reset_log_completion(p_cds_contextType p_cds_context)
{
	/* reset */
	p_cds_context->log_complete.indicator = WLAN_LOG_INDICATOR_UNUSED;
	p_cds_context->log_complete.is_fatal = WLAN_LOG_TYPE_NON_FATAL;
	p_cds_context->log_complete.is_report_in_progress = false;
	p_cds_context->log_complete.reason_code = WLAN_LOG_REASON_CODE_UNUSED;
	p_cds_context->log_complete.recovery_needed = false;

}
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/*
 * cds_init_log_completion() - Initialize log param structure
 *
 * This function is used to initialize the logging related
 * parameters
 *
 * Return: None
 */
void cds_init_log_completion(void)
{
<<<<<<< HEAD
	p_cds_contextType p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
				"%s: cds context is Invalid", __func__);
=======
	struct cds_context *p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		cds_err("cds context is Invalid");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return;
	}

	p_cds_context->log_complete.is_fatal = WLAN_LOG_TYPE_NON_FATAL;
	p_cds_context->log_complete.indicator = WLAN_LOG_INDICATOR_UNUSED;
	p_cds_context->log_complete.reason_code = WLAN_LOG_REASON_CODE_UNUSED;
	p_cds_context->log_complete.is_report_in_progress = false;
}

/**
 * cds_set_log_completion() - Store the logging params
 * @is_fatal: Indicates if the event triggering bug report is fatal or not
 * @indicator: Source which trigerred the bug report
 * @reason_code: Reason for triggering bug report
 * @recovery_needed: If recovery is needed after bug report
 *
 * This function is used to set the logging parameters based on the
 * caller
 *
 * Return: 0 if setting of params is successful
 */
QDF_STATUS cds_set_log_completion(uint32_t is_fatal,
		uint32_t indicator,
		uint32_t reason_code,
		bool recovery_needed)
{
<<<<<<< HEAD
	p_cds_contextType p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
				"%s: cds context is Invalid", __func__);
=======
	struct cds_context *p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		cds_err("cds context is Invalid");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return QDF_STATUS_E_FAILURE;
	}

	qdf_spinlock_acquire(&p_cds_context->bug_report_lock);
	p_cds_context->log_complete.is_fatal = is_fatal;
	p_cds_context->log_complete.indicator = indicator;
	p_cds_context->log_complete.reason_code = reason_code;
	p_cds_context->log_complete.recovery_needed = recovery_needed;
	p_cds_context->log_complete.is_report_in_progress = true;
	qdf_spinlock_release(&p_cds_context->bug_report_lock);
<<<<<<< HEAD
	QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_DEBUG,
		  "%s: is_fatal %d ind %d reasn_code %d recovery needed %d",
		   __func__, is_fatal, indicator, reason_code, recovery_needed);
=======
	cds_debug("is_fatal %d indicator %d reason_code %d recovery needed %d",
		  is_fatal, indicator, reason_code, recovery_needed);

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	return QDF_STATUS_SUCCESS;
}

/**
 * cds_get_and_reset_log_completion() - Get and reset logging related params
 * @is_fatal: Indicates if the event triggering bug report is fatal or not
 * @indicator: Source which trigerred the bug report
 * @reason_code: Reason for triggering bug report
 * @recovery_needed: If recovery is needed after bug report
 *
 * This function is used to get the logging related parameters
 *
 * Return: None
 */
void cds_get_and_reset_log_completion(uint32_t *is_fatal,
		uint32_t *indicator,
		uint32_t *reason_code,
		bool *recovery_needed)
{
<<<<<<< HEAD
	p_cds_contextType p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
				"%s: cds context is Invalid", __func__);
=======
	struct cds_context *p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		cds_err("cds context is Invalid");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return;
	}

	qdf_spinlock_acquire(&p_cds_context->bug_report_lock);
	*is_fatal =  p_cds_context->log_complete.is_fatal;
	*indicator = p_cds_context->log_complete.indicator;
	*reason_code = p_cds_context->log_complete.reason_code;
	*recovery_needed = p_cds_context->log_complete.recovery_needed;
<<<<<<< HEAD
	cds_reset_log_completion(p_cds_context);
	qdf_spinlock_release(&p_cds_context->bug_report_lock);

=======

	/* reset */
	p_cds_context->log_complete.indicator = WLAN_LOG_INDICATOR_UNUSED;
	p_cds_context->log_complete.is_fatal = WLAN_LOG_TYPE_NON_FATAL;
	p_cds_context->log_complete.is_report_in_progress = false;
	p_cds_context->log_complete.reason_code = WLAN_LOG_REASON_CODE_UNUSED;
	p_cds_context->log_complete.recovery_needed = false;
	qdf_spinlock_release(&p_cds_context->bug_report_lock);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * cds_is_log_report_in_progress() - Check if bug reporting is in progress
 *
 * This function is used to check if the bug reporting is already in progress
 *
 * Return: true if the bug reporting is in progress
 */
bool cds_is_log_report_in_progress(void)
{
<<<<<<< HEAD
	p_cds_contextType p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
				"%s: cds context is Invalid", __func__);
=======
	struct cds_context *p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		cds_err("cds context is Invalid");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return true;
	}
	return p_cds_context->log_complete.is_report_in_progress;
}

/**
 * cds_is_fatal_event_enabled() - Return if fatal event is enabled
 *
 * Return true if fatal event is enabled.
 */
bool cds_is_fatal_event_enabled(void)
{
<<<<<<< HEAD
	p_cds_contextType p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
				"%s: cds context is Invalid", __func__);
=======
	struct cds_context *p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		cds_err("cds context is Invalid");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return false;
	}


	return p_cds_context->enable_fatal_event;
}

#ifdef WLAN_FEATURE_TSF_PLUS
bool cds_is_ptp_rx_opt_enabled(void)
{
<<<<<<< HEAD
	hdd_context_t *hdd_ctx;
	p_cds_contextType p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: cds context is Invalid", __func__);
		return false;
	}

	hdd_ctx = (hdd_context_t *)(p_cds_context->pHDDContext);
	if ((NULL == hdd_ctx) || (NULL == hdd_ctx->config)) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: Hdd Context is Null", __func__);
		return false;
	}

	return HDD_TSF_IS_RX_SET(hdd_ctx);
=======
	struct hdd_context *hdd_ctx;
	struct cds_context *p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		cds_err("cds context is Invalid");
		return false;
	}

	hdd_ctx = (struct hdd_context *)(p_cds_context->hdd_context);
	if ((!hdd_ctx) || (!hdd_ctx->config)) {
		cds_err("Hdd Context is Null");
		return false;
	}

	return hdd_tsf_is_rx_set(hdd_ctx);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

bool cds_is_ptp_tx_opt_enabled(void)
{
<<<<<<< HEAD
	hdd_context_t *hdd_ctx;
	p_cds_contextType p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: cds context is Invalid", __func__);
		return false;
	}

	hdd_ctx = (hdd_context_t *)(p_cds_context->pHDDContext);
	if ((NULL == hdd_ctx) || (NULL == hdd_ctx->config)) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			  "%s: Hdd Context is Null", __func__);
		return false;
	}

	return HDD_TSF_IS_TX_SET(hdd_ctx);
=======
	struct hdd_context *hdd_ctx;
	struct cds_context *p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		cds_err("cds context is Invalid");
		return false;
	}

	hdd_ctx = (struct hdd_context *)(p_cds_context->hdd_context);
	if ((!hdd_ctx) || (!hdd_ctx->config)) {
		cds_err("Hdd Context is Null");
		return false;
	}

	return hdd_tsf_is_tx_set(hdd_ctx);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}
#endif

/**
 * cds_get_log_indicator() - Get the log flush indicator
 *
 * This function is used to get the log flush indicator
 *
 * Return: log indicator
 */
uint32_t cds_get_log_indicator(void)
{
<<<<<<< HEAD
	p_cds_contextType p_cds_context;
=======
	struct cds_context *p_cds_context;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	uint32_t indicator;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
<<<<<<< HEAD
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
				"%s: cds context is Invalid", __func__);
=======
		cds_err("cds context is Invalid");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return WLAN_LOG_INDICATOR_UNUSED;
	}

	if (cds_is_load_or_unload_in_progress() ||
	    cds_is_driver_recovering() || cds_is_driver_in_bad_state()) {
		return WLAN_LOG_INDICATOR_UNUSED;
	}

	qdf_spinlock_acquire(&p_cds_context->bug_report_lock);
	indicator = p_cds_context->log_complete.indicator;
	qdf_spinlock_release(&p_cds_context->bug_report_lock);
	return indicator;
}

/**
 * cds_wlan_flush_host_logs_for_fatal() - Wrapper to flush host logs
 *
 * This function is used to send signal to the logger thread to
 * flush the host logs.
 *
 * Return: None
 *
 */
void cds_wlan_flush_host_logs_for_fatal(void)
{
<<<<<<< HEAD
	wlan_flush_host_logs_for_fatal();
=======
	if (cds_is_log_report_in_progress())
		wlan_flush_host_logs_for_fatal();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * cds_flush_logs() - Report fatal event to userspace
 * @is_fatal: Indicates if the event triggering bug report is fatal or not
 * @indicator: Source which trigerred the bug report
 * @reason_code: Reason for triggering bug report
 * @dump_mac_trace: If mac trace are needed in logs.
 * @recovery_needed: If recovery is needed after bug report
 *
 * This function sets the log related params and send the WMI command to the
 * FW to flush its logs. On receiving the flush completion event from the FW
 * the same will be conveyed to userspace
 *
 * Return: 0 on success
 */
QDF_STATUS cds_flush_logs(uint32_t is_fatal,
		uint32_t indicator,
		uint32_t reason_code,
		bool dump_mac_trace,
		bool recovery_needed)
{
<<<<<<< HEAD
	uint32_t ret;
	QDF_STATUS status;

	p_cds_contextType p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
				"%s: cds context is Invalid", __func__);
		return QDF_STATUS_E_FAILURE;
	}
	if (!p_cds_context->enable_fatal_event) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
				"%s: Fatal event not enabled", __func__);
=======
	QDF_STATUS status;

	struct cds_context *p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		cds_err("cds context is Invalid");
		return QDF_STATUS_E_FAILURE;
	}
	if (!p_cds_context->enable_fatal_event) {
		cds_err("Fatal event not enabled");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return QDF_STATUS_E_FAILURE;
	}
	if (cds_is_load_or_unload_in_progress() ||
	    cds_is_driver_recovering() || cds_is_driver_in_bad_state()) {
<<<<<<< HEAD
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
				"%s: un/Load/SSR in progress", __func__);
		return QDF_STATUS_E_FAILURE;
	}

	if (cds_is_log_report_in_progress() == true) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
				"%s: Bug report already in progress - dropping! type:%d, indicator=%d reason_code=%d",
				__func__, is_fatal, indicator, reason_code);
=======
		cds_err("un/Load/SSR in progress");
		return QDF_STATUS_E_FAILURE;
	}

	if (cds_is_log_report_in_progress()) {
		cds_err("Bug report already in progress - dropping! type:%d, indicator=%d reason_code=%d",
			is_fatal, indicator, reason_code);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return QDF_STATUS_E_FAILURE;
	}

	status = cds_set_log_completion(is_fatal, indicator,
		reason_code, recovery_needed);
	if (QDF_STATUS_SUCCESS != status) {
<<<<<<< HEAD
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
			"%s: Failed to set log trigger params", __func__);
		return QDF_STATUS_E_FAILURE;
	}

	QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_INFO,
			"%s: Triggering bug report: type:%d, indicator=%d reason_code=%d",
			__func__, is_fatal, indicator, reason_code);

	if (dump_mac_trace)
		qdf_trace_dump_all(p_cds_context->pMACContext, 0, 0, 500, 0);
=======
		cds_err("Failed to set log trigger params");
		return QDF_STATUS_E_FAILURE;
	}

	cds_debug("Triggering bug report: type:%d, indicator=%d reason_code=%d",
		  is_fatal, indicator, reason_code);

	if (dump_mac_trace)
		qdf_trace_dump_all(p_cds_context->mac_context, 0, 0, 100, 0);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	if (WLAN_LOG_INDICATOR_HOST_ONLY == indicator) {
		cds_wlan_flush_host_logs_for_fatal();
		return QDF_STATUS_SUCCESS;
	}

<<<<<<< HEAD
	ret = sme_send_flush_logs_cmd_to_fw(p_cds_context->pMACContext);
	if (0 != ret) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
				"%s: Failed to send flush FW log", __func__);
		cds_reset_log_completion(p_cds_context);
=======
	status = sme_send_flush_logs_cmd_to_fw();
	if (QDF_IS_STATUS_ERROR(status)) {
		cds_err("Failed to send flush FW log");
		cds_init_log_completion();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return QDF_STATUS_E_FAILURE;
	}

	return QDF_STATUS_SUCCESS;
}

/**
 * cds_logging_set_fw_flush_complete() - Wrapper for FW log flush completion
 *
 * This function is used to send signal to the logger thread to indicate
 * that the flushing of FW logs is complete by the FW
 *
 * Return: None
 *
 */
void cds_logging_set_fw_flush_complete(void)
{
<<<<<<< HEAD
	wlan_logging_set_fw_flush_complete();
=======
	if (cds_is_fatal_event_enabled())
		wlan_logging_set_fw_flush_complete();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * cds_set_fatal_event() - set fatal event status
 * @value: pending statue to set
 *
 * Return: None
 */
void cds_set_fatal_event(bool value)
{
<<<<<<< HEAD
	p_cds_contextType p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		QDF_TRACE(QDF_MODULE_ID_QDF, QDF_TRACE_LEVEL_ERROR,
				"%s: cds context is Invalid", __func__);
=======
	struct cds_context *p_cds_context;

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		cds_err("cds context is Invalid");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return;
	}
	p_cds_context->enable_fatal_event = value;
}

/**
 * cds_get_radio_index() - get radio index
 *
 * Return: radio index otherwise, -EINVAL
 */
int cds_get_radio_index(void)
{
<<<<<<< HEAD
	p_cds_contextType p_cds_context;
=======
	struct cds_context *p_cds_context;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		/*
		 * To avoid recursive call, this should not change to
		 * QDF_TRACE().
		 */
		pr_err("%s: cds context is invalid\n", __func__);
		return -EINVAL;
	}

	return p_cds_context->radio_index;
}

/**
 * cds_set_radio_index() - set radio index
 * @radio_index:	the radio index to set
 *
 * Return: QDF status
 */
QDF_STATUS cds_set_radio_index(int radio_index)
{
<<<<<<< HEAD
	p_cds_contextType p_cds_context;
=======
	struct cds_context *p_cds_context;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		pr_err("%s: cds context is invalid\n", __func__);
		return QDF_STATUS_E_FAILURE;
	}

	p_cds_context->radio_index = radio_index;

	return QDF_STATUS_SUCCESS;
}

/**
 * cds_init_ini_config() - API to initialize CDS configuration parameters
 * @cfg: CDS Configuration
 *
 * Return: void
 */

void cds_init_ini_config(struct cds_config_info *cfg)
{
<<<<<<< HEAD
	cds_context_type *cds_ctx;
=======
	struct cds_context *cds_ctx;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	cds_ctx = cds_get_context(QDF_MODULE_ID_QDF);
	if (!cds_ctx) {
		cds_err("Invalid CDS Context");
		return;
	}

	cds_ctx->cds_cfg = cfg;
}

/**
 * cds_deinit_ini_config() - API to free CDS configuration parameters
 *
 * Return: void
 */
void cds_deinit_ini_config(void)
{
<<<<<<< HEAD
	cds_context_type *cds_ctx;
=======
	struct cds_context *cds_ctx;
	struct cds_config_info *cds_cfg;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	cds_ctx = cds_get_context(QDF_MODULE_ID_QDF);
	if (!cds_ctx) {
		cds_err("Invalid CDS Context");
		return;
	}

<<<<<<< HEAD
	if (cds_ctx->cds_cfg)
		qdf_mem_free(cds_ctx->cds_cfg);

	cds_ctx->cds_cfg = NULL;
=======
	cds_cfg = cds_ctx->cds_cfg;
	cds_ctx->cds_cfg = NULL;

	if (cds_cfg)
		qdf_mem_free(cds_cfg);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * cds_get_ini_config() - API to get CDS configuration parameters
 *
 * Return: cds config structure
 */
struct cds_config_info *cds_get_ini_config(void)
{
<<<<<<< HEAD
	cds_context_type *cds_ctx;
=======
	struct cds_context *cds_ctx;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	cds_ctx = cds_get_context(QDF_MODULE_ID_QDF);
	if (!cds_ctx) {
		cds_err("Invalid CDS Context");
		return NULL;
	}

	return cds_ctx->cds_cfg;
}

/**
 * cds_is_5_mhz_enabled() - API to get 5MHZ enabled
 *
 * Return: true if 5 mhz is enabled, false otherwise
 */
bool cds_is_5_mhz_enabled(void)
{
<<<<<<< HEAD
	p_cds_contextType p_cds_context;
=======
	struct cds_context *p_cds_context;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	p_cds_context = cds_get_context(QDF_MODULE_ID_QDF);
	if (!p_cds_context) {
		cds_err("%s: cds context is invalid", __func__);
		return false;
	}

	if (p_cds_context->cds_cfg)
		return (p_cds_context->cds_cfg->sub_20_channel_width ==
						WLAN_SUB_20_CH_WIDTH_5);

	return false;
}

/**
 * cds_is_10_mhz_enabled() - API to get 10-MHZ enabled
 *
 * Return: true if 10 mhz is enabled, false otherwise
 */
bool cds_is_10_mhz_enabled(void)
{
<<<<<<< HEAD
	p_cds_contextType p_cds_context;
=======
	struct cds_context *p_cds_context;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	p_cds_context = cds_get_context(QDF_MODULE_ID_QDF);
	if (!p_cds_context) {
		cds_err("%s: cds context is invalid", __func__);
		return false;
	}

	if (p_cds_context->cds_cfg)
		return (p_cds_context->cds_cfg->sub_20_channel_width ==
						WLAN_SUB_20_CH_WIDTH_10);

	return false;
}

/**
 * cds_is_sub_20_mhz_enabled() - API to get sub 20-MHZ enabled
 *
 * Return: true if 5 or 10 mhz is enabled, false otherwise
 */
bool cds_is_sub_20_mhz_enabled(void)
{
<<<<<<< HEAD
	p_cds_contextType p_cds_context;
=======
	struct cds_context *p_cds_context;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	p_cds_context = cds_get_context(QDF_MODULE_ID_QDF);
	if (!p_cds_context) {
		cds_err("%s: cds context is invalid", __func__);
		return false;
	}

	if (p_cds_context->cds_cfg)
		return p_cds_context->cds_cfg->sub_20_channel_width;

	return false;
}

/**
 * cds_is_self_recovery_enabled() - API to get self recovery enabled
 *
 * Return: true if self recovery enabled, false otherwise
 */
bool cds_is_self_recovery_enabled(void)
{
<<<<<<< HEAD
	p_cds_contextType p_cds_context;
=======
	struct cds_context *p_cds_context;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	p_cds_context = cds_get_context(QDF_MODULE_ID_QDF);
	if (!p_cds_context) {
		cds_err("%s: cds context is invalid", __func__);
		return false;
	}

	if (p_cds_context->cds_cfg)
		return p_cds_context->cds_cfg->self_recovery_enabled;

	return false;
}

/**
<<<<<<< HEAD
=======
 * cds_is_fw_down() - Is FW down or not
 *
 * Return: true if FW is down and false otherwise.
 */
bool cds_is_fw_down(void)
{
	qdf_device_t qdf_ctx;

	qdf_ctx = cds_get_context(QDF_MODULE_ID_QDF_DEVICE);
	if (!qdf_ctx) {
		cds_err("cds context is invalid");
		return false;
	}

	return pld_is_fw_down(qdf_ctx->dev);
}

/**
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * cds_svc_fw_shutdown_ind() - API to send userspace about FW crash
 *
 * @dev: Device Pointer
 *
 * Return: None
 */
void cds_svc_fw_shutdown_ind(struct device *dev)
{
	hdd_svc_fw_shutdown_ind(dev);
}

<<<<<<< HEAD
=======
#ifdef WLAN_LOGGING_SOCK_SVC_ENABLE
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/*
 * cds_pkt_stats_to_logger_thread() - send pktstats to user
 * @pl_hdr: Pointer to pl_hdr
 * @pkt_dump: Pointer to pkt_dump data structure.
 * @data: Pointer to data
 *
 * This function is used to send the pkt stats to SVC module.
 *
 * Return: None
 */
inline void cds_pkt_stats_to_logger_thread(void *pl_hdr, void *pkt_dump,
						void *data)
{
	if (cds_get_ring_log_level(RING_ID_PER_PACKET_STATS) !=
						WLAN_LOG_LEVEL_ACTIVE)
		return;

	wlan_pkt_stats_to_logger_thread(pl_hdr, pkt_dump, data);
}
<<<<<<< HEAD

/**
 * cds_register_dp_cb() - Register datapath callbacks with CDS
 * @dp_cbs: pointer to cds_dp_cbacks structure
 *
 * Return: QDF_STATUS
 */
QDF_STATUS cds_register_dp_cb(struct cds_dp_cbacks *dp_cbs)
{
	p_cds_contextType cds_ctx;

	cds_ctx = cds_get_global_context();
	if (!cds_ctx) {
		cds_err("Invalid CDS context");
		return QDF_STATUS_E_FAILURE;
	}

	cds_ctx->ol_txrx_update_mac_id_cb = dp_cbs->ol_txrx_update_mac_id_cb;
	cds_ctx->hdd_en_lro_in_cc_cb = dp_cbs->hdd_en_lro_in_cc_cb;
	cds_ctx->hdd_disable_lro_in_cc_cb = dp_cbs->hdd_disble_lro_in_cc_cb;
	cds_ctx->hdd_set_rx_mode_rps_cb = dp_cbs->hdd_set_rx_mode_rps_cb;
	cds_ctx->hdd_ipa_set_mcc_mode_cb = dp_cbs->hdd_ipa_set_mcc_mode_cb;
	return QDF_STATUS_SUCCESS;
}

/**
 * cds_deregister_dp_cb() - Deregister datapath callbacks with CDS
 * @dp_cbs: pointer to cds_dp_cbacks structure
 *
 * Return: QDF_STATUS
 */
QDF_STATUS cds_deregister_dp_cb(void)

{
	p_cds_contextType cds_ctx;

	cds_ctx = cds_get_global_context();
	if (!cds_ctx) {
		cds_err("Invalid CDS context");
		return QDF_STATUS_E_FAILURE;
	}

	cds_ctx->ol_txrx_update_mac_id_cb = NULL;
	cds_ctx->hdd_en_lro_in_cc_cb = NULL;
	cds_ctx->hdd_disable_lro_in_cc_cb = NULL;
	cds_ctx->hdd_set_rx_mode_rps_cb = NULL;
	cds_ctx->hdd_ipa_set_mcc_mode_cb = NULL;

	return QDF_STATUS_SUCCESS;
}

uint32_t cds_get_connectivity_stats_pkt_bitmap(void *context)
{
	hdd_adapter_t *adapter = NULL;
=======
#endif

/**
 * cds_get_conparam() - Get the connection mode parameters
 *
 * Return the connection mode parameter set by insmod or set during statically
 * linked driver
 *
 * Return: enum QDF_GLOBAL_MODE
 */
enum QDF_GLOBAL_MODE cds_get_conparam(void)
{
	enum QDF_GLOBAL_MODE con_mode;

	con_mode = hdd_get_conparam();

	return con_mode;
}

#ifdef FEATURE_HTC_CREDIT_HISTORY
inline void
cds_print_htc_credit_history(uint32_t count, qdf_abstract_print *print,
			     void *print_priv)
{
	htc_print_credit_history(gp_cds_context->htc_ctx, count,
				 print, print_priv);
}
#endif

uint32_t cds_get_connectivity_stats_pkt_bitmap(void *context)
{
	struct hdd_adapter *adapter = NULL;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	if (!context)
		return 0;

<<<<<<< HEAD
	adapter = (hdd_adapter_t *)context;
	if (unlikely(adapter->magic != WLAN_HDD_ADAPTER_MAGIC)) {
		QDF_TRACE(QDF_MODULE_ID_HDD_DATA, QDF_TRACE_LEVEL_ERROR,
			  "Magic cookie(%x) for adapter sanity verification is invalid",
			  adapter->magic);
=======
	adapter = (struct hdd_adapter *)context;
	if (unlikely(adapter->magic != WLAN_HDD_ADAPTER_MAGIC)) {
		cds_err("Magic cookie(%x) for adapter sanity verification is invalid",
			adapter->magic);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return 0;
	}
	return adapter->pkt_type_bitmap;
}

/**
 * cds_get_arp_stats_gw_ip() - get arp stats track IP
 *
 * Return: ARP stats IP to track
 */
uint32_t cds_get_arp_stats_gw_ip(void *context)
{
<<<<<<< HEAD
	hdd_adapter_t *adapter = NULL;
=======
	struct hdd_adapter *adapter = NULL;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	if (!context)
		return 0;

<<<<<<< HEAD
	adapter = (hdd_adapter_t *)context;

	if (unlikely(adapter->magic != WLAN_HDD_ADAPTER_MAGIC)) {
		QDF_TRACE(QDF_MODULE_ID_HDD_DATA, QDF_TRACE_LEVEL_ERROR,
			  "Magic cookie(%x) for adapter sanity verification is invalid",
			  adapter->magic);
=======
	adapter = (struct hdd_adapter *)context;

	if (unlikely(adapter->magic != WLAN_HDD_ADAPTER_MAGIC)) {
		cds_err("Magic cookie(%x) for adapter sanity verification is invalid",
			adapter->magic);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return 0;
	}

	return adapter->track_arp_ip;
}

/**
 * cds_incr_arp_stats_tx_tgt_delivered() - increment ARP stats
 *
 * Return: none
 */
void cds_incr_arp_stats_tx_tgt_delivered(void)
{
<<<<<<< HEAD
	hdd_context_t *hdd_ctx;
	hdd_adapter_list_node_t *adapter_node = NULL, *next = NULL;
	hdd_adapter_t *adapter = NULL;
	QDF_STATUS status;

	hdd_ctx = (hdd_context_t *) (gp_cds_context->pHDDContext);
=======
	struct hdd_context *hdd_ctx;
	struct hdd_adapter *adapter, *next_adapter = NULL;
	wlan_net_dev_ref_dbgid dbgid =
			NET_DEV_HOLD_CDS_INCR_ARP_STATS_TX_TGT_DELIVERED;

	hdd_ctx = gp_cds_context->hdd_context;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	if (!hdd_ctx) {
		cds_err("Hdd Context is Null");
		return;
	}

<<<<<<< HEAD
	status = hdd_get_front_adapter(hdd_ctx, &adapter_node);

	while (NULL != adapter_node && QDF_STATUS_SUCCESS == status) {
		adapter = adapter_node->pAdapter;

		if (QDF_STA_MODE == adapter->device_mode)
			break;

		status = hdd_get_next_adapter(hdd_ctx, adapter_node, &next);
		adapter_node = next;
=======
	hdd_for_each_adapter_dev_held_safe(hdd_ctx, adapter, next_adapter,
					   dbgid) {
		if (adapter->device_mode == QDF_STA_MODE) {
			hdd_adapter_dev_put_debug(adapter, dbgid);
			if (next_adapter)
				hdd_adapter_dev_put_debug(next_adapter, dbgid);
			break;
		}
		hdd_adapter_dev_put_debug(adapter, dbgid);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	}

	if (adapter)
		adapter->hdd_stats.hdd_arp_stats.tx_host_fw_sent++;
}

/**
 * cds_incr_arp_stats_tx_tgt_acked() - increment ARP stats
 *
 * Return: none
 */
void cds_incr_arp_stats_tx_tgt_acked(void)
{
<<<<<<< HEAD
	hdd_context_t *hdd_ctx;
	hdd_adapter_list_node_t *adapter_node = NULL, *next = NULL;
	hdd_adapter_t *adapter = NULL;
	QDF_STATUS status;

	hdd_ctx = (hdd_context_t *) (gp_cds_context->pHDDContext);
=======
	struct hdd_context *hdd_ctx;
	struct hdd_adapter *adapter, *next_adapter = NULL;
	wlan_net_dev_ref_dbgid dbgid =
			NET_DEV_HOLD_CDS_INCR_ARP_STATS_TX_TGT_ACKED;

	hdd_ctx = gp_cds_context->hdd_context;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	if (!hdd_ctx) {
		cds_err("Hdd Context is Null");
		return;
	}

<<<<<<< HEAD
	status = hdd_get_front_adapter(hdd_ctx, &adapter_node);

	while (NULL != adapter_node && QDF_STATUS_SUCCESS == status) {
		adapter = adapter_node->pAdapter;

		if (QDF_STA_MODE == adapter->device_mode)
			break;

		status = hdd_get_next_adapter(hdd_ctx, adapter_node, &next);
		adapter_node = next;
=======
	hdd_for_each_adapter_dev_held_safe(hdd_ctx, adapter, next_adapter,
					   dbgid) {
		if (adapter->device_mode == QDF_STA_MODE) {
			hdd_adapter_dev_put_debug(adapter, dbgid);
			if (next_adapter)
				hdd_adapter_dev_put_debug(next_adapter, dbgid);
			break;
		}
		hdd_adapter_dev_put_debug(adapter, dbgid);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	}

	if (adapter)
		adapter->hdd_stats.hdd_arp_stats.tx_ack_cnt++;
}

<<<<<<< HEAD
#ifdef WMI_INTERFACE_EVENT_LOGGING
inline void
cds_print_htc_credit_history(uint32_t count, qdf_abstract_print *print,
			     void *print_priv)
{
	htc_print_credit_history(gp_cds_context->htc_ctx, count,
				 print, print_priv);
=======
#ifdef FEATURE_ALIGN_STATS_FROM_DP
/**
 * cds_get_cdp_vdev_stats() - Function which retrieves cdp vdev stats
 * @vdev_id: vdev id
 * @vdev_stats: cdp vdev stats retrieves from DP
 *
 * Return: If get cdp vdev stats success return true, otherwise return false
 */
static bool
cds_get_cdp_vdev_stats(uint8_t vdev_id, struct cdp_vdev_stats *vdev_stats)
{
	void *soc = cds_get_context(QDF_MODULE_ID_SOC);

	if (!vdev_stats)
		return false;

	if (cdp_host_get_vdev_stats(soc, vdev_id, vdev_stats, true))
		return false;

	return true;
}

bool
cds_dp_get_vdev_stats(uint8_t vdev_id, struct cds_vdev_dp_stats *stats)
{
	struct cdp_vdev_stats *vdev_stats;
	bool ret = false;

	vdev_stats = qdf_mem_malloc(sizeof(*vdev_stats));
	if (!vdev_stats)
		return false;

	if (cds_get_cdp_vdev_stats(vdev_id, vdev_stats)) {
		stats->tx_retries = vdev_stats->tx.retries;
		ret = true;
	}

	qdf_mem_free(vdev_stats);
	return ret;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}
#endif

#ifdef ENABLE_SMMU_S1_TRANSLATION
<<<<<<< HEAD
QDF_STATUS cds_smmu_mem_map_setup(qdf_device_t osdev, bool ipa_present)
{
	int attr = 0;
	bool ipa_smmu_enable = false;
	struct dma_iommu_mapping *mapping = pld_smmu_get_mapping(osdev->dev);

	osdev->smmu_s1_enabled = false;

	if (ipa_present) {
		ipa_smmu_enable = qdf_get_ipa_smmu_status();
		if (ipa_smmu_enable)
			cds_info("SMMU enabled from IPA side");
		else
			cds_info("SMMU not enabled from IPA side");
	}

	if (mapping && ((iommu_domain_get_attr(mapping->domain,
			 DOMAIN_ATTR_S1_BYPASS, &attr) == 0) &&
			 !attr)) {
		cds_info("SMMU enabled from WLAN side");

		if (ipa_present) {
			if (ipa_smmu_enable) {
				cds_info("SMMU enabled from both IPA and WLAN side");
				osdev->smmu_s1_enabled = true;
			} else {
				cds_err("SMMU mismatch: IPA: disable, WLAN: enable");
				return QDF_STATUS_E_FAILURE;
			}
		} else {
			osdev->smmu_s1_enabled = true;
		}

	} else {
		cds_info("No SMMU mapping present or SMMU disabled from WLAN side");

		if (ipa_present) {
			if (ipa_smmu_enable) {
				cds_err("SMMU mismatch: IPA: enable, WLAN: disable");
				return QDF_STATUS_E_FAILURE;
			} else {
				cds_info("SMMU diabled from both IPA and WLAN side");
			}
		}
	}

	return QDF_STATUS_SUCCESS;
}
=======
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0))
QDF_STATUS cds_smmu_mem_map_setup(qdf_device_t osdev, bool ipa_present)
{
	struct iommu_domain *domain;
	bool ipa_smmu_enabled;
	bool wlan_smmu_enabled;

	domain = pld_smmu_get_domain(osdev->dev);
	if (domain) {
		int attr = 0;
		int errno = iommu_domain_get_attr(domain,
						  DOMAIN_ATTR_S1_BYPASS, &attr);

		wlan_smmu_enabled = !errno && !attr;
	} else {
		cds_info("No SMMU mapping present");
		wlan_smmu_enabled = false;
	}

	if (!wlan_smmu_enabled) {
		osdev->smmu_s1_enabled = false;
		goto exit_with_success;
	}

	if (!ipa_present) {
		osdev->smmu_s1_enabled = true;
		goto exit_with_success;
	}

	ipa_smmu_enabled = qdf_get_ipa_smmu_enabled();

	osdev->smmu_s1_enabled = ipa_smmu_enabled && wlan_smmu_enabled;
	if (ipa_smmu_enabled != wlan_smmu_enabled) {
		cds_err("SMMU mismatch; IPA:%s, WLAN:%s",
			ipa_smmu_enabled ? "enabled" : "disabled",
			wlan_smmu_enabled ? "enabled" : "disabled");
		return QDF_STATUS_E_FAILURE;
	}

exit_with_success:
	osdev->domain = domain;

	cds_info("SMMU S1 %s", osdev->smmu_s1_enabled ? "enabled" : "disabled");

	return QDF_STATUS_SUCCESS;
}

#else
QDF_STATUS cds_smmu_mem_map_setup(qdf_device_t osdev, bool ipa_present)
{
	struct dma_iommu_mapping *mapping;
	bool ipa_smmu_enabled;
	bool wlan_smmu_enabled;

	mapping = pld_smmu_get_mapping(osdev->dev);
	if (mapping) {
		int attr = 0;
		int errno = iommu_domain_get_attr(mapping->domain,
						  DOMAIN_ATTR_S1_BYPASS, &attr);

		wlan_smmu_enabled = !errno && !attr;
	} else {
		cds_info("No SMMU mapping present");
		wlan_smmu_enabled = false;
	}

	if (!wlan_smmu_enabled) {
		osdev->smmu_s1_enabled = false;
		goto exit_with_success;
	}

	if (!ipa_present) {
		osdev->smmu_s1_enabled = true;
		goto exit_with_success;
	}

	ipa_smmu_enabled = qdf_get_ipa_smmu_enabled();

	osdev->smmu_s1_enabled = ipa_smmu_enabled && wlan_smmu_enabled;
	if (ipa_smmu_enabled != wlan_smmu_enabled) {
		cds_err("SMMU mismatch; IPA:%s, WLAN:%s",
			ipa_smmu_enabled ? "enabled" : "disabled",
			wlan_smmu_enabled ? "enabled" : "disabled");
		return QDF_STATUS_E_FAILURE;
	}

exit_with_success:
	osdev->iommu_mapping = mapping;

	cds_info("SMMU S1 %s", osdev->smmu_s1_enabled ? "enabled" : "disabled");

	return QDF_STATUS_SUCCESS;
}
#endif
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

#ifdef IPA_OFFLOAD
int cds_smmu_map_unmap(bool map, uint32_t num_buf, qdf_mem_info_t *buf_arr)
{
<<<<<<< HEAD
	return hdd_ipa_uc_smmu_map(map, num_buf, buf_arr);
=======
	return ucfg_ipa_uc_smmu_map(map, num_buf, buf_arr);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}
#else
int cds_smmu_map_unmap(bool map, uint32_t num_buf, qdf_mem_info_t *buf_arr)
{
	return 0;
}
#endif

#else
<<<<<<< HEAD
QDF_STATUS cds_smmu_mem_map_setup(qdf_device_t osdev, bool ipa_present)
{
	osdev->smmu_s1_enabled = false;
	return QDF_STATUS_SUCCESS;
}

int cds_smmu_map_unmap(bool map, uint32_t num_buf, qdf_mem_info_t *buf_arr)
{
	return 0;
}
#endif

uint32_t cds_get_mcc_to_scc_switch_mode(void)
{
	hdd_context_t *hdd_ctx;

	hdd_ctx = cds_get_context(QDF_MODULE_ID_HDD);
	if (!hdd_ctx) {
		cds_err("HDD context is NULL");
		return false;
	}

	return hdd_ctx->config->WlanMccToSccSwitchMode;
}

bool cds_is_sta_sap_scc_allowed_on_dfs_channel(void)
{
	hdd_context_t *hdd_ctx;
	bool ret = false;

	hdd_ctx = cds_get_context(QDF_MODULE_ID_HDD);

	if (!hdd_ctx) {
		cds_err("HDD context is NULL");
		return false;
	}

	if ((hdd_ctx->config->WlanMccToSccSwitchMode !=
				QDF_MCC_TO_SCC_SWITCH_DISABLE) &&
			(hdd_ctx->config->sta_sap_scc_on_dfs_chan))
		ret = true;

	return ret;
}

QDF_STATUS cds_register_mode_change_cb(send_mode_change_event_cb callback)
{
	p_cds_contextType cds_ctx;

	cds_ctx = cds_get_global_context();
	if (!cds_ctx) {
		cds_err("Invalid CDS context");
		return QDF_STATUS_E_FAILURE;
	}

	cds_ctx->mode_change_cb = callback;

	return QDF_STATUS_SUCCESS;
}

QDF_STATUS cds_deregister_mode_change_cb(void)
{
	p_cds_contextType cds_ctx;

	cds_ctx = cds_get_global_context();
	if (!cds_ctx) {
		cds_err("Invalid CDS context");
		return QDF_STATUS_E_FAILURE;
	}

	cds_ctx->mode_change_cb = NULL;

	return QDF_STATUS_SUCCESS;
}

bool cds_get_pktcap_mode_enable(void)
{
	hdd_context_t *hdd_ctx;

	hdd_ctx = cds_get_context(QDF_MODULE_ID_HDD);
=======
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(4, 19, 0))
QDF_STATUS cds_smmu_mem_map_setup(qdf_device_t osdev, bool ipa_present)
{
	osdev->smmu_s1_enabled = false;
	osdev->domain = NULL;
	return QDF_STATUS_SUCCESS;
}
#else
QDF_STATUS cds_smmu_mem_map_setup(qdf_device_t osdev, bool ipa_present)
{
	osdev->smmu_s1_enabled = false;
	return QDF_STATUS_SUCCESS;
}
#endif

int cds_smmu_map_unmap(bool map, uint32_t num_buf, qdf_mem_info_t *buf_arr)
{
	return 0;
}
#endif

#ifdef WLAN_FEATURE_PKT_CAPTURE
bool cds_is_pktcapture_enabled(void)
{
	struct hdd_context *hdd_ctx;

	hdd_ctx = gp_cds_context->hdd_context;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	if (!hdd_ctx) {
		cds_err("HDD context is NULL");
		return false;
	}

<<<<<<< HEAD
	return hdd_ctx->config->pktcap_mode_enable;
=======
	return hdd_ctx->enable_pkt_capture_support;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

uint8_t cds_get_pktcapture_mode(void)
{
<<<<<<< HEAD
	hdd_context_t *hdd_ctx;

	hdd_ctx = cds_get_context(QDF_MODULE_ID_HDD);
	if (!hdd_ctx) {
		cds_err("HDD context is NULL");
		return 0;
	}

	return hdd_ctx->pktcapture_mode;
}
=======
	struct hdd_context *hdd_ctx;

	hdd_ctx = gp_cds_context->hdd_context;
	if (!hdd_ctx) {
		cds_err("HDD context is NULL");
		return false;
	}

	return hdd_ctx->val_pkt_capture_mode;
}
#endif /* WLAN_FEATURE_PKT_CAPTURE */
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

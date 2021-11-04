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
 * DOC: wlan_hdd_power.c
 *
 * WLAN power management functions
 *
 */

/* Include files */

#include <linux/pm.h>
#include <linux/wait.h>
#include <linux/cpu.h>
<<<<<<< HEAD
=======
#include "osif_sync.h"
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#include <wlan_hdd_includes.h>
#if defined(WLAN_OPEN_SOURCE) && defined(CONFIG_HAS_WAKELOCK)
#include <linux/wakelock.h>
#endif
#include "qdf_types.h"
#include "sme_api.h"
#include <cds_api.h>
#include <cds_sched.h>
#include <mac_init_api.h>
#include <wlan_qct_sys.h>
#include <wlan_hdd_main.h>
#include <wlan_hdd_assoc.h>
#include <wlan_nlink_srv.h>
#include <wlan_hdd_misc.h>
#include <wlan_hdd_power.h>
#include <wlan_hdd_host_offload.h>
#include <dbglog_host.h>
#include <wlan_hdd_trace.h>
#include <wlan_hdd_p2p.h>

#include <linux/semaphore.h>
#include <wlan_hdd_hostapd.h>
<<<<<<< HEAD
#include "cfg_api.h"
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

#include <linux/inetdevice.h>
#include <wlan_hdd_cfg.h>
#include <wlan_hdd_scan.h>
<<<<<<< HEAD
#include <wlan_hdd_cfg80211.h>
#include <net/addrconf.h>
#include <wlan_hdd_ipa.h>
#include <wlan_hdd_lpass.h>

#include <wma_types.h>
#include "hif.h"
#include "sme_power_save_api.h"
#include "cds_concurrency.h"
=======
#include <wlan_hdd_stats.h>
#include <wlan_hdd_cfg80211.h>
#include <net/addrconf.h>
#include <wlan_hdd_lpass.h>

#include <wma_types.h>
#include <ol_txrx_osif_api.h>
#include <ol_defines.h>
#include "hif.h"
#include "hif_unit_test_suspend.h"
#include "sme_power_save_api.h"
#include "wlan_policy_mgr_api.h"
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#include "cdp_txrx_flow_ctrl_v2.h"
#include "pld_common.h"
#include "wlan_hdd_driver_ops.h"
#include <wlan_logging_sock_svc.h>
<<<<<<< HEAD
#include "cds_utils.h"
#include "wlan_hdd_packet_filter_api.h"
#include "cds_concurrency.h"

/* Preprocessor definitions and constants */
#define HDD_SSR_BRING_UP_TIME 30000
=======
#include "scheduler_api.h"
#include "cds_utils.h"
#include "wlan_hdd_packet_filter_api.h"
#include "wlan_cfg80211_scan.h"
#include <dp_txrx.h>
#include "wlan_ipa_ucfg_api.h"
#include <wlan_cfg80211_mc_cp_stats.h>
#include "wlan_p2p_ucfg_api.h"
#include "wlan_mlme_ucfg_api.h"
#include "wlan_osif_request_manager.h"
#include <wlan_hdd_sar_limits.h>
#include "wlan_hdd_thermal.h"

/* Preprocessor definitions and constants */
#ifdef QCA_WIFI_NAPIER_EMULATION
#define HDD_SSR_BRING_UP_TIME 3000000
#else
#define HDD_SSR_BRING_UP_TIME 30000
#endif
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/* Type declarations */

#ifdef FEATURE_WLAN_DIAG_SUPPORT
<<<<<<< HEAD
/**
 * hdd_wlan_suspend_resume_event()- send suspend/resume state
 * @state: suspend/resume state
 *
 * This Function send send suspend resume state diag event
 *
 * Return: void.
 */
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
void hdd_wlan_suspend_resume_event(uint8_t state)
{
	WLAN_HOST_DIAG_EVENT_DEF(suspend_state, struct host_event_suspend);
	qdf_mem_zero(&suspend_state, sizeof(suspend_state));

	suspend_state.state = state;
	WLAN_HOST_DIAG_EVENT_REPORT(&suspend_state, EVENT_WLAN_SUSPEND_RESUME);
}

/**
 * hdd_wlan_offload_event()- send offloads event
 * @type: offload type
 * @state: enabled or disabled
 *
 * This Function send offloads enable/disable diag event
 *
 * Return: void.
 */

void hdd_wlan_offload_event(uint8_t type, uint8_t state)
{
	WLAN_HOST_DIAG_EVENT_DEF(host_offload, struct host_event_offload_req);
	qdf_mem_zero(&host_offload, sizeof(host_offload));

	host_offload.offload_type = type;
	host_offload.state = state;

	WLAN_HOST_DIAG_EVENT_REPORT(&host_offload, EVENT_WLAN_OFFLOAD_REQ);
}
#endif

<<<<<<< HEAD
/* Function and variables declarations */

/**
 * hdd_conf_gtk_offload() - Configure GTK offload
 * @pAdapter:   pointer to the adapter
 * @fenable:    flag set to enable (1) or disable (0) GTK offload
 *
 * Central function to enable or disable GTK offload.
 *
 * Return: nothing
 */
#ifdef WLAN_FEATURE_GTK_OFFLOAD
static void hdd_conf_gtk_offload(hdd_adapter_t *pAdapter, bool fenable)
{
	QDF_STATUS ret;
	tSirGtkOffloadParams hddGtkOffloadReqParams;
	hdd_station_ctx_t *pHddStaCtx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);

	if (fenable) {
		if ((eConnectionState_Associated ==
		     pHddStaCtx->conn_info.connState)
		    && (GTK_OFFLOAD_ENABLE ==
			pHddStaCtx->gtkOffloadReqParams.ulFlags)) {
			qdf_mem_copy(&hddGtkOffloadReqParams,
					&pHddStaCtx->gtkOffloadReqParams,
				     sizeof(tSirGtkOffloadParams));

			ret = sme_set_gtk_offload(
						WLAN_HDD_GET_HAL_CTX(pAdapter),
						&hddGtkOffloadReqParams,
						pAdapter->sessionId);
			if (QDF_STATUS_SUCCESS != ret) {
				hdd_err("sme_set_gtk_offload failed %d", ret);
				return;
			}

			hdd_debug("sme_set_gtk_offload successfull");
		}

	} else {
		if ((eConnectionState_Associated ==
		     pHddStaCtx->conn_info.connState)
		    && (qdf_is_macaddr_equal(
				&pHddStaCtx->gtkOffloadReqParams.bssid,
				&pHddStaCtx->conn_info.bssId))
		    && (GTK_OFFLOAD_ENABLE ==
			pHddStaCtx->gtkOffloadReqParams.ulFlags)) {

			/* Host driver has previously offloaded GTK rekey  */
			ret = sme_get_gtk_offload
				(WLAN_HDD_GET_HAL_CTX(pAdapter),
				 wlan_hdd_cfg80211_update_replay_counter_cb,
				 pAdapter, pAdapter->sessionId);
			if (QDF_STATUS_SUCCESS != ret) {
				hdd_err("sme_get_gtk_offload failed, returned %d",
					ret);
				return;
			}
			hdd_debug("sme_get_gtk_offload successful");

			/* Sending GTK offload dissable */
			memcpy(&hddGtkOffloadReqParams,
			       &pHddStaCtx->gtkOffloadReqParams,
			       sizeof(tSirGtkOffloadParams));
			hddGtkOffloadReqParams.ulFlags =
				GTK_OFFLOAD_DISABLE;
			ret =
				sme_set_gtk_offload(WLAN_HDD_GET_HAL_CTX
							    (pAdapter),
						    &hddGtkOffloadReqParams,
						    pAdapter->sessionId);
			if (QDF_STATUS_SUCCESS != ret) {
				hdd_err("failed to dissable GTK offload, returned %d",
					ret);
				return;
			}
			hdd_debug("successfully dissabled GTK offload request to HAL");
		}
	}
}
#else /* WLAN_FEATURE_GTK_OFFLOAD */
static void hdd_conf_gtk_offload(hdd_adapter_t *pAdapter, bool fenable)
{
}
#endif /*WLAN_FEATURE_GTK_OFFLOAD */
=======
#ifdef WLAN_FEATURE_PKT_CAPTURE

/* timeout in msec to wait for RX_THREAD to suspend */
#define HDD_MONTHREAD_SUSPEND_TIMEOUT 200

void wlan_hdd_mon_thread_resume(struct hdd_context *hdd_ctx)
{
	if (hdd_ctx->is_ol_mon_thread_suspended) {
		cds_resume_mon_thread();
		hdd_ctx->is_ol_mon_thread_suspended = false;
	}
}

int wlan_hdd_mon_thread_suspend(struct hdd_context *hdd_ctx)
{
	p_cds_sched_context cds_sched_context = get_cds_sched_ctxt();
	int rc;

	if (!cds_sched_context)
		return -EINVAL;

	set_bit(RX_SUSPEND_EVENT,
		&cds_sched_context->sched_mon_ctx.ol_mon_event_flag);
	wake_up_interruptible(&cds_sched_context->
			      sched_mon_ctx.ol_mon_wait_queue);
	rc = wait_for_completion_timeout(
			&cds_sched_context->sched_mon_ctx.ol_suspend_mon_event,
			msecs_to_jiffies(HDD_MONTHREAD_SUSPEND_TIMEOUT));
	if (!rc) {
		clear_bit(RX_SUSPEND_EVENT,
			  &cds_sched_context->sched_mon_ctx.ol_mon_event_flag);
		hdd_err("Failed to stop tl_shim mon thread");
		return -EINVAL;
	}
	hdd_ctx->is_ol_mon_thread_suspended = true;

	return 0;
}
#endif

#ifdef QCA_CONFIG_SMP

/* timeout in msec to wait for RX_THREAD to suspend */
#define HDD_RXTHREAD_SUSPEND_TIMEOUT 200

void wlan_hdd_rx_thread_resume(struct hdd_context *hdd_ctx)
{
	if (hdd_ctx->is_ol_rx_thread_suspended) {
		cds_resume_rx_thread();
		hdd_ctx->is_ol_rx_thread_suspended = false;
	}
}

int wlan_hdd_rx_thread_suspend(struct hdd_context *hdd_ctx)
{
	p_cds_sched_context cds_sched_context = get_cds_sched_ctxt();
	int rc;

	if (!cds_sched_context)
		return 0;

	/* Suspend tlshim rx thread */
	set_bit(RX_SUSPEND_EVENT, &cds_sched_context->ol_rx_event_flag);
	wake_up_interruptible(&cds_sched_context->ol_rx_wait_queue);
	rc = wait_for_completion_timeout(&cds_sched_context->
					 ol_suspend_rx_event,
					 msecs_to_jiffies
					 (HDD_RXTHREAD_SUSPEND_TIMEOUT)
					);
	if (!rc) {
		clear_bit(RX_SUSPEND_EVENT,
			  &cds_sched_context->ol_rx_event_flag);
		hdd_err("Failed to stop tl_shim rx thread");
		return -EINVAL;
	}
	hdd_ctx->is_ol_rx_thread_suspended = true;

	return 0;
}
#endif /* QCA_CONFIG_SMP */

/**
 * hdd_enable_gtk_offload() - enable GTK offload
 * @adapter: pointer to the adapter
 *
 * Central function to enable GTK offload.
 *
 * Return: nothing
 */
static void hdd_enable_gtk_offload(struct hdd_adapter *adapter)
{
	QDF_STATUS status;

	status = ucfg_pmo_enable_gtk_offload_in_fwr(adapter->vdev);
	if (status != QDF_STATUS_SUCCESS)
		hdd_info("Failed to enable gtk offload");
}

/**
 * hdd_disable_gtk_offload() - disable GTK offload
 * @adapter:   pointer to the adapter
 *
 * Central function to disable GTK offload.
 *
 * Return: nothing
 */
static void hdd_disable_gtk_offload(struct hdd_adapter *adapter)
{
	struct pmo_gtk_rsp_req gtk_rsp_request;
	QDF_STATUS status;

	/* ensure to get gtk rsp first before disable it*/
	gtk_rsp_request.callback = wlan_hdd_cfg80211_update_replay_counter_cb;

	/* Passing as void* as PMO does not know legacy HDD adapter type */
	gtk_rsp_request.callback_context = (void *)adapter;

	status = ucfg_pmo_get_gtk_rsp(adapter->vdev, &gtk_rsp_request);
	if (status != QDF_STATUS_SUCCESS) {
		hdd_err("Failed to send get gtk rsp status:%d", status);
		return;
	}

	hdd_debug("send get_gtk_rsp successful");
	status = ucfg_pmo_disable_gtk_offload_in_fwr(adapter->vdev);
	if (status != QDF_STATUS_SUCCESS)
		hdd_info("Failed to disable gtk offload");
}
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

#ifdef WLAN_NS_OFFLOAD
/**
 * __wlan_hdd_ipv6_changed() - IPv6 notifier callback function
<<<<<<< HEAD
 * @nb: notifier block that was registered with the kernel
 * @data: (unused) generic data that was registered with the kernel
 * @arg: (unused) generic argument that was registered with the kernel
=======
 * @net_dev: net_device whose IP address changed
 * @event: event from kernel, NETDEV_UP or NETDEV_DOWN
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *
 * This is a callback function that is registered with the kernel via
 * register_inet6addr_notifier() which allows the driver to be
 * notified when there is an IPv6 address change.
 *
<<<<<<< HEAD
 * Return: NOTIFY_DONE to indicate we don't care what happens with
 *	other callbacks
 */
static int __wlan_hdd_ipv6_changed(struct notifier_block *nb,
				 unsigned long data, void *arg)
{
	struct inet6_ifaddr *ifa = (struct inet6_ifaddr *)arg;
	struct net_device *ndev = ifa->idev->dev;
	hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(ndev);
	hdd_context_t *pHddCtx;
	hdd_station_ctx_t *sta_ctx;
	int status;

	ENTER_DEV(ndev);

	if ((pAdapter == NULL) || (WLAN_HDD_ADAPTER_MAGIC != pAdapter->magic)) {
		hdd_debug("Adapter context is invalid %pK", pAdapter);
		return NOTIFY_DONE;
	}

	if ((pAdapter->dev == ndev) &&
	    (pAdapter->device_mode == QDF_STA_MODE ||
	     pAdapter->device_mode == QDF_P2P_CLIENT_MODE ||
	     pAdapter->device_mode == QDF_NDI_MODE)) {
		pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
		status = wlan_hdd_validate_context(pHddCtx);
		if (0 != status)
			return NOTIFY_DONE;

		/* Ignore if the interface is down */
		if (!(ndev->flags & IFF_UP)) {
			hdd_err("Rcvd change addr request on %s(flags 0x%X)",
				ndev->name, ndev->flags);
			hdd_err("NETDEV Interface is down, ignoring...");
			return NOTIFY_DONE;
		}

		sta_ctx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
		hdd_debug("invoking sme_dhcp_done_ind");
		sme_dhcp_done_ind(pHddCtx->hHal,
					  pAdapter->sessionId);
		schedule_work(&pAdapter->ipv6NotifierWorkQueue);
	}
	EXIT();
	return NOTIFY_DONE;
}

/**
 * wlan_hdd_ipv6_changed() - IPv6 change notifier callback
 * @nb: pointer to notifier block
 * @data: data
 * @arg: arg
 *
 * This is the IPv6 notifier callback function gets invoked
 * if any change in IP and then invoke the function @__wlan_hdd_ipv6_changed
 * to reconfigure the offload parameters.
 *
 * Return: 0 on success, error number otherwise.
 */
int wlan_hdd_ipv6_changed(struct notifier_block *nb,
				unsigned long data, void *arg)
{
	int ret;

	cds_ssr_protect(__func__);
	ret = __wlan_hdd_ipv6_changed(nb, data, arg);
	cds_ssr_unprotect(__func__);

	return ret;
=======
 * Return: None
 */
static void __wlan_hdd_ipv6_changed(struct net_device *net_dev,
				    unsigned long event)
{
	struct hdd_adapter *adapter = WLAN_HDD_GET_PRIV_PTR(net_dev);
	struct hdd_context *hdd_ctx;
	int errno;

	hdd_enter_dev(net_dev);

	errno = hdd_validate_adapter(adapter);
	if (errno || adapter->dev != net_dev)
		goto exit;

	hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	errno = wlan_hdd_validate_context(hdd_ctx);
	if (errno)
		goto exit;

	/* Only need to be notified for ipv6_add_addr
	 * No need for ipv6_del_addr or addrconf_ifdown
	 */
	if (event == NETDEV_UP &&
	    (adapter->device_mode == QDF_STA_MODE ||
	     adapter->device_mode == QDF_P2P_CLIENT_MODE)) {
		hdd_debug("invoking sme_dhcp_done_ind");
		sme_dhcp_done_ind(hdd_ctx->mac_handle, adapter->vdev_id);
		schedule_work(&adapter->ipv6_notifier_work);
	}

exit:
	hdd_exit();
}

int wlan_hdd_ipv6_changed(struct notifier_block *nb,
			  unsigned long data, void *context)
{
	struct inet6_ifaddr *ifa = context;
	struct net_device *net_dev = ifa->idev->dev;
	struct osif_vdev_sync *vdev_sync;

	if (osif_vdev_sync_op_start(net_dev, &vdev_sync))
		return NOTIFY_DONE;

	__wlan_hdd_ipv6_changed(net_dev, data);

	osif_vdev_sync_op_stop(vdev_sync);

	return NOTIFY_DONE;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * hdd_fill_ipv6_uc_addr() - fill IPv6 unicast addresses
 * @idev: pointer to net device
 * @ipv6addr: destination array to fill IPv6 addresses
 * @ipv6addr_type: IPv6 Address type
<<<<<<< HEAD
 * @scope_array: IPv6 Address scope
=======
 * @scope_array: scope of ipv6 addr
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @count: number of IPv6 addresses
 *
 * This is the IPv6 utility function to populate unicast addresses.
 *
 * Return: 0 on success, error number otherwise.
 */
static int hdd_fill_ipv6_uc_addr(struct inet6_dev *idev,
<<<<<<< HEAD
				uint8_t ipv6_uc_addr[][SIR_MAC_IPV6_ADDR_LEN],
				uint8_t *ipv6addr_type,
				enum sir_ipv6_addr_scope *scope_array,
=======
				uint8_t ipv6_uc_addr[][QDF_IPV6_ADDR_SIZE],
				uint8_t *ipv6addr_type,
				enum pmo_ns_addr_scope *scope_array,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				uint32_t *count)
{
	struct inet6_ifaddr *ifa;
	struct list_head *p;
	uint32_t scope;

	read_lock_bh(&idev->lock);
	list_for_each(p, &idev->addr_list) {
<<<<<<< HEAD
		if (*count >= SIR_MAC_NUM_TARGET_IPV6_NS_OFFLOAD_NA) {
=======
		if (*count >= PMO_MAC_NUM_TARGET_IPV6_NS_OFFLOAD_NA) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			read_unlock_bh(&idev->lock);
			return -EINVAL;
		}
		ifa = list_entry(p, struct inet6_ifaddr, if_list);
		if (ifa->flags & IFA_F_DADFAILED)
			continue;
		scope = ipv6_addr_src_scope(&ifa->addr);
		switch (scope) {
		case IPV6_ADDR_SCOPE_GLOBAL:
		case IPV6_ADDR_SCOPE_LINKLOCAL:
			qdf_mem_copy(ipv6_uc_addr[*count], &ifa->addr.s6_addr,
				sizeof(ifa->addr.s6_addr));
<<<<<<< HEAD
			ipv6addr_type[*count] = SIR_IPV6_ADDR_UC_TYPE;
			scope_array[*count] = sir_get_ipv6_addr_scope(scope);
=======
			ipv6addr_type[*count] = PMO_IPV6_ADDR_UC_TYPE;
			scope_array[*count] = ucfg_pmo_ns_addr_scope(scope);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			hdd_debug("Index %d scope = %s UC-Address: %pI6",
				*count, (scope == IPV6_ADDR_SCOPE_LINKLOCAL) ?
				"LINK LOCAL" : "GLOBAL", ipv6_uc_addr[*count]);
			*count += 1;
			break;
		default:
			hdd_warn("The Scope %d is not supported", scope);
		}
	}

	read_unlock_bh(&idev->lock);
	return 0;
}

/**
 * hdd_fill_ipv6_ac_addr() - fill IPv6 anycast addresses
 * @idev: pointer to net device
 * @ipv6addr: destination array to fill IPv6 addresses
 * @ipv6addr_type: IPv6 Address type
<<<<<<< HEAD
 * @scope_array: IPv6 Address scope
=======
 * @scope_array: scope of ipv6 addr
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @count: number of IPv6 addresses
 *
 * This is the IPv6 utility function to populate anycast addresses.
 *
 * Return: 0 on success, error number otherwise.
 */
static int hdd_fill_ipv6_ac_addr(struct inet6_dev *idev,
<<<<<<< HEAD
				uint8_t ipv6_ac_addr[][SIR_MAC_IPV6_ADDR_LEN],
				uint8_t *ipv6addr_type,
				enum sir_ipv6_addr_scope *scope_array,
=======
				uint8_t ipv6_ac_addr[][QDF_IPV6_ADDR_SIZE],
				uint8_t *ipv6addr_type,
				enum pmo_ns_addr_scope *scope_array,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				uint32_t *count)
{
	struct ifacaddr6 *ifaca;
	uint32_t scope;

	read_lock_bh(&idev->lock);
	for (ifaca = idev->ac_list; ifaca; ifaca = ifaca->aca_next) {
<<<<<<< HEAD
		if (*count >= SIR_MAC_NUM_TARGET_IPV6_NS_OFFLOAD_NA) {
=======
		if (*count >= PMO_MAC_NUM_TARGET_IPV6_NS_OFFLOAD_NA) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			read_unlock_bh(&idev->lock);
			return -EINVAL;
		}
		/* For anycast addr no DAD */
		scope = ipv6_addr_src_scope(&ifaca->aca_addr);
		switch (scope) {
		case IPV6_ADDR_SCOPE_GLOBAL:
		case IPV6_ADDR_SCOPE_LINKLOCAL:
			qdf_mem_copy(ipv6_ac_addr[*count], &ifaca->aca_addr,
				sizeof(ifaca->aca_addr));
<<<<<<< HEAD
			ipv6addr_type[*count] = SIR_IPV6_ADDR_AC_TYPE;
			scope_array[*count] = sir_get_ipv6_addr_scope(scope);
=======
			ipv6addr_type[*count] = PMO_IPV6_ADDR_AC_TYPE;
			scope_array[*count] = ucfg_pmo_ns_addr_scope(scope);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			hdd_debug("Index %d scope = %s AC-Address: %pI6",
				*count, (scope == IPV6_ADDR_SCOPE_LINKLOCAL) ?
				"LINK LOCAL" : "GLOBAL", ipv6_ac_addr[*count]);
			*count += 1;
			break;
		default:
			hdd_warn("The Scope %d is not supported", scope);
		}
	}

	read_unlock_bh(&idev->lock);
	return 0;
}

<<<<<<< HEAD
/**
 * hdd_disable_ns_offload() - Disables IPv6 NS offload
 * @adapter:	ponter to the adapter
 *
 * Return:	nothing
 */
static void hdd_disable_ns_offload(hdd_adapter_t *adapter)
{
	tSirHostOffloadReq offloadReq;
	QDF_STATUS status;

	qdf_mutex_acquire(&adapter->ns_offload_info_lock);
	adapter->ns_offload_info.offload = false;
	qdf_mutex_release(&adapter->ns_offload_info_lock);

	qdf_mem_zero((void *)&offloadReq, sizeof(tSirHostOffloadReq));
	hdd_wlan_offload_event(SIR_IPV6_NS_OFFLOAD, SIR_OFFLOAD_DISABLE);
	offloadReq.enableOrDisable = SIR_OFFLOAD_DISABLE;
	offloadReq.offloadType =  SIR_IPV6_NS_OFFLOAD;
	status = sme_set_host_offload(
		WLAN_HDD_GET_HAL_CTX(adapter),
		adapter->sessionId, &offloadReq);

	if (QDF_STATUS_SUCCESS != status)
		hdd_err("Failed to disable NS Offload");
}

/**
 * hdd_enable_ns_offload() - Enables IPv6 NS offload
 * @adapter:	ponter to the adapter
 *
 * Return:	nothing
 */
static void hdd_enable_ns_offload(hdd_adapter_t *adapter)
{
	struct inet6_dev *in6_dev;
	uint8_t ipv6_addr[SIR_MAC_NUM_TARGET_IPV6_NS_OFFLOAD_NA]
					[SIR_MAC_IPV6_ADDR_LEN] = { {0,} };
	uint8_t ipv6_addr_type[SIR_MAC_NUM_TARGET_IPV6_NS_OFFLOAD_NA] = { 0 };
	enum sir_ipv6_addr_scope scope[SIR_MAC_NUM_TARGET_IPV6_NS_OFFLOAD_NA];
	tSirHostOffloadReq offloadReq;
	QDF_STATUS status;
	uint32_t count = 0;
	int err, i;

	in6_dev = __in6_dev_get(adapter->dev);
	if (NULL == in6_dev) {
		hdd_warn("IPv6 dev does not exist. Failed to request NSOffload");
		return;
	}

	qdf_mem_zero(scope, sizeof(scope));

	/* Unicast Addresses */
	err = hdd_fill_ipv6_uc_addr(in6_dev, ipv6_addr, ipv6_addr_type, scope,
				    &count);
	if (err) {
		hdd_disable_ns_offload(adapter);
		hdd_debug("Max supported addresses: disabling NS offload");
		return;
	}

	/* Anycast Addresses */
	err = hdd_fill_ipv6_ac_addr(in6_dev, ipv6_addr, ipv6_addr_type, scope,
				    &count);
	if (err) {
		hdd_disable_ns_offload(adapter);
		hdd_debug("Max supported addresses: disabling NS offload");
		return;
	}

	qdf_mem_zero(&offloadReq, sizeof(offloadReq));
	for (i = 0; i < count; i++) {
		/* Filling up the request structure
		 * Filling the selfIPv6Addr with solicited address
		 * A Solicited-Node multicast address is created by
		 * taking the last 24 bits of a unicast or anycast
		 * address and appending them to the prefix
		 *
		 * FF02:0000:0000:0000:0000:0001:FFXX:XXXX
		 *
		 * here XX is the unicast/anycast bits
		 */
		offloadReq.nsOffloadInfo.selfIPv6Addr[i][0] = 0xFF;
		offloadReq.nsOffloadInfo.selfIPv6Addr[i][1] = 0x02;
		offloadReq.nsOffloadInfo.selfIPv6Addr[i][11] = 0x01;
		offloadReq.nsOffloadInfo.selfIPv6Addr[i][12] = 0xFF;
		offloadReq.nsOffloadInfo.selfIPv6Addr[i][13] =
					ipv6_addr[i][13];
		offloadReq.nsOffloadInfo.selfIPv6Addr[i][14] =
					ipv6_addr[i][14];
		offloadReq.nsOffloadInfo.selfIPv6Addr[i][15] =
					ipv6_addr[i][15];
		offloadReq.nsOffloadInfo.slotIdx = i;
		qdf_mem_copy(&offloadReq.nsOffloadInfo.targetIPv6Addr[i],
			&ipv6_addr[i][0], SIR_MAC_IPV6_ADDR_LEN);

		offloadReq.nsOffloadInfo.targetIPv6AddrValid[i] =
			SIR_IPV6_ADDR_VALID;
		offloadReq.nsOffloadInfo.target_ipv6_addr_ac_type[i] =
			ipv6_addr_type[i];
		offloadReq.nsOffloadInfo.scope[i] = scope[i];

		qdf_mem_copy(&offloadReq.params.hostIpv6Addr,
			&offloadReq.nsOffloadInfo.targetIPv6Addr[i],
			SIR_MAC_IPV6_ADDR_LEN);

		hdd_debug("Setting NSOffload with solicitedIp: ");
		hdd_debug("%pI6, targetIp: %pI6, Index %d",
			&offloadReq.nsOffloadInfo.selfIPv6Addr[i],
			&offloadReq.nsOffloadInfo.targetIPv6Addr[i], i);
	}

	hdd_wlan_offload_event(SIR_IPV6_NS_OFFLOAD, SIR_OFFLOAD_ENABLE);
	offloadReq.offloadType =  SIR_IPV6_NS_OFFLOAD;
	offloadReq.enableOrDisable = SIR_OFFLOAD_ENABLE;
	qdf_copy_macaddr(&offloadReq.nsOffloadInfo.self_macaddr,
			 &adapter->macAddressCurrent);

	/* set number of ns offload address count */
	offloadReq.num_ns_offload_count = count;

	qdf_mutex_acquire(&adapter->ns_offload_info_lock);
	adapter->ns_offload_info.offload = true;
	adapter->ns_offload_info.num_ns_offload_count = count;
	adapter->ns_offload_info.nsOffloadInfo = offloadReq.nsOffloadInfo;
	qdf_mutex_release(&adapter->ns_offload_info_lock);

	/* Configure the Firmware with this */
	status = sme_set_host_offload(WLAN_HDD_GET_HAL_CTX(adapter),
		adapter->sessionId, &offloadReq);
	if (QDF_STATUS_SUCCESS != status) {
		hdd_err("Failed to enable HostOffload feature with status: %d",
			status);
	}
}

/**
 * hdd_conf_ns_offload() - Configure NS offload
 * @adapter:   pointer to the adapter
 * @fenable:    flag to enable or disable
 *              0 - disable
 *              1 - enable
 *
 * Return: nothing
 */
void hdd_conf_ns_offload(hdd_adapter_t *adapter, bool fenable)
{
	hdd_context_t *hdd_ctx;

	ENTER();
	hdd_debug(" fenable = %d", fenable);

	hdd_ctx = WLAN_HDD_GET_CTX(adapter);

	/* In SAP/P2PGo mode, ARP/NS offload feature capability
	 * is controlled by one bit.
	 */

	if ((QDF_SAP_MODE == adapter->device_mode ||
		QDF_P2P_GO_MODE == adapter->device_mode) &&
		!hdd_ctx->ap_arpns_support) {
		hdd_debug("NS Offload is not supported in SAP/P2PGO mode");
		return;
	}

	if (QDF_IBSS_MODE == adapter->device_mode) {
		hdd_debug("NS Offload is not supported in IBSS mode");
		return;
	}

	if (fenable)
		hdd_enable_ns_offload(adapter);
	else
		hdd_disable_ns_offload(adapter);

	EXIT();
=======
void hdd_enable_ns_offload(struct hdd_adapter *adapter,
			   enum pmo_offload_trigger trigger)
{
	struct hdd_context *hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	struct wlan_objmgr_psoc *psoc = hdd_ctx->psoc;
	struct inet6_dev *in6_dev;
	struct pmo_ns_req *ns_req;
	QDF_STATUS status;
	int errno;

	hdd_enter();

	if (!psoc) {
		hdd_err("psoc is NULL");
		goto out;
	}

	in6_dev = __in6_dev_get(adapter->dev);
	if (!in6_dev) {
		hdd_err("IPv6 dev does not exist. Failed to request NSOffload");
		goto out;
	}

	ns_req = qdf_mem_malloc(sizeof(*ns_req));
	if (!ns_req)
		goto out;

	ns_req->psoc = psoc;
	ns_req->vdev_id = adapter->vdev_id;
	ns_req->trigger = trigger;
	ns_req->count = 0;

	/* check if offload cache and send is required or not */
	status = ucfg_pmo_ns_offload_check(psoc, trigger, adapter->vdev_id);
	if (QDF_IS_STATUS_ERROR(status)) {
		hdd_debug("NS offload is not required");
		goto free_req;
	}

	/* Unicast Addresses */
	errno = hdd_fill_ipv6_uc_addr(in6_dev, ns_req->ipv6_addr,
				      ns_req->ipv6_addr_type, ns_req->scope,
				      &ns_req->count);
	if (errno) {
		hdd_disable_ns_offload(adapter, trigger);
		hdd_debug("Max supported addresses: disabling NS offload");
		goto free_req;
	}

	/* Anycast Addresses */
	errno = hdd_fill_ipv6_ac_addr(in6_dev, ns_req->ipv6_addr,
				      ns_req->ipv6_addr_type, ns_req->scope,
				      &ns_req->count);
	if (errno) {
		hdd_disable_ns_offload(adapter, trigger);
		hdd_debug("Max supported addresses: disabling NS offload");
		goto free_req;
	}

	/* cache ns request */
	status = ucfg_pmo_cache_ns_offload_req(ns_req);
	if (QDF_IS_STATUS_ERROR(status)) {
		hdd_err("Failed to cache ns request; status:%d", status);
		goto free_req;
	}

	/* enable ns request */
	status = ucfg_pmo_enable_ns_offload_in_fwr(adapter->vdev, trigger);
	if (QDF_IS_STATUS_ERROR(status)) {
		hdd_err("Failed to enable ns offload; status:%d", status);
		goto free_req;
	}

	hdd_wlan_offload_event(SIR_IPV6_NS_OFFLOAD, SIR_OFFLOAD_ENABLE);

free_req:
	qdf_mem_free(ns_req);

out:
	hdd_exit();
}

void hdd_disable_ns_offload(struct hdd_adapter *adapter,
		enum pmo_offload_trigger trigger)
{
	QDF_STATUS status;
	struct hdd_context *hdd_ctx = WLAN_HDD_GET_CTX(adapter);

	hdd_enter();

	status = ucfg_pmo_ns_offload_check(hdd_ctx->psoc, trigger,
					   adapter->vdev_id);
	if (status != QDF_STATUS_SUCCESS) {
		hdd_debug("Flushing of NS offload not required");
		goto out;
	}

	status = ucfg_pmo_flush_ns_offload_req(adapter->vdev);
	if (status != QDF_STATUS_SUCCESS) {
		hdd_err("Failed to flush NS Offload");
		goto out;
	}

	status = ucfg_pmo_disable_ns_offload_in_fwr(adapter->vdev, trigger);
	if (status != QDF_STATUS_SUCCESS)
		hdd_err("Failed to disable NS Offload");
	else
		hdd_wlan_offload_event(SIR_IPV6_NS_OFFLOAD,
			SIR_OFFLOAD_DISABLE);
out:
	hdd_exit();

}

/**
 * hdd_send_ps_config_to_fw() - Check user pwr save config set/reset PS
 * @adapter: pointer to hdd adapter
 *
 * This function checks the power save configuration saved in MAC context
 * and sends power save config to FW.
 *
 * Return: None
 */
static void hdd_send_ps_config_to_fw(struct hdd_adapter *adapter)
{
	struct mac_context *mac_ctx;
	struct hdd_context *hdd_ctx;

	if (hdd_validate_adapter(adapter))
		return;

	hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	mac_ctx  = MAC_CONTEXT(hdd_ctx->mac_handle);

	if (mac_ctx->usr_cfg_ps_enable)
		sme_ps_enable_disable(hdd_ctx->mac_handle, adapter->vdev_id,
				      SME_PS_ENABLE);
	else
		sme_ps_enable_disable(hdd_ctx->mac_handle, adapter->vdev_id,
				      SME_PS_DISABLE);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * __hdd_ipv6_notifier_work_queue() - IPv6 notification work function
<<<<<<< HEAD
 * @work: registered work item
=======
 * @adapter: adapter whose IP address changed
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *
 * This function performs the work initially trigged by a callback
 * from the IPv6 netdev notifier.  Since this means there has been a
 * change in IPv6 state for the interface, the NS offload is
 * reconfigured.
 *
 * Return: None
 */
<<<<<<< HEAD
static void __hdd_ipv6_notifier_work_queue(struct work_struct *work)
{
	hdd_adapter_t *pAdapter =
		container_of(work, hdd_adapter_t, ipv6NotifierWorkQueue);
	hdd_context_t *pHddCtx;
	int status;
	bool ndi_connected = false;

	ENTER();

	pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
	status = wlan_hdd_validate_context(pHddCtx);
	if (0 != status)
		return;

	if (!pHddCtx->config->active_mode_offload) {
		hdd_warn("Active mode offload is disabled");
		return;
	}

	/* check if the device is in NAN data mode */
	if (WLAN_HDD_IS_NDI(pAdapter))
		ndi_connected = WLAN_HDD_IS_NDI_CONNECTED(pAdapter);

	if (eConnectionState_Associated ==
	     (WLAN_HDD_GET_STATION_CTX_PTR(pAdapter))->conn_info.connState ||
		ndi_connected)
		if (pHddCtx->config->fhostNSOffload &&
		    pHddCtx->ns_offload_enable)
			hdd_conf_ns_offload(pAdapter, true);
	EXIT();
}

/**
 * hdd_ipv6_notifier_work_queue() - IP V6 change notifier work handler
 * @work: Pointer to work context
 *
 * Return: none
 */
void hdd_ipv6_notifier_work_queue(struct work_struct *work)
{
	cds_ssr_protect(__func__);
	__hdd_ipv6_notifier_work_queue(work);
	cds_ssr_unprotect(__func__);
}

/**
 * hdd_conf_hostoffload() - Central function to configure the supported offloads
 * @pAdapter:   pointer to the adapter
 * @fenable:    flag set to enable (1) or disable (0)
 *
 * Central function to configure the supported offloads either
 * enable or disable them.
 *
 * Return: nothing
 */
void hdd_conf_hostoffload(hdd_adapter_t *pAdapter, bool fenable)
{
	hdd_context_t *pHddCtx;

	ENTER();

	hdd_debug("Configuring offloads with flag: %d", fenable);

	/* Get the HDD context. */
	pHddCtx = WLAN_HDD_GET_CTX(pAdapter);

	if (((QDF_STA_MODE != pAdapter->device_mode) &&
	     (QDF_P2P_CLIENT_MODE != pAdapter->device_mode))) {
		hdd_debug("Offloads not supported in mode %d",
			pAdapter->device_mode);
		return;
	}

	if (eConnectionState_Associated !=
	       (WLAN_HDD_GET_STATION_CTX_PTR(pAdapter))->conn_info.connState) {
		hdd_debug("Offloads not supported in state %d",
			(WLAN_HDD_GET_STATION_CTX_PTR(pAdapter))->
							conn_info.connState);
		return;
	}

	hdd_conf_gtk_offload(pAdapter, fenable);

	/* Configure ARP/NS offload during cfg80211 suspend/resume and
	 * Enable MC address filtering during cfg80211 suspend
	 * only if active mode offload is disabled
	 */
	if (!pHddCtx->config->active_mode_offload) {
		hdd_debug("configuring unconfigured active mode offloads");
		hdd_conf_arp_offload(pAdapter, fenable);
		wlan_hdd_set_mc_addr_list(pAdapter, fenable);

		if (pHddCtx->config->fhostNSOffload &&
		    pHddCtx->ns_offload_enable)
			hdd_conf_ns_offload(pAdapter, fenable);
	}

	/* Configure DTIM hardware filter rules */
	hdd_conf_hw_filter_mode(pAdapter, pHddCtx->config->hw_filter_mode,
				fenable);

	EXIT();
}
#endif
=======
static void __hdd_ipv6_notifier_work_queue(struct hdd_adapter *adapter)
{
	struct hdd_context *hdd_ctx;
	int errno;

	hdd_enter();

	errno = hdd_validate_adapter(adapter);
	if (errno)
		goto exit;

	hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	errno = wlan_hdd_validate_context(hdd_ctx);
	if (errno)
		goto exit;

	hdd_enable_ns_offload(adapter, pmo_ipv6_change_notify);

	hdd_send_ps_config_to_fw(adapter);
exit:
	hdd_exit();
}

void hdd_ipv6_notifier_work_queue(struct work_struct *work)
{
	struct hdd_adapter *adapter = container_of(work, struct hdd_adapter,
						   ipv6_notifier_work);
	struct osif_vdev_sync *vdev_sync;

	if (osif_vdev_sync_op_start(adapter->dev, &vdev_sync))
		return;

	__hdd_ipv6_notifier_work_queue(adapter);

	osif_vdev_sync_op_stop(vdev_sync);
}
#endif /* WLAN_NS_OFFLOAD */

static void hdd_enable_hw_filter(struct hdd_adapter *adapter)
{
	QDF_STATUS status;

	hdd_enter();

	status = ucfg_pmo_enable_hw_filter_in_fwr(adapter->vdev);
	if (status != QDF_STATUS_SUCCESS)
		hdd_info("Failed to enable hardware filter");

	hdd_exit();
}

static void hdd_disable_hw_filter(struct hdd_adapter *adapter)
{
	QDF_STATUS status;

	hdd_enter();

	status = ucfg_pmo_disable_hw_filter_in_fwr(adapter->vdev);
	if (status != QDF_STATUS_SUCCESS)
		hdd_info("Failed to disable hardware filter");

	hdd_exit();
}

static void hdd_enable_action_frame_patterns(struct hdd_adapter *adapter)
{
	QDF_STATUS status;

	hdd_enter();

	status = ucfg_pmo_enable_action_frame_patterns(adapter->vdev,
						       QDF_SYSTEM_SUSPEND);
	if (QDF_IS_STATUS_ERROR(status))
		hdd_info("Failed to enable action frame patterns");

	hdd_exit();
}

static void hdd_disable_action_frame_patterns(struct hdd_adapter *adapter)
{
	QDF_STATUS status;

	hdd_enter();

	status = ucfg_pmo_disable_action_frame_patterns(adapter->vdev);
	if (QDF_IS_STATUS_ERROR(status))
		hdd_info("Failed to disable action frame patterns");

	hdd_exit();
}

void hdd_enable_host_offloads(struct hdd_adapter *adapter,
	enum pmo_offload_trigger trigger)
{
	hdd_enter();

	if (!ucfg_pmo_is_vdev_supports_offload(adapter->vdev)) {
		hdd_debug("offload is not supported on vdev opmode %d",
			  adapter->device_mode);
		goto out;
	}

	if (!ucfg_pmo_is_vdev_connected(adapter->vdev)) {
		hdd_debug("offload is not supported on disconnected vdevs");
		goto out;
	}

	hdd_debug("enable offloads");
	hdd_enable_gtk_offload(adapter);
	hdd_enable_arp_offload(adapter, trigger);
	hdd_enable_ns_offload(adapter, trigger);
	hdd_enable_mc_addr_filtering(adapter, trigger);
	if (adapter->device_mode != QDF_NDI_MODE)
		hdd_enable_hw_filter(adapter);
	hdd_enable_action_frame_patterns(adapter);
out:
	hdd_exit();

}

void hdd_disable_host_offloads(struct hdd_adapter *adapter,
	enum pmo_offload_trigger trigger)
{
	hdd_enter();

	if (!ucfg_pmo_is_vdev_supports_offload(adapter->vdev)) {
		hdd_info("offload is not supported on this vdev opmode: %d",
				adapter->device_mode);
			goto out;
	}

	if (!ucfg_pmo_is_vdev_connected(adapter->vdev)) {
		hdd_info("vdev is not connected");
		goto out;
	}

	hdd_debug("disable offloads");
	hdd_disable_gtk_offload(adapter);
	hdd_disable_arp_offload(adapter, trigger);
	hdd_disable_ns_offload(adapter, trigger);
	hdd_disable_mc_addr_filtering(adapter, trigger);
	if (adapter->device_mode != QDF_NDI_MODE)
		hdd_disable_hw_filter(adapter);
	hdd_disable_action_frame_patterns(adapter);
out:
	hdd_exit();

}
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * hdd_lookup_ifaddr() - Lookup interface address data by name
 * @adapter: the adapter whose name should be searched for
 *
 * return in_ifaddr pointer on success, NULL for failure
 */
<<<<<<< HEAD
static struct in_ifaddr *hdd_lookup_ifaddr(hdd_adapter_t *adapter)
=======
static struct in_ifaddr *hdd_lookup_ifaddr(struct hdd_adapter *adapter)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	struct in_ifaddr *ifa;
	struct in_device *in_dev;

	if (!adapter) {
		hdd_err("adapter is null");
		return NULL;
	}

	in_dev = __in_dev_get_rtnl(adapter->dev);
	if (!in_dev) {
		hdd_err("Failed to get in_device");
		return NULL;
	}

	/* lookup address data by interface name */
	for (ifa = in_dev->ifa_list; ifa; ifa = ifa->ifa_next) {
		if (!strcmp(adapter->dev->name, ifa->ifa_label))
			return ifa;
	}

	return NULL;
}

/**
 * hdd_populate_ipv4_addr() - Populates the adapter's IPv4 address
 * @adapter: the adapter whose IPv4 address is desired
 * @ipv4_addr: the address of the array to copy the IPv4 address into
 *
 * return: zero for success; non-zero for failure
 */
<<<<<<< HEAD
static int hdd_populate_ipv4_addr(hdd_adapter_t *adapter, uint8_t *ipv4_addr)
=======
static int hdd_populate_ipv4_addr(struct hdd_adapter *adapter,
				  uint8_t *ipv4_addr)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	struct in_ifaddr *ifa;
	int i;

	if (!adapter) {
		hdd_err("adapter is null");
		return -EINVAL;
	}

	if (!ipv4_addr) {
		hdd_err("ipv4_addr is null");
		return -EINVAL;
	}

	ifa = hdd_lookup_ifaddr(adapter);
	if (!ifa || !ifa->ifa_local) {
		hdd_err("ipv4 address not found");
		return -EINVAL;
	}

	/* convert u32 to byte array */
	for (i = 0; i < 4; i++)
		ipv4_addr[i] = (ifa->ifa_local >> i * 8) & 0xff;

	return 0;
}

/**
 * hdd_set_grat_arp_keepalive() - Enable grat APR keepalive
 * @adapter: the HDD adapter to configure
 *
 * This configures gratuitous APR keepalive based on the adapter's current
 * connection information, specifically IPv4 address and BSSID
 *
 * return: zero for success, non-zero for failure
 */
<<<<<<< HEAD
static int hdd_set_grat_arp_keepalive(hdd_adapter_t *adapter)
{
	QDF_STATUS status;
	int exit_code;
	hdd_context_t *hdd_ctx;
	hdd_station_ctx_t *sta_ctx;
	tSirKeepAliveReq req = {
		.packetType = SIR_KEEP_ALIVE_UNSOLICIT_ARP_RSP,
		.dest_macaddr = QDF_MAC_ADDR_BROADCAST_INITIALIZER,
=======
static int hdd_set_grat_arp_keepalive(struct hdd_adapter *adapter)
{
	QDF_STATUS status;
	int exit_code;
	struct hdd_context *hdd_ctx;
	struct hdd_station_ctx *sta_ctx;
	struct keep_alive_req req = {
		.packetType = SIR_KEEP_ALIVE_UNSOLICIT_ARP_RSP,
		.dest_macaddr = QDF_MAC_ADDR_BCAST_INIT,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	};

	if (!adapter) {
		hdd_err("adapter is null");
		return -EINVAL;
	}

	hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	if (!hdd_ctx) {
		hdd_err("hdd_ctx is null");
		return -EINVAL;
	}

	sta_ctx = WLAN_HDD_GET_STATION_CTX_PTR(adapter);
	if (!sta_ctx) {
		hdd_err("sta_ctx is null");
		return -EINVAL;
	}

	exit_code = hdd_populate_ipv4_addr(adapter, req.hostIpv4Addr);
	if (exit_code) {
		hdd_err("Failed to populate ipv4 address");
		return exit_code;
	}

	/* according to RFC5227, sender/target ip address should be the same */
	qdf_mem_copy(&req.destIpv4Addr, &req.hostIpv4Addr,
		     sizeof(req.destIpv4Addr));

<<<<<<< HEAD
	qdf_copy_macaddr(&req.bssid, &sta_ctx->conn_info.bssId);
	req.timePeriod = hdd_ctx->config->infraStaKeepAlivePeriod;
	req.sessionId = adapter->sessionId;
=======
	qdf_copy_macaddr(&req.bssid, &sta_ctx->conn_info.bssid);
	ucfg_mlme_get_sta_keep_alive_period(hdd_ctx->psoc, &req.timePeriod);
	req.sessionId = adapter->vdev_id;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	hdd_debug("Setting gratuitous ARP keepalive; ipv4_addr:%u.%u.%u.%u",
		 req.hostIpv4Addr[0], req.hostIpv4Addr[1],
		 req.hostIpv4Addr[2], req.hostIpv4Addr[3]);

<<<<<<< HEAD
	status = sme_set_keep_alive(hdd_ctx->hHal, req.sessionId, &req);
=======
	status = sme_set_keep_alive(hdd_ctx->mac_handle, req.sessionId, &req);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	if (QDF_IS_STATUS_ERROR(status)) {
		hdd_err("Failed to set keepalive");
		return qdf_status_to_os_return(status);
	}

	return 0;
}

/**
 * __hdd_ipv4_notifier_work_queue() - IPv4 notification work function
<<<<<<< HEAD
 * @work: registered work item
=======
 * @adapter: adapter whose IP address changed
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *
 * This function performs the work initially trigged by a callback
 * from the IPv4 netdev notifier.  Since this means there has been a
 * change in IPv4 state for the interface, the ARP offload is
 * reconfigured. Also, Updates the HLP IE info with IP address info
 * to fw if LFR3 is enabled
 *
 * Return: None
 */
<<<<<<< HEAD
static void __hdd_ipv4_notifier_work_queue(struct work_struct *work)
{
	hdd_adapter_t *pAdapter =
		container_of(work, hdd_adapter_t, ipv4NotifierWorkQueue);
	hdd_context_t *pHddCtx;
	hdd_station_ctx_t *sta_ctx;
	int status;
	bool ndi_connected;
	bool sta_associated;
	hdd_wext_state_t *wext_state;
	tCsrRoamProfile *roam_profile;
	struct in_ifaddr *ifa;

	hdd_debug("Configuring ARP Offload");

	pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
	status = wlan_hdd_validate_context(pHddCtx);
	if (status)
		return;

	if (!pHddCtx->config->active_mode_offload) {
		hdd_warn("Active mode offload is disabled");
		return;
	}

	ndi_connected = WLAN_HDD_IS_NDI(pAdapter) &&
		WLAN_HDD_IS_NDI_CONNECTED(pAdapter);

	sta_ctx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
	sta_associated = sta_ctx->conn_info.connState ==
		eConnectionState_Associated;

	if (!ndi_connected && !sta_associated)
		return;

	/*
	 * This invocation being part of the IPv4 registration callback,
	 * we are passing second parameter as 2 to avoid registration
	 * of IPv4 notifier again.
	 */
	hdd_conf_arp_offload(pAdapter, true);

	if (pHddCtx->config->sta_keepalive_method == HDD_STA_KEEPALIVE_GRAT_ARP)
		hdd_set_grat_arp_keepalive(pAdapter);

	wext_state = WLAN_HDD_GET_WEXT_STATE_PTR(pAdapter);
	roam_profile = &wext_state->roamProfile;
	ifa = hdd_lookup_ifaddr(pAdapter);

	hdd_debug("FILS Roaming support: %d",
		  pHddCtx->config->is_fils_roaming_supported);

	if (ifa && pHddCtx->config->is_fils_roaming_supported)
		sme_send_hlp_ie_info(pHddCtx->hHal,
				pAdapter->sessionId,
				roam_profile,
				ifa->ifa_local);
}

/**
 * hdd_ipv4_notifier_work_queue() - IP V4 change notifier work handler
 * @work: Pointer to work context
 *
 * Return: none
 */
void hdd_ipv4_notifier_work_queue(struct work_struct *work)
{
	cds_ssr_protect(__func__);
	__hdd_ipv4_notifier_work_queue(work);
	cds_ssr_unprotect(__func__);
=======
static void __hdd_ipv4_notifier_work_queue(struct hdd_adapter *adapter)
{
	struct hdd_context *hdd_ctx;
	int errno;
	struct csr_roam_profile *roam_profile;
	struct in_ifaddr *ifa;
	enum station_keepalive_method val;
	QDF_STATUS status;

	hdd_enter();

	errno = hdd_validate_adapter(adapter);
	if (errno)
		goto exit;

	hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	errno = wlan_hdd_validate_context(hdd_ctx);
	if (errno)
		goto exit;

	hdd_enable_arp_offload(adapter, pmo_ipv4_change_notify);

	status = ucfg_mlme_get_sta_keepalive_method(hdd_ctx->psoc, &val);
	if (QDF_IS_STATUS_ERROR(status))
		goto exit;

	if (val == MLME_STA_KEEPALIVE_GRAT_ARP)
		hdd_set_grat_arp_keepalive(adapter);

	hdd_debug("FILS Roaming support: %d",
		  hdd_ctx->is_fils_roaming_supported);
	roam_profile = hdd_roam_profile(adapter);

	ifa = hdd_lookup_ifaddr(adapter);
	if (ifa && hdd_ctx->is_fils_roaming_supported)
		sme_send_hlp_ie_info(hdd_ctx->mac_handle, adapter->vdev_id,
				     roam_profile, ifa->ifa_local);
	hdd_send_ps_config_to_fw(adapter);
exit:
	hdd_exit();
}

void hdd_ipv4_notifier_work_queue(struct work_struct *work)
{
	struct hdd_adapter *adapter = container_of(work, struct hdd_adapter,
						   ipv4_notifier_work);
	struct osif_vdev_sync *vdev_sync;

	if (osif_vdev_sync_op_start(adapter->dev, &vdev_sync))
		return;

	__hdd_ipv4_notifier_work_queue(adapter);

	osif_vdev_sync_op_stop(vdev_sync);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * __wlan_hdd_ipv4_changed() - IPv4 notifier callback function
<<<<<<< HEAD
 * @nb: notifier block that was registered with the kernel
 * @data: (unused) generic data that was registered with the kernel
 * @arg: (unused) generic argument that was registered with the kernel
=======
 * @net_dev: the net_device whose IP address changed
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *
 * This is a callback function that is registered with the kernel via
 * register_inetaddr_notifier() which allows the driver to be
 * notified when there is an IPv4 address change.
 *
<<<<<<< HEAD
 * Return: NOTIFY_DONE to indicate we don't care what happens with
 *	other callbacks
 */
static int __wlan_hdd_ipv4_changed(struct notifier_block *nb,
				 unsigned long data, void *arg)
{
	struct in_ifaddr *ifa = (struct in_ifaddr *)arg;
	struct net_device *ndev = ifa->ifa_dev->dev;
	hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(ndev);
	hdd_context_t *pHddCtx;
	hdd_station_ctx_t *sta_ctx;
	int status;

	ENTER_DEV(ndev);

	if ((pAdapter == NULL) || (WLAN_HDD_ADAPTER_MAGIC != pAdapter->magic)) {
		hdd_debug("Adapter context is invalid %pK", pAdapter);
		return NOTIFY_DONE;
	}

	if ((pAdapter->dev == ndev) &&
	    (pAdapter->device_mode == QDF_STA_MODE ||
	     pAdapter->device_mode == QDF_P2P_CLIENT_MODE ||
	     pAdapter->device_mode == QDF_NDI_MODE)) {

		pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
		status = wlan_hdd_validate_context(pHddCtx);
		if (0 != status)
			return NOTIFY_DONE;

		/* Ignore if the interface is down */
		if (!(ndev->flags & IFF_UP)) {
			hdd_err("Rcvd change addr request on %s(flags 0x%X)",
				ndev->name, ndev->flags);
			hdd_err("NETDEV Interface is down, ignoring...");
			return NOTIFY_DONE;
		}

		sta_ctx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);
		hdd_debug("invoking sme_dhcp_done_ind");
		sme_dhcp_done_ind(pHddCtx->hHal,
					  pAdapter->sessionId);

		if (!pHddCtx->config->fhostArpOffload) {
			hdd_debug("Offload not enabled ARPOffload=%d",
				pHddCtx->config->fhostArpOffload);
			return NOTIFY_DONE;
		}

		ifa = hdd_lookup_ifaddr(pAdapter);
		if (ifa && ifa->ifa_local)
			schedule_work(&pAdapter->ipv4NotifierWorkQueue);
	}
	EXIT();
	return NOTIFY_DONE;
}

/**
 * wlan_hdd_ipv4_changed() - IPv4 change notifier callback
 * @nb: pointer to notifier block
 * @data: data
 * @arg: arg
 *
 * This is the IPv4 notifier callback function gets invoked
 * if any change in IP and then invoke the function @__wlan_hdd_ipv4_changed
 * to reconfigure the offload parameters.
 *
 * Return: 0 on success, error number otherwise.
 */
int wlan_hdd_ipv4_changed(struct notifier_block *nb,
			unsigned long data, void *arg)
{
	int ret;

	cds_ssr_protect(__func__);
	ret = __wlan_hdd_ipv4_changed(nb, data, arg);
	cds_ssr_unprotect(__func__);

	return ret;
}

/**
 * hdd_conf_arp_offload() - Configure ARP offload
 * @pAdapter: Adapter context for which ARP offload is to be configured
 * @fenable: true : enable ARP offload false : disable arp offload
 *
 * Return:
 *	QDF_STATUS_SUCCESS - on successful operation,
 *	QDF_STATUS_E_FAILURE - on failure of operation
 */
QDF_STATUS hdd_conf_arp_offload(hdd_adapter_t *pAdapter, bool fenable)
{
	struct in_ifaddr *ifa;
	int i = 0;
	tSirHostOffloadReq offLoadRequest;
	hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);

	hdd_debug("fenable = %d", fenable);

	/* In SAP/P2P Go mode, ARP/NS Offload feature capability
	 * is controlled by one bit.
	 */
	if ((QDF_SAP_MODE == pAdapter->device_mode ||
		QDF_P2P_GO_MODE == pAdapter->device_mode) &&
		!pHddCtx->ap_arpns_support) {
		hdd_debug("ARP Offload is not supported in SAP/P2PGO mode");
		return QDF_STATUS_SUCCESS;
	}

	if (fenable) {
		ifa = hdd_lookup_ifaddr(pAdapter);
		if (ifa && ifa->ifa_local) {
			offLoadRequest.offloadType = SIR_IPV4_ARP_REPLY_OFFLOAD;
			offLoadRequest.enableOrDisable = SIR_OFFLOAD_ENABLE;
			hdd_wlan_offload_event(SIR_IPV4_ARP_REPLY_OFFLOAD,
					       SIR_OFFLOAD_ENABLE);

			hdd_debug("Enable ARP offload: filter programmed = %d",
			       offLoadRequest.enableOrDisable);

			/* converting u32 to IPV4 address */
			for (i = 0; i < 4; i++) {
				offLoadRequest.params.hostIpv4Addr[i] =
					(ifa->ifa_local >> (i * 8)) & 0xFF;
			}
			hdd_debug(" Enable SME HostOffload: %d.%d.%d.%d",
			       offLoadRequest.params.hostIpv4Addr[0],
			       offLoadRequest.params.hostIpv4Addr[1],
			       offLoadRequest.params.hostIpv4Addr[2],
			       offLoadRequest.params.hostIpv4Addr[3]);

			if (QDF_STATUS_SUCCESS !=
			    sme_set_host_offload(WLAN_HDD_GET_HAL_CTX(pAdapter),
						 pAdapter->sessionId,
						 &offLoadRequest)) {
				hdd_err("Failed to enable HostOffload feature");
				return QDF_STATUS_E_FAILURE;
			}

			qdf_mutex_acquire(&pAdapter->arp_offload_info_lock);
			pAdapter->arp_offload_info.offload = fenable;
			qdf_mem_copy(pAdapter->arp_offload_info.ipv4,
				     offLoadRequest.params.hostIpv4Addr,
				     SIR_IPV4_ADDR_LEN);
			qdf_mutex_release(&pAdapter->arp_offload_info_lock);
		} else {
			hdd_debug("IP Address is not assigned");
		}

		return QDF_STATUS_SUCCESS;
	}
	hdd_wlan_offload_event(SIR_IPV4_ARP_REPLY_OFFLOAD,
		SIR_OFFLOAD_DISABLE);
	qdf_mem_zero((void *)&offLoadRequest,
			sizeof(tSirHostOffloadReq));
	offLoadRequest.enableOrDisable = SIR_OFFLOAD_DISABLE;
	offLoadRequest.offloadType = SIR_IPV4_ARP_REPLY_OFFLOAD;

	if (QDF_STATUS_SUCCESS !=
	    sme_set_host_offload(WLAN_HDD_GET_HAL_CTX(pAdapter),
				 pAdapter->sessionId, &offLoadRequest)) {
		hdd_err("Failure to disable host offload feature");
		return QDF_STATUS_E_FAILURE;
	}

	qdf_mutex_acquire(&pAdapter->arp_offload_info_lock);
	pAdapter->arp_offload_info.offload = fenable;
	qdf_mutex_release(&pAdapter->arp_offload_info_lock);

	return QDF_STATUS_SUCCESS;
}

int hdd_conf_hw_filter_mode(hdd_adapter_t *adapter, enum hw_filter_mode mode,
			    bool filter_enable)
{
	QDF_STATUS status;

	if (!adapter) {
		hdd_err("adapter is null");
		return -EINVAL;
	}

	status = sme_conf_hw_filter_mode(WLAN_HDD_GET_HAL_CTX(adapter),
					 adapter->sessionId, mode,
					 filter_enable);

	return qdf_status_to_os_return(status);
}

#ifdef WLAN_FEATURE_PACKET_FILTERING
/**
 * wlan_hdd_set_mc_addr_list() - set MC address list in FW
 * @pAdapter: adapter whose MC list is being set
 * @set: flag which indicates if addresses are being set or cleared
 *
 * Returns: 0 on success, errno on failure
 */
int wlan_hdd_set_mc_addr_list(hdd_adapter_t *pAdapter, uint8_t set)
{
	uint8_t i;
	int ret = 0;
	tpSirRcvFltMcAddrList pMulticastAddrs = NULL;
	tHalHandle hHal = NULL;
	hdd_context_t *pHddCtx = (hdd_context_t *) pAdapter->pHddCtx;
	hdd_station_ctx_t *sta_ctx = WLAN_HDD_GET_STATION_CTX_PTR(pAdapter);

	ENTER();

	ret = wlan_hdd_validate_context(pHddCtx);
	if (0 != ret)
		return ret;

	hHal = pHddCtx->hHal;

	if (NULL == hHal) {
		hdd_err("HAL Handle is NULL");
		return -EINVAL;
	}

	if (!sta_ctx) {
		hdd_err("sta_ctx is NULL");
		return -EINVAL;
	}

	/* Check if INI is enabled or not, other wise just return */
	if (!pHddCtx->config->fEnableMCAddrList) {
		hdd_warn("gMCAddrListEnable is not enabled in INI");
		return -EINVAL;
	}
	pMulticastAddrs = qdf_mem_malloc(sizeof(tSirRcvFltMcAddrList));
	if (NULL == pMulticastAddrs) {
		hdd_err("Could not allocate Memory");
		return -ENOMEM;
	}
	pMulticastAddrs->action = set;

	if (set) {
		/*
		 * Following pre-conditions should be satisfied before we
		 * configure the MC address list.
		 */
		if (pAdapter->mc_addr_list.mc_cnt &&
				(((pAdapter->device_mode == QDF_STA_MODE ||
				pAdapter->device_mode == QDF_P2P_CLIENT_MODE) &&
				hdd_conn_is_connected(sta_ctx)) ||
				(WLAN_HDD_IS_NDI(pAdapter) &&
				WLAN_HDD_IS_NDI_CONNECTED(pAdapter)))) {

			pMulticastAddrs->ulMulticastAddrCnt =
				pAdapter->mc_addr_list.mc_cnt;

			for (i = 0; i < pAdapter->mc_addr_list.mc_cnt; i++) {
				memcpy(pMulticastAddrs->multicastAddr[i].bytes,
				       pAdapter->mc_addr_list.addr[i],
				       sizeof(pAdapter->mc_addr_list.addr[i]));
				hdd_debug("%s multicast filter: addr ="
				       MAC_ADDRESS_STR,
				       set ? "setting" : "clearing",
				       MAC_ADDR_ARRAY(pMulticastAddrs->
						      multicastAddr[i].bytes));
			}
			/* Set multicast filter */
			sme_8023_multicast_list(hHal, pAdapter->sessionId,
						pMulticastAddrs);
		} else {
			hdd_debug("MC address list not sent to FW, cnt: %d",
					pAdapter->mc_addr_list.mc_cnt);
		}
	} else {
		/* Need to clear only if it was previously configured */
		if (pAdapter->mc_addr_list.isFilterApplied) {
			pMulticastAddrs->ulMulticastAddrCnt =
				pAdapter->mc_addr_list.mc_cnt;
			for (i = 0; i < pAdapter->mc_addr_list.mc_cnt; i++) {
				memcpy(pMulticastAddrs->multicastAddr[i].bytes,
				       pAdapter->mc_addr_list.addr[i],
				       sizeof(pAdapter->mc_addr_list.addr[i]));
			}
			sme_8023_multicast_list(hHal, pAdapter->sessionId,
						pMulticastAddrs);
		}

	}
	/* MAddrCnt is MulticastAddrCnt */
	hdd_debug("smeSessionId:%d; set:%d; MCAdddrCnt :%d",
	       pAdapter->sessionId, set,
	       pMulticastAddrs->ulMulticastAddrCnt);

	pAdapter->mc_addr_list.isFilterApplied = set ? true : false;
	qdf_mem_free(pMulticastAddrs);

	EXIT();

	return ret;
}
#endif

/**
 * hdd_conf_suspend_ind() - Send Suspend notification
 * @pHddCtx: HDD Global context
 * @pAdapter: adapter being suspended
 * @callback: callback function to be called upon completion
 * @callbackContext: callback context to be passed back to callback function
 *
 * Return: None.
 */
static void hdd_send_suspend_ind(hdd_context_t *pHddCtx,
				uint32_t conn_state_mask,
				 void (*callback)(void *callbackContext,
						  bool suspended),
				 void *callbackContext)
{
	QDF_STATUS qdf_ret_status = QDF_STATUS_E_FAILURE;

	hdd_debug("send wlan suspend indication");

	qdf_ret_status =
		sme_configure_suspend_ind(pHddCtx->hHal, conn_state_mask,
					  callback, callbackContext);

	if (QDF_STATUS_SUCCESS != qdf_ret_status)
		hdd_err("sme_configure_suspend_ind returned failure %d",
		       qdf_ret_status);
}

/**
 * hdd_conf_suspend_ind() - Send Resume notification
 * @pAdapter: adapter being resumed
 *
 * Return: None.
 */
static void hdd_conf_resume_ind(hdd_adapter_t *pAdapter)
{
	hdd_context_t *pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
	QDF_STATUS qdf_ret_status = QDF_STATUS_E_FAILURE;

	qdf_ret_status = sme_configure_resume_req(pHddCtx->hHal, NULL);

	if (QDF_STATUS_SUCCESS != qdf_ret_status)
		hdd_err("sme_configure_resume_req return failure %d",
			qdf_ret_status);

	hdd_debug("send wlan resume indication");
	/* Disable supported OffLoads */
	hdd_conf_hostoffload(pAdapter, false);
=======
 * Return: None
 */
static void __wlan_hdd_ipv4_changed(struct net_device *net_dev)
{
	struct in_ifaddr *ifa;
	struct hdd_adapter *adapter = WLAN_HDD_GET_PRIV_PTR(net_dev);
	struct hdd_context *hdd_ctx;
	int errno;

	hdd_enter_dev(net_dev);

	errno = hdd_validate_adapter(adapter);
	if (errno || adapter->dev != net_dev)
		goto exit;

	hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	errno = wlan_hdd_validate_context(hdd_ctx);
	if (errno)
		goto exit;

	if (adapter->device_mode == QDF_STA_MODE ||
	    adapter->device_mode == QDF_P2P_CLIENT_MODE) {
		hdd_debug("invoking sme_dhcp_done_ind");
		sme_dhcp_done_ind(hdd_ctx->mac_handle, adapter->vdev_id);

		if (!ucfg_pmo_is_arp_offload_enabled(hdd_ctx->psoc)) {
			hdd_debug("Offload not enabled");
			goto exit;
		}

		ifa = hdd_lookup_ifaddr(adapter);
		if (ifa && ifa->ifa_local)
			schedule_work(&adapter->ipv4_notifier_work);
	}

exit:
	hdd_exit();
}

int wlan_hdd_ipv4_changed(struct notifier_block *nb,
			  unsigned long data, void *context)
{
	struct in_ifaddr *ifa = context;
	struct net_device *net_dev = ifa->ifa_dev->dev;
	struct osif_vdev_sync *vdev_sync;

	if (osif_vdev_sync_op_start(net_dev, &vdev_sync))
		return NOTIFY_DONE;

	__wlan_hdd_ipv4_changed(net_dev);

	osif_vdev_sync_op_stop(vdev_sync);

	return NOTIFY_DONE;
}

#ifdef FEATURE_RUNTIME_PM
int wlan_hdd_pm_qos_notify(struct notifier_block *nb, unsigned long curr_val,
			   void *context)
{
	struct hdd_context *hdd_ctx = container_of(nb, struct hdd_context,
						   pm_qos_notifier);
	void *hif_ctx;

	if (hdd_ctx->driver_status != DRIVER_MODULES_ENABLED) {
		hdd_debug_rl("Driver Module closed; skipping pm qos notify");
		return 0;
	}

	hif_ctx = cds_get_context(QDF_MODULE_ID_HIF);
	if (!hif_ctx) {
		hdd_err("Hif context is Null");
		return -EINVAL;
	}

	hdd_debug("PM QOS update: runtime_pm_prevented %d Current value: %ld",
		  hdd_ctx->runtime_pm_prevented, curr_val);
	qdf_spin_lock_irqsave(&hdd_ctx->pm_qos_lock);

	if (!hdd_ctx->runtime_pm_prevented &&
	    curr_val != PM_QOS_CPU_DMA_LAT_DEFAULT_VALUE) {
		hif_pm_runtime_get_noresume(hif_ctx, RTPM_ID_QOS_NOTIFY);
		hdd_ctx->runtime_pm_prevented = true;
	} else if (hdd_ctx->runtime_pm_prevented &&
		   curr_val == PM_QOS_CPU_DMA_LAT_DEFAULT_VALUE) {
		hif_pm_runtime_put(hif_ctx, RTPM_ID_QOS_NOTIFY);
		hdd_ctx->runtime_pm_prevented = false;
	}

	qdf_spin_unlock_irqrestore(&hdd_ctx->pm_qos_lock);

	return NOTIFY_DONE;
}
#endif

/**
 * hdd_get_ipv4_local_interface() - get ipv4 local interafce from iface list
 * @adapter: Adapter context for which ARP offload is to be configured
 *
 * Return:
 *	ifa - on successful operation,
 *	NULL - on failure of operation
 */
static struct in_ifaddr *hdd_get_ipv4_local_interface(
				struct hdd_adapter *adapter)
{
	struct in_ifaddr **ifap = NULL;
	struct in_ifaddr *ifa = NULL;
	struct in_device *in_dev;

	in_dev = __in_dev_get_rtnl(adapter->dev);
	if (in_dev) {
		for (ifap = &in_dev->ifa_list; (ifa = *ifap) != NULL;
			     ifap = &ifa->ifa_next) {
			if (!strcmp(adapter->dev->name, ifa->ifa_label)) {
				/* if match break */
				return ifa;
			}
		}
	}
	ifa = NULL;

	return ifa;
}

void hdd_enable_arp_offload(struct hdd_adapter *adapter,
			    enum pmo_offload_trigger trigger)
{
	struct hdd_context *hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	struct wlan_objmgr_psoc *psoc = hdd_ctx->psoc;
	QDF_STATUS status;
	struct pmo_arp_req *arp_req;
	struct in_ifaddr *ifa;

	arp_req = qdf_mem_malloc(sizeof(*arp_req));
	if (!arp_req)
		return;

	arp_req->psoc = psoc;
	arp_req->vdev_id = adapter->vdev_id;
	arp_req->trigger = trigger;

	status = ucfg_pmo_check_arp_offload(psoc, trigger, adapter->vdev_id);
	if (QDF_IS_STATUS_ERROR(status)) {
		hdd_debug("ARP offload not required");
		goto free_req;
	}

	ifa = hdd_get_ipv4_local_interface(adapter);
	if (!ifa || !ifa->ifa_local) {
		hdd_info("IP Address is not assigned");
		status = QDF_STATUS_NOT_INITIALIZED;
		goto free_req;
	}

	arp_req->ipv4_addr = (uint32_t)ifa->ifa_local;

	status = ucfg_pmo_cache_arp_offload_req(arp_req);
	if (QDF_IS_STATUS_ERROR(status)) {
		hdd_err("failed to cache arp offload req; status:%d", status);
		goto free_req;
	}

	status = ucfg_pmo_enable_arp_offload_in_fwr(adapter->vdev, trigger);
	if (QDF_IS_STATUS_ERROR(status)) {
		hdd_err("failed arp offload config in fw; status:%d", status);
		goto free_req;
	}

	hdd_wlan_offload_event(PMO_IPV4_ARP_REPLY_OFFLOAD, PMO_OFFLOAD_ENABLE);

free_req:
	qdf_mem_free(arp_req);
}

void hdd_disable_arp_offload(struct hdd_adapter *adapter,
		enum pmo_offload_trigger trigger)
{
	QDF_STATUS status;
	struct hdd_context *hdd_ctx = WLAN_HDD_GET_CTX(adapter);

	status = ucfg_pmo_check_arp_offload(hdd_ctx->psoc, trigger,
					    adapter->vdev_id);
	if (status != QDF_STATUS_SUCCESS) {
		hdd_debug("Flushing of ARP offload not required");
		return;
	}

	status = ucfg_pmo_flush_arp_offload_req(adapter->vdev);
	if (status != QDF_STATUS_SUCCESS) {
		hdd_err("Failed to flush arp Offload");
		return;
	}

	status = ucfg_pmo_disable_arp_offload_in_fwr(adapter->vdev,
						     trigger);
	if (status == QDF_STATUS_SUCCESS)
		hdd_wlan_offload_event(PMO_IPV4_ARP_REPLY_OFFLOAD,
			PMO_OFFLOAD_DISABLE);
	else
		hdd_info("fail to disable arp offload");
}

void hdd_enable_mc_addr_filtering(struct hdd_adapter *adapter,
				  enum pmo_offload_trigger trigger)
{
	struct hdd_context *hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	QDF_STATUS status;

	if (wlan_hdd_validate_context(hdd_ctx))
		return;

	if (!hdd_adapter_is_connected_sta(adapter))
		return;

	status = ucfg_pmo_enable_mc_addr_filtering_in_fwr(hdd_ctx->psoc,
							  adapter->vdev_id,
							  trigger);
	if (QDF_IS_STATUS_ERROR(status))
		hdd_debug("failed to enable mc list; status:%d", status);

}

void hdd_disable_mc_addr_filtering(struct hdd_adapter *adapter,
				   enum pmo_offload_trigger trigger)
{
	struct hdd_context *hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	QDF_STATUS status;

	if (wlan_hdd_validate_context(hdd_ctx))
		return;

	if (!hdd_adapter_is_connected_sta(adapter))
		return;

	status = ucfg_pmo_disable_mc_addr_filtering_in_fwr(hdd_ctx->psoc,
							   adapter->vdev_id,
							   trigger);
	if (QDF_IS_STATUS_ERROR(status))
		hdd_err("failed to disable mc list; status:%d", status);
}

int hdd_cache_mc_addr_list(struct pmo_mc_addr_list_params *mc_list_config)
{
	QDF_STATUS status;

	status = ucfg_pmo_cache_mc_addr_list(mc_list_config);

	return qdf_status_to_os_return(status);
}

void hdd_disable_and_flush_mc_addr_list(struct hdd_adapter *adapter,
					enum pmo_offload_trigger trigger)
{
	struct hdd_context *hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	QDF_STATUS status;

	if (!hdd_adapter_is_connected_sta(adapter))
		goto flush_mc_list;

	/* disable mc list first because the mc list is cached in PMO */
	status = ucfg_pmo_disable_mc_addr_filtering_in_fwr(hdd_ctx->psoc,
							   adapter->vdev_id,
							   trigger);
	if (QDF_IS_STATUS_ERROR(status))
		hdd_debug("failed to disable mc list; status:%d", status);

flush_mc_list:
	status = ucfg_pmo_flush_mc_addr_list(hdd_ctx->psoc,
					     adapter->vdev_id);
	if (QDF_IS_STATUS_ERROR(status))
		hdd_debug("failed to flush mc list; status:%d", status);

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * hdd_update_conn_state_mask(): record info needed by wma_suspend_req
 * @adapter: adapter to get info from
 * @conn_state_mask: mask of connection info
 *
 * currently only need to send connection info.
 */
<<<<<<< HEAD
static void
hdd_update_conn_state_mask(hdd_adapter_t *adapter, uint32_t *conn_state_mask)
{

	eConnectionState connState;
	hdd_station_ctx_t *sta_ctx;

	sta_ctx = WLAN_HDD_GET_STATION_CTX_PTR(adapter);

	connState = sta_ctx->conn_info.connState;

	if (connState == eConnectionState_Associated ||
			connState == eConnectionState_IbssConnected)
		*conn_state_mask |= (1 << adapter->sessionId);
=======
static void hdd_update_conn_state_mask(struct hdd_adapter *adapter,
				       uint32_t *conn_state_mask)
{

	eConnectionState conn_state;
	struct hdd_station_ctx *sta_ctx;

	sta_ctx = WLAN_HDD_GET_STATION_CTX_PTR(adapter);

	conn_state = sta_ctx->conn_info.conn_state;

	if (conn_state == eConnectionState_Associated ||
			conn_state == eConnectionState_IbssConnected)
		*conn_state_mask |= (1 << adapter->vdev_id);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * hdd_suspend_wlan() - Driver suspend function
 * @callback: Callback function to invoke when driver is ready to suspend
 * @callbackContext: Context to pass back to @callback function
 *
<<<<<<< HEAD
 * Return: None.
 */
static void
hdd_suspend_wlan(void (*callback)(void *callbackContext, bool suspended),
		 void *callbackContext)
{
	hdd_context_t *pHddCtx;

	QDF_STATUS status;
	hdd_adapter_t *pAdapter = NULL;
	hdd_adapter_list_node_t *pAdapterNode = NULL, *pNext = NULL;
=======
 * Return: 0 on success else error code.
 */
static int
hdd_suspend_wlan(void)
{
	struct hdd_context *hdd_ctx;
	QDF_STATUS status;
	struct hdd_adapter *adapter = NULL, *next_adapter = NULL;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	uint32_t conn_state_mask = 0;

	hdd_info("WLAN being suspended by OS");

<<<<<<< HEAD
	pHddCtx = cds_get_context(QDF_MODULE_ID_HDD);
	if (!pHddCtx) {
		hdd_err("HDD context is Null");
		return;
=======
	hdd_ctx = cds_get_context(QDF_MODULE_ID_HDD);
	if (!hdd_ctx) {
		hdd_err("HDD context is Null");
		return -EINVAL;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	}

	if (cds_is_driver_recovering() || cds_is_driver_in_bad_state()) {
		hdd_info("Recovery in Progress. State: 0x%x Ignore suspend!!!",
			 cds_get_driver_state());
<<<<<<< HEAD
		return;
	}

	status = hdd_get_front_adapter(pHddCtx, &pAdapterNode);
	while (NULL != pAdapterNode && QDF_STATUS_SUCCESS == status) {
		pAdapter = pAdapterNode->pAdapter;

		/* stop all TX queues before suspend */
		hdd_info("Disabling queues for dev mode %s",
			 hdd_device_mode_to_string(pAdapter->device_mode));
		wlan_hdd_netif_queue_control(pAdapter,
					     WLAN_STOP_ALL_NETIF_QUEUE,
					     WLAN_CONTROL_PATH);

		if (pAdapter->device_mode == QDF_STA_MODE)
			status = hdd_enable_default_pkt_filters(pAdapter);
		/* Configure supported OffLoads */
		hdd_conf_hostoffload(pAdapter, true);

		hdd_update_conn_state_mask(pAdapter, &conn_state_mask);

		status = hdd_get_next_adapter(pHddCtx, pAdapterNode, &pNext);

		pAdapterNode = pNext;
	}

	hdd_send_suspend_ind(pHddCtx, conn_state_mask, callback,
			callbackContext);

	pHddCtx->hdd_wlan_suspended = true;
	hdd_wlan_suspend_resume_event(HDD_WLAN_EARLY_SUSPEND);
=======
		return -EINVAL;
	}

	hdd_for_each_adapter_dev_held_safe(hdd_ctx, adapter, next_adapter,
					   NET_DEV_HOLD_SUSPEND_WLAN) {
		if (wlan_hdd_validate_vdev_id(adapter->vdev_id)) {
			hdd_adapter_dev_put_debug(adapter,
						  NET_DEV_HOLD_SUSPEND_WLAN);
			continue;
		}

		/* stop all TX queues before suspend */
		hdd_debug("Disabling queues for dev mode %s",
			  qdf_opmode_str(adapter->device_mode));
		wlan_hdd_netif_queue_control(adapter,
					     WLAN_STOP_ALL_NETIF_QUEUE,
					     WLAN_CONTROL_PATH);

		if (adapter->device_mode == QDF_STA_MODE)
			status = hdd_enable_default_pkt_filters(adapter);

		/* Configure supported OffLoads */
		hdd_enable_host_offloads(adapter, pmo_apps_suspend);
		hdd_update_conn_state_mask(adapter, &conn_state_mask);
		hdd_adapter_dev_put_debug(adapter, NET_DEV_HOLD_SUSPEND_WLAN);
	}

	status = ucfg_pmo_psoc_user_space_suspend_req(hdd_ctx->psoc,
						      QDF_SYSTEM_SUSPEND);
	if (status != QDF_STATUS_SUCCESS)
		return -EAGAIN;

	hdd_ctx->hdd_wlan_suspended = true;

	hdd_configure_sar_sleep_index(hdd_ctx);

	hdd_wlan_suspend_resume_event(HDD_WLAN_EARLY_SUSPEND);

	return 0;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * hdd_resume_wlan() - Driver resume function
 *
<<<<<<< HEAD
 * Return: None.
 */
static void hdd_resume_wlan(void)
{
	hdd_context_t *pHddCtx;
	hdd_adapter_t *pAdapter = NULL;
	hdd_adapter_list_node_t *pAdapterNode = NULL, *pNext = NULL;
=======
 * Return: 0 on success else error code.
 */
static int hdd_resume_wlan(void)
{
	struct hdd_context *hdd_ctx;
	struct hdd_adapter *adapter, *next_adapter = NULL;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	QDF_STATUS status;

	hdd_info("WLAN being resumed by OS");

<<<<<<< HEAD
	pHddCtx = cds_get_context(QDF_MODULE_ID_HDD);
	if (!pHddCtx) {
		hdd_err("HDD context is Null");
		return;
=======
	hdd_ctx = cds_get_context(QDF_MODULE_ID_HDD);
	if (!hdd_ctx) {
		hdd_err("HDD context is Null");
		return -EINVAL;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	}

	if (cds_is_driver_recovering() || cds_is_driver_in_bad_state()) {
		hdd_info("Recovery in Progress. State: 0x%x Ignore resume!!!",
			 cds_get_driver_state());
<<<<<<< HEAD
		return;
	}

	pHddCtx->hdd_wlan_suspended = false;
	hdd_wlan_suspend_resume_event(HDD_WLAN_EARLY_RESUME);

	/*loop through all adapters. Concurrency */
	status = hdd_get_front_adapter(pHddCtx, &pAdapterNode);

	while (NULL != pAdapterNode && QDF_STATUS_SUCCESS == status) {
		pAdapter = pAdapterNode->pAdapter;

		/* wake the tx queues */
		hdd_info("Enabling queues for dev mode %s",
			 hdd_device_mode_to_string(pAdapter->device_mode));
		wlan_hdd_netif_queue_control(pAdapter,
					WLAN_WAKE_ALL_NETIF_QUEUE,
					WLAN_CONTROL_PATH);

		if (pAdapter->device_mode == QDF_STA_MODE)
			status = hdd_disable_default_pkt_filters(pAdapter);
		hdd_conf_resume_ind(pAdapter);

		status = hdd_get_next_adapter(pHddCtx, pAdapterNode, &pNext);
		pAdapterNode = pNext;
	}
	hdd_ipa_resume(pHddCtx);
}

/**
 * hdd_svc_fw_shutdown_ind() - API to send FW SHUTDOWN IND to Userspace
 *
 * @dev: Device Pointer
 *
 * Return: None
 */
void hdd_svc_fw_shutdown_ind(struct device *dev)
{
	hdd_context_t *hdd_ctx;
	v_CONTEXT_t g_context;

	g_context = cds_get_global_context();

	if (!g_context)
		return;
=======
		return -EINVAL;
	}

	hdd_ctx->hdd_wlan_suspended = false;
	hdd_wlan_suspend_resume_event(HDD_WLAN_EARLY_RESUME);

	/*loop through all adapters. Concurrency */
	hdd_for_each_adapter_dev_held_safe(hdd_ctx, adapter, next_adapter,
					   NET_DEV_HOLD_RESUME_WLAN) {
		if (wlan_hdd_validate_vdev_id(adapter->vdev_id)) {
			hdd_adapter_dev_put_debug(adapter,
						  NET_DEV_HOLD_RESUME_WLAN);
			continue;
		}

		/* Disable supported OffLoads */
		hdd_disable_host_offloads(adapter, pmo_apps_resume);

		/* wake the tx queues */
		hdd_debug("Enabling queues for dev mode %s",
			  qdf_opmode_str(adapter->device_mode));
		wlan_hdd_netif_queue_control(adapter,
					WLAN_WAKE_ALL_NETIF_QUEUE,
					WLAN_CONTROL_PATH);

		if (adapter->device_mode == QDF_STA_MODE)
			status = hdd_disable_default_pkt_filters(adapter);

		hdd_adapter_dev_put_debug(adapter, NET_DEV_HOLD_RESUME_WLAN);
	}

	ucfg_ipa_resume(hdd_ctx->pdev);
	status = ucfg_pmo_psoc_user_space_resume_req(hdd_ctx->psoc,
						     QDF_SYSTEM_SUSPEND);
	if (QDF_IS_STATUS_ERROR(status))
		return qdf_status_to_os_return(status);

	hdd_configure_sar_resume_index(hdd_ctx);

	return 0;
}

void hdd_svc_fw_shutdown_ind(struct device *dev)
{
	struct hdd_context *hdd_ctx;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	hdd_ctx = cds_get_context(QDF_MODULE_ID_HDD);

	hdd_ctx ? wlan_hdd_send_svc_nlink_msg(hdd_ctx->radio_index,
					      WLAN_SVC_FW_SHUTDOWN_IND,
					      NULL, 0) : 0;
}

/**
 * hdd_ssr_restart_sap() - restart sap on SSR
 * @hdd_ctx:   hdd context
 *
 * Return:     nothing
 */
<<<<<<< HEAD
static void hdd_ssr_restart_sap(hdd_context_t *hdd_ctx)
{
	QDF_STATUS  status;
	hdd_adapter_list_node_t *adapter_node = NULL, *next = NULL;
	hdd_adapter_t *adapter;

	ENTER();

	status =  hdd_get_front_adapter(hdd_ctx, &adapter_node);
	while (NULL != adapter_node && QDF_STATUS_SUCCESS == status) {
		adapter = adapter_node->pAdapter;
		if (adapter && adapter->device_mode == QDF_SAP_MODE) {
=======
static void hdd_ssr_restart_sap(struct hdd_context *hdd_ctx)
{
	struct hdd_adapter *adapter, *next_adapter = NULL;

	hdd_enter();

	hdd_for_each_adapter_dev_held_safe(hdd_ctx, adapter, next_adapter,
					   NET_DEV_HOLD_SSR_RESTART_SAP) {
		if (adapter->device_mode == QDF_SAP_MODE) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			if (test_bit(SOFTAP_INIT_DONE, &adapter->event_flags)) {
				hdd_debug("Restart prev SAP session");
				wlan_hdd_start_sap(adapter, true);
			}
		}
<<<<<<< HEAD
		status = hdd_get_next_adapter(hdd_ctx, adapter_node, &next);
		adapter_node = next;
	}

	EXIT();
}

/**
 * hdd_wlan_shutdown() - HDD SSR shutdown function
 *
 * This function is called by the HIF to shutdown the driver during SSR.
 *
 * Return: QDF_STATUS_SUCCESS if the driver was shut down,
 *	or an error status otherwise
 */
QDF_STATUS hdd_wlan_shutdown(void)
{
	v_CONTEXT_t p_cds_context = NULL;
	hdd_context_t *pHddCtx;
	p_cds_sched_context cds_sched_context = NULL;

	hdd_info("WLAN driver shutting down!");

	/* Get the global CDS context. */
	p_cds_context = cds_get_global_context();
	if (!p_cds_context) {
		hdd_err("Global CDS context is Null");
		return QDF_STATUS_E_FAILURE;
	}

	/* Get the HDD context. */
	pHddCtx = cds_get_context(QDF_MODULE_ID_HDD);
	if (!pHddCtx) {
=======
		hdd_adapter_dev_put_debug(adapter,
					  NET_DEV_HOLD_SSR_RESTART_SAP);
	}

	hdd_exit();
}

QDF_STATUS hdd_wlan_shutdown(void)
{
	struct hdd_context *hdd_ctx;
	void *soc = cds_get_context(QDF_MODULE_ID_SOC);

	hdd_info("WLAN driver shutting down!");

	/* Get the HDD context. */
	hdd_ctx = cds_get_context(QDF_MODULE_ID_HDD);
	if (!hdd_ctx) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		hdd_err("HDD context is Null");
		return QDF_STATUS_E_FAILURE;
	}

<<<<<<< HEAD
	pHddCtx->is_ssr_in_progress = true;
	cds_set_connection_in_progress(false);

	cds_clear_concurrent_session_count();

	hdd_debug("Invoking packetdump deregistration API");
	wlan_deregister_txrx_packetdump();
=======
	hdd_set_connection_in_progress(false);
	policy_mgr_clear_concurrent_session_count(hdd_ctx->psoc);

	hdd_debug("Invoking packetdump deregistration API");
	wlan_deregister_txrx_packetdump(OL_TXRX_PDEV_ID);

	/* resume wlan threads before adapter reset which does vdev destroy */
	if (hdd_ctx->is_scheduler_suspended) {
		scheduler_resume();
		hdd_ctx->is_scheduler_suspended = false;
		hdd_ctx->is_wiphy_suspended = false;
	}

	wlan_hdd_rx_thread_resume(hdd_ctx);

	dp_txrx_resume(cds_get_context(QDF_MODULE_ID_SOC));

	if (cds_is_pktcapture_enabled())
		wlan_hdd_mon_thread_resume(hdd_ctx);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	/*
	 * After SSR, FW clear its txrx stats. In host,
	 * as adapter is intact so those counts are still
	 * available. Now if agains Set stats command comes,
	 * then host will increment its counts start from its
	 * last saved value, i.e., count before SSR, and FW will
	 * increment its count from 0. This will finally sends a
	 * mismatch of packet counts b/w host and FW to framework
	 * that will create ambiquity. Therfore, Resetting the host
	 * counts here so that after SSR both FW and host start
	 * increment their counts from 0.
	 */
<<<<<<< HEAD
	hdd_reset_all_adapters_connectivity_stats(pHddCtx);

	hdd_reset_all_adapters(pHddCtx);

	/* Flush cached rx frame queue */
	ol_txrx_flush_cache_rx_queue();

	/* De-register the HDD callbacks */
	hdd_deregister_cb(pHddCtx);

	cds_sched_context = get_cds_sched_ctxt();

	/* Wakeup all driver threads */
	if (true == pHddCtx->isMcThreadSuspended) {
		complete(&cds_sched_context->ResumeMcEvent);
		pHddCtx->isMcThreadSuspended = false;
		pHddCtx->isWiphySuspended = false;
	}
#ifdef QCA_CONFIG_SMP
	if (true == pHddCtx->is_ol_rx_thread_suspended) {
		complete(&cds_sched_context->ol_resume_rx_event);
		pHddCtx->is_ol_rx_thread_suspended = false;
	}
#endif
	if (cds_get_pktcap_mode_enable() &&
	    pHddCtx->is_ol_mon_thread_suspended) {
		complete(&cds_sched_context->ol_resume_mon_event);
		pHddCtx->is_ol_mon_thread_suspended = false;
	}

	hdd_ipa_uc_ssr_deinit();

	qdf_mc_timer_stop(&pHddCtx->tdls_source_timer);

	hdd_bus_bw_compute_timer_stop(pHddCtx);

	hdd_wlan_stop_modules(pHddCtx, false);

	hdd_lpass_notify_stop(pHddCtx);

	hdd_info("WLAN driver shutdown complete");
=======
	hdd_reset_all_adapters_connectivity_stats(hdd_ctx);

	hdd_reset_all_adapters(hdd_ctx);

	ucfg_ipa_uc_ssr_cleanup(hdd_ctx->pdev);

	/* Flush cached rx frame queue */
	if (soc)
		cdp_flush_cache_rx_queue(soc);

	/* De-register the HDD callbacks */
	hdd_deregister_cb(hdd_ctx);

	hdd_wlan_stop_modules(hdd_ctx, false);

	hdd_lpass_notify_stop(hdd_ctx);

	hdd_info("WLAN driver shutdown complete");

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	return QDF_STATUS_SUCCESS;
}

#ifdef FEATURE_WLAN_DIAG_SUPPORT
/**
 * hdd_wlan_ssr_reinit_event()- send ssr reinit state
 *
 * This Function send send ssr reinit state diag event
 *
 * Return: void.
 */
static void hdd_wlan_ssr_reinit_event(void)
{
	WLAN_HOST_DIAG_EVENT_DEF(ssr_reinit, struct host_event_wlan_ssr_reinit);
	qdf_mem_zero(&ssr_reinit, sizeof(ssr_reinit));
	ssr_reinit.status = SSR_SUB_SYSTEM_REINIT;
	WLAN_HOST_DIAG_EVENT_REPORT(&ssr_reinit,
					EVENT_WLAN_SSR_REINIT_SUBSYSTEM);
}
#else
static inline void hdd_wlan_ssr_reinit_event(void)
{

}
#endif

/**
 * hdd_send_default_scan_ies - send default scan ies to fw
 *
 * This function is used to send default scan ies to fw
 * in case of wlan re-init
 *
 * Return: void
 */
<<<<<<< HEAD
static void hdd_send_default_scan_ies(hdd_context_t *hdd_ctx)
{
	hdd_adapter_list_node_t *adapter_node, *next;
	hdd_adapter_t *adapter;
	QDF_STATUS status;

	status = hdd_get_front_adapter(hdd_ctx, &adapter_node);
	while (NULL != adapter_node && QDF_STATUS_SUCCESS == status) {
		adapter = adapter_node->pAdapter;
=======
static void hdd_send_default_scan_ies(struct hdd_context *hdd_ctx)
{
	struct hdd_adapter *adapter, *next_adapter = NULL;

	hdd_for_each_adapter_dev_held_safe(hdd_ctx, adapter, next_adapter,
					   NET_DEV_HOLD_SEND_DEFAULT_SCAN_IES) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		if (hdd_is_interface_up(adapter) &&
		    (adapter->device_mode == QDF_STA_MODE ||
		    adapter->device_mode == QDF_P2P_DEVICE_MODE) &&
		    adapter->scan_info.default_scan_ies) {
<<<<<<< HEAD
			sme_set_default_scan_ie(hdd_ctx->hHal,
				      adapter->sessionId,
				      adapter->scan_info.default_scan_ies,
				      adapter->scan_info.default_scan_ies_len);
		}
		status = hdd_get_next_adapter(hdd_ctx, adapter_node,
					      &next);
		adapter_node = next;
	}
}

void hdd_is_interface_down_during_ssr(hdd_context_t *hdd_ctx)
{
	hdd_adapter_t *adapter = NULL;
	hdd_adapter_list_node_t *adapternode = NULL, *pnext = NULL;
	QDF_STATUS status;

	ENTER();

	status = hdd_get_front_adapter(hdd_ctx, &adapternode);
	while (NULL != adapternode && QDF_STATUS_SUCCESS == status) {
		adapter = adapternode->pAdapter;
		if (test_bit(DOWN_DURING_SSR, &adapter->event_flags)) {
			clear_bit(DOWN_DURING_SSR, &adapter->event_flags);
			hdd_stop_adapter(hdd_ctx, adapter, true);
			clear_bit(DEVICE_IFACE_OPENED, &adapter->event_flags);
		}
		status = hdd_get_next_adapter(hdd_ctx, adapternode, &pnext);
		adapternode = pnext;
	}

	EXIT();
}

/**
 * hdd_wlan_re_init() - HDD SSR re-init function
 *
 * This function is called by the HIF to re-initialize the driver after SSR.
 *
 * Return: QDF_STATUS_SUCCESS if the driver was re-initialized,
 *	or an error status otherwise
 */
QDF_STATUS hdd_wlan_re_init(void)
{

	v_CONTEXT_t p_cds_context = NULL;
	hdd_context_t *pHddCtx = NULL;
	hdd_adapter_t *pAdapter;
	int ret;
	bool bug_on_reinit_failure = CFG_BUG_ON_REINIT_FAILURE_DEFAULT;

	hdd_prevent_suspend(WIFI_POWER_EVENT_WAKELOCK_DRIVER_REINIT);

	/* Get the CDS context */
	p_cds_context = cds_get_global_context();
	if (p_cds_context == NULL) {
		hdd_err("Failed cds_get_global_context");
		goto err_re_init;
	}

	/* Get the HDD context */
	pHddCtx = cds_get_context(QDF_MODULE_ID_HDD);
	if (!pHddCtx) {
		hdd_err("HDD context is Null");
		goto err_re_init;
	}
	bug_on_reinit_failure = pHddCtx->config->bug_on_reinit_failure;

	pAdapter = hdd_get_first_valid_adapter();
	if (!pAdapter)
		hdd_err("Failed to get adapter");

	if (pHddCtx->config->enable_dp_trace)
		hdd_dp_trace_init(pHddCtx->config);

	ret = hdd_wlan_start_modules(pHddCtx, pAdapter, true);
=======
			sme_set_default_scan_ie(hdd_ctx->mac_handle,
				      adapter->vdev_id,
				      adapter->scan_info.default_scan_ies,
				      adapter->scan_info.default_scan_ies_len);
		}
		hdd_adapter_dev_put_debug(adapter,
					  NET_DEV_HOLD_SEND_DEFAULT_SCAN_IES);
	}
}

/**
 * hdd_is_interface_down_during_ssr - Check if the interface went down during
 * SSR
 * @hdd_ctx: HDD context
 *
 * Check if any of the interface went down while the device is recovering.
 * If the interface went down close the session.
 */
static void hdd_is_interface_down_during_ssr(struct hdd_context *hdd_ctx)
{
	struct hdd_adapter *adapter = NULL, *pnext = NULL;
	QDF_STATUS status;

	hdd_enter();

	status = hdd_get_front_adapter(hdd_ctx, &adapter);
	while (adapter && status == QDF_STATUS_SUCCESS) {
		if (test_bit(DOWN_DURING_SSR, &adapter->event_flags)) {
			clear_bit(DOWN_DURING_SSR, &adapter->event_flags);
			hdd_stop_adapter(hdd_ctx, adapter);
			hdd_deinit_adapter(hdd_ctx, adapter, true);
			clear_bit(DEVICE_IFACE_OPENED, &adapter->event_flags);
		}
		status = hdd_get_next_adapter(hdd_ctx, adapter, &pnext);
		adapter = pnext;
	}

	hdd_exit();
}

/**
 * hdd_restore_sar_config - Restore the saved SAR config after SSR
 * @hdd_ctx: HDD context
 *
 * Restore the SAR config that was lost during SSR.
 *
 * Return: None
 */
static void hdd_restore_sar_config(struct hdd_context *hdd_ctx)
{
	QDF_STATUS status;

	if (!hdd_ctx->sar_cmd_params)
		return;

	status = sme_set_sar_power_limits(hdd_ctx->mac_handle,
					  hdd_ctx->sar_cmd_params);
	if (QDF_IS_STATUS_ERROR(status))
		hdd_err("Unable to configured SAR after SSR");
}

QDF_STATUS hdd_wlan_re_init(void)
{
	struct hdd_context *hdd_ctx = NULL;
	struct hdd_adapter *adapter;
	int ret;
	bool bug_on_reinit_failure = CFG_BUG_ON_REINIT_FAILURE_DEFAULT;
	bool value;

	hdd_prevent_suspend(WIFI_POWER_EVENT_WAKELOCK_DRIVER_REINIT);

	/* Get the HDD context */
	hdd_ctx = cds_get_context(QDF_MODULE_ID_HDD);
	if (!hdd_ctx) {
		hdd_err("HDD context is Null");
		goto err_ctx_null;
	}
	bug_on_reinit_failure = hdd_ctx->config->bug_on_reinit_failure;

	adapter = hdd_get_first_valid_adapter(hdd_ctx);
	if (!adapter)
		hdd_err("Failed to get adapter");

	hdd_dp_trace_init(hdd_ctx->config);

	ret = hdd_wlan_start_modules(hdd_ctx, true);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	if (ret) {
		hdd_err("Failed to start wlan after error");
		goto err_re_init;
	}

<<<<<<< HEAD
	hdd_update_hw_sw_info(pHddCtx);

	wlan_hdd_send_svc_nlink_msg(pHddCtx->radio_index,
				WLAN_SVC_FW_CRASHED_IND, NULL, 0);

	/* Restart all adapters */
	hdd_start_all_adapters(pHddCtx);

	/* init the scan reject params */
	hdd_init_scan_reject_params(pHddCtx);

	hdd_set_roaming_in_progress(false);
	complete(&pAdapter->roaming_comp_var);
	pHddCtx->btCoexModeSet = false;

	/* Allow the phone to go to sleep */
	hdd_allow_suspend(WIFI_POWER_EVENT_WAKELOCK_DRIVER_REINIT);

	/* set chip power save failure detected callback */
	sme_set_chip_pwr_save_fail_cb(pHddCtx->hHal,
				      hdd_chip_pwr_save_fail_detected_cb);

	hdd_send_default_scan_ies(pHddCtx);
	hdd_info("WLAN host driver reinitiation completed!");
	goto success;

err_re_init:
	/* Allow the phone to go to sleep */
	hdd_allow_suspend(WIFI_POWER_EVENT_WAKELOCK_DRIVER_REINIT);
	return -EPERM;

success:
	if (pHddCtx->config->sap_internal_restart)
		hdd_ssr_restart_sap(pHddCtx);
	hdd_is_interface_down_during_ssr(pHddCtx);

	pHddCtx->is_ssr_in_progress = false;

	hdd_wlan_ssr_reinit_event();
	return QDF_STATUS_SUCCESS;
}

int wlan_hdd_set_powersave(hdd_adapter_t *adapter,
	bool allow_power_save, uint32_t timeout)
{
	tHalHandle hal;
	hdd_context_t *hdd_ctx;
	QDF_STATUS status = QDF_STATUS_SUCCESS;

	if (NULL == adapter) {
=======
	hdd_update_hw_sw_info(hdd_ctx);

	wlan_hdd_send_svc_nlink_msg(hdd_ctx->radio_index,
				WLAN_SVC_FW_CRASHED_IND, NULL, 0);

	/* Restart all adapters */
	hdd_start_all_adapters(hdd_ctx);

	hdd_init_scan_reject_params(hdd_ctx);

	hdd_set_roaming_in_progress(false);
	complete(&adapter->roaming_comp_var);
	hdd_ctx->bt_coex_mode_set = false;

	/* Allow the phone to go to sleep */
	hdd_allow_suspend(WIFI_POWER_EVENT_WAKELOCK_DRIVER_REINIT);
	/* set chip power save failure detected callback */
	sme_set_chip_pwr_save_fail_cb(hdd_ctx->mac_handle,
				      hdd_chip_pwr_save_fail_detected_cb);

	hdd_restore_thermal_mitigation_config(hdd_ctx);
	hdd_restore_sar_config(hdd_ctx);

	hdd_send_default_scan_ies(hdd_ctx);
	hdd_info("WLAN host driver reinitiation completed!");

	ucfg_mlme_get_sap_internal_restart(hdd_ctx->psoc, &value);
	if (value)
		hdd_ssr_restart_sap(hdd_ctx);
	hdd_is_interface_down_during_ssr(hdd_ctx);
	hdd_wlan_ssr_reinit_event();
	return QDF_STATUS_SUCCESS;

err_re_init:
	qdf_dp_trace_deinit();

err_ctx_null:
	/* Allow the phone to go to sleep */
	hdd_allow_suspend(WIFI_POWER_EVENT_WAKELOCK_DRIVER_REINIT);
	if (bug_on_reinit_failure)
		QDF_BUG(0);
	return -EPERM;
}

int wlan_hdd_set_powersave(struct hdd_adapter *adapter,
	bool allow_power_save, uint32_t timeout)
{
	mac_handle_t mac_handle;
	struct hdd_context *hdd_ctx;
	QDF_STATUS status = QDF_STATUS_SUCCESS;
	bool is_bmps_enabled;

	if (!adapter) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		hdd_err("Adapter NULL");
		return -ENODEV;
	}

	hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	if (!hdd_ctx) {
		hdd_err("hdd context is NULL");
		return -EINVAL;
	}

	hdd_debug("Allow power save: %d", allow_power_save);
<<<<<<< HEAD
	hal = WLAN_HDD_GET_HAL_CTX(adapter);
=======
	mac_handle = hdd_ctx->mac_handle;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	/*
	 * This is a workaround for defective AP's that send a disassoc
	 * immediately after WPS connection completes. Defer powersave by a
	 * small amount if the affected AP is detected.
	 */
	if (allow_power_save &&
	    adapter->device_mode == QDF_STA_MODE &&
<<<<<<< HEAD
	    !adapter->sessionCtx.station.ap_supports_immediate_power_save) {
=======
	    !adapter->session.station.ap_supports_immediate_power_save) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		timeout = AUTO_PS_DEFER_TIMEOUT_MS;
		hdd_debug("Defer power-save due to AP spec non-conformance");
	}

	if (allow_power_save) {
		if (QDF_STA_MODE == adapter->device_mode ||
		    QDF_P2P_CLIENT_MODE == adapter->device_mode) {
			hdd_debug("Disabling Auto Power save timer");
<<<<<<< HEAD
			status = sme_ps_disable_auto_ps_timer(
				WLAN_HDD_GET_HAL_CTX(adapter),
				adapter->sessionId);
=======
			status = sme_ps_disable_auto_ps_timer(mac_handle,
						adapter->vdev_id);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			if (status != QDF_STATUS_SUCCESS)
				goto end;
		}

<<<<<<< HEAD
		if (hdd_ctx->config && hdd_ctx->config->is_ps_enabled) {
=======
		ucfg_mlme_is_bmps_enabled(hdd_ctx->psoc, &is_bmps_enabled);
		if (is_bmps_enabled) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			hdd_debug("Wlan driver Entering Power save");

			/*
			 * Enter Power Save command received from GUI
			 * this means DHCP is completed
			 */
			if (timeout) {
<<<<<<< HEAD
				status = sme_ps_enable_auto_ps_timer(hal,
							    adapter->sessionId,
=======
				status = sme_ps_enable_auto_ps_timer(mac_handle,
							    adapter->vdev_id,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
							    timeout);
				if (status != QDF_STATUS_SUCCESS)
					goto end;
			} else {
<<<<<<< HEAD
				status = sme_ps_enable_disable(hal,
						adapter->sessionId,
=======
				status = sme_ps_enable_disable(mac_handle,
						adapter->vdev_id,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
						SME_PS_ENABLE);
				if (status != QDF_STATUS_SUCCESS)
					goto end;
			}
		} else {
			hdd_debug("Power Save is not enabled in the cfg");
		}
	} else {
		hdd_debug("Wlan driver Entering Full Power");

		/*
		 * Enter Full power command received from GUI
		 * this means we are disconnected
		 */
<<<<<<< HEAD
		status = sme_ps_disable_auto_ps_timer(
					WLAN_HDD_GET_HAL_CTX(adapter),
					adapter->sessionId);
		if (status != QDF_STATUS_SUCCESS)
			goto end;
		status = sme_ps_enable_disable(hal, adapter->sessionId,
					       SME_PS_DISABLE);
=======
		status = sme_ps_disable_auto_ps_timer(mac_handle,
					adapter->vdev_id);

		if (status != QDF_STATUS_SUCCESS)
			goto end;

		ucfg_mlme_is_bmps_enabled(hdd_ctx->psoc, &is_bmps_enabled);
		if (is_bmps_enabled)
			status = sme_ps_enable_disable(mac_handle,
						       adapter->vdev_id,
						       SME_PS_DISABLE);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	}

end:
	return qdf_status_to_os_return(status);
}

<<<<<<< HEAD
static void wlan_hdd_print_suspend_fail_stats(hdd_context_t *hdd_ctx)
=======
static void wlan_hdd_print_suspend_fail_stats(struct hdd_context *hdd_ctx)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	struct suspend_resume_stats *stats = &hdd_ctx->suspend_resume_stats;

	hdd_err("ipa:%d, radar:%d, roam:%d, scan:%d, initial_wakeup:%d",
		stats->suspend_fail[SUSPEND_FAIL_IPA],
		stats->suspend_fail[SUSPEND_FAIL_RADAR],
		stats->suspend_fail[SUSPEND_FAIL_ROAM],
		stats->suspend_fail[SUSPEND_FAIL_SCAN],
		stats->suspend_fail[SUSPEND_FAIL_INITIAL_WAKEUP]);
}

<<<<<<< HEAD
void wlan_hdd_inc_suspend_stats(hdd_context_t *hdd_ctx,
=======
void wlan_hdd_inc_suspend_stats(struct hdd_context *hdd_ctx,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				enum suspend_fail_reason reason)
{
	wlan_hdd_print_suspend_fail_stats(hdd_ctx);
	hdd_ctx->suspend_resume_stats.suspend_fail[reason]++;
	wlan_hdd_print_suspend_fail_stats(hdd_ctx);
}

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 12, 0)
<<<<<<< HEAD
void
=======
static inline void
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
hdd_sched_scan_results(struct wiphy *wiphy, uint64_t reqid)
{
	cfg80211_sched_scan_results(wiphy);
}
#else
<<<<<<< HEAD
void
=======
static inline void
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
hdd_sched_scan_results(struct wiphy *wiphy, uint64_t reqid)
{
	cfg80211_sched_scan_results(wiphy, reqid);
}
#endif

/**
 * __wlan_hdd_cfg80211_resume_wlan() - cfg80211 resume callback
 * @wiphy: Pointer to wiphy
 *
 * This API is called when cfg80211 driver resumes driver updates
 * latest sched_scan scan result(if any) to cfg80211 database
 *
 * Return: integer status
 */
static int __wlan_hdd_cfg80211_resume_wlan(struct wiphy *wiphy)
{
<<<<<<< HEAD
	hdd_context_t *pHddCtx = wiphy_priv(wiphy);
	hdd_adapter_t *pAdapter;
	hdd_adapter_list_node_t *pAdapterNode, *pNext;
	QDF_STATUS status = QDF_STATUS_SUCCESS;
	int exit_code;
	p_cds_sched_context cds_sched_context = get_cds_sched_ctxt();

	ENTER();
=======
	struct hdd_context *hdd_ctx = wiphy_priv(wiphy);
	QDF_STATUS status = QDF_STATUS_SUCCESS;
	int exit_code;

	hdd_enter();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	if (cds_is_driver_recovering()) {
		hdd_debug("Driver is recovering; Skipping resume");
		exit_code = 0;
		goto exit_with_code;
	}

<<<<<<< HEAD
	if (QDF_GLOBAL_FTM_MODE == hdd_get_conparam()) {
		hdd_err("Command not allowed in FTM mode");
=======
	if (QDF_GLOBAL_FTM_MODE == hdd_get_conparam() ||
	    QDF_GLOBAL_MONITOR_MODE == hdd_get_conparam()) {
		hdd_err("Command not allowed in mode %d",
			hdd_get_conparam());
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		exit_code = -EINVAL;
		goto exit_with_code;
	}

<<<<<<< HEAD
	exit_code = wlan_hdd_validate_context(pHddCtx);
	if (exit_code) {
		hdd_err("Invalid HDD context");
		goto exit_with_code;
	}

	mutex_lock(&pHddCtx->iface_change_lock);
	if (pHddCtx->driver_status != DRIVER_MODULES_ENABLED) {
		mutex_unlock(&pHddCtx->iface_change_lock);
=======
	if (hdd_ctx->config->is_wow_disabled) {
		hdd_err("wow is disabled");
		return -EINVAL;
	}

	if (hdd_ctx->driver_status != DRIVER_MODULES_ENABLED) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		hdd_debug("Driver is not enabled; Skipping resume");
		exit_code = 0;
		goto exit_with_code;
	}
<<<<<<< HEAD
	mutex_unlock(&pHddCtx->iface_change_lock);

	pld_request_bus_bandwidth(pHddCtx->parent_dev, PLD_BUS_WIDTH_MEDIUM);

	/* Resume MC thread */
	if (pHddCtx->isMcThreadSuspended) {
		complete(&cds_sched_context->ResumeMcEvent);
		pHddCtx->isMcThreadSuspended = false;
	}
#ifdef QCA_CONFIG_SMP
	/* Resume tlshim Rx thread */
	if (pHddCtx->is_ol_rx_thread_suspended) {
		complete(&cds_sched_context->ol_resume_rx_event);
		pHddCtx->is_ol_rx_thread_suspended = false;
	}
#endif
	/* Resume tlshim mon thread */
	if (cds_get_pktcap_mode_enable() &&
	    pHddCtx->is_ol_mon_thread_suspended) {
		complete(&cds_sched_context->ol_resume_mon_event);
		pHddCtx->is_ol_mon_thread_suspended = false;
	}

	hdd_resume_wlan();

	MTRACE(qdf_trace(QDF_MODULE_ID_HDD,
			 TRACE_CODE_HDD_CFG80211_RESUME_WLAN,
			 NO_SESSION, pHddCtx->isWiphySuspended));
	qdf_spin_lock(&pHddCtx->sched_scan_lock);
	pHddCtx->isWiphySuspended = false;
	if (true != pHddCtx->isSchedScanUpdatePending) {
		qdf_spin_unlock(&pHddCtx->sched_scan_lock);
		hdd_debug("Return resume is not due to PNO indication");
		goto exit_with_success;
	}
	/* Reset flag to avoid updatating cfg80211 data old results again */
	pHddCtx->isSchedScanUpdatePending = false;
	qdf_spin_unlock(&pHddCtx->sched_scan_lock);

	status = hdd_get_front_adapter(pHddCtx, &pAdapterNode);
	while (NULL != pAdapterNode && QDF_STATUS_SUCCESS == status) {
		pAdapter = pAdapterNode->pAdapter;
		if ((NULL != pAdapter) &&
		    (QDF_STA_MODE == pAdapter->device_mode)) {
			if (0 !=
			    wlan_hdd_cfg80211_update_bss(pHddCtx->wiphy,
							 pAdapter, 0)) {
				hdd_warn("NO SCAN result");
			} else {
				/* Acquire wakelock to handle the case where
				 * APP's tries to suspend immediately after
				 * updating the scan results. Whis results in
				 * app's is in suspended state and not able to
				 * process the connect request to AP
				 */
				hdd_prevent_suspend_timeout(
					HDD_WAKELOCK_TIMEOUT_RESUME,
					WIFI_POWER_EVENT_WAKELOCK_RESUME_WLAN);
				hdd_sched_scan_results(pHddCtx->wiphy, 0);
			}

			hdd_debug("cfg80211 scan result database updated");
			goto exit_with_success;
		}
		status = hdd_get_next_adapter(pHddCtx, pAdapterNode, &pNext);
		pAdapterNode = pNext;
	}

exit_with_success:
	pHddCtx->suspend_resume_stats.resumes++;
	exit_code = 0;

exit_with_code:
	EXIT();
	return exit_code;
}

/**
 * wlan_hdd_cfg80211_ready_to_suspend() - set cfg80211 ready to suspend event
 * @callbackContext: Pointer to callback context
 * @suspended: Suspend flag
 *
 * Return: none
 */
static void wlan_hdd_cfg80211_ready_to_suspend(void *callbackContext,
						bool suspended)
{
	hdd_context_t *pHddCtx = (hdd_context_t *) callbackContext;

	pHddCtx->suspended = suspended;
	complete(&pHddCtx->ready_to_suspend);
}

/**
 * wlan_hdd_cfg80211_resume_wlan() - cfg80211 resume callback
 * @wiphy: Pointer to wiphy
 *
 * This API is called when cfg80211 driver resumes driver updates
 * latest sched_scan scan result(if any) to cfg80211 database
 *
 * Return: integer status
 */
int wlan_hdd_cfg80211_resume_wlan(struct wiphy *wiphy)
{
	int ret;

	cds_ssr_protect(__func__);
	ret = __wlan_hdd_cfg80211_resume_wlan(wiphy);
	cds_ssr_unprotect(__func__);

	return ret;
}

/**
 * __wlan_hdd_cfg80211_suspend_wlan() - cfg80211 suspend callback
 * @wiphy: Pointer to wiphy
 * @wow: Pointer to wow
=======

	status = hdd_resume_wlan();
	if (status != QDF_STATUS_SUCCESS) {
		exit_code = 0;
		goto exit_with_code;
	}
	/* Resume control path scheduler */
	if (hdd_ctx->is_scheduler_suspended) {
		scheduler_resume();
		hdd_ctx->is_scheduler_suspended = false;
	}
	/* Resume all components registered to pmo */
	status = ucfg_pmo_resume_all_components(hdd_ctx->psoc,
						QDF_SYSTEM_SUSPEND);
	if (status != QDF_STATUS_SUCCESS) {
		exit_code = 0;
		goto exit_with_code;
	}
	/* Resume tlshim Rx thread */
	if (hdd_ctx->enable_rxthread)
		wlan_hdd_rx_thread_resume(hdd_ctx);

	if (hdd_ctx->enable_dp_rx_threads)
		dp_txrx_resume(cds_get_context(QDF_MODULE_ID_SOC));

	if (cds_is_pktcapture_enabled())
		wlan_hdd_mon_thread_resume(hdd_ctx);

	qdf_mtrace(QDF_MODULE_ID_HDD, QDF_MODULE_ID_HDD,
		   TRACE_CODE_HDD_CFG80211_RESUME_WLAN,
		   NO_SESSION, hdd_ctx->is_wiphy_suspended);

	hdd_ctx->is_wiphy_suspended = false;

	hdd_ctx->suspend_resume_stats.resumes++;
	exit_code = 0;

exit_with_code:
	hdd_exit();
	return exit_code;
}

static int _wlan_hdd_cfg80211_resume_wlan(struct wiphy *wiphy)
{
	void *hif_ctx;
	struct hdd_context *hdd_ctx = wiphy_priv(wiphy);
	int errno;

	if(!hdd_ctx) {
		hdd_err_rl("hdd context is null");
		return -ENODEV;
	}

	/* If Wifi is off, return success for system resume */
	if (hdd_ctx->driver_status != DRIVER_MODULES_ENABLED) {
		hdd_debug("Driver Modules not Enabled ");
		return 0;
	}

	errno = wlan_hdd_validate_context(hdd_ctx);
	if (errno)
		return errno;

	hif_ctx = cds_get_context(QDF_MODULE_ID_HIF);
	errno = __wlan_hdd_cfg80211_resume_wlan(wiphy);
	hif_pm_runtime_put(hif_ctx, RTPM_ID_SUSPEND_RESUME);

	return errno;
}

int wlan_hdd_cfg80211_resume_wlan(struct wiphy *wiphy)
{
	struct osif_psoc_sync *psoc_sync;
	int errno;

	errno = osif_psoc_sync_op_start(wiphy_dev(wiphy), &psoc_sync);
	if (errno)
		return errno;

	errno = _wlan_hdd_cfg80211_resume_wlan(wiphy);

	osif_psoc_sync_op_stop(psoc_sync);

	return errno;
}

static void hdd_suspend_cb(void)
{
	struct hdd_context *hdd_ctx;

	hdd_ctx = cds_get_context(QDF_MODULE_ID_HDD);
	if (!hdd_ctx) {
		hdd_err("HDD context is NULL");
		return;
	}

	complete(&hdd_ctx->mc_sus_event_var);
}

/**
 * __wlan_hdd_cfg80211_suspend_wlan() - cfg80211 suspend callback
 * @wiphy: Pointer to wiphy
 * @wow: Pointer to wow
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *
 * This API is called when cfg80211 driver suspends
 *
 * Return: integer status
 */
static int __wlan_hdd_cfg80211_suspend_wlan(struct wiphy *wiphy,
				     struct cfg80211_wowlan *wow)
{
<<<<<<< HEAD
#ifdef QCA_CONFIG_SMP
#define RX_TLSHIM_SUSPEND_TIMEOUT 200   /* msecs */
#endif
	hdd_context_t *pHddCtx = wiphy_priv(wiphy);
	p_cds_sched_context cds_sched_context = get_cds_sched_ctxt();
	hdd_adapter_list_node_t *pAdapterNode = NULL, *pNext = NULL;
	hdd_adapter_t *pAdapter;
	hdd_scaninfo_t *pScanInfo;
	QDF_STATUS status;
	int rc;

	ENTER();

	if (QDF_GLOBAL_FTM_MODE == hdd_get_conparam()) {
		hdd_err("Command not allowed in FTM mode");
		return -EINVAL;
	}

	rc = wlan_hdd_validate_context(pHddCtx);
	if (0 != rc)
		return rc;

	mutex_lock(&pHddCtx->iface_change_lock);

	if (pHddCtx->driver_status == DRIVER_MODULES_OPENED) {
		mutex_unlock(&pHddCtx->iface_change_lock);
		hdd_err("Driver open state,  can't suspend");
		return -EAGAIN;
	}

	if (pHddCtx->driver_status != DRIVER_MODULES_ENABLED) {
		mutex_unlock(&pHddCtx->iface_change_lock);
		hdd_debug("Driver Modules not Enabled ");
		return 0;
	}
	mutex_unlock(&pHddCtx->iface_change_lock);

	if (cds_is_connection_in_progress(NULL, NULL)) {
		hdd_err("Suspend rejected: conn in progress");
		return -EINVAL;
	}
=======
	struct hdd_context *hdd_ctx = wiphy_priv(wiphy);
	struct hdd_adapter *adapter, *next_adapter = NULL;
	mac_handle_t mac_handle;
	int rc;
	wlan_net_dev_ref_dbgid dbgid = NET_DEV_HOLD_CFG80211_SUSPEND_WLAN;

	hdd_enter();

	if (QDF_GLOBAL_FTM_MODE == hdd_get_conparam() ||
	    QDF_GLOBAL_MONITOR_MODE == hdd_get_conparam()) {
		hdd_err_rl("Command not allowed in mode %d",
			   hdd_get_conparam());
		return -EINVAL;
	}

	rc = wlan_hdd_validate_context(hdd_ctx);
	if (0 != rc)
		return rc;

	/* Wait for the stop module if already in progress */
	hdd_psoc_idle_timer_stop(hdd_ctx);

	if (hdd_ctx->config->is_wow_disabled) {
		hdd_info_rl("wow is disabled");
		return -EINVAL;
	}

	if (hdd_ctx->driver_status != DRIVER_MODULES_ENABLED) {
		hdd_debug("Driver Modules not Enabled ");
		return 0;
	}

	mac_handle = hdd_ctx->mac_handle;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	/* If RADAR detection is in progress (HDD), prevent suspend. The flag
	 * "dfs_cac_block_tx" is set to true when RADAR is found and stay true
	 * until CAC is done for a SoftAP which is in started state.
	 */
<<<<<<< HEAD
	status = hdd_get_front_adapter(pHddCtx, &pAdapterNode);
	while (NULL != pAdapterNode && QDF_STATUS_SUCCESS == status) {
		pAdapter = pAdapterNode->pAdapter;

		if (wlan_hdd_validate_session_id(pAdapter->sessionId)) {
			hdd_debug("invalid session id: %d", pAdapter->sessionId);
			goto next_adapter;
		}

		if (QDF_SAP_MODE == pAdapter->device_mode) {
			if (BSS_START ==
			    WLAN_HDD_GET_HOSTAP_STATE_PTR(pAdapter)->bssState &&
			    true ==
			    WLAN_HDD_GET_AP_CTX_PTR(pAdapter)->
			    dfs_cac_block_tx) {
				hdd_err("RADAR detection in progress, do not allow suspend");
				wlan_hdd_inc_suspend_stats(pHddCtx,
							   SUSPEND_FAIL_RADAR);
				return -EAGAIN;
			} else if (!pHddCtx->config->enableSapSuspend) {
=======
	hdd_for_each_adapter_dev_held_safe(hdd_ctx, adapter, next_adapter,
					   dbgid) {
		if (wlan_hdd_validate_vdev_id(adapter->vdev_id)) {
			hdd_adapter_dev_put_debug(adapter, dbgid);
			continue;
		}

		if (QDF_SAP_MODE == adapter->device_mode) {
			if (BSS_START ==
			    WLAN_HDD_GET_HOSTAP_STATE_PTR(adapter)->bss_state &&
			    true ==
			    WLAN_HDD_GET_AP_CTX_PTR(adapter)->
			    dfs_cac_block_tx) {
				hdd_err("RADAR detection in progress, do not allow suspend");
				wlan_hdd_inc_suspend_stats(hdd_ctx,
							   SUSPEND_FAIL_RADAR);
				hdd_adapter_dev_put_debug(adapter, dbgid);
				if (next_adapter)
					hdd_adapter_dev_put_debug(next_adapter,
								  dbgid);
				return -EAGAIN;
			} else if (!ucfg_pmo_get_enable_sap_suspend(
				   hdd_ctx->psoc)) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				/* return -EOPNOTSUPP if SAP does not support
				 * suspend
				 */
				hdd_err("SAP does not support suspend!!");
<<<<<<< HEAD
				return -EOPNOTSUPP;
			}
		} else if (QDF_P2P_GO_MODE == pAdapter->device_mode) {
			if (!pHddCtx->config->enableSapSuspend) {
=======
				hdd_adapter_dev_put_debug(adapter, dbgid);
				if (next_adapter)
					hdd_adapter_dev_put_debug(next_adapter,
								  dbgid);
				return -EOPNOTSUPP;
			}
		} else if (QDF_P2P_GO_MODE == adapter->device_mode) {
			if (!ucfg_pmo_get_enable_sap_suspend(
				   hdd_ctx->psoc)) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				/* return -EOPNOTSUPP if GO does not support
				 * suspend
				 */
				hdd_err("GO does not support suspend!!");
<<<<<<< HEAD
				return -EOPNOTSUPP;
			}
		}
		if (pAdapter->is_roc_inprogress)
			wlan_hdd_cleanup_remain_on_channel_ctx(pAdapter);
next_adapter:
		status = hdd_get_next_adapter(pHddCtx, pAdapterNode, &pNext);
		pAdapterNode = pNext;
	}

	/* Stop ongoing scan on each interface */
	status = hdd_get_front_adapter(pHddCtx, &pAdapterNode);
	while (NULL != pAdapterNode && QDF_STATUS_SUCCESS == status) {
		pAdapter = pAdapterNode->pAdapter;
		pScanInfo = &pAdapter->scan_info;

		if (sme_neighbor_middle_of_roaming
		   (pHddCtx->hHal, pAdapter->sessionId) ||
		    hdd_is_roaming_in_progress(pHddCtx)) {
			hdd_err("Roaming in progress, do not allow suspend");
			wlan_hdd_inc_suspend_stats(pHddCtx,
						   SUSPEND_FAIL_ROAM);
			return -EAGAIN;
		}

		hdd_abort_mac_scan(pHddCtx, pAdapter->sessionId,
				   INVALID_SCAN_ID, eCSR_SCAN_ABORT_DEFAULT);

		/* for suspend case, don't wait for scan cancel completion */

		status = hdd_get_next_adapter(pHddCtx, pAdapterNode, &pNext);
		pAdapterNode = pNext;
	}

	/* flush any pending powersave timers */
	status = hdd_get_front_adapter(pHddCtx, &pAdapterNode);
	while (pAdapterNode && QDF_IS_STATUS_SUCCESS(status)) {
		pAdapter = pAdapterNode->pAdapter;

		if (pAdapter->sessionId >= MAX_NUMBER_OF_ADAPTERS)
			goto fetch_adapter;

		sme_ps_timer_flush_sync(pHddCtx->hHal, pAdapter->sessionId);
fetch_adapter:
		status = hdd_get_next_adapter(pHddCtx, pAdapterNode,
					      &pAdapterNode);
=======
				hdd_adapter_dev_put_debug(adapter, dbgid);
				if (next_adapter)
					hdd_adapter_dev_put_debug(next_adapter,
								  dbgid);
				return -EOPNOTSUPP;
			}
		}
		hdd_adapter_dev_put_debug(adapter, dbgid);
	}
	/* p2p cleanup task based on scheduler */
	ucfg_p2p_cleanup_tx_by_psoc(hdd_ctx->psoc);
	ucfg_p2p_cleanup_roc_by_psoc(hdd_ctx->psoc);

	if (hdd_is_connection_in_progress(NULL, NULL)) {
		hdd_err_rl("Connection is in progress, rejecting suspend");
		return -EINVAL;
	}

	/* flush any pending powersave timers */
	hdd_for_each_adapter_dev_held_safe(hdd_ctx, adapter, next_adapter,
					   dbgid) {
		if (wlan_hdd_validate_vdev_id(adapter->vdev_id)) {
			hdd_adapter_dev_put_debug(adapter, dbgid);
			continue;
		}

		sme_ps_timer_flush_sync(mac_handle, adapter->vdev_id);
		hdd_adapter_dev_put_debug(adapter, dbgid);
	}

	/*
	 * Suspend all components registered to pmo, abort ongoing scan and
	 * don't allow new scan any more before scheduler thread suspended.
	 */
	if (ucfg_pmo_suspend_all_components(hdd_ctx->psoc,
					    QDF_SYSTEM_SUSPEND)) {
		hdd_err("Some components not ready to suspend!");
		return -EAGAIN;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	}

	/*
	 * Suspend IPA early before proceeding to suspend other entities like
	 * firmware to avoid any race conditions.
	 */
<<<<<<< HEAD
	if (hdd_ipa_suspend(pHddCtx)) {
		hdd_err("IPA not ready to suspend!");
		wlan_hdd_inc_suspend_stats(pHddCtx, SUSPEND_FAIL_IPA);
		return -EAGAIN;
	}

	/* Wait for the target to be ready for suspend */
	INIT_COMPLETION(pHddCtx->ready_to_suspend);

	hdd_suspend_wlan(&wlan_hdd_cfg80211_ready_to_suspend, pHddCtx);

	rc = wait_for_completion_timeout(&pHddCtx->ready_to_suspend,
		msecs_to_jiffies(WLAN_WAIT_TIME_READY_TO_SUSPEND));
	if (!rc) {
		hdd_err("Failed to get ready to suspend");
		goto resume_tx;
	}

	if (!pHddCtx->suspended) {
		hdd_err("Faied as suspend_status is wrong:%d",
			pHddCtx->suspended);
		goto resume_tx;
	}

	/* Suspend MC thread */
	set_bit(MC_SUSPEND_EVENT, &cds_sched_context->mcEventFlag);
	wake_up_interruptible(&cds_sched_context->mcWaitQueue);

	/* Wait for suspend confirmation from MC thread */
	rc = wait_for_completion_timeout(&pHddCtx->mc_sus_event_var,
		msecs_to_jiffies(WLAN_WAIT_TIME_MCTHREAD_SUSPEND));
	if (!rc) {
		clear_bit(MC_SUSPEND_EVENT,
			  &cds_sched_context->mcEventFlag);
		hdd_err("Failed to stop mc thread");
		goto resume_tx;
	}

	pHddCtx->isMcThreadSuspended = true;

#ifdef QCA_CONFIG_SMP
	/* Suspend tlshim rx thread */
	set_bit(RX_SUSPEND_EVENT, &cds_sched_context->ol_rx_event_flag);
	wake_up_interruptible(&cds_sched_context->ol_rx_wait_queue);
	rc = wait_for_completion_timeout(&cds_sched_context->
					 ol_suspend_rx_event,
					 msecs_to_jiffies
						 (RX_TLSHIM_SUSPEND_TIMEOUT));
	if (!rc) {
		clear_bit(RX_SUSPEND_EVENT,
			  &cds_sched_context->ol_rx_event_flag);
		hdd_err("Failed to stop tl_shim rx thread");
		goto resume_mc;
	}
	pHddCtx->is_ol_rx_thread_suspended = true;
#endif
	/* Suspend tlshim mon thread */
	if (cds_get_pktcap_mode_enable()) {
		set_bit(RX_SUSPEND_EVENT,
			&cds_sched_context->ol_mon_event_flag);
		wake_up_interruptible(&cds_sched_context->ol_mon_wait_queue);
		rc = wait_for_completion_timeout(&cds_sched_context->
						 ol_suspend_mon_event,
						 msecs_to_jiffies
						 (RX_TLSHIM_SUSPEND_TIMEOUT));
		if (!rc) {
			clear_bit(RX_SUSPEND_EVENT,
				  &cds_sched_context->ol_mon_event_flag);
			hdd_err("Failed to stop tl_shim mon thread");
			goto resume_all;
		}
		pHddCtx->is_ol_mon_thread_suspended = true;
	}

	MTRACE(qdf_trace(QDF_MODULE_ID_HDD,
			 TRACE_CODE_HDD_CFG80211_SUSPEND_WLAN,
			 NO_SESSION, pHddCtx->isWiphySuspended));
	pHddCtx->isWiphySuspended = true;

	pld_request_bus_bandwidth(pHddCtx->parent_dev, PLD_BUS_WIDTH_NONE);

	EXIT();
	return 0;

resume_all:
#ifdef QCA_CONFIG_SMP
	complete(&cds_sched_context->ol_resume_rx_event);
	pHddCtx->is_ol_rx_thread_suspended = false;
#endif
resume_mc:
	complete(&cds_sched_context->ResumeMcEvent);
	pHddCtx->isMcThreadSuspended = false;

resume_tx:

=======
	if (ucfg_ipa_suspend(hdd_ctx->pdev)) {
		hdd_err("IPA not ready to suspend!");
		wlan_hdd_inc_suspend_stats(hdd_ctx, SUSPEND_FAIL_IPA);
		return -EAGAIN;
	}

	/* Suspend control path scheduler */
	scheduler_register_hdd_suspend_callback(hdd_suspend_cb);
	scheduler_set_event_mask(MC_SUSPEND_EVENT);
	scheduler_wake_up_controller_thread();

	/* Wait for suspend confirmation from scheduler */
	rc = wait_for_completion_timeout(&hdd_ctx->mc_sus_event_var,
		msecs_to_jiffies(WLAN_WAIT_TIME_MCTHREAD_SUSPEND));
	if (!rc) {
		scheduler_clear_event_mask(MC_SUSPEND_EVENT);
		hdd_err("Failed to stop mc thread");
		goto resume_tx;
	}
	hdd_ctx->is_scheduler_suspended = true;

	if (hdd_ctx->enable_rxthread) {
		if (wlan_hdd_rx_thread_suspend(hdd_ctx))
			goto resume_ol_rx;
	}

	if (hdd_ctx->enable_dp_rx_threads) {
		if (dp_txrx_suspend(cds_get_context(QDF_MODULE_ID_SOC)))
			goto resume_ol_rx;
	}

	if (cds_is_pktcapture_enabled()) {
		if (wlan_hdd_mon_thread_suspend(hdd_ctx))
			goto resume_dp_thread;
	}

	qdf_mtrace(QDF_MODULE_ID_HDD, QDF_MODULE_ID_HDD,
		   TRACE_CODE_HDD_CFG80211_SUSPEND_WLAN,
		   NO_SESSION, hdd_ctx->is_wiphy_suspended);

	if (hdd_suspend_wlan() < 0) {
		hdd_err("Failed to suspend WLAN");
		goto resume_dp_thread;
	}

	hdd_ctx->is_wiphy_suspended = true;

	hdd_exit();
	return 0;

resume_dp_thread:
	if (hdd_ctx->enable_dp_rx_threads)
		dp_txrx_resume(cds_get_context(QDF_MODULE_ID_SOC));

	/* Resume tlshim MON thread */
	if (cds_is_pktcapture_enabled())
		wlan_hdd_mon_thread_resume(hdd_ctx);

resume_ol_rx:
	/* Resume tlshim Rx thread */
	wlan_hdd_rx_thread_resume(hdd_ctx);
	scheduler_resume();
	hdd_ctx->is_scheduler_suspended = false;
resume_tx:
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	hdd_resume_wlan();
	return -ETIME;

}

<<<<<<< HEAD
/**
 * wlan_hdd_cfg80211_suspend_wlan() - cfg80211 suspend callback
 * @wiphy: Pointer to wiphy
 * @wow: Pointer to wow
 *
 * This API is called when cfg80211 driver suspends
 *
 * Return: integer status
 */
int wlan_hdd_cfg80211_suspend_wlan(struct wiphy *wiphy,
				   struct cfg80211_wowlan *wow)
{
	int ret;

	cds_ssr_protect(__func__);
	ret = __wlan_hdd_cfg80211_suspend_wlan(wiphy, wow);
	cds_ssr_unprotect(__func__);

	return ret;
=======
static int _wlan_hdd_cfg80211_suspend_wlan(struct wiphy *wiphy,
					   struct cfg80211_wowlan *wow)
{
	void *hif_ctx;
	struct hdd_context *hdd_ctx = wiphy_priv(wiphy);
	int errno;

	if(!hdd_ctx) {
		hdd_err_rl("hdd context is null");
		return -ENODEV;
	}

	/* If Wifi is off, return success for system suspend */
	if (hdd_ctx->driver_status != DRIVER_MODULES_ENABLED) {
		hdd_debug("Driver Modules not Enabled ");
		return 0;
	}

	errno = wlan_hdd_validate_context(hdd_ctx);
	if (errno)
		return errno;

	hif_ctx = cds_get_context(QDF_MODULE_ID_HIF);
	errno = hif_pm_runtime_get_sync(hif_ctx, RTPM_ID_SUSPEND_RESUME);
	if (errno)
		return errno;

	errno = __wlan_hdd_cfg80211_suspend_wlan(wiphy, wow);
	if (errno) {
		hif_pm_runtime_put(hif_ctx, RTPM_ID_SUSPEND_RESUME);
		return errno;
	}

	return errno;
}

int wlan_hdd_cfg80211_suspend_wlan(struct wiphy *wiphy,
				   struct cfg80211_wowlan *wow)
{
	struct osif_psoc_sync *psoc_sync;
	int errno;

	errno = osif_psoc_sync_op_start(wiphy_dev(wiphy), &psoc_sync);
	if (errno)
		return errno;

	errno = _wlan_hdd_cfg80211_suspend_wlan(wiphy, wow);

	osif_psoc_sync_op_stop(psoc_sync);

	return errno;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * hdd_stop_dhcp_ind() - API to stop DHCP sequence
 * @adapter: Adapter on which DHCP needs to be stopped
 *
 * Release the wakelock held for DHCP process and allow
 * the runtime pm to continue
 *
 * Return: None
 */
<<<<<<< HEAD
static void hdd_stop_dhcp_ind(hdd_adapter_t *adapter)
{
	hdd_context_t *hdd_ctx = WLAN_HDD_GET_CTX(adapter);

	hdd_debug("DHCP stop indicated through power save");
	sme_dhcp_stop_ind(hdd_ctx->hHal, adapter->device_mode,
			  adapter->macAddressCurrent.bytes,
			  adapter->sessionId);
=======
static void hdd_stop_dhcp_ind(struct hdd_adapter *adapter)
{
	struct hdd_context *hdd_ctx = WLAN_HDD_GET_CTX(adapter);

	hdd_debug("DHCP stop indicated through power save");
	sme_dhcp_stop_ind(hdd_ctx->mac_handle, adapter->device_mode,
			  adapter->mac_addr.bytes,
			  adapter->vdev_id);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	hdd_allow_suspend(WIFI_POWER_EVENT_WAKELOCK_DHCP);
	qdf_runtime_pm_allow_suspend(&hdd_ctx->runtime_context.connect);
}

/**
 * hdd_start_dhcp_ind() - API to start DHCP sequence
 * @adapter: Adapter on which DHCP needs to be stopped
 *
 * Prevent APPS suspend and the runtime suspend during
 * DHCP sequence
 *
 * Return: None
 */
<<<<<<< HEAD
static void hdd_start_dhcp_ind(hdd_adapter_t *adapter)
{
	hdd_context_t *hdd_ctx = WLAN_HDD_GET_CTX(adapter);
=======
static void hdd_start_dhcp_ind(struct hdd_adapter *adapter)
{
	struct hdd_context *hdd_ctx = WLAN_HDD_GET_CTX(adapter);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	hdd_debug("DHCP start indicated through power save");
	qdf_runtime_pm_prevent_suspend(&hdd_ctx->runtime_context.connect);
	hdd_prevent_suspend_timeout(HDD_WAKELOCK_TIMEOUT_CONNECT,
				    WIFI_POWER_EVENT_WAKELOCK_DHCP);
<<<<<<< HEAD
	sme_dhcp_start_ind(hdd_ctx->hHal, adapter->device_mode,
			   adapter->macAddressCurrent.bytes,
			   adapter->sessionId);
=======
	sme_dhcp_start_ind(hdd_ctx->mac_handle, adapter->device_mode,
			   adapter->mac_addr.bytes,
			   adapter->vdev_id);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * __wlan_hdd_cfg80211_set_power_mgmt() - set cfg80211 power management config
 * @wiphy: Pointer to wiphy
 * @dev: Pointer to network device
 * @allow_power_save: is wlan allowed to go into power save mode
 * @timeout: Timeout value in ms
 *
 * Return: 0 for success, non-zero for failure
 */
static int __wlan_hdd_cfg80211_set_power_mgmt(struct wiphy *wiphy,
					      struct net_device *dev,
					      bool allow_power_save,
					      int timeout)
{
<<<<<<< HEAD
	hdd_adapter_t *pAdapter = WLAN_HDD_GET_PRIV_PTR(dev);
	hdd_context_t *pHddCtx;
	QDF_STATUS qdf_status;
	int status;

	ENTER();
=======
	struct hdd_adapter *adapter = WLAN_HDD_GET_PRIV_PTR(dev);
	struct hdd_context *hdd_ctx;
	int status;

	hdd_enter();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	if (timeout < 0) {
		hdd_debug("User space timeout: %d; Enter full power or power save",
			  timeout);
		timeout = 0;
	}

	if (QDF_GLOBAL_FTM_MODE == hdd_get_conparam()) {
		hdd_err("Command not allowed in FTM mode");
		return -EINVAL;
	}

<<<<<<< HEAD
	if (wlan_hdd_validate_session_id(pAdapter->sessionId)) {
		hdd_err("invalid session id: %d", pAdapter->sessionId);
		return -EINVAL;
	}

	MTRACE(qdf_trace(QDF_MODULE_ID_HDD,
			 TRACE_CODE_HDD_CFG80211_SET_POWER_MGMT,
			 pAdapter->sessionId, timeout));

	pHddCtx = WLAN_HDD_GET_CTX(pAdapter);
	status = wlan_hdd_validate_context(pHddCtx);
=======
	if (wlan_hdd_validate_vdev_id(adapter->vdev_id))
		return -EINVAL;

	qdf_mtrace(QDF_MODULE_ID_HDD, QDF_MODULE_ID_HDD,
		   TRACE_CODE_HDD_CFG80211_SET_POWER_MGMT,
		   adapter->vdev_id, timeout);

	hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	status = wlan_hdd_validate_context(hdd_ctx);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	if (0 != status)
		return status;

<<<<<<< HEAD
	mutex_lock(&pHddCtx->iface_change_lock);
	if (pHddCtx->driver_status != DRIVER_MODULES_ENABLED) {
		mutex_unlock(&pHddCtx->iface_change_lock);
		hdd_debug("Driver Module not enabled return success");
		return 0;
	}
	mutex_unlock(&pHddCtx->iface_change_lock);

	if (allow_power_save &&
	    pHddCtx->hdd_wlan_suspended &&
	    pHddCtx->config->fhostArpOffload &&
	    (eConnectionState_Associated ==
	     (WLAN_HDD_GET_STATION_CTX_PTR(pAdapter))->conn_info.connState)) {
		hdd_debug("offload: calling arp offload");
		qdf_status = hdd_conf_arp_offload(pAdapter, true);
		if (!QDF_IS_STATUS_SUCCESS(qdf_status)) {
			hdd_debug("Failed to enable ARPOFFLOAD Feature %d",
				qdf_status);
		}
	}

	status = wlan_hdd_set_powersave(pAdapter, allow_power_save, timeout);

	allow_power_save ? hdd_stop_dhcp_ind(pAdapter) :
		hdd_start_dhcp_ind(pAdapter);

	EXIT();
	return status;
}

/**
 * wlan_hdd_cfg80211_set_power_mgmt() - set cfg80211 power management config
 * @wiphy: Pointer to wiphy
 * @dev: Pointer to network device
 * @allow_power_save: is wlan allowed to go into power save mode
 * @timeout: Timeout value
 *
 * Return: 0 for success, non-zero for failure
 */
=======
	if (hdd_ctx->driver_status != DRIVER_MODULES_ENABLED) {
		hdd_debug("Driver Module not enabled return success");
		return 0;
	}

	status = wlan_hdd_set_powersave(adapter, allow_power_save, timeout);

	allow_power_save ? hdd_stop_dhcp_ind(adapter) :
		hdd_start_dhcp_ind(adapter);

	hdd_exit();
	return status;
}

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
int wlan_hdd_cfg80211_set_power_mgmt(struct wiphy *wiphy,
				     struct net_device *dev,
				     bool allow_power_save,
				     int timeout)
{
<<<<<<< HEAD
	int ret;

	cds_ssr_protect(__func__);
	ret = __wlan_hdd_cfg80211_set_power_mgmt(wiphy, dev,
		allow_power_save, timeout);
	cds_ssr_unprotect(__func__);

	return ret;
=======
	int errno;
	struct osif_vdev_sync *vdev_sync;

	errno = osif_vdev_sync_op_start(dev, &vdev_sync);
	if (errno)
		return errno;

	errno = __wlan_hdd_cfg80211_set_power_mgmt(wiphy, dev, allow_power_save,
						   timeout);

	osif_vdev_sync_op_stop(vdev_sync);

	return errno;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * __wlan_hdd_cfg80211_set_txpower() - set TX power
 * @wiphy: Pointer to wiphy
 * @wdev: Pointer to network device
 * @type: TX power setting type
<<<<<<< HEAD
 * @dbm: TX power in dbm
=======
 * @mbm: TX power in mBm
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *
 * Return: 0 for success, non-zero for failure
 */
static int __wlan_hdd_cfg80211_set_txpower(struct wiphy *wiphy,
					   struct wireless_dev *wdev,
					   enum nl80211_tx_power_setting type,
<<<<<<< HEAD
					   int dbm)
{
	hdd_context_t *pHddCtx = (hdd_context_t *) wiphy_priv(wiphy);
	tHalHandle hHal = NULL;
	struct qdf_mac_addr bssid = QDF_MAC_ADDR_BROADCAST_INITIALIZER;
	struct qdf_mac_addr selfMac = QDF_MAC_ADDR_BROADCAST_INITIALIZER;
	int status;

	ENTER();
=======
					   int mbm)
{
	struct hdd_context *hdd_ctx = (struct hdd_context *) wiphy_priv(wiphy);
	mac_handle_t mac_handle;
	struct hdd_adapter *adapter;
	struct qdf_mac_addr bssid = QDF_MAC_ADDR_BCAST_INIT;
	struct qdf_mac_addr selfmac;
	QDF_STATUS status;
	int errno;
	int dbm;

	hdd_enter();

	if (!wdev) {
		hdd_err("wdev is null, set tx power failed");
		return -EIO;
	}

	adapter = WLAN_HDD_GET_PRIV_PTR(wdev->netdev);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	if (QDF_GLOBAL_FTM_MODE == hdd_get_conparam()) {
		hdd_err("Command not allowed in FTM mode");
		return -EINVAL;
	}

<<<<<<< HEAD
	MTRACE(qdf_trace(QDF_MODULE_ID_HDD,
			 TRACE_CODE_HDD_CFG80211_SET_TXPOWER,
			 NO_SESSION, type));

	status = wlan_hdd_validate_context(pHddCtx);
	if (0 != status)
		return status;

	hHal = pHddCtx->hHal;

	if (0 != sme_cfg_set_int(hHal, WNI_CFG_CURRENT_TX_POWER_LEVEL, dbm)) {
		hdd_err("sme_cfg_set_int failed for tx power %hu",
				dbm);
=======
	qdf_mtrace(QDF_MODULE_ID_HDD, QDF_MODULE_ID_HDD,
		   TRACE_CODE_HDD_CFG80211_SET_TXPOWER,
		   NO_SESSION, type);

	errno = wlan_hdd_validate_context(hdd_ctx);
	if (errno)
		return errno;

	if (wlan_hdd_validate_vdev_id(adapter->vdev_id))
		return -EINVAL;

	if (adapter->device_mode == QDF_SAP_MODE ||
	    adapter->device_mode == QDF_P2P_GO_MODE) {
		qdf_copy_macaddr(&bssid, &adapter->mac_addr);
	} else {
		struct hdd_station_ctx *sta_ctx =
			WLAN_HDD_GET_STATION_CTX_PTR(adapter);

		if (eConnectionState_Associated ==
		    sta_ctx->conn_info.conn_state)
			qdf_copy_macaddr(&bssid, &sta_ctx->conn_info.bssid);
	}

	qdf_copy_macaddr(&selfmac, &adapter->mac_addr);

	mac_handle = hdd_ctx->mac_handle;

	dbm = MBM_TO_DBM(mbm);

	/*
	 * the original implementation of this function expected power
	 * values in dBm instead of mBm. If the conversion from mBm to
	 * dBm is zero, then assume dBm was passed.
	 */
	if (!dbm)
		dbm = mbm;

	status = ucfg_mlme_set_current_tx_power_level(hdd_ctx->psoc, dbm);
	if (QDF_IS_STATUS_ERROR(status)) {
		hdd_err("sme_cfg_set_int failed for tx power %hu, %d",
			dbm, status);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return -EIO;
	}

	hdd_debug("Set tx power level %d dbm", dbm);

	switch (type) {
	/* Automatically determine transmit power */
	case NL80211_TX_POWER_AUTOMATIC:
	/* Fall through */
	case NL80211_TX_POWER_LIMITED:
	/* Limit TX power by the mBm parameter */
<<<<<<< HEAD
		if (sme_set_max_tx_power(hHal, bssid, selfMac, dbm) !=
		    QDF_STATUS_SUCCESS) {
			hdd_err("Setting maximum tx power failed");
=======
		status = sme_set_max_tx_power(mac_handle, bssid, selfmac, dbm);
		if (QDF_IS_STATUS_ERROR(status)) {
			hdd_err("Setting maximum tx power failed, %d", status);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			return -EIO;
		}
		break;

	case NL80211_TX_POWER_FIXED:    /* Fix TX power to the mBm parameter */
		hdd_err("NL80211_TX_POWER_FIXED not supported");
		return -EOPNOTSUPP;

	default:
		hdd_err("Invalid power setting type %d", type);
		return -EIO;
	}

<<<<<<< HEAD
	EXIT();
	return 0;
}

/**
 * wlan_hdd_cfg80211_set_txpower() - set TX power
 * @wiphy: Pointer to wiphy
 * @wdev: Pointer to network device
 * @type: TX power setting type
 * @dbm: TX power in dbm
 *
 * Return: 0 for success, non-zero for failure
 */
int wlan_hdd_cfg80211_set_txpower(struct wiphy *wiphy,
				  struct wireless_dev *wdev,
				  enum nl80211_tx_power_setting type,
				  int dbm)
{
	int ret;

	cds_ssr_protect(__func__);
	ret = __wlan_hdd_cfg80211_set_txpower(wiphy,
					      wdev,
					      type, dbm);
	cds_ssr_unprotect(__func__);

	return ret;
}
=======
	hdd_exit();
	return 0;
}

int wlan_hdd_cfg80211_set_txpower(struct wiphy *wiphy,
				  struct wireless_dev *wdev,
				  enum nl80211_tx_power_setting type,
				  int mbm)
{
	struct osif_psoc_sync *psoc_sync;
	int errno;

	errno = osif_psoc_sync_op_start(wiphy_dev(wiphy), &psoc_sync);
	if (errno)
		return errno;

	errno = __wlan_hdd_cfg80211_set_txpower(wiphy, wdev, type, mbm);

	osif_psoc_sync_op_stop(psoc_sync);

	return errno;
}

static void wlan_hdd_get_tx_power(struct hdd_adapter *adapter, int *dbm)

{
	wlan_cfg80211_mc_cp_stats_get_tx_power(adapter->vdev, dbm);
}

#ifdef FEATURE_ANI_LEVEL_REQUEST
static void hdd_get_ani_level_cb(struct wmi_host_ani_level_event *ani,
				 uint8_t num, void *context)
{
	struct osif_request *request;
	struct ani_priv *priv;
	uint8_t min_recv_freqs = QDF_MIN(num, MAX_NUM_FREQS_FOR_ANI_LEVEL);

	request = osif_request_get(context);
	if (!request) {
		hdd_err("Obsolete request");
		return;
	}

	/* propagate response back to requesting thread */
	priv = osif_request_priv(request);
	priv->ani = qdf_mem_malloc(min_recv_freqs *
				   sizeof(struct wmi_host_ani_level_event));
	if (!priv->ani)
		goto complete;

	priv->num_freq = min_recv_freqs;
	qdf_mem_copy(priv->ani, ani,
		     min_recv_freqs * sizeof(struct wmi_host_ani_level_event));

complete:
	osif_request_complete(request);
	osif_request_put(request);
}

/**
 * wlan_hdd_get_ani_level_dealloc() - Dealloc mem allocated in priv data
 * @priv: the priv data
 *
 * Return: None
 */
static void wlan_hdd_get_ani_level_dealloc(void *priv)
{
	struct ani_priv *ani = priv;

	if (ani->ani)
		qdf_mem_free(ani->ani);
}

QDF_STATUS wlan_hdd_get_ani_level(struct hdd_adapter *adapter,
				  struct wmi_host_ani_level_event *ani,
				  uint32_t *parsed_freqs,
				  uint8_t num_freqs)
{
	struct hdd_context *hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	int ret;
	QDF_STATUS status;
	void *cookie;
	struct osif_request *request;
	struct ani_priv *priv;
	static const struct osif_request_params params = {
		.priv_size = sizeof(*priv),
		.timeout_ms = 1000,
		.dealloc = wlan_hdd_get_ani_level_dealloc,
	};

	if (!hdd_ctx) {
		hdd_err("Invalid HDD context");
		return QDF_STATUS_E_INVAL;
	}

	request = osif_request_alloc(&params);
	if (!request) {
		hdd_err("Request allocation failure");
		return QDF_STATUS_E_NOMEM;
	}
	cookie = osif_request_cookie(request);

	status = sme_get_ani_level(hdd_ctx->mac_handle, parsed_freqs,
				   num_freqs, hdd_get_ani_level_cb, cookie);

	if (QDF_IS_STATUS_ERROR(status)) {
		hdd_err("Unable to retrieve ani level");
		goto complete;
	} else {
		/* request was sent -- wait for the response */
		ret = osif_request_wait_for_response(request);
		if (ret) {
			hdd_err("SME timed out while retrieving ANI level");
			status = QDF_STATUS_E_TIMEOUT;
			goto complete;
		}
	}

	priv = osif_request_priv(request);

	qdf_mem_copy(ani, priv->ani, sizeof(struct wmi_host_ani_level_event) *
		     priv->num_freq);

complete:
	/*
	 * either we never sent a request, we sent a request and
	 * received a response or we sent a request and timed out.
	 * regardless we are done with the request.
	 */
	osif_request_put(request);

	hdd_exit();
	return status;
}
#endif
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * __wlan_hdd_cfg80211_get_txpower() - get TX power
 * @wiphy: Pointer to wiphy
 * @wdev: Pointer to network device
 * @dbm: Pointer to TX power in dbm
 *
 * Return: 0 for success, non-zero for failure
 */
static int __wlan_hdd_cfg80211_get_txpower(struct wiphy *wiphy,
				  struct wireless_dev *wdev,
				  int *dbm)
{

<<<<<<< HEAD
	hdd_context_t *pHddCtx = (hdd_context_t *) wiphy_priv(wiphy);
	struct net_device *ndev = wdev->netdev;
	hdd_adapter_t *adapter = WLAN_HDD_GET_PRIV_PTR(ndev);
	int status;
	hdd_station_ctx_t *sta_ctx = WLAN_HDD_GET_STATION_CTX_PTR(adapter);

	ENTER();
=======
	struct hdd_context *hdd_ctx = (struct hdd_context *) wiphy_priv(wiphy);
	struct net_device *ndev = wdev->netdev;
	struct hdd_adapter *adapter = WLAN_HDD_GET_PRIV_PTR(ndev);
	int status;
	struct hdd_station_ctx *sta_ctx;
	static bool is_rate_limited;

	hdd_enter_dev(ndev);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	if (QDF_GLOBAL_FTM_MODE == hdd_get_conparam()) {
		hdd_err("Command not allowed in FTM mode");
		return -EINVAL;
	}

<<<<<<< HEAD
	status = wlan_hdd_validate_context(pHddCtx);
	if (0 != status) {
		*dbm = 0;
		return status;
	}

	/* Validate adapter sessionId */
	if (wlan_hdd_validate_session_id(adapter->sessionId)) {
		hdd_debug("invalid session id: %d", adapter->sessionId);
		return -EINVAL;
	}

	if (sta_ctx->hdd_ReassocScenario) {
		hdd_debug("Roaming is in progress, rej this req");
		return -EINVAL;
	}

	mutex_lock(&pHddCtx->iface_change_lock);
	if (pHddCtx->driver_status != DRIVER_MODULES_ENABLED) {
		mutex_unlock(&pHddCtx->iface_change_lock);
		hdd_debug("Driver Module not enabled return success");
		/* Send cached data to upperlayer*/
		*dbm = adapter->hdd_stats.ClassA_stat.max_pwr;
		return 0;
	}
	mutex_unlock(&pHddCtx->iface_change_lock);

	if (sta_ctx->conn_info.connState != eConnectionState_Associated) {
		hdd_debug("Not associated");
		/*To keep GUI happy */
		*dbm = 0;
		return 0;
	}

	MTRACE(qdf_trace(QDF_MODULE_ID_HDD,
			 TRACE_CODE_HDD_CFG80211_GET_TXPOWER,
			 adapter->sessionId, adapter->device_mode));
	wlan_hdd_get_class_astats(adapter);
	*dbm = adapter->hdd_stats.ClassA_stat.max_pwr;

	EXIT();
	return 0;
}

/**
 * wlan_hdd_cfg80211_get_txpower() - cfg80211 get power handler function
 * @wiphy: Pointer to wiphy structure.
 * @wdev: Pointer to wireless_dev structure.
 * @dbm: dbm
 *
 * This is the cfg80211 get txpower handler function which invokes
 * the internal function @__wlan_hdd_cfg80211_get_txpower with
 * SSR protection.
 *
 * Return: 0 for success, error number on failure.
 */
=======
	*dbm = 0;

	status = wlan_hdd_validate_context(hdd_ctx);
	if (status)
		return status;

	/* Validate adapter sessionId */
	status = wlan_hdd_validate_vdev_id(adapter->vdev_id);
	if (status)
		return status;
	switch (adapter->device_mode) {
	case QDF_STA_MODE:
	case QDF_P2P_CLIENT_MODE:
		sta_ctx = WLAN_HDD_GET_STATION_CTX_PTR(adapter);
		if (sta_ctx->hdd_reassoc_scenario) {
			hdd_debug("Roaming is in progress, rej this req");
			return -EINVAL;
		}
		if (sta_ctx->conn_info.conn_state !=
		    eConnectionState_Associated) {
			hdd_debug("Not associated");
			return 0;
		}
		break;
	case QDF_SAP_MODE:
	case QDF_P2P_GO_MODE:
		if (!test_bit(SOFTAP_BSS_STARTED, &adapter->event_flags)) {
			hdd_debug("SAP is not started yet");
			return 0;
		}
		break;
	default:
		hdd_debug_rl("Current interface is not supported for get tx_power");
		return 0;
	}

	HDD_IS_RATE_LIMIT_REQ(is_rate_limited,
			      hdd_ctx->config->nb_commands_interval);
	if (hdd_ctx->driver_status != DRIVER_MODULES_ENABLED ||
	    is_rate_limited) {
		hdd_debug("Modules not enabled/rate limited, use cached stats");
		/* Send cached data to upperlayer*/
		*dbm = adapter->hdd_stats.class_a_stat.max_pwr;
		return 0;
	}

	qdf_mtrace(QDF_MODULE_ID_HDD, QDF_MODULE_ID_HDD,
		   TRACE_CODE_HDD_CFG80211_GET_TXPOWER,
		   adapter->vdev_id, adapter->device_mode);

	wlan_hdd_get_tx_power(adapter, dbm);
	hdd_debug("power: %d", *dbm);

	return 0;
}

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
int wlan_hdd_cfg80211_get_txpower(struct wiphy *wiphy,
					 struct wireless_dev *wdev,
					 int *dbm)
{
<<<<<<< HEAD
	int ret;

	cds_ssr_protect(__func__);
	ret = __wlan_hdd_cfg80211_get_txpower(wiphy, wdev, dbm);
	cds_ssr_unprotect(__func__);

	return ret;
}

/**
 * hdd_set_qpower_config() - set qpower config to firmware
 * @adapter: HDD adapter
 * @qpower: new qpower config value
 *
 * Return: 0 on success; Errno on failure
 */
int hdd_set_qpower_config(hdd_context_t *hddctx, hdd_adapter_t *adapter,
			  u8 qpower)
{
	QDF_STATUS status;

	if (!hddctx->config->enablePowersaveOffload) {
		hdd_err("qpower is disabled in configuration");
		return -EINVAL;
	}
	if (adapter->device_mode != QDF_STA_MODE &&
	    adapter->device_mode != QDF_P2P_CLIENT_MODE) {
		hdd_debug(FL("QPOWER only allowed in STA/P2P-Client modes:%d "),
			adapter->device_mode);
		return -EINVAL;
	}

	if (qpower > PS_DUTY_CYCLING_QPOWER ||
	    qpower < PS_LEGACY_NODEEPSLEEP) {
		hdd_err("invalid qpower value: %d", qpower);
		return -EINVAL;
	}

	if (hddctx->config->nMaxPsPoll) {
		if ((qpower == PS_QPOWER_NODEEPSLEEP) ||
				(qpower == PS_LEGACY_NODEEPSLEEP))
			qpower = PS_LEGACY_NODEEPSLEEP;
		else
			qpower = PS_LEGACY_DEEPSLEEP;
		hdd_info("Qpower disabled, %d", qpower);
	}
	status = wma_set_qpower_config(adapter->sessionId, qpower);
	if (status != QDF_STATUS_SUCCESS) {
		hdd_err("failed to configure qpower: %d", status);
		return -EINVAL;
	}

	return 0;
}

#ifdef WLAN_SUSPEND_RESUME_TEST
/*
 * On iHelium there are 12 CE irqs and #2 is the wake irq. This may not be
 * a valid assumption on future platforms.
 */
#define CE_IRQ_COUNT 12
#define CE_WAKE_IRQ 2
static struct net_device *g_dev;
static struct wiphy *g_wiphy;
=======
	struct osif_psoc_sync *psoc_sync;
	int errno;

	errno = osif_psoc_sync_op_start(wiphy_dev(wiphy), &psoc_sync);
	if (errno)
		return errno;

	errno = __wlan_hdd_cfg80211_get_txpower(wiphy, wdev, dbm);

	osif_psoc_sync_op_stop(psoc_sync);

	return errno;
}

int hdd_set_power_config(struct hdd_context *hddctx,
			 struct hdd_adapter *adapter,
			 uint8_t power)
{
	QDF_STATUS status;

	if (adapter->device_mode != QDF_STA_MODE &&
	    adapter->device_mode != QDF_P2P_CLIENT_MODE) {
		hdd_info("Advanced power save only allowed in STA/P2P-Client modes:%d",
			 adapter->device_mode);
		return -EINVAL;
	}

	if (power > PMO_PS_ADVANCED_POWER_SAVE_ENABLE ||
	    power < PMO_PS_ADVANCED_POWER_SAVE_DISABLE) {
		hdd_err("invalid power value: %d", power);
		return -EINVAL;
	}

	if (ucfg_pmo_get_max_ps_poll(hddctx->psoc)) {
		hdd_info("Disable advanced power save since max ps poll is enabled");
		power = PMO_PS_ADVANCED_POWER_SAVE_DISABLE;
	}

	status = wma_set_power_config(adapter->vdev_id, power);
	if (status != QDF_STATUS_SUCCESS) {
		hdd_err("failed to configure power: %d", status);
		return -EINVAL;
	}

	/* cache latest userspace power save config to reapply after SSR */
	ucfg_pmo_set_power_save_mode(hddctx->psoc, power);

	return 0;
}


#ifdef WLAN_SUSPEND_RESUME_TEST
static struct net_device *g_dev;
static struct wiphy *g_wiphy;
static enum wow_resume_trigger g_resume_trigger;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

#define HDD_FA_SUSPENDED_BIT (0)
static unsigned long fake_apps_state;

/**
 * __hdd_wlan_fake_apps_resume() - The core logic for
 *	hdd_wlan_fake_apps_resume() skipping the call to hif_fake_apps_resume(),
 *	which is only need for non-irq resume
 * @wiphy: the kernel wiphy struct for the device being resumed
 * @dev: the kernel net_device struct for the device being resumed
 *
 * Return: none, calls QDF_BUG() on failure
 */
static void __hdd_wlan_fake_apps_resume(struct wiphy *wiphy,
					struct net_device *dev)
{
<<<<<<< HEAD
	qdf_device_t qdf_dev;
	int i, resume_err;

	hdd_debug("Unit-test resume WLAN");
=======
	struct hif_opaque_softc *hif_ctx;
	qdf_device_t qdf_dev;

	hdd_info("Unit-test resume WLAN");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	qdf_dev = cds_get_context(QDF_MODULE_ID_QDF_DEVICE);
	if (!qdf_dev) {
		hdd_err("Failed to get QDF device context");
		QDF_BUG(0);
		return;
	}

<<<<<<< HEAD
	if (!test_and_clear_bit(HDD_FA_SUSPENDED_BIT, &fake_apps_state)) {
		hdd_debug("Not unit-test suspended; Nothing to do");
		return;
	}

	/* disable wake irq */
	pld_disable_irq(qdf_dev->dev, CE_WAKE_IRQ);

	resume_err = wlan_hdd_bus_resume_noirq();
	QDF_BUG(resume_err == 0);

	/* simulate kernel enable irqs */
	for (i = 0; i < CE_IRQ_COUNT; i++)
		pld_enable_irq(qdf_dev->dev, i);

	resume_err = wlan_hdd_bus_resume();
	QDF_BUG(resume_err == 0);

	resume_err = wlan_hdd_cfg80211_resume_wlan(wiphy);
	QDF_BUG(resume_err == 0);

	dev->watchdog_timeo = HDD_TX_TIMEOUT;

	hdd_debug("Unit-test resume succeeded");
=======
	hif_ctx = cds_get_context(QDF_MODULE_ID_HIF);
	if (!hif_ctx) {
		hdd_err("Failed to get HIF context");
		return;
	}

	if (!test_and_clear_bit(HDD_FA_SUSPENDED_BIT, &fake_apps_state)) {
		hdd_alert("Not unit-test suspended; Nothing to do");
		return;
	}

	/* simulate kernel disable irqs */
	QDF_BUG(!hif_apps_wake_irq_disable(hif_ctx));

	QDF_BUG(!wlan_hdd_bus_resume_noirq());

	/* simulate kernel enable irqs */
	QDF_BUG(!hif_apps_irqs_enable(hif_ctx));

	QDF_BUG(!wlan_hdd_bus_resume());

	QDF_BUG(!wlan_hdd_cfg80211_resume_wlan(wiphy));

	if (g_resume_trigger == WOW_RESUME_TRIGGER_HTC_WAKEUP)
		hif_vote_link_down(hif_ctx);

	dev->watchdog_timeo = HDD_TX_TIMEOUT;

	hdd_alert("Unit-test resume succeeded");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * hdd_wlan_fake_apps_resume_irq_callback() - Irq callback function for resuming
 *	from unit-test initiated suspend from irq wakeup signal
<<<<<<< HEAD
 * @val: interrupt val
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *
 * Resume wlan after getting very 1st CE interrupt from target
 *
 * Return: none
 */
<<<<<<< HEAD
static void hdd_wlan_fake_apps_resume_irq_callback(uint32_t val)
{
	hdd_debug("Trigger unit-test resume WLAN; val: 0x%x", val);
=======
static void hdd_wlan_fake_apps_resume_irq_callback(void)
{
	hdd_info("Trigger unit-test resume WLAN");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	QDF_BUG(g_wiphy);
	QDF_BUG(g_dev);
	__hdd_wlan_fake_apps_resume(g_wiphy, g_dev);
	g_wiphy = NULL;
	g_dev = NULL;
}

<<<<<<< HEAD
int hdd_wlan_fake_apps_suspend(struct wiphy *wiphy, struct net_device *dev)
{
	qdf_device_t qdf_dev;
	struct hif_opaque_softc *hif_ctx;
	pm_message_t state;
	int i, resume_err, suspend_err;

	hdd_debug("Unit-test suspend WLAN");
=======
int hdd_wlan_fake_apps_suspend(struct wiphy *wiphy, struct net_device *dev,
			       enum wow_interface_pause pause_setting,
			       enum wow_resume_trigger resume_setting)
{
	int errno;
	qdf_device_t qdf_dev;
	struct hif_opaque_softc *hif_ctx;
	struct hdd_context *hdd_ctx = cds_get_context(QDF_MODULE_ID_HDD);
	struct wow_enable_params wow_params = {
		.is_unit_test = true,
		.interface_pause = pause_setting,
		.resume_trigger = resume_setting
	};

	if (wlan_hdd_validate_context(hdd_ctx))
		return -EINVAL;

	if (!hdd_ctx->config->is_unit_test_framework_enabled) {
		hdd_warn_rl("UT framework is disabled");
		return -EINVAL;
	}

	hdd_info("Unit-test suspend WLAN");

	if (pause_setting < WOW_INTERFACE_PAUSE_DEFAULT ||
	    pause_setting >= WOW_INTERFACE_PAUSE_COUNT) {
		hdd_err("Invalid interface pause %d (expected range [0, 2])",
			pause_setting);
		return -EINVAL;
	}

	if (resume_setting < WOW_RESUME_TRIGGER_DEFAULT ||
	    resume_setting >= WOW_RESUME_TRIGGER_COUNT) {
		hdd_err("Invalid resume trigger %d (expected range [0, 2])",
			resume_setting);
		return -EINVAL;
	}
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	qdf_dev = cds_get_context(QDF_MODULE_ID_QDF_DEVICE);
	if (!qdf_dev) {
		hdd_err("Failed to get QDF device context");
		return -EINVAL;
	}

	hif_ctx = cds_get_context(QDF_MODULE_ID_HIF);
	if (!hif_ctx) {
		hdd_err("Failed to get HIF context");
		return -EINVAL;
	}

	if (test_and_set_bit(HDD_FA_SUSPENDED_BIT, &fake_apps_state)) {
<<<<<<< HEAD
		hdd_debug("Already unit-test suspended; Nothing to do");
		return 0;
	}

	suspend_err = wlan_hdd_cfg80211_suspend_wlan(wiphy, NULL);
	if (suspend_err)
		goto resume_done;

	state.event = PM_EVENT_SUSPEND;
	suspend_err = wlan_hdd_unit_test_bus_suspend(state);
	if (suspend_err)
		goto cfg80211_resume;

	/* simulate kernel disabling irqs */
	for (i = 0; i < CE_IRQ_COUNT; i++)
		pld_disable_irq(qdf_dev->dev, i);

	suspend_err = wlan_hdd_bus_suspend_noirq();
	if (suspend_err)
		goto enable_irqs_and_bus_resume;

	/* re-enable wake irq */
	pld_enable_irq(qdf_dev->dev, CE_WAKE_IRQ);
=======
		hdd_alert("Already unit-test suspended; Nothing to do");
		return 0;
	}

	/* pci link is needed to wakeup from HTC wakeup trigger */
	if (resume_setting == WOW_RESUME_TRIGGER_HTC_WAKEUP)
		hif_vote_link_up(hif_ctx);

	errno = wlan_hdd_cfg80211_suspend_wlan(wiphy, NULL);
	if (errno)
		goto link_down;

	errno = wlan_hdd_unit_test_bus_suspend(wow_params);
	if (errno)
		goto cfg80211_resume;

	/* simulate kernel disabling irqs */
	errno = hif_apps_irqs_disable(hif_ctx);
	if (errno)
		goto bus_resume;

	errno = wlan_hdd_bus_suspend_noirq();
	if (errno)
		goto enable_irqs;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	/* pass wiphy/dev to callback via global variables */
	g_wiphy = wiphy;
	g_dev = dev;
<<<<<<< HEAD
	hif_fake_apps_suspend(hif_ctx, hdd_wlan_fake_apps_resume_irq_callback);
=======
	g_resume_trigger = resume_setting;
	hif_ut_apps_suspend(hif_ctx, hdd_wlan_fake_apps_resume_irq_callback);

	/* re-enable wake irq */
	errno = hif_apps_wake_irq_enable(hif_ctx);
	if (errno)
		goto fake_apps_resume;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	/*
	 * Tell the kernel not to worry if TX queues aren't moving. This is
	 * expected since we are suspending the wifi hardware, but not APPS
	 */
	dev->watchdog_timeo = INT_MAX;

<<<<<<< HEAD
	hdd_debug("Unit-test suspend succeeded");
	return 0;

enable_irqs_and_bus_resume:
	/* re-enable irqs */
	for (i = 0; i < CE_IRQ_COUNT; i++)
		pld_enable_irq(qdf_dev->dev, i);

	resume_err = wlan_hdd_bus_resume();
	QDF_BUG(resume_err == 0);

cfg80211_resume:
	resume_err = wlan_hdd_cfg80211_resume_wlan(wiphy);
	QDF_BUG(resume_err == 0);

resume_done:
	clear_bit(HDD_FA_SUSPENDED_BIT, &fake_apps_state);
	hdd_err("Unit-test suspend failed: %d", suspend_err);
	return suspend_err;
=======
	hdd_alert("Unit-test suspend succeeded");

	return 0;

fake_apps_resume:
	hif_ut_apps_resume(hif_ctx);

enable_irqs:
	QDF_BUG(!hif_apps_irqs_enable(hif_ctx));

bus_resume:
	QDF_BUG(!wlan_hdd_bus_resume());

cfg80211_resume:
	QDF_BUG(!wlan_hdd_cfg80211_resume_wlan(wiphy));

link_down:
	hif_vote_link_down(hif_ctx);

	clear_bit(HDD_FA_SUSPENDED_BIT, &fake_apps_state);
	hdd_err("Unit-test suspend failed: %d", errno);

	return errno;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

int hdd_wlan_fake_apps_resume(struct wiphy *wiphy, struct net_device *dev)
{
	struct hif_opaque_softc *hif_ctx;
<<<<<<< HEAD
=======
	struct hdd_context *hdd_ctx = cds_get_context(QDF_MODULE_ID_HDD);

	if (wlan_hdd_validate_context(hdd_ctx))
		return -EINVAL;

	if (!hdd_ctx->config->is_unit_test_framework_enabled) {
		hdd_warn_rl("UT framework is disabled");
		return -EINVAL;
	}
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	hif_ctx = cds_get_context(QDF_MODULE_ID_HIF);
	if (!hif_ctx) {
		hdd_err("Failed to get HIF context");
		return -EINVAL;
	}

<<<<<<< HEAD
	hif_fake_apps_resume(hif_ctx);
=======
	hif_ut_apps_resume(hif_ctx);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	__hdd_wlan_fake_apps_resume(wiphy, dev);

	return 0;
}
#endif
<<<<<<< HEAD

#ifdef FW_THERMAL_THROTTLE_SUPPORT
void hdd_send_thermal_notification(hdd_context_t *hdd_ctx,
				   enum hdd_thermal_states thermal_state)
{
	QDF_STATUS status;
	hdd_adapter_t *sta_adapter;
	bool is_sta_connected, is_sta_connecting, is_sta_disconnecting;

	if (!hdd_ctx) {
		hdd_err("hdd context is null");
		return;
	}

	if (!hdd_ctx->is_thermal_system_registered) {
		hdd_debug("Thermal system not registered! Ignore");
		return;
	}

	sta_adapter = hdd_get_adapter(hdd_ctx, QDF_STA_MODE);
	if (!sta_adapter) {
		hdd_err("STA adapter not present");
		return;
	}

	is_sta_connected = hdd_conn_is_connected(WLAN_HDD_GET_STATION_CTX_PTR(
						 sta_adapter));
	is_sta_connecting = hdd_is_connecting(WLAN_HDD_GET_STATION_CTX_PTR(
					      sta_adapter));
	is_sta_disconnecting =
		hdd_is_disconnecting(WLAN_HDD_GET_STATION_CTX_PTR(sta_adapter));

	if (cds_get_connection_count() > 1) {
		hdd_debug("Concurrent sessions present ignoring thermal notif");
		return;
	}

	if (is_sta_disconnecting) {
		hdd_debug("STA disconnecting; send disable thermal notif");
		thermal_state = 0;
		goto send;
	}

	if (!is_sta_connected || is_sta_connecting) {
		hdd_debug("STA not connected/connecting, ignore thermal notif");
		return;
	}

	switch (thermal_state) {
	case HDD_THERMAL_STATE_HIGH:
		cds_set_driver_thermal_mitigated(true);
		hdd_debug("STA connected, issue disconnect");
		wlan_hdd_disconnect(sta_adapter, eCSR_DISCONNECT_REASON_DEAUTH);

		/*
		 * Sending the thermal notification after disconnection will be
		 * taken care in the disconnect path, so return from here and
		 * do not send the notification now.
		 */
		return;
	case HDD_THERMAL_STATE_MEDIUM:
	case HDD_THERMAL_STATE_NORMAL:
		cds_set_driver_thermal_mitigated(false);
		break;
	default:
		hdd_err("Invalid thermal state: %d", thermal_state);
		return;
	}

send:
	status = wma_update_thermal_mitigation_to_fw(thermal_state);
	if (QDF_IS_STATUS_ERROR(status))
		hdd_err("Failed to send thermal mitigation to FW");
}

/**
 * hdd_thermal_mitigation_disable() - Disable thermal mitigation
 * @hdd_ctx: The HDD context
 *
 * This function verifies whether driver is already performing any sort of
 * thermal mitigation in connected STA scenario. If that is the case, then it
 * disables the thermal mitigation by sending command to FW.
 *
 * Return: None
 */
void hdd_thermal_mitigation_disable(hdd_context_t *hdd_ctx)
{
	if (cds_is_sta_active_connection_exists() &&
	    hdd_ctx->is_thermal_system_registered) {
		hdd_debug("Disabling thermal mitigation; STA+ concr not supp");
		hdd_send_thermal_notification(hdd_ctx,
					      HDD_THERMAL_STATE_NORMAL);
	}
}

/**
 * hdd_thermal_mitigation_enable() - Enable thermal mitigation
 * @hdd_ctx: The HDD context
 *
 * This function verifies whether driver is connected in STA with no concurrent
 * sessions active. If yes then it sends the current thermal state notification
 * to the firmware.
 *
 * Return: None
 */
void hdd_thermal_mitigation_enable(hdd_context_t *hdd_ctx)
{
	uint16_t thermal_state = HDD_THERMAL_STATE_NORMAL;

	if (cds_is_sta_active_connection_exists() &&
	    cds_get_connection_count() == 1 &&
	    hdd_ctx->is_thermal_system_registered) {
		hdd_debug("Re-enabling thermal mitigation");
		if (!pld_get_thermal_state(hdd_ctx->parent_dev, &thermal_state))
			hdd_send_thermal_notification(hdd_ctx,
						      hdd_map_thermal_states(
						      thermal_state));
	}
}

/**
 * hdd_map_thermal_states() - Return thermal state enum from int value
 * @state: The state that is to be mapped
 *
 * Return: enum hdd_thermal_states value for the corresponding state
 */
enum hdd_thermal_states hdd_map_thermal_states(uint16_t state)
{
	switch (state) {
	case 0:
		return HDD_THERMAL_STATE_NORMAL;
	case 1:
		return HDD_THERMAL_STATE_MEDIUM;
	case 2:
		return HDD_THERMAL_STATE_HIGH;
	default:
		hdd_err("Invalid thermal state");
		return HDD_THERMAL_STATE_INVAL;
	}
}
#endif
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

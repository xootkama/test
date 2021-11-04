/*
<<<<<<< HEAD
 * Copyright (c) 2012-2014, 2017-2018 The Linux Foundation. All rights reserved.
=======
 * Copyright (c) 2012-2014, 2017-2019, 2020 The Linux Foundation. All rights reserved.
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

#if !defined(WLAN_HDD_IOCTL_H)
#define WLAN_HDD_IOCTL_H

#include <linux/netdevice.h>
#include <uapi/linux/if.h>
#include "wlan_hdd_main.h"

extern struct sock *cesium_nl_srv_sock;

int hdd_ioctl(struct net_device *dev, struct ifreq *ifr, int cmd);
<<<<<<< HEAD
int wlan_hdd_set_mc_rate(hdd_adapter_t *pAdapter, int targetRate);
=======
int wlan_hdd_set_mc_rate(struct hdd_adapter *adapter, int target_rate);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * hdd_update_smps_antenna_mode() - set smps and antenna mode
 * @hdd_ctx: Pointer to hdd context
 * @mode: antenna mode
 *
 * This function will set smps and antenna mode.
 *
 * Return: QDF_STATUS
 */
<<<<<<< HEAD
QDF_STATUS hdd_update_smps_antenna_mode(hdd_context_t *hdd_ctx, int mode);
=======
QDF_STATUS hdd_update_smps_antenna_mode(struct hdd_context *hdd_ctx, int mode);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * hdd_set_antenna_mode() - SET ANTENNA MODE command handler
 * @adapter: Pointer to network adapter
 * @hdd_ctx: Pointer to hdd context
 * @mode: new anteena mode
 */
<<<<<<< HEAD
int hdd_set_antenna_mode(hdd_adapter_t *adapter,
				  hdd_context_t *hdd_ctx, int mode);

=======
int hdd_set_antenna_mode(struct hdd_adapter *adapter,
			  struct hdd_context *hdd_ctx, int mode);

#ifdef WLAN_FEATURE_ROAM_OFFLOAD
/**
 * hdd_get_roam_scan_ch_cb() - roam scan channel list callback handler
 * @hdd_handle: Pointer to hdd context
 * @roam_ch: pointer to roam scan ch event data
 * @context: cookie
 *
 * Callback function to processes roam scan chaanel list event. If
 * command response field in the response message is set that means
 * event received as a response of GETROAMSCANCHANNELS command else
 * event was rasied by firmware upon disconnection.
 *
 * Return: none
 */
void hdd_get_roam_scan_ch_cb(hdd_handle_t hdd_handle,
			     struct roam_scan_ch_resp *roam_ch,
			     void *context);

/**
 * hdd_get_roam_scan_freq() - roam scan freq list
 * @adapter: Pointer to hdd adapter
 * @mac_handle: pointer to mac_handle
 * @chan_list: Pointer to hold roam scan freq list
 * @num_channels: Pointer to hold num of roam scan channels in list
 *
 * This function gets roam scan frequencies from FW if FW is capable else
 * roam scan frequencies are taken from host maintained list.
 *
 * Return: 0 on success else error value
 */
int
hdd_get_roam_scan_freq(struct hdd_adapter *adapter, mac_handle_t mac_handle,
		       uint32_t *chan_list, uint8_t *num_channels);
#else
static inline void
hdd_get_roam_scan_ch_cb(hdd_handle_t hdd_handle,
			void *roam_ch,
			void *context)
{
}

static inline int
hdd_get_roam_scan_freq(struct hdd_adapter *adapter, mac_handle_t mac_handle,
		       uint32_t *chan_list, uint8_t *num_channels)
{
	return -EFAULT;
}
#endif

#ifdef QCA_IBSS_SUPPORT
/**
 * hdd_get_ibss_peer_info_cb() - IBSS peer Info request callback
 * @context: callback context (adapter supplied by caller)
 * @peer_info: Peer info response
 *
 * This is an asynchronous callback function from SME when the peer info
 * is received
 *
 * Return: 0 for success non-zero for failure
 */
void hdd_get_ibss_peer_info_cb(void *context,
				tSirPeerInfoRspParams *peer_info);
#else
static inline void
hdd_get_ibss_peer_info_cb(void *context,
			  tSirPeerInfoRspParams *peer_info)
{
}
#endif
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#endif /* end #if !defined(WLAN_HDD_IOCTL_H) */


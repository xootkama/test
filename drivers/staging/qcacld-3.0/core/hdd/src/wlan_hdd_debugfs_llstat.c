/*
<<<<<<< HEAD
 * Copyright (c) 2012-2018 The Linux Foundation. All rights reserved.
=======
 * Copyright (c) 2012-2019 The Linux Foundation. All rights reserved.
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
 * DOC: wlan_hdd_debugfs_llstat.c
 *
 * WLAN Host Device Driver implementation to update
 * debugfs with Link Layer statistics
 */

<<<<<<< HEAD
#include <wlan_hdd_debugfs_llstat.h>
#include <cds_sched.h>
=======
#include <cds_sched.h>
#include "osif_sync.h"
#include <wlan_hdd_debugfs_llstat.h>
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#include <wlan_hdd_stats.h>
#include <wma_api.h>

struct ll_stats_buf {
	ssize_t len;
	uint8_t *result;
};

static struct ll_stats_buf ll_stats;

static DEFINE_MUTEX(llstats_mutex);

<<<<<<< HEAD
void hdd_debugfs_process_iface_stats(hdd_adapter_t *adapter,
		void *data, uint32_t num_peers)
{
	tpSirWifiIfaceStat iface_stat;
	tpSirWifiInterfaceInfo iface_info;
	tpSirWifiWmmAcStat ac_stat;
	struct wifi_iface_offload_stat *offload_stat;
=======
void hdd_debugfs_process_iface_stats(struct hdd_adapter *adapter,
		void *data, uint32_t num_peers)
{
	struct wifi_interface_stats *iface_stat;
	struct wifi_interface_info *iface_info;
	wmi_iface_link_stats *link_stats;
	wmi_wmm_ac_stats *ac_stats;
	wmi_iface_offload_stats *offload_stats;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	uint64_t average_tsf_offset;
	int i;
	ssize_t len = 0;
	uint8_t *buffer;

<<<<<<< HEAD
	ENTER();
=======
	hdd_enter();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	mutex_lock(&llstats_mutex);
	if (!ll_stats.result) {
		mutex_unlock(&llstats_mutex);
		hdd_err("LL statistics buffer is NULL");
		return;
	}

	iface_stat = data;
	buffer = ll_stats.result;
	buffer += ll_stats.len;
	len = scnprintf(buffer, DEBUGFS_LLSTATS_BUF_SIZE - ll_stats.len,
			"\n\n===LL_STATS_IFACE: num_peers: %d===", num_peers);

	if (false == hdd_get_interface_info(adapter, &iface_stat->info)) {
		mutex_unlock(&llstats_mutex);
		hdd_err("hdd_get_interface_info get fail");
		return;
	}

	iface_info = &iface_stat->info;
	buffer += len;
	ll_stats.len += len;
	len = scnprintf(buffer, DEBUGFS_LLSTATS_BUF_SIZE - ll_stats.len,
<<<<<<< HEAD
			"\nmode: %u, MAC_ADDR: %pM, state: %u, roaming: %u, capabilities: %u, SSID: %s, BSSID_MAC: %pM, ap_country_str: %s, country_str: %s",
			iface_info->mode, &iface_info->macAddr.bytes[0],
			iface_info->state, iface_info->roaming,
			iface_info->capabilities, iface_info->ssid,
			&iface_info->bssid.bytes[0], iface_info->apCountryStr,
			iface_info->countryStr);

	average_tsf_offset =  iface_stat->avg_bcn_spread_offset_high;
	average_tsf_offset =  (average_tsf_offset << 32) |
				iface_stat->avg_bcn_spread_offset_low;
=======
			"\nmode: %u, MAC_ADDR: "QDF_FULL_MAC_FMT", state: %u, roaming: %u, capabilities: %u, SSID: %s, BSSID_MAC: "QDF_FULL_MAC_FMT", ap_country_str: %s, country_str: %s",
			iface_info->mode,
			QDF_FULL_MAC_REF(iface_info->macAddr.bytes),
			iface_info->state, iface_info->roaming,
			iface_info->capabilities, iface_info->ssid,
			QDF_FULL_MAC_REF(iface_info->bssid.bytes),
			iface_info->apCountryStr,
			iface_info->countryStr);

	link_stats = &iface_stat->link_stats;
	average_tsf_offset =  link_stats->avg_bcn_spread_offset_high;
	average_tsf_offset =  (average_tsf_offset << 32) |
				link_stats->avg_bcn_spread_offset_low;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	buffer += len;
	ll_stats.len += len;
	len = scnprintf(buffer, DEBUGFS_LLSTATS_BUF_SIZE - ll_stats.len,
<<<<<<< HEAD
			"\nbeacon_rx: %u, mgmt_rx: %u, mgmt_action_rx: %u, mgmt_action_tx: %u, rssi_mgmt: %u, rssi_data: %u, rssi_ack: %u, is_leaky_ap: %u, avg_rx_frms_leaked: %u, rx_leak_window: %u, average_tsf_offset: %llu, Tx RTS success count: %u, Tx RTS fail count: %u, Tx ppdu success count: %u, Tx ppdu fail count: %u, Connected duration: %u, Disconnected duration: %u, RTT ranging duration: %u, RTT responder duration: %u, Num tx probes: %u, Num beacon miss: %u,\n\nNumber of AC: %d",
			iface_stat->beaconRx, iface_stat->mgmtRx,
			iface_stat->mgmtActionRx, iface_stat->mgmtActionTx,
			iface_stat->rssiMgmt, iface_stat->rssiData,
			iface_stat->rssiAck, iface_stat->is_leaky_ap,
			iface_stat->avg_rx_frms_leaked,
			iface_stat->rx_leak_window, average_tsf_offset,
			iface_stat->tx_rts_succ_cnt,
			iface_stat->tx_rts_fail_cnt,
			iface_stat->tx_ppdu_succ_cnt,
			iface_stat->tx_ppdu_fail_cnt,
			iface_stat->connected_duration,
			iface_stat->disconnected_duration,
			iface_stat->rtt_ranging_duration,
			iface_stat->rtt_responder_duration,
			iface_stat->num_probes_tx, iface_stat->num_beacon_miss,
			iface_stat->num_ac);

	for (i = 0; i < iface_stat->num_ac; i++) {
		ac_stat = &iface_stat->AccessclassStats[i];
=======
			"\nbeacon_rx: %u, mgmt_rx: %u, mgmt_action_rx: %u, mgmt_action_tx: %u, rssi_mgmt: %d, rssi_data: %d, rssi_ack: %d, is_leaky_ap: %u, avg_rx_frms_leaked: %u, rx_leak_window: %u, average_tsf_offset: %llu, Tx RTS success count: %u, Tx RTS fail count: %u, Tx ppdu success count: %u, Tx ppdu fail count: %u, Connected duration: %u, Disconnected duration: %u, RTT ranging duration: %u, RTT responder duration: %u, Num tx probes: %u, Num beacon miss: %u,\n\nNumber of AC: %d",
			link_stats->beacon_rx, link_stats->mgmt_rx,
			link_stats->mgmt_action_rx, link_stats->mgmt_action_tx,
			link_stats->rssi_mgmt, link_stats->rssi_data,
			link_stats->rssi_ack, link_stats->is_leaky_ap,
			link_stats->avg_rx_frms_leaked,
			link_stats->rx_leak_window, average_tsf_offset,
			link_stats->tx_rts_succ_cnt,
			link_stats->tx_rts_fail_cnt,
			link_stats->tx_ppdu_succ_cnt,
			link_stats->tx_ppdu_fail_cnt,
			link_stats->connected_duration,
			link_stats->disconnected_duration,
			link_stats->rtt_ranging_duration,
			link_stats->rtt_responder_duration,
			link_stats->num_probes_tx, link_stats->num_beacon_miss,
			link_stats->num_ac);

	for (i = 0; i < link_stats->num_ac; i++) {
		ac_stats = &iface_stat->ac_stats[i];
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		buffer += len;
		ll_stats.len += len;
		len = scnprintf(buffer,
				DEBUGFS_LLSTATS_BUF_SIZE - ll_stats.len,
<<<<<<< HEAD
				"\nAC: %d, tx_mpdu: %u, rx_mpdu: %u, tx_mcast: %u, rx_mcast: %u, rx_ampdu: %u tx_ampdu: %u, mpdu_lost: %u, retries: %u, retries_short: %u, retries_long: %u, contention_time: min-%u max-%u avg-%u, contention num samples: %u",
				ac_stat->ac, ac_stat->txMpdu, ac_stat->rxMpdu,
				ac_stat->txMcast, ac_stat->rxMcast,
				ac_stat->rxAmpdu, ac_stat->txAmpdu,
				ac_stat->mpduLost, ac_stat->retries,
				ac_stat->retriesShort, ac_stat->retriesLong,
				ac_stat->contentionTimeMin,
				ac_stat->contentionTimeMax,
				ac_stat->contentionTimeAvg,
				ac_stat->contentionNumSamples);
=======
				"\nac_type: %d, tx_mpdu: %u, rx_mpdu: %u, tx_mcast: %u, rx_mcast: %u, rx_ampdu: %u tx_ampdu: %u, mpdu_lost: %u, retries: %u, retries_short: %u, retries_long: %u, contention_time: min-%u max-%u avg-%u, contention num samples: %u, tx_pending_msdu: %u",
				ac_stats->ac_type,
				ac_stats->tx_mpdu, ac_stats->rx_mpdu,
				ac_stats->tx_mcast, ac_stats->rx_mcast,
				ac_stats->rx_ampdu, ac_stats->rx_ampdu,
				ac_stats->mpdu_lost, ac_stats->retries,
				ac_stats->retries_short, ac_stats->retries_long,
				ac_stats->contention_time_min,
				ac_stats->contention_time_max,
				ac_stats->contention_time_avg,
				ac_stats->contention_num_samples,
				ac_stats->tx_pending_msdu);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	}

	buffer += len;
	ll_stats.len += len;
	len = scnprintf(buffer, DEBUGFS_LLSTATS_BUF_SIZE - ll_stats.len,
			"\n\nNumber of offload stats: %d",
			iface_stat->num_offload_stats);

	for (i = 0; i < iface_stat->num_offload_stats; i++) {
<<<<<<< HEAD
		offload_stat = &iface_stat->offload_stat[i];
=======
		offload_stats = &iface_stat->offload_stats[i];
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		buffer += len;
		ll_stats.len += len;
		len = scnprintf(buffer,
				DEBUGFS_LLSTATS_BUF_SIZE - ll_stats.len,
				"\ntype: %d, rx_count: %u, drp_count: %u, fwd_count: %u",
<<<<<<< HEAD
				offload_stat->type, offload_stat->rx_count,
				offload_stat->drp_count,
				offload_stat->fwd_count);
=======
				offload_stats->type, offload_stats->rx_count,
				offload_stats->drp_count,
				offload_stats->fwd_count);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	}

	ll_stats.len += len;
	mutex_unlock(&llstats_mutex);
<<<<<<< HEAD
	EXIT();
}

void hdd_debugfs_process_peer_stats(hdd_adapter_t *adapter, void *data)
{
	tpSirWifiPeerStat peer_stat;
	tpSirWifiPeerInfo peer_info;
	tpSirWifiRateStat rate_stat;
=======
	hdd_exit();
}

void hdd_debugfs_process_peer_stats(struct hdd_adapter *adapter, void *data)
{
	struct wifi_peer_stat *peer_stat;
	struct wifi_peer_info *peer_info;
	struct wifi_rate_stat *rate_stat;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	int i, j, num_rate;
	ssize_t len = 0;
	uint8_t *buffer;

<<<<<<< HEAD
	ENTER();
=======
	hdd_enter();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	mutex_lock(&llstats_mutex);
	if (!ll_stats.result) {
		mutex_unlock(&llstats_mutex);
		hdd_err("LL statistics buffer is NULL");
		return;
	}

<<<<<<< HEAD
	peer_stat = (tpSirWifiPeerStat) data;
=======
	peer_stat = data;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	buffer = ll_stats.result;
	buffer += ll_stats.len;
	len = scnprintf(buffer, DEBUGFS_LLSTATS_BUF_SIZE - ll_stats.len,
			"\n\n===LL_STATS_PEER_ALL : num_peers %u===",
<<<<<<< HEAD
			peer_stat->numPeers);

	peer_info = (tpSirWifiPeerInfo) ((uint8_t *) peer_stat->peerInfo);
	for (i = 1; i <= peer_stat->numPeers; i++) {
=======
			peer_stat->num_peers);

	peer_info = peer_stat->peer_info;
	for (i = 1; i <= peer_stat->num_peers; i++) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		buffer += len;
		ll_stats.len += len;
		len = scnprintf(buffer,
				DEBUGFS_LLSTATS_BUF_SIZE - ll_stats.len,
<<<<<<< HEAD
				"\nType: %d, peer_mac: %pM, capabilities: %u\nnum_rates: %d",
				wmi_to_sir_peer_type(peer_info->type),
				&peer_info->peerMacAddress.bytes[0],
				peer_info->capabilities, peer_info->numRate);

		num_rate = peer_info->numRate;
		for (j = 0; j < num_rate; j++) {
			rate_stat = (tpSirWifiRateStat) ((uint8_t *)
					peer_info->rateStats + (j *
					sizeof(tSirWifiRateStat)));
=======
				"\nType: %d, peer_mac: "QDF_FULL_MAC_FMT", capabilities: %u\nnum_rates: %d",
				wmi_to_sir_peer_type(peer_info->type),
				QDF_FULL_MAC_REF(peer_info->peer_macaddr.bytes),
				peer_info->capabilities, peer_info->num_rate);

		num_rate = peer_info->num_rate;
		for (j = 0; j < num_rate; j++) {
			rate_stat = &peer_info->rate_stats[j];
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			buffer += len;
			ll_stats.len += len;
			len = scnprintf(buffer,
				DEBUGFS_LLSTATS_BUF_SIZE - ll_stats.len,
				"\npreamble: %0x, nss: %0x, bw: %0x, mcs: %0x, bitrate: %0x, txmpdu: %u, rxmpdu: %u, mpdu_lost: %u, retries: %u, retries_short: %u, retries_long: %u",
				rate_stat->rate.preamble, rate_stat->rate.nss,
<<<<<<< HEAD
				rate_stat->rate.bw, rate_stat->rate.rateMcsIdx,
				rate_stat->rate.bitrate, rate_stat->txMpdu,
				rate_stat->rxMpdu, rate_stat->mpduLost,
				rate_stat->retries, rate_stat->retriesShort,
				rate_stat->retriesLong);
		}
		peer_info = (tpSirWifiPeerInfo) ((uint8_t *)
				peer_stat->peerInfo + (i *
				sizeof(tSirWifiPeerInfo)) +
				(num_rate * sizeof(tSirWifiRateStat)));
	}
	ll_stats.len += len;
	mutex_unlock(&llstats_mutex);
	EXIT();

}

void hdd_debugfs_process_radio_stats(hdd_adapter_t *adapter,
=======
				rate_stat->rate.bw,
				rate_stat->rate.rate_or_mcs_index,
				rate_stat->rate.bitrate, rate_stat->tx_mpdu,
				rate_stat->rx_mpdu, rate_stat->mpdu_lost,
				rate_stat->retries, rate_stat->retries_short,
				rate_stat->retries_long);
		}
		peer_info = (struct wifi_peer_info *) ((uint8_t *)
				peer_stat->peer_info + (i *
				sizeof(struct wifi_peer_info)) +
				(num_rate * sizeof(struct wifi_rate_stat)));
	}
	ll_stats.len += len;
	mutex_unlock(&llstats_mutex);
	hdd_exit();

}

void hdd_debugfs_process_radio_stats(struct hdd_adapter *adapter,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		uint32_t more_data, void *data, uint32_t num_radio)
{
	int i, j;
	ssize_t len = 0;
	uint8_t *buffer;
<<<<<<< HEAD
	tSirWifiRadioStat *radio_stat = (tpSirWifiRadioStat) data;
	tSirWifiChannelStats *chan_stat;

	ENTER();
=======
	struct wifi_radio_stats *radio_stat = (struct wifi_radio_stats *) data;
	struct wifi_channel_stats *chan_stat;

	hdd_enter();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	mutex_lock(&llstats_mutex);
	if (!ll_stats.result) {
		mutex_unlock(&llstats_mutex);
		hdd_err("LL statistics buffer is NULL");
		return;
	}

	buffer = ll_stats.result;
	buffer += ll_stats.len;
	len = scnprintf(buffer, DEBUGFS_LLSTATS_BUF_SIZE,
			 "\n\n===LL_STATS_RADIO: number of radios: %u===",
			  num_radio);

	for (i = 0; i < num_radio; i++) {
		buffer += len;
		ll_stats.len += len;
		len = scnprintf(buffer,
			DEBUGFS_LLSTATS_BUF_SIZE - ll_stats.len,
			"\nRadio: %u on_time: %u, tx_time: %u, rx_time: %u, on_time_scan: %u, on_time_nbd: %u, on_time_gscan: %u, on_time_roam_scan: %u, on_time_pno_scan: %u  on_time_hs20: %u, on_time_host_scan: %u, on_time_lpi_scan: %u\ntotal_num_tx_pwr_levels: %u\n",
<<<<<<< HEAD
			radio_stat->radio, radio_stat->onTime,
			radio_stat->txTime, radio_stat->rxTime,
			radio_stat->onTimeScan, radio_stat->onTimeNbd,
			radio_stat->onTimeGscan,
			radio_stat->onTimeRoamScan,
			radio_stat->onTimePnoScan,
			radio_stat->onTimeHs20,
=======
			radio_stat->radio, radio_stat->on_time,
			radio_stat->tx_time, radio_stat->rx_time,
			radio_stat->on_time_scan, radio_stat->on_time_nbd,
			radio_stat->on_time_gscan,
			radio_stat->on_time_roam_scan,
			radio_stat->on_time_pno_scan,
			radio_stat->on_time_hs20,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			radio_stat->on_time_host_scan,
			radio_stat->on_time_lpi_scan,
			radio_stat->total_num_tx_power_levels);

		for (j = 0; j < radio_stat->total_num_tx_power_levels; j++) {
			buffer += len;
			ll_stats.len += len;
			len = scnprintf(buffer,
				DEBUGFS_LLSTATS_BUF_SIZE - ll_stats.len,
				"%d ", radio_stat->tx_time_per_power_level[j]);
		}

		buffer += len;
		ll_stats.len += len;
		len = scnprintf(buffer,
			DEBUGFS_LLSTATS_BUF_SIZE - ll_stats.len,
<<<<<<< HEAD
			"\nNum channels: %d", radio_stat->numChannels);

		for (j = 0; j < radio_stat->numChannels; j++) {
			chan_stat = (tSirWifiChannelStats *)
					((uint8_t *)radio_stat->channels +
					  (j * sizeof(tSirWifiChannelStats)));
=======
			"\nNum channels: %d", radio_stat->num_channels);

		for (j = 0; j < radio_stat->num_channels; j++) {
			chan_stat = (struct wifi_channel_stats *)
					((uint8_t *)radio_stat->channels +
					  (j * sizeof(struct wifi_channel_stats)));
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

			buffer += len;
			ll_stats.len += len;
			len = scnprintf(buffer,
				DEBUGFS_LLSTATS_BUF_SIZE - ll_stats.len,
<<<<<<< HEAD
				"\nChan width: %d, center_freq: %d, center_freq0: %d, center_freq1: %d, on_time: %d, cca_busy_time: %d",
				chan_stat->channel.width,
				chan_stat->channel.centerFreq,
				chan_stat->channel.centerFreq0,
				chan_stat->channel.centerFreq1,
				chan_stat->onTime, chan_stat->ccaBusyTime);
=======
				"\nChan width: %u, center_freq: %u, center_freq0: %u, center_freq1: %u, on_time: %u, cca_busy_time: %u",
				chan_stat->channel.width,
				chan_stat->channel.center_freq,
				chan_stat->channel.center_freq0,
				chan_stat->channel.center_freq1,
				chan_stat->on_time, chan_stat->cca_busy_time);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		}

		radio_stat++;
	}
	ll_stats.len += len;
	mutex_unlock(&llstats_mutex);
<<<<<<< HEAD
	EXIT();
=======
	hdd_exit();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

static inline void wlan_hdd_llstats_free_buf(void)
{
	mutex_lock(&llstats_mutex);
	qdf_mem_free(ll_stats.result);
	ll_stats.result = NULL;
	ll_stats.len =  0;
	mutex_unlock(&llstats_mutex);
}

static int wlan_hdd_llstats_alloc_buf(void)
{
	mutex_lock(&llstats_mutex);
	if (ll_stats.result) {
		mutex_unlock(&llstats_mutex);
		hdd_err("Buffer is already allocated");
		return 0;
	}
	ll_stats.len = 0;
	ll_stats.result = qdf_mem_malloc(DEBUGFS_LLSTATS_BUF_SIZE);
	if (!ll_stats.result) {
		mutex_unlock(&llstats_mutex);
<<<<<<< HEAD
		hdd_err("LL Stats buffer allocation failed");
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return -EINVAL;
	}
	mutex_unlock(&llstats_mutex);
	return 0;
}

/**
 * hdd_debugfs_stats_update() - Update userspace with local statistics buffer
 * @buf: userspace buffer (to which data is being copied into)
 * @count: max data that can be copied into buf
 * @pos: offset (where data should be copied into)
 *
 * This function should copies link layer statistics buffer into debugfs
 * entry.
 *
 * Return: number of characters copied; 0 on no-copy
 */
static ssize_t hdd_debugfs_stats_update(char __user *buf, size_t count,
				     loff_t *pos)
{
	ssize_t ret_cnt;

<<<<<<< HEAD
	ENTER();
=======
	hdd_enter();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	mutex_lock(&llstats_mutex);
	if (!ll_stats.result) {
		mutex_unlock(&llstats_mutex);
		hdd_err("Trying to read from NULL buffer");
		return 0;
	}

	ret_cnt = simple_read_from_buffer(buf, count, pos,
			ll_stats.result, ll_stats.len);
	mutex_unlock(&llstats_mutex);
	hdd_debug("LL stats read req: count: %zu, pos: %lld", count, *pos);

<<<<<<< HEAD
	EXIT();
=======
	hdd_exit();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	return ret_cnt;
}

/**
 * __wlan_hdd_read_ll_stats_debugfs() - API to collect LL stats from FW
<<<<<<< HEAD
 * @file: file pointer
=======
 * @net_dev: net_device context used to register the debugfs file
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @buf: buffer
 * @count: count
 * @pos: position pointer
 *
 * Return: Number of bytes read on success, error number otherwise
 */
<<<<<<< HEAD
static ssize_t __wlan_hdd_read_ll_stats_debugfs(struct file *file,
			char __user *buf, size_t count, loff_t *pos)
{
	hdd_adapter_t *adapter;
	hdd_context_t *hdd_ctx;
	ssize_t ret = 0;

	ENTER();

	adapter = (hdd_adapter_t *)file->private_data;
	if ((!adapter) || (WLAN_HDD_ADAPTER_MAGIC != adapter->magic)) {
=======
static ssize_t __wlan_hdd_read_ll_stats_debugfs(struct net_device *net_dev,
						char __user *buf, size_t count,
						loff_t *pos)
{
	struct hdd_adapter *adapter = WLAN_HDD_GET_PRIV_PTR(net_dev);
	struct hdd_context *hdd_ctx;
	ssize_t ret;

	hdd_enter();

	if (adapter->magic != WLAN_HDD_ADAPTER_MAGIC) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		hdd_err("Invalid adapter or adapter has invalid magic");
		return -EINVAL;
	}

	hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	ret = wlan_hdd_validate_context(hdd_ctx);
<<<<<<< HEAD
	if (0 != ret)
=======
	if (ret)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return ret;

	/* All the events are received and buffer is populated */
	ret = hdd_debugfs_stats_update(buf, count, pos);
<<<<<<< HEAD
	hdd_info("%zu characters written into debugfs", ret);

	EXIT();
	return ret;

=======
	hdd_debug("%zu characters written into debugfs", ret);

	hdd_exit();

	return ret;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * wlan_hdd_read_ll_stats_debugfs() - SSR wrapper function to read LL debugfs
 * @file: file pointer
 * @buf: buffer
 * @count: count
 * @pos: position pointer
 *
 * Return: Number of bytes read on success, error number otherwise
 */
static ssize_t wlan_hdd_read_ll_stats_debugfs(struct file *file,
<<<<<<< HEAD
		char __user *buf,
		size_t count, loff_t *pos)
{
	int ret;

	cds_ssr_protect(__func__);
	ret = __wlan_hdd_read_ll_stats_debugfs(file, buf, count, pos);
	cds_ssr_unprotect(__func__);

	return ret;
=======
					      char __user *buf, size_t count,
					      loff_t *pos)
{
	struct net_device *net_dev = file_inode(file)->i_private;
	struct osif_vdev_sync *vdev_sync;
	ssize_t err_size;

	err_size = osif_vdev_sync_op_start(net_dev, &vdev_sync);
	if (err_size)
		return err_size;

	err_size = __wlan_hdd_read_ll_stats_debugfs(net_dev, buf, count, pos);

	osif_vdev_sync_op_stop(vdev_sync);

	return err_size;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * __wlan_hdd_open_ll_stats_debugfs() - Function to save private on open
<<<<<<< HEAD
 * @inode: Pointer to inode structure
 * @file: file pointer
 *
 * Return: zero
 */
static int __wlan_hdd_open_ll_stats_debugfs(struct inode *inode,
					    struct file *file)
{
	hdd_adapter_t *adapter;
	hdd_context_t *hdd_ctx;
	int errno;

	ENTER();

	if (inode->i_private)
		file->private_data = inode->i_private;

	adapter = (hdd_adapter_t *)file->private_data;
=======
 * @net_dev: net_device context used to register the debugfs file
 *
 * Return: Errno
 */
static int __wlan_hdd_open_ll_stats_debugfs(struct net_device *net_dev)
{
	struct hdd_adapter *adapter = WLAN_HDD_GET_PRIV_PTR(net_dev);
	struct hdd_context *hdd_ctx;
	int errno;

	hdd_enter();

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	errno = hdd_validate_adapter(adapter);
	if (errno)
		return errno;

	hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	errno = wlan_hdd_validate_context(hdd_ctx);
	if (errno)
		return errno;

	errno = wlan_hdd_llstats_alloc_buf();
	if (errno)
		return errno;

	errno = wlan_hdd_ll_stats_get(adapter, DEBUGFS_LLSTATS_REQID,
				      DEBUGFS_LLSTATS_REQMASK);
<<<<<<< HEAD
	if (errno) {
		wlan_hdd_llstats_free_buf();
		return errno;
	}

	EXIT();

	return 0;
}


/**
 * wlan_hdd_open_ll_stats_debugfs() - SSR wrapper function to save private
 *                                    on open
 * @inode: Pointer to inode structure
 * @file: file pointer
 *
 * Return: zero
=======
	if (errno)
		goto free_buf;

	hdd_exit();

	return 0;

free_buf:
	wlan_hdd_llstats_free_buf();

	hdd_exit();

	return errno;
}

/**
 * wlan_hdd_open_ll_stats_debugfs() - SSR wrapper function to save private
 *	on open
 * @inode: Pointer to inode structure
 * @file: file pointer
 *
 * Return: Errno
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 */
static int wlan_hdd_open_ll_stats_debugfs(struct inode *inode,
					  struct file *file)
{
<<<<<<< HEAD
	int ret;

	cds_ssr_protect(__func__);
	ret = __wlan_hdd_open_ll_stats_debugfs(inode, file);
	cds_ssr_unprotect(__func__);

	return ret;
=======
	struct net_device *net_dev = inode->i_private;
	struct osif_vdev_sync *vdev_sync;
	int errno;

	errno = osif_vdev_sync_op_start(net_dev, &vdev_sync);
	if (errno)
		return errno;

	errno = __wlan_hdd_open_ll_stats_debugfs(net_dev);

	osif_vdev_sync_op_stop(vdev_sync);

	return errno;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * __wlan_hdd_release_ll_stats_debugfs() - Function to save private on release
<<<<<<< HEAD
 * @inode: Pointer to inode structure
 * @file: file pointer
 *
 * Return: zero
 */
static int __wlan_hdd_release_ll_stats_debugfs(struct inode *inode,
					    struct file *file)
{
	hdd_adapter_t *adapter;
	hdd_context_t *hdd_ctx;
	int ret;

	ENTER();

	if (inode->i_private)
		file->private_data = inode->i_private;

	adapter = (hdd_adapter_t *)file->private_data;
	if ((NULL == adapter) || (WLAN_HDD_ADAPTER_MAGIC != adapter->magic)) {
=======
 * @net_dev: net_device context used to register the debugfs file
 *
 * Return: Errno
 */
static int __wlan_hdd_release_ll_stats_debugfs(struct net_device *net_dev)
{
	struct hdd_adapter *adapter = WLAN_HDD_GET_PRIV_PTR(net_dev);
	struct hdd_context *hdd_ctx;
	int ret;

	hdd_enter();

	if (adapter->magic != WLAN_HDD_ADAPTER_MAGIC) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		hdd_err("Invalid adapter or adapter has invalid magic");
		return -EINVAL;
	}

	hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	ret = wlan_hdd_validate_context(hdd_ctx);
<<<<<<< HEAD
	if (0 != ret)
=======
	if (ret)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return ret;

	wlan_hdd_llstats_free_buf();

<<<<<<< HEAD
	EXIT();
=======
	hdd_exit();

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	return 0;
}

/**
 * wlan_hdd_release_ll_stats_debugfs() - SSR wrapper function to save private
 *                                       on release
 * @inode: Pointer to inode structure
 * @file: file pointer
 *
<<<<<<< HEAD
 * Return: zero
 */
static int wlan_hdd_release_ll_stats_debugfs(struct inode *inode,
					  struct file *file)
{
	int ret;

	cds_ssr_protect(__func__);
	ret = __wlan_hdd_release_ll_stats_debugfs(inode, file);
	cds_ssr_unprotect(__func__);

	return ret;
=======
 * Return: Errno
 */
static int wlan_hdd_release_ll_stats_debugfs(struct inode *inode,
					     struct file *file)
{
	struct net_device *net_dev = file_inode(file)->i_private;
	struct osif_vdev_sync *vdev_sync;
	int errno;

	errno = osif_vdev_sync_op_start(net_dev, &vdev_sync);
	if (errno)
		return errno;

	errno = __wlan_hdd_release_ll_stats_debugfs(net_dev);

	osif_vdev_sync_op_stop(vdev_sync);

	return errno;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

static const struct file_operations fops_ll_stats_debugfs = {
	.read = wlan_hdd_read_ll_stats_debugfs,
	.open = wlan_hdd_open_ll_stats_debugfs,
	.release = wlan_hdd_release_ll_stats_debugfs,
	.owner = THIS_MODULE,
	.llseek = default_llseek,
};

<<<<<<< HEAD
int wlan_hdd_create_ll_stats_file(hdd_adapter_t *adapter)
{
	if (!debugfs_create_file("ll_stats", 0444, adapter->debugfs_phy,
				 adapter, &fops_ll_stats_debugfs))
=======
int wlan_hdd_create_ll_stats_file(struct hdd_adapter *adapter)
{
	if (!debugfs_create_file("ll_stats", 0444, adapter->debugfs_phy,
				 adapter->dev, &fops_ll_stats_debugfs))
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return -EINVAL;

	return 0;
}

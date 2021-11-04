/*
<<<<<<< HEAD
 * Copyright (c) 2016-2017 The Linux Foundation. All rights reserved.
=======
 * Copyright (c) 2016-2019 The Linux Foundation. All rights reserved.
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

#if !defined WLAN_HDD_TSF_H
#define WLAN_HDD_TSF_H
<<<<<<< HEAD

#include "wlan_hdd_cfg.h"
=======
#include "wlan_hdd_cfg.h"
#include "wlan_hdd_main.h"
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * enum hdd_tsf_get_state - status of get tsf action
 * @TSF_RETURN:                   get tsf
 * @TSF_STA_NOT_CONNECTED_NO_TSF: sta not connected to ap
 * @TSF_NOT_RETURNED_BY_FW:       fw not returned tsf
 * @TSF_CURRENT_IN_CAP_STATE:     driver in capture state
 * @TSF_CAPTURE_FAIL:             capture fail
 * @TSF_GET_FAIL:                 get fail
 * @TSF_RESET_GPIO_FAIL:          GPIO reset fail
 * @TSF_SAP_NOT_STARTED_NO_TSF    SAP not started
 * @TSF_NOT_READY: TSF module is not initialized or init failed
 * @TSF_DISABLED_BY_TSFPLUS: cap_tsf/get_tsf are disabled due to TSF_PLUS
 */
enum hdd_tsf_get_state {
	TSF_RETURN = 0,
	TSF_STA_NOT_CONNECTED_NO_TSF,
	TSF_NOT_RETURNED_BY_FW,
	TSF_CURRENT_IN_CAP_STATE,
	TSF_CAPTURE_FAIL,
	TSF_GET_FAIL,
	TSF_RESET_GPIO_FAIL,
	TSF_SAP_NOT_STARTED_NO_TSF,
	TSF_NOT_READY,
	TSF_DISABLED_BY_TSFPLUS
};

/**
 * enum hdd_tsf_capture_state - status of capture
 * @TSF_IDLE:      idle
 * @TSF_CAP_STATE: current is in capture state
 */
enum hdd_tsf_capture_state {
	TSF_IDLE = 0,
	TSF_CAP_STATE
};

#ifdef WLAN_FEATURE_TSF
/**
 * wlan_hdd_tsf_init() - set gpio and callbacks for
 *     capturing tsf and init tsf_plus
<<<<<<< HEAD
 * @hdd_ctx: pointer to the hdd_context_t
=======
 * @hdd_ctx: pointer to the struct hdd_context
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *
 * This function set the callback to sme module, the callback will be
 * called when a tsf event is reported by firmware; set gpio number
 * to FW, FW will toggle this gpio when received a CAP_TSF command;
 * do tsf_plus init
 *
 * Return: nothing
 */
<<<<<<< HEAD
void wlan_hdd_tsf_init(struct hdd_context_s *hdd_ctx);

/**
 * wlan_hdd_tsf_deinit() - reset callbacks for capturing tsf, deinit tsf_plus
 * @hdd_ctx: pointer to the hdd_context_t
=======
void wlan_hdd_tsf_init(struct hdd_context *hdd_ctx);

/**
 * wlan_hdd_tsf_deinit() - reset callbacks for capturing tsf, deinit tsf_plus
 * @hdd_ctx: pointer to the struct hdd_context
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *
 * This function reset the callback to sme module, and deinit tsf_plus
 *
 * Return: nothing
 */
<<<<<<< HEAD
void wlan_hdd_tsf_deinit(hdd_context_t *hdd_ctx);
=======
void wlan_hdd_tsf_deinit(struct hdd_context *hdd_ctx);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * hdd_capture_tsf() - capture tsf
 * @adapter: pointer to adapter
 * @buf: pointer to uplayer buf
 * @len : the length of buf
 *
 * This function returns tsf value to uplayer.
 *
 * Return: 0 for success or non-zero negative failure code
 */
<<<<<<< HEAD
int hdd_capture_tsf(struct hdd_adapter_s *adapter, uint32_t *buf, int len);
=======
int hdd_capture_tsf(struct hdd_adapter *adapter, uint32_t *buf, int len);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * hdd_indicate_tsf() - return tsf to uplayer
 *
 * @adapter: pointer to adapter
 * @buf: pointer to uplayer buf
 * @len : the length of buf
 *
 * This function returns tsf value to uplayer.
 *
 * Return: Describe the execute result of this routine
 */
<<<<<<< HEAD
int hdd_indicate_tsf(struct hdd_adapter_s *adapter, uint32_t *buf, int len);
=======
int hdd_indicate_tsf(struct hdd_adapter *adapter, uint32_t *buf, int len);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * wlan_hdd_cfg80211_handle_tsf_cmd(): Setup TSF operations
 * @wiphy: Pointer to wireless phy
 * @wdev: Pointer to wireless device
 * @data: Pointer to data
 * @data_len: Data length
 *
 * Handle TSF SET / GET operation from userspace
 *
 * Return: 0 on success, negative errno on failure
 */
int wlan_hdd_cfg80211_handle_tsf_cmd(struct wiphy *wiphy,
					struct wireless_dev *wdev,
					const void *data,
					int data_len);

int hdd_get_tsf_cb(void *pcb_cxt, struct stsf *ptsf);
<<<<<<< HEAD
#else
static inline void wlan_hdd_tsf_init(struct hdd_context_s *hdd_ctx)
{
}

static inline void wlan_hdd_tsf_deinit(hdd_context_t *hdd_ctx)
{
}

static inline int hdd_indicate_tsf(struct hdd_adapter_s *adapter, uint32_t *buf,
=======

#else
static inline void wlan_hdd_tsf_init(struct hdd_context *hdd_ctx)
{
}

static inline void wlan_hdd_tsf_deinit(struct hdd_context *hdd_ctx)
{
}

static inline int hdd_indicate_tsf(struct hdd_adapter *adapter, uint32_t *buf,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				int len)
{
	return -ENOTSUPP;
}

static inline int
<<<<<<< HEAD
hdd_capture_tsf(struct hdd_adapter_s *adapter, uint32_t *buf, int len)
=======
hdd_capture_tsf(struct hdd_adapter *adapter, uint32_t *buf, int len)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	return -ENOTSUPP;
}

static inline int wlan_hdd_cfg80211_handle_tsf_cmd(struct wiphy *wiphy,
					struct wireless_dev *wdev,
					const void *data,
					int data_len)
{
	return -ENOTSUPP;
}
static inline int hdd_get_tsf_cb(void *pcb_cxt, struct stsf *ptsf)
{
	return -ENOTSUPP;
}

#endif

#if defined(WLAN_FEATURE_TSF_PLUS) && defined(WLAN_FEATURE_TSF)
<<<<<<< HEAD
#define HDD_TSF_IS_PTP_ENABLED(hdd) \
({ \
	hdd_context_t *hdd_ctx = (hdd); \
	hdd_ctx && hdd_ctx->config && hdd_ctx->config->tsf_ptp_options; \
})

#define HDD_TSF_IS_TX_SET(hdd) \
({ \
	hdd_context_t *hdd_ctx = (hdd); \
	hdd_ctx && hdd_ctx->config && \
	(hdd_ctx->config->tsf_ptp_options & CFG_SET_TSF_PTP_OPT_TX); \
})

#define HDD_TSF_IS_RX_SET(hdd) \
({ \
	hdd_context_t *hdd_ctx = (hdd); \
	hdd_ctx && hdd_ctx->config && \
	(hdd_ctx->config->tsf_ptp_options & CFG_SET_TSF_PTP_OPT_RX); \
})

#define HDD_TSF_IS_RAW_SET(hdd) \
({ \
	hdd_context_t *hdd_ctx = (hdd); \
	hdd_ctx && hdd_ctx->config && \
	(hdd_ctx->config->tsf_ptp_options & CFG_SET_TSF_PTP_OPT_RAW); \
})

#define HDD_TSF_IS_DBG_FS_SET(hdd) \
({ \
	hdd_context_t *hdd_ctx = (hdd); \
	hdd_ctx && hdd_ctx->config && \
	(hdd_ctx->config->tsf_ptp_options & CFG_SET_TSF_DBG_FS); \
})
=======
/**
 * hdd_tsf_is_tx_set() - check ini configuration
 * @hdd: pointer to hdd context
 *
 * This function checks tsf configuration for ptp on tx
 *
 * Return: true on enable, false on disable
 */

bool hdd_tsf_is_tx_set(struct hdd_context *hdd);
/**
 * hdd_tsf_is_rx_set() - check ini configuration
 * @hdd: pointer to hdd context
 *
 * This function checks tsf configuration for ptp on rx
 *
 * Return: true on enable, false on disable
 */
bool hdd_tsf_is_rx_set(struct hdd_context *hdd);
/**
 * hdd_tsf_is_raw_set() - check ini configuration
 * @hdd: pointer to hdd context
 *
 * This function checks tsf configuration for ptp on raw
 *
 * Return: true on enable, false on disable
 */
bool hdd_tsf_is_raw_set(struct hdd_context *hdd);
/**
 * hdd_tsf_is_dbg_fs_set() - check ini configuration
 * @hdd: pointer to hdd context
 *
 * This function checks tsf configuration for ptp on dbg fs
 *
 * Return: true on enable, false on disable
 */
bool hdd_tsf_is_dbg_fs_set(struct hdd_context *hdd);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * hdd_start_tsf_sync() - start tsf sync
 * @adapter: pointer to adapter
 *
 * This function initialize and start TSF synchronization
 *
 * Return: Describe the execute result of this routine
 */
<<<<<<< HEAD
int hdd_start_tsf_sync(hdd_adapter_t *adapter);
=======
int hdd_start_tsf_sync(struct hdd_adapter *adapter);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * hdd_stop_tsf_sync() - stop tsf sync
 * @adapter: pointer to adapter
 *
 * This function stop and de-initialize TSF synchronization
 *
 * Return: Describe the execute result of this routine
 */
<<<<<<< HEAD
int hdd_stop_tsf_sync(hdd_adapter_t *adapter);
=======
int hdd_stop_tsf_sync(struct hdd_adapter *adapter);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * hdd_tsf_notify_wlan_state_change() -
 *     notify tsf module of wlan connection state
 * @old_state: old wlan state
 * @new_state: new wlan state
 *
 * This function check the old and new connection state, determine whether
 * to start or stop tsf sync
 *
 * Return: nothing
 */
<<<<<<< HEAD
void hdd_tsf_notify_wlan_state_change(hdd_adapter_t *adapter,
=======
void hdd_tsf_notify_wlan_state_change(struct hdd_adapter *adapter,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				      eConnectionState old_state,
				      eConnectionState new_state);

/**
 * hdd_tx_timestamp() - time stamp TX netbuf
 *
 * @netbuf: pointer to a TX netbuf
 * @target_time: TX time for the netbuf
 *
 * This function  get corresponding host time from target time,
 * and time stamp the TX netbuf with this time
 *
 * Return: Describe the execute result of this routine
 */
int hdd_tx_timestamp(qdf_nbuf_t netbuf, uint64_t target_time);

/**
 * hdd_rx_timestamp() - time stamp RX netbuf
 *
 * @netbuf: pointer to a RX netbuf
 * @target_time: RX time for the netbuf
 *
 * This function get corresponding host time from target time,
 * and time stamp the RX netbuf with this time
 *
 * Return: Describe the execute result of this routine
 */
int hdd_rx_timestamp(qdf_nbuf_t netbuf, uint64_t target_time);
<<<<<<< HEAD
#else
static inline int hdd_start_tsf_sync(hdd_adapter_t *adapter)
=======
/**
 * hdd_capture_req_timer_expired_handler() - capture req timer handler
 * @arg: pointer to a adapter
 *
 * This function set a timeout handler for TSF capture timer.
 *
 * Return: none
 */

void hdd_capture_req_timer_expired_handler(void *arg);

/**
 * hdd_tsf_is_tsf64_tx_set() - check ini configuration
 * @hdd: pointer to hdd context
 *
 * This function checks tsf configuration for ptp on tsf64 tx
 *
 * Return: true on enable, false on disable
 */
bool hdd_tsf_is_tsf64_tx_set(struct hdd_context *hdd);
#else
static inline int hdd_start_tsf_sync(struct hdd_adapter *adapter)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	return -ENOTSUPP;
}

<<<<<<< HEAD
static inline int hdd_stop_tsf_sync(hdd_adapter_t *adapter)
=======
static inline int hdd_stop_tsf_sync(struct hdd_adapter *adapter)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	return -ENOTSUPP;
}

static inline
<<<<<<< HEAD
void hdd_tsf_notify_wlan_state_change(hdd_adapter_t *adapter,
=======
void hdd_tsf_notify_wlan_state_change(struct hdd_adapter *adapter,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				      eConnectionState old_state,
				      eConnectionState new_state)

{
}

static inline
int hdd_tx_timestamp(qdf_nbuf_t netbuf, uint64_t target_time)
{
	return -ENOTSUPP;
}

static inline
int hdd_rx_timestamp(qdf_nbuf_t netbuf, uint64_t target_time)
{
	return -ENOTSUPP;
}
<<<<<<< HEAD
#endif

=======

static inline
void hdd_capture_req_timer_expired_handler(void *arg)
{
}

static inline
bool hdd_tsf_is_tsf64_tx_set(struct hdd_context *hdd)
{
	return FALSE;
}
#endif

#ifdef WLAN_FEATURE_TSF_PTP
/**
 * wlan_get_ts_info() - return ts info to uplayer
 * @dev: pointer to net_device
 * @info: pointer to ethtool_ts_info
 *
 * Return: Describe the execute result of this routine
 */
int wlan_get_ts_info(struct net_device *dev, struct ethtool_ts_info *info);

#endif
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#endif

/*
<<<<<<< HEAD
 * Copyright (c) 2018 The Linux Foundation. All rights reserved.
=======
 * Copyright (c) 2018-2019 The Linux Foundation. All rights reserved.
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
 * DOC: wlan_hdd_debugfs_csr.h
 *
 * WLAN Host Device Driver implementation to update
 * debugfs with connect, scan and roam information
 */

#ifndef _WLAN_HDD_DEBUGFS_CSR_H
#define _WLAN_HDD_DEBUGFS_CSR_H

#include <wlan_hdd_includes.h>

<<<<<<< HEAD
=======
#ifdef WLAN_DEBUGFS

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#define DEBUGFS_CONNECT_INFO_BUF_SIZE    (4 * 1024)
#define DEBUGFS_OFFLOAD_INFO_BUF_SIZE    (4 * 1024)
#define DEBUGFS_ROAM_SCAN_STATS_INFO_BUF_SIZE (4 * 1024)

/**
 * struct wlan_hdd_debugfs_buffer_info - Debugfs buffer info
 * @length: current length of the debugfs buffer
 * @max_buf_len: maximum buffer length of the debugfs buffer
 * @id: id from enum hdd_debugfs_file_id used to identify file
 * @data: start of debugfs buffer from which file read starts
 * @adapter: pointer to adapter
 *
 * This structure is used to hold the debugfs buffer details and is stored in
 * private data of file argument in file open operation.
 */
struct wlan_hdd_debugfs_buffer_info {
	ssize_t length;
	ssize_t max_buf_len;
	enum hdd_debugfs_file_id id;
	uint8_t *data;
<<<<<<< HEAD
	hdd_adapter_t *adapter;
=======
	struct hdd_adapter *adapter;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
};

/**
 * struct hdd_roam_scan_stats_debugfs_priv - private data for request mgr
 * @res: pointer to roam scan stats response
 */
struct hdd_roam_scan_stats_debugfs_priv {
	struct wmi_roam_scan_stats_res *roam_scan_stats_res;
};

<<<<<<< HEAD
#ifdef WLAN_DEBUGFS
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/**
 * wlan_hdd_debugfs_csr_init() - Create wifi diagnostic debugfs files
 * @adapter: pointer to adapter for which debugfs files are to be created
 *
 * Return: None
 */
<<<<<<< HEAD
void wlan_hdd_debugfs_csr_init(hdd_adapter_t *adapter);
=======
void wlan_hdd_debugfs_csr_init(struct hdd_adapter *adapter);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * wlan_hdd_debugfs_csr_deinit() - Remove wifi diagnostic debugfs files
 * @adapter: pointer to adapter for which debugfs files are to be removed
 *
 * Return: None
 */
<<<<<<< HEAD
void wlan_hdd_debugfs_csr_deinit(hdd_adapter_t *adapter);
=======
void wlan_hdd_debugfs_csr_deinit(struct hdd_adapter *adapter);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * wlan_hdd_current_time_info_debugfs() - API to get time into user buffer
 * @buf: output buffer to hold current time when queried
 * @buf_avail_len: available buffer length
 *
 * Return: No.of bytes copied
 */
ssize_t
wlan_hdd_current_time_info_debugfs(uint8_t *buf, ssize_t buf_avail_len);

/**
 * wlan_hdd_debugfs_update_connect_info() - API to get connect info
 * into user buffer
 * @buf: output buffer to hold connect info
 * @buf_avail_len: available buffer length
 *
 * Return: No.of bytes copied
 */
ssize_t
<<<<<<< HEAD
wlan_hdd_debugfs_update_connect_info(hdd_context_t *hdd_ctx,
				     hdd_adapter_t *adapter,
=======
wlan_hdd_debugfs_update_connect_info(struct hdd_context *hdd_ctx,
				     struct hdd_adapter *adapter,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				     uint8_t *buf, ssize_t buf_avail_len);

/**
 * wlan_hdd_debugfs_update_filters_info() - API to get offload info
 * into user buffer
 * @buf: output buffer to hold offload info
 * @buf_avail_len: available buffer length
 *
 * Return: No.of bytes copied
 */
ssize_t
<<<<<<< HEAD
wlan_hdd_debugfs_update_filters_info(hdd_context_t *hdd_ctx,
				     hdd_adapter_t *adapter,
=======
wlan_hdd_debugfs_update_filters_info(struct hdd_context *hdd_ctx,
				     struct hdd_adapter *adapter,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				     uint8_t *buf, ssize_t buf_avail_len);

/**
 * wlan_hdd_debugfs_update_roam_stats() - API to get roam scan stats info
 * into user buffer
 * @buf: output buffer to hold roam scan stats info
 * @buf_avail_len: available buffer length
 *
 * Return: No.of bytes copied
 */
ssize_t
<<<<<<< HEAD
wlan_hdd_debugfs_update_roam_stats(hdd_context_t *hdd_ctx,
				   hdd_adapter_t *adapter,
=======
wlan_hdd_debugfs_update_roam_stats(struct hdd_context *hdd_ctx,
				   struct hdd_adapter *adapter,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				   uint8_t *buf, ssize_t buf_avail_len);

#else
/**
 * wlan_hdd_debugfs_csr_init() - Create wifi diagnostic debugfs files
 * @adapter: pointer to adapter for which debugfs files are to be created
 *
 * Return: None
 */
<<<<<<< HEAD
static inline void wlan_hdd_debugfs_csr_init(hdd_adapter_t *adapter)
=======
static inline void wlan_hdd_debugfs_csr_init(struct hdd_adapter *adapter)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
}

/**
 * wlan_hdd_debugfs_csr_deinit() - Remove wifi diagnostic debugfs files
 * @adapter: pointer to adapter for which debugfs files are to be removed
 *
 * Return: None
 */
<<<<<<< HEAD
static inline void wlan_hdd_debugfs_csr_deinit(hdd_adapter_t *adapter)
=======
static inline void wlan_hdd_debugfs_csr_deinit(struct hdd_adapter *adapter)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
}

/**
 * wlan_hdd_current_time_info_debugfs() - API to get time into user buffer
 * @buf: output buffer to hold current time when queried
 * @buf_avail_len: available buffer length
 *
 * Return: No.of bytes copied
 */
static inline ssize_t
wlan_hdd_current_time_info_debugfs(uint8_t *buf, ssize_t buf_avail_len)
{
	return 0;
}

/**
 * wlan_hdd_debugfs_update_connect_info() - API to get connect info
 * into user buffer
 * @buf: output buffer to hold connect info
 * @buf_avail_len: available buffer length
 *
 * Return: No.of bytes copied
 */
static inline ssize_t
<<<<<<< HEAD
wlan_hdd_debugfs_update_connect_info(hdd_context_t *hdd_ctx,
				     hdd_adapter_t *adapter,
=======
wlan_hdd_debugfs_update_connect_info(struct hdd_context *hdd_ctx,
				     struct hdd_adapter *adapter,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				     uint8_t *buf, ssize_t buf_avail_len)
{
	return 0;
}

/**
 * wlan_hdd_debugfs_update_filters_info() - API to get offload info
 * into user buffer
 * @buf: output buffer to hold offload info
 * @buf_avail_len: available buffer length
 *
 * Return: No.of bytes copied
 */
static inline ssize_t
<<<<<<< HEAD
wlan_hdd_debugfs_update_filters_info(hdd_context_t *hdd_ctx,
				     hdd_adapter_t *adapter,
=======
wlan_hdd_debugfs_update_filters_info(struct hdd_context *hdd_ctx,
				     struct hdd_adapter *adapter,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				     uint8_t *buf, ssize_t buf_avail_len)
{
	return 0;
}

/**
 * wlan_hdd_debugfs_update_roam_stats() - API to get roam scan stats info
 * into user buffer
 * @buf: output buffer to hold roam scan stats info
 * @buf_avail_len: available buffer length
 *
 * Return: No.of bytes copied
 */
static inline ssize_t
<<<<<<< HEAD
wlan_hdd_debugfs_update_roam_stats(hdd_context_t *hdd_ctx,
				   hdd_adapter_t *adapter,
=======
wlan_hdd_debugfs_update_roam_stats(struct hdd_context *hdd_ctx,
				   struct hdd_adapter *adapter,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				   uint8_t *buf, ssize_t buf_avail_len)
{
	return 0;
}

#endif

#endif /* _WLAN_HDD_DEBUGFS_CSR_H */

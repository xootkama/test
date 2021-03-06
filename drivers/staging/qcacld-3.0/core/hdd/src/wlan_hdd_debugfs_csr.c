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
 * DOC: wlan_hdd_debugfs_csr.c
 *
 * WLAN Host Device Driver implementation to update
 * debugfs with roaming related information
 */

<<<<<<< HEAD
=======
#include "osif_sync.h"
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#include <wlan_hdd_debugfs_csr.h>
#include <wlan_hdd_main.h>
#include <cds_sched.h>
#include <wma_api.h>
#include "qwlan_version.h"
#include "wmi_unified_param.h"
<<<<<<< HEAD
#include "wlan_hdd_request_manager.h"
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#include "wlan_hdd_debugfs.h"

ssize_t
wlan_hdd_current_time_info_debugfs(uint8_t *buf, ssize_t buf_avail_len)
{
	ssize_t length;
	char time_buffer[HDD_TIME_STRING_LEN];
	int ret_val;

	qdf_get_time_of_the_day_in_hr_min_sec_usec(time_buffer,
						   sizeof(time_buffer));
	ret_val = scnprintf(buf, buf_avail_len,
			    "\nTime at which this file generated = %s\n",
			    time_buffer);
	if (ret_val < 0)
		return 0;
	length = ret_val;

	return length;
}

/**
<<<<<<< HEAD
 * wlan_hdd_debugfs_update_csr() - Function to upadte internal debugfs buffer
 * and write into user-space buffer
 * @hd_ctx: hdd context
=======
 * wlan_hdd_debugfs_update_csr() - Function to update internal debugfs buffer
 * and write into user-space buffer
 * @hdd_ctx: hdd context
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @adapter: adapter
 * @id: used to identify file for which this info has to be read
 * @buf: output buffer to write
 * @buf_avail_len: length of the available buffer
 *
 * Return: Number of bytes read on success, zero otherwise
 */
static ssize_t
<<<<<<< HEAD
wlan_hdd_debugfs_update_csr(hdd_context_t *hdd_ctx, hdd_adapter_t *adapter,
			    enum hdd_debugfs_file_id id, uint8_t *buf,
=======
wlan_hdd_debugfs_update_csr(struct hdd_context *hdd_ctx,
			    struct hdd_adapter *adapter,
			    enum hdd_debugfs_file_id id,
			    uint8_t *buf,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			    ssize_t buf_avail_len)
{
	ssize_t len = 0;

	switch (id) {
	case HDD_DEBUFS_FILE_ID_CONNECT_INFO:
		/* populate connect info */
		len = wlan_hdd_debugfs_update_connect_info(hdd_ctx, adapter,
							   buf, buf_avail_len);
		break;
	case HDD_DEBUFS_FILE_ID_ROAM_SCAN_STATS_INFO:
		/* populate roam scan stats info */
		len = wlan_hdd_debugfs_update_roam_stats(hdd_ctx, adapter,
							 buf, buf_avail_len);
		break;
	case HDD_DEBUFS_FILE_ID_OFFLOAD_INFO:
		/* populate offload info */
		len = wlan_hdd_debugfs_update_filters_info(hdd_ctx, adapter,
							   buf, buf_avail_len);
		break;
	default:
		hdd_err("Failed to fetch stats, unknown stats type");
	}

	return len;
}

/**
 * __wlan_hdd_read_debugfs_csr() - Function to read debug stats
<<<<<<< HEAD
 * @file: file pointer
=======
 * @info: buffer info allocated when the debugfs file was opened
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @buf: buffer
 * @count: count
 * @pos: position pointer
 *
 * Return: Number of bytes read on success, zero otherwise
 */
static ssize_t
<<<<<<< HEAD
__wlan_hdd_read_debugfs_csr(struct file *file, char __user *buf,
			    size_t count, loff_t *pos)
{
	struct wlan_hdd_debugfs_buffer_info *info;
	hdd_adapter_t *adapter;
	hdd_context_t *hdd_ctx;
	int ret;
	ssize_t length;

	ENTER();

	info = file->private_data;
	if (!info || !info->data) {
		hdd_err("No valid private data");
		return 0;
	}

	adapter = info->adapter;
	if ((!adapter) || (adapter->magic != WLAN_HDD_ADAPTER_MAGIC)) {
=======
__wlan_hdd_read_debugfs_csr(struct wlan_hdd_debugfs_buffer_info *info,
			    char __user *buf, size_t count, loff_t *pos)
{
	struct hdd_adapter *adapter = info->adapter;
	struct hdd_context *hdd_ctx;
	int ret;
	ssize_t length;

	hdd_enter();

	if (adapter->magic != WLAN_HDD_ADAPTER_MAGIC) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		hdd_err("Invalid adapter or adapter has invalid magic");
		return 0;
	}

	hdd_ctx = WLAN_HDD_GET_CTX(adapter);
	ret = wlan_hdd_validate_context(hdd_ctx);
	if (ret)
		return 0;

	if (!test_bit(DEVICE_IFACE_OPENED, &adapter->event_flags)) {
		hdd_err("Interface is not enabled");
		return 0;
	}

	if (*pos == 0) {
<<<<<<< HEAD
		info->length =
			wlan_hdd_debugfs_update_csr(hdd_ctx, adapter,
						      info->id, info->data,
						      info->max_buf_len);
=======
		info->length = wlan_hdd_debugfs_update_csr(hdd_ctx, adapter,
							   info->id,
							   info->data,
							   info->max_buf_len);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	}

	length = simple_read_from_buffer(buf, count, pos,
					 info->data, info->length);
	hdd_debug("length written = %zu, count: %zu, pos: %lld",
		  length, count, *pos);

<<<<<<< HEAD
	EXIT();
=======
	hdd_exit();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	return length;
}

/**
 * wlan_hdd_read_debugfs_csr() - SSR wrapper function to read stats
 * @file: file pointer
 * @buf: buffer
 * @count: count
 * @pos: position pointer
 *
 * Return: Number of bytes read on success, zero otherwise
 */
static ssize_t
wlan_hdd_read_debugfs_csr(struct file *file, char __user *buf,
			  size_t count, loff_t *pos)
{
<<<<<<< HEAD
	int ret;

	cds_ssr_protect(__func__);
	ret = __wlan_hdd_read_debugfs_csr(file, buf, count, pos);
	cds_ssr_unprotect(__func__);

	return ret;
=======
	struct wlan_hdd_debugfs_buffer_info *info = file->private_data;
	struct osif_vdev_sync *vdev_sync;
	ssize_t err_size;

	err_size = osif_vdev_sync_op_start(info->adapter->dev, &vdev_sync);
	if (err_size)
		return err_size;

	err_size = __wlan_hdd_read_debugfs_csr(info, buf, count, pos);

	osif_vdev_sync_op_stop(vdev_sync);

	return err_size;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * __wlan_hdd_open_debugfs_csr() - Allocates memory for private data
<<<<<<< HEAD
 * @inode: Pointer to inode structure
 * @file: file pointer
 *
 * Return: zero
 */
static int __wlan_hdd_open_debugfs_csr(struct inode *inode,
				       struct file *file)
{
	struct wlan_hdd_debugfs_buffer_info *info;
	struct hdd_debugfs_file_info *csr;
	hdd_adapter_t *adapter = NULL;
	hdd_context_t *hdd_ctx;
	int ret;

	ENTER();

	csr = inode->i_private;
	if (!csr) {
		hdd_err("No private data");
		return -EINVAL;
	}

	adapter = qdf_container_of(csr, hdd_adapter_t,
				   csr_file[csr->id]);
	if ((adapter == NULL) || (adapter->magic != WLAN_HDD_ADAPTER_MAGIC)) {
=======
 * @adapter: the HDD adapter to operate against
 * @csr: file info used to register the debugfs file
 * @file: file pointer
 *
 * Return: Errno
 */
static int __wlan_hdd_open_debugfs_csr(struct hdd_adapter *adapter,
				       struct hdd_debugfs_file_info *csr,
				       struct file *file)
{
	struct wlan_hdd_debugfs_buffer_info *info;
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
	if (ret)
		return -EINVAL;

	if (!test_bit(DEVICE_IFACE_OPENED, &adapter->event_flags)) {
		hdd_err("Interface is not enabled");
		return -EINVAL;
	}

	info = qdf_mem_malloc(sizeof(*info));
	if (!info) {
		hdd_err("Not enough memory for file private data");
		return -ENOMEM;
	}

	info->data = qdf_mem_malloc(csr->buf_max_size);
	if (!info->data) {
		hdd_err("roam stats debugfs buffer allocation failed");
		qdf_mem_free(info);
		return -ENOMEM;
	}
	info->length = 0;
	info->max_buf_len = csr->buf_max_size;
	info->id = csr->id;
	info->adapter = adapter;

	file->private_data = info;
<<<<<<< HEAD
	EXIT();
=======
	hdd_exit();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	return 0;
}

/**
 * wlan_hdd_open_debugfs_csr() - SSR wrapper function to allocate memory for
<<<<<<< HEAD
 * private data on file open
 * @inode: Pointer to inode structure
 * @file: file pointer
 *
 * Return: zero
 */
static int wlan_hdd_open_debugfs_csr(struct inode *inode,
				     struct file *file)
{
	int ret;

	cds_ssr_protect(__func__);

	hdd_debugfs_thread_increment();
	ret = __wlan_hdd_open_debugfs_csr(inode, file);
	if (ret)
		hdd_debugfs_thread_decrement();

	cds_ssr_unprotect(__func__);

	return ret;
=======
 *	private data on file open
 * @inode: Pointer to inode structure
 * @file: file pointer
 *
 * Return: Errno
 */
static int wlan_hdd_open_debugfs_csr(struct inode *inode, struct file *file)
{
	struct hdd_debugfs_file_info *csr = inode->i_private;
	struct hdd_adapter *adapter = qdf_container_of(csr, struct hdd_adapter,
						       csr_file[csr->id]);
	struct osif_vdev_sync *vdev_sync;
	int errno;

	errno = osif_vdev_sync_op_start(adapter->dev, &vdev_sync);
	if (errno)
		return errno;

	hdd_debugfs_thread_increment();
	errno = __wlan_hdd_open_debugfs_csr(adapter, csr, file);
	if (errno)
		hdd_debugfs_thread_decrement();

	osif_vdev_sync_op_stop(vdev_sync);

	return errno;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * __wlan_hdd_release_debugfs_csr() - Function to free private memory on
<<<<<<< HEAD
 * release
 * @inode: Pointer to inode structure
 * @file: file pointer
 *
 * Return: zero
 */
static int __wlan_hdd_release_debugfs_csr(struct inode *inode,
					  struct file *file)
{
	struct wlan_hdd_debugfs_buffer_info *info = file->private_data;

	ENTER();

	if (!info)
		return 0;
=======
 *	release
 * @file: file pointer
 *
 * Return: Errno
 */
static int
__wlan_hdd_release_debugfs_csr(struct file *file)
{
	struct wlan_hdd_debugfs_buffer_info *info = file->private_data;

	hdd_enter();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	file->private_data = NULL;
	qdf_mem_free(info->data);
	qdf_mem_free(info);

<<<<<<< HEAD
	EXIT();
=======
	hdd_exit();
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	return 0;
}

/**
 * wlan_hdd_release_debugfs_csr() - SSR wrapper function to free
 * private data on release
 * @inode: Pointer to inode structure
 * @file: file pointer
 *
<<<<<<< HEAD
 * Return: zero
 */
static int wlan_hdd_release_debugfs_csr(struct inode *inode, struct file *file)
{
	int ret;

	cds_ssr_protect(__func__);
	ret = __wlan_hdd_release_debugfs_csr(inode, file);
	hdd_debugfs_thread_decrement();
	cds_ssr_unprotect(__func__);

	return ret;
=======
 * Return: Errno
 */
static int wlan_hdd_release_debugfs_csr(struct inode *inode, struct file *file)
{
	struct wlan_hdd_debugfs_buffer_info *info = file->private_data;
	struct osif_vdev_sync *vdev_sync;
	int errno;

	errno = osif_vdev_sync_op_start(info->adapter->dev, &vdev_sync);
	if (errno)
		return errno;

	errno = __wlan_hdd_release_debugfs_csr(file);
	hdd_debugfs_thread_decrement();

	osif_vdev_sync_op_stop(vdev_sync);

	return errno;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

static const struct file_operations fops_csr_debugfs = {
	.read = wlan_hdd_read_debugfs_csr,
	.open = wlan_hdd_open_debugfs_csr,
	.release = wlan_hdd_release_debugfs_csr,
	.owner = THIS_MODULE,
	.llseek = default_llseek,
};

<<<<<<< HEAD
void wlan_hdd_debugfs_csr_init(hdd_adapter_t *adapter)
=======
void wlan_hdd_debugfs_csr_init(struct hdd_adapter *adapter)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	struct hdd_debugfs_file_info *csr;
	const uint32_t max_len = HDD_DEBUGFS_FILE_NAME_MAX;

	/*
	 * Create debufs diagnostic files for connect, offload info
	 * and roam info and store in csr_file member of adapter
	 */

	csr = &adapter->csr_file[HDD_DEBUFS_FILE_ID_CONNECT_INFO];
	if (!csr->entry) {
		strlcpy(csr->name, "connect_info", max_len);
		csr->id = HDD_DEBUFS_FILE_ID_CONNECT_INFO;
		csr->buf_max_size = DEBUGFS_CONNECT_INFO_BUF_SIZE;
		csr->entry = debugfs_create_file(csr->name, 0444,
						 adapter->debugfs_phy,
						 csr, &fops_csr_debugfs);
		if (!csr->entry)
			hdd_err("Failed to create debugfs file: %s",
				csr->name);
	}

	csr = &adapter->csr_file[HDD_DEBUFS_FILE_ID_OFFLOAD_INFO];
	if (!csr->entry) {
		strlcpy(csr->name, "offload_info", max_len);
		csr->id = HDD_DEBUFS_FILE_ID_OFFLOAD_INFO;
		csr->buf_max_size = DEBUGFS_OFFLOAD_INFO_BUF_SIZE;
		csr->entry = debugfs_create_file(csr->name, 0444,
						 adapter->debugfs_phy,
						 csr, &fops_csr_debugfs);
		if (!csr->entry)
<<<<<<< HEAD
			hdd_err("Failed to create debugfs file: %s",
				csr->name);
=======
			hdd_err("Failed to create generic_info debugfs file");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	}

	csr = &adapter->csr_file[HDD_DEBUFS_FILE_ID_ROAM_SCAN_STATS_INFO];
	if (!csr->entry) {
		strlcpy(csr->name, "roam_stats", max_len);
		csr->id = HDD_DEBUFS_FILE_ID_ROAM_SCAN_STATS_INFO;
		csr->buf_max_size = DEBUGFS_ROAM_SCAN_STATS_INFO_BUF_SIZE;
		csr->entry = debugfs_create_file(csr->name, 0444,
						 adapter->debugfs_phy,
						 csr, &fops_csr_debugfs);
		if (!csr->entry)
<<<<<<< HEAD
			hdd_err("Failed to create debugfs file: %s",
				csr->name);
	}
}

void wlan_hdd_debugfs_csr_deinit(hdd_adapter_t *adapter)
=======
			hdd_err("Failed to create generic_info debugfs file");
	}
}

void wlan_hdd_debugfs_csr_deinit(struct hdd_adapter *adapter)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	uint32_t i;
	struct dentry *entry;

	for (i = 0; i < HDD_DEBUGFS_FILE_ID_MAX; i++) {
		entry = adapter->csr_file[i].entry;
		if (!entry)
			continue;

		adapter->csr_file[i].entry = NULL;
		debugfs_remove(entry);
		entry = NULL;
	}
}

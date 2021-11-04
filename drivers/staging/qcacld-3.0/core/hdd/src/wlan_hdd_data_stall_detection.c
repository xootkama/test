/*
<<<<<<< HEAD
 * Copyright (c) 2017 The Linux Foundation. All rights reserved.
=======
 * Copyright (c) 2017-2020 The Linux Foundation. All rights reserved.
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
 * DOC: wlan_hdd_data_stall_detection.c
 *
 * WLAN Host Device Driver Data Stall detection API implementation
 */

<<<<<<< HEAD
#include "wlan_hdd_data_stall_detection.h"
#include "cdp_txrx_cmn.h"
#include "ol_txrx_types.h"
=======
#include <wlan_qct_sys.h>
#include <scheduler_api.h>
#include "wlan_hdd_data_stall_detection.h"
#include "wlan_hdd_main.h"
#include "cdp_txrx_cmn.h"
#include "cdp_txrx_misc.h"
#include "ol_txrx_types.h"
#include "ol_defines.h"
#ifdef FEATURE_WLAN_DIAG_SUPPORT
#include "host_diag_core_event.h"
#include "host_diag_core_log.h"
#endif /* FEATURE_WLAN_DIAG_SUPPORT */
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

#ifdef FEATURE_WLAN_DIAG_SUPPORT

/**
 * hdd_data_stall_send_event()- send data stall information
 * @reason: data stall event subtype
 * This Function sends data stall status diag event
 *
 * Return: void.
 */
static void hdd_data_stall_send_event(uint32_t reason)
{
	WLAN_HOST_DIAG_EVENT_DEF(sta_data_stall,
				struct host_event_wlan_datastall);
	qdf_mem_zero(&sta_data_stall, sizeof(sta_data_stall));
	sta_data_stall.reason = reason;
<<<<<<< HEAD
=======
	hdd_debug("Posting data stall event %x", reason);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	WLAN_HOST_DIAG_EVENT_REPORT(&sta_data_stall, EVENT_WLAN_STA_DATASTALL);
}
#else
static inline void hdd_data_stall_send_event(uint32_t reason)
{
}
#endif

/**
<<<<<<< HEAD
 * hdd_data_stall_process_cb() - Process data stall message
=======
 * hdd_data_stall_process_event() - Process data stall event
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @message: data stall message
 *
 * Process data stall message
 *
 * Return: void
 */
<<<<<<< HEAD
static void hdd_data_stall_process_cb(
=======
static void hdd_data_stall_process_event(
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			struct data_stall_event_info *data_stall_info)
{
	hdd_data_stall_send_event(data_stall_info->data_stall_type);
}

<<<<<<< HEAD
int hdd_register_data_stall_detect_cb(void)
{
	QDF_STATUS status;

	/* Register the data stall callback */
	status = ol_register_data_stall_detect_cb(hdd_data_stall_process_cb);
=======
/**
 * hdd_data_stall_process_cb() - Process data stall message
 * @message: data stall message
 *
 * Process data stall message
 *
 * Return: void
 */
static void hdd_data_stall_process_cb(
			struct data_stall_event_info *info)
{
	struct scheduler_msg msg = {0};
	struct data_stall_event_info *data_stall_event_info;
	QDF_STATUS status;

	data_stall_event_info = qdf_mem_malloc(sizeof(*data_stall_event_info));
	if (!data_stall_event_info)
		return;

	data_stall_event_info->data_stall_type = info->data_stall_type;
	data_stall_event_info->indicator = info->indicator;
	data_stall_event_info->pdev_id = info->pdev_id;
	data_stall_event_info->recovery_type = info->recovery_type;
	data_stall_event_info->vdev_id_bitmap = info->vdev_id_bitmap;

	sys_build_message_header(SYS_MSG_ID_DATA_STALL_MSG, &msg);
	/* Save callback and data */
	msg.callback = hdd_data_stall_process_event;
	msg.bodyptr = data_stall_event_info;
	msg.bodyval = 0;

	status = scheduler_post_message(QDF_MODULE_ID_HDD,
					QDF_MODULE_ID_HDD,
					QDF_MODULE_ID_SYS, &msg);

	if (status != QDF_STATUS_SUCCESS)
		qdf_mem_free(data_stall_event_info);
}

int hdd_register_data_stall_detect_cb(void)
{
	QDF_STATUS status;
	void *soc = cds_get_context(QDF_MODULE_ID_SOC);

	/* Register the data stall callback */
	hdd_debug("Register data stall detect callback");
	status = cdp_data_stall_cb_register(soc, OL_TXRX_PDEV_ID,
					    hdd_data_stall_process_cb);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	return qdf_status_to_os_return(status);
}

int hdd_deregister_data_stall_detect_cb(void)
{
	QDF_STATUS status;
<<<<<<< HEAD

	/* De-Register the data stall callback */
	status = ol_deregister_data_stall_detect_cb(hdd_data_stall_process_cb);
=======
	void *soc = cds_get_context(QDF_MODULE_ID_SOC);

	/* De-Register the data stall callback */
	hdd_debug("De-Register data stall detect callback");
	status = cdp_data_stall_cb_deregister(soc, OL_TXRX_PDEV_ID,
					      hdd_data_stall_process_cb);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	return qdf_status_to_os_return(status);
}

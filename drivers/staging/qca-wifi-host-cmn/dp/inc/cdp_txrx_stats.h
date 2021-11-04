/*
<<<<<<< HEAD
 * Copyright (c) 2016-2017 The Linux Foundation. All rights reserved.
=======
 * Copyright (c) 2016-2017,2019 The Linux Foundation. All rights reserved.
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
 * @file cdp_txrx_stats.h
 * @brief Define the host data path statistics API functions
 * called by the host control SW and the OS interface module
 */
#ifndef _CDP_TXRX_STATS_H_
#define _CDP_TXRX_STATS_H_
<<<<<<< HEAD
#include <qdf_status.h>
#include <qdf_types.h>

/**
 * ol_txrx_display_stats() - Display OL TXRX stats
 * @value: Module id for which stats needs to be displayed
 * @verb_level: verbosity level for tx rx stats
 *
 * Return: QDF_STATUS_SUCCESS on success, QDF_STATUS_E code on failure
 */
QDF_STATUS ol_txrx_display_stats(uint16_t value,
			enum qdf_stats_verb_lvl verb_level);
QDF_STATUS ol_txrx_clear_stats(uint16_t bitmap);
int ol_txrx_stats(uint8_t vdev_id, char *buffer, unsigned int buf_len);
=======
#include <cdp_txrx_ops.h>

static inline QDF_STATUS
cdp_clear_stats(ol_txrx_soc_handle soc, uint8_t pdev_id, uint8_t bitmap)
{

	if (!soc || !soc->ops) {
		QDF_TRACE(QDF_MODULE_ID_CDP, QDF_TRACE_LEVEL_DEBUG,
				"%s: Invalid Instance", __func__);
		QDF_BUG(0);
		return QDF_STATUS_E_INVAL;
	}

	if (!soc->ops->mob_stats_ops ||
	    !soc->ops->mob_stats_ops->clear_stats)
		return QDF_STATUS_E_INVAL;

	return soc->ops->mob_stats_ops->clear_stats(soc, pdev_id, bitmap);
}

static inline int
cdp_stats(ol_txrx_soc_handle soc, uint8_t vdev_id, char *buffer,
		unsigned int buf_len)
{
	if (!soc || !soc->ops) {
		QDF_TRACE(QDF_MODULE_ID_CDP, QDF_TRACE_LEVEL_DEBUG,
				"%s: Invalid Instance", __func__);
		QDF_BUG(0);
		return 0;
	}

	if (!soc->ops->mob_stats_ops ||
	    !soc->ops->mob_stats_ops->stats)
		return 0;

	return soc->ops->mob_stats_ops->stats(vdev_id, buffer, buf_len);
}
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

#endif /* _CDP_TXRX_STATS_H_ */

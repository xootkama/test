/*
<<<<<<< HEAD
 * Copyright (c) 2014-2016 The Linux Foundation. All rights reserved.
=======
 * Copyright (c) 2014-2016, 2018-2019 The Linux Foundation. All rights reserved.
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
 * DOC: qdf_timer
 * This file abstracts OS timers running in soft IRQ context.
 */

#ifndef _QDF_TIMER_H
#define _QDF_TIMER_H

#include <qdf_types.h>
#include <i_qdf_timer.h>

<<<<<<< HEAD
/* Platform timer object */
typedef __qdf_timer_t qdf_timer_t;
=======
typedef struct __qdf_timer_t qdf_timer_t;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * qdf_timer_init() - initialize a timer
 * @hdl: OS handle
 * @timer: Timer object pointer
 * @func: Timer function
<<<<<<< HEAD
 * @arg: Arguement of timer function
=======
 * @arg: Argument of timer function
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @type: deferrable or non deferrable timer type
 *
 * Timer type QDF_TIMER_TYPE_SW means its a deferrable sw timer which will
 * not cause CPU wake upon expiry
 * Timer type QDF_TIMER_TYPE_WAKE_APPS means its a non-deferrable timer which
 * will cause CPU wake up on expiry
 *
<<<<<<< HEAD
 * Return: none
 */
static inline void qdf_timer_init(qdf_handle_t hdl, qdf_timer_t *timer,
				  qdf_timer_func_t func, void *arg,
				  QDF_TIMER_TYPE type)
{
	__qdf_timer_init(hdl, timer, func, arg, type);
}

/**
 * qdf_timer_start() - start a one-shot timer
 * @timer: Timer object pointer
 * @msec: Expiration period in milliseconds
 *
 * Return: none
 */
static inline void
qdf_timer_start(qdf_timer_t *timer, int msec)
=======
 * Return: QDF_STATUS
 */
static inline QDF_STATUS
qdf_timer_init(qdf_handle_t hdl, qdf_timer_t *timer, qdf_timer_func_t func,
	       void *arg, QDF_TIMER_TYPE type)
{
	return __qdf_timer_init(timer, func, arg, type);
}

/**
 * qdf_timer_start() - start a timer
 * @timer: timer to start
 * @msec: Expiration period in milliseconds
 *
 * If QDF timer multiplier is set, the timeout value may get scaled.
 *
 * Return: none
 */
static inline void qdf_timer_start(qdf_timer_t *timer, int msec)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	__qdf_timer_start(timer, msec);
}

/**
<<<<<<< HEAD
 * qdf_timer_mod() - modify existing timer to new timeout value
 * @timer: Timer object pointer
 * @msec: Expiration period in milliseconds
 *
=======
 * qdf_timer_mod() - modify the timeout on a timer
 * @timer: timer to modify
 * @msec: Expiration period in milliseconds
 *
 * If @timer is not active, it will be activated.
 *
 * If QDF timer multiplier is set, the timeout value may get scaled.
 *
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * Return: none
 */
static inline void qdf_timer_mod(qdf_timer_t *timer, int msec)
{
	__qdf_timer_mod(timer, msec);
}

/**
<<<<<<< HEAD
 * qdf_timer_stop() - cancel qdf timer
 * @timer: Timer object pointer
 *
 * return: bool TRUE Timer was cancelled and deactived
 * FALSE Timer was cancelled but already got fired.
 *
 * The function will return after any running timer completes.
=======
 * qdf_timer_stop() - cancel a timer
 * @timer: timer to cancel
 *
 * Note! The timer callback may be executing when this function call returns.
 * If you want to ensure that it is not, use qdf_timer_sync_cancel() instead.
 *
 * Return: true if @timer was deactivated, false if @timer was not active
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 */
static inline bool qdf_timer_stop(qdf_timer_t *timer)
{
	return __qdf_timer_stop(timer);
}

<<<<<<< HEAD

/**
 * qdf_timer_sync_cancel - Cancel a timer synchronously
 * The function will return after any running timer completes.
 * @timer: timer object pointer
 *
 * return: bool TRUE timer was cancelled and deactived
 * FALSE timer was not cancelled
=======
/**
 * qdf_timer_sync_cancel - Cancel a timer synchronously
 * @timer: timer to cancel
 *
 * If the timer callback is already running, this function blocks until it
 * completes.
 *
 * Return: true if @timer was deactivated, false if @timer was not active
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 */
static inline bool qdf_timer_sync_cancel(qdf_timer_t *timer)
{
	return __qdf_timer_sync_cancel(timer);
}

<<<<<<< HEAD

/**
 * qdf_timer_free() - free qdf timer
 * @timer: Timer object pointer
 *
 * The function will return after any running timer completes.
=======
/**
 * qdf_timer_free() - free a timer
 * @timer: timer to free
 *
 * If the timer callback is already running, this function blocks until it
 * completes.
 *
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * Return: none
 */
static inline void qdf_timer_free(qdf_timer_t *timer)
{
	__qdf_timer_free(timer);
}

#endif /* _QDF_TIMER_H */

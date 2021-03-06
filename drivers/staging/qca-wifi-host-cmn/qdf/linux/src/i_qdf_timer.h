/*
<<<<<<< HEAD
 * Copyright (c) 2014-2018 The Linux Foundation. All rights reserved.
=======
 * Copyright (c) 2014-2019 The Linux Foundation. All rights reserved.
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
 * DOC: i_qdf_timer
 * This file provides OS dependent timer API's.
 */

#ifndef _I_QDF_TIMER_H
#define _I_QDF_TIMER_H

#include <linux/version.h>
#include <linux/delay.h>
#include <linux/timer.h>
#include <linux/jiffies.h>
<<<<<<< HEAD
#include <qdf_types.h>

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 9, 0)
#define setup_deferrable_timer(timer, fn, data)                                \
	__setup_timer((timer), (fn), (data), TIMER_DEFERRABLE)
#endif

/* timer data type */
typedef struct timer_list __qdf_timer_t;

/**
 * __qdf_timer_init() - initialize a softirq timer
 * @hdl: OS handle
 * @timer: Pointer to timer object
 * @func: Function pointer
 * @arg: Arguement
 * @type: deferrable or non deferrable timer type
 *
 * Timer type QDF_TIMER_TYPE_SW means its a deferrable sw timer which will
 * not cause CPU wake upon expiry
 * Timer type QDF_TIMER_TYPE_WAKE_APPS means its a non-deferrable timer which
 * will cause CPU wake up on expiry
 *
 * Return: QDF_STATUS
 */
static inline QDF_STATUS __qdf_timer_init(qdf_handle_t hdl,
					  struct timer_list *timer,
					  qdf_timer_func_t func, void *arg,
					  QDF_TIMER_TYPE type)
{
	if (type == QDF_TIMER_TYPE_SW) {
		if (object_is_on_stack(timer))
			setup_deferrable_timer_on_stack(timer, func,
							(unsigned long)arg);
		else
			setup_deferrable_timer(timer, func,
					       (unsigned long)arg);
	} else {
		if (object_is_on_stack(timer))
			setup_timer_on_stack(timer, func, (unsigned long)arg);
		else
			setup_timer(timer, func, (unsigned long)arg);
=======
#include "qdf_mc_timer.h"
#include <qdf_types.h>
#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 14, 0)
#include <linux/sched/task_stack.h>
#endif

typedef void (*qdf_timer_func_t)(void *);


struct __qdf_timer_t {
	struct timer_list os_timer;
	qdf_timer_func_t callback;
	void *context;
};

#ifdef QDF_TIMER_MULTIPLIER_FRAC
#define __qdf_scaled_msecs_to_jiffies(msec) \
	(QDF_TIMER_MULTIPLIER_FRAC * msecs_to_jiffies(msec))
#else
#define __qdf_scaled_msecs_to_jiffies(msec) \
	(qdf_timer_get_multiplier() * msecs_to_jiffies(msec))
#endif

#if LINUX_VERSION_CODE >= KERNEL_VERSION(4, 15, 0)
static inline void __os_timer_shim(struct timer_list *os_timer)
{
	struct __qdf_timer_t *timer = from_timer(timer, os_timer, os_timer);

	timer->callback(timer->context);
}

static inline QDF_STATUS __qdf_timer_init(struct __qdf_timer_t *timer,
					  qdf_timer_func_t func, void *arg,
					  QDF_TIMER_TYPE type)
{
	struct timer_list *os_timer = &timer->os_timer;
	uint32_t flags = 0;

	timer->callback = func;
	timer->context = arg;

	if (type == QDF_TIMER_TYPE_SW)
		flags |= TIMER_DEFERRABLE;

	if (object_is_on_stack(os_timer))
		timer_setup_on_stack(os_timer, __os_timer_shim, flags);
	else
		timer_setup(os_timer, __os_timer_shim, flags);

	return QDF_STATUS_SUCCESS;
}

#else

#if LINUX_VERSION_CODE < KERNEL_VERSION(4, 9, 0)
#define setup_deferrable_timer(timer, fn, data) \
	__setup_timer((timer), (fn), (data), TIMER_DEFERRABLE)
#endif

static inline void __os_timer_shim(unsigned long addr)
{
	struct __qdf_timer_t *timer = (void *)addr;

	timer->callback(timer->context);
}

static inline QDF_STATUS __qdf_timer_init(struct __qdf_timer_t *timer,
					  qdf_timer_func_t func, void *arg,
					  QDF_TIMER_TYPE type)
{
	struct timer_list *os_timer = &timer->os_timer;
	bool is_on_stack = object_is_on_stack(os_timer);
	unsigned long addr = (unsigned long)timer;

	timer->callback = func;
	timer->context = arg;

	if (type == QDF_TIMER_TYPE_SW) {
		if (is_on_stack)
			setup_deferrable_timer_on_stack(os_timer,
							__os_timer_shim,
							addr);
		else
			setup_deferrable_timer(os_timer, __os_timer_shim, addr);
	} else {
		if (is_on_stack)
			setup_timer_on_stack(os_timer, __os_timer_shim, addr);
		else
			setup_timer(os_timer, __os_timer_shim, addr);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	}

	return QDF_STATUS_SUCCESS;
}
<<<<<<< HEAD

/**
 * __qdf_timer_start() - start a qdf softirq timer
 * @timer: Pointer to timer object
 * @delay: Delay in milli seconds
 *
 * Return: QDF_STATUS
 */
static inline QDF_STATUS __qdf_timer_start(struct timer_list *timer,
					   uint32_t delay)
{
	timer->expires = jiffies + msecs_to_jiffies(delay);
	add_timer(timer);

	return QDF_STATUS_SUCCESS;
}

/**
 * __qdf_timer_mod() - modify a timer
 * @timer: Pointer to timer object
 * @delay: Delay in milli seconds
 *
 * Return: QDF_STATUS
 */
static inline QDF_STATUS __qdf_timer_mod(struct timer_list *timer,
					 uint32_t delay)
{
	mod_timer(timer, jiffies + msecs_to_jiffies(delay));

	return QDF_STATUS_SUCCESS;
}

/**
 * __qdf_timer_stop() - cancel a timer
 * @timer: Pointer to timer object
 *
 * Return: true if timer was cancelled and deactived,
 * false if timer was cancelled but already got fired.
 */
static inline bool __qdf_timer_stop(struct timer_list *timer)
{
	if (likely(del_timer(timer)))
		return 1;
	else
		return 0;
}

/**
 * __qdf_timer_free() - free a qdf timer
 * @timer: Pointer to timer object
 *
 * Return: None
 */
static inline void __qdf_timer_free(struct timer_list *timer)
{
	del_timer_sync(timer);

	if (object_is_on_stack(timer))
		destroy_timer_on_stack(timer);
}

/**
 * __qdf_sostirq_timer_sync_cancel() - Synchronously canel a timer
 * @timer: Pointer to timer object
 *
 * Synchronization Rules:
 * 1. caller must make sure timer function will not use
 *    qdf_set_timer to add iteself again.
 * 2. caller must not hold any lock that timer function
 *    is likely to hold as well.
 * 3. It can't be called from interrupt context.
 *
 * Return: true if timer was cancelled and deactived,
 * false if timer was cancelled but already got fired.
 */
static inline bool __qdf_timer_sync_cancel(struct timer_list *timer)
{
	return del_timer_sync(timer);
}

#endif /*_QDF_TIMER_PVT_H*/
=======
#endif /* KERNEL_VERSION(4, 15, 0)*/

static inline void __qdf_timer_start(struct __qdf_timer_t *timer, uint32_t msec)
{
	struct timer_list *os_timer = &timer->os_timer;

	os_timer->expires = jiffies + __qdf_scaled_msecs_to_jiffies(msec);
	add_timer(os_timer);
}

static inline void __qdf_timer_mod(struct __qdf_timer_t *timer, uint32_t msec)
{
	mod_timer(&timer->os_timer,
		  jiffies + __qdf_scaled_msecs_to_jiffies(msec));
}

static inline bool __qdf_timer_stop(struct __qdf_timer_t *timer)
{
	return !!del_timer(&timer->os_timer);
}

static inline void __qdf_timer_free(struct __qdf_timer_t *timer)
{
	struct timer_list *os_timer = &timer->os_timer;

	del_timer_sync(os_timer);

	if (object_is_on_stack(os_timer))
		destroy_timer_on_stack(os_timer);
}

static inline bool __qdf_timer_sync_cancel(struct __qdf_timer_t *timer)
{
	return del_timer_sync(&timer->os_timer);
}

#endif /* _I_QDF_TIMER_H */
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

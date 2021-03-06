/*
<<<<<<< HEAD
 * Copyright (c) 2012-2019 The Linux Foundation. All rights reserved.
=======
 * Copyright (c) 2012-2020 The Linux Foundation. All rights reserved.
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

<<<<<<< HEAD
#if !defined(__CDS_SCHED_H)
=======
#ifndef __CDS_SCHED_H
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#define __CDS_SCHED_H

/**=========================================================================

   \file  cds_sched.h

   \brief Connectivity driver services scheduler

   ========================================================================*/

/*--------------------------------------------------------------------------
   Include Files
   ------------------------------------------------------------------------*/
#include <qdf_event.h>
#include <i_qdf_types.h>
#include <linux/wait.h>
#if defined(WLAN_OPEN_SOURCE) && defined(CONFIG_HAS_WAKELOCK)
#include <linux/wakelock.h>
#endif
<<<<<<< HEAD
#include <cds_mq.h>
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#include <qdf_types.h>
#include "qdf_lock.h"
#include "qdf_mc_timer.h"
#include "cds_config.h"
<<<<<<< HEAD
#include "cds_reg_service.h"
#include "qdf_cpuhp.h"
#include "ol_txrx.h"

#define TX_POST_EVENT               0x001
#define TX_SUSPEND_EVENT            0x002
#define MC_POST_EVENT               0x001
#define MC_SUSPEND_EVENT            0x002
#define RX_POST_EVENT               0x001
#define RX_SUSPEND_EVENT            0x002
#define TX_SHUTDOWN_EVENT           0x010
#define MC_SHUTDOWN_EVENT           0x010
#define RX_SHUTDOWN_EVENT           0x010
#define WD_POST_EVENT               0x001
#define WD_SHUTDOWN_EVENT           0x002
#define WD_CHIP_RESET_EVENT         0x004
#define WD_WLAN_SHUTDOWN_EVENT      0x008
#define WD_WLAN_REINIT_EVENT        0x010

/*
 * Maximum number of messages in the system
 * These are buffers to account for all current messages
 * with some accounting of what we think is a
 * worst-case scenario.  Must be able to handle all
 * incoming frames, as well as overhead for internal
 * messaging
 *
 * Increased to 8000 to handle more RX frames
 */
#define CDS_CORE_MAX_MESSAGES 8000
=======
#include "qdf_cpuhp.h"

#define MC_SUSPEND_EVENT            0x002
#define RX_POST_EVENT               0x001
#define RX_SUSPEND_EVENT            0x002
#define RX_VDEV_DEL_EVENT           0x004
#define RX_SHUTDOWN_EVENT           0x010
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

#ifdef QCA_CONFIG_SMP
/*
** Maximum number of cds messages to be allocated for
** OL Rx thread.
*/
#define CDS_MAX_OL_RX_PKT 4000
#endif

<<<<<<< HEAD
/*
** Maximum number of cds messages to be allocated for
** OL MON thread.
*/
#define CDS_MAX_OL_MON_PKT 4000

typedef void (*cds_ol_rx_thread_cb)(void *context, void *rxpkt, uint16_t staid);

typedef void (*cds_ol_mon_thread_cb)(
			void *context, void *monpkt,
			uint8_t vdev_id, uint8_t tid,
			struct ol_mon_tx_status pkt_tx_status,
			bool pkt_format);

typedef int (*send_mode_change_event_cb)(void);

/*
** QDF Message queue definition.
*/
typedef struct _cds_mq_type {
	/* Lock use to synchronize access to this message queue */
	spinlock_t mqLock;

	/* List of vOS Messages waiting on this queue */
	struct list_head mqList;

} cds_mq_type, *p_cds_mq_type;
=======
typedef void (*cds_ol_rx_thread_cb)(void *context,
				    qdf_nbuf_t rxpkt,
				    uint16_t staid);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/*
** CDS message wrapper for data rx from TXRX
*/
struct cds_ol_rx_pkt {
	struct list_head list;
	void *context;

	/* Rx skb */
<<<<<<< HEAD
	void *Rxpkt;
=======
	qdf_nbuf_t Rxpkt;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	/* Station id to which this packet is destined */
	uint16_t staId;

	/* Call back to further send this packet to txrx layer */
	cds_ol_rx_thread_cb callback;

};

<<<<<<< HEAD
/*
** CDS message wrapper for mon data from TXRX
*/
=======
#ifdef WLAN_FEATURE_PKT_CAPTURE
/*
 * Maximum number of cds messages to be allocated for
 * OL MON thread.
 */
#define CDS_MAX_OL_MON_PKT 4000

struct cds_sched_mon_context {
	/* MON thread lock */
	spinlock_t ol_mon_thread_lock;

	/* OL MON thread handle */
	struct task_struct *ol_mon_thread;

	/* Handle of Event for MON thread to signal startup */
	struct completion ol_mon_start_event;

	/* Completion object to suspend OL MON thread */
	struct completion ol_suspend_mon_event;

	/* Completion objext to resume OL MON thread */
	struct completion ol_resume_mon_event;

	/* Completion object for OL MON thread shutdown */
	struct completion ol_mon_shutdown;

	/* Waitq for OL MON thread */
	wait_queue_head_t ol_mon_wait_queue;

	unsigned long ol_mon_event_flag;

	/* MON buffer queue */
	struct list_head ol_mon_thread_queue;

	/* Spinlock to synchronize between tasklet and thread */
	spinlock_t ol_mon_queue_lock;

	/* MON queue length */
	unsigned int ol_mon_queue_len;

	/* Lock to synchronize free buffer queue access */
	spinlock_t cds_ol_mon_pkt_freeq_lock;

	/* Free message queue for OL MON processing */
	struct list_head cds_ol_mon_pkt_freeq;

	/* MON thread affinity cpu */
	unsigned long mon_thread_cpu;

};

#endif /* WLAN_FEATURE_PKT_CAPTURE */
typedef void (*cds_ol_mon_thread_cb)(
			void *context, void *monpkt,
			uint8_t vdev_id, uint8_t tid,
			uint8_t status, bool pkt_format);

/*
 * CDS message wrapper for mon data from TXRX
 */
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
struct cds_ol_mon_pkt {
	struct list_head list;
	void *context;

	/* mon skb */
	void *monpkt;

	/* vdev id to which this packet is destined */
	uint8_t vdev_id;

	uint8_t tid;

	/* Tx packet status */
<<<<<<< HEAD
	struct ol_mon_tx_status pkt_tx_status;
=======
	uint8_t status;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	/* 0 = 802.3 format , 1 = 802.11 format */
	bool pkt_format;

	/* Call back to further send this packet to txrx layer */
	cds_ol_mon_thread_cb callback;
};

/*
** CDS Scheduler context
** The scheduler context contains the following:
**   ** the messages queues
**   ** the handle to the tread
**   ** pointer to the events that gracefully shutdown the MC and Tx threads
**
*/
typedef struct _cds_sched_context {
<<<<<<< HEAD
	/* Place holder to the CDS Context */
	void *pVContext;
	/* WMA Message queue on the Main thread */
	cds_mq_type wmaMcMq;

	/* PE Message queue on the Main thread */
	cds_mq_type peMcMq;

	/* SME Message queue on the Main thread */
	cds_mq_type smeMcMq;

	/* SYS Message queue on the Main thread */
	cds_mq_type sysMcMq;

	/* Handle of Event for MC thread to signal startup */
	struct completion McStartEvent;

	struct task_struct *McThread;

	/* completion object for MC thread shutdown */
	struct completion McShutdown;

	/* Wait queue for MC thread */
	wait_queue_head_t mcWaitQueue;

	unsigned long mcEventFlag;

	/* Completion object to resume Mc thread */
	struct completion ResumeMcEvent;

	/* lock to make sure that McThread suspend/resume mechanism is in sync */
	spinlock_t McThreadLock;
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#ifdef QCA_CONFIG_SMP
	spinlock_t ol_rx_thread_lock;

	/* OL Rx thread handle */
	struct task_struct *ol_rx_thread;

	/* Handle of Event for Rx thread to signal startup */
	struct completion ol_rx_start_event;

	/* Completion object to suspend OL rx thread */
	struct completion ol_suspend_rx_event;

<<<<<<< HEAD
	/* Completion objext to resume OL rx thread */
=======
	/* Completion object to resume OL rx thread */
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	struct completion ol_resume_rx_event;

	/* Completion object for OL Rxthread shutdown */
	struct completion ol_rx_shutdown;

	/* Waitq for OL Rx thread */
	wait_queue_head_t ol_rx_wait_queue;

	unsigned long ol_rx_event_flag;

	/* Rx buffer queue */
	struct list_head ol_rx_thread_queue;

	/* Spinlock to synchronize between tasklet and thread */
	spinlock_t ol_rx_queue_lock;

<<<<<<< HEAD
	/* Rx queue length */
	unsigned int ol_rx_queue_len;

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	/* Lock to synchronize free buffer queue access */
	spinlock_t cds_ol_rx_pkt_freeq_lock;

	/* Free message queue for OL Rx processing */
	struct list_head cds_ol_rx_pkt_freeq;

	/* The CPU hotplug event registration handle, used to unregister */
	struct qdf_cpuhp_handler *cpuhp_event_handle;

	/* affinity lock */
	struct mutex affinity_lock;

<<<<<<< HEAD
	/* rx thread affinity cpu */
	unsigned long rx_thread_cpu;

	/* high throughput required */
	bool high_throughput_required;
#endif
	/* MON thread lock */
	spinlock_t ol_mon_thread_lock;

	/* OL MON thread handle */
	struct task_struct *ol_mon_thread;

	/* Handle of Event for MON thread to signal startup */
	struct completion ol_mon_start_event;

	/* Completion object to suspend OL MON thread */
	struct completion ol_suspend_mon_event;

	/* Completion objext to resume OL MON thread */
	struct completion ol_resume_mon_event;

	/* Completion object for OL MON thread shutdown */
	struct completion ol_mon_shutdown;

	/* Waitq for OL MON thread */
	wait_queue_head_t ol_mon_wait_queue;

	unsigned long ol_mon_event_flag;

	/* MON buffer queue */
	struct list_head ol_mon_thread_queue;

	/* Spinlock to synchronize between tasklet and thread */
	spinlock_t ol_mon_queue_lock;

	/* MON queue length */
	unsigned int ol_mon_queue_len;

	/* Lock to synchronize free buffer queue access */
	spinlock_t cds_ol_mon_pkt_freeq_lock;

	/* Free message queue for OL MON processing */
	struct list_head cds_ol_mon_pkt_freeq;

	/* MON thread affinity cpu */
	unsigned long mon_thread_cpu;
=======
	/* Saved rx thread CPU affinity */
	struct cpumask rx_thread_cpu_mask;

	/* CPU affinity bitmask */
	uint8_t conf_rx_thread_cpu_mask;

	/* high throughput required */
	bool high_throughput_required;

	/* affinity requied during uplink traffic*/
	bool rx_affinity_required;
	uint8_t conf_rx_thread_ul_affinity;
#endif

#ifdef WLAN_FEATURE_PKT_CAPTURE
	struct cds_sched_mon_context sched_mon_ctx;
#endif /* WLAN_FEATURE_PKT_CAPTURE */
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
} cds_sched_context, *p_cds_sched_context;

/**
 * struct cds_log_complete - Log completion internal structure
 * @is_fatal: Type is fatal or not
 * @indicator: Source of bug report
 * @reason_code: Reason code for bug report
 * @is_report_in_progress: If bug report is in progress
 * @recovery_needed: if recovery is needed after report completion
 *
 * This structure internally stores the log related params
 */
struct cds_log_complete {
	uint32_t is_fatal;
	uint32_t indicator;
	uint32_t reason_code;
	bool is_report_in_progress;
	bool recovery_needed;
};

<<<<<<< HEAD
/*
** CDS Sched Msg Wrapper
** Wrapper messages so that they can be chained to their respective queue
** in the scheduler.
*/
typedef struct _cds_msg_wrapper {
	/* Message node */
	struct list_head msgNode;

	/* the Vos message it is associated to */
	cds_msg_t *pVosMsg;

} cds_msg_wrapper, *p_cds_msg_wrapper;

/* forward-declare hdd_context_s as it is used ina function type */
struct hdd_context_s;
struct hdd_adapter_s;
typedef struct _cds_context_type {
	/* Messages buffers */
	cds_msg_t aMsgBuffers[CDS_CORE_MAX_MESSAGES];

	cds_msg_wrapper aMsgWrappers[CDS_CORE_MAX_MESSAGES];

	/* Free Message queue */
	cds_mq_type freeVosMq;

=======
struct cds_context {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	/* Scheduler Context */
	cds_sched_context qdf_sched;

	/* HDD Module Context  */
<<<<<<< HEAD
	void *pHDDContext;

	/* MAC Module Context  */
	void *pMACContext;

	qdf_event_t ProbeEvent;

	uint32_t driver_state;
	unsigned long fw_state;

	qdf_event_t wmaCompleteEvent;

	/* WMA Context */
	void *pWMAContext;

	void *pHIFContext;
=======
	void *hdd_context;

	/* MAC Module Context  */
	void *mac_context;

	uint32_t driver_state;

	qdf_event_t wma_complete_event;

	/* WMA Context */
	void *wma_context;

	void *hif_context;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	void *htc_ctx;

	void *g_ol_context;
	/*
	 * qdf_ctx will be used by qdf
	 * while allocating dma memory
	 * to access dev information.
	 */
	qdf_device_t qdf_ctx;

<<<<<<< HEAD
	void *pdev_txrx_ctx;

	/* Configuration handle used to get system configuration */
	void *cfg_ctx;
=======
	void *dp_soc;

	void *dp_mem_pre_alloc_ctx;

	/* Configuration handle used to get system configuration */
	struct cdp_cfg *cfg_ctx;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	/* radio index per driver */
	int radio_index;

	bool is_wakelock_log_enabled;
	uint32_t wakelock_log_level;
	uint32_t connectivity_log_level;
	uint32_t packet_stats_log_level;
	uint32_t driver_debug_log_level;
	uint32_t fw_debug_log_level;
	struct cds_log_complete log_complete;
	qdf_spinlock_t bug_report_lock;
<<<<<<< HEAD
	qdf_event_t connection_update_done_evt;
	qdf_mutex_t qdf_conc_list_lock;
	qdf_mc_timer_t dbs_opportunistic_timer;
	qdf_event_t opportunistic_update_done_evt;
#ifdef FEATURE_WLAN_MCC_TO_SCC_SWITCH
	void (*sap_restart_chan_switch_cb)(struct hdd_adapter_s *,
					   uint32_t, uint32_t);
#endif
	QDF_STATUS (*sme_get_valid_channels)(void*, uint16_t cfg_id,
		uint8_t *, uint32_t *);
	void (*sme_get_nss_for_vdev)(void*, enum tQDF_ADAPTER_MODE,
		uint8_t *, uint8_t *);

	/* Datapath callback functions */
	void (*ol_txrx_update_mac_id_cb)(uint8_t, uint8_t);
	void (*hdd_en_lro_in_cc_cb)(struct hdd_context_s *);
	void (*hdd_disable_lro_in_cc_cb)(struct hdd_context_s *);
	void (*hdd_set_rx_mode_rps_cb)(struct hdd_context_s *, void *, bool);
	void (*hdd_ipa_set_mcc_mode_cb)(bool);

	/* This list is not sessionized. This mandatory channel list would be
	 * as per OEMs preference as per the regulatory/other considerations.
	 * So, this would remain same for all the interfaces.
	 */
	uint8_t sap_mandatory_channels[QDF_MAX_NUM_CHAN];
	uint32_t sap_mandatory_channels_len;
	bool enable_sap_mandatory_chan_list;
	bool do_hw_mode_change;
	bool enable_fatal_event;
	struct cds_config_info *cds_cfg;

	/* This is to track if HW mode change is in progress */
	uint32_t hw_mode_change_in_progress;
	uint16_t unsafe_channel_count;
	uint16_t unsafe_channel_list[NUM_CHANNELS];
	/* current system preference */
	uint8_t cur_conc_system_pref;
	qdf_work_t cds_recovery_work;
	qdf_workqueue_t *cds_recovery_wq;
	enum cds_hang_reason recovery_reason;
	qdf_event_t channel_switch_complete;
	send_mode_change_event_cb mode_change_cb;
} cds_context_type, *p_cds_contextType;

extern struct _cds_sched_context *gp_cds_sched_context;
=======

	bool enable_fatal_event;
	struct cds_config_info *cds_cfg;

	struct ol_tx_sched_wrr_ac_specs_t ac_specs[QCA_WLAN_AC_ALL];
	qdf_work_t cds_recovery_work;
	qdf_workqueue_t *cds_recovery_wq;
	enum qdf_hang_reason recovery_reason;
};
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/*---------------------------------------------------------------------------
   Function declarations and documenation
   ---------------------------------------------------------------------------*/
#ifdef QCA_CONFIG_SMP
int cds_sched_handle_cpu_hot_plug(void);
int cds_sched_handle_throughput_req(bool high_tput_required);

<<<<<<< HEAD
=======
/**
 * cds_sched_handle_rx_thread_affinity_req - rx thread affinity req handler
 * @high_tput_required: high throughput is required or not
 *
 * rx thread affinity handler will find online cores and
 * will assign proper core based on perf requirement
 *
 * Return: None
 */
void cds_sched_handle_rx_thread_affinity_req(bool high_throughput);

/**
 * cds_set_rx_thread_ul_cpu_mask() - Rx_thread affinity for UL from INI
 * @cpu_affinity_mask: CPU affinity bitmap
 *
 * Return:None
 */
void cds_set_rx_thread_ul_cpu_mask(uint8_t cpu_affinity_mask);

/**
 * cds_set_rx_thread_cpu_mask() - Rx_thread affinity from INI
 * @cpu_affinity_mask: CPU affinity bitmap
 *
 * Return:None
 */
void cds_set_rx_thread_cpu_mask(uint8_t cpu_affinity_mask);

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/*---------------------------------------------------------------------------
   \brief cds_drop_rxpkt_by_staid() - API to drop pending Rx packets for a sta
   The \a cds_drop_rxpkt_by_staid() drops queued packets for a station, to drop
   all the pending packets the caller has to send WLAN_MAX_STA_COUNT as staId.
   \param  pSchedContext - pointer to the global CDS Sched Context
   \param staId - Station Id

   \return Nothing
   \sa cds_drop_rxpkt_by_staid()
   -------------------------------------------------------------------------*/
void cds_drop_rxpkt_by_staid(p_cds_sched_context pSchedContext, uint16_t staId);

/*---------------------------------------------------------------------------
   \brief cds_indicate_rxpkt() - API to Indicate rx data packet
   The \a cds_indicate_rxpkt() enqueues the rx packet onto ol_rx_thread_queue
   and notifies cds_ol_rx_thread().
   \param  Arg - pointer to the global CDS Sched Context
   \param pkt - Vos data message buffer

   \return Nothing
   \sa cds_indicate_rxpkt()
   -------------------------------------------------------------------------*/
void cds_indicate_rxpkt(p_cds_sched_context pSchedContext,
			struct cds_ol_rx_pkt *pkt);

/**
<<<<<<< HEAD
 * cds_wakeup_rx_thread() - wakeup rx thread
 * @Arg: Pointer to the global CDS Sched Context
 *
 * This api wake up cds_ol_rx_thread() to process pkt
 *
 * Return: none
 */
void cds_wakeup_rx_thread(p_cds_sched_context pSchedContext);

/**
 * cds_close_rx_thread() - close the Tlshim Rx thread
 * @p_cds_context: Pointer to the global CDS Context
 *
 * This api closes the Tlshim Rx thread:
 *
 * Return: qdf status
 */
QDF_STATUS cds_close_rx_thread(void *p_cds_context);
=======
 * cds_close_rx_thread() - close the Rx thread
 *
 * This api closes the Rx thread:
 *
 * Return: qdf status
 */
QDF_STATUS cds_close_rx_thread(void);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/*---------------------------------------------------------------------------
   \brief cds_alloc_ol_rx_pkt() - API to return next available cds message
   The \a cds_alloc_ol_rx_pkt() returns next available cds message buffer
   used for Rx Data processing.
   \param pSchedContext - pointer to the global CDS Sched Context

   \return pointer to cds message buffer
   \sa cds_alloc_ol_rx_pkt()
   -------------------------------------------------------------------------*/
struct cds_ol_rx_pkt *cds_alloc_ol_rx_pkt(p_cds_sched_context pSchedContext);

/*---------------------------------------------------------------------------
   \brief cds_free_ol_rx_pkt() - API to release cds message to the freeq
   The \a cds_free_ol_rx_pkt() returns the cds message used for Rx data
   to the free queue.
   \param  pSchedContext - pointer to the global CDS Sched Context
   \param  pkt - Vos message buffer to be returned to free queue.

   \return Nothing
   \sa cds_free_ol_rx_pkt()
   -------------------------------------------------------------------------*/
void cds_free_ol_rx_pkt(p_cds_sched_context pSchedContext,
			 struct cds_ol_rx_pkt *pkt);
/*---------------------------------------------------------------------------
   \brief cds_free_ol_rx_pkt_freeq() - Free cdss buffer free queue
   The \a cds_free_ol_rx_pkt_freeq() does mem free of the buffers
   available in free cds buffer queue which is used for Data rx processing
   from Tlshim.
   \param pSchedContext - pointer to the global CDS Sched Context

   \return Nothing
   \sa cds_free_ol_rx_pkt_freeq()
   -------------------------------------------------------------------------*/
void cds_free_ol_rx_pkt_freeq(p_cds_sched_context pSchedContext);
#else
/**
<<<<<<< HEAD
=======
 * cds_sched_handle_rx_thread_affinity_req - rx thread affinity req handler
 * @high_tput_required: high throughput is required or not
 *
 * rx thread affinity handler will find online cores and
 * will assign proper core based on perf requirement
 *
 * Return: None
 */
static inline void cds_sched_handle_rx_thread_affinity_req(
	bool high_throughput) {}

/**
 * cds_set_rx_thread_ul_cpu_mask() - Rx_thread affinity for UL from INI
 * @cpu_affinity_mask: CPU affinity bitmap
 *
 * Return:None
 */
static inline void cds_set_rx_thread_ul_cpu_mask(uint8_t cpu_affinity_mask) {}

/**
 * cds_set_rx_thread_cpu_mask() - Rx_thread affinity from INI
 * @cpu_affinity_mask: CPU affinity bitmap
 *
 * Return:None
 */
static inline void cds_set_rx_thread_cpu_mask(uint8_t cpu_affinity_mask) {}

/**
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * cds_drop_rxpkt_by_staid() - api to drop pending rx packets for a sta
 * @pSchedContext: Pointer to the global CDS Sched Context
 * @staId: Station Id
 *
 * This api drops queued packets for a station, to drop all the pending
 * packets the caller has to send WLAN_MAX_STA_COUNT as staId.
 *
 * Return: none
 */
static inline
void cds_drop_rxpkt_by_staid(p_cds_sched_context pSchedContext, uint16_t staId)
{
}

/**
 * cds_indicate_rxpkt() - API to Indicate rx data packet
 * @pSchedContext: pointer to  CDS Sched Context
 * @pkt: CDS OL RX pkt pointer containing to RX data message buffer
 *
 * Return: none
 */
static inline
void cds_indicate_rxpkt(p_cds_sched_context pSchedContext,
			struct cds_ol_rx_pkt *pkt)
{
}

/**
<<<<<<< HEAD
 * cds_wakeup_rx_thread() - wakeup rx thread
 * @Arg: Pointer to the global CDS Sched Context
 *
 * This api wake up cds_ol_rx_thread() to process pkt
 *
 * Return: none
 */
static inline
void cds_wakeup_rx_thread(p_cds_sched_context pSchedContext)
{
}

/**
 * cds_close_rx_thread() - close the Tlshim Rx thread
 * @p_cds_context: Pointer to the global CDS Context
 *
 * This api closes the Tlshim Rx thread:
=======
 * cds_close_rx_thread() - close the Rx thread
 *
 * This api closes the Rx thread:
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *
 * Return: qdf status
 */
static inline
<<<<<<< HEAD
QDF_STATUS cds_close_rx_thread(void *p_cds_context)
=======
QDF_STATUS cds_close_rx_thread(void)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	return QDF_STATUS_SUCCESS;
}

/**
 * cds_alloc_ol_rx_pkt() - API to return next available cds message
 * @pSchedContext: pointer to  CDS Sched Context
 *
 * Return: none
 */
static inline
struct cds_ol_rx_pkt *cds_alloc_ol_rx_pkt(p_cds_sched_context pSchedContext)
{
	return NULL;
}

/**
 * cds_free_ol_rx_pkt() - API to release cds message to the freeq
 * @pSchedContext: pointer to  CDS Sched Context
 * @pkt: CDS message buffer to be returned to free queue
 *
 * Return: none
 */
static inline
void cds_free_ol_rx_pkt(p_cds_sched_context pSchedContext,
			 struct cds_ol_rx_pkt *pkt)
{
}

/**
 * cds_free_ol_rx_pkt_freeq() - Free cds buffer free queue
 * @pSchedContext: pointer to  CDS Sched Context
 * @pkt: CDS message buffer to be returned to free queue
 *
 * Return: none
 */
static inline
void cds_free_ol_rx_pkt_freeq(p_cds_sched_context pSchedContext)
{
}

static inline int cds_sched_handle_throughput_req(
	bool high_tput_required)
{
	return 0;
}

#endif

<<<<<<< HEAD
/**
 * cds_drop_monpkt() - API to drop pending mon packets
 * @pschedcontext: Pointer to the global CDS Sched Context
 *
 * This api drops all the pending packets in the queue.
 *
 * Return: none
 */
void cds_drop_monpkt(p_cds_sched_context pschedcontext);

/**
 * cds_indicate_monpkt() - API to Indicate rx data packet
 * @pschedcontext: pointer to  CDS Sched Context
 * @pkt: CDS OL MON pkt pointer containing to mon data message buffer
 *
 * Return: none
 */
void cds_indicate_monpkt(p_cds_sched_context pschedcontext,
			 struct cds_ol_mon_pkt *pkt);

/**
 * cds_wakeup_mon_thread() - wakeup mon thread
 * @Arg: Pointer to the global CDS Sched Context
 *
 * This api wake up cds_ol_mon_thread() to process pkt
 *
 * Return: none
 */
void cds_wakeup_mon_thread(p_cds_sched_context pschedcontext);

/**
 * cds_close_mon_thread() - close the Tlshim MON thread
 * @p_cds_context: Pointer to the global CDS Context
 *
 * This api closes the Tlshim MON thread:
 *
 * Return: qdf status
 */
QDF_STATUS cds_close_mon_thread(void *p_cds_context);

/**
 * cds_alloc_ol_mon_pkt() - API to return next available cds message
 * @pSchedContext: Pointer to the global CDS Sched Context
 *
 * This api returns next available cds message buffer used for mon data
 * processing
 *
 * Return: Pointer to cds message buffer
 */
struct cds_ol_mon_pkt *cds_alloc_ol_mon_pkt(p_cds_sched_context pschedcontext);

/**
 * cds_free_ol_mon_pkt() - api to release cds message to the freeq
 * This api returns the cds message used for mon data to the free queue
 * @pSchedContext: Pointer to the global CDS Sched Context
 * @pkt: CDS message buffer to be returned to free queue.
 *
 * Return: none
 */
void cds_free_ol_mon_pkt(p_cds_sched_context pschedcontext,
			 struct cds_ol_mon_pkt *pkt);

/**
 * cds_free_ol_mon_pkt_freeq() - free cds buffer free queue
 * @pSchedContext - pointer to the global CDS Sched Context
 *
 * This API does mem free of the buffers available in free cds buffer
 * queue which is used for mon Data processing.
 *
 * Return: none
 */
void cds_free_ol_mon_pkt_freeq(p_cds_sched_context pschedcontext);

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/*---------------------------------------------------------------------------

   \brief cds_sched_open() - initialize the CDS Scheduler

   The \a cds_sched_open() function initializes the CDS Scheduler
   Upon successful initialization:

     - All the message queues are initialized

     - The Main Controller thread is created and ready to receive and
       dispatch messages.

     - The Tx thread is created and ready to receive and dispatch messages

   \param  p_cds_context - pointer to the global QDF Context

   \param  p_cds_sched_context - pointer to a previously allocated buffer big
   enough to hold a scheduler context.

   \return QDF_STATUS_SUCCESS - Scheduler was successfully initialized and
   is ready to be used.

   QDF_STATUS_E_RESOURCES - System resources (other than memory)
<<<<<<< HEAD
   are unavailable to initilize the scheduler
=======
   are unavailable to initialize the scheduler
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

   QDF_STATUS_E_NOMEM - insufficient memory exists to initialize
   the scheduler

   QDF_STATUS_E_INVAL - Invalid parameter passed to the scheduler Open
   function

   QDF_STATUS_E_FAILURE - Failure to initialize the scheduler/

   \sa cds_sched_open()

   -------------------------------------------------------------------------*/
QDF_STATUS cds_sched_open(void *p_cds_context,
			  p_cds_sched_context pSchedCxt, uint32_t SchedCtxSize);

/*---------------------------------------------------------------------------

   \brief cds_sched_close() - Close the CDS Scheduler

   The \a cds_sched_closes() function closes the CDS Scheduler
   Upon successful closing:

     - All the message queues are flushed

     - The Main Controller thread is closed

     - The Tx thread is closed

<<<<<<< HEAD
   \param  p_cds_context - pointer to the global QDF Context

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
   \return QDF_STATUS_SUCCESS - Scheduler was successfully initialized and
   is ready to be used.

   QDF_STATUS_E_INVAL - Invalid parameter passed to the scheduler Open
   function

   QDF_STATUS_E_FAILURE - Failure to initialize the scheduler/

   \sa cds_sched_close()

   ---------------------------------------------------------------------------*/
<<<<<<< HEAD
QDF_STATUS cds_sched_close(void *p_cds_context);

/* Helper routines provided to other CDS API's */
QDF_STATUS cds_mq_init(p_cds_mq_type pMq);
void cds_mq_deinit(p_cds_mq_type pMq);
void cds_mq_put(p_cds_mq_type pMq, p_cds_msg_wrapper pMsgWrapper);
void cds_mq_put_front(p_cds_mq_type mq, p_cds_msg_wrapper msg_wrapper);
p_cds_msg_wrapper cds_mq_get(p_cds_mq_type pMq);
bool cds_is_mq_empty(p_cds_mq_type pMq);
p_cds_sched_context get_cds_sched_ctxt(void);
QDF_STATUS cds_sched_init_mqs(p_cds_sched_context pSchedContext);
void cds_sched_deinit_mqs(p_cds_sched_context pSchedContext);
void cds_sched_flush_mc_mqs(p_cds_sched_context pSchedContext);
=======
QDF_STATUS cds_sched_close(void);

p_cds_sched_context get_cds_sched_ctxt(void);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

void qdf_timer_module_init(void);
void qdf_timer_module_deinit(void);
void cds_ssr_protect_init(void);
<<<<<<< HEAD
void cds_ssr_protect(const char *caller_func);
void cds_ssr_unprotect(const char *caller_func);
bool cds_wait_for_external_threads_completion(const char *caller_func);
void cds_print_external_threads(void);
int cds_get_gfp_flags(void);

/**
 * cds_return_external_threads_count() - return active external thread calls
 *
 * Return: total number of active extrenal threads in driver
 */
int cds_return_external_threads_count(void);

/**
=======
int cds_get_gfp_flags(void);

/**
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * cds_shutdown_notifier_register() - Register for shutdown notification
 * @cb          : Call back to be called
 * @priv        : Private pointer to be passed back to call back
 *
 * During driver remove or shutdown (recovery), external threads might be stuck
 * waiting on some event from firmware at lower layers. Remove or shutdown can't
 * proceed till the thread completes to avoid any race condition. Call backs can
 * be registered here to get early notification of remove or shutdown so that
 * waiting thread can be unblocked and hence remove or shutdown can proceed
 * further as waiting there may not make sense when FW may already have been
 * down.
 *
 * Return: CDS status
 */
QDF_STATUS cds_shutdown_notifier_register(void (*cb)(void *priv), void *priv);

/**
 * cds_shutdown_notifier_purge() - Purge all the notifiers
 *
 * Shutdown notifiers are added to provide the early notification of remove or
 * shutdown being initiated. Adding this API to purge all the registered call
 * backs as they are not useful any more while all the lower layers are being
 * shutdown.
 *
 * Return: None
 */
void cds_shutdown_notifier_purge(void);
<<<<<<< HEAD
=======

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/**
 * cds_shutdown_notifier_call() - Call shutdown notifier call back
 *
 * Call registered shutdown notifier call back to indicate about remove or
 * shutdown.
 */
void cds_shutdown_notifier_call(void);

/**
<<<<<<< HEAD
 * cds_remove_timer_from_sys_msg() - Flush timer message from sys msg queue
 * @timer_cookie: Unique cookie of the timer message to be flushed
 *
 * Find the timer message in the sys msg queue for the unique cookie
 * and flush the message from the queue.
 *
 * Return: None
 */
void cds_remove_timer_from_sys_msg(uint32_t timer_cookie);

#endif /* #if !defined __CDS_SCHED_H */
=======
 * cds_resume_rx_thread() - resume rx thread by completing its resume event
 *
 * Resume RX thread by completing RX thread resume event
 *
 * Return: None
 */
void cds_resume_rx_thread(void);

#ifdef WLAN_FEATURE_PKT_CAPTURE
/**
 * cds_resume_mon_thread() - resume mon thread by completing its resume event
 *
 * Resume MON thread by completing RX thread resume event
 *
 * Return: None
 */
void cds_resume_mon_thread(void);

/**
 * cds_drop_monpkt() - API to drop pending mon packets
 * @pschedcontext: Pointer to the global CDS Sched Context
 *
 * This api drops all the pending packets in the queue.
 *
 * Return: none
 */
void cds_drop_monpkt(p_cds_sched_context pschedcontext);

/**
 * cds_indicate_monpkt() - API to Indicate rx data packet
 * @pschedcontext: pointer to  CDS Sched Context
 * @pkt: CDS OL MON pkt pointer containing to mon data message buffer
 *
 * Return: none
 */
void cds_indicate_monpkt(p_cds_sched_context pschedcontext,
			 struct cds_ol_mon_pkt *pkt);

/**
 * cds_wakeup_mon_thread() - wakeup mon thread
 * @Arg: Pointer to the global CDS Sched Context
 *
 * This api wake up cds_ol_mon_thread() to process pkt
 *
 * Return: none
 */
void cds_wakeup_mon_thread(p_cds_sched_context pschedcontext);

/**
 * cds_close_mon_thread() - close the Tlshim MON thread
 *
 * This api closes the Tlshim MON thread:
 *
 * Return: qdf status
 */
QDF_STATUS cds_close_mon_thread(void);

/**
 * cds_open_mon_thread() - open the Tlshim MON thread
 * @pSchedContext: Pointer to the global CDS Sched Context
 *
 * This api opens the Tlshim MON thread:
 *
 * Return: qdf status
 */
QDF_STATUS cds_open_mon_thread(p_cds_sched_context pschedcontext);

/**
 * cds_alloc_mon_thread() - alloc resources for MON thread
 * @pSchedContext: Pointer to the global CDS Sched Context
 *
 * This api alloc resources for MON thread:
 *
 * Return: qdf status
 */
QDF_STATUS cds_alloc_mon_thread(p_cds_sched_context pschedcontext);

/**
 * cds_alloc_ol_mon_pkt() - API to return next available cds message
 * @pSchedContext: Pointer to the global CDS Sched Context
 *
 * This api returns next available cds message buffer used for mon data
 * processing
 *
 * Return: Pointer to cds message buffer
 */
struct cds_ol_mon_pkt *cds_alloc_ol_mon_pkt(p_cds_sched_context pschedcontext);

/**
 * cds_free_ol_mon_pkt() - api to release cds message to the freeq
 * This api returns the cds message used for mon data to the free queue
 * @pSchedContext: Pointer to the global CDS Sched Context
 * @pkt: CDS message buffer to be returned to free queue.
 *
 * Return: none
 */
void cds_free_ol_mon_pkt(p_cds_sched_context pschedcontext,
			 struct cds_ol_mon_pkt *pkt);

/**
 * cds_free_ol_mon_pkt_freeq() - free cds buffer free queue
 * @pSchedContext - pointer to the global CDS Sched Context
 *
 * This API does mem free of the buffers available in free cds buffer
 * queue which is used for mon Data processing.
 *
 * Return: none
 */
void cds_free_ol_mon_pkt_freeq(p_cds_sched_context pschedcontext);
#else
static inline
void cds_resume_mon_thread(void)
{
}

static inline
void cds_drop_monpkt(p_cds_sched_context pschedcontext)
{
}

static inline
void cds_indicate_monpkt(p_cds_sched_context pschedcontext,
			 struct cds_ol_mon_pkt *pkt)
{
}

static inline
void cds_wakeup_mon_thread(p_cds_sched_context pschedcontext)
{
}

static inline
QDF_STATUS cds_close_mon_thread(void)
{
	return QDF_STATUS_SUCCESS;
}

static inline
QDF_STATUS cds_open_mon_thread(p_cds_sched_context pschedcontext)
{
	return QDF_STATUS_SUCCESS;
}

static inline
QDF_STATUS cds_alloc_mon_thread(p_cds_sched_context pschedcontext)
{
	return QDF_STATUS_SUCCESS;
}

static inline
struct cds_ol_mon_pkt *cds_alloc_ol_mon_pkt(p_cds_sched_context pschedcontext)
{
	return NULL;
}

static inline
void cds_free_ol_mon_pkt(p_cds_sched_context pschedcontext,
			 struct cds_ol_mon_pkt *pkt)
{
}

static inline
void cds_free_ol_mon_pkt_freeq(p_cds_sched_context pschedcontext)
{
}
#endif /* WLAN_FEATURE_PKT_CAPTURE */
#endif /* #ifndef __CDS_SCHED_H */
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

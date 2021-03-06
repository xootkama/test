/*
<<<<<<< HEAD
 * Copyright (c) 2014-2019 The Linux Foundation. All rights reserved.
=======
 * Copyright (c) 2014-2020 The Linux Foundation. All rights reserved.
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

#if !defined(__CDS_API_H)
#define __CDS_API_H

/**
<<<<<<< HEAD
* DOC:  cds_api.h
*
* Connectivity driver services public API
*
*/
=======
 * DOC:  cds_api.h
 *
 * Connectivity driver services public API
 *
 */
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

#include <qdf_types.h>
#include <qdf_status.h>
#include <qdf_mem.h>
#include <qdf_debugfs.h>
#include <qdf_list.h>
#include <qdf_trace.h>
#include <qdf_event.h>
#include <qdf_lock.h>
<<<<<<< HEAD
#include <cds_reg_service.h>
#include <cds_mq.h>
=======
#include "qdf_platform.h"
#include "qdf_cpuhp.h"
#include <wlan_cmn.h>
#include "reg_services_public_struct.h"
#include <cds_reg_service.h>
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#include <cds_packet.h>
#include <cds_sched.h>
#include <qdf_threads.h>
#include <qdf_mc_timer.h>
<<<<<<< HEAD

/* Amount of time to wait for WMA to perform an asynchronous activity.
* This value should be larger than the timeout used by WMI to wait for
* a response from target
*/
#define CDS_WMA_TIMEOUT  (15000)

/**
* enum cds_driver_state - Driver state
* @CDS_DRIVER_STATE_UNINITIALIZED: Driver is in uninitialized state.
* CDS_DRIVER_STATE_LOADED: Driver is loaded and functional.
* CDS_DRIVER_STATE_LOADING: Driver probe is in progress.
* CDS_DRIVER_STATE_UNLOADING: Driver remove is in progress.
* CDS_DRIVER_STATE_RECOVERING: Recovery in progress.
* CDS_DRIVER_STATE_BAD: Driver in bad state.
* CDS_DRIVER_STATE_FW_READY:
* CDS_DRIVER_STATE_MODULE_STOPPING: Module stop in progress.
* CDS_DRIVER_STATE_THERMAL_STATE: Driver in thermal mitigated state
*/
enum cds_driver_state {
CDS_DRIVER_STATE_UNINITIALIZED	 = 0,
CDS_DRIVER_STATE_LOADED		 = BIT(0),
CDS_DRIVER_STATE_LOADING	 = BIT(1),
CDS_DRIVER_STATE_UNLOADING	 = BIT(2),
CDS_DRIVER_STATE_RECOVERING	 = BIT(3),
CDS_DRIVER_STATE_BAD		 = BIT(4),
CDS_DRIVER_STATE_FW_READY	 = BIT(5),
CDS_DRIVER_STATE_MODULE_STOPPING = BIT(6),
CDS_DRIVER_STATE_THERMAL_STATE	 = BIT(7),
};

#define __CDS_IS_DRIVER_STATE(_state, _mask) (((_state) & (_mask)) == (_mask))

/**
* enum cds_fw_state - Firmware state
* @CDS_FW_STATE_UNINITIALIZED: Firmware is in uninitialized state.
*/
enum cds_fw_state {
CDS_FW_STATE_UNINITIALIZED = 0,
};

#define __CDS_IS_FW_STATE(_state, _mask) (((_state) & (_mask)) == (_mask))

/**
* struct cds_sme_cbacks - list of sme functions registered with
* CDS
* @sme_get_valid_channels: gets the valid channel list for current reg domain
* @sme_get_nss_for_vdev: gets the nss allowed for the vdev type
*/
struct cds_sme_cbacks {
QDF_STATUS(*sme_get_valid_channels)(void*, uint16_t,
	uint8_t *, uint32_t *);
void (*sme_get_nss_for_vdev)(void*, enum tQDF_ADAPTER_MODE,
	uint8_t *, uint8_t *);
};

/**
* struct cds_dp_cbacks - list of datapath functions registered with CDS
* @ol_txrx_update_mac_id_cb: updates mac_id for vdev
* @hdd_en_lro_in_cc_cb: enables LRO if concurrency is not active
* @hdd_disble_lro_in_cc_cb: disables LRO due to concurrency
* @hdd_set_rx_mode_rps_cb: enable/disable RPS in SAP mode
*/
struct cds_dp_cbacks {
void (*ol_txrx_update_mac_id_cb)(uint8_t, uint8_t);
void (*hdd_en_lro_in_cc_cb)(struct hdd_context_s *);
void (*hdd_disble_lro_in_cc_cb)(struct hdd_context_s *);
void (*hdd_set_rx_mode_rps_cb)(struct hdd_context_s *, void *, bool);
void (*hdd_ipa_set_mcc_mode_cb)(bool);
};
=======
#include <wlan_objmgr_psoc_obj.h>
#include <cdp_txrx_handle.h>

/* Amount of time to wait for WMA to perform an asynchronous activity.
 * This value should be larger than the timeout used by WMI to wait for
 * a response from target
 */
#define CDS_WMA_TIMEOUT  (15000)

/**
 * enum cds_driver_state - Driver state
 * @CDS_DRIVER_STATE_UNINITIALIZED: Driver is in uninitialized state.
 * CDS_DRIVER_STATE_LOADED: Driver is loaded and functional.
 * CDS_DRIVER_STATE_LOADING: Driver probe is in progress.
 * CDS_DRIVER_STATE_UNLOADING: Driver remove is in progress.
 * CDS_DRIVER_STATE_RECOVERING: Recovery in progress.
 * CDS_DRIVER_STATE_BAD: Driver in bad state.
 * CDS_DRIVER_STATE_MODULE_STOPPING: Module stop in progress.
 */
enum cds_driver_state {
	CDS_DRIVER_STATE_UNINITIALIZED          = 0,
	CDS_DRIVER_STATE_LOADED                 = BIT(0),
	CDS_DRIVER_STATE_LOADING                = BIT(1),
	CDS_DRIVER_STATE_UNLOADING              = BIT(2),
	CDS_DRIVER_STATE_RECOVERING             = BIT(3),
	CDS_DRIVER_STATE_BAD                    = BIT(4),
	CDS_DRIVER_STATE_FW_READY               = BIT(5),
	CDS_DRIVER_STATE_MODULE_STOPPING        = BIT(6),
};

/**
 * struce cds_vdev_dp_stats - vdev stats populated from DP
 * @tx_retries: packet number of successfully transmitted after more
 *              than one retransmission attempt
 */
struct cds_vdev_dp_stats {
	uint32_t tx_retries;
};

#define __CDS_IS_DRIVER_STATE(_state, _mask) (((_state) & (_mask)) == (_mask))
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

void cds_set_driver_state(enum cds_driver_state);
void cds_clear_driver_state(enum cds_driver_state);
enum cds_driver_state cds_get_driver_state(void);

/**
<<<<<<< HEAD
* cds_set_fw_state() - Set current firmware state
* @state:	Firmware state to be set to.
*
* This API sets firmware state to state. This API only sets the state and
* doesn't clear states, please make sure to use cds_clear_firmware_state
* to clear any state if required.
*
* Return: None
*/
void cds_set_fw_state(enum cds_fw_state);

/**
* cds_clear_fw_state() - Clear current fw state
* @state:	Driver state to be cleared.
*
* This API clears fw state. This API only clears the state, please make
* sure to use cds_set_fw_state to set any new states.
*
* Return: None
*/
void cds_clear_fw_state(enum cds_fw_state);

/**
* cds_get_fw_state() - Get current firmware state
*
* This API returns current firmware state stored in global context.
*
* Return: Firmware state enum
*/
enum cds_fw_state cds_get_fw_state(void);

/**
* cds_is_driver_loading() - Is driver load in progress
*
* Return: true if driver is loading and false otherwise.
*/
static inline bool cds_is_driver_loading(void)
{
enum cds_driver_state state = cds_get_driver_state();

return __CDS_IS_DRIVER_STATE(state, CDS_DRIVER_STATE_LOADING);
}

/**
* cds_is_driver_unloading() - Is driver unload in progress
*
* Return: true if driver is unloading and false otherwise.
*/
static inline bool cds_is_driver_unloading(void)
{
enum cds_driver_state state = cds_get_driver_state();

return __CDS_IS_DRIVER_STATE(state, CDS_DRIVER_STATE_UNLOADING);
}

/**
* cds_is_driver_recovering() - Is recovery in progress
*
* Return: true if recovery in progress  and false otherwise.
*/
static inline bool cds_is_driver_recovering(void)
{
enum cds_driver_state state = cds_get_driver_state();

return __CDS_IS_DRIVER_STATE(state, CDS_DRIVER_STATE_RECOVERING);
}

/**
* cds_is_driver_in_bad_state() - is driver in bad state
*
* Return: true if driver is in bad state and false otherwise.
*/
static inline bool cds_is_driver_in_bad_state(void)
{
enum cds_driver_state state = cds_get_driver_state();

return __CDS_IS_DRIVER_STATE(state, CDS_DRIVER_STATE_BAD);
}

/**
* cds_is_load_or_unload_in_progress() - Is driver load OR unload in progress
*
* Return: true if driver is loading OR unloading and false otherwise.
*/
static inline bool cds_is_load_or_unload_in_progress(void)
{
enum cds_driver_state state = cds_get_driver_state();

return __CDS_IS_DRIVER_STATE(state, CDS_DRIVER_STATE_LOADING) ||
	__CDS_IS_DRIVER_STATE(state, CDS_DRIVER_STATE_UNLOADING);
}

/**
* cds_is_module_stop_in_progress() - Is module stopping
*
* Return: true if module stop is in progress.
*/
static inline bool cds_is_module_stop_in_progress(void)
{
enum cds_driver_state state = cds_get_driver_state();

return __CDS_IS_DRIVER_STATE(state, CDS_DRIVER_STATE_MODULE_STOPPING);
}

/**
* cds_is_module_state_transitioning() - Is module state transitioning
*
* Return: true if module stop is in progress.
*/
static inline int cds_is_module_state_transitioning(void)
{
if (cds_is_load_or_unload_in_progress() || cds_is_driver_recovering() ||
	cds_is_module_stop_in_progress()) {
	pr_info("%s: Load/Unload %d or recovery %d or module_stop %d is in progress",
		__func__, cds_is_load_or_unload_in_progress(),
			cds_is_driver_recovering(),
			cds_is_module_stop_in_progress());
	return true;
} else {
	return false;
}
}


/**
* cds_is_fw_down() - Is FW down or not
*
* Return: true if FW is down and false otherwise.
*/
static inline bool cds_is_fw_down(void)
{
	return pld_is_fw_down();
}

/**
* cds_is_target_ready() - Is target is in ready state
*
* Return: true if target is in ready state and false otherwise.
*/
=======
 * cds_is_driver_loading() - Is driver load in progress
 *
 * Return: true if driver is loading and false otherwise.
 */
static inline bool cds_is_driver_loading(void)
{
	enum cds_driver_state state = cds_get_driver_state();

	return __CDS_IS_DRIVER_STATE(state, CDS_DRIVER_STATE_LOADING);
}

/**
 * cds_is_driver_unloading() - Is driver unload in progress
 *
 * Return: true if driver is unloading and false otherwise.
 */
static inline bool cds_is_driver_unloading(void)
{
	enum cds_driver_state state = cds_get_driver_state();

	return __CDS_IS_DRIVER_STATE(state, CDS_DRIVER_STATE_UNLOADING);
}

/**
 * cds_is_driver_recovering() - Is recovery in progress
 *
 * Return: true if recovery in progress  and false otherwise.
 */
static inline bool cds_is_driver_recovering(void)
{
	enum cds_driver_state state = cds_get_driver_state();

	return __CDS_IS_DRIVER_STATE(state, CDS_DRIVER_STATE_RECOVERING);
}

/**
 * cds_is_driver_in_bad_state() - is driver in bad state
 *
 * Return: true if driver is in bad state and false otherwise.
 */
static inline bool cds_is_driver_in_bad_state(void)
{
	enum cds_driver_state state = cds_get_driver_state();

	return __CDS_IS_DRIVER_STATE(state, CDS_DRIVER_STATE_BAD);
}

/**
 * cds_is_load_or_unload_in_progress() - Is driver load OR unload in progress
 *
 * Return: true if driver is loading OR unloading and false otherwise.
 */
static inline bool cds_is_load_or_unload_in_progress(void)
{
	enum cds_driver_state state = cds_get_driver_state();

	return __CDS_IS_DRIVER_STATE(state, CDS_DRIVER_STATE_LOADING) ||
		__CDS_IS_DRIVER_STATE(state, CDS_DRIVER_STATE_UNLOADING);
}

/**
 * cds_is_target_ready() - Is target is in ready state
 *
 * Return: true if target is in ready state and false otherwise.
 */
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
static inline bool cds_is_target_ready(void)
{
	enum cds_driver_state state = cds_get_driver_state();

	return __CDS_IS_DRIVER_STATE(state, CDS_DRIVER_STATE_FW_READY);
}

/**
<<<<<<< HEAD
* cds_set_recovery_in_progress() - Set recovery in progress
* @value: value to set
*
* Return: none
*/
static inline void cds_set_recovery_in_progress(uint8_t value)
{
if (value)
	cds_set_driver_state(CDS_DRIVER_STATE_RECOVERING);
else
	cds_clear_driver_state(CDS_DRIVER_STATE_RECOVERING);
}

/**
* cds_set_driver_in_bad_state() - Set driver state
* @value: value to set
*
* Return: none
*/
static inline void cds_set_driver_in_bad_state(uint8_t value)
{
if (value)
	cds_set_driver_state(CDS_DRIVER_STATE_BAD);
else
	cds_clear_driver_state(CDS_DRIVER_STATE_BAD);
}

/**
* cds_set_target_ready() - Set target ready state
* @value: value to set
*
* Return: none
*/
static inline void cds_set_target_ready(uint8_t value)
{
if (value)
	cds_set_driver_state(CDS_DRIVER_STATE_FW_READY);
else
	cds_clear_driver_state(CDS_DRIVER_STATE_FW_READY);
}

/**
* cds_set_load_in_progress() - Set load in progress
* @value: value to set
*
* Return: none
*/
static inline void cds_set_load_in_progress(uint8_t value)
{
if (value)
	cds_set_driver_state(CDS_DRIVER_STATE_LOADING);
else
	cds_clear_driver_state(CDS_DRIVER_STATE_LOADING);
}

/**
* cds_set_driver_loaded() - Set load completed
* @value: value to set
*
* Return: none
*/
static inline void cds_set_driver_loaded(uint8_t value)
{
if (value)
	cds_set_driver_state(CDS_DRIVER_STATE_LOADED);
else
	cds_clear_driver_state(CDS_DRIVER_STATE_LOADED);
}

/**
* cds_set_unload_in_progress() - Set unload in progress
* @value: value to set
*
* Return: none
*/
static inline void cds_set_unload_in_progress(uint8_t value)
{
if (value)
	cds_set_driver_state(CDS_DRIVER_STATE_UNLOADING);
else
	cds_clear_driver_state(CDS_DRIVER_STATE_UNLOADING);
}

/**
* cds_set_module_stop_in_progress() - Setting module stop in progress
*
* @value: value to set
*
* Return: none
*/
static inline void cds_set_module_stop_in_progress(bool value)
{
if (value)
	cds_set_driver_state(CDS_DRIVER_STATE_MODULE_STOPPING);
else
	cds_clear_driver_state(CDS_DRIVER_STATE_MODULE_STOPPING);
}

/**
* cds_is_driver_loaded() - Is driver loaded
*
* Return: true if driver is loaded or false otherwise.
*/
static inline bool cds_is_driver_loaded(void)
{
enum cds_driver_state state = cds_get_driver_state();

return __CDS_IS_DRIVER_STATE(state, CDS_DRIVER_STATE_LOADED);
}

#ifdef FW_THERMAL_THROTTLE_SUPPORT
/**
 * cds_set_driver_thermal_mitigated() - Setting the flag to indicate that driver
 * is in thermal mitigation state.
 *
 * @value: A boolean value to indicate to set or reset
 *
 * Return: None
 */
static inline void cds_set_driver_thermal_mitigated(bool value)
{
	if (value)
		cds_set_driver_state(CDS_DRIVER_STATE_THERMAL_STATE);
	else
		cds_clear_driver_state(CDS_DRIVER_STATE_THERMAL_STATE);
}

/**
 * cds_is_driver_thermal_mitigated() - Check if driver is in power save state
 *
 * Return: True if in power save state, false otherwise
 */
static inline bool cds_is_driver_thermal_mitigated(void)
{
	enum cds_driver_state state = cds_get_driver_state();

	return __CDS_IS_DRIVER_STATE(state, CDS_DRIVER_STATE_THERMAL_STATE);
}
#else
static inline void cds_set_driver_thermal_mitigated(bool value)
{
}

static inline bool cds_is_driver_thermal_mitigated(void)
{
	return false;
}
#endif
v_CONTEXT_t cds_init(void);
void cds_deinit(void);

QDF_STATUS cds_pre_enable(v_CONTEXT_t cds_context);

QDF_STATUS cds_open(void);

QDF_STATUS cds_enable(v_CONTEXT_t cds_context);

QDF_STATUS cds_disable(v_CONTEXT_t cds_context);

QDF_STATUS cds_post_disable(void);

QDF_STATUS cds_close(v_CONTEXT_t cds_context);

void cds_core_return_msg(void *pVContext, p_cds_msg_wrapper pMsgWrapper);

void *cds_get_context(QDF_MODULE_ID moduleId);

v_CONTEXT_t cds_get_global_context(void);

QDF_STATUS cds_alloc_context(void *p_cds_context, QDF_MODULE_ID moduleID,
		     void **ppModuleContext, uint32_t size);

QDF_STATUS cds_free_context(void *p_cds_context, QDF_MODULE_ID moduleID,
		    void *pModuleContext);

QDF_STATUS cds_set_context(QDF_MODULE_ID module_id, void *context);

QDF_STATUS cds_get_vdev_types(enum tQDF_ADAPTER_MODE mode, uint32_t *type,
		      uint32_t *subType);

void cds_flush_work(void *work);
void cds_flush_delayed_work(void *dwork);

bool cds_is_packet_log_enabled(void);

uint64_t cds_get_monotonic_boottime(void);

/**
* cds_get_recovery_reason() - get self recovery reason
* @reason: cds hang reason
*
* Return: None
*/
void cds_get_recovery_reason(enum cds_hang_reason *reason);

/**
* cds_reset_recovery_reason() - reset the reason to unspecified
*
* Return: None
*/
void cds_reset_recovery_reason(void);

/**
* cds_trigger_recovery() - trigger self recovery
* @reason: recovery reason
*
* Return: none
*/
void cds_trigger_recovery(enum cds_hang_reason reason);
=======
 * cds_set_recovery_in_progress() - Set recovery in progress
 * @value: value to set
 *
 * Return: none
 */
static inline void cds_set_recovery_in_progress(uint8_t value)
{
	if (value)
		cds_set_driver_state(CDS_DRIVER_STATE_RECOVERING);
	else
		cds_clear_driver_state(CDS_DRIVER_STATE_RECOVERING);
}

/**
 * cds_set_driver_in_bad_state() - Set driver state
 * @value: value to set
 *
 * Return: none
 */
static inline void cds_set_driver_in_bad_state(uint8_t value)
{
	if (value)
		cds_set_driver_state(CDS_DRIVER_STATE_BAD);
	else
		cds_clear_driver_state(CDS_DRIVER_STATE_BAD);
}

/**
 * cds_set_target_ready() - Set target ready state
 * @value: value to set
 *
 * Return: none
 */
static inline void cds_set_target_ready(uint8_t value)
{
	if (value)
		cds_set_driver_state(CDS_DRIVER_STATE_FW_READY);
	else
		cds_clear_driver_state(CDS_DRIVER_STATE_FW_READY);
}

/**
 * cds_set_load_in_progress() - Set load in progress
 * @value: value to set
 *
 * Return: none
 */
static inline void cds_set_load_in_progress(uint8_t value)
{
	if (value)
		cds_set_driver_state(CDS_DRIVER_STATE_LOADING);
	else
		cds_clear_driver_state(CDS_DRIVER_STATE_LOADING);
}

/**
 * cds_set_driver_loaded() - Set load completed
 * @value: value to set
 *
 * Return: none
 */
static inline void cds_set_driver_loaded(uint8_t value)
{
	if (value)
		cds_set_driver_state(CDS_DRIVER_STATE_LOADED);
	else
		cds_clear_driver_state(CDS_DRIVER_STATE_LOADED);
}

/**
 * cds_set_unload_in_progress() - Set unload in progress
 * @value: value to set
 *
 * Return: none
 */
static inline void cds_set_unload_in_progress(uint8_t value)
{
	if (value)
		cds_set_driver_state(CDS_DRIVER_STATE_UNLOADING);
	else
		cds_clear_driver_state(CDS_DRIVER_STATE_UNLOADING);
}

/**
 * cds_set_module_stop_in_progress() - Setting module stop in progress
 *
 * @value: value to set
 *
 * Return: none
 */
static inline void cds_set_module_stop_in_progress(bool value)
{
	if (value)
		cds_set_driver_state(CDS_DRIVER_STATE_MODULE_STOPPING);
	else
		cds_clear_driver_state(CDS_DRIVER_STATE_MODULE_STOPPING);
}

/**
 * cds_is_driver_loaded() - Is driver loaded
 *
 * Return: true if driver is loaded or false otherwise.
 */
static inline bool cds_is_driver_loaded(void)
{
	enum cds_driver_state state = cds_get_driver_state();

	return __CDS_IS_DRIVER_STATE(state, CDS_DRIVER_STATE_LOADED);
}

/**
 * cds_init() - Initialize CDS
 *
 * This function allocates the resource required for CDS, but does not
 * initialize all the members. This overall initialization will happen at
 * cds_open().
 *
 * Return: QDF_STATUS_SUCCESS if CDS was initialized and an error on failure
 */
QDF_STATUS cds_init(void);

void cds_deinit(void);

QDF_STATUS cds_pre_enable(void);

QDF_STATUS cds_open(struct wlan_objmgr_psoc *psoc);

/**
 * cds_dp_open() - Open datapath module
 * @psoc - object manager soc handle
 *
 * API to map the datapath rings to interrupts
 * and also open the datapath pdev module.
 *
 * Return: QDF status
 */
QDF_STATUS cds_dp_open(struct wlan_objmgr_psoc *psoc);

/**
 * cds_enable() - start/enable cds module
 * @psoc: Psoc pointer
 *
 * Return: QDF status
 */
QDF_STATUS cds_enable(struct wlan_objmgr_psoc *psoc);

QDF_STATUS cds_disable(struct wlan_objmgr_psoc *psoc);

QDF_STATUS cds_post_disable(void);

QDF_STATUS cds_close(struct wlan_objmgr_psoc *psoc);

/**
 * cds_dp_close() - Close datapath module
 * @psoc: Object manager soc handle
 *
 * API used to detach interrupts assigned to service
 * datapath rings and close pdev module
 *
 * Return: Status
 */
QDF_STATUS cds_dp_close(struct wlan_objmgr_psoc *psoc);

void *cds_get_context(QDF_MODULE_ID module_id);

void *cds_get_global_context(void);

QDF_STATUS cds_alloc_context(QDF_MODULE_ID module_id, void **module_context,
			     uint32_t size);

QDF_STATUS cds_free_context(QDF_MODULE_ID module_id, void *module_context);

QDF_STATUS cds_set_context(QDF_MODULE_ID module_id, void *context);

void cds_flush_work(void *work);
void cds_flush_delayed_work(void *dwork);

#ifdef REMOVE_PKT_LOG
static inline
bool cds_is_packet_log_enabled(void)
{
	return false;
}
#else
bool cds_is_packet_log_enabled(void);
#endif

/**
 * cds_get_recovery_reason() - get self recovery reason
 * @reason: cds hang reason
 *
 * Return: None
 */
void cds_get_recovery_reason(enum qdf_hang_reason *reason);

/**
 * cds_reset_recovery_reason() - reset the reason to unspecified
 *
 * Return: None
 */
void cds_reset_recovery_reason(void);

/**
 * cds_trigger_recovery() - trigger self recovery
 * @reason: recovery reason
 *
 * Return: none
 */
#define cds_trigger_recovery(reason) \
	__cds_trigger_recovery(reason, __func__, __LINE__)

void cds_trigger_recovery_psoc(void *psoc, enum qdf_hang_reason reason,
			       const char *func, const uint32_t line);

void __cds_trigger_recovery(enum qdf_hang_reason reason, const char *func,
			    const uint32_t line);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

void cds_set_wakelock_logging(bool value);
bool cds_is_wakelock_enabled(void);
void cds_set_ring_log_level(uint32_t ring_id, uint32_t log_level);
enum wifi_driver_log_level cds_get_ring_log_level(uint32_t ring_id);
void cds_set_multicast_logging(uint8_t value);
uint8_t cds_is_multicast_logging(void);
QDF_STATUS cds_set_log_completion(uint32_t is_fatal,
<<<<<<< HEAD
	uint32_t type,
	uint32_t sub_type,
	bool recovery_needed);
void cds_get_and_reset_log_completion(uint32_t *is_fatal,
	uint32_t *type,
	uint32_t *sub_type,
	bool *recovery_needed);
=======
		uint32_t type,
		uint32_t sub_type,
		bool recovery_needed);
void cds_get_and_reset_log_completion(uint32_t *is_fatal,
		uint32_t *type,
		uint32_t *sub_type,
		bool *recovery_needed);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
bool cds_is_log_report_in_progress(void);
bool cds_is_fatal_event_enabled(void);

#ifdef WLAN_FEATURE_TSF_PLUS
bool cds_is_ptp_rx_opt_enabled(void);
bool cds_is_ptp_tx_opt_enabled(void);
#else
static inline bool cds_is_ptp_rx_opt_enabled(void)
{
<<<<<<< HEAD
return false;
=======
	return false;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

static inline bool cds_is_ptp_tx_opt_enabled(void)
{
<<<<<<< HEAD
return false;
=======
	return false;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}
#endif

uint32_t cds_get_log_indicator(void);
void cds_set_fatal_event(bool value);
void cds_wlan_flush_host_logs_for_fatal(void);

void cds_init_log_completion(void);
QDF_STATUS cds_flush_logs(uint32_t is_fatal,
<<<<<<< HEAD
	uint32_t indicator,
	uint32_t reason_code,
	bool dump_mac_trace,
	bool recovery_needed);
=======
		uint32_t indicator,
		uint32_t reason_code,
		bool dump_mac_trace,
		bool recovery_needed);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
void cds_logging_set_fw_flush_complete(void);
void cds_svc_fw_shutdown_ind(struct device *dev);
#ifdef FEATURE_WLAN_DIAG_SUPPORT
void cds_tdls_tx_rx_mgmt_event(uint8_t event_id, uint8_t tx_rx,
<<<<<<< HEAD
		uint8_t type, uint8_t sub_type, uint8_t *peer_mac);
#else
static inline
void cds_tdls_tx_rx_mgmt_event(uint8_t event_id, uint8_t tx_rx,
		uint8_t type, uint8_t sub_type, uint8_t *peer_mac)
=======
			uint8_t type, uint8_t sub_type, uint8_t *peer_mac);
#else
static inline
void cds_tdls_tx_rx_mgmt_event(uint8_t event_id, uint8_t tx_rx,
			uint8_t type, uint8_t sub_type, uint8_t *peer_mac)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

{
}
#endif /* FEATURE_WLAN_DIAG_SUPPORT */

int cds_get_radio_index(void);
QDF_STATUS cds_set_radio_index(int radio_index);
void cds_init_ini_config(struct cds_config_info *cds_cfg);
void cds_deinit_ini_config(void);
struct cds_config_info *cds_get_ini_config(void);

bool cds_is_5_mhz_enabled(void);
bool cds_is_10_mhz_enabled(void);
bool cds_is_sub_20_mhz_enabled(void);
bool cds_is_self_recovery_enabled(void);
<<<<<<< HEAD
void cds_pkt_stats_to_logger_thread(void *pl_hdr, void *pkt_dump, void *data);
QDF_STATUS cds_register_dp_cb(struct cds_dp_cbacks *dp_cbs);
QDF_STATUS cds_deregister_dp_cb(void);
=======
bool cds_is_fw_down(void);
enum QDF_GLOBAL_MODE cds_get_conparam(void);

#ifdef WLAN_LOGGING_SOCK_SVC_ENABLE
void cds_pkt_stats_to_logger_thread(void *pl_hdr, void *pkt_dump, void *data);
#else
static inline
void cds_pkt_stats_to_logger_thread(void *pl_hdr, void *pkt_dump, void *data)
{
}
#endif

#ifdef FEATURE_HTC_CREDIT_HISTORY
/**
 * cds_print_htc_credit_history() - Helper function to copy HTC credit
 *				    history via htc_print_credit_history()
 *
 * @count:	Number of lines to be copied
 * @print:	Print callback to print in the buffer
 *
 * Return:	none
 */
void cds_print_htc_credit_history(uint32_t count,
				qdf_abstract_print * print,
				void *print_priv);
#else

static inline
void cds_print_htc_credit_history(uint32_t count,
				qdf_abstract_print *print,
				void *print_priv)
{
}
#endif
/**
 * cds_is_group_addr() - checks whether addr is multi cast
 * @mac_addr: address to be checked for multicast
 *
 * Check if the input mac addr is multicast addr
 *
 * Return: true if multicast addr else false
 */
static inline
bool cds_is_group_addr(uint8_t *mac_addr)
{
	if (mac_addr[0] & 0x01)
		return true;
	else
		return false;
}
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * cds_get_arp_stats_gw_ip() - get arp stats track IP
 * @context: osif dev
 *
 * Return: ARP stats IP to track.
 */
uint32_t cds_get_arp_stats_gw_ip(void *context);
/**
 * cds_get_connectivity_stats_pkt_bitmap() - get pkt-type bitmap
 * @context: osif dev context
 *
 * Return: pkt bitmap to track
 */
uint32_t cds_get_connectivity_stats_pkt_bitmap(void *context);
void cds_incr_arp_stats_tx_tgt_delivered(void);
void cds_incr_arp_stats_tx_tgt_acked(void);

<<<<<<< HEAD
#ifdef WMI_INTERFACE_EVENT_LOGGING
void cds_print_htc_credit_history(uint32_t count, qdf_abstract_print * print,
				  void *print_priv);
=======
#ifdef FEATURE_ALIGN_STATS_FROM_DP
/**
 * cds_dp_get_vdev_stats() - get vdev stats from DP
 * @vdev_id: vdev id
 * @stats: structure of counters which CP is interested in
 *
 * Return: if get vdev stats from DP success, return true otherwise false
 */
bool cds_dp_get_vdev_stats(uint8_t vdev_id, struct cds_vdev_dp_stats *stats);
#else
static inline bool
cds_dp_get_vdev_stats(uint8_t vdev_id, struct cds_vdev_dp_stats *stats)
{
	return false;
}
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#endif

/**
 * cds_smmu_mem_map_setup() - Check SMMU S1 stage enable
 *                            status and setup wlan driver
 * @osdev: Parent device instance
 * @ipa_present: IPA HW support flag
 *
 * This API checks if SMMU S1 translation is enabled in
 * platform driver or not and sets it accordingly in driver.
 *
 * Return: QDF_STATUS
 */
QDF_STATUS cds_smmu_mem_map_setup(qdf_device_t osdev, bool ipa_present);

/**
 * cds_smmu_map_unmap() - Map / Unmap DMA buffer to IPA UC
 * @map: Map / unmap operation
 * @num_buf: Number of buffers in array
 * @buf_arr: Buffer array of DMA mem mapping info
 *
 * This API maps/unmaps WLAN-IPA buffers if SMMU S1 translation
 * is enabled.
 *
 * Return: Status of map operation
 */
int cds_smmu_map_unmap(bool map, uint32_t num_buf, qdf_mem_info_t *buf_arr);

<<<<<<< HEAD
/**
 * cds_get_mcc_to_scc_switch_mode() - get mcc to scc swith mode
 *
 * Get the mcc to scc swith mode from ini
 *
 * Return: current mcc to scc swith mode
 */
uint32_t cds_get_mcc_to_scc_switch_mode(void);

/**
 * cds_is_sta_sap_scc_allowed_on_dfs_channel() - get the status sta, sap scc on
 * dfs channel
 *
 * Get the status of sta, sap scc on dfs channel
 *
 * Return: true if sta, sap scc is allowed on dfs channel otherwise false
 */
bool cds_is_sta_sap_scc_allowed_on_dfs_channel(void);
/**
 * cds_register_mode_change_cb() - Register mode change callback with CDS
 * @callback: HDD callback to be registered
 *
 * Return: QDF_STATUS
 */
QDF_STATUS cds_register_mode_change_cb(send_mode_change_event_cb callback);
/**
 * cds_deregister_mode_change_cb() - Deregister mode change callback with CDS
 *
 * Return: QDF_STATUS
 */
QDF_STATUS cds_deregister_mode_change_cb(void);

/**
 * cds_get_pktcap_mode_enable() - get pktcap mode enable/disable
 *
 * Get the pktcap mode enable/disable from ini
 *
 * Return: 0 - disable, 1 - enable
 */
bool cds_get_pktcap_mode_enable(void);
=======
#ifdef WLAN_FEATURE_PKT_CAPTURE
/**
 * cds_is_pktcapture_enabled() - is packet capture support enabled
 *
 * Check is packet capture mode enabled from ini
 *
 * Return: 0 - disable, 1 - enable
 */
bool cds_is_pktcapture_enabled(void);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/**
 * cds_get_pktcapture_mode() - get pktcapture mode value
 *
 * Get the pktcapture mode value from hdd context
 *
 * Return: 0 - disable
 *         1 - Mgmt packets
 *         2 - Data packets
 *         3 - Both Mgmt and Data packets
 */
uint8_t cds_get_pktcapture_mode(void);
<<<<<<< HEAD
=======
#else
static inline
bool cds_is_pktcapture_enabled(void)
{
	return false;
}

static inline
uint8_t cds_get_pktcapture_mode(void)
{
	return 0;
}
#endif /* WLAN_FEATURE_PKT_CAPTURE */

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#endif /* if !defined __CDS_API_H */

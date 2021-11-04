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

/*===========================================================================

			s a p C h S e l e c t . C
   OVERVIEW:

   This software unit holds the implementation of the WLAN SAP modules
   functions for channel selection.

   DEPENDENCIES:

   Are listed for each API below.
   ===========================================================================*/

/*--------------------------------------------------------------------------
   Include Files
   ------------------------------------------------------------------------*/
#include "qdf_trace.h"
#include "csr_api.h"
#include "sme_api.h"
#include "sap_ch_select.h"
#include "sap_internal.h"
#ifdef ANI_OS_TYPE_QNX
#include "stdio.h"
#endif
#ifdef FEATURE_AP_MCC_CH_AVOIDANCE
#include "lim_utils.h"
#include "parser_api.h"
<<<<<<< HEAD
#endif /* FEATURE_AP_MCC_CH_AVOIDANCE */
#include "cds_utils.h"
#include "pld_common.h"
#include "cds_concurrency.h"
=======
#include <wlan_utility.h>
#endif /* FEATURE_AP_MCC_CH_AVOIDANCE */
#include "cds_utils.h"
#include "pld_common.h"
#include "wlan_reg_services_api.h"
#include <wlan_scan_utils_api.h>
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

/*--------------------------------------------------------------------------
   Function definitions
   --------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------
   Defines
   --------------------------------------------------------------------------*/
#define SAP_DEBUG

#define IS_RSSI_VALID(extRssi, rssi) \
	( \
		((extRssi < rssi) ? true : false) \
	)

<<<<<<< HEAD
#define SET_ACS_BAND(acs_band, pSapCtx) \
{ \
	if (pSapCtx->acs_cfg->start_ch <= 14 && \
		pSapCtx->acs_cfg->end_ch <= 14) \
		acs_band = eCSR_DOT11_MODE_11g; \
	else if (pSapCtx->acs_cfg->start_ch >= 14)\
=======
#define SET_ACS_BAND(acs_band, sap_ctx) \
{ \
	if (sap_ctx->acs_cfg->start_ch_freq <= \
	    WLAN_REG_CH_TO_FREQ(CHAN_ENUM_2484) && \
	    sap_ctx->acs_cfg->end_ch_freq <= \
			WLAN_REG_CH_TO_FREQ(CHAN_ENUM_2484)) \
		acs_band = eCSR_DOT11_MODE_11g; \
	else if (sap_ctx->acs_cfg->start_ch_freq >= \
		 WLAN_REG_CH_TO_FREQ(CHAN_ENUM_2484))\
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		acs_band = eCSR_DOT11_MODE_11a; \
	else \
		acs_band = eCSR_DOT11_MODE_abg; \
}

<<<<<<< HEAD
#define GET_IE_LEN_IN_BSS_DESC(lenInBss) (lenInBss + sizeof(lenInBss) - \
			((uintptr_t)OFFSET_OF(tSirBssDescription, ieFields)))

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#define ACS_WEIGHT_AMOUNT_LOCAL    240

#define ACS_WEIGHT_AMOUNT_CONFIG(weights) \
	(((weights) & 0xf) + \
	(((weights) & 0xf0) >> 4) + \
	(((weights) & 0xf00) >> 8) + \
	(((weights) & 0xf000) >> 12) + \
	(((weights) & 0xf0000) >> 16) + \
	(((weights) & 0xf00000) >> 20))

/*
 * LSH/RSH 4 to enhance the accurate since
 * need to do modulation to ACS_WEIGHT_AMOUNT_LOCAL.
 */
#define ACS_WEIGHT_COMPUTE(weights, weight, factor, base) \
	(((((((((weight) << 4) * ACS_WEIGHT_AMOUNT_LOCAL * (factor)) + \
	(ACS_WEIGHT_AMOUNT_CONFIG((weights)) >> 1)) / \
	ACS_WEIGHT_AMOUNT_CONFIG((weights))) + \
	((base) >> 1)) / (base)) + 8) >> 4)

#define ACS_WEIGHT_CFG_TO_LOCAL(weights, weight) \
	(((((((weight) << 4) * ACS_WEIGHT_AMOUNT_LOCAL) + \
	(ACS_WEIGHT_AMOUNT_CONFIG((weights)) >> 1)) / \
	ACS_WEIGHT_AMOUNT_CONFIG((weights))) + 8) >> 4)

#define ACS_WEIGHT_SOFTAP_RSSI_CFG(weights) \
	((weights) & 0xf)

#define ACS_WEIGHT_SOFTAP_COUNT_CFG(weights) \
	(((weights) & 0xf0) >> 4)

#define ACS_WEIGHT_SOFTAP_NOISE_FLOOR_CFG(weights) \
	(((weights) & 0xf00) >> 8)

#define ACS_WEIGHT_SOFTAP_CHANNEL_FREE_CFG(weights) \
	(((weights) & 0xf000) >> 12)

#define ACS_WEIGHT_SOFTAP_TX_POWER_RANGE_CFG(weights) \
	(((weights) & 0xf0000) >> 16)

#define ACS_WEIGHT_SOFTAP_TX_POWER_THROUGHPUT_CFG(weights) \
	(((weights) & 0xf00000) >> 20)

typedef struct {
	uint16_t chStartNum;
	uint32_t weight;
} sapAcsChannelInfo;

sapAcsChannelInfo acs_ht40_channels5_g[] = {
	{36, SAP_ACS_WEIGHT_MAX},
	{44, SAP_ACS_WEIGHT_MAX},
	{52, SAP_ACS_WEIGHT_MAX},
	{60, SAP_ACS_WEIGHT_MAX},
	{100, SAP_ACS_WEIGHT_MAX},
	{108, SAP_ACS_WEIGHT_MAX},
	{116, SAP_ACS_WEIGHT_MAX},
	{124, SAP_ACS_WEIGHT_MAX},
	{132, SAP_ACS_WEIGHT_MAX},
	{140, SAP_ACS_WEIGHT_MAX},
	{149, SAP_ACS_WEIGHT_MAX},
	{157, SAP_ACS_WEIGHT_MAX},
};

sapAcsChannelInfo acs_ht80_channels[] = {
	{36, SAP_ACS_WEIGHT_MAX},
	{52, SAP_ACS_WEIGHT_MAX},
	{100, SAP_ACS_WEIGHT_MAX},
	{116, SAP_ACS_WEIGHT_MAX},
	{132, SAP_ACS_WEIGHT_MAX},
	{149, SAP_ACS_WEIGHT_MAX},
};

sapAcsChannelInfo acs_vht160_channels[] = {
	{36, SAP_ACS_WEIGHT_MAX},
	{100, SAP_ACS_WEIGHT_MAX},
};

sapAcsChannelInfo acs_ht40_channels24_g[] = {
	{1, SAP_ACS_WEIGHT_MAX},
	{2, SAP_ACS_WEIGHT_MAX},
	{3, SAP_ACS_WEIGHT_MAX},
	{4, SAP_ACS_WEIGHT_MAX},
	{9, SAP_ACS_WEIGHT_MAX},
};

#define CHANNEL_165  165

/* rssi discount for channels in PCL */
#define PCL_RSSI_DISCOUNT 10

#ifdef FEATURE_AP_MCC_CH_AVOIDANCE
/**
 * sap_check_n_add_channel() - checks and add given channel in sap context's
 * avoid_channels_info struct
 * @sap_ctx:           sap context.
 * @new_channel:       channel to be added to sap_ctx's avoid ch info
 *
 * sap_ctx contains sap_avoid_ch_info strcut containing the list of channels on
 * which MDM device's AP with MCC was detected. This function will add channels
 * to that list after checking for duplicates.
 *
 * Return: true: if channel was added or already present
 *   else false: if channel list was already full.
 */
static bool
<<<<<<< HEAD
sap_check_n_add_channel(ptSapContext sap_ctx,
=======
sap_check_n_add_channel(struct sap_context *sap_ctx,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			uint8_t new_channel)
{
	uint8_t i = 0;
	struct sap_avoid_channels_info *ie_info =
		&sap_ctx->sap_detected_avoid_ch_ie;

	for (i = 0; i < sizeof(ie_info->channels); i++) {
		if (ie_info->channels[i] == new_channel)
			break;

		if (ie_info->channels[i] == 0) {
			ie_info->channels[i] = new_channel;
			break;
		}
	}
	if (i == sizeof(ie_info->channels))
		return false;
	else
		return true;
}
/**
 * sap_check_n_add_overlapped_chnls() - checks & add overlapped channels
 *                                      to primary channel in 2.4Ghz band.
 * @sap_ctx:           sap context.
 * @primary_chnl:      primary channel to be avoided.
 *
 * sap_ctx contains sap_avoid_ch_info struct containing the list of channels on
 * which MDM device's AP with MCC was detected. This function will add channels
 * to that list after checking for duplicates.
 *
 * Return: true: if channel was added or already present
 *   else false: if channel list was already full.
 */
static bool
<<<<<<< HEAD
sap_check_n_add_overlapped_chnls(ptSapContext sap_ctx, uint8_t primary_channel)
=======
sap_check_n_add_overlapped_chnls(struct sap_context *sap_ctx,
				 uint8_t primary_channel)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	uint8_t i = 0, j = 0, upper_chnl = 0, lower_chnl = 0;
	struct sap_avoid_channels_info *ie_info =
		&sap_ctx->sap_detected_avoid_ch_ie;
	/*
	 * if primary channel less than channel 1 or out of 2g band then
	 * no further process is required. return true in this case.
	 */
	if (primary_channel < CHANNEL_1 || primary_channel > CHANNEL_14)
		return true;

	/* lower channel is one channel right before primary channel */
	lower_chnl = primary_channel - 1;
	/* upper channel is one channel right after primary channel */
	upper_chnl = primary_channel + 1;

	/* lower channel needs to be non-zero, zero is not valid channel */
	if (lower_chnl > (CHANNEL_1 - 1)) {
		for (i = 0; i < sizeof(ie_info->channels); i++) {
			if (ie_info->channels[i] == lower_chnl)
				break;
			if (ie_info->channels[i] == 0) {
				ie_info->channels[i] = lower_chnl;
				break;
			}
		}
	}
	/* upper channel needs to be atleast last channel in 2.4Ghz band */
	if (upper_chnl < (CHANNEL_14 + 1)) {
		for (j = 0; j < sizeof(ie_info->channels); j++) {
			if (ie_info->channels[j] == upper_chnl)
				break;
			if (ie_info->channels[j] == 0) {
				ie_info->channels[j] = upper_chnl;
				break;
			}
		}
	}
	if (i == sizeof(ie_info->channels) || j == sizeof(ie_info->channels))
		return false;
	else
		return true;
}

/**
 * sap_process_avoid_ie() - processes the detected Q2Q IE
 * context's avoid_channels_info struct
<<<<<<< HEAD
 * @hal:                hal handle
=======
 * @mac_handle:         opaque handle to the MAC context
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @sap_ctx:            sap context.
 * @scan_result:        scan results for ACS scan.
 * @spect_info:         spectrum weights array to update
 *
 * Detection of Q2Q IE indicates presence of another MDM device with its AP
 * operating in MCC mode. This function parses the scan results and processes
 * the Q2Q IE if found. It then extracts the channels and populates them in
 * sap_ctx struct. It also increases the weights of those channels so that
 * ACS logic will avoid those channels in its selection algorithm.
 *
 * Return: void
 */
<<<<<<< HEAD
static void sap_process_avoid_ie(tHalHandle hal,
			  ptSapContext sap_ctx,
			  tScanResultHandle scan_result,
			  tSapChSelSpectInfo *spect_info)
{
	uint32_t total_ie_len = 0;
	uint8_t *temp_ptr = NULL;
	uint8_t i = 0;
	struct sAvoidChannelIE *avoid_ch_ie;
	tCsrScanResultInfo *node = NULL;
	tpAniSirGlobal mac_ctx = NULL;
	tSapSpectChInfo *spect_ch = NULL;

	mac_ctx = PMAC_STRUCT(hal);
	spect_ch = spect_info->pSpectCh;
	node = sme_scan_result_get_first(hal, scan_result);

	while (node) {
		total_ie_len =
			GET_IE_LEN_IN_BSS_DESC(node->BssDescriptor.length);
		temp_ptr = cfg_get_vendor_ie_ptr_from_oui(mac_ctx,
				SIR_MAC_QCOM_VENDOR_OUI,
				SIR_MAC_QCOM_VENDOR_SIZE,
				((uint8_t *)&node->BssDescriptor.ieFields),
				total_ie_len);
=======
static void
sap_process_avoid_ie(mac_handle_t mac_handle, struct sap_context *sap_ctx,
		     qdf_list_t *scan_list, tSapChSelSpectInfo *spect_info)
{
	const uint8_t *temp_ptr = NULL;
	uint8_t i = 0;
	struct sAvoidChannelIE *avoid_ch_ie;
	struct mac_context *mac_ctx = NULL;
	tSapSpectChInfo *spect_ch = NULL;
	qdf_list_node_t *cur_lst = NULL, *next_lst = NULL;
	struct scan_cache_node *cur_node = NULL;
	uint32_t chan_freq;

	mac_ctx = MAC_CONTEXT(mac_handle);
	spect_ch = spect_info->pSpectCh;

	if (scan_list)
		qdf_list_peek_front(scan_list, &cur_lst);

	while (cur_lst) {
		cur_node = qdf_container_of(cur_lst, struct scan_cache_node,
					    node);

		temp_ptr = wlan_get_vendor_ie_ptr_from_oui(
				SIR_MAC_QCOM_VENDOR_OUI,
				SIR_MAC_QCOM_VENDOR_SIZE,
				util_scan_entry_ie_data(cur_node->entry),
				util_scan_entry_ie_len(cur_node->entry));
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

		if (temp_ptr) {
			avoid_ch_ie = (struct sAvoidChannelIE *)temp_ptr;
			if (avoid_ch_ie->type !=
					QCOM_VENDOR_IE_MCC_AVOID_CH) {
<<<<<<< HEAD
				node = sme_scan_result_get_next(hal,
					scan_result);
=======
				qdf_list_peek_next(scan_list,
						   cur_lst, &next_lst);
				cur_lst = next_lst;
				next_lst = NULL;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				continue;
			}

			sap_ctx->sap_detected_avoid_ch_ie.present = 1;
<<<<<<< HEAD
			QDF_TRACE(QDF_MODULE_ID_SAP,
				  QDF_TRACE_LEVEL_DEBUG,
				  "Q2Q IE - avoid ch %d",
				  avoid_ch_ie->channel);
			/* add this channel to to_avoid channel list */
			sap_check_n_add_channel(sap_ctx,
					avoid_ch_ie->channel);
			sap_check_n_add_overlapped_chnls(sap_ctx,
					avoid_ch_ie->channel);
=======

			chan_freq =
			    wlan_reg_legacy_chan_to_freq(mac_ctx->pdev,
							 avoid_ch_ie->channel);

			sap_debug("Q2Q-IE avoid freq = %d", chan_freq);
			/* add this channel to to_avoid channel list */
			sap_check_n_add_channel(sap_ctx, avoid_ch_ie->channel);
			sap_check_n_add_overlapped_chnls(sap_ctx,
							 avoid_ch_ie->channel);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			/*
			 * Mark weight of these channel present in IE to MAX
			 * so that ACS logic will to avoid thse channels
			 */
<<<<<<< HEAD
			for (i = 0; i < spect_info->numSpectChans; i++)
				if (spect_ch[i].chNum == avoid_ch_ie->channel) {
					/*
					 * weight is set more than max so that,
					 * in the case of other channels being
					 * assigned max weight due to noise,
					 * they may be preferred over channels
					 * with Q2Q IE.
					 */
					spect_ch[i].weight = SAP_ACS_WEIGHT_MAX + 1;
					spect_ch[i].weight_copy =
						SAP_ACS_WEIGHT_MAX + 1;
					break;
				}
		} /* if (temp_ptr) */
		node = sme_scan_result_get_next(hal, scan_result);
	}
}
#endif /* FEATURE_AP_MCC_CH_AVOIDANCE */

/*==========================================================================
   FUNCTION    sap_cleanup_channel_list

   DESCRIPTION
    Function sap_cleanup_channel_list frees up the memory allocated to the channel list.

   DEPENDENCIES
    NA.

   PARAMETERS

    IN
    NULL

   RETURN VALUE
    NULL
   ============================================================================*/

void sap_cleanup_channel_list(void *p_cds_gctx)
{
	ptSapContext pSapCtx;

	QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_DEBUG,
		  "Cleaning up the channel list structure");

	if (NULL == p_cds_gctx) {
		QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_FATAL,
			  "SAP Global Context is NULL");
		return;
	}

	pSapCtx = CDS_GET_SAP_CB(p_cds_gctx);
	if (NULL == pSapCtx) {
		QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_FATAL,
			  "SAP Context is NULL");
		return;
	}

	pSapCtx->SapChnlList.numChannel = 0;
	if (pSapCtx->SapChnlList.channelList) {
		qdf_mem_free(pSapCtx->SapChnlList.channelList);
		pSapCtx->SapChnlList.channelList = NULL;
	}

	pSapCtx->SapAllChnlList.numChannel = 0;
	if (pSapCtx->SapAllChnlList.channelList) {
		qdf_mem_free(pSapCtx->SapAllChnlList.channelList);
		pSapCtx->SapAllChnlList.channelList = NULL;
	}
}

/**
 * sap_channel_in_acs_channel_list() - check if channel in acs channel list
 * @channel_num: channel to check
 * @sap_ctx: struct ptSapContext
 * @spect_info_params: strcut tSapChSelSpectInfo
 *
 * This function checks if specified channel is in the configured ACS channel
 * list.
 *
 * Return: channel number if in acs channel list or SAP_CHANNEL_NOT_SELECTED
 */
uint8_t sap_channel_in_acs_channel_list(uint8_t channel_num,
					ptSapContext sap_ctx,
					tSapChSelSpectInfo *spect_info_params)
{
	uint8_t i = 0;

	if ((NULL == sap_ctx->acs_cfg->ch_list) ||
	    (NULL == spect_info_params))
		return channel_num;

	if (channel_num > 0 && channel_num <= 252) {
		for (i = 0; i < sap_ctx->acs_cfg->ch_list_count; i++) {
			if ((sap_ctx->acs_cfg->ch_list[i]) == channel_num)
				return channel_num;
		}
		return SAP_CHANNEL_NOT_SELECTED;
	} else {
		return SAP_CHANNEL_NOT_SELECTED;
	}
}

/**
 * sap_select_preferred_channel_from_channel_list() - to calc best cahnnel
 * @best_chnl: best channel already calculated among all the chanels
=======
			for (i = 0; i < spect_info->numSpectChans; i++) {
				if (spect_ch[i].chan_freq != chan_freq)
					continue;
				/*
				 * weight is set more than max so that,
				 * in the case of other channels being
				 * assigned max weight due to noise,
				 * they may be preferred over channels
				 * with Q2Q IE.
				 */
				spect_ch[i].weight = SAP_ACS_WEIGHT_MAX + 1;
				spect_ch[i].weight_copy =
							SAP_ACS_WEIGHT_MAX + 1;
				break;
			}
		}

		qdf_list_peek_next(scan_list, cur_lst, &next_lst);
		cur_lst = next_lst;
		next_lst = NULL;
	}
}
#endif /* FEATURE_AP_MCC_CH_AVOIDANCE */

/**
 * sap_select_preferred_channel_from_channel_list() - to calc best cahnnel
 * @best_ch_freq: best chan freq already calculated among all the chanels
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @sap_ctx: sap context
 * @spectinfo_param: Pointer to tSapChSelSpectInfo structure
 *
 * This function calculates the best channel among the configured channel list.
 * If channel list not configured then returns the best channel calculated
 * among all the channel list.
 *
<<<<<<< HEAD
 * Return: uint8_t best channel
 */
static
uint8_t sap_select_preferred_channel_from_channel_list(uint8_t best_chnl,
				ptSapContext sap_ctx,
				tSapChSelSpectInfo *spectinfo_param)
{
	uint8_t i = 0;

=======
 * Return: uint32_t best channel frequency
 */
static
uint32_t sap_select_preferred_channel_from_channel_list(uint32_t best_ch_freq,
				struct sap_context *sap_ctx,
				tSapChSelSpectInfo *spectinfo_param)
{
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	/*
	 * If Channel List is not Configured don't do anything
	 * Else return the Best Channel from the Channel List
	 */
<<<<<<< HEAD
	if ((NULL == sap_ctx->acs_cfg->ch_list) ||
		(NULL == spectinfo_param) ||
		(0 == sap_ctx->acs_cfg->ch_list_count))
		return best_chnl;

	if (best_chnl <= 0 || best_chnl > 252)
		return SAP_CHANNEL_NOT_SELECTED;

	for (i = 0; i < sap_ctx->acs_cfg->ch_list_count; i++) {
		if ((sap_ctx->acs_cfg->ch_list[i] == best_chnl) &&
		!(CDS_IS_DFS_CH(best_chnl) && cds_disallow_mcc(best_chnl))) {
			QDF_TRACE(QDF_MODULE_ID_SAP,
				QDF_TRACE_LEVEL_INFO,
				"Best channel so far is: %d",
				best_chnl);
			return best_chnl;
		}
	}
=======
	if ((!sap_ctx->acs_cfg->freq_list) ||
	    (!spectinfo_param) ||
	    (!sap_ctx->acs_cfg->ch_list_count))
		return best_ch_freq;

	if (wlansap_is_channel_present_in_acs_list(best_ch_freq,
					sap_ctx->acs_cfg->freq_list,
					sap_ctx->acs_cfg->ch_list_count))
		return best_ch_freq;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	return SAP_CHANNEL_NOT_SELECTED;
}

<<<<<<< HEAD
/*==========================================================================
   FUNCTION    sap_chan_sel_init

   DESCRIPTION
    Function sap_chan_sel_init allocates the memory, intializes the
    structures used by the channel selection algorithm

   DEPENDENCIES
    NA.

   PARAMETERS

    IN
    halHandle          : Pointer to tHalHandle
   *pSpectInfoParams  : Pointer to tSapChSelSpectInfo structure
     pSapCtx           : Pointer to SAP Context

   RETURN VALUE
    bool:  Success or FAIL

   SIDE EFFECTS
   ============================================================================*/
static bool sap_chan_sel_init(tHalHandle halHandle,
			      tSapChSelSpectInfo *pSpectInfoParams,
			      ptSapContext pSapCtx)
{
	tSapSpectChInfo *pSpectCh = NULL;
	uint8_t *pChans = NULL;
	uint16_t channelnum = 0;
	tpAniSirGlobal pMac = PMAC_STRUCT(halHandle);
	bool chSafe = true;
	uint32_t dfs_master_cap_enabled;
	bool include_dfs_ch = true;
	bool sta_sap_scc_on_dfs_chan =
		cds_is_sta_sap_scc_allowed_on_dfs_channel();
	uint8_t chan_num;

	QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH, "In %s",
		  __func__);

	pSpectInfoParams->numSpectChans =
		pMac->scan.base_channels.numChannels;

	/* Allocate memory for weight computation of 2.4GHz */
	pSpectCh =
		(tSapSpectChInfo *)qdf_mem_malloc(
					(pSpectInfoParams->numSpectChans) *
					sizeof(*pSpectCh));

	if (pSpectCh == NULL) {
		QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_ERROR,
			  "In %s, QDF_MALLOC_ERR", __func__);
		return false;
	}
=======
/**
 * sap_chan_sel_init() - Initialize channel select
 * @mac_handle: Opaque handle to the global MAC context
 * @pSpectInfoParams: Pointer to tSapChSelSpectInfo structure
 * @sap_ctx: Pointer to SAP Context
 *
 * Function sap_chan_sel_init allocates the memory, initializes the
 * structures used by the channel selection algorithm
 *
 * Return: bool Success or FAIL
 */
static bool sap_chan_sel_init(mac_handle_t mac_handle,
			      tSapChSelSpectInfo *pSpectInfoParams,
			      struct sap_context *sap_ctx)
{
	tSapSpectChInfo *pSpectCh = NULL;
	uint32_t *pChans = NULL;
	uint16_t channelnum = 0;
	struct mac_context *mac = MAC_CONTEXT(mac_handle);
	bool include_dfs_ch = true;
	uint8_t sta_sap_scc_on_dfs_chnl_config_value;

	pSpectInfoParams->numSpectChans =
		mac->scan.base_channels.numChannels;

	/* Allocate memory for weight computation of 2.4GHz */
	pSpectCh = qdf_mem_malloc((pSpectInfoParams->numSpectChans) *
			sizeof(*pSpectCh));
	if (!pSpectCh)
		return false;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	/* Initialize the pointers in the DfsParams to the allocated memory */
	pSpectInfoParams->pSpectCh = pSpectCh;

<<<<<<< HEAD
	pChans = pMac->scan.base_channels.channelList;

#if defined(FEATURE_WLAN_STA_AP_MODE_DFS_DISABLE)
	if (pSapCtx->dfs_ch_disable == true)
		include_dfs_ch = false;
#endif
	sme_cfg_get_int(halHandle, WNI_CFG_DFS_MASTER_ENABLED,
			&dfs_master_cap_enabled);
	if (dfs_master_cap_enabled == 0 ||
	    ACS_DFS_MODE_DISABLE == pSapCtx->dfs_mode)
=======
	pChans = mac->scan.base_channels.channel_freq_list;

	policy_mgr_get_sta_sap_scc_on_dfs_chnl(mac->psoc,
			&sta_sap_scc_on_dfs_chnl_config_value);
#if defined(FEATURE_WLAN_STA_AP_MODE_DFS_DISABLE)
	if (sap_ctx->dfs_ch_disable == true)
		include_dfs_ch = false;
#endif
	if (!mac->mlme_cfg->dfs_cfg.dfs_master_capable ||
	    ACS_DFS_MODE_DISABLE == sap_ctx->dfs_mode)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		include_dfs_ch = false;

	/* Fill the channel number in the spectrum in the operating freq band */
	for (channelnum = 0;
	     channelnum < pSpectInfoParams->numSpectChans;
	     channelnum++, pChans++, pSpectCh++) {
<<<<<<< HEAD
		chSafe = true;

		pSpectCh->chNum = *pChans;
		/* Initialise for all channels */
		pSpectCh->rssiAgr = SOFTAP_MIN_RSSI;
		/* Initialise 20MHz for all the Channels */
		pSpectCh->channelWidth = SOFTAP_HT20_CHANNELWIDTH;
=======
		uint8_t channel;

		channel = wlan_reg_freq_to_chan(mac->pdev, *pChans);

		pSpectCh->chan_freq = *pChans;
		/* Initialise for all channels */
		pSpectCh->rssiAgr = SOFTAP_MIN_RSSI;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		/* Initialise max ACS weight for all channels */
		pSpectCh->weight = SAP_ACS_WEIGHT_MAX;

		/* check if the channel is in NOL blacklist */
		if (sap_dfs_is_channel_in_nol_list(
<<<<<<< HEAD
					pSapCtx, *pChans,
					PHY_SINGLE_CHANNEL_CENTERED)) {
			QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
				  "In %s, Ch %d is in NOL list", __func__,
				  *pChans);
			chSafe = false;
			continue;
		}

		if ((include_dfs_ch == false) || sta_sap_scc_on_dfs_chan) {
			if (CDS_IS_DFS_CH(*pChans)) {
				chSafe = false;
				QDF_TRACE(QDF_MODULE_ID_SAP,
					  QDF_TRACE_LEVEL_INFO_HIGH,
					  "In %s, DFS Ch %d not considered for ACS. include_dfs_ch %u, sta_sap_scc_on_dfs_chan %d",
					  __func__, *pChans, include_dfs_ch,
					  sta_sap_scc_on_dfs_chan);
=======
					sap_ctx, channel,
					PHY_SINGLE_CHANNEL_CENTERED)) {
			QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
				  "In %s, Ch %d is in NOL list", __func__,
				  channel);
			continue;
		}

		if (!include_dfs_ch ||
		    sta_sap_scc_on_dfs_chnl_config_value == 1) {
			if (wlan_reg_is_dfs_for_freq(mac->pdev,
						     pSpectCh->chan_freq)) {
				QDF_TRACE(QDF_MODULE_ID_SAP,
					  QDF_TRACE_LEVEL_INFO_HIGH,
					  "In %s, DFS Ch %d not considered for ACS. include_dfs_ch %u, sta_sap_scc_on_dfs_chnl_config_value %d",
					  __func__, channel, include_dfs_ch,
					  sta_sap_scc_on_dfs_chnl_config_value);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				continue;
			}
		}

<<<<<<< HEAD
		if (!cds_is_safe_channel(*pChans))
			chSafe = false;

		/* OFDM rates are not supported on channel 14 */
		if (*pChans == 14 &&
		    eCSR_DOT11_MODE_11b != pSapCtx->csr_roamProfile.phyMode) {
			continue;
		}

		/* Skip DSRC channels */
		if (cds_is_dsrc_channel(cds_chan_to_freq(*pChans)))
			continue;

		if (!pSapCtx->enable_etsi_srd_chan_support &&
				cds_is_etsi13_regdmn_srd_chan(
				cds_chan_to_freq(*pChans)))
			continue;

		if (true == chSafe) {
			pSpectCh->valid = true;
			for (chan_num = 0; chan_num < pSapCtx->num_of_channel;
			     chan_num++) {
				if (pSpectCh->chNum !=
				    pSapCtx->channelList[chan_num])
					continue;

				/*
				 * Initialize ACS weight to 0 for channels
				 * present in sap context scan channel list
				 */
				pSpectCh->weight = 0;
				break;
			}
		}
	}
=======
		if (!policy_mgr_is_safe_channel(mac->psoc, *pChans))
			continue;

		/* OFDM rates are not supported on channel 14 */
		if (channel == 14 &&
		    eCSR_DOT11_MODE_11b != sap_ctx->csr_roamProfile.phyMode)
			continue;

		/* Skip DSRC channels */
		if (wlan_reg_is_dsrc_chan(mac->pdev, channel))
			continue;

		/*
		 * Skip the channels which are not in ACS config from user
		 * space
		 */
		if (!wlansap_is_channel_present_in_acs_list(*pChans,
					sap_ctx->acs_cfg->freq_list,
					sap_ctx->acs_cfg->ch_list_count))
			continue;

		pSpectCh->valid = true;
		pSpectCh->weight = 0;
	}

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	return true;
}

/**
 * sapweight_rssi_count() - calculates the channel weight due to rssi
    and data count(here number of BSS observed)
<<<<<<< HEAD
 * @sap_ctx: softap context
 * @rssi: Max signal strength receieved from a BSS for the channel
 * @count: Number of BSS observed in the channel
 *
 * Return: Calculated channel weight based on above two
 */
static
uint32_t sapweight_rssi_count(ptSapContext sap_ctx, int8_t rssi,
			      uint16_t count)
{
	int32_t rssi_weight = 0;
	int32_t count_weight = 0;
	uint32_t rssi_cnt_weight = 0;
=======
 * @sap_ctx     : Softap context
 * @rssi        : Max signal strength receieved from a BSS for the channel
 * @count       : Number of BSS observed in the channel
 *
 * Return: uint32_t Calculated channel weight based on above two
 */
static
uint32_t sapweight_rssi_count(struct sap_context *sap_ctx, int8_t rssi,
			      uint16_t count)
{
	int32_t rssiWeight = 0;
	int32_t countWeight = 0;
	uint32_t rssicountWeight = 0;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	uint8_t softap_rssi_weight_cfg, softap_count_weight_cfg;
	uint8_t softap_rssi_weight_local, softap_count_weight_local;

	softap_rssi_weight_cfg =
	    ACS_WEIGHT_SOFTAP_RSSI_CFG(sap_ctx->auto_channel_select_weight);

	softap_count_weight_cfg =
	    ACS_WEIGHT_SOFTAP_COUNT_CFG(sap_ctx->auto_channel_select_weight);

	softap_rssi_weight_local =
	    ACS_WEIGHT_CFG_TO_LOCAL(sap_ctx->auto_channel_select_weight,
				    softap_rssi_weight_cfg);

	softap_count_weight_local =
	    ACS_WEIGHT_CFG_TO_LOCAL(sap_ctx->auto_channel_select_weight,
				    softap_count_weight_cfg);

	/* Weight from RSSI */
<<<<<<< HEAD
	rssi_weight = ACS_WEIGHT_COMPUTE(sap_ctx->auto_channel_select_weight,
					 softap_rssi_weight_cfg,
					 rssi - SOFTAP_MIN_RSSI,
					 SOFTAP_MAX_RSSI - SOFTAP_MIN_RSSI);

	if (rssi_weight > softap_rssi_weight_local)
	    rssi_weight = softap_rssi_weight_local;

	else if (rssi_weight < 0)
		rssi_weight = 0;

	/* Weight from data count */
	count_weight = ACS_WEIGHT_COMPUTE(sap_ctx->auto_channel_select_weight,
					  softap_count_weight_cfg,
					  count - SOFTAP_MIN_COUNT,
					  SOFTAP_MAX_COUNT - SOFTAP_MIN_COUNT);

	if (count_weight > softap_count_weight_local)
	    count_weight = softap_count_weight_local;

	rssi_cnt_weight = rssi_weight + count_weight;

	QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
		  "In %s, rssiWeight=%d, countWeight=%d, rssicountWeight=%d",
		  __func__, rssi_weight, count_weight, rssi_cnt_weight);

	return rssi_cnt_weight;
=======
	rssiWeight = ACS_WEIGHT_COMPUTE(sap_ctx->auto_channel_select_weight,
					softap_rssi_weight_cfg,
					rssi - SOFTAP_MIN_RSSI,
					SOFTAP_MAX_RSSI - SOFTAP_MIN_RSSI);

	if (rssiWeight > softap_rssi_weight_local)
		rssiWeight = softap_rssi_weight_local;

	else if (rssiWeight < 0)
		rssiWeight = 0;

	/* Weight from data count */
	countWeight = ACS_WEIGHT_COMPUTE(sap_ctx->auto_channel_select_weight,
					 softap_count_weight_cfg,
					 count - SOFTAP_MIN_COUNT,
					 SOFTAP_MAX_COUNT - SOFTAP_MIN_COUNT);

	if (countWeight > softap_count_weight_local)
		countWeight = softap_count_weight_local;

	rssicountWeight = rssiWeight + countWeight;

	QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
		  "rssiWeight=%d, countWeight=%d, rssicountWeight=%d",
		  rssiWeight, countWeight, rssicountWeight);

	return rssicountWeight;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * sap_get_channel_status() - get channel info via channel number
 * @p_mac: Pointer to Global MAC structure
 * @channel_id: channel id
 *
 * Return: chan status info
 */
static struct lim_channel_status *sap_get_channel_status
<<<<<<< HEAD
	(tpAniSirGlobal p_mac, uint32_t channel_id)
{
	return csr_get_channel_status(p_mac, channel_id);
=======
	(struct mac_context *p_mac, uint32_t chan_freq)
{
	return csr_get_channel_status(p_mac, chan_freq);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * sap_clear_channel_status() - clear chan info
 * @p_mac: Pointer to Global MAC structure
 *
 * Return: none
 */
<<<<<<< HEAD
static void sap_clear_channel_status(tpAniSirGlobal p_mac)
=======
static void sap_clear_channel_status(struct mac_context *p_mac)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	csr_clear_channel_status(p_mac);
}

/**
 * sap_weight_channel_noise_floor() - compute noise floor weight
 * @sap_ctx:  sap context
 * @chn_stat: Pointer to chan status info
 *
 * Return: channel noise floor weight
 */
<<<<<<< HEAD
static uint32_t sap_weight_channel_noise_floor(ptSapContext sap_ctx,
=======
static uint32_t sap_weight_channel_noise_floor(struct sap_context *sap_ctx,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
					       struct lim_channel_status
						*channel_stat)
{
	uint32_t    noise_floor_weight;
	uint8_t     softap_nf_weight_cfg;
	uint8_t     softap_nf_weight_local;

	softap_nf_weight_cfg =
	    ACS_WEIGHT_SOFTAP_NOISE_FLOOR_CFG
	    (sap_ctx->auto_channel_select_weight);

	softap_nf_weight_local =
	    ACS_WEIGHT_CFG_TO_LOCAL(sap_ctx->auto_channel_select_weight,
				    softap_nf_weight_cfg);

<<<<<<< HEAD
	if (channel_stat == NULL || channel_stat->channelfreq == 0) {
		QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_DEBUG,
			  "In %s, sanity check failed return max weight",
			  __func__);
		return softap_nf_weight_local;
	}
=======
	if (!channel_stat || channel_stat->channelfreq == 0)
		return softap_nf_weight_local;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	noise_floor_weight = (channel_stat->noise_floor == 0) ? 0 :
			    (ACS_WEIGHT_COMPUTE(
			     sap_ctx->auto_channel_select_weight,
			     softap_nf_weight_cfg,
			     channel_stat->noise_floor -
			     SOFTAP_MIN_NF,
			     SOFTAP_MAX_NF - SOFTAP_MIN_NF));

	if (noise_floor_weight > softap_nf_weight_local)
		noise_floor_weight = softap_nf_weight_local;
<<<<<<< HEAD
	else if (noise_floor_weight < 0)
		noise_floor_weight = 0;

	QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
		  "In %s, nf=%d, nfwc=%d, nfwl=%d, nfw=%d",
		  __func__, channel_stat->noise_floor,
=======

	QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
		  "nf=%d, nfwc=%d, nfwl=%d, nfw=%d",
		  channel_stat->noise_floor,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		  softap_nf_weight_cfg, softap_nf_weight_local,
		  noise_floor_weight);

	return noise_floor_weight;
}

/**
 * sap_weight_channel_free() - compute channel free weight
 * @sap_ctx:  sap context
 * @chn_stat: Pointer to chan status info
 *
 * Return: channel free weight
 */
<<<<<<< HEAD
static uint32_t sap_weight_channel_free(ptSapContext sap_ctx,
=======
static uint32_t sap_weight_channel_free(struct sap_context *sap_ctx,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
					struct lim_channel_status
					*channel_stat)
{
	uint32_t     channel_free_weight;
	uint8_t      softap_channel_free_weight_cfg;
	uint8_t      softap_channel_free_weight_local;
	uint32_t     rx_clear_count = 0;
	uint32_t     cycle_count = 0;

	softap_channel_free_weight_cfg =
	    ACS_WEIGHT_SOFTAP_CHANNEL_FREE_CFG
	    (sap_ctx->auto_channel_select_weight);

	softap_channel_free_weight_local =
	    ACS_WEIGHT_CFG_TO_LOCAL(sap_ctx->auto_channel_select_weight,
				    softap_channel_free_weight_cfg);

<<<<<<< HEAD
	if (channel_stat == NULL || channel_stat->channelfreq == 0) {
		QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_DEBUG,
			  "In %s, sanity check failed return max weight",
			  __func__);
		return softap_channel_free_weight_local;
	}
=======
	if (!channel_stat || channel_stat->channelfreq == 0)
		return softap_channel_free_weight_local;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	rx_clear_count = channel_stat->rx_clear_count -
			channel_stat->tx_frame_count -
			channel_stat->rx_frame_count;
	cycle_count = channel_stat->cycle_count;

	/* LSH 4, otherwise it is always 0. */
	channel_free_weight = (cycle_count == 0) ? 0 :
			 (ACS_WEIGHT_COMPUTE(
			  sap_ctx->auto_channel_select_weight,
			  softap_channel_free_weight_cfg,
<<<<<<< HEAD
			((rx_clear_count << 8) +
			(cycle_count >> 1))/cycle_count -
			(SOFTAP_MIN_CHNFREE << 8),
			(SOFTAP_MAX_CHNFREE -
			SOFTAP_MIN_CHNFREE) << 8));
=======
			 ((rx_clear_count << 8) +
			 (cycle_count >> 1))/cycle_count -
			 (SOFTAP_MIN_CHNFREE << 8),
			 (SOFTAP_MAX_CHNFREE -
			 SOFTAP_MIN_CHNFREE) << 8));
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	if (channel_free_weight > softap_channel_free_weight_local)
		channel_free_weight = softap_channel_free_weight_local;

	QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
<<<<<<< HEAD
		  "In %s, rcc=%d, cc=%d, tc=%d, rc=%d, cfwc=%d, cfwl=%d, cfw=%d",
		  __func__, rx_clear_count, cycle_count,
		 channel_stat->tx_frame_count,
		 channel_stat->rx_frame_count,
=======
		  "rcc=%d, cc=%d, tc=%d, rc=%d, cfwc=%d, cfwl=%d, cfw=%d",
		  rx_clear_count, cycle_count,
		  channel_stat->tx_frame_count,
		  channel_stat->rx_frame_count,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		  softap_channel_free_weight_cfg,
		  softap_channel_free_weight_local,
		  channel_free_weight);

	return channel_free_weight;
}

/**
 * sap_weight_channel_txpwr_range() - compute channel tx power range weight
 * @sap_ctx:  sap context
 * @chn_stat: Pointer to chan status info
 *
 * Return: tx power range weight
 */
<<<<<<< HEAD
static uint32_t sap_weight_channel_txpwr_range(ptSapContext sap_ctx,
=======
static uint32_t sap_weight_channel_txpwr_range(struct sap_context *sap_ctx,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
					       struct lim_channel_status
					       *channel_stat)
{
	uint32_t     txpwr_weight_low_speed;
	uint8_t      softap_txpwr_range_weight_cfg;
	uint8_t      softap_txpwr_range_weight_local;

	softap_txpwr_range_weight_cfg =
	    ACS_WEIGHT_SOFTAP_TX_POWER_RANGE_CFG
	    (sap_ctx->auto_channel_select_weight);

	softap_txpwr_range_weight_local =
	    ACS_WEIGHT_CFG_TO_LOCAL(sap_ctx->auto_channel_select_weight,
				    softap_txpwr_range_weight_cfg);

<<<<<<< HEAD
	if (channel_stat == NULL || channel_stat->channelfreq == 0) {
		QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_DEBUG,
			  "In %s, sanity check failed return max weight",
			  __func__);
		return softap_txpwr_range_weight_local;
	}
=======
	if (!channel_stat || channel_stat->channelfreq == 0)
		return softap_txpwr_range_weight_local;

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	txpwr_weight_low_speed = (channel_stat->chan_tx_pwr_range == 0) ? 0 :
				(ACS_WEIGHT_COMPUTE(
				 sap_ctx->auto_channel_select_weight,
				 softap_txpwr_range_weight_cfg,
				 SOFTAP_MAX_TXPWR -
				 channel_stat->chan_tx_pwr_range,
				 SOFTAP_MAX_TXPWR - SOFTAP_MIN_TXPWR));

	if (txpwr_weight_low_speed > softap_txpwr_range_weight_local)
		txpwr_weight_low_speed = softap_txpwr_range_weight_local;

	QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
<<<<<<< HEAD
		  "In %s, tpr=%d, tprwc=%d, tprwl=%d, tprw=%d",
		  __func__, channel_stat->chan_tx_pwr_range,
=======
		  "tpr=%d, tprwc=%d, tprwl=%d, tprw=%d",
		  channel_stat->chan_tx_pwr_range,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		  softap_txpwr_range_weight_cfg,
		  softap_txpwr_range_weight_local,
		  txpwr_weight_low_speed);

	return txpwr_weight_low_speed;
}

/**
 * sap_weight_channel_txpwr_tput() - compute channel tx power
 * throughput weight
 * @sap_ctx:  sap context
 * @chn_stat: Pointer to chan status info
 *
 * Return: tx power throughput weight
 */
<<<<<<< HEAD
static uint32_t sap_weight_channel_txpwr_tput(ptSapContext sap_ctx,
=======
static uint32_t sap_weight_channel_txpwr_tput(struct sap_context *sap_ctx,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
					      struct lim_channel_status
					      *channel_stat)
{
	uint32_t     txpwr_weight_high_speed;
	uint8_t      softap_txpwr_tput_weight_cfg;
	uint8_t      softap_txpwr_tput_weight_local;

	softap_txpwr_tput_weight_cfg =
	    ACS_WEIGHT_SOFTAP_TX_POWER_THROUGHPUT_CFG
	    (sap_ctx->auto_channel_select_weight);

	softap_txpwr_tput_weight_local =
	    ACS_WEIGHT_CFG_TO_LOCAL(sap_ctx->auto_channel_select_weight,
				    softap_txpwr_tput_weight_cfg);

<<<<<<< HEAD
	if (channel_stat == NULL || channel_stat->channelfreq == 0) {
		QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_DEBUG,
			  "In %s, sanity check failed return max weight",
			  __func__);
		return softap_txpwr_tput_weight_local;
	}
=======
	if (!channel_stat || channel_stat->channelfreq == 0)
		return softap_txpwr_tput_weight_local;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	txpwr_weight_high_speed = (channel_stat->chan_tx_pwr_throughput == 0)
				  ? 0 : (ACS_WEIGHT_COMPUTE(
				  sap_ctx->auto_channel_select_weight,
				  softap_txpwr_tput_weight_cfg,
				  SOFTAP_MAX_TXPWR -
				  channel_stat->chan_tx_pwr_throughput,
				  SOFTAP_MAX_TXPWR - SOFTAP_MIN_TXPWR));

	if (txpwr_weight_high_speed > softap_txpwr_tput_weight_local)
		txpwr_weight_high_speed = softap_txpwr_tput_weight_local;

	QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
<<<<<<< HEAD
		  "In %s, tpt=%d, tptwc=%d, tptwl=%d, tptw=%d",
		  __func__, channel_stat->chan_tx_pwr_throughput,
=======
		  "tpt=%d, tptwc=%d, tptwl=%d, tptw=%d",
		  channel_stat->chan_tx_pwr_throughput,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		  softap_txpwr_tput_weight_cfg,
		  softap_txpwr_tput_weight_local,
		  txpwr_weight_high_speed);

	return txpwr_weight_high_speed;
}

/**
 * sap_weight_channel_status() - compute chan status weight
 * @sap_ctx:  sap context
 * @chn_stat: Pointer to chan status info
 *
 * Return: chan status weight
 */
static
<<<<<<< HEAD
uint32_t sap_weight_channel_status(ptSapContext sap_ctx,
				   struct lim_channel_status *channel_stat)

=======
uint32_t sap_weight_channel_status(struct sap_context *sap_ctx,
				   struct lim_channel_status *channel_stat)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	return sap_weight_channel_noise_floor(sap_ctx, channel_stat) +
	       sap_weight_channel_free(sap_ctx, channel_stat) +
	       sap_weight_channel_txpwr_range(sap_ctx, channel_stat) +
	       sap_weight_channel_txpwr_tput(sap_ctx, channel_stat);
}

/**
<<<<<<< HEAD
 * sap_check_channels_same_band() - Check if two channels belong to same band
 * @ch_num1: channel number
 * @ch_num2: channel number
 *
 * Return: true if both channels belong to same band else false
 */
static bool sap_check_channels_same_band(uint16_t ch_num1, uint16_t ch_num2)
{
	if ((ch_num1 <= SIR_11B_CHANNEL_END &&
	     ch_num2 <= SIR_11B_CHANNEL_END) ||
	    (ch_num1 >= SIR_11A_CHANNEL_BEGIN &&
	     ch_num2 >= SIR_11A_CHANNEL_BEGIN))
	    return true;

	return false;
}

/**
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * sap_update_rssi_bsscount() - updates bss count and rssi effect.
 *
 * @pSpectCh:     Channel Information
 * @offset:       Channel Offset
 * @sap_24g:      Channel is in 2.4G or 5G
 * @spectch_start: the start of spect ch array
 * @spectch_end: the end of spect ch array
 *
 * sap_update_rssi_bsscount updates bss count and rssi effect based
 * on the channel offset.
 *
 * Return: None.
 */

static void sap_update_rssi_bsscount(tSapSpectChInfo *pSpectCh, int32_t offset,
	bool sap_24g, tSapSpectChInfo *spectch_start,
	tSapSpectChInfo *spectch_end)
{
	tSapSpectChInfo *pExtSpectCh = NULL;
	int32_t rssi, rsssi_effect;

	pExtSpectCh = (pSpectCh + offset);
<<<<<<< HEAD
	if (pExtSpectCh != NULL &&
	    pExtSpectCh >= spectch_start &&
	    pExtSpectCh < spectch_end) {
		if (!sap_check_channels_same_band(pSpectCh->chNum,
		    pExtSpectCh->chNum))
=======
	if (pExtSpectCh && pExtSpectCh >= spectch_start &&
	    pExtSpectCh < spectch_end) {
		if (!WLAN_REG_IS_SAME_BAND_FREQS(pSpectCh->chan_freq,
						 pExtSpectCh->chan_freq))
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			return;
		++pExtSpectCh->bssCount;
		switch (offset) {
		case -1:
		case 1:
			rsssi_effect = sap_24g ?
			    SAP_24GHZ_FIRST_OVERLAP_CHAN_RSSI_EFFECT_PRIMARY :
			    SAP_SUBBAND1_RSSI_EFFECT_PRIMARY;
			break;
		case -2:
		case 2:
			rsssi_effect = sap_24g ?
			    SAP_24GHZ_SEC_OVERLAP_CHAN_RSSI_EFFECT_PRIMARY :
			    SAP_SUBBAND2_RSSI_EFFECT_PRIMARY;
			break;
		case -3:
		case 3:
			rsssi_effect = sap_24g ?
			    SAP_24GHZ_THIRD_OVERLAP_CHAN_RSSI_EFFECT_PRIMARY :
			    SAP_SUBBAND3_RSSI_EFFECT_PRIMARY;
			break;
		case -4:
		case 4:
			rsssi_effect = sap_24g ?
			    SAP_24GHZ_FOURTH_OVERLAP_CHAN_RSSI_EFFECT_PRIMARY :
			    SAP_SUBBAND4_RSSI_EFFECT_PRIMARY;
			break;
		case -5:
		case 5:
			rsssi_effect = SAP_SUBBAND5_RSSI_EFFECT_PRIMARY;
			break;
		case -6:
		case 6:
			rsssi_effect = SAP_SUBBAND6_RSSI_EFFECT_PRIMARY;
			break;
		case -7:
		case 7:
			rsssi_effect = SAP_SUBBAND7_RSSI_EFFECT_PRIMARY;
			break;
		default:
			rsssi_effect = 0;
			break;
		}

		rssi = pSpectCh->rssiAgr + rsssi_effect;
		if (IS_RSSI_VALID(pExtSpectCh->rssiAgr, rssi))
			pExtSpectCh->rssiAgr = rssi;
		if (pExtSpectCh->rssiAgr < SOFTAP_MIN_RSSI)
			pExtSpectCh->rssiAgr = SOFTAP_MIN_RSSI;
	}
}

/**
<<<<<<< HEAD
 * sap_upd_chan_spec_params() - sap_upd_chan_spec_params
 *                              updates channel parameters obtained from Beacon
 * @pBeaconStruct Beacon strucutre populated by parse_beacon function
 * @channelWidth Channel width
 * @secondaryChannelOffset Secondary Channel Offset
 * @vhtSupport If channel supports VHT
 * @centerFreq Central frequency for the given channel.
 *
 * sap_upd_chan_spec_params updates the spectrum channels based on the
 * pBeaconStruct obtained from Beacon IE
 *
 * Return: NA.
 */

static void sap_upd_chan_spec_params(tSirProbeRespBeacon *pBeaconStruct,
				     uint16_t *channelWidth,
				     uint16_t *secondaryChannelOffset,
				     uint16_t *vhtSupport,
				     uint16_t *centerFreq,
				     uint16_t *centerFreq_2)
{
	if (NULL == pBeaconStruct) {
		QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_ERROR,
			  FL("pBeaconStruct is NULL"));
		return;
	}

	if (pBeaconStruct->HTCaps.present && pBeaconStruct->HTInfo.present) {
		*channelWidth = pBeaconStruct->HTCaps.supportedChannelWidthSet;
		*secondaryChannelOffset =
			pBeaconStruct->HTInfo.secondaryChannelOffset;
		if (!pBeaconStruct->VHTOperation.present)
			return;
		*vhtSupport = pBeaconStruct->VHTOperation.present;
		if (pBeaconStruct->VHTOperation.chanWidth) {
			*centerFreq =
				pBeaconStruct->VHTOperation.chanCenterFreqSeg1;
			*centerFreq_2 =
				pBeaconStruct->VHTOperation.chanCenterFreqSeg2;
			 /*
			  * LHS follows tSirMacHTChannelWidth, while RHS follows
			  * WNI_CFG_VHT_CHANNEL_WIDTH_X format hence following
			  * adjustment
			  */
			*channelWidth =
				pBeaconStruct->VHTOperation.chanWidth + 1;

		}
	}
}

/**
=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * sap_update_rssi_bsscount_vht_5G() - updates bss count and rssi effect.
 *
 * @spect_ch:     Channel Information
 * @offset:       Channel Offset
 * @num_ch:       no.of channels
 * @spectch_start: the start of spect ch array
 * @spectch_end: the end of spect ch array
 *
 * sap_update_rssi_bsscount_vht_5G updates bss count and rssi effect based
 * on the channel offset.
 *
 * Return: None.
 */

static void sap_update_rssi_bsscount_vht_5G(tSapSpectChInfo *spect_ch,
					    int32_t offset,
					    uint16_t num_ch,
					    tSapSpectChInfo *spectch_start,
					    tSapSpectChInfo *spectch_end)
{
	int32_t ch_offset;
	uint16_t i, cnt;

	if (!offset)
		return;
	if (offset > 0)
		cnt = num_ch;
	else
		cnt = num_ch + 1;
	for (i = 0; i < cnt; i++) {
		ch_offset = offset + i;
		if (ch_offset == 0)
			continue;
		sap_update_rssi_bsscount(spect_ch, ch_offset, false,
			spectch_start, spectch_end);
	}
}
/**
 * sap_interference_rssi_count_5G() - sap_interference_rssi_count
 *                                    considers the Adjacent channel rssi and
 *                                    data count(here number of BSS observed)
 * @spect_ch:        Channel Information
 * @chan_width:      Channel width parsed from beacon IE
 * @sec_chan_offset: Secondary Channel Offset
 * @center_freq:     Central frequency for the given channel.
 * @channel_id:      channel_id
 * @spectch_start: the start of spect ch array
 * @spectch_end: the end of spect ch array
 *
 * sap_interference_rssi_count_5G considers the Adjacent channel rssi
 * and data count(here number of BSS observed)
 *
 * Return: NA.
 */

static void sap_interference_rssi_count_5G(tSapSpectChInfo *spect_ch,
					   uint16_t chan_width,
					   uint16_t sec_chan_offset,
<<<<<<< HEAD
					   uint16_t center_freq,
					   uint16_t center_freq_2,
					   uint8_t channel_id,
=======
					   uint32_t ch_freq0,
					   uint32_t ch_freq1,
					   uint32_t op_chan_freq,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
					   tSapSpectChInfo *spectch_start,
					   tSapSpectChInfo *spectch_end)
{
	uint16_t num_ch;
	int32_t offset = 0;

<<<<<<< HEAD
	if (NULL == spect_ch) {
		QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_ERROR,
			  FL("spect_ch is NULL"));
		return;
	}

	/* Updating the received ChannelWidth */
	if (spect_ch->channelWidth != chan_width)
		spect_ch->channelWidth = chan_width;
	/* If received ChannelWidth is other than HT20,
	 * we need to update the extension channel Params as well
	 * chan_width == 0, HT20
	 * chan_width == 1, HT40
	 * chan_width == 2, VHT80
	 * chan_width == 3, VHT160
	 */

	switch (spect_ch->channelWidth) {
	case eHT_CHANNEL_WIDTH_40MHZ:   /* HT40 */
=======
	sap_debug("freq = %d, ch width = %d, ch_freq0 = %d ch_freq1 = %d",
		  op_chan_freq, chan_width, ch_freq0, ch_freq1);

	switch (chan_width) {
	case eHT_CHANNEL_WIDTH_40MHZ:
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		switch (sec_chan_offset) {
		/* Above the Primary Channel */
		case PHY_DOUBLE_CHANNEL_LOW_PRIMARY:
			sap_update_rssi_bsscount(spect_ch, 1, false,
<<<<<<< HEAD
				spectch_start, spectch_end);
=======
						 spectch_start, spectch_end);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			return;

		/* Below the Primary channel */
		case PHY_DOUBLE_CHANNEL_HIGH_PRIMARY:
			sap_update_rssi_bsscount(spect_ch, -1, false,
<<<<<<< HEAD
				spectch_start, spectch_end);
			return;
		}
		return;
	case eHT_CHANNEL_WIDTH_80MHZ:   /* VHT80 */
		num_ch = 3;
		if ((center_freq - channel_id) == 6) {
			offset = 1;
		} else if ((center_freq - channel_id) == 2) {
			offset = -1;
		} else if ((center_freq - channel_id) == -2) {
			offset = -2;
		} else if ((center_freq - channel_id) == -6) {
			offset = -3;
		}
		break;
	case eHT_CHANNEL_WIDTH_160MHZ:   /* VHT160 */
		num_ch = 7;
		if ((center_freq - channel_id) == 14)
			offset = 1;
		else if ((center_freq - channel_id) == 10)
			offset = -1;
		else if ((center_freq - channel_id) == 6)
			offset = -2;
		else if ((center_freq - channel_id) == 2)
			offset = -3;
		else if ((center_freq - channel_id) == -2)
			offset = -4;
		else if ((center_freq - channel_id) == -6)
			offset = -5;
		else if ((center_freq - channel_id) == -10)
			offset = -6;
		else if ((center_freq - channel_id) == -14)
=======
						 spectch_start, spectch_end);
			return;
		}
		return;
	case eHT_CHANNEL_WIDTH_80MHZ:
	case eHT_CHANNEL_WIDTH_80P80MHZ:
		num_ch = 3;
		if ((ch_freq0 - op_chan_freq) == 30) {
			offset = 1;
		} else if ((ch_freq0 - op_chan_freq) == 10) {
			offset = -1;
		} else if ((ch_freq0 - op_chan_freq) == -10) {
			offset = -2;
		} else if ((ch_freq0 - op_chan_freq) == -30) {
			offset = -3;
		}
		break;
	case eHT_CHANNEL_WIDTH_160MHZ:
		num_ch = 7;
		if ((ch_freq0 - op_chan_freq) == 70)
			offset = 1;
		else if ((ch_freq0 - op_chan_freq) == 50)
			offset = -1;
		else if ((ch_freq0 - op_chan_freq) == 30)
			offset = -2;
		else if ((ch_freq0 - op_chan_freq) == 10)
			offset = -3;
		else if ((ch_freq0 - op_chan_freq) == -10)
			offset = -4;
		else if ((ch_freq0 - op_chan_freq) == -30)
			offset = -5;
		else if ((ch_freq0 - op_chan_freq) == -50)
			offset = -6;
		else if ((ch_freq0 - op_chan_freq) == -70)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			offset = -7;
		break;
	default:
		return;
	}
<<<<<<< HEAD
	sap_update_rssi_bsscount_vht_5G(spect_ch, offset, num_ch,
		spectch_start, spectch_end);
=======

	sap_update_rssi_bsscount_vht_5G(spect_ch, offset, num_ch, spectch_start,
					spectch_end);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * sap_interference_rssi_count() - sap_interference_rssi_count
 *                                 considers the Adjacent channel rssi
 *                                 and data count(here number of BSS observed)
 * @spect_ch    Channel Information
 * @spectch_start: the start of spect ch array
 * @spectch_end: the end of spect ch array
 *
 * sap_interference_rssi_count considers the Adjacent channel rssi
 * and data count(here number of BSS observed)
 *
 * Return: None.
 */

static void sap_interference_rssi_count(tSapSpectChInfo *spect_ch,
	tSapSpectChInfo *spectch_start,
	tSapSpectChInfo *spectch_end)
{
<<<<<<< HEAD
	if (NULL == spect_ch) {
=======
	if (!spect_ch) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_ERROR,
			  "%s: spect_ch is NULL", __func__);
		return;
	}

<<<<<<< HEAD
	switch (spect_ch->chNum) {
=======
	switch (wlan_freq_to_chan(spect_ch->chan_freq)) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	case CHANNEL_1:
		sap_update_rssi_bsscount(spect_ch, 1, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 2, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 3, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 4, true,
			spectch_start, spectch_end);
		break;

	case CHANNEL_2:
		sap_update_rssi_bsscount(spect_ch, -1, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 1, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 2, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 3, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 4, true,
			spectch_start, spectch_end);
		break;
	case CHANNEL_3:
		sap_update_rssi_bsscount(spect_ch, -2, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, -1, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 1, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 2, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 3, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 4, true,
			spectch_start, spectch_end);
		break;
	case CHANNEL_4:
		sap_update_rssi_bsscount(spect_ch, -3, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, -2, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, -1, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 1, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 2, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 3, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 4, true,
			spectch_start, spectch_end);
		break;

	case CHANNEL_5:
	case CHANNEL_6:
	case CHANNEL_7:
	case CHANNEL_8:
	case CHANNEL_9:
	case CHANNEL_10:
		sap_update_rssi_bsscount(spect_ch, -4, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, -3, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, -2, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, -1, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 1, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 2, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 3, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 4, true,
			spectch_start, spectch_end);
		break;

	case CHANNEL_11:
		sap_update_rssi_bsscount(spect_ch, -4, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, -3, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, -2, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, -1, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 1, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 2, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 3, true,
			spectch_start, spectch_end);
		break;

	case CHANNEL_12:
		sap_update_rssi_bsscount(spect_ch, -4, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, -3, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, -2, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, -1, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 1, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 2, true,
			spectch_start, spectch_end);
		break;

	case CHANNEL_13:
		sap_update_rssi_bsscount(spect_ch, -4, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, -3, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, -2, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, -1, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, 1, true,
			spectch_start, spectch_end);
		break;

	case CHANNEL_14:
		sap_update_rssi_bsscount(spect_ch, -4, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, -3, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, -2, true,
			spectch_start, spectch_end);
		sap_update_rssi_bsscount(spect_ch, -1, true,
			spectch_start, spectch_end);
		break;

	default:
		break;
	}
}

/**
 * ch_in_pcl() - Is channel in the Preferred Channel List (PCL)
 * @sap_ctx: SAP context which contains the current PCL
 * @channel: Input channel number to be checked
 *
 * Check if a channel is in the preferred channel list
 *
 * Return:
 *   true:    channel is in PCL,
 *   false:   channel is not in PCL
 */
<<<<<<< HEAD
static bool ch_in_pcl(ptSapContext sap_ctx, uint8_t channel)
=======
static bool ch_in_pcl(struct sap_context *sap_ctx, uint32_t ch_freq)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	uint32_t i;

	for (i = 0; i < sap_ctx->acs_cfg->pcl_ch_count; i++) {
<<<<<<< HEAD
		if (channel == sap_ctx->acs_cfg->pcl_channels[i])
=======
		if (ch_freq == sap_ctx->acs_cfg->pcl_chan_freq[i])
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			return true;
	}

	return false;
}

/**
<<<<<<< HEAD
 * sap_compute_spect_weight() - Compute spectrum weight
 * @pSpectInfoParams: Pointer to the tSpectInfoParams structure
 * @halHandle: Pointer to HAL handle
=======
 * sap_upd_chan_spec_params() - sap_upd_chan_spec_params
 *  updates channel parameters obtained from Beacon
 * @scan_entry: Beacon strucutre populated by scan
 * @ch_width: Channel width
 * @sec_ch_offset: Secondary Channel Offset
 * @center_freq0: Central frequency 0 for the given channel
 * @center_freq1: Central frequency 1 for the given channel
 *
 * sap_upd_chan_spec_params updates the spectrum channels based on the
 * scan_entry
 *
 * Return: NA.
 */
static void
sap_upd_chan_spec_params(struct scan_cache_node *scan_entry,
			 tSirMacHTChannelWidth *ch_width,
			 uint16_t *sec_ch_offset,
			 uint32_t *center_freq0,
			 uint32_t *center_freq1)
{
	enum wlan_phymode phy_mode;
	struct channel_info *chan;

	phy_mode = util_scan_entry_phymode(scan_entry->entry);
	chan = util_scan_entry_channel(scan_entry->entry);

	if (IS_WLAN_PHYMODE_160MHZ(phy_mode)) {
		if (phy_mode == WLAN_PHYMODE_11AC_VHT80_80 ||
		    phy_mode == WLAN_PHYMODE_11AXA_HE80_80) {
			*ch_width = eHT_CHANNEL_WIDTH_80P80MHZ;
			*center_freq0 = chan->cfreq0;
			*center_freq1 = chan->cfreq1;
		} else {
			*ch_width = eHT_CHANNEL_WIDTH_160MHZ;
			if (chan->cfreq1)
				*center_freq0 = chan->cfreq1;
			else
				*center_freq0 = chan->cfreq0;
		}

	} else if (IS_WLAN_PHYMODE_80MHZ(phy_mode)) {
		*ch_width = eHT_CHANNEL_WIDTH_80MHZ;
		*center_freq0 = chan->cfreq0;
	} else if (IS_WLAN_PHYMODE_40MHZ(phy_mode)) {
		if (chan->cfreq0 > chan->chan_freq)
			*sec_ch_offset = PHY_DOUBLE_CHANNEL_LOW_PRIMARY;
		else
			*sec_ch_offset = PHY_DOUBLE_CHANNEL_HIGH_PRIMARY;
		*ch_width = eHT_CHANNEL_WIDTH_40MHZ;
		*center_freq0 = chan->cfreq0;
	} else {
		*ch_width = eHT_CHANNEL_WIDTH_20MHZ;
	}
}

/**
 * sap_compute_spect_weight() - Compute spectrum weight
 * @pSpectInfoParams: Pointer to the tSpectInfoParams structure
 * @mac_handle: Opaque handle to the global MAC context
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 * @pResult: Pointer to tScanResultHandle
 * @sap_ctx: Context of the SAP
 *
 * Main function for computing the weight of each channel in the
 * spectrum based on the RSSI value of the BSSes on the channel
 * and number of BSS
 */
static void sap_compute_spect_weight(tSapChSelSpectInfo *pSpectInfoParams,
<<<<<<< HEAD
				     tHalHandle halHandle,
				     tScanResultHandle pResult,
				     ptSapContext sap_ctx)
{
	int8_t rssi = 0;
	uint8_t chn_num = 0;
	uint8_t channel_id = 0;
	uint8_t i;
	bool found;

	tCsrScanResultInfo *pScanResult;
	tSapSpectChInfo *pSpectCh = pSpectInfoParams->pSpectCh;
	uint32_t operatingBand;
	uint16_t channelWidth;
	uint16_t secondaryChannelOffset;
	uint16_t centerFreq;
	uint16_t centerFreq_2 = 0;
	uint16_t vhtSupport;
	uint32_t ieLen = 0;
	tSirProbeRespBeacon *pBeaconStruct;
	tpAniSirGlobal pMac = (tpAniSirGlobal) halHandle;
	tSapSpectChInfo *spectch_start = pSpectInfoParams->pSpectCh;
	tSapSpectChInfo *spectch_end = pSpectInfoParams->pSpectCh +
		pSpectInfoParams->numSpectChans;

	pBeaconStruct = qdf_mem_malloc(sizeof(tSirProbeRespBeacon));
	if (NULL == pBeaconStruct) {
		QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
			  "Unable to allocate memory in sap_compute_spect_weight");
		return;
	}
	QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
		  "In %s, Computing spectral weight", __func__);

	/**
	 * Soft AP specific channel weight calculation using DFS formula
	 */
	SET_ACS_BAND(operatingBand, sap_ctx);

	pScanResult = sme_scan_result_get_first(halHandle, pResult);

	while (pScanResult) {
		pSpectCh = pSpectInfoParams->pSpectCh;
		/* Defining the default values, so that any value will hold the default values */
		channelWidth = eHT_CHANNEL_WIDTH_20MHZ;
		secondaryChannelOffset = PHY_SINGLE_CHANNEL_CENTERED;
		vhtSupport = 0;
		centerFreq = 0;


		ieLen = GET_IE_LEN_IN_BSS(
				pScanResult->BssDescriptor.length);
		qdf_mem_set((uint8_t *) pBeaconStruct,
				   sizeof(tSirProbeRespBeacon), 0);


		if ((sir_parse_beacon_ie
		     (pMac, pBeaconStruct, (uint8_t *)
		      (pScanResult->BssDescriptor.ieFields),
		      ieLen)) == eSIR_SUCCESS)
			sap_upd_chan_spec_params(
				pBeaconStruct,
				&channelWidth,
				&secondaryChannelOffset,
				&vhtSupport, &centerFreq,
				&centerFreq_2);
=======
				     mac_handle_t mac_handle,
				     qdf_list_t *scan_list,
				     struct sap_context *sap_ctx)
{
	int8_t rssi = 0;
	uint8_t chn_num = 0;
	tSapSpectChInfo *pSpectCh = pSpectInfoParams->pSpectCh;
	tSirMacHTChannelWidth ch_width = 0;
	uint16_t secondaryChannelOffset;
	uint32_t center_freq0, center_freq1;
	uint8_t i;
	bool found;
	struct mac_context *mac = MAC_CONTEXT(mac_handle);
	tSapSpectChInfo *spectch_start = pSpectInfoParams->pSpectCh;
	tSapSpectChInfo *spectch_end = pSpectInfoParams->pSpectCh +
		pSpectInfoParams->numSpectChans;
	qdf_list_node_t *cur_lst = NULL, *next_lst = NULL;
	struct scan_cache_node *cur_node = NULL;
	uint32_t normalized_weight;
	uint8_t normalize_factor;
	uint32_t chan_freq;
	struct acs_weight *weight_list =
				mac->mlme_cfg->acs.normalize_weight_chan;
	struct acs_weight_range *range_list =
				mac->mlme_cfg->acs.normalize_weight_range;
	bool freq_present_in_list = false;

	QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
		  "In %s, Computing spectral weight", __func__);

	if (scan_list)
		qdf_list_peek_front(scan_list, &cur_lst);
	while (cur_lst) {
		cur_node = qdf_container_of(cur_lst, struct scan_cache_node,
					    node);
		pSpectCh = pSpectInfoParams->pSpectCh;
		/* Defining the default values, so that any value will hold the default values */

		secondaryChannelOffset = PHY_SINGLE_CHANNEL_CENTERED;
		center_freq0 = 0;
		center_freq1 = 0;

		chan_freq =
		    util_scan_entry_channel_frequency(cur_node->entry);

		sap_upd_chan_spec_params(cur_node, &ch_width,
					 &secondaryChannelOffset,
					 &center_freq0, &center_freq1);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

		/* Processing for each tCsrScanResultInfo in the tCsrScanResult DLink list */
		for (chn_num = 0; chn_num < pSpectInfoParams->numSpectChans;
		     chn_num++) {

<<<<<<< HEAD
			/*
			 * If the Beacon has channel ID, use it other wise we
			 * will rely on the channelIdSelf
			 */
			if (pScanResult->BssDescriptor.channelId == 0)
				channel_id =
				      pScanResult->BssDescriptor.channelIdSelf;
			else
				channel_id =
				      pScanResult->BssDescriptor.channelId;

			if (pSpectCh && (channel_id == pSpectCh->chNum)) {
				if (pSpectCh->rssiAgr <
				    pScanResult->BssDescriptor.rssi)
					pSpectCh->rssiAgr =
						pScanResult->BssDescriptor.rssi;

				++pSpectCh->bssCount;   /* Increment the count of BSS */

				/*
				 * Connsidering the Extension Channel
				 * only in a channels
				 */
				switch (operatingBand) {
				case eCSR_DOT11_MODE_11a:
					sap_interference_rssi_count_5G(
					    pSpectCh, channelWidth,
					    secondaryChannelOffset,
					    centerFreq,
					    centerFreq_2,
					    channel_id,
					    spectch_start,
					    spectch_end);
					break;

				case eCSR_DOT11_MODE_11g:
					sap_interference_rssi_count(pSpectCh,
						spectch_start, spectch_end);
					break;

				case eCSR_DOT11_MODE_abg:
					if (pSpectCh->chNum >=
					    SIR_11A_CHANNEL_BEGIN)
						sap_interference_rssi_count_5G(
						    pSpectCh, channelWidth,
						    secondaryChannelOffset,
						    centerFreq,
						    centerFreq_2,
						    channel_id,
						    spectch_start,
						    spectch_end);
					else
						sap_interference_rssi_count(
						    pSpectCh,
						    spectch_start,
						    spectch_end);
					break;
				}

				QDF_TRACE(QDF_MODULE_ID_SAP,
					  QDF_TRACE_LEVEL_INFO_HIGH,
					  "In %s, bssdes.ch_self=%d, bssdes.ch_ID=%d, bssdes.rssi=%d, SpectCh.bssCount=%d, pScanResult=%pK, ChannelWidth %d, secondaryChanOffset %d, center frequency %d",
					  __func__,
					  pScanResult->BssDescriptor.
					  channelIdSelf,
					  pScanResult->BssDescriptor.channelId,
					  pScanResult->BssDescriptor.rssi,
					  pSpectCh->bssCount, pScanResult,
					  pSpectCh->channelWidth,
					  secondaryChannelOffset, centerFreq);
				pSpectCh++;
				break;
			} else {
				pSpectCh++;
			}
		}

		pScanResult = sme_scan_result_get_next(halHandle, pResult);
=======
			if (chan_freq != pSpectCh->chan_freq) {
				pSpectCh++;
				continue;
			}

			if (pSpectCh->rssiAgr < cur_node->entry->rssi_raw)
				pSpectCh->rssiAgr = cur_node->entry->rssi_raw;

			++pSpectCh->bssCount;

			if (WLAN_REG_IS_24GHZ_CH_FREQ(chan_freq))
				sap_interference_rssi_count(pSpectCh,
					spectch_start, spectch_end);
			else
				sap_interference_rssi_count_5G(
				    pSpectCh, ch_width, secondaryChannelOffset,
				    center_freq0, center_freq1, chan_freq,
				    spectch_start, spectch_end);

			pSpectCh++;
			break;

		}

		qdf_list_peek_next(scan_list, cur_lst, &next_lst);
		cur_lst = next_lst;
		next_lst = NULL;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	}

	/* Calculate the weights for all channels in the spectrum pSpectCh */
	pSpectCh = pSpectInfoParams->pSpectCh;

<<<<<<< HEAD
	QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
		  "In %s, Spectrum Channels Weight", __func__);

=======
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	for (chn_num = 0; chn_num < (pSpectInfoParams->numSpectChans);
	     chn_num++) {

		/*
		   rssi : Maximum received signal strength among all BSS on that channel
		   bssCount : Number of BSS on that channel
		 */

		rssi = (int8_t) pSpectCh->rssiAgr;
<<<<<<< HEAD
		if (ch_in_pcl(sap_ctx, pSpectCh->chNum))
=======
		if (ch_in_pcl(sap_ctx, pSpectCh->chan_freq))
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			rssi -= PCL_RSSI_DISCOUNT;

		if (rssi < SOFTAP_MIN_RSSI)
			rssi = SOFTAP_MIN_RSSI;

		if (pSpectCh->weight == SAP_ACS_WEIGHT_MAX) {
			pSpectCh->weight_copy = pSpectCh->weight;
			goto debug_info;
		}

		/* There may be channels in scanlist, which were not sent to
		 * FW for scanning as part of ACS scan list, but they do have an
		 * effect on the neighbouring channels, so they help to find a
		 * suitable channel, but there weight should be max as they were
		 * and not meant to be included in the ACS scan results.
		 * So just assign RSSI as -100, bsscount as 0, and weight as max
		 * to them, so that they always stay low in sorting of best
<<<<<<< HEAD
		 * channels which were included in ACS scan list
		 */
		found = false;
		for (i = 0; i < sap_ctx->num_of_channel; i++) {
			if (pSpectCh->chNum == sap_ctx->channelList[i]) {
=======
		 * channles which were included in ACS scan list
		 */
		found = false;
		for (i = 0; i < sap_ctx->num_of_channel; i++) {
			if (pSpectCh->chan_freq == sap_ctx->freq_list[i]) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			/* Scan channel was included in ACS scan list */
				found = true;
				break;
			}
		}

		if (found)
			pSpectCh->weight =
				SAPDFS_NORMALISE_1000 *
				(sapweight_rssi_count(sap_ctx, rssi,
				pSpectCh->bssCount) + sap_weight_channel_status(
<<<<<<< HEAD
				sap_ctx, sap_get_channel_status(pMac,
							 pSpectCh->chNum)));
=======
				sap_ctx, sap_get_channel_status(mac,
							 pSpectCh->chan_freq)));
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		else {
			pSpectCh->weight = SAP_ACS_WEIGHT_MAX;
			pSpectCh->rssiAgr = SOFTAP_MIN_RSSI;
			rssi = SOFTAP_MIN_RSSI;
			pSpectCh->bssCount = SOFTAP_MIN_COUNT;
		}

<<<<<<< HEAD
=======
		chan_freq = pSpectCh->chan_freq;

		if (wlan_reg_is_dfs_for_freq(mac->pdev, chan_freq)) {
			normalize_factor =
				MLME_GET_DFS_CHAN_WEIGHT(
				mac->mlme_cfg->acs.np_chan_weightage);
			freq_present_in_list = true;
		}
		/* Check if the freq is present in range list */
		for (i = 0; i < mac->mlme_cfg->acs.num_weight_range; i++) {
			if (chan_freq >= range_list[i].start_freq &&
			    chan_freq <= range_list[i].end_freq) {
				normalize_factor =
					range_list[i].normalize_weight;
				sap_debug("Range list, freq %d normalize weight factor %d",
					  chan_freq, normalize_factor);
				freq_present_in_list = true;
			}
		}

		/* Check if user wants a special factor for this freq */

		for (i = 0; i < mac->mlme_cfg->acs.normalize_weight_num_chan;
		     i++) {
			if (chan_freq == weight_list[i].chan_freq) {
				normalize_factor =
					weight_list[i].normalize_weight;
				sap_debug("freq %d normalize weight factor %d",
					  chan_freq, normalize_factor);
				freq_present_in_list = true;
			}
		}

		if (freq_present_in_list) {
			normalized_weight =
				((SAP_ACS_WEIGHT_MAX - pSpectCh->weight) *
				(100 - normalize_factor)) / 100;
			sap_debug("freq %d old weight %d new weight %d",
				  chan_freq, pSpectCh->weight,
				  pSpectCh->weight + normalized_weight);
			pSpectCh->weight += normalized_weight;
			freq_present_in_list = false;
		}

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		if (pSpectCh->weight > SAP_ACS_WEIGHT_MAX)
			pSpectCh->weight = SAP_ACS_WEIGHT_MAX;
		pSpectCh->weight_copy = pSpectCh->weight;

debug_info:
<<<<<<< HEAD
		/* ------ Debug Info ------ */
		QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
			  "In %s, Chan=%d Weight= %d rssiAgr=%d, rssi_pcl_discount: %d, bssCount=%d",
			  __func__, pSpectCh->chNum, pSpectCh->weight,
			  pSpectCh->rssiAgr, rssi, pSpectCh->bssCount);
		/* ------ Debug Info ------ */
		pSpectCh++;
	}
	sap_clear_channel_status(pMac);
	qdf_mem_free(pBeaconStruct);
=======
		sap_debug("freq = %d, weight = %d rssi = %d bss count = %d",
			   pSpectCh->chan_freq, pSpectCh->weight,
			  pSpectCh->rssiAgr, pSpectCh->bssCount);

		pSpectCh++;
	}
	sap_clear_channel_status(mac);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/*==========================================================================
   FUNCTION    sap_chan_sel_exit

   DESCRIPTION
    Exit function for free out the allocated memory, to be called
    at the end of the dfsSelectChannel function

   DEPENDENCIES
    NA.

   PARAMETERS

    IN
    pSpectInfoParams       : Pointer to the tSapChSelSpectInfo structure

   RETURN VALUE
    void     : NULL

   SIDE EFFECTS
   ============================================================================*/
static void sap_chan_sel_exit(tSapChSelSpectInfo *pSpectInfoParams)
{
	/* Free all the allocated memory */
	qdf_mem_free(pSpectInfoParams->pSpectCh);
}

/*==========================================================================
   FUNCTION    sap_sort_chl_weight

   DESCRIPTION
<<<<<<< HEAD
    Funtion to sort the channels with the least weight first for 20MHz channels
=======
    Function to sort the channels with the least weight first for 20MHz channels
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

   DEPENDENCIES
    NA.

   PARAMETERS

    IN
    pSpectInfoParams       : Pointer to the tSapChSelSpectInfo structure

   RETURN VALUE
    void     : NULL

   SIDE EFFECTS
   ============================================================================*/
static void sap_sort_chl_weight(tSapChSelSpectInfo *pSpectInfoParams)
{
	tSapSpectChInfo temp;

	tSapSpectChInfo *pSpectCh = NULL;
	uint32_t i = 0, j = 0, minWeightIndex = 0;

	pSpectCh = pSpectInfoParams->pSpectCh;
	for (i = 0; i < pSpectInfoParams->numSpectChans; i++) {
		minWeightIndex = i;
		for (j = i + 1; j < pSpectInfoParams->numSpectChans; j++) {
			if (pSpectCh[j].weight <
			    pSpectCh[minWeightIndex].weight) {
				minWeightIndex = j;
			} else if (pSpectCh[j].weight ==
				   pSpectCh[minWeightIndex].weight) {
				if (pSpectCh[j].bssCount <
				    pSpectCh[minWeightIndex].bssCount)
					minWeightIndex = j;
			}
		}
		if (minWeightIndex != i) {
			qdf_mem_copy(&temp, &pSpectCh[minWeightIndex],
				     sizeof(*pSpectCh));
			qdf_mem_copy(&pSpectCh[minWeightIndex], &pSpectCh[i],
				     sizeof(*pSpectCh));
			qdf_mem_copy(&pSpectCh[i], &temp, sizeof(*pSpectCh));
		}
	}
}

/**
<<<<<<< HEAD
 * set_ht80_chl_bit() - to set availabe channel to ht80 channel bitmap
 * @channel_bitmap: Pointer to the chan_bonding_bitmap structure
 * @spect_info_params: Pointer to the tSapChSelSpectInfo structure
 *
 * Return: none
 */
static void set_ht80_chl_bit(chan_bonding_bitmap *channel_bitmap,
			     tSapChSelSpectInfo *spec_info_params)
{
	uint8_t i, j;
	tSapSpectChInfo *spec_info;
	int start_channel = 0;

	channel_bitmap->chanBondingSet[0].startChannel =
			acs_ht80_channels[0].chStartNum;
	channel_bitmap->chanBondingSet[1].startChannel =
			acs_ht80_channels[1].chStartNum;
	channel_bitmap->chanBondingSet[2].startChannel =
			acs_ht80_channels[2].chStartNum;
	channel_bitmap->chanBondingSet[3].startChannel =
			acs_ht80_channels[3].chStartNum;
	channel_bitmap->chanBondingSet[4].startChannel =
			acs_ht80_channels[4].chStartNum;
	channel_bitmap->chanBondingSet[5].startChannel =
			acs_ht80_channels[5].chStartNum;

	spec_info = spec_info_params->pSpectCh;
	for (j = 0; j < spec_info_params->numSpectChans; j++) {
		for (i = 0; i < MAX_80MHZ_BANDS; i++) {
			start_channel =
				channel_bitmap->chanBondingSet[i].startChannel;
			if (spec_info[j].chNum >= start_channel &&
				(spec_info[j].chNum <=
					start_channel + 12)) {
				channel_bitmap->chanBondingSet[i].channelMap |=
					1 << ((spec_info[j].chNum -
						start_channel)/4);
				break;
			}
		}
	}
}

/**
 * sap_sort_chl_weight_ht80() - to sort the channels with the least weight
 * @pSpectInfoParams: Pointer to the tSapChSelSpectInfo structure
 *
 * Funtion to sort the channels with the least weight first for HT80 channels
 *
 * Return: none
 */
static void sap_sort_chl_weight_ht80(tSapChSelSpectInfo *pSpectInfoParams)
{
	uint8_t i, j, n;
	tSapSpectChInfo *pSpectInfo;
	uint8_t minIdx;
	int start_channel = 0;
	chan_bonding_bitmap *channel_bitmap;

	channel_bitmap = qdf_mem_malloc(sizeof(chan_bonding_bitmap));
	if (NULL == channel_bitmap) {
		QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
			  "%s: Failed to allocate memory", __func__);
		return;
	}
	pSpectInfo = pSpectInfoParams->pSpectCh;
	/* for each HT80 channel, calculate the combined weight of the
	   four 20MHz weight */
	for (i = 0; i < ARRAY_SIZE(acs_ht80_channels); i++) {
		for (j = 0; j < pSpectInfoParams->numSpectChans; j++) {
			if (pSpectInfo[j].chNum ==
					acs_ht80_channels[i].chStartNum)
				break;
		}
		if (j == pSpectInfoParams->numSpectChans)
			continue;

		if (!(((pSpectInfo[j].chNum + 4) == pSpectInfo[j + 1].chNum) &&
			((pSpectInfo[j].chNum + 8) ==
				 pSpectInfo[j + 2].chNum) &&
			((pSpectInfo[j].chNum + 12) ==
				 pSpectInfo[j + 3].chNum))) {
=======
 * sap_sort_chl_weight_80_mhz() - to sort the channels with the least weight
 * @pSpectInfoParams: Pointer to the tSapChSelSpectInfo structure
 * Function to sort the channels with the least weight first for HT80 channels
 *
 * Return: none
 */
static void sap_sort_chl_weight_80_mhz(struct mac_context *mac_ctx,
				       tSapChSelSpectInfo *pSpectInfoParams)
{
	uint8_t i, j;
	tSapSpectChInfo *pSpectInfo;
	uint8_t minIdx;
	struct ch_params acs_ch_params;
	int8_t center_freq_diff;
	uint32_t combined_weight;
	uint32_t min_ch_weight;

	pSpectInfo = pSpectInfoParams->pSpectCh;

	for (j = 0; j < pSpectInfoParams->numSpectChans; j++) {

		if (pSpectInfo[j].weight_calc_done)
			continue;

		acs_ch_params.ch_width = CH_WIDTH_80MHZ;

		wlan_reg_set_channel_params_for_freq(mac_ctx->pdev,
						     pSpectInfo[j].chan_freq,
						     0, &acs_ch_params);

		/* Check if the freq supports 80 Mhz */
		if (acs_ch_params.ch_width != CH_WIDTH_80MHZ) {
			pSpectInfo[j].weight = SAP_ACS_WEIGHT_MAX * 4;
			pSpectInfo[j].weight_calc_done = true;
			continue;
		}

		center_freq_diff = acs_ch_params.mhz_freq_seg0 -
				   pSpectInfo[j].chan_freq;

		/* This channel frequency does not have all channels */
		if (center_freq_diff != 30) {
			pSpectInfo[j].weight = SAP_ACS_WEIGHT_MAX * 4;
			pSpectInfo[j].weight_calc_done = true;
			continue;
		}

		/* no other freq left for 80 Mhz operation in spectrum */
		if (j + 3 > pSpectInfoParams->numSpectChans)
			continue;

		/* Check whether all frequencies are present for 80 Mhz */

		if (!(((pSpectInfo[j].chan_freq + 20) ==
			pSpectInfo[j + 1].chan_freq) &&
			((pSpectInfo[j].chan_freq + 40) ==
				 pSpectInfo[j + 2].chan_freq) &&
			((pSpectInfo[j].chan_freq + 60) ==
				 pSpectInfo[j + 3].chan_freq))) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			/*
			 * some channels does not exist in pSectInfo array,
			 * skip this channel and those in the same HT80 width
			 */
			pSpectInfo[j].weight = SAP_ACS_WEIGHT_MAX * 4;
<<<<<<< HEAD
			if ((pSpectInfo[j].chNum + 4) ==
					pSpectInfo[j + 1].chNum)
				pSpectInfo[j + 1].weight =
					SAP_ACS_WEIGHT_MAX * 4;
			if ((pSpectInfo[j].chNum + 8) ==
					pSpectInfo[j + 2].chNum)
				pSpectInfo[j + 2].weight =
					SAP_ACS_WEIGHT_MAX * 4;
			if ((pSpectInfo[j].chNum + 12) ==
					pSpectInfo[j + 3].chNum)
				pSpectInfo[j + 3].weight =
					SAP_ACS_WEIGHT_MAX * 4;
			continue;
		}
		/*found the channel, add the 4 adjacent channels' weight */
		acs_ht80_channels[i].weight = pSpectInfo[j].weight +
			pSpectInfo[j + 1].weight + pSpectInfo[j + 2].weight +
			pSpectInfo[j + 3].weight;
		/* find best channel among 4 channels as the primary channel */
		if ((pSpectInfo[j].weight + pSpectInfo[j + 1].weight) <
			(pSpectInfo[j + 2].weight + pSpectInfo[j + 3].weight)) {
			/* lower 2 channels are better choice */
			if (pSpectInfo[j].weight < pSpectInfo[j + 1].weight)
				minIdx = 0;
			else
				minIdx = 1;
		} else if (pSpectInfo[j + 2].weight <=
				pSpectInfo[j + 3].weight) {
			/* upper 2 channels are better choice */
			minIdx = 2;
		} else {
			minIdx = 3;
		}

		/*
		 * set all 4 channels to max value first, then reset the
		 * best channel as the selected primary channel, update its
		 * weightage with the combined weight value
		 */
		for (n = 0; n < 4; n++)
			pSpectInfo[j + n].weight = SAP_ACS_WEIGHT_MAX * 4;

		pSpectInfo[j + minIdx].weight = acs_ht80_channels[i].weight;
	}

	/*
	 * mark the weight of the channel that can't satisfy 80MHZ
	 * as max value, so that it will be sorted to the bottom
	 */
	set_ht80_chl_bit(channel_bitmap, pSpectInfoParams);
	for (j = 0; j < pSpectInfoParams->numSpectChans; j++) {
		for (i = 0; i < MAX_80MHZ_BANDS; i++) {
			start_channel =
				channel_bitmap->chanBondingSet[i].startChannel;
			if (pSpectInfo[j].chNum >= start_channel &&
				(pSpectInfo[j].chNum <=
					start_channel + 12) &&
				channel_bitmap->chanBondingSet[i].channelMap !=
					SAP_80MHZ_MASK)
				pSpectInfo[j].weight = SAP_ACS_WEIGHT_MAX * 4;
		}
	}

	/*
	 * Assign max weight(SAP_ACS_WEIGHT_MAX * 4) to 2.4 Ghz channels
	 * and channel 165 as they cannot be part of a 80Mhz channel bonding.
	 */
	pSpectInfo = pSpectInfoParams->pSpectCh;
	for (j = 0; j < pSpectInfoParams->numSpectChans; j++) {
		if ((pSpectInfo[j].chNum >= CDS_CHANNEL_NUM(CHAN_ENUM_1) &&
		     pSpectInfo[j].chNum <= CDS_CHANNEL_NUM(CHAN_ENUM_14)) ||
		    (CHANNEL_165 == pSpectInfo[j].chNum))
			pSpectInfo[j].weight = SAP_ACS_WEIGHT_MAX * 4;
=======
			pSpectInfo[j].weight_calc_done = true;
			if ((pSpectInfo[j].chan_freq + 20) ==
					pSpectInfo[j + 1].chan_freq) {
				pSpectInfo[j + 1].weight =
					SAP_ACS_WEIGHT_MAX * 4;
				pSpectInfo[j +1].weight_calc_done = true;
			}
			if ((pSpectInfo[j].chan_freq + 40) ==
					pSpectInfo[j + 2].chan_freq) {
				pSpectInfo[j + 2].weight =
					SAP_ACS_WEIGHT_MAX * 4;
				pSpectInfo[j +2].weight_calc_done = true;
			}
			if ((pSpectInfo[j].chan_freq + 60) ==
					pSpectInfo[j + 3].chan_freq) {
				pSpectInfo[j + 3].weight =
					SAP_ACS_WEIGHT_MAX * 4;
				pSpectInfo[j +3].weight_calc_done = true;
			}

			continue;
		}

		/* We have 4 channels to calculate cumulative weight */

		combined_weight = pSpectInfo[j].weight +
				  pSpectInfo[j + 1].weight +
				  pSpectInfo[j + 2].weight +
				  pSpectInfo[j + 3].weight;

		min_ch_weight = pSpectInfo[j].weight;
		minIdx = 0;

		for (i = 0; i < 4; i++) {
			if (min_ch_weight > pSpectInfo[j + i].weight) {
				min_ch_weight = pSpectInfo[j + i].weight;
				minIdx = i;
			}
			pSpectInfo[j + i].weight = SAP_ACS_WEIGHT_MAX * 4;
			pSpectInfo[j + i].weight_calc_done = true;
		}

		pSpectInfo[j + minIdx].weight = combined_weight;

		sap_debug("best freq = %d for 80mhz center freq %d combined weight = %d",
			  pSpectInfo[j + minIdx].chan_freq,
			  acs_ch_params.mhz_freq_seg0,
			  combined_weight);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	}

	sap_sort_chl_weight(pSpectInfoParams);

	pSpectInfo = pSpectInfoParams->pSpectCh;
<<<<<<< HEAD
	for (j = 0; j < (pSpectInfoParams->numSpectChans); j++) {
		QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
			FL("Channel=%d Weight= %d rssi=%d bssCount=%d"),
			pSpectInfo->chNum, pSpectInfo->weight,
			pSpectInfo->rssiAgr, pSpectInfo->bssCount);
		pSpectInfo++;
	}
	qdf_mem_free(channel_bitmap);
=======

	for (j = 0; j < (pSpectInfoParams->numSpectChans); j++) {
		sap_debug("freq = %d weight = %d rssi = %d bss count = %d",
			  pSpectInfo->chan_freq, pSpectInfo->weight,
			  pSpectInfo->rssiAgr, pSpectInfo->bssCount);

		pSpectInfo++;
	}
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/**
 * sap_sort_chl_weight_vht160() - to sort the channels with the least weight
 * @pSpectInfoParams: Pointer to the tSapChSelSpectInfo structure
 *
<<<<<<< HEAD
 * Funtion to sort the channels with the least weight first for VHT160 channels
 *
 * Return: none
 */
static void sap_sort_chl_weight_vht160(tSapChSelSpectInfo *pSpectInfoParams)
{
	uint8_t i, j, n, idx;
	tSapSpectChInfo *pSpectInfo;
	uint8_t minIdx;

	pSpectInfo = pSpectInfoParams->pSpectCh;
	/* for each VHT160 channel, calculate the combined weight of the
	   8 20MHz weight */
	for (i = 0; i < ARRAY_SIZE(acs_vht160_channels); i++) {
		for (j = 0; j < pSpectInfoParams->numSpectChans; j++) {
			if (pSpectInfo[j].chNum ==
					acs_vht160_channels[i].chStartNum)
				break;
		}
		if (j == pSpectInfoParams->numSpectChans)
			continue;

		if (!(((pSpectInfo[j].chNum + 4) == pSpectInfo[j + 1].chNum) &&
			((pSpectInfo[j].chNum + 8) ==
				 pSpectInfo[j + 2].chNum) &&
			((pSpectInfo[j].chNum + 12) ==
				 pSpectInfo[j + 3].chNum) &&
			((pSpectInfo[j].chNum + 16) ==
				 pSpectInfo[j + 4].chNum) &&
			((pSpectInfo[j].chNum + 20) ==
				 pSpectInfo[j + 5].chNum) &&
			((pSpectInfo[j].chNum + 24) ==
				 pSpectInfo[j + 6].chNum) &&
			((pSpectInfo[j].chNum + 28) ==
				 pSpectInfo[j + 7].chNum))) {
=======
 * Function to sort the channels with the least weight first for VHT160 channels
 *
 * Return: none
 */
static void sap_sort_chl_weight_160_mhz(struct mac_context *mac_ctx,
					tSapChSelSpectInfo *pSpectInfoParams)
{
	uint8_t i, j;
	tSapSpectChInfo *pSpectInfo;
	uint8_t minIdx;
	struct ch_params acs_ch_params;
	int8_t center_freq_diff;
	uint32_t combined_weight;
	uint32_t min_ch_weight;

	pSpectInfo = pSpectInfoParams->pSpectCh;

	for (j = 0; j < pSpectInfoParams->numSpectChans; j++) {

		if (pSpectInfo[j].weight_calc_done)
			continue;

		acs_ch_params.ch_width = CH_WIDTH_160MHZ;

		wlan_reg_set_channel_params_for_freq(mac_ctx->pdev,
						     pSpectInfo[j].chan_freq,
						     0, &acs_ch_params);

		/* Check if the freq supports 160 Mhz */
		if (acs_ch_params.ch_width != CH_WIDTH_160MHZ) {
			pSpectInfo[j].weight = SAP_ACS_WEIGHT_MAX * 8;
			pSpectInfo[j].weight_calc_done = true;
			continue;
		}

		center_freq_diff = acs_ch_params.mhz_freq_seg1 -
				   pSpectInfo[j].chan_freq;

		/* This channel frequency does not have all channels */
		if (center_freq_diff != 70) {
			pSpectInfo[j].weight = SAP_ACS_WEIGHT_MAX * 8;
			pSpectInfo[j].weight_calc_done = true;
			continue;
		}

		/* no other freq left for 160 Mhz operation in spectrum */
		if (j + 7 > pSpectInfoParams->numSpectChans)
			continue;

		/* Check whether all frequencies are present for 160 Mhz */

		if (!(((pSpectInfo[j].chan_freq + 20) ==
			pSpectInfo[j + 1].chan_freq) &&
			((pSpectInfo[j].chan_freq + 40) ==
				 pSpectInfo[j + 2].chan_freq) &&
			((pSpectInfo[j].chan_freq + 60) ==
				 pSpectInfo[j + 3].chan_freq) &&
			((pSpectInfo[j].chan_freq + 80) ==
				 pSpectInfo[j + 4].chan_freq) &&
			((pSpectInfo[j].chan_freq + 100) ==
				 pSpectInfo[j + 5].chan_freq) &&
			((pSpectInfo[j].chan_freq + 120) ==
				 pSpectInfo[j + 6].chan_freq) &&
			((pSpectInfo[j].chan_freq + 140) ==
				 pSpectInfo[j + 7].chan_freq))) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			/*
			 * some channels does not exist in pSectInfo array,
			 * skip this channel and those in the same VHT160 width
			 */
			pSpectInfo[j].weight = SAP_ACS_WEIGHT_MAX * 8;
<<<<<<< HEAD
			if ((pSpectInfo[j].chNum + 4) ==
					pSpectInfo[j + 1].chNum)
				pSpectInfo[j + 1].weight =
					SAP_ACS_WEIGHT_MAX * 8;
			if ((pSpectInfo[j].chNum + 8) ==
					pSpectInfo[j + 2].chNum)
				pSpectInfo[j + 2].weight =
					SAP_ACS_WEIGHT_MAX * 8;
			if ((pSpectInfo[j].chNum + 12) ==
					pSpectInfo[j + 3].chNum)
				pSpectInfo[j + 3].weight =
					SAP_ACS_WEIGHT_MAX * 8;
			if ((pSpectInfo[j].chNum + 16) ==
					pSpectInfo[j + 4].chNum)
				pSpectInfo[j + 4].weight =
					SAP_ACS_WEIGHT_MAX * 8;
			if ((pSpectInfo[j].chNum + 20) ==
					pSpectInfo[j + 5].chNum)
				pSpectInfo[j + 5].weight =
					SAP_ACS_WEIGHT_MAX * 8;
			if ((pSpectInfo[j].chNum + 24) ==
					pSpectInfo[j + 6].chNum)
				pSpectInfo[j + 6].weight =
					SAP_ACS_WEIGHT_MAX * 8;
			if ((pSpectInfo[j].chNum + 28) ==
					pSpectInfo[j + 7].chNum)
				pSpectInfo[j + 7].weight =
					SAP_ACS_WEIGHT_MAX * 8;
			continue;
		}
		/*found the channel, add the 7 adjacent channels' weight */
		acs_vht160_channels[i].weight = pSpectInfo[j].weight +
			pSpectInfo[j + 1].weight + pSpectInfo[j + 2].weight +
			pSpectInfo[j + 3].weight + pSpectInfo[j + 4].weight +
			pSpectInfo[j + 5].weight + pSpectInfo[j + 6].weight +
			pSpectInfo[j + 7].weight;

		/* find best channel among 8 channels as the primary channel */
		if ((pSpectInfo[j].weight + pSpectInfo[j + 1].weight +
			pSpectInfo[j + 2].weight + pSpectInfo[j + 3].weight) >
			(pSpectInfo[j + 4].weight + pSpectInfo[j + 5].weight +
			pSpectInfo[j + 6].weight + pSpectInfo[j + 7].weight))
			idx = 4;
		else
			idx = 0;
		/* find best channel among 4 channels as the primary channel */
		if ((pSpectInfo[j + idx].weight +
					pSpectInfo[j + idx + 1].weight) <
			(pSpectInfo[j + idx + 2].weight +
			 pSpectInfo[j + idx + 3].weight)) {
			/* lower 2 channels are better choice */
			if (pSpectInfo[j + idx].weight <
					pSpectInfo[j + idx + 1].weight)
				minIdx = 0 + idx;
			else
				minIdx = 1 + idx;
		} else if (pSpectInfo[j + idx + 2].weight <=
				pSpectInfo[j + idx + 3].weight) {
			/* upper 2 channels are better choice */
			minIdx = 2 + idx;
		} else {
			minIdx = 3 + idx;
		}

		/*
		 * set all 8 channels to max value first, then reset the
		 * best channel as the selected primary channel, update its
		 * weightage with the combined weight value
		 */
		for (n = 0; n < 8; n++)
			pSpectInfo[j + n].weight = SAP_ACS_WEIGHT_MAX * 8;

		pSpectInfo[j + minIdx].weight = acs_vht160_channels[i].weight;
	}

	/*
	 * Assign max weight(SAP_ACS_WEIGHT_MAX * 8) to 2.4 Ghz channels
	 * and channel 132-165 as they cannot be part of a 160Mhz channel
	 * bonding.
	 */
	pSpectInfo = pSpectInfoParams->pSpectCh;
	for (j = 0; j < pSpectInfoParams->numSpectChans; j++) {
		if ((pSpectInfo[j].chNum >= CDS_CHANNEL_NUM(CHAN_ENUM_1) &&
		     pSpectInfo[j].chNum <= CDS_CHANNEL_NUM(CHAN_ENUM_14)) ||
		    (pSpectInfo[j].chNum >= CDS_CHANNEL_NUM(CHAN_ENUM_132) &&
		     pSpectInfo[j].chNum <= CDS_CHANNEL_NUM(CHAN_ENUM_165)))
			pSpectInfo[j].weight = SAP_ACS_WEIGHT_MAX * 8;
=======
			pSpectInfo[j].weight_calc_done = true;
			if ((pSpectInfo[j].chan_freq + 20) ==
					pSpectInfo[j + 1].chan_freq) {
				pSpectInfo[j + 1].weight =
					SAP_ACS_WEIGHT_MAX * 8;
				pSpectInfo[j + 1].weight_calc_done = true;
			}
			if ((pSpectInfo[j].chan_freq + 40) ==
					pSpectInfo[j + 2].chan_freq) {
				pSpectInfo[j + 2].weight =
					SAP_ACS_WEIGHT_MAX * 8;
				pSpectInfo[j + 2].weight_calc_done = true;
			}
			if ((pSpectInfo[j].chan_freq + 60) ==
					pSpectInfo[j + 3].chan_freq) {
				pSpectInfo[j + 3].weight =
					SAP_ACS_WEIGHT_MAX * 8;
				pSpectInfo[j + 3].weight_calc_done = true;
			}
			if ((pSpectInfo[j].chan_freq + 80) ==
					pSpectInfo[j + 4].chan_freq) {
				pSpectInfo[j + 4].weight =
					SAP_ACS_WEIGHT_MAX * 8;
				pSpectInfo[j + 4].weight_calc_done = true;
			}
			if ((pSpectInfo[j].chan_freq + 100) ==
					pSpectInfo[j + 5].chan_freq) {
				pSpectInfo[j + 5].weight =
					SAP_ACS_WEIGHT_MAX * 8;
				pSpectInfo[j + 5].weight_calc_done = true;
			}
			if ((pSpectInfo[j].chan_freq + 120) ==
					pSpectInfo[j + 6].chan_freq) {
				pSpectInfo[j + 6].weight =
					SAP_ACS_WEIGHT_MAX * 8;
				pSpectInfo[j + 6].weight_calc_done = true;
			}
			if ((pSpectInfo[j].chan_freq + 140) ==
					pSpectInfo[j + 7].chan_freq) {
				pSpectInfo[j + 7].weight =
					SAP_ACS_WEIGHT_MAX * 8;
				pSpectInfo[j + 7].weight_calc_done = true;
			}

			continue;
		}


		/* We have 8 channels to calculate cumulative weight */

		combined_weight = pSpectInfo[j].weight +
				  pSpectInfo[j + 1].weight +
				  pSpectInfo[j + 2].weight +
				  pSpectInfo[j + 3].weight +
				  pSpectInfo[j + 4].weight +
				  pSpectInfo[j + 5].weight +
				  pSpectInfo[j + 6].weight +
				  pSpectInfo[j + 7].weight;

		min_ch_weight = pSpectInfo[j].weight;
		minIdx = 0;

		for (i = 0; i < 8; i++) {
			if (min_ch_weight > pSpectInfo[j + i].weight) {
				min_ch_weight = pSpectInfo[j + i].weight;
				minIdx = i;
			}
			pSpectInfo[j + i].weight = SAP_ACS_WEIGHT_MAX * 8;
			pSpectInfo[j + i].weight_calc_done = true;
		}

		pSpectInfo[j + minIdx].weight = combined_weight;

		sap_debug("best freq = %d for 160mhz center freq %d combined weight = %d",
			  pSpectInfo[j + minIdx].chan_freq,
			  acs_ch_params.mhz_freq_seg1,
			  combined_weight);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	}

	sap_sort_chl_weight(pSpectInfoParams);

	pSpectInfo = pSpectInfoParams->pSpectCh;
	for (j = 0; j < (pSpectInfoParams->numSpectChans); j++) {
<<<<<<< HEAD
		QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
			FL("Channel=%d Weight= %d rssi=%d bssCount=%d"),
			pSpectInfo->chNum, pSpectInfo->weight,
			pSpectInfo->rssiAgr, pSpectInfo->bssCount);
=======
		sap_debug("freq = %d weight = %d rssi = %d bss count = %d",
			  pSpectInfo->chan_freq, pSpectInfo->weight,
			  pSpectInfo->rssiAgr, pSpectInfo->bssCount);

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		pSpectInfo++;
	}
}

/**
 * sap_allocate_max_weight_ht40_24_g() - allocate max weight for 40Mhz
 *                                       to all 2.4Ghz channels
 * @spect_info_params: Pointer to the tSapChSelSpectInfo structure
 *
 * Return: none
 */
<<<<<<< HEAD
static void sap_allocate_max_weight_ht40_24_g(
			tSapChSelSpectInfo *spect_info_params)
=======
static void
sap_allocate_max_weight_40_mhz_24_g(tSapChSelSpectInfo *spect_info_params)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	tSapSpectChInfo *spect_info;
	uint8_t j;

	/*
	 * Assign max weight for 40Mhz (SAP_ACS_WEIGHT_MAX * 2) to all
	 * 2.4 Ghz channels
	 */
	spect_info = spect_info_params->pSpectCh;
	for (j = 0; j < spect_info_params->numSpectChans; j++) {
<<<<<<< HEAD
		if ((spect_info[j].chNum >= CDS_CHANNEL_NUM(CHAN_ENUM_1) &&
		     spect_info[j].chNum <= CDS_CHANNEL_NUM(CHAN_ENUM_14)))
=======
		if (WLAN_REG_IS_24GHZ_CH_FREQ(spect_info[j].chan_freq))
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			spect_info[j].weight = SAP_ACS_WEIGHT_MAX * 2;
	}
}

/**
 * sap_allocate_max_weight_ht40_5_g() - allocate max weight for 40Mhz
 *                                      to all 5Ghz channels
 * @spect_info_params: Pointer to the tSapChSelSpectInfo structure
 *
 * Return: none
 */
<<<<<<< HEAD
static void sap_allocate_max_weight_ht40_5_g(
			tSapChSelSpectInfo *spect_info_params)
=======
static void
sap_allocate_max_weight_40_mhz(tSapChSelSpectInfo *spect_info_params)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	tSapSpectChInfo *spect_info;
	uint8_t j;

	/*
	 * Assign max weight for 40Mhz (SAP_ACS_WEIGHT_MAX * 2) to all
	 * 5 Ghz channels
	 */
	spect_info = spect_info_params->pSpectCh;
	for (j = 0; j < spect_info_params->numSpectChans; j++) {
<<<<<<< HEAD
		if ((spect_info[j].chNum >= CDS_CHANNEL_NUM(CHAN_ENUM_36) &&
		     spect_info[j].chNum <= CDS_CHANNEL_NUM(CHAN_ENUM_165)))
=======
		if (WLAN_REG_IS_5GHZ_CH_FREQ(spect_info[j].chan_freq) ||
		    WLAN_REG_IS_6GHZ_CHAN_FREQ(spect_info[j].chan_freq))
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			spect_info[j].weight = SAP_ACS_WEIGHT_MAX * 2;
	}
}

/**
 * sap_sort_chl_weight_ht40_24_g() - to sort channel with the least weight
 * @pSpectInfoParams: Pointer to the tSapChSelSpectInfo structure
 *
<<<<<<< HEAD
 * Funtion to sort the channels with the least weight first for HT40 channels
 *
 * Return: none
 */
static void sap_sort_chl_weight_ht40_24_g(tSapChSelSpectInfo *pSpectInfoParams)
=======
 * Function to sort the channels with the least weight first for HT40 channels
 *
 * Return: none
 */
static void sap_sort_chl_weight_ht40_24_g(struct mac_context *mac_ctx,
					  tSapChSelSpectInfo *pSpectInfoParams,
					  v_REGDOMAIN_t domain)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	uint8_t i, j;
	tSapSpectChInfo *pSpectInfo;
	uint32_t tmpWeight1, tmpWeight2;
	uint32_t ht40plus2gendch = 0;
<<<<<<< HEAD
=======
	uint32_t channel;
	uint32_t chan_freq;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	pSpectInfo = pSpectInfoParams->pSpectCh;
	/*
	 * for each HT40 channel, calculate the combined weight of the
	 * two 20MHz weight
	 */
	for (i = 0; i < ARRAY_SIZE(acs_ht40_channels24_g); i++) {
		for (j = 0; j < pSpectInfoParams->numSpectChans; j++) {
<<<<<<< HEAD
			if (pSpectInfo[j].chNum ==
				acs_ht40_channels24_g[i].chStartNum)
=======
			channel = wlan_freq_to_chan(pSpectInfo[j].chan_freq);
			if (channel == acs_ht40_channels24_g[i].chStartNum)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				break;
		}
		if (j == pSpectInfoParams->numSpectChans)
			continue;

<<<<<<< HEAD
		if (!((pSpectInfo[j].chNum + 4) == pSpectInfo[j + 4].chNum)) {
=======
		if (!((pSpectInfo[j].chan_freq + 20) ==
		       pSpectInfo[j + 4].chan_freq)) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			pSpectInfo[j].weight = SAP_ACS_WEIGHT_MAX * 2;
			continue;
		}
		/*
		 * check if there is another channel combination possiblity
		 * e.g., {1, 5} & {5, 9}
		 */
<<<<<<< HEAD
		if ((pSpectInfo[j + 4].chNum + 4) == pSpectInfo[j + 8].chNum) {
=======
		if ((pSpectInfo[j + 4].chan_freq + 20) ==
		     pSpectInfo[j + 8].chan_freq) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			/* need to compare two channel pairs */
			tmpWeight1 = pSpectInfo[j].weight +
						pSpectInfo[j + 4].weight;
			tmpWeight2 = pSpectInfo[j + 4].weight +
						pSpectInfo[j + 8].weight;
			if (tmpWeight1 <= tmpWeight2) {
				if (pSpectInfo[j].weight <=
						pSpectInfo[j + 4].weight) {
					pSpectInfo[j].weight =
						tmpWeight1;
					pSpectInfo[j + 4].weight =
						SAP_ACS_WEIGHT_MAX * 2;
					pSpectInfo[j + 8].weight =
						SAP_ACS_WEIGHT_MAX * 2;
				} else {
					pSpectInfo[j + 4].weight =
						tmpWeight1;
					/* for secondary channel selection */
					pSpectInfo[j].weight =
						SAP_ACS_WEIGHT_MAX * 2
						- 1;
					pSpectInfo[j + 8].weight =
						SAP_ACS_WEIGHT_MAX * 2;
				}
			} else {
				if (pSpectInfo[j + 4].weight <=
						pSpectInfo[j + 8].weight) {
					pSpectInfo[j + 4].weight =
						tmpWeight2;
					pSpectInfo[j].weight =
						SAP_ACS_WEIGHT_MAX * 2;
					/* for secondary channel selection */
					pSpectInfo[j + 8].weight =
						SAP_ACS_WEIGHT_MAX * 2
						- 1;
				} else {
					pSpectInfo[j + 8].weight =
						tmpWeight2;
					pSpectInfo[j].weight =
						SAP_ACS_WEIGHT_MAX * 2;
					pSpectInfo[j + 4].weight =
						SAP_ACS_WEIGHT_MAX * 2;
				}
			}
		} else {
			tmpWeight1 = pSpectInfo[j].weight_copy +
						pSpectInfo[j + 4].weight_copy;
			if (pSpectInfo[j].weight_copy <=
					pSpectInfo[j + 4].weight_copy) {
				pSpectInfo[j].weight = tmpWeight1;
				pSpectInfo[j + 4].weight =
					SAP_ACS_WEIGHT_MAX * 2;
			} else {
				pSpectInfo[j + 4].weight = tmpWeight1;
				pSpectInfo[j].weight =
					SAP_ACS_WEIGHT_MAX * 2;
			}
		}
	}
	/*
	 * Every channel should be checked. Add the check for the omissive
	 * channel. Mark the channel whose combination can't satisfy 40MHZ
	 * as max value, so that it will be sorted to the bottom.
	 */
<<<<<<< HEAD
	if (cds_is_fcc_regdomain())
=======
	if (REGDOMAIN_FCC == domain)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		ht40plus2gendch = HT40PLUS_2G_FCC_CH_END;
	else
		ht40plus2gendch = HT40PLUS_2G_EURJAP_CH_END;
	for (i = HT40MINUS_2G_CH_START; i <= ht40plus2gendch; i++) {
<<<<<<< HEAD
		for (j = 0; j < pSpectInfoParams->numSpectChans; j++) {
			if (pSpectInfo[j].chNum == i &&
				((pSpectInfo[j].chNum + 4) !=
					pSpectInfo[j+4].chNum) &&
				((pSpectInfo[j].chNum - 4) !=
					pSpectInfo[j-4].chNum))
=======
		chan_freq = wlan_reg_legacy_chan_to_freq(mac_ctx->pdev, i);
		for (j = 0; j < pSpectInfoParams->numSpectChans; j++) {
			if (pSpectInfo[j].chan_freq == chan_freq &&
				((pSpectInfo[j].chan_freq + 20) !=
					pSpectInfo[j + 4].chan_freq) &&
				((pSpectInfo[j].chan_freq - 20) !=
					pSpectInfo[j - 4].chan_freq))
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				pSpectInfo[j].weight = SAP_ACS_WEIGHT_MAX * 2;
		}
	}
	for (i = ht40plus2gendch + 1; i <= HT40MINUS_2G_CH_END; i++) {
<<<<<<< HEAD
		for (j = 0; j < pSpectInfoParams->numSpectChans; j++) {
			if (pSpectInfo[j].chNum == i &&
				(pSpectInfo[j].chNum - 4) !=
					pSpectInfo[j-4].chNum)
=======
		chan_freq = wlan_reg_legacy_chan_to_freq(mac_ctx->pdev, i);
		for (j = 0; j < pSpectInfoParams->numSpectChans; j++) {
			if (pSpectInfo[j].chan_freq == chan_freq &&
				(pSpectInfo[j].chan_freq - 20) !=
					pSpectInfo[j - 4].chan_freq)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				pSpectInfo[j].weight = SAP_ACS_WEIGHT_MAX * 2;
		}
	}

	pSpectInfo = pSpectInfoParams->pSpectCh;
	for (j = 0; j < (pSpectInfoParams->numSpectChans); j++) {
<<<<<<< HEAD
		QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
			  "In %s, Channel=%d Weight= %d rssi=%d bssCount=%d",
			  __func__, pSpectInfo->chNum, pSpectInfo->weight,
			  pSpectInfo->rssiAgr, pSpectInfo->bssCount);
=======
		sap_debug("freq = %d weight = %d rssi = %d bss count = %d",
			  pSpectInfo->chan_freq, pSpectInfo->weight,
			  pSpectInfo->rssiAgr, pSpectInfo->bssCount);

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		pSpectInfo++;
	}

	sap_sort_chl_weight(pSpectInfoParams);
}

<<<<<<< HEAD
/*==========================================================================
   FUNCTION    sap_sort_chl_weight_ht40_5_g

   DESCRIPTION
    Funtion to sort the channels with the least weight first for HT40 channels

   DEPENDENCIES
    NA.

   PARAMETERS

    IN
    pSpectInfoParams       : Pointer to the tSapChSelSpectInfo structure

   RETURN VALUE
    void     : NULL

   SIDE EFFECTS
   ============================================================================*/
static void sap_sort_chl_weight_ht40_5_g(tSapChSelSpectInfo *pSpectInfoParams)
{
	uint8_t i, j;
	tSapSpectChInfo *pSpectInfo;

	pSpectInfo = pSpectInfoParams->pSpectCh;
	/*for each HT40 channel, calculate the combined weight of the
	   two 20MHz weight */
	for (i = 0; i < ARRAY_SIZE(acs_ht40_channels5_g); i++) {
		for (j = 0; j < pSpectInfoParams->numSpectChans; j++) {
			if (pSpectInfo[j].chNum ==
			    acs_ht40_channels5_g[i].chStartNum)
				break;
		}
		if (j == pSpectInfoParams->numSpectChans)
			continue;

		/* found the channel, add the two adjacent channels' weight */
		if ((pSpectInfo[j].chNum + 4) == pSpectInfo[j + 1].chNum) {
			acs_ht40_channels5_g[i].weight = pSpectInfo[j].weight +
						      pSpectInfo[j + 1].weight;
			/* select better of the adjact channel as the primary channel */
			if (pSpectInfo[j].weight <= pSpectInfo[j + 1].weight) {
				pSpectInfo[j].weight =
					acs_ht40_channels5_g[i].weight;
				/* mark the adjacent channel's weight as max value so
				   that it will be sorted to the bottom */
				pSpectInfo[j + 1].weight =
					SAP_ACS_WEIGHT_MAX * 2;
			} else {
				pSpectInfo[j + 1].weight =
					acs_ht40_channels5_g[i].weight;
				/* mark the adjacent channel's weight as max value so
				   that it will be sorted to the bottom */
				pSpectInfo[j].weight = SAP_ACS_WEIGHT_MAX * 2;
			}

		} else
			pSpectInfo[j].weight = SAP_ACS_WEIGHT_MAX * 2;
	}

	/*
	 *Every channel should be checked. Add the check for the omissive
	 * channel. Mark the channel whose combination can't satisfy 40MHZ
	 * as max value, so that it will be sorted to the bottom
	 */
	for (j = 1; j < pSpectInfoParams->numSpectChans; j++) {
		for (i = 0; i < ARRAY_SIZE(acs_ht40_channels5_g); i++) {
			if (pSpectInfo[j].chNum ==
				(acs_ht40_channels5_g[i].chStartNum + 4) &&
				pSpectInfo[j-1].chNum !=
					acs_ht40_channels5_g[i].chStartNum) {
				pSpectInfo[j].weight = SAP_ACS_WEIGHT_MAX * 2;
				break;
			}
		}
	}
	/* avoid channel 165 by setting its weight to max */
	pSpectInfo = pSpectInfoParams->pSpectCh;
	for (j = 0; j < pSpectInfoParams->numSpectChans; j++) {
		if (CHANNEL_165 == pSpectInfo[j].chNum) {
			pSpectInfo[j].weight = SAP_ACS_WEIGHT_MAX * 2;
			break;
		}
	}

	pSpectInfo = pSpectInfoParams->pSpectCh;
	for (j = 0; j < (pSpectInfoParams->numSpectChans); j++) {
		QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
			  "In %s, Channel=%d Weight= %d rssi=%d bssCount=%d",
			  __func__, pSpectInfo->chNum, pSpectInfo->weight,
			  pSpectInfo->rssiAgr, pSpectInfo->bssCount);
		pSpectInfo++;
	}

	sap_sort_chl_weight(pSpectInfoParams);
=======
static void sap_sort_chl_weight_40_mhz(struct mac_context *mac_ctx,
				       tSapChSelSpectInfo *pSpectInfoParams)
{
	uint8_t i, j;
	tSapSpectChInfo *pSpectInfo;
	uint8_t minIdx;
	struct ch_params acs_ch_params;
	int8_t center_freq_diff;
	uint32_t combined_weight;
	uint32_t min_ch_weight;

	pSpectInfo = pSpectInfoParams->pSpectCh;

	for (j = 0; j < pSpectInfoParams->numSpectChans; j++) {

		if (WLAN_REG_IS_24GHZ_CH_FREQ(pSpectInfo[j].chan_freq))
			continue;

		if (pSpectInfo[j].weight_calc_done)
			continue;

		acs_ch_params.ch_width = CH_WIDTH_40MHZ;

		wlan_reg_set_channel_params_for_freq(mac_ctx->pdev,
						     pSpectInfo[j].chan_freq,
						     0, &acs_ch_params);

		/* Check if the freq supports 40 Mhz */
		if (acs_ch_params.ch_width != CH_WIDTH_40MHZ) {
			pSpectInfo[j].weight = SAP_ACS_WEIGHT_MAX * 2;
			pSpectInfo[j].weight_calc_done = true;
			continue;
		}

		center_freq_diff = acs_ch_params.mhz_freq_seg0 -
				   pSpectInfo[j].chan_freq;

		/* This channel frequency does not have all channels */
		if (center_freq_diff != 10) {
			pSpectInfo[j].weight = SAP_ACS_WEIGHT_MAX * 2;
			pSpectInfo[j].weight_calc_done = true;
			continue;
		}

		/* no other freq left for 40 Mhz operation in spectrum */
		if (j + 1 > pSpectInfoParams->numSpectChans)
			continue;

		/* Check whether all frequencies are present for 40 Mhz */

		if (!((pSpectInfo[j].chan_freq + 20) ==
		       pSpectInfo[j + 1].chan_freq)) {
			/*
			 * some channels does not exist in pSectInfo array,
			 * skip this channel and those in the same 40 width
			 */
			pSpectInfo[j].weight = SAP_ACS_WEIGHT_MAX * 2;
			pSpectInfo[j].weight_calc_done = true;

			if ((pSpectInfo[j].chan_freq + 20) ==
					pSpectInfo[j + 1].chan_freq) {
				pSpectInfo[j + 1].weight =
					SAP_ACS_WEIGHT_MAX * 2;
				pSpectInfo[j +1].weight_calc_done = true;
			}

			continue;
		}

		/* We have 2 channels to calculate cumulative weight */

		combined_weight = pSpectInfo[j].weight +
				  pSpectInfo[j + 1].weight;

		min_ch_weight = pSpectInfo[j].weight;
		minIdx = 0;

		for (i = 0; i < 2; i++) {
			if (min_ch_weight > pSpectInfo[j + i].weight) {
				min_ch_weight = pSpectInfo[j + i].weight;
				minIdx = i;
			}
			pSpectInfo[j + i].weight = SAP_ACS_WEIGHT_MAX * 2;
			pSpectInfo[j + i].weight_calc_done = true;
		}

		pSpectInfo[j + minIdx].weight = combined_weight;

		sap_debug("best freq = %d for 40mhz center freq %d combined weight = %d",
			  pSpectInfo[j + minIdx].chan_freq,
			  acs_ch_params.mhz_freq_seg0,
			  combined_weight);
	}

	sap_sort_chl_weight(pSpectInfoParams);

	pSpectInfo = pSpectInfoParams->pSpectCh;
	for (j = 0; j < (pSpectInfoParams->numSpectChans); j++) {
		sap_debug("freq = %d weight = %d rssi = %d bss count = %d",
			  pSpectInfo->chan_freq, pSpectInfo->weight,
			  pSpectInfo->rssiAgr, pSpectInfo->bssCount);

		pSpectInfo++;
	}
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

/*==========================================================================
   FUNCTION    sap_sort_chl_weight_all

   DESCRIPTION
<<<<<<< HEAD
    Funtion to sort the channels with the least weight first
=======
    Function to sort the channels with the least weight first
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

   DEPENDENCIES
    NA.

   PARAMETERS

    IN
<<<<<<< HEAD
    ptSapContext           : Pointer to the ptSapContext structure
=======
    sap_ctx                : Pointer to the struct sap_context *structure
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
    pSpectInfoParams       : Pointer to the tSapChSelSpectInfo structure

   RETURN VALUE
    void     : NULL

   SIDE EFFECTS
   ============================================================================*/
<<<<<<< HEAD
static void sap_sort_chl_weight_all(ptSapContext pSapCtx,
				    tSapChSelSpectInfo *pSpectInfoParams,
				    uint32_t operatingBand)
{
	tSapSpectChInfo *pSpectCh = NULL;
	uint32_t j = 0;
#ifndef SOFTAP_CHANNEL_RANGE
	uint32_t i = 0;
#endif

	pSpectCh = pSpectInfoParams->pSpectCh;
#ifdef SOFTAP_CHANNEL_RANGE

	switch (pSapCtx->acs_cfg->ch_width) {
=======
static void sap_sort_chl_weight_all(struct mac_context *mac_ctx,
				    struct sap_context *sap_ctx,
				    tSapChSelSpectInfo *pSpectInfoParams,
				    uint32_t operatingBand,
				    v_REGDOMAIN_t domain)
{
	tSapSpectChInfo *pSpectCh = NULL;
	uint32_t j = 0;

	pSpectCh = pSpectInfoParams->pSpectCh;

	switch (sap_ctx->acs_cfg->ch_width) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	case CH_WIDTH_40MHZ:
		/*
		 * Assign max weight to all 5Ghz channels when operating band
		 * is 11g and to all 2.4Ghz channels when operating band is 11a
		 * or 11abg to avoid selection in ACS algorithm for starting SAP
		 */
		if (eCSR_DOT11_MODE_11g == operatingBand) {
<<<<<<< HEAD
			sap_sort_chl_weight_ht40_24_g(pSpectInfoParams);
			sap_allocate_max_weight_ht40_5_g(pSpectInfoParams);
		} else {
			sap_allocate_max_weight_ht40_24_g(pSpectInfoParams);
			sap_sort_chl_weight_ht40_5_g(pSpectInfoParams);
=======
			sap_allocate_max_weight_40_mhz(pSpectInfoParams);
			sap_sort_chl_weight_ht40_24_g(mac_ctx,
						      pSpectInfoParams,
						      domain);
		} else {
			sap_allocate_max_weight_40_mhz_24_g(pSpectInfoParams);
			sap_sort_chl_weight_40_mhz(mac_ctx, pSpectInfoParams);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		}
		break;
	case CH_WIDTH_80MHZ:
	case CH_WIDTH_80P80MHZ:
<<<<<<< HEAD
		sap_sort_chl_weight_ht80(pSpectInfoParams);
		break;
	case CH_WIDTH_160MHZ:
		sap_sort_chl_weight_vht160(pSpectInfoParams);
=======
		sap_sort_chl_weight_80_mhz(mac_ctx, pSpectInfoParams);
		break;
	case CH_WIDTH_160MHZ:
		sap_sort_chl_weight_160_mhz(mac_ctx, pSpectInfoParams);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		break;
	case CH_WIDTH_20MHZ:
	default:
		/* Sorting the channels as per weights as 20MHz channels */
		sap_sort_chl_weight(pSpectInfoParams);
	}

<<<<<<< HEAD
#else
	/* Sorting the channels as per weights */
	for (i = 0; i < SPECT_24GHZ_CH_COUNT; i++) {
		minWeightIndex = i;
		for (j = i + 1; j < SPECT_24GHZ_CH_COUNT; j++) {
			if (pSpectCh[j].weight <
			    pSpectCh[minWeightIndex].weight) {
				minWeightIndex = j;
			}
		}
		if (minWeightIndex != i) {
			qdf_mem_copy(&temp, &pSpectCh[minWeightIndex],
				     sizeof(*pSpectCh));
			qdf_mem_copy(&pSpectCh[minWeightIndex], &pSpectCh[i],
				     sizeof(*pSpectCh));
			qdf_mem_copy(&pSpectCh[i], &temp, sizeof(*pSpectCh));
		}
	}
#endif

	/* For testing */
	QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO,
		  "In %s, Sorted Spectrum Channels Weight", __func__);
	pSpectCh = pSpectInfoParams->pSpectCh;
	for (j = 0; j < (pSpectInfoParams->numSpectChans); j++) {
		QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO,
			  "In %s, Channel=%d Weight= %d rssi=%d bssCount=%d",
			  __func__, pSpectCh->chNum, pSpectCh->weight,
=======
	pSpectCh = pSpectInfoParams->pSpectCh;
	for (j = 0; j < (pSpectInfoParams->numSpectChans); j++) {
		sap_debug("Freq = %d weight = %d rssi aggr = %d bss count = %d",
			  pSpectCh->chan_freq, pSpectCh->weight,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			  pSpectCh->rssiAgr, pSpectCh->bssCount);
		pSpectCh++;
	}

}

/**
 * sap_is_ch_non_overlap() - returns true if non-overlapping channel
 * @sap_ctx: Sap context
 * @ch: channel number
 *
 * Returns: true if non-overlapping (1, 6, 11) channel, false otherwise
 */
<<<<<<< HEAD
static bool sap_is_ch_non_overlap(ptSapContext sap_ctx, uint16_t ch)
=======
static bool sap_is_ch_non_overlap(struct sap_context *sap_ctx, uint16_t ch)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	if (sap_ctx->enableOverLapCh)
		return true;

	if ((ch == CHANNEL_1) || (ch == CHANNEL_6) || (ch == CHANNEL_11))
		return true;

	return false;
}

<<<<<<< HEAD
/**
 * sap_select_channel() - select SAP channel
 * @hal: Pointer to HAL handle
 * @sap_ctx: Sap context
 * @scan_result: Pointer to tScanResultHandle
 *
 * Runs a algorithm to select the best channel to operate in based on BSS
 * rssi and bss count on each channel
 *
 * Returns: channel number if success, 0 otherwise
 */
uint8_t sap_select_channel(tHalHandle hal, ptSapContext sap_ctx,
			   tScanResultHandle scan_result)
=======
uint32_t sap_select_channel(mac_handle_t mac_handle,
			   struct sap_context *sap_ctx,
			   qdf_list_t *scan_list)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	/* DFS param object holding all the data req by the algo */
	tSapChSelSpectInfo spect_info_obj = { NULL, 0 };
	tSapChSelSpectInfo *spect_info = &spect_info_obj;
	uint8_t best_ch_num = SAP_CHANNEL_NOT_SELECTED;
<<<<<<< HEAD
	uint32_t ht40plus2gendch = 0;
#ifdef SOFTAP_CHANNEL_RANGE
	uint8_t count;
	uint32_t start_ch_num, end_ch_num, tmp_ch_num, operating_band = 0;
#endif
	QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
		  "In %s, Running SAP Ch Select", __func__);

	/*
	 * If ACS weight is not enabled on noise_floor/channel_free/tx_power,
	 * then skip acs process if no bss found.
	 */
	if (NULL == scan_result &&
	    !(sap_ctx->auto_channel_select_weight & 0xffff00)) {
		QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
			  FL("No external AP present"));

#ifndef SOFTAP_CHANNEL_RANGE
		return SAP_CHANNEL_NOT_SELECTED;
#else
		return sap_select_default_oper_chan(sap_ctx->acs_cfg);
#endif
	}

	/* Initialize the structure pointed by spect_info */
	if (sap_chan_sel_init(hal, spect_info, sap_ctx) != true) {
=======
	uint32_t best_ch_weight = SAP_ACS_WEIGHT_MAX;
	uint32_t ht40plus2gendch = 0;
	v_REGDOMAIN_t domain;
	uint8_t country[CDS_COUNTRY_CODE_LEN + 1];
	uint8_t count;
	uint32_t operating_band = 0;
	struct mac_context *mac_ctx;
	uint32_t best_chan_freq = 0;

	mac_ctx = MAC_CONTEXT(mac_handle);

	/* Initialize the structure pointed by spect_info */
	if (sap_chan_sel_init(mac_handle, spect_info, sap_ctx) != true) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_ERROR,
			  FL("Ch Select initialization failed"));
		return SAP_CHANNEL_NOT_SELECTED;
	}
<<<<<<< HEAD
	/* Compute the weight of the entire spectrum in the operating band */
	sap_compute_spect_weight(spect_info, hal, scan_result, sap_ctx);

#ifdef FEATURE_AP_MCC_CH_AVOIDANCE
	/* process avoid channel IE to collect all channels to avoid */
	sap_process_avoid_ie(hal, sap_ctx, scan_result, spect_info);
#endif /* FEATURE_AP_MCC_CH_AVOIDANCE */

#ifdef SOFTAP_CHANNEL_RANGE
	start_ch_num = sap_ctx->acs_cfg->start_ch;
	end_ch_num = sap_ctx->acs_cfg->end_ch;
	SET_ACS_BAND(operating_band, sap_ctx);

	sap_ctx->acsBestChannelInfo.channelNum = 0;
	sap_ctx->acsBestChannelInfo.weight = SAP_ACS_WEIGHT_MAX;

	/* Sort the ch lst as per the computed weights, lesser weight first. */
	sap_sort_chl_weight_all(sap_ctx, spect_info, operating_band);

	/*Loop till get the best channel in the given range */
	for (count = 0; count < spect_info->numSpectChans; count++) {
		if ((start_ch_num > spect_info->pSpectCh[count].chNum) ||
		    (end_ch_num < spect_info->pSpectCh[count].chNum))
			continue;

		if (best_ch_num == SAP_CHANNEL_NOT_SELECTED) {
			best_ch_num = spect_info->pSpectCh[count].chNum;
			/* check if best_ch_num is in preferred channel list */
			best_ch_num =
				sap_select_preferred_channel_from_channel_list(
					best_ch_num, sap_ctx, spect_info);
			/* if not in preferred ch lst, go to nxt best ch */
			if (best_ch_num == SAP_CHANNEL_NOT_SELECTED)
				continue;

#ifdef FEATURE_AP_MCC_CH_AVOIDANCE
			/*
			 * Weight of the channels(device's AP is operating)
			 * increased to MAX+1 so that they will be choosen only
			 * when there is no other best channel to choose
			 */
			if (sap_check_in_avoid_ch_list(sap_ctx, best_ch_num)) {
				best_ch_num = SAP_CHANNEL_NOT_SELECTED;
				continue;
			}
#endif

			sap_ctx->acsBestChannelInfo.channelNum = best_ch_num;
			sap_ctx->acsBestChannelInfo.weight =
					spect_info->pSpectCh[count].weight_copy;
		}

		if (best_ch_num == SAP_CHANNEL_NOT_SELECTED)
			continue;

		if (operating_band != eCSR_DOT11_MODE_11g) {
			QDF_TRACE(QDF_MODULE_ID_SAP,
				QDF_TRACE_LEVEL_INFO_HIGH,
				"operating_band %d", operating_band);
			continue;
		}

		/* Give preference to Non-overlap channels */
		if (false == sap_is_ch_non_overlap(sap_ctx,
				spect_info->pSpectCh[count].chNum)) {
			QDF_TRACE(QDF_MODULE_ID_SAP,
				QDF_TRACE_LEVEL_INFO_HIGH,
				FL("ch: %d skipped as its overlapping ch"),
				spect_info->pSpectCh[count].chNum);
			continue;
		}

		if (spect_info->pSpectCh[count].weight_copy >
				sap_ctx->acsBestChannelInfo.weight) {
			QDF_TRACE(QDF_MODULE_ID_SAP,
				QDF_TRACE_LEVEL_INFO_HIGH,
				"candidate ch weight: %d, best ch weight: %d",
				spect_info->pSpectCh[count].weight_copy,
				sap_ctx->acsBestChannelInfo.weight);
			continue;
		}

		if (CDS_IS_DFS_CH(spect_info->pSpectCh[count].chNum) &&
			cds_disallow_mcc(spect_info->pSpectCh[count].chNum)) {
			QDF_TRACE(QDF_MODULE_ID_SAP,
				QDF_TRACE_LEVEL_INFO_HIGH,
				"No DFS MCC");
			continue;
		}

		tmp_ch_num = spect_info->pSpectCh[count].chNum;
		tmp_ch_num = sap_channel_in_acs_channel_list(
					tmp_ch_num, sap_ctx, spect_info);
		if (tmp_ch_num == SAP_CHANNEL_NOT_SELECTED)
			continue;

		best_ch_num = tmp_ch_num;
		break;
	}
#else
	/* Sort the ch lst as per the computed weights, lesser weight first. */
	sap_sort_chl_weight_all(sap_ctx, hal, spect_info);
	/* Get the first channel in sorted array as best 20M Channel */
	best_ch_num = (uint8_t) spect_info->pSpectCh[0].chNum;
	/* Select Best Channel from Channel List if Configured */
	best_ch_num = sap_select_preferred_channel_from_channel_list(
					best_ch_num, sap_ctx, spect_info);
#endif
=======

	/* Compute the weight of the entire spectrum in the operating band */
	sap_compute_spect_weight(spect_info, mac_handle, scan_list, sap_ctx);

#ifdef FEATURE_AP_MCC_CH_AVOIDANCE
	/* process avoid channel IE to collect all channels to avoid */
	sap_process_avoid_ie(mac_handle, sap_ctx, scan_list, spect_info);
#endif /* FEATURE_AP_MCC_CH_AVOIDANCE */

	wlan_reg_read_current_country(mac_ctx->psoc, country);
	wlan_reg_get_domain_from_country_code(&domain, country, SOURCE_DRIVER);

	SET_ACS_BAND(operating_band, sap_ctx);

	/* Sort the ch lst as per the computed weights, lesser weight first. */
	sap_sort_chl_weight_all(mac_ctx, sap_ctx, spect_info, operating_band,
				domain);

	/*Loop till get the best channel in the given range */
	for (count = 0; count < spect_info->numSpectChans; count++) {
		best_chan_freq = spect_info->pSpectCh[count].chan_freq;
		/* check if best_ch_num is in preferred channel list */
		best_chan_freq =
			sap_select_preferred_channel_from_channel_list(
				best_chan_freq, sap_ctx, spect_info);
		/* if not in preferred ch lst, go to nxt best ch */
		if (best_chan_freq == SAP_CHANNEL_NOT_SELECTED)
			continue;

#ifdef FEATURE_AP_MCC_CH_AVOIDANCE
		/*
		 * Weight of the channels(device's AP is operating)
		 * increased to MAX+1 so that they will be chosen only
		 * when there is no other best channel to choose
		 */
		if (!WLAN_REG_IS_6GHZ_CHAN_FREQ(best_chan_freq) &&
		    sap_check_in_avoid_ch_list(sap_ctx,
		    wlan_reg_freq_to_chan(mac_ctx->pdev, best_chan_freq))) {
			best_chan_freq = SAP_CHANNEL_NOT_SELECTED;
			continue;
		}
#endif

		/* Give preference to Non-overlap channels */
		if (WLAN_REG_IS_24GHZ_CH_FREQ(best_chan_freq) &&
		    !sap_is_ch_non_overlap(sap_ctx,
		    wlan_reg_freq_to_chan(mac_ctx->pdev, best_chan_freq))) {
			sap_debug("freq %d is overlapping, skipped",
				  best_chan_freq);
			continue;
		}

		best_ch_weight = spect_info->pSpectCh[count].weight;
		sap_debug("Freq = %d selected as best frequency weight = %d",
			  best_chan_freq, best_ch_weight);

		break;
	}
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	/*
	 * in case the best channel seleted is not in PCL and there is another
	 * channel which has same weightage and is in PCL, choose the one in
	 * PCL
	 */
<<<<<<< HEAD
	for (count = 0; count < spect_info->numSpectChans; count++) {
		if (!ch_in_pcl(sap_ctx, spect_info->pSpectCh[count].chNum) ||
		    (spect_info->pSpectCh[count].weight !=
				sap_ctx->acsBestChannelInfo.weight))
			continue;

		if (sap_select_preferred_channel_from_channel_list(
			spect_info->pSpectCh[count].chNum, sap_ctx, spect_info)
			== SAP_CHANNEL_NOT_SELECTED)
			continue;

#ifdef FEATURE_AP_MCC_CH_AVOIDANCE
		if (sap_check_in_avoid_ch_list(sap_ctx, best_ch_num))
			continue;
#endif
		best_ch_num = spect_info->pSpectCh[count].chNum;
		QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
			FL("change best channel to %d in PCL"), best_ch_num);
		break;
	}

	sap_ctx->acs_cfg->pri_ch = best_ch_num;
=======
	if (!ch_in_pcl(sap_ctx, best_chan_freq)) {
		uint32_t cal_chan_freq, cal_chan_weight;
		for (count = 0; count < spect_info->numSpectChans; count++) {
			cal_chan_freq = spect_info->pSpectCh[count].chan_freq;
			cal_chan_weight = spect_info->pSpectCh[count].weight;
			/* skip pcl channel whose weight is bigger than best */
			if (!ch_in_pcl(sap_ctx, cal_chan_freq) ||
			    (cal_chan_weight > best_ch_weight))
				continue;

			if (best_chan_freq == cal_chan_freq)
				continue;

			if (sap_select_preferred_channel_from_channel_list(
				cal_chan_freq, sap_ctx,
				spect_info)
				== SAP_CHANNEL_NOT_SELECTED)
				continue;

			best_chan_freq = cal_chan_freq;
			sap_debug("Changed best freq to %d Preferred freq",
				  best_chan_freq);

			break;
		}
	}

	sap_ctx->acs_cfg->pri_ch_freq = best_chan_freq;

	/* Below code is for 2.4Ghz freq, so freq to channel is safe here */

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	/* determine secondary channel for 2.4G channel 5, 6, 7 in HT40 */
	if ((operating_band != eCSR_DOT11_MODE_11g) ||
	    (sap_ctx->acs_cfg->ch_width != CH_WIDTH_40MHZ))
		goto sap_ch_sel_end;

<<<<<<< HEAD
	if (cds_is_fcc_regdomain())
=======
	best_ch_num = wlan_reg_freq_to_chan(mac_ctx->pdev, best_chan_freq);

	if (REGDOMAIN_FCC == domain)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		ht40plus2gendch = HT40PLUS_2G_FCC_CH_END;
	else
		ht40plus2gendch = HT40PLUS_2G_EURJAP_CH_END;
	if ((best_ch_num >= HT40MINUS_2G_CH_START) &&
			(best_ch_num <= ht40plus2gendch)) {
		int weight_below, weight_above, i;
		tSapSpectChInfo *pspect_info;

		weight_below = weight_above = SAP_ACS_WEIGHT_MAX;
		pspect_info = spect_info->pSpectCh;
		for (i = 0; i < spect_info->numSpectChans; i++) {
<<<<<<< HEAD
			if (pspect_info[i].chNum == (best_ch_num - 4))
				weight_below = pspect_info[i].weight;
			if (pspect_info[i].chNum == (best_ch_num + 4))
=======
			if (pspect_info[i].chan_freq == (best_chan_freq - 20))
				weight_below = pspect_info[i].weight;
			if (pspect_info[i].chan_freq == (best_ch_num + 20))
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				weight_above = pspect_info[i].weight;
		}

		if (weight_below < weight_above)
<<<<<<< HEAD
			sap_ctx->acs_cfg->ht_sec_ch =
					sap_ctx->acs_cfg->pri_ch - 4;
		else
			sap_ctx->acs_cfg->ht_sec_ch =
					sap_ctx->acs_cfg->pri_ch + 4;
	} else if (best_ch_num >= 1 && best_ch_num <= 4) {
		sap_ctx->acs_cfg->ht_sec_ch = sap_ctx->acs_cfg->pri_ch + 4;
	} else if (best_ch_num > ht40plus2gendch && best_ch_num <= HT40MINUS_2G_CH_END) {
		sap_ctx->acs_cfg->ht_sec_ch = sap_ctx->acs_cfg->pri_ch - 4;
	} else if (best_ch_num == 14) {
		sap_ctx->acs_cfg->ht_sec_ch = 0;
	}
	sap_ctx->secondary_ch = sap_ctx->acs_cfg->ht_sec_ch;
=======
			sap_ctx->acs_cfg->ht_sec_ch_freq =
					sap_ctx->acs_cfg->pri_ch_freq - 20;
		else
			sap_ctx->acs_cfg->ht_sec_ch_freq =
					sap_ctx->acs_cfg->pri_ch_freq + 20;
	} else if (best_ch_num >= 1 && best_ch_num <= 4) {
		sap_ctx->acs_cfg->ht_sec_ch_freq =
					sap_ctx->acs_cfg->pri_ch_freq + 20;
	} else if (best_ch_num >= ht40plus2gendch && best_ch_num <=
			HT40MINUS_2G_CH_END) {
		sap_ctx->acs_cfg->ht_sec_ch_freq =
					sap_ctx->acs_cfg->pri_ch_freq - 20;
	} else if (best_ch_num == 14) {
		sap_ctx->acs_cfg->ht_sec_ch_freq = 0;
	}
	sap_ctx->sec_ch_freq = sap_ctx->acs_cfg->ht_sec_ch_freq;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

sap_ch_sel_end:
	/* Free all the allocated memory */
	sap_chan_sel_exit(spect_info);

<<<<<<< HEAD
	QDF_TRACE(QDF_MODULE_ID_SAP, QDF_TRACE_LEVEL_INFO_HIGH,
		  FL("Running SAP Ch select Completed, Ch=%d"), best_ch_num);
	if (best_ch_num > 0 && best_ch_num <= 252)
		return best_ch_num;
	else
		return SAP_CHANNEL_NOT_SELECTED;
=======
	return best_chan_freq;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

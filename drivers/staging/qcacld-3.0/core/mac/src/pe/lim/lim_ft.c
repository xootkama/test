/*
<<<<<<< HEAD
 * Copyright (c) 2012-2018, 2020 The Linux Foundation. All rights reserved.
=======
 * Copyright (c) 2012-2021 The Linux Foundation. All rights reserved.
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

/**=========================================================================

   \brief implementation for PE 11r VoWiFi FT Protocol

   ========================================================================*/

/* $Header$ */

/*--------------------------------------------------------------------------
   Include Files
   ------------------------------------------------------------------------*/
#include <lim_send_messages.h>
#include <lim_types.h>
#include <lim_ft.h>
#include <lim_ft_defs.h>
#include <lim_utils.h>
#include <lim_prop_exts_utils.h>
#include <lim_assoc_utils.h>
#include <lim_session.h>
#include <lim_admit_control.h>
<<<<<<< HEAD
#include "wmm_apsd.h"
#include "wma.h"

extern void lim_send_set_sta_key_req(tpAniSirGlobal pMac,
				     tLimMlmSetKeysReq * pMlmSetKeysReq,
				     uint16_t staIdx,
				     uint8_t defWEPIdx,
				     tpPESession sessionEntry, bool sendRsp);

/*--------------------------------------------------------------------------
   Initialize the FT variables.
   ------------------------------------------------------------------------*/
void lim_ft_open(tpAniSirGlobal pMac, tpPESession psessionEntry)
{
	if (psessionEntry)
		qdf_mem_set(&psessionEntry->ftPEContext, sizeof(tftPEContext),
			    0);
}

void lim_ft_cleanup_all_ft_sessions(tpAniSirGlobal pMac)
=======
#include <lim_security_utils.h>
#include "wmm_apsd.h"
#include "wma.h"

/*--------------------------------------------------------------------------
   Initialize the FT variables.
   ------------------------------------------------------------------------*/
void lim_ft_open(struct mac_context *mac, struct pe_session *pe_session)
{
	if (pe_session)
		qdf_mem_zero(&pe_session->ftPEContext, sizeof(tftPEContext));
}

void lim_ft_cleanup_all_ft_sessions(struct mac_context *mac)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	/* Wrapper function to cleanup all FT sessions */
	int i;

<<<<<<< HEAD
	for (i = 0; i < pMac->lim.maxBssId; i++) {
		if (true == pMac->lim.gpSession[i].valid) {
			/* The session is valid, may have FT data */
			lim_ft_cleanup(pMac, &pMac->lim.gpSession[i]);
=======
	for (i = 0; i < mac->lim.maxBssId; i++) {
		if (true == mac->lim.gpSession[i].valid) {
			/* The session is valid, may have FT data */
			lim_ft_cleanup(mac, &mac->lim.gpSession[i]);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		}
	}
}

<<<<<<< HEAD
void lim_ft_cleanup(tpAniSirGlobal pMac, tpPESession psessionEntry)
{
	if (NULL == psessionEntry) {
		pe_err("psessionEntry is NULL");
=======
void lim_ft_cleanup(struct mac_context *mac, struct pe_session *pe_session)
{
	if (!pe_session) {
		pe_err("pe_session is NULL");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return;
	}

	/* Nothing to be done if the session is not in STA mode */
<<<<<<< HEAD
	if (!LIM_IS_STA_ROLE(psessionEntry)) {
		pe_err("psessionEntry is not in STA mode");
		return;
	}

	if (NULL != psessionEntry->ftPEContext.pFTPreAuthReq) {
		pe_debug("Freeing pFTPreAuthReq: %pK",
			       psessionEntry->ftPEContext.pFTPreAuthReq);
		if (NULL !=
		    psessionEntry->ftPEContext.pFTPreAuthReq->
		    pbssDescription) {
			qdf_mem_free(psessionEntry->ftPEContext.pFTPreAuthReq->
				     pbssDescription);
			psessionEntry->ftPEContext.pFTPreAuthReq->
			pbssDescription = NULL;
		}
		qdf_mem_free(psessionEntry->ftPEContext.pFTPreAuthReq);
		psessionEntry->ftPEContext.pFTPreAuthReq = NULL;
	}

	if (psessionEntry->ftPEContext.pAddBssReq) {
		qdf_mem_free(psessionEntry->ftPEContext.pAddBssReq);
		psessionEntry->ftPEContext.pAddBssReq = NULL;
	}

	if (psessionEntry->ftPEContext.pAddStaReq) {
		qdf_mem_free(psessionEntry->ftPEContext.pAddStaReq);
		psessionEntry->ftPEContext.pAddStaReq = NULL;
	}

	/* The session is being deleted, cleanup the contents */
	qdf_mem_set(&psessionEntry->ftPEContext, sizeof(tftPEContext), 0);
=======
	if (!LIM_IS_STA_ROLE(pe_session)) {
		pe_debug("pe_session is not in STA mode");
		return;
	}

	if (pe_session->ftPEContext.pFTPreAuthReq) {
		pe_debug("Freeing pFTPreAuthReq: %pK",
			       pe_session->ftPEContext.pFTPreAuthReq);
		if (NULL !=
		    pe_session->ftPEContext.pFTPreAuthReq->
		    pbssDescription) {
			qdf_mem_free(pe_session->ftPEContext.pFTPreAuthReq->
				     pbssDescription);
			pe_session->ftPEContext.pFTPreAuthReq->
			pbssDescription = NULL;
		}
		qdf_mem_free(pe_session->ftPEContext.pFTPreAuthReq);
		pe_session->ftPEContext.pFTPreAuthReq = NULL;
	}

	if (pe_session->ftPEContext.pAddBssReq) {
		qdf_mem_free(pe_session->ftPEContext.pAddBssReq);
		pe_session->ftPEContext.pAddBssReq = NULL;
	}

	if (pe_session->ftPEContext.pAddStaReq) {
		qdf_mem_free(pe_session->ftPEContext.pAddStaReq);
		pe_session->ftPEContext.pAddStaReq = NULL;
	}

	/* The session is being deleted, cleanup the contents */
	qdf_mem_zero(&pe_session->ftPEContext, sizeof(tftPEContext));
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

#if defined(WLAN_FEATURE_HOST_ROAM) || defined(WLAN_FEATURE_ROAM_OFFLOAD)
/*------------------------------------------------------------------
 *
 * Create the new Add Bss Req to the new AP.
 * This will be used when we are ready to FT to the new AP.
 * The newly created ft Session entry is passed to this function
 *
 *------------------------------------------------------------------*/
<<<<<<< HEAD
void lim_ft_prepare_add_bss_req(tpAniSirGlobal pMac,
		uint8_t updateEntry, tpPESession pftSessionEntry,
		tpSirBssDescription bssDescription)
{
	tpAddBssParams pAddBssParams = NULL;
	tAddStaParams *sta_ctx;
	uint8_t chanWidthSupp = 0;
	tSchBeaconStruct *pBeaconStruct;

	/* Nothing to be done if the session is not in STA mode */
	if (!LIM_IS_STA_ROLE(pftSessionEntry)) {
		pe_err("psessionEntry is not in STA mode");
=======
void lim_ft_prepare_add_bss_req(struct mac_context *mac,
		struct pe_session *ft_session,
		struct bss_description *bssDescription)
{
	struct bss_params *pAddBssParams = NULL;
	tAddStaParams *sta_ctx;
	bool chan_width_support = false;
	tSchBeaconStruct *pBeaconStruct;
	tDot11fIEVHTCaps *vht_caps = NULL;

	/* Nothing to be done if the session is not in STA mode */
	if (!LIM_IS_STA_ROLE(ft_session)) {
		pe_err("pe_session is not in STA mode");
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		return;
	}

	pBeaconStruct = qdf_mem_malloc(sizeof(tSchBeaconStruct));
<<<<<<< HEAD
	if (NULL == pBeaconStruct) {
		pe_err("Unable to allocate memory for creating ADD_BSS");
		return;
	}
	/* Package SIR_HAL_ADD_BSS_REQ message parameters */
	pAddBssParams = qdf_mem_malloc(sizeof(tAddBssParams));
	if (NULL == pAddBssParams) {
		qdf_mem_free(pBeaconStruct);
		pe_err("Unable to allocate memory for creating ADD_BSS");
		return;
	}

	lim_extract_ap_capabilities(pMac, (uint8_t *) bssDescription->ieFields,
			lim_get_ielen_from_bss_description(bssDescription),
			pBeaconStruct);

	if (pMac->lim.gLimProtectionControl !=
	    WNI_CFG_FORCE_POLICY_PROTECTION_DISABLE)
		lim_decide_sta_protection_on_assoc(pMac, pBeaconStruct,
						   pftSessionEntry);

	qdf_mem_copy(pAddBssParams->bssId, bssDescription->bssId,
		     sizeof(tSirMacAddr));

	/* Fill in tAddBssParams selfMacAddr */
	qdf_mem_copy(pAddBssParams->selfMacAddr, pftSessionEntry->selfMacAddr,
		     sizeof(tSirMacAddr));

	pAddBssParams->bssType = pftSessionEntry->bssType;
	pAddBssParams->operMode = BSS_OPERATIONAL_MODE_STA;

	pAddBssParams->beaconInterval = bssDescription->beaconInterval;

	pAddBssParams->dtimPeriod = pBeaconStruct->tim.dtimPeriod;
	pAddBssParams->updateBss = updateEntry;

	pAddBssParams->reassocReq = true;

	pAddBssParams->cfParamSet.cfpCount = pBeaconStruct->cfParamSet.cfpCount;
	pAddBssParams->cfParamSet.cfpPeriod =
		pBeaconStruct->cfParamSet.cfpPeriod;
	pAddBssParams->cfParamSet.cfpMaxDuration =
		pBeaconStruct->cfParamSet.cfpMaxDuration;
	pAddBssParams->cfParamSet.cfpDurRemaining =
		pBeaconStruct->cfParamSet.cfpDurRemaining;

	pAddBssParams->rateSet.numRates =
		pBeaconStruct->supportedRates.numRates;
	qdf_mem_copy(pAddBssParams->rateSet.rate,
		     pBeaconStruct->supportedRates.rate,
		     pBeaconStruct->supportedRates.numRates);
=======
	if (!pBeaconStruct)
		return;

	/* Package SIR_HAL_ADD_BSS_REQ message parameters */
	pAddBssParams = qdf_mem_malloc(sizeof(struct bss_params));
	if (!pAddBssParams) {
		qdf_mem_free(pBeaconStruct);
		return;
	}

	lim_extract_ap_capabilities(mac, (uint8_t *) bssDescription->ieFields,
			lim_get_ielen_from_bss_description(bssDescription),
			pBeaconStruct);

	if (mac->lim.gLimProtectionControl !=
	    MLME_FORCE_POLICY_PROTECTION_DISABLE)
		lim_decide_sta_protection_on_assoc(mac, pBeaconStruct,
						   ft_session);

	qdf_mem_copy(pAddBssParams->bssId, bssDescription->bssId,
		     sizeof(tSirMacAddr));
	pAddBssParams->beaconInterval = bssDescription->beaconInterval;

	pAddBssParams->dtimPeriod = pBeaconStruct->tim.dtimPeriod;
	pAddBssParams->updateBss = false;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	pAddBssParams->nwType = bssDescription->nwType;

	pAddBssParams->shortSlotTimeSupported =
		(uint8_t) pBeaconStruct->capabilityInfo.shortSlotTime;
<<<<<<< HEAD
	pAddBssParams->llaCoexist =
		(uint8_t) pftSessionEntry->beaconParams.llaCoexist;
	pAddBssParams->llbCoexist =
		(uint8_t) pftSessionEntry->beaconParams.llbCoexist;
	pAddBssParams->llgCoexist =
		(uint8_t) pftSessionEntry->beaconParams.llgCoexist;
	pAddBssParams->ht20Coexist =
		(uint8_t) pftSessionEntry->beaconParams.ht20Coexist;
#ifdef WLAN_FEATURE_11W
	pAddBssParams->rmfEnabled = pftSessionEntry->limRmfEnabled;
#endif

	/* Use the advertised capabilities from the received beacon/PR */
	if (IS_DOT11_MODE_HT(pftSessionEntry->dot11mode) &&
	    (pBeaconStruct->HTCaps.present)) {
		pAddBssParams->htCapable = pBeaconStruct->HTCaps.present;
=======
	pAddBssParams->llbCoexist =
		(uint8_t) ft_session->beaconParams.llbCoexist;
#ifdef WLAN_FEATURE_11W
	pAddBssParams->rmfEnabled = ft_session->limRmfEnabled;
#endif
	/* Use the advertised capabilities from the received beacon/PR */
	if (IS_DOT11_MODE_HT(ft_session->dot11mode) &&
	    (pBeaconStruct->HTCaps.present)) {
		chan_width_support =
			lim_get_ht_capability(mac,
					      eHT_SUPPORTED_CHANNEL_WIDTH_SET,
					      ft_session);
		lim_sta_add_bss_update_ht_parameter(bssDescription->chan_freq,
						    &pBeaconStruct->HTCaps,
						    &pBeaconStruct->HTInfo,
						    chan_width_support,
						    pAddBssParams);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		qdf_mem_copy(&pAddBssParams->staContext.capab_info,
			     &pBeaconStruct->capabilityInfo,
			     sizeof(pAddBssParams->staContext.capab_info));
		qdf_mem_copy(&pAddBssParams->staContext.ht_caps,
			     (uint8_t *) &pBeaconStruct->HTCaps +
			     sizeof(uint8_t),
			     sizeof(pAddBssParams->staContext.ht_caps));
<<<<<<< HEAD

		if (pBeaconStruct->HTInfo.present) {
			pAddBssParams->htOperMode =
				(tSirMacHTOperatingMode) pBeaconStruct->HTInfo.
				opMode;
			pAddBssParams->dualCTSProtection =
				(uint8_t) pBeaconStruct->HTInfo.dualCTSProtection;

			chanWidthSupp = lim_get_ht_capability(pMac,
							      eHT_SUPPORTED_CHANNEL_WIDTH_SET,
							      pftSessionEntry);
			if ((pBeaconStruct->HTCaps.supportedChannelWidthSet) &&
			    (chanWidthSupp)) {
				pAddBssParams->ch_width = (uint8_t)
					pBeaconStruct->HTInfo.recommendedTxWidthSet;
				if (pBeaconStruct->HTInfo.secondaryChannelOffset ==
						PHY_DOUBLE_CHANNEL_LOW_PRIMARY)
					pAddBssParams->ch_center_freq_seg0 =
						bssDescription->channelId + 2;
				else if (pBeaconStruct->HTInfo.secondaryChannelOffset ==
						PHY_DOUBLE_CHANNEL_HIGH_PRIMARY)
					pAddBssParams->ch_center_freq_seg0 =
						bssDescription->channelId - 2;
			} else {
				pAddBssParams->ch_width = CH_WIDTH_20MHZ;
				pAddBssParams->ch_center_freq_seg0 = 0;
			}
			pAddBssParams->llnNonGFCoexist =
				(uint8_t) pBeaconStruct->HTInfo.nonGFDevicesPresent;
			pAddBssParams->fLsigTXOPProtectionFullSupport =
				(uint8_t) pBeaconStruct->HTInfo.
				lsigTXOPProtectionFullSupport;
			pAddBssParams->fRIFSMode =
				pBeaconStruct->HTInfo.rifsMode;
		}
	}

	pAddBssParams->currentOperChannel = bssDescription->channelId;
	pftSessionEntry->htSecondaryChannelOffset =
		pBeaconStruct->HTInfo.secondaryChannelOffset;
	sta_ctx = &pAddBssParams->staContext;

	if (pftSessionEntry->vhtCapability &&
	    pftSessionEntry->vhtCapabilityPresentInBeacon) {
		pAddBssParams->vhtCapable = pBeaconStruct->VHTCaps.present;
		if (pBeaconStruct->VHTOperation.chanWidth && chanWidthSupp) {
			pAddBssParams->ch_width =
				pBeaconStruct->VHTOperation.chanWidth + 1;
			pAddBssParams->ch_center_freq_seg0 =
				pBeaconStruct->VHTOperation.chanCenterFreqSeg1;
			pAddBssParams->ch_center_freq_seg1 =
				pBeaconStruct->VHTOperation.chanCenterFreqSeg2;
		}
		pAddBssParams->staContext.vht_caps =
			((pBeaconStruct->VHTCaps.maxMPDULen <<
			  SIR_MAC_VHT_CAP_MAX_MPDU_LEN) |
			 (pBeaconStruct->VHTCaps.supportedChannelWidthSet <<
			  SIR_MAC_VHT_CAP_SUPP_CH_WIDTH_SET) |
			 (pBeaconStruct->VHTCaps.ldpcCodingCap <<
			  SIR_MAC_VHT_CAP_LDPC_CODING_CAP) |
			 (pBeaconStruct->VHTCaps.shortGI80MHz <<
			  SIR_MAC_VHT_CAP_SHORTGI_80MHZ) |
			 (pBeaconStruct->VHTCaps.shortGI160and80plus80MHz <<
			  SIR_MAC_VHT_CAP_SHORTGI_160_80_80MHZ) |
			 (pBeaconStruct->VHTCaps.txSTBC <<
			  SIR_MAC_VHT_CAP_TXSTBC) |
			 (pBeaconStruct->VHTCaps.rxSTBC <<
			  SIR_MAC_VHT_CAP_RXSTBC) |
			 (pBeaconStruct->VHTCaps.suBeamFormerCap <<
			  SIR_MAC_VHT_CAP_SU_BEAMFORMER_CAP) |
			 (pBeaconStruct->VHTCaps.suBeamformeeCap <<
			  SIR_MAC_VHT_CAP_SU_BEAMFORMEE_CAP) |
			 (pBeaconStruct->VHTCaps.csnofBeamformerAntSup <<
			  SIR_MAC_VHT_CAP_CSN_BEAMORMER_ANT_SUP) |
			 (pBeaconStruct->VHTCaps.numSoundingDim <<
			  SIR_MAC_VHT_CAP_NUM_SOUNDING_DIM) |
			 (pBeaconStruct->VHTCaps.muBeamformerCap <<
			  SIR_MAC_VHT_CAP_NUM_BEAM_FORMER_CAP) |
			 (pBeaconStruct->VHTCaps.muBeamformeeCap <<
			  SIR_MAC_VHT_CAP_NUM_BEAM_FORMEE_CAP) |
			 (pBeaconStruct->VHTCaps.vhtTXOPPS <<
			  SIR_MAC_VHT_CAP_TXOPPS) |
			 (pBeaconStruct->VHTCaps.htcVHTCap <<
			  SIR_MAC_VHT_CAP_HTC_CAP) |
			 (pBeaconStruct->VHTCaps.maxAMPDULenExp <<
			  SIR_MAC_VHT_CAP_MAX_AMDU_LEN_EXPO) |
			 (pBeaconStruct->VHTCaps.vhtLinkAdaptCap <<
			  SIR_MAC_VHT_CAP_LINK_ADAPT_CAP) |
			 (pBeaconStruct->VHTCaps.rxAntPattern <<
			  SIR_MAC_VHT_CAP_RX_ANTENNA_PATTERN) |
			 (pBeaconStruct->VHTCaps.txAntPattern <<
			  SIR_MAC_VHT_CAP_TX_ANTENNA_PATTERN) |
			 (pBeaconStruct->VHTCaps.reserved1 <<
			  SIR_MAC_VHT_CAP_RESERVED2));
=======
	}

	ft_session->htSecondaryChannelOffset =
		pBeaconStruct->HTInfo.secondaryChannelOffset;
	sta_ctx = &pAddBssParams->staContext;

	if (ft_session->vhtCapability &&
	    ft_session->vhtCapabilityPresentInBeacon) {
		pAddBssParams->vhtCapable = pBeaconStruct->VHTCaps.present;
		if (pBeaconStruct->VHTOperation.chanWidth && chan_width_support)
			pAddBssParams->ch_width =
				pBeaconStruct->VHTOperation.chanWidth + 1;
		vht_caps = &pBeaconStruct->VHTCaps;
		lim_update_vhtcaps_assoc_resp(mac, pAddBssParams,
					      vht_caps, ft_session);
	} else if (ft_session->vhtCapability &&
	    pBeaconStruct->vendor_vht_ie.VHTCaps.present) {
		pe_debug("VHT caps are present in vendor specific IE");
		pAddBssParams->vhtCapable =
			pBeaconStruct->vendor_vht_ie.VHTCaps.present;
		if (pBeaconStruct->vendor_vht_ie.VHTOperation.chanWidth &&
		    chan_width_support)
			pAddBssParams->ch_width =
			pBeaconStruct->vendor_vht_ie.VHTOperation.chanWidth + 1;
		vht_caps = &pBeaconStruct->vendor_vht_ie.VHTCaps;
		lim_update_vhtcaps_assoc_resp(mac, pAddBssParams,
					      vht_caps, ft_session);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	} else {
		pAddBssParams->vhtCapable = 0;
	}

<<<<<<< HEAD
	pe_debug("SIR_HAL_ADD_BSS_REQ with channel: %d",
		pAddBssParams->currentOperChannel);
=======
	if (lim_is_session_he_capable(ft_session) &&
	    pBeaconStruct->he_cap.present) {
		lim_update_bss_he_capable(mac, pAddBssParams);
		lim_add_bss_he_cfg(pAddBssParams, ft_session);
	}

	pe_debug("SIR_HAL_ADD_BSS_REQ with frequency: %d",
		bssDescription->chan_freq);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	/* Populate the STA-related parameters here */
	/* Note that the STA here refers to the AP */
	{
		pAddBssParams->staContext.staType = STA_ENTRY_OTHER;

		qdf_mem_copy(pAddBssParams->staContext.bssId,
			     bssDescription->bssId, sizeof(tSirMacAddr));
		pAddBssParams->staContext.listenInterval =
			bssDescription->beaconInterval;

		pAddBssParams->staContext.assocId = 0;
		pAddBssParams->staContext.uAPSD = 0;
		pAddBssParams->staContext.maxSPLen = 0;
<<<<<<< HEAD
		pAddBssParams->staContext.shortPreambleSupported =
			(uint8_t) pBeaconStruct->capabilityInfo.shortPreamble;
		pAddBssParams->staContext.updateSta = updateEntry;
		pAddBssParams->staContext.encryptType =
			pftSessionEntry->encryptType;
#ifdef WLAN_FEATURE_11W
		pAddBssParams->staContext.rmfEnabled =
			pftSessionEntry->limRmfEnabled;
#endif

		if (IS_DOT11_MODE_HT(pftSessionEntry->dot11mode) &&
		    (pBeaconStruct->HTCaps.present)) {
			pAddBssParams->staContext.us32MaxAmpduDuration = 0;
			pAddBssParams->staContext.htCapable = 1;
			pAddBssParams->staContext.greenFieldCapable =
				(uint8_t) pBeaconStruct->HTCaps.greenField;
			pAddBssParams->staContext.lsigTxopProtection =
				(uint8_t) pBeaconStruct->HTCaps.lsigTXOPProtection;
			if ((pBeaconStruct->HTCaps.supportedChannelWidthSet) &&
			    (chanWidthSupp)) {
=======
		pAddBssParams->staContext.updateSta = false;
		pAddBssParams->staContext.encryptType =
			ft_session->encryptType;
#ifdef WLAN_FEATURE_11W
		pAddBssParams->staContext.rmfEnabled =
			ft_session->limRmfEnabled;
#endif

		if (IS_DOT11_MODE_HT(ft_session->dot11mode) &&
		    (pBeaconStruct->HTCaps.present)) {
			pAddBssParams->staContext.htCapable = 1;
			if (pBeaconStruct->HTCaps.supportedChannelWidthSet &&
			    chan_width_support) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				pAddBssParams->staContext.ch_width = (uint8_t)
					pBeaconStruct->HTInfo.recommendedTxWidthSet;
			} else {
				pAddBssParams->staContext.ch_width =
					CH_WIDTH_20MHZ;
			}
<<<<<<< HEAD
			if (pftSessionEntry->vhtCapability &&
=======
			if (ft_session->vhtCapability &&
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			    IS_BSS_VHT_CAPABLE(pBeaconStruct->VHTCaps)) {
				pAddBssParams->staContext.vhtCapable = 1;
				if ((pBeaconStruct->VHTCaps.suBeamFormerCap ||
				     pBeaconStruct->VHTCaps.muBeamformerCap) &&
<<<<<<< HEAD
				    pftSessionEntry->vht_config.su_beam_formee)
					sta_ctx->vhtTxBFCapable
						= 1;
				if (pBeaconStruct->VHTCaps.suBeamformeeCap &&
				    pftSessionEntry->vht_config.su_beam_former)
					sta_ctx->enable_su_tx_bformer = 1;
			}
			if ((pBeaconStruct->HTCaps.supportedChannelWidthSet) &&
			    (chanWidthSupp)) {
=======
				    ft_session->vht_config.su_beam_formee)
					sta_ctx->vhtTxBFCapable
						= 1;
				if (pBeaconStruct->VHTCaps.suBeamformeeCap &&
				    ft_session->vht_config.su_beam_former)
					sta_ctx->enable_su_tx_bformer = 1;
			}
			if (lim_is_session_he_capable(ft_session) &&
				pBeaconStruct->he_cap.present)
				lim_intersect_ap_he_caps(ft_session,
					pAddBssParams, pBeaconStruct, NULL);

			if (pBeaconStruct->HTCaps.supportedChannelWidthSet &&
			    chan_width_support) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				sta_ctx->ch_width = (uint8_t)
					pBeaconStruct->HTInfo.recommendedTxWidthSet;
				if (pAddBssParams->staContext.vhtCapable &&
					pBeaconStruct->VHTOperation.chanWidth)
					sta_ctx->ch_width =
					pBeaconStruct->VHTOperation.chanWidth
						+ 1;
			} else {
				pAddBssParams->staContext.ch_width =
					CH_WIDTH_20MHZ;
			}
			pAddBssParams->staContext.mimoPS =
				(tSirMacHTMIMOPowerSaveState) pBeaconStruct->HTCaps.
				mimoPowerSave;
<<<<<<< HEAD
			pAddBssParams->staContext.maxAmsduSize =
				(uint8_t) pBeaconStruct->HTCaps.maximalAMSDUsize;
			pAddBssParams->staContext.maxAmpduDensity =
				pBeaconStruct->HTCaps.mpduDensity;
			pAddBssParams->staContext.fDsssCckMode40Mhz =
				(uint8_t) pBeaconStruct->HTCaps.dsssCckMode40MHz;
=======
			pAddBssParams->staContext.maxAmpduDensity =
				pBeaconStruct->HTCaps.mpduDensity;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			pAddBssParams->staContext.fShortGI20Mhz =
				(uint8_t) pBeaconStruct->HTCaps.shortGI20MHz;
			pAddBssParams->staContext.fShortGI40Mhz =
				(uint8_t) pBeaconStruct->HTCaps.shortGI40MHz;
			pAddBssParams->staContext.maxAmpduSize =
				pBeaconStruct->HTCaps.maxRxAMPDUFactor;
<<<<<<< HEAD

			if (pBeaconStruct->HTInfo.present)
				pAddBssParams->staContext.rifsMode =
					pBeaconStruct->HTInfo.rifsMode;
		}

		if ((pftSessionEntry->limWmeEnabled
		     && pBeaconStruct->wmeEdcaPresent)
		    || (pftSessionEntry->limQosEnabled
=======
		}

		if ((ft_session->limWmeEnabled
		     && pBeaconStruct->wmeEdcaPresent)
		    || (ft_session->limQosEnabled
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			&& pBeaconStruct->edcaPresent))
			pAddBssParams->staContext.wmmEnabled = 1;
		else
			pAddBssParams->staContext.wmmEnabled = 0;

		pAddBssParams->staContext.wpa_rsn = pBeaconStruct->rsnPresent;
		/* For OSEN Connection AP does not advertise RSN or WPA IE
		 * so from the IEs we get from supplicant we get this info
		 * so for FW to transmit EAPOL message 4 we shall set
		 * wpa_rsn
		 */
		pAddBssParams->staContext.wpa_rsn |=
			(pBeaconStruct->wpaPresent << 1);
		if ((!pAddBssParams->staContext.wpa_rsn)
<<<<<<< HEAD
		    && (pftSessionEntry->isOSENConnection))
			pAddBssParams->staContext.wpa_rsn = 1;
		/* Update the rates */
		lim_populate_peer_rate_set(pMac,
					   &pAddBssParams->staContext.
					   supportedRates,
					   pBeaconStruct->HTCaps.supportedMCSSet,
					   false, pftSessionEntry,
					   &pBeaconStruct->VHTCaps);
	}

	pAddBssParams->maxTxPower = pftSessionEntry->maxTxPower;

#ifdef WLAN_FEATURE_11W
	if (pftSessionEntry->limRmfEnabled) {
=======
		    && (ft_session->isOSENConnection))
			pAddBssParams->staContext.wpa_rsn = 1;
		/* Update the rates */
		lim_populate_peer_rate_set(mac,
					   &pAddBssParams->staContext.
					   supportedRates,
					   pBeaconStruct->HTCaps.supportedMCSSet,
					   false, ft_session,
					   &pBeaconStruct->VHTCaps,
					   &pBeaconStruct->he_cap, NULL,
					   bssDescription);
	}

	pAddBssParams->maxTxPower = ft_session->maxTxPower;

#ifdef WLAN_FEATURE_11W
	if (ft_session->limRmfEnabled) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		pAddBssParams->rmfEnabled = 1;
		pAddBssParams->staContext.rmfEnabled = 1;
	}
#endif
<<<<<<< HEAD

	pAddBssParams->status = QDF_STATUS_SUCCESS;
	pAddBssParams->respReqd = true;

	pAddBssParams->staContext.sessionId = pftSessionEntry->peSessionId;
	pAddBssParams->staContext.smesessionId = pftSessionEntry->smeSessionId;
	pAddBssParams->sessionId = pftSessionEntry->peSessionId;

	/* Set a new state for MLME */
	if (!lim_is_roam_synch_in_progress(pftSessionEntry)) {
		pftSessionEntry->limMlmState =
			eLIM_MLM_WT_ADD_BSS_RSP_FT_REASSOC_STATE;
		MTRACE(mac_trace
			(pMac, TRACE_CODE_MLM_STATE,
			pftSessionEntry->peSessionId,
			eLIM_MLM_WT_ADD_BSS_RSP_FT_REASSOC_STATE));
	}
	pAddBssParams->halPersona = (uint8_t) pftSessionEntry->pePersona;

	pftSessionEntry->ftPEContext.pAddBssReq = pAddBssParams;
=======
	pAddBssParams->staContext.sessionId = ft_session->peSessionId;
	pAddBssParams->staContext.smesessionId = ft_session->smeSessionId;

	/* Set a new state for MLME */
	if (!lim_is_roam_synch_in_progress(ft_session)) {
		ft_session->limMlmState =
			eLIM_MLM_WT_ADD_BSS_RSP_FT_REASSOC_STATE;
		MTRACE(mac_trace
			(mac, TRACE_CODE_MLM_STATE,
			ft_session->peSessionId,
			eLIM_MLM_WT_ADD_BSS_RSP_FT_REASSOC_STATE));
	}
	ft_session->ftPEContext.pAddBssReq = pAddBssParams;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	pe_debug("Saving SIR_HAL_ADD_BSS_REQ for pre-auth ap");

	qdf_mem_free(pBeaconStruct);
	return;
}
#endif

<<<<<<< HEAD
#ifdef WLAN_FEATURE_ROAM_OFFLOAD
=======
#if defined(WLAN_FEATURE_ROAM_OFFLOAD)

/**
 * lim_convert_phymode_to_dot11mode() - get dot11 mode from phymode
 * @phymode: phymode
 *
 * The function is to convert the phymode to corresponding dot11 mode
 *
 * Return: dot11mode.
 */
static uint8_t lim_convert_phymode_to_dot11mode(enum wlan_phymode phymode)
{

	if (IS_WLAN_PHYMODE_HE(phymode))
		return MLME_DOT11_MODE_11AX;

	if (IS_WLAN_PHYMODE_VHT(phymode))
		return MLME_DOT11_MODE_11AC;

	if (IS_WLAN_PHYMODE_HT(phymode))
		return MLME_DOT11_MODE_11N;

	if (phymode == WLAN_PHYMODE_11G)
		return MLME_DOT11_MODE_11G;

	if (phymode == WLAN_PHYMODE_11G_ONLY)
		return MLME_DOT11_MODE_11G_ONLY;

	if (phymode == WLAN_PHYMODE_11A)
		return MLME_DOT11_MODE_11A;

	if (phymode == WLAN_PHYMODE_11B)
		return MLME_DOT11_MODE_11B;

	return MLME_DOT11_MODE_ALL;
}

/**
 * lim_calculate_dot11_mode() - calculate dot11 mode.
 * @mac_context: mac context
 * @bcn: beacon structure
 * @band: reg_wifi_band
 *
 * The function is to calculate dot11 mode in case fw doen't send phy mode.
 *
 * Return: dot11mode.
 */
static uint8_t lim_calculate_dot11_mode(struct mac_context *mac_ctx,
					tSchBeaconStruct *bcn,
					enum reg_wifi_band band)
{
	enum mlme_dot11_mode self_dot11_mode;
	enum mlme_dot11_mode new_dot11_mode;

	self_dot11_mode = mac_ctx->mlme_cfg->dot11_mode.dot11_mode;

	if (band == REG_BAND_2G)
		new_dot11_mode = MLME_DOT11_MODE_11G;
	else
		new_dot11_mode = MLME_DOT11_MODE_11A;

	switch (self_dot11_mode) {
	case MLME_DOT11_MODE_11AX:
	case MLME_DOT11_MODE_11AX_ONLY:
	case MLME_DOT11_MODE_ALL:
		if (bcn->he_cap.present)
			return MLME_DOT11_MODE_11AX;
		else if (bcn->VHTCaps.present ||
			 bcn->vendor_vht_ie.present)
			return MLME_DOT11_MODE_11AC;
		else if (bcn->HTCaps.present)
			return MLME_DOT11_MODE_11N;
	case MLME_DOT11_MODE_11AC:
	case MLME_DOT11_MODE_11AC_ONLY:
		if (bcn->VHTCaps.present ||
		    bcn->vendor_vht_ie.present)
			return MLME_DOT11_MODE_11AC;
		else if (bcn->HTCaps.present)
			return MLME_DOT11_MODE_11N;
	case MLME_DOT11_MODE_11N:
	case MLME_DOT11_MODE_11N_ONLY:
		if (bcn->HTCaps.present)
			return MLME_DOT11_MODE_11N;
	default:
			return new_dot11_mode;
	}

}

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
/**
 * lim_fill_dot11mode() - to fill 802.11 mode in FT session
 * @mac_ctx: pointer to mac ctx
 * @ft_session: FT session
<<<<<<< HEAD
 * @psessionEntry: PE session
 * @bcn: AP beacon pointer
=======
 * @pe_session: PE session
 * @bcn: AP beacon pointer
 * @bss_phymode: bss phy mode
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *
 * This API fills FT session's dot11mode either from pe session or
 * from CFG depending on the condition.
 *
 * Return: none
 */
<<<<<<< HEAD
static void lim_fill_dot11mode(tpAniSirGlobal mac_ctx,
			       tpPESession ft_session,
			       tpPESession psessionEntry,
			       tSchBeaconStruct *bcn)
{
	uint32_t self_dot11_mode;

	if (psessionEntry->ftPEContext.pFTPreAuthReq &&
			!mac_ctx->roam.configParam.isRoamOffloadEnabled) {
		ft_session->dot11mode =
			psessionEntry->ftPEContext.pFTPreAuthReq->dot11mode;
		return;
	}

	wlan_cfg_get_int(mac_ctx, WNI_CFG_DOT11_MODE, &self_dot11_mode);
	pe_debug("selfDot11Mode: %d", self_dot11_mode);

	if (ft_session->limRFBand == SIR_BAND_2_4_GHZ)
		ft_session->dot11mode = WNI_CFG_DOT11_MODE_11G;
	else
		ft_session->dot11mode = WNI_CFG_DOT11_MODE_11A;

	switch (self_dot11_mode) {
	case WNI_CFG_DOT11_MODE_11AC:
	case WNI_CFG_DOT11_MODE_11AC_ONLY:
		if (bcn->VHTCaps.present)
			ft_session->dot11mode = WNI_CFG_DOT11_MODE_11AC;
		else if (bcn->HTCaps.present)
			ft_session->dot11mode = WNI_CFG_DOT11_MODE_11N;
		break;
	case WNI_CFG_DOT11_MODE_11N:
	case WNI_CFG_DOT11_MODE_11N_ONLY:
		if (bcn->HTCaps.present)
			ft_session->dot11mode = WNI_CFG_DOT11_MODE_11N;
		break;
	}
}
#else
/**
 * lim_fill_dot11mode() - to fill 802.11 mode in FT session
 * @mac_ctx: pointer to mac ctx
 * @pftSessionEntry: FT session
 * @psessionEntry: PE session
 * @bcn: AP beacon pointer
=======
static void lim_fill_dot11mode(struct mac_context *mac_ctx,
			       struct pe_session *ft_session,
			       struct pe_session *pe_session,
			       tSchBeaconStruct *bcn,
			       enum wlan_phymode bss_phymode)
{
	if (pe_session->ftPEContext.pFTPreAuthReq &&
	    !csr_is_roam_offload_enabled(mac_ctx)) {
		ft_session->dot11mode =
			pe_session->ftPEContext.pFTPreAuthReq->dot11mode;
		return;
	}

	if (bss_phymode == WLAN_PHYMODE_AUTO)
		ft_session->dot11mode = lim_calculate_dot11_mode(
							mac_ctx, bcn,
							ft_session->limRFBand);

	else
		ft_session->dot11mode =
			lim_convert_phymode_to_dot11mode(bss_phymode);
}
#elif defined(WLAN_FEATURE_HOST_ROAM)
/**
 * lim_fill_dot11mode() - to fill 802.11 mode in FT session
 * @mac_ctx: pointer to mac ctx
 * @ft_session: FT session
 * @pe_session: PE session
 * @bcn: AP beacon pointer
 * @bss_phymode: bss phy mode
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 *
 * This API fills FT session's dot11mode either from pe session.
 *
 * Return: none
 */
<<<<<<< HEAD
static void lim_fill_dot11mode(tpAniSirGlobal mac_ctx,
			       tpPESession pftSessionEntry,
			       tpPESession psessionEntry,
			       tSchBeaconStruct *bcn)
{
	pftSessionEntry->dot11mode =
			psessionEntry->ftPEContext.pFTPreAuthReq->dot11mode;
=======
static void lim_fill_dot11mode(struct mac_context *mac_ctx,
			       struct pe_session *ft_session,
			       struct pe_session *pe_session,
			       tSchBeaconStruct *bcn,
			       enum wlan_phymode bss_phymode)
{
	ft_session->dot11mode =
			pe_session->ftPEContext.pFTPreAuthReq->dot11mode;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}
#endif

#if defined(WLAN_FEATURE_HOST_ROAM) || defined(WLAN_FEATURE_ROAM_OFFLOAD)
/*------------------------------------------------------------------
 *
 * Setup the new session for the pre-auth AP.
 * Return the newly created session entry.
 *
 *------------------------------------------------------------------*/
<<<<<<< HEAD
void lim_fill_ft_session(tpAniSirGlobal pMac,
			 tpSirBssDescription pbssDescription,
			 tpPESession pftSessionEntry, tpPESession psessionEntry)
{
	uint8_t currentBssUapsd;
=======
void lim_fill_ft_session(struct mac_context *mac,
			 struct bss_description *pbssDescription,
			 struct pe_session *ft_session,
			 struct pe_session *pe_session,
			 enum wlan_phymode bss_phymode)
{
	uint8_t currentBssUapsd;
	uint8_t bss_chan_id;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	int8_t localPowerConstraint;
	int8_t regMax;
	tSchBeaconStruct *pBeaconStruct;
	ePhyChanBondState cbEnabledMode;
<<<<<<< HEAD

	pBeaconStruct = qdf_mem_malloc(sizeof(tSchBeaconStruct));
	if (NULL == pBeaconStruct) {
		pe_err("No memory for creating lim_fill_ft_session");
		return;
	}

	/* Retrieve the session that was already created and update the entry */
	pftSessionEntry->limWmeEnabled = psessionEntry->limWmeEnabled;
	pftSessionEntry->limQosEnabled = psessionEntry->limQosEnabled;
	pftSessionEntry->limWsmEnabled = psessionEntry->limWsmEnabled;
	pftSessionEntry->lim11hEnable = psessionEntry->lim11hEnable;
	pftSessionEntry->isOSENConnection = psessionEntry->isOSENConnection;

	/* Fields to be filled later */
	pftSessionEntry->pLimJoinReq = NULL;
	pftSessionEntry->smeSessionId = psessionEntry->smeSessionId;
	pftSessionEntry->transactionId = 0;

	lim_extract_ap_capabilities(pMac, (uint8_t *) pbssDescription->ieFields,
			lim_get_ielen_from_bss_description(pbssDescription),
			pBeaconStruct);

	pftSessionEntry->rateSet.numRates =
		pBeaconStruct->supportedRates.numRates;
	qdf_mem_copy(pftSessionEntry->rateSet.rate,
		     pBeaconStruct->supportedRates.rate,
		     pBeaconStruct->supportedRates.numRates);

	pftSessionEntry->extRateSet.numRates =
		pBeaconStruct->extendedRates.numRates;
	qdf_mem_copy(pftSessionEntry->extRateSet.rate,
		     pBeaconStruct->extendedRates.rate,
		     pftSessionEntry->extRateSet.numRates);

	pftSessionEntry->ssId.length = pBeaconStruct->ssId.length;
	qdf_mem_copy(pftSessionEntry->ssId.ssId, pBeaconStruct->ssId.ssId,
		     pftSessionEntry->ssId.length);

	/* Copy The channel Id to the session Table */
	pftSessionEntry->limReassocChannelId = pbssDescription->channelId;
	pftSessionEntry->currentOperChannel = pbssDescription->channelId;

	pftSessionEntry->limRFBand = lim_get_rf_band(
				pftSessionEntry->currentOperChannel);
	lim_fill_dot11mode(pMac, pftSessionEntry, psessionEntry, pBeaconStruct);

	pe_debug("dot11mode: %d", pftSessionEntry->dot11mode);
	pftSessionEntry->vhtCapability =
		(IS_DOT11_MODE_VHT(pftSessionEntry->dot11mode)
		 && IS_BSS_VHT_CAPABLE(pBeaconStruct->VHTCaps));
	pftSessionEntry->htCapability =
		(IS_DOT11_MODE_HT(pftSessionEntry->dot11mode)
		 && pBeaconStruct->HTCaps.present);

	/* Copy The channel Id to the session Table */
	pftSessionEntry->limReassocChannelId = pbssDescription->channelId;
	pftSessionEntry->currentOperChannel = pbssDescription->channelId;

	pftSessionEntry->limRFBand = lim_get_rf_band(
				pftSessionEntry->currentOperChannel);

	if (pftSessionEntry->limRFBand == SIR_BAND_2_4_GHZ) {
		cbEnabledMode = pMac->roam.configParam.channelBondingMode24GHz;
	} else {
		cbEnabledMode = pMac->roam.configParam.channelBondingMode5GHz;
	}
	pftSessionEntry->htSupportedChannelWidthSet =
	    (pBeaconStruct->HTInfo.present) ?
	    (cbEnabledMode && pBeaconStruct->HTInfo.recommendedTxWidthSet) : 0;
	pftSessionEntry->htRecommendedTxWidthSet =
		pftSessionEntry->htSupportedChannelWidthSet;

	if (IS_BSS_VHT_CAPABLE(pBeaconStruct->VHTCaps) &&
		pBeaconStruct->VHTOperation.present &&
		pftSessionEntry->vhtCapability) {
		pftSessionEntry->vhtCapabilityPresentInBeacon = 1;
	} else {
		pftSessionEntry->vhtCapabilityPresentInBeacon = 0;
	}
	if (pftSessionEntry->htRecommendedTxWidthSet) {
		pftSessionEntry->ch_width = CH_WIDTH_40MHZ;
		if (pftSessionEntry->vhtCapabilityPresentInBeacon &&
				pBeaconStruct->VHTOperation.chanWidth) {
			pftSessionEntry->ch_width =
				pBeaconStruct->VHTOperation.chanWidth + 1;
			pftSessionEntry->ch_center_freq_seg0 =
				pBeaconStruct->VHTOperation.chanCenterFreqSeg1;
			pftSessionEntry->ch_center_freq_seg1 =
				pBeaconStruct->VHTOperation.chanCenterFreqSeg2;
		} else {
			if (pBeaconStruct->HTInfo.secondaryChannelOffset ==
					PHY_DOUBLE_CHANNEL_LOW_PRIMARY)
				pftSessionEntry->ch_center_freq_seg0 =
					pbssDescription->channelId + 2;
			else if (pBeaconStruct->HTInfo.secondaryChannelOffset ==
					PHY_DOUBLE_CHANNEL_HIGH_PRIMARY)
				pftSessionEntry->ch_center_freq_seg0 =
					pbssDescription->channelId - 2;
			else
				pe_warn("Invalid sec ch offset");
		}
	} else {
		pftSessionEntry->ch_width = CH_WIDTH_20MHZ;
		pftSessionEntry->ch_center_freq_seg0 = 0;
		pftSessionEntry->ch_center_freq_seg1 = 0;
	}

	sir_copy_mac_addr(pftSessionEntry->selfMacAddr,
			  psessionEntry->selfMacAddr);
	sir_copy_mac_addr(pftSessionEntry->limReAssocbssId,
			  pbssDescription->bssId);
	sir_copy_mac_addr(pftSessionEntry->prev_ap_bssid, psessionEntry->bssId);

	/* Store beaconInterval */
	pftSessionEntry->beaconParams.beaconInterval =
		pbssDescription->beaconInterval;
	pftSessionEntry->bssType = psessionEntry->bssType;

	pftSessionEntry->statypeForBss = STA_ENTRY_PEER;
	pftSessionEntry->nwType = pbssDescription->nwType;


	if (pftSessionEntry->bssType == eSIR_INFRASTRUCTURE_MODE) {
		pftSessionEntry->limSystemRole = eLIM_STA_ROLE;
=======
	struct lim_max_tx_pwr_attr tx_pwr_attr = {0};

	pBeaconStruct = qdf_mem_malloc(sizeof(tSchBeaconStruct));
	if (!pBeaconStruct)
		return;

	/* Retrieve the session that was already created and update the entry */
	ft_session->limWmeEnabled = pe_session->limWmeEnabled;
	ft_session->limQosEnabled = pe_session->limQosEnabled;
	ft_session->limWsmEnabled = pe_session->limWsmEnabled;
	ft_session->lim11hEnable = pe_session->lim11hEnable;
	ft_session->isOSENConnection = pe_session->isOSENConnection;
	ft_session->connected_akm = pe_session->connected_akm;

	/* Fields to be filled later */
	ft_session->lim_join_req = NULL;
	ft_session->smeSessionId = pe_session->smeSessionId;

	lim_extract_ap_capabilities(mac, (uint8_t *) pbssDescription->ieFields,
			lim_get_ielen_from_bss_description(pbssDescription),
			pBeaconStruct);

	ft_session->rateSet.numRates =
		pBeaconStruct->supportedRates.numRates;
	qdf_mem_copy(ft_session->rateSet.rate,
		     pBeaconStruct->supportedRates.rate,
		     pBeaconStruct->supportedRates.numRates);

	ft_session->extRateSet.numRates =
		pBeaconStruct->extendedRates.numRates;
	qdf_mem_copy(ft_session->extRateSet.rate,
		     pBeaconStruct->extendedRates.rate,
		     ft_session->extRateSet.numRates);

	ft_session->ssId.length = pBeaconStruct->ssId.length;
	qdf_mem_copy(ft_session->ssId.ssId, pBeaconStruct->ssId.ssId,
		     ft_session->ssId.length);
	/* Copy The channel Id to the session Table */
	bss_chan_id =
		wlan_reg_freq_to_chan(mac->pdev, pbssDescription->chan_freq);
	ft_session->lim_reassoc_chan_freq = pbssDescription->chan_freq;
	ft_session->curr_op_freq = pbssDescription->chan_freq;
	ft_session->limRFBand = lim_get_rf_band(ft_session->curr_op_freq);

	lim_fill_dot11mode(mac, ft_session, pe_session, pBeaconStruct,
			   bss_phymode);
	pe_debug("dot11mode: %d bss_phymode %d", ft_session->dot11mode,
		 bss_phymode);

	ft_session->vhtCapability =
		(IS_DOT11_MODE_VHT(ft_session->dot11mode) &&
		 (IS_BSS_VHT_CAPABLE(pBeaconStruct->VHTCaps) ||
		  IS_BSS_VHT_CAPABLE(pBeaconStruct->vendor_vht_ie.VHTCaps)));
	ft_session->htCapability =
		(IS_DOT11_MODE_HT(ft_session->dot11mode)
		 && pBeaconStruct->HTCaps.present);

	if (IS_DOT11_MODE_HE(ft_session->dot11mode) &&
	    pBeaconStruct->he_cap.present)
		lim_update_session_he_capable(mac, ft_session);

	/* Assign default configured nss value in the new session */
	if (wlan_reg_is_5ghz_ch_freq(ft_session->curr_op_freq))
		ft_session->vdev_nss = mac->vdev_type_nss_5g.sta;
	else
		ft_session->vdev_nss = mac->vdev_type_nss_2g.sta;

	ft_session->nss = ft_session ->vdev_nss;

	if (ft_session->limRFBand == REG_BAND_2G) {
		cbEnabledMode = mac->roam.configParam.channelBondingMode24GHz;
	} else {
		cbEnabledMode = mac->roam.configParam.channelBondingMode5GHz;
	}
	ft_session->htSupportedChannelWidthSet =
	    (pBeaconStruct->HTInfo.present) ?
	    (cbEnabledMode && pBeaconStruct->HTInfo.recommendedTxWidthSet) : 0;
	ft_session->htRecommendedTxWidthSet =
		ft_session->htSupportedChannelWidthSet;

	if (IS_BSS_VHT_CAPABLE(pBeaconStruct->VHTCaps) &&
		pBeaconStruct->VHTOperation.present &&
		ft_session->vhtCapability) {
		ft_session->vhtCapabilityPresentInBeacon = 1;
	} else if (IS_BSS_VHT_CAPABLE(pBeaconStruct->vendor_vht_ie.VHTCaps) &&
		    pBeaconStruct->vendor_vht_ie.VHTOperation.present &&
		    ft_session->vhtCapability){
		ft_session->vhtCapabilityPresentInBeacon = 1;
	} else {
		ft_session->vhtCapabilityPresentInBeacon = 0;
	}

	if (ft_session->htRecommendedTxWidthSet) {
		ft_session->ch_width = CH_WIDTH_40MHZ;
		if (ft_session->vhtCapabilityPresentInBeacon &&
				pBeaconStruct->VHTOperation.chanWidth) {
			ft_session->ch_width =
				pBeaconStruct->VHTOperation.chanWidth + 1;
			ft_session->ch_center_freq_seg0 =
			pBeaconStruct->VHTOperation.chan_center_freq_seg0;
			ft_session->ch_center_freq_seg1 =
			pBeaconStruct->VHTOperation.chan_center_freq_seg1;
		} else if (ft_session->vhtCapabilityPresentInBeacon &&
			   pBeaconStruct->vendor_vht_ie.VHTOperation.chanWidth){
			ft_session->ch_width =
			pBeaconStruct->vendor_vht_ie.VHTOperation.chanWidth + 1;
			ft_session->ch_center_freq_seg0 =
		pBeaconStruct->vendor_vht_ie.VHTOperation.chan_center_freq_seg0;
			ft_session->ch_center_freq_seg1 =
		pBeaconStruct->vendor_vht_ie.VHTOperation.chan_center_freq_seg1;

		} else {
			if (pBeaconStruct->HTInfo.secondaryChannelOffset ==
					PHY_DOUBLE_CHANNEL_LOW_PRIMARY)
				ft_session->ch_center_freq_seg0 =
					bss_chan_id + 2;
			else if (pBeaconStruct->HTInfo.secondaryChannelOffset ==
					PHY_DOUBLE_CHANNEL_HIGH_PRIMARY)
				ft_session->ch_center_freq_seg0 =
					bss_chan_id - 2;
			else {
				pe_warn("Invalid sec ch offset");
				ft_session->ch_width = CH_WIDTH_20MHZ;
				ft_session->ch_center_freq_seg0 = 0;
				ft_session->ch_center_freq_seg1 = 0;
			}
		}
	} else {
		ft_session->ch_width = CH_WIDTH_20MHZ;
		ft_session->ch_center_freq_seg0 = 0;
		ft_session->ch_center_freq_seg1 = 0;
	}

	sir_copy_mac_addr(ft_session->self_mac_addr,
			  pe_session->self_mac_addr);
	sir_copy_mac_addr(ft_session->limReAssocbssId,
			  pbssDescription->bssId);
	sir_copy_mac_addr(ft_session->prev_ap_bssid, pe_session->bssId);

	/* Store beaconInterval */
	ft_session->beaconParams.beaconInterval =
		pbssDescription->beaconInterval;
	ft_session->bssType = pe_session->bssType;

	ft_session->statypeForBss = STA_ENTRY_PEER;
	ft_session->nwType = pbssDescription->nwType;


	if (ft_session->bssType == eSIR_INFRASTRUCTURE_MODE) {
		ft_session->limSystemRole = eLIM_STA_ROLE;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	} else {
		/* Throw an error & return & make sure to delete the session */
		pe_warn("Invalid bss type");
	}

<<<<<<< HEAD
	pftSessionEntry->limCurrentBssCaps = pbssDescription->capabilityInfo;
	pftSessionEntry->limReassocBssCaps = pbssDescription->capabilityInfo;
	if (pMac->roam.configParam.shortSlotTime &&
	    SIR_MAC_GET_SHORT_SLOT_TIME(pftSessionEntry->limReassocBssCaps)) {
		pftSessionEntry->shortSlotTimeSupported = true;
	}

	regMax = cfg_get_regulatory_max_transmit_power(pMac,
						       pftSessionEntry->
						       currentOperChannel);
	localPowerConstraint = regMax;
	lim_extract_ap_capability(pMac, (uint8_t *) pbssDescription->ieFields,
		lim_get_ielen_from_bss_description(pbssDescription),
		&pftSessionEntry->limCurrentBssQosCaps,
		&pftSessionEntry->limCurrentBssPropCap, &currentBssUapsd,
		&localPowerConstraint, pftSessionEntry);

	pftSessionEntry->limReassocBssQosCaps =
		pftSessionEntry->limCurrentBssQosCaps;
	pftSessionEntry->limReassocBssPropCap =
		pftSessionEntry->limCurrentBssPropCap;

	pftSessionEntry->is11Rconnection = psessionEntry->is11Rconnection;
#ifdef FEATURE_WLAN_ESE
	pftSessionEntry->isESEconnection = psessionEntry->isESEconnection;
	pftSessionEntry->is_ese_version_ie_present =
		pBeaconStruct->is_ese_ver_ie_present;
#endif
	pftSessionEntry->isFastTransitionEnabled =
		psessionEntry->isFastTransitionEnabled;

	pftSessionEntry->isFastRoamIniFeatureEnabled =
		psessionEntry->isFastRoamIniFeatureEnabled;

#ifdef FEATURE_WLAN_ESE
	pftSessionEntry->maxTxPower =
		lim_get_max_tx_power(regMax, localPowerConstraint,
				     pMac->roam.configParam.nTxPowerCap);
#else
	pftSessionEntry->maxTxPower = QDF_MIN(regMax, (localPowerConstraint));
=======
	ft_session->limCurrentBssCaps = pbssDescription->capabilityInfo;
	ft_session->limReassocBssCaps = pbssDescription->capabilityInfo;
	if (mac->mlme_cfg->ht_caps.short_slot_time_enabled &&
	    SIR_MAC_GET_SHORT_SLOT_TIME(ft_session->limReassocBssCaps)) {
		ft_session->shortSlotTimeSupported = true;
	}

	regMax = wlan_reg_get_channel_reg_power_for_freq(
		mac->pdev, ft_session->curr_op_freq);
	localPowerConstraint = regMax;
	lim_extract_ap_capability(mac, (uint8_t *) pbssDescription->ieFields,

		lim_get_ielen_from_bss_description(pbssDescription),
		&ft_session->limCurrentBssQosCaps,
		&currentBssUapsd,
		&localPowerConstraint, ft_session);

	ft_session->limReassocBssQosCaps =
		ft_session->limCurrentBssQosCaps;

	ft_session->is11Rconnection = pe_session->is11Rconnection;
#ifdef FEATURE_WLAN_ESE
	ft_session->isESEconnection = pe_session->isESEconnection;
	ft_session->is_ese_version_ie_present =
		pBeaconStruct->is_ese_ver_ie_present;
#endif
	ft_session->isFastTransitionEnabled =
		pe_session->isFastTransitionEnabled;

	ft_session->isFastRoamIniFeatureEnabled =
		pe_session->isFastRoamIniFeatureEnabled;

	tx_pwr_attr.reg_max = regMax;
	tx_pwr_attr.ap_tx_power = localPowerConstraint;
	tx_pwr_attr.ini_tx_power = mac->mlme_cfg->power.max_tx_power;
	tx_pwr_attr.frequency = ft_session->curr_op_freq;

#ifdef FEATURE_WLAN_ESE
	ft_session->maxTxPower = lim_get_max_tx_power(mac, &tx_pwr_attr);
#else
	ft_session->maxTxPower = QDF_MIN(regMax, (localPowerConstraint));
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#endif

	pe_debug("Reg max: %d local pwr: %d, ini tx pwr: %d max tx pwr: %d",
		regMax, localPowerConstraint,
<<<<<<< HEAD
		pMac->roam.configParam.nTxPowerCap,
		pftSessionEntry->maxTxPower);
	if (!lim_is_roam_synch_in_progress(psessionEntry)) {
		pftSessionEntry->limPrevSmeState = pftSessionEntry->limSmeState;
		pftSessionEntry->limSmeState = eLIM_SME_WT_REASSOC_STATE;
		MTRACE(mac_trace(pMac,
				TRACE_CODE_SME_STATE,
				pftSessionEntry->peSessionId,
				pftSessionEntry->limSmeState));
	}
	pftSessionEntry->encryptType = psessionEntry->encryptType;
#ifdef WLAN_FEATURE_11W
	pftSessionEntry->limRmfEnabled = psessionEntry->limRmfEnabled;
#endif
	if ((pftSessionEntry->limRFBand == SIR_BAND_2_4_GHZ) &&
		(pftSessionEntry->htSupportedChannelWidthSet ==
		eHT_CHANNEL_WIDTH_40MHZ))
		lim_init_obss_params(pMac, pftSessionEntry);

	pftSessionEntry->enableHtSmps = psessionEntry->enableHtSmps;
	pftSessionEntry->htSmpsvalue = psessionEntry->htSmpsvalue;
=======
		mac->mlme_cfg->power.max_tx_power,
		ft_session->maxTxPower);
	if (!lim_is_roam_synch_in_progress(pe_session)) {
		ft_session->limPrevSmeState = ft_session->limSmeState;
		ft_session->limSmeState = eLIM_SME_WT_REASSOC_STATE;
		MTRACE(mac_trace(mac,
				TRACE_CODE_SME_STATE,
				ft_session->peSessionId,
				ft_session->limSmeState));
	}
	ft_session->encryptType = pe_session->encryptType;
#ifdef WLAN_FEATURE_11W
	ft_session->limRmfEnabled = pe_session->limRmfEnabled;
#endif
	if ((ft_session->limRFBand == REG_BAND_2G) &&
		(ft_session->htSupportedChannelWidthSet ==
		eHT_CHANNEL_WIDTH_40MHZ))
		lim_init_obss_params(mac, ft_session);

	ft_session->enableHtSmps = pe_session->enableHtSmps;
	ft_session->htSmpsvalue = pe_session->htSmpsvalue;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	/*
	 * By default supported NSS 1x1 is set to true
	 * and later on updated while determining session
	 * supported rates which is the intersection of
	 * self and peer rates
	 */
<<<<<<< HEAD
	pftSessionEntry->supported_nss_1x1 = true;
	pe_debug("FT enable smps: %d mode: %d supported nss 1x1: %d",
		pftSessionEntry->enableHtSmps,
		pftSessionEntry->htSmpsvalue,
		pftSessionEntry->supported_nss_1x1);
=======
	ft_session->supported_nss_1x1 = true;
	pe_debug("FT enable smps: %d mode: %d supported nss 1x1: %d",
		ft_session->enableHtSmps,
		ft_session->htSmpsvalue,
		ft_session->supported_nss_1x1);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

	qdf_mem_free(pBeaconStruct);
}
#endif

<<<<<<< HEAD
/*------------------------------------------------------------------
 *
 * This function is called to process the update key request from SME
 *
 *------------------------------------------------------------------*/
bool lim_process_ft_update_key(tpAniSirGlobal pMac, uint32_t *pMsgBuf)
{
	tAddBssParams *pAddBssParams;
	tSirFTUpdateKeyInfo *pKeyInfo;
	uint32_t val = 0;
	tpPESession psessionEntry;
	uint8_t sessionId;

	/* Sanity Check */
	if (pMac == NULL || pMsgBuf == NULL) {
		return false;
	}

	pKeyInfo = (tSirFTUpdateKeyInfo *) pMsgBuf;

	psessionEntry = pe_find_session_by_bssid(pMac, pKeyInfo->bssid.bytes,
						 &sessionId);
	if (NULL == psessionEntry) {
		pe_err("%s: Unable to find session for the following bssid",
			       __func__);
		lim_print_mac_addr(pMac, pKeyInfo->bssid.bytes, LOGE);
		return false;
	}

	/* Nothing to be done if the session is not in STA mode */
	if (!LIM_IS_STA_ROLE(psessionEntry)) {
		pe_err("psessionEntry is not in STA mode");
		return false;
	}

	if (NULL == psessionEntry->ftPEContext.pAddBssReq) {
		/* AddBss Req is NULL, save the keys to configure them later. */
		tpLimMlmSetKeysReq pMlmSetKeysReq =
			&psessionEntry->ftPEContext.PreAuthKeyInfo.
			extSetStaKeyParam;

		qdf_mem_zero(pMlmSetKeysReq, sizeof(tLimMlmSetKeysReq));
		qdf_copy_macaddr(&pMlmSetKeysReq->peer_macaddr,
				 &pKeyInfo->bssid);
		pMlmSetKeysReq->sessionId = psessionEntry->peSessionId;
		pMlmSetKeysReq->smesessionId = psessionEntry->smeSessionId;
		pMlmSetKeysReq->edType = pKeyInfo->keyMaterial.edType;
		pMlmSetKeysReq->numKeys = pKeyInfo->keyMaterial.numKeys;
		qdf_mem_copy((uint8_t *) &pMlmSetKeysReq->key,
			     (uint8_t *) &pKeyInfo->keyMaterial.key,
			     sizeof(tSirKeys));

		psessionEntry->ftPEContext.PreAuthKeyInfo.
		extSetStaKeyParamValid = true;

		if (psessionEntry->ftPEContext.pAddStaReq == NULL) {
			pe_err("pAddStaReq is NULL");
			lim_send_set_sta_key_req(pMac, pMlmSetKeysReq, 0, 0,
						 psessionEntry, false);
			psessionEntry->ftPEContext.PreAuthKeyInfo.
			extSetStaKeyParamValid = false;
		}
	} else {
		pAddBssParams = psessionEntry->ftPEContext.pAddBssReq;

		/* Store the key information in the ADD BSS parameters */
		pAddBssParams->extSetStaKeyParamValid = 1;
		pAddBssParams->extSetStaKeyParam.encType =
			pKeyInfo->keyMaterial.edType;
		qdf_mem_copy((uint8_t *) &pAddBssParams->extSetStaKeyParam.key,
			     (uint8_t *) &pKeyInfo->keyMaterial.key,
			     sizeof(tSirKeys));
		if (eSIR_SUCCESS !=
		    wlan_cfg_get_int(pMac, WNI_CFG_SINGLE_TID_RC, &val)) {
			pe_warn("Unable to read WNI_CFG_SINGLE_TID_RC");
		}

		pAddBssParams->extSetStaKeyParam.singleTidRc = val;
		pe_debug("Key valid: %d keyLength: %d",
			pAddBssParams->extSetStaKeyParamValid,
			pAddBssParams->extSetStaKeyParam.key[0].keyLength);

		pAddBssParams->extSetStaKeyParam.staIdx = 0;

		pe_debug("BSSID: " MAC_ADDRESS_STR,
			       MAC_ADDR_ARRAY(pKeyInfo->bssid.bytes));

		qdf_copy_macaddr(&pAddBssParams->extSetStaKeyParam.peer_macaddr,
				 &pKeyInfo->bssid);

		pAddBssParams->extSetStaKeyParam.sendRsp = false;
	}
	return true;
}

static void
lim_ft_send_aggr_qos_rsp(tpAniSirGlobal pMac, uint8_t rspReqd,
			 tpAggrAddTsParams aggrQosRsp, uint8_t smesessionId)
=======
static void
lim_ft_send_aggr_qos_rsp(struct mac_context *mac, uint8_t rspReqd,
			 struct aggr_add_ts_param *aggrQosRsp,
			 uint8_t smesessionId)
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
{
	tpSirAggrQosRsp rsp;
	int i = 0;

	if (!rspReqd) {
		return;
	}
	rsp = qdf_mem_malloc(sizeof(tSirAggrQosRsp));
<<<<<<< HEAD
	if (NULL == rsp) {
		pe_err("AllocateMemory failed for tSirAggrQosRsp");
		return;
	}
=======
	if (!rsp)
		return;

>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	rsp->messageType = eWNI_SME_FT_AGGR_QOS_RSP;
	rsp->sessionId = smesessionId;
	rsp->length = sizeof(*rsp);
	rsp->aggrInfo.tspecIdx = aggrQosRsp->tspecIdx;
<<<<<<< HEAD
	for (i = 0; i < SIR_QOS_NUM_AC_MAX; i++) {
=======
	for (i = 0; i < QCA_WLAN_AC_ALL; i++) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		if ((1 << i) & aggrQosRsp->tspecIdx) {
			if (QDF_IS_STATUS_SUCCESS(aggrQosRsp->status[i]))
				rsp->aggrInfo.aggrRsp[i].status =
					eSIR_MAC_SUCCESS_STATUS;
			else
				rsp->aggrInfo.aggrRsp[i].status =
					eSIR_MAC_UNSPEC_FAILURE_STATUS;
			rsp->aggrInfo.aggrRsp[i].tspec = aggrQosRsp->tspec[i];
		}
	}
<<<<<<< HEAD
	lim_send_sme_aggr_qos_rsp(pMac, rsp, smesessionId);
	return;
}

void lim_process_ft_aggr_qo_s_rsp(tpAniSirGlobal pMac, tpSirMsgQ limMsg)
{
	tpAggrAddTsParams pAggrQosRspMsg = NULL;
	tAddTsParams addTsParam = { 0 };
=======
	lim_send_sme_aggr_qos_rsp(mac, rsp, smesessionId);
	return;
}

void lim_process_ft_aggr_qos_rsp(struct mac_context *mac,
				 struct scheduler_msg *limMsg)
{
	struct aggr_add_ts_param *pAggrQosRspMsg;
	struct add_ts_param addTsParam = { 0 };
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	tpDphHashNode pSta = NULL;
	uint16_t assocId = 0;
	tSirMacAddr peerMacAddr;
	uint8_t rspReqd = 1;
<<<<<<< HEAD
	tpPESession psessionEntry = NULL;
	int i = 0;

	pe_debug(" Received AGGR_QOS_RSP from HAL");
	SET_LIM_PROCESS_DEFD_MESGS(pMac, true);
	pAggrQosRspMsg = (tpAggrAddTsParams) (limMsg->bodyptr);
	if (NULL == pAggrQosRspMsg) {
		pe_err("NULL pAggrQosRspMsg");
		return;
	}
	psessionEntry =
		pe_find_session_by_session_id(pMac, pAggrQosRspMsg->sessionId);
	if (NULL == psessionEntry) {
		pe_err("Cant find session entry for %s", __func__);
		if (pAggrQosRspMsg != NULL) {
=======
	struct pe_session *pe_session = NULL;
	int i = 0;

	pe_debug(" Received AGGR_QOS_RSP from HAL");
	SET_LIM_PROCESS_DEFD_MESGS(mac, true);
	pAggrQosRspMsg = limMsg->bodyptr;
	if (!pAggrQosRspMsg) {
		pe_err("NULL pAggrQosRspMsg");
		return;
	}
	pe_session =
		pe_find_session_by_session_id(mac, pAggrQosRspMsg->sessionId);
	if (!pe_session) {
		pe_err("Cant find session entry for %s", __func__);
		if (pAggrQosRspMsg) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			qdf_mem_free(pAggrQosRspMsg);
		}
		return;
	}
<<<<<<< HEAD
	if (!LIM_IS_STA_ROLE(psessionEntry)) {
		pe_err("psessionEntry is not in STA mode");
		return;
	}
	for (i = 0; i < HAL_QOS_NUM_AC_MAX; i++) {
		if ((((1 << i) & pAggrQosRspMsg->tspecIdx)) &&
		    (pAggrQosRspMsg->status[i] != QDF_STATUS_SUCCESS)) {
			sir_copy_mac_addr(peerMacAddr, psessionEntry->bssId);
			addTsParam.staIdx = pAggrQosRspMsg->staIdx;
			addTsParam.sessionId = pAggrQosRspMsg->sessionId;
			addTsParam.tspec = pAggrQosRspMsg->tspec[i];
			addTsParam.tspecIdx = pAggrQosRspMsg->tspecIdx;
			lim_send_delts_req_action_frame(pMac, peerMacAddr, rspReqd,
							&addTsParam.tspec.tsinfo,
							&addTsParam.tspec,
							psessionEntry);
			pSta =
				dph_lookup_assoc_id(pMac, addTsParam.staIdx, &assocId,
						    &psessionEntry->dph.dphHashTable);
			if (pSta != NULL) {
				lim_admit_control_delete_ts(pMac, assocId,
							    &addTsParam.tspec.
							    tsinfo, NULL,
							    (uint8_t *) &
							    addTsParam.tspecIdx);
			}
		}
	}
	lim_ft_send_aggr_qos_rsp(pMac, rspReqd, pAggrQosRspMsg,
				 psessionEntry->smeSessionId);
	if (pAggrQosRspMsg != NULL) {
=======
	if (!LIM_IS_STA_ROLE(pe_session)) {
		pe_err("pe_session is not in STA mode");
		return;
	}
	for (i = 0; i < QCA_WLAN_AC_ALL; i++) {
		if ((((1 << i) & pAggrQosRspMsg->tspecIdx)) &&
		    (pAggrQosRspMsg->status[i] != QDF_STATUS_SUCCESS)) {
			sir_copy_mac_addr(peerMacAddr, pe_session->bssId);
			addTsParam.pe_session_id = pAggrQosRspMsg->sessionId;
			addTsParam.tspec = pAggrQosRspMsg->tspec[i];
			addTsParam.tspec_idx = pAggrQosRspMsg->tspecIdx;
			lim_send_delts_req_action_frame(mac, peerMacAddr,
							rspReqd,
							&addTsParam.tspec.tsinfo,
							&addTsParam.tspec,
							pe_session);
			pSta =
				dph_lookup_hash_entry(mac, peerMacAddr,
						      &assocId,
						      &pe_session->
						      dph.dphHashTable);

			if (pSta) {
				lim_admit_control_delete_ts(mac, assocId,
							    &addTsParam.tspec.
							    tsinfo, NULL,
							    (uint8_t *) &
							    addTsParam.tspec_idx);
			}
		}
	}
	lim_ft_send_aggr_qos_rsp(mac, rspReqd, pAggrQosRspMsg,
				 pe_session->smeSessionId);
	if (pAggrQosRspMsg) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		qdf_mem_free(pAggrQosRspMsg);
	}
	return;
}

<<<<<<< HEAD
tSirRetStatus lim_process_ft_aggr_qos_req(tpAniSirGlobal pMac, uint32_t *pMsgBuf)
{
	tSirMsgQ msg;
	tSirAggrQosReq *aggrQosReq = (tSirAggrQosReq *) pMsgBuf;
	tpAggrAddTsParams pAggrAddTsParam;
	tpPESession psessionEntry = NULL;
=======
QDF_STATUS lim_process_ft_aggr_qos_req(struct mac_context *mac,
				       uint32_t *msg_buf)
{
	struct scheduler_msg msg = {0};
	tSirAggrQosReq *aggrQosReq = (tSirAggrQosReq *) msg_buf;
	struct aggr_add_ts_param *pAggrAddTsParam;
	struct pe_session *pe_session = NULL;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
	tpLimTspecInfo tspecInfo;
	uint8_t ac;
	tpDphHashNode pSta;
	uint16_t aid;
	uint8_t sessionId;
	int i;

<<<<<<< HEAD
	pAggrAddTsParam = qdf_mem_malloc(sizeof(tAggrAddTsParams));
	if (NULL == pAggrAddTsParam) {
		pe_err("AllocateMemory() failed");
		return eSIR_MEM_ALLOC_FAILED;
	}

	psessionEntry = pe_find_session_by_bssid(pMac, aggrQosReq->bssid.bytes,
						 &sessionId);

	if (psessionEntry == NULL) {
		pe_err("psession Entry Null for sessionId: %d",
			       aggrQosReq->sessionId);
		qdf_mem_free(pAggrAddTsParam);
		return eSIR_FAILURE;
	}

	/* Nothing to be done if the session is not in STA mode */
	if (!LIM_IS_STA_ROLE(psessionEntry)) {
		pe_err("psessionEntry is not in STA mode");
		qdf_mem_free(pAggrAddTsParam);
		return eSIR_FAILURE;
	}

	pSta = dph_lookup_hash_entry(pMac, aggrQosReq->bssid.bytes, &aid,
				     &psessionEntry->dph.dphHashTable);
	if (pSta == NULL) {
		pe_err("Station context not found - ignoring AddTsRsp");
		qdf_mem_free(pAggrAddTsParam);
		return eSIR_FAILURE;
	}

	pAggrAddTsParam->staIdx = psessionEntry->staId;
	/* Fill in the sessionId specific to PE */
	pAggrAddTsParam->sessionId = sessionId;
	pAggrAddTsParam->tspecIdx = aggrQosReq->aggrInfo.tspecIdx;
	pAggrAddTsParam->vdev_id = psessionEntry->smeSessionId;

	for (i = 0; i < HAL_QOS_NUM_AC_MAX; i++) {
		if (aggrQosReq->aggrInfo.tspecIdx & (1 << i)) {
			tSirMacTspecIE *pTspec =
=======
	pAggrAddTsParam = qdf_mem_malloc(sizeof(*pAggrAddTsParam));
	if (!pAggrAddTsParam)
		return QDF_STATUS_E_NOMEM;

	pe_session = pe_find_session_by_bssid(mac, aggrQosReq->bssid.bytes,
					      &sessionId);

	if (!pe_session) {
		pe_err("psession Entry Null for sessionId: %d",
			       aggrQosReq->sessionId);
		qdf_mem_free(pAggrAddTsParam);
		return QDF_STATUS_E_FAILURE;
	}

	/* Nothing to be done if the session is not in STA mode */
	if (!LIM_IS_STA_ROLE(pe_session)) {
		pe_err("pe_session is not in STA mode");
		qdf_mem_free(pAggrAddTsParam);
		return QDF_STATUS_E_FAILURE;
	}

	pSta = dph_lookup_hash_entry(mac, aggrQosReq->bssid.bytes, &aid,
				     &pe_session->dph.dphHashTable);
	if (!pSta) {
		pe_err("Station context not found - ignoring AddTsRsp");
		qdf_mem_free(pAggrAddTsParam);
		return QDF_STATUS_E_FAILURE;
	}

	/* Fill in the sessionId specific to PE */
	pAggrAddTsParam->sessionId = sessionId;
	pAggrAddTsParam->tspecIdx = aggrQosReq->aggrInfo.tspecIdx;
	pAggrAddTsParam->vdev_id = pe_session->smeSessionId;

	for (i = 0; i < QCA_WLAN_AC_ALL; i++) {
		if (aggrQosReq->aggrInfo.tspecIdx & (1 << i)) {
			struct mac_tspec_ie *pTspec =
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				&aggrQosReq->aggrInfo.aggrAddTsInfo[i].tspec;
			/* Since AddTS response was successful, check for the PSB flag
			 * and directional flag inside the TS Info field.
			 * An AC is trigger enabled AC if the PSB subfield is set to 1
			 * in the uplink direction.
			 * An AC is delivery enabled AC if the PSB subfield is set to 1
			 * in the downlink direction.
			 * An AC is trigger and delivery enabled AC if the PSB subfield
			 * is set to 1 in the bi-direction field.
			 */
			if (pTspec->tsinfo.traffic.psb == 1) {
<<<<<<< HEAD
				lim_set_tspec_uapsd_mask_per_session(pMac,
								     psessionEntry,
=======
				lim_set_tspec_uapsd_mask_per_session(mac,
								     pe_session,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
								     &pTspec->
								     tsinfo,
								     SET_UAPSD_MASK);
			} else {
<<<<<<< HEAD
				lim_set_tspec_uapsd_mask_per_session(pMac,
								     psessionEntry,
=======
				lim_set_tspec_uapsd_mask_per_session(mac,
								     pe_session,
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
								     &pTspec->
								     tsinfo,
								     CLEAR_UAPSD_MASK);
			}
			/*
			 * ADDTS success, so AC is now admitted.
			 * We shall now use the default
			 * EDCA parameters as advertised by AP and
			 * send the updated EDCA params
			 * to HAL.
			 */
			ac = upToAc(pTspec->tsinfo.traffic.userPrio);
			if (pTspec->tsinfo.traffic.direction ==
			    SIR_MAC_DIRECTION_UPLINK) {
<<<<<<< HEAD
				psessionEntry->
=======
				pe_session->
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				gAcAdmitMask
				[SIR_MAC_DIRECTION_UPLINK] |=
					(1 << ac);
			} else if (pTspec->tsinfo.traffic.direction ==
				   SIR_MAC_DIRECTION_DNLINK) {
<<<<<<< HEAD
				psessionEntry->
=======
				pe_session->
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
				gAcAdmitMask
				[SIR_MAC_DIRECTION_DNLINK] |=
					(1 << ac);
			} else if (pTspec->tsinfo.traffic.direction ==
				   SIR_MAC_DIRECTION_BIDIR) {
<<<<<<< HEAD
				psessionEntry->
				gAcAdmitMask
				[SIR_MAC_DIRECTION_UPLINK] |=
					(1 << ac);
				psessionEntry->
=======
				pe_session->
				gAcAdmitMask
				[SIR_MAC_DIRECTION_UPLINK] |=
					(1 << ac);
				pe_session->
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
					gAcAdmitMask
					[SIR_MAC_DIRECTION_DNLINK] |=
					(1 << ac);
			}
<<<<<<< HEAD
			lim_set_active_edca_params(pMac,
						   psessionEntry->gLimEdcaParams,
						   psessionEntry);

				lim_send_edca_params(pMac,
					     psessionEntry->gLimEdcaParamsActive,
					     pSta->bssId);

			if (eSIR_SUCCESS !=
			    lim_tspec_add(pMac, pSta->staAddr, pSta->assocId,
					  pTspec, 0, &tspecInfo)) {
				pe_err("Adding entry in lim Tspec Table failed");
				pMac->lim.gLimAddtsSent = false;
				qdf_mem_free(pAggrAddTsParam);
				return eSIR_FAILURE;
=======
			lim_set_active_edca_params(mac,
						   pe_session->gLimEdcaParams,
						   pe_session);

				lim_send_edca_params(mac,
					     pe_session->gLimEdcaParamsActive,
					     pe_session->vdev_id, false);

			if (QDF_STATUS_SUCCESS !=
			    lim_tspec_add(mac, pSta->staAddr, pSta->assocId,
					  pTspec, 0, &tspecInfo)) {
				pe_err("Adding entry in lim Tspec Table failed");
				mac->lim.gLimAddtsSent = false;
				qdf_mem_free(pAggrAddTsParam);
				return QDF_STATUS_E_FAILURE;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			}

			pAggrAddTsParam->tspec[i] =
				aggrQosReq->aggrInfo.aggrAddTsInfo[i].tspec;
		}
	}

#ifdef WLAN_FEATURE_ROAM_OFFLOAD
<<<<<<< HEAD
	if (!pMac->roam.configParam.isRoamOffloadEnabled ||
	    (pMac->roam.configParam.isRoamOffloadEnabled &&
	     !psessionEntry->is11Rconnection))
=======
	if (!mac->mlme_cfg->lfr.lfr3_roaming_offload ||
	    (mac->mlme_cfg->lfr.lfr3_roaming_offload &&
	     !pe_session->is11Rconnection))
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
#endif
	{
	msg.type = WMA_AGGR_QOS_REQ;
	msg.bodyptr = pAggrAddTsParam;
	msg.bodyval = 0;

	/* We need to defer any incoming messages until we get a
	 * WMA_AGGR_QOS_RSP from HAL.
	 */
<<<<<<< HEAD
	SET_LIM_PROCESS_DEFD_MESGS(pMac, false);
	MTRACE(mac_trace_msg_tx(pMac, psessionEntry->peSessionId, msg.type));

	if (eSIR_SUCCESS != wma_post_ctrl_msg(pMac, &msg)) {
			pe_warn("wma_post_ctrl_msg() failed");
			SET_LIM_PROCESS_DEFD_MESGS(pMac, true);
			qdf_mem_free(pAggrAddTsParam);
			return eSIR_FAILURE;
=======
	SET_LIM_PROCESS_DEFD_MESGS(mac, false);
	MTRACE(mac_trace_msg_tx(mac, pe_session->peSessionId, msg.type));

	if (QDF_STATUS_SUCCESS != wma_post_ctrl_msg(mac, &msg)) {
			pe_warn("wma_post_ctrl_msg() failed");
			SET_LIM_PROCESS_DEFD_MESGS(mac, true);
			qdf_mem_free(pAggrAddTsParam);
			return QDF_STATUS_E_FAILURE;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
		}
	}
#ifdef WLAN_FEATURE_ROAM_OFFLOAD
	else {
		/* Implies it is a LFR3.0 based 11r connection
<<<<<<< HEAD
		 * so donot send add ts request to fimware since it
		 * already has the RIC IEs */

		/* Send the Aggr QoS response to SME */
		lim_ft_send_aggr_qos_rsp(pMac, true, pAggrAddTsParam,
					 psessionEntry->smeSessionId);
		if (pAggrAddTsParam != NULL) {
=======
		 * so donot send add ts request to firmware since it
		 * already has the RIC IEs */

		/* Send the Aggr QoS response to SME */
		lim_ft_send_aggr_qos_rsp(mac, true, pAggrAddTsParam,
					 pe_session->smeSessionId);
		if (pAggrAddTsParam) {
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
			qdf_mem_free(pAggrAddTsParam);
		}
	}
#endif

<<<<<<< HEAD
	return eSIR_SUCCESS;
=======
	return QDF_STATUS_SUCCESS;
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
}

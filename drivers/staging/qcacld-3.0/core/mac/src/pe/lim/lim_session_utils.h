/*
<<<<<<< HEAD
 * Copyright (c) 2012-2015 The Linux Foundation. All rights reserved.
=======
 * Copyright (c) 2012-2015, 2018, 2020 The Linux Foundation. All rights reserved.
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

#if !defined(__LIM_SESSION_UTILS_H)
#define __LIM_SESSION_UTILS_H

<<<<<<< HEAD
uint8_t is_lim_session_off_channel(tpAniSirGlobal pMac, uint8_t sessionId);
uint8_t lim_is_chan_switch_running(tpAniSirGlobal pMac);
uint8_t lim_is_in_mcc(tpAniSirGlobal pMac);
uint8_t pe_get_current_stas_count(tpAniSirGlobal pMac);
=======
uint8_t lim_is_chan_switch_running(struct mac_context *mac);
uint8_t lim_is_in_mcc(struct mac_context *mac);
uint8_t pe_get_current_stas_count(struct mac_context *mac);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

#endif /* #if !defined( __LIM_SESSION_UTILS_H ) */

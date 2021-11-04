/*
<<<<<<< HEAD
 * Copyright (c) 2011-2014 The Linux Foundation. All rights reserved.
=======
 * Copyright (c) 2011-2014, 2017-2018 The Linux Foundation. All rights reserved.
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

/*
 *
 * sys_startup.h: System startup header file.
 * Author:  V. K. Kandarpa
 * Date:    01/29/2002
 *
 * History:-
 * Date     Modified by         Modification Information
 * --------------------------------------------------------------------------
 *
 */

#ifndef __SYSSTARTUP_H
#define __SYSSTARTUP_H

#include "sir_params.h"

/* Defines */

/* Function */

<<<<<<< HEAD
extern void sysMACCleanup(void *);
extern tSirRetStatus sys_bbt_process_message_core(struct sAniSirGlobal *, tpSirMsgQ,
						  uint32_t, uint32_t);
=======
/**
 * sys_bbt_process_message_core() - to process BBT messages
 * @mac_ctx: pointer to mac context
 * @msg: message pointer
 * @type: type of persona
 * @subtype: subtype of persona
 *
 * This routine is to process some bbt messages
 *
 * Return: None
 */
QDF_STATUS sys_bbt_process_message_core(struct mac_context *mac_ctx,
					struct scheduler_msg *msg,
					uint32_t type, uint32_t subtype);
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701

#endif /* __SYSSTARTUP_H */

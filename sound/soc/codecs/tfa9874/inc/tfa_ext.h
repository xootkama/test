/*
<<<<<<< HEAD
 * Copyright (C) 2018 NXP Semiconductors, All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
=======
 * Copyright 2016-2017 NXP Semiconductors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/*
 * tfa_ext.h
 *
 *  Created on: Jun 8, 2016
 *      Author: wim
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 */

#ifndef TFA_SRC_TFA_EXT_H_
#define TFA_SRC_TFA_EXT_H_

#include "tfa_device.h"

/*
 * events
 */
/** Maximum value for enumerator */
#define LVM_MAXENUM (0xffff)
/**
This enum type specifies the different events that may trigger a callback.
*/
enum tfadsp_event_en
{
 TFADSP_CMD_ACK         =  1,   /**< Command handling is completed */
 TFADSP_SOFT_MUTE_READY     =  8,   /**< Muting completed */
 TFADSP_VOLUME_READY        = 16,   /**< Volume change completed */
 TFADSP_DAMAGED_SPEAKER     = 32,   /**< Damaged speaker was detected */
 TFADSP_CALIBRATE_DONE      = 64,   /**< Calibration is completed */
 TFADSP_SPARSESIG_DETECTED  = 128,  /**< Sparse signal detected */
 TFADSP_CMD_READY       = 256,  /**< Ready to receive commands */
 TFADSP_EXT_PWRUP       = 0x8000,/**< DSP API has started, powered up */
 TFADSP_EXT_PWRDOWN         = 0x8001,/**< DSP API stopped, power down */
 TFADSP_EVENT_DUMMY = LVM_MAXENUM
} ;

typedef int (*tfa_event_handler_t)(struct tfa_device *tfa, enum tfadsp_event_en tfadsp_event);
typedef int (*dsp_send_message_t)(struct tfa_device *tfa, int length, const char *buf);
typedef int (*dsp_read_message_t)(struct tfa_device *tfa, int length, char *buf);
typedef int (*dsp_write_reg_t)(struct tfa_device *tfa, unsigned char subaddress, unsigned short value);

int tfa_ext_register(dsp_write_reg_t tfa_write_reg, dsp_send_message_t tfa_send_message, dsp_read_message_t tfa_read_message, tfa_event_handler_t *tfa_event_handler);

#endif /* TFA_SRC_TFA_EXT_H_ */

/*
<<<<<<< HEAD
 * Copyright (C) 2018 NXP Semiconductors, All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
=======
 * Copyright 2014-2017 NXP Semiconductors
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
>>>>>>> cb9015c4d77900578f941ba9cf87a3d4f575b701
 */

/*
	Linux kernel specific definitions used by code shared with
	Linux/Windows user space.
*/

#ifndef __CONFIG_LINUX_KERNEL_INC__
#define __CONFIG_LINUX_KERNEL_INC__

#include <linux/ctype.h>
#include <linux/delay.h>
#include <linux/slab.h>
#include <linux/crc32.h>
#include <linux/ftrace.h>

#define _ASSERT(e)
#define PRINT_ASSERT(e)if ((e)) printk(KERN_ERR "PrintAssert:%s (%s:%d) error code:%d\n",__FUNCTION__,__FILE__,__LINE__, e)

#if defined(CONFIG_TRACING) && defined(DEBUG)
	#define tfa98xx_trace_printk(...) trace_printk(__VA_ARGS__)
#else
	#define tfa98xx_trace_printk(...)
#endif

#endif /* __CONFIG_LINUX_KERNEL_INC__ */


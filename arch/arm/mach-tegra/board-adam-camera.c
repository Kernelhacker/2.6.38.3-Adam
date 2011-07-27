/*
 * arch/arm/mach-tegra/board-adam-camera.c
 *
 * Copyright (C) 2011 Eduardo Jos� Tagle <ejtagle@tutopia.com>
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

#include <linux/console.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/clk.h>
#include <linux/mtd/mtd.h>
#include <linux/mtd/partitions.h>
#include <linux/platform_data/tegra_usb.h>
#include <linux/gpio.h>
#include <linux/delay.h>
#include <linux/reboot.h>
#include <linux/memblock.h>

#include <asm/mach-types.h>
#include <asm/mach/arch.h>
#include <asm/mach/time.h>
#include <asm/setup.h>

#include <mach/io.h>
#include <mach/iomap.h>
#include <mach/irqs.h>
#include <mach/nand.h>
#include <mach/iomap.h>
#include <linux/i2c.h>

#include "board.h"
#include "board-adam.h"
#include "clock.h"
#include "gpio-names.h"
#include "devices.h"

/*static struct platform_device adam_camera_pm_device = {
	.name		= "adam-pm-camera",
	.id			= -1,
};


static struct platform_device *adam_camera_pm_devices[] __initdata = {
	&adam_camera_pm_device,
};*/

static struct i2c_board_info __initdata adam_i2c_bus0_sensor_info[] = {
         {
                I2C_BOARD_INFO("ov5650", 0x6c),
         },
};

int __init adam_camera_register_devices(void)
{

	return i2c_register_board_info(0, adam_i2c_bus0_sensor_info,
                ARRAY_SIZE(adam_i2c_bus0_sensor_info));	
//	return platform_add_devices(adam_camera_pm_devices, ARRAY_SIZE(adam_camera_pm_devices));
}

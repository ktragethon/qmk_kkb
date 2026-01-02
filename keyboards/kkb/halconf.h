// Copyright 2025 kkb (@ktragethon)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define _CHIBIOS_HAL_CONF_VER_8_0_

// Enable I2C for RGB matrix driver
#define HAL_USE_I2C TRUE

#include_next <halconf.h>

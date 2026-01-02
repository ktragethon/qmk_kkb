// Copyright 2025 kkb (@ktragethon)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#include_next <mcuconf.h>

#undef STM32_PLLM_VALUE
#define STM32_PLLM_VALUE 2

#undef STM32_PLLN_VALUE
#define STM32_PLLN_VALUE 12

// Enable I2C1 for RGB driver
#undef STM32_I2C_USE_I2C1
#define STM32_I2C_USE_I2C1 TRUE

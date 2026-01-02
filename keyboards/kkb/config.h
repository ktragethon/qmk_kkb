// Copyright 2025 kkb (@ktragethon)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define MATRIX_UNSELECT_DRIVE_HIGH

// Fallback, default brightness. This is what Keychron uses for K7 Pro Iso RGB
#define M_TV 0x18

// RGB Matrix Configuration - Driver specific settings
#ifdef RGB_MATRIX_ENABLE
#    define DRIVER_COUNT 2
#    define SNLED27351_I2C_ADDRESS_1 0b1110111
#    define SNLED27351_I2C_ADDRESS_2 0b1110100
#    define SNLED27351_PHASE_CHANNEL SNLED27351_SCAN_PHASE_9_CHANNEL
#    define SNLED27351_CURRENT_TUNE {M_TV, M_TV, M_TV, M_TV, M_TV, M_TV, M_TV, M_TV, M_TV, M_TV, M_TV, M_TV}
#    define CAPS_LOCK_INDEX 29
#    define LOW_BAT_IND_INDEX 62
#endif


// BT Pin definition
#define USB_BT_MODE_SELECT_PIN A10

// I2C Configuration
#define I2C1_TIMINGR_PRESC 0U
#define I2C1_TIMINGR_SCLDEL 3U
#define I2C1_TIMINGR_SDADEL 0U
#define I2C1_TIMINGR_SCLH 15U
#define I2C1_TIMINGR_SCLL 51U

// Factory test support
#define FN_KEY1 MO(2)
#define FN_KEY2 MO(3)

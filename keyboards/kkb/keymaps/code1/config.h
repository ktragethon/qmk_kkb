// Copyright 2025 kkb (@ktragethon)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// CONFIGURATION VALIDATION
#ifndef RGB_MATRIX_ENABLE
#    error "This keymap requires RGB_MATRIX_ENABLE"
#endif

// ============================= WARNING ======================================
// The default value in Keychron's own repo for the K7 Pro ISO RGB is:
// 0x18. ANSI-version uses 0x38. Unsure of reasons. Use at your own risk

#ifdef M_TV
#    undef M_TV
#    define M_TV 0x38
#endif

#undef SNLED27351_CURRENT_TUNE
#define SNLED27351_CURRENT_TUNE {M_TV, M_TV, M_TV, M_TV, M_TV, M_TV, M_TV, M_TV, M_TV, M_TV, M_TV, M_TV}

// ============================ DISABLE UNNEEDED =============================
// Disable unused RGB Matrix effects (in case they are active in keyboard.json)
#undef ENABLE_RGB_MATRIX_ALPHAS_MODS
#undef ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#undef ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_BREATHING
#undef ENABLE_RGB_MATRIX_BAND_SAT
#undef ENABLE_RGB_MATRIX_BAND_VAL
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#undef ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#undef ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#undef ENABLE_RGB_MATRIX_CYCLE_ALL
#undef ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#undef ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#undef ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#undef ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#undef ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#undef ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#undef ENABLE_RGB_MATRIX_DUAL_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_BEACON
#undef ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#undef ENABLE_RGB_MATRIX_RAINDROPS
#undef ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#undef ENABLE_RGB_MATRIX_HUE_BREATHING
#undef ENABLE_RGB_MATRIX_HUE_PENDULUM
#undef ENABLE_RGB_MATRIX_HUE_WAVE
#undef ENABLE_RGB_MATRIX_PIXEL_RAIN
#undef ENABLE_RGB_MATRIX_PIXEL_FLOW
#undef ENABLE_RGB_MATRIX_PIXEL_FRACTAL

#undef RGB_MATRIX_FRAMEBUFFER_EFFECTS
#undef RGB_MATRIX_KEYPRESSES

#define RGB_MATRIX_DISABLE_SHARED_KEYCODES

// Keep the solid-color
#define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR

// ========================== RGB DELTAS AND LIMITS ===========================
// Define (0-100%) the default fallback startup brightness
#define KKB_BRIGHTNESS_STARTUP_FALLBACK_PERCENT 80

// KEYBOARD LAYOUT CONSTANTS
#define KKB_TOTAL_KEYS 69                                       // Total number of keys on K7 Pro ISO RGB
#define KKB_NUM_ROW_START 1                                     // Number row starts at LED index 1
#define KKB_NUM_ROW_COUNT 10                                    // Numbers 1-0 (10 keys total)
#define KKB_NUM_ROW_END (KKB_NUM_ROW_START + KKB_NUM_ROW_COUNT) // End of number row

// BRIGHTNESS CONFIGURATION
#define KKB_BRIGHT_MIN 10            // Abs minimum brightness (limit)
#define KKB_BRIGHT_MAX 255           // Abs maximum brightness (limit)
#define KKB_BRIGHT_DIFF_CAPS -20     // Diff, Caps lock dimmer than main
#define KKB_BRIGHT_DIFF_FN_ACTIVE 40 // Diff, Active FN keys brighter
#define KKB_BRIGHT_DIFF_FN_OFF -60   // Diff, Inactive FN keys dimmer
#define INDICATOR_STEP_PERCENT 10    // The percentage steps for visualization

// BRIGHTNESS LIMIT AND CLAMP CALCULATIONS
#ifndef CLAMP
#    define CLAMP(x, lower, upper) (((x) > (upper)) ? (upper) : (((x) < (lower)) ? (lower) : (x)))
#endif
#ifndef ABS_COMPILE_TIME
#    define ABS_COMPILE_TIME(x) ((x) < 0 ? -(x) : (x))
#endif

#define KKB_BRIGHT_MIN_MAIN MAX(KKB_BRIGHT_MIN, ABS_COMPILE_TIME(KKB_BRIGHT_DIFF_FN_OFF))
#define KKB_BRIGHT_MAX_MAIN (KKB_BRIGHT_MAX - KKB_BRIGHT_DIFF_FN_ACTIVE)
#define KKB_BRIGHT_STEP 5

#define KKB_BRIGHT_SPAN_5 ((KKB_BRIGHT_MAX_MAIN - KKB_BRIGHT_MIN_MAIN) / 5)
#define KKB_BRIGHT_START_RAW (KKB_BRIGHT_MIN_MAIN + (KKB_BRIGHTNESS_STARTUP_FALLBACK_PERCENT * KKB_BRIGHT_SPAN_5) / 100 * 5)

// BRIGHTNESS FALLBACK DEFAULT START VALUE
#define KKB_BRIGHT_START (((KKB_BRIGHT_START_RAW + 4) / 5) * 5)

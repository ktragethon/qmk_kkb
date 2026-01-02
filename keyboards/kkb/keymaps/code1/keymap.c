// Copyright 2025 kkb (@ktragethon)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#include "keymap_aliases.h"

// LAYER COLORS (HSV values)
static const hsv_t PROGMEM kkb_color_caps         = {HSV_ORANGE};
static const hsv_t PROGMEM kkb_color_win_standard = {HSV_GOLDENROD};
static const hsv_t PROGMEM kkb_color_brghtscale   = {HSV_CYAN};
static const hsv_t PROGMEM kkb_color_win_special  = {HSV_BLUE};
static const hsv_t PROGMEM kkb_color_win_fn       = {HSV_BLUE};
static const hsv_t PROGMEM kkb_color_fn_active    = {HSV_GREEN};
static const hsv_t PROGMEM kkb_color_fn_controls  = {HSV_SPRINGGREEN};
static const hsv_t PROGMEM kkb_color_sys          = {HSV_WHITE};
static const rgb_t         kkb_color_off          = {RGB_OFF};

/**
 * @brief Layer definitions for K7 Pro keyboard
 */
enum kkb_layers {
    __BASE = 0, //< Base Windows layer (DIP switch position)
    __CODE,     //< Custom special layer (different base color)
    _B_FN1,     //< Standard Function layer 1
    _B_FN2,     //< Standard Function layer 2
    _C_FN1,     //< Special Function layer 1
    _C_FN2,     //< Special Function layer 2
    _C_FN3,     //< Special Function layer 3
    _C_FN4,     //< Function layer for special mode
    _C_CF1,     //< System configuration layer
    _C_CF2      //< Bootloader/reset layer
};

// clang-format off
/**
* @brief All layers with dedicated keymaps for each layer
*/
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /**
    * @brief L0: Basic Windows layout. Standard QWERTY layout with Windows key combinations
    */
    [__BASE] = LAYOUT_69_iso(
        KC_ESC,     KC_1,        KC_2,        KC_3,        KC_4,        KC_5,        KC_6,        KC_7,        KC_8,        KC_9,        KC_0,        KC_MINS,     KC_EQL,      KC_BSPC,                     KC_DEL,
        KC_TAB,     KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,        KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        KC_LBRC,     KC_RBRC,                                  KC_HOME,
        KC_CAPS,    KC_A,        KC_S,        KC_D,        KC_F,        KC_G,        KC_H,        KC_J,        KC_K,        KC_L,        KC_SCLN,     KC_QUOT,     KC_NUHS,     KC_ENT,                      KC_PGUP,
        KC_LSFT,    KC_NUBS,     KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,        KC_N,        KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,                  KC_RSFT,     KC_UP,          KC_PGDN,
        KC_LCTL,    KC_LGUI,     KC_LALT,                                            KC_SPC,                                             KC_RALT,     MO(_B_FN1),  MO(_B_FN2),  KC_LEFT,     KC_DOWN,        KC_RGHT),

    /**
    * @brief L1: Coding Windows layout. QWERTY layout with Windows key combinations and special function layers
    */
    [__CODE] = LAYOUT_69_iso(
        KC_ESC,     KC_1,        KC_2,        KC_3,        KC_4,        KC_5,        KC_6,        KC_7,        KC_8,        KC_9,        KC_0,        KC_MINS,     KC_EQL,      KC_BSPC,                     KC_DEL,
        KC_TAB,     KC_Q,        KC_W,        KC_E,        KC_R,        KC_T,        KC_Y,        KC_U,        KC_I,        KC_O,        KC_P,        KC_LBRC,     KC_RBRC,                                  KC_NO,
        MO(_C_FN3), KC_A,        KC_S,        KC_D,        KC_F,        KC_G,        KC_H,        KC_J,        KC_K,        KC_L,        KC_SCLN,     KC_QUOT,     KC_NUHS,     KC_ENT,                      KC_NO,
        KC_LSFT,    MO(_C_FN4),  KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,        KC_N,        KC_M,        KC_COMM,     KC_DOT,      KC_SLSH,                  KC_RSFT,     KC_UP,          KC_RCTL,
        KC_LCTL,    KC_LGUI,     KC_LALT,                                            KC_SPC,                                             KC_RALT,     MO(_C_FN1),  MO(_C_FN2),  KC_LEFT,     KC_DOWN,        KC_RGHT),

    /**
    * @brief L2: Standard Windows FN 1. Media controls, RGB controls, and system functions
    */
    [_B_FN1] = LAYOUT_69_iso(
        KC_GRV,     KC_BRID,     KC_BRIU,     KC_TASK,     KC_FILE,     RM_VALD,     RM_VALU,     KC_MPRV,     KC_MPLY,     KC_MNXT,     KC_MUTE,     KC_VOLD,     KC_VOLU,     KC_TRNS,                     KC_TRNS,
        KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                                  KC_TRNS,
        RM_TOGG,    RM_NEXT,     RM_VALU,     RM_HUEU,     RM_SATU,     RM_SPDU,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                     KC_TRNS,
        KC_TRNS,    KC_TRNS,     RM_PREV,     RM_VALD,     RM_HUED,     RM_SATD,     RM_SPDD,     NK_TOGG,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                  KC_TRNS,     KC_TRNS,        KC_TRNS,
        KC_TRNS,    KC_TRNS,     KC_TRNS,                                            KC_TRNS,                                            KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,        KC_TRNS),

    /**
    * @brief L3: Standard Windows FN 2. Function keys F1-F12
    */
    [_B_FN2] = LAYOUT_69_iso(
        KC_TILD,    KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5,       KC_F6,       KC_F7,       KC_F8,       KC_F9,       KC_F10,      KC_F11,      KC_F12,      KC_TRNS,                     KC_TRNS,
        KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                                  KC_TRNS,
        KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                     KC_TRNS,
        KC_TRNS,    KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,                  KC_TRNS,     KC_TRNS,        KC_TRNS,
        KC_TRNS,    KC_TRNS,     KC_TRNS,                                            KC_TRNS,                                            KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,        KC_TRNS),

    /**
    * @brief L4: Coding FN 1 [FN1]. Has coding characters [] () {} <> & | =
    */
    [_C_FN1] = LAYOUT_69_iso(
        KC_NO,      UC_LBRC,     UC_RBRC,     KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                       KC_NO,
        KC_NO,      UC_LPRN,     UC_RPRN,     UC_AMPR,     UC_PIPE,     KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                                    KC_NO,
        KC_NO,      UC_LCBR,     UC_RCBR,     UC_EQUA,     KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                       KC_NO,
        KC_NO,      KC_NO,       UC_LABK,     UC_RABK,     KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                    KC_NO,       KC_NO,          KC_NO,
        KC_NO,      KC_NO,       KC_NO,                                              KC_NO,                                              KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,          KC_NO),

    /**
    * @brief L5: Coding FN 2 [FN2]. Has coding characters ! ? + - * / " ' ; :
    */
    [_C_FN2] = LAYOUT_69_iso(
        KC_NO,      UC_EXCL,     UC_QUST,     KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                       KC_NO,
        KC_NO,      UC_VADD,     UC_VSUB,     UC_VMUL,     UC_VDIV,     KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                                    KC_NO,
        KC_NO,      UC_QOTE,     UC_SQOT,     UC_SCOL,     UC_COLO,     KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                       KC_NO,
        KC_NO,      KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                    KC_NO,       KC_NO,          KC_NO,
        KC_NO,      KC_NO,       KC_NO,                                              KC_NO,                                              KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,          KC_NO),

    /**
    * @brief L6: Coding FN 3 [CAPS]. Build, flash, F1-F12
    */
    [_C_FN3] = LAYOUT_69_iso(
        KC_NO,      KC_F1,       KC_F2,       KC_F3,       KC_F4,       KC_F5,       KC_F6,       KC_F7,       KC_F8,       KC_F9,       KC_F10,      KC_F11,      KC_F12,      KC_NO,                       KC_NO,
        KC_NO,      KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                                    KC_NO,
        KC_NO,      KC_NO,       KC_NO,       KC_NO,       UC_FLS,      KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                       KC_NO,
        KC_TRNS,    KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       UC_BLD,      KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                    KC_TRNS,     KC_NO,          KC_NO,
        KC_TRNS,    KC_NO,       KC_TRNS,                                            KC_NO,                                              KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,          KC_NO),

    /**
    * @brief L6: Coding FN 4 [NUBS]. Navigation (System access layer with TO(LSCFG) on Escape)
    */
    [_C_FN4] = LAYOUT_69_iso(
        TO(_C_CF1), KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,        KC_NO,                       KC_NO,
        KC_NO,      KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                                     UC_ED1,
        KC_NO,      KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,        UC_PIN,                      UC_ED2,
        KC_TRNS,    KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                     KC_TRNS,     KC_PGUP,        KC_NO,
        KC_TRNS,    KC_NO,       KC_TRNS,                                            KC_NO,                                              KC_NO,       KC_NO,       KC_NO,        KC_HOME,     KC_PGDN,        KC_END),

    /**
    * @brief L8: System Config. SysConfig, brightness controls and indicator (1-0). Bootloader access
    */
    [_C_CF1] = LAYOUT_69_iso(
        KC_NO,      KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                       KC_NO,
        KC_NO,      KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                                    TG(_C_CF1),
        KC_CAPS,    KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                       KC_NO,
        KC_NO,      KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                    KC_NO,       RM_VALU,        KC_NO,
        KC_NO,      KC_NO,       KC_NO,                                              MO(_C_CF2),                                         KC_NO,       KC_NO,       KC_NO,       KC_NO,       RM_VALD,        KC_NO),

    /**
    * @brief L9: Bootloader/reset. Bootloader access via QK_BOOT on Enter key.
    */
    [_C_CF2] = LAYOUT_69_iso(
        KC_NO,      KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                       KC_NO,
        KC_NO,      KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                                    KC_NO,
        KC_NO,      KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       QK_BOOT,                     KC_NO,
        KC_NO,      KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,                    KC_NO,       KC_NO,          KC_NO,
        KC_NO,      KC_NO,       KC_NO,                                              KC_NO,                                              KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,          KC_NO),
};

// clang-format on

/**
 * Current main brightness level
 */
static uint8_t g_kkb_brightness = KKB_BRIGHT_START;

/**
 * @brief Create RGB color with brightness
 *
 * @param hsv_progmem Pointer to HSV color in PROGMEM
 * @param brightness Final brightness level (0-255)
 * @return rgb_t RGB color struct
 */
static inline rgb_t kkb_create_color_progmem(const hsv_t *hsv_progmem, uint8_t brightness) {
    if (brightness == 0) {
        const rgb_t off = {RGB_OFF};
        return off;
    }

    hsv_t hsv_color = {pgm_read_byte(&hsv_progmem->h), pgm_read_byte(&hsv_progmem->s), pgm_read_byte(&hsv_progmem->v)};

    const uint8_t clamped_brightness = MIN(KKB_BRIGHT_MAX, MAX(KKB_BRIGHT_MIN, brightness));
    const hsv_t   hsv                = {hsv_color.h, hsv_color.s, clamped_brightness};
    return hsv_to_rgb(hsv);
}

/**
 * @brief Calculate brightness with offset from main brightness
 *
 * @param brightness_offset Offset to apply to main brightness
 * @return uint8_t Calculated brightness value
 */
static inline uint8_t kkb_get_brightness(int8_t brightness_offset) {
    return g_kkb_brightness + brightness_offset;
}

/**
 * @brief Set colors based on active keys in current layer, and parameters
 *
 * @param led_min Minimum LED index to process
 * @param led_max Maximum LED index to process
 * @param layer Current layer to analyze
 * @param inactive_Off If there should be no dimming (only off) for inactive keys
 */
static void kkb_set_layer_key_colors(uint8_t led_min, uint8_t led_max, uint8_t layer, bool inactive_Off) {
    uint8_t bright_active   = kkb_get_brightness(KKB_BRIGHT_DIFF_FN_ACTIVE);
    uint8_t bright_inactive = kkb_get_brightness(KKB_BRIGHT_DIFF_FN_OFF);
    uint8_t bright_caps_dim = kkb_get_brightness(KKB_BRIGHT_DIFF_FN_OFF);

    rgb_t color_active   = kkb_create_color_progmem(&kkb_color_fn_active, bright_active);
    rgb_t color_caps_dim = inactive_Off ? kkb_color_off : kkb_create_color_progmem(&kkb_color_caps, bright_caps_dim);
    rgb_t color_controls = kkb_create_color_progmem(&kkb_color_fn_controls, bright_active);
    rgb_t color_inactive = inactive_Off ? kkb_color_off : kkb_create_color_progmem(&kkb_color_win_fn, bright_inactive);

    // Process each key position
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];

            if (index >= led_min && index < led_max && index != NO_LED) {
                uint16_t keycode = keymap_key_to_keycode(layer, (keypos_t){col, row});

                if (keycode > KC_TRNS) {
                    // Active key in this layer - highlight it
                    rgb_matrix_set_color(index, color_active.r, color_active.g, color_active.b);
                } else if (keycode == KC_TRNS) {
                    // Transparent key in this layer - highlight it
                    rgb_matrix_set_color(index, color_controls.r, color_controls.g, color_controls.b);
                } else if (keycode == KC_NO) {
                    // Inactive key - dim it or turn off (depending on 'off' param), select color based on CAPS
                    if (!host_keyboard_led_state().caps_lock) {
                        rgb_matrix_set_color(index, color_inactive.r, color_inactive.g, color_inactive.b);
                    } else {
                        rgb_matrix_set_color(index, color_caps_dim.r, color_caps_dim.g, color_caps_dim.b);
                    }
                }
            }
        }
    }
}

/**
 * @brief Update main brightness level with bounds checking, then save to EEPROM
 *
 * @param adjustment Brightness adjustment value (positive or negative)
 * @return true if brightness was updated, false if out of bounds
 */
static bool kkb_update_brightness(int8_t adjustment) {
    // Calculate new brightness with clamping to main range
    int16_t new_brightness = (int16_t)g_kkb_brightness + adjustment;
    new_brightness         = CLAMP(new_brightness, KKB_BRIGHT_MIN_MAIN, KKB_BRIGHT_MAX_MAIN);

    // Only update if brightness actually changed
    if (new_brightness != g_kkb_brightness) {
        g_kkb_brightness = (uint8_t)new_brightness;
        uint32_t to_save = g_kkb_brightness;
        eeconfig_update_user(to_save);
        return true;
    }
    return false;
}

/**
 * @brief Convert brightness to percentage (0-100)
 */
static uint8_t kkb_brightness_to_percent(void) {
    if (KKB_BRIGHT_MAX_MAIN <= KKB_BRIGHT_MIN_MAIN) return 0;

    // Calculate percentage from min to max
    uint16_t range    = KKB_BRIGHT_MAX_MAIN - KKB_BRIGHT_MIN_MAIN;
    uint16_t position = g_kkb_brightness - KKB_BRIGHT_MIN_MAIN;

    // Avoid division by zero
    if (range == 0) return 100;

    return (uint8_t)((position * 100) / range);
}

/**
 * @brief Display brightness level indicator on number keys (1-0)
 *
 * @param led_min Minimum LED index to process
 * @param led_max Maximum LED index to process
 */
static void kkb_show_brightness_indicator(uint8_t led_min, uint8_t led_max) {
    // Get percentage (0-100)
    uint8_t brightness_percent = kkb_brightness_to_percent();

    // Calculate active indicators (10% per indicator)
    uint8_t active_indicators = brightness_percent / INDICATOR_STEP_PERCENT;

    // Get indicator color at current brightness level
    uint8_t brightness      = kkb_get_brightness(KKB_BRIGHT_DIFF_FN_ACTIVE);
    rgb_t   indicator_color = kkb_create_color_progmem(&kkb_color_brghtscale, brightness);

    // Light up number keys based on brightness level
    for (uint8_t i = 0; i < KKB_NUM_ROW_COUNT; i++) {
        if (active_indicators > i) {
            const uint8_t led_index = i + KKB_NUM_ROW_START;
            if (led_index >= led_min && led_index < led_max) {
                rgb_matrix_set_color(led_index, indicator_color.r, indicator_color.g, indicator_color.b);
            }
        }
    }
}

/**
 * @brief Set all LEDs in range to a specific color
 *
 * @param led_min Minimum LED index
 * @param led_max Maximum LED index
 * @param color RGB color to apply
 */
static inline void kkb_set_all_leds(uint8_t led_min, uint8_t led_max, rgb_t color) {
    bool  caps_active = host_keyboard_led_state().caps_lock;
    rgb_t caps_color  = caps_active ? kkb_create_color_progmem(&kkb_color_caps, kkb_get_brightness(KKB_BRIGHT_DIFF_CAPS)) : color;

    for (uint8_t i = led_min; i < led_max; i++) {
        if (caps_active && (g_led_config.flags[i] & LED_FLAG_KEYLIGHT)) {
            rgb_matrix_set_color(i, caps_color.r, caps_color.g, caps_color.b);
        } else {
            rgb_matrix_set_color(i, color.r, color.g, color.b);
        }
    }
}

/**
 * @brief Handles any base-layer (simply set one color and brightness to all LEDs)
 *
 * @param led_min Minimum LED index
 * @param led_max Maximum LED index
 * @param base_color Pointer to HSV base-color in PROGMEM
 */
static void handle_base_layer(uint8_t led_min, uint8_t led_max, const hsv_t *base_color) {
    uint8_t brightness     = kkb_get_brightness(0);
    rgb_t   base_color_rgb = kkb_create_color_progmem(base_color, brightness);
    kkb_set_all_leds(led_min, led_max, base_color_rgb);
}

/**
 * @brief Handle 'System-Config' Layer, which has a unique RGB handling compared to
 * other layers and base-layers
 *
 * @param led_min Minimum LED index
 * @param led_max Maximum LED index
 * @param layer the layer (to get keycodes from)
 */
static void handle_system_config_layer(uint8_t led_min, uint8_t led_max, uint8_t layer) {
    // Set normal layer colors first
    kkb_set_layer_key_colors(led_min, led_max, layer, true);
    kkb_show_brightness_indicator(led_min, led_max);

    rgb_t sys_max    = kkb_create_color_progmem(&kkb_color_sys, KKB_BRIGHT_MAX);
    rgb_t caps_color = kkb_create_color_progmem(&kkb_color_caps, KKB_BRIGHT_MAX);

    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];
            if (index >= led_min && index < led_max && index != NO_LED) {
                uint16_t keycode = keymap_key_to_keycode(layer, (keypos_t){col, row});

                // Check if this is the spacebar (MO(_C_CF2))
                if (keycode == MO(_C_CF2)) {
                    // Use system color at max brightness
                    rgb_matrix_set_color(index, sys_max.r, sys_max.g, sys_max.b);
                } else if (host_keyboard_led_state().caps_lock && keycode == KC_CAPS) {
                    // Use system color at max brightness
                    rgb_matrix_set_color(index, caps_color.r, caps_color.g, caps_color.b);
                }
            }
        }
    }
}

/**
 * @brief Handle 'Bootloader' Layer, which has a unique RGB handling compared to
 * other layers and base-layers
 *
 * @param led_min Minimum LED index
 * @param led_max Maximum LED index
 * @param layer the layer (to get keycodes from)
 */
static void handle_bootloader_layer(uint8_t led_min, uint8_t led_max, uint8_t layer) {
    // Set normal layer colors first
    kkb_set_layer_key_colors(led_min, led_max, layer, true);

    // Get system color at maximum brightness
    rgb_t sys_max = kkb_create_color_progmem(&kkb_color_sys, KKB_BRIGHT_MAX);

    // Highlight only active keys in at maximum brightness
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
        for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
            uint8_t index = g_led_config.matrix_co[row][col];

            if (index >= led_min && index < led_max && index != NO_LED) {
                uint16_t keycode = keymap_key_to_keycode(layer, (keypos_t){col, row});

                if (keycode > KC_TRNS) {
                    // Active key - use system color at max brightness
                    rgb_matrix_set_color(index, sys_max.r, sys_max.g, sys_max.b);
                }
            }
        }
    }
}

// ######################################################
// #####                                            #####
// #####           QMK OVERRIDES BELOW              #####
// #####    Called from QMK, to be handled here     #####
// #####                                            #####
// ######################################################

/**
 * @brief Main RGB matrix indicator function
 *
 * Sets LED colors based on current layer and keyboard state.
 *
 * @param led_min Minimum LED index to process
 * @param led_max Maximum LED index to process
 * @return false to indicate we handled all LED processing
 */
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    uint8_t current_layer = get_highest_layer(layer_state | default_layer_state);

    switch (current_layer) {
        case __CODE:
            handle_base_layer(led_min, led_max, &kkb_color_win_special);
            break;

        case __BASE:
            handle_base_layer(led_min, led_max, &kkb_color_win_standard);
            break;

        case _C_FN4:
        case _C_FN3:
        case _C_FN2:
        case _C_FN1:
        case _B_FN2:
        case _B_FN1:
            kkb_set_layer_key_colors(led_min, led_max, current_layer, false);
            break;

        case _C_CF2:
            handle_bootloader_layer(led_min, led_max, current_layer);
            break;

        case _C_CF1:
            handle_system_config_layer(led_min, led_max, current_layer);
            break;

        default:
            handle_base_layer(led_min, led_max, &kkb_color_win_standard);
            break;
    }

    return false;
}

/**
 * @brief Post-init functions
 */
void keyboard_post_init_user(void) {
    // read last value
    uint32_t raw    = eeconfig_read_user(); // 4 bytes
    uint8_t  stored = (uint8_t)(raw & 0xFF);
    if (stored < KKB_BRIGHT_MIN || stored > KKB_BRIGHT_MAX) stored = KKB_BRIGHT_START; // corrupted or first boot
    g_kkb_brightness = stored;
}

/**
 * @brief Helper to avoid holding keys that trigger EEPROM writes
 */
static struct {
    bool valu_held;
    bool vald_held;
} brightness_state = {false, false};

/**
 * @brief Process custom keycodes and brightness controls
 *
 * @param keycode The keycode that was pressed/released
 * @param record Key event record
 * @return true to continue QMK processing, false to stop
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (get_highest_layer(layer_state | default_layer_state) >= __CODE) {
        switch (keycode) {
            case RM_VALU:
                if (record->event.pressed && !brightness_state.valu_held) {
                    kkb_update_brightness(KKB_BRIGHT_STEP);
                    brightness_state.valu_held = true;
                } else if (!record->event.pressed) {
                    brightness_state.valu_held = false;
                }
                return false; // Stop QMK processing

            case RM_VALD:
                if (record->event.pressed && !brightness_state.vald_held) {
                    kkb_update_brightness(-KKB_BRIGHT_STEP);
                    brightness_state.vald_held = true;
                } else if (!record->event.pressed) {
                    brightness_state.vald_held = false;
                }
                return false; // Stop QMK processing

            default:
                break; // Continue to QMK processing
        }
    }

    return true; // Let QMK handle the keycode
}

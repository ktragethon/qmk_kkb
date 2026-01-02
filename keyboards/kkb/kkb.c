// Copyright 2025 kkb (@ktragethon)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "kkb.h"

#ifdef RGB_MATRIX_ENABLE
const snled27351_led_t PROGMEM g_snled27351_leds[RGB_MATRIX_LED_COUNT] = {
    /* Converted from CKLED2001 to SNLED27351 format
     *   driver
     *   |  R location
     *   |  |         G location
     *   |  |         |         B location
     *   |  |         |         | */
    {0, CB6_CA1, CB4_CA1, CB5_CA1},    // 0: F_1, D_1, E_1
    {0, CB6_CA2, CB4_CA2, CB5_CA2},    // 1: F_2, D_2, E_2
    {0, CB6_CA3, CB4_CA3, CB5_CA3},    // 2: F_3, D_3, E_3
    {0, CB6_CA4, CB4_CA4, CB5_CA4},    // 3: F_4, D_4, E_4
    {0, CB6_CA5, CB4_CA5, CB5_CA5},    // 4: F_5, D_5, E_5
    {0, CB6_CA6, CB4_CA6, CB5_CA6},    // 5: F_6, D_6, E_6
    {0, CB6_CA7, CB4_CA7, CB5_CA7},    // 6: F_7, D_7, E_7
    {0, CB6_CA8, CB4_CA8, CB5_CA8},    // 7: F_8, D_8, E_8
    {0, CB6_CA9, CB4_CA9, CB5_CA9},    // 8: F_9, D_9, E_9
    {0, CB6_CA10, CB4_CA10, CB5_CA10}, // 9: F_10, D_10, E_10
    {0, CB6_CA11, CB4_CA11, CB5_CA11}, // 10: F_11, D_11, E_11
    {0, CB6_CA12, CB4_CA12, CB5_CA12}, // 11: F_12, D_12, E_12
    {0, CB6_CA13, CB4_CA13, CB5_CA13}, // 12: F_13, D_13, E_13
    {0, CB6_CA14, CB4_CA14, CB5_CA14}, // 13: F_14, D_14, E_14
    {0, CB6_CA16, CB4_CA16, CB5_CA16}, // 14: F_16, D_16, E_16

    {0, CB1_CA1, CB3_CA1, CB2_CA1},    // 15: A_1, C_1, B_1
    {0, CB1_CA2, CB3_CA2, CB2_CA2},    // 16: A_2, C_2, B_2
    {0, CB1_CA3, CB3_CA3, CB2_CA3},    // 17: A_3, C_3, B_3
    {0, CB1_CA4, CB3_CA4, CB2_CA4},    // 18: A_4, C_4, B_4
    {0, CB1_CA5, CB3_CA5, CB2_CA5},    // 19: A_5, C_5, B_5
    {0, CB1_CA6, CB3_CA6, CB2_CA6},    // 20: A_6, C_6, B_6
    {0, CB1_CA7, CB3_CA7, CB2_CA7},    // 21: A_7, C_7, B_7
    {0, CB1_CA8, CB3_CA8, CB2_CA8},    // 22: A_8, C_8, B_8
    {0, CB1_CA9, CB3_CA9, CB2_CA9},    // 23: A_9, C_9, B_9
    {0, CB1_CA10, CB3_CA10, CB2_CA10}, // 24: A_10, C_10, B_10
    {0, CB1_CA11, CB3_CA11, CB2_CA11}, // 25: A_11, C_11, B_11
    {0, CB1_CA12, CB3_CA12, CB2_CA12}, // 26: A_12, C_12, B_12
    {0, CB1_CA13, CB3_CA13, CB2_CA13}, // 27: A_13, C_13, B_13
    {0, CB1_CA16, CB3_CA16, CB2_CA16}, // 28: A_16, C_16, B_16

    {1, CB9_CA1, CB7_CA1, CB8_CA1},    // 29: I_1, G_1, H_1
    {1, CB9_CA2, CB7_CA2, CB8_CA2},    // 30: I_2, G_2, H_2
    {1, CB9_CA3, CB7_CA3, CB8_CA3},    // 31: I_3, G_3, H_3
    {1, CB9_CA4, CB7_CA4, CB8_CA4},    // 32: I_4, G_4, H_4
    {1, CB9_CA5, CB7_CA5, CB8_CA5},    // 33: I_5, G_5, H_5
    {1, CB9_CA6, CB7_CA6, CB8_CA6},    // 34: I_6, G_6, H_6
    {1, CB9_CA7, CB7_CA7, CB8_CA7},    // 35: I_7, G_7, H_7
    {1, CB9_CA8, CB7_CA8, CB8_CA8},    // 36: I_8, G_8, H_8
    {1, CB9_CA9, CB7_CA9, CB8_CA9},    // 37: I_9, G_9, H_9
    {1, CB9_CA10, CB7_CA10, CB8_CA10}, // 38: I_10, G_10, H_10
    {1, CB9_CA11, CB7_CA11, CB8_CA11}, // 39: I_11, G_11, H_11
    {1, CB9_CA12, CB7_CA12, CB8_CA12}, // 40: I_12, G_12, H_12
    {1, CB9_CA14, CB7_CA14, CB8_CA14}, // 41: I_14, G_14, H_14
    {0, CB1_CA14, CB3_CA14, CB2_CA14}, // 42: A_14, C_14, B_14
    {1, CB9_CA16, CB7_CA16, CB8_CA16}, // 43: I_16, G_16, H_16

    {1, CB3_CA1, CB1_CA1, CB2_CA1},    // 44: C_1, A_1, B_1
    {1, CB3_CA2, CB1_CA2, CB2_CA2},    // 45: C_2, A_2, B_2
    {1, CB3_CA3, CB1_CA3, CB2_CA3},    // 46: C_3, A_3, B_3
    {1, CB3_CA4, CB1_CA4, CB2_CA4},    // 47: C_4, A_4, B_4
    {1, CB3_CA5, CB1_CA5, CB2_CA5},    // 48: C_5, A_5, B_5
    {1, CB3_CA6, CB1_CA6, CB2_CA6},    // 49: C_6, A_6, B_6
    {1, CB3_CA7, CB1_CA7, CB2_CA7},    // 50: C_7, A_7, B_7
    {1, CB3_CA8, CB1_CA8, CB2_CA8},    // 51: C_8, A_8, B_8
    {1, CB3_CA9, CB1_CA9, CB2_CA9},    // 52: C_9, A_9, B_9
    {1, CB3_CA10, CB1_CA10, CB2_CA10}, // 53: C_10, A_10, B_10
    {1, CB3_CA11, CB1_CA11, CB2_CA11}, // 54: C_11, A_11, B_11
    {1, CB3_CA12, CB1_CA12, CB2_CA12}, // 55: C_12, A_12, B_12
    {1, CB3_CA14, CB1_CA14, CB2_CA14}, // 56: C_14, A_14, B_14
    {1, CB3_CA15, CB1_CA15, CB2_CA15}, // 57: C_15, A_15, B_15
    {1, CB3_CA16, CB1_CA16, CB2_CA16}, // 58: C_16, A_16, B_16

    {1, CB6_CA1, CB4_CA1, CB5_CA1},    // 59: F_1, D_1, E_1
    {1, CB6_CA2, CB4_CA2, CB5_CA2},    // 60: F_2, D_2, E_2
    {1, CB6_CA3, CB4_CA3, CB5_CA3},    // 61: F_3, D_3, E_3
    {1, CB6_CA7, CB4_CA7, CB5_CA7},    // 62: F_7, D_7, E_7
    {1, CB6_CA11, CB4_CA11, CB5_CA11}, // 63: F_11, D_11, E_11
    {1, CB6_CA12, CB4_CA12, CB5_CA12}, // 64: F_12, D_12, E_12
    {1, CB6_CA13, CB4_CA13, CB5_CA13}, // 65: F_13, D_13, E_13
    {1, CB6_CA14, CB4_CA14, CB5_CA14}, // 66: F_14, D_14, E_14
    {1, CB6_CA15, CB4_CA15, CB5_CA15}, // 67: F_15, D_15, E_15
    {1, CB6_CA16, CB4_CA16, CB5_CA16}, // 68: F_16, D_16, E_16
};
#endif

// Key combination definitions for Windows shortcuts
typedef struct PACKED {
    uint8_t len;
    uint8_t keycode[3];
} key_combination_t;

// Some key-combos as the default firmware
key_combination_t PROGMEM key_comb_list[4] = {
    {2, {KC_LWIN, KC_TAB}},        // Task (win)
    {2, {KC_LWIN, KC_E}},          // Files (win)
    {3, {KC_LSFT, KC_LWIN, KC_S}}, // Screenshot (win)
    {2, {KC_LWIN, KC_C}}           // Cortana (win)
};

// Default base-layer switch. On keyboard DIP: WIN / MAC
bool dip_switch_update_kb(uint8_t index, bool active) {
    if (index == 0) {
        default_layer_set(1UL << (active ? 0 : 1));
    }
    return dip_switch_update_user(index, active);
}

// QMK: User keycodes
bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_TASK:
        case KC_FILE:
        case KC_SNAP:
        case KC_CTANA:
            if (record->event.pressed) {
                for (uint8_t i = 0; i < key_comb_list[keycode - KC_TASK].len; i++)
                    register_code(key_comb_list[keycode - KC_TASK].keycode[i]);
            } else {
                for (int8_t i = key_comb_list[keycode - KC_TASK].len - 1; i >= 0; i--)
                    unregister_code(key_comb_list[keycode - KC_TASK].keycode[i]);
            }
            return false;
    }

    return process_record_user(keycode, record);
}

// QMK: Initialization
void keyboard_post_init_kb(void) {
    dip_switch_read(true);

// Disable 'int-to-pointer-cast'
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"

    // Just configure the pin, don't act on it
    palSetLineMode(USB_BT_MODE_SELECT_PIN, PAL_MODE_INPUT);

#pragma GCC diagnostic pop

#if defined(RGB_MATRIX_ENABLE)
    rgb_matrix_enable();
    rgb_matrix_mode(RGB_MATRIX_SOLID_COLOR);
    rgb_matrix_sethsv(0, 0, 200);
#endif

    keyboard_post_init_user();
}

// QMK: Background tasks
void housekeeping_task_kb(void) {
    housekeeping_task_user();
}

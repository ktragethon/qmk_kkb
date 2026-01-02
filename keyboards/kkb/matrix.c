// Copyright 2025 kkb (@ktragethon)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "quantum.h"
#include "matrix.h"

// HC595 shift register pins
#define HC595_STCP B0
#define HC595_SHCP A1
#define HC595_DS A7

static pin_t row_pins[MATRIX_ROWS] = MATRIX_ROW_PINS;
static pin_t col_pins[MATRIX_COLS] = MATRIX_COL_PINS;

static inline void HC595_delay(uint16_t n) {
    while (n-- > 0) {
        asm volatile("nop" ::: "memory");
    }
}

// Disable 'int-to-pointer-cast' warning (this entire file)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"

// Write to HC595
static void HC595_output(uint16_t data) {
    uint8_t i;
    uint8_t n = 1;

    for (i = 16; i > 0; i--) {
        writePinLow(HC595_SHCP);

        if (data & 0x8000) {
            writePinHigh(HC595_DS);
        } else {
            writePinLow(HC595_DS);
        }

        data <<= 1;
        HC595_delay(n);
        writePinHigh(HC595_SHCP);
        HC595_delay(n);
    }

    HC595_delay(n);
    writePinLow(HC595_STCP);
    HC595_delay(n);
    writePinHigh(HC595_STCP);
}

// Configure pin to output, drive low
static inline void setPinOutput_writeLow_atomic(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        setPinOutput(pin);
        writePinLow(pin);
    }
}

// Configure pin to input, pullup high
static inline void setPinInput_writeHigh_atomic(pin_t pin) {
    ATOMIC_BLOCK_FORCEON {
        setPinInputHigh(pin);
    }
}

// Validate and read pin from matrix
static inline uint8_t readMatrixPin(pin_t pin) {
    if (pin != NO_PIN) {
        return readPin(pin);
    } else {
        return 1; // No valid key, return 1
    }
}

// Select column (GPIO or shift-register)
static bool select_col(uint8_t col) {
    pin_t pin = col_pins[col];

    // Column 0: GPIO directly
    if (col == 0) {
        if (pin != NO_PIN) {
            setPinOutput_writeLow_atomic(pin);
            return true;
        }
    } else {
        // Columns > 0: Shift registers
        HC595_output(~(0x01 << (col - 1)));
        return true;
    }
    return false;
}

// Deselect column ( GPIO or shift-register)
static void unselect_col(uint8_t col) {
    pin_t pin = col_pins[col];

    // Column 0: GPIO directly
    if (col == 0) {
        if (pin != NO_PIN) {
            setPinInput_writeHigh_atomic(pin);
        }
    } else {
        // Columns > 0: Shift registers
        if (col >= MATRIX_COLS - 1) {
            HC595_output(0xFFFF);
        }
    }
}

// Deselect all columns
static void unselect_cols(void) {
    if (col_pins[0] != NO_PIN) {
        setPinInput_writeHigh_atomic(col_pins[0]);
    }
    HC595_output(0xFFFF);
}

// QMK: Matrix init
void matrix_init_custom(void) {
    // Initialize row pins as input with pullup
    for (uint8_t x = 0; x < MATRIX_ROWS; x++) {
        if (row_pins[x] != NO_PIN) {
            setPinInput_writeHigh_atomic(row_pins[x]);
        }
    }

    // Initialize HC595 control pins
    setPinOutput(HC595_DS);
    setPinOutput(HC595_STCP);
    setPinOutput(HC595_SHCP);

    // Deselect all columns
    unselect_cols();
}

// QMK: Matrix scan
bool matrix_scan_custom(matrix_row_t *raw) {
    bool hasChanged = false;
    // Columns
    for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
        select_col(col);
        wait_us(1); // Settle
        // Rows
        for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {
            bool key_pressed = readMatrixPin(row_pins[row]) == 0;

            // Save old matrix, to detect changes
            matrix_row_t old_row = raw[row];
            if (key_pressed)
                raw[row] |= (MATRIX_ROW_SHIFTER << col);
            else
                raw[row] &= ~(MATRIX_ROW_SHIFTER << col);
            hasChanged |= (raw[row] != old_row);
        }

        unselect_col(col);
    }

    return hasChanged;
}

#pragma GCC diagnostic pop

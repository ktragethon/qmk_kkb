// Copyright 2025 kkb (@ktragethon)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// ============================= SELECT LANGUAGE ==============================

// #define HOST_LAYOUT_US       1
#define HOST_LAYOUT_NORWEGIAN 1

// ============================== GENERAL COMBOS ==============================
// Shortened key-combos used in some layers (for VSCode or other usage)
#define UC_BLD LCTL(LGUI(KC_F1))  // Ctrl+Win+F1  (vscode shortcut to Build)
#define UC_FLS LCTL(LGUI(KC_F2))  // Ctrl+Win+F2  (vscode shortcut to Flash)
#define UC_ED1 LCTL(KC_1)         // Ctrl+1       (vscode shortcut to Editor 1)
#define UC_ED2 LCTL(KC_2)         // Ctrl+2       (vscode shortcut to Editor 2)
#define UC_PIN LCTL(LGUI(KC_F13)) // Ctrl+Win+F13 (vscode shortcut, pin current editor)

#define UC_EXCL S(KC_1) // Same keys in NO and US layouts

// ============================================================================
// NORWEGIAN LAYOUT
// ============================================================================
#if defined(HOST_LAYOUT_NORWEGIAN)
    #include "keymap_norwegian.h"

    // Map UC_* aliases to Norwegian keycodes
    #define UC_LBRC NO_LBRC     // [ FN1
    #define UC_RBRC NO_RBRC     // ] FN1
    #define UC_LPRN NO_LPRN     // ( FN1
    #define UC_RPRN NO_RPRN     // ) FN1
    #define UC_LCBR NO_LCBR     // { FN1
    #define UC_RCBR NO_RCBR     // } FN1
    #define UC_LABK NO_LABK     // < FN1
    #define UC_RABK NO_RABK     // > FN1
    #define UC_AMPR NO_AMPR     // & FN1
    #define UC_EQUA NO_EQL      // = FN1
    #define UC_PIPE NO_PIPE     // | FN1
    #define UC_VMUL NO_ASTR     // * FN2
    #define UC_VDIV NO_SLSH     // / FN2
    #define UC_VADD NO_PLUS     // + FN2
    #define UC_VSUB NO_MINS     // - FN2
    #define UC_QUST NO_QUES     // ? FN2
    #define UC_QOTE NO_DQUO     // " FN2
    #define UC_SQOT NO_QUOT     // ' FN2
    #define UC_SCOL NO_SCLN     // ; FN2
    #define UC_COLO NO_COLN     // : FN2

// ============================================================================
// US LAYOUT
// ============================================================================
#elif defined(HOST_LAYOUT_US)

    // Map UC_* aliases to US keycodes
    #define UC_LBRC KC_LBRC     // [ FN1
    #define UC_RBRC KC_RBRC     // ] FN1
    #define UC_LPRN S(KC_9)     // ( FN1
    #define UC_RPRN S(KC_0)     // ) FN1
    #define UC_LCBR S(KC_LBRC)  // { FN1
    #define UC_RCBR S(KC_RBRC)  // } FN1
    #define UC_LABK S(KC_COMM)  // < FN1
    #define UC_RABK S(KC_DOT)   // > FN1
    #define UC_AMPR S(KC_7)     // & FN1
    #define UC_EQUA KC_EQL      // = FN1
    #define UC_PIPE S(KC_BSLS)  // | FN1
    #define UC_VMUL S(KC_8)     // * FN2
    #define UC_VDIV KC_SLSH     // / FN2
    #define UC_VADD S(KC_EQL)   // + FN2
    #define UC_VSUB KC_MINS     // - FN2
    #define UC_QUST S(KC_SLSH)  // ? FN2
    #define UC_QOTE S(KC_QUOT)  // " FN2
    #define UC_SQOT KC_QUOT     // ' FN2
    #define UC_SCOL KC_SCLN     // ; FN2
    #define UC_COLO S(KC_SCLN)  // : FN2

#else
    #error "Please define HOST_LAYOUT_NORWEGIAN or HOST_LAYOUT_US in keymap_aliases.h"

#endif

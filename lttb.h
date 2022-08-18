#pragma once

#include "quantum.h"

// Taken from drashna:
// Since our quirky block definitions are basically a list of comma separated
// arguments, we need a wrapper in order for these definitions to be
// expanded before being used as arguments to the LAYOUT_xxx macro.
#if !defined(LAYOUT)
#if defined(LAYOUT_ortho_4x12)
#define LAYOUT_wrapper_ortho_4x12(...) LAYOUT_ortho_4x12(__VA_ARGS__)
#define LAYOUT LAYOUT_ortho_4x12
#elif defined(KEYMAP)
#define LAYOUT KEYMAP
#endif
#endif
#define KEYMAP_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

enum userspace_layer_codes {
    DEF = SAFE_RANGE,
    MOUSE,
    SYM,
    NAV,
    NUM,
    ADJUST,

    SW_APPL,
    SW_LANG,
    SW_WIND,

    UK_SELWRD,

    NEW_SAFE_RANGE
};

enum userspace_layers {
    _DEF,
    _MOUSE,
    _SYM,
    _NAV,
    _NUM,
    _ADJUST
};

#define FWD       G(KC_RBRC)
#define BACK      G(KC_LBRC)
#define TABL      G(S(KC_LBRC))
#define TABR      G(S(KC_RBRC))
#define SPCL      A(G(KC_LEFT))
#define SPC_R     A(G(KC_RGHT))
#define WORD_PREV A(KC_LEFT)
#define WORD_NEXT A(KC_RIGHT)

#define OS_SFT OSM(MOD_LSFT)
#define OS_CTL OSM(MOD_LCTL)
#define OS_ALT OSM(MOD_LALT)
#define OS_GUI OSM(MOD_LGUI)

#define __________________XXXXXXX__________________     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ___________________________________________     _______, _______, _______, _______, _______
#define _________________                               _______, _______

#define _________________QWERTY_L1_________________     KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________     KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________     KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________     KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _________________NUMBRS_H1_________________     KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define _________________NUMBRS_H2_________________     KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define _________________FUNKEY_H1_________________     KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5
#define _________________FUNKEY_H2_________________     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10

/* Base Layer */

#define BASE_A KC_A
#define BASE_S KC_S
#define BASE_D KC_D
#define BASE_F KC_F
#define BASE_Z SFT_T(KC_Z)

#define BASE_J KC_J
#define BASE_K KC_K
#define BASE_L KC_L
#define BASE_SCLN KC_SCLN
#define BASE_SLSH SFT_T(KC_SLSH)

#define BASE_THUMB_L LT(_NAV, KC_SPC)
#define BASE_THUMB_R LT(_SYM, KC_ENT)

#define _________________BASE_5_L0_________________     _________________NUMBRS_H1_________________
#define _________________BASE_5_L1_________________     _________________QWERTY_L1_________________
#define _________________BASE_5_L2_________________     BASE_A, BASE_S, BASE_D, BASE_F, KC_G
#define _________________BASE_5_L3_________________     BASE_Z, KC_X,   KC_C,   KC_V,   KC_B

#define _________________BASE_5_R0_________________     _________________NUMBRS_H2_________________
#define _________________BASE_5_R1_________________     _________________QWERTY_R1_________________
#define _________________BASE_5_R2_________________     KC_H, BASE_J, BASE_K,    BASE_L,   BASE_SCLN
#define _________________BASE_5_R3_________________     KC_N, KC_M,   KC_COMM,   KC_DOT,   BASE_SLSH

#define _________________BASE_6_L0_________________     KC_GRV,        _________________BASE_5_L0_________________
#define _________________BASE_6_L1_________________     KC_TAB,        _________________BASE_5_L1_________________
#define _________________BASE_6_L2_________________     CTL_T(KC_ESC), _________________BASE_5_L2_________________
#define _________________BASE_6_L3_________________     KC_LSFT,       _________________BASE_5_L3_________________

#define _________________BASE_6_R0_________________     _________________BASE_5_R0_________________, KC_MINS
#define _________________BASE_6_R1_________________     _________________BASE_5_R1_________________, KC_BSPC
#define _________________BASE_6_R2_________________     _________________BASE_5_R2_________________, KC_QUOT
#define _________________BASE_6_R3_________________     _________________BASE_5_R3_________________, KC_RSFT

#define ____BASE_2_LT____                               KC_LGUI, BASE_THUMB_L
#define ____BASE_2_RT____                               BASE_THUMB_R, KC_HYPR

#define __________BASE_3_LT___________                  KC_LALT, ____BASE_2_LT____
#define __________BASE_3_RT___________                  ____BASE_2_RT____, KC_LCTL

/* Symbols Layer */

#define MT_COLN KC_SCLN
#define MT_LPRN KC_9
#define MT_RPRN KC_0

#define _________________SYMB_5_L0_________________     ___________________________________________
#define _________________SYMB_5_L1_________________     KC_EXLM,        KC_AT,          A(KC_3),        KC_DLR,         KC_PERC
#define _________________SYMB_5_L2_________________     KC_GRV,         KC_DQUO,        KC_MINS,        KC_HASH,        KC_PIPE
#define _________________SYMB_5_L3_________________     KC_TILD,        KC_BSLS,        KC_PLUS,        KC_ASTR,        XXXXXXX

#define _________________SYMB_5_R0_________________     ___________________________________________
#define _________________SYMB_5_R1_________________     KC_CIRC, KC_UNDS,        KC_LCBR,      KC_RCBR,      XXXXXXX
#define _________________SYMB_5_R2_________________     KC_AMPR, KC_LPRN,        KC_RPRN,      KC_EQL,       KC_COLN
#define _________________SYMB_5_R3_________________     KC_LT,   KC_LBRC,        KC_RBRC,      KC_GT,        KC_QUES

#define _________________SYMB_6_L0_________________     _______, _________________SYMB_5_L0_________________
#define _________________SYMB_6_L1_________________     _______, _________________SYMB_5_L1_________________
#define _________________SYMB_6_L2_________________     _______, _________________SYMB_5_L2_________________
#define _________________SYMB_6_L3_________________     _______, _________________SYMB_5_L3_________________

#define _________________SYMB_6_R0_________________     _________________SYMB_5_R0_________________, _______
#define _________________SYMB_6_R1_________________     _________________SYMB_5_R1_________________, _______
#define _________________SYMB_6_R2_________________     _________________SYMB_5_R2_________________, _______
#define _________________SYMB_6_R3_________________     _________________SYMB_5_R3_________________, _______

#define ____SYMB_2_LT____                               _______, _______
#define ____SYMB_2_RT____                               _______, _______

#define __________SYMB_3_LT___________                  _______, ____SYMB_2_LT____
#define __________SYMB_3_RT___________                  _______, ____SYMB_2_RT____

/* Navigation Layer */



#define _________________NAVI_5_L0_________________     ___________________________________________
#define _________________NAVI_5_L1_________________     SW_WIND,          SW_APPL,          BACK,              FWD,               _______
#define _________________NAVI_5_L2_________________     CTL_T(KC_DEL),    OPT_T(KC_TAB),    GUI_T(KC_PGDN),    SFT_T(KC_PGUP),    CAPS_WORD
#define _________________NAVI_5_L3_________________     G(KC_Z),          G(KC_X),          G(KC_C),           G(KC_V),           _______

#define _________________NAVI_5_R0_________________     ___________________________________________
#define _________________NAVI_5_R1_________________     _______,   KC_WH_U,   KC_UP,   KC_WH_D,   KC_DEL
#define _________________NAVI_5_R2_________________     UK_SELWRD, KC_LEFT,   KC_DOWN, KC_RIGHT,  KC_BSPC
#define _________________NAVI_5_R3_________________     _______,   TABL,      TABR,    XXXXXXX,   SW_LANG

#define _________________NAVI_6_L0_________________     _______, _________________NAVI_5_L0_________________
#define _________________NAVI_6_L1_________________     _______, _________________NAVI_5_L1_________________
#define _________________NAVI_6_L2_________________     _______, _________________NAVI_5_L2_________________
#define _________________NAVI_6_L3_________________     _______, _________________NAVI_5_L3_________________

#define _________________NAVI_6_R0_________________     _________________NAVI_5_R0_________________, _______
#define _________________NAVI_6_R1_________________     _________________NAVI_5_R1_________________, _______
#define _________________NAVI_6_R2_________________     _________________NAVI_5_R2_________________, _______
#define _________________NAVI_6_R3_________________     _________________NAVI_5_R3_________________, _______

#define ____NAVI_2_LT____                               _______, _______
#define ____NAVI_2_RT____                               _______, _______

#define __________NAVI_3_LT___________                  _______, ____NAVI_2_LT____
#define __________NAVI_3_RT___________                  _______, ____NAVI_2_RT____

/* Numeric Layer */

#define _________________NUMB_5_L0_________________     ___________________________________________
#define _________________NUMB_5_L1_________________     _________________FUNKEY_H1_________________
#define _________________NUMB_5_L2_________________     CTL_T(KC_1),  OPT_T(KC_2),    GUI_T(KC_3),  SFT_T(KC_4), KC_5
#define _________________NUMB_5_L3_________________     XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX,       KC_F11

#define _________________NUMB_5_R0_________________     ___________________________________________
#define _________________NUMB_5_R1_________________     _________________FUNKEY_H2_________________
#define _________________NUMB_5_R2_________________     KC_6,         SFT_T(KC_7),  GUI_T(KC_8),  OPT_T(KC_9), CTL_T(KC_0)
#define _________________NUMB_5_R3_________________     KC_F12,       XXXXXXX,       XXXXXXX,       XXXXXXX,       XXXXXXX

#define _________________NUMB_6_L0_________________     _______, _________________NUMB_5_L0_________________
#define _________________NUMB_6_L1_________________     _______, _________________NUMB_5_L1_________________
#define _________________NUMB_6_L2_________________     _______, _________________NUMB_5_L2_________________
#define _________________NUMB_6_L3_________________     _______, _________________NUMB_5_L3_________________

#define _________________NUMB_6_R0_________________     _________________NUMB_5_R0_________________, _______
#define _________________NUMB_6_R1_________________     _________________NUMB_5_R1_________________, _______
#define _________________NUMB_6_R2_________________     _________________NUMB_5_R2_________________, _______
#define _________________NUMB_6_R3_________________     _________________NUMB_5_R3_________________, _______

#define ____NUMB_2_LT____                               _______, _______
#define ____NUMB_2_RT____                               _______, _______

#define __________NUMB_3_LT___________                  _______, ____NUMB_2_LT____
#define __________NUMB_3_RT___________                  _______, ____NUMB_2_RT____

/* Mouse Layer */

#define _________________MOUS_5_L0_________________     ___________________________________________
#define _________________MOUS_5_L1_________________     _______,    KC_ACL1,   KC_WH_D,   KC_ACL2, _______
#define _________________MOUS_5_L2_________________     TG(_MOUSE), KC_WH_R,   KC_WH_U,   KC_WH_L, _______
#define _________________MOUS_5_L3_________________     _______,    _______,   KC_ACL0,   KC_BTN1, _______

#define _________________MOUS_5_R0_________________     ___________________________________________
#define _________________MOUS_5_R1_________________     _______,   KC_ACL1,   KC_MS_U,   KC_ACL2,   _______
#define _________________MOUS_5_R2_________________     _______,   KC_MS_L,   KC_MS_D,   KC_MS_R,   _______
#define _________________MOUS_5_R3_________________     _______,   KC_BTN2,   _______,   _______,   _______

#define _________________MOUS_6_L0_________________     _______, _________________MOUS_5_L0_________________
#define _________________MOUS_6_L1_________________     _______, _________________MOUS_5_L1_________________
#define _________________MOUS_6_L2_________________     _______, _________________MOUS_5_L2_________________
#define _________________MOUS_6_L3_________________     _______, _________________MOUS_5_L3_________________

#define _________________MOUS_6_R0_________________     _________________MOUS_5_R0_________________, _______
#define _________________MOUS_6_R1_________________     _________________MOUS_5_R1_________________, _______
#define _________________MOUS_6_R2_________________     _________________MOUS_5_R2_________________, _______
#define _________________MOUS_6_R3_________________     _________________MOUS_5_R3_________________, _______

#define ____MOUS_2_LT____                               _______, _______
#define ____MOUS_2_RT____                               _______, _______

#define __________MOUS_3_LT___________                  _______, ____MOUS_2_LT____
#define __________MOUS_3_RT___________                  _______, ____MOUS_2_RT____

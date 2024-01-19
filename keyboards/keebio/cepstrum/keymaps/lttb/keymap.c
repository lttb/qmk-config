#include QMK_KEYBOARD_H
#include "lttb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_DEF] = LAYOUT_65xt(
    KC_F1, KC_F2,  KC_TILD,  KC_1,    KC_2,    KC_3,    KC_4,         KC_5,   KC_6,  KC_7,  KC_8,         KC_9,    KC_0,    KC_MINS,   KC_EQL,         KC_BSPC, KC_DEL,
    KC_F3, KC_F4,  KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,         KC_T,   KC_Y,  KC_U,  KC_I,         KC_O,    KC_P,    KC_LBRC,   KC_RBRC,        KC_BSLS, KC_END,
    KC_F5, KC_F6,  BASE_ESC, KC_A,    KC_S,    KC_D,    KC_F,         KC_G,   KC_H,  KC_J,  KC_K,         KC_L,    KC_ENT,  KC_QUOT,                   KC_ENT,  KC_PGUP,
    KC_F7, KC_F8,  KC_LSFT,           KC_Z,    KC_X,    KC_C,         KC_V,   KC_B,  KC_N,  KC_M,         KC_COMM, KC_DOT,  BASE_SLSH, SFT_T(KC_SCLN), KC_UP,   KC_PGDN,
    KC_F9, KC_F10, KC_RCTL,  KC_LCTL, KC_LALT, KC_LGUI, BASE_THUMB_L,                       BASE_THUMB_R, KC_HYPR, KC_RCTL, KC_RGUI,   KC_LEFT,        KC_DOWN, KC_RGHT
  ),

  [_SYM] = LAYOUT_65xt(
    RGB_TOG, RGB_MOD, QK_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_BSPC, KC_DEL,
    RGB_HUI, RGB_HUD, _______, KC_EXLM, KC_AT,   KC_LCBR, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_RCBR, KC_GT,   KC_BSLS, _______, _______, _______, _______,
    RGB_SAI, RGB_SAD, _______, KC_GRV,  KC_LBRC, KC_LPRN, KC_EQL,  KC_COLN, KC_ASTR, KC_PIPE, KC_RPRN, KC_RBRC, KC_QUES, _______,          _______, _______,
    RGB_VAI, RGB_VAD, _______,          KC_TILD, KC_DQT,  KC_PLUS, KC_MINS, KC_UNDS, KC_HASH, KC_TAG,  KC_SCLN, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, _______
  ),

  [_NAV] = LAYOUT_65xt(
    _______, _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,   KC_F6,     KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_F11,  KC_F12,  KC_BSPC, KC_DEL,
    _______, _______, _______, KC_Q,    SW_APPL, SW_WIND, TAB_BACK, XXXXXXX, SW_LANG,   KC_DEL,  KC_UP,   KC_BSPC,  XXXXXXX, _______, _______, _______, _______,
    _______, _______, _______, OS_CTL,  OS_ALT,  OS_GUI,  OS_SFT,   XXXXXXX, UK_SELWRD, KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,          _______, _______,
    _______, _______, _______,          G(KC_Z), NAVI_X,  G(KC_C),  G(KC_V), G(KC_ESC), CW_TOGG, SGLBR,   SGRBR,    GLBR,    GRBR,    _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                               _______, _______,  _______, _______, _______, _______, _______
  ),

  [_ADJ] = LAYOUT_65xt(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______,
    _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______, _______
  )

};


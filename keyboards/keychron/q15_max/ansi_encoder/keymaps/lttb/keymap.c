/* Copyright 2024 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "keychron_common.h"
#include "lttb.h"

/*enum layers {*/
/*    MAC_BASE,*/
/*    WIN_BASE,*/
/*    MAC_FN,*/
/*    WIN_FN,*/
/*    COM_FN,*/
/*};*/
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEF] = LAYOUT_ansi_66(
        KC_MUTE,  KC_1,    KC_2,    KC_3,    KC_4,         KC_5,         KC_6,    KC_7,     KC_8,    KC_9,    KC_0,      KC_MINS,        KC_BSPC, KC_MUTE,
        KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,         KC_T,         KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,      KC_LBRC,        KC_RBRC, KC_BSLS,
        BASE_ESC, KC_A,    KC_S,    KC_D,    KC_F,         KC_G,         KC_H,    KC_J,     KC_K,    KC_L,    KC_ENT,    KC_QUOT,        KC_ENT,
        KC_LSFT,  KC_Z,    KC_X,    KC_C,    KC_V,         KC_B,         KC_N,    KC_M,     KC_COMM, KC_DOT,  BASE_SLSH, SFT_T(KC_SCLN), KC_UP,   KC_DEL,
        KC_ESC,   KC_LALT, KC_LALT, KC_LGUI,       BASE_THUMB_L,         BASE_THUMB_R, KC_HYPR, MO(_ADJ),                       KC_LEFT, KC_DOWN, KC_RGHT),

    [_SYM] = LAYOUT_ansi_66(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_MINS, KC_BSPC, KC_MUTE,
        _______, KC_EXLM, KC_AT,   KC_LCBR, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_RCBR, KC_GT,   KC_BSLS, KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_GRV,  KC_LBRC, KC_LPRN, KC_EQL,  KC_COLN, KC_ASTR, KC_PIPE, KC_RPRN, KC_RBRC, KC_QUES, KC_QUOT, KC_ENT,
        _______, KC_TILD, KC_DQT,  KC_PLUS, KC_MINS, KC_UNDS, KC_HASH, KC_TAG,  KC_SCLN, XXXXXXX, XXXXXXX, KC_RSFT, KC_UP,   KC_DEL,
        _______, _______, _______, _______,  _______,       _______,       _______, _______ ,KC_LEFT, KC_DOWN,  KC_RGHT),


    [_NAV] = LAYOUT_ansi_66(
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,     KC_F6,     KC_F7,   KC_F8,   KC_F9,    KC_F10,  KC_MINS, KC_BSPC, KC_MUTE,
        _______, KC_Q,    SW_APPL, SW_WIND, TAB_BACK, XXXXXXX,   SW_LANG,   KC_DEL,  KC_UP,   KC_BSPC,  XXXXXXX, KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT,  XXXXXXX,   UK_SELWRD, KC_LEFT, KC_DOWN, KC_RIGHT, _______, KC_QUOT, KC_ENT,
        _______, G(KC_Z), NAVI_X,  G(KC_C), G(KC_V),  G(KC_ESC), CW_TOGG,   SGLBR,   SGRBR,   GLBR,     GRBR,    KC_RSFT, KC_UP,   KC_DEL,
        _______, _______, _______, _______,  _______,       _______,       _______,  _______,KC_LEFT, KC_DOWN,  KC_RGHT),

    /*[WIN_BASE] = LAYOUT_ansi_66(*/
    /*    KC_MUTE,  KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,   KC_BSPC,  KC_MUTE,*/
    /*    KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,   KC_RBRC,  KC_BSLS,*/
    /*    KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,   KC_ENT,*/
    /*    KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,   KC_UP,    KC_DEL,*/
    /*    KC_LCTL,  KC_LGUI,  KC_LALT,  _______,  KC_SPC,                       KC_SPC,             MO(WIN_FN),MO(COM_FN),KC_LEFT, KC_DOWN,  KC_RGHT),*/
    /**/
    /*[MAC_FN] = LAYOUT_ansi_66(*/
    /* RGB_TOG,  KC_BRID,  KC_BRIU,  KC_MCTRL, KC_LNPAD, RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  RGB_TOG,*/
    /*    KC_GRV,   BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,*/
    /*    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,*/
    /*    _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,*/
    /*    _______,  _______,  _______,  _______,  _______,                      _______,            _______,  _______,  _______,  _______,  _______),*/
    /**/
    /*[WIN_FN] = LAYOUT_ansi_66(*/
    /* RGB_TOG,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  RGB_TOG,*/
    /*    KC_GRV,   BT_HST1,  BT_HST2,  BT_HST3,  P2P4G,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,*/
    /*    RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,*/
    /*    _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,*/
    /*    _______,  _______,  _______,  _______,  _______,                      _______,            _______,  _______,  _______,  _______,  _______),*/

    [_ADJ] = LAYOUT_ansi_66(
        RGB_TOG, KC_BRID,  KC_BRIU, KC_MCTRL, KC_LNPAD, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, RGB_TOG,
        KC_GRV,  BT_HST1,  BT_HST2, BT_HST3,  P2P4G,    _______, _______, _______, _______, _______, _______, _______, _______, _______,
        RGB_TOG, RGB_MOD,  RGB_VAI, RGB_HUI,  RGB_SAI,  RGB_SPI, _______, _______, _______, _______, _______, _______, _______,
        _______, RGB_RMOD, RGB_VAD, RGB_HUD,  RGB_SAD,  RGB_SPD, NK_TOGG, _______, _______, _______, _______, _______, _______, _______,
        _______, _______,  _______, _______,  _______,  _______, _______, _______, _______, _______, _______),
};

// clang-format on
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][2][2] = {
    [_DEF] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU),ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_SYM] = {ENCODER_CCW_CW(_______, _______),ENCODER_CCW_CW(_______, _______)},
    [_NAV] = {ENCODER_CCW_CW(_______, _______),ENCODER_CCW_CW(_______, _______)},
    [_ADJ] = {ENCODER_CCW_CW(_______, _______),ENCODER_CCW_CW(_______, _______)},
    /*[WIN_BASE] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU),ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},*/
    /*[MAC_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI),ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},*/
    /*[WIN_FN]   = {ENCODER_CCW_CW(RGB_VAD, RGB_VAI),ENCODER_CCW_CW(RGB_VAD, RGB_VAI)},*/
    /*[COM_FN]   = {ENCODER_CCW_CW(_______, _______),ENCODER_CCW_CW(_______, _______)},*/
};

#endif // ENCODER_MAP_ENABLE

// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     if (!process_record_keychron_common(keycode, record)) {
//         return false;
//     }
//     return true;
// }

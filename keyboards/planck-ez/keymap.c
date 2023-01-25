/* Copyright 2020 ZSA Technology Inc
 * Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
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
#include "lttb.h"

#define ___________ XXXXXXX, XXXXXXX, XXXXXXX

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEF] = LAYOUT_wrapper(
        _________________BASE_6_L1_________________, _________________BASE_6_R1_________________,
        _________________BASE_6_L2_________________, _________________BASE_6_R2_________________,
        _________________BASE_6_L3_________________, _________________BASE_6_R3_________________,
        ___________, __________BASE_3_LT___________, KC_NO, __________BASE_3_RT___________, XXXXXXX, QK_BOOT
    ),

    [_SYM] = LAYOUT_wrapper(
        _________________SYMB_6_L1_________________, _________________SYMB_6_R1_________________,
        _________________SYMB_6_L2_________________, _________________SYMB_6_R2_________________,
        _________________SYMB_6_L3_________________, _________________SYMB_6_R3_________________,
        ___________, __________SYMB_3_LT___________, KC_NO, __________SYMB_3_RT___________, XXXXXXX, XXXXXXX
    ),

    [_NAV] = LAYOUT_wrapper(
        _________________NAVI_6_L1_________________, _________________NAVI_6_R1_________________,
        _________________NAVI_6_L2_________________, _________________NAVI_6_R2_________________,
        _________________NAVI_6_L3_________________, _________________NAVI_6_R3_________________,
        ___________, __________NAVI_3_LT___________, KC_NO, __________NAVI_3_RT___________, XXXXXXX, XXXXXXX
    ),

    [_NUM] = LAYOUT_wrapper(
        _________________NUMB_6_L1_________________, _________________NUMB_6_R1_________________,
        _________________NUMB_6_L2_________________, _________________NUMB_6_R2_________________,
        _________________NUMB_6_L3_________________, _________________NUMB_6_R3_________________,
        ___________, __________NUMB_3_LT___________, KC_NO, __________NUMB_3_RT___________, XXXXXXX, XXXXXXX
    ),

    [_MOUSE] = LAYOUT_wrapper(
        _________________MOUS_6_L1_________________, _________________MOUS_6_R1_________________,
        _________________MOUS_6_L2_________________, _________________MOUS_6_R2_________________,
        _________________MOUS_6_L3_________________, _________________MOUS_6_R3_________________,
        ___________, __________MOUS_3_LT___________, KC_NO, __________MOUS_3_RT___________, XXXXXXX, XXXXXXX    
    ),

    [_SCRL] = LAYOUT_wrapper(
        _________________SCRL_6_L1_________________, _________________SCRL_6_R1_________________,
        _________________SCRL_6_L2_________________, _________________SCRL_6_R2_________________,
        _________________SCRL_6_L3_________________, _________________SCRL_6_R3_________________,
        ___________, __________SCRL_3_LT___________, KC_NO, __________SCRL_3_RT___________, XXXXXXX, XXXXXXX    
    ),

};
// clang-format on

// const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
//     [0] = {{42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {146, 224, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {42, 255, 255}, {32, 255, 234}, {32, 255, 234}, {32, 255, 234}, {32, 255, 234}},

//     [1] = {{89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {169, 120, 255}, {169, 120, 255}, {169, 120, 255}, {169, 120, 255}, {169, 120, 255}, {169, 120, 255}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {169, 120, 255}, {169, 120, 255}, {169, 120, 255}, {169, 120, 255}, {169, 120, 255}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}, {89, 255, 246}},

//     [2] = {{216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {249, 228, 255}, {249, 228, 255}, {249, 228, 255}, {216, 255, 255}, {216, 255, 255}, {105, 255, 255}, {105, 255, 255}, {105, 255, 255}, {216, 255, 255}, {14, 255, 255}, {216, 255, 255}, {216, 255, 255}, {249, 228, 255}, {249, 228, 255}, {249, 228, 255}, {216, 255, 255}, {216, 255, 255}, {105, 255, 255}, {105, 255, 255}, {105, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}, {216, 255, 255}},

// };

// void set_layer_color(int layer) {
//     for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
//         HSV hsv = {
//             .h = pgm_read_byte(&ledmap[layer][i][0]),
//             .s = pgm_read_byte(&ledmap[layer][i][1]),
//             .v = pgm_read_byte(&ledmap[layer][i][2]),
//         };
//         if (!hsv.h && !hsv.s && !hsv.v) {
//             rgb_matrix_set_color(i, 0, 0, 0);
//         } else {
//             RGB   rgb = hsv_to_rgb(hsv);
//             float f   = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
//             rgb_matrix_set_color(i, f * rgb.r, f * rgb.g, f * rgb.b);
//         }
//     }
// }

// bool rgb_matrix_indicators_user(void) {
//     if (keyboard_config.disable_layer_led) {
//         return false;
//     }
//     switch (get_highest_layer(layer_state)) {
//         case 1:
//             set_layer_color(0);
//             break;
//         case 2:
//             set_layer_color(1);
//             break;
//         case 3:
//             set_layer_color(2);
//             break;
//         default:
//             if (rgb_matrix_get_flags() == LED_FLAG_NONE) rgb_matrix_set_color_all(0, 0, 0);
//             break;
//     }
//     return false;
// }

// bool encoder_update_user(uint8_t index, bool clockwise) {
//     if (clockwise) {
// #    ifdef MOUSEKEY_ENABLE
//         tap_code(KC_MS_WH_DOWN);
// #    else
//         tap_code(KC_PGDN);
// #    endif
//     } else {
// #    ifdef MOUSEKEY_ENABLE
//         tap_code(KC_MS_WH_UP);
// #    else
//         tap_code(KC_PGUP);
// #    endif
//     }
//     return true;
// }

bool music_mask_user(uint16_t keycode) {
    switch (keycode) {
        case SYM:
        case NAV:
            return false;
        default:
            return true;
    }
}


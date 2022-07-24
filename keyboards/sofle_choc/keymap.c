/* Copyright 2022 lttb
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_DEF] = LAYOUT_wrapper(
        _________________BASE_6_L0_________________,                        _________________BASE_6_R0_________________,
        _________________BASE_6_L1_________________,                        _________________BASE_6_R1_________________,
        _________________BASE_6_L2_________________,                        _________________BASE_6_R2_________________,
        _________________BASE_6_L3_________________,   KC_MUTE, KC_MPLY,    _________________BASE_6_R3_________________,
              XXXXXXX, XXXXXXX, __________BASE_3_LT___________, __________BASE_3_RT___________, XXXXXXX, XXXXXXX
    ),

    [_MOUSE] = LAYOUT_wrapper(
        _________________MOUS_6_L0_________________,                        _________________MOUS_6_R0_________________,
        _________________MOUS_6_L1_________________,                        _________________MOUS_6_R1_________________,
        _________________MOUS_6_L2_________________,                        _________________MOUS_6_R2_________________,
        _________________MOUS_6_L3_________________,   KC_MUTE, KC_MPLY,    _________________MOUS_6_R3_________________,
              XXXXXXX, XXXXXXX, __________MOUS_3_LT___________, __________MOUS_3_RT___________, XXXXXXX, XXXXXXX
    ),

    [_SYM] = LAYOUT_wrapper(
        _________________SYMB_6_L0_________________,                        _________________SYMB_6_R0_________________,
        _________________SYMB_6_L1_________________,                        _________________SYMB_6_R1_________________,
        _________________SYMB_6_L2_________________,                        _________________SYMB_6_R2_________________,
        _________________SYMB_6_L3_________________,   _______, _______,    _________________SYMB_6_R3_________________,
              XXXXXXX, XXXXXXX, __________SYMB_3_LT___________, __________SYMB_3_RT___________, XXXXXXX, XXXXXXX
    ),

    [_NAV] = LAYOUT_wrapper(
        _________________NAVI_6_L0_________________,                        _________________NAVI_6_R0_________________,
        _________________NAVI_6_L1_________________,                        _________________NAVI_6_R1_________________,
        _________________NAVI_6_L2_________________,                        _________________NAVI_6_R2_________________,
        _________________NAVI_6_L3_________________,   _______, _______,    _________________NAVI_6_R3_________________,
              XXXXXXX, XXXXXXX, __________NAVI_3_LT___________, __________NAVI_3_RT___________, XXXXXXX, XXXXXXX
    ),

    [_NUM] = LAYOUT_wrapper(
        _________________NUMB_6_L0_________________,                        _________________NUMB_6_R0_________________,
        _________________NUMB_6_L1_________________,                        _________________NUMB_6_R1_________________,
        _________________NUMB_6_L2_________________,                        _________________NUMB_6_R2_________________,
        _________________NUMB_6_L3_________________,   _______, _______,    _________________NUMB_6_R3_________________,
              XXXXXXX, XXXXXXX, __________NUMB_3_LT___________, __________NUMB_3_RT___________, XXXXXXX, XXXXXXX
    ),
};



#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

void write_int_ln(const char* prefix, uint8_t value) {
    oled_write_P(prefix, false);
    oled_write(get_u8_str(value, ' '), false);
}

static void print_status_narrow(void) {
    oled_write_ln_P(PSTR("SofleChoc _____"), false);

    if (get_highest_layer(layer_state) == _ADJUST) {
        uint8_t mode  = rgb_matrix_get_mode();
        HSV     hsv   = rgb_matrix_get_hsv();
        uint8_t speed = rgb_matrix_get_speed();

        if (keymap_config.swap_lctl_lgui) {
            oled_write_ln_P(PSTR("MAC\n"), false);
        } else {
            oled_write_ln_P(PSTR("WIN\n"), false);
        }

        oled_write_ln("RGB", false);
        write_int_ln(PSTR("Mo"), mode);
        write_int_ln(PSTR("H "), hsv.h);
        write_int_ln(PSTR("S "), hsv.s);
        write_int_ln(PSTR("V "), hsv.v);
        write_int_ln(PSTR("Sp"), speed);
        oled_write_P(PSTR("\n\n\n"), false);
    } else {
        oled_write_P(PSTR("\n\n\n\n\n\n\n\n\n"), false);
        led_t led_usb_state = host_keyboard_led_state();
        if (led_usb_state.caps_lock) {
            oled_write_ln_P(PSTR(" CAP "), true);
        } else {
            oled_write_ln_P(PSTR("     "), false);
        }
    }

    // Print current layer
    switch (get_highest_layer(layer_state)) {
        case _DEF:
            oled_write_P(PSTR("Alpha"), false);
            break;
        case _NAV:
            oled_write_P(PSTR("Nav  "), false);
            break;
        case _SYM:
            oled_write_P(PSTR("Sym  "), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj  "), false);
            break;
        default:
            oled_write_P(PSTR("???  "), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }

    return false;
}

#endif

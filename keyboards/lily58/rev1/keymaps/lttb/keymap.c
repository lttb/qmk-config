
#include QMK_KEYBOARD_H
#include "lttb.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

    [_DEF] = LAYOUT_wrapper(
        _________________BASE_6_L0_________________,                        _________________BASE_6_R0_________________,
        _________________BASE_6_L1_________________,                        _________________BASE_6_R1_________________,
        _________________BASE_6_L2_________________,                        _________________BASE_6_R2_________________,
        _________________BASE_6_L3_________________,   KC_MUTE, KC_MPLY,    _________________BASE_6_R3_________________,
                       XXXXXXX, __________BASE_3_LT___________, __________BASE_3_RT___________, XXXXXXX
    ),

    [_SYM] = LAYOUT_wrapper(
        _________________SYMB6_L0_________________,                        _________________SYMB_6_R0_________________,
        _________________SYMB_6_L1_________________,                        _________________SYMB_6_R1_________________,
        _________________SYMB_6_L2_________________,                        _________________SYMB_6_R2_________________,
        _________________SYMB_6_L3_________________,   _______, _______,    _________________SYMB_6_R3_________________,
                       XXXXXXX, __________SYMB_3_LT___________, __________SYMB_3_RT___________, XXXXXXX
    ),

    [_NAV] = LAYOUT_wrapper(
        _________________NAVI_6_L0_________________,                        _________________NAVI_6_R0_________________,
        _________________NAVI_6_L1_________________,                        _________________NAVI_6_R1_________________,
        _________________NAVI_6_L2_________________,                        _________________NAVI_6_R2_________________,
        _________________NAVI_6_L3_________________,   _______, _______,    _________________NAVI_6_R3_________________,
                       XXXXXXX, __________NAVI_3_LT___________, __________NAVI_3_RT___________, XXXXXXX
    ),

    [_NUM] = LAYOUT_wrapper(
        _________________NUMB_6_L0_________________,                        _________________NUMB_6_R0_________________,
        _________________NUMB_6_L1_________________,                        _________________NUMB_6_R1_________________,
        _________________NUMB_6_L2_________________,                        _________________NUMB_6_R2_________________,
        _________________NUMB_6_L3_________________,   _______, _______,    _________________NUMB_6_R3_________________,
                       XXXXXXX, __________NUMB_3_LT___________, __________NUMB_3_RT___________, XXXXXXX
    ),

    [_MOUSE] = LAYOUT_wrapper(
        _________________MOUS_6_L0_________________,                        _________________MOUS_6_R0_________________,
        _________________MOUS_6_L1_________________,                        _________________MOUS_6_R1_________________,
        _________________MOUS_6_L2_________________,                        _________________MOUS_6_R2_________________,
        _________________MOUS_6_L3_________________,   _______, _______,    _________________MOUS_6_R3_________________,
                       XXXXXXX, __________MOUS_3_LT___________, __________MOUS_3_RT___________, XXXXXXX
    ),

    [_SCRL] = LAYOUT_wrapper(
        _________________SCRL_6_L0_________________,                        _________________SCRL_6_R0_________________,
        _________________SCRL_6_L1_________________,                        _________________SCRL_6_R1_________________,
        _________________SCRL_6_L2_________________,                        _________________SCRL_6_R2_________________,
        _________________SCRL_6_L3_________________,   _______, _______,    _________________SCRL_6_R3_________________,
                       XXXXXXX, __________SCRL_3_LT___________, __________SCRL_3_RT___________, XXXXXXX
    ),
};


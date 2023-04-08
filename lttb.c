#include QMK_KEYBOARD_H

#include "./features/swapper.h"
// #include "./features/achordion.h"
#include "./features/select_word.h"

#include "lttb.h"


bool sw_appl_active = false;
bool sw_wind_active = false;
bool sw_lang_active = false;
bool sw_tabl_active = false;
bool sw_tabr_active = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_select_word(keycode, record, UK_SELWRD)) { return false; }

    bool is_swapper_skip = keycode == KC_LSFT
        || keycode == OSM(MOD_LSFT)
        || keycode == MOD_LSFT
        || keycode == KC_LEFT
        || keycode == KC_RIGHT
        || keycode == KC_UP
        || keycode == KC_DOWN;

    update_swapper(
        &sw_appl_active, KC_LGUI, KC_TAB, false, SW_APPL,
        keycode, is_swapper_skip || keycode == NAVI_X || keycode == KC_Q || keycode == TAB_BACK, record
    );
    if (sw_appl_active && keycode == NAVI_X) {
        if (record->event.pressed) {
            unregister_code(KC_X);
            register_code(KC_Q);
        } else {
            unregister_code(KC_Q);
        }
    }

    update_swapper(
        &sw_wind_active, KC_LGUI, KC_GRV, false, SW_WIND,
        keycode, is_swapper_skip, record
    );
    update_swapper(
        &sw_lang_active, KC_LGUI, KC_SPC, false, SW_LANG,
        keycode, is_swapper_skip, record
    );
    update_swapper(
        &sw_tabr_active, KC_LCTL, KC_TAB, false, SW_TABR,
        keycode, is_swapper_skip || keycode == SW_TABL, record
    );
    update_swapper(
        &sw_tabl_active, KC_LCTL, KC_TAB, true, SW_TABL,
        keycode, is_swapper_skip || keycode == SW_TABR, record
    );

    switch (keycode) {
        case SW_APPL:
        case SW_WIND:
        case SW_LANG:
            return true;

        case OPT_T(MT_COLN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_COLN);
                return false;
            }
            break;
        case SFT_T(MT_LPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LPRN);
                return false;
            }
            break;
        case CMD_T(MT_RPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RPRN);
                return false;
            }
            break;
    }

    // if (!process_achordion(keycode, record)) { return false; }

    return true;
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OS_CTL:
        case OS_ALT:
        case OS_GUI:
        case OS_SFT:
        case BASE_C:
           return 500;
        case BASE_ESC:
           return 150;
        default:
            return TAPPING_TERM;
    }
}


bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            if (keycode == BASE_C || keycode == BASE_X) {
                return false;
            }

            return true;
        default:
            return false;
    }
}

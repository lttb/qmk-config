#include QMK_KEYBOARD_H

#include "./features/swapper.h"
#include "./features/achordion.h"
#include "./features/select_word.h"

#include "lttb.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case OS_CTL:
           return 500;
        case OS_ALT:
           return 500;
        case OS_GUI:
           return 500;
        case OS_SFT:
           return 500;
        default:
            return TAPPING_TERM;
    }
}

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

    if (!process_achordion(keycode, record)) { return false; }

    return true;
}

// bool get_tapping_force_hold(uint16_t keycode, keyrecord_t* record) {
//   // If you quickly hold a tap-hold key after tapping it, the tap action is
//   // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
//   // lead to missed triggers in fast typing. Here, returning true means we
//   // instead want to "force hold" and disable key repeating.
//   switch (keycode) {
//     case BASE_D:
//     case BASE_J:
//     case BASE_K:
//         return false;  // Enable key repeating.
//     default:
//         return true;  // Otherwise, force hold and disable key repeating.
//   }
// }

// layer_state_t layer_state_set_user(layer_state_t state) {
//     return update_tri_layer_state(state, _SYM, _NAV, _NUM);
// }

void matrix_scan_user(void) {
  achordion_task();
}

bool achordion_chord(
    uint16_t tap_hold_keycode,
    keyrecord_t* tap_hold_record,
    uint16_t other_keycode,
    keyrecord_t* other_record
) {
    switch (tap_hold_keycode) {
        case BASE_THUMB_L:
        case BASE_THUMB_R:
        case BASE_Q:
        case BASE_ESC:
        case BASE_Z:
        case BASE_X:
        case BASE_COMM:
        case BASE_DOT:
        case BASE_SLSH:
        case BASE_SCLN:
            return true;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
        case BASE_THUMB_L:
        case BASE_THUMB_R:
        case BASE_Q:
        case BASE_ESC:
        case BASE_Z:
        case BASE_X:
        case BASE_COMM:
        case BASE_DOT:
        case BASE_SLSH:
        case BASE_SCLN:
            return 0;  // Bypass Achordion for these keys.
  }

  return 800;  // Otherwise use a timeout of 800 ms.
}

// bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         // case BASE_Z:
//         case BASE_SLSH:
//         // case BASE_THUMB_L:
//         case BASE_THUMB_R:
//             // Immediately select the hold action when another key is pressed.
//             return true;
//         default:
//             // Do not select the hold action when another key is pressed.
//             return false;
//     }
// }

// bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         // case BASE_THUMB_L:
//         case BASE_THUMB_R:
//             return false;
//         default:
//             return true;
//     }
// }

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

#include QMK_KEYBOARD_H

#include "./features/swapper.h"
#include "./features/achordion.h"
#include "./features/select_word.h"

#include "lttb.h"

enum combo_events {
    MOUSE_KEYS_COMBO,

    SFT_COMBO,
    SFT_COMBO_L,
    SFT_COMBO_R,
    CMD_COMBO,
    CMD_COMBO_L,
    CMD_COMBO_R,
    ALT_COMBO,
    ALT_COMBO_L,
    ALT_COMBO_R,
    CTL_COMBO,
    CTL_COMBO_L,
    CTL_COMBO_R,

    SFT_ALT_COMBO_L,
    SFT_ALT_COMBO_R,
    SFT_CMD_COMBO_L,
    SFT_CMD_COMBO_R,
    SFT_CTL_COMBO_L,
    SFT_CTL_COMBO_R,
    CMD_ALT_COMBO_L,
    CMD_ALT_COMBO_R,
    CMD_CTL_COMBO_L,
    CMD_CTL_COMBO_R,
    CTL_ALT_COMBO_L,
    CTL_ALT_COMBO_R,

    SFT_CMD_ALT_COMBO_L,
    SFT_CMD_ALT_COMBO_R,
    SFT_CMD_CTL_COMBO_L,
    SFT_CMD_CTL_COMBO_R,
    SFT_CTL_ALT_COMBO_L,
    SFT_CTL_ALT_COMBO_R,
    CMD_ALT_CTL_COMBO_L,
    CMD_ALT_CTL_COMBO_R,

    SFT_CMD_ALT_CTL_COMBO_L,
    SFT_CMD_ALT_CTL_COMBO_R,

    COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM mouse_keys_combo[] = {KC_X, KC_C, COMBO_END};

const uint16_t PROGMEM sft_combo[]   = {KC_F,         KC_J,      COMBO_END};
const uint16_t PROGMEM sft_combo_l[] = {BASE_THUMB_L, KC_F,      COMBO_END};
const uint16_t PROGMEM sft_combo_r[] = {BASE_THUMB_R, KC_J,      COMBO_END};

const uint16_t PROGMEM cmd_combo[]   = {KC_D,         KC_K,      COMBO_END};
const uint16_t PROGMEM cmd_combo_l[] = {BASE_THUMB_L, KC_D,      COMBO_END};
const uint16_t PROGMEM cmd_combo_r[] = {BASE_THUMB_R, KC_K,      COMBO_END};

const uint16_t PROGMEM alt_combo[]   = {KC_S,         KC_L,      COMBO_END};
const uint16_t PROGMEM alt_combo_l[] = {BASE_THUMB_L, KC_S,      COMBO_END};
const uint16_t PROGMEM alt_combo_r[] = {BASE_THUMB_R, KC_L,      COMBO_END};

const uint16_t PROGMEM ctl_combo[]   = {KC_A,         KC_SCLN,   COMBO_END};
const uint16_t PROGMEM ctl_combo_l[] = {BASE_THUMB_L, KC_A,      COMBO_END};
const uint16_t PROGMEM ctl_combo_r[] = {BASE_THUMB_R, KC_SCLN, COMBO_END};

const uint16_t PROGMEM sft_cmd_combo_l[] = {KC_D,    KC_F, COMBO_END};
const uint16_t PROGMEM sft_cmd_combo_r[] = {KC_K,    KC_J, COMBO_END};
const uint16_t PROGMEM sft_alt_combo_l[] = {KC_S,    KC_F, COMBO_END};
const uint16_t PROGMEM sft_alt_combo_r[] = {KC_L,    KC_J, COMBO_END};
const uint16_t PROGMEM sft_ctl_combo_l[] = {KC_A,    KC_F, COMBO_END};
const uint16_t PROGMEM sft_ctl_combo_r[] = {KC_SCLN, KC_J, COMBO_END};
const uint16_t PROGMEM cmd_ctl_combo_l[] = {KC_A,    KC_D, COMBO_END};
const uint16_t PROGMEM cmd_ctl_combo_r[] = {KC_SCLN, KC_K, COMBO_END};
const uint16_t PROGMEM cmd_alt_combo_l[] = {KC_S,    KC_D, COMBO_END};
const uint16_t PROGMEM cmd_alt_combo_r[] = {KC_L,    KC_K, COMBO_END};
const uint16_t PROGMEM ctl_alt_combo_l[] = {KC_A,    KC_S, COMBO_END};
const uint16_t PROGMEM ctl_alt_combo_r[] = {KC_SCLN, KC_L, COMBO_END};

const uint16_t PROGMEM sft_cmd_alt_combo_l[] = {KC_S,    KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM sft_cmd_alt_combo_r[] = {KC_L,    KC_K, KC_J, COMBO_END};
const uint16_t PROGMEM sft_cmd_ctl_combo_l[] = {KC_A,    KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM sft_cmd_ctl_combo_r[] = {KC_SCLN, KC_K, KC_J, COMBO_END};
const uint16_t PROGMEM cmd_alt_ctl_combo_l[] = {KC_A,    KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM cmd_alt_ctl_combo_r[] = {KC_SCLN, KC_L, KC_K, COMBO_END};
const uint16_t PROGMEM sft_ctl_alt_combo_l[] = {KC_A,    KC_S, KC_F, COMBO_END};
const uint16_t PROGMEM sft_ctl_alt_combo_r[] = {KC_SCLN, KC_L, KC_J, COMBO_END};

const uint16_t PROGMEM sft_cmd_alt_ctl_combo_l[] = {KC_A,    KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM sft_cmd_alt_ctl_combo_r[] = {KC_SCLN, KC_L, KC_K, KC_J, COMBO_END};

combo_t key_combos[] = {
    [MOUSE_KEYS_COMBO] = COMBO(mouse_keys_combo, TG(1)),

    [SFT_COMBO] = COMBO(sft_combo, OSM(MOD_LSFT)),
    [SFT_COMBO_L] = COMBO(sft_combo_l, OSM(MOD_LSFT)),
    [SFT_COMBO_R] = COMBO(sft_combo_r, OSM(MOD_LSFT)),

    [CMD_COMBO] = COMBO(cmd_combo, OSM(MOD_LGUI)),
    [CMD_COMBO_L] = COMBO(cmd_combo_l, OSM(MOD_LGUI)),
    [CMD_COMBO_R] = COMBO(cmd_combo_r, OSM(MOD_LGUI)),

    [ALT_COMBO] = COMBO(alt_combo, OSM(MOD_LALT)),
    [ALT_COMBO_L] = COMBO(alt_combo_l, OSM(MOD_LALT)),
    [ALT_COMBO_R] = COMBO(alt_combo_r, OSM(MOD_LALT)),

    [CTL_COMBO] = COMBO(ctl_combo, OSM(MOD_LCTL)),
    [CTL_COMBO_L] = COMBO(ctl_combo_l, OSM(MOD_LCTL)),
    [CTL_COMBO_R] = COMBO(ctl_combo_r, OSM(MOD_LCTL)),

    [SFT_CMD_COMBO_L] = COMBO(sft_cmd_combo_l, OSM(MOD_LSFT | MOD_LGUI)),
    [SFT_CMD_COMBO_R] = COMBO(sft_cmd_combo_r, OSM(MOD_LSFT | MOD_LGUI)),
    [SFT_ALT_COMBO_L] = COMBO(sft_alt_combo_l, OSM(MOD_LSFT | MOD_LALT)),
    [SFT_ALT_COMBO_R] = COMBO(sft_alt_combo_r, OSM(MOD_LSFT | MOD_LALT)),
    [SFT_CTL_COMBO_L] = COMBO(sft_ctl_combo_l, OSM(MOD_LSFT | MOD_LCTL)),
    [SFT_CTL_COMBO_R] = COMBO(sft_ctl_combo_r, OSM(MOD_LSFT | MOD_LCTL)),
    [CMD_CTL_COMBO_L] = COMBO(cmd_ctl_combo_l, OSM(MOD_LGUI | MOD_LCTL)),
    [CMD_CTL_COMBO_R] = COMBO(cmd_ctl_combo_r, OSM(MOD_LGUI | MOD_LCTL)),
    [CMD_ALT_COMBO_L] = COMBO(cmd_alt_combo_l, OSM(MOD_LGUI | MOD_LALT)),
    [CMD_ALT_COMBO_R] = COMBO(cmd_alt_combo_r, OSM(MOD_LGUI | MOD_LALT)),
    [CTL_ALT_COMBO_L] = COMBO(ctl_alt_combo_l, OSM(MOD_LCTL | MOD_LALT)),
    [CTL_ALT_COMBO_R] = COMBO(ctl_alt_combo_r, OSM(MOD_LCTL | MOD_LALT)),

    [SFT_CMD_ALT_COMBO_L] = COMBO(sft_cmd_alt_combo_l, OSM(MOD_LSFT | MOD_LGUI | MOD_LALT)),
    [SFT_CMD_ALT_COMBO_R] = COMBO(sft_cmd_alt_combo_r, OSM(MOD_LSFT | MOD_LGUI | MOD_LALT)),
    [SFT_CMD_CTL_COMBO_L] = COMBO(sft_cmd_ctl_combo_l, OSM(MOD_LSFT | MOD_LGUI | MOD_LCTL)),
    [SFT_CMD_CTL_COMBO_R] = COMBO(sft_cmd_ctl_combo_r, OSM(MOD_LSFT | MOD_LGUI | MOD_LCTL)),
    [CMD_ALT_CTL_COMBO_L] = COMBO(cmd_alt_ctl_combo_l, OSM(MOD_LGUI | MOD_LALT | MOD_LCTL)),
    [CMD_ALT_CTL_COMBO_R] = COMBO(cmd_alt_ctl_combo_r, OSM(MOD_LGUI | MOD_LALT | MOD_LCTL)),
    [SFT_CTL_ALT_COMBO_L] = COMBO(sft_ctl_alt_combo_l, OSM(MOD_LSFT | MOD_LCTL | MOD_LALT)),
    [SFT_CTL_ALT_COMBO_R] = COMBO(sft_ctl_alt_combo_r, OSM(MOD_LSFT | MOD_LCTL | MOD_LALT)),

    [SFT_CMD_ALT_CTL_COMBO_L] = COMBO(sft_cmd_alt_ctl_combo_l, OSM(MOD_LSFT | MOD_LGUI | MOD_LALT | MOD_LCTL)),
    [SFT_CMD_ALT_CTL_COMBO_R] = COMBO(sft_cmd_alt_ctl_combo_r, OSM(MOD_LSFT | MOD_LGUI | MOD_LALT | MOD_LCTL)),
};

bool get_combo_must_hold(uint16_t index, combo_t *combo) {
    switch (index) {
        // exclude accidental rolling combos
        case CMD_ALT_COMBO_L:
        case CMD_CTL_COMBO_L:
        case SFT_CTL_COMBO_L:
        case CTL_ALT_COMBO_L:
            return true;
    }

    return false;
}

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
        &sw_appl_active, KC_LGUI, KC_TAB, SW_APPL,
        keycode, is_swapper_skip, record
    );
    update_swapper(
        &sw_wind_active, KC_LGUI, KC_GRV, SW_WIND,
        keycode, is_swapper_skip, record
    );
    update_swapper(
        &sw_lang_active, KC_LGUI, KC_SPC, SW_LANG,
        keycode, is_swapper_skip, record
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

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t* record) {
  // If you quickly hold a tap-hold key after tapping it, the tap action is
  // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
  // lead to missed triggers in fast typing. Here, returning true means we
  // instead want to "force hold" and disable key repeating.
  switch (keycode) {
    case SFT_T(KC_J):
    case CMD_T(KC_K):
    case CMD_T(KC_D):
        return false;  // Enable key repeating.
    default:
        return true;  // Otherwise, force hold and disable key repeating.
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _SYM, _NAV, _NUM);
}

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
            return true;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
        case BASE_THUMB_L:
        case BASE_THUMB_R:
            return 0;  // Bypass Achordion for these keys.
  }

  return 800;  // Otherwise use a timeout of 800 ms.
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_Z):
        // case BASE_THUMB_L:
        case BASE_THUMB_R:
            // Immediately select the hold action when another key is pressed.
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BASE_THUMB_L:
        case BASE_THUMB_R:
            return false;
        default:
            return true;
    }
}

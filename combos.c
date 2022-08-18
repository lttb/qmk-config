#include QMK_KEYBOARD_H

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

const uint16_t PROGMEM sft_combo[]   = {BASE_F,       BASE_J,    COMBO_END};
const uint16_t PROGMEM sft_combo_l[] = {BASE_THUMB_L, BASE_F,    COMBO_END};
const uint16_t PROGMEM sft_combo_r[] = {BASE_THUMB_R, BASE_J,    COMBO_END};

const uint16_t PROGMEM cmd_combo[]   = {BASE_D,       BASE_K,    COMBO_END};
const uint16_t PROGMEM cmd_combo_l[] = {BASE_THUMB_L, BASE_D,    COMBO_END};
const uint16_t PROGMEM cmd_combo_r[] = {BASE_THUMB_R, BASE_K,    COMBO_END};

const uint16_t PROGMEM alt_combo[]   = {BASE_S,       BASE_L,    COMBO_END};
const uint16_t PROGMEM alt_combo_l[] = {BASE_THUMB_L, BASE_S,    COMBO_END};
const uint16_t PROGMEM alt_combo_r[] = {BASE_THUMB_R, BASE_L,    COMBO_END};

const uint16_t PROGMEM ctl_combo[]   = {BASE_A,       BASE_SCLN, COMBO_END};
const uint16_t PROGMEM ctl_combo_l[] = {BASE_THUMB_L, BASE_A,    COMBO_END};
const uint16_t PROGMEM ctl_combo_r[] = {BASE_THUMB_R, BASE_SCLN, COMBO_END};

const uint16_t PROGMEM sft_cmd_combo_l[] = {BASE_D,    BASE_F, COMBO_END};
const uint16_t PROGMEM sft_cmd_combo_r[] = {BASE_K,    BASE_J, COMBO_END};
const uint16_t PROGMEM sft_alt_combo_l[] = {BASE_S,    BASE_F, COMBO_END};
const uint16_t PROGMEM sft_alt_combo_r[] = {BASE_L,    BASE_J, COMBO_END};
const uint16_t PROGMEM sft_ctl_combo_l[] = {BASE_A,    BASE_F, COMBO_END};
const uint16_t PROGMEM sft_ctl_combo_r[] = {BASE_SCLN, BASE_J, COMBO_END};
const uint16_t PROGMEM cmd_ctl_combo_l[] = {BASE_A,    BASE_D, COMBO_END};
const uint16_t PROGMEM cmd_ctl_combo_r[] = {BASE_SCLN, BASE_K, COMBO_END};
const uint16_t PROGMEM cmd_alt_combo_l[] = {BASE_S,    BASE_D, COMBO_END};
const uint16_t PROGMEM cmd_alt_combo_r[] = {BASE_L,    BASE_K, COMBO_END};
const uint16_t PROGMEM ctl_alt_combo_l[] = {BASE_A,    BASE_S, COMBO_END};
const uint16_t PROGMEM ctl_alt_combo_r[] = {BASE_SCLN, BASE_L, COMBO_END};

const uint16_t PROGMEM sft_cmd_alt_combo_l[] = {BASE_S,    BASE_D, BASE_F, COMBO_END};
const uint16_t PROGMEM sft_cmd_alt_combo_r[] = {BASE_L,    BASE_K, BASE_J, COMBO_END};
const uint16_t PROGMEM sft_cmd_ctl_combo_l[] = {BASE_A,    BASE_D, BASE_F, COMBO_END};
const uint16_t PROGMEM sft_cmd_ctl_combo_r[] = {BASE_SCLN, BASE_K, BASE_J, COMBO_END};
const uint16_t PROGMEM cmd_alt_ctl_combo_l[] = {BASE_A,    BASE_S, BASE_D, COMBO_END};
const uint16_t PROGMEM cmd_alt_ctl_combo_r[] = {BASE_SCLN, BASE_L, BASE_K, COMBO_END};
const uint16_t PROGMEM sft_ctl_alt_combo_l[] = {BASE_A,    BASE_S, BASE_F, COMBO_END};
const uint16_t PROGMEM sft_ctl_alt_combo_r[] = {BASE_SCLN, BASE_L, BASE_J, COMBO_END};

const uint16_t PROGMEM sft_cmd_alt_ctl_combo_l[] = {BASE_A,    BASE_S, BASE_D, BASE_F, COMBO_END};
const uint16_t PROGMEM sft_cmd_alt_ctl_combo_r[] = {BASE_SCLN, BASE_L, BASE_K, BASE_J, COMBO_END};

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
        case SFT_COMBO_L:
        case CMD_COMBO_L:
        case ALT_COMBO_L:
        case CTL_COMBO_L:
        case CMD_ALT_COMBO_L:
        case CMD_CTL_COMBO_L:
        case SFT_CTL_COMBO_L:
        case CTL_ALT_COMBO_L:
        case CMD_ALT_CTL_COMBO_L:
        case SFT_CMD_ALT_COMBO_L:
            return true;
    }

    return false;
}

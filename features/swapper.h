/**
 * @see https://github.com/qmk/qmk_firmware/blob/592028c72423fbba9d9a507200a95e96097a90e0/users/callum/swapper.h
 */

#pragma once

#include QMK_KEYBOARD_H

// Implements cmd-tab like behaviour on a single key. On first tap of trigger
// cmdish is held and tabish is tapped -- cmdish then remains held until some
// other key is hit or released. For example:
//
//     trigger, trigger, a -> cmd down, tab, tab, cmd up, a
//     nav down, trigger, nav up -> nav down, cmd down, tab, cmd up, nav up
//
// This behaviour is useful for more than just cmd-tab, hence: cmdish, tabish.
void update_swapper(
    bool *active,
    uint16_t cmdish,
    uint16_t tabish,
    bool shifted,
    uint16_t trigger,
    uint16_t keycode,
    bool is_skip,
    keyrecord_t *record
);

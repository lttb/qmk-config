/**
 * A slightly modified version of the Callum's swapper implementation.
 * @see https://github.com/qmk/qmk_firmware/blob/592028c72423fbba9d9a507200a95e96097a90e0/users/callum/swapper.c
 */

#include "swapper.h"

void update_swapper(
    bool *active,
    uint16_t cmdish,
    uint16_t tabish,
    uint16_t trigger,
    uint16_t keycode,
    bool is_skip,
    keyrecord_t *record
) {
    if (keycode == trigger) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(cmdish);
            }
            register_code(tabish);
        } else {
            unregister_code(tabish);
            // Don't unregister cmdish until some other key is hit or released.
        }
    } else if (*active && !is_skip) {
        unregister_code(cmdish);
        *active = false;
    }
}


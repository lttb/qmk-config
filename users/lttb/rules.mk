SRC += ./features/swapper.c
# SRC += ./features/achordion.c
SRC += ./features/select_word.c
SRC += lttb.c
# SRC += combos.c

# @see https://github.com/qmk/qmk_firmware/issues/21137
INTROSPECTION_KEYMAP_C = combos.c

# Enable link time optimization
# Trade longer compile time for smaller firmware size
LTO_ENABLE = yes

# Enable audio keys and system control
EXTRAKEY_ENABLE = yes

COMBO_ENABLE = yes

CAPS_WORD_ENABLE = yes

ifeq ($(strip $(KEYBOARD)), sofle_choc)
  VIA_ENABLE = no
endif

# AUTO_SHIFT_ENABLE = no
# MOUSEKEY_ENABLE = no
# CONSOLE_ENABLE = no
# COMMAND_ENABLE = no

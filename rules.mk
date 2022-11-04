SRC += ./features/swapper.c
SRC += ./features/achordion.c
SRC += ./features/select_word.c
SRC += lttb.c
# SRC += combos.c

# Enable link time optimization
# Trade longer compile time for smaller firmware size
LTO_ENABLE = yes

# Change keymaps without flashing
# https://caniusevia.com/
VIA_ENABLE = no

# Enable audio keys and system control
EXTRAKEY_ENABLE = yes

AUTO_SHIFT_ENABLE = no

MOUSEKEY_ENABLE = yes

COMBO_ENABLE = no

CONSOLE_ENABLE = no
COMMAND_ENABLE = no

CAPS_WORD_ENABLE = yes

ifeq ($(strip $(KEYBOARD)), sofle_choc)

endif

CONVERT_TO=liatris
PIN_COMPATIBLE=promicro

# NOTE: These are already enabled by default at the revision level
ENCODER_ENABLE = no
OLED_ENABLE = no
BACKLIGHT_ENABLE = no

# RGB Matrix is enabled at the revision level,
# while we use the regular RGB underglow for testing
RGB_MATRIX_ENABLE = yes
RGBLIGHT_ENABLE = yes


EXTRAKEY_ENABLE = yes
COMBO_ENABLE = yes

# Trying to fix sleep mode issues, where the keyboard doesn't respond after waking up from deep sleep
NO_SUSPEND_POWER_DOWN = yes


# For debug?
# CONSOLE_ENABLE = yes

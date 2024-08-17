#include QMK_KEYBOARD_H
#include "keymap_russian.h"
#include "keymap_ukrainian.h"
#include "keymap_us_international.h"
#include "sendstring_us_international.h"


// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L RALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN)


// Combos:
const uint16_t PROGMEM combo_ui_esc[] = {KC_U, KC_I, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_ui_esc, KC_ESC),
};


// Layers
enum corn_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

// multi-layout https://www.reddit.com/r/olkb/comments/v8q7v3/multiple_languages_with_different_keyboard_layouts/
// https://getreuer.info/posts/keyboards/non-english/index.html
enum unicode_names {
    CN_LOWER,
    CN_UPPER,
};

const uint32_t unicode_map[] PROGMEM = {
    [CN_LOWER] = 0x00df,  // colon for lower layout
    [CN_UPPER] = 0x1e9e,  // colon for upper layout
};

#define CN_UP UP(CN_LOWER, CN_UPPER)


enum custom_keycodes {
    // layers
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    // unicode
    US_FLAG,
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

        // layers
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;

        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;

        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;

        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;

        // unicode
        case US_FLAG:  // Types US flag emoji.
            if (record->event.pressed) {
                send_unicode_string("");
                // Or if you prefer ASCII-only source files, use escape codes to
                // write the UTF-8 encoding of U+1F1FA, U+1F1F8:
                // send_unicode_string("\xf0\x9f\x87\xba\xf0\x9f\x87\xb8");
            }
            return false;

    }
    return true;
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_split_3x6_3(

    // ╭---------+---------+---------+---------+---------+---------╮ ╭---------+---------+---------+---------+---------+---------╮
         KC_BSLS ,   CN_UP ,    KC_W ,    KC_E ,    KC_R ,    KC_T ,      KC_Y ,    KC_U ,    KC_I ,    KC_O ,    KC_P , KC_BSPC ,
    // ⎟---------+---------+---------+---------+---------+---------⎟ ⎟---------+---------+---------+---------+---------+---------⎟
          KC_GRV ,  HOME_A ,  HOME_S ,  HOME_D ,  HOME_F ,    KC_G ,      KC_H ,  HOME_J ,  HOME_K ,  HOME_L ,HOME_SCLN, KC_QUOT ,
    // ⎟---------+---------+---------+---------+---------+---------⎟ ⎟---------+---------+---------+---------+---------+---------⎟
         KC_LSFT ,    KC_Z ,    KC_X ,    KC_C ,    KC_V ,    KC_B ,      KC_N ,    KC_M , KC_COMM ,  KC_DOT , KC_SLSH , KC_RSFT ,
    // ╰---------+---------+---------+---------/---------/---------/ \---------\---------\---------+---------+---------+---------╯
                                        KC_TAB , KC_LOWER,  KC_ENT ,    KC_SPC , KC_RAISE, KC_BSPC
    //                              /_________/_________/_________/   \_________\_________\_________\_

  ),

  [_LOWER] = LAYOUT_split_3x6_3(
    // ╭---------+---------+---------+---------+---------+---------╮ ╭---------+---------+---------+---------+---------+---------╮
         _______ , _______ , KC_PAST , KC_PLUS , KC_PEQL , _______ ,   _______ ,    KC_7 ,    KC_8 ,    KC_9 , _______ ,  KC_DEL ,
    // ⎟---------+---------+---------+---------+---------+---------⎟ ⎟---------+---------+---------+---------+---------+---------⎟
         _______ , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , _______ ,   _______ ,    KC_4 ,    KC_5 ,    KC_6 ,    KC_0 , _______ ,
    // ⎟---------+---------+---------+---------+---------+---------⎟ ⎟---------+---------+---------+---------+---------+---------⎟
         _______ , _______ , KC_CIRC , KC_PERC , KC_MINS , _______ ,   _______ ,    KC_1 ,    KC_2 ,    KC_3 , _______ , _______ ,
    // ╰---------+---------+---------+---------/---------/---------/ \---------\---------\---------+---------+---------+---------╯
                                       _______ , XXXXXXX , _______ ,   _______ , _______ ,  KC_DEL
    //                              /_________/_________/_________/   \_________\_________\_________\_
    //                                          ^^^^^^^

  ),

  [_RAISE] = LAYOUT_split_3x6_3(
    // ╭---------+---------+---------+---------+---------+---------╮ ╭---------+---------+---------+---------+---------+---------╮
         _______ , KC_DLR ,    KC_AT , KC_QUES , KC_EXLM , _______ ,   KC_LBRC , KC_LCBR , KC_RCBR , KC_RBRC , _______ , _______ ,
    // ⎟---------+---------+---------+---------+---------+---------⎟ ⎟---------+---------+---------+---------+---------+---------⎟
         _______ , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT ,  KC_GRV ,   KC_LEFT , KC_DOWN ,   KC_UP , KC_RGHT , KC_UNDS , _______ ,
    // ⎟---------+---------+---------+---------+---------+---------⎟ ⎟---------+---------+---------+---------+---------+---------⎟
         _______ , KC_PIPE , KC_AMPR ,   CN_UP , KC_HASH , _______ ,   KC_LABK , KC_LPRN , KC_RPRN , KC_RABK , _______ , _______ ,
    // ╰---------+---------+---------+---------/---------/---------/ \---------\---------\---------+---------+---------+---------╯
                                       _______ , _______ , _______ ,   _______ , XXXXXXX , _______
    //                              /_________/_________/_________/   \_________\_________\_________\_
    //                                                                            ^^^^^^^

  ),

  [_ADJUST] = LAYOUT_split_3x6_3(
    // ╭---------+---------+---------+---------+---------+---------╮ ╭---------+---------+---------+---------+---------+---------╮
         RGB_TOG , _______ , _______ , _______ , QK_BOOT ,  QK_RBT ,   _______ ,   KC_F7 , KC_F8   , KC_F9   , KC_F10  ,  KC_F13 ,
    // ⎟---------+---------+---------+---------+---------+---------⎟ ⎟---------+---------+---------+---------+---------+---------⎟
         _______ , RGB_HUI , RGB_SAI , RGB_VAI , RGB_MOD , RGB_SPI ,   _______ ,   KC_F4 , KC_F5   , KC_F6   , KC_F11  ,  KC_F14 ,
    // ⎟---------+---------+---------+---------+---------+---------⎟ ⎟---------+---------+---------+---------+---------+---------⎟
         _______ , RGB_HUD , RGB_SAD , RGB_VAD , RGB_RMOD, RGB_SPD ,   _______ ,   KC_F1 , KC_F2   , KC_F3   , KC_F12  ,  KC_F15 ,
    // ╰---------+---------+---------+---------/---------/---------/ \---------\---------\---------+---------+---------+---------╯
                                       _______ , XXXXXXX , _______ ,   _______ , XXXXXXX , _______
    //                              /_________/_________/_________/   \_________\_________\_________\_
    //                                         ^^^^^^^              &             ^^^^^^^

  )

};

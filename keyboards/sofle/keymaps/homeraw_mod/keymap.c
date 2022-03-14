#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
};


// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RCTL_T(KC_SCLN)


// Combos:
//const uint16_t PROGMEM combo_jk_esc[] = {MT(MOD_RSFT, KC_J), MT(MOD_RGUI, KC_K), COMBO_END};
const uint16_t PROGMEM combo_ui_esc[] = {KC_U, KC_I, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_ui_esc, KC_ESC),
};

//************************************************************************************************************************************************************

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | <--  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |  A/⎈ |  S/⌥ |  D/⌘ |  F/⇧ |   G  |-------.    ,-------|   H  |  J/⇧ |  K/⌘ |  L/⌥ |  ;/⎈ |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |  Tab |LOWER | /Enter  /       \Space \  |RAISE |  <-- |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `---------------------------''------'           '------''---------------------------'
 */

[_QWERTY] = LAYOUT(
  KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , XXXXXXX,
//  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  KC_ESC , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                      KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
  KC_TAB , HOME_A , HOME_S , HOME_D , HOME_F , KC_G   ,                      KC_H   , HOME_J , HOME_K , HOME_L , HOME_SCLN, KC_QUOT,
  KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_MUTE,    XXXXXXX, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                    XXXXXXX, XXXXXXX, KC_TAB , KC_LOWER, KC_ENT,    KC_SPC , KC_RAISE, KC_BSPC, XXXXXXX, XXXXXXX
),

//************************************************************************************************************************************************************

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |   *  |   7  |   8  |   9  |   =  | ---> |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   ⎈  |   ⌥  |   k  |   ⇧  |      |-------.    ,-------|   +  |   4  |   5  |   6  |   0  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|   -  |   1  |   2  |   3  |   .  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |//////| /Enter  /       \Space \  |      | ---> |      |      |
 *            |      |      |      |//////|/       /         \      \ |      |      |      |      |
 *            `---------------------------''-------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                      KC_PAST, KC_7   , KC_8   , KC_9   , KC_PEQL, KC_DEL  ,
  _______, KC_LCTL , KC_LALT, KC_LGUI, KC_LSFT,_______,                      KC_PLUS, KC_4   , KC_5   , KC_6   , KC_0   , _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, KC_MINS, KC_1   , KC_2   , KC_3   , KC_PDOT, _______,
                    _______, _______, _______, _______, _______,    _______, _______, KC_DEL , _______, _______
),

//************************************************************************************************************************************************************
//todo: ^ - KC_CIRC
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   @  |   %  |   ?  |   !  |   $  |                    |   [  |   {  |   }  |   ]  |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   ⎈  |   ⌥  |   ⌘  |   ⇧  |   `  |-------.    ,-------| Left | Down |  Up  | Right|   _  |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |   |  |   &  |   #  |   -  |   ~  |-------|    |-------|      |  (   |   )  |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /Enter  /       \Space \  |//////|      |      |      |
 *            |      |      |      |      |/       /         \      \ |//////|      |      |      |
 *            `---------------------------''------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,                      KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10 , _______,
  _______, KC_AT  , KC_PERC, KC_QUES, KC_EXLM, KC_DLR ,                      KC_LBRC, KC_LCBR, KC_RCBR, KC_RBRC, _______, _______,
  _______, KC_LCTL, KC_LALT, KC_LGUI, KC_LSFT, KC_GRV ,                      KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_UNDS, _______,
  _______, KC_PIPE, KC_AMPR, KC_HASH, KC_MINS, KC_TILD, _______,    _______, _______, KC_LPRN, KC_RPRN, _______, _______, _______,
                    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
),

//************************************************************************************************************************************************************

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |//////| /Enter  /       \Space \  |//////|      |      |      |
 *            |      |      |      |//////|/       /         \      \ |//////|      |      |      |
 *            `---------------------------''------'           '------''---------------------------'
 */
[_ADJUST] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
  )
};

//************************************************************************************************************************************************************

/* EMPTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /Enter  /       \Space \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `---------------------------''------'           '------''---------------------------'
 */
//[_EMPTY_LAYOUT] = LAYOUT(
//  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
//  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
//  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
//  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
//                    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
//),

//************************************************************************************************************************************************************


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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
    }
    return true;
}

#ifdef ENCODER_ENABLE

static int8_t ticks = 0;

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) { ++ticks; } else { --ticks; }
        if (abs(ticks) >= 2) {
            tap_code16(clockwise ? KC_VOLD: KC_VOLU);
            ticks = 0;
        }
    } else if (index == 1) {
        if (clockwise) { ++ticks; } else { --ticks; }
        if (abs(ticks) >= 2) {
            tap_code16(clockwise ?  KC_F1: KC_F2);
            ticks = 0;
        }
    }
    return true;
}
#endif

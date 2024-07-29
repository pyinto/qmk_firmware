/* Copyright 2022 splitkb.com <support@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/


#pragma once

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_TWINKLE
#endif


// Activate caps word by pressing Left Shift + Right Shift
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD


// Maximum time between taps of tap dances
#define TAPPING_TERM 175

// Max time between taps to prevent hold function and hold auto-repeat
#define QUICK_TAP_TERM 100

// Perform hold action if pressing a dual-role key, tapping another key and
// releasing the dual-role key within tapping term
//  This makes tap and hold keys (like Layer Tap) work better for fast typists, or for high TAPPING_TERM settings.
#define PERMISSIVE_HOLD
//#define HOLD_ON_OTHER_KEY_PRESS  // todo: should i use this over PERMISSIVE_HOLD?


// TODO: read about it https://docs.qmk.fm/features/combo#combo-term
#define COMBO_COUNT 2


// TODO: trying to solve sleep issue on mac
// Disables usb suspend check after keyboard startup. Usually the keyboard waits for the host to wake it up before
//  any tasks are performed. This is useful for split keyboards as one half will not get a wakeup call but must
//  send commands to the master.
#define NO_USB_STARTUP_CHECK


// TODO: DEPRECATED, replaced with QUICK_TAP_TERM...
//  https://docs.qmk.fm/ChangeLog/20230226#i-m-t-i
//#define TAPPING_FORCE_HOLD
//#define IGNORE_MOD_TAP_INTERRUPT

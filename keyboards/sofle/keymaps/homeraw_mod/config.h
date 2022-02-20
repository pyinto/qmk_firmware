#pragma once
#undef TAPPING_TERM

// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 250

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

//This makes tap and hold keys (like Layer Tap) work better for fast typists, or for high TAPPING_TERM settings.
#define PERMISSIVE_HOLD

#define COMBO_COUNT 2


/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/

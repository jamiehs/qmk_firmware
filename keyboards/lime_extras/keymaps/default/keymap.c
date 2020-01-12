#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _MAIN 0
#define _FN   1


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_MAIN] = KEYMAP(
    MO(_FN),        KC_B,       KC_C,        KC_D,
    KC_E,           KC_F,       KC_G,
    KC_H,                       KC_I,        KC_J,
    KC_K,                       KC_L
  ),

[_FN] = KEYMAP(
    KC_TRNS,        KC_TRNS,       KC_TRNS,        RESET,
    KC_TRNS,        KC_TRNS,       KC_TRNS,
    KC_TRNS,                       KC_TRNS,        KC_TRNS,
    KC_TRNS,                       KC_TRNS
  ),
};

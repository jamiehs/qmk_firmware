#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define BASE 0
#define FN1 1
#define FN2 2

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  OS_FULLSCREEN,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case OS_FULLSCREEN:
      if (record->event.pressed) {
        SEND_STRING(SS_LGUI(SS_TAP(X_F11))); // GUI + F11
      }
      break;
  }
  return true;
};

//Tap Dance Declarations
enum {
  TD_GRV = 0
};

//Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
  //Tap once for Esc, twice for Caps Lock
  [TD_GRV]  = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRAVE)
// Other declarations would go here, separated by commas, if you have them
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [BASE] = LAYOUT_65_with_macro(
    KC_F16,  KC_F17, TD(TD_GRV), KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  XXXXXXX, KC_BSPC, KC_DEL, \
    KC_F14,  KC_F15,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_VOLU, \
    KC_F18,  KC_F19,   MO(FN1), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_VOLD, \
    KC_F13,  KC_F14,   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                   KC_UP,   OS_FULLSCREEN, \
    LCAG(KC_LEFT),  LCAG(KC_RGHT),  KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, TG(FN1),           KC_SPC,  XXXXXXX,                   KC_RALT, KC_RCTL, MO(FN2), KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [FN1] = LAYOUT_65_with_macro(
    RESET  , _______, KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  XXXXXXX, KC_BSPC, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______, _______, _______, _______, _______,          KC_PGUP, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______,                   KC_PGDN, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, XXXXXXX,                   _______, _______, _______, _______, _______, _______
  ),

  [FN2] = LAYOUT_65_with_macro(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX, _______, RESET, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                   _______, _______, \
    _______, _______, _______, _______, _______, _______, _______,          _______, XXXXXXX,                   _______, _______, _______, LCAG(KC_LEFT), _______, LCAG(KC_RGHT)
  )
};

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN   1


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = KEYMAP_5x7(
    // left hand
    KC_NO,      KC_GRV,         KC_1,       KC_2,        KC_3,       KC_4,      KC_5,
    KC_NO,      KC_TAB,         KC_Q,       KC_W,        KC_E,       KC_R,      KC_T,
    KC_NO,      MO(_FN),        KC_A,       KC_S,        KC_D,       KC_F,      KC_G,
    KC_NO,      KC_LSHIFT,      KC_Z,       KC_X,        KC_C,       KC_V,      KC_B,
                                            KC_LEFT,     KC_UP,

                                                         KC_LCTRL,    KC_LALT,
                                                         KC_LSHIFT,   KC_LGUI,
                                                         KC_GRV,      KC_ESC,


    // right hand
    KC_6,           KC_7,       KC_8,        KC_9,       KC_0,      KC_MINS,    KC_EQL,
    KC_Y,           KC_U,       KC_I,        KC_O,       KC_P,      KC_LBRC,    KC_RBRC,
    KC_H,           KC_J,       KC_K,        KC_L,       KC_SCLN,   KC_QUOT,    KC_BSLS,
    KC_N,           KC_M,       KC_COMM,     KC_DOT,     KC_SLSH,   KC_NO,    KC_DEL,
                                KC_DOWN,     KC_RIGHT,

    KC_SPC,         KC_BSPC,
    KC_ENTER,       MO(_FN),
    KC_VOLU,        KC_VOLD
  ),

[_FN] = KEYMAP_5x7(
    // left hand
    _______,        _______,        KC_F1,         KC_F2,         KC_F3,          KC_F4,        KC_F5,
    _______,        _______,        _______,       _______,        _______,       _______,      _______,
    _______,        _______,        _______,       _______,        _______,       _______,      _______,
    _______,        _______,        _______,       _______,        _______,       _______,      _______,
                                                   RESET,          _______,

                                                                                  _______,      _______,
                                                                                  _______,      _______,
                                                                                  _______,      _______,


    // right hand
    KC_F6,          KC_F7,         KC_F8,          KC_F9,        KC_F10,       KC_F11,          KC_F12,
    _______,        _______,       KC_UP,          _______,       _______,      RGB_VAD,        RGB_VAI,
    _______,        KC_LEFT,       KC_DOWN,        KC_RIGHT,      _______,      RGB_SAD,        RGB_SAI,
    _______,        _______,       _______,        _______,       _______,      RGB_MOD,        _______,
                                   _______,        RESET,

    _______,        _______,
    KC_MPLY,        _______,
    _______,        _______
  ),
};

int savedVal = 200;

void matrix_init_user(void) { // Runs boot tasks for keyboard
    rgblight_enable();
    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_sethsv(282,0,127);
};

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
      case _FN:
        // savedVal = rgblight_get_val();
        // rgblight_sethsv_noeeprom(111,255,255);
        break;
      case _QWERTY:
        // rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
        // rgblight_sethsv_noeeprom(282,200,savedVal);
        break;
    }
  return state;
}

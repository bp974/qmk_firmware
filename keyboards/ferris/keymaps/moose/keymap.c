// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum ferris_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _SPACE,
  _RESET
};

enum ferris_tap_dances {
  TD_Q_ESC
};

enum custom_keycodes {
  ALT_TAB = SAFE_RANGE,
  COPY,
  PASTE
};

// shift
#define KC_LSHZ LSFT_T(KC_Z)
#define KC_RLSH RSFT_T(KC_SLSH)

// home row mods
#define HRL1 MT(MOD_LCTL, KC_A)
#define HRL2 MT(MOD_LALT,KC_S)
#define HRL3 MT(MOD_LGUI,KC_D)
#define HRL4 MT(MOD_LSFT, KC_F)

#define HRR1 MT(MOD_RSFT,KC_J)
#define HRR2 MT(MOD_RGUI,KC_K)
#define HRR3 MT(MOD_RALT,KC_L)
#define HRR4 MT(MOD_RCTL,KC_SCLN)

#define KC_SWAP CG_TOGG // swap control and gui on both sides
// #define HYPG HYPR_T(KC_G)
#define SPCET LT(_SPACE, KC_SPC)

// Special/layer
#define LOWER MO(_LOWER)
#define RES MO(_RESET)
#define BSPCR LT(_RAISE, KC_BSPC)

#define HYPRT MEH_T(KC_T)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case ALT_TAB:
        if (record->event.pressed) {
            // when keycode QMKBEST is pressed
            SEND_STRING(SS_DOWN(X_LGUI));
            SEND_STRING(SS_TAP(X_TAB));
            SEND_STRING(SS_UP(X_LGUI));
        } else {
        // when keycode QMKBEST is released
        }
        break;
    case COPY:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI));
            SEND_STRING(SS_TAP(X_C));
            SEND_STRING(SS_UP(X_LGUI));
        }
        break;
    case PASTE:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI));
            SEND_STRING(SS_TAP(X_V));
            SEND_STRING(SS_UP(X_LGUI));
        }
        break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* QWERTY */
    KC_Q,    KC_W,    KC_E,    KC_R,   HYPRT,            KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,
    HRL1   , HRL2,    HRL3,    HRL4,   KC_G ,           KC_H ,   HRR1,   HRR2,    HRR3,   HRR4,
    KC_LSHZ, KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,   KC_COMM, KC_DOT, KC_RLSH,
                               KC_ENT, BSPCR,            SPCET, LOWER
  ),

  [_LOWER] = LAYOUT( /* [> LOWER <] */
    KC_TAB , _______, _______, _______, _______,        _______, _______, _______, KC_MINS, KC_EQL,
    KC_CAPS, _______, _______, _______, _______,        _______, _______, _______, _______, KC_QUOT,
    KC_GRV,  _______, _______, _______, _______,        _______, _______, KC_LBRC, KC_RBRC, KC_BSLS,
                             XXXXXXX, KC_DELETE,        RES, _______
  ),

  [_RAISE] = LAYOUT( /* [> RAISE <] */
    KC_ESC,   _______, _______, _______, _______,        _______, _______, _______, _______, _______,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    _______, _______, COPY ,   PASTE, _______,           _______, _______, _______, KC_F11,  KC_F12,
                              XXXXXXX, KC_LSFT,          _______,_______
  ),

  [_SPACE] = LAYOUT( /* [> SPACE <] */
    KC_1,       KC_2,    KC_3,    KC_4,    KC_5,         KC_6,    KC_7,   KC_8,    KC_9,    KC_0,
    _______, _______, _______, _______, KC_PGUP,         KC_HOME, KC_LEFT,  KC_UP , KC_DOWN, KC_RIGHT,
    _______, _______, _______, _______, KC_PGDN,         KC_END , _______, _______, _______, _______,
                               XXXXXXX, KC_LSFT,         _______, _______
  ),

  [_RESET] = LAYOUT(
    _______, _______, _______, _______, _______,         _______,   _______, _______, _______, _______,
    _______, _______, _______, _______, _______,         _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,         _______, _______, _______, _______, RESET,
                               _______, CG_TOGG,         _______, _______
  ),
};

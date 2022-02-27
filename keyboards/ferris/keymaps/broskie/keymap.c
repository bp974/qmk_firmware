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
  _SPECL,
  _NUM
};

enum ferris_tap_dances {
  TD_Q_ESC
};

// control
#define KC_CTLA LCTL_T(KC_A)
#define KC_CTSC RCTL_T(KC_SCLN)
// shift
#define KC_LSHZ LSFT_T(KC_Z)
#define KC_LSHD LSFT_T(KC_D)
#define KC_RLSH RSFT_T(KC_SLSH)
#define KC_RSHK RSFT_T(KC_K)
// alt/option
#define KC_ALTS LALT_T(KC_S)
#define KC_ALTL RALT_T(KC_L)
// gui/command
#define KC_GUIF LGUI_T(KC_F)
#define KC_GUIJ RALT_T(KC_J)
// Special/layer
#define KC_SPL1 LT(_LOWER, KC_SPC)
#define KC_BSL2 LT(_RAISE, KC_BSPC)
#define KC_SWAP CG_TOGG // swap control and gui on both sides

// #define KC_GUTA GUI_T(KC_TAB)
// #define KC_CLGV CTL_T(KC_GRV)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* QWERTY */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,            KC_Y,    KC_U,   KC_I,    KC_O,   KC_P,
    KC_CTLA, KC_ALTS, KC_LSHD, KC_GUIF, KC_G,            KC_H,    KC_GUIJ,KC_RSHK, KC_ALTL,KC_CTSC,
    KC_LSHZ, KC_X,    KC_C,    KC_V,    KC_B,            KC_N,    KC_M,   KC_COMM, KC_DOT, KC_RLSH,
                                    KC_MEH, KC_SPL1, KC_BSL2, KC_TAB
  ),

  [_LOWER] = LAYOUT( /* [> LOWER <] */
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    _______, KC_HOME, LSFT_T(KC_END), KC_PGUP, KC_PGDN,  KC_MINS, KC_EQL,  KC_LPRN, KC_RPRN, KC_QUOT,
    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT, KC_MPLY,         KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_ENT,
                                    KC_SWAP, _______, KC_DELETE, KC_GESC  
  ),

  [_RAISE] = LAYOUT( /* [> RAISE <] */
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    KC_TAB,  KC_F11,  LSFT_T(KC_F12), _______, _______,  KC_BSLS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    _______, _______, _______, _______, _______,         KC_PIPE, KC_GRV, KC_LBRC, KC_RBRC, KC_ENT,
                                    _______, TT(_SPECL), _______, TT(_NUM)
  ),

  [_SPECL] = LAYOUT( /* [> SPECL <] */
    TG(_SPECL), _______, _______, _______, _______,      _______, _______, _______, _______, _______,
    KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_MS_BTN1,         _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,         _______, _______, _______, _______, RESET,
                                    _______, _______, _______, _______
  ),

  [_NUM] = LAYOUT( /* [> NUM <] */
    TG(_NUM), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, KC_7, KC_8, KC_9, KC_MINS,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, KC_4, KC_5, KC_6, KC_DOT,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, KC_1, KC_2, KC_3, KC_0,
                                    XXXXXXX, KC_SPL1, KC_BSL2, XXXXXXX
  )
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};

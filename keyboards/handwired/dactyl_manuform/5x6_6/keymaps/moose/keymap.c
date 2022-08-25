#include QMK_KEYBOARD_H

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _MOOSE 3
#define _SPACE 4

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)

#define HRL1 MT(MOD_LCTL, KC_A)
#define HRL2 MT(MOD_LALT,KC_S)
#define HRL3 MT(MOD_LGUI,KC_D)
#define HRL4 MT(MOD_LSFT, KC_F)

#define HRR1 MT(MOD_RSFT,KC_J)
#define HRR2 MT(MOD_RGUI,KC_K)
#define HRR3 MT(MOD_RALT,KC_L)
#define HRR4 MT(MOD_RCTL,KC_SCLN)

#define TBSPC MT(MOD_LGUI,KC_BSPC)
#define T_DEL MT(MOD_LALT,KC_DEL)

// Layer switches
// #define EMODT LT(_MOOSE, KC_E)
#define CAPST LT(_MOOSE, KC_CAPS)
// #define RMODT LT(_RAISE, KC_R)
#define SPCET LT(_MOOSE, KC_SPC)

#define MEHT MEH_T(KC_T)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6(
        KC_EQL , KC_1  , KC_2  , KC_3  , KC_4 , KC_5  ,                         KC_6  ,  KC_7  ,  KC_8  ,  KC_9  , KC_0  ,  KC_MINS,
        KC_TAB , KC_Q  , KC_W  , KC_E  , KC_R , MEHT  ,                         KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  , KC_P  ,  KC_BSLS,
        CAPST  , HRL1  , HRL2  , HRL3  , HRL4 , KC_G  ,                         KC_H  ,  HRR1  ,  HRR2  ,  HRR3  , HRR4  ,  KC_QUOT,
        KC_LSFT, KC_Z  , KC_X  , KC_C  , KC_V , KC_B  ,                         KC_N  ,  KC_M  , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                 KC_GRV, TG(LOWER),KC_LEFT,KC_RGHT,                                          KC_UP, KC_DOWN ,KC_LBRC, KC_RBRC,

                                       KC_ESC, MEH(KC_Q),                      MEH(KC_R), MEH(KC_0),
                                               MEH(KC_W),                      MEH(KC_Y),
                                  TBSPC, T_DEL,MEH(KC_E),                      MEH(KC_A), KC_ENTER, SPCET
    ),

    [_LOWER] = LAYOUT_5x6(
        _______,_______,_______,_______,_______,_______,                        _______, KC_NUM, KC_PEQL,KC_PSLS,KC_PAST,_______,
        _______,_______,_______,_______,_______,_______,                        _______, KC_P7 ,  KC_P8 , KC_P9 ,KC_PMNS,_______,
        _______,_______,_______,_______,_______,_______,                        _______, KC_P4 ,  KC_P5 , KC_P6 ,KC_PPLS,_______,
        _______,_______,_______,_______,_______,_______,                        _______, KC_P1 ,  KC_P2 , KC_P3 ,KC_PENT,_______,
                _______,_______,_______,_______,                                         _______, KC_P0 , KC_PDOT,KC_PENT,

                                        _______,_______,                        _______,TT(_QWERTY),
                                                _______,                        _______,
                                _______,_______,_______,                        _______,_______,_______
    ),

    [_RAISE] = LAYOUT_5x6(
          _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
          _______,_______,_______,_______,_______,_______,                        _______,KC_LCBR,KC_RCBR,KC_MINS,KC_EQL ,_______,
          _______,_______,_______ ,_______,_______,_______,                       _______,KC_LPRN,KC_RPRN,KC_BSLS,_______,_______,
          _______,_______,_______,_______,_______,_______,                        _______,KC_LABK,KC_RABK,_______,KC_GRV ,_______,
                  _______,_______,_______,_______,                                        _______,_______,_______ ,_______,

                                          _______,_______,                        _______,_______,
                                                  _______,                        _______,
                                  _______,_______,_______,                        _______,_______, _______
    ),

    [_MOOSE] = LAYOUT_5x6(
          KC_ESC , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 ,                        KC_F6  , KC_F7 , KC_F8 , KC_F9 ,KC_F10 ,KC_F11 ,
          KC_F12 ,_______,KC_MUTE,KC_VOLD,KC_VOLU,_______,                        _______,_______,KC_UP,_______,_______,_______,
          _______,_______,KC_MPLY,KC_MPRV,KC_MNXT,_______,                        KC_HOME,KC_LEFT,KC_DOWN,KC_RIGHT,_______,KC_END,
          _______,_______,_______,_______,_______,_______,                        _______,KC_PGUP,_______,_______,_______,_______,
                  _______,_______,_______,_______,                                        KC_PGDN,_______,_______,_______,

                                          _______,_______,                        _______,_______,
                                                  _______,                        _______,
                                  _______,_______,_______,                        _______,_______, _______
    ),

    [_SPACE] = LAYOUT_5x6(
          _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
          _______,_______,_______,_______,_______,_______,                        _______,_______,_______,_______,_______,_______,
          KC_GRV ,  KC_1 ,  KC_2 ,  KC_3 ,  KC_4 ,  KC_5 ,                         KC_6  ,  KC_7 ,  KC_8 ,  KC_9 , KC_0  ,_______,
          _______,_______,_______,_______,_______,_______,                        _______,KC_BSPC, KC_DEL,_______,_______,_______,
                  _______,_______,_______,_______,                                        _______,_______,_______ ,_______,

                                          _______,_______,                        _______,_______,
                                                  _______,                        _______,
                                  KC_LSFT,_______,_______,                        _______,_______, _______
    )
};

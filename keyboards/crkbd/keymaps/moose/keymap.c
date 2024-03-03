/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

enum corny_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _SYMBOL
};

enum corny_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  SYMBOL,
  SELEND,
  SELHOME,
  LOCK
};

// home row mods
#define CTL_A MT(MOD_LCTL, KC_A)
#define ALT_S MT(MOD_LALT, KC_S)
#define GUI_D MT(MOD_LGUI, KC_D)
#define LSF_F MT(MOD_LSFT, KC_F)

#define LSF_J MT(MOD_RSFT, KC_J)
#define GUI_K MT(MOD_RGUI, KC_K)
#define ALT_L MT(MOD_RALT, KC_L)
#define CTL_SC MT(MOD_RCTL, KC_SCLN)
#define MINS_ADJUST LT(_ADJUST, KC_MINS)

#define HYPRT MEH_T(KC_T)
#define EQ_RLSH RSFT_T(KC_EQL)

//#define MEH_TAB MT(KC_MEH, KC_TAB)
#define SPC_RSE LT(_RAISE, KC_SPC)
#define TAB_SYMB LT(_SYMBOL, KC_TAB)
#define BSCP_LOWR LT(_LOWER, KC_BSPC)

#define LOWER TT(_LOWER)
#define RAISE MO(_RAISE)
//#define TT_LOWER TT(_LOWER)
//#define ADJUST MO(_ADJUST)

#define MAC CG_TOGG // swap control and gui on both sides

  const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_EQL,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P, MINS_ADJUST,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      TAB_SYMB,   CTL_A,   ALT_S,   KC_D,   LSF_F, KC_G,                         KC_H,   LSF_J,   KC_K,   ALT_L, CTL_SC,  KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,                         KC_N,  KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         RAISE ,KC_LGUI, BSCP_LOWR,     SPC_RSE,  KC_ENT, LOWER
                                      //`--------------------------'  `--------------------------'

  ),


    [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______, _______, _______, _______,  _______,  _______,                    XXXXXXX, XXXXXXX,  KC_UP,  XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, KC_LEFT, SELHOME, SELEND, KC_RIGHT,                     XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, KC_HOME, KC_END, _______,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                        _______, _______, KC_DEL,      _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),


  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,   KC_MINS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_GRV, _______, _______, _______, _______, KC_VOLU,                      _______, _______, _______, _______, _______,  KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, _______, KC_MPLY, KC_MPRV, KC_MNXT, KC_VOLD,                      _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LSFT, _______, _______,   _______, _______, _______
                                      //`--------------------------'  `--------------------------'
    ),


  [_SYMBOL] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     _______,   KC_F2,  KC_F3,   KC_F4,  KC_F5,    KC_F6,                       _______, KC_LBRC, KC_RBRC, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,                       KC_HOME, KC_LPRN, KC_RPRN, _______, _______, KC_END,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     _______, KC_F12, _______, _______, _______, _______,                       _______, KC_LT,    KC_GT, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         _______, _______, _______,   _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),


  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      MAC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LOCK, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, KC_SLEP,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QK_RBT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,   _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8
#define L_SYMBOL 16

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Qwerty"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_SYMBOL:
            oled_write_ln_P(PSTR("Symbol"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '
};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
  if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
    (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) {
      keycode = keycode & 0xFF;
  }
  if (keycode < 60) {
      name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
     switch (keycode) {
        case SELEND:
            if (record->event.pressed) {
                tap_code16(LSFT(KC_END));
            }
            break;

        case SELHOME:
            if (record->event.pressed) {
                tap_code16(LSFT(KC_HOME));
            }
            break;
        case LOCK:
            if (record->event.pressed) {
                tap_code16(LCTL(LCMD(KC_Q)));
            }
            break;
    }

    if (record->event.pressed) {
        set_keylog(keycode, record);
    }
  return true;
}
#endif // OLED_ENABLE

#ifdef RGBLIGHT_ENABLE
    static uint16_t key_timer; // timer to track the last keyboard activity
    static void refresh_rgb(void); // refreshes the activity timer and RGB, invoke whenever activity happens
    static void check_rgb_timeout(void); // checks if enough time has passed for RGB to timeout
    bool is_rgb_timeout = false; // store if RGB has timed out or not in a boolean


    void refresh_rgb() {
    key_timer = timer_read(); // store time of last refresh
    if (is_rgb_timeout) { // only do something if rgb has timed out
        print("Activity detected, removing timeout\n");
        is_rgb_timeout = false;
        rgblight_wakeup();
    }
    }

    void check_rgb_timeout() {
    if (!is_rgb_timeout && timer_elapsed(key_timer) > RGBLIGHT_TIMEOUT) {
        rgblight_suspend();
        is_rgb_timeout = true;
    }
    }


    /* Then, call the above functions from QMK's built in post processing functions like so */

    /* Runs at the end of each scan loop, check if RGB timeout has occured */
    void housekeeping_task_user(void) {
    #ifdef RGBLIGHT_TIMEOUT
    check_rgb_timeout();
    #endif

    /* rest of the function code here */
    }

    /* Runs after each key press, check if activity occurred */
    void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    #ifdef RGBLIGHT_TIMEOUT
    if (record->event.pressed) refresh_rgb();
    #endif

    /* rest of the function code here */
    }

    /* Runs after each encoder tick, check if activity occurred */
    void post_encoder_update_user(uint8_t index, bool clockwise) {
    #ifdef RGBLIGHT_TIMEOUT
    refresh_rgb();
    #endif

    /* rest of the function code here */
    }
#endif // RGBLIGHT_ENABLE

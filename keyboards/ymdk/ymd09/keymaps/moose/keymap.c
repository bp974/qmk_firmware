#include QMK_KEYBOARD_H

#define RGBMOD LT(1, HYPR(KC_P8))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //add hypr hotkeys to other nmums

  [0] = LAYOUT(KC_VOLU, HYPR(KC_P0), HYPR(KC_P9),
               KC_VOLD, RGBMOD , HYPR(KC_P7),
               KC_MPLY, KC_MPRV, KC_MNXT),

  [1] = LAYOUT(RGB_RMOD, RGB_TOG, RGB_MOD,
               RGB_HUI , KC_TRNS, RGB_VAI,
               RGB_HUD , RGB_M_P, RGB_VAD),

};

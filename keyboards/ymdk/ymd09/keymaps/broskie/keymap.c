#include QMK_KEYBOARD_H
#define _NORM 0
#define _LOWER 1

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

enum custom_keycodes {
  ALT_TAB = SAFE_RANGE,
  FAST_PASS
};

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
      case FAST_PASS:
          if (record->event.pressed) {        
              SEND_STRING("SecretPass");       
          }
          break;
  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    //add hypr hotkeys to other nmums

  [_NORM] = LAYOUT(MEH(KC_0), MEH(KC_8), MEH(KC_9),
               KC_VOLU, LT(1, KC_MPLY) , ALT_TAB,
               KC_VOLD, KC_MPRV, FAST_PASS),

  [_LOWER] = LAYOUT(RGB_RMOD, RGB_TOG, RGB_MOD,
               RGB_HUI , KC_TRNS, RGB_VAI,
               RGB_HUD , RGB_M_P, RGB_VAD),

};

/* Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
 * Copyright 2019 Sunjun Kim
 * Copyright 2020 Ploopy Corporation
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define LAYER_HOLD_LIMIT 400  //hold for less than 400ms to toggle RGB

enum custom_keycodes {
    LAYER_TAP = SAFE_RANGE,  //custom keycode, name it what you want
    COPY,
    PASTE,
};

uint16_t layer_hold_timer = 0;  //timer variable

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( KC_BTN1, KC_BTN3, KC_BTN2, KC_BTN4, LAYER_TAP),
    [1] = LAYOUT( COPY, KC_ENT, PASTE, _______, _______ ),
    [2] = LAYOUT( _______, _______, _______, _______, _______ ),
    [3] = LAYOUT( _______, _______, _______, _______, _______ ),
    [4] = LAYOUT( _______, _______, _______, _______, _______ ),
    [5] = LAYOUT( _______, _______, _______, _______, _______ ),
    [6] = LAYOUT( _______, _______, _______, _______, _______ ),
    [7] = LAYOUT( _______, _______, _______, _______, _______ )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LAYER_TAP:
            if (record->event.pressed) {        //when RGB_MACRO is pressed
                layer_hold_timer = timer_read();  //  mark the time it was pressed
                layer_on(1);                //  go to (layer)
            } else {                            //when RGB_MACRO is released
                layer_off(1);               //  leave (layer)
                if (timer_elapsed(layer_hold_timer) < LAYER_HOLD_LIMIT)
                    tap_code16(KC_BTN5);        //  toggle RGB if held less than RGB_HOLD_LIMIT ms
            }
            break;

        case COPY:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("c"));
            }
            break;
        case PASTE:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTRL("v"));
            }
            break;
        default:
            return true;
    }
    return true;
};

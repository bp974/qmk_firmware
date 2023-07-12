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
#define LAYER_HOLD_LIMIT 200

// NOTE: LT() functions only work with basic keys, aka not mouse buttons

enum custom_keycodes {
    COPY = SAFE_RANGE,
    PASTE,
    MID_ENT,  // enter on long press, middle click elsewhere
    FAST_PASS, // fast pass used for work on long press, right click elsewhere
};

uint16_t layer_hold_timer = 0;  //timer variable

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( KC_BTN1, MID_ENT, KC_BTN2, COPY, PASTE),
    [1] = LAYOUT( _______, _______, _______, _______, _______ ),
    [2] = LAYOUT( _______, _______, _______, _______, _______ ),
    [3] = LAYOUT( _______, _______, _______, _______, _______ ),
    [4] = LAYOUT( _______, _______, _______, _______, _______ ),
    [5] = LAYOUT( _______, _______, _______, _______, _______ ),
    [6] = LAYOUT( _______, _______, _______, _______, _______ ),
    [7] = LAYOUT( _______, _______, _______, _______, _______ )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COPY:
            if (record->event.pressed) {        
                layer_hold_timer = timer_read();              
            } else {                           
                if (timer_elapsed(layer_hold_timer) > LAYER_HOLD_LIMIT) {
                    SEND_STRING(SS_LCTRL("c"));  
                } else {
                    tap_code16(KC_BTN4);
                }
            }
            break;
        case PASTE:
            if (record->event.pressed) {        
                layer_hold_timer = timer_read();              
            } else {                           
                if (timer_elapsed(layer_hold_timer) > LAYER_HOLD_LIMIT) {
                    SEND_STRING(SS_LCTRL("v"));  
                } else {
                    tap_code16(KC_BTN5);
                }
            }
            break;
        case MID_ENT:
            if (record->event.pressed) {        
                layer_hold_timer = timer_read();              
            } else {                           
                if (timer_elapsed(layer_hold_timer) > LAYER_HOLD_LIMIT) {
                    tap_code16(KC_ENT);
                } else {
                    tap_code16(KC_BTN3);
                }
            }
            break;
        default:
            return true;
    }
    return true;
};

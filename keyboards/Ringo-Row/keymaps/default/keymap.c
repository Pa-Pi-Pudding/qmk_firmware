/* Copyright 2020 Pa_Pi_Pudding
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_9,   KC_F10,   KC_11,    KC_12,   KC_NO,\
        KC_GRAVE,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINUS,   KC_EQUAL,   KC_BSPACE,\
        KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRACKET,   KC_RBRACKET, KC_ENTER,  KC_NO, \
        KC_LCTRL,   KC_A1,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCOLON,   KC_QUOTE,   KC_NO,\
        KC_LSHIFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMMA,   KC_DOT,   KC_SLASH,   KC_BSLASH,   KC_LSHIFT,   KC_NO,\
        KC_LALT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LGUI,   KC_NO,   KC_SPACE,   KC_RGUI,  KC_RALT,   MO(_FN),   KC_NO,   KC_NO,   KCNO,   KC_NO\
    ),
    [_FN] = LAYOUT(
        KC_ESC,   KC_BRMD,   KC_BRMU,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MEDIA_FAST_FORWARD,   KC_PAUS,   KC_MEDIA_FAST_FOWRARD,   KC__MUTE,   KC__VOLUP,    KC__VOLDOWN,   KC_NO,\
        KC_GRAVE,   KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINUS,   KC_EQUAL,   KC_BSPACE,\
        KC_TAB,   KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRACKET,   KC_RBRACKET, KC_ENTER,  KC_NO, \
        KC_LCTRL,   KC_A1,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCOLON,   KC_QUOTE,   KC_NO,\
        KC_LSHIFT,   KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMMA,   KC_DOT,   KC_SLASH,   KC_BSLASH,   KC_LSHIFT,   KC_NO,\
        KC_LALT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_LGUI,   KC_NO,   KC_SPACE,   KC_RGUI,  KC_RALT,   MO(_BASE),   KC_NO,   KC_NO,   KCNO,   KC_NO\
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

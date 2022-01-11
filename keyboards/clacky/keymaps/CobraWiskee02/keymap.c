/* Copyright 2021 CobraWiskee
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

// Helpful defines
#define F9 KC_F9
#define F11 KC_F11
#define KC_LGUI KC_LGUI
#define G(kc) LGUI(kc)
#define KC_ENT KC_ENTER
#define KC_TAB KC_TAB
#define KC_LEFT KC_LEFT
#define KC_RGHT KC_RIGHT
#define KC_MUTE KC_AUDIO_MUTE
#define KC_MPLY KC_MEDIA_PLAY_PAUSE
#define KC_VOLU KC_AUDIO_VOL_UP
#define KC_VOLD KC_AUDIO_VOL_DOWN
#define GRAVE_MODS  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

//Alt+Tab declarations
//bool is_alt_tab_active = false;
//uint16_t alt_tab_timer = 0;

// Defines names for use in layer keycodes and the keymap
#define _AL 0
#define _BL 1

// Tap Dance declarations
enum {
    ANS_END,
    AUD_TOG,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for CTRL+A, twice for CTRL+E
    [ANS_END] = ACTION_TAP_DANCE_DOUBLE(LALT(KC_A), LALT(KC_E)),
    [AUD_TOG] = ACTION_TAP_DANCE_DOUBLE(LCTL(KC_F9), LCTL(KC_F11)),
};


// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_AL] = LAYOUT( \
        LCTL(G(KC_LEFT)),    LCTL(G(KC_RGHT)),    KC_TRNS,    TD(AUD_TOG), \
        KC_MPLY,    KC_MUTE,    LGUI(KC_D),    KC_TRNS, \
                     TD(ANS_END) \
    ),
  [_BL] = LAYOUT( \
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, \
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, \
                     KC_TRNS \
    )
};

/* The encoder_update_user is a function.
 * It'll be called by QMK every time you turn the encoder.
 *
 * The index parameter tells you which encoder was turned. If you only have
 * one encoder, the index will always be zero.
 *
 * The clockwise parameter tells you the direction of the encoder. It'll be
 * true when you turned the encoder clockwise, and false otherwise.
 */
bool encoder_update_kb(uint8_t index, bool clockwise) {

if (clockwise) {
      tap_code(KC_VOLU);
 } else {
      tap_code(KC_VOLD);
}
 return true;
};
  /* You can copy the code and change the index for every encoder you have. Most
     keyboards will only have two, so this piece of code will suffice. */
//} else if (index == 1) { /* Second encoder */
//if (clockwise) {
//  tap_code(KC_UP);
// } else {
//  tap_code(KC_DOWN);


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
#define KC_ENT KC_ENTER
#define KC_LSFT KC_LSHIFT
#define KC_LCTL KC_LCTRL
#define KC_PSCR KC_PSCREEN
#define F9 KC_F9
#define F11 KC_F11
#define KC_LGUI KC_LGUI
#define G(kc) LGUI(kc)
#define KC_ENT KC_ENTER
#define KC_TAB KC_TAB
#define KC_LEFT KC_LEFT
#define KC_RGHT KC_RIGHT
#define KC_DOWN KC_DOWN
#define KC_MUTE KC_AUDIO_MUTE
#define KC_MPLY KC_MEDIA_PLAY_PAUSE
#define KC_VOLU KC_AUDIO_VOL_UP
#define KC_VOLD KC_AUDIO_VOL_DOWN
#define KC_APP KC_APPLICATION
#define GRAVE_MODS  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT)|MOD_BIT(KC_LGUI)|MOD_BIT(KC_RGUI)|MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

//Keypad Definitions
#define X_PSLS X_KP_SLASH
#define X_PAST X_KP_ASTERISK
#define X_PMNS X_KP_MINUS
#define X_PPLS X_KP_PLUS
#define X_PENT X_KP_ENTER
#define X_P1   X_KP_1
#define X_P2   X_KP_2
#define X_P3   X_KP_3
#define X_P4   X_KP_4
#define X_P5   X_KP_5
#define X_P6   X_KP_6
#define X_P7   X_KP_7
#define X_P8   X_KP_8
#define X_P9   X_KP_9
#define X_P0   X_KP_0
#define X_PDOT X_KP_DOT
#define X_PEQL X_KP_EQUAL
#define X_PCMM X_KP_COMMA

/* Mouse Keys */
#define X_MS_U X_MS_UP
#define X_MS_D X_MS_DOWN
#define X_MS_L X_MS_LEFT
#define X_MS_R X_MS_RIGHT
#define X_BTN1 X_MS_BTN1
#define X_BTN2 X_MS_BTN2
#define X_BTN3 X_MS_BTN3
#define X_BTN4 X_MS_BTN4
#define X_BTN5 X_MS_BTN5
#define X_WH_U X_MS_WH_UP
#define X_WH_D X_MS_WH_DOWN
#define X_WH_L X_MS_WH_LEFT
#define X_WH_R X_MS_WH_RIGHT
#define X_ACL0 X_MS_ACCEL0
#define X_ACL1 X_MS_ACCEL1
#define X_ACL2 X_MS_ACCEL2

// Defines names for use in layer keycodes and the keymap
#define _AL 0
#define _BL 1
#define _CL 2

// Tap Dance declarations
enum {
    SCR_SHT,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for capture region and twice for screen
    [SCR_SHT] = ACTION_TAP_DANCE_DOUBLE(KC_PSCR, LCTL(KC_PSCR)),
};

enum custom_keycodes {
    ANSLT = SAFE_RANGE,
    ENDLT,
    PSTVAL,
    FLXRST,
    ZWJ
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case ANSLT:
        if (record->event.pressed) {
            // when keycode ANSLT is pressed
            SEND_STRING(SS_LALT("a"));
            layer_move(_BL);
        } else {
            // when keycode ANSLT is released
        }
        break;

    case ENDLT:
        if (record->event.pressed) {
            // when keycode ENDLT is pressed
            SEND_STRING(SS_LALT("e"));
            layer_move(_AL);
        } else {
            // when keycode ENDLT is released
        }
        break;

    case PSTVAL:
        if (record->event.pressed) {
            // when keycode ENDLT is pressed
           SEND_STRING(SS_LALT("hvv"));
        } else {
            // when keycode ENDLT is released
        }
        break;

    //Resets printer in FLEX
    case FLXRST:
        if (record->event.pressed) {
        //End Writer
        SEND_STRING(SS_TAP(X_APP)SS_DELAY(100)SS_TAP(X_E)SS_DELAY(100)
        //Vary Off
        SS_TAP(X_APP)SS_DELAY(100)SS_TAP(X_DOWN)SS_DELAY(100)SS_TAP(X_DOWN)SS_DELAY(100)SS_TAP(X_DOWN)SS_DELAY(100)SS_TAP(X_DOWN)SS_DELAY(100)SS_TAP(X_DOWN)SS_DELAY(100)SS_TAP(X_DOWN)SS_DELAY(100)SS_TAP(X_DOWN)SS_DELAY(100)SS_TAP(X_ENT)SS_DELAY(100)
        //Vary On
        SS_TAP(X_APP)SS_DELAY(100)SS_TAP(X_DOWN)SS_DELAY(100)SS_TAP(X_DOWN)SS_DELAY(100)SS_TAP(X_DOWN)SS_DELAY(100)SS_TAP(X_DOWN)SS_DELAY(100)SS_TAP(X_DOWN)SS_DELAY(100)SS_TAP(X_DOWN)SS_DELAY(100)SS_TAP(X_ENT)SS_DELAY(100)
        //Start Writer
        SS_TAP(X_APP)SS_DELAY(100)SS_TAP(X_S));
        } else {
        }
        break;

    case ZWJ: // Inserts a Zero Width Joiner to breakup hyperlinks
        if (record->event.pressed) {
            SEND_STRING(SS_LALT(SS_TAP(X_KP_8)SS_TAP(X_KP_2)SS_TAP(X_KP_0)SS_TAP(X_KP_3)));        
        } else {
        }
        break;
      }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_AL] = LAYOUT( \
        LM(_CL, MOD_LALT),    G(KC_UP),    LGUI(KC_D),    TD(SCR_SHT), \
        MO(_BL),    (LALT(KC_Q)),    KC_MUTE,    KC_MPLY, \
                     LALT(KC_A) \
    ),
  [_BL] = LAYOUT( \
        LCTL(KC_Z),   LCTL(KC_C),    LCTL(KC_V),    PSTVAL, \
        KC_TRNS,    KC_A,    KC_LCTL,    KC_LSFT, \
                     FLXRST \
    ),
  [_CL] = LAYOUT( \
        KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS, \
        KC_TRNS,   KC_TRNS,    KC_TRNS,    KC_TRNS, \
                     KC_E \
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
  if (IS_LAYER_ON(_CL)) {
    if (clockwise) {
    tap_code16(KC_TAB);
    } else {
    tap_code16(S(KC_TAB));
    }
  } else { // on other layers VOL contril   
  if (IS_LAYER_ON(_BL)) {
    if (clockwise) {
    tap_code16(LCTL(KC_RGHT));
    } else {
    tap_code16(LCTL(KC_LEFT));
    }
  } else {
   if (clockwise){
      tap_code(KC_VOLU);
    } else{
      tap_code(KC_VOLD);
    }
  }
 }
 return true;
};

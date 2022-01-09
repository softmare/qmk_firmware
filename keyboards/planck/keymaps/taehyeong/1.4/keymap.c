/* Copyright 2015-2021 Jack Humbert
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


enum planck_layers {
  _COLEMAK,
  _QWERTY,
  _SPCHAR,
  _NUMBER,
  _SPECIAL,
  _MOVE,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE
};

#define SPCHAR MO(_SPCHAR)
#define NUMBER MO(_NUMBER)
#define MOVE MO(_MOVE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT_planck_1x2uC(KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, KC_SCLN, QWERTY, LT(5,KC_ESC), LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_D, KC_H, LCTL_T(KC_N), LSFT_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), LT(5,KC_ENT), MOVE, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, MOVE, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, SPCHAR, KC_SPC, NUMBER, KC_BSPC, KC_NO, KC_NO, BL_STEP),
	[1] = LAYOUT_planck_1x2uC(KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_SCLN, KC_TRNS, LT(5,KC_ESC), LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G, KC_H, LCTL_T(KC_J), LSFT_T(KC_K), LALT_T(KC_L), LGUI_T(KC_P), LT(5,KC_ENT), MOVE, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, MOVE, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, SPCHAR, KC_SPC, NUMBER, KC_BSPC, KC_NO, KC_NO, BL_STEP),
	[2] = LAYOUT_planck_1x2uC(KC_TRNS, KC_PIPE, KC_AMPR, KC_LBRC, KC_RBRC, KC_DLR, KC_HASH, KC_PLUS, KC_LT, KC_GT, KC_DQUO, KC_RALT, KC_TRNS, KC_LCBR, KC_RCBR, KC_LPRN, KC_RPRN, KC_EXLM, KC_QUES, KC_MINS, KC_UNDS, KC_EQL, KC_QUOT, KC_TRNS, KC_TRNS, KC_GRV, KC_TILD, KC_COLN, KC_SCLN, KC_ASTR, KC_SLSH, KC_PERC, KC_BSLS, KC_AT, KC_CIRC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[3] = LAYOUT_planck_1x2uC(KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_TRNS, KC_TRNS, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_PDOT, KC_MINS, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS, KC_TRNS, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_DEL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
	[4] = LAYOUT_planck_1x2uC(RGB_VAD, RGB_VAI, KC_MPRV, KC_VOLU, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_P7, KC_P8, KC_P9, KC_PMNS, RGB_SAD, RGB_SAI, RGB_TOG, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_P4, KC_P5, KC_P6, KC_ENT, KC_TRNS, RGB_HUD, RGB_HUI, RGB_MOD, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P1, KC_P2, KC_P3, KC_PAST, RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_P0, KC_PPLS, KC_PDOT, KC_PSLS),
	[5] = LAYOUT_planck_1x2uC(KC_TRNS, KC_BTN5, KC_WH_D, KC_MS_U, KC_WH_U, KC_BTN4, KC_TRNS, KC_PGDN, KC_UP, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R, KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, KC_END, KC_TRNS, KC_TRNS, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_TRNS, KC_TRNS, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, KC_TRNS, KC_ACL0, KC_ACL1, KC_ACL2, KC_TRNS, KC_TRNS, KC_BTN1, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _SPCHAR, _NUMBER, _SPECIAL);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        layer_invert(_QWERTY);
        tap_code(KC_RALT);
      }
      return false;
      break;
  }
  return true;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_S): case LSFT_T(KC_D):
            return TAPPING_TERM - 50;
        default:
            return TAPPING_TERM;
    }
}


// https://m.blog.naver.com/hansin_k/220965689128
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

enum planck_layers {
    _COLEMAK, _QWERTY, _RAISE, _LOWER, _LEFT, _RIGHT, _VIRT, _LMOVE, _RMOVE, _FUNCTION, // Default, Programming, Both-hand Layer set
    _GAME, _GAME_LT}; // No Auto Shift, Qwerty, Left-Major Layer set

enum planck_keycodes { TG_KR = SAFE_RANGE, VIMCP };

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define LEFT MO(_LEFT)
#define RIGHT MO(_RIGHT)
#define LMOVE(key) LT(_LMOVE, key)
#define RMOVE(key) LT(_RMOVE, key)
#define FUNCTION MO(_FUNCTION)

#define GAME TG(_GAME)
#define GAME_LT MO(_GAME_LT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------.                    ,-------------------------------------------------------------------------------.
       KC_TAB    ,    KC_Q     ,    KC_W     ,    KC_F     ,    KC_P     ,  KC_G  ,                         KC_J,    KC_L     ,    KC_U     ,    KC_Y     ,   TG_KR     ,  KC_DEL,
  //|------------+-------------+-------------+-------------+-------------+--------|                    |--------+-------------+-------------+-------------+-------------+--------------|
    LMOVE(KC_ESC), LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_D   ,                         KC_H, LCTL_T(KC_N), RSFT_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), RMOVE(KC_ENT),
  //|------------+-------------+-------------+-------------+-------------+--------|                    |--------+-------------+-------------+-------------+-------------+--------------|
     FUNCTION    , KC_Z        , KC_X        , KC_C        , KC_V        , KC_B   ,                         KC_K,         KC_M, KC_COMM     , KC_DOT      , KC_SLSH     ,  CW_TOGG     ,//QK_LOCK      ,
  //|------------+-------------+-------------+-------------+-------------+--------|                    |--------+-------------+-------------+-------------+-------------+--------------|
                                                           LEFT, LOWER,   KC_SPC,                     KC_BSPC,  RAISE, RIGHT
                                                       //`--------------------------'               `--------------------------'

  ),

  [_QWERTY] = LAYOUT_split_3x6_3(
  //,---------------------------------------------------------------------------.                  ,----------------------------------------------------------------.
        KC_TRNS, KC_Q        , KC_W        , KC_E        , KC_R        , KC_T   ,                   KC_Y,         KC_U, KC_I        , KC_O        , KC_TRNS     , KC_TRNS,
  //-----------+-------------+-------------+-------------+-------------+--------+                  ,----+-------------+-------------+-------------+-------------+--------+
        KC_TRNS, LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G   ,                   KC_H, LCTL_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), LGUI_T(KC_P), KC_TRNS,
  //-----------+-------------+-------------+-------------+-------------+--------+                  ,----+-------------+-------------+-------------+-------------+--------+
        KC_TRNS, KC_Z        , KC_X        , KC_C        , KC_V        , KC_B   ,                   KC_N,    KC_M     , KC_COMM     , KC_DOT      , KC_SLSH     , KC_TRNS,
  //-----------+-------------+-------------+-------------+-------------+--------+                  ,----+-------------+-------------+-------------+-------------+--------+
                                                      KC_TRNS, KC_TRNS, KC_TRNS,                  KC_TRNS, KC_TRNS, KC_TRNS
                                                      //`--------------------------'            `--------------------------'
  ),

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, KC_LT, KC_LCBR, KC_LPRN, KC_LBRC, KC_NO,                          KC_TRNS, KC_RBRC, KC_RPRN,  KC_RCBR, KC_GT,        KC_NO,
        KC_NO, KC_SCLN, KC_DQT, KC_QUES, KC_TILD, KC_NO,                     KC_NO, KC_HASH, KC_EXLM, KC_QUOT, KC_UNDS, KC_TRNS,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                               KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_NO, KC_NO, KC_TRNS,                         KC_TRNS, KC_TRNS, KC_NO
  ),



  [_LOWER] = LAYOUT_split_3x6_3(
        KC_NO, KC_CIRC, KC_AT, KC_NO, KC_NO, KC_NO,                        KC_NO, KC_NO, KC_PERC, KC_DLR, KC_SLSH, KC_NO,
        KC_NO, KC_EQL, KC_COLN, KC_NUBS, KC_AMPR, KC_NO,                   KC_NO, KC_PIPE, KC_PLUS, KC_MINS, KC_ASTR, KC_TRNS,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                          KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                            KC_NO, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_NO, KC_NO
  ),


  [_LEFT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_TRNS, KC_BSLS, KC_QUOT, KC_COMM, KC_SCLN, KC_NO,                                                    KC_LBRC, KC_P7, KC_P8, KC_P9, KC_EQL, KC_RBRC,
        KC_NO, LGUI_T(KC_PSLS), LALT_T(KC_PMNS), LSFT_T(KC_PPLS), LCTL_T(KC_PAST), KC_NO,                    KC_MINS, LCTL_T(KC_P4), RSFT_T(KC_P5), LALT_T(KC_P6), LGUI_T(KC_PDOT), KC_PENT,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                                              KC_GRV, KC_P1, KC_P2, KC_P3, KC_NO, KC_NO,
                            KC_TRNS, KC_NO, KC_TRNS,                         KC_TRNS, KC_P0, KC_NO
  ),

  [_RIGHT] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        KC_NO, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                             KC_6, KC_7, KC_8, KC_9, KC_0, KC_NO,
        KC_NO, LGUI_T(KC_F1), LALT_T(KC_F2), LSFT_T(KC_F3), LCTL_T(KC_F4), KC_F5,                            KC_F6, LCTL_T(KC_F7), RSFT_T(KC_F8), LALT_T(KC_F9), LGUI_T(KC_F10), KC_NO,
        KC_NO, KC_F11, KC_F12, KC_F13, KC_F14, KC_F15,                        KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_NO,
                            KC_NO, KC_NO, KC_NO,                         KC_NO, KC_NO, KC_TRNS
  ),

  [_LMOVE] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_ENT, KC_HOME, KC_UP, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_RMOVE] = LAYOUT_split_3x6_3(
        KC_TRNS, TG(_RMOVE), KC_BTN4, KC_MS_U, KC_BTN5, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS   , KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS   , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_ACL2   , KC_BTN1, KC_BTN2, KC_ACL0, KC_TRNS
  ),
  [_VIRT] = LAYOUT_split_3x6_3(
        KC_NO   , KC_NO   , KC_NO   , KC_NO   , GAME , KC_NO, KC_NO, AS_ON, AS_OFF, KC_NO, KC_NO, KC_NO,
        KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO, KC_NO, KC_NO, AS_UP, AS_DOWN, AS_RPT,   KC_NO, KC_NO,
        KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO, KC_NO, KC_NO, DT_UP, DT_DOWN, DT_PRNT, KC_NO, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_FUNCTION] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_TRNS, KC_MPLY, KC_VOLU, KC_MUTE, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_MPRV, KC_VOLD, KC_MNXT, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                   KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_GAME] = LAYOUT_split_3x6_3(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_RALT, KC_DEL,
        KC_LSFT, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_P, KC_ENT,
        KC_LCTL, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_CAPS,
        KC_LALT, GAME_LT, KC_SPC, KC_TRNS, KC_TRNS, GAME
  ),
  [_GAME_LT] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_ESC , KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, GAME_LT, KC_TRNS, KC_TRNS, KC_TRNS, GAME
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _VIRT);
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TG_KR:
            if (record->event.pressed) {
                layer_invert(_QWERTY);
                if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {  // if shift is pressed
                    return false;
                }
                tap_code(KC_RALT);
                return false;
            }
        case VIMCP:
            if (record->event.pressed) {
                tap_code16(KC_DQUO);
                tap_code16(KC_ASTR);
                tap_code16(KC_Y);
                return false;
            }
    }

    return true;
}


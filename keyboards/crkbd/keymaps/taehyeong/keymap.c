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

enum planck_layers { _COLEMAK, _QWERTY, _GAME, _RAISE, _LOWER, _LRCOMBO, _LMOVE, _RMOVE, _MOUSE, _MOUSE_TOGGLE, _FUNCTION, _KEYBOARD };

enum planck_keycodes { TG_KR = SAFE_RANGE, VIMCP };

#define GAME TG(_GAME)
#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define LMOVE(key) LT(_LMOVE, key)
#define RMOVE(key) LT(_RMOVE, key)
#define MOUSE_TOGGLE TG(_MOUSE_TOGGLE)
#define KEYBOARD TG(_KEYBOARD)
#define FUNCTION MO(_FUNCTION)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_COLEMAK] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------------------------------.                    ,-------------------------------------------------------------------------------.
       KC_TAB    ,    KC_Q     ,    KC_W     ,    KC_F     ,    KC_P     ,  KC_G  ,                         KC_J,    KC_L     ,    KC_U     ,    KC_Y     ,   TG_KR     ,  KC_DEL      ,
  //|------------+-------------+-------------+-------------+-------------+--------|                    |--------+-------------+-------------+-------------+-------------+--------------|
    LMOVE(KC_ESC), LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_D   ,                         KC_H, LCTL_T(KC_N), RSFT_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), RMOVE(KC_ENT),
  //|------------+-------------+-------------+-------------+-------------+--------|                    |--------+-------------+-------------+-------------+-------------+--------------|
     FUNCTION    , KC_Z        , KC_X        , KC_C        , KC_V        , KC_B   ,                         KC_K,         KC_M, KC_COMM     , KC_DOT      , KC_SLSH     , KC_CAPS      ,
  //|------------+-------------+-------------+-------------+-------------+--------|                    |--------+-------------+-------------+-------------+-------------+--------------|
                                                          LOWER,   KC_SPC,  KC_NO,                   KC_NO,   KC_BSPC,  RAISE
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
        KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, VIMCP, LCTL(KC_V), LALT(KC_TAB), LGUI(KC_TAB), KC_TRNS,
        KC_TRNS, KC_F5, KC_F6, KC_F7, KC_F8, KC_TRNS, KC_TRNS, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, KC_TRNS,
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_FUNCTION] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_TRNS, KC_MPLY, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_MPRV, KC_VOLD, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_LOWER] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR, KC_ASTR, KC_EXLM, KC_7, KC_8, KC_9, KC_TRNS,
        KC_TRNS, KC_QUOT, KC_SCLN, KC_EQL, KC_MINS, KC_HASH, KC_CIRC, KC_DLR, KC_4, KC_5, KC_6, KC_TRNS,
        KC_TRNS, LGUI_T(KC_DOT), LALT_T(KC_COMM), LSFT_T(KC_ASTR), LCTL_T(KC_PERC), KC_TRNS, KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_ENT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_TRNS, KC_TRNS
  ),

  [_LMOVE] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_ENT, KC_HOME, KC_UP, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_RMOVE] = LAYOUT_split_3x6_3(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_UP, KC_END, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_MOUSE] = LAYOUT_split_3x6_3(
        KC_TRNS, MOUSE_TOGGLE, KC_BTN4, KC_MS_U, KC_BTN5, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL2, KC_TRNS, KC_TRNS, KC_ACL2, KC_ACL0, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_BTN1, KC_TRNS, KC_TRNS, KC_BTN2, KC_TRNS
  ),

  [_MOUSE_TOGGLE] = LAYOUT_split_3x6_3(
        KC_TRNS, MOUSE_TOGGLE, KC_BTN4, KC_MS_U, KC_BTN5, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL2, KC_TRNS, KC_TRNS, KC_ACL2, KC_ACL0, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_BTN1, KC_TRNS, KC_TRNS, KC_BTN2, KC_TRNS
  ),
  [_LRCOMBO] = LAYOUT_split_3x6_3(
        KC_NO   , KEYBOARD, KC_NO   , KC_NO   , GAME, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO, KC_NO, KC_NO, KC_ASUP, KC_ASDN, KC_ASRP, KC_NO, KC_NO,
        KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  ),
  [_GAME] = LAYOUT_split_3x6_3(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_RALT, KC_DEL,
        KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_P, KC_ENT,
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_CAPS,
        KC_TRNS, KC_TRNS, GAME, KC_TRNS, KC_TRNS, KC_TRNS
  ),

  [_KEYBOARD] = LAYOUT_split_3x6_3(
        KC_NO, RGB_HUD, RGB_HUI, RGB_VAD, RGB_VAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_TRNS, RGB_MOD, RGB_SAD, RGB_SAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_TRNS,  KC_TRNS, KEYBOARD, KC_TRNS, KC_TRNS, KC_TRNS
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

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
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
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
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
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _LRCOMBO);
    state = update_tri_layer_state(state, _LMOVE, _RMOVE, _MOUSE);
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TG_KR:
            if (record->event.pressed) {
                layer_invert(_QWERTY);
                if (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT)) {  // if shift is pressed
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

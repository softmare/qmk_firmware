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
    [_COLEMAK]      = LAYOUT_ortho_4x12(
        KC_TAB, KC_Q, KC_W, KC_F, KC_P, KC_G, KC_J, KC_L, KC_U, KC_Y, TG_KR, KC_DEL,
        LMOVE(KC_ESC), LGUI_T(KC_A), LALT_T(KC_R), LSFT_T(KC_S), LCTL_T(KC_T), KC_D, KC_H, LCTL_T(KC_N), RSFT_T(KC_E), LALT_T(KC_I), LGUI_T(KC_O), RMOVE(KC_ENT), 
        FUNCTION, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_CAPS, 
        KC_NO, KC_NO, KC_NO, KC_NO, LOWER, KC_SPC, KC_BSPC, RAISE, KC_NO, KC_NO, KC_NO, KC_NO),

    [_QWERTY]       = LAYOUT_ortho_4x12(
        KC_TRNS, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_TRNS, KC_TRNS, 
        KC_TRNS, LGUI_T(KC_A), LALT_T(KC_S), LSFT_T(KC_D), LCTL_T(KC_F), KC_G, KC_H, LCTL_T(KC_J), RSFT_T(KC_K), LALT_T(KC_L), LGUI_T(KC_P), KC_TRNS, 
        KC_TRNS, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_GAME]         = LAYOUT_ortho_4x12(
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_RALT, KC_DEL, 
        KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_P, KC_ENT, 
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_CAPS, 
        KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_RAISE]        = LAYOUT_ortho_4x12(
        KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, VIMCP, LCTL(KC_V), LALT(KC_TAB), LGUI(KC_TAB), KC_TRNS, 
        KC_TRNS, KC_F5, KC_F6, KC_F7, KC_F8, KC_TRNS, KC_TRNS, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, KC_TRNS, 
        KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_FUNCTION]        = LAYOUT_ortho_4x12(
        KC_TRNS, KC_TRNS, KC_MPLY, KC_VOLU, KC_MUTE, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_MPRV, KC_VOLD, KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_LOWER]     = LAYOUT_ortho_4x12(
        KC_TRNS, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR, KC_EXLM, KC_ASTR, KC_7, KC_8, KC_9, KC_TRNS, 
        KC_TRNS, KC_QUOT, KC_SCLN, KC_EQL, KC_MINS, KC_HASH, KC_DLR, KC_GRV, KC_4, KC_5, KC_6, KC_TRNS, 
        KC_TRNS, LGUI_T(KC_DOT), LALT_T(KC_COMM), LSFT_T(KC_NO), LCTL_T(KC_NO), KC_TRNS, KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_ENT, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_0, KC_DOT, KC_COMM, KC_TRNS),

    [_LMOVE]        = LAYOUT_ortho_4x12(
        KC_TRNS, KC_ENT, KC_HOME, KC_UP, KC_END, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_RMOVE]        = LAYOUT_ortho_4x12(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_HOME, KC_UP, KC_END, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_MOUSE]        = LAYOUT_ortho_4x12(
        KC_TRNS, MOUSE_TOGGLE, KC_BTN4, KC_MS_U, KC_BTN5, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL2, KC_TRNS, KC_TRNS, KC_ACL2, KC_ACL0, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_MOUSE_TOGGLE] = LAYOUT_ortho_4x12(
        KC_TRNS, MOUSE_TOGGLE, KC_BTN4, KC_MS_U, KC_BTN5, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_ACL0, KC_ACL2, KC_TRNS, KC_TRNS, KC_ACL2, KC_ACL0, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_KEYBOARD]     = LAYOUT_ortho_4x12(
        KC_NO, RGB_HUD, RGB_HUI, RGB_VAD, RGB_VAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_TRNS, RGB_MOD, RGB_SAD, RGB_SAI, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        RESET, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_LRCOMBO]      = LAYOUT_ortho_4x12(
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_NO, KEYBOARD, KC_NO, KC_NO, GAME, KC_NO, KC_NO, KC_ASUP, KC_ASDN, KC_ASRP, KC_NO, KC_NO, 
        KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};

#ifdef AUDIO_ENABLE
float plover_song[][2]    = SONG(PLOVER_SOUND);
float plover_gb_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _LOWER, _RAISE, _LRCOMBO);
    state = update_tri_layer_state(state, _LMOVE, _RMOVE, _MOUSE);
    switch (get_highest_layer(state)) {
        case _GAME:
            autoshift_disable();
            break;
        default:
            autoshift_enable();
            break;
    }
    return state;
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LPRN:
        case KC_DLR:
        case KC_RPRN:
        case KC_ASTR:
        case KC_EXLM:
        case KC_HASH:
        case KC_AMPR:
        case KC_1:
        case KC_2:
        case KC_3:
        case KC_4:
        case KC_5:
        case KC_6:
        case KC_7:
        case KC_8:
        case KC_9:
        case KC_0:
            return true;
        default:
            return false;
    }
}

uint16_t get_autoshift_timeout(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case AUTO_SHIFT_NUMERIC:
            return 3 * get_generic_autoshift_timeout();
        default:
            return get_generic_autoshift_timeout();
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch (keycode) {
        case KC_LPRN:
            register_code16((!shifted) ? KC_LPRN : KC_LT);
            break;
        case KC_RPRN:
            register_code16((!shifted) ? KC_RPRN : KC_GT);
            break;
        case KC_DLR:
            register_code16((!shifted) ? KC_DLR : KC_CIRC);
            break;
        case KC_ASTR:
            register_code16((!shifted) ? KC_ASTR : KC_PERC);
            break;
        case KC_EXLM:
            register_code16((!shifted) ? KC_EXLM : KC_BSLS);
            break;
        case KC_HASH:
            register_code16((!shifted) ? KC_HASH : KC_AT);
            break;
        case KC_AMPR:
            register_code16((!shifted) ? KC_AMPR : KC_PIPE);
            break;
        case KC_1:
            register_code16((!shifted) ? KC_1 : KC_P1);
            break;
        case KC_2:
            register_code16((!shifted) ? KC_2 : KC_P2);
            break;
        case KC_3:
            register_code16((!shifted) ? KC_3 : KC_P3);
            break;
        case KC_4:
            register_code16((!shifted) ? KC_4 : KC_P4);
            break;
        case KC_5:
            register_code16((!shifted) ? KC_5 : KC_P5);
            break;
        case KC_6:
            register_code16((!shifted) ? KC_6 : KC_P6);
            break;
        case KC_7:
            register_code16((!shifted) ? KC_7 : KC_P7);
            break;
        case KC_8:
            register_code16((!shifted) ? KC_8 : KC_P8);
            break;
        case KC_9:
            register_code16((!shifted) ? KC_9 : KC_P9);
            break;
        case KC_0:
            register_code16((!shifted) ? KC_0 : KC_P0);
            break;
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch (keycode) {
        case KC_LPRN:
            unregister_code16((!shifted) ? KC_LPRN : KC_LT);
            break;
        case KC_RPRN:
            unregister_code16((!shifted) ? KC_RPRN : KC_GT);
            break;
        case KC_DLR:
            unregister_code16((!shifted) ? KC_DLR : KC_CIRC);
            break;
        case KC_EXLM:
            unregister_code16((!shifted) ? KC_EXLM : KC_BSLS);
            break;
        case KC_ASTR:
            unregister_code16((!shifted) ? KC_ASTR : KC_PERC);
            break;
        case KC_HASH:
            unregister_code16((!shifted) ? KC_HASH : KC_AT);
            break;
        case KC_AMPR:
            unregister_code16((!shifted) ? KC_AMPR : KC_PIPE);
            break;
        case KC_1:
            unregister_code16((!shifted) ? KC_1 : KC_P1);
            break;
        case KC_2:
            unregister_code16((!shifted) ? KC_2 : KC_P2);
            break;
        case KC_3:
            unregister_code16((!shifted) ? KC_3 : KC_P3);
            break;
        case KC_4:
            unregister_code16((!shifted) ? KC_4 : KC_P4);
            break;
        case KC_5:
            unregister_code16((!shifted) ? KC_5 : KC_P5);
            break;
        case KC_6:
            unregister_code16((!shifted) ? KC_6 : KC_P6);
            break;
        case KC_7:
            unregister_code16((!shifted) ? KC_7 : KC_P7);
            break;
        case KC_8:
            unregister_code16((!shifted) ? KC_8 : KC_P8);
            break;
        case KC_9:
            unregister_code16((!shifted) ? KC_9 : KC_P9);
            break;
        case KC_0:
            unregister_code16((!shifted) ? KC_0 : KC_P0);
            break;
        default:
            // & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
            // The IS_RETRO check isn't really necessary here, always using
            // keycode & 0xFF would be fine.
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
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

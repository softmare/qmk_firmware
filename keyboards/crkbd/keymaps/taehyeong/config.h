// Copyright 2022 LucW (@luc-languagetools)
// SPDX-License-Identifier: GPL-2.0-or-later


#pragma once


/* Select hand configuration */

// #define MASTER_LEFT
// #define MASTER_RIGHT
# define SPLIT_USB_DETECT
// #define EE_HANDS

#define QUICK_TAP_TERM 0 // disable double tap repeat
#define IGNORE_MOD_TAP_INTERRUPT
#define TAPPING_TERM 170
#define TAPPING_TERM_PER_KEY

// auto shift
#define AUTO_SHIFT_REPEAT
#define AUTO_SHIFT_TIMEOUT 150
#define AUTO_SHIFT_TIMEOUT_PER_KEY

// disable auto shift for alpha and special keys
// ref : https://docs.qmk.fm/#/feature_auto_shift
#define NO_AUTO_SHIFT_ALPHA
#define No_AUTO_SHIFT_SPECIAL



// #define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD
// #define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// MOUSE SETTINGS
// ==============

// #define MOUSEKEY_TIME_TO_MAX 200
#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL
#define MK_C_INTERVAL_0 7
#define MK_C_INTERVAL_UNMOD 7
#define MK_C_INTERVAL_2 7
//#define MK_C_INTERVAL_1 7
//#define MK_C_OFFSET_1 5
#define MK_C_OFFSET_0 2
#define MK_C_OFFSET_UNMOD 4
#define MK_C_OFFSET_2 24
//#define MK_W_OFFSET_0 1
//#define MK_W_INTERVAL_0 400
//#define MK_W_INTERVAL_1 200
#define MK_W_INTERVAL_UNMOD 100
#define MK_W_INTERVAL_2 20

#define RGBLIGHT_LAYERS

#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_LIMIT_VAL 90
    // #define RGBLIGHT_LIMIT_VAL 0
    #define RGBLIGHT_HUE_STEP 10
    #define RGBLIGHT_SAT_STEP 17
    #define RGBLIGHT_VAL_STEP 17
#endif

#ifdef RGB_MATRIX_ENABLE
 // #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
 // #define RGB_MATRIX_KEYPRESSES // reacts to keypresses
 // #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
 // #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
 // #define ENABLE_RGB_MATRIX_SPLASH
 //#define ENABLE_RGB_MATRIX_SOLID_SPLASH
#endif

#define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

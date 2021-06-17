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
  _QWERTY,
  _DVORAK,
  _LOWER,
  _RAISE,
  _FUNCT,
  _MOUSE,
  _ADJUST
};

// Layer shortcuts
#define DVORAK DF(_DVORAK)
#define QWERTY DF(_QWERTY)
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define MOUSE LT(_MOUSE, KC_SPC)
#define FUNCT MO(_FUNCT)
#define ADJUST MO(_ADJUST)

// Window management via Magnet app
#define WIN50L LCA(KC_LEFT)
#define WIN50R LCA(KC_RGHT)
#define WIN33L LCA(KC_D)
#define WIN66R LCA(KC_T)
#define WIN100 LCA(KC_ENT)

// Misc mac shortcuts
#define ALFRED LGUI(KC_SPC) // Toggle Alfred
#define TYPOGR SGUI(KC_T) // Fire ALS Typograph workflow
#define ADD_TSK HYPR(KC_A) // Add task via Todoist
#define CLIPBRD HYPR(KC_J) // Show Alfred clipboard
#define SCRSHT SGUI(KC_4) // Make a screenshot
#define TIMER HYPR(KC_T) // Toggle Tyme2

// Player shortcuts
#define PREV KC_MEDIA_PREV_TRACK
#define NEXT KC_MEDIA_NEXT_TRACK
#define VOL_DN KC_VOLD
#define VOL_UP KC_VOLU
#define PLAY KC_MPLY

// Copy, paste etc
#define SEL_ALL LGUI(KC_A)
#define CUT LGUI(KC_B)
#define COPY LGUI(KC_I)
#define PASTE LGUI(KC_DOT)
#define RMWRD LALT(KC_BSPC)
#define RMLINE LGUI(KC_BSPC)
#define CTL_TAB LCTL_T(KC_TAB)

// Brackets and punctuation
#define CURLL LSFT(KC_MINS)
#define CURLR LSFT(KC_EQL)
#define RUCOMMA LSFT(KC_6)
#define RUDOT LSFT(KC_7)

#include "tapdance.c"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT_split_3x6_3(
KC_ESC,   KC_Q,     KC_W,     KC_E,     KC_R,        KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,
CTL_TAB,  KC_A,     KC_S,     KC_D,     KC_F,        KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
KC_LSPO,  KC_Z,     KC_X,     KC_C,     KC_V,        KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSPC,
                              KC_LGUI,  TD(LOW_ALF), KC_ENT,   KC_SPC,   RAISE,    FUNCT
),

[_DVORAK] = LAYOUT_split_3x6_3(
KC_ESC,   KC_QUOT,  KC_COMM,  KC_DOT,   KC_P,        KC_Y,     KC_F,     KC_G,     KC_C,     KC_R,     KC_L,     KC_SLSH,
CTL_TAB,  KC_A,     KC_O,     KC_E,     KC_U,        KC_I,     KC_D,     KC_H,     KC_T,     KC_N,     KC_S,     KC_MINUS,
KC_LSPO,  KC_SCLN,  KC_Q,     KC_J,     KC_K,        KC_X,     KC_B,     KC_M,     KC_W,     KC_V,     KC_Z,     KC_RSPC,
                              KC_LGUI,  TD(LOW_ALF), KC_ENT,   KC_SPC,   RAISE,    FUNCT
),

[_LOWER] = LAYOUT_split_3x6_3(
TIMER,    TYPOGR,   ADD_TSK,  CLIPBRD,  SCRSHT,      CURLL,    CURLR,    KC_P7,    KC_P8,    KC_P9,    KC_PMNS,  KC_PSLS,
PREV,     NEXT,     VOL_DN,   PLAY,     VOL_UP,      RUCOMMA,  RUDOT,    KC_P4,    KC_P5,    KC_P6,    KC_PPLS,  KC_PAST,
_______,  SEL_ALL,  CUT,      COPY,     PASTE,       KC_MINS,  KC_EQL,   KC_P1,    KC_P2,    KC_P3,    KC_PEQL,  KC_PDOT,
                              _______,  _______,     _______,  _______,  KC_P0,    _______
),

[_RAISE] = LAYOUT_split_3x6_3(
XXXXXXX,  KC_TILD,  KC_BSLS,  XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,  TD(WIN_L),WIN100,   TD(WIN_R),XXXXXXX,  XXXXXXX,
KC_CAPS,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,      KC_PERC,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_F18,   _______,
CURLL,    KC_GRV,   KC_CIRC,  KC_AMPR,  KC_ASTR,     KC_QUES,  _______,  KC_BSPC,  RMWRD,    RMLINE,   _______,  CURLR,
                              _______,  ADJUST,      _______,  _______,  _______,  _______
),

[_FUNCT] = LAYOUT_split_3x6_3(
XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,  KC_F1,    KC_F2,    KC_F3,    KC_F4,   XXXXXXX,
XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,  KC_F5,    KC_F6,    KC_F7,    KC_F8,   XXXXXXX,
XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,  KC_F9,    KC_F10,   KC_F11,   KC_F12,  XXXXXXX,
                              XXXXXXX,  XXXXXXX,     XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX
),

[_MOUSE] = LAYOUT_split_3x6_3(
XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,      XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_MS_U,  XXXXXXX,  XXXXXXX, XXXXXXX,
XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,      XXXXXXX,  XXXXXXX,  KC_MS_L,  KC_MS_D,  KC_MS_R,  XXXXXXX, XXXXXXX,
XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,      XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
                              XXXXXXX, XXXXXXX,      XXXXXXX,  KC_BTN2,  KC_BTN1,  XXXXXXX
),

[_ADJUST] = LAYOUT_split_3x6_3(
_______,  RESET,    DEBUG,    RGB_TOG, RGB_MOD,      RGB_HUI,  RGB_HUD,  RGB_SAI,  RGB_SAD,  RGB_VAI,  RGB_VAD, KC_DEL,
_______,  _______,  MU_MOD,   AU_ON,   AU_OFF,       _______,  DVORAK,   QWERTY,   _______,  _______,  _______, _______,
_______,  MUV_DE,   MUV_IN,   MU_ON,   MU_OFF,       MI_ON,    MI_OFF,   TERM_ON,  TERM_OFF, _______,  _______, _______,
                              _______, _______,      _______,  _______,  _______,  _______
)
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
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

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE

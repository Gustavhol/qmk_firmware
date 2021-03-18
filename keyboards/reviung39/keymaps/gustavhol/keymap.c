/* Copyright 2019 gtips
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
#include "quantum/keymap_extras/keymap_swedish.h"

enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};


// Fillers to make layering more clear

#define _______ KC_TRNS
#define SFT_ESC SFT_T(KC_ESC)
#define CTL_BSPC CTL_T(KC_BSPC)
#define ALT_SPC ALT_T(KC_SPC)
#define SFT_ENT SFT_T(KC_ENT)
#define C_S_LFT CTL_T(LALT_T(KC_LEFT))
#define S_TAB SFT_T(KC_TAB)
#define G_C_A LGUI(LCTL(KC_A))
#define G_C_M LGUI(LCTL(KC_M))
#define SFT_A SFT_T(KC_A)
#define CTL_S CTL_T(KC_S)
#define ALT_D ALT_T(KC_D)
#define GUI_F GUI_T(KC_F)
#define GUI_J GUI_T(KC_J)
#define ALT_K ALT_T(KC_K)
#define CTL_L CTL_T(KC_L)
#define SFT_OE SFT_T(KC_SCLN)

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define ADJUST MO(_ADJUST)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_reviung39(
      KC_ESC  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,              KC_Y   , KC_U   , KC_I   , KC_O  , KC_P   , KC_LBRC,
      S_TAB   , SFT_A  , CTL_S  , ALT_D  , GUI_F  , KC_G   ,              KC_H   , GUI_J  , ALT_K  , CTL_L , SFT_OE , KC_QUOT,
      G_C_A   , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,              KC_N   , KC_M   , KC_COMM, KC_DOT, SE_SCLN, KC_DEL,
                                 LT(LOWER, KC_BSPC) ,LT(LOWER, KC_SPC), LT(RAISE,KC_ENTER)
    ),
  /* [_BASE] = LAYOUT_reviung39( */
  /*   KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,      KC_T,               KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC, */
  /*   KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,      KC_G,               KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT, */
  /*   KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,               KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  RSFT_T(KC_ENT), */
  /*                                                      LOWER,    KC_SPC,   RAISE */
  /* ), */
    [_RAISE] = LAYOUT_reviung39
      (_______, SE_UNDS, SE_AMPR, SE_GRV , SE_LCBR, SE_RCBR,              SE_LESS, SE_GRTR, SE_EQL , SE_PLUS, _______, KC_F10,
       _______, SE_MINS , SE_APOS, SE_QUO2, SE_LPRN, SE_RPRN,             SE_LBRC, SE_RBRC, SE_COLN, SE_SLSH , SE_AT  , C(S(KC_7)),
       G_C_M  , SE_CIRC, SE_BSLS, SE_ASTR, KC_EXLM, S(KC_3),           SE_PIPE, SE_QUES, SE_DLR , KC_PERC, SE_TILD, _______,
                                                     _______, _______, _______
      ),
  
  /* [_LOWER] = LAYOUT_reviung39( */
  /*   _______,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,    KC_PERC,            KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_DEL, */
  /*   _______,  KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,   KC_PIPE,            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  KC_GRV,   KC_TILD, */
  /*   _______,  KC_ESC,   KC_LGUI,  KC_LALT,  KC_CAPS,   KC_DQUO,            KC_HOME,  KC_END,   KC_PGUP,  KC_PGDN,  KC_PSCR,  RSFT_T(KC_SPC), */
  /*                                                      _______,  KC_ENT,   _______ */
  /* ), */


    [_LOWER] = LAYOUT_reviung39
    (_______, _______, _______, _______, _______, _______,                _______, KC_7   , KC_8   , KC_9   , _______, KC_MUTE,
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                  _______, KC_4   , KC_5   , KC_6   , _______, KC_VOLU,
     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                 KC_0   , KC_1   , KC_2   , KC_3   , _______, KC_VOLD,
                                                     _______, _______, _______
     ),
  /* [_RAISE] = LAYOUT_reviung39( */
  /*   _______,  KC_1,     KC_2,     KC_3,     KC_4,      KC_5,               KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_DEL, */
  /*   _______,  KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,   KC_BSLS,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6, */
  /*   _______,  KC_ESC,   KC_RGUI,  KC_RALT,  KC_CAPS,   KC_QUOT,            KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12, */
  /*                                                      _______,  KC_BSPC,  _______ */
  /* ), */

    [_ADJUST] = LAYOUT_reviung39
    (RESET,   _______, _______, _______, _______, _______,                KC_HOME, KC_PGDN,  KC_PGUP , KC_END , _______, _______,
     _______, _______, _______, _______, _______, _______,                KC_LEFT, KC_DOWN  , KC_UP  , KC_RIGHT , _______, _______,
     _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______   , _______, _______,
                                       S(A(KC_DOWN)), S(A(KC_UP)),  S(A(KC_LEFT))
    ),

  /* [_ADJUST] = LAYOUT_reviung39( */
  /*   RGB_VAI,   RGB_SAI, RGB_HUI,  RGB_MOD,  XXXXXXX,   RGB_TOG,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, */
  /*   RGB_VAD,   RGB_SAD, RGB_HUD,  RGB_RMOD, XXXXXXX,   XXXXXXX,            XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, */
  /*   XXXXXXX,   XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,            RESET,    XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, */
  /*                                                      _______,  XXXXXXX,  _______ */
  /* ), */
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//  Per key tapping term
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CTL_S:
            return 300;
        case ALT_D:
            return 300;
        case ALT_K:
            return 300;
        case CTL_L:
            return 300;
        case SFT_OE:
            return 150;
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
            return 150;
        default:
            return TAPPING_TERM;
    }
}

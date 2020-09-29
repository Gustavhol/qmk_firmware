

#include QMK_KEYBOARD_H
#include "quantum/keymap_extras/keymap_swedish.h"

extern keymap_config_t keymap_config;

#define _BASE 0
#define _RAISE 1
#define _LOWER 2
#define _ADJUST 3

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

enum custom_keycodes {
    SENS,
};



#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define ADJUST MO(_ADJUST)

// #define MEDIA_KEY_DELAY 10

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Base (qwerty)
     * +-----------------------------------------+                             +-----------------------------------------+
     * | ESC  |   q  |   w  |   e  |   r  |   t  |                             |   y  |   u  |   i  |   o  |   p  |      |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | TAB  |   a  |   s  |   d  |   f  |   g  |                             |   h  |   j  |   k  |   l  |   ;  |      |
     * |------+------+------+------+------+------|                             |------+------+------+------+------+------|
     * | SHFT |   z  |   x  |   c  |   v  |   b  |                             |   n  |   m  |   ,  |   .  |   /  |      |
     * +------+------+------+------+-------------+                             +-------------+------+------+------+------+
     *               |  [   |   ]  |                                                         |      |      |
     *               +-------------+-------------+                             +-------------+-------------+
     *                             |      |      |                             |      |      |
     *                             |------+------|                             |------+------|
     *                             |      |      |                             |      |      |
     *                             +-------------+                             +-------------+
     *                                           +-------------+ +-------------+
     *                                           |      |      | |      |      |
     *                                           |------+------| |------+------|
     *                                           |      |      | |      |      |
     *                                           +-------------+ +-------------+
     */

/* MED HOME ROW MODIFIERS */
    [_BASE] = LAYOUT(KC_ESC  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,              KC_Y   , KC_U   , KC_I   , KC_O  , KC_P   , KC_LBRC,
                     S_TAB   , SFT_A  , CTL_S  , ALT_D  , GUI_F  , KC_G   ,              KC_H   , GUI_J  , ALT_K  , CTL_L , SFT_OE , KC_QUOT,
                     G_C_A   , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,              KC_N   , KC_M   , KC_COMM, KC_DOT, SE_SCLN, G(KC_LSFT),
                                        _______, _______ ,                                                 KC_DEL , _______,

                                 LT(LOWER, KC_BSPC)  , LT(LOWER, KC_SPC),              LT(RAISE,KC_ENTER), G(KC_LSFT),
                                          LT(ADJUST, _______), _______,                _______, _______,
                                                        _______, KC_DEL,               KC_MPLY , KC_F12),

/* UTAN HOME ROW MODIFIERS */
    /* [_BASE] = LAYOUT(KC_ESC  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,              KC_Y   , KC_U   , KC_I   , KC_O  , KC_P   , KC_LBRC, */
    /*                  S_TAB   , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,              KC_H   , KC_J   , KC_K   , KC_L  , KC_SCLN, KC_QUOT, */
    /*                  G_C_A   , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,              KC_N   , KC_M   , KC_COMM, KC_DOT, SE_SCLN, KC_SFTENT, */
    /*                                     KC_LALT, KC_LGUI ,                                                 KC_DEL , KC_LGUI, */

    /*                              LT(LOWER, KC_BSPC)  , LT(LOWER, KC_SPC),              LT(RAISE,KC_ENTER), G(KC_LSFT), */
    /*                                       LT(ADJUST, _______), KC_LCTRL,                KC_LSFT, KC_LGUI, */
    /*                                                     _______, KC_DEL,               KC_MPLY , KC_F12), */

    [_RAISE] = LAYOUT(_______, SE_UNDS, SE_AMPR, SE_GRV , SE_LCBR, SE_RCBR,              SE_LESS, SE_GRTR, SE_EQL , SE_PLUS, _______, KC_F10,
                      _______, SE_MINS , SE_APOS, SE_QUO2, SE_LPRN, SE_RPRN,             SE_LBRC, SE_RBRC, SE_COLN, SE_SLSH , SE_AT  , C(S(KC_7)),
                      G_C_M  , SE_CIRC, SE_BSLS, SE_ASTR, KC_EXLM, S(KC_3),           SE_PIPE, SE_QUES, SE_DLR , KC_PERC, SE_TILD, _______,
                                        _______, _______,                                                KC_VOLD, KC_VOLU,
                                                         _______, _______,               _______, _______,
                                                         _______, _______,               _______, _______,
                                                         _______, _______,               SENS, _______),

    [_LOWER] = LAYOUT(_______, _______, _______, _______, _______, _______,                _______, KC_7   , KC_8   , KC_9   , _______, KC_MUTE,
                      KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                  _______, KC_4   , KC_5   , KC_6   , _______, KC_VOLU,
                      KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                 _______, KC_1   , KC_2   , KC_3   , _______, KC_VOLD,
                                        _______, _______,                                                   KC_0, _______,
                                                          _______, _______,              _______, _______,
                                                          _______, _______,              _______, _______,
                                                          _______, _______,              _______, _______),

    [_ADJUST] = LAYOUT(RESET,   _______, _______, _______, _______, _______,                KC_HOME, KC_PGDN,  KC_PGUP , KC_END , _______, _______,
                       _______, _______, _______, _______, _______, _______,                KC_LEFT, KC_DOWN  , KC_UP  , KC_RIGHT , _______, _______,
                       _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______   , _______, _______,
                                         S(A(KC_DOWN)), S(A(KC_UP)),                                    S(A(KC_LEFT)), S(A(KC_RIGHT)),
                                                          _______, _______,              _______, _______,
                                                          _______, _______,              _______, _______,
                                                          _______, _______,              _______, _______)

};


layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

uint8_t sensVal = 1;
bool sensAdj = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case SENS:
      if (record->event.pressed) {
      sensAdj = !sensAdj;
      return false;
      break;
      }
  }
  return true;
}

uint8_t x;

void encoder_update_user(uint8_t index, bool clockwise) {
    //   if (IS_LAYER_ON(_RAISE)) {
    //       if (clockwise) {
    //             register_code(KC_LALT);
    //             tap_code(KC_DOWN);
    //             unregister_code(KC_LALT);
    //         } else {
    //             register_code(KC_LALT);
    //             tap_code(KC_UP);
    //             unregister_code(KC_LALT);
    //         }
    //         } else if (IS_LAYER_ON(_LOWER)){
    //     if (clockwise) {
    //             register_code(KC_LCTRL);
    //             tap_code(KC_Z);
    //             unregister_code(KC_LCTRL);
    //         } else {
    //             register_code(KC_LCTL);
    //             register_code(KC_LSFT);
    //             tap_code(KC_Z);
    //             unregister_code(KC_LSFT);
    //             unregister_code(KC_LCTL);
    //         }
              if (IS_LAYER_ON(_RAISE)) {
                if (clockwise) {
                        #ifdef MOUSEKEY_ENABLE
                          for (x = 0; x < sensVal; x++) {
                              tap_code(KC_MS_WH_UP);
                            }
                        #else
                          tap_code(KC_PGUP);
                        #endif
                      } else {
                        #ifdef MOUSEKEY_ENABLE
                          for (x = 0; x < sensVal; x++) {
                              tap_code(KC_MS_WH_DOWN);
                            }
                        #else
                          tap_code(KC_PGDN);
                        #endif
                              }


            } else if (sensAdj) {
                if(clockwise && sensVal > 1) {
                    sensVal--;
                  } else {
                if (sensVal < 5) {
                    sensVal++;
        }}
                }else {
            if (clockwise) {
           tap_code(KC_AUDIO_VOL_UP);
           } else {
           tap_code(KC_AUDIO_VOL_DOWN);
           }

}}

void matrix_scan_user(void) {
}

void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}

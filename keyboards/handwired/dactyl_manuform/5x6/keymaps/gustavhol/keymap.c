/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H
#include "quantum/keymap_extras/sendstring_swedish.h"


#define _QWERTY 0
#define _RAISE 1
#define _SPECIAL 2

#define RAISE MO(_RAISE)
#define SPECIAL MO(_SPECIAL)
#define G_C_X LGUI(LCTL(KC_X))

enum custom_keycodes {
    STRING = SAFE_RANGE,
    FLASH,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_5x6(
     KC_A, KC_B,LT(RAISE, KC_MPRV), LT(RAISE, KC_MPLY), LT(RAISE, KC_MNXT),KC_MSTP,_______  , _______  , _______  , _______  , _______  ,_______,
     _______, _______  , _______  , _______  , _______  , _______  ,                         _______  , _______  , _______  , _______  , _______  ,_______,
     _______, _______  , _______  , _______  , _______  , _______  ,                         _______  , _______  , _______  , _______  ,_______,_______,
     _______, _______  , _______  , _______  , _______  , _______  ,                         _______  , _______  ,_______,_______ ,_______,_______,
                      _______,_______,                                                       _______, _______,
                                      _______,_______,                        _______, _______,
                                      _______,_______,                         _______,  _______,
                                      _______, _______,                        _______, _______
  ),

  [_RAISE] = LAYOUT_5x6(
     _______, _______  , KC_MRWD  , STRING   , G_C_X    , RESET    ,                        _______  , _______ , _______ , _______ ,_______ ,_______ ,
     _______, _______  , _______  , _______  , _______  , _______  ,                         _______  , _______  , _______  , _______  , _______  ,_______,
     _______, _______  , _______  , _______  , _______  , _______  ,                         _______  , _______  , _______  , _______  ,_______,_______,
     _______, _______  , _______  , _______  , _______  , _______  ,                         _______  , _______  ,_______,_______ ,_______,_______,
                      _______,_______,                                                       _______, _______,
                                      _______,_______,                        _______, _______,
                                      _______,_______,                         _______,  _______,
                                      _______, _______,                        _______, _______
  ),
  [_SPECIAL] = LAYOUT_5x6(
     _______, _______ , KC_NO , KC_NO , KC_NO , KC_NO ,                        _______  , _______ , _______ , _______ ,_______ ,_______ ,
     _______, _______  , _______  , _______  , _______  , _______  ,                         _______  , _______  , _______  , _______  , _______  ,_______,
     _______, _______  , _______  , _______  , _______  , _______  ,                         _______  , _______  , _______  , _______  ,_______,_______,
     _______, _______  , _______  , _______  , _______  , _______  ,                         _______  , _______  ,_______,_______ ,_______,_______,
                      _______,_______,                                                       _______, _______,
                                      _______,_______,                        _______, _______,
                                      _______,_______,                         _______,  _______,
                                      _______, _______,                        _______, _______
  ),
};

void encoder_update_user(uint8_t index, bool clockwise) {
            if (clockwise) {
           tap_code(KC_AUDIO_VOL_DOWN);
           } else {
           tap_code(KC_AUDIO_VOL_UP);
           }

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
      case STRING:
      if (record->event.pressed) {
        SEND_STRING("wm305jmo");
        tap_code(KC_ENTER);
      return false;
      break;
      }
      case FLASH:
      if (record->event.pressed) {
      SEND_STRING("make handwired/dactyl_manuform/5x6:gustavhol:avrdude");
      return false;
      break;
      }
  }
  return true;
}

void matrix_scan_user(void) {
}

/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"
#include "quantum/keymap_extras/keymap_swedish.h"

extern keymap_config_t keymap_config;

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ARROWS,
  _ADJUST,
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  BACKLIT,
  SENS,
};


#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ARROWS MO(_ARROWS)
#define KC_SFTTAB SFT_T(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_UP, KC_SFTENT ,
    KC_LCTRL , KC_LALT , KC_LGUI, ARROWS, LT(LOWER, KC_BSPC) ,   LT(LOWER,KC_SPC),  LT(RAISE,KC_ENT),  RAISE,   KC_DEL, KC_LEFT, KC_DOWN,   KC_RGHT
),





/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Sens |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9, _______, _______,
    SENS,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_4,    KC_5,    KC_6, _______, _______,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_1,    KC_2,    KC_3, _______,  _______,
    _______, _______, _______, _______, _______, _______, _______, KC_0, SE_COLN, _______, _______, SE_COLN
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
     _______, SE_UNDS, SE_AMPR, SE_GRV , SE_LCBR, SE_RCBR, SE_LESS, SE_GRTR, SE_EQL , SE_PLUS, _______, KC_F10,
    _______, SE_MINS, SE_APOS, SE_QUO2, SE_LPRN, SE_RPRN, SE_LBRC, SE_RBRC, SE_COLN, SE_SLSH , SE_AT  , C(S(KC_7)),
    _______, SE_CIRC, SE_BSLS, SE_ASTR, KC_EXLM, S(KC_3), SE_PIPE, SE_QUES, SE_DLR , KC_PERC, SE_TILD, _______,
    _______, _______, _______, _______, LOWER,_______, _______, RAISE, _______, _______, _______, _______
),


/* ARROWS
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Sens |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_ARROWS] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, _______, _______,    _______,    _______, _______, _______,
    _______,  _______,   _______,   _______,   _______,   _______,   KC_LEFT,   KC_DOWN,    KC_UP,    KC_RGHT, _______, _______,
    _______, _______,   _______,   _______,   _______,  _______,  _______,  _______,    _______,    _______, _______,  _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),


/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Plover|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    SENS, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______,  _______,  CK_TOGG, _______,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, CK_UP   , _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, CK_DOWN , SENS
)

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
//   float sens1[][2]             = SONG(SENS_1);
//   float sens2[][2]             = SONG(SENS_2);
//   float sens3[][2]             = SONG(SENS_3);
//   float sens4[][2]             = SONG(SENS_4);
//   float sens5[][2]             = SONG(SENS_5);
//   float guitar[][2]            = SONG(GUITAR_SOUND);
#endif

uint32_t layer_state_set_user(uint32_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}



uint8_t sensVal = 1;
bool sensAdj = false;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // case QWERTY:
    //   if (record->event.pressed) {
    //     print("mode just switched to qwerty and this is a huge string\n");
    //     set_single_persistent_default_layer(_QWERTY);
    //   }
    //   return false;
    //   break;
    // case BACKLIT:
    //   if (record->event.pressed) {
    //     register_code(KC_RSFT);
    //     #ifdef BACKLIGHT_ENABLE
    //       backlight_step();
    //     #endif
    //     #ifdef KEYBOARD_planck_rev5
    //       PORTE &= ~(1<<6);
    //     #endif
    //   } else {
    //     unregister_code(KC_RSFT);
    //     #ifdef KEYBOARD_planck_rev5
    //       PORTE |= (1<<6);
    //     #endif
    //   }
    //   return false;
    //   break;
      case SENS:
      if (record->event.pressed) {
      sensAdj = !sensAdj;
      return false;
      break;
      }
  }
  return true;
}

bool muse_mode = false;
uint8_t x;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {


  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
      if (IS_LAYER_ON(_RAISE)) {
          if (clockwise) {
                register_code(KC_LALT);
                tap_code(KC_DOWN);
                unregister_code(KC_LALT);
            } else {
                register_code(KC_LALT);
                tap_code(KC_UP);
                unregister_code(KC_LALT);
            }
            } else if (IS_LAYER_ON(_LOWER)){
        if (clockwise) {
                register_code(KC_LCTRL);
                tap_code(KC_Z);
                unregister_code(KC_LCTRL);
            } else {
                register_code(KC_LCTL);
                register_code(KC_LSFT);
                tap_code(KC_Z);
                unregister_code(KC_LSFT);
                unregister_code(KC_LCTL);
            }
            } else if (sensAdj) {
                if(clockwise && sensVal > 1) {
                    sensVal--;
                    // if (sensVal == 1) {
                    //      PLAY_SONG(sens1);
                    //      } else if (sensVal == 2) {
                    //      PLAY_SONG(sens2);
                    //      } else if (sensVal == 3) {
                    //      PLAY_SONG(sens3);
                    //      } else if (sensVal == 4) {
                    //      PLAY_SONG(sens4);
                    //      }
                  } else {
                if (sensVal < 5) {
                    sensVal++;
                    // if (sensVal == 2) {
                    //      PLAY_SONG(sens2);
                    //      } else if (sensVal == 3) {
                    //      PLAY_SONG(sens3);
                    //      } else if (sensVal == 4) {
                    //      PLAY_SONG(sens4);
                    //      } else if (sensVal == 5) {
                    //      PLAY_SONG(sens5);
                    //      }
        }
                }
  } else {
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
        }

    }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_song);
        #endif
        layer_on(_ADJUST);
      } else {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(plover_gb_song);
        #endif
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

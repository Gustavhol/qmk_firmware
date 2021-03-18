#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     * ,-----------------------,
     * |  7  |  8  |  9  |  /  |
     * |-----+-----+-----+-----|
     * |  4  |  5  |  6  |  *  |
     * |-----+-----+-----+-----|
     * |  1  |  2  |  3  |  -  |
     * |-----+-----+-----+-----|
     * |  0  |  .  |  =  |  +  |
     * `-----------------------'
     */
    LAYOUT_ortho_4x4(
        /* KC_P7, KC_P8,   KC_P9,      KC_MPLY, */
        /* KC_P4, KC_P5,   KC_P6,      KC_PAST, */
        /* KC_P1, KC_P2,   KC_P3,      KC_PMNS, */
        /* KC_P0, KC_PDOT, KC_PEQL,    KC_PPLS */

        G(A(KC_0)), G(A(KC_1)), G(A(KC_2)), KC_MPLY,
        G(A(KC_3)), G(A(KC_4)), G(A(KC_5)), G(A(KC_6)),
        G(A(KC_7)), G(A(KC_8)), G(A(KC_9)), G(A(KC_Y)),
        G(A(KC_U)), G(A(KC_I)), G(A(KC_O)), G(A(KC_P)) )

};

// Set led state during powerup
void keyboard_post_init_user(void) { writePinHigh(LED_RED); }

void encoder_update_user(uint8_t index, bool clockwise) {
    /*
    Rev1.1                      Rev1
    ,-----------------------,   ,-----------------------,
    |  E1 |  E2 |  E3 |  E4 |   |  E1 |     |     |  E2 |
    |-----+-----+-----+-----|   |-----+-----+-----+-----|
    |     |     |     |  E3 |   |     |     |     |     |
    |-----+-----+-----+-----|   |-----+-----+-----+-----|
    |     |     |     |  E2 |   |     |     |     |     |
    |-----+-----+-----+-----|   |-----+-----+-----+-----|
    |     |     |     |  E1 |   |     |     |     |     |
    `-----------------------'   `-----------------------'
     */

    // First encoder (E1)
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_F17);
        } else {
            tap_code(KC_F18);
        }
        // Second encoder (E2)
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
        // Third encoder (E3)
    } else if (index == 2) {
        if (clockwise) {
            tap_code(KC_F21);
        } else {
            tap_code(KC_F22);
        }
        // Forth encoder (E4)
    } else if (index == 3) {
        if (clockwise) {
            tap_code(KC_F23);
        } else {
            tap_code(KC_F24);
        }
    }
}

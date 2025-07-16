#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { 

// +------+----+----+------+
// | RE1  |  1 |  2 | RE2  |
// +------+----+----+------+
// | 3    |  4 |  5 | 6    |
// +------+----+----+------+
// | 7    |  8 |  9 | 10   |
// +------+----+----+------+
// | None | 11 | 12 | None |
// +------+----+----+------+


    [0] = LAYOUT_ortho_4x4(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,
        KC_F5,   KC_F6,   KC_F7,   KC_F8,
        KC_F9,   KC_F10,   KC_F11,   KC_F12,
        KC_NO,   KC_F13,   KC_BOOT,  KC_NO
    ),
    [1] = LAYOUT_ortho_4x4(
        KC_NO, KC_TRNS, KC_TRNS, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO, KC_TRNS, KC_TRNS, KC_NO
    ),
    [2] = LAYOUT_ortho_4x4(
        KC_NO, KC_TRNS, KC_TRNS, KC_NO,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_NO, KC_TRNS, KC_TRNS, KC_NO
    )
};
enum layer_names {
    _MEDIA,
    _FIGMA,
    _GAME
};

#ifdef OLED_ENABLE
// Draw to OLED
bool oled_task_user() {
    // Set cursor position
    oled_set_cursor(0, 1);
    
    // Write text to OLED
    oled_write("Hello World!", false);
    
    return false;
}

#endif

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD)},
    [1] = { ENCODER_CCW_CW(UG_HUED, UG_HUEU)},
    [2] = { ENCODER_CCW_CW(UG_VALD, UG_VALU)},
};
#endif




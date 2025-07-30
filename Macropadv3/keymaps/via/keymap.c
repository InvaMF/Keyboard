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
        KC_NO,   KC_F13,   QK_BOOT,  KC_NO
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




#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [2] = { ENCODER_CCW_CW(MS_WHLU, MS_WHLD),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
};
#endif

void keyboard_post_init_user(void) {
    rgblight_enable_noeeprom();                // Active les LEDs RGB
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT); // Mode lumière fixe
    rgblight_sethsv_noeeprom(HSV_RED);      // Couleur rouge doux (par exemple)
}


layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case 0:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
            rgblight_sethsv_noeeprom(HSV_RED);  // RED
            break;
        case 1:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
            rgblight_sethsv_noeeprom(HSV_BLUE);  // BLUE rgblight_sethsv_noeeprom(213, 255, 255);
            break;
        case 2:
            rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING);
            rgblight_sethsv_noeeprom(HSV_GREEN);  // GREEN
            break;
    }
    return state;
}


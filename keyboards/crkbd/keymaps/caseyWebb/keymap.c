/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2022 @caseyWebb

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
#include <stdio.h>

enum tap_dance{
    TD_COLON,
    TD_NAV_LAYER
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_COLON] = ACTION_TAP_DANCE_DOUBLE(KC_SCLN, KC_COLN),
    [TD_NAV_LAYER] = ACTION_TAP_DANCE_DOUBLE(MO(2), MO(3))
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
    KC_TAB,              KC_QUOT,      KC_COMM, KC_DOT, KC_P, KC_Y,    KC_F,  KC_G, KC_C, KC_R, KC_L, KC_SLASH,
    MT(KC_LSFT, KC_ESC), KC_A,         KC_O,    KC_E,   KC_U, KC_I,    KC_D,  KC_H, KC_T, KC_N, KC_S, KC_BSPC,
    KC_GRAVE,            TD(TD_COLON), KC_Q,    KC_J,   KC_K, KC_X,    KC_B,  KC_M, KC_W, KC_V, KC_Z, KC_ENT,

    KC_LCMD, MO(1), MO(2),    MT(MOD_LALT, KC_TAB), MT(MOD_RSFT, KC_SPC), KC_RCTL
  ),

  [1] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, KC_HASH, KC_EXLM, KC_LCBR,     KC_RCBR,     KC_LABK,      KC_EQUAL, KC_7, KC_8, KC_9, KC_ASTR,  KC_TRANSPARENT,
    KC_TRANSPARENT, KC_CIRC, KC_DLR,  KC_LPRN,     KC_RPRN,     KC_PIPE,      KC_RABK,  KC_4, KC_5, KC_6, KC_MINUS, KC_TRANSPARENT,
    KC_AMPR,        KC_PERC, KC_AT,   KC_LBRACKET, KC_RBRACKET, KC_BSLASH,    KC_DOT,   KC_1, KC_2, KC_3, KC_PLUS,  KC_TRANSPARENT,

    KC_TRANSPARENT, _______,  MO(4),    KC_TRANSPARENT, KC_TRANSPARENT, KC_0
  ),

  [2] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,    KC_PGUP,        KC_HOME,        KC_UP,          KC_END,         KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,    KC_PGDOWN,      KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, MO(4), _______,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [3] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,    KC_MS_WH_UP,    KC_MS_BTN1,     KC_MS_UP,       KC_MS_BTN2,     KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,    KC_MS_WH_DOWN,  KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, KC_TRANSPARENT, _______,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),

  [4] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_UP,   KC_TRANSPARENT,    MEH(KC_P),      MEH(KC_G),      MEH(KC_C),      MEH(KC_R),      KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_VOL_DOWN, KC_TRANSPARENT,    MEH(KC_J),      MEH(KC_H),      MEH(KC_T),      MEH(KC_N),      KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_MUTE,     KC_TRANSPARENT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,

    KC_TRANSPARENT, _______, _______,    KC_TRANSPARENT, KC_RCMD, KC_TRANSPARENT
  )
};

#ifdef AUTO_SHIFT_ENABLE
bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        case KC_SLASH:
        case KC_GRAVE:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_1: register_code16((shifted) ? KC_F1 : KC_1); break;
        case KC_2: register_code16((shifted) ? KC_F2 : KC_2); break;
        case KC_3: register_code16((shifted) ? KC_F3 : KC_3); break;
        case KC_4: register_code16((shifted) ? KC_F4 : KC_4); break;
        case KC_5: register_code16((shifted) ? KC_F5 : KC_5); break;
        case KC_6: register_code16((shifted) ? KC_F6 : KC_6); break;
        case KC_7: register_code16((shifted) ? KC_F7 : KC_7); break;
        case KC_8: register_code16((shifted) ? KC_F8 : KC_8); break;
        case KC_9: register_code16((shifted) ? KC_F9 : KC_9); break;
        case KC_0: register_code16((shifted) ? KC_F10 : KC_0); break;
        case KC_GRAVE: register_code16((shifted) ? KC_F12 : KC_GRAVE); break;
        case KC_A ... KC_Z:
        case KC_SLASH:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LCMD));
            }
            register_code16(keycode);
            break;
        default:
            return;
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {
        case KC_1: unregister_code16((shifted) ? KC_F1 : KC_1); break;
        case KC_2: unregister_code16((shifted) ? KC_F2 : KC_2); break;
        case KC_3: unregister_code16((shifted) ? KC_F3 : KC_3); break;
        case KC_4: unregister_code16((shifted) ? KC_F4 : KC_4); break;
        case KC_5: unregister_code16((shifted) ? KC_F5 : KC_5); break;
        case KC_6: unregister_code16((shifted) ? KC_F6 : KC_6); break;
        case KC_7: unregister_code16((shifted) ? KC_F7 : KC_7); break;
        case KC_8: unregister_code16((shifted) ? KC_F8 : KC_8); break;
        case KC_9: unregister_code16((shifted) ? KC_F9 : KC_9); break;
        case KC_0: unregister_code16((shifted) ? KC_F10 : KC_0); break;
        case KC_GRAVE: unregister_code16((shifted) ? KC_F12 : KC_GRAVE); break;
        case KC_A ... KC_Z:
        case KC_SLASH:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LCMD));
            }
            unregister_code16(keycode);
            break;
        default:
            return;
    }
}
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
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

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_ENABLE

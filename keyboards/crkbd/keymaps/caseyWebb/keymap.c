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

enum custom_keycodes {
  KC_DOT_EXLM = SAFE_RANGE,
  KC_COMM_SCLN
};

enum combos {
  SPOTLIGHT,
  MEH
};

const uint16_t PROGMEM meh_combo[] = {KC_RSFT, MO(1), COMBO_END};
const uint16_t PROGMEM spotlight_combo[] = {LT(2, KC_SPC), MT(MOD_RGUI, KC_ESC), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(meh_combo, KC_MEH),
  COMBO(spotlight_combo, RGUI(KC_SPC)),
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
    KC_ESC,   KC_QUOT, KC_COMM_SCLN, KC_DOT_EXLM, KC_P, KC_Y, KC_F,  KC_G, KC_C, KC_R, KC_L, KC_SLASH,
    KC_BSPC,  KC_A,    KC_O,         KC_E,        KC_U, KC_I, KC_D,  KC_H, KC_T, KC_N, KC_S, KC_MINUS,
    KC_GRAVE, KC_COLN, KC_Q,         KC_J,        KC_K, KC_X, KC_B,  KC_M, KC_W, KC_V, KC_Z, KC_ENT,

    KC_RALT, KC_RSFT, MO(1),                                  LT(2, KC_SPC), MT(MOD_RGUI, KC_TAB), KC_RCTL
  ),

  [1] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, KC_HASH, KC_PERC, KC_LCBR,     KC_RCBR,     KC_LABK,      KC_EQUAL, KC_7, KC_8, KC_9, KC_ASTR, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_CIRC, KC_DLR,  KC_LPRN,     KC_RPRN,     KC_PIPE,      KC_RABK,  KC_4, KC_5, KC_6, KC_PLUS, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_AMPR, KC_AT,   KC_LBRACKET, KC_RBRACKET, KC_BSLASH,    KC_UNDS,  KC_1, KC_2, KC_3, KC_DOT,  KC_TRANSPARENT,

    KC_RCMD, _______, _______,                                                KC_TRANSPARENT, KC_0, KC_TRANSPARENT
  ),

  [2] = LAYOUT_split_3x6_3(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PGUP,        LCMD(KC_LEFT),       KC_UP,               LCMD(KC_RIGHT),      KC_TRANSPARENT, KC_AUDIO_VOL_UP,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_PGDOWN,      KC_LEFT,             KC_DOWN,             KC_RIGHT,            KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, KC_TRANSPARENT, KC_AUDIO_MUTE,

    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case  KC_DOT_EXLM:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_RSHIFT)){
          register_code16(KC_EXLM);
        } else {
          register_code(KC_DOT);
        }
      } else {
        unregister_code16(KC_EXLM);
        unregister_code(KC_DOT);
      }
      return false;
    case KC_COMM_SCLN:
      if (record->event.pressed){
        if (get_mods() & MOD_BIT(KC_RSHIFT)) {
          unregister_code(KC_RSHIFT);
          register_code(KC_SCLN);
          register_code(KC_RSHIFT);
        } else {
          register_code(KC_COMM);
        }
      } else {
        unregister_code(KC_SCLN);
        unregister_code(KC_LSHIFT);
        unregister_code(KC_COMM);
      }
      return false;
    default:
      return true;
  }
}

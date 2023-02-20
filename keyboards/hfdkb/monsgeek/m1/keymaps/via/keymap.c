/* Copyright (C) 2022 jonylee@hfd
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

enum __layers {
    WIN_B,
    WIN_WASD,
    WIN_FN,
    MAC_B,
    MAC_WASD,
    MAC_FN
};
enum custom_keycodes {
    KC_MISSION_CONTROL = QK_USER,
    KC_LAUNCHPAD,
    KC_RESET
};

#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)
#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [WIN_B] = LAYOUT( /* Base */
		KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,     KC_F12,     KC_DEL,              KC_MUTE, 
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,    KC_8,    KC_9,     KC_0,     KC_MINS,    KC_EQL,     KC_BSPC,             KC_HOME, 
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,     KC_P,     KC_LBRC,    KC_RBRC,    KC_BSLS,             KC_PGUP, 
		KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT,    KC_NUHS,    KC_ENT,              KC_PGDN, 
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  KC_NUBS,                KC_RSFT,    KC_UP,   KC_END, 
		KC_LCTL, KC_LGUI, KC_LALT,                  KC_SPC,                           KC_RALT,  MO(WIN_FN),   KC_RCTL,    KC_LEFT,            KC_DOWN, KC_RGHT),

    [WIN_WASD] = LAYOUT( /* Base */
		KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6,  KC_F7,   KC_F8,   KC_F9,    KC_F10,   KC_F11,     KC_F12,     KC_DEL,              KC_MUTE, 
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,    KC_8,    KC_9,     KC_0,     KC_MINS,    KC_EQL,     KC_BSPC,             KC_HOME, 
		KC_TAB,  KC_Q,    KC_UP,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,    KC_I,    KC_O,     KC_P,     KC_LBRC,    KC_RBRC,    KC_BSLS,            KC_PGUP, 
		KC_CAPS, KC_LEFT, KC_DOWN,  KC_RGHT,    KC_F,   KC_G,   KC_H,   KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_QUOT, KC_NUHS,   KC_ENT,              KC_PGDN, 
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  KC_NUBS,                  KC_RSFT,   KC_W,   KC_END, 
		KC_LCTL, KC_LGUI, KC_LALT,                  KC_SPC,                           KC_RALT,  MO(WIN_FN),   KC_RCTL,    KC_A,                KC_S, KC_D),


    [WIN_FN] = LAYOUT( /* FN */
		KC_ESC,  KC_MYCM, KC_MAIL, KC_WSCH, KC_WHOM,KC_MSEL,KC_MPLY,KC_MPRV,KC_MNXT,KC_F9,      KC_F10,  KC_F11,     KC_F12,     KC_DEL,                 RGB_MOD, 
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,       KC_0,    RGB_SPD,    RGB_SPI,    KC_BSPC,                KC_HOME, 
		KC_TAB,  KC_Q,    TG(WIN_WASD), KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_INS, DF(MAC_B),  KC_PSCR, KC_LBRC,    KC_RBRC,    RGB_MOD,            KC_PGUP, 
		KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   RGB_TOG,    KC_SCLN, KC_QUOT,   RGB_MOD,  KC_ENT,                     KC_PGDN, 
		KC_LSFT, KC_Z,    KC_X,    KC_CALC, KC_V,   KC_B,   KC_N,   KC_MUTE, KC_VOLD,KC_VOLU,   KC_SLSH, KC_NUBS,               KC_RSFT,        RGB_VAI, KC_END, 
		KC_LCTL, MAGIC_TOGGLE_GUI, KC_LALT,                  KC_SPC,                             KC_RALT, MO(WIN_FN), KC_RCTL,   RGB_SAD,       RGB_VAD, RGB_SAI),

    [MAC_B] = LAYOUT( /* Base */
		KC_ESC,  KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, KC_F5,  KC_F6, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU,      KC_DEL,             KC_MUTE, 
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,       KC_0,   KC_MINS,    KC_EQL,     KC_BSPC,            KC_HOME, 
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,       KC_P,   KC_LBRC,    KC_RBRC,    KC_BSLS,            KC_PGUP, 
		KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,       KC_SCLN, KC_QUOT,   KC_NUHS,    KC_ENT,              KC_PGDN, 
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT,     KC_SLSH, KC_NUBS,               KC_RSFT,     KC_UP,  KC_END, 
		KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                                    KC_RGUI, MO(MAC_FN), KC_RCTL,   KC_LEFT,    KC_DOWN, KC_RGHT),

    [MAC_WASD] = LAYOUT( /* Base */
		KC_ESC,  KC_BRID, KC_BRIU, KC_MCTL, KC_LPAD, KC_F5,  KC_F6, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD,  KC_VOLU,      KC_DEL,             KC_MUTE, 
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,       KC_0,   KC_MINS,    KC_EQL,     KC_BSPC,            KC_HOME, 
		KC_TAB,  KC_Q,    KC_UP,   KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,       KC_P,   KC_LBRC,    KC_RBRC,    KC_BSLS,            KC_PGUP, 
		KC_CAPS, KC_LEFT, KC_DOWN, KC_RGHT, KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,       KC_SCLN, KC_QUOT,   KC_NUHS,    KC_ENT,             KC_PGDN, 
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT,     KC_SLSH, KC_NUBS,               KC_RSFT,     KC_W,  KC_END, 
		KC_LCTL, KC_LALT, KC_LGUI,                   KC_SPC,                                    KC_RGUI, MO(MAC_FN), KC_RCTL,   KC_A,        KC_S,  KC_D),

    [MAC_FN] = LAYOUT( /* FN */
		KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,  KC_F6, KC_F7,   KC_F8,  KC_F9,      KC_F10, KC_F11,     KC_F12,     KC_DEL,             RGB_MOD, 
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,       KC_0,    RGB_SPD,    RGB_SPI,   KC_BSPC,           KC_HOME, 
		KC_TAB,  KC_Q,    TG(MAC_WASD), KC_E,    KC_R,   KC_T,   KC_Y,   KC_U,   KC_INS, DF(WIN_B),  KC_PSCR, KC_LBRC, KC_RBRC, RGB_MOD,            KC_PGUP, 
		KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   RGB_TOG,    KC_SCLN, KC_QUOT,   RGB_MOD,    KC_ENT,             KC_PGDN, 
		KC_LSFT, KC_Z,    KC_X,    KC_CALC, KC_V,   KC_B,   KC_N,   KC_MUTE, KC_VOLD,KC_VOLU,   KC_SLSH, KC_NUBS,               KC_RSFT,   RGB_VAI, KC_END, 
		KC_LCTL, KC_LALT, KC_LGUI,                 KC_SPC,                                      KC_RGUI, MO(MAC_FN), KC_RCTL,   RGB_SAD,   RGB_VAD, RGB_SAI)
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
#ifdef VIA_ENABLE
            case KC_RESET:
            if (record->event.pressed) {
                via_eeprom_set_valid(false);
                eeconfig_init_via();
            }
            return false;
#endif
    }
    return true;
}


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [WIN_B] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [WIN_WASD] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [WIN_FN] = { ENCODER_CCW_CW(RGB_VAI, RGB_VAD) },
    [MAC_B] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [MAC_WASD] = { ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [MAC_FN] = { ENCODER_CCW_CW(RGB_VAI, RGB_VAD) }
};
#endif


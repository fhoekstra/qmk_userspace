/*
 * Copyright 2021 Quentin LEBASTARD <qlebastard@gmail.com>
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

#include "oneshot.h"

// Layer keys (abstraction needed for Callum-style)
#define LA_SYM MO(_SYM)
#define LA_NUM MO(_NUM)
// Modifiers
#define OS_LGUI OSM(MOD_LGUI)
#define OS_RGUI OSM(MOD_RGUI)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_LCTL OSM(MOD_LCTL)
#define OS_RCTL OSM(MOD_RCTL)
#define OS_LALT OSM(MOD_LALT)
#define OS_RALT OSM(MOD_RALT)
// Copy-paste shortcodes
#define MYCOPY C(KC_C)
#define MYPASTE C(KC_V)
#define MYSCOPY S(C(KC_C))
#define MYSPASTE S(C(KC_V))

enum custom_layers {
    _BASE,
    _NUM,
    _SYM,
    _EXTRA,
};

enum keycodes {
    // Callum One-Shot Mods:
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_GUI,
};

const uint16_t PROGMEM combo_jk[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_jkl[] = {KC_J, KC_K, KC_L, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_jk, KC_ESC),
    COMBO(combo_jkl, KC_ENT),
};
uint16_t COMBO_LEN = ARRAY_SIZE(key_combos);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_TAB  ,  KC_Q  ,  KC_W  , KC_E   ,  KC_R  , KC_T   ,                       KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  , KC_BSPC,
        //|--------+----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----+--------|
           OS_LCTL ,  KC_A  ,  KC_S  , KC_D   ,  KC_F  , KC_G   ,                       KC_H  ,  KC_J  ,  KC_K  ,  KC_L  , KC_SCLN, KC_QUOT,
        //|--------+----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----+--------|
           OS_LSFT  , KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  , KC_B   ,                       KC_N  ,  KC_M  , KC_COMM, KC_DOT , KC_SLSH, KC_ESC,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                OS_LSFT, KC_SPC , LA_NUM ,    LA_SYM , KC_TAB , KC_BSPC
                                            //`--------------------------'  `--------------------------'
        ),

    [_NUM] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_TAB  , KC_PERC, KC_PAST, KC_PMNS, KC_PLUS, KC_HOME,                       KC_END,  KC_7  ,  KC_8  ,  KC_9  , XXXXXXX, KC_BSPC,
        //|--------+----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----+--------|
           OS_LCTL , OS_GUI , OS_ALT , OS_SHFT, OS_CTRL, KC_SLSH,                        KC_0 ,  KC_4  ,  KC_5  ,  KC_6  , KC_DEL , XXXXXXX,
        //|--------+----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----+--------|
           OS_LSFT , KC_EQL , KC_EXLM,  KC_AT , KC_HASH, KC_BSLS,                       KC_EQL,  KC_1  ,  KC_2  ,  KC_3  , KC_INS , XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_TRNS, KC_TRNS, _______,   _______ , KC_TRNS, KC_TRNS
                                            //`--------------------------'  `--------------------------'
        ),

    [_SYM] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           KC_TAB  , KC_TILD, KC_MINS, KC_DQUO, KC_LPRN, KC_CIRC,                      KC_DLR , KC_RPRN, KC_AMPR, KC_ASTR, XXXXXXX , KC_BSPC,
        //|--------+----*---+---*----+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----+--------|
           OS_LCTL , KC_GRV , KC_UNDS, KC_QUOT,KC_COLON, XXXXXXX,                      KC_LEFT, KC_DOWN, KC_UP  ,KC_RIGHT, KC_UNDS, XXXXXXX,
        //|--------+----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----+--------|
           OS_LSFT , KC_PIPE, XXXXXXX, KC_LCBR, KC_LBRC, KC_LABK,                      KC_RABK, KC_RBRC, KC_RCBR, XXXXXXX, KC_MINS, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_TRNS, KC_TRNS, _______,   _______ , KC_TRNS, KC_TRNS
                                            //`--------------------------'  `--------------------------'
        ),

    [_EXTRA] = LAYOUT_split_3x6_3(
        //,-----------------------------------------------------.                    ,-----------------------------------------------------.
           QK_BOOT , RGB_HUI, RGB_SAI, MYCOPY , MYPASTE, RGB_VAI,                      KC_PSCR,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , XXXXXXX,
        //|--------+----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----+--------|
           RGB_TOG , OS_GUI , OS_ALT , OS_SHFT, OS_CTRL, XXXXXXX,                      KC_PGUP,  KC_F4 ,  KC_F5 ,  KC_F6 , KC_F11 , XXXXXXX,
        //|--------+----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----+--------|
           RGB_MOD , RGB_HUD, RGB_SAD, MYSCOPY,MYSPASTE, RGB_VAD,                     KC_PGDN,  KC_F1 ,  KC_F2 ,  KC_F3 , KC_F12,  XXXXXXX,
        //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                                KC_TRNS, KC_TRNS, _______ ,    _______ , KC_TRNS, KC_TRNS
                                            //`--------------------------'  `--------------------------'
        )};

// Callum One-Shot Mods:

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NUM:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NUM:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_GUI:
        return true;
    default:
        return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_gui_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_oneshot(
        &os_shft_state, KC_LSFT, OS_SHFT,
        keycode, record
    );
    update_oneshot(
        &os_ctrl_state, KC_LCTL, OS_CTRL,
        keycode, record
    );
    update_oneshot(
        &os_alt_state, KC_LALT, OS_ALT,
        keycode, record
    );
    update_oneshot(
        &os_gui_state, KC_LGUI, OS_GUI,
        keycode, record
    );

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _NUM, _SYM, _EXTRA);
}

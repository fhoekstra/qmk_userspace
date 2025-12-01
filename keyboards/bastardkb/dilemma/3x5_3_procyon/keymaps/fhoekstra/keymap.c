#include QMK_KEYBOARD_H

#include "oneshot.h"

// Layer keys (abstraction needed for Callum-style)
#define LA_SYM MO(_SYM)
#define LA_EXT MO(_EXT)
#define LA_SHRT MO(_SHRT)
#define LA_NUM MO(_NUM)

// Trackpad/pointer layers
#define PT_Z LT(LAYER_POINTER, KC_Z)
#define PT_SLSH LT(LAYER_POINTER, KC_SLSH)

#ifndef POINTING_DEVICE_ENABLE
#    define DRGSCRL KC_NO
#    define DPI_MOD KC_NO
#    define S_D_MOD KC_NO
#    define SNIPING KC_NO
#endif // !POINTING_DEVICE_ENABLE

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
// Misc keycodes
#define VOLUP KC_KB_VOLUME_UP
#define VOLDN KC_KB_VOLUME_DOWN
#define BRTUP KC_BRIGHTNESS_UP
#define MUTE KC_KB_MUTE
#define BRTDN KC_BRIGHTNESS_DOWN
#define SHFT_G S(KC_G)
#define C_TAB C(KC_TAB)
#define CS_TAB S(C(KC_TAB))
#define A_TAB A(KC_TAB)
#define AS_TAB S(A(KC_TAB))
#define EURO RALT(KC_5)
#define FWD A(KC_RIGHT)
#define BCK A(KC_LEFT)
#define FND C(KC_F)

enum custom_layers {
    _BASE,
    _EXT,
    _NUM,
    _SHRT,
    _SYM,
    _FUNC,
    LAYER_POINTER,
};

enum keycodes {
    // Callum One-Shot Mods:
    // Custom oneshot mod implementation with no timers.
    OS_SHFT = SAFE_RANGE,
    OS_CTRL,
    OS_ALT,
    OS_GUI,
    // UnDead 🧟 keys: add a space after a dead key to un-dead them
    KC_UNDEAD_ON,
    KC_UNDEAD_OFF,
};

const uint16_t PROGMEM combo_bottom_inner[] = {KC_B, KC_N, COMBO_END};
const uint16_t PROGMEM combo_df[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM combo_below_df[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_below_df_sym[] = {KC_MINS, KC_LPRN, COMBO_END};
const uint16_t PROGMEM combo_below_df_ext[] = {MYSCOPY, MYSPASTE, COMBO_END};
const uint16_t PROGMEM combo_below_jk[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_below_jk_num[] = {KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM combo_below_jk_func[] = {KC_F4, KC_F5, COMBO_END};
const uint16_t PROGMEM combo_below_jk_ext[] = {KC_BSPC, KC_HOME, COMBO_END};
// UnDead mode
const uint16_t PROGMEM combo_qz[] = {KC_Q, KC_Z, COMBO_END};
const uint16_t PROGMEM combo_psl[] = {KC_P, KC_SLSH, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_bottom_inner, CW_TOGG),
    COMBO(combo_df, KC_ESC),
    COMBO(combo_below_df, KC_TAB),
    COMBO(combo_below_df_ext, KC_TAB),
    COMBO(combo_below_df_sym, KC_TAB),
    COMBO(combo_below_jk, KC_TAB),
    COMBO(combo_below_jk_ext, KC_TAB),
    COMBO(combo_below_jk_num, KC_TAB),
    COMBO(combo_below_jk_func, KC_TAB),
    COMBO(combo_qz, KC_UNDEAD_ON),
    COMBO(combo_psl, KC_UNDEAD_OFF),
};
uint16_t COMBO_LEN = ARRAY_SIZE(key_combos);

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT_split_3x5_3(
        //,--------------------------------------------.                    ,--------------------------------------------.
             KC_Q  ,  KC_W  , KC_E   ,  KC_R  , KC_T   ,                       KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  ,
        //|----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----|
             KC_A  ,  KC_S  , KC_D   ,  KC_F  , KC_G   ,                       KC_H  ,  KC_J  ,  KC_K  ,  KC_L  , KC_QUOT,
        //|----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----|
             PT_Z  ,  KC_X  ,  KC_C  ,  KC_V  , KC_B   ,                       KC_N  ,  KC_M  , KC_COMM, KC_DOT , KC_SLSH,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                       LA_EXT , OS_LSFT, LA_NUM ,    LA_SHRT, KC_SPC , LA_SYM
                                   //`--------------------------'  `--------------------------'
        ),

    [_EXT] = LAYOUT_split_3x5_3(
        //,--------------------------------------------.                    ,--------------------------------------------.
            KC_ESC ,  BCK   ,  FND   ,  FWD   , KC_INS ,                      KC_INS , KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX,
        //|----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----|
            OS_GUI , OS_ALT , OS_SHFT, OS_CTRL, OS_RALT,                      KC_LEFT, KC_DOWN,  KC_UP ,KC_RIGHT, KC_DEL ,
        //|----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----|
            XXXXXXX, XXXXXXX, KC_TAB , KC_ESC, XXXXXXX,                      XXXXXXX, KC_BSPC, KC_HOME, KC_END , KC_PSCR,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                       _______, _______, _______,   _______ , KC_ENT , _______
                                   //`--------------------------'  `--------------------------'
        ),

    [_SYM] = LAYOUT_split_3x5_3(
        //,--------------------------------------------.                    ,--------------------------------------------.
            KC_TILD, KC_EQL , KC_PLUS, KC_LCBR, KC_PERC,                      KC_AMPR, KC_RCBR, KC_ASTR, KC_EXLM,  KC_AT ,
        //|----*---+----*---+---*----+---**---+--------|                    |--------+---**---+---*----+---*----+---*----|
            KC_GRV ,KC_COLON, KC_UNDS, KC_MINS, KC_LBRC,                      KC_RBRC, OS_CTRL, OS_SHFT, OS_ALT , OS_GUI ,
        //|----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----|
            KC_PIPE, KC_SCLN, KC_HASH, KC_LPRN,  EURO  ,                      XXXXXXX, KC_RPRN, KC_CIRC, KC_DLR , KC_BSLS,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                       _______, _______, _______,   _______ , _______, _______
                                   //`--------------------------'  `--------------------------'
        ),

    [_FUNC] = LAYOUT_split_3x5_3( // SYM + EXT
        //,--------------------------------------------.                    ,--------------------------------------------.
            KC_STOP, KC_MPLY,  VOLDN ,  VOLUP ,  MUTE  ,                      QK_BOOT,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 ,
        //|----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----|
            OS_GUI , OS_ALT , OS_SHFT, OS_CTRL, RM_TOGG,                       BRTUP ,  KC_F4 ,  KC_F5 ,  KC_F6 , KC_F11 ,
        //|----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----|
             MUTE  , XXXXXXX, MYSCOPY,MYSPASTE, RM_NEXT,                       BRTDN ,  KC_F1 ,  KC_F2 ,  KC_F3 , KC_F12 ,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                       _______, _______, _______,   _______ , KC_ENT , _______
                                   //`--------------------------'  `--------------------------'
        ),

    [_NUM] = LAYOUT_split_3x5_3(
        //,--------------------------------------------.                    ,--------------------------------------------.
            AS_TAB , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,  KC_7  ,  KC_8  ,  KC_9  , XXXXXXX,
        //|----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----|
            OS_GUI , OS_ALT , OS_SHFT, OS_CTRL, OS_RALT,                       KC_0  ,  KC_4  ,  KC_5  ,  KC_6  , KC_DOT ,
        //|----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----|
             A_TAB , CS_TAB ,  C_TAB ,  KC_V  , XXXXXXX,                      XXXXXXX,  KC_1  ,  KC_2  ,  KC_3  , KC_SLSH,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                       _______, _______, _______,   _______ , KC_ENT , _______
                                   //`--------------------------'  `--------------------------'
        ),

    [_SHRT] = LAYOUT_split_3x5_3(
        //,--------------------------------------------.                    ,--------------------------------------------.
            AS_TAB , CS_TAB ,  C_TAB ,  A_TAB , XXXXXXX,                     XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----|
            AS_TAB , CS_TAB ,  C_TAB ,  A_TAB , XXXXXXX,                     XXXXXXX , OS_CTRL, OS_SHFT, OS_RALT, OS_GUI ,
        //|----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----|
            XXXXXXX, XXXXXXX, MYSCOPY,MYSPASTE, XXXXXXX,                     XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                       _______, _______, _______,   _______ , _______, _______
                                   //`--------------------------'  `--------------------------'
        ),

/** \brief Mouse emulation and pointer functions. */
  [LAYER_POINTER] = LAYOUT_split_3x5_3(
        //,--------------------------------------------.                    ,--------------------------------------------.
            QK_BOOT,  EE_CLR, XXXXXXX, DPI_MOD, S_D_MOD,                     XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----|
            KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,                     XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----|
            _______, DRGSCRL, SNIPING, MS_BTN3, XXXXXXX,                     XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                       MS_BTN3, MS_BTN2, MS_BTN1,   _______ , _______, _______
                                   //`--------------------------'  `--------------------------'
  ),
};
// clang-format on

// #define DILEMMA_AUTO_SNIPING_ON_LAYER _EXT
#define DILEMMA_MINIMUM_SNIPING_DPI 500
#define DILEMMA_SNIPING_DPI_CONFIG_STEP 200
#define Dilemma_MINIMUM_DEFAULT_DPI 4000
#define Dilemma_MAXIMUM_DEFAULT_DPI 32000
#define Dilemma_DEFAULT_DPI_CONFIG_STEP 4000

#ifdef POINTING_DEVICE_ENABLE
#    ifdef DILEMMA_AUTO_SNIPING_ON_LAYER
layer_state_t layer_state_set_user(layer_state_t state) {
    dilemma_set_pointer_sniping_enabled(layer_state_cmp(state, DILEMMA_AUTO_SNIPING_ON_LAYER));
    return state;
}
#    endif // DILEMMA_AUTO_SNIPING_ON_LAYER
#endif     // POINTING_DEVICE_ENABLE

#ifdef ENCODER_MAP_ENABLE
// clang-format off
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BASE]       = {ENCODER_CCW_CW(MS_WHLD, MS_WHLU),  ENCODER_CCW_CW(KC_VOLU, KC_VOLD)},
    [_EXT]   = {ENCODER_CCW_CW(KC_UP, KC_DOWN),    ENCODER_CCW_CW(KC_RGHT, KC_LEFT)},
    [_NUM] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_SHRT]      = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_SYM]    = {ENCODER_CCW_CW(RM_VALU, RM_VALD),  ENCODER_CCW_CW(RM_SPDU, RM_SPDD)},
    [_FUNC]    = {ENCODER_CCW_CW(RM_NEXT, RM_PREV),  ENCODER_CCW_CW(KC_RGHT, KC_LEFT)},
    [LAYER_POINTER]    = {ENCODER_CCW_CW(RM_HUEU, RM_HUED),  ENCODER_CCW_CW(RM_SATU, RM_SATD)},
};
// clang-format on
#endif // ENCODER_MAP_ENABLE

// Caps word: when do we continue when do we stop?
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
            return true;

        default:
            return false;  // Deactivate Caps Word.
    }
}

// Callum One-Shot Mods:

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_EXT:
    case LA_SHRT:
    case LA_NUM:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_EXT:
    case LA_SHRT:
    case LA_NUM:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_RALT:
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

bool undead_keys_enabled = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Callum
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
        &os_alt_state, KC_RALT, OS_RALT,
        keycode, record
    );
    update_oneshot(
        &os_gui_state, KC_LGUI, OS_GUI,
        keycode, record
    );

    if (keycode == KC_UNDEAD_ON) {
        undead_keys_enabled = true;
    } else if (keycode == KC_UNDEAD_OFF) {
        undead_keys_enabled = false;
    }

    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record){
    if (undead_keys_enabled) {
        switch (keycode) {
            case KC_GRV:
            case KC_QUOT:
            case KC_DQUO:
            case KC_TILD:
            case KC_CIRC:
                if (record->event.pressed) {
                    tap_code(KC_SPACE);
                }
                break;
        }
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _EXT, _SYM, _FUNC);
}

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
    OS_RALTC,
    OS_GUIC,
    // UnDead 🧟 keys: add a space after a dead key to un-dead them
    KC_UNDEAD_ON,
    KC_UNDEAD_OFF,
    KC_IS_MAC,
    KC_IS_NOT_MAC,
    // Custom keycodes for common shortcuts, to translate between Mac and other OS
    CLOSE_T,
    OPEN_T,
    FIND,
    FWD,
    BACK,
    MYCUT,
    MYCOPY,
    MYPASTE,
    MYSCOPY,
    MYSPASTE,
    REFRESH,
    NXT_WRD,
    PRV_WRD,
    NXT_WND,
    PRV_WND,
    NEXT_WS,
    PREV_WS,
};

const uint16_t PROGMEM combo_bottom_inner[]  = {KC_B, KC_N, COMBO_END};
const uint16_t PROGMEM combo_l_quote[]       = {KC_L, KC_QUOT, COMBO_END};
const uint16_t PROGMEM combo_below_df[]      = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM combo_below_df_sym[]  = {KC_MINS, KC_LPRN, COMBO_END};
const uint16_t PROGMEM combo_below_df_ext[]  = {MYSCOPY, MYSPASTE, COMBO_END};
const uint16_t PROGMEM combo_below_jk[]      = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM combo_below_jk_num[]  = {KC_4, KC_5, COMBO_END};
const uint16_t PROGMEM combo_below_jk_func[] = {KC_F4, KC_F5, COMBO_END};
const uint16_t PROGMEM combo_below_jk_ext[]  = {KC_BSPC, KC_HOME, COMBO_END};
// UnDead mode
const uint16_t PROGMEM combo_odot[] = {KC_O, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_psl[]  = {KC_P, KC_SLSH, COMBO_END};
// Temporary manual Mac mode switch
const uint16_t PROGMEM combo_wx[]   = {KC_W, KC_X, COMBO_END};
const uint16_t PROGMEM combo_ce[]   = {KC_C, KC_E, COMBO_END};
combo_t                key_combos[] = {
    COMBO(combo_bottom_inner, CW_TOGG), COMBO(combo_l_quote, KC_COLON), COMBO(combo_below_df, KC_TAB), COMBO(combo_below_df_ext, KC_TAB), COMBO(combo_below_df_sym, KC_TAB), COMBO(combo_below_jk, KC_TAB), COMBO(combo_below_jk_ext, KC_TAB), COMBO(combo_below_jk_num, KC_TAB), COMBO(combo_below_jk_func, KC_TAB), COMBO(combo_odot, KC_UNDEAD_ON), COMBO(combo_psl, KC_UNDEAD_OFF), COMBO(combo_wx, KC_IS_MAC), COMBO(combo_ce, KC_IS_NOT_MAC),
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
            KC_ESC ,  BACK  ,  FIND  ,  FWD   , KC_INS ,                      KC_INS , KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX,
        //|----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----|
            OS_GUIC, OS_ALT , OS_SHFT, OS_CTRL, OS_RALTC,                      KC_LEFT, KC_DOWN,  KC_UP ,KC_RIGHT, KC_DEL ,
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
            KC_GRV ,KC_COLON, KC_UNDS, KC_MINS, KC_LBRC,                      KC_RBRC, OS_CTRL, OS_SHFT, OS_ALT , OS_GUIC,
        //|----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----|
            KC_PIPE, KC_SCLN, KC_HASH, KC_LPRN, KC_LABK,                      KC_RABK, KC_RPRN, KC_CIRC, KC_DLR , KC_BSLS,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                       _______, _______, _______,   _______ , KC_SPC , _______
                                   //`--------------------------'  `--------------------------'
        ),

    [_FUNC] = LAYOUT_split_3x5_3( // SYM + EXT
        //,--------------------------------------------.                    ,--------------------------------------------.
            KC_STOP, KC_MPLY,  VOLDN ,  VOLUP ,  MUTE  ,                      QK_BOOT,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 ,
        //|----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----|
            OS_GUIC, OS_ALT , OS_SHFT, OS_CTRL, RM_TOGG,                       BRTUP ,  KC_F4 ,  KC_F5 ,  KC_F6 , KC_F11 ,
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
            OS_GUIC, OS_ALT , OS_SHFT, OS_CTRL, OS_RALTC,                      KC_0  ,  KC_4  ,  KC_5  ,  KC_6  , KC_DOT ,
        //|----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----|
             A_TAB , CS_TAB ,  C_TAB ,  KC_V  , XXXXXXX,                      XXXXXXX,  KC_1  ,  KC_2  ,  KC_3  , KC_SLSH,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                       _______, _______, _______,   _______ , KC_ENT , _______
                                   //`--------------------------'  `--------------------------'
        ),

    [_SHRT] = LAYOUT_split_3x5_3(
        //,--------------------------------------------.                    ,--------------------------------------------.
            XXXXXXX, CLOSE_T, MYSCOPY,MYSPASTE, OPEN_T ,                      XXXXXXX, PRV_WRD, NXT_WRD, REFRESH, XXXXXXX,
        //|----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----|
            PRV_WND, CS_TAB ,  C_TAB , NXT_WND, XXXXXXX,                      PREV_WS, XXXXXXX, XXXXXXX, NEXT_WS, XXXXXXX,
        //|----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----|
            XXXXXXX,  MYCUT , MYCOPY , MYPASTE, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------|
                                       _______, _______, _______,   _______ , _______, _______
                                   //`--------------------------'  `--------------------------'
        ),

/** \brief Mouse emulation and pointer functions. */
  [LAYER_POINTER] = LAYOUT_split_3x5_3(
        //,--------------------------------------------.                    ,--------------------------------------------.
            QK_BOOT,  EE_CLR, XXXXXXX, DPI_MOD, S_D_MOD,                     XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //|----*---+----*---+----*---+---**---+--------|                    |--------+---**---+---*----+---*----+---*----|
            KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, XXXXXXX,                     XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
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

// Caps word: when do we continue when do we stop?
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case KC_MINS:
            return true;

        default:
            return false; // Deactivate Caps Word.
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
        case OS_RALTC:
        case OS_GUIC:
            return true;
        default:
            return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state  = os_up_unqueued;
oneshot_state os_ralt_state = os_up_unqueued;
oneshot_state os_gui_state  = os_up_unqueued;

bool undead_keys_enabled  = false;
bool is_mac               = false;
bool is_switching_windows = false;

void handle_window_switching_mode(uint16_t keycode, keyrecord_t *record) {
    // Handle modifier key state for NXT_WND and PRV_WND
    if (is_switching_windows) {
        if (keycode != PRV_WND && keycode != NXT_WND) {
            // Different key pressed, release modifier
            if (is_mac) {
                unregister_code(KC_LGUI);
            } else {
                unregister_code(KC_LALT);
            }
            is_switching_windows = false;
        }
    }
}

void handle_custom_shortcut_keycodes(uint16_t keycode, keyrecord_t *record) {
    handle_window_switching_mode(keycode, record);

    if (record->event.pressed) {
        switch (keycode) {
            case CLOSE_T: // Close browser tab: Cmd+W on Mac, Ctrl+W elsewhere
                if (is_mac) {
                    tap_code16(G(KC_W));
                } else {
                    tap_code16(C(KC_W));
                }
                break;
            case OPEN_T: // Open new browser tab: Cmd+T on Mac, Ctrl+T elsewhere
                if (is_mac) {
                    tap_code16(G(KC_T));
                } else {
                    tap_code16(C(KC_T));
                }
                break;
            case FIND: // Find: Cmd+F on Mac, Ctrl+F elsewhere
                if (is_mac) {
                    tap_code16(G(KC_F));
                } else {
                    tap_code16(C(KC_F));
                }
                break;
            case FWD: // Forward in browser history: Cmd+] on Mac, Alt+Right elsewhere
                if (is_mac) {
                    tap_code16(G(KC_RBRC));
                } else {
                    tap_code16(A(KC_RIGHT));
                }
                break;
            case BACK: // Back in browser history: Cmd+[ on Mac, Alt+Left elsewhere
                if (is_mac) {
                    tap_code16(G(KC_LBRC));
                } else {
                    tap_code16(A(KC_LEFT));
                }
                break;
            case MYCUT: // Cut: Cmd+X on Mac, Ctrl+X elsewhere
                if (is_mac) {
                    tap_code16(G(KC_X));
                } else {
                    tap_code16(C(KC_X));
                }
                break;
            case MYCOPY: // Copy: Cmd+C on Mac, Ctrl+C elsewhere
                if (is_mac) {
                    tap_code16(G(KC_C));
                } else {
                    tap_code16(C(KC_C));
                }
                break;
            case MYPASTE: // Paste: Cmd+V on Mac, Ctrl+V elsewhere
                if (is_mac) {
                    tap_code16(G(KC_V));
                } else {
                    tap_code16(C(KC_V));
                }
                break;
            case MYSCOPY: // Copy in the terminal: Cmd+C on Mac, Shift+Ctrl+C elsewhere
                if (is_mac) {
                    tap_code16(G(KC_C));
                } else {
                    tap_code16(S(C(KC_C)));
                }
                break;
            case MYSPASTE: // Paste in the terminal: Cmd+V on Mac, Shift+Ctrl+V elsewhere
                if (is_mac) {
                    tap_code16(G(KC_V));
                } else {
                    tap_code16(S(C(KC_V)));
                    break;
                    case REFRESH: // Refresh page: Cmd+R on Mac, Ctrl+R elsewhere
                        if (is_mac) {
                            tap_code16(G(KC_R));
                        } else {
                            tap_code16(C(KC_R));
                        }
                        break;
                    case NXT_WND: // Next window: Cmd+` on Mac, Alt+Tab elsewhere
                        if (!is_switching_windows) {
                            if (is_mac) {
                                register_code(KC_LGUI);
                            } else {
                                register_code(KC_LALT);
                            }
                            is_switching_windows = true;
                        }
                        tap_code16(KC_TAB);
                        break;
                    case PRV_WND: // Previous window: Cmd+Shift+` on Mac, Alt+Shift+Tab elsewhere
                        if (!is_switching_windows) {
                            if (is_mac) {
                                register_code(KC_LGUI);
                            } else {
                                register_code(KC_LALT);
                            }
                            is_switching_windows = true;
                        }
                        tap_code16(S(KC_TAB));
                        break;
                    case NEXT_WS: // Next workspace: Cmd+Right on my Mac (changed from Ctrl+Right), Ctrl+Win+Right elsewhere
                        if (is_mac) {
                            tap_code16(G(KC_RIGHT));
                        } else {
                            tap_code16(C(G(KC_RIGHT)));
                        }
                        break;
                    case PREV_WS: // Previous workspace: Cmd+Left on my Mac (changed from Ctrl+Left), Ctrl+Win+Left elsewhere
                        if (is_mac) {
                            tap_code16(G(KC_LEFT));
                        } else {
                            tap_code16(C(G(KC_LEFT)));
                        }
                        break;
                    case NXT_WRD: // Next word: Alt+Right on Mac, Ctrl+Right elsewhere
                        if (is_mac) {
                            tap_code16(A(KC_RIGHT));
                        } else {
                            tap_code16(C(KC_RIGHT));
                        }
                        break;
                    case PRV_WRD: // Previous word: Alt+Left on Mac, Ctrl+Left elsewhere
                        if (is_mac) {
                            tap_code16(A(KC_LEFT));
                        } else {
                            tap_code16(C(KC_LEFT));
                        }
                        break;
                }
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Callum
    update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot(&os_ralt_state, KC_RALT, OS_RALTC, keycode, record);
    update_oneshot(&os_gui_state, KC_LGUI, OS_GUIC, keycode, record);

    if (keycode == KC_UNDEAD_ON) {
        undead_keys_enabled = true;
    } else if (keycode == KC_UNDEAD_OFF) {
        undead_keys_enabled = false;
    }

    if (keycode == KC_IS_MAC) {
        is_mac = true;
    } else if (keycode == KC_IS_NOT_MAC) {
        is_mac = false;
    }

    handle_custom_shortcut_keycodes(keycode, record);

    return true;
}

bool process_detected_host_os_user(os_variant_t detected_os) {
    if (detected_os == OS_MACOS || detected_os == OS_IOS) {
        is_mac = true;
    } else {
        is_mac = false;
    }
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
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

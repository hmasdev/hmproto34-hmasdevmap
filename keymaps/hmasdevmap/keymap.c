// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "quantum.h"

/* layer name */
enum keymap_layer {
    KL_NORMAN = 0,
    KL_QWERTY,
    KL_OPE,
    KL_FUN,
    KL_SYMNUM,
};
/* layer end */


/* macro start */
enum custom_keycodes {
    CKC_BE=SAFE_RANGE,
    CKC_DE,
    CKC_EXIT,
    CKC_FU,
    CKC_HA,
    CKC_NN,
    CKC_NU,
    CKC_NYU,
    CKC_PO,
    CKC_RI,
    CKC_RO,
    CKC_RYA,
    CKC_RYU,
    CKC_RYO,
    CKC_UN,
    CKC_WA,
    CKC_WO,
    CKC_ZA,
    CKC_L_ARROW,
    CKC_R_ARROW,
    /* PYTHON */
    CKC_PYTHON,
    CKC_PYTHONM,
    CKC_PIP_INSTALL,
    CKC_PIP_INSTALL_R,
    CKC_PYTEST,
    CKC_FLAKE8,
    CKC_MYPY,
    CKC_PY_NOQA,
    CKC_PY_TYPE_IGNORE,
    CKC_PY_TYPE_IGNORE_NOQA,
    /* SAFE RANGE */
    HM_SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case CKC_BE: if (record->event.pressed) { SEND_STRING("be"); } return false; break;
        case CKC_DE: if (record->event.pressed) { SEND_STRING("de"); } return false; break;
        case CKC_EXIT: if (record->event.pressed) { SEND_STRING("exit"); } return false; break;
        case CKC_FU: if (record->event.pressed) { SEND_STRING("fu"); } return false; break;
        case CKC_HA: if (record->event.pressed) { SEND_STRING("ha"); } return false; break;
        case CKC_NN: if (record->event.pressed) { SEND_STRING("nn"); } return false; break;
        case CKC_NU: if (record->event.pressed) { SEND_STRING("nu"); } return false; break;
        case CKC_NYU: if (record->event.pressed) { SEND_STRING("nyu"); } return false; break;
        case CKC_PO: if (record->event.pressed) { SEND_STRING("po"); } return false; break;
        case CKC_RI: if (record->event.pressed) { SEND_STRING("ri"); } return false; break;
        case CKC_RO: if (record->event.pressed) { SEND_STRING("ro"); } return false; break;
        case CKC_RYA: if (record->event.pressed) { SEND_STRING("rya"); } return false; break;
        case CKC_RYU: if (record->event.pressed) { SEND_STRING("ryu"); } return false; break;
        case CKC_RYO: if (record->event.pressed) { SEND_STRING("ryo"); } return false; break;
        case CKC_UN: if (record->event.pressed) { SEND_STRING("un"); } return false; break;
        case CKC_WA: if (record->event.pressed) { SEND_STRING("wa"); } return false; break;
        case CKC_WO: if (record->event.pressed) { SEND_STRING("wo"); } return false; break;
        case CKC_ZA: if (record->event.pressed) { SEND_STRING("za"); } return false; break;
        case CKC_L_ARROW: if (record->event.pressed) { SEND_STRING("<- "); } return false; break;
        case CKC_R_ARROW: if (record->event.pressed) { SEND_STRING("-> "); } return false; break;
        // PYTHON
        case CKC_PYTHON: if (record->event.pressed) { SEND_STRING("python "); } return false; break;
        case CKC_PYTHONM: if (record->event.pressed) { SEND_STRING("python -m "); } return false; break;
        case CKC_PIP_INSTALL: if (record->event.pressed) { SEND_STRING("pip install "); } return false; break;
        case CKC_PIP_INSTALL_R: if (record->event.pressed) { SEND_STRING("pip install -r requirements.txt"); } return false; break;
        case CKC_PYTEST: if (record->event.pressed) { SEND_STRING("pytest "); } return false; break;
        case CKC_FLAKE8: if (record->event.pressed) { SEND_STRING("flake8 "); } return false; break;
        case CKC_MYPY: if (record->event.pressed) { SEND_STRING("mypy "); } return false; break;
        case CKC_PY_NOQA: if (record->event.pressed) { SEND_STRING("  # noqa"); } return false; break;
        case CKC_PY_TYPE_IGNORE: if (record->event.pressed) { SEND_STRING("  # type' ignore"); } return false; break;
        case CKC_PY_TYPE_IGNORE_NOQA: if (record->event.pressed) { SEND_STRING("  # type' ignore # noqa"); } return false; break;
        default: return true; break;
    };
    return true;
};
/* macro end */


/* tap dance start */
enum {
    TD_BRACKET_L = 0,
    TD_BRACKET_R,
    TD_QUOTE,
    TD_3_QUOTE,
};

void BRACKET_DANCE_L(tap_dance_state_t *state, void *user_data) {
    if(state->count == 1){SEND_STRING("*");}
    else if(state->count == 2){SEND_STRING("]");}
    else if(state->count == 3){SEND_STRING("}");}
};
void BRACKET_DANCE_R(tap_dance_state_t *state, void *user_data) {
    if(state->count == 1){SEND_STRING("(");}
    else if(state->count == 2){SEND_STRING("\\");}
    else if(state->count == 3){SEND_STRING("|");}
};
void QUOTE_DANCE(tap_dance_state_t *state, void *user_data) {
    if(state->count == 1){SEND_STRING("&");}
    else if(state->count == 2){SEND_STRING("@");}
    else if(state->count == 3){SEND_STRING("{");}
};
void THREE_QUOTE_DANCE(tap_dance_state_t *state, void *user_data) {
    if(state->count == 1){SEND_STRING("&&&");}
    else if(state->count == 2){SEND_STRING("@@@");}
    else if(state->count == 3){SEND_STRING("{{{");}
};

tap_dance_action_t tap_dance_actions[] = {
    [TD_BRACKET_L] = ACTION_TAP_DANCE_FN (BRACKET_DANCE_L),
    [TD_BRACKET_R] = ACTION_TAP_DANCE_FN (BRACKET_DANCE_R),
    [TD_QUOTE]     = ACTION_TAP_DANCE_FN (QUOTE_DANCE),
    [TD_3_QUOTE]   = ACTION_TAP_DANCE_FN (THREE_QUOTE_DANCE),
};
/* tap dance end */


/* combo start */
const uint16_t PROGMEM KC_YN[] = {KC_Y, KC_N, COMBO_END};
const uint16_t PROGMEM KC_HJ[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM KC_TG[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM KC_FG[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM KC_HOME_LEFT[] = {KC_HOME, KC_LEFT, COMBO_END};

const uint16_t PROGMEM KC_DE[] = {KC_D, KC_E, COMBO_END};
const uint16_t PROGMEM KC_UN[] = {KC_U, KC_N, COMBO_END};
const uint16_t PROGMEM KC_RI[] = {KC_R, KC_I, COMBO_END};
const uint16_t PROGMEM KC_PO[] = {KC_O, KC_P, COMBO_END};

const uint16_t PROGMEM KC_WE[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM KC_WD[] = {KC_W, KC_D, COMBO_END};
const uint16_t PROGMEM KC_ER[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM KC_DF[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM KC_IU[] = {KC_I, KC_U, COMBO_END};
const uint16_t PROGMEM KC_RU[] = {KC_R, KC_U, COMBO_END};
const uint16_t PROGMEM KC_IO[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM KC_RP[] = {KC_R, KC_P, COMBO_END};

const uint16_t PROGMEM KC_RT[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM KC_FB[] = {KC_F, KC_B, COMBO_END};
const uint16_t PROGMEM KC_WER[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM KC_WDF[] = {KC_W, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM KC_ERT[] = {KC_E, KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM KC_DFB[] = {KC_D, KC_F, KC_B, COMBO_END};
const uint16_t PROGMEM KC_YU[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM KC_JU[] = {KC_J, KC_U, COMBO_END};
const uint16_t PROGMEM KC_UIO[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM KC_URP[] = {KC_U, KC_R, KC_P, COMBO_END};
const uint16_t PROGMEM KC_YUI[] = {KC_Y, KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM KC_JUR[] = {KC_J, KC_U, KC_R, COMBO_END};

const uint16_t PROGMEM KC_SX[] = {KC_S, KC_X, COMBO_END};
const uint16_t PROGMEM KC_DC[] = {KC_D, KC_C, COMBO_END};
const uint16_t PROGMEM KC_EC[] = {KC_E, KC_C, COMBO_END};

const uint16_t PROGMEM KC_COMM_K[] = {LT(KL_OPE, KC_COMM), KC_K, COMBO_END};
const uint16_t PROGMEM KC_COMM_B [] = {LT(KL_OPE, KC_COMM), KC_B, COMBO_END};
const uint16_t PROGMEM KC_COMM_V[] = {LT(KL_OPE, KC_COMM), KC_V, COMBO_END};
const uint16_t PROGMEM KC_SPACE_N[] = {LT(KL_FUN, KC_SPACE), KC_N, COMBO_END};
const uint16_t PROGMEM KC_SPACE_H[] = {LT(KL_FUN, KC_SPACE), KC_H, COMBO_END};
const uint16_t PROGMEM KC_SPACE_M[] = {LT(KL_FUN, KC_SPACE), KC_M, COMBO_END};

const uint16_t PROGMEM KC_XC[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM KC_ZX[] = {KC_Z, KC_X, COMBO_END};
const uint16_t PROGMEM KC_QW[] = {LCTL_T(KC_Q), KC_W, COMBO_END};
const uint16_t PROGMEM KC_ENT_L_BRACKET[] = {LSFT_T(KC_ENT), TD(TD_BRACKET_L), COMBO_END};
const uint16_t PROGMEM KC_ENT_R_BRACKET[] = {LSFT_T(KC_ENT), TD(TD_BRACKET_R), COMBO_END};

const uint16_t PROGMEM KC_TAB_COMM[] = {LSFT_T(KC_TAB), LT(KL_OPE, KC_COMM), COMBO_END};
const uint16_t PROGMEM KC_GRV_SPACE[] = {LALT_T(KC_GRV), LT(KL_FUN, KC_SPACE), COMBO_END};

const uint16_t PROGMEM KC_ENT_KC_0[] = {KC_ENT, KC_0, COMBO_END};
const uint16_t PROGMEM KC_ENT_KC_1[] = {KC_ENT, KC_1, COMBO_END};

const uint16_t PROGMEM KC_QWER[] = {LCTL_T(KC_Q), KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM KC_QWDF[] = {LCTL_T(KC_Q), KC_W, KC_D, KC_F, COMBO_END};

const uint16_t PROGMEM KC_F2_F3[] = {KC_F2, KC_F3, COMBO_END};
const uint16_t PROGMEM KC_F1_F2_F3[] = {KC_F1, KC_F2, KC_F3, COMBO_END};
const uint16_t PROGMEM KC_F2_F3_F4[] = {KC_F2, KC_F3, KC_F4, COMBO_END};
const uint16_t PROGMEM KC_F1_F2_F3_F4[] = {KC_F1, KC_F2, KC_F3, KC_F4, COMBO_END};
const uint16_t PROGMEM KC_F3_F4[] = {KC_F3, KC_F4, COMBO_END};
const uint16_t PROGMEM KC_F4_F5[] = {KC_F4, KC_F5, COMBO_END};
const uint16_t PROGMEM KC_F3_F4_F5[] = {KC_F3, KC_F4, KC_5, COMBO_END};
const uint16_t PROGMEM KC_F6_F7[] = {KC_F6, KC_F7, COMBO_END};
const uint16_t PROGMEM KC_F7_F8[] = {KC_F7, KC_F8, COMBO_END};
const uint16_t PROGMEM KC_F6_F7_F8[] = {KC_F6, KC_F7, KC_F8, COMBO_END};

const uint16_t PROGMEM KC_TD_QUOTE_CKC_NN[] = {TD(TD_QUOTE), CKC_NN, COMBO_END};

combo_t key_combos[] = {
    // python
    COMBO(KC_F2_F3, CKC_PYTHON),
    COMBO(KC_F2_F3_F4, CKC_PYTHONM),
    COMBO(KC_F1_F2_F3, CKC_PYTEST),
    COMBO(KC_F1_F2_F3_F4, CKC_PIP_INSTALL),
    COMBO(KC_F3_F4, CKC_PY_NOQA),
    COMBO(KC_F4_F5, CKC_PY_TYPE_IGNORE),
    COMBO(KC_F3_F4_F5, CKC_PY_TYPE_IGNORE_NOQA),
    COMBO(KC_F6_F7, CKC_PYTEST),
    COMBO(KC_F7_F8, CKC_FLAKE8),
    COMBO(KC_F6_F7_F8, CKC_MYPY),

    // To enhance the typing experience
    COMBO(KC_DE, CKC_DE),  // mod norman
    COMBO(KC_UN, CKC_UN),  // mod norman
    COMBO(KC_RI, CKC_RI),  // mod norman
    COMBO(KC_PO, CKC_PO),  // mod norman

    // To reduce the load on the index finger
    COMBO(KC_YN, KC_J),  // mod norman
    COMBO(KC_HJ, KC_Y),  // qwerty
    COMBO(KC_TG, KC_B),  // mod norman
    COMBO(KC_FG, KC_T),  // qwerty
    COMBO(KC_HOME_LEFT, CKC_WO),

    // for brackets and quotes
    // COMBO(KC_WE, LSFT(KC_RBRC)),  // qwerty {
    COMBO(KC_WD, LSFT(KC_RBRC)),  // mod norman {
    // COMBO(KC_ER, KC_RBRC),  // qwerty [
    COMBO(KC_DF, KC_RBRC),  // mod norman [
    // COMBO(KC_IU, KC_BSLS), // qwerty ]
    // COMBO(KC_RT, KC_BSLS), // qwerty ]
    // COMBO(KC_RU, KC_BSLS), // mod norman ]
    COMBO(KC_FB, KC_BSLS), // mod norman ]
    // COMBO(KC_IO, LSFT(KC_BSLS)), // qwerty }
    COMBO(KC_RP, LSFT(KC_BSLS)), // mod norman }
    // COMBO(KC_WER, LSFT(KC_7)),  // qwerty '
    COMBO(KC_WDF, LSFT(KC_7)),  // mod norman '
    // COMBO(KC_UIO, LSFT(KC_7)),  // qwerty '
    COMBO(KC_URP, LSFT(KC_7)),  // mod norman '
    // COMBO(KC_ERT, LSFT(KC_2)),  // qwerty "
    COMBO(KC_DFB, LSFT(KC_2)),  // mod norman "
    // COMBO(KC_YUI, LSFT(KC_2)),  // qwerty "
    COMBO(KC_JUR, LSFT(KC_2)),  // mod norman "

    // for R4 keys
    COMBO(KC_SX, KC_X),  // qwerty / mod norman
    COMBO(KC_DC, KC_C),  // qwerty
    COMBO(KC_EC, KC_C),  // mod norman

    // for space/back-space/hyphen/period
    COMBO(KC_COMM_B, LT(KL_SYMNUM, KC_MINS)),  // qwerty
    COMBO(KC_COMM_K, LT(KL_SYMNUM, KC_MINS)),  // mod norman
    COMBO(KC_COMM_V, LT(KL_SYMNUM, KC_DOT)),  // qwerty / mod norman
    COMBO(KC_SPACE_N, KC_BSPC),  // qwerty
    COMBO(KC_SPACE_H, KC_BSPC),  // mod norman
    COMBO(KC_SPACE_M, LSFT_T(KC_SPACE)),  // qwerty / mod norman
    COMBO(KC_ENT_L_BRACKET, KC_DEL),
    COMBO(KC_ENT_R_BRACKET, KC_ENT),

    COMBO(KC_QW, KC_ESC),

    // for numpad
    COMBO(KC_ENT_KC_0, KC_BSPC),
    COMBO(KC_ENT_KC_1, LSFT(KC_ENT)),

    // for layer change
    COMBO(KC_TAB_COMM, MO(KL_SYMNUM)),
    COMBO(KC_GRV_SPACE, MO(KL_SYMNUM)),

    // for default layer change
    COMBO(KC_QWER, DF(KL_NORMAN)),     // qwerty
    COMBO(KC_QWDF, DF(KL_QWERTY)),     // mod norman

    // combo for mouse
    COMBO(KC_TD_QUOTE_CKC_NN, KC_BTN1),
};
/* combo end */


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // QWERTY
    [KL_QWERTY] = LAYOUT(
        LCTL_T(KC_Q),        KC_W,                KC_E,                KC_R,                KC_T,                KC_Y,                KC_U,                KC_I,                KC_O,                LGUI_T(KC_P),
        KC_A,                KC_S,                KC_D,                KC_F,                KC_G,                KC_H,                KC_J,                KC_K,                KC_L,                KC_SCLN,
        KC_Z,                KC_X,                KC_C,                KC_V,                KC_B,                KC_N,                KC_M,                KC_COMM,             KC_DOT,              LCTL_T(KC_SLSH),
        LSFT_T(KC_TAB),      XXXXXXX,             XXXXXXX,             XXXXXXX,             LT(KL_OPE, KC_BSPC), LT(KL_FUN, KC_SPACE),XXXXXXX,             XXXXXXX,             XXXXXXX,             LALT_T(KC_GRV)
    ),

    // mod norman
    [KL_NORMAN] = LAYOUT(
        LCTL_T(KC_Q),        KC_W,                KC_D,                KC_F,                KC_B,                KC_J,                KC_U,                KC_R,                KC_P,                LGUI_T(KC_SCLN),
        KC_A,                KC_S,                KC_E,                KC_T,                KC_G,                KC_Y,                KC_N,                KC_I,                KC_O,                KC_L,
        KC_Z,                KC_X,                KC_C,                KC_V,                KC_K,                KC_H,                KC_M,                KC_EQL,              KC_INT3,             LCTL_T(KC_SLSH),
        LSFT_T(KC_TAB),      XXXXXXX,             XXXXXXX,             XXXXXXX,             LT(KL_OPE, KC_COMM), LT(KL_FUN, KC_SPACE),XXXXXXX,             XXXXXXX,             XXXXXXX,             LALT_T(KC_GRV)
    ),

    // Ope
    [KL_OPE] = LAYOUT(
        CKC_EXIT,            CKC_WA,              KC_MS_UP,            CKC_FU,              CKC_BE,              CKC_WO,              CKC_NU,              KC_UP,               CKC_RO,              LGUI_T(KC_LBRC),
        CKC_ZA,              KC_MS_LEFT,          KC_MS_DOWN,          KC_MS_RIGHT,         KC_BTN1,             KC_HOME,             KC_LEFT,             KC_DOWN,             KC_RIGHT,            KC_END,
        LSFT_T(KC_APP),      KC_WH_U,             KC_WH_D,             KC_BTN3,             KC_BTN2,             TD(TD_BRACKET_L),    TD(TD_BRACKET_R),    TD(TD_QUOTE),        CKC_NN,              LCTL_T(KC_INT1),
        LT(KL_SYMNUM, KC_TAB),XXXXXXX,            XXXXXXX,             XXXXXXX,             _______,             LSFT_T(KC_ENT),      XXXXXXX,             XXXXXXX,             XXXXXXX,             LALT_T(KC_QUOT)
    ),

    // Fun
    [KL_FUN] = LAYOUT(
        LCTL(KC_0),          LCTL(KC_1),          LCTL(KC_2),          LCTL(KC_3),          LCTL(KC_4),          CKC_NYU,             CKC_RYA,             CKC_RYU,             CKC_RYO,             LGUI_T(KC_F10),
        KC_F1,               KC_F2,               KC_F3,               KC_F4,               KC_F5,               KC_F6,               KC_F7,               KC_F8,               KC_F9,               KC_F11,
        RCS(KC_E),           LCAG(KC_N),          RCS(KC_I),           RCS(KC_EQL),         RCS(KC_LBRC),        LCA(KC_LEFT),        LCA(KC_RGHT),        LCA(KC_DOWN),        LCA(KC_UP),          LCTL_T(KC_F12),
        LCTL(KC_SLSH),       XXXXXXX,             XXXXXXX,             XXXXXXX,             RCS(KC_P),           _______,             XXXXXXX,             XXXXXXX,             XXXXXXX,             MO(KL_SYMNUM)
    ),

    // Symbol and Number
    [KL_SYMNUM] = LAYOUT(
        LCTL(KC_MINS),       RCS(KC_SCLN),        RCS(KC_ESC),         LSG(KC_LEFT),        LSG(KC_RGHT),        LSFT(KC_MINS),       KC_7,                KC_8,                KC_9,                LSFT(KC_QUOT),
        LSFT(KC_1),          LSFT(KC_SLSH),       LSFT(KC_EQL),        LSFT(KC_6),          LSFT(KC_INT3),       KC_DOT,              KC_4,                KC_5,                KC_6,                KC_SLSH,
        LSFT(KC_LBRC),       CKC_L_ARROW,         CKC_R_ARROW,         LSFT(KC_5),          LSFT(KC_4),          KC_0,                KC_1,                KC_2,                KC_3,                LSFT(KC_SCLN),
        LSFT(KC_3),          XXXXXXX,             XXXXXXX,             XXXXXXX,             TD(TD_3_QUOTE),      KC_ENT,              XXXXXXX,             XXXXXXX,             XXXXXXX,             KC_MINS
    )
};

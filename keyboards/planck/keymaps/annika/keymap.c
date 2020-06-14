// #include "action_layer.h"
// #include "eeconfig.h"

#include QMK_KEYBOARD_H

#include "muse.h" // TODO: Remove? Music?
#include "keymap_extras/keymap_german.h"

// extern keymap_config_t keymap_config;

enum a_board_layers {
  // Layer
  _BASE,
  _PNCT,
  _FUNC,
  _NUMS,
  _LEADER,
  _ADJUST,
  _GAMING,
  _GAMING_SHOOTER,
  _GAMING_AOE,
  _GAMING_AOE1,
};

enum a_board_keycodes {
  // Layer
  LR_BASE = SAFE_RANGE,
  LR_GMNG,
  LR_AOE,
  LR_SHTR,
  LR_ADJT,

  // OS selection. 
  OS_COS, // Chrome OS.
  OS_LNX, // Linux.
  OS_WIN, // Windows.

  // Macros
  MC_FIND, // Find selection in page (Ctrl+C Ctrl+F Ctrl+V).
  MC_GGLE, // Google for current selection (Ctrl+C Ctrl+L Ctrl+V Enter).
  MC_LINK, // Link what is currently highlighted (Ctrl+C Ctrl+K Ctrl+V Enter).
  MC_DKLF, // Dock window left.
  MC_DKRG, // Dock window right.
  MC_DLFT, // Go to virtual desktop left.
  MC_DRGT, // Go to virtual desktop right.
  MC_MVLF, // Move window to virtual desktop on the left.
  MC_MVRG, // Move window to virtual desktop on the right.
};

// Remaps (similar to macros)
#define MC_EXIT LALT(KC_F4)      // Close window, ALT + F4.
#define MC_NTRM LCTL(LSFT(KC_N)) // Open new Terminal.

// TODO: Create custom unicode map; use XP(0x0142, 0x0141) for upper/lower case.
#define UC_LSTR UC(0x0142) // Polish l with a stroke.
#define UC_BKTK UC(0x0060) // Backtick (non-dead key).


static enum operating_systems {
  LINUX,
  CHROME_OS,
  WINDOWS,
} os;

// Layers
#define LR_PNCT  MO(_PNCT)
#define LR_FUNC  MO(_FUNC)
#define LR_FNCR  MO(_FUNC_CR)
#define LR_AOE1  MO(_GAMING_AOE1)
#define LR_NUMS  LT(_NUMS, DE_F)
#define LR_LEAD OSL(_LEADER)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_planck_2x2u(
  KC_ESC , DE_Q   , DE_W   , DE_E   , DE_R   , DE_T   , DE_Y   , DE_U   , DE_I   , DE_O   , DE_P   , KC_BSPC,
  KC_TAB , DE_A   , DE_S   , DE_D   , LR_NUMS, DE_G   , DE_H   , DE_J   , DE_K   , DE_L   , LR_LEAD, KC_ENT ,
  KC_LSFT, DE_Z   , DE_X   , DE_C   , DE_V   , DE_B   , DE_N   , DE_M   , DE_COMM, DE_DOT , DE_SS  , KC_RSFT,
  KC_LCTL, KC_LGUI, KC_LALT, LR_FUNC,     LR_PNCT     ,     KC_SPC      , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT
),

// TODO: Utilize page up/down, R_Shift keys better.
// TODO: Bottom left key.
[_PNCT] = LAYOUT_planck_2x2u(
  _______, DE_EXLM, DE_AT,   DE_HASH, DE_DLR,  DE_EURO, UC_BKTK, DE_LCBR, DE_RCBR, DE_UNDS, DE_PLUS, KC_DEL ,
  _______, DE_TILD, DE_BSLS, DE_DQOT, DE_QUOT, DE_DEG , DE_ASTR, DE_LPRN, DE_RPRN, DE_MINS, DE_EQL , _______,
  _______, DE_GRV , DE_AMPR, DE_LBRC, DE_RBRC, DE_CIRC, DE_PIPE, DE_LESS, DE_MORE, DE_PERC, DE_SLSH, _______,
  _______, _______, _______, _______,     _______     ,     KC_DEL      , KC_HOME, KC_PGDN, KC_PGUP, KC_END
),

// TODO: Use right-hand side for dynamic macros?
[_FUNC] = LAYOUT_planck_2x2u(
  MC_EXIT, MC_FIND, MC_GGLE, MC_NTRM, MC_LINK, _______, _______, _______, _______, _______, _______, _______,
  _______, MC_DKLF, MC_DKRG, MC_DLFT, MC_DRGT, _______, _______, _______, _______, _______, _______, _______,
  _______, KC_HOME, KC_END,  MC_MVLF, MC_MVRG, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______,     _______     ,     KC_MPLY     , KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
),

[_NUMS] = LAYOUT_planck_2x2u(
  _______, KC_F1  , KC_F2  , KC_F3  , _______, _______, _______, KC_7   , KC_8   , KC_9   , _______, _______,
  _______, KC_F4  , KC_F5  , KC_F6  , _______, _______, _______, KC_4   , KC_5   , KC_6   , _______, _______,
  _______, KC_F7  , KC_F8  , KC_F9  , _______, _______, _______, KC_1   , KC_2   , KC_3   , _______, _______,
  _______, KC_F10 , KC_F11 , KC_F12 ,     _______     ,     KC_0        , KC_COMM, KC_DOT , _______, _______
),

[_LEADER] = LAYOUT_planck_2x2u(
  _______, _______, _______, _______, _______, _______, _______, DE_UE  , _______, DE_OE  , _______, _______,
  _______, DE_AE  , DE_SS  , _______, _______, _______, _______, _______, _______, UC_LSTR, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______,     _______     ,     _______     , _______, _______, _______, _______
),

[_GAMING] = LAYOUT_planck_2x2u(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, DE_F   , _______, _______, _______, _______, _______, LR_NUMS, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LR_BASE,
  _______, _______, _______, KC_LALT,     KC_SPC      ,     _______     , _______, _______, _______, _______
),

[_GAMING_AOE] = LAYOUT_planck_2x2u(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, DE_F   , _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, LR_BASE,
  _______, _______, _______, KC_LCTL,     LR_AOE1     ,     _______     , _______, _______, _______, _______
),
[_GAMING_AOE1] = LAYOUT_planck_2x2u(
  _______, _______, KC_7   , KC_8   , KC_9   , _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_4   , KC_5   , KC_6   , _______, _______, _______, _______, _______, _______, _______,
  _______, _______, KC_1   , KC_2   , KC_3   , _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______,     _______     ,     _______      , _______, _______, _______, _______
),

[_GAMING_SHOOTER] = LAYOUT_planck_2x2u(
  _______, _______, DE_Q   , DE_W   , DE_E   , DE_R   , DE_T   , KC_7   , KC_8   , KC_9   , _______, _______,
  _______, _______, DE_A   , DE_S   , DE_D   , DE_F   , DE_G   , KC_4   , KC_5   , KC_6   , _______, _______,
  KC_LCTL, KC_LSFT, DE_Z   , DE_X   , DE_C   , DE_V   , DE_B   , KC_1   , KC_2   , KC_3   , _______, LR_BASE,
  _______, _______, _______, KC_LALT,     KC_SPC      ,     _______     , _______, _______, _______, _______
),

[_ADJUST] = LAYOUT_planck_2x2u(
  _______, _______, OS_WIN , _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, LR_AOE , LR_SHTR, _______, _______, LR_GMNG, _______, _______, _______, OS_LNX , _______, _______,
  _______, _______, _______, OS_COS , _______, LR_BASE, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______,     _______     ,     _______     , _______, _______, _______, _______
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  // Note: For layers that don't expose the FUNC and PNCT layer keys, we need
  // to provide a layer-specific way to switch back to the BASE layer.
  return update_tri_layer_state(state, _FUNC, _PNCT, _ADJUST);
}

// Executes before usual QMK key event handling. On returning false, QMK will
// skip the normal key event handling.
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Macros 

    // Go to desktop left/right.
    case MC_DLFT:
      if (record->event.pressed) {
        switch (os) {
          case LINUX:     SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_LEFT)))); break;
          case WINDOWS:   SEND_STRING(SS_LCTRL(SS_LGUI(SS_TAP(X_LEFT)))); break;
          case CHROME_OS: SEND_STRING(SS_LCTRL(SS_LSFT(" ")) SS_DELAY(5) SS_LGUI("[") SS_DELAY(5) SS_LCTRL(SS_LSFT(" "))); break;
          default: return false;
        }
      }
      return false;
    case MC_DRGT:
      if (record->event.pressed) {
        switch (os) {
          case LINUX:     SEND_STRING(SS_LCTRL(SS_LALT(SS_TAP(X_RGHT)))); break;
          case WINDOWS:   SEND_STRING(SS_LCTRL(SS_LGUI(SS_TAP(X_RGHT)))); break;
          case CHROME_OS: SEND_STRING(SS_LCTRL(SS_LSFT(" ")) SS_DELAY(5) SS_LGUI("]") SS_DELAY(5) SS_LCTRL(SS_LSFT(" "))); break;
          default: return false;
        }
      }
      return false;

    // Move window to desktop on the left/right (Chrome OS only).
    case MC_MVLF:
      if (record->event.pressed) {
        if (os == CHROME_OS) {
          SEND_STRING(SS_LCTRL(SS_LSFT(" ")) SS_DELAY(5) SS_LSFT(SS_LGUI("[")) SS_DELAY(5) SS_LCTRL(SS_LSFT(" ")));
        }
      }
      return false;
    case MC_MVRG:
      if (record->event.pressed) {
        if (os == CHROME_OS) {
          SEND_STRING(SS_LCTRL(SS_LSFT(" ")) SS_DELAY(5) SS_LSFT(SS_LGUI("]")) SS_DELAY(5) SS_LCTRL(SS_LSFT(" ")));
        }
      }
      return false;

    // Dock windows left/right.
    case MC_DKLF:
      if (record->event.pressed) {
        switch (os) {
          case LINUX:
          case WINDOWS:   SEND_STRING(SS_LGUI(SS_TAP(X_LEFT))); break;
          case CHROME_OS: SEND_STRING(SS_LCTRL(SS_LSFT(" ")) SS_DELAY(5) SS_LALT("[") SS_DELAY(5) SS_LCTRL(SS_LSFT(" "))); break;
          default: return false;
        }
      }
      return false;
    case MC_DKRG:
      if (record->event.pressed) {
        switch (os) {
          case LINUX:
          case WINDOWS:   SEND_STRING(SS_LGUI(SS_TAP(X_RGHT))); break;
          case CHROME_OS: SEND_STRING(SS_LCTRL(SS_LSFT(" ")) SS_DELAY(5) SS_LALT("]") SS_DELAY(5) SS_LCTRL(SS_LSFT(" "))); break;
          default: return false;
        }
      }
      return false;

    // Custom actions
    // TODO: Revisit whether delays help for MC_FIND.
    case MC_GGLE:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("c") SS_DELAY(5) SS_LCTRL("t") SS_DELAY(5) SS_LCTRL("v") SS_TAP(X_ENTER));
      }
      return false;
    case MC_FIND:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("c") SS_DELAY(5) SS_LCTRL("f") SS_DELAY(5) SS_LCTRL("v"));
      }
      return false;
    case MC_LINK:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTRL("c") SS_LCTRL("k") SS_LCTRL("v"));
      }
      return false;

    // Layers
    case LR_BASE:
      if (record->event.pressed) {
        layer_off(_FUNC);
        layer_off(_PNCT);
        layer_off(_ADJUST);
        set_single_persistent_default_layer(_BASE);
      }
      return false;
    case LR_GMNG:
      if (record->event.pressed) {
        layer_off(_FUNC);
        layer_off(_PNCT);
        layer_off(_ADJUST);
        set_single_persistent_default_layer(_GAMING);
      }
      return false;
    case LR_AOE:
      if (record->event.pressed) {
        layer_off(_FUNC);
        layer_off(_PNCT);
        layer_off(_ADJUST);
        set_single_persistent_default_layer(_GAMING_AOE);
      }
      return false;
    case LR_SHTR:
      if (record->event.pressed) {
        layer_off(_FUNC);
        layer_off(_PNCT);
        layer_off(_ADJUST);
        set_single_persistent_default_layer(_GAMING_SHOOTER);
      }
      return false;

    // OS selection
    case OS_LNX:
      if (record->event.pressed) {
        os = LINUX;
        set_unicode_input_mode(UC_LNX);
      }
      return false;
    case OS_WIN:
      if (record->event.pressed) {
        os = WINDOWS;
        // Note: Requires WinCompose.
        set_unicode_input_mode(UC_WINC);
      }
      return false;
    case OS_COS:
      if (record->event.pressed) {
        os = CHROME_OS;
        set_unicode_input_mode(UC_LNX);
      }
      return false;
  }

  return true;
}

// Templates

/*
[TODO] = LAYOUT_planck_2x2u(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),
*/

/*
    case TODO:
      if (record->event.pressed) {
        switch (os) {
          case LINUX:     TODO
          case WINDOWS:   TODO
          case CHROME_OS: TODO
          default: return false;
        }
      }
      return false;
*/

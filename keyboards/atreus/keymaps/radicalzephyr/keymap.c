#include QMK_KEYBOARD_H

///  This layout is designed to be used on machines where the OS is
///  already set to a dvorak layout. It assumes that the dvorak
///  mapping will be happening on the PC side and sends
///  "un-dvorakized" keycodes. (So it sends qwerty letters, but
///  specially-shuffled punctuation.)  This is helpful for laptops
///  where you want to be able to use the internal keyboard in dvorak
///  without having to change the OS mappings.

// Each layer gets a name for readability, which is then used in the
// keymap matrix below.  The underscores don't mean anything - you can
// have a layer called STUFF or any other name.  Layer names don't all
// need to be of the same length, obviously, and you can also skip
// them entirely and just use numbers.
#define _QW 0
#define _RS 1
#define _LW 2

#define _HW_DV 3
#define _RS_DV 4
#define _LW_DV 2

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QW] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    KC_ESC, KC_TAB, KC_LGUI,  KC_LSFT, KC_BSPC,  KC_LCTL, KC_LALT, KC_SPC,  MO(_RS), KC_QUOT, KC_LBRC, KC_ENT
  ),

  /*
   *   !       @      {      }      |         ||       up     7     8     9    *
   *   #       $      [      ]      `         ||      down    4     5     6    +
   *   %       ^      (      )      ~         ||        `     1     2     3    \
   *  lower  insert  super  shift  bksp  ctrl || alt  space   fn    0     .    =?
   */
  [_RS] = LAYOUT( /* [> RAISE <] */
    KC_EXLM, KC_AT,         KC_UNDS, KC_PLUS, KC_PIPE,                   KC_UP,   KC_7,    KC_8, KC_9,    KC_ASTR ,
    KC_HASH, KC_DLR,        KC_LPRN, KC_RPRN, KC_GRV,                    KC_DOWN, KC_4,    KC_5, KC_6,    KC_RCBR ,
    KC_PERC, KC_CIRC,       KC_MINS, KC_EQL,  KC_TILD,                   KC_AMPR, KC_1,    KC_2, KC_3,    KC_BSLS ,
    TG(_LW), LSFT(KC_INS),  KC_LGUI, KC_LSFT, KC_DEL,  KC_LCTL, KC_LALT, KC_SPC,  KC_TRNS, KC_0, KC_RBRC, KC_ENT  ),

  [_HW_DV] = LAYOUT(
    KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,                      KC_F,   KC_G,       KC_C,    KC_R,    KC_L   ,
    KC_A,    KC_O,    KC_E,    KC_U,    KC_I,                      KC_D,   KC_H,       KC_T,    KC_N,    KC_S   ,
    KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,                      KC_B,   KC_M,       KC_W,    KC_V,    KC_Z   ,
    KC_ESC,  KC_TAB,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC, MO(_RS_DV), KC_MINS, KC_SLSH, KC_ENT ),

  /*
   *   !        @      {      }      |         ||       up      7     8     9    *
   *   #        $      [      ]      `         ||      down     4     5     6    +
   *   %        ^      (      )      ~         ||        `      1     2     3    \
   *  lower   insert  super  shift  bksp  ctrl || alt  space    fn    0     .    =?
   */
  [_RS_DV] = LAYOUT(
    KC_EXLM, KC_AT,         KC_LCBR, KC_RCBR, KC_PIPE,                   KC_UP,   KC_7,    KC_8, KC_9,   KC_ASTR ,
    KC_HASH, KC_DLR,        KC_LPRN, KC_RPRN, KC_GRV,                    KC_DOWN, KC_4,    KC_5, KC_6,   KC_PLUS ,
    KC_PERC, KC_CIRC,       KC_LBRC, KC_RBRC, KC_TILD,                   KC_AMPR, KC_1,    KC_2, KC_3,   KC_BSLS ,
    TG(_LW), LSFT(KC_INS),  KC_LGUI, KC_LSFT, KC_DEL,  KC_LCTL, KC_LALT, KC_SPC,  KC_TRNS, KC_0, KC_EQL, KC_ENT  ),

  /*
   * insert   home     up    end   pgup       ||       up     F7    F8     F9    F10
   *  del     left    down  right  pgdn       ||      down    F4    F5     F6    F11
   * volup   LAGSWP    QW    DV    reset      ||              F1    F2     F3    F12
   * voldn   LAGNRM  super  shift  bksp  ctrl || alt  space   L0  prtsc  scroll  pause
   */
  [_LW] = LAYOUT( /* [> LOWER <] */
    KC_INS,  KC_HOME, KC_UP,   KC_END,     KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT,    KC_PGDN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    KC_VOLU, LAG_SWP, DF(_QW), DF(_HW_DV), QK_BOOT,                   KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    KC_VOLD, LAG_NRM, KC_LGUI, KC_LSFT,    KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  TO(_QW), KC_PSCR, KC_SLCK, KC_PAUS )

};

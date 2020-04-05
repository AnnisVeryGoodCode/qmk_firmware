#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

// USB Device descriptor parameter
#define VENDOR_ID       0x0001  // Doesn't matter.
#define PRODUCT_ID      0x0001  // Doesn't matter.
#define MANUFACTURER    Anni
#define PRODUCT         A_Board
#define DESCRIPTION     A 13x4 ortholinear board

// key matrix size
#define MATRIX_ROWS 4
#define MATRIX_COLS 13

// PCB default pin-out
#define MATRIX_ROW_PINS { B6, B5, B4, D7 }
#define MATRIX_COL_PINS { F0, F1, F4, F5, F6, F7, D1, D0, B7, B3, B2, B1, B0 }
#define UNUSED_PINS

// COL2ROW or ROW2COL
#define DIODE_DIRECTION COL2ROW

// Set 0 if debouncing isn't needed.
// The delay when reading the value of the pin (5 is default).
#define DEBOUNCE 5

// Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in
// keymap.
#define LOCKING_SUPPORT_ENABLE

// Feature disable options. These options are also useful to firmware size
// reduction.

// disable debug print
//#define NO_DEBUG

// disable print
//#define NO_PRINT

// disable action features
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#endif

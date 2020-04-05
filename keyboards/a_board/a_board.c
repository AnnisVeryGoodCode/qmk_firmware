#include "a_board.h"

// TODO: Probably not needed. matrix_init_* functions can be used for
// setup and initializations after hardware setup but before many features are
// loaded.
void matrix_init_kb(void) {
	matrix_init_user();
}


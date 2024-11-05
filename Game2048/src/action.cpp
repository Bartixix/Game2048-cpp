#include "../includes/ioControl.h"
#include "../includes/action/move.h"

bool Move(const int& direction, bool compress) {
	if (direction == KEY_UP) return mU(compress);
	if (direction == KEY_DOWN) return mD(compress);
	if (direction == KEY_RIGHT) return mR(compress);
	if (direction == KEY_LEFT) return mL(compress);
	return false;
}

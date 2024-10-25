#include "../includes/ioControl.h"
#include "../includes/action/move.h"
#include "../includes/action/compress.h"

bool Move(int direction) {
	if (direction == KEY_UP) return mU();
	if (direction == KEY_DOWN) return mD();
	if (direction == KEY_RIGHT) return mR();
	if (direction == KEY_LEFT) return mL();
	return false;
}

bool Cmp(int direction) {
	if (direction == KEY_UP) return cU();
	if (direction == KEY_DOWN) return cD();
	if (direction == KEY_RIGHT) return cR();
	if (direction == KEY_LEFT) return cL();
	return false;
}
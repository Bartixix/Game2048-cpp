#include <cmath>

#include "../../includes/model/ActionHelper.h"

extern int* data[4];

bool mU(bool compress) {
	bool changed = false;

	for (int x = 0; x < 4; x++) {
		Helper xHelper;

		for (int y = 0; y < 4; y++) {
			if (data[y][x] != 0) {
				xHelper.Add(data[y][x]);
				changed = true;
			}
		}

		if (compress) xHelper.Cmp();
		xHelper.Cpy(data, false, x);
	}

	return changed;
}

bool mD(bool compress) {
	bool changed = false;

	for (int x = 0; x < 4; x++) {
		Helper xHelper;
		xHelper.Reverse();

		for (int y = 3; y >= 0; y--) {
			if (data[y][x] != 0) {
				xHelper.Add(data[y][x]);
				changed = true;
			}
		}

		if (compress) xHelper.Cmp();
		xHelper.Cpy(data, false, x);
	}

	return changed;
}

bool mR(bool compress) {
	bool changed = false;

	for (int y = 0; y < 4; y++) {
		Helper yHelper;
		yHelper.Reverse();

		for (int x = 3; x >= 0; x--) {
			if (data[y][x] != 0) {
				yHelper.Add(data[y][x]);
				changed = true;
			}
		}

		if (compress) yHelper.Cmp();
		yHelper.Cpy(data, true, y);
	}

	return changed;
}

bool mL(bool compress) {
	bool changed = false;

	for (int y = 0; y < 4; y++) {
		Helper yHelper;

		for (int x = 0; x < 4; x++) {
			if (data[y][x] != 0) {
				yHelper.Add(data[y][x]);
				changed = true;
			}
		}

		if (compress) yHelper.Cmp();
		yHelper.Cpy(data, true, y);
	}

	return changed;
}
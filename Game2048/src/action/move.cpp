#include "../../includes/data.h"

bool mU() {
	bool changed = false;
	for (int i = 0; i < 16; i++) {
		int x = (int)floor((double)i / 4);
		int y = i % 4;

		if (data[y][x] == 0) {
			for (int j = y; j < 4; j++) {
				if (data[j][x] != 0) {
					data[y][x] = data[j][x];
					data[j][x] = 0;
					changed = true;
					break;
				};
			}
		}
	}
	return changed;
}

bool mD() {
	bool changed = false;
	for (int i = 15; i >= 0; i--) {
		int x = (int)floor((double)i / 4);
		int y = i % 4;

		if (data[y][x] == 0) {
			for (int j = y; j >= 0; j--) {
				if (data[j][x] != 0) {
					data[y][x] = data[j][x];
					data[j][x] = 0;
					changed = true;
					break;
				};
			}
		}
	}
	return changed;
}

bool mR() {
	bool changed = false;
	for (int i = 15; i >= 0; i--) {
		int y = (int)floor((double)i / 4);
		int x = i % 4;

		if (data[y][x] == 0) {
			for (int j = x; j >= 0; j--) {
				if (data[y][j] != 0) {
					data[y][x] = data[y][j];
					data[y][j] = 0;
					changed = true;
					break;
				};
			}
		}
	}
	return changed;
}

bool mL() {
	bool changed = false;
	for (int i = 0; i < 16; i++) {
		int y = (int)floor((double)i / 4);
		int x = i % 4;

		if (data[y][x] == 0) {
			for (int j = x; j < 4; j++) {
				if (data[y][j] != 0) {
					data[y][x] = data[y][j];
					data[y][j] = 0;
					changed = true;
					break;
				};
			}
		}
	}
	return changed;
}
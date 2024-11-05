#include "../../includes/model/ActionHelper.h"

void Helper::Add(const int& i) {
	data[next] = i;
	if (!reverse) next++;
	else next--;
}

void Helper::Reverse() {
	if (!reverse) {
		reverse = true;
		next = 3;
	}
}

void Helper::Cpy(int* target[4], const bool& swapX, const int& i) {
	if (swapX) {
		for (int j = 0; j < 4; j++) {
			target[i][j] = data[j];
		}
	}
	else {
		for (int j = 0; j < 4; j++) {
			target[j][i] = data[j];
		}
	}
}

void Helper::Cmp() {
	if (!reverse) {
		int start = 0;
		while (start < 3) {
			for (int i = 1; i < 3 - start; i++) {
				if (data[start] == data[start + i]) {
					data[start] *= 2;
					data[start + i] = 0;
					break;
				}
			}
			start++;
		}
	}
	else {
		int start = 3;
		while (start >= 1) {
			for (int i = 1; i < start + 1; i++) {
				if (data[start] == data[start - i]) {
					data[start] *= 2;
					data[start - i] = 0;
					break;
				}
			}
			start--;
		}
	}
}

int& Helper::operator[] (size_t i) {
	return data[i];
}
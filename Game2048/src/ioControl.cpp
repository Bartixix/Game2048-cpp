#include <iostream>
#include <conio.h>

#include "../includes/data.h"

using std::cin;
using std::cout;

constexpr auto KEY_UP = 72;
constexpr auto KEY_DOWN = 80;
constexpr auto KEY_LEFT = 75;
constexpr auto KEY_RIGHT = 77;

void PrintBoard() {
	for (char* line : board) {
		cout << line << "\n";
	}
}

int GetInput() {
	return tolower(_getch());
}
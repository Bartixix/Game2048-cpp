#include <iostream>
#include <conio.h>

#include "../includes/data.h"

using std::endl;
using std::cout;


void PrintBoard() {
	char* board[15];
	if (!MergeData(board)) return;

	for (char* line : board) {
		cout << line << endl;
	}
}

int GetInput() {
	return tolower(_getch());
}
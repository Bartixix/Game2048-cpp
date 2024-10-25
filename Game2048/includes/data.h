#pragma once

#include <string>

extern int data[4][4];
extern char board[15][32];

struct Vector {
	int x;
	int y;
};

Vector* MapBoard(Vector* base);

bool UpdateBoard();

bool UpdateData(Vector* base, int value);

bool LoadFromBuf(int** buf);
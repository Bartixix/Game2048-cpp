#pragma once

#include <string>

struct Vector {
	int x;
	int y;
};

void MakeBoard();

bool MergeData(char* outBoard[15]);

Vector* MapBoard(Vector* base);

bool UpdateData(Vector* base, int value);

bool NewTile();
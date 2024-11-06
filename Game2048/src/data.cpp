#include <string>
#include <cmath>
#include <cstdlib>
#include <ctime>

int* data[4] = {
	new int[4] {0,0,0,0},
	new int[4] {0,0,0,0},
	new int[4] {0,0,0,0},
	new int[4] {0,0,0,0}
};

char* board[15];

struct Vector
{
	int x;
	int y;
};

void MakeBoard() {
	for (int i = 0; i < 15; i++) {
		if (i % 4 == 3) board[i] = new char[32] { "-------+-------+-------+-------" };
		else board[i] = new char[32] {"       |       |       |       "};
	}
}

Vector* MapBoard(Vector* base) {
	int x = base->x * 8 + 3;
	int y = base->y * 4 + 1;

	if (x < 0 || x>31) return new Vector{ 0,0 };
	if (y < 0 || y>15) return new Vector{ 0,0 };

	return new Vector{ x,y };
}

bool MergeData(char* outBoard[15]) {
	std::copy(board, board + 15, outBoard);
	MakeBoard();

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			Vector* base = new Vector{ x,y };
			Vector* mapped = MapBoard(base);

			if (mapped->x == 0 && mapped->y == 0) return false;

			std::string sValue = std::to_string(data[y][x]);

			int len = (int)sValue.length();
			int delta = (int)floor((double)len / 2);

			if (mapped->x - delta < 0 || mapped->x + delta > 31) return false;

			for (int i = 0; i < len; i++) {
				std::string out = sValue.c_str();
				if(out != "0") outBoard[mapped->y][mapped->x - delta] = out[i];
				delta--;
			}

			delete base;
			delete mapped;
		}
	}

	return true;
}

bool UpdateData(Vector* base, int value) {
	double log = log2(value);
	double rnd = round(log);

	if (log != rnd || value > 65536) return false;
	
	data[base->y][base->x] = value;

	return true;
}

static bool GetFree(Vector* free) {
	int count = 0;
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (data[y][x] == 0) count++;
		}
	}

	if (count == 0) return false;

	srand((unsigned)time(NULL));
	int tile = rand() % count;

	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			if (data[y][x] == 0) count--;

			if (count == 0) {
				free->x = x;
				free->y = y;
				return true;
			}
		}
	}

	return false;
}

bool NewTile() {
	Vector free;
	if (!GetFree(&free)) return false;

	srand((unsigned)time(NULL));
	int tileSel = rand() % 10;
	int tile;

	if (tileSel == 9) tile = 4;
	else tile = 2;

	UpdateData(&free, tile);

	return true;
}
#include <string>

int data[4][4];

char board[15][32] = {
	"       |       |       |       ",
	"       |       |       |       ",
	"       |       |       |       ",
	"-------+-------+-------+-------",
	"       |       |       |       ",
	"       |       |       |       ",
	"       |       |       |       ",
	"-------+-------+-------+-------",
	"       |       |       |       ",
	"       |       |       |       ",
	"       |       |       |       ",
	"-------+-------+-------+-------",
	"       |       |       |       ",
	"       |       |       |       ",
	"       |       |       |       ",
};

struct Vector
{
	int x;
	int y;
};

Vector* MapBoard(Vector* base) {
	int x = base->x * 8 + 3;
	int y = base->y * 4 + 1;

	if (x < 0 || x>31) return new Vector{ 0,0 };
	if (y < 0 || y>15) return new Vector{ 0,0 };

	return new Vector{ x,y };
}

void Clear(Vector* mapped) {
	for (int i = -3; i < 3; i++) {
		board[mapped->y][mapped->x + i] = ' ';
	}
}

bool UpdateBoard() {
	for (int y = 0; y < 4; y++) {
		for (int x = 0; x < 4; x++) {
			Vector* mapped = MapBoard(new Vector{ x,y });

			if (mapped->x == 0 && mapped->y == 0) return false;

			std::string sValue = std::to_string(data[y][x]);

			int len = (int)sValue.length();
			int delta = (int)floor((double)len / 2);

			if (mapped->x - delta < 0 || mapped->x + delta > 31) return false;

			for (int i = 0; i < len; i++) {
				if (sValue == "0")
					Clear(mapped);
				else
					board[mapped->y][mapped->x - delta] = sValue.c_str()[i];
				delta--;
			}	
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

bool LoadFromBuf(int** buf) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			data[i][j] = buf[i][j];
		}
	}
	return true;
}
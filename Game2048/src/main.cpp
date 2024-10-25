#include "../includes/action.h"
#include "../includes/data.h"
#include "../includes/ioControl.h"

void BT() {
	UpdateData(new Vector{ 3,2 }, 512);
	UpdateData(new Vector{ 3,3 }, 65536);
	UpdateData(new Vector{ 0,0 }, 16);
	UpdateData(new Vector{ 2,2 }, 128);

	UpdateBoard();
	PrintBoard();
	Move(KEY_LEFT);

	UpdateBoard();
	PrintBoard();

	Move(KEY_RIGHT);

	UpdateBoard();
	PrintBoard();
}

int main(int argc, char** argv) {
	UpdateData(new Vector{ 3,3 }, 512);
	UpdateData(new Vector{ 2,2 }, 1024);
	UpdateData(new Vector{ 3,0 }, 16);
	UpdateData(new Vector{ 0,2 }, 32);
	UpdateData(new Vector{ 0,0 }, 128);
	UpdateData(new Vector{ 2,1 }, 2048);
	UpdateData(new Vector{ 1,3 }, 8);

	PrintBoard();

	while (true) {
		if (Move(GetInput())) {
			std::system("cls");
			UpdateBoard();
			PrintBoard();
		}
	}

	std::cin.get();
}
#include <conio.h> 
#include <iostream> 

#include "../includes/action.h"
#include "../includes/data.h"
#include "../includes/ioControl.h"

static void BT() {
	UpdateData(new Vector{ 3,2 }, 512);
	UpdateData(new Vector{ 3,3 }, 65536);
	UpdateData(new Vector{ 0,0 }, 16);
	UpdateData(new Vector{ 2,2 }, 128);

	PrintBoard();
	Move(KEY_LEFT, false);

	PrintBoard();

	Move(KEY_RIGHT, false);

	PrintBoard();
}

int main(int argc, char** argv) {
	UpdateData(new Vector{ 3,3 }, 16);
	UpdateData(new Vector{ 2,2 }, 1024);
	UpdateData(new Vector{ 3,0 }, 16);
	UpdateData(new Vector{ 0,2 }, 16);
	UpdateData(new Vector{ 0,0 }, 128);
	UpdateData(new Vector{ 2,1 }, 16);
	UpdateData(new Vector{ 1,3 }, 8);

	MakeBoard();
	PrintBoard();

	int input;
	while (true) {
		input = GetInput();
		if (Move(input, true)) {
			Move(input, false);
			std::cout << "\x1B[2J\x1B[H";
			if (!NewTile()) break;
			PrintBoard();
		}
	}

	std::cout << "lost" << std::endl;

	std::cin.get();
}
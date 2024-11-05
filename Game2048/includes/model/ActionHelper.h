#pragma once

#include <iostream>

struct Helper {
	int data[4] = { 0,0,0,0 };
	int next = 0;
	bool reverse = false;
	

	void Add(const int& i);

	void Reverse();

	void Cpy(int* target[4], const bool& swapX, const int& i);

	void Cmp();

	int& operator[] (size_t i);
};
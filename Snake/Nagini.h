#pragma once
#include <iostream>

enum Move
{
	FORWARD, BACK, UP, DOWN
};

class Nagini
{
	public:
		Nagini(int, int);
		~Nagini();
		void move(Move);
		void print();

	private:
		int x_snake;
		int y_snake;
		int length;
};
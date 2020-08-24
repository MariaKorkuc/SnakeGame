#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include "utils.h"

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
		Point get_head_coord();
	private:
		int x_snake;
		int y_snake;
		Move lastMove;
		char head;
		int length;
};
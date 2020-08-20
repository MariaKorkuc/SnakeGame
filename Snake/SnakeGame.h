#pragma once
#include <iostream>
#include "BabySnake.h"

class SnakeGame
{
public:
	SnakeGame();
	~SnakeGame();
	void run();
	void clearScreen();

private:
	BabySnake _snake;

};
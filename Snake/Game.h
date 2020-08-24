#pragma once
#include "Nagini.h"
#include <Windows.h>
#include <cstdio>
#include <stdlib.h>
#include <conio.h>
#include "utils.h"
#include <time.h>

class Game
{
public:
	Game(int width, int height);
	~Game();
	void run();
	
private:
	void clearScreen();
	void step();
	void setBoundries();
	void setFruit();
	int width;
	int height;

	Point fruit;
	Nagini snake;
};
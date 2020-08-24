#pragma once
#include "Nagini.h"
#include <Windows.h>
#include <cstdio>
#include <stdlib.h>
#include <conio.h>
#include "utils.h"
#include <time.h>
#include <vector>

using namespace std;

class Game
{
public:
	Game(int width, int height);
	~Game();
	void run();
	const void printPoints();
	
private:
	void clearScreen();
	void step();
	void setBoundries();
	void setFruit();
	bool check_fruit_eaten();
	int width;
	int height;

	Point fruit;
	Nagini snake;
	int points;
	int lives;
};
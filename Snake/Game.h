#pragma once
#include "Nagini.h"
#include <Windows.h>
#include <cstdio>
#include <stdlib.h>
#include <conio.h>
#include "utils.h"
#include <time.h>

using namespace std;

class Game
{
public:
	Game(int width, int height);
	~Game();
	void run();
	const void printPoints();
	void resetSnake(Move where);
	
private:
	void clearScreen();
	void step();
	void setBoundries();
	void setFruit();
	bool check_fruit_eaten();
	bool check_stepped_on_boundries();
	bool check_ate_himself();
	int width;
	int height;

	Segment fruit;
	Nagini snake;
	int points;
	int lives;
};
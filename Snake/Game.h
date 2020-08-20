#pragma once
#include "Nagini.h"
#include <Windows.h>

class Game
{
public:
	Game();
	~Game();
	void step();
	
private:
	void clearScreen();

	Nagini snake;
};
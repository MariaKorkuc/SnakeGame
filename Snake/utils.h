#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <map>

enum Move
{
	FORWARD, BACK, UP, DOWN
};

void SetCMDSizeAndTitle(short height, short width, std::string title);
void gotoxy(int column, int line);

struct Segment
{
	Segment(int x = 1, int y = 1, char c = '@', Move n = FORWARD) : x(x), y(y), c(c), next_pos(n) {}
	Segment(const Segment& p) : x(p.x), y(p.y), c(p.c), next_pos(p.next_pos) {}
	bool operator==(const Segment& p)
	{
		return p.x == x && p.y == y;
	}

	int x;
	int y;
	char c;
	Move next_pos;
};

std::ostream& operator<<(std::ostream& o, const Segment& p);
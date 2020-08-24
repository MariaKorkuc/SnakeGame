#pragma once
#include <iostream>
#include <Windows.h>
#include <string>

void SetCMDSizeAndTitle(short height, short width, std::string title);
void gotoxy(int column, int line);

struct Point
{
	Point(int x = 1, int y = 1, char c = '@') : x(x), y(y), c(c) {}
	Point(const Point& p) : x(p.x), y(p.y) {}
	bool operator==(const Point& p)
	{
		return p.x == x && p.y == y;
	}

	int x;
	int y;
	char c;
};

std::ostream& operator<<(std::ostream& o, const Point& p);
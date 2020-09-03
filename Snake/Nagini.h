#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include "utils.h"

using namespace std;


class Nagini
{
	public:
		Nagini(int, int);
		~Nagini();
		void move(Move);
		void print();
		Segment get_head_coord();
		void add_segment_to_belly();
		vector<Segment> get_belly() { return belly; }
		void reset(Move whereto);
	private:
		void moveBelly(int start);
		Move lastMove;
		Segment head;
		vector<Segment> belly;
};
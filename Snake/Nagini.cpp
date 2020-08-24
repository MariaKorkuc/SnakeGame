#include "Nagini.h"

using namespace std;

Nagini::Nagini(int x_width, int y_width)
{
	x_snake = x_width / 2;
	y_snake = y_width / 2;
	length = 0;
}

Nagini::~Nagini()
{

}

void Nagini::move(Move m)
{
	switch (m)
	{
		case FORWARD:
			x_snake++;
			lastMove = FORWARD;
			head = '>';
			break;
		case BACK:
			x_snake--;
			lastMove = BACK;
			head = '<';
			break;
		case UP:
			y_snake--;
			lastMove = UP;
			head = '^';
			break;
		case DOWN:
			y_snake++;
			lastMove = DOWN;
			head = 'v';
			break;
		default:
			break;
	}
}

void Nagini::print()
{
	string snake;

	for (int i = 0; i < length; i++)
	{
		snake += "-";
	}

	snake += head;
	gotoxy(x_snake, y_snake);
	cout << snake << endl;


}


Point Nagini::get_head_coord()
{
	return Point(x_snake, y_snake);
}
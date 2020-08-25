#include "Nagini.h"

using namespace std;

Nagini::Nagini(int x_width, int y_width)
{
	head = Segment(x_width / 2, y_width / 2, '>', BACK);
	lastMove = FORWARD;
}

Nagini::~Nagini()
{

}

void Nagini::move(Move m)
{
	moveBelly(belly.size()-1);
	switch (m)
	{
		case FORWARD:
			head.x++;
			head.c = '>';
			head.next_pos = BACK;
			break;
		case BACK:
			head.x--;
			head.c = '<';
			head.next_pos = FORWARD;
			break;
		case UP:
			head.y--;
			head.c = '^';
			head.next_pos = DOWN;
			break;
		case DOWN:
			head.y++;
			head.c = 'v';
			head.next_pos = UP;
			break;
		default:
			break;
	}

	lastMove = m;

}

void Nagini::print()
{
	cout << head;
	for(auto seg : belly)
	{
		cout << seg;
	}
}

Segment Nagini::get_head_coord()
{
	return head;
}

void Nagini::add_segment_to_belly()
{
	if (belly.size())
	{
		Segment prev(belly[belly.size() - 1]);
		int x, y;
		char seg;

		switch (prev.next_pos)
		{
		case FORWARD:
			seg = '-';
			x = prev.x - 1;
			y = prev.y;
			break;
		case BACK:
			seg = '-';
			x = prev.x + 1;
			y = prev.y;
			break;
		case DOWN:
			seg = '|';
			x = prev.x;
			y = prev.y + 1;
			break;
		case UP:
			seg = '|';
			x = prev.x;
			y = prev.y - 1;
			break;
		default:
			seg = 'x';
			x = prev.x - 1;
			y = prev.y;
			break;
		}

		Segment s(x, y, seg, prev.next_pos);
		belly.push_back(s);

	}
	else
	{
		char seg;
		int x, y;
		Move next;

		switch (head.c)
		{
		case '<':
			seg = '-';
			x = head.x + 1;
			y = head.y;
			next = FORWARD;
			break;
		case '>':
			seg = '-';
			x = head.x - 1;
			y = head.y;
			next = BACK;
			break;
		case '^':
			seg = '|';
			x = head.x;
			y = head.y + 1;
			next = DOWN;
			break;
		case 'v':
			seg = '|';
			x = head.x;
			y = head.y - 1;
			next = UP;
			break;
		default:
			seg = '>';
			x = head.x;
			y = head.y;
			next = BACK;
			break;
		}

		Segment segment(x,y,seg, next);
		belly.push_back(segment);
	}
}

void Nagini::moveBelly(int start)
{
	if (start == -1)
	{
		return;
	}

	if (!start)
	{
		//dla pierwszego po g³owie
		belly[start] = head;
		if (lastMove == FORWARD || BACK)
		{
			belly[start].c = '-';
		}
		else
		{
			belly[start].c = '|';
		}
	}
	else
	{
		belly[start] = belly[start - 1];
	}

	moveBelly(start - 1);
}
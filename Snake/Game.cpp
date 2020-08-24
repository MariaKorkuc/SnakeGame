#include "Game.h"


Game::Game(int width, int height) : snake(width, height)
{
    this->width = width;
    this->height = height;
    points = 0;
    lives = 3;
    setFruit();
    step();
}

Game::~Game()
{

}

void Game::run()
{
    int key;

    do
    {
        key = _getch();
        switch (key)
        {
        case 'd':
            snake.move(FORWARD);
            break;
        case 'a':
            snake.move(BACK);
            break;
        case 's':
            snake.move(DOWN);
            break;
        case 'w':
            snake.move(UP);
            break;
        default:
            break;
        }

        check_fruit_eaten();
        step();
    } while (key != 'x');
}

void Game::step()
{
    clearScreen();
    cout << fruit;
    snake.print();
}

void Game::clearScreen()
{
    system("cls");
    setBoundries();
}

void Game::setBoundries()
{
    for (int x = 0; x < width; x++)
    {
        gotoxy(x, 0);
        cout << "*";

        gotoxy(x, height - 1);
        cout << "*";
    }

    for (int y = 0; y < height; y++)
    {
        gotoxy(0, y);
        cout << "*";

        gotoxy(width-1, y);
        cout << "*";
    }
}


void Game::setFruit()
{
    int x_fruit, y_fruit;
    Point fr;

    do {
        x_fruit = rand() % (width - 2) + 1;
        y_fruit = rand() % (height - 2) + 1;
        fr = Point(x_fruit, y_fruit);
    } while (fr == snake.get_head_coord());

    fruit = fr;
}


bool Game::check_fruit_eaten()
{
    if (fruit == snake.get_head_coord())
    {
        points += 10;
        setFruit();
        return true;
    }

    return false;
}


const void Game::printPoints()
{
    cout << "Points in current game: " << points << endl;
}
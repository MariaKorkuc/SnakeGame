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
        check_stepped_on_boundries();
        check_ate_himself();
        if (!lives)
        {
            cout << "GAME OVER\n";
            break;
        }
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
    //system("cls");
    //setBoundries();
    HANDLE                     hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                      count;
    DWORD                      cellCount;
    COORD                      homeCoords = { 0, 0 };

    hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hStdOut == INVALID_HANDLE_VALUE) return;

    /* Get the number of cells in the current buffer */
    if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    /* Fill the entire buffer with spaces */
    if (!FillConsoleOutputCharacter(
        hStdOut,
        (TCHAR)' ',
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Fill the entire buffer with the current colors and attributes */
    if (!FillConsoleOutputAttribute(
        hStdOut,
        csbi.wAttributes,
        cellCount,
        homeCoords,
        &count
    )) return;

    /* Move the cursor home */
    SetConsoleCursorPosition(hStdOut, homeCoords);
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
    Segment fr;

    do {
        x_fruit = rand() % (width - 2) + 1;
        y_fruit = rand() % (height - 2) + 1;
        fr = Segment(x_fruit, y_fruit);
    } while (fr == snake.get_head_coord());

    fruit = fr;
}


bool Game::check_fruit_eaten()
{
    if (fruit == snake.get_head_coord())
    {
        points += 10;
        setFruit();
        snake.add_segment_to_belly();
        return true;
    }

    return false;
}


bool Game::check_stepped_on_boundries()
{
    Segment coord = snake.get_head_coord();

    if (coord.x == 1 || coord.x == width-1)
    {
        lives--;
        points -= 20;
        resetSnake(coord.x == 1 ? FORWARD : BACK);
        return true;
    }

    if (coord.y == 1 || coord.y == height-1)
    {
        lives--;
        points -= 20;
        resetSnake(coord.y == 1 ? DOWN : UP);
        return true;
    }

    return false;
}

bool Game::check_ate_himself()
{
    Segment coord = snake.get_head_coord();
    for (auto seg : snake.get_belly())
    {
        if (coord == seg)
        {
            points -= 20;
            lives--;
            return true;
        }
    }
    return false;
}


const void Game::printPoints()
{
    cout << "Points in current game: " << points << endl;
}

void Game::resetSnake(Move where)
{
    snake.reset(where);
}
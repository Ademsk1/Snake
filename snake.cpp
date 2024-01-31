#include <vector>
#include "s.hpp"
#include "grid.hpp"
#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    Grid grid = Grid(10);
    Snake snake = Snake({3, 3}, 10);
    bool continue_game = true;
    while (continue_game)
    {

        grid.print_grid();
        snake.check_user_input();
        snake.move();
        grid.clear();
        grid.draw(snake.body);
        grid.print_grid();
        Sleep(1000);
    }
}

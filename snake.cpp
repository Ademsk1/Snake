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
    grid.place_cherry(snake.body);
    bool continue_game = true;
    while (continue_game)
    {
        system("cls");
        snake.check_user_input();
        snake.move();
        grid.check_if_eaten(snake);
        grid.draw(snake.body);
        grid.print_grid();
        Sleep(500);
        grid.clear();
        continue_game = snake.eat_self();
    }
}

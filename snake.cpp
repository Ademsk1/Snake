#include <vector>
#include <chrono>
#include <thread>
#include "s.hpp"
#include "grid.hpp"
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
int main()
{

    Snake snake = Snake({3, 3});
    Grid grid = Grid(10, snake);
    bool continue_game = true;

    while (continue_game)
    {
        grid.print_grid();
        snake.move_head();
        std::cout << snake.get_head_position()[0] << ", " << snake.get_head_position()[1] << "\n";
        grid.clear();
        grid.draw(snake);
        grid.print_grid();
    }
}

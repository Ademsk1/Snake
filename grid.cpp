#include "s.hpp"
#include "grid.hpp"
#include <iostream>
#include <vector>

Grid::Grid(int setSize, Snake &snake)
{
    size = setSize;
    grid.resize(size);

    for (int i = 0; i < size; i++)
    {
        grid[i].resize(size);
    }

    vector<int> head = snake.get_head_position();
    grid[head[0]][head[1]] = true;
}

void Grid::draw(Snake &snake)
{
    vector<int> head = snake.get_head_position();
    grid[head[0]][head[1]] = true;
}

void Grid::clear()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            grid[i][j] = 0;
        }
    }
}

void Grid::print_grid()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << grid[i][j];
        };
        std::cout << "\n";
    }
    std::cout << "\n";
}
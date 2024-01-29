#include "s.hpp"
#include "grid.hpp"
#include <iostream>
#include <vector>
Grid::Grid(int size, Snake Snake)
{
    vector<vector<int>> grid(size, vector<int>(size, 0));

    array<int, 2> head = Snake.get_head_position();
    grid[head[0]][head[1]] = true;
}

Grid::print_grid()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            std::cout << grid[i][j]
        }
    }
}
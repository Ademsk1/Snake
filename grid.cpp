#include "s.hpp"
#include "grid.hpp"
#include <iostream>
#include <vector>

Grid::Grid(int setSize)
{
    size = setSize;
    grid.resize(size);

    for (int i = 0; i < size; i++)
    {
        grid[i].resize(size);
        fill(grid[i].begin(), grid[i].end(), unoccupied);
    }
    place_cherry();
}

void Grid::place_cherry()
{
    int &ir = icherry;
    int &jr = jcherry;
    ir = rand() % size;
    jr = rand() % size;
}

void Grid::draw(vector<vector<int>> body)
{
    for (vector<int> cell : body)
    {
        grid[cell[0]][cell[1]] = occupied;
    }
    grid[icherry][jcherry] = cherry;
}

void Grid::check_if_eaten(Snake &snake)
{
    if (snake.body[0][0] == icherry & snake.body[0][1] == jcherry)
    {
        place_cherry();
        snake.eat(icherry, jcherry);
    }
}

void Grid::clear()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            grid[i][j] = unoccupied;
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
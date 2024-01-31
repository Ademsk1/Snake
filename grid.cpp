#include "s.hpp"
#include "grid.hpp"
#include <iostream>
#include <vector>

Grid::Grid(int setSize)
{
    size = setSize;
    string tb(size + 2, '-');
    top_bottom = tb;
    grid.resize(size);

    for (int i = 0; i < size; i++)
    {
        grid[i].resize(size);
        fill(grid[i].begin(), grid[i].end(), unoccupied);
    }
}

void Grid::place_cherry(vector<vector<int>> body)
{
    int &ir = icherry;
    int &jr = jcherry;
    vector<int> cherry_position = {ir, jr};
    bool inside_snake = true;
    if (body.size() == body.size() * body.size())
    {
        return;
    }
    while (inside_snake)
    {
        inside_snake = false;
        ir = rand() % size;
        jr = rand() % size;
        for (auto cell : body)
        {
            if (ir == cell[0] && jr == cell[1])
            {
                inside_snake = true;
            }
        }
    }
}

void Grid::draw(vector<vector<int>> body)
{
    grid[icherry][jcherry] = cherry;
    for (vector<int> cell : body)
    {
        grid[cell[0]][cell[1]] = occupied;
    }
}

void Grid::check_if_eaten(Snake &snake)
{
    if (snake.body[0][0] == icherry & snake.body[0][1] == jcherry)
    {
        place_cherry(snake.body);
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
    std::cout << top_bottom << "\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << "|";
        for (int j = 0; j < size; j++)
        {
            std::cout << grid[i][j];
        };
        std::cout << "|\n";
    }
    std::cout << top_bottom << "\n";
}
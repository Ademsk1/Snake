#include "s.hpp"

Snake::Snake(array<int, 2> starting_position)
{
    position = starting_position;
    length = 2;
};

void Snake::change_direction(array<int, 2> new_direction)
{
    if (direction[0] * new_direction[0] || direction[1] * new_direction[1])
    {
        return;
    }
    direction = new_direction;
}

std::array<int, 2> Snake::get_direction()
{
    return direction;
}

std::array<int, 2> Snake::get_head_position()
{
    return position;
}

array<int, 2> Snake::move_head()
{
    for (int i; i < 2; i++)
    {
        position[i] += direction[i];
    }
}
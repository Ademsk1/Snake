#include "s.hpp"
#include <iostream>
Snake::Snake(vector<int> starting_position)
{
    position = starting_position;
    length = 2;
};

void Snake::change_direction(vector<int> new_direction)
{
    if (direction[0] * new_direction[0] || direction[1] * new_direction[1])
    {
        return;
    }
    direction = new_direction;
}

vector<int> Snake::get_direction()
{
    return direction;
}

vector<int> Snake::get_head_position()
{
    return position;
}

vector<int> Snake::move_head()
{
    std::cout << "Old head position" << position[0] << ", " << position[1] << "\n";
    std::cout << "Old head direction" << direction[0] << ", " << direction[1] << "\n";
    position[0] += direction[0];
    position[1] += direction[1];

    std::cout << "New head position: " << position[0] << ", " << position[1] << "\n";
}
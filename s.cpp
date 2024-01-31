#include "s.hpp"
#include <iostream>
#include <unordered_map>
#include <windows.h>
Snake::Snake(vector<int> starting_position, int gridsize) : gridsize(gridsize)
{
    position = starting_position;
    body.push_back(position);
    body.push_back({position[0], position[0] - 1});
};

void Snake::eat(int i, int j)
{
    body.push_back({i, j});
}
void Snake::change_direction(vector<int> new_direction)
{
    if (direction[0] * new_direction[0] || direction[1] * new_direction[1])
    {
        return;
    }
    direction = new_direction;
}
vector<vector<int>> Snake::get_body_position()
{
    return body;
}

bool Snake::eat_self()
{
    for (int i = 1; i < body.size(); i++)
    {
        if (body[i][0] == body[0][0] && body[i][1] == body[0][1])
        {
            return false;
        }
    }
    return true;
}

void Snake::move()
{

    for (int i = body.size() - 1; i > 0; i--)
    {
        body[i][0] = body[i - 1][0] % gridsize;
        body[i][1] = body[i - 1][1] % gridsize;
    }

    vector<int> &head = body[0];
    checkwrap();
}

void Snake::checkwrap()
{
    vector<int> &head = body[0];
    head[0] += direction[0];
    head[1] += direction[1];
    for (int &i : head)
    {
        if (i == gridsize)
        {
            i = 0;
        }
        else if (i == -1)
        {
            i = gridsize - 1;
        }
    }
}

void Snake::check_user_input()
{
    vector<char> inputs = {'A', 'W', 'S', 'D'};
    const unordered_map<char, vector<int>> kdm = {
        {'A', {0, -1}},
        {'S', {1, 0}},
        {'W', {-1, 0}},
        {'D', {0, 1}}};
    for (auto &iter : kdm)
    {
        if (GetAsyncKeyState(iter.first))
        {
            change_direction(iter.second);
        }
    }
}
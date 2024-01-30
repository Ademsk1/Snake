#include <vector>
#ifndef SNAKE
#define SNAKE

using namespace std;
class Snake
{
    vector<int> position = {0, 0}; // TODO:change to center
    int length;
    vector<vector<int>> body;
    vector<int> direction = {0, 1}; // y,x

public:
    void change_direction(vector<int> new_direction);
    vector<int> get_direction();
    vector<int> get_head_position();
    Snake(vector<int> starting_position);
    vector<int> move_head();
};
#endif
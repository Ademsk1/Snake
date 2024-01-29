#include <vector>
using namespace std;
class Snake
{
    array<int, 2> position = {0, 0}; // TODO:change to center
    int length;
    vector<array<int, 2>> body;
    array<int, 2> direction = {0, 1}; // y,x

public:
    void change_direction(array<int, 2> new_direction);
    array<int, 2> get_direction();
    bool valid_direction(array<int, 2> new_direction);
    array<int, 2> get_head_position();
    Snake(array<int, 2> starting_position);
    array<int, 2> move_head();
};
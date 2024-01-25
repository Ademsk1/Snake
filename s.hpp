#include <vector>
using namespace std;
class Snake
{
    array<int, 2> position = {0, 0}; // TODO:change to center
    int length = 2;
    vector<int> body;
    array<int, 2> direction = {0, 1}; // y,x
    //{0 , 1}, {0, -1}
    // {1, 0}, {-1, 0}
    // valid {1, 0} {0, -1}

public:
    void change_direction(array<int, 2> new_direction);
    array<int, 2> get_direction();
    bool valid_direction(array<int, 2> new_direction);
    array<int, 2> get_head_position();
    Snake(array<int, 2> starting_position);
};
#ifndef SNAKE
#define SNAKE
#include <vector>

using namespace std;
class Snake
{
    vector<int> position;
    vector<int> direction = {1, 0}; // y,x
    const int gridsize;
    bool increase_size;

public:
    vector<vector<int>> body;
    void change_direction(vector<int> new_direction);
    vector<vector<int>> get_body_position();
    Snake(int gridsize);
    void move();
    void checkwrap();
    void eat(int i, int j);
    void check_user_input();
    bool eat_self();
};
#endif
#include "s.hpp"
using namespace std;

class Grid
{
    int size;
    vector<vector<bool>> grid;

public:
    Grid(int size, Snake &snake);
    void print_grid();
    void clear();
    void draw(Snake &snake);
};
#include "s.hpp"
using namespace std;

class Grid
{
    int size = 8;
    vector<int> row(8, 0);
    vector<vector<int>> grid(8, vector<int>(8));

public:
    Grid(int size, Snake snake);
    void print_grid();
};
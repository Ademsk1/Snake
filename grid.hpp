#include "s.hpp"
#include <string>
using namespace std;

class Grid
{
    int size;
    string top_bottom;
    string unoccupied = " ";
    string occupied = "o";
    string cherry = "x";
    vector<vector<string>> grid;

public:
    int icherry;
    int jcherry;
    Grid(int size);
    void print_grid();
    void clear();
    void draw(vector<vector<int>> body);
    void place_cherry(vector<vector<int>> body);
    void check_if_eaten(Snake &snake);
};
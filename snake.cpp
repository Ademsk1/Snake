#include <vector>
#include <chrono>
#include <thread>
#include "s.hpp"
#include "grid.hpp"

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono;      // nanoseconds, system_clock, seconds
using namespace std;

int main()
{
    // declare size of arena
    //
    Grid game = Grid(10);
    bool continue_game = true;

    while (continue_game)
    {

        sleep_until(system_clock::now() + seconds(1));
    }
}

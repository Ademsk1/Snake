#include <vector>
#include "s.hpp"
#include "grid.hpp"
#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

void ClearScreen()
{
    COORD cursorPosition;
    cursorPosition.X = 0;
    cursorPosition.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

bool Game()
{
    string play_again;
    srand(time(NULL));
    int difficulty;
    int game_size;
    cout << "Welcome to Snake!\n\n";
    cout << "What size do you want the grid to be?: ";
    cin >> game_size;
    Grid grid = Grid(game_size);
    Snake snake = Snake(game_size);
    grid.place_cherry(snake.body);
    cout << "Input difficulty:\n(1) Easy\n(2) Normal \n(3) Hard\n";
    cin >> difficulty;
    int time_difficulty = 300 / difficulty;
    bool continue_game = true;
    system("cls");
    while (continue_game)
    {
        ClearScreen();
        snake.check_user_input();
        snake.move();
        grid.check_if_eaten(snake);
        grid.draw(snake.body);
        grid.print_grid();
        Sleep(time_difficulty);
        grid.clear();
        continue_game = snake.eat_self();
    }
    system("cls");
    cout << "You Lost!\n\n Your score: " << grid.get_score() << "\n";
    FlushConsoleInputBuffer(GetStdHandle(STD_INPUT_HANDLE));
    cout << "Would you like to play again? (y/n): ";
    cin >> play_again;
    cout << "\n";
    if (play_again == "y")
    {
        return true;
    }
    return false;
}
int main()
{
    bool play_again = true;
    while (play_again)
    {
        play_again = Game();
    }
}

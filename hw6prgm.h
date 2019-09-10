#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
#include <cstring>
using namespace std;


// Printing introduction 
void print_Intro();

//printing game Introduction and rules
void game_Intro();

// Creating a enum array for the two dimensional array
enum pieces {Flag = 'F', Bomb = 'B', Marshal = '1', General = '2', Colonel = '3', Major = '4', Captain = '5', Lieutentant = '6', Sergeant = '7', Miner = '8', Spy = 'S', blank = ' ' };

// Creating a second enum type to keep tarck of the color
enum Color { Red = 'R', Blue = 'B', None = 'N' };

// Creating a struct for the piece 
struct piece {
	pieces rank;
	Color color;
	bool movable;
	pieces hidden;
};

// constant variable for the size of the array
const int board_size = 5;

// Function to initialize the board
void initial_board(piece **board);

// Function to set the pieces
void set_board(piece **board);

// Sets the color for the pieces 
void set_color(piece **board);
// Sets the movement to valid pieces 
void set_movement(piece **board);

// Prints the board
void print_board(piece **board, bool reveal);

// Random selecting
void random_select(pieces values[]);

//checks the rules to see if the piece can me moved to the spot 
bool move_check(piece **board, int x1, int y1, int x2, int y2);

// gets the input coordinates from the user
string get_coordinates(int &x, int&y, string message);
// clears input in a line
void new_line();

// check the movement of a piece
bool check_move (int x1, int x2, int y1, int y2, piece **board);
// Moves the piece
string move_piece(int x1, int x2, int y1, int y2, piece **board);

//Compares to pieces' rank and determines the winner
string compare_pieces(int x1, int x2, int y1, int y2, piece **board);

// End game info
void end_game();

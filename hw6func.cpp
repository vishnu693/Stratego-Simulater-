#include "hw6prgm.h"

/*
============================================================================
Function : print_Intro
Parameters : nothing
Return :nothing, it is a void function
Description : The function prints out the intro
============================================================================
*/
void print_Intro()
{
	// printig out my information
	cout << "+------------------------------------------------------------+" << endl;
	cout << "|              Computer Science and Engineering              |" << endl;
	cout << "|               CSCE 1030 - Computer Science I               |" << endl;
	cout << "|      Vishnu Kommineni vk0175  VishnuKommineni@my.unt.edu   |" << endl;
	cout << "+------------------------------------------------------------+" << endl;
	cout << endl;
	return ;
}


/*
============================================================================
Function : game_Intro
Parameters : nothing
Return :nothing, it is a void function
Description : The function prints out the introduction and the rules for the game
============================================================================
*/
void game_Intro()
{
	cout << "This program will set up a 5x5 game board for a 1030 version of the game of Stratego.One player will compete against the computer, each assigned 10 total pieces consisting of the following :" << endl;
	cout << "   1 FLAG (F)\n   3 BOMB(B)\n   1 MARSHAL(1) or GENERAL(2)\n   3 COLONEL(3), MAJOR(4), CAPTAIN(5), LIEUTENANT(6), or SERGEANT(7)\n   1 MINER(8)\n   1 SPY(S) " << endl;
	cout << endl;
	cout << "GENERAL RULES: " << endl;
	cout << "-------------------------" << endl;
	cout << "For the most part, the game will follow the standard Stratego rules, although there are some exceptions. " << endl;
	cout << endl;
	cout << "1. Both players (BLUE and RED) will have all of their 10 game pieces assigned randomly with the only requirement being that the FLAG must be placed in the back row.RED will start the game first." << endl;
	cout << endl;
	cout << "2. Higher ranked pieces can capture lower ranked pieces in the following order: 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8->S, meaning that 1 (the MARSHAL) can remove 2 (the GENERAL) and so forth.The MINER(8) piece may strike a BOMB and remove it to occupy the now unoccupied space.A SPY(S), although the lowest ranked piece, may remove the MARSHAL(1) or the GENERAL(2)." << endl;
	cout << endl;
	cout << "3. The FLAG and BOMBs are not moveable while all of the other pieces may move one square at a time forward, backward, or sideward, but not diagonally to an open square." << endl;
	cout << endl;
	cout << "4. A player must either move or strike on his/her turn." << endl;
	cout << endl;
	cout << "5. The game ends when a player strikes his/her opponent's flag." << endl;
	cout << endl;
	cout << "-------------------------------------------------------------------------------------" << endl;
	cout << endl;
	return ;
}

/*
============================================================================
Function : initial_board
Parameters : pointer that points to the two dimentional array
Return :nothing, but initializes the array
Description : The function in initializes the value to the array
============================================================================
*/

void initial_board(piece **board){

	for (int i = 0; i < board_size; i++) {
		for (int j = 0; j < board_size; j++) {
			board[i][j].rank = blank;
		}
	}

	return;
}

/*
============================================================================
Function : set_board
Parameters : pointer that points to the two dimentional array
Return :nothing, but initializes the array
Description : The set the value to the array
============================================================================
*/
void set_board(piece** board){
	srand(time(NULL));

	int array_size = 10;
	pieces values[11];
	random_select(values);

	for (int i = 0; i < board_size; i++) {
		if (i == 3) {
			random_select(values);
		}
		for (int j = 0; j < board_size; j++) {

			if (i == 0)
			{
				board[i][j].rank = values[j];
			}
			else if (i == 1) {
				board[i][j].rank = values[j + 5];
			}
			else if (i == 3) {
				board[i][j].rank = values[j + 5];
			}
			else if (i == 4)
			{
				board[i][j].rank = values[j];
			}
		}

	}
	return;
}

/*
============================================================================
Function : random_select
Parameters : a one dimentional array
Return :nothing, but sets values in teh inputed array
Description : choses the placement of the pieces and puts it in the array
============================================================================
*/

void random_select(pieces values[]){
	for (int i = 0; i< 10; i++)
	{
		values[i] = blank;
	}
	char characters[10] = { 'B','B','B','M','S','X','Y','Y','Y' };
	int array_size = 9;
	// randomly placing the flag
	int flag_pos = rand() % board_size;
	values[flag_pos] = Flag;
	for (int i = 0; i < array_size; i++)
	{
		while (characters[i] != ' ') {
			int rand_num = rand() % 11;
			if (values[rand_num] == ' ')
			{
				if (characters[i] == 'B')
				{
					values[rand_num] = Bomb;
					characters[i] = ' ';
				}
				else if (characters[i] == 'M')
				{
					values[rand_num] = Miner;
					characters[i] = ' ';
				}
				else if (characters[i] == 'S')
				{
					values[rand_num] = Spy;
					characters[i] = ' ';
				}
				else if (characters[i] == 'X')
				{
					int ran_choice = rand() % 2;

					if (ran_choice == 0)
					{
						values[rand_num] = Marshal;
						characters[i] = ' ';
					}
					else
					{
						values[rand_num] = General;
						characters[i] = ' ';
					}
				}
				else if (characters[i] == 'Y')
				{
					int ran_choice = rand() % 5;

					if (ran_choice == 0)
					{
						values[rand_num] = Colonel;
						characters[i] = ' ';
					}
					else if (ran_choice == 1)
					{
						values[rand_num] = Major;
						characters[i] = ' ';
					}
					else if (ran_choice == 2)
					{
						values[rand_num] = Captain;
						characters[i] = ' ';
					}
					else if (ran_choice == 3)
					{
						values[rand_num] = Lieutentant;
						characters[i] = ' ';
					}
					else if (ran_choice == 4)
					{
						values[rand_num] = Sergeant;
						characters[i] = ' ';
					}

				}
			}
		}
	}

	return;
}

/*
============================================================================
Function : set_color
Parameters : the two dimentional array
Return : nothing, but initializes the array
Description : The set the color values to the peices
============================================================================
*/

void set_color(piece **board){
	for (int i = 0; i <board_size; i++)
	{
		for (int j = 0; j < board_size; j++)
		{
			if (i == 0 || i == 1)
			{
				board[i][j].color = Blue;
			}
			else if (i == 2)
			{
				board[i][j].color = None;
			}
			else if (i == 3 || i == 4)
			{
				board[i][j].color = Red;
			}
		}
	}
	return;
}


/*
============================================================================
Function : print_board
Parameters : the two dimentional array
Return :nothing, but initializes the array
Description : The function in initializes the value to the array
============================================================================
*/

void print_board(piece **board, bool reveal){
	cout << "     1 2 3 4 5" << endl;
	cout << "   +-----------+" << endl;
	for (int i = 0; i < board_size; i++) {
		if (i == 0)
		{
			cout << "A  | ";
		}
		else if (i == 1)
		{
			cout << "B  | ";
		}
		else if (i == 2)
		{
			cout << "C  | ";
		}
		else if (i == 3)
		{
			cout << "D  | ";
		}
		else if (i == 4)
		{
			cout << "E  | ";
		}
		for (int j = 0; j < board_size; j++) {
			if ( board[i][j].color == 'B')
			{
				if(reveal == true)
				{
					printf("\033[1;34m%c\033[0m ", static_cast<char>(board[i][j].rank));
				}
				else if (reveal == false && board[i][j].rank != blank){
					printf("\033[1;34m%c\033[0m ", 'X');
				}
				else{
					 cout << static_cast <char>(board[i][j].rank) << " ";
				}
			}
			 else if ( board[i][j].color == 'R')
            {
                printf("\033[1;31m%c\033[0m ", static_cast<char>(board[i][j].rank));
            }
			 else {
				 cout << static_cast <char>(board[i][j].rank) << " ";
			 }
						
		}
		cout << "|" << endl;
	}
	cout << "   +-----------+" << endl;
	return;
}

/*
============================================================================
Function : set_movement
Parameters : the two dimentional array
Return : nothing, but initializes the array
Description : The function sets movement to valid pieces 
============================================================================
*/
	void set_movement(piece **board)
	{
		for(int i =0; i< board_size; i++)
		{
			for(int y =0; y < board_size; y++)
			{
				if(board[i][y].rank == Bomb||board[i][y].rank == Flag||board[i][y].rank == blank)
				{
					board[i][y].movable = false;
				}
				else
				{
					board[i][y].movable = true;
				}
			}
		}
	}
	
	
/*
============================================================================
Function : new_line
Parameters : none
Return : none
Description : clears teh input stream
============================================================================
*/
	void new_line()
	{
	  char symbol;
	  do{
		  cin.get(symbol);
	  }while(symbol!= '\n');
	}


	
/*
============================================================================
Function : get_coordiantes
Parameters : integers that have a cetrain value and message to print out
Return :  the location in the form of a string
Description : reads in the cordinates and changes it into number values
============================================================================
*/
string get_coordinates(int &x, int&y, string message)
{
	char c = ' ';
	char d = ' ';
	bool valid = false;
	bool error = false;
	string s;
		while (valid == false)
		{ cout << message;
			cin.get(c);
			cin.get(d);
			if( c == 'Q' && d =='Q')
			{
				return "QQ";
			}
			cin.putback(d);
			cin.putback(c);
			cin >> s;
			if(isalpha(c))
			{
				if(c > 64 && c < 70)
				{
					x = static_cast<int>(c-65);
					valid =true;
				}
				else if( c >= 97 && c <= 101)
				{
					x = static_cast<int>(c-97);
					valid =true;
				}
				else 
				{
					error = true;
				}
			}
			else{
				error = true;
				}
			
			if(isdigit(d) && valid == true)
			{
				cin.putback(d);
				cin >>y;
				if(y >=1 && y <= 5)
				{
					y -=1;
					valid = true;
				}
				else
				{
					valid = false;
					error = true;
				}
			}
			else{
				valid = false;
				error = true;
			}
			if(error == true)
			{
				cout << "Error: Invalid piece or not movable at " << c << d << " . Try again ...."<<endl;
			}
		}
		return s;
		
}


/*
============================================================================
Function : check_move
Parameters : integers that have the coordinates of the move
Return :  a boolean expression to see if the value works
Description : takes in the corordinates and checks if the move is valid
============================================================================
*/
bool check_move (int x1, int x2, int y1, int y2,piece **board )
{
	if(board[x1][y1].movable == false)
	{
		return false;
	}
	if(board[x1][y1].color == Blue)
	{
		return false;
	}
	
	if(board[x2][y2].color == Red)
	{
		return false;
	}
	if(x1 == (x2 -1) && y1 == y2) // up movement
	{
		return true;
	}
	else if(x1 ==x2 && y2 == (y1+1) ) // right movement
	{
		return true;
	}
	else if(x1 ==x2 && y2 == (y1-1) ) // left movement
	{
		return true;
	}
	else if(x1 == (x2 +1) && y1 == y2) // up movement
	{
		return true;
	}
	else 
	{
		return false;
	}
}

/*
============================================================================
Function : move_piece
Parameters : integers that have the coordinates of the move and the board
Return :  none
Description : updates the pieces location
============================================================================
*/
string move_piece(int x1, int x2, int y1, int y2, piece **board)
{
	// Blank piece
	piece empty;
	empty.rank = blank;
	empty.color = None;
	empty.movable = false;
	string out;
	
	
	if(board[x2][y2].rank == blank)
	{
		board[x2][y2] = board[x1][y1];
		board[x1][y1] = empty;
	}
	else
	{
		out =compare_pieces(x1, x2, y1, y2, board);
	}
	print_board(board, false);
	return out;
	
}

/*
============================================================================
Function : compare_pieces
Parameters : integers that have the coordinates of the moves and the board
Return :  none
Description : updates the pieces location
============================================================================
*/
string compare_pieces(int x1, int x2, int y1, int y2, piece **board)
{
	// Blank piece
	piece empty;
	empty.rank = blank;
	empty.color = None;
	empty.movable = false;

	if(board[x2][y2].rank == Flag)
	{
		board[x2][y2] = board[x1][y1];
			board[x1][y1] = empty;
		return "WIN";
	}
	else if(isdigit(board[x1][y1].rank) && isdigit(board[x2][y2].rank))
	{
		if(board[x1][y1].rank > board[x2][y2].rank && board[x2][y2].color == Blue)
		{
			cout<<"RED " <<static_cast<char> (board[x1][y1].rank) <<" at " << static_cast<char> (x2 + 65) << (y2+1) << " is captured by BLUE "<< static_cast<char> (board[x2][y2].rank)<< " at "<< static_cast<char> (x2 + 65) << (y2+1)<<endl;
			board[x1][y1] = empty;
	
		}
		else if(board[x1][y1].rank < board[x2][y2].rank && board[x2][y2].color == Blue)
		{
			cout<<"RED " <<static_cast<char> (board[x1][y1].rank) <<" at " << static_cast<char> (x2 + 65) << (y2+1) << " captured BLUE "<< static_cast<char> (board[x2][y2].rank)<< " at "<< static_cast<char> (x2 + 65) << (y2+1)<<endl;
			board[x2][y2] = board[x1][y1];
			board[x1][y1] = empty;
		}
		else if(board[x1][y1].rank == board[x2][y2].rank && board[x2][y2].color == Blue)
		{
			cout<<"RED " <<static_cast<char> (board[x1][y1].rank) <<" at " << static_cast<char> (x2 + 65) << (y2+1) << " captured BLUE "<< static_cast<char> (board[x2][y2].rank)<< " at "<< static_cast<char> (x2 + 65) << (y2+1)<<endl;
			board[x1][y1] = empty;
			board[x2][y2] = empty;
		}
	}
	else if(board[x2][y2].rank == Bomb)
	{
		if(board[x1][y1].rank == Miner)
		{
			cout<<"RED " <<static_cast<char> (board[x1][y1].rank) <<" at " << static_cast<char> (x2 + 65) << (y2+1) << " captured BLUE "<< static_cast<char> (board[x2][y2].rank)<< " at "<< static_cast<char> (x2 + 65) << (y2+1)<<endl;
			board[x2][y2] = board[x1][y1];
			board[x1][y1] = empty;
		}
		else 
		{
			cout<<"RED " <<static_cast<char> (board[x1][y1].rank) <<" at " << static_cast<char> (x2 + 65) << (y2+1) << " is captured by BLUE "<< static_cast<char> (board[x2][y2].rank)<< " at "<< static_cast<char> (x2 + 65) << (y2+1)<<endl;
			board[x1][y1] = empty;
			
		}
	}
	else if(board[x1][y1].rank == Spy)
	{
		if(board[x2][y2].rank == Marshal || board[x2][y2].rank == General)
		{
			cout<<"RED " <<static_cast<char> (board[x1][y1].rank) <<" at " << static_cast<char> (x2 + 65) << (y2+1) << " captured BLUE "<< static_cast<char> (board[x2][y2].rank)<< " at "<< static_cast<char> (x2 + 65) << (y2+1)<<endl;
			board[x2][y2] = board[x1][y1];
			board[x1][y1] = empty;
		}
		else
		{
			cout<<"RED " <<static_cast<char> (board[x1][y1].rank) <<" at " << static_cast<char> (x2 + 65) << (y2+1) << " is captured by BLUE "<< static_cast<char> (board[x2][y2].rank)<< " at "<< static_cast<char> (x2 + 65) << (y2+1)<<endl;
			board[x1][y1] = empty;
		}
	}
	else if(board[x2][y2].rank == Spy)
	{
		if(board[x1][y1].rank == Marshal || board[x1][y1].rank == General)
		{
			cout<<"RED " <<static_cast<char> (board[x1][y1].rank) <<" at " << static_cast<char> (x2 + 65) << (y2+1) << " is captured by BLUE "<< static_cast<char> (board[x2][y2].rank)<< " at "<< static_cast<char> (x2 + 65) << (y2+1)<<endl;
			board[x1][y1] = empty;
		}
		else
		{
			cout<<"RED " <<static_cast<char> (board[x1][y1].rank) <<" at " << static_cast<char> (x2 + 65) << (y2+1) << " captured BLUE "<< static_cast<char> (board[x2][y2].rank)<< " at "<< static_cast<char> (x2 + 65) << (y2+1)<<endl;
			board[x2][y2] = board[x1][y1];
			board[x1][y1] = empty;
		}
	}
	return "";
}

/*
============================================================================
Function : end_game
Parameters : none
Return :  none
Description : prints the end message 
============================================================================
*/

void end_game()
{
	cout<<"Thank you for playing the game!"<<endl;
}

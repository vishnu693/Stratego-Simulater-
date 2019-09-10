#include "hw6prgm.h"

int main()
{
	// creating a 2 dimensional  dynamic array 
	piece **board = new piece*[board_size];
	for (int i = 0; i < board_size; i++)
	{
		board[i] = new piece[board_size];
	}

	// printing out information using another function
	print_Intro();

	// printing out information about the game and rules using another function
	game_Intro();


	initial_board(board);

	set_board(board);
	set_color(board);
	set_movement(board);
	// Print the board once after initial setup 
	print_board(board, false);
	// variables for coordinates
	int x1,x2,y1,y2;
	string initial = "";
	while (initial !="QQ")
	{
		
		string message = "RED MOVE: Enter current coordinates of piece (e.g., D3, or QQ to quit):";
		initial = get_coordinates(x1, y1, message);
		new_line();
		if(initial == "QQ")
		{ end_game();
			break;
		}
	
		
			while (board[x1][y1].movable == false)
			{
				cout << "Error: Invalid piece or not movable at " << initial<<endl;
				initial = get_coordinates(x1, y1, message);
				new_line();
				if(initial == "QQ")
				{
					end_game();
					break;
				}
				
			}
				
		string message_1 = "RED MOVE: Enter new coordinates of piece at " + initial + ":";
		string new_location = get_coordinates(x2, y2, message_1);
		new_line();
		if(new_location == "QQ")
				{
					end_game();
				break;
				}
		
		string out;
		bool check = check_move(x1, x2, y1, y2,board);
		if(check == false)
		{
			while (check_move(x1, x2, y1, y2,board) == false)
			{
				cout <<"Invalid piece move from "<< initial <<" to "<< new_location<<endl;
				initial = get_coordinates(x1, y1, message);
				new_line();
				message_1 = "RED MOVE: Enter new coordinates of piece at " + initial + ":";
				new_location = get_coordinates(x2, y2, message_1);	
				new_line();
				if(new_location == "QQ")
				{
					end_game();
					break;
				}
			}
			out = move_piece(x1, x2, y1, y2,board);
		}
		else if (check_move(x1, x2, y1, y2,board) == true)
		{
			out = move_piece(x1, x2, y1, y2, board);
		}
		if(out == "WIN")
		{
			cout<<endl;
			cout<<endl;
			cout << "You won the game"<<endl;
			print_board(board, true);
		}
	}
	
	
	// Delete the dynamic array
	for(int i =0; i< board_size; i++)
	{
		delete [] board[i];
	}
	
	delete [] board;

		return 0;
}



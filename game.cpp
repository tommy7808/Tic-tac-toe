#include "game.h"

Player player1, player2;

void Game::printboard(){
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			std::cout << '[' << board[i][j] << ']' << "\t";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

void Game::startgame()
{
	printboard();

	//create players
	std::cout << "\nPlayer1 Name: ";
	std::cin >> player1.name;
	player1.symbol = 'X';
	std::cout << player1.name << ", your symbol is: " << player1.symbol << std::endl; 

	std::cout << "\nPlayer2 Name: ";
	std::cin >> player2.name;
	player2.symbol = 'O';
	std::cout << player2.name << ", your symbol is: " << player2.symbol << std::endl;

	std::cout << "\n----------";
	std::cout << "\nGAME START";
	std::cout << "\n----------\n";
	gameloop();
}

void Game::gameloop()
{
	char position;
	while(true)
	{
		printboard();

		//player1 turn
		std::cout << player1.name + ": ";
		std::cin >> position;

		add_symbol(position, player1);
		if(check_win(player1))
		{
			printboard();
			break;
		}
		printboard();

		//player2 turn
		std::cout << player2.name + ": ";
		std::cin >> position;
		add_symbol(position, player2);
		if(check_win(player2))
		{
			printboard();
			break;
		} 


	}
}

void Game::add_symbol(char position, Player player)
{
	// Check if valid input is given
	switch (position)
	{
	case '1':
		break;
	case '2':
		break;
	case '3':
		break;
	case '4':
		break;
	case '5':
		break;
	case '6':
		break;
	case '7':
		break;
	case '8':
		break;
	case '9':
		break;
	default:
		std::cout << "Invalid input\n";
		std::cout << "Pick a number between (1-9)\n";

		std::cout << player.name + ": ";
		std::cin >> position;
		add_symbol(position, player);
	}
	//check if this position has already been used
	if(positions[position] == true)
	{
		std::cout << "\nThis position has already been used, please try again.\n";
		std::cout << player.name + ": ";
		std::cin >> position;
		add_symbol(position, player);
	}

	//add symbol to board
	for(int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(board[i][j] == position)
			{
				positions[board[i][j]] = true;
				board[i][j] = player.symbol;	
			}
		}
	}
}

bool Game::check_win(Player player)
{
	std::vector<char> input;
	
	//horizonatal check
	for (int i = 0; i < 3; i++)
	{
		if(board[i][0] == board[i][1] && board[i][1] == board[i][2])
		{
			std::cout << "Congatrulations " << player.name << ", you have won!" << std::endl;
			return true;
		}
	}

	//vertical check
	for (int i = 0; i < 3; i++)
	{
		if(board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			std::cout << "Congatrulations " << player.name << ", you have won!" << std::endl;
			return true;
		}
	}
	
	//diagonal check
	if((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || ((board[0][2] == board[1][1] && board[1][1] == board[2][0])))
	{
		std::cout << "Congatrulations " << player.name << ", you have won!" << std::endl;
		return true;
	}

	return false;
}
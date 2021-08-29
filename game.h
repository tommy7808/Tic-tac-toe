#ifndef GAME
#define GAME
#include <iostream>
#include <string>
#include <vector>
#include <map>

struct Player
{
	std::string name;
	char symbol;
};

class Game
{
	public:
		std::map<char, bool> positions {{'1', false}, {'2', false}, {'3', false}, {'4', false}, {'5', false}, {'6', false}, {'7', false}, {'8', false}, {'9', false}};
		char board[3][3] = {
			{'1', '2', '3'},
			{'4', '5', '6'},
			{'7', '8', '9'}
		};
		void gameloop();
		void startgame();
		void printboard();
		void add_symbol(char position, Player player);
		bool check_win(Player player);
};

#endif
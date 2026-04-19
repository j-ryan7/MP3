/*
Jaden Ryan
4/19/2026

Program Description: Tic Tac D'Oh; A program that lets 2 users play Tic-Tac-Toe as many times as they wish, and keeps track of ties and wins for each player. 
*/
#include<iostream>
#include<string>		//include the string library to use getline for the player names
using namespace std;
const int arraySize = 25;		//the instructions said I could put this as a global variable, so I did in case I needed it
								//the value is 25 because I split the array into 5 rows with 5 characters each. 
int getPlayerInput(string playerName);					//This function will get the input of the selected player
bool isLegalMove(char board[], int location);			//This function will check if the selected move is legal or not
void placeMarkOnBoard(char board[], char playerMark, int location);			//If the move is legal, this replaces the chosen spot with an X or O depending on the player
void clearBoard(char board[]);							//This function resets the board to its default state with no X's and O's
bool hasThreeInRow(char board[], char playerMark);		//This checks if there is 3 in a row of either X or O
void displayBoard(char board[]);						//This displays the board in its current state
void displayGameStats(int ties, int player1Score, int player2Score);		//This displays the number of wins each player has, as well as the number of ties
bool playAgainOrQuit();									//This prompts the user to select if they want to play again or quit
bool isGameTied(char board[]);							//This checks if the game is tied or not


int main() {
	char gameBoard[arraySize] = { '7', '|', '8', '|', '9', '-', '-', '-', '-', '-', '4','|','5','|','6','-', '-', '-', '-', '-', '1','|','2','|','3' };
	//The above array is set to have lines of alternating values and bars between them, as well as lines of horizontal dashes to separate the board further
	string player1 = " ";		//This stores the name of player 1
	string player2 = " ";		//This stores the name of player 2
	char player1Mark = 'X';		//This is the mark for player 1
	char player2Mark = 'O';		//This is the mark for player 2
	int tiedGames = 0;			//This stores the number of tied games
	int player1Wins = 0;		//This stores the number of games player 1 won
	int player2Wins = 0;		//this stores the number of games player 2 won
	int turnCounter = 0;		//this counter is used with the modulo function to determine whether it's player 1 or 2 turn
	bool moveLegal = false;		//This stores the legality of the selected move
	int playerInput = 0;		//This stores the slot that the player chooses
	bool threeInRow = false;	//This stores if a player has met the conditions to win
	bool gameIsTie = false;		//This stores if the game is tied
	bool gameIsWon = false;		//This stores if a player has won
	bool playAgain = true;		//This stores if the player wishes to play again. Must start true because the while loop i used depends on this variable
	cout << "Enter player 1's name: ";		//We only need to ask the names once, so we do so outside of the while loop
	getline(cin, player1);			//getline is used to store the cin value of the string
	cout << "Enter player 2's name: ";		//Do the same thing for player 2
	getline(cin, player2);
	displayBoard(gameBoard);		//Display the board before the loop begins so that player 1 has a reference to pick from
	while (playAgain == true) {		//While the player has not chosen to quit, the game runs
		while (turnCounter % 2 == 0) {			//While the turn counter is even, player 1 runs. It must be even since it starts at zero.
			gameIsWon = hasThreeInRow(gameBoard, player2Mark);		//This checks if player 2 has won the game. I check for player 2, even though it's player 1's turn, as player 2 was the last to make a move
			if (gameIsWon == true) {			//If player 2 has won, it does the following: increase their win count by one, say that they won, reset gameIsWon to false, clear the board,
				player2Wins++;					//show stats on who has won how many times, and prompt if they want to play again
				cout << player2 << " wins!" << endl;
				gameIsWon = false;
				clearBoard(gameBoard);
				displayGameStats(tiedGames, player1Wins, player2Wins);
				playAgain = playAgainOrQuit();
				if (playAgain == false) {		//If they don't want to play again, break this while loop. The next while loop won't run since turn counter is even, 
					break;							//and the outer loop won't run again since playAgain == false
				}
				displayBoard(gameBoard);		//If they picked to play again, display the game board, and continue as normal
			}
			gameIsTie = isGameTied(gameBoard);			//This checks if the game is tied
			if (gameIsTie == true) {		//If it is, do the following: increase tied games by one, say that it's a tie, reset gameIsTie to false, clear the board, display win stats, and prompt to play again
				tiedGames++;
				cout << "It's a tie!" << endl;
				gameIsTie = false;
				clearBoard(gameBoard);
				displayGameStats(tiedGames, player1Wins, player2Wins);
				playAgain = playAgainOrQuit();
				if (playAgain == false) {		//If they don't want to play again, this breaks the loop
					break;
				}
				displayBoard(gameBoard);		//Otherwise, they're playing again, so display a cleared board
			}	
			playerInput = getPlayerInput(player1);		//If the game is not won or tied, ask player 1 for their choice
			moveLegal = isLegalMove(gameBoard, playerInput);		//This checks if they made a legal move
			if (moveLegal == true) {			//If they did choose a legal move, replace the chosen spot on the board with an X, display the new board with the added X,
				placeMarkOnBoard(gameBoard, player1Mark, playerInput);		//and increase the turn count to make it player 2's turn
				displayBoard(gameBoard);
				turnCounter++;
			}
			else {					//If they didn't pick a legal move, tell them, and use continue to reset back to this while loop until they pick a legal move
				cout << "Error: Not a legal move." << endl;
				continue;
			}
		}
		while (turnCounter % 2 == 1) {	//This while loop is mostly the same as lines 46 through 84, but with slight differences.
			gameIsWon = hasThreeInRow(gameBoard, player1Mark);		//instead of checking for player 2 winning, check for player 1 winning
			if (gameIsWon == true) {
				player1Wins++;
				cout << player1 << " wins!" << endl;
				gameIsWon = false;
				clearBoard(gameBoard);
				displayGameStats(tiedGames, player1Wins, player2Wins);
				playAgain = playAgainOrQuit();
				if (playAgain == false) {
					break;
				}
				displayBoard(gameBoard);
			}
			gameIsTie = isGameTied(gameBoard);
			if (gameIsTie == true) {
				tiedGames++;
				cout << "It's a tie!" << endl;
				gameIsTie = false;
				clearBoard(gameBoard);
				displayGameStats(tiedGames, player1Wins, player2Wins);
				playAgain = playAgainOrQuit();
				if (playAgain == false) {
					break;
				}
				displayBoard(gameBoard);
			}
			playerInput = getPlayerInput(player2);			//get the input of player 2 instead, as it is there turn
			moveLegal = isLegalMove(gameBoard, playerInput);
			if (moveLegal == true) {
				placeMarkOnBoard(gameBoard, player2Mark, playerInput);		//replace the chosen spot, if it is legal, with an O instead of an X
				displayBoard(gameBoard);
				turnCounter++;			//this sets the turn counter back to even, making it player 1's turn again
			}
			else {
				cout << "Error: Not a legal move." << endl;
				continue;

			}
		}
	}


	return 0;		//once the while loop is ended, return 0 to end the program
}

int getPlayerInput(string playerName) {			
	int choice = 0;				//This stores the choice that will be returned from the function
	cout << playerName << ": Choose an open spot number to place your mark: ";		//This outputs the name of the player whose turn it is and asks them to choose a spot
	cin >> choice;			//store that choice
	if (choice == 7) {				//This set of if loops checks through the possible inputs and returns the array value of the chosen number
		return 0;
	}
	else if (choice == 8) {
		return 2;
	}
	else if (choice == 9) {
		return 4;
	}
	else if (choice == 4) {
		return 10;
	}
	else if (choice == 5) {
		return 12;
	}
	else if (choice == 6) {
		return 14;
	}
	else if (choice == 1) {
		return 20;
	}
	else if (choice == 2) {
		return 22;
	}
	else if (choice == 3) {
		return 24;
	}
}
bool isLegalMove(char board[], int location) {	
	if ((board[location] == 'X') || (board[location] == 'O') || (location > 24) || (location < 0)) {		//If the chosen spot has an X or an O, then it's an invalid move. The same thing
		return false;																						//applies if it is out of the array bounds. If it's invalid, return false
	}
	else {																									//otherwise, return true
		return true;
	}
}
void placeMarkOnBoard(char board[], char playerMark, int location) {				//this function places a mark at the chosen spot, with the appropriate mark for the current player's turn
	board[location] = playerMark;
}
void clearBoard(char board[]) {		//This sets all of the values that could potentially get replaced with an X or O back to their base values
	board[0] = '7';
	board[2] = '8';
	board[4] = '9';
	board[10] = '4';
	board[12] = '5';
	board[14] = '6';
	board[20] = '1';
	board[22] = '2';
	board[24] = '3';
}
bool hasThreeInRow(char board[], char playerMark) {			//There is 8 possible ways to win: 3 potential columns, 3 potential rows, and 2 diagonals
	if (board[0] == playerMark) {		//If the top left corner is an X or O, then it checks through to see if the topmost row, leftmost column, or one of the diagonals is all the same character
		if ((board[2] == playerMark) && (board[4] == playerMark)) {				//If they are the same, it returns true
			return true;
		}
		else if ((board[10] == playerMark) && (board[20] == playerMark)) {
			return true;
		}
		else if ((board[12] == playerMark) && (board[24] == playerMark)) {
			return true;
		}
	}
	if (board[2] == playerMark) {				//This checks the middle column
		if ((board[12] == playerMark) && (board[22] == playerMark)) {
			return true;
		}
	}
	if (board[4] == playerMark) {				//This checks the rightmost column and the other diagonal
		if ((board[12] == playerMark) && (board[20] == playerMark)) {
			return true;
		}
		else if ((board[14] == playerMark) && (board[24] == playerMark)) {
			return true;
		}
	}
	if (board[10] == playerMark) {			//This checks the middle row
		if ((board[12] == playerMark) && (board[14] == playerMark)) {
			return true;
		}
	}
	if (board[20] == playerMark) {		//This checks the bottom row
		if ((board[22] == playerMark) && (board[24] == playerMark)) {
			return true;
		}
	}
	return false;			//If none of them were all X's or all O's, then it must be false
}
void displayBoard(char board[]) {		
	cout << endl;				//This puts out an endl to break up text
	for (int x = 0; x < arraySize; x++) {		//This outputs each element of the array
		cout << board[x];
		if (((x + 1) % 5) == 0) {				//If the array value + 1 is 5, then it's the end of a row, so put an endline to properly format it
			cout << endl;
		}
	}
	cout << endl;
}
void displayGameStats(int ties, int player1Score, int player2Score) {		//This outputs the number of ties, wins for player 1, and wins for player 2
	cout << "Number of games tied: " << ties << endl;
	cout << "Number of games player 1 won: " << player1Score << endl;
	cout << "Number of games player 2 won: " << player2Score << endl;
}
bool playAgainOrQuit() {			
	int option = 0;				//This option stores if the user wants to play again or not
	cout << "Options: " << endl << "1) Play Again" << endl << "2) Quit" << endl;		//This outputs the options, play again or quit, and the appropriate numbers for each selection
	cin >> option;		//store the selected choice
	if (option == 1) {		//If they pick 1, they want to play again, so return true so the while loop continues
		return true;
	}
	else {
		return false;		//Otherwise, they want to quit, so this breaks the while loop 
	}
}
bool isGameTied(char board[]) {			//These if statements check if every single possible choice is taken up by an X or an O
	if ((board[0] == 'X') || (board[0] == 'O')) {			//If they are, and the game has not been won, then it must be a tie. As such, it returns true for the variable
		if ((board[2] == 'X') || (board[2] == 'O')) {
			if ((board[4] == 'X') || (board[4] == 'O')) {
				if ((board[10] == 'X') || (board[10] == 'O')) {
					if ((board[12] == 'X') || (board[12] == 'O')) {
						if ((board[14] == 'X') || (board[14] == 'O')) {
							if ((board[20] == 'X') || (board[20] == 'O')) {
								if ((board[22] == 'X') || (board[22] == 'O')) {
									if ((board[24] == 'X') || (board[24] == 'O')) {
										return true;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	return false;		//If one of them isn't an X or O, then there is still possible moves and a possible winner, so the game is not tied, so return false
}		//Side note: I had this as a single if statement before using &&, but the program just wouldn't do anything, so this if statement of doom and despair was born
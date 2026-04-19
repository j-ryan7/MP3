/*
Jaden Ryan
4/19/2026

Program Description: Tic Tac D'Oh; A program that lets 2 users play Tic-Tac-Toe as many times as they wish, and keeps track of ties and wins for each player. 
*/
#include<iostream>
#include<string>
using namespace std;
const int arraySize = 25;

int getPlayerInput(string playerName);
bool isLegalMove(char board[], int location);
void placeMarkOnBoard(char board[], char playerMark, int location);
void clearBoard(char board[]);
bool hasThreeInRow(char board[], char playerMark);
void displayBoard(char board[]);
void displayGameStats(int ties, int player1Score, int player2Score);
bool playAgainOrQuit();
bool isGameTied(char board[]);


int main() {
	char gameBoard[arraySize] = { '7', '|', '8', '|', '9', '-', '-', '-', '-', '-', '4','|','5','|','6','-', '-', '-', '-', '-', '1','|','2','|','3' };
	string player1 = " ";
	string player2 = " ";
	char player1Mark = 'X';
	char player2Mark = 'O';
	int tiedGames = 0;
	int player1Wins = 0;
	int player2Wins = 0;
	int turnCounter = 0;
	bool moveLegal = false;
	int playerInput = 0;
	bool threeInRow = false;
	bool gameIsTie = false;
	bool gameIsWon = false;
	bool playAgain = true;
	cout << "Enter player 1's name: ";
	getline(cin, player1);
	cout << "Enter player 2's name: ";
	getline(cin, player2);
	displayBoard(gameBoard);
	while (playAgain == true) {
		while (turnCounter % 2 == 0) {
			gameIsWon = hasThreeInRow(gameBoard, player2Mark);
			if (gameIsWon == true) {
				player2Wins++;
				cout << player2 << " wins!" << endl;
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
			playerInput = getPlayerInput(player1);
			moveLegal = isLegalMove(gameBoard, playerInput);
			if (moveLegal == true) {
				placeMarkOnBoard(gameBoard, player1Mark, playerInput);
				displayBoard(gameBoard);
				turnCounter++;
			}
			else {
				cout << "Error: Not a legal move." << endl;
				continue;
			}
		}
		while (turnCounter % 2 == 1) {
			gameIsWon = hasThreeInRow(gameBoard, player1Mark);
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
			playerInput = getPlayerInput(player2);
			moveLegal = isLegalMove(gameBoard, playerInput);
			if (moveLegal == true) {
				placeMarkOnBoard(gameBoard, player2Mark, playerInput);
				displayBoard(gameBoard);
				turnCounter++;
			}
			else {
				cout << "Error: Not a legal move." << endl;
				continue;

			}
		}
	}


	return 0;
}

int getPlayerInput(string playerName) {
	int choice = 0;
	cout << playerName << ": Choose an open spot number to place your mark: ";
	cin >> choice;
	if (choice == 7) {
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
	if ((board[location] == 'X') || (board[location] == 'O') || (location > 24) || (location < 0)) {
		return false;
	}
	else {
		return true;
	}
}
void placeMarkOnBoard(char board[], char playerMark, int location) {
	board[location] = playerMark;
}
void clearBoard(char board[]) {
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
bool hasThreeInRow(char board[], char playerMark) {
	if (board[0] == playerMark) {
		if ((board[2] == playerMark) && (board[4] == playerMark)) {
			return true;
		}
		else if ((board[10] == playerMark) && (board[20] == playerMark)) {
			return true;
		}
		else if ((board[12] == playerMark) && (board[24] == playerMark)) {
			return true;
		}
	}
	if (board[2] == playerMark) {
		if ((board[12] == playerMark) && (board[22] == playerMark)) {
			return true;
		}
	}
	if (board[4] == playerMark) {
		if ((board[12] == playerMark) && (board[20] == playerMark)) {
			return true;
		}
		else if ((board[14] == playerMark) && (board[24] == playerMark)) {
			return true;
		}
	}
	if (board[10] == playerMark) {
		if ((board[12] == playerMark) && (board[14] == playerMark)) {
			return true;
		}
	}
	if (board[20] == playerMark) {
		if ((board[22] == playerMark) && (board[24] == playerMark)) {
			return true;
		}
	}
	return false;
}
void displayBoard(char board[]) {
	cout << endl;
	for (int x = 0; x < arraySize; x++) {
		cout << board[x];
		if (((x + 1) % 5) == 0) {
			cout << endl;
		}
	}
	cout << endl;
}
void displayGameStats(int ties, int player1Score, int player2Score) {
	cout << "Number of games tied: " << ties << endl;
	cout << "Number of games player 1 won: " << player1Score << endl;
	cout << "Number of games player 2 won: " << player2Score << endl;
}
bool playAgainOrQuit() {
	int option = 0;
	cout << "Options: " << endl << "1) Play Again" << endl << "2) Quit" << endl;
	cin >> option;
	if (option == 1) {
		return true;
	}
	else {
		return false;
	}
}
bool isGameTied(char board[]) {
	if ((board[0] == 'X') || (board[0] == 'O')) {
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
	return false;
}
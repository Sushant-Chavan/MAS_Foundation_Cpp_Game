/*
 * main.cpp
 *
 *  Created on: Mar 28, 2018
 *      Author: suvich15
 */


#include <iostream>
#include "Board.h"

using namespace std;

int main()
{
	char difficultMode;
	cout << "Activate Difficult Mode? (Y/N) : ";
	cin >> difficultMode;

	Board* board = new Board();
	board->setIsDiffcultMode(difficultMode == 'y' || difficultMode == 'Y');
	board->startGame();

	delete board;
	board = NULL;

	return 0;
}

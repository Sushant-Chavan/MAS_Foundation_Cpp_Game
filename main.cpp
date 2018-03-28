/*
 * Assignment2.cpp
 *
 *  Created on: Mar 28, 2018
 *      Author: suvich15
 */


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Board.h"

using namespace std;

const int MAX_PEOPLE = 5;

int getHighestInArray(int* array, unsigned int size)
{
	int highestIndex = 0;
	int maxSize = 0;
	for(unsigned int i = 0; i < size; i++)
	{
		if (maxSize < array[i])
		{
			maxSize = array[i];
			highestIndex = i;
		}
	}

	return highestIndex;
}

int getLeastInArray(int* array, unsigned int size)
{
	int leastInArray = 0;
	int minSize = 0xFF;
	for(unsigned int i = 0; i < size; i++)
	{
		if (minSize > array[i])
		{
			minSize = array[i];
			leastInArray = i;
		}
	}

	return leastInArray;
}

void pizzaBot()
{
	int numOfPizza[MAX_PEOPLE];

	int entriesCount = 0;
	while(entriesCount < MAX_PEOPLE)
	{
		cout << "Enter number of slices eaten by Person " << entriesCount+1 << " : ";
		cin >> numOfPizza[entriesCount];

		entriesCount++;
	}

	cout << "Person " << getHighestInArray(numOfPizza, MAX_PEOPLE)+1 << " ate the most pizza's" << endl;
	cout << "Person " << getLeastInArray(numOfPizza, MAX_PEOPLE)+1 << " ate the least pizza's" << endl;
}

void guessBot()
{
	srand(time(0));
	int randomNum = rand()%100;

	//cout << randomNum;
	unsigned int numOfAttempts = 1;

	int input = -1;
	cout << "Guess a number between 0 - 100: ";
	while(input != randomNum)
	{
		cin >> input;

		if (input >=0 && input <=100)
		{
			 if(input < randomNum)
			 {
				 cout << "Guess higher: ";
				 numOfAttempts++;
			 }
			 else if (input > randomNum)
			 {
				 cout << "Guess lower: ";
				 numOfAttempts++;
			 }
		}
		else
		{
			cout << "Enter values between 0 - 100: ";
		}
	}

	cout << "Congrats to guessed right! It took you " << numOfAttempts << " attempts to guess." << endl;

}

int main()
{
	//pizzaBot();
	//guessBot();

	char difficultMode;
	cout << "Activate Difficult Mode? (Y/N) : ";
	cin >> difficultMode;

	Board* board = new Board();
	board->setIsDiffcultMode(difficultMode == 'y' || difficultMode == 'Y');
	board->startGame();

	return 0;
}

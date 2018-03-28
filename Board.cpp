/*
 * Game.cpp
 *
 *  Created on: Mar 28, 2018
 *      Author: suvich15
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Board.h"

using namespace std;

const char PLAYER_SYMBOL = 'P';
const char TRAP_SYMBOL = 'T';
const char TREASURE_SYMBOL = 'X';
const char EMPTY_PLACE_SYMBOL = '-';


Board::Board()
: _treasureInitialized(false)
, _playerAlive(true)
, _treasureFound(false)
, _validBoardSetup(false)
, _isDifficultMode(false)
{
	createBoard();
}

void Board::createBoard()
{
	_player = new Player(0,0);
	setupPositionForTreasure();
	createTraps();
	validityCheck();
}

Board::~Board()
{
}

void Board::validityCheck()
{
	bool isValid = _player->getPosition() != _treasure;

	if(isValid)
	{
		for(unsigned int i = 0; i < _traps.size() && isValid; i++)
		{
			std::pair<int, int> currTrapPos = _traps[i]->getPosition();
			isValid = currTrapPos != _player->getPosition();
			if (isValid)
			{
				isValid = currTrapPos != _treasure;
				if(isValid)
				{
					for(unsigned int j = i+1; j < _traps.size() && isValid; j++)
					{
						if (_traps[j]->getPosition() == currTrapPos)
						{
							isValid = false;
							cout << "Invalid board! Two traps are at same position!" << endl;
						}
					}
				}
				else
				{
					cout << "Invalid board! A trap is at a position of the treasure" << endl;
				}
			}
			else
			{
				cout << "Invalid board! A trap is at a position of the player" << endl;
			}
		}
	}
	else
	{
		cout << "Invalid board! Player and treasure at same position!" << endl;
	}

	_validBoardSetup = isValid;
}

void Board::startGame()
{
	char userInput;

	while(_playerAlive && !_treasureFound)
	{
		printBoard();
		cin >> userInput;

		if(!isValidInput(userInput))
			continue;

		movePlayer(userInput);

		if(_isDifficultMode)
		{
			updateTraps();
		}

		_playerAlive = isPlayerAlive();
		_treasureFound = isTreasureFound();
	}

	printGameStatus();
}

void Board::movePlayer(char userInput)
{
	switch(userInput)
	{
	case 'a':
	case 'A':
		_player->moveLeft();
		break;
	case 'd':
	case 'D':
		_player->moveRight();
		break;
	case 'w':
	case 'W':
		_player->moveTop();
		break;
	case 's':
	case 'S':
		_player->moveBottom();
		break;
	}
}

void Board::updateTraps()
{
	if(!_traps.empty())
	{
#ifdef DEBUGGING_ACTIVE
		cout << "Before Trap update" << endl;
		for(unsigned int i = 0; i < _traps.size(); i++)
		{
			std::pair<int, int> pos = _traps[i]->getPosition();
			cout << "Position " << i << " : " << pos.first << " " << pos.second << endl;
		}
#endif
		std::vector<std::vector<Trap*>::iterator> removeList;
		for(std::vector<Trap*>::iterator itr = _traps.begin(); itr != _traps.end(); itr++)
		{
			(*itr)->updatePosition(_treasure.first, _treasure.second);
			if(!isPositionWithinBounds((*itr)->getPosition()))
			{
				removeList.push_back(itr);
			}
		}

#ifdef DEBUGGING_ACTIVE
		cout << "After Trap update" << endl;
		for(unsigned int i = 0; i < _traps.size(); i++)
		{
			std::pair<int, int> pos = _traps[i]->getPosition();
			cout << "Position " << i << " : " << pos.first << " " << pos.second << endl;
		}
#endif

		if(!removeList.empty())
		{
			for(unsigned int i = 0; i < removeList.size(); i++)
			{
				_traps.erase(removeList[i]);
			}
		}
	}
}

bool Board::isPlayerAlive()
{
	bool isPlayerAlive = isPositionWithinBounds(_player->getPosition());

	if(isPlayerAlive && !_traps.empty())
	{
		for(unsigned int i = 0; i < _traps.size(); i++)
		{
			if(_traps[i]->getPosition() == _player->getPosition())
			{
				isPlayerAlive = false;
				break;
			}
		}
	}

	return isPlayerAlive;

}

bool Board::isPositionWithinBounds(std::pair<int, int> position)
{
	int x = position.first;
	int y = position.second;

	return (x >= 0 && x < MAX_WIDTH_OF_BOARD &&
			y >= 0 && y < MAX_HEIGHT_OF_BOARD);
}

bool Board::isTreasureFound()
{
	return _treasure == _player->getPosition();;
}

char Board::getObjectCharacter(unsigned int posX, unsigned int posY)
{
	char returnChar = EMPTY_PLACE_SYMBOL;

	std::pair<int, int> inputPosition = std::make_pair(posX, posY);

	if(_player->getPosition() == inputPosition)
		returnChar = PLAYER_SYMBOL;
	else if (_treasure == inputPosition)
		returnChar = TREASURE_SYMBOL;
	else
	{
		for(unsigned int i = 0; i < _traps.size(); i++)
		{
			if(_traps[i]->getPosition() == inputPosition)
			{
				returnChar = TRAP_SYMBOL;
				break;
			}
		}
	}

	return returnChar;
}

void Board::printBoard()
{
	for(unsigned int row = 0; row < MAX_HEIGHT_OF_BOARD; row++)
	{
		for (unsigned int col = 0; col < MAX_WIDTH_OF_BOARD; col++)
		{
			cout << getObjectCharacter(row, col) << " ";
		}

		cout << endl;
	}
}

void Board::printGameStatus()
{
	if(_treasureFound)
		cout << "!!! WELL DONE. TREASURE FOUND !!!" << endl;
	else if(!_playerAlive)
		cout << "!!! PLAYER DIED !!!" << endl;
	else
		cout << "GAME ASSERTED!!!!!" << endl;
}

bool Board::isValidInput(char input)
{
	bool isValid = false;
	char validInputs[8] = {'a', 'A', 's', 'S', 'd', 'D', 'w', 'W'};

	for(int i = 0 ; i < 8; i++)
	{
		if(input == validInputs[i])
		{
			isValid = true;
			break;
		}
	}

	return isValid;
}

void Board::setupPositionForTreasure()
{
	_treasure = getValidInitialPosition();
	_treasureInitialized = true;
}

void Board::createTraps()
{
	for(unsigned int i = 0; i < MAX_NUM_OF_TRAPS; i++)
	{
		std::pair<int, int> validPos = getValidInitialPosition();
		_traps.push_back(new Trap(validPos.first, validPos.second, MAX_DISPLACEMENT_OF_TRAPS));
	}
}

std::pair<int, int> Board::getValidInitialPosition()
{
	std::pair<int,int> validPosition;

	do
	{
		srand(time(0));
		validPosition.first = rand() % MAX_WIDTH_OF_BOARD;

		srand(time(0));
		validPosition.second = rand() % MAX_HEIGHT_OF_BOARD;

	}while (!isEmptyLocation(validPosition.first, validPosition.second));

	return validPosition;

}

bool Board::isEmptyLocation(int x, int y)
{
	bool isEmpty = true;
	std::pair<int, int> input = std::make_pair(x,y);

	if (input == _player->getPosition() ||
	   (_treasureInitialized && _treasure == input))
	{
		isEmpty = false;
	}
	else if (!_traps.empty())
	{
		for(unsigned int i = 0; i < _traps.size(); i++)
		{
			if(_traps[i]->getPosition() == input)
			{
				isEmpty = false;
				break;
			}
		}
	}

	return isEmpty;
}

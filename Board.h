/*
 * Game.h
 *
 *  Created on: Mar 28, 2018
 *      Author: suvich15
 */

#ifndef BOARD_H_
#define BOARD_H_


#include <vector>
#include "GameDefines.h"
#include "Player.h"
#include "Trap.h"

class Board
{
public:
	Board();
	virtual ~Board();

	void startGame();

	void setIsDiffcultMode(bool isDifficult) { _isDifficultMode = isDifficult; }

protected:
	void createBoard();

	std::pair<int, int> getValidInitialPosition();
	bool isPositionWithinBounds(std::pair<int, int> position);

	void setupPositionForTreasure();
	void createTraps();

	bool isEmptyLocation(int x, int y);
	bool isValidInput(char input);

	void movePlayer(char userInput);
	void updateTraps();
	bool isPlayerAlive();
	bool isTreasureFound();

	char getObjectCharacter(unsigned int posX, unsigned int posY);

	void printBoard();
	void printGameStatus();

	void validityCheck();

	std::vector<Trap*> _traps;
	Player* _player;
	std::pair<int, int> _treasure;
	bool _treasureInitialized;

	bool _playerAlive;
	bool _treasureFound;

	bool _validBoardSetup;

	bool _isDifficultMode;
};


#endif /* BOARD_H_ */

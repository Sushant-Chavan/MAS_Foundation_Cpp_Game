/*
 * Trap.cpp
 *
 *  Created on: Mar 28, 2018
 *      Author: suvich15
 */



#include "Trap.h"

void Trap::updatePosition(int treasureX, int treasureY)
{
	int newPosX = _position.first;
	int newPosY = _position.second;

	// Find a position such that we do not overlap with the treasure
	do
	{
		newPosX = _position.first;
		newPosY = _position.second;
		calculateNewPos(newPosX, newPosY);
	}while(newPosX != treasureX && newPosY == treasureY);

	_position = std::make_pair(newPosX, newPosY);
}

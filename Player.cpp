/*
 * Player.cpp
 *
 *  Created on: Mar 28, 2018
 *      Author: suvich15
 */




#include "Player.h"

bool Player::playerWon()
{
	return _playerWon;
}

void Player::setPlayerWon(bool winStatus)
{
	_playerWon = winStatus;
}

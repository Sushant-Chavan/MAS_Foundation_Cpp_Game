/*
 * Player.h
 *
 *  Created on: Mar 28, 2018
 *      Author: suvich15
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "MovingObject.h"


class Player : public MovingObject
{
public:
	Player():MovingObject(), _playerWon(false) {}
	Player(int x, int y) : MovingObject(x,y, PLAYER), _playerWon(false){}

	bool playerWon();
	void setPlayerWon(bool winStatus = true);

protected:
	bool _playerWon;
};

#endif /* PLAYER_H_ */

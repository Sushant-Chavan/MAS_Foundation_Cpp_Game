/*
 * Trap.h
 *
 *  Created on: Mar 28, 2018
 *      Author: suvich15
 */

#ifndef TRAP_H_
#define TRAP_H_


#include "MovingObject.h"
#include "GameLogic.h"


class Trap : public MovingObject, public GameAI
{
public:
	Trap(): MovingObject(), GameAI(){}
	Trap(int x, int y, int maxDisplacement) : MovingObject(x,y, TRAP), GameAI(maxDisplacement) {}

	void updatePosition(int treasureX, int treasureY);
};


#endif /* TRAP_H_ */

/*
 * GameLogic.h
 *
 *  Created on: Mar 28, 2018
 *      Author: suvich15
 */

#ifndef GAMELOGIC_H_
#define GAMELOGIC_H_


class GameAI
{
public:
	GameAI(): _maxStepsToTake(1) {}
	GameAI(int maxSteps): _maxStepsToTake(maxSteps) {}
	~GameAI() {}

protected:
	void calculateNewPos(int& xPos, int& yPos);

	int _maxStepsToTake;

};


#endif /* GAMELOGIC_H_ */

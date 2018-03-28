/*
 * GameLogic.cpp
 *
 *  Created on: Mar 28, 2018
 *      Author: suvich15
 */



#include <cstdlib>
#include <ctime>
#include <math.h>
#include "GameLogic.h"

void GameAI::calculateNewPos(int& xPos, int& yPos)
{
	srand(time(0));
	int randomXShift = rand() % (_maxStepsToTake + 1);
	randomXShift *= pow (-1, randomXShift+1);

	srand(time(0));
	int randomYShift = rand() % (_maxStepsToTake + 1);
	randomYShift *= pow (-1, randomYShift+1);

	xPos += randomXShift;
	yPos += randomYShift;
}

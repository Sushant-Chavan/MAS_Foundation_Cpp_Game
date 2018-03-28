/*
 * MovingObject.cpp
 *
 *  Created on: Mar 28, 2018
 *      Author: suvich15
 */




#include "MovingObject.h"

MovingObject::MovingObject()
: _type(INVALID)
{
 _position = std::make_pair(0,0);
}

MovingObject::MovingObject(int x, int y, OBJECT_TYPE type)
: _type(type)
{
 _position = std::make_pair(x,y);
}

MovingObject::~MovingObject()
{
#ifdef DEBUGGING_ACTIVE
	cout << "Object of type " << _type << " deleted!" << endl;
#endif
}

void MovingObject::moveRight(int numOfSpaces)
{
	_position.second += numOfSpaces;
}

void MovingObject::moveLeft(int numOfSpaces)
{
	_position.second -= numOfSpaces;
}
void MovingObject::moveTop(int numOfSpaces)
{
	_position.first -= numOfSpaces;
}
void MovingObject::moveBottom(int numOfSpaces)
{
	_position.first += numOfSpaces;
}

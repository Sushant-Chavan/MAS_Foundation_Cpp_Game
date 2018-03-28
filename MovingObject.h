/*
 * MovingObject.h
 *
 *  Created on: Mar 28, 2018
 *      Author: suvich15
 */

#ifndef MOVINGOBJECT_H_
#define MOVINGOBJECT_H_

#include <utility>

class MovingObject
{
public:
	enum OBJECT_TYPE
	{
		INVALID = 0,
		PLAYER,
		TRAP,
		COUNT
	};

	MovingObject();
	MovingObject(int x, int y, OBJECT_TYPE type);
	virtual ~MovingObject();

	std::pair<int, int> getPosition() { return _position; }
	void setPosition(int x, int y) { _position.first = x; _position.second = y; }

	OBJECT_TYPE getType() { return _type; }
	void setType(OBJECT_TYPE type) { _type = type; }

	virtual void moveRight(int numOfSpaces = 1);
	virtual void moveLeft(int numOfSpaces = 1);
	virtual void moveTop(int numOfSpaces = 1);
	virtual void moveBottom(int numOfSpaces = 1);

protected:
		std::pair<int, int> _position;
		OBJECT_TYPE _type;
};



#endif /* MOVINGOBJECT_H_ */

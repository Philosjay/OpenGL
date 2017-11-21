#ifndef OBJECT_H_
#define OBJECT_H_

class Object
{
public:
	Object();

	void setPos(int x, int y);
	int getPos_X();
	int getPos_Y();

protected:
	int		posX, posY;

};



#endif // !OBJECT_H_
#pragma once

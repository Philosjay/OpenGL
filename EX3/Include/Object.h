#ifndef OBJECT_H_
#define OBJECT_H_

class Object
{
public:
	Object();

	void setPos(int x, int y);

protected:
	int		posX, posY;

};

Object::Object()
{
	posX = 0, posY = 0;
}

void Object::setPos(int x, int y) {
	posX = x;
	posY = y;
}



#endif // !OBJECT_H_
#pragma once

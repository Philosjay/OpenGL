#include "../Include/Object.h"


Object::Object()
{
	posX = 0, posY = 0;
}

void Object::setPos(int x, int y) {
	posX = x;
	posY = y;
}

int Object::getPos_X()
{
	return posX;
}
int Object::getPos_Y()
{
	return posY;
}

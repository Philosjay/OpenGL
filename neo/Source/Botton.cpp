#include "../Include/Botton.h"


Botton::Botton() :
	Widget(),
	isActive(false)
{
}
void Botton::setActive(bool isActive)
{
	this->isActive = isActive;
	if (isActive) {
		mLayers[Layer::Buttom]->setColor(0.5, 0.5, 0.5);
	}
	else {
		mLayers[Layer::Buttom]->setColor(0.8, 0.8, 0.8);
	}

}
bool Botton::isWidgetActive(int x, int y)
{
	int length = endPosX > startPosX ? endPosX - startPosX : startPosX - endPosX;
	int	height = endPosY > startPosY ? endPosY - startPosY : startPosY - endPosY;

	if ((x >= startPosX && x <= startPosX + length) && (y >= startPosY - height &&y <= startPosY)) {
		return true;
	}
	else {
		return false;
	}
	return isActive;
}
void Botton::setId(int i)
{
	id = i;
}

bool Botton::isGrabbed(int x, int y)
{
	

	if (mLayers[Layer::Buttom]->isGrabbed(x, y)) {
			return true;

	}
	return false;
}

int Botton::getId()
{
	return id;
}

float Botton::getValue(int index)
{
	return value[index];
}

void Botton::setValue(float value, int index)
{
	this->value[index] = value;
}

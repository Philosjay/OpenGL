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
		mLayers[Layer::Buttom]->setColor(Color::Grey2);
	}
	else {
		mLayers[Layer::Buttom]->setColor(Color::Grey);
	}

}
bool Botton::isWidgetActive(int x, int y)
{
	if ((x >= originPosX && x <= originPosX + length) && (y >= originPosY - height &&y <= originPosY)) {
		return true;
	}
	else {
		return false;
	}
	return isActive;
}
void Botton::setType(int i)
{
	bottonType = i;
}

bool Botton::isGrabbed(int x, int y)
{
	

	if (mLayers[Layer::Buttom]->isGrabbed(x, y)) {
			return true;

	}
	return false;
}

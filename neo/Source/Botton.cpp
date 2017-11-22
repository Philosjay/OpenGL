#include "../Include/Botton.h"
#include "../Include/settingList.h"


Botton::Botton() :
	Widget(),
	isActive(false)
{
}
void Botton::setActive(bool isActive)
{
	this->isActive = isActive;
	if (isActive) {
		mLayers[Layer::Buttom]->setColor(ColorSet::Grey2);
	}
	else {
		mLayers[Layer::Buttom]->setColor(ColorSet::Grey);
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

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
	if ((x >= posX && x <= posX + sizeX) && (y >= posY&&y <= posY + sizeY)) {
		return true;
	}
	else {
		return false;
	}
	return isActive;
}
void Botton::setType(Menu i)
{
	bottonType = i;
}
void Botton::setType(ToolSet i)
{
	bottonType = i;
}
void Botton::setType(LineWidthSet i)
{
	bottonType = i;
}
void Botton::setType(Color i)
{
	bottonType = i;
}
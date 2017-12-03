#include "../Include/Factory_LineWidth3.h"
#include "../Include/Botton.h"

Factory_LineWidth3::Factory_LineWidth3()
{
}

Botton * Factory_LineWidth3::generateBotton()
{
	Botton* tmp = new Botton;
	tmp->setSize(120, 30);
	tmp->setPos(1170, 340);
	tmp->setValue(3, 0);
	tmp->loadTexture("Textures/line3.bmp");
	return tmp;
}

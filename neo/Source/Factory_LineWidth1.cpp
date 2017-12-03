#include "../Include/Factory_LineWidth1.h"
#include "../Include/Botton.h"

Factory_LineWidth1::Factory_LineWidth1()
{
}

Botton * Factory_LineWidth1::generateBotton()
{
	Botton* tmp = new Botton;
	tmp->setSize(120, 30);
	tmp->setPos(1170, 400);
	tmp->setValue(1, 0);
	tmp->loadTexture("Textures/line1.bmp");
	return tmp;
}

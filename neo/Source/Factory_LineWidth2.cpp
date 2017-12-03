#include "../Include/Factory_LineWidth2.h"
#include "../Include/Botton.h"

Factory_LineWidth2::Factory_LineWidth2()
{
}

Botton * Factory_LineWidth2::generateBotton()
{
	Botton* tmp = new Botton;
	tmp->setSize(120, 30);
	tmp->setPos(1170, 370);
	tmp->setValue(2, 0);
	tmp->loadTexture("Textures/line2.bmp");
	return tmp;
}

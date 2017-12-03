#include "../Include/Factory_LineWidth4.h"
#include "../Include/Botton.h"

Factory_LineWidth4::Factory_LineWidth4()
{
}

Botton * Factory_LineWidth4::generateBotton()
{
	Botton* tmp = new Botton;
	tmp = new Botton;
	tmp->setSize(120, 30);
	tmp->setPos(1170, 310);
	tmp->setValue(4, 0);
	tmp->loadTexture("Textures/line4.bmp");
	return tmp;
}

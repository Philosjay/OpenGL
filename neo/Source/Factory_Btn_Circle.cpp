#include "../Include/Factory_Btn_Circle.h"
#include "../Include/Botton.h"

Botton * Factory_Btn_Circle::generate()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1170, 540);
	tmp->loadTexture("Textures/circle.bmp");
	tmp->setKey(8);
	return tmp;
}

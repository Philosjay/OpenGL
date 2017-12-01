#include "../Include/Factory_Btn_Circlef.h"
#include "../Include/Botton.h"

Botton * Factory_Btn_Circlef::generate()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1230, 540);
	tmp->loadTexture("Textures/circle2.bmp");
	tmp->setKey(1);
	return tmp;
}

#include "../Include/Factory_Btn_Curve.h"
#include "../Include/Botton.h"

Botton * Factory_Btn_Curve::generate()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1230, 600);
	tmp->loadTexture("Textures/Curve.bmp");
	tmp->setKey(2);
	return tmp;
}

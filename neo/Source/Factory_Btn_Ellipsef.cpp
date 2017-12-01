#include "../Include/Factory_Btn_Ellipsef.h"
#include "../Include/Botton.h"

Botton * Factory_Btn_Ellipsef::generate()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1230, 510);
	tmp->loadTexture("Textures/Ellipse2.bmp");
	tmp->setKey(5);
	return tmp;
}

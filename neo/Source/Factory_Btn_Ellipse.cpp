#include "../Include/Factory_Btn_Ellipse.h"
#include "../Include/Botton.h"

Botton * Factory_Btn_Ellipse::generate()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1170, 510);
	tmp->loadTexture("Textures/Ellipse.bmp");
	tmp->setKey(4);
	return tmp;
}

#include "../Include/Factory_Btn_Triangle.h"
#include "../Include/Botton.h"

Botton * Factory_Btn_Triangle::generate()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1170, 570);
	tmp->loadTexture("Textures/triangle.bmp");
	tmp->setKey(12);
	return tmp;
}

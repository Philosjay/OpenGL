#include "../Include/Factory_Btn_Polygon.h"
#include "../Include/Botton.h"

Botton * Factory_Btn_Polygon::generate()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1230, 450);
	//	tmp->loadTexture("Textures/rectangle2.bmp");
	tmp->setKey(9);
	return tmp;
}
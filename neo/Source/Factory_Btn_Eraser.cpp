#include "../Include/Factory_Btn_Eraser.h"
#include "../Include/Botton.h"

Botton * Factory_Btn_Eraser::generate()
{
	Botton* tmp	= new Botton;
	tmp->setSize(100, 80);
	tmp->setPos(1230, 730);
	tmp->loadTexture("Textures/Eraser.bmp");
	tmp->setKey(6);
	return tmp;
}

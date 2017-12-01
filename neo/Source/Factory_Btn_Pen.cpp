#include "../Include/Factory_Btn_Pen.h"
#include "../Include/Botton.h"

Botton * Factory_Btn_Pen::generate()
{
	Botton* tmp = new Botton;
	tmp->setSize(100, 80);
	tmp->setPos(930, 730);
	tmp->loadTexture("Textures/Pencil.bmp");
	tmp->setKey(0);
	return tmp;
}

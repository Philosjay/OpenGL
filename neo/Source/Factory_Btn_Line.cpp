#include "../Include/Factory_Btn_Line.h"
#include "../Include/Botton.h"

Botton * Factory_Btn_Line::generate()
{
	Botton* tmp = new Botton;
	tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1170, 600);
	tmp->loadTexture("Textures/Line.bmp");
	tmp->setKey(7);
	return tmp;
}

#include "../Include/Factory_Btn_Zoom.h"
#include "../Include/Botton.h"

Botton * Factory_Btn_Zoom::generate()
{
	Botton*	tmp = new Botton;
	tmp->setSize(100, 80);
	tmp->setPos(1030, 730);
	tmp->loadTexture("Textures/Zoom.bmp");
	tmp->setKey(14);
	return tmp;
}

#include "../Include/Factory_Btn_Rectf.h"
#include "../Include/Botton.h"

Botton * Factory_Btn_Rectf::generate()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1230, 480);
	tmp->loadTexture("Textures/rectangle2.bmp");
	tmp->setKey(11);
	return tmp;
}
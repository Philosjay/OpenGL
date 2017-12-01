#include "../Include/Factory_Btn_Rect.h"
#include "../Include/Botton.h"

Botton * Factory_Btn_Rect::generate()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1170, 480);
	tmp->loadTexture("Textures/rectangle.bmp");
	tmp->setKey(10);
	return tmp;
}

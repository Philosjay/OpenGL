#include "../Include/Factory_Btn_Trianglef.h"
#include "../Include/Botton.h"

Botton * Factory_Btn_Trianglef::generate()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1230, 570);
	tmp->loadTexture("Textures/triangle2.bmp");
	tmp->setKey(13);
	return tmp;
}

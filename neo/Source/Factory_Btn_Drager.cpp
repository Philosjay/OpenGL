#include "../Include/Factory_Btn_Drager.h"
#include "../Include/Botton.h"

Botton * Factory_Btn_Drager::generate()
{
	Botton* tmp = new Botton;
	tmp->setSize(100, 80);
	tmp->setPos(1130, 730);
	tmp->loadTexture("Textures/PaintBucket.bmp");
	tmp->setKey(3);
	return tmp;
}

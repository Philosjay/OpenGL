#include "../Include/Factory_Drager.h"
#include "../Include/Botton.h"

Factory_Drager::Factory_Drager()
{
	id = 5;
}

Botton * Factory_Drager::generateBotton()
{
	Botton* tmp = new Botton;
	tmp->setSize(100, 80);
	tmp->setPos(1130, 730);
	tmp->loadTexture("Textures/PaintBucket.bmp");
	tmp->setValue(1, 0);
	tmp->setId(id);
	return tmp;
}

Graph * Factory_Drager::generateGraph()
{
	return nullptr;
}

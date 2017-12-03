#include "../Include/Factory_Zoom.h"
#include "../Include/Botton.h"

Factory_Zoom::Factory_Zoom()
{
	id = 14;
}

Botton * Factory_Zoom::generateBotton()
{
	Botton*	tmp = new Botton;
	tmp->setSize(100, 80);
	tmp->setPos(1030, 730);
	tmp->loadTexture("Textures/Zoom.bmp");
	tmp->setValue(0, 0);
	tmp->setId(id);
	return tmp;
}

Graph * Factory_Zoom::generateGraph()
{
	return nullptr;
}

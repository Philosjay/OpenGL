#include "../Include/Factory_Eraser.h"
#include "../Include/Botton.h"

Factory_Eraser::Factory_Eraser()
{
	id = 6;
}

Botton * Factory_Eraser::generateBotton()
{
	Botton* tmp	= new Botton;
	tmp->setSize(100, 80);
	tmp->setPos(1230, 730);
	tmp->loadTexture("Textures/Eraser.bmp");
	tmp->setId(id);
	tmp->setValue(0, 0);
	return tmp;
}

Graph * Factory_Eraser::generateGraph()
{
	return nullptr;
}

Painter * Factory_Eraser::generatePainter()
{
	return nullptr;
}

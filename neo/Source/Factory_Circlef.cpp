#include "../Include/Factory_Circlef.h"
#include "../Include/Botton.h"
#include "../Include/Circle.h"
#include "../Include/PainterForCircle.h"
#include "../Include/StorerForCircle.h"

Factory_Circlef::Factory_Circlef()
{
	id = 1;
}

Botton * Factory_Circlef::generateBotton()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1230, 540);
	tmp->loadTexture("Textures/circle2.bmp");
	tmp->setValue(0, 0);
	tmp->setId(id);
	return tmp;
}

Graph * Factory_Circlef::generateGraph()
{
	Graph* tmp = new Circle;
	tmp->setFill(true);
	tmp->setId(id);
	return tmp;
}

Painter * Factory_Circlef::generatePainter()
{
	Painter* tmp = new PainterForCircle;
	return tmp;
}

Storer * Factory_Circlef::generateStorer()
{
	Storer* tmp = new StorerForCircle;
	return tmp;
}


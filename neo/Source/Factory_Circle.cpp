#include "../Include/Factory_Circle.h"
#include "../Include/Botton.h"
#include "../Include/Circle.h"
#include "../Include/PainterForCircle.h"
#include "../Include/StorerForCircle.h"

Factory_Circle::Factory_Circle()
{
	id = 0;
}


Botton * Factory_Circle::generateBotton()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1170, 540);
	tmp->loadTexture("Textures/circle.bmp");
	tmp->setValue(0,0);
	tmp->setId(id);
	return tmp;
}

Graph * Factory_Circle::generateGraph()
{
	Graph* tmp = new Circle;
	tmp->setId(id);
	return tmp;
}

Painter * Factory_Circle::generatePainter()
{
	Painter* tmp = new PainterForCircle;
	return tmp;
}

Storer * Factory_Circle::generateStorer()
{
	Storer* tmp = new StorerForCircle;
	return tmp;
}

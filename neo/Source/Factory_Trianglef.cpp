#include "../Include/Factory_Trianglef.h"
#include "../Include/Botton.h"
#include "../Include/Triangle.h"
#include "../Include/PainterForTriangle.h"
#include "../Include/StorerForTriangle.h"

Factory_Trianglef::Factory_Trianglef()
{
	id = 13;
}

Botton * Factory_Trianglef::generateBotton()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1230, 570);
	tmp->loadTexture("Textures/triangle2.bmp");
	tmp->setValue(0, 0);
	tmp->setId(id);
	return tmp;
}

Graph * Factory_Trianglef::generateGraph()
{
	Graph* tmp = new Triangle;
	tmp->setFill(true);
	tmp->setId(id);
	return tmp;
}

Painter * Factory_Trianglef::generatePainter()
{
	Painter* tmp = new PainterForTriangle;
	return tmp;
}

Storer * Factory_Trianglef::generateStorer()
{
	Storer* tmp = new StorerForTriangle;
	return tmp;
}

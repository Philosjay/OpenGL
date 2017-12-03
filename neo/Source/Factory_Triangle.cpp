#include "../Include/Factory_Triangle.h"
#include "../Include/Botton.h"
#include "../Include/Triangle.h"
#include "../Include/PainterForTriangle.h"
#include "../Include/StorerForTriangle.h"

Factory_Triangle::Factory_Triangle()
{
	id = 12;
}

Botton * Factory_Triangle::generateBotton()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1170, 570);
	tmp->loadTexture("Textures/triangle.bmp");
	tmp->setValue(0, 0);
	tmp->setId(id);
	return tmp;
}

Graph * Factory_Triangle::generateGraph()
{
	Graph* tmp = new Triangle;
	tmp->setId(id);
	return tmp;
}

Painter * Factory_Triangle::generatePainter()
{
	Painter* tmp = new PainterForTriangle;
	return tmp;
}

Storer * Factory_Triangle::generateStorer()
{
	Storer* tmp = new StorerForTriangle;
	return tmp;
}

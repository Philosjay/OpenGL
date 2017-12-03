#include "../Include/Factory_Polygon.h"
#include "../Include/Botton.h"
#include "../Include/Polygon.h"
#include "../Include/PainterForPolygon.h"
#include "../Include/StorerForPolygon.h"

Factory_Polygon::Factory_Polygon()
{
	id = 9;
}

Botton * Factory_Polygon::generateBotton()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1230, 450);
	//	tmp->loadTexture("Textures/rectangle2.bmp");
	tmp->setValue(0, 0);
	tmp->setId(id);
	return tmp;
}

Graph * Factory_Polygon::generateGraph()
{
	Graph* tmp = new Polygon;
	tmp->setId(id);
	return tmp;
}

Painter * Factory_Polygon::generatePainter()
{
	Painter* tmp = new PainterForPolygon;
	return tmp;
}

Storer * Factory_Polygon::generateStorer()
{
	Storer* tmp = new StorerForPolygon;
	return tmp;
}

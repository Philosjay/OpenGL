#include "../Include/Factory_Line.h"
#include "../Include/Botton.h"
#include "../Include/Line.h"
#include "../Include/PainterForLine.h"
#include "../Include/StorerForLine.h"

Factory_Line::Factory_Line()
{
	id = 7;
}

Botton * Factory_Line::generateBotton()
{
	Botton* tmp = new Botton;
	tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1170, 600);
	tmp->loadTexture("Textures/Line.bmp");
	tmp->setId(id);
	tmp->setValue(0, 0);
	return tmp;
}

Graph * Factory_Line::generateGraph()
{
	Graph* tmp = new Line;
	tmp->setId(id);
	return tmp;
}

Painter * Factory_Line::generatePainter()
{
	Painter* tmp = new PainterForLine;
	return tmp;
}

Storer * Factory_Line::generateStorer()
{
	Storer* tmp = new StorerForLine;
	return tmp;
}

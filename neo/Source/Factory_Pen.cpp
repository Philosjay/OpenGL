#include "../Include/Factory_Pen.h"
#include "../Include/Botton.h"
#include "../Include/Pen.h"
#include "../Include/PainterForPen.h"

Factory_Pen::Factory_Pen()
{
	id = 8;
}

Botton * Factory_Pen::generateBotton()
{
	Botton* tmp = new Botton;
	tmp->setSize(100, 80);
	tmp->setPos(930, 730);
	tmp->loadTexture("Textures/Pencil.bmp");
	tmp->setValue(0, 0);
	tmp->setId(id);
	return tmp;
}

Graph * Factory_Pen::generateGraph()
{
	Graph* tmp = new Pen;
	tmp->setId(id);
	return tmp;
}

Painter * Factory_Pen::generatePainter()
{
	Painter* tmp = new PainterForPen;
	tmp->setId(id);
	return tmp;
}

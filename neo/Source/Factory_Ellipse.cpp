#include "../Include/Factory_Ellipse.h"
#include "../Include/Botton.h"
#include "../Include/Ellipse.h"
#include "../Include/PainterForEllipse.h"
#include "../Include/StorerForEllipse.h"

Factory_Ellipse::Factory_Ellipse()
{
	id = 3;
}

Botton * Factory_Ellipse::generateBotton()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1170, 510);
	tmp->loadTexture("Textures/Ellipse.bmp");
	tmp->setValue(0, 0);
	tmp->setId(id);
	return tmp;
}

Graph * Factory_Ellipse::generateGraph()
{
	Graph* tmp = new Ellipse_;
	tmp->setId(id);
	return tmp;
}

Painter * Factory_Ellipse::generatePainter()
{
	Painter* tmp = new PainterForEllipse;
	return tmp;
}

Storer * Factory_Ellipse::generateStorer()
{
	Storer* tmp = new StorerForEllipse;
	return tmp;
}

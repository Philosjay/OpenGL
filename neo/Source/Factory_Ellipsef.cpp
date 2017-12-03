#include "../Include/Factory_Ellipsef.h"
#include "../Include/Botton.h"
#include "../Include/Ellipse.h"
#include "../Include/PainterForEllipse.h"
#include "../Include/StorerForEllipse.h"

Factory_Ellipsef::Factory_Ellipsef()
{
	id = 4;
}

Botton * Factory_Ellipsef::generateBotton()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1230, 510);
	tmp->loadTexture("Textures/Ellipse2.bmp");
	tmp->setValue(0, 0);
	tmp->setId(id);
	return tmp;
}

Graph * Factory_Ellipsef::generateGraph()
{
	Graph* tmp = new Ellipse_;
	tmp->setFill(true);
	tmp->setId(id);
	return tmp;
}

Painter * Factory_Ellipsef::generatePainter()
{
	Painter* tmp = new PainterForEllipse;
	return tmp;
}

Storer * Factory_Ellipsef::generateStorer()
{
	Storer* tmp = new StorerForEllipse;
	return tmp;
}

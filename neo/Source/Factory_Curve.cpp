#include "../Include/Factory_Curve.h"
#include "../Include/Botton.h"
#include "../Include/Bezier.h"
#include "../Include/PainterForCurve.h"
#include "../Include/StorerForCurve.h"

Factory_Curve::Factory_Curve()
{
	id = 2;
}

Botton * Factory_Curve::generateBotton()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1230, 600);
	tmp->loadTexture("Textures/Curve.bmp");
	tmp->setValue(0, 0);
	tmp->setId(id);
	return tmp;
}

Graph * Factory_Curve::generateGraph()
{
	Graph* tmp = new Bezier;
	tmp->setId(id);
	return tmp;
}

Painter * Factory_Curve::generatePainter()
{
	Painter* tmp = new PainterForCurve;
	return tmp;
}

Storer * Factory_Curve::generateStorer()
{
	Storer* tmp = new StorerForCurve;
	return tmp;
}

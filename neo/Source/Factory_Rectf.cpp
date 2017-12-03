#include "../Include/Factory_Rectf.h"
#include "../Include/Botton.h"
#include "../Include/Rect.h"
#include "../Include/PainterForRect.h"
#include "../Include/StorerForRect.h"

Factory_Rectf::Factory_Rectf()
{
	id = 11;
}

Botton * Factory_Rectf::generateBotton()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1230, 480);
	tmp->loadTexture("Textures/rectangle2.bmp");
	tmp->setValue(0, 0);
	tmp->setId(id);
	return tmp;
}

Graph * Factory_Rectf::generateGraph()
{
	Graph* tmp = new Rect;
	tmp->setFill(true);
	tmp->setId(id);
	return tmp;
}

Painter * Factory_Rectf::generatePainter()
{
	Painter* tmp = new PainterForRect;
	return tmp;
}

Storer * Factory_Rectf::generateStorer()
{
	Storer* tmp = new StorerForRect;
	return tmp;
}

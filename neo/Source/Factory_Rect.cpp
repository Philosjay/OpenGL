#include "../Include/Factory_Rect.h"
#include "../Include/Botton.h"
#include "../Include/Rect.h"
#include "../Include/PainterForRect.h"
#include "../Include/StorerForRect.h"

Factory_Rect::Factory_Rect()
{
	id = 10;
}

Botton * Factory_Rect::generateBotton()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1170, 480);
	tmp->loadTexture("Textures/rectangle.bmp");
	tmp->setId(id);
	tmp->setValue(0, 0);
	return tmp;
}

Graph * Factory_Rect::generateGraph()
{
	Graph* tmp = new Rect;
	tmp->setId(id);

	return tmp;
}

Painter * Factory_Rect::generatePainter()
{
	Painter* tmp = new PainterForRect;
	return tmp;
}

Storer * Factory_Rect::generateStorer()
{
	Storer* tmp = new StorerForRect;
	return tmp;
}

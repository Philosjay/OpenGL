#include "../Include/Factory.h"

Factory::Factory()
{
}

Botton * Factory::generateBotton()
{
	return nullptr;
}

Graph * Factory::generateGraph()
{
	return nullptr;
}

Painter * Factory::generatePainter()
{
	return nullptr;
}

Storer * Factory::generateStorer()
{
	return nullptr;
}

int Factory::getId()
{
	return id;
}

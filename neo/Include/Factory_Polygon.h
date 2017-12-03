#ifndef Factory_POLYGON_H_
#define Factory_POLYGON_H_

#include "Factory.h"

class Factory_Polygon : public Factory {
public:
	Factory_Polygon();
	Botton*		generateBotton();
	Graph*		generateGraph();
	Painter*	generatePainter();
	Storer*		generateStorer();
};
#endif // !Factory_ERASER_H_
#pragma once
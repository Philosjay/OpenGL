#ifndef Factory_ELLIPSE_H_
#define Factory_ELLIPSE_H_

#include "Factory.h"

class Factory_Ellipse : public Factory {
public:
	Factory_Ellipse();
	Botton*		generateBotton();
	Graph*		generateGraph();
	Painter*	generatePainter();
	Storer*		generateStorer();
};

#endif // !Factory_ELLIPSE_H_
#pragma once

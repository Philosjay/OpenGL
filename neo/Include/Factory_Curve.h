#ifndef Factory_CURVE_H_
#define Factory_CURVE_H_

#include "Factory.h"

class Factory_Curve : public Factory {
public:
	Factory_Curve();
	Botton*		generateBotton();
	Graph*		generateGraph();
	Painter*	generatePainter();
	Storer*		generateStorer();
};
#endif // !Factory_ERASER_H_
#pragma once
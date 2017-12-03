#ifndef Factory_CIRCLE_H_
#define Factory_CIRCLE_H_

#include "Factory.h"

class Factory_Circle : public Factory {
public:
	Botton*		generateBotton();
	Graph*		generateGraph();
	Painter*	generatePainter();
	Storer*		generateStorer();
	Factory_Circle();
};
#endif // !Factory_ERASER_H_
#pragma once

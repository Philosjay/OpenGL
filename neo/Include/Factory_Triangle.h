#ifndef Factory_TRIANGLE_H_
#define Factory_TRIANGLE_H_

#include "Factory.h"

class Factory_Triangle : public Factory {
public:
	Factory_Triangle();
	Botton*		generateBotton();
	Graph*		generateGraph();
	Painter*	generatePainter();
	Storer*		generateStorer();
};
#endif // !Factory_ERASER_H_
#pragma once

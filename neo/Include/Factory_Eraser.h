#ifndef Factory_ERASER_H_
#define Factory_ERASER_H_

#include "Factory.h"

class Factory_Eraser : public Factory {
public:
	Factory_Eraser();
	Botton*		generateBotton();
	Graph*		generateGraph();
	Painter*	generatePainter();
};
#endif // !Factory_ERASER_H_
#pragma once

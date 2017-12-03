#ifndef Factory_RECT_H_
#define Factory_RECT_H_

#include "Factory.h"

class Factory_Rect : public Factory {
public:
	Factory_Rect();
	Botton*		generateBotton();
	Graph*		generateGraph();
	Painter*	generatePainter();
	Storer*		generateStorer();
};
#endif // !Factory_ERASER_H_
#pragma once

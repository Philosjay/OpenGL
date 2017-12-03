#ifndef Factory_TRIANGLEF_H_
#define Factory_TRIANGLEF_H_

#include "Factory.h"

class Factory_Trianglef : public Factory {
public:
	Factory_Trianglef();
	Botton*		generateBotton();
	Graph*		generateGraph();
	Painter*	generatePainter();
	Storer*		generateStorer();
};
#endif // !Factory_ERASER_H_
#pragma once

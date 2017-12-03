#ifndef Factory_CIRCLEF_H_
#define Factory_CIRCLEF_H_

#include "Factory.h"

class Factory_Circlef : public Factory {
public:
	Botton*		generateBotton();
	Graph*		generateGraph();
	Painter*	generatePainter();
	Storer*		generateStorer();
	Factory_Circlef();
};
#endif // !Factory_ERASER_H_
#pragma once

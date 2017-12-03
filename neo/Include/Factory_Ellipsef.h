#ifndef Factory_ELLIPSEF_H_
#define Factory_ELLIPSEF_H_

#include "Factory.h"

class Factory_Ellipsef : public Factory {
public:
	Factory_Ellipsef();
	Botton*		generateBotton();
	Graph*		generateGraph();
	Painter*	generatePainter();
	Storer*		generateStorer();
};

#endif // !Factory_ELLIPSE_H_
#pragma once

#ifndef Factory_PEN_H_
#define Factory_PEN_H_

#include "Factory.h"

class Factory_Pen : public Factory{
public:
	Factory_Pen();
	Botton*		generateBotton();
	Graph*		generateGraph();
	Painter*	generatePainter();
};

#endif // !Factory_PEN_H_
#pragma once

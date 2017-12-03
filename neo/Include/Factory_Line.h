#ifndef Factory_LINE_H_
#define Factory_LINE_H_

#include "Factory.h"

class Factory_Line : public Factory {
public:
	Factory_Line();
	Botton*		generateBotton();
	Graph*		generateGraph();
	Painter*	generatePainter();
	Storer*		generateStorer();
};

#endif // !Factory_LINE_H_
#pragma once

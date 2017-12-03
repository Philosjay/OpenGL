#ifndef Factory_RECTF_H_
#define Factory_RECTF_H_

#include "Factory.h"

class Factory_Rectf : public Factory {
public:
	Factory_Rectf();
	Botton*		generateBotton();
	Graph*		generateGraph();
	Painter*	generatePainter();
	Storer*		generateStorer();
};
#endif // !Factory_ERASER_H_
#pragma once#pragma once

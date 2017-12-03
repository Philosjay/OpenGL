#ifndef FACTPRY_BTN_DRAGER_H_
#define FACTPRY_BTN_DRAGER_H_

#include "Factory.h"

class Factory_Drager : public Factory {
public:
	Factory_Drager();

	Botton*		generateBotton();
	Graph*		generateGraph();
};

#endif // !FACTPRY_BTN_DRAGER_H_
#pragma once

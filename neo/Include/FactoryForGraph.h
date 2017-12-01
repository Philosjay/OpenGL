#ifndef FACTORYFORGRAPH_H_
#define FACTORYFORGRAPH_H_

#include "settingList.h"

class Graph;

class FactoryForGraph
{
public:
	FactoryForGraph();

	Graph*	generateGraph(int type);
private:

};


#endif // !FACTORYFORGRAPH_H_
#pragma once

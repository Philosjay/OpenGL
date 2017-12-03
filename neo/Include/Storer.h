#ifndef Storer_H_
#define Storer_H_

#include <fstream>
#include "../Include/Graph.h"

using namespace std;

class Graph;

class Storer {
public:
	virtual void	save(Graph* g,ofstream& f);
	virtual Graph*	load(int id, ifstream& f);
protected:

};

#endif // !Storer_H_
#pragma once

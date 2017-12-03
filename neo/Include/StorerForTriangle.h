#ifndef STORERFORTRIANGLE_H_
#define STORERFORTRIANGLE_H_


#include "Storer.h"

class StorerForTriangle : public Storer {
public:
	StorerForTriangle();
	void	save(Graph* g, ofstream& f);
	Graph*	load(int id, ifstream& f);
};

#endif // !StorerFORCIRCLE_H_
#pragma once


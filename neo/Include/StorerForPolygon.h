#ifndef STORERFORPOLYGON_H_
#define STORERFORPOLYGON_H_


#include "Storer.h"

class StorerForPolygon : public Storer {
public:
	void	save(Graph* g, ofstream& f);
	Graph*	load(int id, ifstream& f);
};

#endif // !StorerFORCIRCLE_H_
#pragma once

#ifndef STORERFORCURVE_H_
#define STORERFORCURVE_H_


#include "Storer.h"

class StorerForCurve : public Storer {
public:
	void	save(Graph* g, ofstream& f);
	Graph*	load(int id, ifstream& f);
};

#endif // !StorerFORCIRCLE_H_
#pragma once

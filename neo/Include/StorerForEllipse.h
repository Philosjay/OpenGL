#ifndef STORERFORELLIPSE_H_
#define STORERFORELLIPSE_H_

#include "Storer.h"

class StorerForEllipse : public Storer {
public:
	void	save(Graph* g, ofstream& f);
	Graph*	load(int id, ifstream& f);
};

#endif // !StorerFORCIRCLE_H_
#pragma once


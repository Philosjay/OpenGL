#ifndef STORERFORLINE_H_
#define STORERFORLINE_H_


#include "Storer.h"

class StorerForLine : public Storer {
public:
	void	save(Graph* g, ofstream& f);
	Graph*	load(int id, ifstream& f);
};

#endif // !StorerFORCIRCLE_H_
#pragma once

#ifndef STORERFORRECT_H_
#define STORERFORRECT_H_

#include "Storer.h"

class StorerForRect : public Storer {
public:
	StorerForRect();
	void	save(Graph* g, ofstream& f);
	Graph*	load(int id, ifstream& f);
};

#endif // !STORERFORRECT_H_
#pragma once

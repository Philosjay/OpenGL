#ifndef STORERFORCIRCLE_H_
#define STORERFORCIRCLE_H_


#include "Storer.h"

class StorerForCircle : public Storer{
public:
	StorerForCircle();
	void	save(Graph* g, ofstream& f);
	Graph*	load(int id,ifstream& f);
};

#endif // !StorerFORCIRCLE_H_
#pragma once

#ifndef CIRCLEF_H_
#define CIRCLEF_H_

#include "Graph.h"

class Circlef :public Graph
{
public:
	Circlef();
	bool	isGrabbed(int x, int y);
	void	draw();
private:
	float R;
};


#endif
#pragma once

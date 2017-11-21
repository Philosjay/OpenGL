#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Graph.h"

class Circle :public Graph
{
public:
	Circle();
	bool	isGrabbed(int x, int y);
	void	draw();
private:
	float R;
};




#endif // !CIRCLE_H_
#pragma once

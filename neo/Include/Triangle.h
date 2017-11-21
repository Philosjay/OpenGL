#ifndef TRIANGLE_H_
#define TRIANGLR_H_

#include "Graph.h"

class Triangle : public Graph
{
public:
	Triangle();

	void	draw();
	bool	isGrabbed(int x, int y);
private:
	float	points[3][2];
	
};



#endif // !TRIANGLE_H_
#pragma once

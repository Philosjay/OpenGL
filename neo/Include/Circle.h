#ifndef CIRCLE_H_
#define CIRCLE_H_

#include "Graph.h"

class Circle :public Graph
{
public:
	Circle();
	bool	isGrabbed(int x, int y);
	void	draw();
	void	setRadius(float r);
	void	moveTo(int x, int y);
	void	move(int x, int y);
	float	getRadius();
private:
	float R;
};




#endif // !CIRCLE_H_
#pragma once

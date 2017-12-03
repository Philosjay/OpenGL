#ifndef TRIANGLE_H_
#define TRIANGLR_H_

#include "Graph.h"

class Triangle : public Graph
{
public:
	Triangle();

	void	draw();
	bool	isGrabbed(int x, int y);
	void	setSize(float length, float height);
	void	moveTo(int x, int y);
	void	move(int x, int y);
	float	getWidth();
	float	getHeight();
private:
	float	points[3][2];
	float	width;
	float	height;
};



#endif // !TRIANGLE_H_
#pragma once

#ifndef RECT_H_
#define RECT_H_

#include "Graph.h"

class Rect : public Graph
{
public:
	Rect();

	void	draw();
	bool	isGrabbed(int x, int y);
	void	setSize(float length, float height);
	void	moveTo(int x, int y);
	void	move(int x, int y);
private:
	float	width;
	float	height;
	int		points[4][2];
	int		rotateCenterAngle;
};

#endif // !RECT_H_
#pragma once

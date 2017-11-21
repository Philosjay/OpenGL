#ifndef RECT_H_
#define RECT_H_

#include "Graph.h"

class Rect : public Graph
{
public:
	Rect();

	void	draw();
	bool	isGrabbed(int x, int y);
private:

	int		points[4][2];
};

#endif // !RECT_H_
#pragma once

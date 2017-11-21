#ifndef RECTF_H_
#define RECTF_H_

#include "Graph.h"

class Rectf : public Graph
{
public:
	Rectf();

	bool	isGrabbed(int x, int y);
	void	draw();
private:
	int		points[4][2];
};



#endif // !RECTF_H_
#pragma once

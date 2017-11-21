#ifndef TRIANGLEF_H_
#define TRIANGLEF_H_

#include "Graph.h"

class Trianglef : public Graph
{
public:
	Trianglef();
	bool	isGrabbed(int x, int y);
	void	draw();
private:
	float		points[3][2];
	
};


#endif // !TRIANGLEF_H_
#pragma once

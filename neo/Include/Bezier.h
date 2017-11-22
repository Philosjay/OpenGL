#ifndef BEZIER_H_
#define BEZIER_H_

#include "Graph.h"

class Bezier:public Graph
{
public:
	Bezier();
	
	void	setRefPoint(int x, int y, int num);
	void	draw();

	void	setEndPos(int x, int y);

private:


	typedef GLfloat VECTOR[2];
	int		count;
	VECTOR points[4];
	int		mStatus;

	void	setStatus(int status);
};


#endif // !BEZIER_H_
#pragma once

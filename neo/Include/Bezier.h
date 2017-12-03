#ifndef BEZIER_H_
#define BEZIER_H_

#include "Graph.h"

class Bezier : public Graph
{
public:
	Bezier();
	bool	isGrabbed(int x, int y);
	void	setRefPoint(int x, int y, int num);
	void	draw();
	void	move(int x, int y);
	void	setEndPos(int x, int y);
	Point	getRefPoint(int num);
private:


	typedef GLfloat VECTOR[2];
	//取样点总数
	int		count;
	VECTOR points[4];

};


#endif // !BEZIER_H_
#pragma once

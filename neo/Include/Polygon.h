#ifndef POLYGON_H_
#define POLYGON_H_

#include "../Include/Graph.h"



class Polygon : public Graph
{
public:
	Polygon();

	void	setRefPoint(int x, int y, int num);
	Point   getRefPoint(int num);
	void	draw();
	void	move(int x, int y);
	bool	isGrabbed(int x, int y);
	void	setMaxRefNum(int x);
	int		getMaxRefNum();
private:
	double	getTriangleArea(Point p0, Point p1, Point p2);
	float	points[30][2];
	int		n;
};


#endif // !POLYGON_H_
#pragma once

#ifndef POLYGON_H_
#define POLYGON_H_

#include "../Include/Graph.h"



class Polygon : public Graph
{
public:
	Polygon();

	void	setRefPoint(int x, int y, int num);
	void	draw();
	void	move(int x, int y);
	bool	isGrabbed(int x, int y);
private:
	typedef struct {
		double x;
		double y;
	}Point;
	double	getTriangleArea(Point p0, Point p1, Point p2);
	float	points[20][2];
	int		n;
};


#endif // !POLYGON_H_
#pragma once

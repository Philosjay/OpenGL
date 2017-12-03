#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include "Graph.h"

#define PI 3.14159f 

class Ellipse_ :public Graph
{
public:
	Ellipse_();
	bool	isGrabbed(int x, int y);
	void	draw();
	void	moveTo(int x, int y);
	void	move(int x, int y);
	virtual void	setRadiusA(float r);
	virtual void	setRadiusB(float r);
	float	getRadiusA();
	float	getRadiusB();
private:
	float R1;
	float R2;
	int		originX;
	int		originY;
};



#endif // !ELLIPSE_H_
#pragma once

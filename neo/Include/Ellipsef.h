#ifndef ELLIPSEF_H_
#define ELLIPSEF_H_

#include "Graph.h"


#define PI 3.14159f 


class Ellipsef_ :public Graph
{
public:
	Ellipsef_();

	void	setLineWidth(int width);
	void	draw();
	bool	isGrabbed(int x, int y);
private:
	int		mLineWidth;

	float R1;
	float R2;
	int		originX;
	int		originY;
};



#endif // !ELLIPSE_H_
#pragma once#pragma once

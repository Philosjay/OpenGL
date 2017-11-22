#ifndef LINE_H_
#define LINE_H_

#include "Graph.h"

class Line:public Graph
{
public:
	Line();
	bool	isGrabbed(int x, int y);
	void	draw();
private:
};



#endif // !LINE_H_
#pragma once

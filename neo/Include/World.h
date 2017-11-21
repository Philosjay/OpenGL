#ifndef WORLD_H_
#define WORLD_H_

#include <GL/glut.h>

class Graph;

class World
{
public:
	World();
	void addGraph(Graph* g);
	void show();
	Graph*	grab(int x, int y);
	int		drawConstantGraph(int x0, int y0, int x1, int y1, int type, int color, int size);
private:

	Graph*	mGraphs[10000000];
	int		mGraphCount;

	//用于绘制连续图

	int lineWidth;

	
};




#endif // WORLD_H_

#pragma once

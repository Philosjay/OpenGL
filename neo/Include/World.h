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
	int		getTotalGraphCount();
	Graph*	getGraph(int index);
	void	removeAllGraphs();
private:

	Graph*	mGraphs[10000000];
	int		mGraphCount;

	//用于绘制连续图

	int lineWidth;

	
};




#endif // WORLD_H_

#pragma once

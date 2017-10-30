#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

#include "SceneNode.h"


class Graph :public SceneNode
{
public:
	Graph();

	void setCurPos(int x, int y);
	void setMotionPos(int x, int y);
private:


};
Graph::Graph() {
}


inline void Graph::setCurPos(int x, int y)
{
	curPosX = x;
	curPosY = y;
}

inline void Graph::setMotionPos(int x, int y)
{
	motionPosX = x;
	motionPosY = y;
}

#endif // !GRAPH_H_
#pragma once

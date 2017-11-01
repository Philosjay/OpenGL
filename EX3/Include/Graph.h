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
	void setLineWidth(int width);
private:

protected:
	int	mLineWidth;
	//用于动态绘制图形
	int curPosX, curPosY;
	int motionPosX, motionPosY;

};
Graph::Graph()
	:mLineWidth(1)
{
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

inline void Graph::setLineWidth(int width)
{
	mLineWidth = width;
}

#endif // !GRAPH_H_
#pragma once

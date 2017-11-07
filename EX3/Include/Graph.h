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
	void	setStartPoint(int x, int y);
	void	setEndPoint(int x, int y);
	int	getStartPosX() { return curPosX; }
	int	getStartPosY() { return curPosY; }
	int	getEndPosX() { return motionPosX; }
	int	getEndPosY() { return motionPosY; }
	virtual void setStatus(int status);
	virtual	void setRef1Point(int x,int y);
	virtual void setRef2Point(int x, int y);
	virtual void preview(int type, int color, int lineWidth,
		int curPosX, int curPosY, int motionPosX, int motionPosY);
	virtual void updateStatus();
	virtual int getStatus();
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

inline void Graph::setStartPoint(int x, int y)
{
}

inline void Graph::setEndPoint(int x, int y)
{
}

inline void Graph::setStatus(int status)
{
}

inline void Graph::setRef1Point(int x, int y)
{
}

inline void Graph::setRef2Point(int x, int y)
{
}

inline void Graph::preview(int type, int color, int lineWidth, int curPosX, int curPosY, int motionPosX, int motionPosY)
{
	setType(type);
	setCurPos(curPosX, curPosY);
	setMotionPos(motionPosX, motionPosY);
	setColor(color);
	setLineWidth(lineWidth);
}

inline void Graph::updateStatus()
{
}

inline int Graph::getStatus()
{
	return 0;
}

#endif // !GRAPH_H_
#pragma once

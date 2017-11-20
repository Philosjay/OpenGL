#include "../Include/Graph.h"

Graph::Graph()
	:mLineWidth(1)
	, R(100)
	, n(1000)
	, Pi(3.1415926536f)
{
}


void Graph::setCurPos(int x, int y)
{
	curPosX = x;
	curPosY = y;
}

void Graph::setMotionPos(int x, int y)
{
	motionPosX = x;
	motionPosY = y;
}

void Graph::setLineWidth(int width)
{
	mLineWidth = width;
}

void Graph::setStartPoint(int x, int y)
{
}

void Graph::setEndPoint(int x, int y)
{
}

void Graph::setStatus(int status)
{
}

void Graph::setRef1Point(int x, int y)
{
}

void Graph::setRef2Point(int x, int y)
{
}

void Graph::preview(int type, int color, int lineWidth, int curPosX, int curPosY, int motionPosX, int motionPosY)
{
	setType(type);
	setCurPos(curPosX, curPosY);
	setMotionPos(motionPosX, motionPosY);
	setColor(color);
	setLineWidth(lineWidth);
}

void Graph::updateStatus()
{
}

int Graph::getStatus()
{
	return 0;
}



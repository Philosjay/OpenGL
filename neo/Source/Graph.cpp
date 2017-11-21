#include "../Include/Graph.h"

Graph::Graph()
	: n(1000)
	, Pi(3.1415926536f)
	, originPosX(0)
	, originPosY(0)
	, isDragged(false)
{
}


void Graph::setOriginPos(int x, int y)
{
	originPosX = x;
	originPosY = y;

	updateCenter();
}

void Graph::move(int x, int y)
{
	centerX += x;
	centerY += y;
}

void Graph::setMotionPos(int x, int y)
{
	motionPosX = x;
	motionPosY = y;
}



void Graph::setCenter()
{
	centerX = (originPosX + motionPosX) / 2;
	centerY = (originPosY + motionPosY) / 2;

	printf("----------------------------------Center X: %d  Y: %d\n", centerX, centerY);
}

void Graph::setRefPoint(int x, int y, int num)
{
	//do nothing by default
}

void Graph::update(int motionPosX, int motionPosY)
{
	setMotionPos(motionPosX, motionPosY);

	float length = motionPosX > originPosX ? motionPosX - originPosX : originPosX - motionPosX;
	float height = motionPosY > originPosY ? motionPosY - originPosY : originPosY - motionPosY;
	setSize(length,height);

	setCenter();
}

bool Graph::isGrabbed(int x, int y)
{
	//Ä¬ÈÏ·µ»Øfalse
	return false;
}

void Graph::updateCenter()
{
	centerX = (originPosX + length / 2);
	centerY = originPosY - height / 2;
}



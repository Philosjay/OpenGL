#include "../Include/Graph.h"

Graph::Graph()
	: n(1000)
	, Pi(3.1415926536f)
	, isDragged(false)
{
}

void Graph::setRefPoint(int x, int y, int num)
{
	//do nothing by default
}
Point Graph::getRefPoint(int num)
{
	return Point();
}
void Graph::rotateCenter(int angle90)
{
}
bool Graph::isGrabbed(int x, int y)
{
	//Ä¬ÈÏ·µ»Øfalse
	return false;
}

void Graph::setRadius(float r)
{
	//do nothing by default
}

void Graph::setRadiusA(float r)
{
}

void Graph::setRadiusB(float r)
{
}


void Graph::setMaxRefNum(int x)
{
}

int Graph::getMaxRefNum()
{
	return 0;
}

float Graph::getRadius()
{
	return 0.0f;
}

float Graph::getRadiusA()
{
	return 0.0f;
}

float Graph::getRadiusB()
{
	return 0.0f;
}

float Graph::getWidth()
{
	return 0.0f;
}

float Graph::getHeight()
{
	return 0.0f;
}

void Graph::setId(int key)
{
	this->id = key;
}

int Graph::getId()
{
	return id;
}





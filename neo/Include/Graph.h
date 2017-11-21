#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

#include "SceneNode.h"


class Graph :public SceneNode
{
public:
	Graph();

	void	setOriginPos(int x, int y);
	void	move(int x, int y);
	void	setMotionPos(int x, int y);
	void	setCenter();
	virtual	void setRefPoint(int x, int y, int num);
	virtual void update(int motionPosX, int motionPosY);
	virtual bool isGrabbed(int x,int y);

	int		requiredClicks;
private:
	void	updateCenter();

	
protected:

	//绘图矩形的左上顶点
	int originPosX, originPosY;
	//绘图矩形的右下顶点
	int motionPosX, motionPosY;
	//绘图矩形的中心
	float centerX;
	float centerY;

	//一些用于绘图的常量参数
	const int n;
	const GLfloat Pi;

	bool	isDragged;

};


#endif // !GRAPH_H_
#pragma once

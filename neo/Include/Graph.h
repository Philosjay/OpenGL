#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

#include "SceneNode.h"


class Graph :public SceneNode
{
public:
	Graph();

	void	setOriginPos(int x, int y);
	void	setCenter(int x, int y);
	void	setMotionPos(int x, int y);
	void	setLineWidth(int width);
	void	setStartPoint(int x, int y);
	void	setEndPoint(int x, int y);
	void	setCenter();
	int	getStartPosX() { return originPosX; }
	int	getStartPosY() { return originPosY; }
	int	getEndPosX() { return motionPosX; }
	int	getEndPosY() { return motionPosY; }
	virtual void setStatus(int status);
	virtual	void setRef1Point(int x,int y);
	virtual void setRef2Point(int x, int y);
	virtual void preview(int motionPosX, int motionPosY);
	virtual void updateStatus();
	virtual int getStatus();
	virtual bool isGrabbed(int x,int y);
private:
	void	updateCenter();

	
protected:
	int	mLineWidth;
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

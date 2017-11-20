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
	GLfloat R;

	//一些用于绘图的常量参数
	const int n;
	const GLfloat Pi;

};


#endif // !GRAPH_H_
#pragma once

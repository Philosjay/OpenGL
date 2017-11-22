#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

#include "SceneNode.h"

//Graph类新增绘制图形所需点击处理接口、拖拽方法的接口
class Graph :public SceneNode
{
public:
	Graph();

	virtual	void setRefPoint(int x, int y, int num);
	virtual bool isGrabbed(int x,int y);

	int		requiredClicks;
private:

	
protected:

	//一些用于绘图的常量参数
	const int n;
	const GLfloat Pi;

	bool	isDragged;

};


#endif // !GRAPH_H_
#pragma once

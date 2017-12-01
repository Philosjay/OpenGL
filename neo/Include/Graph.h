#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

#include "SceneNode.h"

//Graph类新增绘制图形所需点击处理接口、拖拽方法的接口
class Graph :public SceneNode
{
public:
	Graph();

	//设置指定参考点，用于特殊图形绘制，如Bezier曲线
	virtual	void	setRefPoint(int x, int y, int num);
	virtual void	rotateCenter(int angle90);
	virtual bool	isGrabbed(int x,int y);
	virtual void	setRadius(float r);
	virtual void	setRadiusA(float r);
	virtual void	setRadiusB(float r);
	virtual	void	setWidth(float width);
	virtual void	setHeight(float height);
	virtual void	setMaxRefNum(int x);
	void			setKey(int key);
	int				getKey();
	//区分绘图所需点击数，用于特殊图形绘制，如Bezier曲线
private:
	
	
protected:

	//一些用于绘图的常量参数
	const int n;
	const GLfloat Pi;
	int key;
	bool	isDragged;

};


#endif // !GRAPH_H_
#pragma once

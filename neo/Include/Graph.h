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
	virtual	Point	getRefPoint(int num);
	virtual void	rotateCenter(int angle90);
	virtual bool	isGrabbed(int x,int y);
	virtual void	setRadius(float r);
	virtual void	setRadiusA(float r);
	virtual void	setRadiusB(float r);
	virtual void	setMaxRefNum(int x);
	virtual int		getMaxRefNum();
	virtual float	getRadius();
	virtual float	getRadiusA();
	virtual float	getRadiusB();
	virtual float	getWidth();
	virtual float	getHeight();
	void			setId(int key);
	int				getId();
	//区分绘图所需点击数，用于特殊图形绘制，如Bezier曲线
private:
	
	
protected:

	//一些用于绘图的常量参数
	const int n;
	const GLfloat Pi;
	int id;
	bool	isDragged;

};


#endif // !GRAPH_H_
#pragma once

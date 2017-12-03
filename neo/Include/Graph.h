#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

#include "SceneNode.h"

//Graph����������ͼ������������ӿڡ���ק�����Ľӿ�
class Graph :public SceneNode
{
public:
	Graph();

	//����ָ���ο��㣬��������ͼ�λ��ƣ���Bezier����
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
	//���ֻ�ͼ������������������ͼ�λ��ƣ���Bezier����
private:
	
	
protected:

	//һЩ���ڻ�ͼ�ĳ�������
	const int n;
	const GLfloat Pi;
	int id;
	bool	isDragged;

};


#endif // !GRAPH_H_
#pragma once

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
	//���ֻ�ͼ������������������ͼ�λ��ƣ���Bezier����
private:
	
	
protected:

	//һЩ���ڻ�ͼ�ĳ�������
	const int n;
	const GLfloat Pi;
	int key;
	bool	isDragged;

};


#endif // !GRAPH_H_
#pragma once

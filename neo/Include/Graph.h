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

	//��ͼ���ε����϶���
	int originPosX, originPosY;
	//��ͼ���ε����¶���
	int motionPosX, motionPosY;
	//��ͼ���ε�����
	float centerX;
	float centerY;

	//һЩ���ڻ�ͼ�ĳ�������
	const int n;
	const GLfloat Pi;

	bool	isDragged;

};


#endif // !GRAPH_H_
#pragma once

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

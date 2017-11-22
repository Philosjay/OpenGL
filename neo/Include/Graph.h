#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>

#include "SceneNode.h"

//Graph����������ͼ������������ӿڡ���ק�����Ľӿ�
class Graph :public SceneNode
{
public:
	Graph();

	virtual	void setRefPoint(int x, int y, int num);
	virtual bool isGrabbed(int x,int y);

	int		requiredClicks;
private:

	
protected:

	//һЩ���ڻ�ͼ�ĳ�������
	const int n;
	const GLfloat Pi;

	bool	isDragged;

};


#endif // !GRAPH_H_
#pragma once

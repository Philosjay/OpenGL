#ifndef WORLD_H_
#define WORLD_H_

#include <GL/glut.h>


class Graph;

class World
{
public:
	World();

	void previewGraph(int type, int color,int lineWidth, int curPosX, int curPosY, int motionPosX, int motionPosY);
	void saveGraph();
	void addGraph(int type);
	void show();
private:

	Graph*	mGraphs[10000000];
	Graph*	mTmp;
	int		mGraphCount;
	int		curType;

	//���ڻ�������ͼ
	int x0;
	int y0;
	int lineWidth;
	//���ڻ�������
	int startPosX;
	int startPosY;
	int endPosX;
	int endPosY;

	int		drawConstantGraph(int x0, int y0, int x1, int y1,int type,int color,int size);
};




#endif // WORLD_H_

#pragma once

#ifndef WORLD_H_
#define WORLD_H_

#include <GL/glut.h>

#include "Graph.h"
#include "Line.h"
#include "Rect.h"
#include "Rectf.h"
#include "Triangle.h"
#include "Trianglef.h"
#include "Circle.h"
#include "Circlef.h"
#include "Ellipse.h"
#include "Ellipsef.h"
#include "Eraser.h"
#include "Pen.h"
#include "Bezier.h"


bool	isDrawingConstant = false;
bool	isPreviewing = false;

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
	Graph*	mTmp=NULL;
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

World::World():
	mGraphCount(0)
{

	
}

inline void World::previewGraph(int type,int color,  int lineWidth,
								int curPosX, int curPosY, int motionPosX, int motionPosY)
{
	

	if(!isPreviewing)
	{
		printf("is generating new \n");

		mTmp = NULL;
		curType = type;		//����ʶ��Pen��Eraser
		this->lineWidth = lineWidth;	//��¼Pen��Eraser�����ش�С

		isPreviewing = true;

		switch (type)
		{
		case SceneNode::Line:
			mTmp = new Line;
			break;
		case SceneNode::Rect:
			mTmp = new Rect;
			break;
		case SceneNode::Rectf:
			mTmp = new Rectf;
			break;
		case SceneNode::Triangle:
			mTmp = new Triangle;
			break;
		case SceneNode::Trianglef:
			mTmp = new Trianglef;
			break;
		case SceneNode::CirCle:
			mTmp = new Circle;
			break;
		case SceneNode::CirClef:
			mTmp = new Circlef;
			break;
		case SceneNode::Ellipse:
			mTmp = new Ellipse_;
			break;
		case SceneNode::Ellipsef:
			mTmp = new Ellipsef_;
			break;
		case SceneNode::Eraser:
			mTmp = new Eraser;
			break;
		case SceneNode::Pen:
			mTmp = new Pen;
			break;
		case SceneNode::Curve:
			mTmp = new Bezier;
		default:
			break;
		}
	}

	if (mTmp != NULL) {
		mTmp->preview(type, color, lineWidth,curPosX, curPosY, motionPosX, motionPosY);
	}


	//���ڵ���Eraser��Pen
	int size = 0;
	switch (type)
	{
	case SceneNode::Eraser:
		if (!isDrawingConstant) {
			x0 = curPosX;
			y0 = curPosY;
		}
		size = lineWidth * 4;
		isDrawingConstant = true;
		drawConstantGraph(x0, y0, motionPosX, motionPosY, type, color, size);
		x0 = motionPosX;
		y0 = motionPosY;
		break;
	case SceneNode::Pen:
		if (!isDrawingConstant) {
			x0 = curPosX;
			y0 = curPosY;
		}
		size = lineWidth * 2;
		isDrawingConstant = true;
		drawConstantGraph(x0, y0, motionPosX, motionPosY, type, color, size);
		x0 = motionPosX;
		y0 = motionPosY;
		break;
	default:
		break;
	}
}

inline void World::saveGraph()		//����ſ�ʱ����������������Ż���Pen��Eraserʱ���ô˱��淽��
{
	switch (curType)
	{
	case SceneNode::Eraser:
	case SceneNode::Pen:
		//���ڴ˱���
		isDrawingConstant = false;
		break;
	case SceneNode::Curve:
		//��������ʱҪд����ı��淽��
		mTmp->updateStatus();
		if (mTmp->getStatus() == Bezier::end) {
			mGraphs[mGraphCount++] = mTmp;
			isPreviewing = false;
		}
		break;
	default:
		mGraphs[mGraphCount++] = mTmp;
		isPreviewing = false;
		break;
	}
}

inline void World::addGraph(int type)
{

}

inline void World::show()
{
	for (int i = 0; i < mGraphCount; i++) {
		if (mGraphs[i] != NULL)
			mGraphs[i]->draw();
	}
	if (mTmp != NULL) {
		mTmp->draw();

	}

}

inline int World::drawConstantGraph(int x0, int y0, int x1, int y1,int type,int color,int size)
{
	//��������С��һ����Χ
	if (sqrtf(((float)x1 - (float)x0)*((float)x1 - (float)x0)
		+ ((float)y1 - (float)y0)*((float)y1 - (float)y0)) <= (float)size) {
		//��ͼ
		switch (type)
		{
		case SceneNode::Eraser:
			mTmp = new Eraser;
			break;
		case SceneNode::Pen:
			mTmp = new Pen;
			break;
		default:
			break;
		}
		mTmp->setMotionPos((x1 + x0) / 2, (y1 + y0) / 2);
		mTmp->setLineWidth(size);
		mTmp->setColor(color);
		mGraphs[mGraphCount++] = mTmp;
		isPreviewing = false;
		return 0;
	}
	//ǰ���
	drawConstantGraph(x0, y0, (x1 + x0) / 2, (y1 + y0) / 2,type,color,size);

	//����
	drawConstantGraph((x1 + x0) / 2, (y1 + y0) / 2,x1, y1,type,color,size);
}



#endif // WORLD_H_

#pragma once

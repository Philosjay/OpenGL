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




bool	isDrawingConstant = false;

class World
{
public:
	World();

	void previewGraph(int type, int color,int lineWidth, int curPosX, int curPosY, int motionPosX, int motionPosY);
	void saveGraph();
	void show();
private:
	Graph*	mGraphs[1000000];
	Graph*	mTmp=NULL;
	int		mGraphCount;
	int		curType;

	//用于绘制连续图
	int x0;
	int y0;
	int lineWidth;

	int		drawConstantGraph(int x0, int y0, int x1, int y1);
};

World::World():
	mGraphCount(0)
{

	
}

inline void World::previewGraph(int type,int color,  int lineWidth,
								int curPosX, int curPosY, int motionPosX, int motionPosY)
{
	mTmp = NULL;
	curType = type;		//用于识别Pen和Eraser
	this->lineWidth = lineWidth;	//记录Pen和Eraser的像素大小

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
	default:
		break;
	}

	if (mTmp != NULL) {
		mTmp->setType(type);
		mTmp->setCurPos(curPosX, curPosY);
		mTmp->setMotionPos(motionPosX, motionPosY);
		mTmp->setColor(color);
		mTmp->setLineWidth(lineWidth);
	}
	
	if (!isDrawingConstant) {
		x0 = curPosX;
		y0 = curPosY;
	}

	if (type == SceneNode::Eraser) {

		if (sqrtf(((float)motionPosX - (float)x0)*((float)motionPosX - (float)x0)
			+ ((float)motionPosY - (float)y0)*((float)motionPosY - (float)y0)) >= lineWidth*4) {
			isDrawingConstant = true;
			drawConstantGraph(x0, y0, motionPosX, motionPosY);
		}
		else {
			mGraphs[mGraphCount++] = mTmp;
		}
			x0 = motionPosX;
			y0 = motionPosY;

	}
}

inline void World::saveGraph()
{
	if(curType!=SceneNode::Eraser )
	mGraphs[mGraphCount++] = mTmp;

	isDrawingConstant = false;
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

inline int World::drawConstantGraph(int x0, int y0, int x1, int y1)
{
	//当两点间距小于一定范围
	if (sqrtf(((float)x1 - (float)x0)*((float)x1 - (float)x0)
		+ ((float)y1 - (float)y0)*((float)y1 - (float)y0)) <= lineWidth*4) {
		//画图
		mTmp = new Eraser;
		mTmp->setMotionPos((x1 + x0) / 2, (y1 + y0) / 2);
		mTmp->setLineWidth(lineWidth);
		mGraphs[mGraphCount++] = mTmp;
		return 0;
	}
	//前半段
	drawConstantGraph(x0, y0, (x1 + x0) / 2, (y1 + y0) / 2);

	//后半段
	drawConstantGraph((x1 + x0) / 2, (y1 + y0) / 2,x1, y1);
}



#endif // WORLD_H_

#pragma once

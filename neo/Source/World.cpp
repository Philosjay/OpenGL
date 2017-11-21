#include "../Include/World.h"

#include "../Include/Graph.h"
#include "../Include/Line.h"
#include "../Include/Rect.h"
#include "../Include/Rectf.h"
#include "../Include/Triangle.h"
#include "../Include/Trianglef.h"
#include "../Include/Circle.h"
#include "../Include/Circlef.h"
#include "../Include/Ellipse.h"
#include "../Include/Ellipsef.h"
#include "../Include/Eraser.h"
#include "../Include/Pen.h"
#include "../Include/Bezier.h"

bool	isDrawingConstant = false;
bool	isPreviewing = false;

World::World() :
	mGraphCount(0),
	mTmp(NULL)
{


}

void World::previewGraph(int type, int color, int lineWidth,
	int curPosX, int curPosY, int motionPosX, int motionPosY)
{


	if (!isPreviewing)
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
		mTmp->setColor(color);
		mTmp->setLineWidth(lineWidth);

		if (type != SceneNode::Curve) {
			mTmp->setOriginPos(curPosX, curPosY);
		}

		mTmp->preview(motionPosX, motionPosY);


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
void World::saveGraph()		//����ſ�ʱ����������������Ż���Pen��Eraserʱ���ô˱��淽��
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

 void World::addGraph(int type)
{

}
void World::show()
{
	//�Ѵ����ͼ��
	for (int i = 0; i < mGraphCount; i++) {
		if (mGraphs[i] != NULL)
			mGraphs[i]->draw();
	}

	//��̬Ԥ����ͼ��
	if (mTmp != NULL) {
		mTmp->draw();

	}

}

Graph * World::grab(int x, int y)
{
	for (int i = mGraphCount-1; i >= 0; i--) {
		if (mGraphs[i] != NULL) {
			if (mGraphs[i]->isGrabbed(x, y)) {
				return mGraphs[i];
			}
		}
	}
	return NULL;
}

int World::drawConstantGraph(int x0, int y0, int x1, int y1, int type, int color, int size)
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
	drawConstantGraph(x0, y0, (x1 + x0) / 2, (y1 + y0) / 2, type, color, size);

	//����
	drawConstantGraph((x1 + x0) / 2, (y1 + y0) / 2, x1, y1, type, color, size);
}

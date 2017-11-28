#include "../Include/PainterForRect.h"
#include "../Include/Window.h"
#include "../Include/Graph.h"
#include "../Include/World.h"

PainterForRect::PainterForRect(Application * targetApp, Window * targetWindow, World * targetWorld)
	: Painter(targetApp, targetWindow, targetWorld)
{
	requiredClicks = 1;
}

void PainterForRect::mouseButton(int button, int state, int x, int y)
{
	switch (button) {
	case GLUT_LEFT_BUTTON:
		switch (state) {
		case GLUT_DOWN:
			break;
		case GLUT_UP:
			if (mPainter->getTargetWindow()->isInPaper()) {
				if (mPainter->getTargetGraph() != NULL) {
					if (mPainter->getRequiredClicks() <= 0) {
						mPainter->quit();
					}
				}
			}
			break;
		}
		break;
	case GLUT_RIGHT_BUTTON:
		switch (state)
		{
		case GLUT_DOWN:
			//点击右键结束绘图
			mPainter->quit();
			break;
		default:
			break;
		}

		break;
	case GLUT_MIDDLE_BUTTON:

		break;
	}
	mPainter->update();
}

void PainterForRect::mouseMotion(int x, int y)
{	
	//换算后的坐标，用于求尺寸
	mPainter->setEndPos(x + 50, 770 - y);

	float deltaX = -mPainter->getCurPosX() + mPainter->getEndPosX();
	float deltaY = -mPainter->getCurPosY() + mPainter->getEndPosY();

	//宽高允许为负数，在Rect内部的运算中表现为Rect中心的偏移
	float width = deltaX;
	float height = -deltaY;

	if (mPainter->getTargetWindow()->isInPaper()) {
		if (mPainter->getTargetGraph() != NULL)
			mPainter->getTargetGraph()->setWidth(width);
			mPainter->getTargetGraph()->setHeight(height);
			mPainter->getTargetGraph()->setSize(width, height);
	}

	//更新当前操作状态
	mPainter->update();
}



void PainterForRect::paint(int x, int y)
{
	if (!mPainter->isStarted()) {
		start(x, y);
	}
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMotion);
}

void PainterForRect::start(int x, int y)
{
	//记录起始点，用于motion求尺寸
	mPainter->setCurPos(x, y);

	mPainter->setStarted();
	mPainter->getTargetGraph()->setWidth(0);
	mPainter->getTargetGraph()->setHeight(0);
	mPainter->getTargetGraph()->moveTo(x, y);
	mPainter->getTargetGraph()->setColor(mPainter->getTargetWindow()->getActiveColor());
	mPainter->getTargetGraph()->setLineWidth(mPainter->getTargetWindow()->getActiveLineWidth());
	mPainter->getTargetWorld()->addGraph(mPainter->getTargetGraph());
	mPainter->setClicked();
}



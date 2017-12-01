#include "../Include/PainterForCircle.h"
#include "../Include/Window.h"
#include "../Include/Graph.h"
#include "../Include/World.h"

PainterForCircle::PainterForCircle(Application * targetApp, Window * targetWindow, World * targetWorld)
	:Painter (targetApp, targetWindow, targetWorld)
{
	requiredClicks = 1;
}

PainterForCircle::PainterForCircle()
{
}

void PainterForCircle::paint(int x, int y)
{
	if (!mPainter->isStarted()) {
		start(x, y);
	}
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMotion);
}

void PainterForCircle::start(int x, int y)
{
	//记录起始点，用于motion求半径
	mPainter->setCurPos(x, y);

	mPainter->setStarted();
	mPainter->getTargetGraph()->setRadius(0);
	mPainter->getTargetGraph()->moveTo(x,y);
	mPainter->getTargetGraph()->setColor(mPainter->getTargetWindow()->getActiveColor());
	mPainter->getTargetGraph()->setLineWidth(mPainter->getTargetWindow()->getActiveLineWidth());
	mPainter->getTargetWorld()->addGraph(mPainter->getTargetGraph());
	mPainter->setClicked();
}

void PainterForCircle::mouseButton(int button, int state, int x, int y)
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

void PainterForCircle::mouseMotion(int x, int y)
{	
	//换算后的坐标，用于求半径
	mPainter->setEndPos(x + 50, 770 - y);

	float R = sqrtf(((float)mPainter->getEndPosX() - (float)mPainter->getCurPosX())*((float)mPainter->getEndPosX() - (float)mPainter->getCurPosX())
		+ ((float)mPainter->getEndPosY() - (float)mPainter->getCurPosY())*((float)mPainter->getEndPosY() - (float)mPainter->getCurPosY()));

	if (mPainter->getTargetWindow()->isInPaper()) {
		if (mPainter->getTargetGraph() != NULL)
			mPainter->getTargetGraph()->setRadius(R);
	}

	//更新当前操作状态
	mPainter->update();
}




#include "../Include/PainterForPolygon.h"
#include "../Include/Window.h"
#include "../Include/Graph.h"
#include "../Include/Painter.h"
#include "../Include/World.h"

int num;
int startX, startY;

PainterForPolygon::PainterForPolygon(Application * targetApp, Window * targetWindow, World * targetWorld)
	: Painter(targetApp, targetWindow, targetWorld)
{
	requiredClicks = 18;
}

PainterForPolygon::PainterForPolygon()
{
	requiredClicks = 18;
}

void PainterForPolygon::mouseButton(int button, int state, int x, int y)
{


	switch (button) {
	case GLUT_LEFT_BUTTON:
		switch (state) {
		case GLUT_DOWN:
			mPainter->setCurPos(x + 50, 770 - y);

			mPainter->getTargetWindow()->update(mPainter->getCurPosX(), mPainter->getCurPosY());
			mPainter->setEndPos(mPainter->getCurPosX(), mPainter->getCurPosY());

			if (mPainter->getTargetWindow()->isInPaper()) {
				mPainter->setClicked();
				//根据所选工具调用不同的方法
				//更新当前图形所需点击数量
				if (mPainter->isStarted()) {
					mPainter->getTargetGraph()->setRefPoint(
						mPainter->getEndPosX(), mPainter->getEndPosY(),
						num -mPainter->getRequiredClicks());
	
					for (int i = num - mPainter->getRequiredClicks(); i < num; i++) {
						mPainter->getTargetGraph()->setRefPoint(
							mPainter->getEndPosX(), mPainter->getEndPosY(),
							i);
					}

					
				}
			}
			
			break;
		case GLUT_UP:
			if (mPainter->getTargetWindow()->isInPaper()) {
				if (mPainter->getRequiredClicks() <= 1) {
					mPainter->getTargetGraph()->setRefPoint(
						startX, startY, num -1);
					mPainter->quit();
				}
			}
//			mPainter->setClicked();
			//				Pgrab = NULL;
			break;
		}
		break;
	case GLUT_RIGHT_BUTTON:
		switch (state)
		{
		case GLUT_DOWN:
			//点击右键结束绘图
			mPainter->getTargetGraph()->setRefPoint(
				startX, startY, num - 1);
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

void PainterForPolygon::mouseMotion(int x, int y)
{	//换算后的坐标
	
	mPainter->setEndPos(x + 50, 770 - y);

	if (mPainter->getTargetWindow()->isInPaper()) {
		if (mPainter->getTargetGraph() != NULL)
			mPainter->getTargetGraph()->setRefPoint(
				mPainter->getEndPosX(), mPainter->getEndPosY(),
				num - mPainter->getRequiredClicks());
		for (int i = num - mPainter->getRequiredClicks() ; i < num; i++) {
			mPainter->getTargetGraph()->setRefPoint(
				mPainter->getEndPosX(), mPainter->getEndPosY(),
				i);
		}

	}
	mPainter->update();
}



void PainterForPolygon::paint(int x, int y)
{
	if (!mPainter->isStarted()) {
		start(x, y);
	}
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMotion);
}

void PainterForPolygon::start(int x, int y)
{
	for (int i = 0; i < mPainter->getRequiredClicks()+1; i++) {
		mPainter->getTargetGraph()->setRefPoint(
			x, y, i);
	}
	num = mPainter->getRequiredClicks();
	mPainter->getTargetGraph()->setMaxRefNum(num);
	startX = x;
	startY = y;

	mPainter->setStarted();
	mPainter->getTargetGraph()->moveTo(mPainter->getCurPosX(), mPainter->getCurPosY());
	mPainter->getTargetGraph()->setColor(mColor.r,mColor.g,mColor.b);
	mPainter->getTargetGraph()->setLineWidth(mPainter->getTargetWindow()->getActiveLineWidth());
	mPainter->getTargetWorld()->addGraph(mPainter->getTargetGraph());
	mPainter->setClicked();
}

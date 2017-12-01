#include "../Include/PainterForLine.h"
#include "../Include/Window.h"
#include "../Include/Graph.h"

#include <GL/glut.h>
#include <iostream>



PainterForLine::PainterForLine(Application* targetApp, Window* targetWindow, World* targetWorld)
	: Painter(targetApp, targetWindow, targetWorld)
{
	requiredClicks = 1;

}

PainterForLine::PainterForLine()
{
}

void PainterForLine::paint(int x,int y)
{
	if (!mPainter->isStarted()) {
		start(x, y);
	}
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMotion);

}
void PainterForLine::mouseButton(int button, int state, int x, int y)
{
	switch (button) {
		case GLUT_LEFT_BUTTON:
			switch (state) {
			case GLUT_DOWN:
				mPainter->setCurPos(x + 50, 770 - y);

				mPainter->getTargetWindow()->update(mPainter->getCurPosX(), mPainter->getCurPosY());
				mPainter->setEndPos(mPainter->getCurPosX(), mPainter->getCurPosY());

				if (mPainter->getTargetWindow()->isInPaper()) {
					//根据所选工具调用不同的方法
					//更新当前图形所需点击数量
					if (mPainter->isStarted()) {
						mPainter->getTargetGraph()->setEndPos(mPainter->getCurPosX(), mPainter->getCurPosY());
						mPainter->setClicked();
					}
				}
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
void PainterForLine::mouseMotion(int x, int y)
{
	//换算后的坐标
	mPainter->setEndPos(x + 50, 770 - y);

	if (mPainter->getTargetWindow()->isInPaper()) {
		if (mPainter->getTargetGraph() != NULL)
			mPainter->getTargetGraph()->setEndPos(mPainter->getEndPosX(), mPainter->getEndPosY());
	}

	//更新当前操作状态
	mPainter->update();

}


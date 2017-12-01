#include "../Include/PainterForCurve.h"
#include "../Include/Window.h"
#include "../Include/Graph.h"
#include "../Include/Painter.h"
#include "../Include/World.h"




PainterForCurve::PainterForCurve(Application* targetApp, Window* targetWindow, World* targetWorld)
	: Painter(targetApp, targetWindow,targetWorld)
{
	requiredClicks = 3;
}

PainterForCurve::PainterForCurve()
{
}

void PainterForCurve::paint(int x, int y)
{
	if (!mPainter->isStarted()) {
		start(x, y);
	}
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMotion);
}
void PainterForCurve::start(int x, int y)
{
	for (int i = 0; i < mPainter->getRequiredClicks(); i++) {
		mPainter->getTargetGraph()->setRefPoint(
			x, y, i);
	}

	mPainter->setStarted();
	mPainter->getTargetGraph()->moveTo(mPainter->getCurPosX(), mPainter->getCurPosY());
	mPainter->getTargetGraph()->setColor(mPainter->getTargetWindow()->getActiveColor());
	mPainter->getTargetGraph()->setLineWidth(mPainter->getTargetWindow()->getActiveLineWidth());
	mPainter->getTargetWorld()->addGraph(mPainter->getTargetGraph());
	mPainter->setClicked();
}
void PainterForCurve::mouseButton(int button, int state, int x, int y)
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
					
					switch (mPainter->getRequiredClicks())
					{
					case 2:
						mPainter->getTargetGraph()->setRefPoint(
							mPainter->getCurPosX(), mPainter->getCurPosY(), 1);
						break;
					case 1:
						mPainter->getTargetGraph()->setRefPoint(
							mPainter->getCurPosX(), mPainter->getCurPosY(), 2);
						break;
					default:
						break;
					}
					mPainter->setClicked();
				}
			}
			break;
		case GLUT_UP:
			if (mPainter->getTargetWindow()->isInPaper()) {
				if (mPainter->getRequiredClicks() <= 0) {
					mPainter->quit();
				}
			}
			//				Pgrab = NULL;
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
void PainterForCurve::mouseMotion(int x, int y)
{
	//换算后的坐标
	mPainter->setEndPos(x + 50, 770 - y);

	if (mPainter->getTargetWindow()->isInPaper()) {
		if (mPainter->getTargetGraph() != NULL)
			switch (mPainter ->getRequiredClicks())
			{
			case 2:
				mPainter->getTargetGraph()->setRefPoint(mPainter->getEndPosX(), mPainter->getEndPosY(), 3);
				mPainter->getTargetGraph()->setRefPoint(mPainter->getEndPosX(), mPainter->getEndPosY(), 2);
				break;
			case 1:
				mPainter->getTargetGraph()->setRefPoint(mPainter->getEndPosX(), mPainter->getEndPosY(), 1);
				break;
			case 0:
				mPainter->getTargetGraph()->setRefPoint(mPainter->getEndPosX(), mPainter->getEndPosY(), 2);
				break;
			default:
				break;
			}
	}

	//更新当前操作状态
	mPainter->update();

}
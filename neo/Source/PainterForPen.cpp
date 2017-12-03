#include "../Include/PainterForPen.h"
#include "../Include/Window.h"
#include "../Include/Graph.h"
#include "../Include/World.h"
#include "../Include/Pen.h"
#include "../Include/settingList.h"

PainterForPen::PainterForPen(Application * targetApp, Window * targetWindow, World * targetWorld)
	:Painter(targetApp, targetWindow, targetWorld)
{
	requiredClicks = 1;
}

PainterForPen::PainterForPen()
{
	requiredClicks = 1;
}

void PainterForPen::mouseButton(int button, int state, int x, int y)
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

void PainterForPen::mouseMotion(int x, int y)
{	//换算后的坐标，用于求半径
	mPainter->setEndPos(x + 50, 770 - y);
	

	if (mPainter->getTargetWindow()->isInPaper()) {
		if (mPainter->getTargetGraph() != NULL)
			mPainter->drawConstantGraph(mPainter->getPrePosX(), mPainter->getPrePosY(),
				mPainter->getEndPosX(), mPainter->getEndPosY(), mPainter->getTargetWindow()->getActiveLineWidth());
	}
	//记录上一个点的位置，用于求鼠标位移
	mPainter->setPrePos(x + 50, 770 - y);

	//更新当前操作状态
	mPainter->update();
}

void PainterForPen::paint(int x, int y)
{
	if (!mPainter->isStarted()) {
		start(x, y);
	}
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMotion);
}

void PainterForPen::start(int x, int y)
{	//记录起始点，用于motion求半径
	mPainter->setCurPos(x, y);
	//记录上一个点的位置，用于求鼠标位移
	mPainter->setPrePos(x, y);


	mPainter->setStarted();
	mPainter->getTargetGraph()->moveTo(x, y);
	mPainter->getTargetGraph()->setColor(mColor.r, mColor.g, mColor.b);
	mPainter->getTargetGraph()->setLineWidth(mPainter->getTargetWindow()->getActiveLineWidth());
	mPainter->getTargetWorld()->addGraph(mPainter->getTargetGraph());
	mPainter->setClicked();
}

int PainterForPen::drawConstantGraph(float x0, float y0, float x1, float y1, float size)
{

	//当两点间距小于一定范围
	if (sqrtf(((float)x1 - (float)x0)*((float)x1 - (float)x0)
		+ ((float)y1 - (float)y0)*((float)y1 - (float)y0)) <= (float)size) {
		Graph* mTmp = NULL;
		//画图
		mTmp = new Pen;
		mTmp->setEndPos((x1 + x0) / 2, (y1 + y0) / 2);
		mTmp->setLineWidth(size);
		mTmp->setColor(mPainter->getColor().r, mPainter->getColor().g, mPainter->getColor().b);
		mTmp->setId(mPainter->getId());
		mPainter->getTargetWorld()->addGraph(mTmp);
		return 0;
	}
	//前半段
	drawConstantGraph(x0, y0, (x1 + x0) / 2, (y1 + y0) / 2,  size);

	//后半段
	drawConstantGraph((x1 + x0) / 2, (y1 + y0) / 2, x1, y1,  size);

}
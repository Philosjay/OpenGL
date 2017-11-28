#include "../Include/PainterForEllipse.h"
#include "../Include/Window.h"
#include "../Include/Graph.h"
#include "../Include/World.h"


PainterForEllipse::PainterForEllipse(Application * targetApp, Window * targetWindow, World * targetWorld)
	: Painter(targetApp, targetWindow, targetWorld)
{
	requiredClicks = 1;
}

void PainterForEllipse::mouseButton(int button, int state, int x, int y)
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
			//����Ҽ�������ͼ
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

void PainterForEllipse::mouseMotion(int x, int y)
{
	//����������
	mPainter->setEndPos(x + 50, 770 - y);

	float deltaX =	-mPainter->getCurPosX() + mPainter->getEndPosX();
	float deltaY =  -mPainter->getCurPosY() + mPainter->getEndPosY();

	float R1 = deltaX > 0 ? deltaX : -deltaX;
	float R2 = deltaY > 0 ? deltaY : -deltaY;

	

	if (mPainter->getTargetWindow()->isInPaper()) {
		if (mPainter->getTargetGraph() != NULL)
			mPainter->getTargetGraph()->setRadiusA(R1);
			mPainter->getTargetGraph()->setRadiusB(R2);
	}

	//���µ�ǰ����״̬
	mPainter->update();
}



void PainterForEllipse::paint(int x, int y)
{
	if (!mPainter->isStarted()) {
		start(x, y);
	}
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMotion);
}

void PainterForEllipse::start(int x, int y)
{
	//��¼��ʼ�㣬����motion��뾶
	mPainter->setCurPos(x, y);

	mPainter->setStarted();
	mPainter->getTargetGraph()->setRadiusA(0);
	mPainter->getTargetGraph()->setRadiusB(0);
	mPainter->getTargetGraph()->moveTo(x, y);
	mPainter->getTargetGraph()->setColor(mPainter->getTargetWindow()->getActiveColor());
	mPainter->getTargetGraph()->setLineWidth(mPainter->getTargetWindow()->getActiveLineWidth());
	mPainter->getTargetWorld()->addGraph(mPainter->getTargetGraph());
	mPainter->setClicked();
}

void PainterForEllipse::setRadiusA(float r)
{
}

void PainterForEllipse::setRadiusB(float r)
{
	
}

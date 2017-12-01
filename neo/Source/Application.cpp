#include "../Include/Application.h"

#include "../Include/World.h"
#include "../Include/Window.h"
#include "../Include/Botton.h"
#include "../Include/Graph.h"
#include "../Include/Line.h"
#include "../Include/Rect.h"
#include "../Include/Triangle.h"
#include "../Include/Circle.h"
#include "../Include/Ellipse.h"
#include "../Include/Eraser.h"
#include "../Include/Pen.h"
#include "../Include/Bezier.h"
#include "../Include/Polygon.h"
#include "../Include/settingList.h"
#include "../Include/PainterForLine.h"
#include "../Include/PainterForCurve.h"
#include "../Include/PainterForCircle.h"
#include "../Include/PainterForEllipse.h"
#include "../Include/PainterForRect.h"
#include "../Include/PainterForTriangle.h"
#include "../Include/PainterForPolygon.h"
#include "../Include/PainterForPen.h"

#include "../Include/Manager.h"

#include<iostream>


Window* window;
World*	world;
Graph*	grab;
Application* app;
Graph*	newGraph = NULL;

int curPosX, curPosY;
int endPosX, endPosY;

int mShapeStatus;
int mLineWidthStatus;
int mColorStatus;

int prePosX;
int prePosY;

Application::Application()
	:  mGrab(NULL)
	, curStatus(End)
{
	world = new World;
	window = new Window(1280, 720, "test");
	mManager = new Manager(this,window,world);
	window->registerManager(mManager);

	mWorld = world;
	mWindow = window;
	grab = mGrab;
	app = this;
}
void Application::init() {
	glClearColor(1, 1, 1, 0);
}

void Application::mouseButton(int button, int state, int x, int y)
{
	Painter* painter = NULL; 

	switch (button) {
	case GLUT_LEFT_BUTTON:
		switch (state) {
		case GLUT_DOWN:
			curPosX = x + 50;
			curPosY = 770 - y;
			prePosX = curPosX;
			prePosY = curPosY;


			window->update(curPosX, curPosY);
			endPosX = curPosX;
			endPosY = curPosY;
			printf("is in paper %d \n", window->isInPaper());
			if (window->isInPaper()) {
				//根据所选工具调用不同的方法
				switch (app->curStatus)
				{
				case Application::Draw:
					//更新当前图形所需点击数量
					newGraph =app->getManager()->generateGraph(window->getActiveTool());
					painter = app->getManager()->generatePainter(window->getActiveTool());
					painter->setPaintColor(window->getActiveColor());
					painter->setPaintLineWidth(window->getActiveLineWidth());
					painter->setPaintGraph(newGraph);
					painter->paint(curPosX, curPosY);
					break;
				case Application::Drag:
					grab = world->grab(curPosX, curPosY);
					break;
				default:
					break;
				}
			}
			break;
		case GLUT_UP:
			if (window->isInPaper()) {
				if (newGraph != NULL) {
//					if (newGraph->requiredClicks <= 0) {
//						newGraph = NULL;
//					}
				}	
			}
			grab = NULL;
			break;
		}
		break;
	case GLUT_RIGHT_BUTTON:
		switch (state)
		{
		case GLUT_DOWN:
			//点击右键结束绘图
			newGraph = NULL;
			break;
		default:
			break;
		}

		break;
	case GLUT_MIDDLE_BUTTON:

		break;
	}


	app->updateStatus(window->getActiveTool());
	display();
	printf("Curpos X %d Y %d\n", curPosX, curPosY);

}
void Application::mouseMotion(int x, int y)
{
	//换算后的坐标
	endPosX = x + 50;
	endPosY = 770 - y;


//	window->update(endPosX, endPosY);

	switch (app->curStatus)
	{
	case Application::Draw:
		if (window->isInPaper()) {
			if(newGraph!=NULL)
			newGraph->setEndPos(endPosX, endPosY);
		}
		break;
	case Application::Drag:
		//成功抓取图形，移动它
		if (grab != NULL) {
			int deltaX = endPosX - prePosX;
			int deltaY = endPosY - prePosY;
			grab->move(deltaX, deltaY);
			prePosX = endPosX;
			prePosY = endPosY;
		}
		break;
	default:
		break;
	}

	printf("motion X %d Y %d\n", endPosX, endPosY);

	



	//更新当前操作状态
	display();
}

void Application::run() {

	processUserInput();
	mWindow->update(curPosX, curPosY);
	app->updateStatus(window->getActiveTool());
	this->render();
	glutMainLoop();
}
void Application::updateStatus(int n)
{
	switch (n)
	{
	case ToolSet::line:
	case ToolSet::rect:
	case ToolSet::rectf:
	case ToolSet::triangle:
	case ToolSet::trianglef:
	case ToolSet::cirCle:
	case ToolSet::cirClef:
	case ToolSet::ellipse:
	case ToolSet::ellipsef:
	case ToolSet::curve:
	case ToolSet::polygon:
	case ToolSet::pen:
//	case ToolSet::eraser:
		curStatus = Application::Status::Draw;
		break;
	case ToolSet::drager:
		curStatus = Application::Status::Drag;
		break;
	default:
		break;
	}


}
Manager * Application::getManager()
{
	return mManager;
}
void Application::display() {
	//清空画布


	glColor3f(1, 1, 1);

	glBegin(GL_QUADS);
	glVertex3f(0, 0, -10);
	glVertex3f(1129, 0, -10);
	glVertex3f(1129, 650, -10);
	glVertex3f(0, 650, -10);
	glEnd();

	world->show();
	window->draw();

	glFlush();
}
void Application::render()
{
	mLineWidthStatus = mWindow->getActiveLineWidth();
	glutDisplayFunc(display);
}

inline void Application::processUserInput()
{
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMotion);
}

inline void Application::getFeedback()
{
	mShapeStatus = mWindow->getActiveTool();
	mColorStatus = mWindow->getActiveColor();
}

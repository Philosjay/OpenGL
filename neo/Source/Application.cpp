#include "../Include/Application.h"

#include "../Include/World.h"
#include "../Include/Window.h"
#include "../Include/Botton.h"
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
#include "../Include/Polygon.h"
#include "../Include/settingList.h"


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

int mX0;
int mY0;

Application::Application()
	:  mGrab(NULL)
	, curStatus(End)
{
	world = new World;
	window = new Window(1280, 720, "test");

	mWorld = world;
	mWindow = window;
	grab = mGrab;
	app = this;
}
void Application::init() {
	glClearColor(1, 1, 1, 0);
}

void mouseButton(int button, int state, int x, int y)
{

	switch (button) {
	case GLUT_LEFT_BUTTON:
		switch (state) {
		case GLUT_DOWN:
			curPosX = x + 50;
			curPosY = 770 - y;
			mX0 = curPosX;
			mY0 = curPosY;


			window->update(curPosX, curPosY);
			endPosX = curPosX;
			endPosY = curPosY;
			printf("is in paper %d \n", window->isInPaper());
			if (window->isInPaper()) {
				//根据所选工具调用不同的方法
				switch (app->curStatus)
				{
				case Application::DrawSingle:
					//更新当前图形所需点击数量
					if (newGraph != NULL) {
						newGraph->requiredClicks--;
						newGraph->setEndPos(curPosX, curPosY);
					}

					if (newGraph == NULL) {
						newGraph = app->generateGraph(window->getActiveTool());
						if (newGraph != NULL) {
							newGraph->moveTo(curPosX, curPosY);
							newGraph->setColor(window->getActiveColor());
							newGraph->setLineWidth(window->getActiveLineWidth());
							newGraph->setEndPos(curPosX, curPosY);
							world->addGraph(newGraph);
							newGraph->requiredClicks--;
						}
					}

					break;
				case Application::Drag:
					grab = world->grab(curPosX, curPosY);
					break;
				case Application::DrawConstant:
					break;
				default:
					break;
				}
			}
			break;
		case GLUT_UP:
			if (window->isInPaper()) {
				if (newGraph != NULL) {
					if (newGraph->requiredClicks <= 0) {
						newGraph = NULL;
					}
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
void mouseMotion(int x, int y)
{
	//换算后的坐标
	endPosX = x + 50;
	endPosY = 770 - y;


//	window->update(endPosX, endPosY);

	switch (app->curStatus)
	{
	case Application::DrawSingle:
		if (window->isInPaper()) {
			if(newGraph!=NULL)
			newGraph->setEndPos(endPosX, endPosY);
		}
		break;
	case Application::DrawConstant:
		world->drawConstantGraph(mX0, mY0, endPosX, endPosY,
			window->getActiveTool(), window->getActiveColor(), window->getActiveLineWidth() + 1);
		mX0 = endPosX;
		mY0 = endPosY;
		break;
	case Application::Drag:
		//成功抓取图形，移动它
		if (grab != NULL) {
			int deltaX = endPosX - mX0;
			int deltaY = endPosY - mY0;
			grab->move(deltaX, deltaY);
			mX0 = endPosX;
			mY0 = endPosY;
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
		curStatus = Application::Status::DrawSingle;
		break;
	case ToolSet::drager:
		curStatus = Application::Status::Drag;
		break;
	case ToolSet::pen:
	case ToolSet::eraser:
		curStatus = Application::Status::DrawConstant;
		break;
	default:
		break;
	}


}
Graph * Application::generateGraph(int type)
{
	Graph* mTmp = NULL;
	switch (type)
	{
	case ToolSet::line:
		mTmp = new Line;
		break;
	case ToolSet::rect:
		mTmp = new Rect;
		break;
	case ToolSet::rectf:
		mTmp = new Rectf;
		break;
	case ToolSet::triangle:
		mTmp = new Triangle;
		break;
	case ToolSet::trianglef:
		mTmp = new Trianglef;
		break;
	case ToolSet::cirCle:
		mTmp = new Circle;
		break;
	case ToolSet::cirClef:
		mTmp = new Circlef;
		break;
	case ToolSet::ellipse:
		mTmp = new Ellipse_;
		break;
	case ToolSet::ellipsef:
		mTmp = new Ellipsef_;
		break;
	case ToolSet::eraser:
		mTmp = new Eraser;
		break;
	case ToolSet::pen:
		mTmp = new Pen;
		break;
	case ToolSet::curve:
		mTmp = new Bezier;
		break;
	case ToolSet::polygon:
		mTmp = new Polygon;
		break;
	default:
		break;
	}
	return mTmp;
}
void display() {
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

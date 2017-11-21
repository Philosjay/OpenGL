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


#include<iostream>

Window* window;
World*	world;
Graph*	grab;
Application* app;
Graph*	newGraph = NULL;

int curPosX, curPosY;
int motionPosX, motionPosY;

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
			motionPosX = curPosX;
			motionPosY = curPosY;
			printf("is in paper %d \n", window->isInPaper());
			if (window->isInPaper()) {
				//根据所选工具调用不同的方法
				switch (app->curStatus)
				{
				case Application::DrawSingle:
					if (newGraph == NULL) {
						newGraph = app->generateGraph(window->getActiveTool());
						if (newGraph != NULL) {
							newGraph->setOriginPos(curPosX, curPosY);
							newGraph->setColor(window->getActiveColor());
							newGraph->setLineWidth(window->getActiveLineWidth());
							newGraph->update(curPosX, curPosY);
							world->addGraph(newGraph);
						}
					}
					//更新当前图形所需点击数量
					if (newGraph != NULL) {
						newGraph->requiredClicks--;
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
	motionPosX = x + 50;
	motionPosY = 770 - y;


//	window->update(motionPosX, motionPosY);

	switch (app->curStatus)
	{
	case Application::DrawSingle:
		if (window->isInPaper()) {
			newGraph->update(motionPosX, motionPosY);
		}
		break;
	case Application::DrawConstant:
		world->drawConstantGraph(mX0, mY0, motionPosX, motionPosY,
			window->getActiveTool(), window->getActiveColor(), window->getActiveLineWidth() + 1);
		mX0 = motionPosX;
		mY0 = motionPosY;
		break;
	case Application::Drag:
		//成功抓取图形，移动它
		if (grab != NULL) {
			int deltaX = motionPosX - mX0;
			int deltaY = motionPosY - mY0;
			grab->move(deltaX, deltaY);
			
			mX0 = motionPosX;
			mY0 = motionPosY;
		}
		break;
	default:
		break;
	}

	printf("motion X %d Y %d\n", motionPosX, motionPosY);

	



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
	case SceneNode::Line:
	case SceneNode::Rect:
	case SceneNode::Rectf:
	case SceneNode::Triangle:
	case SceneNode::Trianglef:
	case SceneNode::CirCle:
	case SceneNode::CirClef:
	case SceneNode::Ellipse:
	case SceneNode::Ellipsef:
		curStatus = Application::Status::DrawSingle;
		break;
	case SceneNode::Brush:
		curStatus = Application::Status::Drag;
		break;
	case SceneNode::Pen:
	case SceneNode::Eraser:
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
	return mTmp;
}
void displayMenu() {
	window->draw();

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

#include "../Include/Painter.h"
#include "../Include/Application.h"
#include "../Include/World.h"
#include "../Include/Window.h"
#include "../Include/Graph.h"

#include <iostream>

Painter* Painter::mPainter = NULL;

Painter::Painter(Application * targetApp, Window * targetWindow, World * targetWorld)
	: window(targetWindow)
{

	app = targetApp;
	world = targetWorld;
	requiredClicks = 1;
	isStart = false;
	isEnd = false;

	mPainter = this;
}

Painter::Painter()
{
	requiredClicks = 1;
	isStart = false;
	isEnd = false;

	mPainter = this;
}

void Painter::quit()
{
	glutMouseFunc(mPainter->getTargetApp()->mouseButton);
	glutMotionFunc(mPainter->getTargetApp()->mouseMotion);
}

void Painter::update()
{
	glColor3f(1, 1, 1);

	glBegin(GL_QUADS);
	glVertex3f(0, 0, -10);
	glVertex3f(1129, 0, -10);
	glVertex3f(1129, 650, -10);
	glVertex3f(0, 650, -10);
	glEnd();

	mPainter->getTargetWorld()->show();
	mPainter->getTargetWindow()->draw();

	glFlush();
}


void Painter::start(int x, int y)
{	//接上App内被相应的鼠标左击

	mPainter->setCurPos(x, y);
	mPainter->setPrePos(x, y);
	mPainter->setEndPos(x, y);
	mPainter->getTargetWindow()->update(mPainter->getCurPosX(), mPainter->getCurPosY());


	mPainter->setStarted();
	mPainter->getTargetGraph()->moveTo(mPainter->getCurPosX(), mPainter->getCurPosY());
	mPainter->getTargetGraph()->setColor(mColor.r, mColor.g, mColor.b);
	mPainter->getTargetGraph()->setLineWidth(mPainter->getTargetWindow()->getActiveLineWidth());
	mPainter->getTargetGraph()->setEndPos(mPainter->getCurPosX(), mPainter->getCurPosY());
	mPainter->getTargetWorld()->addGraph(mPainter->getTargetGraph());
	mPainter->setClicked();
}

int Painter::drawConstantGraph(float x0, float y0, float x1, float y1,  float size)
{
	return 0;
}

Color Painter::getColor()
{
	return mColor;
}

void Painter::setPaintColor(Color color)
{
	mColor = color;
}

void Painter::setPaintLineWidth(int lineWidth)
{
	mLineWidth = lineWidth;
}

void Painter::setPaintGraph(Graph * graph)
{
	mGraph = graph;
}

void Painter::registerTargetWorld(World * world)
{
	this->world = world;
}

void Painter::registerTargetWindow(Window * window)
{
	this->window = window;
}

void Painter::registerTargetApplication(Application * app)
{
	this->app = app;
}

void Painter::setClicked()
{
	requiredClicks--;
}

void Painter::setStarted()
{
	isStart = true;
}

void Painter::setCurPos(int x, int y)
{
	curPosX = x; 
	curPosY = y;
}

void Painter::setPrePos(int x, int y)
{
	prePosX = x;
	prePosY = y;
}

void Painter::setEndPos(int x, int y)
{
	endPosX = x;
	endPosY = y;
}

void Painter::setId(int id)
{
	this->id = id;
}

int Painter::getId()
{
	return id;
}

int Painter::getCurPosX()
{
	return curPosX;
}
int Painter::getCurPosY()
{
	return curPosY;
}
int Painter::getPrePosX()
{
	return prePosX;
}
int Painter::getEndPosY()
{
	return endPosY;
}
int Painter::getEndPosX()
{
	return endPosX;
}
int Painter::getPrePosY()
{
	return prePosY;
}
int Painter::getRequiredClicks()
{
	return requiredClicks;
}

bool Painter::isStarted()
{
	return isStart;
}

Graph * Painter::getTargetGraph()
{
	return mGraph;
}

Window * Painter::getTargetWindow()
{
	return window;
}

Application * Painter::getTargetApp()
{
	return app;
}

World * Painter::getTargetWorld()
{
	return world;
}

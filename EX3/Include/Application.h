#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <GL/glut.h>
#include <time.h>


#include "World.h"
#include "Window.h"

Window* window;
World*	world;

int curPosX, curPosY;
int motionPosX, motionPosY;

int mShapeStatus;
int mLineWidthStatus;
int mColorStatus;

void display();


class Application
{
public:
	Application();

	void	init();
	void	run();
	void	update(); 

private:
	enum ToolStatus
	{
		None,
		Pen,
		Zoom,
		Brush,
		Eraser,
	};
	enum ShapeStatus
	{
		Line,
		Curve,
		Triangle,
		CirCle,
		Ellipse,
		Rect,
		Linef,
		Curvef,
		Trianglef,
		CirClef,
		Ellipsef,
		Rectf,
	};
	enum LineWidth
	{
		Width1,
		Width2,
		Width3,
		Width4,
	};
	enum ColorStatus
	{
		Red,
		Green,
		Blue,
		White,
		Black,
		Grey,
		Yellow,

	};

	void	render();
	void	processUserInput();
	void	getFeedback();

	bool	isPreviewing;
	World*	mWorld;
	Window*	mWindow;
};


Application::Application() 
	: isPreviewing(false)
{
	world = new World;
	window = new Window(1280, 720, "test");

	mWorld = world;
	mWindow = window;
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
			window->update(curPosX, curPosY);
			motionPosX = curPosX;
			motionPosY = curPosY;
			printf("is in paper %d \n", window->isInPaper());
			if (window->isInPaper()) {
 				world->previewGraph(window->getActiveTool(), window->getActiveColor(), window->getActiveLineWidth(),
					curPosX, curPosY, motionPosX, motionPosY);
			}

			break;
		case GLUT_UP:
			if (window->isInPaper()) {
				world->saveGraph();
			}
	
			break;
		}
		break;
	case GLUT_MIDDLE_BUTTON:
		
		break;
	}

	printf("Curpos X %d Y %d\n", curPosX, curPosY);

}
void mouseMotion(int x, int y)
{
	
	motionPosX= x + 50;
	motionPosY= 770 - y;
//	window->update(curPosX, curPosY);
	if(window->isInPaper())
	world->previewGraph(window->getActiveTool(), window->getActiveColor(), window->getActiveLineWidth(),
						curPosX, curPosY, motionPosX, motionPosY);
	printf("motion X %d Y %d\n", motionPosX, motionPosY);

	display();
}

void Application::run() {

	clock_t start, finish;
	float	deltaTime = 0.0;
//	while (true)
	{
		processUserInput();
		mWindow->update(curPosX,curPosY);
		getFeedback();
		this->render();
		glutMainLoop();

	}



	
}
void Application::update() {

}
void displayMenu() {
	window->draw();

}
void display() {
	//Çå¿Õ»­²¼

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




#endif // !APPLICATION_H_
#pragma once

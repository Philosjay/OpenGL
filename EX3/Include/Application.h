#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <GL/glut.h>
#include <time.h>


#include "World.h"
#include "Window.h"

Window* window;
World*	world;

int curPosX, curPosY;

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

	int		mToolStatus, mShapeStatus, mLineWidthStatus, mColorStatus;
	World*	mWorld;
	Window*	mWindow;
};


Application::Application() {
	world = new World;
	window = new Window(1280, 720, "test");

	mWorld = world;
	mWindow = window;
}
void Application::init() {

}

void mouseButton(int button, int state, int x, int y)
{
	curPosX = x + 50;
	curPosY = 770-y;
	printf("X %d Y %d\n", curPosX, curPosY);


	window->update(curPosX, curPosY);
/*
	switch (button) {
	case GLUT_LEFT_BUTTON:
		trackballXform = (GLfloat*)objectXform;
		break;
	case GLUT_MIDDLE_BUTTON:
		trackballXform = (GLfloat*)lightXform;
		break;
	}
	switch (state) {
	case GLUT_DOWN:
		startMotion(0, 1, x, y);
		break;
	case GLUT_UP:
		stopMotion(0, 1, x, y);
		break;
	}
*/
}

void Application::run() {

	clock_t start, finish;
	float	deltaTime = 0.0;
//	while (true)
	{
		glutMouseFunc(mouseButton);
		mWindow->update(curPosX,curPosY);
		this->render();
		glutMainLoop();

/*
		//帧数控制，但没有实际作用
		start = clock();

		while (deltaTime>=1.0/60.0)
		{
			deltaTime -= 1.0/60.0 ;

			mWindow->update();
			this->render();
			glutMainLoop();
	
		}

		finish = clock();
		deltaTime += (((float)finish - (float)start)/1000);
*/

	}



	
}
void Application::update() {

}
void display() {
	window->draw();
}
void Application::render()
{
	glutDisplayFunc(display);
}




#endif // !APPLICATION_H_
#pragma once

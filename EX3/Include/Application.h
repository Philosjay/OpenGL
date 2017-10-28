#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <GL/glut.h>
#include <time.h>


#include "World.h"
#include "Window.h"

Window* window;
World*	world;

class Application
{
public:
	Application();

	void	init();
	void	run();
	void	update(); 

private:
	void	render();

	World*	mWorld;
	Window*	mWindow;
};


Application::Application() {
	world = new World;
	window = new Window(1280, 720, "test");

//	mWorld = world;
//	mWindow = window;
}
void Application::init() {

}

void Application::run() {

	clock_t start, finish;
	float	deltaTime = 0.0;
	while (true)
	{
		mWindow->update();
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

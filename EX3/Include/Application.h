#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <GL/glut.h>

#include "World.h"
#include "Window.h"

class Application
{
public:
	Application();

	void	init();
	void	run();
	void	update(); 

private:
	World*	mWorld;
	Window*	mWindow;
};


Application::Application() {
	mWorld = new World;
	mWindow = new Window(600, 600, "test");
}
void Application::init() {

}

void Application::run() {
	mWindow->update();
	mWindow->render();
	glutMainLoop();
}
void Application::update() {

}

#endif // !APPLICATION_H_
#pragma once

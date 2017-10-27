#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <GL/glut.h>

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
	mWindow->update();
	
	this->render();
	glutMainLoop();
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

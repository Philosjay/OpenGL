#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <GL/glut.h>
#include <time.h>


class Window;
class World;
class Graph;
class Painter;
class Manager;

class Application;

class Application
{
public:
	enum Status
	{
		End,
		Draw,
		Drag,
	};
	Application();
	
	void	init();
	void	run();
	void	updateStatus(int n);
	int		curStatus;

	static	void mouseButton(int button, int state, int x, int y);
	static	void mouseMotion(int x, int y);
private:
	Manager* getManager();
	static	void display();
	void	render();
	void	processUserInput();
	void	getFeedback();
	
	World*				mWorld;
	Window*				mWindow;
	Graph*				mGrab;
	Manager*			mManager;

	//�൱��this
	static	Application* mApp;
};





#endif // !APPLICATION_H_
#pragma once

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
		Idle,
		Draw,
		Drag,
		Save,
		Load,
		New,
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
	static	void		newPaper();
	static	void		save(const char* fileName);
	static	void		load(const char* fileName);
	World*				mWorld;
	Window*				mWindow;
	Graph*				mGrab;
	Manager*			mManager;

	//Ïàµ±ÓÚthis
	static	Application* mApp;
};





#endif // !APPLICATION_H_
#pragma once

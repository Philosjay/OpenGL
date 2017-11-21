#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <GL/glut.h>
#include <time.h>


class Window;
class World;
class Graph;
void display();


class Application
{
public:
	enum Status
	{
		End,
		DrawSingle,
		DrawConstant,
		Drag,
	};
	Application();

	void	init();
	void	run();
	void	updateStatus(int n);
	int		curStatus;
	Graph*	generateGraph(int type);
private:


	void	render();
	void	processUserInput();
	void	getFeedback();

	World*	mWorld;
	Window*	mWindow;
	Graph*	mGrab;


	
};





#endif // !APPLICATION_H_
#pragma once

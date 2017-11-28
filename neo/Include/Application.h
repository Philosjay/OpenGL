#ifndef APPLICATION_H_
#define APPLICATION_H_

#include <GL/glut.h>
#include <time.h>


class Window;
class World;
class Graph;
class Painter;

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
	Graph*		generateGraph(int type);
	Painter*	generatePainter(int type);

	static	void mouseButton(int button, int state, int x, int y);
	static	void mouseMotion(int x, int y);
private:

	static	void display();
	void	render();
	void	processUserInput();
	void	getFeedback();

	World*	mWorld;
	Window*	mWindow;
	Graph*	mGrab;


	
};





#endif // !APPLICATION_H_
#pragma once

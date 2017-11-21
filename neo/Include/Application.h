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
	Graph*	mGrab;
};





#endif // !APPLICATION_H_
#pragma once

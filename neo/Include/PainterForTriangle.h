#ifndef PAINTERFORTRIANGLE_H_
#define PAINTERFORTRIANGLE_H_

#include "Painter.h"

class Window;
class World;
class Application;

class PainterForTriangle : public Painter {
private:
	static	void mouseButton(int button, int state, int x, int y);
	static	void mouseMotion(int x, int y);

public:
	PainterForTriangle(Application* targetApp, Window* targetWindow, World* targetWorld);
	PainterForTriangle();
	void	paint(int x, int y);
	void	start(int x, int y);
};

#endif // !PAINTERFORTRIANGLE_H_
#pragma once

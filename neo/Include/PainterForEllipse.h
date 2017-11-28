#ifndef PAINTERFORELLIPSE_H_
#define PAINTERFORELLIPSE_H_

#include "Painter.h"

class Window;
class World;
class Application;

class PainterForEllipse : public Painter {
private:
	static	void mouseButton(int button, int state, int x, int y);
	static	void mouseMotion(int x, int y);

public:
	PainterForEllipse(Application* targetApp, Window* targetWindow, World* targetWorld);
	void	paint(int x, int y);
	void	start(int x, int y);
	void	setRadiusA(float r);
	void	setRadiusB(float r);
};

#endif // !PAINTERFORELLIPSE_H_
#pragma once

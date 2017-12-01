#ifndef PAINTERFORPEN_H_
#define PAINTERFORPEN_H_

#include "Painter.h"

class Window;
class World;
class Application;

class PainterForPen : public Painter {
public:
	PainterForPen(Application * targetApp, Window * targetWindow, World * targetWorld);
	PainterForPen();
private:
	static	void mouseButton(int button, int state, int x, int y);
	static	void mouseMotion(int x, int y);
	int	 drawConstantGraph(float x0, float y0, float x1, float y1, float color, float size);
public:
	void paint(int x, int y);
	void start(int x, int y);
};

#endif // !PAINTERFORPEN_H_
#pragma once

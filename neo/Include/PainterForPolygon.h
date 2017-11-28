#ifndef PAINTERFORPOLYGON_H_
#define PAINTERFORPOLYGON_H_

#include "Painter.h"

class Window;
class World;
class Application;

class PainterForPolygon : public Painter {
private:
	static	void mouseButton(int button, int state, int x, int y);
	static	void mouseMotion(int x, int y);
public:
	PainterForPolygon(Application* targetApp, Window* targetWindow, World* targetWorld);

	void paint(int x, int y);
	void start(int x, int y);
};

#endif // !PAINTERFORPOLYGON_H_
#pragma once

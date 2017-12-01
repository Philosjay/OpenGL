#ifndef PAINTERFORCIRCLE_H_
#define PAINTERFORCIRCLE_H_

#include "Painter.h"

class Window;
class World;
class Application;

class PainterForCircle : public Painter
{
private:
	static	void mouseButton(int button, int state, int x, int y);
	static	void mouseMotion(int x, int y);

public:
	PainterForCircle(Application* targetApp, Window* targetWindow, World* targetWorld);
	PainterForCircle();
	void paint(int x, int y);
	void start(int x, int y);
};

#endif // !PAINTERFORCIRCLE_H_
#pragma once

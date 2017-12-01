#ifndef PAINTERFORRECT_H_
#define PAINTERFORRECT_H_

class Window;
class World;
class Application;

#include "Painter.h"

class PainterForRect : public Painter {
private:
	static	void mouseButton(int button, int state, int x, int y);
	static	void mouseMotion(int x, int y);

public:
	PainterForRect(Application* targetApp, Window* targetWindow, World* targetWorld);
	PainterForRect();
	void	paint(int x, int y);
	void	start(int x, int y);

};

#endif // !PAINTERFORRECT_H_
#pragma once

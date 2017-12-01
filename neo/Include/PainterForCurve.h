#ifndef PAINTERFORCURVE_H_
#define PAINTERFORCURVE_H_

#include "Painter.h"

class Window;
class World;
class Application;


class PainterForCurve : public Painter {
private:
	static	void mouseButton(int button, int state, int x, int y);
	static	void mouseMotion(int x, int y);
public:
	PainterForCurve(Application* targetApp, Window* targetWindow, World* targetWorld);
	PainterForCurve();
	void paint(int x, int y);
	void start(int x, int y);


};

#endif // !PAINTERFORCURVE_H_
#pragma once

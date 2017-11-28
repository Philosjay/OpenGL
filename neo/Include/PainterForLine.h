#ifndef PAINTERFORLINE_H_
#define PAINTERFORLINE_H_

#include "Painter.h"

class Window;
class World;
class Application;

class PainterForLine : public Painter{
private:
	static	void mouseButton(int button, int state, int x, int y);
	static	void mouseMotion(int x, int y);
	
public:
	PainterForLine(Application* targetApp, Window* targetWindow, World* targetWorld);
	void paint(int x, int y);



};




#endif // !PAINTERFORLINE_H_
#pragma once

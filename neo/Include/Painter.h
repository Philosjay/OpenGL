#ifndef PAINTER_H_
#define PAINTER_H_


#include <gl/glut.h>

class Graph;
class Window;
class World;
class Application;


class Painter {
public:
	
	Painter(Application* targetApp, Window* targetWindow, World* targetWorld);
	virtual void paint(int x,int y) {
		//do nothing by default
	}
	void quit();
	void update();
	void setPaintColor(int color);
	void setPaintLineWidth(int lineWidth);
	void setPaintGraph(Graph* graph);
	void			setClicked();
	void			setStarted();
	void		setCurPos(int x, int y);
	void		setPrePos(int x, int y);
	void		setEndPos(int x, int y);
	int			getCurPosX();
	int			getCurPosY();
	int			getPrePosY();
	int			getPrePosX();
	int			getEndPosY();
	int			getEndPosX();
	int				getRequiredClicks();
	bool			isStarted();
	Graph*			getTargetGraph();
	Window*			getTargetWindow();
	Application*	getTargetApp();
	World*			getTargetWorld();

	virtual void start(int x, int y);

private:

	
protected:
	static Painter* mPainter;

	Application * app;
	Window* window;
	World*	world;
	Graph*		mGraph;
	int			mColor;
	int			mLineWidth;
	
	bool	isStart;
	bool	isEnd;
	int	requiredClicks;

	int curPosX;
	int curPosY;
	int endPosX;
	int endPosY;

	int prePosX;
	int prePosY;
};

#endif // !PAINTER_H_
#pragma once

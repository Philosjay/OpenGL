#ifndef PAINTER_H_
#define PAINTER_H_


#include <gl/glut.h>
#include "SceneNode.h"

class Graph;
class Window;
class World;
class Application;


class Painter {
public:
	
	Painter(Application* targetApp, Window* targetWindow, World* targetWorld);
	Painter();
	virtual void paint(int x,int y) {
		//do nothing by default
	}
	void quit();
	void update();
	void setPaintColor(Color color);
	void setPaintLineWidth(int lineWidth);
	void setPaintGraph(Graph* graph);
	void registerTargetWorld(World* world);
	void registerTargetWindow(Window* world);
	void registerTargetApplication(Application* app);
	void			setClicked();
	void			setStarted();
	void		setCurPos(int x, int y);
	void		setPrePos(int x, int y);
	void		setEndPos(int x, int y);
	void		setId(int id);
	int			getId();
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
	Color getColor();
	virtual void start(int x, int y);
	virtual int	 drawConstantGraph(float x0, float y0, float x1, float y1, float size);
private:
	
	
protected:
	
	static Painter* mPainter;

	Application * app;
	Window* window;
	World*	world;
	Graph*		mGraph;
	Color mColor;
	int			mLineWidth;
	
	bool	isStart;
	bool	isEnd;
	int	requiredClicks;
	int	id;

	int curPosX;
	int curPosY;
	int endPosX;
	int endPosY;

	int prePosX;
	int prePosY;
};

#endif // !PAINTER_H_
#pragma once

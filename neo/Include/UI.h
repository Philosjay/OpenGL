#ifndef UI_H_
#define UI_H_


class Botton;
class Graph;
class Manager;

class UI {

public:
	UI(Manager* mng);
	
	void	processInput(int x,int y);
	void	show();
	int		getLastActiveTool() {return lastActiveKey[0]; }
	int		getLastActiveLineWidth() { return lastActiveLineWidth+1; }
	int		getLastActiveColor() { return lastActiveColor; }
	bool	isDrawing() { return isdrawing; };
private:
	//有效键位的哈希值
	int lastActiveKey[10] = {0,0,0,0,0,0,0,0,0,0};
	//有效键位的储存索引值
	int lastActiveIndex[10] = { 0,0,0,0,0,0,0,0,0,0 };
	int lastActiveLineWidth = 0;
	int lastActiveColor = 0;
	bool	isdrawing;

	Graph*	mBackground[10];
	Botton*	mToolBottons[100];
	Botton*	mLineWidthBottons[100];
	Botton*	mColorBottons[100];
	Botton*	mMenuBottons[100];
	Manager* mManager;
	int			backgroundCount;

	void	init();
	void	background();
	void	widgets();
	void	addBackground(Graph * widet);
};


#endif // !UI_H_
#pragma once

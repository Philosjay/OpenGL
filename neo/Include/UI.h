#ifndef UI_H_
#define UI_H_


class Botton;
class Graph;

class UI {

public:
	UI();

	void	processInput(int x,int y);
	void	show();
	int		getLastActiveTool() {return lastActiveTool; }
	int		getLastActiveLineWidth() { return lastActiveLineWidth+1; }
	int		getLastActiveColor() { return lastActiveColor; }
	bool	isDrawing() { return isdrawing; };
private:
	int lastActiveTool = 0;
	int lastActiveLineWidth = 0;
	int lastActiveColor = 0;
	bool	isdrawing;

	Graph*	mBackground[10];
	Graph*	mToolBottons[100];
	Graph*	mLineWidthBottons[100];
	Graph*	mColorBottons[100];
	Graph*	mMenuBottons[100];
	int			backgroundCount;

	void	init();
	void	background();
	void	widgets();
	void	addBackground(Graph * widet);
};


#endif // !UI_H_
#pragma once

#ifndef UI_H_
#define UI_H_


class Botton;
class SceneNode;

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

	SceneNode*	mBackground[10];
	SceneNode*	mToolBottons[100];
	SceneNode*	mLineWidthBottons[100];
	SceneNode*	mColorBottons[100];
	SceneNode*	mMenuBottons[100];
	int			backgroundCount;

	void	init();
	void	background();
	void	widgets();
	void	addBackground(SceneNode * widet);
};


#endif // !UI_H_
#pragma once

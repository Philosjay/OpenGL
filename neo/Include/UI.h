#ifndef UI_H_
#define UI_H_

#include "SceneNode.h"

class Botton;
class Graph;
class Manager;

class UI {

public:
	UI(Manager* mng);
	
	void	processInput(int x,int y);
	void	show();
	int		getStatus();
	int		getActiveTool();
	int		getLastActiveLineWidth();
	Color		getLastActiveColor();
	bool	isDrawing() { return isdrawing; };
private:
	//��Ч��λ�Ĺ�ϣֵ,0�ǹ���Ⱥ��1���߿�Ⱥ��2����ɫȺ��3�ǲ˵�Ⱥ
	int lastActiveKey[10] = {0,0,0,-1,0,0,0,0,0,0};
	//��Ч��λ�Ĵ�������ֵ
	int lastActiveLineWidth = 0;
	int lastActiveColor = 0;
	bool	isdrawing;
	bool	isSaving;
	bool	isLoading;

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

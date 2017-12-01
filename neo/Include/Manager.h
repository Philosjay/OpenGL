#ifndef MANAGER_H_
#define MANAGER_H_

#include <vector>

using namespace std;

class Graph;
class Painter;
class Window;
class World;
class Application;
class Botton;
class Factory_Btn;

class Manager {
public:

	enum GraphSet
	{
		pen,
		eraser,
		line,
		curve,
		triangle,
		circle,
		ellipse,
		rect,
		trianglef,
		circlef,
		ellipsef,
		rectf,
		polygon,

		graphCount,
	};
	enum PainterSet
	{
		Ppen,
		Peraser,
		Pline,
		Pcurve,
		Ptriangle,
		Pcircle,
		Pellipse,
		Prect,
		Ppolygon,

		painterCount,
	};
	
	enum BtnGroup1
	{
		Bpen,
		Bzoom,
		Bdrager,
		Beraser,
		Bline,
		Bcurve,
		Btriangle,
		Bcircle,
		Bellipse,
		Brect,
		Btrianglef,
		Bcirclef,
		Bellipsef,
		Brectf,
		Bpolygon,

		BtnGroup1Count,
		groupNum = 1
	};

	enum BtnGroup2
	{
		

		BtnGroup2Count,
	};

	enum BtnGroup3
	{
		Width1,
		Width2,
		Width3,
		Width4,

		BtnGroup3Count,
	};

	enum BtnGroup4
	{
		Red,
		Green,
		Blue,
		Yellow,
		Orange,
		White,
		Black,
		Purple,
		Grey,
		Grey2,

		BtnGroup4Count,
	};
	enum BtnGroup5
	{
		Save,
		Help,

		BtnGroup5Count,
	};


	Manager();
	Manager(Application* targetApp, Window* targetWindow, World* targetWorld);
	Graph*		generateGraph(int type);
	Painter*	generatePainter(int type);
	Botton*		generateBotton(int type,int groupNum);


	vector<Factory_Btn*>		botton_group_factory_List[10];
	vector<Botton*>		bottonList2;
	vector<Botton*>		bottonList3;
private:
	
	Window*			targetWindow;
	World*			targetWorld;
	Application*	targetApp;


};

#endif // !MANAGER_H_
#pragma once

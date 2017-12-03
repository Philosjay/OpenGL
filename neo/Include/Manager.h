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
class Factory;
class Storer;

class Manager {
public:

	Manager();
	Manager(Application* targetApp, Window* targetWindow, World* targetWorld);
	Graph*		getGraph(int id);
	Painter*	getPainter(int id);
//	Botton*		generateBotton(int type,int groupNum);

	Storer*		getStorer(int id);
	//0�ż�¼���������1�ż�¼�߿������2�ż�¼��ɫ���
	vector<Factory*>		Factory_List[10];
private:
	
	Window*			targetWindow;
	World*			targetWorld;
	Application*	targetApp;


};

#endif // !MANAGER_H_
#pragma once

#include "../Include/Application.h"

#include "../Include/World.h"
#include "../Include/Window.h"
#include "../Include/Botton.h"
#include "../Include/Graph.h"
#include "../Include/Painter.h"
#include "../Include/Storer.h"

#include "../Include/Manager.h"

#include<iostream>


Window* window;
World*	world;
Graph*	grab;
Application* app;
Graph*	newGraph = NULL;

int curPosX, curPosY;
int endPosX, endPosY;

int mShapeStatus;
int mLineWidthStatus;
int mColorStatus;

int prePosX;
int prePosY;

Application::Application()
	:  mGrab(NULL)
	, curStatus(Idle)
{
	world = new World;
	window = new Window(1280, 720, "test");
	mManager = new Manager(this,window,world);
	window->registerManager(mManager);

	mWorld = world;
	mWindow = window;
	grab = mGrab;
	app = this;
}
void Application::init() {
	glClearColor(1, 1, 1, 0);
}

void Application::mouseButton(int button, int state, int x, int y)
{
	Painter* painter = NULL; 

	switch (button) {
	case GLUT_LEFT_BUTTON:
		switch (state) {
		case GLUT_DOWN:
			curPosX = x + 50;
			curPosY = 770 - y;
			prePosX = curPosX;
			prePosY = curPosY;


			window->update(curPosX, curPosY);
			app->updateStatus(window->getStatus());

			endPosX = curPosX;
			endPosY = curPosY;
			printf("is in paper %d \n", window->isInPaper());
			//根据所选工具调用不同的方法
			switch (app->curStatus)
			{
			case Application::Draw:
				//更新当前图形所需点击数量
				if (window->isInPaper()) {
					newGraph = app->getManager()->getGraph(window->getActiveTool());
					painter = app->getManager()->getPainter(window->getActiveTool());
					if (painter != NULL) {
						painter->registerTargetApplication(app);
						painter->registerTargetWindow(window);
						painter->registerTargetWorld(world);
						painter->setPaintColor(window->getActiveColor());		//rgb值
						painter->setPaintLineWidth(window->getActiveLineWidth());
						painter->setPaintGraph(newGraph);
						painter->paint(curPosX, curPosY);
					}
				}
				break;
			case Application::Drag:
				grab = world->grab(curPosX, curPosY);
				break;
			case Application::Save:
				save("data.txt");
				break;
			case Application::Load:
				load("data.txt");
				break;
			case Application::New:
				newPaper();
				break;
			case Application::Idle:
				break;
			default:
				break;
			}
			break;
		case GLUT_UP:
			if (window->isInPaper()) {
			}
			grab = NULL;
			break;
		}
		break;
	case GLUT_RIGHT_BUTTON:
		switch (state)
		{
		case GLUT_DOWN:
			//点击右键结束绘图
			newGraph = NULL;
			break;
		default:
			break;
		}

		break;
	case GLUT_MIDDLE_BUTTON:

		break;
	}


	
	display();
	printf("Curpos X %d Y %d\n", curPosX, curPosY);

}
void Application::mouseMotion(int x, int y)
{
	//换算后的坐标
	endPosX = x + 50;
	endPosY = 770 - y;


//	window->update(endPosX, endPosY);

	switch (app->curStatus)
	{
	case Application::Draw:
		if (window->isInPaper()) {
			if(newGraph!=NULL)
			newGraph->setEndPos(endPosX, endPosY);
		}
		break;
	case Application::Drag:
		//成功抓取图形，移动它
		if (grab != NULL) {
			if (window->isInPaper()) {
				int deltaX = endPosX - prePosX;
				int deltaY = endPosY - prePosY;
				grab->move(deltaX, deltaY);
				prePosX = endPosX;
				prePosY = endPosY;
			}
		}
		break;
	default:
		break;
	}

	printf("motion X %d Y %d\n", endPosX, endPosY);

	



	//更新当前操作状态
	display();
}

void Application::run() {

	processUserInput();
	mWindow->update(curPosX, curPosY);
	app->updateStatus(window->getStatus());
	this->render();
	glutMainLoop();
}
void Application::updateStatus(int n)
{
	//对应工具按键被赋予的值
	switch (n)
	{
	case 0:
		curStatus = Application::Status::Draw;
		break;
	case 1:
		curStatus = Application::Status::Drag;
		break;
	case 2:
		curStatus = Application::Save;
		break;
	case 3:
		curStatus = Application::Load;
		break;
	case 4:
		curStatus = Application::New;
		break;
	case -1:
		curStatus = Application::Idle;
	default:
		break;
	}


}
Manager * Application::getManager()
{
	return mManager;
}
void Application::display() {
	//清空画布


	glColor3f(1, 1, 1);

	glBegin(GL_QUADS);
	glVertex3f(0, 0, -10);
	glVertex3f(1129, 0, -10);
	glVertex3f(1129, 650, -10);
	glVertex3f(0, 650, -10);
	glEnd();

	world->show();
	window->draw();

	glFlush();
}
void Application::render()
{
	mLineWidthStatus = mWindow->getActiveLineWidth();
	glutDisplayFunc(display);
}

inline void Application::processUserInput()
{
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMotion);
}

void Application::newPaper()
{
	world->removeAllGraphs();
}

void Application::save(const char* fileName)
{
	ofstream f(fileName,ios::out);

	Storer* storer = NULL;
	for (int i = 0; i < world->getTotalGraphCount(); i++) {
		int id = world->getGraph(i)->getId();
		storer = app->getManager()->getStorer(id);
		if (storer != NULL) {
			storer->save(world->getGraph(i), f);
		}
	}

	f.close();
}

void Application::load(const char * fileName)
{

	world->removeAllGraphs();

	ifstream fin(fileName, ios::in);
	if (fin.peek() == EOF) {
		return;
	}
	int id;
	char marker_start;
	char marker_end;
	while (!fin.eof()){
		fin >> marker_start;
		while (marker_start != '@') {
			fin >> marker_start;
		}

		fin >> id;
		Storer* storer = NULL;
		storer = app->getManager()->getStorer(id);
		if (storer != NULL) {
			world->addGraph(storer->load(id, fin));
		}
		//如果文件流有误，则中断
		fin >> marker_end;
		while (marker_end != '#'){
			fin >> marker_end;
		}
	}


	fin.close();
}

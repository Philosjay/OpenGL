#ifndef WINDOW_H_
#define WINDOW_H_

#include <GL/glut.h>

#include "UI.h"

//透视参数
GLfloat xwMin = 0, ywMin = 0, xwMax = 1280, ywMax = 720;
GLfloat dnear = 25, dfar = 125;



class Window
{
public:
	Window(int width, int height, char* title);
	void	update(int x,int y);
	void	draw();
	bool	isInPaper() { return mUI->isDrawing(); }
	int		getActiveTool() { return mUI->getLastActiveTool(); }
	int		getActiveLineWidth() { return mUI->getLastActiveLineWidth(); }
	int		getActiveColor() { return mUI->getLastActiveColor();
	}



private:
	static void  reshape(int w, int h);
	void		init();

	UI*			mUI;


};
void drawSceneNode(SceneNode* );

Window::Window(int width, int height, char* title)
{
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutCreateWindow("test");

	xwMax = width;
	ywMax = height;
	gluLookAt(50, 50, 50, 50, 50, 0, 0, 1, 0);
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	glMatrixMode(GL_PROJECTION);

	init();

}

void Window::update(int x,int y) {

	mUI->processInput(x, y);
	glutReshapeFunc(reshape);
}

void Window::draw()
{
//	glClear(GL_COLOR_BUFFER_BIT);
	mUI->show();
	
}

inline void Window::reshape(int w, int h)
{
	glViewport(0, 0, w, h);			//重置画面中心，和一下两个 glMatrixMode()照应使用

	glLoadIdentity();

	if (w <= (h + xwMax - ywMax))
		glOrtho(xwMin, xwMax, ywMin*(GLfloat)(h + xwMax - ywMax) / (GLfloat)w, ywMax*(GLfloat)(h + xwMax - ywMax) / (GLfloat)w, dnear, dfar);
	else
		glOrtho(xwMin*(GLfloat)w / (GLfloat)(h + xwMax - ywMax), xwMax*(GLfloat)w / (GLfloat)(h + xwMax - ywMax), ywMin, ywMax, dnear, dfar);
}

void Window::init()
{
	mUI = new UI;


}

#endif // !WINDOW_H_


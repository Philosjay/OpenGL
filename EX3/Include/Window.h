#ifndef WINDOW_H_
#define WINDOW_H_

#include <GL/glut.h>

#include "SceneNode.h"

//透视参数
GLfloat xwMin = 0, ywMin = 0, xwMax = 1280, ywMax = 720;
GLfloat dnear = 25, dfar = 125;

class Window
{
public:
	Window(int width, int height, char* title);
	void	update();
	void	draw();
private:

	static void  reshape(int w, int h);
	void		init();
	void		addWidget(SceneNode* widet);

	SceneNode*	mWidgets[100];
	int			widgetCount;

};
void drawSceneNode(SceneNode* );

Window::Window(int width, int height, char* title):
	widgetCount(0)
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

void Window::update() {
	glutReshapeFunc(reshape);
}

void Window::draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < widgetCount; i++) {
		mWidgets[i]->draw();
	}

	glFlush();
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
	SceneNode* tmp = new SceneNode;
	tmp->setColor(SceneNode::Color::Black);
	tmp->setType(SceneNode::Type::Rect);
	tmp->setPos(100, 100);
	tmp->setSize(300, 500);
	addWidget(tmp);

	tmp = new SceneNode;
	tmp->setColor(SceneNode::Color::Black);
	tmp->setType(SceneNode::Type::Rect);
	tmp->setPos(500, 100);
	tmp->setSize(300, 500);
	addWidget(tmp);

}

inline void Window::addWidget(SceneNode * widet)
{
	mWidgets[widgetCount++]=widet;
}



#endif // !WINDOW_H_


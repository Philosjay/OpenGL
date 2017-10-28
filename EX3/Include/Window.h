#ifndef WINDOW_H_
#define WINDOW_H_

#include <GL/glut.h>

#include "Widget.h"
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
	void		background();
	void		widgets();


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
	background();
	widgets();




}

inline void Window::addWidget(SceneNode * widet)
{
	mWidgets[widgetCount++]=widet;
}

inline void Window::background()
{
	SceneNode* tmp = new SceneNode;
	tmp->setColor(SceneNode::Color::Grey);
	tmp->setType(SceneNode::Type::Rect);
	tmp->setSize(1330, 110);
	tmp->setPos(0, 650);
	addWidget(tmp);

	tmp = new SceneNode;
	tmp->setColor(SceneNode::Color::Grey);
	tmp->setType(SceneNode::Type::Rect);
	tmp->setSize(200, 650);
	tmp->setPos(1130, 0);
	addWidget(tmp);
}

inline void Window::widgets()
{
	Widget* widet = new Widget;
	widet->setSize(150, 100);
	widet->setPos(60, 655);
	addWidget(widet);

	widet = new Widget;
	widet->setSize(150, 100);
	widet->setPos(210, 655);
	addWidget(widet);

	widet = new Widget;
	widet->setSize(150, 100);
	widet->setPos(360, 655);
	addWidget(widet);

	//填充
	widet = new Widget;
	widet->setSize(100, 80);
	widet->setPos(1130, 650);
	addWidget(widet);
	//橡皮
	widet = new Widget;
	widet->setSize(100, 80);
	widet->setPos(1230, 650);
	addWidget(widet);
	//放大镜
	widet = new Widget;
	widet->setSize(100, 80);
	widet->setPos(1030, 650);
	addWidget(widet);
	//画笔
	widet = new Widget;
	widet->setSize(100, 80);
	widet->setPos(930, 650);
	addWidget(widet);
	//工具栏
	widet = new Widget;
	widet->setSize(400, 30);
	widet->setPos(930, 730);
	addWidget(widet);

	//形状栏
	widet = new Widget;
	widet->setSize(120, 30);
	widet->setPos(1170, 600);
	addWidget(widet);
	//直线
	widet = new Widget;
	widet->setSize(60, 30);
	widet->setPos(1170, 570);
	addWidget(widet);
	//曲线
	widet = new Widget;
	widet->setSize(60, 30);
	widet->setPos(1230, 570);
	addWidget(widet);
	//三角形
	widet = new Widget;
	widet->setSize(60, 30);
	widet->setPos(1170, 540);
	addWidget(widet);
	//三角形实
	widet = new Widget;
	widet->setSize(60, 30);
	widet->setPos(1230, 540);
	addWidget(widet);
	//圆形
	widet = new Widget;
	widet->setSize(60, 30);
	widet->setPos(1170, 510);
	addWidget(widet);
	//圆形实
	widet = new Widget;
	widet->setSize(60, 30);
	widet->setPos(1230, 510);
	addWidget(widet);
	//椭圆形
	widet = new Widget;
	widet->setSize(60, 30);
	widet->setPos(1170, 480);
	addWidget(widet);
	//椭圆形实
	widet = new Widget;
	widet->setSize(60, 30);
	widet->setPos(1230, 480);
	addWidget(widet);
	//矩形
	widet = new Widget;
	widet->setSize(60, 30);
	widet->setPos(1170, 450);
	addWidget(widet);
	//矩形实
	widet = new Widget;
	widet->setSize(60, 30);
	widet->setPos(1230, 450);
	addWidget(widet);

	//线宽栏
	widet = new Widget;
	widet->setSize(120, 30);
	widet->setPos(1170, 400);
	addWidget(widet);
	widet = new Widget;
	widet->setSize(120, 30);
	widet->setPos(1170, 370);
	addWidget(widet);
	widet = new Widget;
	widet->setSize(120, 30);
	widet->setPos(1170, 340);
	addWidget(widet);
	widet = new Widget;
	widet->setSize(120, 30);
	widet->setPos(1170, 310);
	addWidget(widet);
	widet = new Widget;
	widet->setSize(120, 30);
	widet->setPos(1170, 280);
	addWidget(widet);

	//颜色栏
	widet = new Widget;
	widet->setSize(120, 30);
	widet->setPos(1170, 220);
	addWidget(widet);
	//
	widet = new Widget;
	widet->setSize(120, 30);
	widet->setPos(1170, 220);
	addWidget(widet);


}




#endif // !WINDOW_H_


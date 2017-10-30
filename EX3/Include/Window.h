#ifndef WINDOW_H_
#define WINDOW_H_

#include <GL/glut.h>

#include "Widget.h"
#include "SceneNode.h"
#include "Botton.h"

//透视参数
GLfloat xwMin = 0, ywMin = 0, xwMax = 1280, ywMax = 720;
GLfloat dnear = 25, dfar = 125;



class Window
{
public:
	Window(int width, int height, char* title);
	void	update(int x,int y);
	void	draw();
	int		getActiveTool() { return lastActiveTool; }
	int		getActiveLineWidth() { return lastActiveLineWidth; }
	int		getActiveColor() { return lastActiveColor; }



private:
	int lastActiveTool = 0;
	int lastActiveLineWidth = 0;
	int lastActiveColor = 0;

	static void  reshape(int w, int h);
	void		init();
	void		addBackground(SceneNode* widet);
	void		background();
	void		widgets();


	SceneNode*	mBackground[10];
	SceneNode*	mToolBottons[Botton::ToolCount];
	SceneNode*	mLineWidthBottons[Botton::WidthCount];
	SceneNode*	mColorBottons[Botton::ColorCount];
	SceneNode*	mMenuBottons[Botton::MenuCount];
	int			backgroundCount;

};
void drawSceneNode(SceneNode* );

Window::Window(int width, int height, char* title):
	backgroundCount(0)
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

	//检测工具区域
	if ((x >= 930 && x <= 1330) && (y >= 650 && y <= 730)||
		((x >= 1170 && x <= 1290) && (y >= 450 && y <= 600))) 
	{
		for (int i = 0; i < Botton::ToolCount; i++) {
			if (mToolBottons[i]->isWidgetActive(x, y)&&i!=lastActiveTool) {
				mToolBottons[i]->setActive(true);
				mToolBottons[lastActiveTool]->setActive(false);
				lastActiveTool = i;
			}
		}
		
	}
	//检测线粗区域
	else if ((x >= 1170 && x <= 1290) && (y >= 280 && y <= 400))
	{
		for (int i = 0; i < Botton::WidthCount; i++) {
			if (mLineWidthBottons[i]->isWidgetActive(x, y) && i != lastActiveLineWidth) {
				mLineWidthBottons[i]->setActive(true);
				mLineWidthBottons[lastActiveLineWidth]->setActive(false);
				lastActiveLineWidth = i;
			}
		}

	}
	//检测颜色区域
	else if ((x >= 117 && x <= 1290) && (y >= 100 && y <= 220))
	{
		for (int i = 0; i < Botton::ColorCount; i++) {
			if (mColorBottons[i]->isWidgetActive(x, y) && i != lastActiveColor) {
				mColorBottons[i]->setActive(true);
				mColorBottons[lastActiveColor]->setActive(false);
				lastActiveColor = i;
			}
		}

	}

	//检测选项区域

	for (int i = 0; i < Botton::MenuCount; i++) {
		mMenuBottons[i]->setActive(false);
		if (mMenuBottons[i]->isWidgetActive(x,y)) {
			mMenuBottons[i]->setActive(true);
		}
	}

	glutReshapeFunc(reshape);
}

void Window::draw()
{
//	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i <backgroundCount; i++) {
		mBackground[i]->draw();
	}

	for (int i = 0; i < Botton::MenuCount; i++) {
		mMenuBottons[i]->draw();
	}


	for (int i = 0; i < Botton::ToolCount; i++) {
		mToolBottons[i]->draw();
	}
	for (int i = 0; i < Botton::WidthCount; i++) {
		mLineWidthBottons[i]->draw();
	}
	for (int i = 0; i < Botton::ColorCount; i++) {
		mColorBottons[i]->draw();
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

	mToolBottons[0]->setActive(true);
	mLineWidthBottons[0]->setActive(true);
	mColorBottons[0]->setActive(true);




}

inline void Window::addBackground(SceneNode * widet)
{
	mBackground[backgroundCount++]=widet;
}

inline void Window::background()
{
	
	SceneNode* tmp = new SceneNode;
	tmp->setColor(SceneNode::Color::Grey);
	tmp->setType(SceneNode::Type::Rect);
	tmp->setSize(1330, 110);
	tmp->setPos(0, 650);
	addBackground(tmp);
	

	tmp = new SceneNode;
	tmp->setColor(SceneNode::Color::Grey);
	tmp->setType(SceneNode::Type::Rect);
	tmp->setSize(200, 650);
	tmp->setPos(1130, 0);
	addBackground(tmp);

	//工具栏
	Widget* widget = new Botton;
	widget->setSize(400, 30);
	widget->setPos(930, 730);
	widget->loadTexture("Textures/Title_Tools.bmp");
	addBackground(widget);

	//形状栏
	widget = new Botton;
	widget->setSize(120, 30);
	widget->setPos(1170, 600);
	widget->loadTexture("Textures/Title_Shape.bmp");
	addBackground(widget);

	//LineWidth
	widget = new Botton;
	widget->setSize(120, 30);
	widget->setPos(1170, 400);
	widget->loadTexture("Textures/Title_Width.bmp");
	addBackground(widget);

	widget = new Botton;
	widget->setSize(120, 30);
	widget->setPos(1170, 220);
	widget->loadTexture("Textures/Title_Color.bmp");
	addBackground(widget);

	widget = new Botton;
	widget->setSize(150, 100);
	widget->setPos(60, 655);
	widget->loadTexture("Textures/Title_Gallery.bmp");
	addBackground(widget);

}

inline void Window::widgets()
{
	Botton* widet = new Botton;
	widet->setSize(150, 100);
	widet->setPos(210, 655);
	widet->loadTexture("Textures/save.bmp");
	widet->setType(Botton::Menu::Save);
	mMenuBottons[Botton::Save] = widet;

	widet = new Botton;
	widet->setSize(150, 100);
	widet->setPos(360, 655);
	widet->loadTexture("Textures/help.bmp");
	mMenuBottons[Botton::Help] = widet;

	//填充
	widet = new Botton;
	widet->setSize(100, 80);
	widet->setPos(1130, 650);
	widet->loadTexture("Textures/PaintBucket.bmp");
	mToolBottons[Botton::Brush] = widet;
	//橡皮
	widet = new Botton;
	widet->setSize(100, 80);
	widet->setPos(1230, 650);
	widet->loadTexture("Textures/Eraser.bmp");
	mToolBottons[Botton::Eraser] = widet;
	//放大镜
	widet = new Botton;
	widet->setSize(100, 80);
	widet->setPos(1030, 650);
	widet->loadTexture("Textures/Zoom.bmp");
	mToolBottons[Botton::Zoom] = widet;
	//画笔
	widet = new Botton;
	widet->setSize(100, 80);
	widet->setPos(930, 650);
	widet->loadTexture("Textures/Pencil.bmp");
	mToolBottons[Botton::Pen] = widet;



	//直线
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1170, 570);
	widet->loadTexture("Textures/Line.bmp");
	mToolBottons[Botton::Line] = widet;
	//曲线
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1230, 570);
	widet->loadTexture("Textures/Curve.bmp");
	mToolBottons[Botton::Curve] = widet;
	//三角形
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1170, 540);
	widet->loadTexture("Textures/triangle.bmp");
	mToolBottons[Botton::Triangle] = widet;
	//三角形实
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1230, 540);
	widet->loadTexture("Textures/triangle2.bmp");
	mToolBottons[Botton::Trianglef] = widet;
	//圆形
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1170, 510);
	widet->loadTexture("Textures/circle.bmp");
	mToolBottons[Botton::CirCle] = widet;
	//圆形实
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1230, 510);
	widet->loadTexture("Textures/circle2.bmp");
	mToolBottons[Botton::CirClef] = widet;
	//椭圆形
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1170, 480);
	widet->loadTexture("Textures/Ellipse.bmp");
	mToolBottons[Botton::Ellipse] = widet;
	//椭圆形实
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1230, 480);
	widet->loadTexture("Textures/Ellipse2.bmp");
	mToolBottons[Botton::Ellipsef] = widet;
	//矩形
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1170, 450);
	widet->loadTexture("Textures/rectangle.bmp");
	mToolBottons[Botton::Rect] = widet;
	//矩形实
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1230, 450);
	widet->loadTexture("Textures/rectangle2.bmp");
	mToolBottons[Botton::Rectf] = widet;

	//线宽栏

	widet = new Botton;
	widet->setSize(120, 30);
	widet->setPos(1170, 370);
	widet->loadTexture("Textures/line1.bmp");
	mLineWidthBottons[Botton::Width1] = widet;
	widet = new Botton;
	widet->setSize(120, 30);
	widet->setPos(1170, 340);
	widet->loadTexture("Textures/line2.bmp");
	mLineWidthBottons[Botton::Width2] = widet;
	widet = new Botton;
	widet->setSize(120, 30);
	widet->setPos(1170, 310);
	widet->loadTexture("Textures/line3.bmp");
	mLineWidthBottons[Botton::Width3] = widet;
	widet = new Botton;
	widet->setSize(120, 30);
	widet->setPos(1170, 280);
	widet->loadTexture("Textures/line4.bmp");
	mLineWidthBottons[Botton::Width4] = widet;

	//颜色栏
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1170, 190);
	widet->loadTexture("Textures/Red.bmp");
	mColorBottons[Botton::Red] = widet;
	//
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1230, 190);
	widet->loadTexture("Textures/Green.bmp");
	mColorBottons[Botton::Green] = widet;

	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1170,160);
	widet->loadTexture("Textures/Blue.bmp");
	mColorBottons[Botton::Blue] = widet;
	/////////////////////
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1230, 160);
	widet->loadTexture("Textures/Yellow.bmp");
	mColorBottons[Botton::Yellow] = widet;

	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1170, 130);
	widet->loadTexture("Textures/Orange.bmp");
	mColorBottons[Botton::Orange] = widet;

	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1230, 130);
	widet->loadTexture("Textures/Black.bmp");
	mColorBottons[Botton::Black] = widet;

	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1170, 100);
	widet->loadTexture("Textures/White.bmp");
	mColorBottons[Botton::White] = widet;

	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1230, 100);
	widet->loadTexture("Textures/Purple.bmp");
	mColorBottons[Botton::Purple] = widet;



}




#endif // !WINDOW_H_


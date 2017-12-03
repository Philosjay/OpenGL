#include "../Include/Window.h"

#include "../Include/UI.h"

//透视参数
GLfloat xwMin = 0, ywMin = 0, xwMax = 1280, ywMax = 720;
GLfloat dnear = 25, dfar = 125;

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

}

void Window::update(int x, int y) {

	mUI->processInput(x, y);
	glutReshapeFunc(reshape);
}

void Window::draw()
{
	//	glClear(GL_COLOR_BUFFER_BIT);
	mUI->show();

}

bool Window::isInPaper()
{
	return mUI->isDrawing();
}

int Window::getStatus()
{
	return mUI->getStatus();
}

int Window::getActiveTool()
{
	return mUI->getActiveTool();
}

int Window::getActiveLineWidth()
{
	return mUI->getLastActiveLineWidth();
}

Color Window::getActiveColor()
{
	return mUI->getLastActiveColor();
}

void Window::registerManager(Manager * mng)
{
	mUI = new UI(mng);
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
	


}
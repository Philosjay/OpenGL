#ifndef WINDOW_H_
#define WINDOW_H_

#include <GL/glut.h>

//透视参数
GLfloat xwMin = -40, ywMin = -60, xwMax = 40, ywMax = 60;
GLfloat dnear = 25, dfar = 125;

class Window
{
public:
	Window(int width, int height, char* title);
	void	update();
	void	render();
private:
	friend void displayFunc();
	friend void  reshape(int w, int h);

};


Window::Window(int width, int height, char* title) {
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutCreateWindow("test");

	gluLookAt(100, 50, 50, 50, 50, 0, 0, 1, 0);
	glClearColor(1, 1, 1, 0);
	glMatrixMode(GL_MODELVIEW);
	glMatrixMode(GL_PROJECTION);
}

void Window::update() {
	glutReshapeFunc(reshape);
}

void Window::render() {
	glutDisplayFunc(displayFunc);
}

void displayFunc()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glPushMatrix();

	glColor3f(0, 0, 1);
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_LINE);

	glBegin(GL_QUADS);
	glVertex3f(0, 0, 0);
	glVertex3f(100, 0, 0);
	glVertex3f(100, 100, 0);
	glVertex3f(0, 100, 0);
	glEnd();

	glPopMatrix();

	glFlush();

}

void reshape(int w, int h)
{
	glViewport(0, 0, w, h);			//重置画面中心，和一下两个 glMatrixMode()照应使用

	glLoadIdentity();

	if (w <= h)
		glFrustum(xwMin, xwMax, ywMin*(GLfloat)h / (GLfloat)w, ywMax*(GLfloat)h / (GLfloat)w, dnear, dfar);
	else
		glFrustum(xwMin*(GLfloat)w / (GLfloat)h, xwMax*(GLfloat)w / (GLfloat)h, ywMin, ywMax, dnear, dfar);

}

#endif // !WINDOW_H_


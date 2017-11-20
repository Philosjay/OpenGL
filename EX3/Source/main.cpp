#include <GL/glut.h>

#include "../Include\Application.h"



int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	Application*	mApp = new Application;

	mApp->run();

	return 0;
}


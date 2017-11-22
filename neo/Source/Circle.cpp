#include "../Include/Circle.h"

Circle::Circle()
	: R(0)
{
	requiredClicks = 1;
}

bool Circle::isGrabbed(int x, int y)
{
	float centerX = (startPosX + endPosX ) / 2;
	float centerY = (startPosY + endPosY ) / 2;


	float dis = sqrtf(((float)x - (float)centerX)*((float)x - (float)centerX)
		+ ((float)y - (float)centerY)*((float)y - (float)centerY));
	if (dis < R) {
		
		return true;
	}
	else {
		return false;
	}
	
}



inline void Circle::draw()
{
	int centerX = (startPosX + endPosX) / 2;
	int centerY = (startPosY + endPosY) / 2;
	glPushMatrix();

	applyColor();
	applyLineWidth();

	glBegin(GL_LINE_LOOP);
	if (endPosX >= startPosX && endPosY <= startPosY) {
		for (int i = 0; i < n; ++i)
			glVertex3f(centerX + R*cos(2 * Pi / n*i) , centerY+ R*sin(2 * Pi / n*i) , 0);
	}
	else if (endPosX >= startPosX && endPosY >= startPosY) {
		for (int i = 0; i < n; ++i)
			glVertex3f(centerX + R*cos(2 * Pi / n*i) , centerY + R*sin(2 * Pi / n*i) , 0);
	}
	else if (endPosX <= startPosX && endPosY <= startPosY) {
		for (int i = 0; i < n; ++i)
			glVertex3f(centerX + R*cos(2 * Pi / n*i) , centerY + R*sin(2 * Pi / n*i) , 0);
	}
	else if (endPosX <= startPosX && endPosY >= startPosY) {
		for (int i = 0; i < n; ++i)
			glVertex3f(centerX + R*cos(2 * Pi / n*i) , centerY + R*sin(2 * Pi / n*i) , 0);
	}
	glEnd();

	glPopMatrix();

	R = sqrtf(((float)endPosX - (float)startPosX)*((float)endPosX - (float)startPosX)
		+ ((float)endPosY - (float)startPosY)*((float)endPosY - (float)startPosY)) / 2;
}
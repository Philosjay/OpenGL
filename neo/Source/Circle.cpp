#include "../Include/Circle.h"

Circle::Circle()
	: R(0)
{
}

bool Circle::isGrabbed(int x, int y)
{

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
	glPushMatrix();

	applyColor();
	applyLineWidth();


	
	if (isFilled) {
		glBegin(GL_POLYGON);
	}
	else {
		glBegin(GL_LINE_LOOP);
	}
	for (int i = 0; i < n; ++i) {
		glVertex3f(centerX + R*cos(2 * Pi / n*i), centerY + R*sin(2 * Pi / n*i), 0);
	}

	glEnd();

	glPopMatrix();

}

void Circle::setRadius(float r)
{
	R = r;
}

void Circle::moveTo(int x, int y)
{
	centerX = x;
	centerY = y;
}

void Circle::move(int x, int y)
{
	centerX += x;
	centerY += y;
}

float Circle::getRadius()
{
	return R;
}

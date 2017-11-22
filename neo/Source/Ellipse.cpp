#include "../Include/Ellipse.h"

Ellipse_::Ellipse_()
	: R1(0)
	, R2(0)
{
	requiredClicks = 1;
}

bool Ellipse_::isGrabbed(int x, int y)
{
	float centerX = (startPosX + endPosX) / 2;
	float centerY = (startPosY + endPosY) / 2;

	float x0 = x - centerX;
	float y0 = y - centerY;

	if ((x0*x0) / (R1*R1) + (y0*y0) / (R2*R2) < 1) {
		return true;
	}
	return false;
}


inline void Ellipse_::draw()
{
	float centerX = (startPosX + endPosX) / 2;
	float centerY = (startPosY + endPosY) / 2;

	glPushMatrix();

	applyColor();
	applyLineWidth();


	glLineWidth(mLineWidth * 2);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < n; ++i)
		glVertex3f(centerX + R1*cos(2 * PI / n*i), centerY - R2*sin(2 * PI / n*i), 0);
	glEnd();

	glPopMatrix();

	R1 = sqrtf(((float)endPosX - (float)startPosX)*((float)endPosX - (float)startPosX)) / 2;
	R2 = sqrtf(((float)endPosY - (float)startPosY)*((float)endPosY - (float)startPosY)) / 2;
}

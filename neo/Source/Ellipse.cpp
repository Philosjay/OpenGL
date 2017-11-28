#include "../Include/Ellipse.h"

Ellipse_::Ellipse_()
	: R1(0)
	, R2(0)
{
}

bool Ellipse_::isGrabbed(int x, int y)
{

	float x0 = x - centerX;
	float y0 = y - centerY;

	if ((x0*x0) / (R1*R1) + (y0*y0) / (R2*R2) < 1) {
		return true;
	}
	return false;
}


inline void Ellipse_::draw()
{
	glPushMatrix();

	applyColor();
	applyLineWidth();

	glLineWidth(mLineWidth * 2);
	if (isFilled) {
		glBegin(GL_POLYGON);
	}
	else {
		glBegin(GL_LINE_LOOP);
	}
	for (int i = 0; i < n; ++i)
		glVertex3f(centerX + R1*cos(2 * PI / n*i), centerY - R2*sin(2 * PI / n*i), 0);
	glEnd();

	glPopMatrix();
}

void Ellipse_::moveTo(int x, int y)
{
	centerX = x;
	centerY = y;
}

void Ellipse_::move(int x, int y)
{
	centerX += x;
	centerY += y;
}

void Ellipse_::setRadiusA(float r)
{
	R1 = r;
}

void Ellipse_::setRadiusB(float r)
{
	R2 = r;
}

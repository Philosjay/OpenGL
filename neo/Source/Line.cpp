#include "../Include/Line.h"

Line::Line()
{
	requiredClicks = 1;
}

inline void Line::draw()
{
	applyColor();
	applyLineWidth();
	glPushMatrix();


	glBegin(GL_LINES);
	glVertex3f(startPosX, startPosY, 0);
	glVertex3f(endPosX, endPosY, 0);
	glEnd();

	glPopMatrix();
}

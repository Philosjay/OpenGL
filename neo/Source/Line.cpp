#include "../Include/Line.h"

Line::Line()
{
	requiredClicks = 1;
}

bool Line::isGrabbed(int x, int y)
{
	float k = ((float)endPosY - (float)startPosY) / ((float)endPosX - (float)startPosX);
	float y0 = k*(x - startPosX) + startPosY ;
	if (y0 -5 < y&&y < y0 + 5){
		if (startPosX < endPosX) {
			if (x > startPosX&&x < endPosX) {
				return true;
			}
		}
		else {
			if (x < startPosX&&x > endPosX) {
				return true;
			}
		}
}
	return false;
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

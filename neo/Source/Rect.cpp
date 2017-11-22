#include "../Include/Rect.h"


Rect::Rect()
{
	requiredClicks = 1;
}
bool Rect::isGrabbed(int x, int y)
{
	int centerX = (startPosX + endPosX) / 2;
	int centerY = (startPosY + endPosY) / 2;

	int length = endPosX > startPosX ? endPosX - startPosX : startPosX - endPosX;
	int	height = endPosY > startPosY ? endPosY - startPosY : startPosY - endPosY;

	if (x < centerX+length/2 && x > centerX - length/2) {
		if (y<centerY + height / 2 && y> centerY - height / 2) {
			return true;
		}
		
	}
	return false;
}

inline void Rect::draw()
{
	int centerX = (startPosX + endPosX) / 2;
	int centerY = (startPosY + endPosY) / 2;

	int length = endPosX > startPosX ? endPosX - startPosX : startPosX - endPosX;
	int	height = endPosY > startPosY ? endPosY - startPosY : startPosY - endPosY;

	glPushMatrix();

	applyColor();
	applyLineWidth();

	points[0][0] = centerX - length / 2;
	points[0][1] = centerY - height / 2;
	points[1][0] = centerX + length / 2;
	points[1][1] = centerY - height / 2;
	points[2][0] = centerX + length / 2;
	points[2][1] = centerY + height / 2;
	points[3][0] = centerX - length / 2;
	points[3][1] = centerY + height / 2;

	glBegin(GL_LINES);
	glVertex3f(points[0][0], points[0][1], 0);
	glVertex3f(points[1][0], points[1][1], 0);

	glVertex3f(points[1][0] - mLineWidth, points[1][1], 0);
	glVertex3f(points[2][0] - mLineWidth, points[2][1], 0);

	glVertex3f(points[2][0], points[2][1], 0);
	glVertex3f(points[3][0], points[3][1], 0);

	glVertex3f(points[3][0]+ mLineWidth, points[3][1], 0);
	glVertex3f(points[0][0]+ mLineWidth, points[0][1], 0);

	glEnd();

	glPopMatrix();
}


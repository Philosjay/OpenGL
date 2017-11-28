#include "../Include/Triangle.h"

Triangle::Triangle()
{
}
bool Triangle::isGrabbed(int x, int y)
{
	int centerX = startPosX + width / 2;
	int centerY = startPosY - height / 2;

	int absWidth = width > 0 ? width : -width;
	int absHeight = height > 0 ? height : -height;

	if (x < centerX + absWidth / 2 && x > centerX - absWidth / 2) {
		if (y<centerY + absHeight / 2 && y> centerY - absHeight / 2) {
			if (points[0][1] < points[2][1]) {
				if (y < (x - points[2][0])*((points[2][1] - points[0][1]) / (points[2][0] - points[0][0])) + points[2][1]
					&& y < (x - points[2][0])*((points[2][1] - points[1][1]) / (points[2][0] - points[1][0])) + points[2][1])
					return true;
			}
			else {
				if (y > (x - points[2][0])*((points[2][1] - points[0][1]) / (points[2][0] - points[0][0])) + points[2][1]
					&& y > (x - points[2][0])*((points[2][1] - points[1][1]) / (points[2][0] - points[1][0])) + points[2][1])
					return true;
			}
		}
	}
	return false;
}

void Triangle::setSize(float length, float height)
{
	width = length;
	this->height = height;
}

void Triangle::moveTo(int x, int y)
{
	startPosX = x;
	startPosY = y;
}

void Triangle::move(int x, int y)
{
	startPosX += x;
	startPosY += y;
}


inline void Triangle::draw()
{
	int centerX = startPosX + width / 2;
	int centerY = startPosY - height / 2;

	glPushMatrix();

	applyColor();
	applyLineWidth();

	points[0][0] = centerX - width / 2;
	points[0][1] = centerY - height / 2;
	points[1][0] = centerX + width / 2;
	points[1][1] = centerY - height / 2;
	points[2][0] = centerX ;
	points[2][1] = centerY + height / 2;

	if (startPosY <= endPosY) {
		points[0][0] = centerX - width / 2;
		points[0][1] = centerY - height / 2;
		points[1][0] = centerX + width / 2;
		points[1][1] = centerY - height / 2;
		points[2][0] = centerX;
		points[2][1] = centerY + height / 2;
	}
	else {
		points[0][0] = centerX - width / 2;
		points[0][1] = centerY + height / 2;
		points[1][0] = centerX + width / 2;
		points[1][1] = centerY + height / 2;
		points[2][0] = centerX;
		points[2][1] = centerY - height / 2;
	}

	if (isFilled) {
		glBegin(GL_POLYGON);
	}
	else {
		glBegin(GL_LINES);
	}
	glVertex3f(points[0][0], points[0][1], 0);
	glVertex3f(points[1][0], points[1][1], 0);
	glVertex3f(points[1][0] - mLineWidth, points[1][1], 0);
	glVertex3f(points[2][0], points[2][1], 0);
	glVertex3f(points[2][0], points[2][1], 0);
	glVertex3f(points[0][0] + mLineWidth, points[0][1], 0);

	glEnd();

	glPopMatrix();
}
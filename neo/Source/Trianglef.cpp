#include "../Include/Trianglef.h"
#include "../Include/settingList.h"


Trianglef::Trianglef()
{
	requiredClicks = 1;
}

bool Trianglef::isGrabbed(int x, int y)
{
	float centerX = (startPosX + endPosX) / 2;
	float centerY = (startPosY + endPosY) / 2;

	int length = endPosX > startPosX ? endPosX - startPosX : startPosX - endPosX;
	int	height = endPosY > startPosY ? endPosY - startPosY : startPosY - endPosY;

	if (x < centerX + length / 2 && x > centerX - length / 2) {
		if (y<centerY + height / 2 && y> centerY - height / 2) {
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


inline void Trianglef::draw()
{
	float centerX = (startPosX + endPosX) / 2;
	float centerY = (startPosY + endPosY) / 2;

	int length = endPosX > startPosX ? endPosX - startPosX : startPosX - endPosX;
	int	height = endPosY > startPosY ? endPosY - startPosY : startPosY - endPosY;

	glPushMatrix();

	applyColor();
	applyLineWidth();

	points[0][0] = centerX - length / 2;
	points[0][1] = centerY - height / 2;
	points[1][0] = centerX + length / 2;
	points[1][1] = centerY - height / 2;
	points[2][0] = centerX;
	points[2][1] = centerY + height / 2;

	if (startPosY <= endPosY) {
		points[0][0] = centerX - length / 2;
		points[0][1] = centerY - height / 2;
		points[1][0] = centerX + length / 2;
		points[1][1] = centerY - height / 2;
		points[2][0] = centerX;
		points[2][1] = centerY + height / 2;
	}
	else {
		points[0][0] = centerX - length / 2;
		points[0][1] = centerY + height / 2;
		points[1][0] = centerX + length / 2;
		points[1][1] = centerY + height / 2;
		points[2][0] = centerX;
		points[2][1] = centerY - height / 2;
	}

	glBegin(GL_POLYGON);
	glVertex3f(points[0][0], points[0][1], 0);
	glVertex3f(points[1][0], points[1][1], 0);
	glVertex3f(points[1][0] - mLineWidth, points[1][1], 0);
	glVertex3f(points[2][0], points[2][1], 0);
	glVertex3f(points[2][0], points[2][1], 0);
	glVertex3f(points[0][0] + mLineWidth, points[0][1], 0);
	glEnd();

	glPopMatrix();
}


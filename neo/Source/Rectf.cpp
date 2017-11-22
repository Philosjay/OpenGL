#include "../Include/Rectf.h"

Rectf::Rectf()
{
	requiredClicks = 1;
}
bool Rectf::isGrabbed(int x, int y)
{
	int centerX = (startPosX + endPosX) / 2;
	int centerY = (startPosY + endPosY) / 2;

	int length = endPosX > startPosX ? endPosX - startPosX : startPosX - endPosX;
	int	height = endPosY > startPosY ? endPosY - startPosY : startPosY - endPosY;

	if (x < centerX + length / 2 && x > centerX - length / 2) {
		if (y<centerY + height / 2 && y> centerY - height / 2) {
			return true;
		}

	}
	return false;
}
inline void Rectf::draw()
{
	int centerX = (startPosX + endPosX) / 2;
	int centerY = (startPosY + endPosY) / 2;

	int length = endPosX > startPosX ? endPosX - startPosX : startPosX - endPosX;
	int	height = endPosY > startPosY ? endPosY - startPosY : startPosY - endPosY;

	glPushMatrix();

	applyColor();


	points[0][0] = centerX - length / 2;
	points[0][1] = centerY - height / 2;
	points[1][0] = centerX + length / 2;
	points[1][1] = centerY - height / 2;
	points[2][0] = centerX + length / 2;
	points[2][1] = centerY + height / 2;
	points[3][0] = centerX - length / 2;
	points[3][1] = centerY + height / 2;

	if (isTextureEnable) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
	}

	glLineWidth(mLineWidth * 2);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(points[0][0], points[0][1], 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(points[1][0], points[1][1], 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(points[2][0], points[2][1], 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(points[3][0], points[3][1], 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	if (isLineVisible) {
		glColor3f(0.0, 0.0, 0.0);
		glLineWidth(1);
		glBegin(GL_LINES);
		glVertex3f(points[0][0], points[0][1], 0);
		glVertex3f(points[1][0] , points[1][1], 0);
		glVertex3f(points[1][0] , points[1][1], 0);
		glVertex3f(points[2][0], points[2][1], 0);
		glVertex3f(points[2][0], points[2][1], 0);
		glVertex3f(points[3][0], points[3][1], 0);
		glVertex3f(points[3][0], points[3][1], 0);
		glVertex3f(points[0][0], points[0][1], 0);
		glEnd();
	}
	glPopMatrix();
}


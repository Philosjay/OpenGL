#include "../Include/Rect.h"


Rect::Rect()
	: width(0)
	, height(0)
	, rotateCenterAngle(0)
{

}
bool Rect::isGrabbed(int x, int y)
{
	int centerX = startPosX + width / 2;
	int centerY = startPosY - height / 2;

	int absWidth = width > 0 ? width : -width;
	int absHeight = height > 0 ? height : -height;

	if (x < centerX+ absWidth /2 && x > centerX - absWidth /2) {
		if (y<centerY + absHeight / 2 && y> centerY - absHeight / 2) {
			return true;
		}
		
	}
	return false;
}

void Rect::setSize(float length, float height)
{
	width = length;
	this->height = height;


}

void Rect::moveTo(int x, int y)
{
	startPosX = x;
	startPosY = y;
}

void Rect::move(int x, int y)
{
	startPosX += x;
	startPosY += y;
}

float Rect::getWidth()
{
	return width;
}

float Rect::getHeight()
{
	return height;
}


inline void Rect::draw()
{
	if (width == 20) {
		int i = 0;
	}

	int centerX=startPosX + width / 2;
	int centerY=startPosY - height / 2;



	glPushMatrix();

	applyColor();
	applyLineWidth();

	points[0][0] = centerX - width / 2;
	points[0][1] = centerY - height / 2;
	points[1][0] = centerX + width / 2;
	points[1][1] = centerY - height / 2;
	points[2][0] = centerX + width / 2;
	points[2][1] = centerY + height / 2;
	points[3][0] = centerX - width / 2;
	points[3][1] = centerY + height / 2;

	if (isFilled) {
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
			glVertex3f(points[1][0], points[1][1], 0);
			glVertex3f(points[1][0], points[1][1], 0);
			glVertex3f(points[2][0], points[2][1], 0);
			glVertex3f(points[2][0], points[2][1], 0);
			glVertex3f(points[3][0], points[3][1], 0);
			glVertex3f(points[3][0], points[3][1], 0);
			glVertex3f(points[0][0], points[0][1], 0);
			glEnd();
		}
	}
	else {
		glBegin(GL_LINES);
		glVertex3f(points[0][0], points[0][1], 0);
		glVertex3f(points[1][0], points[1][1], 0);

		glVertex3f(points[1][0] - mLineWidth, points[1][1], 0);
		glVertex3f(points[2][0] - mLineWidth, points[2][1], 0);

		glVertex3f(points[2][0], points[2][1], 0);
		glVertex3f(points[3][0], points[3][1], 0);

		glVertex3f(points[3][0] + mLineWidth, points[3][1], 0);
		glVertex3f(points[0][0] + mLineWidth, points[0][1], 0);
	}
	
	if (isFilled) {
		if (isLineVisible) {
			glColor3f(0.0, 0.0, 0.0);
			glLineWidth(1);
			glBegin(GL_LINES);
			glVertex3f(points[0][0], points[0][1], 0);
			glVertex3f(points[1][0], points[1][1], 0);
			glVertex3f(points[1][0], points[1][1], 0);
			glVertex3f(points[2][0], points[2][1], 0);
			glVertex3f(points[2][0], points[2][1], 0);
			glVertex3f(points[3][0], points[3][1], 0);
			glVertex3f(points[3][0], points[3][1], 0);
			glVertex3f(points[0][0], points[0][1], 0);
		}
	}

	glEnd();

	glPopMatrix();
}


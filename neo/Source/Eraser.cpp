#include "../Include/Eraser.h"

Eraser::Eraser()
{
}

inline void Eraser::draw()
{

	glPushMatrix();


	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3f(endPosX, endPosY, 0);
	glVertex3f(endPosX + mLineWidth, endPosY, 0);
	glVertex3f(endPosX + mLineWidth, endPosY + mLineWidth, 0);
	glVertex3f(endPosX, endPosY + mLineWidth, 0);
	glEnd();

	glPopMatrix();

}



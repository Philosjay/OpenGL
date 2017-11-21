#include "../Include/Eraser.h"

Eraser::Eraser()
{
}

inline void Eraser::draw()
{
	glPushMatrix();


	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3f(motionPosX, motionPosY, 0);
	glVertex3f(motionPosX + mLineWidth, motionPosY, 0);
	glVertex3f(motionPosX + mLineWidth, motionPosY + mLineWidth, 0);
	glVertex3f(motionPosX, motionPosY + mLineWidth, 0);
	glEnd();

	glPopMatrix();

}



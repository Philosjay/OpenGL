#include "../Include/Pen.h"

Pen::Pen()
{
	requiredClicks = 0;
}

void Pen::draw()
{

	glPushMatrix();

	applyColor();


	glBegin(GL_QUADS);
	glVertex3f(endPosX, endPosY, 0);
	glVertex3f(endPosX + mLineWidth, endPosY, 0);
	glVertex3f(endPosX + mLineWidth, endPosY + mLineWidth, 0);
	glVertex3f(endPosX, endPosY + mLineWidth, 0);
	glEnd();

	glPopMatrix();

}


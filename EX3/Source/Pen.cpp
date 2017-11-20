#include "../Include/Pen.h"

Pen::Pen()
{
}

void Pen::draw()
{
	glPushMatrix();

	//…Ë÷√—’…´
	switch (SceneNode::mColor)
	{
	case Color::Red:
		glColor3f(1, 0, 0);
		break;
	case Color::Green:
		glColor3f(0, 1, 0);
		break;
	case Color::Blue:
		glColor3f(0, 0, 1);
		break;
	case Color::Yellow:
		glColor3f(1, 1, 0);
		break;
	case Color::Black:
		glColor3f(0, 0, 0);
		break;
	case Color::Purple:
		glColor3f(1, 0, 1);
		break;
	case Color::Orange:
		glColor3f(1, 0.5, 0);
		break;
	case Color::White:
		glColor3f(1, 1, 1);
		break;
	case Color::Grey:
		glColor3f(0.8, 0.8, 0.8);
		break;
	case Color::Grey2:
		glColor3f(0.5, 0.5, 0.5);
		break;
	default:
		break;
	}

	glBegin(GL_QUADS);
	glVertex3f(motionPosX, motionPosY, 0);
	glVertex3f(motionPosX + mLineWidth, motionPosY, 0);
	glVertex3f(motionPosX + mLineWidth, motionPosY + mLineWidth, 0);
	glVertex3f(motionPosX, motionPosY + mLineWidth, 0);
	glEnd();

	glPopMatrix();

}


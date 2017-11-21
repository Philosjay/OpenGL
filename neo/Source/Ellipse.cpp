#include "../Include/Ellipse.h"

Ellipse_::Ellipse_()
{
}

bool Ellipse_::isGrabbed(int x, int y)
{
	float x0 = x - centerX;
	float y0 = y - centerY;

	if ((x0*x0) / (R1*R1) + (y0*y0) / (R2*R2) < 1) {
		return true;
	}
	return false;
}


inline void Ellipse_::draw()
{
	glPushMatrix();

	//ÉèÖÃÑÕÉ«
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
	R1 = sqrtf(((float)motionPosX - (float)originPosX)*((float)motionPosX - (float)originPosX)) / 2;
	R2 = sqrtf(((float)motionPosY - (float)originPosY)*((float)motionPosY - (float)originPosY)) / 2;

	glLineWidth(mLineWidth * 2);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < n; ++i)
		glVertex3f(centerX + R1*cos(2 * PI / n*i), centerY - R2*sin(2 * PI / n*i), 0);
	glEnd();

	glPopMatrix();
}

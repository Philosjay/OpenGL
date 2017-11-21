#include "../Include/Circlef.h"

Circlef::Circlef()
	: R(0)
{
	requiredClicks = 1;
}
bool Circlef::isGrabbed(int x, int y)
{
	float dis = sqrtf(((float)x - (float)centerX)*((float)x - (float)centerX)
		+ ((float)y - (float)centerY)*((float)y - (float)centerY));
	if (dis < R) {
		return true;
	}
	else {
		return false;
	}

}

inline void Circlef::draw()
{
	glPushMatrix();

	//设置颜色
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


	glLineWidth(2);
	//draw（）的关键代码
	glBegin(GL_POLYGON);
	if (motionPosX >= originPosX && motionPosY <= originPosY) {
		for (int i = 0; i < n; ++i)
			glVertex3f(centerX + R*cos(2 * Pi / n*i), centerY + R*sin(2 * Pi / n*i), 0);
	}
	else if (motionPosX >= originPosX && motionPosY >= originPosY) {
		for (int i = 0; i < n; ++i)
			glVertex3f(centerX + R*cos(2 * Pi / n*i), centerY + R*sin(2 * Pi / n*i), 0);
	}
	else if (motionPosX <= originPosX && motionPosY <= originPosY) {
		for (int i = 0; i < n; ++i)
			glVertex3f(centerX + R*cos(2 * Pi / n*i), centerY + R*sin(2 * Pi / n*i), 0);
	}
	else if (motionPosX <= originPosX && motionPosY >= originPosY) {
		for (int i = 0; i < n; ++i)
			glVertex3f(centerX + R*cos(2 * Pi / n*i), centerY + R*sin(2 * Pi / n*i), 0);
	}

	glEnd();

	glPopMatrix();

	R = sqrtf(((float)motionPosX - (float)originPosX)*((float)motionPosX - (float)originPosX)
		+ ((float)motionPosY - (float)originPosY)*((float)motionPosY - (float)originPosY)) / 2;
}

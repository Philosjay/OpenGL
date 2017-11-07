#ifndef CIRCLEF_H_
#define CIRCLEF_H_

#include "Graph.h"

class Circlef :public Graph
{
public:
	Circlef();

	void	draw();
private:;
};

Circlef::Circlef()
{
}


inline void Circlef::draw()
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
	R = sqrtf(((float)motionPosX - (float)curPosX)*((float)motionPosX - (float)curPosX)
		+ ((float)motionPosY - (float)curPosY)*((float)motionPosY - (float)curPosY)) / 2;

	glLineWidth(mLineWidth * 2);
	glBegin(GL_POLYGON);
	if (motionPosX >= curPosX && motionPosY <= curPosY) {
		for (int i = 0; i < n; ++i)
			glVertex3f(curPosX + R*cos(2 * Pi / n*i) + R, curPosY + R*sin(2 * Pi / n*i) - R, 0);
	}
	else if (motionPosX >= curPosX && motionPosY >= curPosY) {
		for (int i = 0; i < n; ++i)
			glVertex3f(curPosX + R*cos(2 * Pi / n*i) + R, curPosY + R*sin(2 * Pi / n*i) + R, 0);
	}
	else if (motionPosX <= curPosX && motionPosY <= curPosY) {
		for (int i = 0; i < n; ++i)
			glVertex3f(curPosX + R*cos(2 * Pi / n*i) - R, curPosY + R*sin(2 * Pi / n*i) - R, 0);
	}
	else if (motionPosX <= curPosX && motionPosY >= curPosY) {
		for (int i = 0; i < n; ++i)
			glVertex3f(curPosX + R*cos(2 * Pi / n*i) - R, curPosY + R*sin(2 * Pi / n*i) + R, 0);
	}
	glEnd();

	glPopMatrix();
}

#endif
#pragma once

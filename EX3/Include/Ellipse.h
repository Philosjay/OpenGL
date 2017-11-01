#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include "Graph.h"

#define PI 3.14159f 

class Ellipse_ :public Graph
{
public:
	Ellipse_();

	void	setLineWidth(int width);
	void	draw();
private:
	int		mLineWidth;
};

Ellipse_::Ellipse_()
	:mLineWidth(1)
{
}

inline void Ellipse_::setLineWidth(int width)
{
	mLineWidth = width;
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
	float R1 = sqrtf(((float)motionPosX - (float)curPosX)*((float)motionPosX - (float)curPosX)) / 2;
	float R2 = sqrtf(((float)motionPosY - (float)curPosY)*((float)motionPosY - (float)curPosY)) / 2;

	glLineWidth(mLineWidth * 2);
	glBegin(GL_LINE_LOOP);
	if (motionPosX >= curPosX && motionPosY <= curPosY) {
		for (int i = 0; i < n; ++i)
			glVertex3f(curPosX + R1*cos(2 * PI / n*i) + R1,curPosY - R2*sin(2 * PI / n*i) - R2,0);
	}
	else if (motionPosX >= curPosX && motionPosY >= curPosY) {
		for (int i = 0; i < n; ++i)
			glVertex3f(curPosX + R1*cos(2 * PI / n*i) + R1, curPosY + R2*sin(2 * PI / n*i) + R2, 0);
	}
	else if (motionPosX <= curPosX && motionPosY <= curPosY) {
		for (int i = 0; i < n; ++i)
			glVertex3f(curPosX - R1*cos(2 * PI / n*i) - R1, curPosY - R2*sin(2 * PI / n*i) - R2, 0);
	}
	else if (motionPosX <= curPosX && motionPosY >= curPosY) {
		for (int i = 0; i < n; ++i)
			glVertex3f(curPosX - R1*cos(2 * PI / n*i) - R1, curPosY + R2*sin(2 * PI / n*i) + R2, 0);
	}
	glEnd();

	glPopMatrix();
}


#endif // !ELLIPSE_H_
#pragma once

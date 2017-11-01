#ifndef TRIANGLE_H_
#define TRIANGLR_H_

#include "Graph.h"

class Triangle : public Graph
{
public:
	Triangle();

	void	draw();
private:
};

Triangle::Triangle()
{
}


inline void Triangle::draw()
{
	glPushMatrix();

	//������ɫ
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
	glLineWidth(mLineWidth * 2);
	glBegin(GL_LINES);
	if (curPosX <= motionPosX) {
		glVertex3f(curPosX, curPosY, 0);
		glVertex3f(motionPosX, curPosY, 0);
		glVertex3f(motionPosX - mLineWidth, curPosY, 0);
		glVertex3f((motionPosX + curPosX)/2, motionPosY, 0);
		glVertex3f((motionPosX + curPosX) / 2, motionPosY, 0);
		glVertex3f(curPosX + mLineWidth, curPosY, 0);
	}
	else {
		glVertex3f(curPosX, curPosY, 0);
		glVertex3f(motionPosX, curPosY, 0);
		glVertex3f(motionPosX + mLineWidth, curPosY, 0);
		glVertex3f((motionPosX + curPosX) / 2, motionPosY, 0);
		glVertex3f((motionPosX + curPosX) / 2, motionPosY, 0);
		glVertex3f(curPosX - mLineWidth, curPosY, 0);
	}
	glEnd();

	glPopMatrix();
}


#endif // !TRIANGLE_H_
#pragma once

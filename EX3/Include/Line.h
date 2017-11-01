#ifndef LINE_H_
#define LINE_H_

#include "Graph.h"

class Line:public Graph
{
public:
	Line();

	void	setLineWidth(int width);
	void	draw();
private:
	int		mLineWidth;
};

Line::Line()
	:mLineWidth(1)
{
}

inline void Line::setLineWidth(int width)
{
	mLineWidth = width;
}

inline void Line::draw()
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
	glLineWidth(mLineWidth*2);
	glBegin(GL_LINES);
	glVertex3f(curPosX, curPosY, 0);
	glVertex3f(motionPosX, motionPosY, 0);
	glEnd();

	glPopMatrix();
}


#endif // !LINE_H_
#pragma once

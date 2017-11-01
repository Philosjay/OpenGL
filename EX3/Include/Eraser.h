#ifndef ERASER_H_
#define ERASER_H_

#include "Graph.h"

class Eraser : public Graph
{
public:
	Eraser();

	void	draw();
private:
};

Eraser::Eraser()
{
}

inline void Eraser::draw()
{
	glPushMatrix();


	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3f(motionPosX, motionPosY, 0);
	glVertex3f(motionPosX+mLineWidth*4 , motionPosY, 0);
	glVertex3f(motionPosX + mLineWidth * 4, motionPosY + mLineWidth * 4, 0);
	glVertex3f(motionPosX, motionPosY + mLineWidth * 4, 0);
	glEnd();

	glPopMatrix();

}



#endif // !RECTF_H_
#pragma once

#ifndef SCENENODE_H_
#define SCENENODE_H_

#include <GL/glut.h>

#include "Object.h"

class SceneNode: public Object
{
public:
	enum Type
	{
		Rect,
		Circle,
		Triangle,
	};

	enum Color
	{
		Red,
		Green,
		Blue,
		Black,
		White,
	};
	SceneNode();

	void	setType(Type type);
	void	setColor(Color color);
	void	setSize(int x, int y);
	void	setSize(int r);
	void	draw();
private:
	int		mType;
	int		mColor;
	int		sizeX;
	int		sizeY;
	int		radius;

	SceneNode*	next;
};

SceneNode::SceneNode() :
	Object(),
	next(NULL)
{
}
void SceneNode::setType(Type type)
{
	mType = type;
}
void SceneNode::setColor(Color color)
{
	mColor = color;
}
void SceneNode::setSize(int x, int y)
{
	sizeX = x;
	sizeY = y;
}
void SceneNode::setSize(int r)
{
	radius = r;
}
void SceneNode::draw() 
{
	glPushMatrix();

	//������ɫ
	switch (mColor)
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
	case Color::Black:
		glColor3f(0, 0, 0);
		break;
	case Color::White:
		glColor3f(1, 1, 1);
		break;
	default:
		break;
	}


	//��������
	switch (mType)
	{
	case Type::Triangle:
		glBegin(GL_TRIANGLES);
		glVertex3f(posX, posY, 0);
		glVertex3f(posX+sizeX, posY, 0);
		glVertex3f(posX+sizeX, posY+sizeY, 0);
		glEnd();
		break;
	case Type::Rect:
		glBegin(GL_QUADS);
		glVertex3f(posX, posY,0);
		glVertex3f(posX+sizeX, posY, 0);
		glVertex3f(posX + sizeX, posY+sizeY, 0);
		glVertex3f(posX , posY+sizeY, 0);
		glEnd();
		break;
	default:
		break;
	}

	glPopMatrix();

	glFlush();
}

#endif // !SCENENODE_H_
#pragma once
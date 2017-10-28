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
		Grey,
		Grey2,
	};
	SceneNode();

	void				setType(Type type);
	void				setColor(Color color);
	virtual		void	setSize(int x, int y);
	virtual		void	draw();
	virtual		void	setActive(bool);
	virtual		bool	isWidgetActive(int x,int y) { return 0; }
private:
	int		mType;
	int		mColor;
	bool	isLineVisible;

	SceneNode*	next;

protected:
	int		sizeX;
	int		sizeY;
};

SceneNode::SceneNode() :
	Object(),
	next(NULL),
	isLineVisible(true)
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
void SceneNode::draw() 
{
	glPushMatrix();

	//设置颜色
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
	case Color::Grey:
		glColor3f(0.8, 0.8, 0.8);
		break;
	case Color::Grey2:
		glColor3f(0.5, 0.5, 0.5);
		break;
	default:
		break;
	}


	//设置类型
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
		if (isLineVisible) {
			glColor3f(0.0, 0.0, 0.0);
			glBegin(GL_LINES);
			glVertex3f(posX, posY, 0);
			glVertex3f(posX + sizeX, posY, 0);
			glVertex3f(posX + sizeX, posY, 0);
			glVertex3f(posX + sizeX, posY + sizeY, 0);
			glVertex3f(posX + sizeX, posY + sizeY, 0);
			glVertex3f(posX, posY + sizeY, 0);
			glVertex3f(posX, posY + sizeY, 0);
			glVertex3f(posX, posY, 0);
			glEnd();
		}
		break;
	default:
		break;
	}

	glPopMatrix();

	glFlush();
}

inline void SceneNode::setActive(bool)
{
	//do nothing by default
}

#endif // !SCENENODE_H_
#pragma once

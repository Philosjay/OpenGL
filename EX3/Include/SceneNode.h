#ifndef SCENENODE_H_
#define SCENENODE_H_

#include <GL/glut.h>

#include "Object.h"

#define BMP_Header_Length 54

class SceneNode: public Object
{
public:
	enum Type
	{
		Pen,
		Zoom,
		Brush,
		Eraser,
		Line,
		Curve,
		Triangle,
		CirCle,
		Ellipse,
		Rect,
		Trianglef,
		CirClef,
		Ellipsef,
		Rectf,
	};

	enum Color
	{
		Red,
		Green,
		Blue,
		Yellow,
		Orange,
		White,
		Black,
		Purple,
		Grey,
		Grey2,
	};
	enum LineWidth
	{
		Width1,
		Width2,
		Width3,
		Width4,
	};
	SceneNode();

	void				setType(Type type);
	void				setColor(Color color);
	void				setType(int type) { mType = type; }
	void				setColor(int color) { mColor = color; }
	virtual		void	setSize(int x, int y);
	virtual		void	setLineWidth(int width);
	virtual		void	draw();
	virtual		void	setActive(bool);
	virtual		bool	isWidgetActive(int x,int y) { return 0; }
	virtual		void	loadTexture(char *file);
	void	setTexture(GLuint texture) { this->texture = texture; }
	void	setTextureEnable(bool isAble) { isTextureEnable = isAble; }
private:
	
	
	bool	isLineVisible;
	GLuint  texture;
	bool	isTextureEnable;
	SceneNode*	next;

protected:
	int		mColor;
	int		mType;
	int		sizeX;
	int		sizeY;



};


#endif // !SCENENODE_H_
#pragma once

#ifndef SCENENODE_H_
#define SCENENODE_H_

#include <GL/glut.h>


#define BMP_Header_Length 54

class SceneNode
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

	void				setType(int type) { mType = type; }
	void				setColor(int color) { mColor = color; }
	virtual		void	setSize(float length, float height);
	virtual		void	setLineWidth(int width);
	void				setLineVisible(bool is);
	virtual		void	draw();
	virtual		void	setActive(bool);
	virtual		bool	isWidgetActive(int x,int y) { return 0; }
	virtual		void	loadTexture(char *file);
	void	setTexture(GLuint texture) { this->texture = texture; }
	void	setTextureEnable(bool isAble) { isTextureEnable = isAble; }
private:

	SceneNode*	next;

protected:
	int		mColor;
	int		mType;
	float	length;
	float	height;
	int		mLineWidth;
	GLuint  texture;
	bool	isTextureEnable;
	bool	isLineVisible;


};


#endif // !SCENENODE_H_
#pragma once

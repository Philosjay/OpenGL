#ifndef BOTTON_H_
#define BOTTON_H_

#include "Widget.h"

class Botton:public Widget
{
public:
	Botton();

	enum ToolSet
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


		ToolCount,
	};
	enum LineWidthSet
	{
		Width1,
		Width2,
		Width3,
		Width4,

		WidthCount,
	};
	enum ColorSet
	{
		Red,
		Green,
		Blue,
		Yellow,
		Orange,
		White,
		Black,
		Purple ,

		ColorCount,
	};
	enum Menu
	{
		Save,
		Help,

		MenuCount,
	};

	virtual void	setActive(bool isActive);
	virtual	bool	isWidgetActive(int x, int y);
	void			setType(Menu i);
	void			setType(ToolSet i);
	void			setType(LineWidthSet i);
	void			setType(Color i);
private:
	bool	isActive;
	int		bottonType;
};


#endif // !BOTTON_H_
#pragma once

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
		Grey,

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
private:
	bool	isActive;
};
Botton::Botton():
	Widget(),
	isActive(false)
{
}

inline void Botton::setActive(bool isActive)
{
	this->isActive = isActive;
	if (isActive) {
		mLayers[Layer::Buttom]->setColor(Color::Grey2);
	}
	else {
		mLayers[Layer::Buttom]->setColor(Color::Grey);
	}

}
inline bool Botton::isWidgetActive(int x, int y)
{
	if ((x >= posX && x <= posX + sizeX) && (y >= posY&&y <= posY + sizeY)) {
		return true;
	}
	else {
		return false;
	}
	return isActive;
}
#endif // !BOTTON_H_
#pragma once

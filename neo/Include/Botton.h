#ifndef BOTTON_H_
#define BOTTON_H_

#include "Widget.h"

class Botton:public Widget
{
public:
	Botton();



	virtual void	setActive(bool isActive);
	virtual	bool	isWidgetActive(int x, int y);
	void			setType(int i);
	bool			isGrabbed(int x, int y);

	bool	isActive;
	int		bottonType;
};


#endif // !BOTTON_H_
#pragma once

#ifndef BOTTON_H_
#define BOTTON_H_

#include "Widget.h"

class Botton:public Widget
{
public:
	Botton();



	virtual void	setActive(bool isActive);
	virtual	bool	isWidgetActive(int x, int y);
	void			setKey(int i);
	bool			isGrabbed(int x, int y);
	int				getKey();
	bool	isActive;
private:
	int		Key;
};


#endif // !BOTTON_H_
#pragma once

#ifndef BOTTON_H_
#define BOTTON_H_

#include "Widget.h"

class Botton:public Widget
{
public:
	Botton();



	virtual void	setActive(bool isActive);
	virtual	bool	isWidgetActive(int x, int y);
	void			setId(int i);
	bool			isGrabbed(int x, int y);
	int				getId();
	float			getValue(int index);
	void			setValue(float value, int index);
	bool	isActive;
private:
	int		id;
protected:
	float	value[10] = { 0,0,0,0,0,0,0,0,0,0 };
};


#endif // !BOTTON_H_
#pragma once

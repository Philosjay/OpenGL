#include "..\Include\Factory_Btn_Blue.h"
#include "../Include/Botton.h"

Botton * Factory_Btn_Blue::generateBotton()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1170, 190);

	float r = 0;
	float g = 0;
	float b = 1;
	//按钮赋值
	tmp->setValue(r, 0);
	tmp->setValue(g, 1);
	tmp->setValue(b, 2);
	//按钮填色
	tmp->setColor(r, g, b);
	tmp->setValue(0,0);
	tmp->setValue(0, 1);
	tmp->setValue(1, 2);
	return tmp;
}

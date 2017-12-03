#include "..\Include\Factory_Btn_Red.h"
#include "../Include/Botton.h"

Botton * Factory_Btn_Red::generateBotton()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1170, 220);

	float r = 1;
	float g = 0;
	float b = 0;
	//按钮赋值
	tmp->setValue(r, 0);
	tmp->setValue(g, 1);
	tmp->setValue(b, 2);
	//按钮填色
	tmp->setColor(r, g, b);
	return tmp;
}

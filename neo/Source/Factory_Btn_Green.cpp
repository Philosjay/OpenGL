#include "..\Include\Factory_Btn_Green.h"
#include "../Include/Botton.h"

Botton * Factory_Btn_Green::generateBotton()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1230, 220);

	float r = 0;
	float g = 1;
	float b = 0;
	//按钮赋值
	tmp->setValue(r, 0);
	tmp->setValue(g, 1);
	tmp->setValue(b, 2);
	//按钮填色
	tmp->setColor(r, g, b);
	return tmp;
}

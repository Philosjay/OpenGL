#include "..\Include\Factory_Btn_White.h"
#include "../Include/Botton.h"

Botton * Factory_Btn_White::generateBotton()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1170, 130);

	float r = 1;
	float g = 1;
	float b = 1;
	//��ť��ֵ
	tmp->setValue(r, 0);
	tmp->setValue(g, 1);
	tmp->setValue(b, 2);
	//��ť��ɫ
	tmp->setColor(r, g, b);
	return tmp;
}

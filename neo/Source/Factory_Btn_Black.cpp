#include "..\Include\Factory_Btn_Black.h"
#include "../Include/Botton.h"

Botton * Factory_Btn_Black::generateBotton()
{
	Botton* tmp = new Botton;
	tmp->setSize(60, 30);
	tmp->setPos(1230, 160);

	float r = 0;
	float g = 0;
	float b = 0;
	//��ť��ֵ
	tmp->setValue(r, 0);
	tmp->setValue(g, 1);
	tmp->setValue(b, 2);
	//��ť��ɫ
	tmp->setColor(r, g, b);
	return tmp;
}

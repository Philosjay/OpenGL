#include "../Include/Bezier.h"


Bezier::Bezier()
	:count(10000)

{

	requiredClicks = 3;
}


void Bezier::setRefPoint(int x, int y,int num)
{
		points[num][0] = x;
		points[num][1] = y;
}

inline void Bezier::draw()
{
	applyColor();
	applyLineWidth();

	VECTOR c[4];//此矩阵是P和M的积，就是控制点阵和Bezier基矩阵的乘积  
	for (int i = 0; i<2; i++)
	{
		c[3][i] = (0 - points[0][i]) + 3 * points[1][i] - 3 * points[2][i] + points[3][i];
		c[2][i] = 3 * points[0][i] - 6 * points[1][i] + 3 * points[2][i];
		c[1][i] = (0 - 3 * points[0][i]) + 3 * points[1][i];
		c[0][i] = points[0][i];
	}
	GLfloat v[2];
	GLfloat newV[2];
	GLfloat deltat = 1.0 / count;
	GLfloat t = 0.0;
	/*
	glBegin(GL_LINE_STRIP);//绘制控制曲线
	glVertex2fv(points[0]);
	glVertex2fv(points[1]);
	glVertex2fv(points[2]);
	glVertex2fv(points[3]);
	glEnd();
	*/
	glBegin(GL_LINES);
	v[0] = points[0][0]; v[1] = points[0][1];
	for (int i = 0; i<count; i++)//绘制最终结果  
	{
		t += deltat;
		newV[0] = c[0][0] + t*(c[1][0] + t*(c[2][0] + t*c[3][0]));
		newV[1] = c[0][1] + t*(c[1][1] + t*(c[2][1] + t*c[3][1]));
		glVertex2fv(v);
		glVertex2fv(newV);
		v[0] = newV[0]; v[1] = newV[1];
	}
	glEnd();
	//	glFlush();x
}


void Bezier::setEndPos(int x, int y)
{
	int n = requiredClicks;

	switch (n)
	{
	case 3:
		setRefPoint(x, y, 0);
		setRefPoint(x, y, 1);
		setRefPoint(x, y, 2); 
		setRefPoint(x, y, 3);

		break;
	case 2:
		setRefPoint(x, y, 3);
		setRefPoint(x, y, 2);
		break;
	case 1:
		setRefPoint(x, y, 1);
		break;
	case 0:
		setRefPoint(x, y, 2);
		break;
	default:
		break;
	}
}

inline void Bezier::setStatus(int status)
{
	mStatus = status;
}
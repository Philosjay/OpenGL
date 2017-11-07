#ifndef BEZIER_H_
#define BEZIER_H_

#include "Graph.h"

class Bezier:public Graph
{
public:
	enum CurveStatus
	{
		init,
		ref1,
		ref2,
		end,
	};
	Bezier();
	
	void	setStartPoint(int x, int y);
	void	setEndPoint(int x, int y);
	void	setRef1Point(int x, int y);
	void	setRef2Point(int x, int y);
	void	draw();
	void	preview(int type, int color, int lineWidth,
		int curPosX, int curPosY, int motionPosX, int motionPosY);
	void	updateStatus();
	virtual int getStatus();

private:


	typedef GLfloat VECTOR[2];
	int		count;
	VECTOR points[4];
	int		mStatus;
	bool	isSettingRef1;

	void	setStatus(int status);
};

Bezier::Bezier()
	:count(10000)
	,mStatus(init)
{
}

inline void Bezier::setStartPoint(int x, int y)
{
	points[0][0] = x;
	points[0][1] = y;

}

inline void Bezier::setEndPoint(int x, int y)
{
	points[3][0] = x;
	points[3][1] = y;
}

inline void Bezier::setRef1Point(int x, int y)
{
	points[1][0] = x;
	points[1][1] = y;
}

inline void Bezier::setRef2Point(int x, int y)
{
	points[2][0] = x;
	points[2][1] = y;
}

inline void Bezier::draw()
{
	points[3][0] = motionPosX;
	points[3][1] = motionPosY;

	points[0][0] = curPosX;
	points[0][1] = curPosY;


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



	switch (mColor)
	{
	case Color::Red:
		glColor3f(1, 0, 0);
		break;
	case Color::Green:
		glColor3f(0, 1, 0);
		break;
	case Color::Blue:
		glColor3f(0, 0, 1);
		break;
	case Color::Yellow:
		glColor3f(1, 1, 0);
		break;
	case Color::Black:
		glColor3f(0, 0, 0);
		break;
	case Color::Purple:
		glColor3f(1, 0, 1);
		break;
	case Color::Orange:
		glColor3f(1, 0.5, 0);
		break;
	case Color::White:
		glColor3f(1, 1, 1);
		break;
	case Color::Grey:
		glColor3f(0.8, 0.8, 0.8);
		break;
	case Color::Grey2:
		glColor3f(0.5, 0.5, 0.5);
		break;
	default:
		break;
	}
	glLineWidth(mLineWidth);
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

inline void Bezier::preview(int type, int color, int lineWidth, int curPosX, int curPosY, int motionPosX, int motionPosY)
{
	setType(type);
	setColor(color);
	setLineWidth(lineWidth);


	static float disToStart=0;
	static float disToEnd = 0;

	switch (mStatus)
	{
	case init:
		setStartPoint(curPosX, curPosY);
		setEndPoint(motionPosX, motionPosY);

		setCurPos(curPosX, curPosY);
		setMotionPos(motionPosX, motionPosY);
		setRef1Point(curPosX, curPosY);
		setRef2Point(motionPosX, motionPosY);


		break;
	case ref1:
		disToStart = sqrtf(((float)curPosX - (float)points[0][0])*((float)curPosX - (float)points[0][0])
			+ ((float)curPosY - (float)points[0][1])*((float)curPosY - (float)points[0][1]));
		disToEnd = sqrtf(((float)curPosX - (float)points[3][0])*((float)curPosX - (float)points[3][0])
			+ ((float)curPosY - (float)points[3][1])*((float)curPosY - (float)points[3][1]));
		if (disToStart <= disToEnd)
		{
			setRef1Point(motionPosX, motionPosY);
		}
		else {
			setRef2Point(motionPosX, motionPosY);
		}
		break;
	case ref2:
		if (disToStart <= disToEnd)
		{
			setRef2Point(motionPosX, motionPosY);
		}
		else {
			setRef1Point(motionPosX, motionPosY);
		}
		break;
	default:
		break;
	}

}

inline void Bezier::updateStatus()
{
	if (mStatus == end) {
		mStatus = init;
	}
	else if (mStatus == init) {
		mStatus = ref1;
	}
	else if (mStatus == ref1) {
		mStatus = ref2;
	}
	else if (mStatus == ref2) {
		mStatus = end;
	}
}

inline int Bezier::getStatus()
{
	return mStatus;
}

inline void Bezier::setStatus(int status)
{
	mStatus = status;
}

#endif // !BEZIER_H_
#pragma once

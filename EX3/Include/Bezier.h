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


#endif // !BEZIER_H_
#pragma once

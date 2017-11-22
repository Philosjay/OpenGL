#include "../Include/Polygon.h"

#include <math.h>

double ABS_DOUBLE_0 = 0.0001;

Polygon::Polygon()
	: n(20)
{
	requiredClicks = n;
}

void Polygon::setRefPoint(int x, int y, int num)
{
	points[num][0] = x;
	points[num][1] = y;
}

void Polygon::draw()
{


	glPushMatrix();

	applyColor();
	applyLineWidth();

	glBegin(GL_POLYGON);
	for (int i = 0; i < n; i++)
	{
		glVertex3f(points[i][0], points[i][1], 0);
	}
	glEnd();

	glPopMatrix();

}

void Polygon::move(int x, int y)
{
	for (int i = 0; i < n; i++) {
		points[i][0] += x;
		points[i][1] += y;
	}
}

bool Polygon::isGrabbed(int x, int y)
{
	for (int i = 0; i < n - 2; i++) {
		Point a, b, c, d;
		a.x = points[i][0];
		a.y = points[i][1];
		b.x = points[i+1][0];
		b.y = points[i+1][1];
		c.x = points[i+2][0];
		c.y = points[i+2][1];
		d.x = x;
		d.y = y;
		for (int i = 0; i < n; i++)
		{
			glVertex3f(points[i][0], points[i][1], 0);
			printf("%d   %d  \n", points[i][0], points[i][1]);
		}
		printf("----------------------------------------------");
		double Sabc = getTriangleArea(a, b, c);
		double Sadb = getTriangleArea(a, d, b);
		double Sbdc = getTriangleArea(b, d, c);
		double Sadc = getTriangleArea(a, d, c);

		double sumSuqar = Sadb + Sbdc + Sadc;

		if (-ABS_DOUBLE_0 < (Sabc - sumSuqar) && (Sabc - sumSuqar) < ABS_DOUBLE_0) {
			if (ABS_DOUBLE_0 < Sabc) {
				return true;
			}
			
		}
	}
	return false;
}
double Polygon::getTriangleArea(Point p0, Point p1, Point p2) {
	Point ab, ac;
	ab.x = p0.x - p1.x;
	ab.y = p0.y - p1.y;
	ac.x = p2.x - p1.x;
	ac.y = p2.y - p1.y;

	double	tmp = ((ab.x*ac.y - ab.y*ac.x) / 2.0);
	double   S = tmp > 0 ? tmp : -tmp;

	return S;
}
void Polygon::setEndPos(int x, int y)
{
	switch (requiredClicks)
	{
	case 20:
		for (int i = 0; i < 20; i++) {
			setRefPoint(x, y, i);
		}
		break;
	case 19:
		setRefPoint(x, y, 19);
		break;
	case 18:
		setRefPoint(x, y, 18);
		break;
	case 17:
		setRefPoint(x, y, 17);
		break;
	case 16:
		setRefPoint(x, y, 16);
		break;
	case 15:
		setRefPoint(x, y, 15);
		break;
	case 14:
		setRefPoint(x, y, 14);
		break;
	case 13:
		setRefPoint(x, y, 13);
		break;
	case 12:
		setRefPoint(x, y, 12);
		break;
	case 11:
		setRefPoint(x, y, 11);
		break;
	case 10:
		setRefPoint(x, y, 10);
		break;
	case 9:
		setRefPoint(x, y, 9);
		break;
	case 8:
		setRefPoint(x, y, 8);
		break;
	case 7:
		setRefPoint(x, y, 7);
		break;
	case 6:
		setRefPoint(x, y, 6);
		break;
	case 5:
		setRefPoint(x, y, 5);
		break;
	case 4:
		setRefPoint(x, y, 4);
		break;
	case 3:
		setRefPoint(x, y, 3);
		break;
	case 2:
		setRefPoint(x, y, 2);
	case 1:
		setRefPoint(x, y, 1);
		break;
	case 0:
		setRefPoint(x, y, 0);
	default:
		break;
	}
}

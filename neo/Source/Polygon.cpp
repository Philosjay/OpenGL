#include "../Include/Polygon.h"

#include <math.h>

double ABS_DOUBLE_0 = 0.0001;

Polygon::Polygon()
	: n(18)
{
}

void Polygon::setRefPoint(int x, int y, int num)
{
	points[num][0] = x;
	points[num][1] = y;
}

Point Polygon::getRefPoint(int num)
{
	Point tmp;
	tmp.x = points[num][0];
	tmp.y = points[num][1];
	return tmp;
}

void Polygon::draw()
{


	glPushMatrix();

	applyColor();
	applyLineWidth();

	glBegin(GL_LINE_STRIP);
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
void Polygon::setMaxRefNum(int x)
{
	n = x;
}
int Polygon::getMaxRefNum()
{
	return n;
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

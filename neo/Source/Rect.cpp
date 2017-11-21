#include "../Include/Rect.h"


Rect::Rect()
{
}
bool Rect::isGrabbed(int x, int y)
{
	if (x < centerX+length/2 && x > centerX - length/2) {
		if (y<centerY + height / 2 && y> centerY - height / 2) {
			return true;
		}
		
	}
	return false;
}

inline void Rect::draw()
{
	glPushMatrix();

	//…Ë÷√—’…´
	switch (SceneNode::mColor)
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

	points[0][0] = centerX - length / 2;
	points[0][1] = centerY - height / 2;
	points[1][0] = centerX + length / 2;
	points[1][1] = centerY - height / 2;
	points[2][0] = centerX + length / 2;
	points[2][1] = centerY + height / 2;
	points[3][0] = centerX - length / 2;
	points[3][1] = centerY + height / 2;

	glLineWidth(mLineWidth * 2);
	glBegin(GL_LINES);
	glVertex3f(points[0][0], points[0][1], 0);
	glVertex3f(points[1][0], points[1][1], 0);

	glVertex3f(points[1][0] - mLineWidth, points[1][1], 0);
	glVertex3f(points[2][0] - mLineWidth, points[2][1], 0);

	glVertex3f(points[2][0], points[2][1], 0);
	glVertex3f(points[3][0], points[3][1], 0);

	glVertex3f(points[3][0]+ mLineWidth, points[3][1], 0);
	glVertex3f(points[0][0]+ mLineWidth, points[0][1], 0);

	glEnd();

	glPopMatrix();
}


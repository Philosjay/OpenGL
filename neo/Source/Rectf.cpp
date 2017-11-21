#include "../Include/Rectf.h"

Rectf::Rectf()
{
}
bool Rectf::isGrabbed(int x, int y)
{
	if (x < centerX + length / 2 && x > centerX - length / 2) {
		if (y<centerY + height / 2 && y> centerY - height / 2) {
			return true;
		}

	}
	return false;
}
inline void Rectf::draw()
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

	if (isTextureEnable) {
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, texture);
	}

	glLineWidth(mLineWidth * 2);
	glBegin(GL_QUADS);
	glTexCoord2f(0.0f, 0.0f);
	glVertex3f(points[0][0], points[0][1], 0);
	glTexCoord2f(1.0f, 0.0f);
	glVertex3f(points[1][0], points[1][1], 0);
	glTexCoord2f(1.0f, 1.0f);
	glVertex3f(points[2][0], points[2][1], 0);
	glTexCoord2f(0.0f, 1.0f);
	glVertex3f(points[3][0], points[3][1], 0);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	if (isLineVisible) {
		glColor3f(0.0, 0.0, 0.0);
		glLineWidth(1);
		glBegin(GL_LINES);
		glVertex3f(points[0][0], points[0][1], 0);
		glVertex3f(points[1][0] , points[1][1], 0);
		glVertex3f(points[1][0] , points[1][1], 0);
		glVertex3f(points[2][0], points[2][1], 0);
		glVertex3f(points[2][0], points[2][1], 0);
		glVertex3f(points[3][0], points[3][1], 0);
		glVertex3f(points[3][0], points[3][1], 0);
		glVertex3f(points[0][0], points[0][1], 0);
		glEnd();
	}
	glPopMatrix();
}


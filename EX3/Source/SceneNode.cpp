#include "../Include/SceneNode.h"
#include <iostream>

SceneNode::SceneNode() :
	Object(),
	next(NULL),
	isLineVisible(true),
	isTextureEnable(false)
{
}
void SceneNode::setType(Type type)
{
	mType = type;
}
void SceneNode::setColor(Color color)
{
	mColor = color;
}
void SceneNode::setSize(int x, int y)
{
	sizeX = x;
	sizeY = y;
}
inline void SceneNode::setLineWidth(int width)
{
	//Do nothing by default
}
void SceneNode::draw()
{

	glPushMatrix();

	//������ɫ
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

	//��������
	switch (mType)
	{
	case Type::Triangle:
		glBegin(GL_TRIANGLES);
		glVertex3f(posX, posY, 0);
		glVertex3f(posX + sizeX, posY, 0);
		glVertex3f(posX + sizeX, posY + sizeY, 0);
		glEnd();
		break;
	case Type::Rect:
		if (isTextureEnable) {
			glEnable(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, texture);
		}

		glBegin(GL_QUADS);
		glTexCoord2f(0.0f, 0.0f);
		glVertex3f(posX, posY, 0);
		glTexCoord2f(1.0f, 0.0f);
		glVertex3f(posX + sizeX, posY, 0);
		glTexCoord2f(1.0f, 1.0f);
		glVertex3f(posX + sizeX, posY + sizeY, 0);
		glTexCoord2f(0.0f, 1.0f);
		glVertex3f(posX, posY + sizeY, 0);
		glEnd();
		glDisable(GL_TEXTURE_2D);
		if (isLineVisible) {
			glColor3f(0.0, 0.0, 0.0);
			glLineWidth(1);
			glBegin(GL_LINES);
			glVertex3f(posX, posY, 0);
			glVertex3f(posX + sizeX, posY, 0);
			glVertex3f(posX + sizeX, posY, 0);
			glVertex3f(posX + sizeX, posY + sizeY, 0);
			glVertex3f(posX + sizeX, posY + sizeY, 0);
			glVertex3f(posX, posY + sizeY, 0);
			glVertex3f(posX, posY + sizeY, 0);
			glVertex3f(posX, posY, 0);
			glEnd();
		}
		break;
		/*	case Type::Line:
		glBegin(GL_LINES);
		glVertex3f(curPosX, curPosY, 0);
		glVertex3f(motionPosX, motionPosY, 0);
		glEnd();
		break;
		*/
	default:
		break;
	}

	glPopMatrix();
	//	glFlush();
}

inline void SceneNode::setActive(bool)
{
	//do nothing by default
}

inline void SceneNode::loadTexture(char *file)
{
	GLint width, height, total_bytes;
	GLubyte* pixels = 0;
	GLuint last_texture_ID, texture_ID = 0;

	//���ļ������ʧ�ܣ�����
	FILE* pFile;
	fopen_s(&pFile, file, "rb");
	if (pFile == 0)
	{
		printf("Can not open file %s...", file);
		return;
	}

	//��ȡ�ļ���ͼ��Ŀ�Ⱥ͸߶�
	fseek(pFile, 0x0012, SEEK_SET);
	fread(&width, 4, 1, pFile);
	fread(&height, 4, 1, pFile);
	fseek(pFile, BMP_Header_Length, SEEK_SET);

	//����ÿ��������ռ�ֽ����������ݴ����ݼ����������ֽ���
	{
		GLint line_bytes = width * 3;
		while (line_bytes % 4 != 0)
		{
			++line_bytes;
		}
		total_bytes = line_bytes * height;
	}

	//�����������ֽ��������ڴ�
	pixels = (GLubyte*)malloc(total_bytes);
	if (pixels == 0)
	{
		printf("Pixeles in file %s is NULL...", file);
		fclose(pFile);
		return;
	}

	//��ȡ��������
	if (fread(pixels, total_bytes, 1, pFile) <= 0)
	{
		free(pixels);
		fclose(pFile);
		return;
	}

	// ����һ���µ�������
	glGenTextures(1, &texture_ID);
	if (texture_ID == 0)
	{
		free(pixels);
		fclose(pFile);
		return;
	}

	// ���µ������������������������
	// �ڰ�ǰ���Ȼ��ԭ���󶨵������ţ��Ա��������лָ�
	glGetIntegerv(GL_TEXTURE_BINDING_2D, (GLint*)&last_texture_ID);
	glBindTexture(GL_TEXTURE_2D, texture_ID);

	//��������趨
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//��ɫ���ģʽ
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);
	glBindTexture(GL_TEXTURE_2D, last_texture_ID);

	// ֮ǰΪpixels������ڴ����ʹ��glTexImage2D�Ժ��ͷ�
	// ��Ϊ��ʱ���������Ѿ���OpenGL���б�����һ�ݣ����ܱ����浽ר�ŵ�ͼ��Ӳ���У�
	free(pixels);



	isTextureEnable = true;
	texture = texture_ID;

}
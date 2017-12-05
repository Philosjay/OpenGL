#include "../Include/SceneNode.h"
#include <iostream>

SceneNode::SceneNode() :
	next(NULL),
	isLineVisible(false),
	isTextureEnable(false),
	isFilled(false),
	defaultCenter(true)
{
}
void SceneNode::setSize(float x, float y)
{
}
void SceneNode::moveTo(int x, int y)
{
	startPosX = x;
	startPosY = y;
}
void SceneNode::move(int x, int y)
{
	startPosX += x;
	startPosY += y;
	endPosX += x;
	endPosY += y;
}
void SceneNode::setEndPos(int x, int y)
{
	endPosX = x;
	endPosY = y;
}
inline void SceneNode::setLineWidth(int width)
{
	mLineWidth = width;
}
void SceneNode::applyColor()
{	//������ɫ
	glColor3f(mColor.r, mColor.g, mColor.b);
}
void SceneNode::applyLineWidth()
{
	glLineWidth(mLineWidth * 2);
}
void SceneNode::setLineVisible(bool is)
{
	this->isLineVisible = is;
}
void SceneNode::setCenterPos(int x, int y)
{
	centerX = x;
	centerY = y;
	defaultCenter = false;
}
void SceneNode::setStartPos(int x, int y)
{
	startPosX = x;
	startPosY = y;
}
Point SceneNode::getCenterPos()
{
	Point tmp;
	tmp.x = centerX;
	tmp.y = centerY;
	return tmp;
}
Point SceneNode::getStartPos()
{
	Point tmp;
	tmp.x = startPosX;
	tmp.y = startPosY;
	return tmp;
}
Point SceneNode::getEndPos()
{
	Point tmp;
	tmp.x = endPosX;
	tmp.y = endPosY;
	return tmp;
}
Color SceneNode::getColor()
{
	return mColor;
}
bool SceneNode::getFillStatus()
{
	return isFilled;
}
int SceneNode::getLineWidth()
{
	return mLineWidth;
}
void SceneNode::draw()
{
	//do nothing by default	
}


void SceneNode::loadTexture(char *file)
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

void SceneNode::setFill(bool isFill)
{
	isFilled = isFill;
}

bool SceneNode::isDefaultCenter()
{
	return defaultCenter;
}

void SceneNode::setColor(float r, float g, float b)
{
	mColor.r = r;
	mColor.g = g;
	mColor.b = b;
}

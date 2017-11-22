#include "../Include/SceneNode.h"
#include "../Include/settingList.h"
#include <iostream>

SceneNode::SceneNode() :
	next(NULL),
	isLineVisible(false),
	isTextureEnable(false)
{
}
void SceneNode::setSize(float x, float y)
{
	length = x;
	height = y;
}
void SceneNode::moveTo(int x, int y)
{
	//在分别移动两组参考点
	startPosX = x;
	startPosY = y;
	endPosX = startPosX + length;
	endPosY = startPosY - height;
}
void SceneNode::move(int x, int y)
{
	//在分别移动两组参考点
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
{	//设置颜色
	switch (SceneNode::mColor)
	{
	case ColorSet::Red:
		glColor3f(1, 0, 0);
		break;
	case ColorSet::Green:
		glColor3f(0, 1, 0);
		break;
	case ColorSet::Blue:
		glColor3f(0, 0, 1);
		break;
	case ColorSet::Yellow:
		glColor3f(1, 1, 0);
		break;
	case ColorSet::Black:
		glColor3f(0, 0, 0);
		break;
	case ColorSet::Purple:
		glColor3f(1, 0, 1);
		break;
	case ColorSet::Orange:
		glColor3f(1, 0.5, 0);
		break;
	case ColorSet::White:
		glColor3f(1, 1, 1);
		break;
	case ColorSet::Grey:
		glColor3f(0.8, 0.8, 0.8);
		break;
	case ColorSet::Grey2:
		glColor3f(0.5, 0.5, 0.5);
		break;
	default:
		break;
	}
}
void SceneNode::applyLineWidth()
{
	glLineWidth(mLineWidth * 2);
}
void SceneNode::setLineVisible(bool is)
{
	this->isLineVisible = is;
}
void SceneNode::draw()
{
	//do nothing by default	
}


inline void SceneNode::loadTexture(char *file)
{
	GLint width, height, total_bytes;
	GLubyte* pixels = 0;
	GLuint last_texture_ID, texture_ID = 0;

	//打开文件，如果失败，返回
	FILE* pFile;
	fopen_s(&pFile, file, "rb");
	if (pFile == 0)
	{
		printf("Can not open file %s...", file);
		return;
	}

	//读取文件中图象的宽度和高度
	fseek(pFile, 0x0012, SEEK_SET);
	fread(&width, 4, 1, pFile);
	fread(&height, 4, 1, pFile);
	fseek(pFile, BMP_Header_Length, SEEK_SET);

	//计算每行像素所占字节数，并根据此数据计算总像素字节数
	{
		GLint line_bytes = width * 3;
		while (line_bytes % 4 != 0)
		{
			++line_bytes;
		}
		total_bytes = line_bytes * height;
	}

	//根据总像素字节数分配内存
	pixels = (GLubyte*)malloc(total_bytes);
	if (pixels == 0)
	{
		printf("Pixeles in file %s is NULL...", file);
		fclose(pFile);
		return;
	}

	//读取像素数据
	if (fread(pixels, total_bytes, 1, pFile) <= 0)
	{
		free(pixels);
		fclose(pFile);
		return;
	}

	// 分配一个新的纹理编号
	glGenTextures(1, &texture_ID);
	if (texture_ID == 0)
	{
		free(pixels);
		fclose(pFile);
		return;
	}

	// 绑定新的纹理，载入纹理并设置纹理参数
	// 在绑定前，先获得原来绑定的纹理编号，以便在最后进行恢复
	glGetIntegerv(GL_TEXTURE_BINDING_2D, (GLint*)&last_texture_ID);
	glBindTexture(GL_TEXTURE_2D, texture_ID);

	//纹理过滤设定
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//颜色混合模式
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pixels);
	glBindTexture(GL_TEXTURE_2D, last_texture_ID);

	// 之前为pixels分配的内存可在使用glTexImage2D以后释放
	// 因为此时像素数据已经被OpenGL另行保存了一份（可能被保存到专门的图形硬件中）
	free(pixels);



	isTextureEnable = true;
	texture = texture_ID;

}
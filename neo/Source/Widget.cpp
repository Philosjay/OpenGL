#include "../Include/Widget.h"
#include "../Include/Rect.h"

Widget::Widget() 
{
	mLayers[Layer::Buttom] = new class Rect;
	mLayers[Layer::Buttom]->setFill(true);
	mLayers[Layer::Buttom]->setColor(0.8, 0.8, 0.8);


	mLayers[Layer::Top] = new class Rect;
	mLayers[Layer::Top]->setFill(true);
	mLayers[Layer::Top]->setColor(0,1,0);
}
void Widget::loadTexture(char *file)
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



	mLayers[Layer::Top]->setTextureEnable(true);
	mLayers[Layer::Top]->setTexture(texture_ID);
}
void Widget::setSize(int x, int y)
{
	//留下备份，在setPos内调节两个图形的位置
	layerSize[Layer::Buttom].x = x;
	layerSize[Layer::Buttom].y = y;
	layerSize[Layer::Top].x = x*0.8;
	layerSize[Layer::Top].y = y*0.8;

	mLayers[Layer::Buttom]->setSize(x, y);
	mLayers[Layer::Top]->setSize(x*0.8, y*0.8);

}
void Widget::setPos(int x, int y)
{
	int width = layerSize[Layer::Buttom].x;
	int height = layerSize[Layer::Buttom].y;
	mLayers[Layer::Buttom]->moveTo(x, y);
	mLayers[Layer::Buttom]->setLineVisible(true);

	width = layerSize[Layer::Top].x;
	height = layerSize[Layer::Top].y;
	mLayers[Layer::Top]->moveTo(x + (layerSize[Layer::Buttom].x - layerSize[Layer::Top].x) / 2,
		y - (layerSize[Layer::Buttom].y - layerSize[Layer::Top].y)/2 );
	mLayers[Layer::Top]->setLineVisible(true);
}
void Widget::draw()
{
	for (int i = 0; i < Layer::LayerCount; i++) {
		mLayers[i]->draw();
	}
}

void Widget::setColor(float r, float g, float b)
{
	mLayers[Layer::Top]->setColor(r, g, b);
}

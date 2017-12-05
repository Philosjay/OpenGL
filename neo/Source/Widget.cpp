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



	mLayers[Layer::Top]->setTextureEnable(true);
	mLayers[Layer::Top]->setTexture(texture_ID);
}
void Widget::setSize(int x, int y)
{
	//���±��ݣ���setPos�ڵ�������ͼ�ε�λ��
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

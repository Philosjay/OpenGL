#ifndef SCENENODE_H_
#define SCENENODE_H_

#include <GL/glut.h>


#define BMP_Header_Length 54

//�����㷨������ͼ��λ�á���С���ṩ������ɫ���߿���ͼ�ķ������Լ��ƶ��ķ���
class SceneNode
{
public:
	SceneNode();

	void			setColor(int color) { mColor = color; }
	void			setSize(float length, float height);
	virtual	void			moveTo(int x, int y);
	virtual void			move(int x, int y);
	virtual void	setEndPos(int x, int y);
	virtual void	setLineWidth(int width);
	void			setLineVisible(bool is);
	void	setTexture(GLuint texture) { this->texture = texture; }
	void	setTextureEnable(bool isAble) { isTextureEnable = isAble; }

	virtual		void	draw();
	virtual		void	loadTexture(char *file);
private:
	SceneNode*		next;
protected:
	//��ͼ���ε����϶���
	int startPosX, startPosY;
	//��ͼ���ε����¶���
	int endPosX,endPosY;

	int length;
	int height;

	int		mColor;
	int		mLineWidth;
	GLuint  texture;
	bool	isTextureEnable;
	bool	isLineVisible;

	void				applyColor();
	void				applyLineWidth();
};


#endif // !SCENENODE_H_
#pragma once

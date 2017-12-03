#ifndef SCENENODE_H_
#define SCENENODE_H_

#include <GL/glut.h>

typedef struct
{
	float x;
	float y;
}Point;

typedef  struct
{
	float r; float g; float b;
}Color;

#define BMP_Header_Length 54

//�����㷨������ͼ��λ�á���С���ṩ������ɫ���߿���ͼ�ķ������Լ��ƶ��ķ���
class SceneNode
{
public:

	SceneNode();

	virtual void			setSize(float length, float height);
	virtual	void			moveTo(int x, int y);
	virtual void			move(int x, int y);
	virtual void	setEndPos(int x, int y);
	virtual void	setLineWidth(int width);
	void			setLineVisible(bool is);
	void	setTexture(GLuint texture) { this->texture = texture; }
	void	setTextureEnable(bool isAble) { isTextureEnable = isAble; }
	void	setCenterPos(int x, int y);
	void	setStartPos(int x, int y);
	Point	getCenterPos();
	Point	getStartPos();
	Point	getEndPos();
	Color	getColor();
	bool	getFillStatus();
	int		getLineWidth();

	virtual		void	draw();
	virtual		void	loadTexture(char *file);
	void		setFill(bool isFill);
	bool		isDefaultCenter();
	void		setColor(float r, float g, float b);


private:
	SceneNode*		next;
	
	Color mColor;
protected:
	//��ͼ���ε����϶���
	int startPosX, startPosY;
	//��ͼ���ε����¶���
	int endPosX,endPosY;
	float centerX;
	float centerY ;


	int		mLineWidth;
	GLuint  texture;
	bool	isTextureEnable;
	bool	isLineVisible;

	bool			isFilled;
	bool			defaultCenter;
	void				applyColor();
	void				applyLineWidth();
};


#endif // !SCENENODE_H_
#pragma once

#ifndef WIDGET_H_
#define WIDGET_H_

#include <vector>

#include "SceneNode.h"

class Widget :public SceneNode
{
public:
	Widget();

	void loadTexture();
	virtual	void	setSize(int x, int y);
	virtual	void	setPos(int x, int y);
	virtual	void	draw();
private:

	struct LayerSize
	{
		int x, y;
	};

protected:
	enum Layer
	{
		Buttom,
		Top,
		LayerCount,
	};

	SceneNode*			mLayers[Layer::LayerCount];
	LayerSize			layerSize[Layer::LayerCount];
};
Widget::Widget():
	SceneNode()
{
	mLayers[Layer::Buttom] = new SceneNode;
	mLayers[Layer::Buttom]->setType(Type::Rect);
	mLayers[Layer::Buttom]->setColor(Color::Grey);
/*
	mLayers[Layer::Mid] = new SceneNode;
	mLayers[Layer::Mid]->setType(Type::Rect);
	mLayers[Layer::Mid]->setColor(Color::Grey);
*/
	mLayers[Layer::Top] = new SceneNode;
	mLayers[Layer::Top]->setType(Type::Rect);
	mLayers[Layer::Top]->setColor(Color::Green);
}
inline void Widget::loadTexture()
{

}
inline void Widget::setSize(int x, int y)
{
	sizeX = x;
	sizeY = y;

	mLayers[Layer::Buttom]->setSize(x, y);
//	mLayers[Layer::Mid]->setSize(x*0.9, y*0.9);
	mLayers[Layer::Top]->setSize(x*0.8, y*0.8);

	layerSize[Layer::Buttom].x = x;
	layerSize[Layer::Buttom].y = y;
//	layerSize[Layer::Mid].x = x*0.9;
//	layerSize[Layer::Mid].y = y*0.9;
	layerSize[Layer::Top].x = x*0.8;
	layerSize[Layer::Top].y = y*0.8;

}
inline void Widget::setPos(int x, int y)
{
	posX = x;
	posY = y;

	mLayers[Layer::Buttom]->setPos(x, y);

//	mLayers[Layer::Mid]->setPos(x+ (layerSize[Layer::Buttom].x-layerSize[Layer::Mid].x)/2,
//								y+(layerSize[Layer::Buttom].y - layerSize[Layer::Mid].y)/2);

	mLayers[Layer::Top]->setPos(x + (layerSize[Layer::Buttom].x - layerSize[Layer::Top].x)/2, 
								y + (layerSize[Layer::Buttom].y - layerSize[Layer::Top].y)/2);
}
inline void Widget::draw()
{
	for (int i = 0; i < Layer::LayerCount; i++) {
		mLayers[i]->draw();
	}
}

#endif // !WIDGET_H_
#pragma once

#ifndef WIDGET_H_
#define WIDGET_H_

#include <vector>

#include "SceneNode.h"

class Widget :public SceneNode
{
public:
	Widget();

	void			loadTexture(char *file);
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


#endif // !WIDGET_H_
#pragma once

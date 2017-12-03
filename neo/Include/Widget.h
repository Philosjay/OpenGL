#ifndef WIDGET_H_
#define WIDGET_H_

#include <vector>

#include "Graph.h"

class Widget :public Graph
{
public:
	Widget();

	void			loadTexture(char *file);
	virtual	void	setSize(int x, int y);
	virtual	void	setPos(int x, int y);
	virtual	void	draw();
	void			setColor(float r, float g, float b);
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

	Graph*				mLayers[Layer::LayerCount];
	LayerSize			layerSize[Layer::LayerCount];
};


#endif // !WIDGET_H_
#pragma once

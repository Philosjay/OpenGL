#include "../Include/World.h"

#include "../Include/Graph.h"
#include "../Include/Eraser.h"
#include "../Include/Pen.h"
#include "../Include/settingList.h"


World::World() :
	mGraphCount(0)
{
}

 void World::addGraph(Graph* g)
{
	 mGraphs[mGraphCount++] = g;
}
void World::show()
{
	//已储存的图形
	for (int i = 0; i < mGraphCount; i++) {
		if (mGraphs[i] != NULL)
			mGraphs[i]->draw();
	}


}

Graph * World::grab(int x, int y)
{
	for (int i = mGraphCount-1; i >= 0; i--) {
		if (mGraphs[i] != NULL) {
			if (mGraphs[i]->isGrabbed(x, y)) {
				return mGraphs[i];
			}
		}
	}
	return NULL;
}

int World::drawConstantGraph(int x0, int y0, int x1, int y1, int type, int color, int size)
{
	
	//当两点间距小于一定范围
	if (sqrtf(((float)x1 - (float)x0)*((float)x1 - (float)x0)
		+ ((float)y1 - (float)y0)*((float)y1 - (float)y0)) <= (float)size) {
		Graph* mTmp = NULL;
		//画图
		switch (type)
		{
		case ToolSet::eraser:
			mTmp = new Eraser;
			break;
		case ToolSet::pen:
			mTmp = new Pen;
			break;
		default:
			break;
		}
		mTmp->setEndPos((x1 + x0) / 2, (y1 + y0) / 2);
		mTmp->setLineWidth(size);
		mTmp->setColor(color);
		mGraphs[mGraphCount++] = mTmp;
		return 0;
	}
	//前半段
	drawConstantGraph(x0, y0, (x1 + x0) / 2, (y1 + y0) / 2, type, color, size);

	//后半段
	drawConstantGraph((x1 + x0) / 2, (y1 + y0) / 2, x1, y1, type, color, size);
	
}

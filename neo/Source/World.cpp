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
	//�Ѵ����ͼ��
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


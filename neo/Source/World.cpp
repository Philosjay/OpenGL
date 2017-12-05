#include "../Include/World.h"

#include "../Include/Graph.h"
#include "../Include/Eraser.h"
#include "../Include/Pen.h"


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
	//ÒÑ´¢´æµÄÍ¼ÐÎ
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

int World::getTotalGraphCount()
{
	return mGraphCount;
}

Graph * World::getGraph(int index)
{
	return mGraphs[index];
}

void World::removeAllGraphs()
{
	for (int i = 0; i < mGraphCount; i++) {
		delete mGraphs[i];
	}
	mGraphCount = 0;
}


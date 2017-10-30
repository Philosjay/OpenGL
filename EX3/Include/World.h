#ifndef WORLD_H_
#define WORLD_H_

#include <GL/glut.h>

#include "Graph.h"

class World
{
public:
	World();

	void previewGraph(int type, int color, int curPosX, int curPosY, int motionPosX, int motionPosY);
	void saveGraph();
	void show();
private:
	Graph*	mGraphs[100];
	Graph*	mTmp;
	int		mGraphCount;
};

World::World():
	mGraphCount(0)
{
	mTmp = new Graph;
}

inline void World::previewGraph(int type,int color, 
								int curPosX, int curPosY, int motionPosX, int motionPosY)
{

	mTmp->setType(type);
	mTmp->setCurPos(curPosX, curPosY);
	mTmp->setMotionPos(motionPosX, motionPosY);
	mTmp->setColor(color);

}

inline void World::saveGraph()
{
	mGraphs[mGraphCount++] = mTmp;
	mTmp = new Graph;
}

inline void World::show()
{
	mTmp->draw();
	for (int i = 0; i < mGraphCount; i++) {
		mGraphs[i]->draw();
	}
}



#endif // WORLD_H_

#pragma once

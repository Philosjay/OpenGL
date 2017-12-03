#include "..\Include\StorerForRect.h"
#include "../Include/Rect.h"
StorerForRect::StorerForRect()
{
}

void StorerForRect::save(Graph * g, ofstream & f)
{
	f << "@" << endl;
	f << g->getId() << endl;
	f << g->getStartPos().x<< endl;
	f << g->getStartPos().y << endl;
	f << g->getWidth() << endl;
	f << g->getHeight() << endl;
	f << g->getFillStatus() << endl;
	f << g->getLineWidth() << endl;
	f << g->getColor().r << endl;
	f << g->getColor().g << endl;
	f << g->getColor().b << endl;
	f << "#" << endl;
}

Graph * StorerForRect::load(int id, ifstream & f)
{
	Graph* tmp = new Rect;

	float startX, startY;
	float width,height;
	float r, g, b;
	bool isFilled;
	int lineWidth;

	f >> startX;
	f >> startY;
	f >> width;
	f >> height;
	f >> isFilled;
	f >> lineWidth;
	f >> r >> g >> b;

	tmp->setId(id);
	tmp->setStartPos(startX, startY);
	tmp->setSize(width, height);
	tmp->setFill(isFilled);
	tmp->setLineWidth(lineWidth);
	tmp->setColor(r, g, b);
	return tmp;
}

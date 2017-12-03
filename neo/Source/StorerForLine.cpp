#include "..\Include\StorerForLine.h"
#include "../Include/Line.h"

void StorerForLine::save(Graph * g, ofstream & f)
{
	f << "@" << endl;
	f << g->getId() << endl;
	f << g->getStartPos().x << endl;
	f << g->getStartPos().y << endl;
	f << g->getEndPos().x << endl;
	f << g->getEndPos().y << endl;
	f << g->getLineWidth() << endl;
	f << g->getColor().r << endl;
	f << g->getColor().g << endl;
	f << g->getColor().b << endl;
	f << "#" << endl;
}

Graph * StorerForLine::load(int id, ifstream & f)
{
	Graph* tmp = new Line;

	Point p1, p0;
	int lineWidth;
	float r, g, b;
	f >> p0.x;
	f >> p0.y;
	f >> p1.x;
	f >> p1.y;
	f >> lineWidth;
	f >> r >> g >> b;

	tmp->setId(id);
	tmp->setStartPos(p0.x, p0.y);
	tmp->setEndPos(p1.x, p1.y);
	tmp->setLineWidth(lineWidth);
	tmp->setColor(r, g, b);
	return tmp;
}

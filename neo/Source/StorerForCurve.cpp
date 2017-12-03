#include "..\Include\StorerForCurve.h"
#include "../Include/Bezier.h"

void StorerForCurve::save(Graph * g, ofstream & f)
{
	f << "@" << endl;
	f << g->getId() << endl;
	f << g->getRefPoint(0).x << endl;
	f << g->getRefPoint(0).y << endl;
	f << g->getRefPoint(1).x << endl;
	f << g->getRefPoint(1).y << endl;
	f << g->getRefPoint(2).x << endl;
	f << g->getRefPoint(2).y << endl;
	f << g->getRefPoint(3).x << endl;
	f << g->getRefPoint(3).y << endl;
	f << g->getLineWidth() << endl;
	f << g->getColor().r << endl;
	f << g->getColor().g << endl;
	f << g->getColor().b << endl;
	f << "#" << endl;
}

Graph * StorerForCurve::load(int id, ifstream & f)
{
	Graph* tmp = new Bezier;

	Point p1, p2, p3, p0;
	int lineWidth;
	float r, g, b;
	f >> p0.x;
	f >> p0.y;
	f >> p1.x;
	f >> p1.y;
	f >> p2.x;
	f >> p2.y;
	f >> p3.x;
	f >> p3.y;
	f >> lineWidth;
	f >> r >> g >> b;

	tmp->setId(id);
	tmp->setRefPoint(p0.x, p0.y, 0);
	tmp->setRefPoint(p1.x, p1.y, 1);
	tmp->setRefPoint(p2.x, p2.y, 2);
	tmp->setRefPoint(p3.x, p3.y, 3);
	tmp->setLineWidth(lineWidth);
	tmp->setColor(r, g, b);
	return tmp;
}

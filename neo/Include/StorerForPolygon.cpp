#include "StorerForPolygon.h"
#include "Polygon.h"

void StorerForPolygon::save(Graph * g, ofstream & f)
{
	f << "@" << endl;
	f << g->getId() << endl;
	for (int i = 0; i < g->getMaxRefNum(); i++) {
		f << g->getRefPoint(i).x << endl;
		f << g->getRefPoint(i).y << endl;
	}
	f << g->getLineWidth() << endl;
	f << g->getColor().r << endl;
	f << g->getColor().g << endl;
	f << g->getColor().b << endl;
	f << "#" << endl;
}

Graph * StorerForPolygon::load(int id, ifstream & f)
{

	Graph* tmp = new Polygon;

	Point p;
	int lineWidth;	
	float r, g, b;

	tmp->setId(id);
	for (int i = 0; i < tmp->getMaxRefNum(); i++) {
		f >> p.x;
		f >> p.y;
		tmp->setRefPoint(p.x, p.y, i);
	}
	f >> lineWidth;
	f >> r >> g >> b;
	tmp->setLineWidth(lineWidth);
	tmp->setColor(r, g, b);
	return tmp;
}

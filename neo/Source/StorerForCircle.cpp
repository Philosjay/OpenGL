#include "..\Include\StorerForCircle.h"
#include "../Include/Circle.h"

using namespace std;

StorerForCircle::StorerForCircle()
{
}

void StorerForCircle::save(Graph* g, std::ofstream& f)
{
	f << "@" << endl;
	f << g->getId() << endl;
	f << g->getCenterPos().x << endl;
	f << g->getCenterPos().y << endl;
	f << g->getRadius() << endl;
	f << g->getFillStatus() << endl;
	f << g->getLineWidth() << endl;
	f << g->getColor().r << endl;
	f << g->getColor().g << endl;
	f << g->getColor().b << endl;
	f << "#" << endl;
}

Graph * StorerForCircle::load(int id, ifstream & f)
{
	Graph* tmp = new Circle;

	float centerX, centerY;
	float R;
	bool isFilled;
	int lineWidth;
	float r, g, b;

	f >> centerX;
	f >> centerY;
	f >> R;
	f >> isFilled;
	f >> lineWidth;
	f >> r >> g >> b;

	tmp->setId(id);
	tmp->setCenterPos(centerX, centerY);
	tmp->setRadius(R);
	tmp->setFill(isFilled);
	tmp->setLineWidth(lineWidth);
	tmp->setColor(r, g, b);
	return tmp;
}

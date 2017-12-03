#include "..\Include\StorerForEllipse.h"
#include "../Include/Ellipse.h"

void StorerForEllipse::save(Graph * g, ofstream & f)
{
	f << "@" << endl;
	f << g->getId() << endl;
	f << g->getCenterPos().x << endl;
	f << g->getCenterPos().y << endl;
	f << g->getRadiusA() << endl;
	f << g->getRadiusB() << endl;
	f << g->getFillStatus() << endl;
	f << g->getLineWidth() << endl;
	f << g->getColor().r << endl;
	f << g->getColor().g << endl;
	f << g->getColor().b << endl;
	f << "#" << endl;
}

Graph * StorerForEllipse::load(int id, ifstream & f)
{
	Graph* tmp = new Ellipse_;

	float centerX, centerY;
	float R1,R2;
	bool isFilled;
	int lineWidth;
	float r, g, b;

	f >> centerX;
	f >> centerY;
	f >> R1;
	f >> R2;
	f >> isFilled;
	f >> lineWidth;
	f >> r >> g >> b;

	tmp->setId(id);
	tmp->setCenterPos(centerX, centerY);
	tmp->setRadiusA(R1);
	tmp->setRadiusB(R2);
	tmp->setFill(isFilled);
	tmp->setLineWidth(lineWidth);
	tmp->setColor(r, g, b);
	return tmp;
}

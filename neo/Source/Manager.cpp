#include "../Include/Manager.h"

#include "../Include/Factory.h"
#include "../Include/Factory_Pen.h"
#include "../Include/Factory_Circle.h"
#include "../Include/Factory_Circlef.h"
#include "../Include/Factory_Curve.h"
#include "../Include/Factory_Drager.h"
#include "../Include/Factory_Ellipse.h"
#include "../Include/Factory_Ellipsef.h"
#include "../Include/Factory_Eraser.h"
#include "../Include/Factory_Line.h"
#include "../Include/Factory_Polygon.h"
#include "../Include/Factory_Rect.h"
#include "../Include/Factory_Rectf.h"
#include "../Include/Factory_Triangle.h"
#include "../Include/Factory_Trianglef.h"
#include "../Include/Factory_Zoom.h"

#include "../Include/Factory_LineWidth1.h"
#include "../Include/Factory_LineWidth2.h"
#include "../Include/Factory_LineWidth3.h"
#include "../Include/Factory_LineWidth4.h"

#include "../Include/Factory_Btn_Black.h"
#include "../Include/Factory_Btn_Blue.h"
#include "../Include/Factory_Btn_Green.h"
#include "../Include/Factory_Btn_Orange.h"
#include "../Include/Factory_Btn_Purple.h"
#include "../Include/Factory_Btn_Red.h"
#include "../Include/Factory_Btn_White.h"
#include "../Include/Factory_Btn_Yellow.h"




Manager::Manager()
{

}

Manager::Manager(Application * targetApp, Window * targetWindow, World * targetWorld)
{
	this->targetApp = targetApp;
	this->targetWindow = targetWindow;
	this->targetWorld = targetWorld;
	
	Factory* tmp = new Factory_Pen;
	Factory_List[0].push_back(tmp);
	tmp = new Factory_Circle;
	Factory_List[0].push_back(tmp);
	tmp = new Factory_Circlef;
	Factory_List[0].push_back(tmp);
	tmp = new Factory_Curve;
	Factory_List[0].push_back(tmp);
	tmp = new Factory_Drager;
	Factory_List[0].push_back(tmp);
	tmp = new Factory_Ellipse;
	Factory_List[0].push_back(tmp);
	tmp = new Factory_Ellipsef;
	Factory_List[0].push_back(tmp);
	tmp = new Factory_Eraser;
	Factory_List[0].push_back(tmp);
	tmp = new Factory_Line;
	Factory_List[0].push_back(tmp);
	tmp = new Factory_Polygon;
	Factory_List[0].push_back(tmp);
	tmp = new Factory_Rect;
	Factory_List[0].push_back(tmp);
	tmp = new Factory_Rectf;
	Factory_List[0].push_back(tmp);
	tmp = new Factory_Triangle;
	Factory_List[0].push_back(tmp);
	tmp = new Factory_Trianglef;
	Factory_List[0].push_back(tmp);
	tmp = new Factory_Zoom;
	Factory_List[0].push_back(tmp);

	

	tmp = new Factory_LineWidth1;
	Factory_List[1].push_back(tmp);
	tmp = new Factory_LineWidth2;
	Factory_List[1].push_back(tmp);
	tmp = new Factory_LineWidth3;
	Factory_List[1].push_back(tmp);
	tmp = new Factory_LineWidth4;
	Factory_List[1].push_back(tmp);



	tmp = new Factory_Btn_Black;
	Factory_List[2].push_back(tmp);
	tmp = new Factory_Btn_Blue;
	Factory_List[2].push_back(tmp);
	tmp = new Factory_Btn_Green;
	Factory_List[2].push_back(tmp);
	tmp = new Factory_Btn_Orange;
	Factory_List[2].push_back(tmp);
	tmp = new Factory_Btn_Purple;
	Factory_List[2].push_back(tmp);
	tmp = new Factory_Btn_Red;
	Factory_List[2].push_back(tmp);
	tmp = new Factory_Btn_White;
	Factory_List[2].push_back(tmp);
	tmp = new Factory_Btn_Yellow;
	Factory_List[2].push_back(tmp);

	

}

Graph * Manager::getGraph(int id)
{
	Graph* tmp = NULL;
	if (Factory_List[0].size() != 0) {
		for (int i = 0; i < Factory_List[0].size(); i++) {
			if (Factory_List[0][i]->getId() == id) {
				tmp = Factory_List[0][i]->generateGraph();
			}
		}
	}
	
	return tmp;
}

Painter * Manager::getPainter(int id)
{
	Painter* tmp = NULL;

	if (Factory_List[0].size() != NULL) {
		for (int i = 0; i < Factory_List[0].size(); i++) {
			if (Factory_List[0][i]->getId() == id) {
				tmp = Factory_List[0][i]->generatePainter();
			}
		}
	}
	return tmp;
}

Storer * Manager::getStorer(int id)
{
	Storer* tmp = NULL;
	if (Factory_List[0].size() != NULL) {
		for (int i = 0; i < Factory_List[0].size(); i++) {
			if (Factory_List[0][i]->getId() == id) {
				tmp = Factory_List[0][i]->generateStorer();
			}
		}
	}
	return tmp;
}


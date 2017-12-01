#include "../Include/Manager.h"

#include "../Include/Line.h"
#include "../Include/Rect.h"
#include "../Include/Triangle.h"
#include "../Include/Circle.h"
#include "../Include/Ellipse.h"
#include "../Include/Eraser.h"
#include "../Include/Pen.h"
#include "../Include/Bezier.h"
#include "../Include/Polygon.h"
#include "../Include/PainterForLine.h"
#include "../Include/PainterForCurve.h"
#include "../Include/PainterForCircle.h"
#include "../Include/PainterForEllipse.h"
#include "../Include/PainterForRect.h"
#include "../Include/PainterForTriangle.h"
#include "../Include/PainterForPolygon.h"
#include "../Include/PainterForPen.h"

#include "../Include/Botton.h"
#include "../Include/Factory_Btn.h"
#include "../Include/Factory_Btn_Pen.h"
#include "../Include/Factory_Btn_Circle.h"
#include "../Include/Factory_Btn_Circlef.h"
#include "../Include/Factory_Btn_Curve.h"
#include "../Include/Factory_Btn_Drager.h"
#include "../Include/Factory_Btn_Ellipse.h"
#include "../Include/Factory_Btn_Ellipsef.h"
#include "../Include/Factory_Btn_Eraser.h"
#include "../Include/Factory_Btn_Line.h"
#include "../Include/Factory_Btn_Polygon.h"
#include "../Include/Factory_Btn_Rect.h"
#include "../Include/Factory_Btn_Rectf.h"
#include "../Include/Factory_Btn_Triangle.h"
#include "../Include/Factory_Btn_Trianglef.h"
#include "../Include/Factory_Btn_Zoom.h"


Manager::Manager()
{

}

Manager::Manager(Application * targetApp, Window * targetWindow, World * targetWorld)
{
	this->targetApp = targetApp;
	this->targetWindow = targetWindow;
	this->targetWorld = targetWorld;

	Factory_Btn* tmp = new Factory_Btn_Pen;
	botton_group_factory_List[0].push_back(tmp);
	tmp = new Factory_Btn_Circle;
	botton_group_factory_List[0].push_back(tmp);
	tmp = new Factory_Btn_Circlef;
	botton_group_factory_List[0].push_back(tmp);
	tmp = new Factory_Btn_Curve;
	botton_group_factory_List[0].push_back(tmp);
	tmp = new Factory_Btn_Drager;
	botton_group_factory_List[0].push_back(tmp);
	tmp = new Factory_Btn_Ellipse;
	botton_group_factory_List[0].push_back(tmp);
	tmp = new Factory_Btn_Ellipsef;
	botton_group_factory_List[0].push_back(tmp);
	tmp = new Factory_Btn_Eraser;
	botton_group_factory_List[0].push_back(tmp);
	tmp = new Factory_Btn_Line;
	botton_group_factory_List[0].push_back(tmp);
	tmp = new Factory_Btn_Polygon;
	botton_group_factory_List[0].push_back(tmp);
	tmp = new Factory_Btn_Rect;
	botton_group_factory_List[0].push_back(tmp);
	tmp = new Factory_Btn_Rectf;
	botton_group_factory_List[0].push_back(tmp);
	tmp = new Factory_Btn_Triangle;
	botton_group_factory_List[0].push_back(tmp);
	tmp = new Factory_Btn_Trianglef;
	botton_group_factory_List[0].push_back(tmp);
	tmp = new Factory_Btn_Zoom;
	botton_group_factory_List[0].push_back(tmp);



		
	for (int i = 0; i < 4; i++) {
		Botton* tmp = generateBotton(i, 2);
		if (tmp != NULL) {
			bottonList2.push_back(tmp);
		}
	}
	for (int i = 0; i < 10; i++) {
		Botton* tmp = generateBotton(i, 3);
		if (tmp != NULL) {
			bottonList3.push_back(tmp);
		}
	}

}

Graph * Manager::generateGraph(int type)
{
	Graph* mTmp = NULL;
	switch (type)
	{
	case BtnGroup1::Bline:
		mTmp = new Line;
		break;
	case BtnGroup1::Brect:
		mTmp = new Rect;
		break;
	case BtnGroup1::Brectf:
		mTmp = new Rect;
		mTmp->setFill(true);
		break;
	case BtnGroup1::Btriangle:
		mTmp = new Triangle;
		break;
	case BtnGroup1::Btrianglef:
		mTmp = new Triangle;
		mTmp->setFill(true);
		break;
	case BtnGroup1::Bcircle:
		mTmp = new Circle;
		break;
	case BtnGroup1::Bcirclef:
		mTmp = new Circle;
		mTmp->setFill(true);
		break;
	case BtnGroup1::Bellipse:
		mTmp = new Ellipse_;
		break;
	case BtnGroup1::Bellipsef:
		mTmp = new Ellipse_;
		mTmp->setFill(true);
		break;
	case BtnGroup1::Beraser:
		mTmp = new Eraser;
		break;
	case BtnGroup1::Bpen:
		mTmp = new Pen;
		break;
	case BtnGroup1::Bcurve:
		mTmp = new Bezier;
		break;
	case BtnGroup1::Bpolygon:
		mTmp = new Polygon;
		break;
	default:
		break;
	}
	return mTmp;
}

Painter * Manager::generatePainter(int type)
{
	Painter* mTmp = NULL;
	switch (type)
	{
	case BtnGroup1::Bline:
		mTmp = new PainterForLine(targetApp,targetWindow,targetWorld);
		break;
	case BtnGroup1::Brect:
	case BtnGroup1::Brectf:
		mTmp = new PainterForRect(targetApp, targetWindow, targetWorld);
		break;
	case BtnGroup1::Btriangle:
	case BtnGroup1::Btrianglef:
		mTmp = new PainterForTriangle(targetApp, targetWindow, targetWorld);
		break;
	case BtnGroup1::Bcircle:
	case BtnGroup1::Bcirclef:
		mTmp = new PainterForCircle(targetApp, targetWindow, targetWorld);
		break;
	case BtnGroup1::Bellipse:
	case BtnGroup1::Bellipsef:
		mTmp = new PainterForEllipse(targetApp, targetWindow, targetWorld);
		break;
	case BtnGroup1::Bpen:
		mTmp = new PainterForPen(targetApp, targetWindow, targetWorld);
		break;
	case BtnGroup1::Bcurve:
		mTmp = new PainterForCurve(targetApp, targetWindow, targetWorld);
		break;
	case BtnGroup1::Bpolygon:
		mTmp = new PainterForPolygon(targetApp, targetWindow, targetWorld);
		break;
	default:
		break;
	}
	return mTmp;
}

Botton * Manager::generateBotton(int type, int groupNum)
{
	Botton* tmp = NULL;

	switch (groupNum)
	{
	case 1:
		switch (type)
		{
		case BtnGroup1::Bcircle:
			tmp = new Botton;
			tmp->setSize(60, 30);
			tmp->setPos(1170, 540);
			tmp->loadTexture("Textures/circle.bmp");
			break;
		case BtnGroup1::Bcirclef:
			tmp = new Botton;
			tmp->setSize(60, 30);
			tmp->setPos(1230, 540);
			tmp->loadTexture("Textures/circle2.bmp");
			break;
		case BtnGroup1::Bcurve:
			tmp = new Botton;
			tmp->setSize(60, 30);
			tmp->setPos(1230, 600);
			tmp->loadTexture("Textures/Curve.bmp");
			break;
		case BtnGroup1::Bdrager:
			tmp = new Botton;
			tmp->setSize(100, 80);
			tmp->setPos(1130, 730);
			tmp->loadTexture("Textures/PaintBucket.bmp");
			break;
		case BtnGroup1::Bellipse:
			tmp = new Botton;
			tmp->setSize(60, 30);
			tmp->setPos(1170, 510);
			tmp->loadTexture("Textures/Ellipse.bmp");
			break;
		case BtnGroup1::Bellipsef:
			tmp = new Botton;
			tmp->setSize(60, 30);
			tmp->setPos(1230, 510);
			tmp->loadTexture("Textures/Ellipse2.bmp");
			break;
		case BtnGroup1::Beraser:
			tmp = new Botton;
			tmp->setSize(100, 80);
			tmp->setPos(1230, 730);
			tmp->loadTexture("Textures/Eraser.bmp");
			break;
		case BtnGroup1::Bline:
			tmp = new Botton;
			tmp->setSize(60, 30);
			tmp->setPos(1170, 600);
			tmp->loadTexture("Textures/Line.bmp");
			break;
		case BtnGroup1::Bpen:
			tmp = new Botton;
			tmp->setSize(100, 80);
			tmp->setPos(930, 730);
			tmp->loadTexture("Textures/Pencil.bmp");
			break;
		case BtnGroup1::Bpolygon:
			tmp = new Botton;
			tmp->setSize(60, 30);
			tmp->setPos(1230, 450);
			//	tmp->loadTexture("Textures/rectangle2.bmp");
			break;
		case BtnGroup1::Brect:
			tmp = new Botton;
			tmp->setSize(60, 30);
			tmp->setPos(1170, 480);
			tmp->loadTexture("Textures/rectangle.bmp");
			break;
		case BtnGroup1::Brectf:

			break;

		case BtnGroup1::Btriangle:
			tmp = new Botton;
			tmp->setSize(60, 30);
			tmp->setPos(1170, 570);
			tmp->loadTexture("Textures/triangle.bmp");
			break;
		case BtnGroup1::Btrianglef:
			tmp = new Botton;
			tmp->setSize(60, 30);
			tmp->setPos(1230, 570);
			tmp->loadTexture("Textures/triangle2.bmp");
			break;
		case BtnGroup1::Bzoom:
			tmp = new Botton;
			tmp->setSize(100, 80);
			tmp->setPos(1030, 730);
			tmp->loadTexture("Textures/Zoom.bmp");
			break;
		default:
			break;
		}
		break;
	case 2:
		switch (type)
		{
		case BtnGroup3::Width1:
			tmp = new Botton;
			tmp->setSize(120, 30);
			tmp->setPos(1170, 400);
			tmp->loadTexture("Textures/line1.bmp");
			break;
		case BtnGroup3::Width2:
			tmp = new Botton;
			tmp->setSize(120, 30);
			tmp->setPos(1170, 370);
			tmp->loadTexture("Textures/line2.bmp");
			break;
		case BtnGroup3::Width3:
			tmp = new Botton;
			tmp->setSize(120, 30);
			tmp->setPos(1170, 340);
			tmp->loadTexture("Textures/line3.bmp");
			break;
		case BtnGroup3::Width4:
			tmp = new Botton;
			tmp->setSize(120, 30);
			tmp->setPos(1170, 310);
			tmp->loadTexture("Textures/line4.bmp");
			break;
		default:
			break;
		}
		break;
	case 3:
		switch (type)
		{
		case BtnGroup4::Black:
			tmp = new Botton;
			tmp->setSize(60, 30);
			tmp->setPos(1230, 160);
			tmp->loadTexture("Textures/Black.bmp");

			break;
		case BtnGroup4::Blue:
			tmp = new Botton;
			tmp->setSize(60, 30);
			tmp->setPos(1170, 190);
			tmp->loadTexture("Textures/Blue.bmp");
			break;
		case BtnGroup4::Green:
			tmp = new Botton;
			tmp->setSize(60, 30);
			tmp->setPos(1230, 220);
			tmp->loadTexture("Textures/Green.bmp");
			break;
		case BtnGroup4::Grey:
			break;
		case BtnGroup4::Grey2:
			break;
		case BtnGroup4::Orange:
			tmp = new Botton;
			tmp->setSize(60, 30);
			tmp->setPos(1170, 160);
			tmp->loadTexture("Textures/Orange.bmp");
			break;
		case BtnGroup4::Purple:
			tmp = new Botton;
			tmp->setSize(60, 30);
			tmp->setPos(1230, 130);
			tmp->loadTexture("Textures/Purple.bmp");
			break;
		case BtnGroup4::Red:
			tmp = new Botton;
			tmp->setSize(60, 30);
			tmp->setPos(1170, 220);
			tmp->loadTexture("Textures/Red.bmp");
			break;
		case BtnGroup4::White:
			tmp = new Botton;
			tmp->setSize(60, 30);
			tmp->setPos(1170, 130);
			tmp->loadTexture("Textures/White.bmp");
			break;
		case BtnGroup4::Yellow:
			tmp = new Botton;
			tmp->setSize(60, 30);
			tmp->setPos(1230, 190);
			tmp->loadTexture("Textures/Yellow.bmp");
			break;
		default:
			break;
		}
		break;
	case 4:
		break;
	default:
		break;
	}

	return tmp;
}

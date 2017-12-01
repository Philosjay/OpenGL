#include "../Include/FactoryForGraph.h"

#include "../Include/Line.h"
#include "../Include/Rect.h"
#include "../Include/Triangle.h"
#include "../Include/Circle.h"
#include "../Include/Ellipse.h"
#include "../Include/Eraser.h"
#include "../Include/Pen.h"
#include "../Include/Bezier.h"
#include "../Include/Polygon.h"

FactoryForGraph::FactoryForGraph()
{
}

Graph * FactoryForGraph::generateGraph(int type)
{
	Graph* mTmp = NULL;
	switch (type)
	{
	case ToolSet::line:
		mTmp = new Line;
		break;
	case ToolSet::rect:
		mTmp = new Rect;
		break;
	case ToolSet::rectf:
		mTmp = new Rect;
		mTmp->setFill(true);
		break;
	case ToolSet::triangle:
		mTmp = new Triangle;
		break;
	case ToolSet::trianglef:
		mTmp = new Triangle;
		mTmp->setFill(true);
		break;
	case ToolSet::cirCle:
		mTmp = new Circle;
		break;
	case ToolSet::cirClef:
		mTmp = new Circle;
		mTmp->setFill(true);
		break;
	case ToolSet::ellipse:
		mTmp = new Ellipse_;
		break;
	case ToolSet::ellipsef:
		mTmp = new Ellipse_;
		mTmp->setFill(true);
		break;
	case ToolSet::eraser:
		mTmp = new Eraser;
		break;
	case ToolSet::pen:
		mTmp = new Pen;
		break;
	case ToolSet::curve:
		mTmp = new Bezier;
		break;
	case ToolSet::polygon:
		mTmp = new Polygon;
		break;
	default:
		break;
	}
	return mTmp;
}

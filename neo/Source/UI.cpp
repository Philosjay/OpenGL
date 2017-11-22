#include "../Include/UI.h"

#include "../Include/Botton.h"
#include "../Include/Widget.h"
#include "../Include/Rectf.h"
#include "../Include/settingList.h"

UI::UI()
	:backgroundCount(0)
	, isdrawing(false)
{
	init();
}

void UI::processInput(int x, int y)
{
	//检测工具区域
	if ((x >= 930 && x <= 1330) && (y >= 650 && y <= 730) ||
		((x >= 1170 && x <= 1290) && (y >= 450 && y <= 600)))
	{
		for (int i = 0; i < ToolSet::ToolCount; i++) {
			if (mToolBottons[i] != NULL) {
				if (mToolBottons[i]->isGrabbed(x, y) && i != lastActiveTool) {
					mToolBottons[i]->setActive(true);
					mToolBottons[lastActiveTool]->setActive(false);
					lastActiveTool = i;
				}
			}

		}

	}
	//检测线粗区域
	else if ((x >= 1170 && x <= 1290) && (y >= 280 && y <= 400))
	{
		for (int i = 0; i < LineWidthSet::WidthCount; i++) {
			if (mLineWidthBottons[i] != NULL) {
				if (mLineWidthBottons[i]->isGrabbed(x, y) && i != lastActiveLineWidth) {
					mLineWidthBottons[i]->setActive(true);
					mLineWidthBottons[lastActiveLineWidth]->setActive(false);
					lastActiveLineWidth = i;
				}
			}

		}

	}
	//检测颜色区域
	else if ((x >= 117 && x <= 1290) && (y >= 100 && y <= 220))
	{
		for (int i = 0; i < ColorSet::ColorCount; i++) {
			if (mColorBottons[i] != NULL) {
				if (mColorBottons[i]->isGrabbed(x, y) && i != lastActiveColor) {
					mColorBottons[i]->setActive(true);
					mColorBottons[lastActiveColor]->setActive(false);
					lastActiveColor = i;
				}
			}

		}

	}
	if ((x >= 50 && x <= 1130) && (y >= 50 && y <= 650))
	{
		isdrawing = true;
	}
	else {
		isdrawing = false;
	}

	//检测选项区域

	for (int i = 0; i < MenuSet::MenuCount; i++) {
		mMenuBottons[i]->setActive(false);
		if (mMenuBottons[i]->isGrabbed(x, y)) {
			mMenuBottons[i]->setActive(true);
		}
	}

}

void UI::show()
{
	for (int i = 0; i <backgroundCount; i++) {
		mBackground[i]->draw();
	}

	for (int i = 0; i < MenuSet::MenuCount; i++) {
		mMenuBottons[i]->draw();
	}


	for (int i = 0; i < ToolSet::ToolCount; i++) {
		if (mToolBottons[i] != NULL)mToolBottons[i]->draw();
	}
	for (int i = 0; i < LineWidthSet::WidthCount; i++) {
		if (mLineWidthBottons[i] != NULL)mLineWidthBottons[i]->draw();
	}
	for (int i = 0; i < ColorSet::ColorCount; i++) {
		if(mColorBottons[i]!=NULL) mColorBottons[i]->draw();
		
	}

	glFlush();
}

inline void UI::init()
{
	for (int i = 0; i < ColorCount; i++) {
		mColorBottons[i] = NULL;
	}
	for (int i = 0; i < ToolCount; i++) {
		mToolBottons[i] = NULL;
	}
	for (int i = 0; i < WidthCount; i++) {
		mLineWidthBottons[i] = NULL;
	}
	for (int i = 0; i <MenuCount; i++) {
		mMenuBottons[i] = NULL;
	}

	background();
	widgets();

	mToolBottons[0]->setActive(true);
	mLineWidthBottons[0]->setActive(true);
	mColorBottons[0]->setActive(true);



}

void UI::background()
{
	Rectf* tmp = new Rectf;
	tmp->setColor(ColorSet::Grey);
	tmp->setSize(1330, 110);
	tmp->moveTo(0, 760);

	addBackground(tmp);


	tmp = new Rectf;
	tmp->setColor(ColorSet::Grey);
	tmp->setSize(200, 650);
	tmp->moveTo(1130, 650);
	
	addBackground(tmp);

	//工具栏
	Widget* widget = new Botton;
	widget->setSize(400, 30);
	widget->setPos(930, 760);
	widget->loadTexture("Textures/Title_Tools.bmp");
	addBackground(widget);

	//形状栏
	widget = new Botton;
	widget->setSize(120, 30);
	widget->setPos(1170, 630);
	widget->loadTexture("Textures/Title_Shape.bmp");
	addBackground(widget);

	//LineWidth
	widget = new Botton;
	widget->setSize(120, 30);
	widget->setPos(1170, 430);
	widget->loadTexture("Textures/Title_Width.bmp");
	addBackground(widget);

	widget = new Botton;
	widget->setSize(120, 30);
	widget->setPos(1170, 250);
	widget->loadTexture("Textures/Title_Color.bmp");
	addBackground(widget);

	widget = new Botton;
	widget->setSize(150, 100);
	widget->setPos(60, 755);
	widget->loadTexture("Textures/Title_Gallery.bmp");
	addBackground(widget);
}

void UI::widgets()
{
	Botton* widet = new Botton;
	widet->setSize(150, 100);
	widet->setPos(210, 755);
	widet->loadTexture("Textures/save.bmp");
	mMenuBottons[MenuSet::Save] = widet;

	widet = new Botton;
	widet->setSize(150, 100);
	widet->setPos(360, 755);
	widet->loadTexture("Textures/help.bmp");
	mMenuBottons[MenuSet::Help] = widet;

	//填充
	widet = new Botton;
	widet->setSize(100, 80);
	widet->setPos(1130, 730);
	widet->loadTexture("Textures/PaintBucket.bmp");
	mToolBottons[ToolSet::drager] = widet;
	//橡皮
	widet = new Botton;
	widet->setSize(100, 80);
	widet->setPos(1230, 730);
	widet->loadTexture("Textures/Eraser.bmp");
	mToolBottons[ToolSet::eraser] = widet;
	//放大镜
	widet = new Botton;
	widet->setSize(100, 80);
	widet->setPos(1030, 730);
	widet->loadTexture("Textures/Zoom.bmp");
	mToolBottons[ToolSet::zoom] = widet;
	//画笔
	widet = new Botton;
	widet->setSize(100, 80);
	widet->setPos(930, 730);
	widet->loadTexture("Textures/Pencil.bmp");
	mToolBottons[ToolSet::pen] = widet;



	//直线
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1170, 600);
	widet->loadTexture("Textures/Line.bmp");
	mToolBottons[ToolSet::line] = widet;
	//曲线
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1230, 600);
	widet->loadTexture("Textures/Curve.bmp");
	mToolBottons[ToolSet::curve] = widet;
	//三角形
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1170, 570);
	widet->loadTexture("Textures/triangle.bmp");
	mToolBottons[ToolSet::triangle] = widet;
	//三角形实
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1230, 570);
	widet->loadTexture("Textures/triangle2.bmp");
	mToolBottons[ToolSet::trianglef] = widet;
	//圆形
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1170, 540);
	widet->loadTexture("Textures/circle.bmp");
	mToolBottons[ToolSet::cirCle] = widet;
	//圆形实
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1230, 540);
	widet->loadTexture("Textures/circle2.bmp");
	mToolBottons[ToolSet::cirClef] = widet;
	//椭圆形
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1170, 510);
	widet->loadTexture("Textures/Ellipse.bmp");
	mToolBottons[ToolSet::ellipse] = widet;
	//椭圆形实
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1230, 510);
	widet->loadTexture("Textures/Ellipse2.bmp");
	mToolBottons[ToolSet::ellipsef] = widet;
	//矩形
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1170, 480);
	widet->loadTexture("Textures/rectangle.bmp");
	mToolBottons[ToolSet::rect] = widet;
	//矩形实
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1230, 480);
	widet->loadTexture("Textures/rectangle2.bmp");
	mToolBottons[ToolSet::rectf] = widet;

	//线宽栏

	widet = new Botton;
	widet->setSize(120, 30);
	widet->setPos(1170, 400);
	widet->loadTexture("Textures/line1.bmp");
	mLineWidthBottons[LineWidthSet::Width1] = widet;
	widet = new Botton;
	widet->setSize(120, 30);
	widet->setPos(1170, 370);
	widet->loadTexture("Textures/line2.bmp");
	mLineWidthBottons[LineWidthSet::Width2] = widet;
	widet = new Botton;
	widet->setSize(120, 30);
	widet->setPos(1170, 340);
	widet->loadTexture("Textures/line3.bmp");
	mLineWidthBottons[LineWidthSet::Width3] = widet;
	widet = new Botton;
	widet->setSize(120, 30);
	widet->setPos(1170, 310);
	widet->loadTexture("Textures/line4.bmp");
	mLineWidthBottons[LineWidthSet::Width4] = widet;

	//颜色栏
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1170, 220);
	widet->loadTexture("Textures/Red.bmp");
	mColorBottons[ColorSet::Red] = widet;
	//
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1230, 220);
	widet->loadTexture("Textures/Green.bmp");
	mColorBottons[ColorSet::Green] = widet;

	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1170, 190);
	widet->loadTexture("Textures/Blue.bmp");
	mColorBottons[ColorSet::Blue] = widet;
	/////////////////////
	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1230, 190);
	widet->loadTexture("Textures/Yellow.bmp");
	mColorBottons[ColorSet::Yellow] = widet;

	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1170, 160);
	widet->loadTexture("Textures/Orange.bmp");
	mColorBottons[ColorSet::Orange] = widet;

	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1230, 160);
	widet->loadTexture("Textures/Black.bmp");
	mColorBottons[ColorSet::Black] = widet;

	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1170, 130);
	widet->loadTexture("Textures/White.bmp");
	mColorBottons[ColorSet::White] = widet;

	widet = new Botton;
	widet->setSize(60, 30);
	widet->setPos(1230, 130);
	widet->loadTexture("Textures/Purple.bmp");
	mColorBottons[ColorSet::Purple] = widet;

}

void UI::addBackground(Graph * widet)
{
	mBackground[backgroundCount++] = widet;
}
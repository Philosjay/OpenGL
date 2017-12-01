#include "../Include/UI.h"
#include "../Include/Rect.h"
#include "../Include/Botton.h"
#include "../Include/Widget.h"
#include "../Include/settingList.h"
#include "../Include/Manager.h"
#include "../Include/Factory_Btn.h"

UI::UI(Manager* mng)
	:backgroundCount(0)
	, isdrawing(false)
{
	mManager = mng;
	init();
}

void UI::processInput(int x, int y)
{
	for (int i = 0; i < mManager->botton_group_factory_List[0].size(); i++) {
		if (mToolBottons[i] != NULL) {
			if (mToolBottons[i]->isGrabbed(x, y) && mToolBottons[i]->getKey() != lastActiveKey[0]) {
				mToolBottons[i]->setActive(true);
				mToolBottons[lastActiveIndex[0]]->setActive(false);
				lastActiveKey[0] = mToolBottons[i]->getKey();
				lastActiveIndex[0] = i;
			}
		}

	}
	for (int i = 0; i < Manager::BtnGroup3::BtnGroup3Count; i++) {
		if (mLineWidthBottons[i] != NULL) {
			if (mLineWidthBottons[i]->isGrabbed(x, y) && i != lastActiveLineWidth) {
				mLineWidthBottons[i]->setActive(true);
				mLineWidthBottons[lastActiveLineWidth]->setActive(false);
				lastActiveLineWidth = i;
				lastActiveIndex[1] = i;
			}
		}

	}
	for (int i = 0; i < Manager::BtnGroup4::BtnGroup4Count; i++) {
		if (mColorBottons[i] != NULL) {
			if (mColorBottons[i]->isGrabbed(x, y) && i != lastActiveColor) {
				mColorBottons[i]->setActive(true);
				mColorBottons[lastActiveColor]->setActive(false);
				lastActiveColor = i;
				lastActiveIndex[2] = i;
			}
		}

	}
	for (int i = 0; i < Manager::BtnGroup5::BtnGroup5Count; i++) {
		mMenuBottons[i]->setActive(false);
		if (mMenuBottons[i]->isGrabbed(x, y)) {
			mMenuBottons[i]->setActive(true);
			lastActiveIndex[3] = i;
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

	

}

void UI::show()
{
	for (int i = 0; i <backgroundCount; i++) {
		mBackground[i]->draw();
	}

	for (int i = 0; i < Manager::BtnGroup5::BtnGroup5Count; i++) {
		mMenuBottons[i]->draw();
	}


	for (int i = 0; i < Manager::BtnGroup1::BtnGroup1Count; i++) {
		if (mToolBottons[i] != NULL)mToolBottons[i]->draw();
	}
	for (int i = 0; i < Manager::BtnGroup3::BtnGroup3Count; i++) {
		if (mLineWidthBottons[i] != NULL)mLineWidthBottons[i]->draw();
	}
	for (int i = 0; i < Manager::BtnGroup4::BtnGroup4Count; i++) {
		if(mColorBottons[i]!=NULL) mColorBottons[i]->draw();
		
	}

	glFlush();
}

inline void UI::init()
{
	for (int i = 0; i < Manager::BtnGroup4::BtnGroup4Count; i++) {
		mColorBottons[i] = NULL;
	}
	for (int i = 0; i < Manager::BtnGroup1::BtnGroup1Count; i++) {
		mToolBottons[i] = NULL;
	}
	for (int i = 0; i <  Manager::BtnGroup3::BtnGroup3Count; i++) {
		mLineWidthBottons[i] = NULL;
	}
	for (int i = 0; i < Manager::BtnGroup5::BtnGroup5Count; i++) {
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
	Rect* tmp = new Rect;
	tmp->setFill(true);
	tmp->setColor(ColorSet::Grey);
	tmp->setSize(1330, 110);
	tmp->moveTo(0, 760);

	addBackground(tmp);


	tmp = new Rect;
	tmp->setFill(true);
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

	//按钮群1
	for (int i = 0; i < mManager->botton_group_factory_List[0].size(); i++) {
		mToolBottons[i] = mManager->botton_group_factory_List[0][i]->generate();
	}


	//按钮群3
	for (int i = 0; i < mManager->bottonList2.size(); i++) {
		mLineWidthBottons[i] = mManager->bottonList2[i];
	}
	//按钮群4
	
	for (int i = 0; i <mManager->bottonList3.size(); i++) {
		mColorBottons[i] = mManager->bottonList3[i];
	}

	/*
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
	*/

}

void UI::addBackground(Graph * widet)
{
	mBackground[backgroundCount++] = widet;
}
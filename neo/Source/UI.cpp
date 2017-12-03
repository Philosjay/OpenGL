#include "../Include/UI.h"
#include "../Include/Rect.h"
#include "../Include/Botton.h"
#include "../Include/Widget.h"
#include "../Include/Manager.h"
#include "../Include/Factory.h"

UI::UI(Manager* mng)
	:backgroundCount(0)
	, isdrawing(false)
	, isSaving(false)
	, isLoading(false)
{
	mManager = mng;
	init();
}

void UI::processInput(int x, int y)
{
	//碰撞检测记录被选中的按键的储存位置，而非id
	for (int i = 0; i < mManager->Factory_List[0].size(); i++) {
		if (mToolBottons[i] != NULL) {
			if (mToolBottons[i]->isGrabbed(x, y) && i != lastActiveKey[0]) {
			mToolBottons[i]->setActive(true);
			mToolBottons[lastActiveKey[0]]->setActive(false);
			lastActiveKey[0] = i;
			}
		}

	}
	for (int i = 0; i < mManager->Factory_List[1].size(); i++) {
		if (mLineWidthBottons[i] != NULL) {
			if (mLineWidthBottons[i]->isGrabbed(x, y) && i != lastActiveKey[1]) {
				mLineWidthBottons[i]->setActive(true);
				mLineWidthBottons[lastActiveKey[1]]->setActive(false);
				lastActiveKey[1] = i;
			}
		}

	}
	for (int i = 0; i < mManager->Factory_List[2].size(); i++) {
		if (mColorBottons[i] != NULL) {
			if (mColorBottons[i]->isGrabbed(x, y) && i != lastActiveKey[2]) {
				mColorBottons[i]->setActive(true);
				mColorBottons[lastActiveKey[2]]->setActive(false);
				lastActiveKey[2] = i;
			}
		}

	}
	for (int i = 0; i < MenuSet::MenuCount; i++) {
		mMenuBottons[i]->setActive(false);
		if (mMenuBottons[i]->isGrabbed(x, y)) {
			mMenuBottons[i]->setActive(true);
			lastActiveKey[3] = i;
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

	for (int i = 0; i < MenuCount; i++) {
		mMenuBottons[i]->draw();
	}


	for (int i = 0; i < mManager->Factory_List[0].size(); i++) {
		if (mToolBottons[i] != NULL)mToolBottons[i]->draw();
	}
	for (int i = 0; i < mManager->Factory_List[1].size(); i++) {
		if (mLineWidthBottons[i] != NULL)mLineWidthBottons[i]->draw();
	}
	for (int i = 0; i <mManager->Factory_List[2].size(); i++) {
		if(mColorBottons[i]!=NULL) mColorBottons[i]->draw();
		
	}

	glFlush();
}

int UI::getStatus()
{
	//按键值0代表draw，1代表drag,2代表save，3代表load,4代表new,-1是无操作
	if (lastActiveKey[3] == 0) {
		lastActiveKey[3] = -1;
		return 2;
	}
	else if(lastActiveKey[3] == 1){
		lastActiveKey[3] = -1;
		return 3;
	}
	else if (lastActiveKey[3] == 2) {
		lastActiveKey[3] = -1;
		return 4;
	}

	if (mToolBottons[lastActiveKey[0]] != NULL) {
		return mToolBottons[lastActiveKey[0]]->getValue(0);
	}
	else {
		return -1;
	}
	
}

int UI::getActiveTool()
{
	return mToolBottons[lastActiveKey[0]]->getId();
}

int UI::getLastActiveLineWidth()
{
	//读取按键被赋予的宽度值
	if (mLineWidthBottons[lastActiveKey[1]] != NULL) {
		return mLineWidthBottons[lastActiveKey[1]]->getValue(0);
	}
	return 1;
}

Color UI::getLastActiveColor()
{
	Color color;
	//读取按键被赋予的rgb值
	if (mColorBottons[lastActiveKey[2]] != NULL) {
		color.r = mColorBottons[lastActiveKey[2]]->getValue(0);
		color.g = mColorBottons[lastActiveKey[2]]->getValue(1);
		color.b = mColorBottons[lastActiveKey[2]]->getValue(2);
	}
	else {
		color.r = 0;
		color.g =0;
		color.b =0;
	}
	return color;
}

inline void UI::init()
{

	background();
	widgets();

	if (mToolBottons[0] != NULL) {
		mToolBottons[0]->setActive(true);
	}
	if (mLineWidthBottons[0] != NULL) {
		mLineWidthBottons[0]->setActive(true);
	}
	if (mColorBottons[0] != NULL) {
		mColorBottons[0]->setActive(true);
	}
	



}

void UI::background()
{
	Rect* tmp = new Rect;
	tmp->setFill(true);
	tmp->setColor(0.8, 0.8, 0.8);
	tmp->setSize(1330, 110);
	tmp->moveTo(0, 760);

	addBackground(tmp);


	tmp = new Rect;
	tmp->setFill(true);
	tmp->setColor(0.8, 0.8, 0.8);
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
	widet->loadTexture("Textures/load.bmp");
	mMenuBottons[MenuSet::Help] = widet;

	widet = new Botton;
	widet->setSize(150, 100);
	widet->setPos(60, 755);
	widet->loadTexture("Textures/new.bmp");
	mMenuBottons[MenuSet::New] = widet;

	//按钮群1
	for (int i = 0; i < mManager->Factory_List[0].size(); i++) {
		mToolBottons[i] = mManager->Factory_List[0][i]->generateBotton();
	}


	//按钮群3
	for (int i = 0; i < mManager->Factory_List[1].size(); i++) {
		mLineWidthBottons[i] = mManager->Factory_List[1][i]->generateBotton();
	}
	//按钮群4
	
	for (int i = 0; i <mManager->Factory_List[2].size(); i++) {
		mColorBottons[i] = mManager->Factory_List[2][i]->generateBotton();
	}

}

void UI::addBackground(Graph * widet)
{
	mBackground[backgroundCount++] = widet;
}
#ifndef WINDOW_H_
#define WINDOW_H_

#include <GL/glut.h>
#include "SceneNode.h"

class UI;
class SceneNode;
class Manager;

class Window
{
public:
	Window(int width, int height, char* title);
	void	update(int x,int y);
	void	draw();
	bool	isInPaper();
	int		getStatus();
	int		getActiveTool();
	int		getActiveLineWidth();
	Color		getActiveColor();
	void	registerManager(Manager* mng);

private:
	static void  reshape(int w, int h);
	void		init();
	UI*			mUI;


};
void drawSceneNode(SceneNode* );



#endif // !WINDOW_H_


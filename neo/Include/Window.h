#ifndef WINDOW_H_
#define WINDOW_H_

#include <GL/glut.h>

class UI;
class SceneNode;

class Window
{
public:
	Window(int width, int height, char* title);
	void	update(int x,int y);
	void	draw();
	bool	isInPaper();
	int		getActiveTool();
	int		getActiveLineWidth();
	int		getActiveColor();


private:
	static void  reshape(int w, int h);
	void		init();

	UI*			mUI;


};
void drawSceneNode(SceneNode* );



#endif // !WINDOW_H_


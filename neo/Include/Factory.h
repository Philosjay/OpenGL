#ifndef Factory_H_
#define Factory_H_

class Botton;
class Graph;
class Storer;
class Loader;
class Painter;


class Factory {
public:
	Factory();
	virtual Botton*		generateBotton();
	virtual Graph*		generateGraph();
	virtual Painter*	generatePainter();
	virtual Storer*		generateStorer();
	int					getId();
protected:
	int id;

};

#endif // !Factory_H_
#pragma once

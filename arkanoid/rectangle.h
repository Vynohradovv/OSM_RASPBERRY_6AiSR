#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

class rectangle
{

private:
	int prX, prY;

public:

	rectangle(void);
	void rectangle_create(int x, int y);
	void rectangle_move(int x, int y);
	void rectangle_draw(void);

};


#endif

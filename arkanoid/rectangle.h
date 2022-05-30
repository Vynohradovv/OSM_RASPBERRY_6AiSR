
#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

class rectangle
{

private:
	int prX, prY, prColor;

public:

	rectangle(int x, int y, int color);
	void move(int x, int y);
	void draw(void);

};


#endif

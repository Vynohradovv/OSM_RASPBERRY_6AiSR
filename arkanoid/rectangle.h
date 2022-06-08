#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include <cstdlib>

class rectangle
{

private:

	bool prVisible;
	int prX, prY;
	const int prColor = (std::rand() % 5);

public:

	rectangle(void);
	rectangle(const int& x, const int& y);

	void rectangle_draw(void);
	int rectangle_getPosX(void);
	int rectangle_getPosY(void);
	bool rectangle_isActive(void);
	void rectangle_visible(bool f);
	void rectangle_move(int x, int y);
	void rectangle_create(int x, int y);
	int rectangle_getColor(int x, int y);
};


#endif

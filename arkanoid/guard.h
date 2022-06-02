#ifndef _GUARD_H_
#define _GUARD_H_


class guard
{

private:

	int prX, prY;

public:

	guard(void);
	void guard_draw(void);
	int guard_getPosX(void);
	int guard_getPosY(void);
	void guard_mov(int x, int y);
	bool guard_isTouch(int objPosX, int objPosY);

};


#endif

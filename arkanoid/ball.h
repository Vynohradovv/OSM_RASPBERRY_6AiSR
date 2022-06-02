#ifndef _BALL_H_
#define _BALL_H_

class ball
{

private:
	int prX, prY, prColor;


public:

	ball(void);
	void ball_draw(void);
	void ball_mov(int x, int y);
	int ball_getPosX(void);
	int ball_getPosY(void);

};


#endif

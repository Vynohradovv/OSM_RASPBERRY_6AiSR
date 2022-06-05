#ifndef _BALL_H_
#define _BALL_H_

class ball
{

private:
	int prX, prY, prColor;
	bool prVisible;

public:

	ball(void);
	void ball_draw(void);
	int ball_getPosX(void);
	int ball_getPosY(void);
	void ball_visible(bool f);
	void ball_mov(int x, int y);

};


#endif

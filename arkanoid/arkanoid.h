#ifndef _ARKANOID_H_
#define _ARKANOID_H_

#include "ball.h"
#include "guard.h"

class arkanoid : public ball, public guard
{

private:

	int ball_x, ball_y;
	void ClearScreen();


public:

	arkanoid(void);
	void draw(void);

};

#endif

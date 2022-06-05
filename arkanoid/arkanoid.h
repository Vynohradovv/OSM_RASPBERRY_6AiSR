#ifndef _ARKANOID_H_
#define _ARKANOID_H_

#include "ball.h"
#include "guard.h"
#include "rectangle.h"

class arkanoid : public ball, public guard
{

private:

	bool start_game, game_over;
	int ball_x, ball_y;
	int rectangle_x, rectangle_y;
	int guard_step_left, guard_step_right;

	void ClearScreen();
	void GameOver();
	void ProcessGame();
	bool isConnect(rectangle *obj);



public:

	arkanoid(void);
	void draw(void);

};

#endif

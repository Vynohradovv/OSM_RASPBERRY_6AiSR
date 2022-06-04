#include "arkanoid.h"
#include "rectangle.h"
#include "peripherals.h"

extern volatile long globalTimer_ms;


rectangle k11, k12, k13, k14, k15;
rectangle k21, k22, k23;

arkanoid::arkanoid(void)
{
	ball_x = 8;
	ball_y = -8;

	k11.rectangle_create(50, 	10);
	k12.rectangle_create(160, 	10);
	k13.rectangle_create(270, 	10);
	k14.rectangle_create(380, 	10);
	k15.rectangle_create(490, 	10);

	k21.rectangle_create(160, 	55);
	k22.rectangle_create(270, 	55);
	k23.rectangle_create(380, 	55);



}

void arkanoid::draw(void)
{
	int Key = getKey();

	this->ClearScreen();

	switch(Key)
	{

	case 105:
		this->guard_mov(-30,0);
		break;

	case 106:
		this->guard_mov(30,0);
		break;

	default:
		break;
	}

	if(globalTimer_ms % 15)
	{
		this->ball_mov(ball_x, ball_y);

		if(this->ball_getPosY() < 15)
		{
			ball_y = -ball_y;
		}

		if((this->ball_getPosX() < 15)||
			(this->ball_getPosX() > 2450))
		{
			ball_x = -ball_x;
		}


		if(this->guard_isTouch(this->ball_getPosX(),this->ball_getPosY()))
		{
			ball_y = -ball_y;
		}
	}

}


void arkanoid::ClearScreen()
{


	k11.rectangle_draw();
	k12.rectangle_draw();
	k13.rectangle_draw();
	k14.rectangle_draw();
	k15.rectangle_draw();

	k21.rectangle_draw();
	k22.rectangle_draw();
	k23.rectangle_draw();

	this->guard_draw();
	this->ball_draw();
}


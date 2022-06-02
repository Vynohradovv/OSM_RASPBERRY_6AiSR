#include "arkanoid.h"
#include "rectangle.h"
#include "guard.h"
#include "ball.h"

#include "peripherals.h"

extern volatile long globalTimer_ms;


//rectangle k11(100,10,0xFF0000);
//rectangle k12(450,10,0x10FF00);
//rectangle k13(800,10,0x2090FF);
//rectangle k14(1150,10,0xFF0010);
//rectangle k15(1500,10,0x14FF00);
//rectangle k16(1850,10,0x1040F6);
//rectangle k17(2200,10,0x02003F);
//
//
//rectangle k22(450,310,0x10FF00);
//rectangle k23(800,310,0x1040F6);
//rectangle k24(1150,310,0x2090FF);
//rectangle k25(1500,310,0x14FF00);
//rectangle k26(1850,310,0xFF0010);


arkanoid::arkanoid(void)
{
	ball_x = 8;
	ball_y = -8;
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

//	k11.draw();
//	k12.draw();
//	k13.draw();
//	k14.draw();
//	k15.draw();
//	k16.draw();
//	k17.draw();
//
//	k22.draw();
//	k23.draw();
//	k24.draw();
//	k25.draw();
//	k26.draw();

	this->guard_draw();
	this->ball_draw();
}


#include "arkanoid.h"
#include "rectangle.h"
#include "peripherals.h"

extern volatile long globalTimer_ms;

#define TEXT_GO_X		(200)
#define TEXT_GO_Y		(200)
#define TEXT_GO_SIZE_X	(300)
#define TEXT_GO_SIZE_Y	(50)

#define TEXT_WIN_X		(40)
#define TEXT_WIN_Y		(200)
#define TEXT_WIN_SIZE_X	(556)
#define TEXT_WIN_SIZE_Y	(50)

#define MAX_SCORE		(9)


extern unsigned int GRAPH[640 * 480];

extern int game_over_r[50][300];
extern int game_over_g[50][300];
extern int game_over_b[50][300];

extern int you_win_r[50][556];
extern int you_win_g[50][556];
extern int you_win_b[50][556];


rectangle k11(50,10), k12(160,10), k13(270,10), k14(380,10), k15(490,10);
rectangle k21(160,55), k22(270,55), k23(380,55);
rectangle k31(270,100);

arkanoid::arkanoid(void)
{
	ball_x = 5;
	ball_y = -5;
	rectangle_x = 0;
	rectangle_y = 8;
	guard_step_left = 10;
	guard_step_right = -10;
	start_game = false;
	game_over = false;
	win_game = false;
	score = 0;
}

bool arkanoid::isConnect(rectangle *obj)
{
	if((this->ball_getPosY() == obj->rectangle_getPosY())&&
		((this->ball_getPosX() >= obj->rectangle_getPosX())&&(this->ball_getPosX() <= obj->rectangle_getPosX() + 100))
		)
	{
		obj->rectangle_visible(false);
		ball_y = -ball_y;
		ball_x = -ball_x;
		score++;
	}
	return false;
}

void arkanoid::ShowTextGameOver(void)
{
	for (int b=TEXT_GO_Y; b<(TEXT_GO_Y+TEXT_GO_SIZE_Y); b++)
	{
	  for (int a=TEXT_GO_X; a<(TEXT_GO_X+TEXT_GO_SIZE_X); a++)
	  {
		  int Color = game_over_r[b - TEXT_GO_Y][a - TEXT_GO_X] << 16 | game_over_g[b - TEXT_GO_Y][a - TEXT_GO_X] << 8 | game_over_b[b - TEXT_GO_Y][a - TEXT_GO_X];
		  SetPixel(GRAPH,a,b, Color);
	  }
	}
}

void arkanoid::ShowTextWin(void)
{
	for (int b=TEXT_WIN_Y; b<(TEXT_WIN_Y+TEXT_WIN_SIZE_Y); b++)
	{
	  for (int a=TEXT_WIN_X; a<(TEXT_WIN_X+TEXT_WIN_SIZE_X); a++)
	  {
		  int Color = you_win_r[b - TEXT_WIN_Y][a - TEXT_WIN_X] << 16 | you_win_g[b - TEXT_WIN_Y][a - TEXT_WIN_X] << 8 | you_win_b[b - TEXT_WIN_Y][a - TEXT_WIN_X];
		  SetPixel(GRAPH,a,b, Color);
	  }
	}
}

void arkanoid::WineGame(void)
{
	if((globalTimer_ms % 15) && win_game)
	{
		if(score >= MAX_SCORE)
		{
			this->ShowTextWin();
		}
	}
}

void arkanoid::GameOver(void)
{
	if((globalTimer_ms % 15) && game_over)
	{

		if(k11.rectangle_getPosY() < 350)
		{
			k11.rectangle_move(rectangle_x, rectangle_y);
		}else{
			k11.rectangle_visible(false);

			if(win_game != true) this->ShowTextGameOver();
		}

		if(k12.rectangle_getPosY() < 350)
		{
			k12.rectangle_move(rectangle_x, rectangle_y);
		}else{
			k12.rectangle_visible(false);
		}

		if(k13.rectangle_getPosY() < 350)
		{
			k13.rectangle_move(rectangle_x, rectangle_y);
		}else{
			k13.rectangle_visible(false);
		}

		if(k14.rectangle_getPosY() < 350)
		{
			k14.rectangle_move(rectangle_x, rectangle_y);
		}else{
			k14.rectangle_visible(false);
		}

		if(k15.rectangle_getPosY() < 350)
		{
			k15.rectangle_move(rectangle_x, rectangle_y);
		}else{
			k15.rectangle_visible(false);
		}

		if(k21.rectangle_getPosY() < 350)
		{
			k21.rectangle_move(rectangle_x, rectangle_y);
		}else{
			k21.rectangle_visible(false);
		}

		if(k22.rectangle_getPosY() < 350)
		{
			k22.rectangle_move(rectangle_x, rectangle_y);
		}else{
			k22.rectangle_visible(false);
		}

		if(k23.rectangle_getPosY() < 350)
		{
			k23.rectangle_move(rectangle_x, rectangle_y);
		}else{
			k23.rectangle_visible(false);
		}

		if(k31.rectangle_getPosY() < 350)
		{
			k31.rectangle_move(rectangle_x, rectangle_y);
		}else{
			k31.rectangle_visible(false);
		}
	}
}

void arkanoid::ProcessGame(void)
{
	if((globalTimer_ms % 15) && start_game)
	{
		this->ball_mov(ball_x, ball_y);

		if(this->ball_getPosY() < 5)
		{
			ball_y = -ball_y;
		}

		if((this->ball_getPosX() < 15)||
			(this->ball_getPosX() > 600)) //2450
		{
			ball_x = -ball_x;
		}

		if(this->ball_getPosY() > 450) //1800
		{
			this->ball_visible(false);
			start_game = false;
			game_over = true;
		}


		if(this->guard_isTouch(this->ball_getPosX(),this->ball_getPosY()))
		{
			ball_y = -ball_y;
		}

		if(k11.rectangle_isActive()) this->isConnect(&k11);
		if(k12.rectangle_isActive()) this->isConnect(&k12);
		if(k13.rectangle_isActive()) this->isConnect(&k13);
		if(k14.rectangle_isActive()) this->isConnect(&k14);
		if(k15.rectangle_isActive()) this->isConnect(&k15);

		if(k21.rectangle_isActive()) this->isConnect(&k21);
		if(k22.rectangle_isActive()) this->isConnect(&k22);
		if(k23.rectangle_isActive()) this->isConnect(&k23);

		if(k31.rectangle_isActive()) this->isConnect(&k31);

		if(score >= MAX_SCORE)
		{
			win_game = true;
		}
	}

}

void arkanoid::draw(void)
{
	int Key = getKey();

	this->ClearScreen();

	switch(Key)
	{

	case 105:
		if(start_game && (this->guard_getPosX() > 50))
		{
			this->guard_mov(guard_step_right,0);
		}
		break;

	case 106:
		if((start_game) && (this->guard_getPosX() < 500))
		{
			this->guard_mov(guard_step_left,0);
		}
		break;

	case 57:

		if(start_game == false) start_game = true;
		break;

	default:
		break;
	}

	this->ProcessGame();
	this->GameOver();
	this->WineGame();



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

	k31.rectangle_draw();

	this->guard_draw();
	this->ball_draw();
}


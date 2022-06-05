#include "ball.h"
#include "peripherals.h"

extern unsigned int GRAPH[640 * 480];

#define sizeX 		(20)
#define sizeY		(20)
#define gColor		(0xFF0000)

ball::ball(void)
{
	prY = 400;
	prX = 330;
	prVisible = true;

	this->ball_draw();

}

void ball::ball_visible(bool f)
{
	prVisible = f;
}


void ball::ball_draw(void)
{
	if(prVisible)
	{
		for (int b=prY; b<(prY+sizeY); b++)
		  for (int a=prX; a<(prX+sizeX); a++)
			  SetPixel(GRAPH,a,b, gColor);
	}
}

void ball::ball_mov(int x, int y)
{
		prY += y;
		prX += x;

		this->ball_draw();
}

int ball::ball_getPosX(void)
{
	return prX;
}

int ball::ball_getPosY(void)
{
	return prY;
}

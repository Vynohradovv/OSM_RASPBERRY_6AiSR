#include "ball.h"
#include "peripherals.h"

extern unsigned int GRAPH[640 * 480];

#define sizeX 		(50)
#define sizeY		(50)
#define gColor		(0xFF0000)

ball::ball(void)
{
	prY = 1600; //0 - 1800
	prX = 1100;	//0 - 2500

	this->ball_draw();
}


void ball::ball_draw(void)
{
	for (int b=prY>>2; b<(prY+sizeY)>>2; b++)
	  for (int a=prX>>2; a<(prX+sizeX)>>2; a++)
		  SetPixel(GRAPH,a,b, gColor);
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

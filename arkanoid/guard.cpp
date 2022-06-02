#include "guard.h"

#include "peripherals.h"

extern unsigned int GRAPH[640 * 480];

#define sizeX 		(500)
#define sizeY		(50)
#define gColor		(0xFF0000)

guard::guard(void)
{
	prY = 1700;
	prX = 1100;

	this->guard_draw();

}

void guard::guard_mov(int x, int y)
{
	prY += y;
	prX += x;

	this->guard_draw();
}

void guard::guard_draw(void)
{
	for (int b=prY>>2; b<(prY+sizeY)>>2; b++)
	  for (int a=prX>>2; a<(prX+sizeX)>>2; a++)
		  SetPixel(GRAPH,a,b, gColor);
}

bool guard::guard_isTouch(int objPosX, int objPosY)
{
	if(((prY-sizeY) <= objPosY) &&
			((prX <= objPosX)&&((prX+sizeX) >= objPosX)))
	{

		return true;
	}

	return false;
}

int guard::guard_getPosX(void)
{
	return prX;
}

int guard::guard_getPosY(void)
{
	return prY;
}

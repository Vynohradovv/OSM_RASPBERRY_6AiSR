#include "guard.h"

#include "peripherals.h"

extern unsigned int GRAPH[640 * 480];

#define sizeX 		(100)
#define sizeY		(15)
#define gColor		(0xFF0000)

guard::guard(void)
{
	prY = 430;
	prX = 280;

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
	for (int b=prY; b<(prY+sizeY); b++)
	  for (int a=prX; a<(prX+sizeX); a++)
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

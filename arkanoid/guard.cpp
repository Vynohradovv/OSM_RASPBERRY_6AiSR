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

	this->draw();

}

void guard::mov(int x, int y)
{
	prY = y;
	prX = x;

	this->draw();
}

void guard::draw(void)
{
	for (int b=prY>>2; b<(prY+sizeY)>>2; b++)
	  for (int a=prX>>2; a<(prX+sizeX)>>2; a++)
		  SetPixel(GRAPH,a,b, gColor);
}

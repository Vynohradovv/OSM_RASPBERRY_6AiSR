#include "rectangle.h"
#include "peripherals.h"

extern unsigned int GRAPH[640 * 480];

#define sizeX 		(300)
#define sizeY		(200)

rectangle::rectangle(int x, int y, int color)
{
	prX = x;
	prY = y;
	prColor = color;

	this->draw();

}

void rectangle::move(int x, int y)
{
	prX = x;
	prY = y;

	this->draw();
}

void rectangle::draw(void)
{
	for (int b=prY>>2; b<(prY+sizeY)>>2; b++)
	  for (int a=prX>>2; a<(prX+sizeX)>>2; a++)
		  SetPixel(GRAPH,a,b, prColor);
}

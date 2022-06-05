#include "rectangle.h"
#include "peripherals.h"

extern unsigned int GRAPH[640 * 480];

extern int yellow_r[100][300];
extern int yellow_g[100][300];
extern int yellow_b[100][300];

extern int green_r[100][300];
extern int green_g[100][300];
extern int green_b[100][300];

#define sizeX 		(100)
#define sizeY		(33)

rectangle::rectangle(void)
{
	prX = 0;
	prY = 0;
	prVisible = true;
}

rectangle::rectangle(const int& x, const int& y)
{
	prVisible = true;
	this->rectangle_create(x, y);
}

void rectangle::rectangle_visible(bool f)
{
	prVisible = f;
}

bool rectangle::rectangle_isActive(void)
{
	return prVisible;
}

void rectangle::rectangle_create(int x, int y)
{
	prX = x;
	prY = y;

	prVisible = true;

	this->rectangle_draw();
}

int rectangle::rectangle_getPosX(void)
{
	return prX;
}

int rectangle::rectangle_getPosY(void)
{
	return prY;
}
void rectangle::rectangle_move(int x, int y)
{
	prX += x;
	prY += y;

	this->rectangle_draw();
}

void rectangle::rectangle_draw(void)
{

	long color = 0;

	if(prVisible)
	{
		for (int b=prY; b < (prY+sizeY); b++)
		{
		  for (int a=prX; a < (prX+sizeX); a++)
		  {
	//		  color = yellow_r[b - prY][a - prX] << 16 | yellow_g[b - prY][a - prX] << 8 | yellow_b[b - prY][a - prX];
			  color = green_r[b - prY][a - prX] << 16 | green_g[b - prY][a - prX] << 8 | green_b[b - prY][a - prX];
			  SetPixel(GRAPH,a,b,color);
		  }
		}
	}
}

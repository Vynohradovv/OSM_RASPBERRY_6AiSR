#include "rectangle.h"
#include "peripherals.h"

extern unsigned int GRAPH[640 * 480];

extern int yellow_r[33][100];
extern int yellow_g[33][100];
extern int yellow_b[33][100];

extern int green_r[33][100];
extern int green_g[33][100];
extern int green_b[33][100];

extern int blue_r[33][100];
extern int blue_g[33][100];
extern int blue_b[33][100];

extern int purple_r[33][100];
extern int purple_g[33][100];
extern int purple_b[33][100];

extern int red_r[33][100];
extern int red_g[33][100];
extern int red_b[33][100];

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

int rectangle::rectangle_getColor(int x, int y)
{
	switch(prColor)
	{
	case 0:
		return green_r[y - prY][x - prX] << 16 | green_g[y - prY][x - prX] << 8 | green_b[y - prY][x - prX];
		break;

	case 1:
		return yellow_r[y - prY][x - prX] << 16 | yellow_g[y - prY][x - prX] << 8 | yellow_b[y - prY][x - prX];
		break;

	case 2:
		return blue_r[y - prY][x - prX] << 16 | blue_g[y - prY][x - prX] << 8 | blue_b[y - prY][x - prX];
		break;

	case 3:
		return purple_r[y - prY][x - prX] << 16 | purple_g[y - prY][x - prX] << 8 | purple_b[y - prY][x - prX];
		break;

	case 4:
		return red_r[y - prY][x - prX] << 16 | red_g[y - prY][x - prX] << 8 | red_b[y - prY][x - prX];
		break;

	default:
		return 0xFF0000;
		break;
	}


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

	if(prVisible)
	{
		for (int b=prY; b < (prY+sizeY); b++)
		{
		  for (int a=prX; a < (prX+sizeX); a++)
		  {
			  SetPixel(GRAPH,a,b,this->rectangle_getColor(a, b));
		  }
		}
	}
}

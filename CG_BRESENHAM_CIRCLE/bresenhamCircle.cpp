#include<iostream>
#include<graphics.h>
#include<random>
#include<time.h>
#include<stdio.h>
#include<X11/Xlib.h>
#include<algorithm>

#define Coordinate(x) {(x) = rand()%(100)+1;}  

void circle(int xc , int yc , int x , int y)
{
	putpixel(xc+x, yc+y, RED); 
    putpixel(xc-x, yc+y, RED); 
    putpixel(xc+x, yc-y, RED); 
    putpixel(xc-x, yc-y, RED); 
    putpixel(xc+y, yc+x, RED); 
    putpixel(xc-y, yc+x, RED); 
    putpixel(xc+y, yc-x, RED); 
    putpixel(xc-y, yc-x, RED); 
}



int main()
{
	srand(time(0));

	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	
	int xc,yc,x1,y1,decision;
	x1=0;
	xc=yc=100;
	Coordinate(y1);

	decision=3-2*y1;

	while(y1>=x1)
	{
		x1++;
		if(decision>0)
		{
			y1--;
			decision+=4*(x1-y1)+10;
		}
		else
		{
			decision+=4*x1+6;
			circle(xc,yc,x1,y1);
			delay(100);
		}

	}
	delay(5000);
	closegraph();
	return 0;
}
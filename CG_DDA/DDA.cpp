#include<iostream>
#include<graphics.h>
#include<random>
#include<time.h>
#include<stdio.h>
#include<X11/Xlib.h>

#define Coordinate(x,y) {(x) = rand()%50 + 1 ; (y) = rand()%50+1;}  
#define min(x,y) ((x)>(y)?1:0)
#define Dexy(x,y,z) ((x)>(y)?(z)=(x)-(y):(z)=(y)-(x))  

using namespace std;



void printResult(float coordinates[][1],int n)
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	for(int i=0;i<n;i++)
	{
		putpixel(coordinates[i][0],coordinates[i][1],RED);	
	}
	delay(5000);
	closegraph();
}


int main()
{
	XInitThreads();
	srand(time(0));

	float coordinates[100][1];
	int n=0;
	
	float x1,y1,x2,y2;
	float dx,dy,length,xInc,yInc;

	float X=0;
	float Y=0;

	Coordinate(x1,y1);
	Coordinate(x2,y2);

	cout<<x1<<"\t"<<y1<<"\n";
	cout<<x2<<"\t"<<y2<<"\n";

	printf("Coordinates Initialized \n");

	Dexy(x1,x2,dx);
	Dexy(y1,y2,dy);
	bool flag=false;

	cout<<dx<<"\t"<<dy;

	if(min(dx,dy)>0)
	{
		length=dx;
		flag=true;
	}
	else
	{
		length=dy;
		flag=false;
	}
		
	xInc=dx/length;	
	yInc=dy/length;

	cout<<xInc<<"\t"<<yInc<<"\n";


	while(X<=length || Y<=length)
	{

		X+=xInc;
		Y+=yInc;
		coordinates[n][0]=X;
		coordinates[n][1]=Y;
		n++;	
	}

	for(int i=0;i<n;i++)
	{
		cout<<"\t"<<coordinates[i][0]<<"\t"<<coordinates[i][1];
	}

	printResult(coordinates,n);
	


}
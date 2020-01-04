#include<iostream>
#include<graphics.h>
#include<random>
#include<time.h>
#include<stdio.h>
#include<X11/Xlib.h>
#include<algorithm>

#define Coordinate(x,y) {(x) = rand()%250 + 1 ; (y) = rand()%250+1;}  
#define min(x,y) ((x)>(y)?1:0)
#define Dexy(x,y,z) ((x)>(y)?(z)=(x)-(y):(z)=(y)-(x))  

using namespace std;


struct CO
{
	float x,y;
};

class coordinates
{
	size_t capacity {0};
	size_t size {0};
	public:
	CO *co {nullptr};


	void push(float x , float y)
	{
		if(size==capacity)
		{
			capacity+=5;
			CO *temp=new CO[capacity];
			copy_n(co,size,temp);
			swap(co,temp);
			delete[] temp;
		}

		co[size].x=x;
		co[size].y=y;

		cout<<"\nCoordinate Added at : "<<size<<"\n";
		size++;
	}

	size_t printSize()
	{
		return size;
	}

	void printall()
	{
		int gd=DETECT,gm;
		initgraph(&gd,&gm,NULL);
		for(size_t i=0;i<size;i++)
		{
			//printf("( %f , %f )\n",co[i].x,co[i].y);
			putpixel(co[i].x,co[i].y,RED);
		}
		delay(5000);
		closegraph();
		
	}

};




int main()
{
	XInitThreads();
	srand(time(0));

	coordinates C;

	
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
		C.push(X,Y);	
	}

	

	C.printall();
	


}
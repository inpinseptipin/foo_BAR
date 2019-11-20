#include<iostream>
#include<graphics.h>
#include<random>
#include<time.h>
#include<stdio.h>
#include<X11/Xlib.h>
#include<algorithm>

#define Coordinate(x,y,z) {(x) = rand()%(100-(z)) + 1 ; (y) = rand()%(100-(z))+1;}  
#define min(x,y) ((x)>(y)?1:0)
#define Dexy(x,y,z) ((z) =(y)-(x)) 
#define assign(x,y,z) ((x)>(y) ? (z)=(y) : (z)=(x) )
#define slope(x,y) ((y)/(x)<(1)? 1:0)

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
		for(size_t i=0;i<size;i++)
		{
			printf("( %f , %f )\n",co[i].x,co[i].y);
		}
	}




};

void printResult(coordinates C)
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	size_t size=C.printSize();
	for(size_t i=0;i<size-1;i++)
	{
		putpixel(C.co[i].x,C.co[i].y,RED);
	}
	delay(5000);
	closegraph();
}


int main()
{
	srand(time(0));
	float x1,x2,y1,y2;

	Coordinate(x2,y2,0);
	Coordinate(x1,y1,30);



	cout<<x1<<"\t"<<y1<<"\n";
	cout<<x2<<"\t"<<y2<<"\n";

	coordinates Z;

	float decision,dx,dy;
	float X,Y;
	X=x1;
	Y=y1;


	Dexy(y1,y2,dy);
	Dexy(x1,x2,dx);

	cout<<dy<<"\t"<<dx;

	float slope=dy/dx;
	cout<<slope<<endl;

	if(slope<1)
	{
		decision=2*dy-dx;
		while(X<=x2 ||Y<=y2)
		{
			
			cout<<decision<<"\n";
			if(decision<0)
			{
				X=X+1;
				decision+=2*dy;
				cout<<X<<"\t"<<Y<<"\n";
				Z.push(X,Y);

			}
			else
			{
				decision+=2*dy-2*dx;
				X=X+1;
				Y=Y+1;
				cout<<X<<"\t"<<Y<<"\n";
				Z.push(X,Y);
			}
		}
	}
	else
	{
		decision=2*dx-dy;
		while(X<=x2 || Y<=y2)
		{
			
			//delay(5000);
			cout<<decision<<"\n";
			if(decision<0)
			{
				Y=Y+1;
				decision+=2*dx;
				cout<<X<<"\t"<<Y<<"\n";
				Z.push(X,Y);
			}
			else
			{
				X+=1;
				Y+=1;
				cout<<X<<"\t"<<Y<<"\n";
				decision+=2*dx-2*dy;
				Z.push(X,Y);
			}

		}
	}
	printResult(Z);	
}
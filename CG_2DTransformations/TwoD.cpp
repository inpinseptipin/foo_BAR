#include<iostream>
#include<graphics.h>
#include<random>
#include<time.h>
#include<stdio.h>
#include<X11/Xlib.h>
#include<algorithm>
#include<math.h>

#define clear() printf("\033[H\033[J");
#define translationFactor(x) ((x)=rand()%100 +1)
#define scalingFactor(x,y) ((x)=rand()%5+1 ,(y)=rand()%5+1);
#define rotationalFactor(x) ((x)=rand()%340+1)
#define angle(r,th,l) ((l)==0?sin((th)*3.14/180):cos((th)*3.14/180))
#define coordinate(x,y) ((x)=rand()%300+1 , (y)=rand()%300+1)

using namespace std;


int X1,Y1;
int X2,Y2;
int T,Sx,Sy;
double R11,R12,R21,R22,th;

void printRotation()
{
	double xn,yn;
	line(X1,Y1,X2,Y2);
	rotationalFactor(th);
	angle(R11,th,1);
	angle(R12,th,0);
	angle(R21,th,1);
	angle(R22,th,0);
	xn=((X2*R11)-(Y2*R12));
	yn=((X2*R21)+(Y2*R22));
	delay(1000);
	setcolor(2);
	line(X1,Y1,xn,yn);


}

void printTranslation()
{
	line(X1,Y1,X2,Y2);
	delay(1000);
	line(X1+T,Y1+T,X2+T,Y2+T);
}

void printScaling()
{
	line(X1,Y1,X2,Y2);
	delay(1000);
	setcolor(2);
	line(X1*Sx,Y1*Sy,X2*Sx,Y2*Sy);	
}

void printResult(int x)
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	switch(x)
	{
		case 1:	printTranslation();
				break;
		case 2: printScaling();
				break;
		case 3: printRotation();
				break;
	}
	delay(5000);
	closegraph();
}




int main()
{
	clear();
	srand(time(0));
	XInitThreads();
	coordinate(X1,Y1);
	coordinate(X2,Y2);
	translationFactor(T);
	scalingFactor(Sx,Sy);

	int choice=0;
	
	while(choice!=5)
	{
		clear();
		cout<<"Press 1 for 2D Translation , Press 2 for 2D Scaling , Press 3 for 2D Rotation"<<endl;
		coordinate(X1,Y1);
		coordinate(X2,Y2);
		cin>>choice;
		switch(choice)
		{
			case 1:printResult(choice);
					clear();
					break;
			case 2:printResult(choice);
					clear();
					break;
			case 3:printResult(choice);
					clear();
					break;

			case 5:cout<<"Exiting \n";
					break;
					
			default:cout<<"Try Again \n";
					break;
		}
		
	}
	
}
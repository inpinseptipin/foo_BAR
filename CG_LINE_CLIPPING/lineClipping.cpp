#include<graphics.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

const int TOP=8; //1000
const int LEFT=1; //0001
const int RIGHT=2; //0010
const int BOTTOM=4; //0100
const int INSIDE=0; //0000

struct RECTANGLE
{
	
	int left;	//(x_min,y_min)
	
	int top;	//(x_min,y_max)

	int right;	//(x_max,y_min)

	int bottom;	//(x_max,y_max)

	void init()
	{
		cin>>left>>top>>right>>bottom;
	}
};

struct CLIP_BOUNDS
{
	int x_min;
	int y_min;
	int x_max;
	int y_max;

	void init(int x1,int y1,int x2,int y2)
	{
		x_min=x1;
		y_min=y1;
		x_max=x2;
		y_max=y2;
	}

	void disp()
	{
		cout<<"x_min : "<<x_min<<"\n";
		cout<<"x_max : "<<x_max<<"\n";
		cout<<"y_min : "<<y_min<<"\n";
		cout<<"y_max : "<<y_max<<"\n";
	}


};

void printRectangle(RECTANGLE rect)
{
	int gd=DETECT,gm;
	initgraph(&gd,&gm,NULL);
	rectangle(rect.left,rect.top,rect.right,rect.bottom);
	delay(15000);
	closegraph();
}

int calculateCodes(int x,int y,CLIP_BOUNDS clip_drop)
{
	int code=INSIDE;

	if(x<clip_drop.x_min)
		code|=LEFT;
	else if (x>clip_drop.x_max)
		code|=RIGHT;
	else if (y>clip_drop.y_max)
		code|=TOP;

	return code;
}

void cohenSutherland(int x1,int y1,int x2,int y2,CLIP_BOUNDS clip_drop)
{
	int code1=calculateCodes(x1,y1,clip_drop);
	int code2=calculateCodes(x2,y2,clip_drop);

	bool accept = false; 
  
    while (true) 
    { 
        if ((code1 == 0) && (code2 == 0)) 
        { 
            // If both endpoints lie within rectangle 
            accept = true; 
            break; 
        } 
        else if (code1 & code2) 
        { 
            // If both endpoints are outside rectangle, 
            // in same region 
            break; 
        } 
        else
        { 
            // Some segment of line lies within the 
            // rectangle 
            int code_out; 
            int x, y; 
  
            // At least one endpoint is outside the  
            // rectangle, pick it. 
            if (code1 != 0) 
                code_out = code1; 
            else
                code_out = code2; 
  
            // Find intersection point; 
            // using formulas y = y1 + slope * (x - x1), 
            // x = x1 + (1 / slope) * (y - y1) 
            if (code_out & TOP) 
            { 
                // point is above the clip rectangle 
                x = x1 + (x2 - x1) * (clip_drop.y_max - y1) / (y2 - y1); 
                y = clip_drop.y_max; 
            } 
            else if (code_out & BOTTOM) 
            { 
                // point is below the rectangle 
                x = x1 + (x2 - x1) * (clip_drop.y_min - y1) / (y2 - y1); 
                y = clip_drop.y_min; 
            } 
            else if (code_out & RIGHT) 
            { 
                // point is to the right of rectangle 
                y = y1 + (y2 - y1) * (clip_drop.x_max - x1) / (x2 - x1); 
                x = clip_drop.x_max; 
            } 
            else if (code_out & LEFT) 
            { 
                // point is to the left of rectangle 
                y = y1 + (y2 - y1) * (clip_drop.x_min - x1) / (x2 - x1); 
                x = clip_drop.x_min; 
            } 
  
            // Now intersection point x,y is found 
            // We replace point outside rectangle 
            // by intersection point 
            if (code_out == code1) 
            { 
                x1 = x; 
                y1 = y; 
                code1 = calculateCodes(x1, y1,clip_drop); 
            } 
            else
            { 
                x2 = x; 
                y2 = y; 
                code2 = calculateCodes(x2, y2,clip_drop); 
            } 
        } 
    } 
    if (accept) 
    { 
        cout <<"Line accepted from " << x1 << ", "
             << y1 << " to "<< x2 << ", " << y2 << endl; 
        // Here the user can add code to display the rectangle 
        // along with the accepted (portion of) lines 
    } 
    else
        cout << "Line rejected" << endl;

}

void initCLIP(CLIP_BOUNDS clip_drop,RECTANGLE rect)
{
	clip_drop.init(rect.left,rect.top,rect.right,rect.bottom);
	clip_drop.disp();
}






int main()
{
	RECTANGLE rect;
	CLIP_BOUNDS clip_drop;
	rect.init();
	initCLIP(clip_drop,rect);

	cohenSutherland(5,5,7,7,clip_drop);
	//printRectangle(rect);
	return 0;
}
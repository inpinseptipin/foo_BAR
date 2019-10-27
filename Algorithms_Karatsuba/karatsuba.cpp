#include<iostream>
#include<math.h>

using namespace std;

struct newNumbers
{
	long int x;
	long int y;
	long int power;

	void disp()
	{
		cout<<"LH : "<<x<<" \t RH : "<<y<<"\t Power: "<<power<<endl;
	}
};

int countDigits(long int N,int count)
{
	count++; 		
	if(N>1)
	return countDigits(N/10,count);
}


long int init(short int x)
{
	long int n;
	cout<<"Enter Number "<<x+1<<" : ";
	cin>>n;
	return n;
}

newNumbers divideNumber(long int N,int count,newNumbers X)
{
	X.power=count/2;
	double dividing=pow(10,count/2);
	X.x=N/dividing;
	X.y=fmod(N,dividing);
	return X;
}

long int karatsuba(newNumbers X,newNumbers Y)
{
	long firstTerm=pow(10,(X.power+Y.power))*(X.x*Y.x);
	long secondTerm=pow(10,X.power)*((X.x+X.y)*(Y.x+Y.y)-(X.x*Y.x)-(X.y*Y.y));
	long thirdTerm=(X.y*Y.y);
	return firstTerm+secondTerm+thirdTerm;
}

int main()
{
	
	long int N1,N2;
	int count=0;
	N1=init(0);
	N2=init(1);
	count=countDigits(N1,count);
	newNumbers X=divideNumber(N1,count,X);
	count=0;
	count=countDigits(N2,count);
	newNumbers Y=divideNumber(N2,count,Y);
	X.disp();
	Y.disp();
	long int product=karatsuba(X,Y);
	cout<<"Product of the numbers : "<<product<<endl;
}
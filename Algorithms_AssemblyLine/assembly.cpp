/*
	Assembly Line Shortest Path Algorithm implementation 

	@Copyright(C) 2019 ,Satyarth Arora
*/


#include<iostream>
#include<random>
#include<string>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>


#define clear() printf("\033[H\033[J");
#define random() rand()%10+1; 
using namespace std;

//Delay Function
void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = 1000 * number_of_seconds; 
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds); 
        
} 

//Assembly Line Object
class assembly
{
	public:
	int* STATIONARRAY;
	int* TIMESIZE;
	int ENTRYCOST;
	int EXITCOST;
	int* TRAVERSALCOST;
	int size;
	string STATION_ID;
	
	//Declares Assembly Object 
	assembly(int size,string name)
	{
		STATION_ID=name;
		this->size=size;
		STATIONARRAY=new int[size];
		TRAVERSALCOST=new int[size-1];
	}

	//Initializes Cost of Assembly Objects
	void initCost()
	{
		
		delay(8);
		int i=0;
		ENTRYCOST=random();
		EXITCOST=random();
		while(i!=size-1)
		{
			TRAVERSALCOST[i]=random();
			STATIONARRAY[i]=random();
			i++;
		}
		STATIONARRAY[i]=random();
	}

	//Display function for Assembly Object
	void dispCost()
	{
		clear();
		cout<<"****************************STATION_ID = "<<STATION_ID<<"*******************************\n";
		cout<<"ENTRY COST : "<<ENTRYCOST<<"\n";
		cout<<"EXIT COST : "<<EXITCOST<<"\n";
		for(int i=0;i<size;i++)
		{
			cout<<"Station Cost "<<i+1<<"\t:"<<STATIONARRAY[i]<<"\n";
		}

		for(int i=0;i<size-1;i++)
		{
			cout<<"Traversal Cost "<<i+1<<"\t"<<TRAVERSALCOST[i]<<"\n";
		}

		cout<<"**********************************************************************************\n";
		
	}	
};


void disp(bool fastest[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(fastest[i]==false)
			cout<<"STOP "<<i+1<<"\t : "<<"Line 1 , Station : "<<i+1<<"\n";
		else
			cout<<"STOP "<<i+1<<"\t : "<<"Line 2 , Station : "<<i+1<<"\n";
	}
}


//Program Logger
void log(int line[],int n,int cost)
{
	clear();
	cout<<"*****************************************************************\n";
	for(int i=0;i<n;i++)
	{
		cout<<line[i]<<"\n";
	}
	cout<<"EXIT COST : "<<cost<<"\n";
	cout<<"*****************************************************************\n";
}

//Calculates Shortest Path
void Path(bool fastest1[],bool fastest2[],assembly LINE1,assembly LINE2,int n)
{
	int line1[5];
	int line2[5];

	line1[0]=LINE1.ENTRYCOST+LINE1.STATIONARRAY[0];
	line2[0]=LINE2.ENTRYCOST+LINE2.STATIONARRAY[0];

	for(int j=1;j<n;j++)
	{
		if((line1[j-1]+LINE1.STATIONARRAY[j])<=(line2[j-1]+LINE2.TRAVERSALCOST[j-1]+LINE1.STATIONARRAY[j]))
		{
			line1[j]=line1[j-1]+LINE1.STATIONARRAY[j];
			fastest1[j-1]=false;
		}
		else
		{
			line1[j]=line2[j-1]+LINE1.STATIONARRAY[j]+LINE2.TRAVERSALCOST[j-1];
			fastest1[j-1]=true;	
		}

		if((line2[j-1]+LINE2.STATIONARRAY[j])<=(line1[j-1]+LINE1.TRAVERSALCOST[j-1]+LINE2.STATIONARRAY[j]))
		{
			line2[j]=line2[j-1]+LINE2.STATIONARRAY[j];
			fastest2[j-1]=false;
		}
		else
		{
			line2[j]=line1[j-1]+LINE2.STATIONARRAY[j]+LINE1.TRAVERSALCOST[j-1];
			fastest2[j-1]=true;	
		}
	}


	cout<<"**********************************************************************\n";


	if ((line1[n-1]+LINE1.EXITCOST)<= (line2[n-1]+LINE2.EXITCOST))
	{
		log(line1,n,LINE1.EXITCOST);
		cout<<"Minimum Cost : " <<line1[n-1]+LINE1.EXITCOST<<endl;
		disp(fastest1,n);
		cout<<"Exit from line 1"<<endl;
		
	}
	else
	{
		log(line2,n,LINE2.EXITCOST);
		cout<<"Minimum Cost : " <<line2[n-1]+LINE2.EXITCOST<<endl;
		disp(fastest2,n);
		cout<<"Exit from line 2"<<endl;	
	}

	cout<<"********************************************************************\n";
}

//Driver Program
int main()
{
	srand(time(0));
	int choice=0;
	assembly LINE1(5,"LINE 1"),LINE2(5,"LINE 2");
	LINE1.initCost();
	LINE2.initCost();
		
	do
	{
		cout<<"Press 1 to See Details of LINE 1 \nPress 2 to See Details of LINE 2 \nPress 3 to Compute Shortest Path \nPress 4 to exit \n";
		cin>>choice;

		switch(choice)
		{
			case 1:LINE1.dispCost();
					break;
			case 2:LINE2.dispCost();
					break;
			case 3:	bool fastest1[5];
					bool fastest2[5];
					bool LINE;
					Path(fastest1,fastest2,LINE1,LINE2,5);
					break;
			case 4: cout<<"Exiting \n";
					break;
			default:cout<<"Try Again\n";
					clear();

					break;
		}
	}
	while(choice!=4);
	return 0;
}
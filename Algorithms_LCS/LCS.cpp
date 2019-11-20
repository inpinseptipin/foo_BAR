/* 
	Longest Common Subsequence DP Implementation in C++ (ITERATIVE)
	@Satyarth Arora
*/


#include<iostream>
#include<random>
#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<iterator>
#include<map>

using namespace std;
#define init(x) (x)=rand()%(10)+1; 


//Initializes Hash Table
void initTable(map<char,bool> charTable)
{
	for(int i=0;i<26;i++)
	{
		charTable.insert(pair<char,bool>(65+i,false));
	}
}


//Prints HashTable
void printTable(map<char,bool> charTable)
{
	map<char,bool>::iterator itr;
	bool flag=false;
	for(itr=charTable.begin();itr!=charTable.end();++itr)
	{
		if(itr->second)
		{
			flag=true;
			cout<<itr->first<<",";
		}
	}
	if(!flag)
	{
		cout<<"No COMMON SEQUENCE FOUND"<<endl;
	}
	cout<<endl;
}

//Checks if element already found and added to the subsequence
bool findTable(map<char,bool> charTable,char x)
{
	map<char,bool>::iterator itr;
	itr=charTable.find(x);
	if(itr->first==x)
		return true;
	else
		return false;
	 
}


//Initializes Random Strings
void charString(char C[],int N)
{
	
	for(int i=0;i<N;i++)
	{
		C[i]=rand()%26+1+65;
	}
}

//Prints Strings
void printString(char A[],int N)
{
	for(int i=0;i<N;i++)
	{
		cout<<A[i]<<" , ";
	}	
	cout<<endl;
}


//Computes LONGEST COMMON SUBSEQUENCE
void LCS(char A[],char B[],int N1,int N2)
{
	map<char,bool> charTable;
	initTable(charTable);

	for(int i=0;i<N1;i++)
	{
		for(int j=0;j<N2;j++)
		{
			if(A[i]==B[j])
			{
				if(!findTable(charTable,A[i]))
				{
					charTable.insert(pair<char,bool>(A[i],true));
					i++;
					j=0;
				}
			}
		}
	}

	printTable(charTable);
}

//Driver Program
int main()
{
	srand(time(0));
	int N1,N2;
	init(N1);
	init(N2);
	char A[N1],B[N2];

	charString(A,N1);
	charString(B,N2);

	cout<<"*******************************String 1***********************"<<endl;
	printString(A,N1);
	cout<<"*******************************String 2***********************"<<endl;
	printString(B,N2);
	cout<<"\n\n\n";

	cout<<"*******************************LCS****************************"<<endl;
	LCS(A,B,N1,N2);
	return 0;
}
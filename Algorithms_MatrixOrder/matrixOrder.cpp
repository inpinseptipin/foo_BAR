#include<iostream>
#include<random>
#include<time.h>
#include<bits/stdc++.h>

using namespace std;

#define clear() printf("\033[H\033[J"); //Clear Screen ( LINUX )
#define random() rand()%100+1; //Returns a random Number with the current time as seed
#define compute(x,y,z) z+=floor(log10(abs((x))) + log10(abs((y)))) + 1;


int init()
{
	int n=-1;
	while(n<=0)
	{
		cout<<"Enter No of Matrices : ";
		cin>>n;
		if(n<=0)
		{
			clear();
			cout<<"Invalid Number of Matrices , Try Again Please \n";
		}		
	}
}

void initMatrix(int matrix[],int n)
{
	for(int i=0;i<n;i++)
	{
		matrix[i]=random();
	}
}

void dispMatrix(int matrix[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		printf("Matrix %d : \t Rows : %d , Columns %d \n",i+1,matrix[i],matrix[i+1]);
	}
}


int computeOrder(int matrix[], int n) 
{ 
  
    int X[n][n]; 
  
    int i, j, k, L, q; 
  
    
    for (i = 1; i < n; i++) 
        X[i][i] = 0; 
  
   
    for (L = 2; L < n; L++) 
    { 
        for (i = 1; i < n - L + 1; i++) 
        { 
            j = i + L - 1; 
            X[i][j] = INT_MAX; 
            for (k = i; k <= j - 1; k++) 
            { 
                
                q = X[i][k] + X[k + 1][j] +  
                    matrix[i - 1] * matrix[k] * matrix[j]; 
                if (q < X[i][j]) 
                    X[i][j] = q; 
            } 
        } 
    } 
  
    return X[1][n - 1]; 
} 




int main()
{
	int n=init();
	int matrix[n];	
	initMatrix(matrix,n);
	dispMatrix(matrix,n);

	cout<<"Minimum no of Multiplications : "<<computeOrder(matrix,n);
	return 0;
}



  

#include<iostream>
#include<stdio.h>
#include<conio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#define size 9
using namespace std;


int sudoku[size][size];
int Check (int y[]);
int temp[size];

     void *print(int matrix[size][size])
      {
		for (int i = 0; i < size; i++)
			{
			for (int j = 0; j < size; j++)
			cout << matrix[i][j] << " ";
			cout << endl;
			}
		return 0;
    }
void *RowCheck ( int x[size][size] )
{ 
	int j;
	for (int i=0; i<size; i++)
	{
		for ( j= 0; j<size; j++)
			temp[j] = x[i][j];
		
		if ( Check (temp) == 0 )
			{
			cout<<"\n Not a correct solution";
			exit(0);
		}
	}

}

int Check (int y[size])
  {
	int lineartemp,j;
	for (int i=0; i<size; i++) 
	{
		lineartemp = y[i];
		for ( j=i+1; j<size; j++) 
		 {
			if (y[j] ==  lineartemp)
			return 0;
			}
	}
	return 1;
	
	}
	
void *ColumnCheck ( int x[size][size])
  {
	int j;
	for (int i=0; i<size; i++)
	 {
		for (j= 0; j<size; j++)
		temp[j] = x[j][i];
		
		if ( Check (temp) == 0 )
		{
		cout<<"\n Not a correct solution";
		exit(0);
	
    	}
	}
 }
void *SquaresCheck (int x[size][size])
{
	int i;
	int j;
	int column;
	int row;
	int k;

	for (column=0; column <= 6; column += 3)
	 {
		for (row=0; row <= 6; row += 3) 
		{
			for (k=0, i=0; i<3; i++) 
			{
			for (j=0; j<3; j++)
				temp[k++] = x[row+i][column+j];
	        }
		if (Check(temp) ==0)
		{
		 cout<<"\n Not a correct solution";
		 exit(0);
		} 
	  }
	}
}

int main()
{
	cout<< " \n Enter all the elements row wise ( Use space bar)\n";
	int i,j;
	pthread_t t1,t2,t3;
	typedef struct
	{
		int RowCheck;
		int ColumnCheck;
		int SquaresCheck;
	}
	parameters;
	parameters *data = (parameters *) malloc(sizeof(parameters));
	data->RowCheck = 0;
	data->ColumnCheck = 0;
	for(i=0;i<size;i++)
	for(j=0;j<size;j++)
	
	cin>>sudoku[i][j];
	
	RowCheck(sudoku);
	ColumnCheck(sudoku);
	SquaresCheck(sudoku);
	
	cout<<"\n Sudoku is correct";
	
	
	getch();
	return 0;

}


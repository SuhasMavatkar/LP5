#include<iostream>
#include<cstdlib>
#include<omp.h>
#include<time.h>
#define MAX 10000
using namespace std;

void swap(int &a, int &b)
{
	int x=a;
	a=b;
	b=x;
}

void display(int array[MAX], int n)
{
	cout<<"\nArray : ";
	for(int i=00;i<n;i++)
		cout<<array[i]<<"\t";
}
clock_t start=clock();
void parallel_bubble(int array[MAX],int n)
{
	for(int k=0;k<n-1;k++)
	{
		if(k%2==0)	//even
		{
			//#pragma omp parallel for
			for(int i=0;i<n/2;i++)
			{
				if(array[2*i]>array[2*i+1])
					swap(array[2*i],array[2*i+1]);
			}
		}
		
		else
		{
			//#pragma omp parallel for
			for(int i=0;i<(n/2)-1;i++)
			{
				if(array[2*i+1]>array[2*i+2])
					swap(array[2*i+1],array[2*i+2]);
			}
		}
	}
}
clock_t stop=clock();

int main()
{
	int n,array[MAX];
	cout<<"\n Enter the number of elements : ";
	cin>>n;
	
	for(int i=0;i<n;i++)
		array[i]=rand()%22;
		
	display(array,n);
	parallel_bubble(array,n);
	display(array,n);
	
	cout<<"\nTime required : "<<(double)(stop-start)*1000.0/CLOCKS_PER_SEC<<" ms";			
	return 0;
}

/*
OUTPUT : 
 parallel (1000 elements)  = 0.002 ms
sequential (1000 elements) = 0.005 ms
*/


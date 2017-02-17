#include<iostream>
using namespace std;
void qsort(int r[],int i,int j); 
int partion(int r[],int first,int end);
int main()
{
	int ori[50];
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>ori[i];
		
	qsort(ori,0,n-1);
	
	for(int i=0;i<n;i++)
		cout<<ori[i]<<' ';
	return 0;
}

void qsort(int r[],int i,int j)
{
	if(i<j)
	{
		int pivotloc = partion(r,i,j);
		qsort(r,i,pivotloc-1);
		qsort(r,pivotloc+1,j);
	}
}

int partion(int r[],int first,int end)
{
	int i=first;
	int j=end;
	int pivot = r[first];
	while(i<j)
	{
		while((i<j)&&(r[j]>=pivot))
			j--;
		r[i]=r[j];
		while((i<j)&&(r[i]<=pivot))
			i++;
		r[j]=r[i];	
	}
	r[i]=pivot;
	return i;
}

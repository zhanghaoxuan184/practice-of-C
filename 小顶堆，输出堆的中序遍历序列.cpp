#include<iostream>
using namespace std;
void sift(int r[], int first, int end);
void show(int r[],int n,int s);

int main()
{
	int n, *ori;
	cin >> n;
	ori = new int[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> ori[i];
	for (int i = n / 2; i >= 1; i--)
	{
		sift(ori, i, n);
	}
	
	show(ori,n,1);
	return 0;
}

void sift(int r[], int first, int end)
{
	int i = first, j = first * 2;
	while (j <= end)
	{
		if (j<end&&r[j]>r[j + 1])
			j++;
		if (r[i] <= r[j])
			break;
		else
		{
			r[0] = r[i];
			r[i] = r[j];
			r[j] = r[0];
			i = j;
			j = i * 2;
		}
	}
}

	

void show(int r[],int n,int s)
{
	if(s<=n)
	{
		show(r,n,s*2);
		cout<<r[s]<<' ';
		show(r,n,s*2+1);
	}
}

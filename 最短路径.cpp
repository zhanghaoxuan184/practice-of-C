#include<iostream>
#include<vector>
#define MAX 10000
using namespace std;
int D[50][50],path[50][50];
int vnum;
int main()
{
	void build();
	void solve();
	void print();
	build();
	solve();
	print();
	return 0;
}


void build()
{
	cin>>vnum;
	for(int i=0;i<vnum;i++)
	{
		for(int j=0;j<vnum;j++)
		{
			cin>>D[i][j];
			if(D[i][j]==MAX)
				path[i][j]=j;
			else
				path[i][j]=j;
		}
	}
}
void solve()
{
	for(int k=0;k<vnum;k++)
		for(int i=0;i<vnum;i++)
			for(int j=0;j<vnum;j++)
			{
				if(D[i][k]+D[k][j]<D[i][j])
				{
					D[i][j]=D[i][k]+D[k][j];
					path[i][j]=path[i][k];
				}
			}
}
void print()
{
	int m;
	cin>>m;
	while(m--)
	{
		int tx,ty,k;
		cin>>tx>>ty;
		cout<<D[tx][ty]<<endl;
		k=path[tx][ty];
		cout<<tx<<' ';
		while(k!=ty)
		{
			cout<<k<<' ';
			k=path[k][ty];
		}
		cout<<ty;
		cout<<endl;
	}
}



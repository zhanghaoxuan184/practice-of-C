#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	char aa,bb;
	int wei;
} *nodever;
int* ver,nver;

int main()
{
	void creat();
	void show();
	creat();
	show();
	return 0;
}

void creat()
{
	cin>>nver;
	ver=new int[nver*2];
	for(int i=0;i<nver*2;i++)
	{
		ver[i]=i;
	}
	nodever=new node[nver];
	for(int i2=0;i2<nver;i2++)
	{
		char aa,bb;
		int wei;
		cin>>aa>>bb>>wei;
		nodever[i2]={aa,bb,wei};
	}
}

void show()
{
	int sum=0;
	bool mysort(node a,node b);
	sort(nodever,nodever+nver,mysort);
	for(int i=0;i<nver;i++)
	{
		if(ver[nodever[i].aa-'A']!=ver[nodever[i].bb-'A'])
		{
			cout<<nodever[i].aa<<' '<<nodever[i].bb<<' '<<nodever[i].wei<<endl;
			sum+=nodever[i].wei;
			int tndst=ver[nodever[i].bb-'A'];
			int tnori=ver[nodever[i].aa-'A'];
			for(int i2=0;i2<nver;i2++)
			{
				if(ver[i2]==tnori)
					ver[i2]=tndst;
			}
		}
	}
	cout<<sum;
	system("PAUSE");
	
}

bool mysort(node a,node b)
{
	return a.wei<b.wei;
}

#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
	int wei;
	int v1,v2;
}*ori;
int nv,ne,*ver,sum=0;

int main()
{
	cin>>nv>>ne;
	ver=new int[nv+1];
	for(int i=0;i<nv+1;i++)
		ver[i]=i;
	void build();
	void solve();
	build();
	solve(); 
	cout<<sum;
	return 0;	
}
void build()
{
	int te=ne;
	ori=new node[ne];
	while(te--)
	{
		cin>>ori[te].v1;
		cin>>ori[te].v2;
		cin>>ori[te].wei;
	}
	bool mysort(node a,node b);
	sort(ori,ori+ne,mysort);
}

void solve()
{
	for(int i=0;i<ne;i++)
	{
		if(ver[ori[i].v1]!=ver[ori[i].v2])
		{
			sum+=ori[i].wei;
			int tori,tres;
			tori=ver[ori[i].v1];
			tres=ver[ori[i].v2];
			for(int i=0;i<nv+1;i++)
				if(ver[i]==tori)
					ver[i]=tres;
		}
	}
}
bool mysort(node a,node b)
{
	return a.wei<b.wei;
}

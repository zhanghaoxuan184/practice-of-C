#include<iostream>
#define MAX 2000000000
#define POS tab[((tp+di)%m+m)%m]
using namespace std;
int *tab;
int n,m,p;

int main()
{
	void creat();
	void find();
	creat();
	
	find();
	return 0;
}

int creat()
{
	cin>>n>>m>>p;	
	tab=new int[m];
	for(int i=0;i<m;i++)
		tab[i]=MAX;
	
	for(int i2=0;i2<n;i2++)
	{
		int tn,tp;
		int d=0,di=0;
		cin>>tn;
		tp=tn%p;
		for(int i3=0;POS!=MAX;i3++)
		{
			if(i3%2==0)
			{
				d++;
				di=d*d;
			}
			else
				di*=-1;
		}
		POS=tn;
	}
}
void find()
{
	while(1)
	{
		int tn,tp;
		int d=0,di=0;
		cin>>tn;
		if(tn==-1)
			return ;	
				
		tp=tn%p;
		for(int i=0;;i++)
		{
			if(d>m/2)
			{
				cout<<"NULL"<<endl;
				break;
			}
			if(POS==tn)
			{
				cout<<tn<<endl;
				break;
			}
			else if(POS==MAX)
			{
				cout<<"NULL"<<endl;
				break;
			}
			else if(POS!=MAX)
				cout<<POS<<' ';
			
			if(i%2==0)
			{
				d++;
				di=d*d;
			}
			else
				di*=-1;
		}
	}
}

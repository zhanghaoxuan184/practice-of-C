#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
struct node
{
	int pos;
	int wei;
	struct node* left,*right;
	string shuff;
	node()
	{
		wei=pos=0;
		left=right=NULL;
		shuff="";
	}
}*res,*ori; 
int n,num,n_res=0;

int main()
{
	void creatvec();
	void creattree();
	void show(node*,string);
	creatvec();
	creattree();
	show(ori,"");
	
	bool mysort2(node,node);
	sort(res,res+n_res,mysort2);
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<'('<<res[i].wei<<')'<<':'<<res[i].shuff<<endl;
	}
	
	return 0;
}

void show(node *root,string shuff)
{
	if(root)
	{
		if(root->pos!=0)
		{
			root->shuff=shuff;
			res[n_res++]=*root;
		}
		show(root->left,shuff+"0");
		show(root->right,shuff+"1");
	}
}


void creattree()
{
	while(num>1)
	{
		bool mysort(node,node);
		sort(ori,ori+num,mysort);
		node* pnode,*p1,*p2;
		pnode=new node;p1=new node;p2=new node;
		pnode->wei=ori[num-1].wei+ori[num-2].wei;
		*p1=ori[num-1];*p2=ori[num-2];ori[num-2]=*pnode;
		ori[num-2].left=p1;
		ori[num-2].right=p2;
		num--;
	}
}

void creatvec()
{
	
	cin>>n;
	num=n;
	res=new node[n];
	ori=new node[n];
	for(int i=0;i<n;i++)
	{
		ori[i].pos=i+1;
		cin>>ori[i].wei;
	}
}


bool mysort(node a,node b)
{
	return a.wei>b.wei;
}
bool mysort2(node a,node b)
{
	return a.pos<b.pos;
}

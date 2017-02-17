#include<iostream>
using namespace std;
struct node
{
	int data;
	struct node *left, *right;
	node()
	{
		data = -2000000000;
		left = right = NULL;
	}
}*root;

int main()
{
	void show(node*);
	void creat();

	creat();
	show(root);
	return 0;
}

void creat()
{
	int tn, nums;
	void add(node*, int);

	cin >> nums;
	root = new node;
	cin >> root->data;
	nums--;
	while (nums--)
	{
		cin >> tn;
		add(root, tn);
	}
}
void add(node* tnode, int tn)
{
	if (tn<tnode->data)
	{
		if (tnode->left == NULL)
		{
			tnode->left = new node;
			tnode->left->data = tn;
		}
		else
			add(tnode->left, tn);
	}
	else if (tn>tnode->data)
	{
		if (tnode->right == NULL)
		{
			tnode->right = new node;
			tnode->right->data = tn;
		}
		else
			add(tnode->right, tn);
	}
}
void show(node* tnode)
{
	if (tnode)
	{
		show(tnode->left);
		show(tnode->right);
		cout << tnode->data << ' ';
	}
}

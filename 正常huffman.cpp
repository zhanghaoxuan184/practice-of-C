#include<iostream>
#include<cstdlib>
using namespace std;

struct node{
	int weight;
	struct node *left, *right;
}*head;
int sum;

int main(){
	void create(),solve();
	int m;
	cin >> m;
	while (m--){
		create();
		solve();
	}
	return 0;
}

void create(){
	int n;
	cin >> n;
	head = new node[n+1];
	for (int i = 0; i < n; i++){
		cin >> head[i].weight;
		head[i].left = head[i].right  = NULL;
		}
	head[n].weight = 0;
}

void solve(){
	sum = 0;
	void sort();
	void show(node * root, int level);
	int i = 0;
	
	while (head[1].weight){
		sort();
		for (i = 0; head[i + 2].weight; i++);
		node *p1=new node , *p2 =new node , *q =new node;
		*p1 = head[i], *p2 = head[i + 1];
		q->left = p1; q->right = p2;q->weight = p1->weight + p2->weight;
		head[i] = *q;head[i + 1] = head[i + 2];
	}
	show(head,0);
	cout << sum<< endl;
}

void sort(){
	for (int i=0;head[i].weight; i++)
		for (int j = i + 1; head[j].weight; j++)
			if (head[i].weight<head[j].weight){
				node ntemp;
				ntemp = head[i]; head[i] = head[j]; head[j] = ntemp;
			}
}

void show(node * root,int level){
	if (root->left)
		show(root->left, level + 1);
	if (root->right)
		show(root->right, level + 1);
	if (root->left==NULL && root->right==NULL)
		sum += root->weight*level;
}

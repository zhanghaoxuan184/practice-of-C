#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct node{
	int weight;
	struct node *left, *right;
	node(){
		weight = 0;
		left = right = NULL;
	}
};
int m,n,sum;
vector<node> vec;

int main(){
	void create(), solve();
	cin >> m;
	while (m--){
		create();
		solve();
	}
	return 0;
}

void create(){
	cin >> n;
	for (int i = 0; i < n; i++){
		node temp;
		cin >> temp.weight;
		vec.push_back(temp);
	}
}

void solve(){
	bool mysort(node a, node b);
	void show(node * root, int level);
	sum = 0;
	while (vec.size()>1){
		sort(vec.begin(), vec.end(),mysort);
		node *p1=new node, *p2 = new node, *q=new node;
		*p1 = vec[0], *p2 = vec[1];
		q->weight=p1->weight+p2->weight;
		q->left=p1,q->right=p2;
		vec.erase(vec.begin());
		vec[0] = *q;
	}
	show(&vec[0], 0);
	cout << sum<<endl;
	vec.clear();
}
bool mysort(node a, node b){
	return (a.weight < b.weight);
}
void show(node * root, int level){
	if (root->left)
		show(root->left, level + 1);
	if (root->right)
		show(root->right, level + 1);
	if (root->left == NULL && root->right == NULL)
		sum += root->weight*level;
}
void trase(node * root)
{
	if(root)
	{
		cout<<root->weight<<' ';
		trase(root->left);
		trase(root->right);
	}
}

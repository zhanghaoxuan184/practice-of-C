#include <iostream>
#include<cstdlib>
#include<vector>

using namespace std;

typedef struct BiTNode{
	char data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;

BiTree CreateBiTree(){
	char ch;
	BiTree T;
	cin>>ch;
	if (ch == '#')
		T = NULL;
	else
	{
		T = new(BiTNode);
		T->data = ch;
		T->lchild = CreateBiTree();
		T->rchild = CreateBiTree();
	}
	return T;
}

void print(BiTree root)
{
    if(root == NULL)
        return;

    vector<BiTree> vec;
    vec.push_back(root);
    int cur = 0;
    int last = 1;

    while(cur < vec.size()) {
        last = vec.size();

        while(cur < last) {
            cout<<vec[cur]->data<<" ";

            if(vec[cur]->lchild != NULL)
                vec.push_back(vec[cur]->lchild);
            if(vec[cur]->rchild != NULL)
                vec.push_back(vec[cur]->rchild);
            ++cur;
        }
        cout<<endl;
    }
}

int main(){
	BiTree T;
	T = CreateBiTree();
	print(T);
	system("PAUSE");
	return 0;
}

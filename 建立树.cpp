#include <iostream>
#include<cstdlib>

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

void PreOrderTraverse(BiTree T){
	if (T){
		cout<<T->data;
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}


void InOrderTraverse(BiTree T){
	if (T){
		InOrderTraverse(T->lchild);
		cout<<T->data;
		InOrderTraverse(T->rchild);
	}
}

void PostOrderTraverse(BiTree T){
	if (T){
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		cout<<T->data;
	}
}

int main(){
	BiTree T;
	T = CreateBiTree();
	InOrderTraverse(T);
	system("PAUSE");
	return 0;
}

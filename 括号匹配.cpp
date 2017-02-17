#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	string strin;
	cin>>strin;
	stack<char> oper;
	for(int i=0;i<strin.size();i++)
	{
		switch(strin[i])
		{
			case '(': case '[': case '{': oper.push(strin[i]);break;
			case ')': case ']': case '}': oper.pop();break;
		}
	}
	if(oper.size()==0)
		cout<<"right"<<endl;
	else
		cout<<"wrong"<<endl;
	return 0;
}

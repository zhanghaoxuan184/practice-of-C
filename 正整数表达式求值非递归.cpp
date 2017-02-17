#include<iostream>
#include<cstdlib>
#include<string>
#include<stack>

using namespace std;

int main()
{
	char orig[200];
	stack<double> res;
	stack<char> ope;

	cin >> orig;

	int flagsmall = 1;
	int flagbig = 1;
	ope.push(0);
	for (int i = 0; flagbig ; i++)
	{
		for (string num;orig[i]>='0' && orig[i]<='9';i++)
		{
			num += orig[i];

			if (orig[i + 1]<'0' || orig[i + 1]>'9')
			{ 
				i++;
				res.push(atoi(num.c_str()));
				break;
			}
		}

		double cal(double a, double b, char oper);
		int opeJudg(char ope1, char ope2);

		while (1)
		{
			if (orig[i] == 0 && res.size() == 1)
			{
				flagbig = 0;
				break;
			}
				
			if (opeJudg(ope.top(),orig[i])==-1)
			{
				ope.push(orig[i]);
				break;
			}
			else if (opeJudg(ope.top(), orig[i]) ==0)
			{
				ope.pop();
				break;
			}
			else if (opeJudg(ope.top(), orig[i]) == 1)
			{
				double a, b;
				a = res.top(); res.pop();
				b = res.top(); res.pop();
				res.push(cal(b, a, ope.top()));
				ope.pop();
			}
		}
	}
	cout << res.top();
	system("PAUSE");
	return 0;
}

int opeJudg(char ope1,char ope2)
{
	if (ope1 == '+' || ope1 == '-')
	{
		if (ope2 == '+' || ope2 == '-' || ope2== ')' || ope2=='\0')
			return 1;
		if (ope2 == '*' || ope2 == '/' || ope2 == '(')
			return -1;
	}
	if (ope1 == '*' || ope1 == '/')
	{
		if (ope2 == '+' || ope2 == '-' || ope2 == ')' || ope2 == '\0')
			return 1;
		if (ope2 == '*' || ope2 == '/')
			return 1;
		if (ope2 == '(')
			return -1;
	}
	if (ope1 == '(')
	{
		if (ope2 == ')')
			return 0;
		else
			return -1;
	}
	if (ope1 == ')')
	{
		return 1;
	}
	if (ope1 == 0)
	{
		if (ope2 == 0)
			return 0;
		else
			return -1;
	}
}
double cal(double a, double b, char oper)
{
	switch (oper)
	{
	case '+':return a + b;
	case '-':return a - b;
	case '*':return a * b;
	case '/':return a / b;
	}
}


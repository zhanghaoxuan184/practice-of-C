#include<iostream>
#include<cstdlib>
#include<string>
#include<stack>

using namespace std;

char orig[200];
int step = 0;
int main()
{
	double solve();
	cin >> orig;
	cout << solve();
	system("PAUSE");
	return 0;
}

double solve()
{
	stack<double> res;
	stack<char> ope;
	void getnum(stack<double> &res);
	int weight(char oper);
	double cal(double a, double b, char oper);
	ope.push(0);
	if (orig[step] == '-')
	{
		res.push(-1);
		ope.push('*');
		step++;
	}

	while (1)
	{	
		getnum(res);
		while (1)
		{
			if (res.size() == 1 && (orig[step] == '\0' || orig[step] == ')'))
			{
				step++;
				return res.top();
			}

			if (orig[step] == '(')
			{
				step++;
				res.push(solve());
			}
			else if (orig[step] == ')' || orig[step] == '\0')
			{
				double a, b;
				a = res.top(); res.pop();
				b = res.top(); res.pop();
				res.push(cal(b, a, ope.top()));
				ope.pop();
			}
			else if (weight(ope.top()) >= weight(orig[step]))
			{
				double a, b;
				a = res.top(); res.pop();
				b = res.top(); res.pop();
				res.push(cal(b, a, ope.top()));
				ope.pop();
				ope.push(orig[step]);
				step++;
				break;
			}
			else if (weight(ope.top()) < weight(orig[step]))
			{
				ope.push(orig[step]);
				step++;
				break;
			}
		}
	}
}

void getnum(  stack<double>  &res)
{
	for (string num; orig[step] >= '0' && orig[step] <= '9'; step++)
	{
		num += orig[step];

		if (orig[step + 1]<'0' || orig[step + 1]>'9')
		{
			step++;
			res.push(atoi(num.c_str()));
			break;
		}
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
int weight(char oper)
{
	if (oper == '+' || oper == '-')
		return 1;
	else if (oper == '*' || oper == '/')
		return 2;
	else if (oper == 0)
		return 0;
}


#include<iostream>
#include<string>

using namespace std;

string create();
void printall(string result);

string stemp="";
int i_stemp=0;

int main()  
{
	while(1)
	{
		cin >> stemp;
		if(stemp=="***")
			break;
		printall(create());
	}
	return 0;
}

string create()
{
	string sout="";
	for (; i_stemp < stemp.size();i_stemp++)
	{
		if (stemp[i_stemp] == ')')
		{
			string outstemp="";
			for (int i = sout.size() - 1; i > 0; i--)
			{
				outstemp += sout[0];
				outstemp += sout[i];
			}
			outstemp += sout[0];
			sout = outstemp;
			return sout;
		}
		else if (stemp[i_stemp] == '(')
		{
			i_stemp++;
			sout+=create();
		}
		else
		{
			sout += stemp[i_stemp];
		}
	}
	return sout;
}

void printall(string result)
{
	string A = "sae";
	string B = "t" + A + "d" + A;
	for (int i = 0; i < result.size(); i++)
	{
		if (result[i] == 'A')
			cout << A;
		else if (result[i] == 'B')
			cout << B;
		else
			cout << result[i];
	}
	cout << endl;
	i_stemp=0;
}

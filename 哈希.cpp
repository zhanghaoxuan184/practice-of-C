#include<iostream>
#define MAX 2000000000
using namespace std;
int main()
{
	int m, p;
	int *table;
	int nums = 0;
	cin >> m >> p;
	
	table = new int[m];
	for (int i = 0; i < m; i++)
	{
		table[i] = MAX;
	}

	while (1)
	{
		int temp,tempin;
		cin >> temp;
		tempin = temp%p;

		if (temp == -1)
		{
			return 0;
		}

		while (table[tempin] != MAX)
		{
			if (table[tempin] == temp)
			{
				cout << tempin<<endl;
				break;
			}	
			(++tempin)%m;
		}
		
		if (nums != m - 1 && table[tempin] == MAX)
		{
			table[tempin]=temp;
			cout << tempin<<endl;
			nums++;
		}
		else if (nums == m - 1 && table[tempin] == MAX)
		{
			cout << "Table full!";
			return 0;
		}
	}
}

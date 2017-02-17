#include<iostream>
#include<vector> 
#include<cstdlib>
struct node
{
	int xi;
	int zhi;
};
using namespace std;

int main()
{
	int m, n;
	vector<node> head1, head2, head;
	cin >> m >> n;
	for (int i0 = 0; i0<m; i0++)
	{
		int xi, zhi;
		node tnode;
		cin >> tnode.xi >> tnode.zhi;
		head1.push_back(tnode);
	}
	for (int i1 = 0; i1<n; i1++)
	{
		int xi, zhi;
		node tnode3;
		cin >> tnode3.xi >> tnode3.zhi;
		head2.push_back(tnode3);
	}

	for (int i = 0; head1.size() + head2.size()>0; i++)
	{
		if (head1.size()>0 && head2.size()>0)
		{
			if (head1[0].zhi<head2[0].zhi)
			{
				head.push_back(head1[0]);
				head1.erase(head1.begin());
			}
			else if (head1[0].zhi == head2[0].zhi)
			{
				node tnode2;
				tnode2.zhi = head1[0].zhi;
				tnode2.xi = head1[0].xi + head2[0].xi;
				head.push_back(tnode2);
				head1.erase(head1.begin());
				head2.erase(head2.begin());
			}
			else if (head1[0].zhi>head2[0].zhi)
			{
				head.push_back(head2[0]);
				head2.erase(head2.begin());
			}
		}
		else if (head1.size()>0)
		{
			head.push_back(head1[0]);
			head1.erase(head1.begin());
		}
		else if (head2.size()>0)
		{
			head.push_back(head2[0]);
			head2.erase(head2.begin());
		}
	}


	for (int i3 = 0; i3<head.size(); i3++)
	{
		if (head[i3].xi == 0)
		{
			head.erase(head.begin() + i3);
			i3--;
		}
	}

	for (int i4 = 0; i4<head.size(); i4++)
	{		
		if (head.size() == 0)
			cout << 0;
		switch (head[i4].zhi)
		{
			case 0: cout << head[i4].xi; break;
			case 1:
				switch (head[i4].xi)
				{
				case 1:cout << 'x'; break;
				case -1:cout << "-x"; break;
					default:cout << head[i4].xi<<'x';
				}break;
			default:
				switch (head[i4].xi)
				{
				case 1:cout << "x^" << head[i4].zhi; break;
				case -1:cout << "-x^" << head[i4].zhi; break;
					default:cout << head[i4].xi<<"x^"<<head[i4].zhi;
				}break;
		}
		if (head.size() - 1 >= i4 + 1)
			if (head[i4+1].xi > 0)
				cout << '+';
	}
	system("PAUSE");
	return 0;
}

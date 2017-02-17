#include<iostream>
#include<cstdlib>
#include<algorithm>

using namespace std;

int main()
{
	int solve();
	int m;

	cin >> m;
	while (m--)
	{
		solve();
	}
}

int solve()
{
	bool mysort(int a, int b);
	int *vertex, *result;
	int n_ver, n_edge;
	cin >> n_ver >> n_edge;
	vertex = new int[n_ver];
	result = new int[n_ver];

	for (int i0 = 0; i0 < n_ver; i0++)
	{
		vertex[i0] = i0;
		result[i0] = 0;
	}

	int tem1, tem2, ori, dst;
	for (int i1 = 0; i1<n_edge; i1++)
	{
		cin >> tem1 >> tem2;
		ori = vertex[tem1 - 1];
		dst = vertex[tem2 - 1];

		for (int i2 = 0; i2 < n_ver; i2++)
		{
			if (vertex[i2] == ori)
				vertex[i2] = dst;
		}
	}
	
	sort(vertex,vertex+n_ver,mysort);
	int n_res = 0, last = vertex[0], pos = 0;
	for (int i3 = 0; i3 < n_ver+1; i3++){
		if (i3 == n_ver){
			result[pos++] = n_res;
			break;
		}
		if (last == vertex[i3]){
			n_res++;
		}
		else{
			result[pos++] = n_res;
			last = vertex[i3];
			n_res = 1;
		}
	}

	cout<<pos<<endl;
	sort(result,result+pos,mysort);
	for (int i4 = 0; i4 < pos; i4++){
		cout << result[i4] << ' ';
	}
	cout << endl;
	return 0;
}


bool mysort(int a, int b){
	return a < b;
}

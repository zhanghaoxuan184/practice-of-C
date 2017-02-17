#include<iostream>
#include<cstdlib>
#include<vector>

using namespace std;

struct coor
{
	int x, y;
	int dir;
};

int **maze;
coor begin0,end0;
void show();

vector<coor> vcoor;

int main()
{
	void create();
	void solve(coor ,int);

	create();
	solve(begin0,23333);
	return 0;
}

void create()
{
	int m, n;
	cin >> m >> n;
	cin >> begin0.x >> begin0.y;
	cin >> end0.x >> end0.y;

	maze = new int*[m + 2];
	for (int i = 0; i < m + 2; i++)
		maze[i] = new int[n + 2];

	for (int j = 0; j < m + 2; j++)
		for (int k = 0; k < n + 2; k++)
			if (j == 0 || j == m + 1 || k == 0 || k == n + 1)
				maze[j][k] = 1;
			else
				cin >> maze[j][k];
}
void solve(coor posi, int dir)
{
	int pass(coor posi,int dir);
	vcoor.push_back(posi);
	maze[posi.x][posi.y] = 2;
	while(1)
	{	
		for(int i=1;i<5;i++)
		{
			if(pass(posi,i))
			{
				switch(i)
				{
					case 1:posi.y++; break;
					case 2:posi.x++; break;
					case 3:posi.y--; break; 
					case 4:posi.x--; break; 
				}
				vcoor.back().dir=i;
				vcoor.push_back(posi);
				if (posi.x == end0.x &&posi.y == end0.y)
				{
					vcoor[vcoor.size() - 1].dir = 1;
					show();
					exit(0);
				}
				maze[posi.x][posi.y] = 2;
				i=0;
			}
		}
		vcoor.pop_back();
		posi.x=vcoor[vcoor.size()-1].x;
		posi.y=vcoor[vcoor.size()-1].y;
		if(vcoor.size()==0)
		{
			cout<<"no";
			exit(0);
		}
	}
}
void show()
{
	for (int i = 0; i < vcoor.size(); i++)
	{
		cout << '(' << vcoor[i].x << ',' << vcoor[i].y
			<< ',' << vcoor[i].dir << ')';
		if (i != vcoor.size() - 1)
			cout << ',';
	}
}
int pass(coor posi,int dir)
{
	switch (dir)
	{
		case 1:posi.y++; break;
		case 2:posi.x++; break;
		case 3:posi.y--; break; 
		case 4:posi.x--; break; 
	}
	if(maze[posi.x][posi.y]!=0)
		return 0;
	return 1;
}

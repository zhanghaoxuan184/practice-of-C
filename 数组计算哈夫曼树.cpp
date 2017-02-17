#include<iostream>
#include<algorithm>
using namespace std;

bool mysort(int a, int b){
	return a > b;
}

int main(){
	int m,n, ori[100] = {0};
	cin>>m;	
	while (m--){		
		int result = 0;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> ori[i];
		for(int j=n;j>1;j--){
			sort(ori, ori + j , mysort);
			result += ori[j - 1] + ori[j - 2];
			ori[j - 2] += ori[j - 1];
		}
		cout<<result<<endl;
	}
	return 0;
}

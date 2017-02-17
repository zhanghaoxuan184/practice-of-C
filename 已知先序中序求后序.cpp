#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	void post(char *pre,char *in,int len);
	int len;
	char pre[50],in[50];
	cin>>pre>>in;
	len=strlen(in);
	post(pre,in,len);
	return 0;
}

void post(char *pre,char *in,int len)
{
	char *tp;
	int len2;
	for(tp=in;tp<in+len;tp++)
		if(*tp==*pre)
			break;
	len2=tp-in;
	if(len2)
		post (pre+1,in,len2);
	if(len-len2-1)
		post(pre+len2+1,tp+1,len-len2-1);
	cout<<*tp;
}

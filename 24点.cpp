#include<stdio.h>
#include<string.h>
#define OP(O) num[0].n=a.n O b.n,sprintf(num[0].s,"(%s"#O"%s)",a.s,b.s);if(sol(n-1)) return 1
#define EP(O) num[0].n=b.n O a.n,sprintf(num[0].s,"(%s"#O"%s)",b.s,a.s);if(sol(n-1)) return 1
typedef struct NUM1
{
	float n;
	char s[100];
}NUM;
NUM num[4];

int sol(int n)
{
	int i,j,k,m;
	if(n==1)
	{
		if(num[0].n-24<1E-5&&num[0].n-24>-1E-5)	return 1;
		else return 0;
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			NUM a=num[i],b=num[j],tem[4];
			memcpy(tem,num,sizeof(num));
			for(k=0,m=1;k<n;k++) 
				if(k!=i&&k!=j)
					num[m++]=num[k];			
			OP(+);OP(-);OP(*);EP(-);
			if(b.n!=0) OP(/);if(a.n!=0) EP(/);
			memcpy(num,tem,sizeof(num));
		}
	}
return 0;
}
int main()
{
	int i;
	for(i=0;i<4;i++)
		scanf("%f",&num[i].n),sprintf(num[i].s,"%d",(int)num[i].n);
	if(sol(4)==1) 
		puts(num[0].s);
	else 
		puts("NO ANSWER");
	return 0;
}

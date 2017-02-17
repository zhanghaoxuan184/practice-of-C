#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<math.h>

#define SETTIME  strftime(stock[numtime].mytime,sizeof(stock[numtime].mytime),"%x%A%X",localtime(&t))

struct STOCK  //股票
{
	char mytime[50],advice[100];
	int flag,stocknum;
	double orihand,handmon,income,incomerate;
	double ori,stock_ave;
	double cur,last;
};
int BUY[1000],b,c;

int main()
{
	FILE *save,*data;
	STOCK stock[500];
	int numtime=0;
	time_t t=time(NULL);
	
	save=fopen("save.txt","a");  //打开存档
	fprintf(save,"%s %s %d %d %f %f %f %f %f %f %f %f %d %d\n",NULL,NULL,0,0,  0,0,  0,0,   0,0,  0,0,  0,0);
	for(int i=0;i<1000;i++)
		fprintf(save,"%d ",0);
	fprintf(save,"\n");
	fclose(save);

	save=fopen("save.txt","r");
	fscanf(save,"%s %s %d %d %lf %lf %lf %lf %lf %lf %lf %lf %d %d",stock[numtime].mytime,stock[numtime].advice,&stock[numtime].flag,\
		&stock[numtime].stocknum,&stock[numtime].orihand,&stock[numtime].handmon,&stock[numtime].income,&stock[numtime].incomerate,\
		&stock[numtime].ori,&stock[numtime].stock_ave,&stock[numtime].cur,&stock[numtime].last,&b,&c);
	fclose(save);                 //存档读取完毕

	data=fopen("data.txt","a");   //打开数据

	while(1)
	{
		if(stock[numtime].last==0)  //新开交易
		{
			SETTIME;
			printf("%s\n",stock[numtime].mytime);
			fprintf(data,"%s\n",stock[numtime].mytime);
			printf("请输入您要投入股市的资金,最好不小于五万\n");
			fprintf(data,"请输入您要投入股市的资金,最好不小于五万\n");
			scanf("%lf",&stock[numtime].orihand);
			printf("请输入您所要购买股票的初始价格\n");
			fprintf(data,"请输入您所要购买股票的初始价格\n");
			scanf("%lf",&stock[numtime].ori);
			stock[numtime].handmon=stock[numtime].orihand;
			stock[numtime].cur=stock[numtime].ori;
			stock[numtime+1].last=stock[numtime].last;
			stock[numtime+1].orihand=stock[numtime].orihand;
			stock[numtime+1].handmon=stock[numtime].handmon;
			stock[numtime+1].ori=stock[numtime].ori;
			stock[numtime+1].stock_ave=stock[numtime].stock_ave;
			stock[numtime+1].stocknum=stock[numtime].stocknum;
			BUY[b]=(int)floor(stock[numtime].orihand*0.1/stock[numtime].cur/100)*100;
			if(BUY[b]>0) 
			{
				sprintf(stock[numtime].advice,"本软件建议您购买%d只股,然后",BUY[b]);
				stock[numtime].stock_ave=(BUY[b]*stock[numtime].cur+stock[numtime].stocknum*stock[numtime].stock_ave)/(stock[numtime].stocknum+BUY[b]);
				stock[numtime+1].stock_ave=stock[numtime].stock_ave;
				stock[numtime].handmon-=BUY[b]*stock[numtime].cur;
				stock[numtime].stocknum+=BUY[b];
				stock[numtime+1].stocknum=stock[numtime].stocknum;
				stock[numtime].income=stock[numtime].handmon+stock[numtime].stocknum*stock[numtime].cur-stock[numtime].orihand;
				stock[numtime].incomerate=stock[numtime].income/stock[numtime].orihand*100;
				stock[numtime+1].handmon=stock[numtime].handmon;
				stock[numtime+1].last=stock[numtime].cur;
				b++;
			}

		}             //新开交易结束

		else            // 从存档中读取数据或其他过程
		{
			SETTIME;
			printf("%s\n",stock[numtime].mytime);
			fprintf(data,"%s\n",stock[numtime].mytime);
			printf("请输今日股价\n");
			fprintf(data,"请输今日股价\n");
			scanf("%lf",&stock[numtime].cur);
			stock[numtime+1].orihand=stock[numtime].orihand;
			stock[numtime+1].ori=stock[numtime].ori;
			stock[numtime+1].last=stock[numtime].last;
			stock[numtime+1].stock_ave=stock[numtime].stock_ave;
			stock[numtime+1].stocknum=stock[numtime].stocknum;
			stock[numtime+1].handmon=stock[numtime].handmon;
			if(stock[numtime].cur>stock[numtime].ori*1.2)
			{
				sprintf(stock[numtime].advice,"本软件建议您卖出%d只股,然后",stock[numtime].stocknum);
				stock[numtime].handmon+=stock[numtime].stocknum*stock[numtime].cur;
				stock[numtime].stocknum=0;
				stock[numtime].income=stock[numtime].handmon+stock[numtime].stocknum*stock[numtime].cur-stock[numtime].orihand;
				stock[numtime].incomerate=stock[numtime].income/stock[numtime].orihand*100;
				stock[numtime+1].last=stock[numtime].cur;
				stock[numtime+1].stocknum=stock[numtime].stocknum;
				stock[numtime+1].handmon=stock[numtime].handmon;
				c=b;
			}
			else if(stock[numtime].last-stock[numtime].cur>0.0618*0.66*stock[numtime].ori)    //跌 
			{
				BUY[b]=(int)floor(stock[numtime].orihand*0.1/stock[numtime].cur/100)*100;
				if(BUY[b]>0&& stock[numtime].handmon-BUY[b]*stock[numtime].cur>0)  //有钱买
				{
					sprintf(stock[numtime].advice,"本软件建议您购买%d只股,然后",BUY[b]);
					stock[numtime].stock_ave=(BUY[b]*stock[numtime].cur+stock[numtime].stocknum*stock[numtime].stock_ave)/(stock[numtime].stocknum+BUY[b]);
					stock[numtime+1].stock_ave=stock[numtime].stock_ave;
					stock[numtime].handmon-=BUY[b]*stock[numtime].cur;
					stock[numtime].stocknum+=BUY[b];
					stock[numtime].income=stock[numtime].handmon+stock[numtime].stocknum*stock[numtime].cur-stock[numtime].orihand;
					stock[numtime].incomerate=stock[numtime].income/stock[numtime].orihand*100;
					stock[numtime].flag=1;
					stock[numtime+1].last=stock[numtime].cur;
					stock[numtime+1].stocknum=stock[numtime].stocknum;
					stock[numtime+1].handmon=stock[numtime].handmon;
					b++;
				}
				else         //没钱买
				{
					sprintf(stock[numtime].advice,"本软件建议您观望",BUY[b]);
					stock[numtime].stock_ave=stock[numtime-1].stock_ave;
					stock[numtime].handmon=stock[numtime-1].handmon;
					stock[numtime].stocknum=stock[numtime-1].stocknum;
					stock[numtime].income=stock[numtime].handmon+stock[numtime].stocknum*stock[numtime].cur-stock[numtime].orihand;
					stock[numtime].incomerate=stock[numtime].income/stock[numtime].orihand*100;
					stock[numtime].flag=0;
				}
			}
			else if(stock[numtime].cur-stock[numtime].last>0.0618*1.26*stock[numtime].ori)    //涨 
			{
				sprintf(stock[numtime].advice,"本软件建议您卖出%d只股,然后",BUY[c]);
				stock[numtime].handmon+=BUY[c]*stock[numtime].cur;
				stock[numtime].stocknum-=BUY[c];
				stock[numtime].income=stock[numtime].handmon+stock[numtime].stocknum*stock[numtime].cur-stock[numtime].orihand;
				stock[numtime].incomerate=stock[numtime].income/stock[numtime].orihand*100;
				stock[numtime].flag=2;
				stock[numtime+1].last=stock[numtime].cur;
				stock[numtime+1].stocknum=stock[numtime].stocknum;
				stock[numtime+1].handmon=stock[numtime].handmon;
				c++;
			}
			else                                    //不涨不跌
			{
				sprintf(stock[numtime].advice,"本软件建议您观望");
				stock[numtime].stock_ave=stock[numtime-1].stock_ave;
				stock[numtime].handmon=stock[numtime-1].handmon;
				stock[numtime].stocknum=stock[numtime-1].stocknum;
				stock[numtime].income=stock[numtime].handmon+stock[numtime].stocknum*stock[numtime].cur-stock[numtime].orihand;
				stock[numtime].incomerate=stock[numtime].income/stock[numtime].orihand*100;
				stock[numtime].flag=0;
			}
		}        // 从存档中读取数据或其他过程结束

		printf("%s\n",stock[numtime].advice);
		fprintf(data,"%s\n",stock[numtime].advice);
		printf("您手中现金为%.0f元\n",stock[numtime].handmon);
		fprintf(data,"您手中现金为%.0f元\n",stock[numtime].handmon);
		printf("您手中股票数为%d股\n",stock[numtime].stocknum);
		fprintf(data,"您手中股票数为%d股\n",stock[numtime].stocknum);
		printf("这些股票均价为%.2f元\n",stock[numtime].stock_ave);
		fprintf(data,"这些股票均价为%.2f元\n",stock[numtime].stock_ave);
		printf("您的收益为%.0f元\n",stock[numtime].income);
		fprintf(data,"您的收益为%.0f元\n",stock[numtime].income);
		printf("您的收益率为百分之%.2f\n",stock[numtime].incomerate);
		fprintf(data,"您的收益率为百分之%.2f\n",stock[numtime].incomerate);
		if(b==c)
		{
			printf("交易结束\n");
			fprintf(data,"交易结束\n");
			fclose(data);
			remove("save.txt");
			system("PAUSE");
			return 0;
		}

		save=fopen("save.txt","w");  //存档
		fprintf(save,"%s %s %d %d %f %f %f %f %f %f %f %f  %d %d \n",stock[numtime].mytime,stock[numtime].advice,stock[numtime].flag,\
			stock[numtime].stocknum, stock[numtime].orihand,stock[numtime].handmon,stock[numtime].income,stock[numtime].incomerate,\
			stock[numtime].ori,stock[numtime].stock_ave,stock[numtime].cur,stock[numtime].last,b,c);
		for(int i=0;i<1000;i++)
			fprintf(save,"%d ",BUY[i]);
		fprintf(save,"\n");
		fclose(save);                
		
		
		printf("*************************************\n");  
		fprintf(data,"*************************************\n");
		fclose(data);
		data=fopen("data.txt","a");//存档读取完毕

		numtime++;
	}
}

#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

ofstream fout;  //输出到文件

//运算符
char sign1[2]={'+', '-'};
char sign2[2]={'*','/'};
char sign3[4]={'+', '-','*','/'};

char sign(int x)   //生成运算符
{
	char ch;
	if(x==1)
	{
		ch=sign1[rand()%2];
	}
	if(x==2)
	{
		ch=sign2[rand()%2];
	}
	if(x==3)
	{
		ch=sign3[rand()%4];
	}
	return ch;
}

double randnum(int m,int f)   //生成运算数
{
	if(f==0)
	{
		int n;
		n=rand()%m+1;
		return n;
	}
	if(f==1)
	{
		float n;
		n=rand()%m+rand()%10*0.1;
		return n;
	}
}

int par()
{
	int a,f=0;
	a=rand()%2;
	if(a==1)
	{
		f=1;
	}
	return f;
}

int main()
{
	int num;   //题目数量
	int sch;   //运算形式
	int max;   //最大值
	int flag1,flag2;  //选择标志
	int out;   //输出方式

	while(1)
	{
		cout<<"请输入题目数量"<<endl;
		cin>>num;
		cout<<"请选择运算符：1.加减运算  2.乘除运算  3.四则运算"<<endl;
		cin>>sch;
		cout<<"请设定运算数最大值(十以内、百以内等）"<<endl;
		cin>>max;
		cout<<"运算过程是否出现括号：0.否  1.是"<<endl;
		cin>>flag1;
		cout<<"运算过程是否出现小数：0.否  1.是"<<endl;
		cin>>flag2;
		cout<<"选择输出方式：1.输出到文件  2.输出到打印机"<<endl;
		cin>>out;
		if(out==1)
		{
			fout.open("jst.txt");
			while(num>0)
			{ 
				double n;   //运算数
				char ch;   //运算符
				int f1=-1,f2=-1;   //括号
				n=randnum(max,flag2);
				fout<<n;
				for(int i=0;i<4;i++)
				{
					if(f1==3)
					{
						f2=0;
					}
					if(f1==-1)
					{
						f1=par();
					}
					ch=sign(sch);
					fout<<ch;
					if(f1==1&&i!=3)
					{
						fout<<"(";
						f1=3;
						f2=1;
					}
					n=randnum(max,flag2);
					fout<<n;
					if(f2==0)
					{
						fout<<")";
						f1=-1;
						f2=-1;
					}
				}
				fout<<"="<<endl;
				num--;
			}
			fout.close();
		}
		if(out==2)
		{
			while(num>0)
			{ 
				double n;   //运算数
				char ch;   //运算符
				int f1=-1,f2=-1;   //括号
				n=randnum(max,flag2);
				cout<<n;
				for(int i=0;i<4;i++)
				{
					if(f1==3)
					{
						f2=0;
					}
					if(f1==-1)
					{
						f1=par();
					}
					ch=sign(sch);
					cout<<ch;
					if(f1==1&&i!=3)
					{
						cout<<"(";
						f1=3;
						f2=1;
					}
					n=randnum(max,flag2);
					cout<<n;
					if(f2==0)
					{
						cout<<")";
						f1=-1;
						f2=-1;
					}
				}
				cout<<"="<<endl;
				num--;
			}
		}
		int flag3;   //结束标志
		cout<<"是否结束：0.否  1.是"<<endl;
		cin>>flag3;
		if(flag3==1)
			break;
	}
	return 0;
}
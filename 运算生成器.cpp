#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

ofstream fout;  //������ļ�

//�����
char sign1[2]={'+', '-'};
char sign2[2]={'*','/'};
char sign3[4]={'+', '-','*','/'};

char sign(int x)   //���������
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

double randnum(int m,int f)   //����������
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
	int num;   //��Ŀ����
	int sch;   //������ʽ
	int max;   //���ֵ
	int flag1,flag2;  //ѡ���־
	int out;   //�����ʽ

	while(1)
	{
		cout<<"��������Ŀ����"<<endl;
		cin>>num;
		cout<<"��ѡ���������1.�Ӽ�����  2.�˳�����  3.��������"<<endl;
		cin>>sch;
		cout<<"���趨���������ֵ(ʮ���ڡ������ڵȣ�"<<endl;
		cin>>max;
		cout<<"��������Ƿ�������ţ�0.��  1.��"<<endl;
		cin>>flag1;
		cout<<"��������Ƿ����С����0.��  1.��"<<endl;
		cin>>flag2;
		cout<<"ѡ�������ʽ��1.������ļ�  2.�������ӡ��"<<endl;
		cin>>out;
		if(out==1)
		{
			fout.open("jst.txt");
			while(num>0)
			{ 
				double n;   //������
				char ch;   //�����
				int f1=-1,f2=-1;   //����
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
				double n;   //������
				char ch;   //�����
				int f1=-1,f2=-1;   //����
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
		int flag3;   //������־
		cout<<"�Ƿ������0.��  1.��"<<endl;
		cin>>flag3;
		if(flag3==1)
			break;
	}
	return 0;
}
#include<iostream>
#include<cstring>
using namespace std;
int n;
int person[1005];
void init()   //���鼯�����ʼ�� 
{
	for(int i=0;i<=n;i++)
	   person[i]=i;  //��ʼ�������������˶�����ʶ���ˣ�ֻ��ʶ�Լ� 
}
int find(int a)  //Ѱ�Ҹ���� 
{
	int temp=a,root;
	while(a!=person[a])  //Ѱ�Ҹ���� 
		a=person[a];
	root=a;  //�ҵ�֮�󣬼�¼����� 
	a=temp;  //�һس�ʼ��Ҷ�ڵ� 
    while(a!=person[a])  //���鼯��·��ѹ�� 
	{
		temp=person[a];
		person[a]=root;
		a=temp;
	}
	return root;  //���ظ���� 
}
void merge(int a,int b)  //�ϲ� 
{
	int root;
	while(a!=person[a])  // Ѱ��a�ĸ���� 
	{
		root=person[a];
		person[a]=b;
		a=root;
	}
	person[a]=b;  //��a�ĸ��ڵ���b 
}
int main()
{
	int t,a,b,m,fata,fatb,sum;
	cin>>t;  //���������� 
	while(t--)
	{
		sum=0;
	    cin>>n>>m;  //���������������� 
	    init();  //���鼯�����ʼ�� 
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			fata=find(a);   fatb=find(b);   //Ѱ�Ҹ��Եĸ��ڵ� 
			if(fata!=fatb)   merge(a,b);  //�����ڵ㲻ͬ����ϲ�������ͬ����Ҫ���� 
		}
	    for(int i=1;i<=n;i++)
	       if(person[i]==i)  sum++;  //��¼�������� 
	    cout<<sum<<endl;  //������ 
	}
	return 0;
}


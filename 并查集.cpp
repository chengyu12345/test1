#include<iostream>
#include<cstring>
using namespace std;
int n;
int person[1005];
void init()   //并查集数组初始化 
{
	for(int i=0;i<=n;i++)
	   person[i]=i;  //初始化，假设所有人都不认识别人，只认识自己 
}
int find(int a)  //寻找根结点 
{
	int temp=a,root;
	while(a!=person[a])  //寻找根结点 
		a=person[a];
	root=a;  //找到之后，记录根结点 
	a=temp;  //找回初始的叶节点 
    while(a!=person[a])  //并查集的路径压缩 
	{
		temp=person[a];
		person[a]=root;
		a=temp;
	}
	return root;  //返回根结点 
}
void merge(int a,int b)  //合并 
{
	int root;
	while(a!=person[a])  // 寻找a的根结点 
	{
		root=person[a];
		person[a]=b;
		a=root;
	}
	person[a]=b;  //将a的根节点变成b 
}
int main()
{
	int t,a,b,m,fata,fatb,sum;
	cin>>t;  //输入样例数 
	while(t--)
	{
		sum=0;
	    cin>>n>>m;  //输入朋友数、边数 
	    init();  //并查集数组初始化 
		for(int i=0;i<m;i++)
		{
			cin>>a>>b;
			fata=find(a);   fatb=find(b);   //寻找各自的根节点 
			if(fata!=fatb)   merge(a,b);  //若根节点不同，则合并。若相同则不需要干嘛 
		}
	    for(int i=1;i<=n;i++)
	       if(person[i]==i)  sum++;  //记录根的数量 
	    cout<<sum<<endl;  //输出结果 
	}
	return 0;
}


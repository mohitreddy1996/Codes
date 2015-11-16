#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

struct node
{
	int v,i,j,q;
};

int tree[30001];
struct node input[230002];

bool comp (struct node a,struct node b)
{
	if(a.v==b.v)
		return a.j>b.j;
	return a.v>b.v;
}
int n;
void upd(int ind,int val)
{
	while(ind<=n)
	{
		tree[ind]+=val;
		ind+=(ind & -ind);
	}
}

int get_ans(int ind)
{
	int res=0;
	while(ind>0)
	{
		res+=(tree[ind]);
		ind-=(ind& -ind);
	}
	return res;
}


int main()
{
	
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&input[i].v);
		input[i].i=i+1;
		input[i].j=-1;
		tree[i]=0;
	}

	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&input[i+n].i,&input[i+n].j,&input[i+n].v);
		input[i+n].q=i;
	}
	sort(input,input+n+m,comp);
	int ans[m+1];
	for(int i=0;i<n+m;i++)
	{
		if(input[i].j==-1)
		{
			upd(input[i].i,1);
		}
		else
		{
			ans[input[i].q]=get_ans(input[i].j)-get_ans(input[i].i-1);
		}
	}

	for(int i=0;i<m;i++)
	{
		printf("%d\n",ans[i]);
	}
	return 0;

}
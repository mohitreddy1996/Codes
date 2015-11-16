#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#define inf 1e9

using namespace std;



int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++)
		{
			string st;
			cin>>st;
			for(int j=1;j<=m;j++)
			{
				if(st[j-1]=='#')
					val[i][j]=0;
				if(st[j-1]=='0')
					val[i][j]=1;
				if(st[j-1]=='T')
					{	val[i][j]=2;}
			}
		}
		memset(dp,0,sizeof(dp));
		for(int i=n;i>=1;i--)
		{
			for(int j=1;j<=m;j++)
			{
				if(val[i][j])
					dp[0][i][j]=max(dp[0][i][j-1],dp[1][i+1][j])+val[i][j]-1;
			}

			for(int j=m;j>=1;j--)
			{
				if(val[i][j])
				{
					dp[1][i][j]=max(dp[1][i][j+1],dp[0][i+1][j])+val[i][j]-1;
				}
			}
		}

		printf("%d\n",dp[1][1][1]);
	}

	return 0;
}
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
#define inf 1e9

using namespace std;



int main()
{
	int lo=1;
	while(1)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
			break;
		int inc,sal,rem;
		scanf("%d %d %d",&inc,&sal,&rem);
		int a[n+1];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int dp[n+1][36];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<35;j++)
			{
				dp[i][j]=inf;
			}
		}
		dp[0][a[0]]=(inc+sal)*a[0];
		for(int i=1;i<n;i++)
		{
			for(int j=0;j<35;j++)
			{
				if(dp[i-1][j]!=inf)
				{
					if(a[i]>j)
					{
						dp[i][a[i]]=min(dp[i][a[i]],dp[i-1][j]+a[i]*sal+(a[i]-j)*inc);
					}
					else
					{
						for(int k=j;k>=a[i];k--)
						{
							dp[i][k]=min(dp[i][k],dp[i-1][j]+sal*k+(j-k)*rem);
						}

					}
				}
			}
		}

		int ans=inf;
		for(int i=0;i<35;i++)
		{
			ans=min(ans,dp[n-1][i]);
		}
		printf("Case %d, cost = $%d\n",lo,ans);
		lo++;
	}

	return 0;
}
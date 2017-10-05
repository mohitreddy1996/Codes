//Problem Link : https://www.codechef.com/AUG17/problems/GCAC/
//Submitted by : Swaraj Mishra 
//Codechef Profile Link: https://www.codechef.com/users/swmshra
#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m,i,j;
		scanf("%d%d",&n,&m);
		long int minSal[n+1];
		for(i=1;i<n+1;i++)
			scanf("%ld",&minSal[i]);
		long int offSal[m+1],jobsOffer[m+1];
		for(i=1;i<m+1;i++)
			scanf("%ld%ld",&offSal[i],&jobsOffer[i]);
		long int tJobsOffer[m+1];
		for(i=1;i<m+1;i++)
			tJobsOffer[i]=jobsOffer[i];
		int jobs[n+1][m+1];
		for(i=1;i<n+1;i++)
		{
			char c[m];
			scanf("%s",c);
			for(j=1;j<m+1;j++)
				jobs[i][j]=c[j-1]-48;
		}
		int count=0,cCompany=0;
		long int sum=0;
		for(i=1;i<n+1;i++)
		{
			long int max=0;
			int t=-1;
			for(j=1;j<m+1;j++)
			{
				if(jobs[i][j]==1&&jobsOffer[j]>0&&offSal[j]>=minSal[i])
				{
					if(offSal[j]>max)
					{ max=offSal[j]; t=j; }
				}
			}			
				if(max&&t!=-1)
				{
					jobsOffer[t]--;
					sum+=offSal[t];
					count++;
				}
		}
		for(i=1;i<m+1;i++)
		{
			if(tJobsOffer[i]==jobsOffer[i])
				cCompany++;
		}
		printf("%d %ld %d\n",count,sum,cCompany);		
	}
}

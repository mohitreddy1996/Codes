#include <iostream>
#include <algorithm>
#include<stdio.h>
using namespace std;


int main()
{	int n,m,k;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d %d",&n,&m,&k);
		char ch[m+1];
		int a[n+1];
		int sum=0;
		for(int i=0;i<n;i++)
		{	int sum=0;
			scanf("%s",ch);
			for(int j=0;j<m;j++)
			{
				if(ch[j]=='.')
					sum=sum+0;
				else
					sum=sum+1;
			}
			a[i]=sum;
		}
		std::sort(a,a+n);
			
		int g=0;
		while(k--)
		{   if(g!=n-1)
		    {
			a[g]=m-a[g];
			if(a[g]>a[g+1])	
				g++;
		    }
		    else
		    {
		         a[g]=m-a[g];   
		    }
				
		}
		for(int i=0;i<n;i++)
		 sum=sum+a[i];	
		printf("%d\n",sum);
	}

return(0);

}

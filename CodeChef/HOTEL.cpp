#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
 
int main()
{
	int t;
	int n;
	int a[101];
	int b[101];
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++)
		{
			scanf("%d",&b[i]);
		}
		std::sort(a,a+n);
		std::sort(b,b+n);
		int count=0;
		int max=0;
		for(int i=0;i<n;i++)
		{   count=0;
			for(int j=0;j<n;j++)
			{
				if(b[i]>a[j])
					count++;
				else
					break;
			}
			count=count-i;
			if(count>max)
				max=count;
		}
	printf("%d\n",max);
	}
 
return(0);
}

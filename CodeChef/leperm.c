#include <algorithm>
#include <stdio.h>
int main()
{
	int t;
	int n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int a[n+1];
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int inv=0;
		int loinv=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				if(a[i]>a[j])
				{
					inv++;
				}
			}
		}
		for(int i=0;i<n-1;i++)
		{
			if(a[i]>a[i+1])
			{
				loinv++;
			}
		}
		if(loinv==inv)
		{
			printf("YES\n");
		}
		else
			printf("NO\n");
	}

return(0);
}

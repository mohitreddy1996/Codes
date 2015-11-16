#include <stdio.h>

int main(void) {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long int n,m;
		scanf("%ld %ld",&m,&n);
		long int j=m;
		while(j<=n)
		{  int k=2;
		   int flag=1;
		   if(j==1)
		   {
		   	
		   }
			else if(j==2)
			 printf("%ld\n",j);
			else if(j==3)
			 printf("%ld\n",j);
			else
			{
				while(k<=sqrt(j))
				{
					if(j%k==0)
					{
						flag=0;
						break;
					}
					k++;
				}
				if(flag==1)
				printf("%ld\n",j);
			}
		
			j++;
		}
		printf("\n");
	}

	return 0;
}
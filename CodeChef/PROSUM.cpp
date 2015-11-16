# include<stdio.h>
int main()
{
	int t;
	long int i,n;
	long long int a,two,count;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%ld",&n);
		count=0;
		two=0;
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&a);
			if(a>1)
				count++;
			if(a==2)
				two++;
		}
		printf("%lld\n",((count*(count-1))/2)-((two*(two-1))/2));
	}
	return 0;
}

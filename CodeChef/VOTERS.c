#include<stdio.h>
long long a[1000001]={0},b[1000001]={0},t;
int main(void)
{
	int n1,n2,n3,n,i,j=1,c=0;
	scanf("%d%d%d",&n1,&n2,&n3);
	n=n1+n2+n3;
	while(n--)
	{
		scanf("%lld",&t);
		a[t]++;
	}
	for(i=1;i<1000000;i++)
	{
		if(a[i]>1)
	   {
		 b[j]=i;j++;c++;
	   }
	}
	printf("%d\n",c);
	for(j=1;j<=c;j++)
	printf("%lld\n",b[j]);
	return 0;
} 

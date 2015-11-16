#include<stdio.h>
 
long long A[100005];
 
int main()
{
	int T, i;
	long long N;
	
	scanf("%d",&T);
	
	while(T--)
	{
		scanf("%lld",&N);
		
		for(i=0; i<N; i++)
			scanf("%lld",&A[i]);
			
		printf("%lld\n",N*(N-1)/2);
	}
	
	return 0;
}

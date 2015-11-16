#include<stdio.h>
#include<math.h>
 
int main()
{
	int T, i, candle[12], small;
	long long age;
	
	scanf("%d",&T);
	
	while(T--)
	{
		age = 0;
		
		for(i=0; i<10; i++)
			scanf("%d",&candle[i]);
		
		small=1;
		
		for(i=2; i<10; i++)
			if(candle[i]<candle[small])
				small = i;
 
		if(candle[0]>=candle[small])
			for(i=0; i<=candle[small]; i++)
				age = age*10 + small;
				
		else
			age = pow(10,candle[0]+1);
			
		printf("%lld\n",age);
	}
return(0);
}

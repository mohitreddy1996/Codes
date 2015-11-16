#include <stdio.h>
 
int main(void) {
    long int n;
    scanf("%ld",&n);
    long int ch[n+1];
    long long int sum=0;
    for(long int i=0;i<n;i++)
    {
        scanf("%ld",&ch[i]);
    }
    for(long int i=0;i<n;i++)
    {
        for(long int j=i+1;j<n;j++)
        {
            sum=sum+(ch[i]&ch[j]);
        }
    }
    printf("%lld",sum);
	return 0;
}

include<stdio.h>
int main()
{
long int t;
scanf("%ld",&t);
long long int n;
for(long int i=0;i<t;i++)
{
 
 scanf("%lld",&n);
 if(n%2)
 printf("BOB\n");
 else
 printf("ALICE\n");
 
}
return(0);
}

#include<stdio.h>
int main()
{
 long int t,n;
  scanf("%ld",&t);
  while(t)
  {
   scanf("%ld",&n);
   printf("%ld\n",(n/2)+1);
  t--;
  }
 return(0);
 } 

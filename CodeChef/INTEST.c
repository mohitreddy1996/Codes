#include<stdlib.h>
#include<stdio.h>
#include<math.h>
int main()
{
 long int n,k,t;
 long int count=0;
 scanf("%ld %ld",&n,&k);
 if((n>=0&&n<=pow(10,7))&&(k>=0&&k<=pow(10,7)))
 {
 for(long int i=0;i<n;i++)
 {
  scanf("%ld",&t);
  if(t>=0&&t<=pow(10,9))
  {
  if(t%k==0)
  count++;
  }
 }
 
 printf("\n %ld",count);
 }
 return(0);
 
 }  

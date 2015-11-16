#include<stdio.h>
int main()
{
int t;
scanf("%d",&t);
for(int i=0;i<t;i++)
{
 long int a,b;
  long int min,max;
  scanf("%ld %ld",&a,&b);
  if(a<b)
   {min=b;
    max=a+b;
   }
   else
   {min=a;
    max=a+b;
   }
   printf("%ld %ld\n",min,max);
 }
 return(0);
}

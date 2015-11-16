#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
int t;
char a[11];
scanf("%d",&t);
if(t>=1&&t<=10000)
for(int i=0;i<t;i++)
{
 scanf("\n%s",a);
int l=strlen(a);
if(a[l-1]%2!=0)
{
--a[l-1];
}
printf("\n%s",a);
 
}
 
 
return(0);
}

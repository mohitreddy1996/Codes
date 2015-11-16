#include<stdlib.h>
#include<stdio.h>
#include<string.h>
int main()
{
 int t;
 char ch[100];
 scanf("\n%d",&t);
 if(t>=0&&t<=40)
 {
  for(int i=0;i<t;i++)
  {
   scanf("\n%s",ch);
   int l;
   int count=0;
   l=strlen(ch);
   if(l<=100)
   for(int j=0;j<l;j++)
   {
    if(ch[j]=='A'||ch[j]=='D'||ch[j]=='Q'||ch[j]=='R'||ch[j]=='O'||ch[j]=='P')
    count=count+1;
    else if(ch[j]=='B')
    count=count+2;
    }
    printf("\n%d",count);
  }
  
 }
 
 return(0);
 
 }

#include<stdio.h>
#include<stdlib.h>
int main()
{ 
 int n;
 int p1score,p2score;
 int p1tot=0;
 int p2tot=0;
 int lead1=0;
  int lead2=0;
 scanf("%d",&n);
 for(int i=0;i<n;i++)
 { 
  scanf("\n%d %d",&p1score,&p2score);
  p1tot+=(p1score);
  p2tot+=(p2score);
  
   if((p1tot-p2tot)>lead1)
   {
    lead1=(p1tot-p2tot);
   }
  
  else
     if((p2tot-p1tot)>lead2)
    {
     lead2=(p2tot-p1tot);
    }
   
  }
  if(lead1>lead2)
  printf("1 %d",lead1);
  else
  printf("2 %d",lead2);
  
  return(0);
  
 }

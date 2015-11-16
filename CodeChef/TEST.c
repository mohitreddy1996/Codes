#include<stdlib.h>
int main()
{
 int i;
 while(1)
 {
  scanf("%d",&i);
  if(i==42)
   break;
  if(i>=0 && i<100)
   { 
    printf("\n %d",i);
   }
 }
  return(0);
 }    

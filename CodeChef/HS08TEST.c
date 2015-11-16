#include<stdio.h>
int main()
{
 int x;
 float y;
float amt;
  scanf("%d",&x);
  scanf("%f",&y);
 
 if((x>0 && x<=2000)&&(y>=0 && y<=2000))
 {
    if((y-(float)x)<0.50)
  printf("%f\n",y);
    else if(x%5==0)
   {
    amt=((y-x)-0.50);
    printf("\n%f",amt);
 
   }
 
  else
  printf("%f\n",y);
 }
 
return(0);
 
} 

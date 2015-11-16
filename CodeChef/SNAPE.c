#include <stdio.h>
#include<math.h>
 
 
int main(void) {
   int t;
   scanf("%d",&t);
   for(int i=0;i<t;i++)
    {
        int b,ls;
        scanf("%d %d",&b,&ls);
        float max=sqrt(ls*ls+b*b);
        float min=sqrt(ls*ls-b*b);
        
        printf("%0.4f %0.4f\n",min,max);
        
    }
   
   return 0;
}

#include <stdio.h>
#include<math.h>
 
 
int main(void) {
   int t;
   scanf("%d",&t);
   for(int i=0;i<t;i++)
   {
       int g;
       scanf("%d",&g);
       long int n;
       int i,q;
       
       for(int j=0;j<g;j++)
       {long int count_head=0,count_tail=0;
           scanf("%d %ld %d",&i,&n,&q);
           if(i==1)
           {
               count_head+=n/2;
               count_tail=n-count_head;
               
           }
           else
           {
               count_tail+=n/2;
               count_head=n-count_tail;
           }
           if(q==1)
           printf("%ld\n",count_head);
           else
           printf("%ld\n",count_tail);
       }
   }
   
   return 0;
}

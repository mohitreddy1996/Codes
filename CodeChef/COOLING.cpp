#include <stdio.h>
#include <algorithm>
int main(void) {
 int t;
 scanf("%d",&t);
 for(int i=0;i<t;i++)
 {
     int n;
     scanf("%d",&n);
      int a[n+1],b[n+1];
     for(int k=0;k<n;k++)
     {
         scanf("%d",&a[k]);
     }
     std::sort(a,a+n);
      for(int k=0;k<n;k++)
     {
         scanf("%d",&b[k]);
     }
     std::sort(b,b+n);
     long int count=0;
     for(int k=0,j=0;k<n;k++)
     {
         if(b[k]>=a[j])
          {
               j++;
               count++;
          }
     }
     printf("%ld\n",count);
 }
	return 0;
}

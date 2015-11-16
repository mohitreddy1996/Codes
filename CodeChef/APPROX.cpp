#include<math.h>
#include<stdio.h>
using namespace std;
int main()
{
    int tc,k;
    scanf("%d",&tc);
    while(tc--)
    {
      int n=103993;
      int d=33102;
     scanf("%d",&k);
     if(k==0)
        printf("3\n");
     else
     {
          printf("3.");
         for(int i=0;i<k;++i)
         { n=(n%d)*10;
             printf("%d",n/d);
 
 
         }
         printf("\n");
     }
    }
 
    return 0;
}

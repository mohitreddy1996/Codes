#include <iostream>
#include <stdio.h>
using namespace std;
 
int main() {
    int t;
    scanf("%d",&t);
    long int a[1000001];
    while(t--)
    {
        long int k;
        scanf("%ld",&k);
        for(int i=0;i<k;i++)
        {
            scanf("%ld",&a[i]);
        }
        long int ns=1,i;
        for(i=0;i<k-1;i++)
        {
            if(a[i]>ns)
                break;
            else
                ns=2*(ns-a[i]);
        }
        if(i==k-1&&a[k-1]==ns)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
        	return 0;
}

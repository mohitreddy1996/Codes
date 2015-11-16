#include <iostream>
#include <stdio.h>
using namespace std;
 
int main() {
        int t;
        scanf("%d",&t);
        while(t--)
        {
            long int n,c,q;
            scanf("%ld %ld %ld",&n,&c,&q);
            long int temp1,temp2;
            long int mark;
            while(q--)
            {
                scanf("%ld %ld",&temp1,&temp2);
                if(c<=temp2&&c>=temp1)
                {
                    c=(temp2-(c-temp1));
                }
            
            }
            printf("%ld\n",c);
        }
    	return 0;
}

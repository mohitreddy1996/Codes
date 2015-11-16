#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    int n,m,d,h;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&n,&m,&d);
        d++;
        int temp=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&h);
            temp+=(h/d);
        }
        if(temp>=m)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }


    return 0;
}

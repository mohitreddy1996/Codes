#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    scanf("%d",&n);
    int x[4],y[4];
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
    }
    if(n==1)
    {
        printf("-1");
    }
    else if(n==2)
    {
        if(x[0]==x[1]||y[0]==y[1])
        {
            printf("-1");
        }
        else
        {
            printf("%d",abs(x[0]-x[1])*abs(y[0]-y[1]));
        }
    }
    else
    {
        int side1,side2;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(x[i]==x[j])
                {
                    side1=abs(y[j]-y[i]);
                    break;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(y[i]==y[j])
                {
                    side2=abs(x[j]-x[i]);
                    break;
                }
            }
        }
        printf("%d",side1*side2);

    }

return 0;
}
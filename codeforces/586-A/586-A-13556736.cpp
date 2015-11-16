#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int a[200];
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {

        scanf("%d",&a[i]);
    }
    int count1=0;
    int i=0;
    while(a[i]!=1)
        i++;
    while(i<n)
    {

        if(a[i]==1)
        {
            count1++;
            if(i+1<n && i+2<n)
            {
                if(a[i+1]==0 && a[i+2]==0)
                {
                    i++;
                    while(i<n && a[i]!=1)
                        i++;
                }
                else
                {
                    i++;
                    while(i<n && a[i]!=1)
                    {
                        count1++;
                        i++;
                    }
                }
            }
            else
                i++;
        }
        else
            i++;
    }
    cout<<count1;
    return 0;
}
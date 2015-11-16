#include <algorithm>
#include <stdio.h>
#include <utility>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int a[m+2];
    for(int i=0;i<m;i++)
        scanf("%d",&a[i]);
    sort(a,a+m);
    int ans,diff;
    for(int i=0;i<=(m-n);i++)
    {
        diff=a[i+n-1]-a[i];
        if(i==0)
        {
            ans=diff;
        }
        else
        {
            ans=min(ans,diff);
        }
    }
    cout<<ans;
    
return(0);    
}
#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;
int a[2002];
int temp[2002][2002]={0};
int dp(int beg,int end,int day)
{   //printf("%d\n",temp[beg][end]);
    if(beg<=end)
    {   if(temp[beg][end]!=0)
            return temp[beg][end];
        return(temp[beg][end]=max((a[beg]*day)+dp(beg+1,end,day+1),(a[end]*day)+dp(beg,end-1,day+1)));
    }
    else
    {
        return 0;
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    //printf("%d",dp(0,n-1,1));
    int x=dp(0,n-1,1);
    printf("%d",x);
return(0);    
}

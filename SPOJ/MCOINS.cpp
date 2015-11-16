#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int k,l,n;
    scanf("%d %d %d",&k,&l,&n);
    int a[n+1];
    int max1=0;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        max1=max(max1,a[i]);
    }
    int win[max1+1];
    win[0]=0;
    for(long int i=1;i<=max1;i++)
    {
        win[i]=!win[i-1];
        if(i>=k&&!win[i-k]) win[i]=1;
        if(i>=l&&!win[i-l]) win[i]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(win[a[i]])
            cout<<"A";
        else
            cout<<"B";
    }
return(0);    
}

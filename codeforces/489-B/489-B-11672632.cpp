#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int m;
    cin>>n;
    int a[n+1];
    for(int i=0;i<n;i++)
        cin>>a[i];
    cin>>m;
    int b[m+1];
    for(int j=0;j<m;j++)
        cin>>b[j];
    sort(a,a+n);
    sort(b,b+m);
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(abs(a[i]-b[j])<=1)
               { b[j]=1000;
               count++;
               break;
               }
        }
    }
    cout<<count;
    
return(0);    
}
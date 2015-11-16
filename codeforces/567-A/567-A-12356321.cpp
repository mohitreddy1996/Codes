#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
using namespace std;

int main() {
    int n;
    scanf("%d",&n);
    long long int a[n+2];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        long int min1=3e9;
        long int max1=-1;
        if(i==0)
        {
            min1=min(min1,labs(a[i]-a[i+1]));
            max1=max(max1,labs(a[i]-a[n-1]));
        }
        else if(i!=n-1)
        {
            min1=min(min1,labs(a[i]-a[i+1]));
            min1=min(min1,labs(a[i]-a[i-1]));
            max1=max(max1,labs(a[i]-a[n-1]));
            max1=max(max1,labs(a[i]-a[0]));
        }
        else
        {
            min1=min(min1,labs(a[i]-a[i-1]));
            max1=max(max1,labs(a[i]-a[0]));
        }
        cout<<min1<<" "<<max1<<"\n";
    }
    return 0;
}
#include <algorithm>
#include <stdio.h>
#include <map>
#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int n;
    cin>>n;
    int a[n+2];
    int b[7000]={0};
    long int sum1=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        b[a[i]]++;
    }
    for(int i=1;i<=(2*n+3);i++)
    {
        if(b[i]>1)
        {
            b[i+1]+=(b[i]-1);
            sum1=sum1+(b[i]-1);
        }
    }
    cout<<sum1;
        
    
return(0);    
}
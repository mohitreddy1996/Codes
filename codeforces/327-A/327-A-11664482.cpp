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
    int s=0;
    int a[105],b[105];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]==1)
            {
                s++;
                b[i]=-1;
                
            }    
        else
            b[i]=1;
    }
    int max2=0;
    for(int i=0;i<n;i++)
    {
        int mark=0;
        int max1=b[i];
        for(int j=i;j<n;j++)
        {
            mark=mark+b[j];
            max1=max(max1,mark);
           
        }
        
        max2=max(max2,max1+s);
    }
    cout<<max2;
    
return(0);    
}
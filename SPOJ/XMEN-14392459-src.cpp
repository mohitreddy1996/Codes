#include <algorithm>
#include <stdio.h>
#include <map>
#include <set>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int t;
    long int n;
    
    scanf("%d",&t);
    while(t--)
    {   long int a[100003],b[100003],c[100003];
        scanf("%ld",&n);
        long int temp;
        for(long int i=0;i<n;i++)
            {
            scanf("%ld",&a[i]);
            c[a[i]]=i;
            }
        for(long int i=0;i<n;i++)
        {    
            scanf("%ld",&b[i]);
            a[i]=c[b[i]];
        }
        
        set<long int> s;
        set<long int>::iterator it;
        s.clear();
        for(long int i=0;i<n;i++)
        {
            s.insert(a[i]);
            it=s.find(a[i]);
            it++;
            if(it!=s.end())
                s.erase(it);
                
        }
        printf("%ld\n",s.size());
    }
return(0);    
}
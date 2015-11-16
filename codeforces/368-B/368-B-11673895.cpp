#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <map>
#include <set>
#include <iostream>
#include <vector>
using namespace std;


int main()
{
    
   long int n,m;
   cin>>n>>m;
   long int a[n+2];
   for(long int i=1;i<=n;i++)
   {
       scanf("%ld",&a[i]);
   }
   map<long int,long int> ma;
   set<long int> s;
   for(long int i=n;i>=1;i--)
   {
       s.insert(a[i]);
       ma[i]=s.size();
   }
    for(long int i=0;i<m;i++)
    {
        long int x;
        cin>>x;
        cout<<ma[x]<<"\n";
        
    }
return(0);    
}
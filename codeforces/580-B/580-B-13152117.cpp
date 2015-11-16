#include <algorithm>
#include <stdio.h>
#include <map>
#include <math.h>
#include <stack>
#include <string.h>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;
#define mod 1000000007
#define MAX 10001
#define inf 1e9
#define inf 1000000000

int main()
{
   long long int n,m;
   cin>>n>>m;
   vector<pair<long long int,long long int> > v;
   vector<long long int> v1;
   for(int i=0;i<n;i++)
   {
        long long int c,s;
        cin>>c>>s;
        v.push_back(make_pair(c,s));
        v1.push_back(c);

   }
   sort(v.begin(),v.end());
   sort(v1.begin(),v1.end());
   long long int sum[100003];
   for(int i=0;i<v.size();i++)
   {
       if(i==0)
        sum[i]=v[i].second;
       else
       {
           sum[i]=sum[i-1]+v[i].second;
       }
   }
   long long int max1=-1;
   for(int i=0;i<n;i++)
   {
       int x=lower_bound(v1.begin(),v1.end(),v1[i]+m)-v1.begin();
       x=x-1;
       if(i==0)
       {
           max1=max(max1,sum[x]);
       }
       else
       {
           max1=max(max1,sum[x]-sum[i-1]);
       }
   }
    cout<<max1;


return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <set>
using namespace std;
int main()
{
int t;
scanf("%d",&t);
long long int n,i,m,tot,res;
 
while(t--)
{tot=0;
res=0;
    cin>>n;
vector < pair<long long int,long long int> >p(n);
     for(i=0;i<n;++i)
     {
         scanf("%lld %lld",&(p[i].first),&(p[i].second));
 
     }
     sort(p.begin(),p.end());
 
vector< long long int>song;
     for(i=0;i<n;++i)
     {
         if(i==0||(p[i-1].first<p[i].first))
            song.push_back(p[i].second);
         else
            tot=tot+p[i].second;
     }
     m=song.size();
     sort(song.begin(), song.end());
    res=m*tot;
    for(i=0;i<song.size();++i)
    {res=res+(i+1)*song[i];
    }
    printf("%lld\n",res);
}
}

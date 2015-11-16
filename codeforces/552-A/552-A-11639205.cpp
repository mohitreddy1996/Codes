#include <algorithm>
#include <stdio.h>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    
    int n;
    scanf("%d",&n);
    int x1,x2,y1,y2;
    set<pair<int,int> > v;
    pair<int,int> p;
    int count1=0;
    while(n--)
    {
        
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        for(int i=x1;i<=x2;i++)
        {
            for(int j=y1;j<=y2;j++)
            {
                p.first=i;
                p.second=j;
                if(v.find(p)!=v.end())
                    count1++;
                else
                {
                v.insert(make_pair(i,j));
                count1++;
                }
                
            }
        }
        
        
    }
    cout<<count1;
    
return(0);    
}
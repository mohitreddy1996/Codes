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

int cat[100002];
int m;
vector<int> v[100002];
int visited[100002];
int count1=0;
void dfs(int x)
{
    stack<pair<int,int> > s;
    s.push(make_pair(x,cat[x]));
    while(s.empty()==false)
    {
        pair<int,int> p=s.top();
        //cout<<p.first<<" "<<p.second<<"\n";
        s.pop();
        if(visited[p.first])
        {
            continue;
        }
        if(p.second>m)
        {
            continue;
        }
        visited[p.first]=1;
        int flag=0;
        for(int i=0;i<v[p.first].size();i++)
        {
            int q=v[p.first][i];
            if(visited[q]==1)
                continue;
            flag=1;
            if(cat[q]==0)
                s.push(make_pair(q,0));
            else
                s.push(make_pair(q,cat[q]+p.second));
        }
        if(!flag)
        {
            //cout<<p.first<<" ";
            count1++;
        }
    }
}

int main()
{
   int n;
   scanf("%d %d",&n,&m);
   for(int i=1;i<=n;i++)
   {
       scanf("%d",&cat[i]);
   }
   for(int i=0;i<n-1;i++)
   {
       int x,y;
       scanf("%d %d",&x,&y);
       v[x].push_back(y);
       v[y].push_back(x);
   }
   dfs(1);
   cout<<count1;

return 0;
}
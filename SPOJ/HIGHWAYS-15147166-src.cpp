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
struct comp
{
    bool operator() (pair<int,int> const &a,pair<int,int> const &b )
    {
        return a.second>b.second;
    }
};

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,st,fi;
        scanf("%d %d %d %d",&n,&m,&st,&fi);
        vector<pair<int,int> > v[n+1];
        int time[n+1],visited[n+1];
        for(int i=0;i<m;i++)
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            v[x].push_back(make_pair(y,z));
            v[y].push_back(make_pair(x,z));

        }
        for(int i=1;i<=n;i++)
        {
            time[i]=inf;
            visited[i]=0;
        }
        priority_queue<pair<int,int>,vector<pair<int,int> >,comp> q;
        time[st]=0;
        q.push(make_pair(st,time[st]));
        while(q.empty()==false)
        {
            pair<int,int> p=q.top();
            q.pop();
            if(visited[p.first])
            {
                continue;
            }

            int x=p.first;
            int w=p.second;
            //cout<<x<<" "<<w<<"\n";
            visited[x]=1;
            for(int i=0;i<v[x].size();i++)
            {
                int y=v[x][i].first;
                int w=v[x][i].second;
                //cout<<y<<" "<<w<<"\n";
                if(visited[y]==0)
                {
                    //cout<<y<<"\n";
                   // cout<<time[y]<<" "<<time[x]<<" "<<w<<"\n";1
                    if(time[y] > time[x]+w)
                    {
                        //cout<<time[y]<<"\n";
                        time[y]=time[x]+w;
                        //cout<<y<<" "<<time[y]<<"\n";
                        q.push(make_pair(y,time[y]));
                    }
                }
            }
        }

        if(time[fi]!=inf)
        printf("%d\n",time[fi]);
        else
            printf("NONE\n");

    }
return(0);
}
